/*
 * Simulator of microcontrollers (glob.cc)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/


#include <stdio.h>

#include "stypes.h"


/*
 * Names of instructions
 */
 
struct dis_entry disass_51[]= {
  { 0x00, 0xff, ' ', 1, "NOP"},
  { 0x01, 0xff, 'A', 2, "AJMP %A"},
  { 0x02, 0xff, 'L', 3, "LJMP %l"},
  { 0x03, 0xff, ' ', 1, "RR A"},
  { 0x04, 0xff, ' ', 1, "INC A"},
  { 0x05, 0xff, ' ', 2, "INC %a"},
  { 0x06, 0xff, ' ', 1, "INC @R0"},
  { 0x07, 0xff, ' ', 1, "INC @R1"},
  { 0x08, 0xff, ' ', 1, "INC R0"},
  { 0x09, 0xff, ' ', 1, "INC R1"},
  { 0x0a, 0xff, ' ', 1, "INC R2"},
  { 0x0b, 0xff, ' ', 1, "INC R3"},
  { 0x0c, 0xff, ' ', 1, "INC R4"},
  { 0x0d, 0xff, ' ', 1, "INC R5"},
  { 0x0e, 0xff, ' ', 1, "INC R6"},
  { 0x0f, 0xff, ' ', 1, "INC R7"},
  { 0x10, 0xff, 'R', 3, "JBC %b,%R"},
  { 0x11, 0xff, 'a', 2, "ACALL %A"},
  { 0x12, 0xff, 'l', 3, "LCALL %l"},
  { 0x13, 0xff, ' ', 1, "RRC A"},
  { 0x14, 0xff, ' ', 1, "DEC A"},
  { 0x15, 0xff, ' ', 2, "DEC %a"},
  { 0x16, 0xff, ' ', 1, "DEC @R0"},
  { 0x17, 0xff, ' ', 1, "DEC @R1"},
  { 0x18, 0xff, ' ', 1, "DEC R0"},
  { 0x19, 0xff, ' ', 1, "DEC R1"},
  { 0x1a, 0xff, ' ', 1, "DEC R2"},
  { 0x1b, 0xff, ' ', 1, "DEC R3"},
  { 0x1c, 0xff, ' ', 1, "DEC R4"},
  { 0x1d, 0xff, ' ', 1, "DEC R5"},
  { 0x1e, 0xff, ' ', 1, "DEC R6"},
  { 0x1f, 0xff, ' ', 1, "DEC R7"},
  { 0x20, 0xff, 'R', 3, "JB %b,%R"},
  { 0x21, 0xff, 'A', 2, "AJMP %A"},
  { 0x22, 0xff, '_', 1, "RET"},
  { 0x23, 0xff, ' ', 1, "RL A"},
  { 0x24, 0xff, ' ', 2, "ADD A,#%d"},
  { 0x25, 0xff, ' ', 2, "ADD A,%a"},
  { 0x26, 0xff, ' ', 1, "ADD A,@R0"},
  { 0x27, 0xff, ' ', 1, "ADD A,@R1"},
  { 0x28, 0xff, ' ', 1, "ADD A,R0"},
  { 0x29, 0xff, ' ', 1, "ADD A,R1"},
  { 0x2a, 0xff, ' ', 1, "ADD A,R2"},
  { 0x2b, 0xff, ' ', 1, "ADD A,R3"},
  { 0x2c, 0xff, ' ', 1, "ADD A,R4"},
  { 0x2d, 0xff, ' ', 1, "ADD A,R5"},
  { 0x2e, 0xff, ' ', 1, "ADD A,R6"},
  { 0x2f, 0xff, ' ', 1, "ADD A,R7"},
  { 0x30, 0xff, 'R', 3, "JNB %b,%R"},
  { 0x31, 0xff, 'a', 2, "ACALL %A"},
  { 0x32, 0xff, '_', 1, "RETI"},
  { 0x33, 0xff, ' ', 1, "RLC A"},
  { 0x34, 0xff, ' ', 2, "ADDC A,#%d"},
  { 0x35, 0xff, ' ', 2, "ADDC A,%a"},
  { 0x36, 0xff, ' ', 1, "ADDC A,@R0"},
  { 0x37, 0xff, ' ', 1, "ADDC A,@R1"},
  { 0x38, 0xff, ' ', 1, "ADDC A,R0"},
  { 0x39, 0xff, ' ', 1, "ADDC A,R1"},
  { 0x3a, 0xff, ' ', 1, "ADDC A,R2"},
  { 0x3b, 0xff, ' ', 1, "ADDC A,R3"},
  { 0x3c, 0xff, ' ', 1, "ADDC A,R4"},
  { 0x3d, 0xff, ' ', 1, "ADDC A,R5"},
  { 0x3e, 0xff, ' ', 1, "ADDC A,R6"},
  { 0x3f, 0xff, ' ', 1, "ADDC A,R7"},
  { 0x40, 0xff, 'r', 2, "JC %r"},
  { 0x41, 0xff, 'A', 2, "AJMP %A"},
  { 0x42, 0xff, ' ', 2, "ORL %a,A"},
  { 0x43, 0xff, ' ', 3, "ORL %a,#%D"},
  { 0x44, 0xff, ' ', 2, "ORL A,#%d"},
  { 0x45, 0xff, ' ', 2, "ORL A,%a"},
  { 0x46, 0xff, ' ', 1, "ORL A,@R0"},
  { 0x47, 0xff, ' ', 1, "ORL A,@R1"},
  { 0x48, 0xff, ' ', 1, "ORL A,R0"},
  { 0x49, 0xff, ' ', 1, "ORL A,R1"},
  { 0x4a, 0xff, ' ', 1, "ORL A,R2"},
  { 0x4b, 0xff, ' ', 1, "ORL A,R3"},
  { 0x4c, 0xff, ' ', 1, "ORL A,R4"},
  { 0x4d, 0xff, ' ', 1, "ORL A,R5"},
  { 0x4e, 0xff, ' ', 1, "ORL A,R6"},
  { 0x4f, 0xff, ' ', 1, "ORL A,R7"},
  { 0x50, 0xff, 'r', 2, "JNC %r"},
  { 0x51, 0xff, 'a', 2, "ACALL %A"},
  { 0x52, 0xff, ' ', 2, "ANL %a,A"},
  { 0x53, 0xff, ' ', 3, "ANL %a,#%D"},
  { 0x54, 0xff, ' ', 2, "ANL A,#%d"},
  { 0x55, 0xff, ' ', 2, "ANL A,%a"},
  { 0x56, 0xff, ' ', 1, "ANL A,@R0"},
  { 0x57, 0xff, ' ', 1, "ANL A,@R1"},
  { 0x58, 0xff, ' ', 1, "ANL A,R0"},
  { 0x59, 0xff, ' ', 1, "ANL A,R1"},
  { 0x5a, 0xff, ' ', 1, "ANL A,R2"},
  { 0x5b, 0xff, ' ', 1, "ANL A,R3"},
  { 0x5c, 0xff, ' ', 1, "ANL A,R4"},
  { 0x5d, 0xff, ' ', 1, "ANL A,R5"},
  { 0x5e, 0xff, ' ', 1, "ANL A,R6"},
  { 0x5f, 0xff, ' ', 1, "ANL A,R7"},
  { 0x60, 0xff, 'r', 2, "JZ %r"},
  { 0x61, 0xff, 'A', 2, "AJMP %A"},
  { 0x62, 0xff, ' ', 2, "XRL %a,A"},
  { 0x63, 0xff, ' ', 3, "XRL %a,#%D"},
  { 0x64, 0xff, ' ', 2, "XRL A,#%d"},
  { 0x65, 0xff, ' ', 2, "XRL A,%a"},
  { 0x66, 0xff, ' ', 1, "XRL A,@R0"},
  { 0x67, 0xff, ' ', 1, "XRL A,@R1"},
  { 0x68, 0xff, ' ', 1, "XRL A,R0"},
  { 0x69, 0xff, ' ', 1, "XRL A,R1"},
  { 0x6a, 0xff, ' ', 1, "XRL A,R2"},
  { 0x6b, 0xff, ' ', 1, "XRL A,R3"},
  { 0x6c, 0xff, ' ', 1, "XRL A,R4"},
  { 0x6d, 0xff, ' ', 1, "XRL A,R5"},
  { 0x6e, 0xff, ' ', 1, "XRL A,R6"},
  { 0x6f, 0xff, ' ', 1, "XRL A,R7"},
  { 0x70, 0xff, 'r', 2, "JNZ %r"},
  { 0x71, 0xff, 'a', 2, "ACALL %A"},
  { 0x72, 0xff, ' ', 2, "ORL C,%b"},
  { 0x73, 0xff, '_', 1, "JMP @A+DPTR"},
  { 0x74, 0xff, ' ', 2, "MOV A,#%d"},
  { 0x75, 0xff, ' ', 3, "MOV %a,#%D"},
  { 0x76, 0xff, ' ', 2, "MOV @R0,#%d"},
  { 0x77, 0xff, ' ', 2, "MOV @R1,#%d"},
  { 0x78, 0xff, ' ', 2, "MOV R0,#%d"},
  { 0x79, 0xff, ' ', 2, "MOV R1,#%d"},
  { 0x7a, 0xff, ' ', 2, "MOV R2,#%d"},
  { 0x7b, 0xff, ' ', 2, "MOV R3,#%d"},
  { 0x7c, 0xff, ' ', 2, "MOV R4,#%d"},
  { 0x7d, 0xff, ' ', 2, "MOV R5,#%d"},
  { 0x7e, 0xff, ' ', 2, "MOV R6,#%d"},
  { 0x7f, 0xff, ' ', 2, "MOV R7,#%d"},
  { 0x80, 0xff, 's', 2, "SJMP %r"},
  { 0x81, 0xff, 'A', 2, "AJMP %A"},
  { 0x82, 0xff, ' ', 2, "ANL C,%b"},
  { 0x83, 0xff, ' ', 1, "MOVC A,@A+PC"},
  { 0x84, 0xff, ' ', 1, "DIV AB"},
  { 0x85, 0xff, ' ', 3, "MOV %8,%a"},
  { 0x86, 0xff, ' ', 2, "MOV %a,@R0"},
  { 0x87, 0xff, ' ', 2, "MOV %a,@R1"},
  { 0x88, 0xff, ' ', 2, "MOV %a,R0"},
  { 0x89, 0xff, ' ', 2, "MOV %a,R1"},
  { 0x8a, 0xff, ' ', 2, "MOV %a,R2"},
  { 0x8b, 0xff, ' ', 2, "MOV %a,R3"},
  { 0x8c, 0xff, ' ', 2, "MOV %a,R4"},
  { 0x8d, 0xff, ' ', 2, "MOV %a,R5"},
  { 0x8e, 0xff, ' ', 2, "MOV %a,R6"},
  { 0x8f, 0xff, ' ', 2, "MOV %a,R7"},
  { 0x90, 0xff, ' ', 3, "MOV DPTR,#%6"},
  { 0x91, 0xff, 'a', 2, "ACALL %A"},
  { 0x92, 0xff, ' ', 2, "MOV %b,C"},
  { 0x93, 0xff, ' ', 1, "MOVC A,@A+DPTR"},
  { 0x94, 0xff, ' ', 2, "SUBB A,#%d"},
  { 0x95, 0xff, ' ', 2, "SUBB A,%a"},
  { 0x96, 0xff, ' ', 1, "SUBB A,@R0"},
  { 0x97, 0xff, ' ', 1, "SUBB A,@R1"},
  { 0x98, 0xff, ' ', 1, "SUBB A,R0"},
  { 0x99, 0xff, ' ', 1, "SUBB A,R1"},
  { 0x9a, 0xff, ' ', 1, "SUBB A,R2"},
  { 0x9b, 0xff, ' ', 1, "SUBB A,R3"},
  { 0x9c, 0xff, ' ', 1, "SUBB A,R4"},
  { 0x9d, 0xff, ' ', 1, "SUBB A,R5"},
  { 0x9e, 0xff, ' ', 1, "SUBB A,R6"},
  { 0x9f, 0xff, ' ', 1, "SUBB A,R7"},
  { 0xa0, 0xff, ' ', 2, "ORL C,/%b"},
  { 0xa1, 0xff, 'A', 2, "AJMP %A"},
  { 0xa2, 0xff, ' ', 2, "MOV C,%b"},
  { 0xa3, 0xff, ' ', 1, "INC DPTR"},
  { 0xa4, 0xff, ' ', 1, "MUL AB"},
  { 0xa5, 0xff, '_', 1, "-"},
  { 0xa6, 0xff, ' ', 2, "MOV @R0,%a"},
  { 0xa7, 0xff, ' ', 2, "MOV @R1,%a"},
  { 0xa8, 0xff, ' ', 2, "MOV R0,%a"},
  { 0xa9, 0xff, ' ', 2, "MOV R1,%a"},
  { 0xaa, 0xff, ' ', 2, "MOV R2,%a"},
  { 0xab, 0xff, ' ', 2, "MOV R3,%a"},
  { 0xac, 0xff, ' ', 2, "MOV R4,%a"},
  { 0xad, 0xff, ' ', 2, "MOV R5,%a"},
  { 0xae, 0xff, ' ', 2, "MOV R6,%a"},
  { 0xaf, 0xff, ' ', 2, "MOV R7,%a"},
  { 0xb0, 0xff, ' ', 2, "ANL C,/%b"},
  { 0xb1, 0xff, 'a', 2, "ACALL %A"},
  { 0xb2, 0xff, ' ', 2, "CPL %b"},
  { 0xb3, 0xff, ' ', 1, "CPL C"},
  { 0xb4, 0xff, 'R', 3, "CJNE A,#%d,%R"},
  { 0xb5, 0xff, 'R', 3, "CJNE A,%a,%R"},
  { 0xb6, 0xff, 'R', 3, "CJNE @R0,#%d,%R"},
  { 0xb7, 0xff, 'R', 3, "CJNE @R1,#%d,%R"},
  { 0xb8, 0xff, 'R', 3, "CJNE R0,#%d,%R"},
  { 0xb9, 0xff, 'R', 3, "CJNE R1,#%d,%R"},
  { 0xba, 0xff, 'R', 3, "CJNE R2,#%d,%R"},
  { 0xbb, 0xff, 'R', 3, "CJNE R3,#%d,%R"},
  { 0xbc, 0xff, 'R', 3, "CJNE R4,#%d,%R"},
  { 0xbd, 0xff, 'R', 3, "CJNE R5,#%d,%R"},
  { 0xbe, 0xff, 'R', 3, "CJNE R6,#%d,%R"},
  { 0xbf, 0xff, 'R', 3, "CJNE R7,#%d,%R"},
  { 0xc0, 0xff, ' ', 2, "PUSH %a"},
  { 0xc1, 0xff, 'A', 2, "AJMP %A"},
  { 0xc2, 0xff, ' ', 2, "CLR %b"},
  { 0xc3, 0xff, ' ', 1, "CLR C"},
  { 0xc4, 0xff, ' ', 1, "SWAP A"},
  { 0xc5, 0xff, ' ', 2, "XCH A,%a"},
  { 0xc6, 0xff, ' ', 1, "XCH A,@R0"},
  { 0xc7, 0xff, ' ', 1, "XCH A,@R1"},
  { 0xc8, 0xff, ' ', 1, "XCH A,R0"},
  { 0xc9, 0xff, ' ', 1, "XCH A,R1"},
  { 0xca, 0xff, ' ', 1, "XCH A,R2"},
  { 0xcb, 0xff, ' ', 1, "XCH A,R3"},
  { 0xcc, 0xff, ' ', 1, "XCH A,R4"},
  { 0xcd, 0xff, ' ', 1, "XCH A,R5"},
  { 0xce, 0xff, ' ', 1, "XCH A,R6"},
  { 0xcf, 0xff, ' ', 1, "XCH A,R7"},
  { 0xd0, 0xff, ' ', 2, "POP %a"},
  { 0xd1, 0xff, 'a', 2, "ACALL %A"},
  { 0xd2, 0xff, ' ', 2, "SETB %b"},
  { 0xd3, 0xff, ' ', 1, "SETB C"},
  { 0xd4, 0xff, ' ', 1, "DA A"},
  { 0xd5, 0xff, 'R', 3, "DJNZ %a,%R"},
  { 0xd6, 0xff, ' ', 1, "XCHD A,@R0"},
  { 0xd7, 0xff, ' ', 1, "XCHD A,@R1"},
  { 0xd8, 0xff, 'r', 2, "DJNZ R0,%r"},
  { 0xd9, 0xff, 'r', 2, "DJNZ R1,%r"},
  { 0xda, 0xff, 'r', 2, "DJNZ R2,%r"},
  { 0xdb, 0xff, 'r', 2, "DJNZ R3,%r"},
  { 0xdc, 0xff, 'r', 2, "DJNZ R4,%r"},
  { 0xdd, 0xff, 'r', 2, "DJNZ R5,%r"},
  { 0xde, 0xff, 'r', 2, "DJNZ R6,%r"},
  { 0xdf, 0xff, 'r', 2, "DJNZ R7,%r"},
  { 0xe0, 0xff, ' ', 1, "MOVX A,@DPTR"},
  { 0xe1, 0xff, 'A', 2, "AJMP %A"},
  { 0xe2, 0xff, ' ', 1, "MOVX A,@R0"},
  { 0xe3, 0xff, ' ', 1, "MOVX A,@R1"},
  { 0xe4, 0xff, ' ', 1, "CLR A"},
  { 0xe5, 0xff, ' ', 2, "MOV A,%a"},
  { 0xe6, 0xff, ' ', 1, "MOV A,@R0"},
  { 0xe7, 0xff, ' ', 1, "MOV A,@R1"},
  { 0xe8, 0xff, ' ', 1, "MOV A,R0"},
  { 0xe9, 0xff, ' ', 1, "MOV A,R1"},
  { 0xea, 0xff, ' ', 1, "MOV A,R2"},
  { 0xeb, 0xff, ' ', 1, "MOV A,R3"},
  { 0xec, 0xff, ' ', 1, "MOV A,R4"},
  { 0xed, 0xff, ' ', 1, "MOV A,R5"},
  { 0xee, 0xff, ' ', 1, "MOV A,R6"},
  { 0xef, 0xff, ' ', 1, "MOV A,R7"},
  { 0xf0, 0xff, ' ', 1, "MOVX @DPTR,A"},
  { 0xf1, 0xff, 'a', 2, "ACALL %A"},
  { 0xf2, 0xff, ' ', 1, "MOVX @R0,A"},
  { 0xf3, 0xff, ' ', 1, "MOVX @R1,A"},
  { 0xf4, 0xff, ' ', 1, "CPL A"},
  { 0xf5, 0xff, ' ', 2, "MOV %a,A"},
  { 0xf6, 0xff, ' ', 1, "MOV @R0,A"},
  { 0xf7, 0xff, ' ', 1, "MOV @R1,A"},
  { 0xf8, 0xff, ' ', 1, "MOV R0,A"},
  { 0xf9, 0xff, ' ', 1, "MOV R1,A"},
  { 0xfa, 0xff, ' ', 1, "MOV R2,A"},
  { 0xfb, 0xff, ' ', 1, "MOV R3,A"},
  { 0xfc, 0xff, ' ', 1, "MOV R4,A"},
  { 0xfd, 0xff, ' ', 1, "MOV R5,A"},
  { 0xfe, 0xff, ' ', 1, "MOV R6,A"},
  { 0xff, 0xff, ' ', 1, "MOV R7,A"},
  { 0, 0, 0, 0, NULL }
};


