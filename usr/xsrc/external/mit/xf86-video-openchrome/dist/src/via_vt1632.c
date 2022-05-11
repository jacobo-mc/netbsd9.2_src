/*
 * Copyright 2016 Kevin Brace
 * Copyright 2016 The OpenChrome Project
 *                [https://www.freedesktop.org/wiki/Openchrome]
 * Copyright 2014 SHS SERVICES GmbH
 * Copyright 2006-2009 Luc Verhaegen.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "via_driver.h"
#include "via_vt1632.h"

static void
viaVT1632DumpRegisters(ScrnInfoPtr pScrn, I2CDevPtr pDev)
{
    int i;
    CARD8 tmp;

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered viaVT1632DumpRegisters.\n"));

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Dumping VT1632(A) registers.\n"));
    for (i = 0; i <= 0x0f; i++) {
        xf86I2CReadByte(pDev, i, &tmp);
        DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO, "0x%02x: 0x%02x\n", i, tmp));
    }

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting viaVT1632DumpRegisters.\n"));
}

static void
viaVT1632InitRegisters(ScrnInfoPtr pScrn, I2CDevPtr pDev)
{
    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered viaVT1632InitRegisters.\n"));

    /* For Wyse C00X VX855 chipset DVP1 (Digital Video Port 1), use
     * 12-bit mode with dual edge transfer, along with rising edge
     * data capture first mode. This is likely true for CX700, VX700,
     * VX800, and VX900 chipsets as well. */
    xf86I2CWriteByte(pDev, 0x08,
                        VIA_VT1632_VEN | VIA_VT1632_HEN |
                        VIA_VT1632_DSEL |
                        VIA_VT1632_EDGE | VIA_VT1632_PDB);

    /* Route receiver detect bit (Offset 0x09[2]) as the output of
     * MSEN pin. */
    xf86I2CWriteByte(pDev, 0x09, 0x20);

    /* Turning on deskew feature caused screen display issues.
     * This was observed with Wyse C00X. */
    xf86I2CWriteByte(pDev, 0x0A, 0x00);

    /* While VIA Technologies VT1632A datasheet insists on setting this
     * register to 0x89 as the recommended setting, in practice, this
     * leads to a blank screen on the display with Wyse C00X. According to
     * Silicon Image SiI 164 datasheet (VT1632A is a pin and mostly
     * register compatible chip), offset 0x0C is for PLL filter enable,
     * PLL filter setting, and continuous SYNC enable bits. All of these are
     * turned off for proper operation. */
    xf86I2CWriteByte(pDev, 0x0C, 0x00);

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting viaVT1632InitRegisters.\n"));
}

/*
 * Returns TMDS receiver detection state for VIA Technologies VT1632
 * external TMDS transmitter.
 */
static Bool
viaVT1632Sense(ScrnInfoPtr pScrn, I2CDevPtr pDev)
{
    CARD8 tmp;
    Bool receiverDetected = FALSE;

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered viaVT1632Sense.\n"));

    xf86I2CReadByte(pDev, 0x09, &tmp);
    if (tmp & 0x04) {
        receiverDetected = TRUE;
    }

    xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                "VT1632 %s a TMDS receiver.\n",
                receiverDetected ? "detected" : "did not detect");

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting viaVT1632Sense.\n"));
    return receiverDetected;
}

static void
viaVT1632Power(ScrnInfoPtr pScrn, I2CDevPtr pDev, Bool powerState)
{
    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered viaVT1632Power.\n"));

    xf86I2CMaskByte(pDev, 0x08, powerState ? 0x01 : 0x00, 0x01);
    xf86DrvMsg(pScrn->scrnIndex, X_INFO, "VT1632 (DVI) Power: %s\n",
                powerState ? "On" : "Off");

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting viaVT1632Power.\n"));
}

