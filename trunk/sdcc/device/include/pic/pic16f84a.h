//
// Register Declarations for Microchip 16F84A Processor
//
//
// This header file was automatically generated by:
//
//	inc2h.pl V1.6
//
//	Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
//
//	SDCC is licensed under the GNU Public license (GPL) v2.  Note that
//	this license covers the code to the compiler and other executables,
//	but explicitly does not cover any code or objects generated by sdcc.
//	We have not yet decided on a license for the run time libraries, but
//	it will not put any requirements on code linked against it. See:
// 
//	http://www.gnu.org/copyleft/gpl/html
//
//	See http://sdcc.sourceforge.net/ for the latest information on sdcc.
//
// 
#ifndef P16F84A_H
#define P16F84A_H

//
// Register addresses.
//
#define INDF_ADDR	0x0000
#define TMR0_ADDR	0x0001
#define PCL_ADDR	0x0002
#define STATUS_ADDR	0x0003
#define FSR_ADDR	0x0004
#define PORTA_ADDR	0x0005
#define PORTB_ADDR	0x0006
#define EEDATA_ADDR	0x0008
#define EEADR_ADDR	0x0009
#define PCLATH_ADDR	0x000A
#define INTCON_ADDR	0x000B
#define OPTION_REG_ADDR	0x0081
#define TRISA_ADDR	0x0085
#define TRISB_ADDR	0x0086
#define EECON1_ADDR	0x0088
#define EECON2_ADDR	0x0089

//
// Memory organization.
//

#pragma memmap INDF_ADDR INDF_ADDR SFR 0x000	// INDF
#pragma memmap TMR0_ADDR TMR0_ADDR SFR 0x000	// TMR0
#pragma memmap PCL_ADDR PCL_ADDR SFR 0x000	// PCL
#pragma memmap STATUS_ADDR STATUS_ADDR SFR 0x000	// STATUS
#pragma memmap FSR_ADDR FSR_ADDR SFR 0x000	// FSR
#pragma memmap PORTA_ADDR PORTA_ADDR SFR 0x000	// PORTA
#pragma memmap PORTB_ADDR PORTB_ADDR SFR 0x000	// PORTB
#pragma memmap EEDATA_ADDR EEDATA_ADDR SFR 0x000	// EEDATA
#pragma memmap EEADR_ADDR EEADR_ADDR SFR 0x000	// EEADR
#pragma memmap PCLATH_ADDR PCLATH_ADDR SFR 0x000	// PCLATH
#pragma memmap INTCON_ADDR INTCON_ADDR SFR 0x000	// INTCON
#pragma memmap OPTION_REG_ADDR OPTION_REG_ADDR SFR 0x000	// OPTION_REG
#pragma memmap TRISA_ADDR TRISA_ADDR SFR 0x000	// TRISA
#pragma memmap TRISB_ADDR TRISB_ADDR SFR 0x000	// TRISB
#pragma memmap EECON1_ADDR EECON1_ADDR SFR 0x000	// EECON1
#pragma memmap EECON2_ADDR EECON2_ADDR SFR 0x000	// EECON2


//         LIST
// P16F84A.INC  Standard Header File, Version 2.00    Microchip Technology, Inc.
//         NOLIST

// This header file defines configurations, registers, and other useful bits of
// information for the PIC16F84 microcontroller.  These names are taken to match 
// the data sheets as closely as possible.  

// Note that the processor must be selected before this file is 
// included.  The processor may be selected the following ways:

//       1. Command line switch:
//               C:\ MPASM MYFILE.ASM /PIC16F84A
//       2. LIST directive in the source file
//               LIST   P=PIC16F84A
//       3. Processor Type entry in the MPASM full-screen interface

//==========================================================================
//
//       Revision History
//
//==========================================================================

//Rev:   Date:    Reason:

//1.00   2/15/99 Initial Release

//==========================================================================
//
//       Verify Processor
//
//==========================================================================

//        IFNDEF __16F84A
//            MESSG "Processor-header file mismatch.  Verify selected processor."
//         ENDIF

//==========================================================================
//
//       Register Definitions
//
//==========================================================================

#define W                    0x0000
#define F                    0x0001

//----- Register Files------------------------------------------------------

extern __data __at (INDF_ADDR) volatile char      INDF;
extern __sfr  __at (TMR0_ADDR)                    TMR0;
extern __data __at (PCL_ADDR) volatile char       PCL;
extern __sfr  __at (STATUS_ADDR)                  STATUS;
extern __sfr  __at (FSR_ADDR)                     FSR;
extern __sfr  __at (PORTA_ADDR)                   PORTA;
extern __sfr  __at (PORTB_ADDR)                   PORTB;
extern __sfr  __at (EEDATA_ADDR)                  EEDATA;
extern __sfr  __at (EEADR_ADDR)                   EEADR;
extern __sfr  __at (PCLATH_ADDR)                  PCLATH;
extern __sfr  __at (INTCON_ADDR)                  INTCON;

extern __sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
extern __sfr  __at (TRISA_ADDR)                   TRISA;
extern __sfr  __at (TRISB_ADDR)                   TRISB;
extern __sfr  __at (EECON1_ADDR)                  EECON1;
extern __sfr  __at (EECON2_ADDR)                  EECON2;

//----- STATUS Bits --------------------------------------------------------


//----- INTCON Bits --------------------------------------------------------


//----- OPTION Bits ----------------------------------------------------


//----- EECON1 Bits --------------------------------------------------------


