/*
 * pdisk.r
 */

/*
 * Copyright 1997 by Apple Computer, Inc.
 *              All Rights Reserved 
 *  
 * Permission to use, copy, modify, and distribute this software and 
 * its documentation for any purpose and without fee is hereby granted, 
 * provided that the above copyright notice appears in all copies and 
 * that both the copyright notice and this permission notice appear in 
 * supporting documentation. 
 *  
 * APPLE COMPUTER DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE 
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE. 
 *  
 * IN NO EVENT SHALL APPLE COMPUTER BE LIABLE FOR ANY SPECIAL, INDIRECT, OR 
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM 
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN ACTION OF CONTRACT, 
 * NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION 
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 
 */

#ifndef SystemSevenOrLater
#define SystemSevenOrLater	1
#endif
#include "Types.r"
#include "SysTypes.r"
#include "version.h"


resource 'vers' (1) {
    kVersionMajor,
    kVersionMinor*0x10 + kVersionBugFix,
    kVersionStage,
    kVersionDelta,
    verUS,
    VERSION,
    $$format(
	"%s - %4d%02d%02d    "
	"? 1992-1998 Apple Computer Inc. All Rights Reserved. Modifications ? %4d Eryk Vershen",
	VERSION, $$year, $$month, $$day,
	$$year
    ),
};


type 'PDSK' as 'STR ';
resource 'PDSK' (0, "Owner Resource", purgeable) {
    $$format(
	"pdisk\n? 1992-1998 Apple Computer Inc. All Rights Reserved. Modifications ? %4d Eryk Vershen",
	$$year
    )
};

resource 'BNDL' (128) {
    'PDSK',
    0,
    {
	'FREF',	{ 0, 128 },
	'ICN#',	{ 0, 128 }
    }
};

resource 'FREF' (128) {
    'APPL',
    0,
    ""
};
resource 'icl8' (128) {
    $"FFFF FFFF FFFF FFFF FFFF FFFF 0000 0000"
    $"0000 FFFF FFFF FFFF 0000 0000 0000 0000"
    $"FF2B 2B2B 2B2B 2B2B 2B2B 2BFF 0000 0000"
    $"00FF 0808 0808 0808 FF00 0000 0000 0000"
    $"FF2B 2B2B 2B2B 2B2B 2B2B FF00 0000 0000"
    $"FF08 0808 0808 0808 08FF 0000 0000 0000"
    $"FFFC FCFC FCFC FCFC FCFC FF00 0000 00FF"
    $"0808 FFFF 0808 0808 0808 FF00 0000 0000"
    $"FF00 0000 0000 0000 0000 FF00 0000 00FF"
    $"FFFF 0000 FF08 0808 0808 08FF 0000 0000"
    $"FF2B 2B2B 2B2B 2B2B 2B2B FF00 FFFF FF08"
    $"08FF FFFF FFFF FFFF FF08 0808 FFFF FFFF"
    $"FF2B 2B2B 2B2B 2B2B 2B2B FF00 0000 FF08"
    $"0808 FFFF 0808 0808 0808 0808 08FF FFFF"
    $"FFFF FFFF FFFF FFFF FFFF FF00 0000 00FF"
    $"0808 0808 0808 0808 0808 0808 08FF FFFF"
    $"00FF F7FC F7FC F7FC F7FF 0000 0000 0000"
    $"FF08 0808 0808 0808 0808 0808 08FF FFFF"
    $"00FF FFFF FBFB FBFF FFFF 0000 0000 0000"
    $"00FF FF08 0808 0808 0808 0808 08FF FFFF"
    $"0000 0000 FFFF FF00 0000 0000 0000 0000"
    $"0000 00FF FFFF FFFF FFFF FF08 08FF FFFF"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 0000 0000 0000 00FF FFFF FFFF"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 0000 0000 0000 0000 00FF FFFF"
    $"0000 0000 0000 0000 FFFF FFFF FFFF FFFF"
    $"FFFF FFFF FFFF FF00 0000 0000 0000 0000"
    $"0000 0000 0000 0000 FF2B 2B2B 2B2B 2B2B"
    $"2B2B 2B2B 2B2B FF00 0000 0000 0000 0000"
    $"0000 0000 0000 00FF 2B2B 2B2B 2B2B 2B2B"
    $"2B2B 2B2B 2B2B FF00 0000 0000 0000 0000"
    $"0000 0000 0000 00FF FCFC FCFC FCFC FCFC"
    $"FCFC FCFC FCFC FF00 0000 0000 0000 0000"
    $"0000 0000 0000 00FF 0000 0000 0000 0000"
    $"0000 0000 0000 FF00 0000 0000 0000 0000"
    $"0000 0000 0000 00FF 2B2B 2B2B 2B2B 2B2B"
    $"2B2B 2B2B 2BFF 0000 0000 0000 0000 0000"
    $"0000 0000 0000 00FF 2B2B 2B2B 2B2B 2B2B"
    $"2B2B 2B2B FF00 0000 0000 0000 0000 0000"
    $"0000 0000 0000 00FF FFFF FFFF FFFF FFFF"
    $"FFFF FFFF FF00 0000 0000 0000 0000 0000"
    $"0000 0000 0000 FFFC F7FC F7FC F7FC F7FC"
    $"F7FC F7FC FF00 00FF FFFF FFFF FFFF FFFF"
    $"0000 0000 0000 FFFF FFFF FFFF FFFF FFFF"
    $"FFFF FFFF FF00 00FF 2B2B 2B2B 2B2B 2BFF"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 0000 00FF 2B2B 2B2B 2B2B 2BFF"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 0000 00FF FCFC E3E3 E3FC FCFF"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 0000 00FF 0000 0000 0000 00FF"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 0000 FF2B 2B2B 2B2B 2B2B 2BFF"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 00FF 2B2B 2B2B 2B2B 2B2B 2BFF"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 00FF FFFF FFFF FFFF FFFF FFFF"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 00FF F7FC F7FC F7FC F7FC FF00"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 00FF FFFF FFFB FBFB FFFF FF00"
    $"0000 0000 0000 0000 0000 0000 0000 0000"
    $"0000 0000 0000 0000 00FF FFFF"
};