static void
viaVT1632SaveRegisters(ScrnInfoPtr pScrn, I2CDevPtr pDev,
                        viaVT1632RecPtr pVIAVT1632Rec)
{
    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered viaVT1632SaveRegisters.\n"));

    xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                "Saving VT1632 registers.\n");
    xf86I2CReadByte(pDev, 0x08, &pVIAVT1632Rec->Register08);
    xf86I2CReadByte(pDev, 0x09, &pVIAVT1632Rec->Register09);
    xf86I2CReadByte(pDev, 0x0A, &pVIAVT1632Rec->Register0A);
    xf86I2CReadByte(pDev, 0x0C, &pVIAVT1632Rec->Register0C);

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting viaVT1632SaveRegisters.\n"));
}

static void
viaVT1632RestoreRegisters(ScrnInfoPtr pScrn, I2CDevPtr pDev,
                            viaVT1632RecPtr pVIAVT1632Rec)
{
    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered viaVT1632RestoreRegisters.\n"));

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Restoring VT1632 registers.\n"));
    xf86I2CWriteByte(pDev, 0x08, pVIAVT1632Rec->Register08);
    xf86I2CWriteByte(pDev, 0x09, pVIAVT1632Rec->Register09);
    xf86I2CWriteByte(pDev, 0x0A, pVIAVT1632Rec->Register0A);
    xf86I2CWriteByte(pDev, 0x0C, pVIAVT1632Rec->Register0C);

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting viaVT1632RestoreRegisters.\n"));
}

static int
viaVT1632CheckModeValidity(xf86OutputPtr output, DisplayModePtr pMode)
{
    ScrnInfoPtr pScrn = output->scrn;
    viaVT1632RecPtr pVIAVT1632Rec = output->driver_private;
    int status = MODE_OK;

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO, 
                        "Entered viaVT1632CheckModeValidity.\n"));

    if (pMode->Clock < pVIAVT1632Rec->DotclockMin) {
        status = MODE_CLOCK_LOW;
        goto exit;
    }

    if (pMode->Clock > pVIAVT1632Rec->DotclockMax) {
        status = MODE_CLOCK_HIGH;
    }

exit:
    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting viaVT1632CheckModeValidity.\n"));
    return status;
}

static void
via_vt1632_create_resources(xf86OutputPtr output)
{
}

static void
via_vt1632_dpms(xf86OutputPtr output, int mode)
{
    ScrnInfoPtr pScrn = output->scrn;
    viaVT1632RecPtr pVIAVT1632Rec = output->driver_private;

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered via_vt1632_dpms.\n"));

    switch (mode) {
    case DPMSModeOn:
        viaVT1632Power(pScrn, pVIAVT1632Rec->VT1632I2CDev, TRUE);
        break;
    case DPMSModeStandby:
    case DPMSModeSuspend:
    case DPMSModeOff:
        viaVT1632Power(pScrn, pVIAVT1632Rec->VT1632I2CDev, FALSE);
        break;
    default:
        break;
    }

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting via_vt1632_dpms.\n"));
}

static void
via_vt1632_save(xf86OutputPtr output)
{
    ScrnInfoPtr pScrn = output->scrn;
    viaVT1632RecPtr pVIAVT1632Rec = output->driver_private;

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered via_vt1632_save.\n"));

    viaVT1632SaveRegisters(pScrn, pVIAVT1632Rec->VT1632I2CDev, pVIAVT1632Rec);

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting via_vt1632_save.\n"));
}

static void
via_vt1632_restore(xf86OutputPtr output)
{
    ScrnInfoPtr pScrn = output->scrn;
    viaVT1632RecPtr pVIAVT1632Rec = output->driver_private;

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered via_vt1632_restore.\n"));

    viaVT1632RestoreRegisters(pScrn, pVIAVT1632Rec->VT1632I2CDev,
                                pVIAVT1632Rec);

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting via_vt1632_restore.\n"));
}

static int
via_vt1632_mode_valid(xf86OutputPtr output, DisplayModePtr pMode)
{
    return viaVT1632CheckModeValidity(output, pMode);
}

static Bool
via_vt1632_mode_fixup(xf86OutputPtr output, DisplayModePtr mode,
                   DisplayModePtr adjusted_mode)
{
    return TRUE;
}

static void
via_vt1632_prepare(xf86OutputPtr output)
{
}

static void
via_vt1632_commit(xf86OutputPtr output)
{
}

