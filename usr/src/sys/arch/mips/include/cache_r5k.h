/*	$NetBSD: cache_r5k.h,v 1.4.22.1 2020/06/20 16:38:42 martin Exp $	*/

/*
 * Copyright 2001 Wasabi Systems, Inc.
 * All rights reserved.
 *
 * Written by Jason R. Thorpe for Wasabi Systems, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed for the NetBSD Project by
 *	Wasabi Systems, Inc.
 * 4. The name of Wasabi Systems, Inc. may not be used to endorse
 *    or promote products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#if defined(_KERNEL) && !defined(_LOCORE)

void	r5k_picache_sync_all(void);
void	r5k_picache_sync_range(register_t, vsize_t);
void	r5k_picache_sync_range_index(vaddr_t, vsize_t);

void	r5k_pdcache_wbinv_all(void);
void	r5k_pdcache_wbinv_range_index(vaddr_t, vsize_t);
void	r4600v1_pdcache_wbinv_range_32(register_t, vsize_t);
void	r4600v2_pdcache_wbinv_range_32(register_t, vsize_t);
void	vr4131v1_pdcache_wbinv_range_16(register_t, vsize_t);

void	r4600v1_pdcache_inv_range_32(register_t, vsize_t);
void	r4600v2_pdcache_inv_range_32(register_t, vsize_t);
void	r4600v1_pdcache_wb_range_32(register_t, vsize_t);
void	r4600v2_pdcache_wb_range_32(register_t, vsize_t);

void	r5k_enable_sdcache(void);

void	r5k_sdcache_wbinv_all(void);
void	r5k_sdcache_wbinv_range(register_t, vsize_t);
void	r5k_sdcache_wbinv_range_index(vaddr_t, vsize_t);
void	r5k_sdcache_inv_range(register_t, vsize_t);
void	r5k_sdcache_wb_range(register_t, vsize_t);

#endif /* _KERNEL && !_LOCORE */

#define CACHEOP_R5K_Page_Invalidate_S   0x17

#define R5K_SC_LINESIZE		32
#define R5K_SC_PAGESIZE		(R5K_SC_LINESIZE * 128)
#define R5K_SC_PAGEMASK		(R5K_SC_PAGESIZE - 1)

#define mips_r5k_round_page(x)	(((x) + (register_t)R5K_SC_PAGEMASK) \
				    & (register_t)R5K_SC_PAGEMASK)
#define mips_r5k_trunc_page(x)	((x) & (register_t)R5K_SC_PAGEMASK)
