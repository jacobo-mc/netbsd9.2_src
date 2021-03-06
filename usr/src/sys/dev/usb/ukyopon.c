/*	$NetBSD: ukyopon.c,v 1.24.2.1 2020/04/12 08:44:42 martin Exp $	*/

/*
 * Copyright (c) 1998, 2005 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Lennart Augustsson (lennart@augustsson.net) at
 * Carlstedt Research & Technology.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by ITOH Yasufumi.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: ukyopon.c,v 1.24.2.1 2020/04/12 08:44:42 martin Exp $");

#ifdef _KERNEL_OPT
#include "opt_usb.h"
#endif

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/kernel.h>
#include <sys/ioctl.h>
#include <sys/conf.h>
#include <sys/tty.h>
#include <sys/file.h>
#include <sys/select.h>
#include <sys/proc.h>
#include <sys/vnode.h>
#include <sys/device.h>
#include <sys/poll.h>

#include <sys/bus.h>

#include <dev/usb/usb.h>
#include <dev/usb/usbcdc.h>

#include <dev/usb/usbdi.h>
#include <dev/usb/usbdi_util.h>
#include <dev/usb/usbdivar.h>
#include <dev/usb/usbdevs.h>
#include <dev/usb/usb_quirks.h>

#include <dev/usb/ucomvar.h>
#include <dev/usb/umodemvar.h>
#include <dev/usb/ukyopon.h>

#ifdef UKYOPON_DEBUG
#define DPRINTFN(n, x)	if (ukyopondebug > (n)) printf x
int	ukyopondebug = 0;
#else
#define DPRINTFN(n, x)
#endif
#define DPRINTF(x) DPRINTFN(0, x)

struct ukyopon_softc {
	/* generic umodem device */
	struct umodem_softc	sc_umodem;

	/* ukyopon addition */
};

#define UKYOPON_MODEM_IFACE_INDEX	0
#define UKYOPON_DATA_IFACE_INDEX	3

static void	ukyopon_get_status(void *, int, u_char *, u_char *);
static int	ukyopon_ioctl(void *, int, u_long, void *, int, proc_t *);
static void	ukyopon_set(void *, int, int, int);
static int	ukyopon_param(void *, int, struct termios *);
static int	ukyopon_open(void *, int);
static void	ukyopon_close(void *, int);

static struct ucom_methods ukyopon_methods = {
	.ucom_get_status = ukyopon_get_status,
	.ucom_set = ukyopon_set,
	.ucom_param = ukyopon_param,
	.ucom_ioctl = ukyopon_ioctl,
	.ucom_open = ukyopon_open,
	.ucom_close = ukyopon_close,
};

static int	ukyopon_match(device_t, cfdata_t, void *);
static void	ukyopon_attach(device_t, device_t, void *);
static int	ukyopon_detach(device_t, int);

CFATTACH_DECL_NEW(ukyopon, sizeof(struct ukyopon_softc), ukyopon_match,
    ukyopon_attach, ukyopon_detach, NULL);

static int
ukyopon_match(device_t parent, cfdata_t match, void *aux)
{
	struct usbif_attach_arg *uiaa = aux;

	if (uiaa->uiaa_vendor == USB_VENDOR_KYOCERA &&
	    uiaa->uiaa_product == USB_PRODUCT_KYOCERA_AHK3001V &&
	    (uiaa->uiaa_ifaceno == UKYOPON_MODEM_IFACE_INDEX ||
	     uiaa->uiaa_ifaceno == UKYOPON_DATA_IFACE_INDEX))
		return UMATCH_VENDOR_PRODUCT;

	return UMATCH_NONE;
}

static void
ukyopon_attach(device_t parent, device_t self, void *aux)
{
	struct ukyopon_softc *sc = device_private(self);
	struct usbif_attach_arg *uiaa = aux;
	struct ucom_attach_args ucaa;

	memset(&ucaa, 0, sizeof(ucaa));

	ucaa.ucaa_portno = (uiaa->uiaa_ifaceno == UKYOPON_MODEM_IFACE_INDEX) ?
		UKYOPON_PORT_MODEM : UKYOPON_PORT_DATA;
	ucaa.ucaa_methods = &ukyopon_methods;
	ucaa.ucaa_info = (uiaa->uiaa_ifaceno == UKYOPON_MODEM_IFACE_INDEX) ?
	    "modem port" : "data transfer port";

	if (umodem_common_attach(self, &sc->sc_umodem, uiaa, &ucaa))
		return;
	return;
}

static void
ukyopon_get_status(void *addr, int portno, u_char *lsr, u_char *msr)
{
	struct ukyopon_softc *sc = addr;

	/*
	 * The device doesn't set DCD (Data Carrier Detect) bit properly.
	 * Assume DCD is always present.
	 */
	if ((sc->sc_umodem.sc_msr & UMSR_DCD) == 0)
		sc->sc_umodem.sc_msr |= UMSR_DCD;

	umodem_get_status(&sc->sc_umodem, portno, lsr, msr);
}

static void
ukyopon_set(void *addr, int portno, int reg, int onoff)
{
	struct ukyopon_softc *sc = addr;

	umodem_set(&sc->sc_umodem, portno, reg, onoff);
}

static int
ukyopon_param(void *addr, int portno, struct termios *t)
{
	struct ukyopon_softc *sc = addr;

	return umodem_param(&sc->sc_umodem, portno, t);
}

static int
ukyopon_open(void *addr, int portno)
{
	struct ukyopon_softc *sc = addr;

	return umodem_open(&sc->sc_umodem, portno);
}

static void
ukyopon_close(void *addr, int portno)
{
	struct ukyopon_softc *sc = addr;

	umodem_close(&sc->sc_umodem, portno);
}


static int
ukyopon_ioctl(void *addr, int portno, u_long cmd, void *data, int flag,
	      proc_t *p)
{
	struct ukyopon_softc *sc = addr;
	struct ukyopon_identify *arg_id = (void*)data;
	int error = 0;

	switch (cmd) {
	case UKYOPON_IDENTIFY:
		strncpy(arg_id->ui_name, UKYOPON_NAME, sizeof(arg_id->ui_name));
		arg_id->ui_busno =
		    device_unit(sc->sc_umodem.sc_udev->ud_bus->ub_usbctl);
		arg_id->ui_address = sc->sc_umodem.sc_udev->ud_addr;
		arg_id->ui_model = UKYOPON_MODEL_UNKNOWN;
		arg_id->ui_porttype = portno;
		break;

	default:
		error = umodem_ioctl(&sc->sc_umodem, portno, cmd, data, flag, p);
		break;
	}

	return error;
}

int
ukyopon_detach(device_t self, int flags)
{
	struct ukyopon_softc *sc = device_private(self);

	return umodem_common_detach(&sc->sc_umodem, flags);
}