static void
via_vt1632_mode_set(xf86OutputPtr output, DisplayModePtr mode,
                    DisplayModePtr adjusted_mode)
{
    ScrnInfoPtr pScrn = output->scrn;
    drmmode_crtc_private_ptr iga = output->crtc->driver_private;
    viaVT1632RecPtr pVIAVT1632Rec = output->driver_private;

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered via_vt1632_mode_set.\n"));

    if (output->crtc) {
        viaExtTMDSSetClockDriveStrength(pScrn, 0x03);
        viaExtTMDSSetDataDriveStrength(pScrn, 0x03);
        viaExtTMDSEnableIOPads(pScrn, 0x03);

        viaVT1632DumpRegisters(pScrn, pVIAVT1632Rec->VT1632I2CDev);
        viaVT1632InitRegisters(pScrn, pVIAVT1632Rec->VT1632I2CDev);
        viaVT1632DumpRegisters(pScrn, pVIAVT1632Rec->VT1632I2CDev);

        viaExtTMDSSetDisplaySource(pScrn, iga->index ? 0x01 : 0x00);
    }

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                "Exiting via_vt1632_mode_set.\n"));
}

static xf86OutputStatus
via_vt1632_detect(xf86OutputPtr output)
{
    xf86MonPtr mon;
    xf86OutputStatus status = XF86OutputStatusDisconnected;
    ScrnInfoPtr pScrn = output->scrn;
    viaVT1632RecPtr pVIAVT1632Rec = output->driver_private;

    /* Check for the DVI presence via VT1632 first before accessing
     * I2C bus. */
    if (viaVT1632Sense(pScrn, pVIAVT1632Rec->VT1632I2CDev)) {

        /* Since DVI presence was established, access the I2C bus
         * assigned to DVI. */
        mon = xf86OutputGetEDID(output, pVIAVT1632Rec->VT1632I2CDev->pI2CBus);

        /* Is the interface type digital? */
        if (mon && DIGITAL(mon->features.input_type)) {
            status = XF86OutputStatusConnected;
            xf86DrvMsg(pScrn->scrnIndex, X_PROBED,
                        "Detected a monitor connected to DVI.\n");
            xf86OutputSetEDID(output, mon);
        } else {
            xf86DrvMsg(pScrn->scrnIndex, X_PROBED,
                        "Could not obtain EDID from a monitor "
                        "connected to DVI.\n");
        }
    }

    return status;
}

#ifdef RANDR_12_INTERFACE
static Bool
via_vt1632_set_property(xf86OutputPtr output, Atom property,
                     RRPropertyValuePtr value)
{
    return TRUE;
}

static Bool
via_vt1632_get_property(xf86OutputPtr output, Atom property)
{
    return FALSE;
}
#endif

static void
via_vt1632_destroy(xf86OutputPtr output)
{
}

const xf86OutputFuncsRec via_vt1632_funcs = {
    .create_resources   = via_vt1632_create_resources,
    .dpms               = via_vt1632_dpms,
    .save               = via_vt1632_save,
    .restore            = via_vt1632_restore,
    .mode_valid         = via_vt1632_mode_valid,
    .mode_fixup         = via_vt1632_mode_fixup,
    .prepare            = via_vt1632_prepare,
    .commit             = via_vt1632_commit,
    .mode_set           = via_vt1632_mode_set,
    .detect             = via_vt1632_detect,
    .get_modes          = xf86OutputGetEDIDModes,
#ifdef RANDR_12_INTERFACE
    .set_property       = via_vt1632_set_property,
#endif
#ifdef RANDR_13_INTERFACE
    .get_property       = via_vt1632_get_property,
#endif
    .destroy            = via_vt1632_destroy,
};