//==========================================================================
//
//       RAM Definition
//
//==========================================================================

//         __MAXRAM H'CF'
//         __BADRAM H'07', H'50'-H'7F', H'87'

//==========================================================================
//
//       Configuration Bits
//
//==========================================================================

#define _CP_ON               0x000F
#define _CP_OFF              0x3FFF
#define _PWRTE_ON            0x3FF7
#define _PWRTE_OFF           0x3FFF
#define _WDT_ON              0x3FFF
#define _WDT_OFF             0x3FFB
#define _LP_OSC              0x3FFC
#define _XT_OSC              0x3FFD
#define _HS_OSC              0x3FFE
#define _RC_OSC              0x3FFF

//         LIST

// ----- EECON1 bits --------------------
typedef union {
  struct {
    unsigned char RD:1;
    unsigned char WR:1;
    unsigned char WREN:1;
    unsigned char WRERR:1;
    unsigned char EEIF:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __EECON1_bits_t;
extern volatile __EECON1_bits_t __at(EECON1_ADDR) EECON1_bits;

#define RD                   EECON1_bits.RD
#define WR                   EECON1_bits.WR
#define WREN                 EECON1_bits.WREN
#define WRERR                EECON1_bits.WRERR
#define EEIF                 EECON1_bits.EEIF

// ----- INTCON bits --------------------
typedef union {
  struct {
    unsigned char RBIF:1;
    unsigned char INTF:1;
    unsigned char T0IF:1;
    unsigned char RBIE:1;
    unsigned char INTE:1;
    unsigned char T0IE:1;
    unsigned char EEIE:1;
    unsigned char GIE:1;
  };
} __INTCON_bits_t;
extern volatile __INTCON_bits_t __at(INTCON_ADDR) INTCON_bits;

#define RBIF                 INTCON_bits.RBIF
#define INTF                 INTCON_bits.INTF
#define T0IF                 INTCON_bits.T0IF
#define RBIE                 INTCON_bits.RBIE
#define INTE                 INTCON_bits.INTE
#define T0IE                 INTCON_bits.T0IE
#define EEIE                 INTCON_bits.EEIE
#define GIE                  INTCON_bits.GIE

// ----- OPTION_REG bits --------------------
typedef union {
  struct {
    unsigned char PS0:1;
    unsigned char PS1:1;
    unsigned char PS2:1;
    unsigned char PSA:1;
    unsigned char T0SE:1;
    unsigned char T0CS:1;
    unsigned char INTEDG:1;
    unsigned char NOT_RBPU:1;
  };
} __OPTION_REG_bits_t;
extern volatile __OPTION_REG_bits_t __at(OPTION_REG_ADDR) OPTION_REG_bits;

#define PS0                  OPTION_REG_bits.PS0
#define PS1                  OPTION_REG_bits.PS1
#define PS2                  OPTION_REG_bits.PS2
#define PSA                  OPTION_REG_bits.PSA
#define T0SE                 OPTION_REG_bits.T0SE
#define T0CS                 OPTION_REG_bits.T0CS
#define INTEDG               OPTION_REG_bits.INTEDG
#define NOT_RBPU             OPTION_REG_bits.NOT_RBPU

// ----- STATUS bits --------------------
typedef union {
  struct {
    unsigned char C:1;
    unsigned char DC:1;
    unsigned char Z:1;
    unsigned char NOT_PD:1;
    unsigned char NOT_TO:1;
    unsigned char RP0:1;
    unsigned char RP1:1;
    unsigned char IRP:1;
  };
} __STATUS_bits_t;
extern volatile __STATUS_bits_t __at(STATUS_ADDR) STATUS_bits;

#define C                    STATUS_bits.C
#define DC                   STATUS_bits.DC
#define Z                    STATUS_bits.Z
#define NOT_PD               STATUS_bits.NOT_PD
#define NOT_TO               STATUS_bits.NOT_TO
#define RP0                  STATUS_bits.RP0
#define RP1                  STATUS_bits.RP1
#define IRP                  STATUS_bits.IRP

// ----- PORTA bits --------------------
typedef union {
    struct {
    unsigned char RA0:1;
    unsigned char RA1:1;
    unsigned char RA2:1;
    unsigned char RA3:1;
    unsigned char RA4:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    };
} __PORTA_bits_t;
extern volatile __PORTA_bits_t __at(PORTA_ADDR) PORTA_bits;
				    
#define RA0             PORTA_bits.RA0
#define RA1             PORTA_bits.RA1
#define RA2             PORTA_bits.RA2
#define RA3             PORTA_bits.RA3
#define RA4		PORTA_bits.RA4

// ----- PORTB bits --------------------

typedef union {
    struct {
    unsigned char RB0:1;
    unsigned char RB1:1;
    unsigned char RB2:1;
    unsigned char RB3:1;
    unsigned char RB4:1;
    unsigned char RB5:1;
    unsigned char RB6:1;
    unsigned char RB7:1;
    };
} __PORTB_bits_t;
extern volatile __PORTB_bits_t __at(PORTB_ADDR) PORTB_bits;
				    
#define RB0		PORTB_bits.RB0
#define RB1		PORTB_bits.RB1
#define RB2		PORTB_bits.RB2
#define RB3		PORTB_bits.RB3
#define RB4		PORTB_bits.RB4
#define RB5		PORTB_bits.RB5
#define RB6		PORTB_bits.RB6
#define RB7		PORTB_bits.RB7

#endif