resource 'icl4' (128) {
    $"FFFF FFFF FFFF 0000 00FF FFFF 0000 0000"
    $"FCCC CCCC CCCF 0000 0F02 0202 F000 0000"
    $"FCCC CCCC CCF0 0000 F020 2020 2F00 0000"
    $"FEEE EEEE EEF0 000F 02FF 0202 02F0 0000"
    $"F000 0000 00F0 000F FF00 F020 202F 0000"
    $"FCCC CCCC CCF0 FFF2 0FFF FFFF F202 FFFF"
    $"FCCC CCCC CCF0 00F0 20FF 2020 2020 2FFF"
    $"FFFF FFFF FFF0 000F 0202 0202 0202 0FFF"
    $"0FCE CECE CF00 0000 F020 2020 2020 2FFF"
    $"0FFF EEEF FF00 0000 0FF2 0202 0202 0FFF"
    $"0000 FFF0 0000 0000 000F FFFF FFF0 2FFF"
    $"0000 0000 0000 0000 0000 0000 000F FFFF"
    $"0000 0000 0000 0000 0000 0000 0000 0FFF"
    $"0000 0000 FFFF FFFF FFFF FFF0 0000 0000"
    $"0000 0000 FCCC CCCC CCCC CCF0 0000 0000"
    $"0000 000F CCCC CCCC CCCC CCF0 0000 0000"
    $"0000 000F EEEE EEEE EEEE EEF0 0000 0000"
    $"0000 000F 0000 0000 0000 00F0 0000 0000"
    $"0000 000F CCCC CCCC CCCC CF00 0000 0000"
    $"0000 000F CCCC CCCC CCCC F000 0000 0000"
    $"0000 000F FFFF FFFF FFFF F000 0000 0000"
    $"0000 00FE CECE CECE CECE F00F FFFF FFFF"
    $"0000 00FF FFFF FFFF FFFF F00F CCCC CCCF"
    $"0000 0000 0000 0000 0000 000F CCCC CCCF"
    $"0000 0000 0000 0000 0000 000F EE88 8EEF"
    $"0000 0000 0000 0000 0000 000F 0000 000F"
    $"0000 0000 0000 0000 0000 00FC CCCC CCCF"
    $"0000 0000 0000 0000 0000 0FCC CCCC CCCF"
    $"0000 0000 0000 0000 0000 0FFF FFFF FFFF"
    $"0000 0000 0000 0000 0000 0FCE CECE CEF0"
    $"0000 0000 0000 0000 0000 0FFF FEEE FFF0"
    $"0000 0000 0000 0000 0000 0000 0FFF"
};