/*
 * Names of SFR cells
 */

struct name_entry sfr_tab51[]=
{
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xe0, "ACC"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xf0, "B"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xd0, "PSW"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x81, "SP"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x82, "DPL"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x83, "DPH"},
  {CPU_251|CPU_DS390F,            0x93, "DPX"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x80, "P0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x90, "P1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xa0, "P2"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xb0, "P3"},
  {CPU_ALL_51|CPU_ALL_52, 0xb8, "IP"},
  {CPU_ALL_51|CPU_ALL_52, 0xa8, "IE"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x89, "TMOD"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x88, "TCON"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8c, "TH0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8a, "TL0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8d, "TH1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8b, "TL1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x98, "SCON"},
  {CPU_DS390|CPU_DS390F,          0x99, "SBUF0"},
  {CPU_DS390|CPU_DS390F,          0xC1, "SBUF1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x99, "SBUF"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x87, "PCON"},
  {CPU_ALL_52|CPU_251, 0xc8, "T2CON"},
  {CPU_ALL_52|CPU_251, 0xcd, "TH2"},
  {CPU_ALL_52|CPU_251, 0xcc, "TL2"},
  {CPU_ALL_52|CPU_251, 0xcb, "RCAP2H"},
  {CPU_ALL_52|CPU_251, 0xca, "RCAP2L"},
  {CPU_251, 0x84, "DPXL"},
  {CPU_DS390|CPU_DS390F, 0x84, "DPL1"},
  {CPU_DS390|CPU_DS390F, 0x85, "DPH1"},
  {CPU_DS390|CPU_DS390F, 0x86, "DPS"},
  {CPU_89C51R|CPU_51R, 0x8e, "AUXR"},
  {CPU_51R|CPU_89C51R|CPU_251, 0xa6, "WDTRST"},
  {CPU_51R|CPU_89C51R|CPU_251, 0xa9, "SADDR"},
  {CPU_89C51R|CPU_51R, 0xb7, "IPH"},
  {CPU_251, 0xb7, "IPH0"},
  {CPU_251, 0xa8, "IE0"},
  {CPU_251, 0xb8, "IPL0"},
  {CPU_51R|CPU_89C51R|CPU_251, 0xb9, "SADEN"},
  {CPU_251, 0xbd, "SPH"},
  {CPU_51R|CPU_89C51R|CPU_251, 0xc9, "T2MOD"},
  {CPU_251, 0xd1, "PSW1"},
  {CPU_89C51R|CPU_251, 0xd8, "CCON"},
  {CPU_89C51R|CPU_251, 0xd9, "CMOD"},
  {CPU_89C51R|CPU_251, 0xda, "CCAPM0"},
  {CPU_89C51R|CPU_251, 0xdb, "CCAPM1"},
  {CPU_89C51R|CPU_251, 0xdc, "CCAPM2"},
  {CPU_89C51R|CPU_251, 0xdd, "CCAPM3"},
  {CPU_89C51R|CPU_251, 0xde, "CCAPM4"},
  {CPU_89C51R|CPU_251, 0xe9, "CL"},
  {CPU_89C51R|CPU_251, 0xea, "CCAP0L"},
  {CPU_89C51R|CPU_251, 0xeb, "CCAP1L"},
  {CPU_89C51R|CPU_251, 0xec, "CCAP2L"},
  {CPU_89C51R|CPU_251, 0xed, "CCAP3L"},
  {CPU_89C51R|CPU_251, 0xee, "CCAP4L"},
  {CPU_89C51R|CPU_251, 0xf9, "CH"},
  {CPU_89C51R|CPU_251, 0xfa, "CCAP0H"},
  {CPU_89C51R|CPU_251, 0xfb, "CCAP1H"},
  {CPU_89C51R|CPU_251, 0xfc, "CCAP2H"},
  {CPU_89C51R|CPU_251, 0xfd, "CCAP3H"},
  {CPU_89C51R|CPU_251, 0xfe, "CCAP4H"},
  {CPU_89C51R,         0xa2, "AUXR1"},
  {CPU_DS390F,         0x9B, "ESP"},
  {CPU_DS390F,         0x9D, "ACON"},
  {0, 0, NULL}
};