Bool
viaVT1632Init(ScrnInfoPtr pScrn, I2CBusPtr pI2CBus)
{
    xf86OutputPtr output;
    VIAPtr pVia = VIAPTR(pScrn);
    viaVT1632RecPtr pVIAVT1632Rec = NULL;
    I2CDevPtr pI2CDevice = NULL;
    I2CSlaveAddr i2cAddr = 0x10;
    CARD8 buf;
    CARD16 vendorID, deviceID;
    Bool status = FALSE;
    char outputNameBuffer[32];

    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Entered viaVT1632Init.\n"));

    if (!xf86I2CProbeAddress(pI2CBus, i2cAddr)) {
        xf86DrvMsg(pScrn->scrnIndex, X_PROBED,
                    "I2C device not found.\n");
        goto exit;
    }

    pI2CDevice = xf86CreateI2CDevRec();
    if (!pI2CDevice) {
        xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
                    "Failed to create an I2C bus device record.\n");
        goto exit;
    }

    pI2CDevice->DevName = "VT1632";
    pI2CDevice->SlaveAddr = i2cAddr;
    pI2CDevice->pI2CBus = pI2CBus;
    if (!xf86I2CDevInit(pI2CDevice)) {
        xf86DestroyI2CDevRec(pI2CDevice, TRUE);
        xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
                    "Failed to initialize a device on I2C bus.\n");
        goto exit;
    }

    xf86I2CReadByte(pI2CDevice, 0, &buf);
    vendorID = buf;
    xf86I2CReadByte(pI2CDevice, 1, &buf);
    vendorID |= buf << 8;
    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Vendor ID: 0x%04x\n", vendorID));

    xf86I2CReadByte(pI2CDevice, 2, &buf);
    deviceID = buf;
    xf86I2CReadByte(pI2CDevice, 3, &buf);
    deviceID |= buf << 8;
    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Device ID: 0x%04x\n", deviceID));

    if ((vendorID != 0x1106) || (deviceID != 0x3192)) {
        xf86DestroyI2CDevRec(pI2CDevice, TRUE);
        xf86DrvMsg(pScrn->scrnIndex, X_PROBED,
                    "VT1632 external TMDS transmitter not detected.\n");
        goto exit;
    }

    xf86DrvMsg(pScrn->scrnIndex, X_PROBED,
                "VT1632 external TMDS transmitter detected.\n");

    pVIAVT1632Rec = xnfcalloc(1, sizeof(viaVT1632Rec));
    if (!pVIAVT1632Rec) {
        xf86DestroyI2CDevRec(pI2CDevice, TRUE);
        xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
                    "Failed to allocate working storage for VT1632.\n");
        goto exit;
    }

    // Remembering which I2C bus is used for VT1632.
    pVIAVT1632Rec->VT1632I2CDev = pI2CDevice;

    xf86I2CReadByte(pI2CDevice, 0x06, &buf);
    pVIAVT1632Rec->DotclockMin = buf * 1000;

    xf86I2CReadByte(pI2CDevice, 0x07, &buf);
    pVIAVT1632Rec->DotclockMax = (buf + 65) * 1000;

    xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Supported VT1632 Dot Clock Range: "
                "%d to %d MHz\n",
                pVIAVT1632Rec->DotclockMin / 1000,
                pVIAVT1632Rec->DotclockMax / 1000);

    /* The code to dynamically designate the particular DVI (i.e., DVI-1,
     * DVI-2, etc.) for xrandr was borrowed from xf86-video-r128 DDX. */
    sprintf(outputNameBuffer, "DVI-%d", (pVia->numberDVI + 1));
    output = xf86OutputCreate(pScrn, &via_vt1632_funcs, outputNameBuffer);
    if (!output) {
        free(pVIAVT1632Rec);
        xf86DestroyI2CDevRec(pI2CDevice, TRUE);
        xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
                    "Failed to allocate X Server display output record for "
                    "VT1632.\n");
        goto exit;
    }

    output->driver_private = pVIAVT1632Rec;

    /* Since there are two (2) display controllers registered with the
     * X.Org Server and both IGA1 and IGA2 can handle DVI without any
     * limitations, possible_crtcs should be set to 0x3 (0b11) so that
     * either display controller can get assigned to handle DVI. */
    output->possible_crtcs = (1 << 1) | (1 << 0);

    output->possible_clones = 0;
    output->interlaceAllowed = FALSE;
    output->doubleScanAllowed = FALSE;

    viaVT1632DumpRegisters(pScrn, pI2CDevice);

    pVia->numberDVI++;
    status = TRUE;
exit:
    DEBUG(xf86DrvMsg(pScrn->scrnIndex, X_INFO,
                        "Exiting viaVT1632Init.\n"));
    return status;
}