resource 'ICN#' (128) {
    {
/* 1 */ $"FFF0 3F00 8010 4080 8020 8040 FFE1 3020"
	$"8021 C810 802E 7F8F 8022 3007 FFE1 0007"
	$"5540 8007 7FC0 6007 0E00 1FE7 0000 001F"
	$"0000 0007 00FF FE00 0080 0200 0100 0200"
	$"01FF FE00 0100 0200 0100 0400 0100 0800"
	$"01FF F800 0355 59FF 03FF F901 0000 0101"
	$"0000 01FF 0000 0101 0000 0201 0000 0401"
	$"0000 07FF 0000 0556 0000 07FE 0000 0070",

/* 2 */ $"FFF0 3F00 FFF0 7F80 FFE0 FFC0 FFE1 FFE0"
	$"FFE1 FFF0 FFEF FFFF FFE3 FFFF FFE1 FFFF"
	$"7FC0 FFFF 7FC0 7FFF 0E00 1FFF 0000 001F"
	$"0000 0007 00FF FE00 00FF FE00 01FF FE00"
	$"01FF FE00 01FF FE00 01FF FC00 01FF F800"
	$"01FF F800 03FF F9FF 03FF F9FF 0000 01FF"
	$"0000 01FF 0000 01FF 0000 03FF 0000 07FF"
	$"0000 07FF 0000 07FE 0000 07FE 0000 0070"
    }
};

resource 'ics#' (128) {
    {
/* 1 */ $"FC30 8448 B4A7 8B7B 7083 007F 0003 1FF0"
	$"1010 1010 2020 3FDF 0011 0011 0021 003E",
/* 2 */ $"FC30 FC78 FCFF FBFF 70FF 007F 0003 1FF0"
	$"1FF0 1FF0 3FE0 3FDF 001F 001F 003F 003E"
    }
};

resource 'ics4' (128) {
    $"FFFF FF00 00FF 0000 FCCC CF00 0F02 F000"
    $"FC38 CF00 F0F0 2FFF FDDD F0FF 2FFF F2FF"
    $"0FFF 0000 F020 20FF 0000 0000 0FFF FFFF"
    $"0000 0000 0000 00FF 000F FFFF FFFF 0000"
    $"000F CCCC CCCF 0000 000F CCCC CCCF 0000"
    $"00FD DDDD DDF0 0000 00FF FFFF FF0F FFFF"
    $"0000 0000 000F CCCF 0000 0000 000F CCCF"
    $"0000 0000 00FD DDDF 0000 0000 00FF FFF0"
};

resource 'ics8' (128) {
    $"FFFF FFFF FFFF 0000 0000 FFFF 0000 0000"
    $"FF2B 2B2B 2BFF 0000 00FF 0808 FF00 0000"
    $"FF2B D8E3 2BFF 0000 FF08 FF08 08FF FFFF"
    $"FFF9 F9F9 FF00 FFFF 08FF FFFF FF08 FFFF"
    $"00FF FFFF 0000 0000 FF08 0808 0808 FFFF"
    $"0000 0000 0000 0000 00FF FFFF FFFF FFFF"
    $"0000 0000 0000 0000 0000 0000 0000 FFFF"
    $"0000 00FF FFFF FFFF FFFF FFFF 0000 0000"
    $"0000 00FF 2B2B 2B2B 2B2B 2BFF 0000 0000"
    $"0000 00FF 2B2B 2B2B 2B2B 2BFF 0000 0000"
    $"0000 FFF9 F9F9 F9F9 F9F9 FF00 0000 0000"
    $"0000 FFFF FFFF FFFF FFFF 00FF FFFF FFFF"
    $"0000 0000 0000 0000 0000 00FF 2B2B 2BFF"
    $"0000 0000 0000 0000 0000 00FF 2B2B 2BFF"
    $"0000 0000 0000 0000 0000 FFF9 F9F9 F9FF"
    $"0000 0000 0000 0000 0000 FFFF FFFF FF"
};

