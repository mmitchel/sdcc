;--------------------------------------------------------
; File Created by SDCC : FreeWare ANSI-C Compiler
; Version 2.1.9Ga Sun Jan 16 17:31:12 2000

;--------------------------------------------------------
	.module _gptrput
;--------------------------------------------------------
; publics variables in this module
;--------------------------------------------------------
	.globl __gptrput
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; special function bits 
;--------------------------------------------------------
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area	DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG	(OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area	ISEG    (DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area	BSEG    (BIT)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area	XSEG    (XDATA)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area GSINIT (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG (CODE)
	G$_gptrput$0$0 ==.
;	_gptrput.c 26
;	-----------------------------------------
;	 function _gptrput
;	-----------------------------------------
__gptrput:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	_gptrput.c 72
	        xch      a,r0
		push     acc
		xch      a,r0
		push     acc
	    ;
	    ;   depending on the pointer type
	    ;
	        mov     a,b
		jz      00001$
	        dec     a
	        jz      00002$
	        dec     a
	        jz      00003$
	        dec     a
	        jz      00004$
		pop     acc
		sjmp    00005$
;
;       store into near space
;       
 00001$:
		pop     acc
		mov     r0,dpl
		mov     @r0,a
		sjmp    00005$
 00002$:
		pop     acc
		movx    @dptr,a
		sjmp    00005$
 00003$:
		pop     acc    ; do nothing
		sjmp    00005$
 00004$:
		pop     acc
		mov     r0,dpl
		movx    @r0,a
 00005$:
		xch     a,r0
		pop     acc
		xch     a,r0
00101$:
	C$_gptrput.c$73$1$1 ==.
	XG$_gptrput$0$0 ==.
	ret
	.area	CSEG    (CODE)