/*
 * Names of bits
 */

struct name_entry bit_tab51[]=
{
  /* PSW */
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xd7, "CY"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xd6, "AC"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xd5, "F0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xd4, "RS1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xd3, "RS0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xd2, "OV"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xd0, "P"},
  /* TCON */
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8f, "TF1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8e, "TR1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8d, "TF0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8c, "TR0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8b, "IE1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x8a, "IT1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x89, "IE0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x88, "IT0"},
  /* IE */
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xaf, "EA"},
  {CPU_89C51R|CPU_251, 0xae, "EC"},
  {CPU_ALL_52|CPU_251, 0xad, "ET2"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xac, "ES"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xab, "ET1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xaa, "EX1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xa9, "ET0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0xa8, "EX0"},
  /* IP */
  {CPU_89C51R|CPU_251, 0xbe, "PPC"},
  {CPU_ALL_52, 0xbd, "PT2"},
  {CPU_ALL_51|CPU_ALL_52, 0xbc, "PS"},
  {CPU_ALL_51|CPU_ALL_52, 0xbb, "PT1"},
  {CPU_ALL_51|CPU_ALL_52, 0xba, "PX1"},
  {CPU_ALL_51|CPU_ALL_52, 0xb9, "PT0"},
  {CPU_ALL_51|CPU_ALL_52, 0xb8, "PX0"},
  /* IPL0 */
  {CPU_251, 0xbe, "IPL0.6"},
  {CPU_251, 0xbd, "IPL0.5"},
  {CPU_251, 0xbc, "IPL0.4"},
  {CPU_251, 0xbb, "IPL0.3"},
  {CPU_251, 0xba, "IPL0.2"},
  {CPU_251, 0xb9, "IPL0.1"},
  {CPU_251, 0xb8, "IPL0.0"},
  /* SCON */
  {CPU_51R|CPU_89C51R|CPU_251, 0x9f, "FE/SM0"},
  {CPU_ALL_51|CPU_ALL_52, 0x9f, "SM0"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x9e, "SM1"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x9d, "SM2"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x9c, "REN"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x9b, "TB8"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x9a, "RB8"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x99, "TI"},
  {CPU_ALL_51|CPU_ALL_52|CPU_251, 0x98, "RI"},
  /* T2CON */
  {CPU_ALL_52|CPU_251, 0xcf, "TF2"},
  {CPU_ALL_52|CPU_251, 0xce, "EXF2"},
  {CPU_ALL_52|CPU_251, 0xcd, "RCLK"},
  {CPU_ALL_52|CPU_251, 0xcc, "TCLK"},
  {CPU_ALL_52|CPU_251, 0xcb, "EXEN2"},
  {CPU_ALL_52|CPU_251, 0xca, "TR2"},
  {CPU_ALL_52|CPU_251, 0xc9, "C/T2"},
  {CPU_ALL_52|CPU_251, 0xc8, "CP/RL2"},
  /* CCON */
  {CPU_89C51R|CPU_251, 0xdf, "CF"},
  {CPU_89C51R|CPU_251, 0xde, "CR"},
  {CPU_89C51R|CPU_251, 0xdc, "CCF4"},
  {CPU_89C51R|CPU_251, 0xdb, "CCF3"},
  {CPU_89C51R|CPU_251, 0xda, "CCF2"},
  {CPU_89C51R|CPU_251, 0xd9, "CCF1"},
  {CPU_89C51R|CPU_251, 0xd8, "CCF0"},
  /* P1 */
  {CPU_89C51R|CPU_251, 0x97, "CEX4"},
  {CPU_89C51R|CPU_251, 0x96, "CEX3"},
  {CPU_89C51R|CPU_251, 0x95, "CEX2"},
  {CPU_89C51R|CPU_251, 0x94, "CEX1"},
  {CPU_89C51R|CPU_251, 0x93, "CEX0"},
  {CPU_89C51R|CPU_251, 0x92, "EXI"},
  {CPU_89C51R|CPU_251, 0x91, "T2EX"},
  {CPU_89C51R|CPU_251, 0x90, "T2"},

  {0, 0, NULL}
};


/*
 * Information about different type of CPUs
 */

struct cpu_entry cpus_51[]=
{
  {"51"    , CPU_51, CPU_HMOS},
  {"8051"  , CPU_51, CPU_HMOS},
  {"8751"  , CPU_51, CPU_HMOS},
  {"C51"   , CPU_51, CPU_CMOS},
  {"80C51" , CPU_51, CPU_CMOS},
  {"87C51" , CPU_51, CPU_CMOS},
  {"31"    , CPU_31, CPU_HMOS},
  {"8031"  , CPU_31, CPU_HMOS},
  {"C31"   , CPU_31, CPU_CMOS},
  {"80C31" , CPU_31, CPU_CMOS},

  {"52"    , CPU_52, CPU_HMOS},
  {"8052"  , CPU_52, CPU_HMOS},
  {"8752"  , CPU_52, CPU_HMOS},
  {"C52"   , CPU_52, CPU_CMOS},
  {"80C52" , CPU_52, CPU_CMOS},
  {"87C52" , CPU_52, CPU_CMOS},
  {"32"    , CPU_32, CPU_HMOS},
  {"8032"  , CPU_32, CPU_HMOS},
  {"C32"   , CPU_32, CPU_CMOS},
  {"80C32" , CPU_32, CPU_CMOS},

  {"51R"   , CPU_51R, CPU_CMOS},
  {"51RA"  , CPU_51R, CPU_CMOS},
  {"51RB"  , CPU_51R, CPU_CMOS},
  {"51RC"  , CPU_51R, CPU_CMOS},
  {"C51R"  , CPU_51R, CPU_CMOS},
  {"C51RA" , CPU_51R, CPU_CMOS},
  {"C51RB" , CPU_51R, CPU_CMOS},
  {"C51RC" , CPU_51R, CPU_CMOS},

  {"89C51R", CPU_89C51R, CPU_CMOS},

  {"251"   , CPU_251, CPU_CMOS},
  {"C251"  , CPU_251, CPU_CMOS},
  {"DS390" , CPU_DS390, CPU_CMOS},
  {"DS390F" , CPU_DS390F, CPU_CMOS},
  {NULL, 0, 0}
};


/* End of s51.src/glob.cc */
