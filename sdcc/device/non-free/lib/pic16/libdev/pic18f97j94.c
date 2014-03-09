/*
 * This definitions of the PIC18F97J94 MCU.
 *
 * This file is part of the GNU PIC library for SDCC, originally
 * created by Molnar Karoly <molnarkaroly@users.sf.net> 2014.
 *
 * This file is generated automatically by the cinc2h.pl, 2014-03-09 13:33:06 UTC.
 *
 * SDCC is licensed under the GNU Public license (GPL) v2. Note that
 * this license covers the code to the compiler and other executables,
 * but explicitly does not cover any code or objects generated by sdcc.
 *
 * For pic device libraries and header files which are derived from
 * Microchip header (.inc) and linker script (.lkr) files Microchip
 * requires that "The header files should state that they are only to be
 * used with authentic Microchip devices" which makes them incompatible
 * with the GPL. Pic device libraries and header files are located at
 * non-free/lib and non-free/include directories respectively.
 * Sdcc should be run with the --use-non-free command line option in
 * order to include non-free header files and libraries.
 *
 * See http://sdcc.sourceforge.net/ for the latest information on sdcc.
 */

#include <pic18f97j94.h>

//==============================================================================

__at(0x0DFF) __sfr UEP0;
__at(0x0DFF) volatile __UEP0bits_t UEP0bits;

__at(0x0E00) __sfr UEP1;
__at(0x0E00) volatile __UEP1bits_t UEP1bits;

__at(0x0E01) __sfr UEP2;
__at(0x0E01) volatile __UEP2bits_t UEP2bits;

__at(0x0E02) __sfr UEP3;
__at(0x0E02) volatile __UEP3bits_t UEP3bits;

__at(0x0E03) __sfr UEP4;
__at(0x0E03) volatile __UEP4bits_t UEP4bits;

__at(0x0E04) __sfr UEP5;
__at(0x0E04) volatile __UEP5bits_t UEP5bits;

__at(0x0E05) __sfr UEP6;
__at(0x0E05) volatile __UEP6bits_t UEP6bits;

__at(0x0E06) __sfr UEP7;
__at(0x0E06) volatile __UEP7bits_t UEP7bits;

__at(0x0E07) __sfr UEP8;
__at(0x0E07) volatile __UEP8bits_t UEP8bits;

__at(0x0E08) __sfr UEP9;
__at(0x0E08) volatile __UEP9bits_t UEP9bits;

__at(0x0E09) __sfr UEP10;
__at(0x0E09) volatile __UEP10bits_t UEP10bits;

__at(0x0E0A) __sfr UEP11;
__at(0x0E0A) volatile __UEP11bits_t UEP11bits;

__at(0x0E0B) __sfr UEP12;
__at(0x0E0B) volatile __UEP12bits_t UEP12bits;

__at(0x0E0C) __sfr UEP13;
__at(0x0E0C) volatile __UEP13bits_t UEP13bits;

__at(0x0E0D) __sfr UEP14;
__at(0x0E0D) volatile __UEP14bits_t UEP14bits;

__at(0x0E0E) __sfr UEP15;
__at(0x0E0E) volatile __UEP15bits_t UEP15bits;

__at(0x0E0F) __sfr UEIE;
__at(0x0E0F) volatile __UEIEbits_t UEIEbits;

__at(0x0E10) __sfr UIE;
__at(0x0E10) volatile __UIEbits_t UIEbits;

__at(0x0E11) __sfr UCFG;
__at(0x0E11) volatile __UCFGbits_t UCFGbits;

__at(0x0E12) __sfr RPOR0_1;
__at(0x0E12) volatile __RPOR0_1bits_t RPOR0_1bits;

__at(0x0E13) __sfr RPOR2_3;
__at(0x0E13) volatile __RPOR2_3bits_t RPOR2_3bits;

__at(0x0E14) __sfr RPOR4_5;
__at(0x0E14) volatile __RPOR4_5bits_t RPOR4_5bits;

__at(0x0E15) __sfr RPOR6_7;
__at(0x0E15) volatile __RPOR6_7bits_t RPOR6_7bits;

__at(0x0E16) __sfr RPOR8_9;
__at(0x0E16) volatile __RPOR8_9bits_t RPOR8_9bits;

__at(0x0E17) __sfr RPOR10_11;
__at(0x0E17) volatile __RPOR10_11bits_t RPOR10_11bits;

__at(0x0E18) __sfr RPOR12_13;
__at(0x0E18) volatile __RPOR12_13bits_t RPOR12_13bits;

__at(0x0E19) __sfr RPOR14_15;
__at(0x0E19) volatile __RPOR14_15bits_t RPOR14_15bits;

__at(0x0E1A) __sfr RPOR16_17;
__at(0x0E1A) volatile __RPOR16_17bits_t RPOR16_17bits;

__at(0x0E1B) __sfr RPOR18_19;
__at(0x0E1B) volatile __RPOR18_19bits_t RPOR18_19bits;

__at(0x0E1C) __sfr RPOR20_21;
__at(0x0E1C) volatile __RPOR20_21bits_t RPOR20_21bits;

__at(0x0E1D) __sfr RPOR22_23;
__at(0x0E1D) volatile __RPOR22_23bits_t RPOR22_23bits;

__at(0x0E1E) __sfr RPOR24_25;
__at(0x0E1E) volatile __RPOR24_25bits_t RPOR24_25bits;

__at(0x0E1F) __sfr RPOR26_27;
__at(0x0E1F) volatile __RPOR26_27bits_t RPOR26_27bits;

__at(0x0E20) __sfr RPOR28_29;
__at(0x0E20) volatile __RPOR28_29bits_t RPOR28_29bits;

__at(0x0E21) __sfr RPOR30_31;
__at(0x0E21) volatile __RPOR30_31bits_t RPOR30_31bits;

__at(0x0E22) __sfr RPOR32_33;
__at(0x0E22) volatile __RPOR32_33bits_t RPOR32_33bits;

__at(0x0E23) __sfr RPOR34_35;
__at(0x0E23) volatile __RPOR34_35bits_t RPOR34_35bits;

__at(0x0E24) __sfr RPOR36_37;
__at(0x0E24) volatile __RPOR36_37bits_t RPOR36_37bits;

__at(0x0E25) __sfr RPOR38_39;
__at(0x0E25) volatile __RPOR38_39bits_t RPOR38_39bits;

__at(0x0E26) __sfr RPOR40_41;
__at(0x0E26) volatile __RPOR40_41bits_t RPOR40_41bits;

__at(0x0E27) __sfr RPOR42_43;
__at(0x0E27) volatile __RPOR42_43bits_t RPOR42_43bits;

__at(0x0E28) __sfr RPOR44_45;
__at(0x0E28) volatile __RPOR44_45bits_t RPOR44_45bits;

__at(0x0E29) __sfr RPOR46;
__at(0x0E29) volatile __RPOR46bits_t RPOR46bits;

__at(0x0E2A) __sfr RPINR0_1;
__at(0x0E2A) volatile __RPINR0_1bits_t RPINR0_1bits;

__at(0x0E2B) __sfr RPINR2_3;
__at(0x0E2B) volatile __RPINR2_3bits_t RPINR2_3bits;

__at(0x0E2C) __sfr RPINR4_5;
__at(0x0E2C) volatile __RPINR4_5bits_t RPINR4_5bits;

__at(0x0E2D) __sfr RPINR6_7;
__at(0x0E2D) volatile __RPINR6_7bits_t RPINR6_7bits;

__at(0x0E2E) __sfr RPINR8_9;
__at(0x0E2E) volatile __RPINR8_9bits_t RPINR8_9bits;

__at(0x0E2F) __sfr RPINR10_11;
__at(0x0E2F) volatile __RPINR10_11bits_t RPINR10_11bits;

__at(0x0E30) __sfr RPINR12_13;
__at(0x0E30) volatile __RPINR12_13bits_t RPINR12_13bits;

__at(0x0E31) __sfr RPINR14_15;
__at(0x0E31) volatile __RPINR14_15bits_t RPINR14_15bits;

__at(0x0E32) __sfr RPINR16_17;
__at(0x0E32) volatile __RPINR16_17bits_t RPINR16_17bits;

__at(0x0E33) __sfr RPINR18_19;
__at(0x0E33) volatile __RPINR18_19bits_t RPINR18_19bits;

__at(0x0E34) __sfr RPINR20_21;
__at(0x0E34) volatile __RPINR20_21bits_t RPINR20_21bits;

__at(0x0E35) __sfr RPINR22_23;
__at(0x0E35) volatile __RPINR22_23bits_t RPINR22_23bits;

__at(0x0E36) __sfr RPINR24_25;
__at(0x0E36) volatile __RPINR24_25bits_t RPINR24_25bits;

__at(0x0E37) __sfr RPINR26_27;
__at(0x0E37) volatile __RPINR26_27bits_t RPINR26_27bits;

__at(0x0E38) __sfr RPINR28_29;
__at(0x0E38) volatile __RPINR28_29bits_t RPINR28_29bits;

__at(0x0E39) __sfr RPINR30_31;
__at(0x0E39) volatile __RPINR30_31bits_t RPINR30_31bits;

__at(0x0E3A) __sfr RPINR32_33;
__at(0x0E3A) volatile __RPINR32_33bits_t RPINR32_33bits;

__at(0x0E3B) __sfr RPINR34_35;
__at(0x0E3B) volatile __RPINR34_35bits_t RPINR34_35bits;

__at(0x0E3C) __sfr RPINR36_37;
__at(0x0E3C) volatile __RPINR36_37bits_t RPINR36_37bits;

__at(0x0E3D) __sfr RPINR38_39;
__at(0x0E3D) volatile __RPINR38_39bits_t RPINR38_39bits;

__at(0x0E3E) __sfr RPINR40_41;
__at(0x0E3E) volatile __RPINR40_41bits_t RPINR40_41bits;

__at(0x0E3F) __sfr RPINR42_43;
__at(0x0E3F) volatile __RPINR42_43bits_t RPINR42_43bits;

__at(0x0E40) __sfr RPINR44_45;
__at(0x0E40) volatile __RPINR44_45bits_t RPINR44_45bits;

__at(0x0E41) __sfr RPINR46_47;
__at(0x0E41) volatile __RPINR46_47bits_t RPINR46_47bits;

__at(0x0E42) __sfr RPINR48_49;
__at(0x0E42) volatile __RPINR48_49bits_t RPINR48_49bits;

__at(0x0E43) __sfr RPINR50_51;
__at(0x0E43) volatile __RPINR50_51bits_t RPINR50_51bits;

__at(0x0E44) __sfr RPINR52_53;
__at(0x0E44) volatile __RPINR52_53bits_t RPINR52_53bits;

__at(0x0E45) __sfr ANCON3;
__at(0x0E45) volatile __ANCON3bits_t ANCON3bits;

__at(0x0E46) __sfr ANCON2;
__at(0x0E46) volatile __ANCON2bits_t ANCON2bits;

__at(0x0E47) __sfr ANCON1;
__at(0x0E47) volatile __ANCON1bits_t ANCON1bits;

__at(0x0E48) __sfr ADCBUF1;

__at(0x0E48) __sfr ADCBUF1L;

__at(0x0E49) __sfr ADCBUF1H;

__at(0x0E4A) __sfr ADCBUF2;

__at(0x0E4A) __sfr ADCBUF2L;

__at(0x0E4B) __sfr ADCBUF2H;

__at(0x0E4C) __sfr ADCBUF3;

__at(0x0E4C) __sfr ADCBUF3L;

__at(0x0E4D) __sfr ADCBUF3H;

__at(0x0E4E) __sfr ADCBUF4;

__at(0x0E4E) __sfr ADCBUF4L;

__at(0x0E4F) __sfr ADCBUF4H;

__at(0x0E50) __sfr ADCBUF5;

__at(0x0E50) __sfr ADCBUF5L;

__at(0x0E51) __sfr ADCBUF5H;

__at(0x0E52) __sfr ADCBUF6;

__at(0x0E52) __sfr ADCBUF6L;

__at(0x0E53) __sfr ADCBUF6H;

__at(0x0E54) __sfr ADCBUF7;

__at(0x0E54) __sfr ADCBUF7L;

__at(0x0E55) __sfr ADCBUF7H;

__at(0x0E56) __sfr ADCBUF8;

__at(0x0E56) __sfr ADCBUF8L;

__at(0x0E57) __sfr ADCBUF8H;

__at(0x0E58) __sfr ADCBUF9;

__at(0x0E58) __sfr ADCBUF9L;

__at(0x0E59) __sfr ADCBUF9H;

__at(0x0E5A) __sfr ADCBUF10;

__at(0x0E5A) __sfr ADCBUF10L;

__at(0x0E5B) __sfr ADCBUF10H;

__at(0x0E5C) __sfr ADCBUF11;

__at(0x0E5C) __sfr ADCBUF11L;

__at(0x0E5D) __sfr ADCBUF11H;

__at(0x0E5E) __sfr ADCBUF12;

__at(0x0E5E) __sfr ADCBUF12L;

__at(0x0E5F) __sfr ADCBUF12H;

__at(0x0E60) __sfr ADCBUF13;

__at(0x0E60) __sfr ADCBUF13L;

__at(0x0E61) __sfr ADCBUF13H;

__at(0x0E62) __sfr ADCBUF14;

__at(0x0E62) __sfr ADCBUF14L;

__at(0x0E63) __sfr ADCBUF14H;

__at(0x0E64) __sfr ADCBUF15;

__at(0x0E64) __sfr ADCBUF15L;

__at(0x0E65) __sfr ADCBUF15H;

__at(0x0E66) __sfr ADCBUF16;

__at(0x0E66) __sfr ADCBUF16L;

__at(0x0E67) __sfr ADCBUF16H;

__at(0x0E68) __sfr ADCBUF17;

__at(0x0E68) __sfr ADCBUF17L;

__at(0x0E69) __sfr ADCBUF17H;

__at(0x0E6A) __sfr ADCBUF18;

__at(0x0E6A) __sfr ADCBUF18L;

__at(0x0E6B) __sfr ADCBUF18H;

__at(0x0E6C) __sfr ADCBUF19;

__at(0x0E6C) __sfr ADCBUF19L;

__at(0x0E6D) __sfr ADCBUF19H;

__at(0x0E6E) __sfr ADCBUF20;

__at(0x0E6E) __sfr ADCBUF20L;

__at(0x0E6F) __sfr ADCBUF20H;

__at(0x0E70) __sfr ADCBUF21;

__at(0x0E70) __sfr ADCBUF21L;

__at(0x0E71) __sfr ADCBUF21H;

__at(0x0E72) __sfr ADCBUF22;

__at(0x0E72) __sfr ADCBUF22L;

__at(0x0E73) __sfr ADCBUF22H;

__at(0x0E74) __sfr ADCBUF23;

__at(0x0E74) __sfr ADCBUF23L;

__at(0x0E75) __sfr ADCBUF23H;

__at(0x0E76) __sfr ADCBUF24;

__at(0x0E76) __sfr ADCBUF24L;

__at(0x0E77) __sfr ADCBUF24H;

__at(0x0E78) __sfr ADCBUF25;

__at(0x0E78) __sfr ADCBUF25L;

__at(0x0E79) __sfr ADCBUF25H;

__at(0x0E7A) __sfr ADCTMUEN0L;
__at(0x0E7A) volatile __ADCTMUEN0Lbits_t ADCTMUEN0Lbits;

__at(0x0E7B) __sfr ADCTMUEN0H;
__at(0x0E7B) volatile __ADCTMUEN0Hbits_t ADCTMUEN0Hbits;

__at(0x0E7C) __sfr ADCTMUEN1L;
__at(0x0E7C) volatile __ADCTMUEN1Lbits_t ADCTMUEN1Lbits;

__at(0x0E7D) __sfr ADCTMUEN1H;
__at(0x0E7D) volatile __ADCTMUEN1Hbits_t ADCTMUEN1Hbits;

__at(0x0E7E) __sfr ADCHIT0L;
__at(0x0E7E) volatile __ADCHIT0Lbits_t ADCHIT0Lbits;

__at(0x0E7F) __sfr ADCHIT0H;
__at(0x0E7F) volatile __ADCHIT0Hbits_t ADCHIT0Hbits;

__at(0x0E80) __sfr ADCHIT1L;
__at(0x0E80) volatile __ADCHIT1Lbits_t ADCHIT1Lbits;

__at(0x0E81) __sfr ADCHIT1H;
__at(0x0E81) volatile __ADCHIT1Hbits_t ADCHIT1Hbits;

__at(0x0E82) __sfr ADCSS0L;
__at(0x0E82) volatile __ADCSS0Lbits_t ADCSS0Lbits;

__at(0x0E83) __sfr ADCSS0H;
__at(0x0E83) volatile __ADCSS0Hbits_t ADCSS0Hbits;

__at(0x0E84) __sfr ADCSS1L;
__at(0x0E84) volatile __ADCSS1Lbits_t ADCSS1Lbits;

__at(0x0E85) __sfr ADCSS1H;
__at(0x0E85) volatile __ADCSS1Hbits_t ADCSS1Hbits;

__at(0x0E86) __sfr ADCHS0L;
__at(0x0E86) volatile __ADCHS0Lbits_t ADCHS0Lbits;

__at(0x0E87) __sfr ADCHS0H;
__at(0x0E87) volatile __ADCHS0Hbits_t ADCHS0Hbits;

__at(0x0E88) __sfr ADCON5L;
__at(0x0E88) volatile __ADCON5Lbits_t ADCON5Lbits;

__at(0x0E89) __sfr ADCON5H;
__at(0x0E89) volatile __ADCON5Hbits_t ADCON5Hbits;

__at(0x0E8A) __sfr ADCON3L;
__at(0x0E8A) volatile __ADCON3Lbits_t ADCON3Lbits;

__at(0x0E8B) __sfr ADCON3H;
__at(0x0E8B) volatile __ADCON3Hbits_t ADCON3Hbits;

__at(0x0E8C) __sfr ADCON2L;
__at(0x0E8C) volatile __ADCON2Lbits_t ADCON2Lbits;

__at(0x0E8D) __sfr ADCON2H;
__at(0x0E8D) volatile __ADCON2Hbits_t ADCON2Hbits;

__at(0x0E8E) __sfr LCDDATA0;
__at(0x0E8E) volatile __LCDDATA0bits_t LCDDATA0bits;

__at(0x0E8F) __sfr LCDDATA1;
__at(0x0E8F) volatile __LCDDATA1bits_t LCDDATA1bits;

__at(0x0E90) __sfr LCDDATA2;
__at(0x0E90) volatile __LCDDATA2bits_t LCDDATA2bits;

__at(0x0E91) __sfr LCDDATA3;
__at(0x0E91) volatile __LCDDATA3bits_t LCDDATA3bits;

__at(0x0E92) __sfr LCDDATA4;
__at(0x0E92) volatile __LCDDATA4bits_t LCDDATA4bits;

__at(0x0E93) __sfr LCDDATA5;
__at(0x0E93) volatile __LCDDATA5bits_t LCDDATA5bits;

__at(0x0E94) __sfr LCDDATA6;
__at(0x0E94) volatile __LCDDATA6bits_t LCDDATA6bits;

__at(0x0E95) __sfr LCDDATA7;
__at(0x0E95) volatile __LCDDATA7bits_t LCDDATA7bits;

__at(0x0E96) __sfr LCDDATA8;
__at(0x0E96) volatile __LCDDATA8bits_t LCDDATA8bits;

__at(0x0E97) __sfr LCDDATA9;
__at(0x0E97) volatile __LCDDATA9bits_t LCDDATA9bits;

__at(0x0E98) __sfr LCDDATA10;
__at(0x0E98) volatile __LCDDATA10bits_t LCDDATA10bits;

__at(0x0E99) __sfr LCDDATA11;
__at(0x0E99) volatile __LCDDATA11bits_t LCDDATA11bits;

__at(0x0E9A) __sfr LCDDATA12;
__at(0x0E9A) volatile __LCDDATA12bits_t LCDDATA12bits;

__at(0x0E9B) __sfr LCDDATA13;
__at(0x0E9B) volatile __LCDDATA13bits_t LCDDATA13bits;

__at(0x0E9C) __sfr LCDDATA14;
__at(0x0E9C) volatile __LCDDATA14bits_t LCDDATA14bits;

__at(0x0E9D) __sfr LCDDATA15;
__at(0x0E9D) volatile __LCDDATA15bits_t LCDDATA15bits;

__at(0x0E9E) __sfr LCDDATA16;
__at(0x0E9E) volatile __LCDDATA16bits_t LCDDATA16bits;

__at(0x0E9F) __sfr LCDDATA17;
__at(0x0E9F) volatile __LCDDATA17bits_t LCDDATA17bits;

__at(0x0EA0) __sfr LCDDATA18;
__at(0x0EA0) volatile __LCDDATA18bits_t LCDDATA18bits;

__at(0x0EA1) __sfr LCDDATA19;
__at(0x0EA1) volatile __LCDDATA19bits_t LCDDATA19bits;

__at(0x0EA2) __sfr LCDDATA20;
__at(0x0EA2) volatile __LCDDATA20bits_t LCDDATA20bits;

__at(0x0EA3) __sfr LCDDATA21;
__at(0x0EA3) volatile __LCDDATA21bits_t LCDDATA21bits;

__at(0x0EA4) __sfr LCDDATA22;
__at(0x0EA4) volatile __LCDDATA22bits_t LCDDATA22bits;

__at(0x0EA5) __sfr LCDDATA23;
__at(0x0EA5) volatile __LCDDATA23bits_t LCDDATA23bits;

__at(0x0EA6) __sfr LCDDATA24;
__at(0x0EA6) volatile __LCDDATA24bits_t LCDDATA24bits;

__at(0x0EA7) __sfr LCDDATA25;
__at(0x0EA7) volatile __LCDDATA25bits_t LCDDATA25bits;

__at(0x0EA8) __sfr LCDDATA26;
__at(0x0EA8) volatile __LCDDATA26bits_t LCDDATA26bits;

__at(0x0EA9) __sfr LCDDATA27;
__at(0x0EA9) volatile __LCDDATA27bits_t LCDDATA27bits;

__at(0x0EAA) __sfr LCDDATA28;
__at(0x0EAA) volatile __LCDDATA28bits_t LCDDATA28bits;

__at(0x0EAB) __sfr LCDDATA29;
__at(0x0EAB) volatile __LCDDATA29bits_t LCDDATA29bits;

__at(0x0EAC) __sfr LCDDATA30;
__at(0x0EAC) volatile __LCDDATA30bits_t LCDDATA30bits;

__at(0x0EAD) __sfr LCDDATA31;
__at(0x0EAD) volatile __LCDDATA31bits_t LCDDATA31bits;

__at(0x0EAE) __sfr LCDDATA32;
__at(0x0EAE) volatile __LCDDATA32bits_t LCDDATA32bits;

__at(0x0EAF) __sfr LCDDATA33;
__at(0x0EAF) volatile __LCDDATA33bits_t LCDDATA33bits;

__at(0x0EB0) __sfr LCDDATA34;
__at(0x0EB0) volatile __LCDDATA34bits_t LCDDATA34bits;

__at(0x0EB1) __sfr LCDDATA35;
__at(0x0EB1) volatile __LCDDATA35bits_t LCDDATA35bits;

__at(0x0EB2) __sfr LCDDATA36;
__at(0x0EB2) volatile __LCDDATA36bits_t LCDDATA36bits;

__at(0x0EB3) __sfr LCDDATA37;
__at(0x0EB3) volatile __LCDDATA37bits_t LCDDATA37bits;

__at(0x0EB4) __sfr LCDDATA38;
__at(0x0EB4) volatile __LCDDATA38bits_t LCDDATA38bits;

__at(0x0EB5) __sfr LCDDATA39;
__at(0x0EB5) volatile __LCDDATA39bits_t LCDDATA39bits;

__at(0x0EB6) __sfr LCDDATA40;
__at(0x0EB6) volatile __LCDDATA40bits_t LCDDATA40bits;

__at(0x0EB7) __sfr LCDDATA41;
__at(0x0EB7) volatile __LCDDATA41bits_t LCDDATA41bits;

__at(0x0EB8) __sfr LCDDATA42;
__at(0x0EB8) volatile __LCDDATA42bits_t LCDDATA42bits;

__at(0x0EB9) __sfr LCDDATA43;
__at(0x0EB9) volatile __LCDDATA43bits_t LCDDATA43bits;

__at(0x0EBA) __sfr LCDDATA44;
__at(0x0EBA) volatile __LCDDATA44bits_t LCDDATA44bits;

__at(0x0EBB) __sfr LCDDATA45;
__at(0x0EBB) volatile __LCDDATA45bits_t LCDDATA45bits;

__at(0x0EBC) __sfr LCDDATA46;
__at(0x0EBC) volatile __LCDDATA46bits_t LCDDATA46bits;

__at(0x0EBD) __sfr LCDDATA47;
__at(0x0EBD) volatile __LCDDATA47bits_t LCDDATA47bits;

__at(0x0EBE) __sfr LCDDATA48;
__at(0x0EBE) volatile __LCDDATA48bits_t LCDDATA48bits;

__at(0x0EBF) __sfr LCDDATA49;
__at(0x0EBF) volatile __LCDDATA49bits_t LCDDATA49bits;

__at(0x0EC0) __sfr LCDDATA50;
__at(0x0EC0) volatile __LCDDATA50bits_t LCDDATA50bits;

__at(0x0EC1) __sfr LCDDATA51;
__at(0x0EC1) volatile __LCDDATA51bits_t LCDDATA51bits;

__at(0x0EC2) __sfr LCDDATA52;
__at(0x0EC2) volatile __LCDDATA52bits_t LCDDATA52bits;

__at(0x0EC3) __sfr LCDDATA53;
__at(0x0EC3) volatile __LCDDATA53bits_t LCDDATA53bits;

__at(0x0EC4) __sfr LCDDATA54;
__at(0x0EC4) volatile __LCDDATA54bits_t LCDDATA54bits;

__at(0x0EC5) __sfr LCDDATA55;
__at(0x0EC5) volatile __LCDDATA55bits_t LCDDATA55bits;

__at(0x0EC6) __sfr LCDDATA56;
__at(0x0EC6) volatile __LCDDATA56bits_t LCDDATA56bits;

__at(0x0EC7) __sfr LCDDATA57;
__at(0x0EC7) volatile __LCDDATA57bits_t LCDDATA57bits;

__at(0x0EC8) __sfr LCDDATA58;
__at(0x0EC8) volatile __LCDDATA58bits_t LCDDATA58bits;

__at(0x0EC9) __sfr LCDDATA59;
__at(0x0EC9) volatile __LCDDATA59bits_t LCDDATA59bits;

__at(0x0ECA) __sfr LCDDATA60;
__at(0x0ECA) volatile __LCDDATA60bits_t LCDDATA60bits;

__at(0x0ECB) __sfr LCDDATA61;
__at(0x0ECB) volatile __LCDDATA61bits_t LCDDATA61bits;

__at(0x0ECC) __sfr LCDDATA62;
__at(0x0ECC) volatile __LCDDATA62bits_t LCDDATA62bits;

__at(0x0ECD) __sfr LCDDATA63;
__at(0x0ECD) volatile __LCDDATA63bits_t LCDDATA63bits;

__at(0x0ECE) __sfr LCDSE0;
__at(0x0ECE) volatile __LCDSE0bits_t LCDSE0bits;

__at(0x0ECF) __sfr LCDSE1;
__at(0x0ECF) volatile __LCDSE1bits_t LCDSE1bits;

__at(0x0ED0) __sfr LCDSE2;
__at(0x0ED0) volatile __LCDSE2bits_t LCDSE2bits;

__at(0x0ED1) __sfr LCDSE3;
__at(0x0ED1) volatile __LCDSE3bits_t LCDSE3bits;

__at(0x0ED2) __sfr LCDSE4;
__at(0x0ED2) volatile __LCDSE4bits_t LCDSE4bits;

__at(0x0ED3) __sfr LCDSE5;
__at(0x0ED3) volatile __LCDSE5bits_t LCDSE5bits;

__at(0x0ED4) __sfr LCDSE6;
__at(0x0ED4) volatile __LCDSE6bits_t LCDSE6bits;

__at(0x0ED5) __sfr LCDSE7;
__at(0x0ED5) volatile __LCDSE7bits_t LCDSE7bits;

__at(0x0ED6) __sfr LCDRL;
__at(0x0ED6) volatile __LCDRLbits_t LCDRLbits;

__at(0x0ED7) __sfr LCDREF;
__at(0x0ED7) volatile __LCDREFbits_t LCDREFbits;

__at(0x0ED8) __sfr LCDREG;
__at(0x0ED8) volatile __LCDREGbits_t LCDREGbits;

__at(0x0ED9) __sfr LCDCON;
__at(0x0ED9) volatile __LCDCONbits_t LCDCONbits;

__at(0x0EDA) __sfr LCDPS;
__at(0x0EDA) volatile __LCDPSbits_t LCDPSbits;

__at(0x0EDB) __sfr REFO2CON3;
__at(0x0EDB) volatile __REFO2CON3bits_t REFO2CON3bits;

__at(0x0EDC) __sfr REFO2CON2;
__at(0x0EDC) volatile __REFO2CON2bits_t REFO2CON2bits;

__at(0x0EDD) __sfr REFO2CON1;
__at(0x0EDD) volatile __REFO2CON1bits_t REFO2CON1bits;

__at(0x0EDE) __sfr REFO2CON;
__at(0x0EDE) volatile __REFO2CONbits_t REFO2CONbits;

__at(0x0EDF) __sfr REFO1CON3;
__at(0x0EDF) volatile __REFO1CON3bits_t REFO1CON3bits;

__at(0x0EE0) __sfr REFO1CON2;
__at(0x0EE0) volatile __REFO1CON2bits_t REFO1CON2bits;

__at(0x0EE1) __sfr REFO1CON1;
__at(0x0EE1) volatile __REFO1CON1bits_t REFO1CON1bits;

__at(0x0EE2) __sfr REFO1CON;
__at(0x0EE2) volatile __REFO1CONbits_t REFO1CONbits;

__at(0x0EE3) __sfr MEMCON;
__at(0x0EE3) volatile __MEMCONbits_t MEMCONbits;

__at(0x0EE4) __sfr PORTL;
__at(0x0EE4) volatile __PORTLbits_t PORTLbits;

__at(0x0EE5) __sfr LATL;
__at(0x0EE5) volatile __LATLbits_t LATLbits;

__at(0x0EE6) __sfr TRISL;
__at(0x0EE6) volatile __TRISLbits_t TRISLbits;

__at(0x0EE7) __sfr PORTK;
__at(0x0EE7) volatile __PORTKbits_t PORTKbits;

__at(0x0EE8) __sfr LATK;
__at(0x0EE8) volatile __LATKbits_t LATKbits;

__at(0x0EE9) __sfr TRISK;
__at(0x0EE9) volatile __TRISKbits_t TRISKbits;

__at(0x0EEA) __sfr ODCON2;
__at(0x0EEA) volatile __ODCON2bits_t ODCON2bits;

__at(0x0EEB) __sfr ODCON1;
__at(0x0EEB) volatile __ODCON1bits_t ODCON1bits;

__at(0x0EEC) __sfr MDCARL;
__at(0x0EEC) volatile __MDCARLbits_t MDCARLbits;

__at(0x0EED) __sfr MDCARH;
__at(0x0EED) volatile __MDCARHbits_t MDCARHbits;

__at(0x0EEE) __sfr MDSRC;
__at(0x0EEE) volatile __MDSRCbits_t MDSRCbits;

__at(0x0EEF) __sfr MDCON;
__at(0x0EEF) volatile __MDCONbits_t MDCONbits;

__at(0x0EF0) __sfr PMD4;
__at(0x0EF0) volatile __PMD4bits_t PMD4bits;

__at(0x0EF1) __sfr PMD3;
__at(0x0EF1) volatile __PMD3bits_t PMD3bits;

__at(0x0EF2) __sfr PMD2;
__at(0x0EF2) volatile __PMD2bits_t PMD2bits;

__at(0x0EF3) __sfr PMD1;
__at(0x0EF3) volatile __PMD1bits_t PMD1bits;

__at(0x0EF4) __sfr PMD0;
__at(0x0EF4) volatile __PMD0bits_t PMD0bits;

__at(0x0EF5) __sfr CTMUCON4;
__at(0x0EF5) volatile __CTMUCON4bits_t CTMUCON4bits;

__at(0x0EF6) __sfr CTMUCON3;
__at(0x0EF6) volatile __CTMUCON3bits_t CTMUCON3bits;

__at(0x0EF7) __sfr CTMUCON2;
__at(0x0EF7) volatile __CTMUCON2bits_t CTMUCON2bits;

__at(0x0EF8) __sfr CTMUCON1;
__at(0x0EF8) volatile __CTMUCON1bits_t CTMUCON1bits;

__at(0x0EF9) __sfr TXREG4;

__at(0x0EFA) __sfr RCREG4;

__at(0x0EFB) __sfr SPBRG4;
__at(0x0EFB) volatile __SPBRG4bits_t SPBRG4bits;

__at(0x0EFC) __sfr SPBRGH4;
__at(0x0EFC) volatile __SPBRGH4bits_t SPBRGH4bits;

__at(0x0EFD) __sfr BAUDCON4;
__at(0x0EFD) volatile __BAUDCON4bits_t BAUDCON4bits;

__at(0x0EFE) __sfr TXSTA4;
__at(0x0EFE) volatile __TXSTA4bits_t TXSTA4bits;

__at(0x0EFF) __sfr RCSTA4;
__at(0x0EFF) volatile __RCSTA4bits_t RCSTA4bits;

__at(0x0F00) __sfr DMACON2;
__at(0x0F00) volatile __DMACON2bits_t DMACON2bits;

__at(0x0F01) __sfr ANCFG;
__at(0x0F01) volatile __ANCFGbits_t ANCFGbits;

__at(0x0F02) __sfr SSP2ADD;

__at(0x0F03) __sfr SSP2BUF;

__at(0x0F04) __sfr T4CON;
__at(0x0F04) volatile __T4CONbits_t T4CONbits;

__at(0x0F05) __sfr PR4;

__at(0x0F06) __sfr TMR4;

__at(0x0F07) __sfr CCP7CON;
__at(0x0F07) volatile __CCP7CONbits_t CCP7CONbits;

__at(0x0F08) __sfr CCPR7;

__at(0x0F08) __sfr CCPR7L;

__at(0x0F09) __sfr CCPR7H;

__at(0x0F0A) __sfr CCP6CON;
__at(0x0F0A) volatile __CCP6CONbits_t CCP6CONbits;

__at(0x0F0B) __sfr CCPR6;

__at(0x0F0B) __sfr CCPR6L;

__at(0x0F0C) __sfr CCPR6H;

__at(0x0F0D) __sfr CCP5CON;
__at(0x0F0D) volatile __CCP5CONbits_t CCP5CONbits;

__at(0x0F0E) __sfr CCPR5;

__at(0x0F0E) __sfr CCPR5L;

__at(0x0F0F) __sfr CCPR5H;

__at(0x0F10) __sfr CCP4CON;
__at(0x0F10) volatile __CCP4CONbits_t CCP4CONbits;

__at(0x0F11) __sfr CCPR4;

__at(0x0F11) __sfr CCPR4L;

__at(0x0F12) __sfr CCPR4H;

__at(0x0F13) __sfr T5GCON;
__at(0x0F13) volatile __T5GCONbits_t T5GCONbits;

__at(0x0F14) __sfr T5CON;
__at(0x0F14) volatile __T5CONbits_t T5CONbits;

__at(0x0F15) __sfr TMR5;

__at(0x0F15) __sfr TMR5L;

__at(0x0F16) __sfr TMR5H;

__at(0x0F17) __sfr SSP2MSK;
__at(0x0F17) volatile __SSP2MSKbits_t SSP2MSKbits;

__at(0x0F18) __sfr SSP2CON2;
__at(0x0F18) volatile __SSP2CON2bits_t SSP2CON2bits;

__at(0x0F19) __sfr SSP2CON1;
__at(0x0F19) volatile __SSP2CON1bits_t SSP2CON1bits;

__at(0x0F1A) __sfr SSP2STAT;
__at(0x0F1A) volatile __SSP2STATbits_t SSP2STATbits;

__at(0x0F1B) __sfr PSTR3CON;
__at(0x0F1B) volatile __PSTR3CONbits_t PSTR3CONbits;

__at(0x0F1C) __sfr PSTR2CON;
__at(0x0F1C) volatile __PSTR2CONbits_t PSTR2CONbits;

__at(0x0F1D) __sfr TXREG2;

__at(0x0F1E) __sfr RCREG2;

__at(0x0F1F) __sfr SPBRG2;
__at(0x0F1F) volatile __SPBRG2bits_t SPBRG2bits;

__at(0x0F20) __sfr SPBRGH2;
__at(0x0F20) volatile __SPBRGH2bits_t SPBRGH2bits;

__at(0x0F21) __sfr DSGPR3;

__at(0x0F22) __sfr DSGPR2;

__at(0x0F23) __sfr DSGPR1;

__at(0x0F24) __sfr DSGPR0;

__at(0x0F25) __sfr DSWAKEH;
__at(0x0F25) volatile __DSWAKEHbits_t DSWAKEHbits;

__at(0x0F26) __sfr DSWAKEL;
__at(0x0F26) volatile __DSWAKELbits_t DSWAKELbits;

__at(0x0F27) __sfr DSCONH;
__at(0x0F27) volatile __DSCONHbits_t DSCONHbits;

__at(0x0F28) __sfr DSCONL;
__at(0x0F28) volatile __DSCONLbits_t DSCONLbits;

__at(0x0F29) __sfr TXREG3;

__at(0x0F2A) __sfr RCREG3;

__at(0x0F2B) __sfr SPBRG3;
__at(0x0F2B) volatile __SPBRG3bits_t SPBRG3bits;

__at(0x0F2C) __sfr SPBRGH3;
__at(0x0F2C) volatile __SPBRGH3bits_t SPBRGH3bits;

__at(0x0F2D) __sfr BAUDCON3;
__at(0x0F2D) volatile __BAUDCON3bits_t BAUDCON3bits;

__at(0x0F2E) __sfr TXSTA3;
__at(0x0F2E) volatile __TXSTA3bits_t TXSTA3bits;

__at(0x0F2F) __sfr RCSTA3;
__at(0x0F2F) volatile __RCSTA3bits_t RCSTA3bits;

__at(0x0F30) __sfr SPBRGH;
__at(0x0F30) volatile __SPBRGHbits_t SPBRGHbits;

__at(0x0F30) __sfr SPBRGH1;
__at(0x0F30) volatile __SPBRGH1bits_t SPBRGH1bits;

__at(0x0F31) __sfr BAUDCON2;
__at(0x0F31) volatile __BAUDCON2bits_t BAUDCON2bits;

__at(0x0F32) __sfr TXSTA2;
__at(0x0F32) volatile __TXSTA2bits_t TXSTA2bits;

__at(0x0F33) __sfr RCSTA2;
__at(0x0F33) volatile __RCSTA2bits_t RCSTA2bits;

__at(0x0F34) __sfr CCPTMRS2;
__at(0x0F34) volatile __CCPTMRS2bits_t CCPTMRS2bits;

__at(0x0F35) __sfr CCPTMRS1;
__at(0x0F35) volatile __CCPTMRS1bits_t CCPTMRS1bits;

__at(0x0F36) __sfr CCPTMRS0;
__at(0x0F36) volatile __CCPTMRS0bits_t CCPTMRS0bits;

__at(0x0F37) __sfr CM3CON;
__at(0x0F37) volatile __CM3CONbits_t CM3CONbits;

__at(0x0F38) __sfr CM2CON;
__at(0x0F38) volatile __CM2CONbits_t CM2CONbits;

__at(0x0F39) __sfr SSP2CON3;
__at(0x0F39) volatile __SSP2CON3bits_t SSP2CON3bits;

__at(0x0F3A) __sfr T8CON;
__at(0x0F3A) volatile __T8CONbits_t T8CONbits;

__at(0x0F3B) __sfr PR8;

__at(0x0F3C) __sfr TMR8;

__at(0x0F3D) __sfr T6CON;
__at(0x0F3D) volatile __T6CONbits_t T6CONbits;

__at(0x0F3E) __sfr PR6;

__at(0x0F3F) __sfr TMR6;

__at(0x0F40) __sfr CCP10CON;
__at(0x0F40) volatile __CCP10CONbits_t CCP10CONbits;

__at(0x0F41) __sfr CCPR10;

__at(0x0F41) __sfr CCPR10L;

__at(0x0F42) __sfr CCPR10H;

__at(0x0F43) __sfr CCP9CON;
__at(0x0F43) volatile __CCP9CONbits_t CCP9CONbits;

__at(0x0F44) __sfr CCPR9;

__at(0x0F44) __sfr CCPR9L;

__at(0x0F45) __sfr CCPR9H;

__at(0x0F46) __sfr CCP8CON;
__at(0x0F46) volatile __CCP8CONbits_t CCP8CONbits;

__at(0x0F47) __sfr CCPR8;

__at(0x0F47) __sfr CCPR8L;

__at(0x0F48) __sfr CCPR8H;

__at(0x0F49) __sfr CCP3CON;
__at(0x0F49) volatile __CCP3CONbits_t CCP3CONbits;

__at(0x0F4A) __sfr CCPR3;

__at(0x0F4A) __sfr CCPR3L;

__at(0x0F4B) __sfr CCPR3H;

__at(0x0F4C) __sfr ECCP3DEL;
__at(0x0F4C) volatile __ECCP3DELbits_t ECCP3DELbits;

__at(0x0F4D) __sfr ECCP3AS;
__at(0x0F4D) volatile __ECCP3ASbits_t ECCP3ASbits;

__at(0x0F4E) __sfr CCP2CON;
__at(0x0F4E) volatile __CCP2CONbits_t CCP2CONbits;

__at(0x0F4F) __sfr CCPR2;

__at(0x0F4F) __sfr CCPR2L;

__at(0x0F50) __sfr CCPR2H;

__at(0x0F51) __sfr ECCP2DEL;
__at(0x0F51) volatile __ECCP2DELbits_t ECCP2DELbits;

__at(0x0F52) __sfr ECCP2AS;
__at(0x0F52) volatile __ECCP2ASbits_t ECCP2ASbits;

__at(0x0F53) __sfr CM1CON;
__at(0x0F53) volatile __CM1CONbits_t CM1CONbits;

__at(0x0F54) __sfr PADCFG1;
__at(0x0F54) volatile __PADCFG1bits_t PADCFG1bits;

__at(0x0F55) __sfr IOCN;
__at(0x0F55) volatile __IOCNbits_t IOCNbits;

__at(0x0F56) __sfr IOCP;
__at(0x0F56) volatile __IOCPbits_t IOCPbits;

__at(0x0F57) __sfr RTCCON2;
__at(0x0F57) volatile __RTCCON2bits_t RTCCON2bits;

__at(0x0F58) __sfr ALRMVALL;

__at(0x0F59) __sfr ALRMVALH;

__at(0x0F5A) __sfr ALRMRPT;
__at(0x0F5A) volatile __ALRMRPTbits_t ALRMRPTbits;

__at(0x0F5B) __sfr ALRMCFG;
__at(0x0F5B) volatile __ALRMCFGbits_t ALRMCFGbits;

__at(0x0F5C) __sfr RTCVALL;

__at(0x0F5D) __sfr RTCVALH;

__at(0x0F5E) __sfr RTCCAL;
__at(0x0F5E) volatile __RTCCALbits_t RTCCALbits;

__at(0x0F5F) __sfr RTCCON1;
__at(0x0F5F) volatile __RTCCON1bits_t RTCCON1bits;

__at(0x0F60) __sfr DMACON1;
__at(0x0F60) volatile __DMACON1bits_t DMACON1bits;

__at(0x0F61) __sfr PIE6;
__at(0x0F61) volatile __PIE6bits_t PIE6bits;

__at(0x0F62) __sfr WPUB;
__at(0x0F62) volatile __WPUBbits_t WPUBbits;

__at(0x0F63) __sfr ACTCON;
__at(0x0F63) volatile __ACTCONbits_t ACTCONbits;

__at(0x0F64) __sfr OSCCON4;
__at(0x0F64) volatile __OSCCON4bits_t OSCCON4bits;

__at(0x0F65) __sfr OSCCON3;
__at(0x0F65) volatile __OSCCON3bits_t OSCCON3bits;

__at(0x0F66) __sfr OSCCON2;
__at(0x0F66) volatile __OSCCON2bits_t OSCCON2bits;

__at(0x0F67) __sfr BAUDCON;
__at(0x0F67) volatile __BAUDCONbits_t BAUDCONbits;

__at(0x0F67) __sfr BAUDCON1;
__at(0x0F67) volatile __BAUDCON1bits_t BAUDCON1bits;

__at(0x0F68) __sfr SSP1MSK;
__at(0x0F68) volatile __SSP1MSKbits_t SSP1MSKbits;

__at(0x0F69) __sfr SSP1CON3;
__at(0x0F69) volatile __SSP1CON3bits_t SSP1CON3bits;

__at(0x0F6A) __sfr TXBUF;
__at(0x0F6A) volatile __TXBUFbits_t TXBUFbits;

__at(0x0F6B) __sfr DMABCH;
__at(0x0F6B) volatile __DMABCHbits_t DMABCHbits;

__at(0x0F6C) __sfr DMABCL;
__at(0x0F6C) volatile __DMABCLbits_t DMABCLbits;

__at(0x0F6D) __sfr RXADDRH;
__at(0x0F6D) volatile __RXADDRHbits_t RXADDRHbits;

__at(0x0F6E) __sfr RXADDRL;
__at(0x0F6E) volatile __RXADDRLbits_t RXADDRLbits;

__at(0x0F6F) __sfr TXADDRH;
__at(0x0F6F) volatile __TXADDRHbits_t TXADDRHbits;

__at(0x0F70) __sfr TXADDRL;
__at(0x0F70) volatile __TXADDRLbits_t TXADDRLbits;

__at(0x0F71) __sfr PORTVP;
__at(0x0F71) volatile __PORTVPbits_t PORTVPbits;

__at(0x0F72) __sfr LATVP;
__at(0x0F72) volatile __LATVPbits_t LATVPbits;

__at(0x0F73) __sfr TRISVP;
__at(0x0F73) volatile __TRISVPbits_t TRISVPbits;

__at(0x0F74) __sfr UADDR;
__at(0x0F74) volatile __UADDRbits_t UADDRbits;

__at(0x0F75) __sfr UCON;
__at(0x0F75) volatile __UCONbits_t UCONbits;

__at(0x0F76) __sfr USTAT;
__at(0x0F76) volatile __USTATbits_t USTATbits;

__at(0x0F77) __sfr UEIR;
__at(0x0F77) volatile __UEIRbits_t UEIRbits;

__at(0x0F78) __sfr UIR;
__at(0x0F78) volatile __UIRbits_t UIRbits;

__at(0x0F79) __sfr UFRM;

__at(0x0F79) __sfr UFRMH;
__at(0x0F79) volatile __UFRMHbits_t UFRMHbits;

__at(0x0F7A) __sfr UFRML;
__at(0x0F7A) volatile __UFRMLbits_t UFRMLbits;

__at(0x0F7B) __sfr RCON4;
__at(0x0F7B) volatile __RCON4bits_t RCON4bits;

__at(0x0F7C) __sfr RCON3;
__at(0x0F7C) volatile __RCON3bits_t RCON3bits;

__at(0x0F7D) __sfr RCON2;
__at(0x0F7D) volatile __RCON2bits_t RCON2bits;

__at(0x0F7E) __sfr EECON2;

__at(0x0F7F) __sfr EECON1;
__at(0x0F7F) volatile __EECON1bits_t EECON1bits;

__at(0x0F80) __sfr PORTA;
__at(0x0F80) volatile __PORTAbits_t PORTAbits;

__at(0x0F81) __sfr PORTB;
__at(0x0F81) volatile __PORTBbits_t PORTBbits;

__at(0x0F82) __sfr PORTC;
__at(0x0F82) volatile __PORTCbits_t PORTCbits;

__at(0x0F83) __sfr PORTD;
__at(0x0F83) volatile __PORTDbits_t PORTDbits;

__at(0x0F84) __sfr PORTE;
__at(0x0F84) volatile __PORTEbits_t PORTEbits;

__at(0x0F85) __sfr PORTF;
__at(0x0F85) volatile __PORTFbits_t PORTFbits;

__at(0x0F86) __sfr PORTG;
__at(0x0F86) volatile __PORTGbits_t PORTGbits;

__at(0x0F87) __sfr PORTH;
__at(0x0F87) volatile __PORTHbits_t PORTHbits;

__at(0x0F88) __sfr PORTJ;
__at(0x0F88) volatile __PORTJbits_t PORTJbits;

__at(0x0F89) __sfr LATA;
__at(0x0F89) volatile __LATAbits_t LATAbits;

__at(0x0F8A) __sfr LATB;
__at(0x0F8A) volatile __LATBbits_t LATBbits;

__at(0x0F8B) __sfr LATC;
__at(0x0F8B) volatile __LATCbits_t LATCbits;

__at(0x0F8C) __sfr LATD;
__at(0x0F8C) volatile __LATDbits_t LATDbits;

__at(0x0F8D) __sfr LATE;
__at(0x0F8D) volatile __LATEbits_t LATEbits;

__at(0x0F8E) __sfr LATF;
__at(0x0F8E) volatile __LATFbits_t LATFbits;

__at(0x0F8F) __sfr LATG;
__at(0x0F8F) volatile __LATGbits_t LATGbits;

__at(0x0F90) __sfr LATH;
__at(0x0F90) volatile __LATHbits_t LATHbits;

__at(0x0F91) __sfr LATJ;
__at(0x0F91) volatile __LATJbits_t LATJbits;

__at(0x0F92) __sfr TRISA;
__at(0x0F92) volatile __TRISAbits_t TRISAbits;

__at(0x0F93) __sfr TRISB;
__at(0x0F93) volatile __TRISBbits_t TRISBbits;

__at(0x0F94) __sfr TRISC;
__at(0x0F94) volatile __TRISCbits_t TRISCbits;

__at(0x0F95) __sfr TRISD;
__at(0x0F95) volatile __TRISDbits_t TRISDbits;

__at(0x0F96) __sfr TRISE;
__at(0x0F96) volatile __TRISEbits_t TRISEbits;

__at(0x0F97) __sfr TRISF;
__at(0x0F97) volatile __TRISFbits_t TRISFbits;

__at(0x0F98) __sfr TRISG;
__at(0x0F98) volatile __TRISGbits_t TRISGbits;

__at(0x0F99) __sfr TRISH;
__at(0x0F99) volatile __TRISHbits_t TRISHbits;

__at(0x0F9A) __sfr TRISJ;
__at(0x0F9A) volatile __TRISJbits_t TRISJbits;

__at(0x0F9B) __sfr OSCTUNE;
__at(0x0F9B) volatile __OSCTUNEbits_t OSCTUNEbits;

__at(0x0F9C) __sfr PSTR1CON;
__at(0x0F9C) volatile __PSTR1CONbits_t PSTR1CONbits;

__at(0x0F9D) __sfr PIE1;
__at(0x0F9D) volatile __PIE1bits_t PIE1bits;

__at(0x0F9E) __sfr PIR1;
__at(0x0F9E) volatile __PIR1bits_t PIR1bits;

__at(0x0F9F) __sfr IPR1;
__at(0x0F9F) volatile __IPR1bits_t IPR1bits;

__at(0x0FA0) __sfr PIE2;
__at(0x0FA0) volatile __PIE2bits_t PIE2bits;

__at(0x0FA1) __sfr PIR2;
__at(0x0FA1) volatile __PIR2bits_t PIR2bits;

__at(0x0FA2) __sfr IPR2;
__at(0x0FA2) volatile __IPR2bits_t IPR2bits;

__at(0x0FA3) __sfr PIE3;
__at(0x0FA3) volatile __PIE3bits_t PIE3bits;

__at(0x0FA4) __sfr PIR3;
__at(0x0FA4) volatile __PIR3bits_t PIR3bits;

__at(0x0FA5) __sfr IPR3;
__at(0x0FA5) volatile __IPR3bits_t IPR3bits;

__at(0x0FA6) __sfr PIR6;
__at(0x0FA6) volatile __PIR6bits_t PIR6bits;

__at(0x0FA7) __sfr PSPCON;
__at(0x0FA7) volatile __PSPCONbits_t PSPCONbits;

__at(0x0FA8) __sfr HLVDCON;
__at(0x0FA8) volatile __HLVDCONbits_t HLVDCONbits;

__at(0x0FA9) __sfr IPR6;
__at(0x0FA9) volatile __IPR6bits_t IPR6bits;

__at(0x0FAA) __sfr T1GCON;
__at(0x0FAA) volatile __T1GCONbits_t T1GCONbits;

__at(0x0FAB) __sfr RCSTA;
__at(0x0FAB) volatile __RCSTAbits_t RCSTAbits;

__at(0x0FAB) __sfr RCSTA1;
__at(0x0FAB) volatile __RCSTA1bits_t RCSTA1bits;

__at(0x0FAC) __sfr TXSTA;
__at(0x0FAC) volatile __TXSTAbits_t TXSTAbits;

__at(0x0FAC) __sfr TXSTA1;
__at(0x0FAC) volatile __TXSTA1bits_t TXSTA1bits;

__at(0x0FAD) __sfr TXREG;

__at(0x0FAD) __sfr TXREG1;

__at(0x0FAE) __sfr RCREG;

__at(0x0FAE) __sfr RCREG1;

__at(0x0FAF) __sfr SPBRG;
__at(0x0FAF) volatile __SPBRGbits_t SPBRGbits;

__at(0x0FAF) __sfr SPBRG1;
__at(0x0FAF) volatile __SPBRG1bits_t SPBRG1bits;

__at(0x0FB0) __sfr T3GCON;
__at(0x0FB0) volatile __T3GCONbits_t T3GCONbits;

__at(0x0FB1) __sfr T3CON;
__at(0x0FB1) volatile __T3CONbits_t T3CONbits;

__at(0x0FB2) __sfr TMR3;

__at(0x0FB2) __sfr TMR3L;

__at(0x0FB3) __sfr TMR3H;

__at(0x0FB4) __sfr PIE4;
__at(0x0FB4) volatile __PIE4bits_t PIE4bits;

__at(0x0FB5) __sfr PIR4;
__at(0x0FB5) volatile __PIR4bits_t PIR4bits;

__at(0x0FB6) __sfr IPR4;
__at(0x0FB6) volatile __IPR4bits_t IPR4bits;

__at(0x0FB7) __sfr PIE5;
__at(0x0FB7) volatile __PIE5bits_t PIE5bits;

__at(0x0FB8) __sfr PIR5;
__at(0x0FB8) volatile __PIR5bits_t PIR5bits;

__at(0x0FB9) __sfr CCP1CON;
__at(0x0FB9) volatile __CCP1CONbits_t CCP1CONbits;

__at(0x0FBA) __sfr CCPR1;

__at(0x0FBA) __sfr CCPR1L;

__at(0x0FBB) __sfr CCPR1H;

__at(0x0FBC) __sfr ECCP1DEL;
__at(0x0FBC) volatile __ECCP1DELbits_t ECCP1DELbits;

__at(0x0FBD) __sfr ECCP1AS;
__at(0x0FBD) volatile __ECCP1ASbits_t ECCP1ASbits;

__at(0x0FBE) __sfr CVRCONL;
__at(0x0FBE) volatile __CVRCONLbits_t CVRCONLbits;

__at(0x0FBF) __sfr CVRCONH;
__at(0x0FBF) volatile __CVRCONHbits_t CVRCONHbits;

__at(0x0FC0) __sfr ADCON1L;
__at(0x0FC0) volatile __ADCON1Lbits_t ADCON1Lbits;

__at(0x0FC1) __sfr ADCON1H;
__at(0x0FC1) volatile __ADCON1Hbits_t ADCON1Hbits;

__at(0x0FC2) __sfr ADCBUF0;

__at(0x0FC2) __sfr ADCBUF0L;

__at(0x0FC3) __sfr ADCBUF0H;

__at(0x0FC4) __sfr CMSTAT;
__at(0x0FC4) volatile __CMSTATbits_t CMSTATbits;

__at(0x0FC5) __sfr SSP1CON2;
__at(0x0FC5) volatile __SSP1CON2bits_t SSP1CON2bits;

__at(0x0FC6) __sfr SSP1CON1;
__at(0x0FC6) volatile __SSP1CON1bits_t SSP1CON1bits;

__at(0x0FC7) __sfr SSP1STAT;
__at(0x0FC7) volatile __SSP1STATbits_t SSP1STATbits;

__at(0x0FC8) __sfr SSP1ADD;

__at(0x0FC9) __sfr SSP1BUF;

__at(0x0FCA) __sfr T2CON;
__at(0x0FCA) volatile __T2CONbits_t T2CONbits;

__at(0x0FCB) __sfr PR2;

__at(0x0FCC) __sfr TMR2;

__at(0x0FCD) __sfr T1CON;
__at(0x0FCD) volatile __T1CONbits_t T1CONbits;

__at(0x0FCE) __sfr TMR1;

__at(0x0FCE) __sfr TMR1L;

__at(0x0FCF) __sfr TMR1H;

__at(0x0FD0) __sfr RCON;
__at(0x0FD0) volatile __RCONbits_t RCONbits;

__at(0x0FD1) __sfr IOCF;
__at(0x0FD1) volatile __IOCFbits_t IOCFbits;

__at(0x0FD2) __sfr IPR5;
__at(0x0FD2) volatile __IPR5bits_t IPR5bits;

__at(0x0FD3) __sfr OSCCON;
__at(0x0FD3) volatile __OSCCONbits_t OSCCONbits;

__at(0x0FD5) __sfr T0CON;
__at(0x0FD5) volatile __T0CONbits_t T0CONbits;

__at(0x0FD6) __sfr TMR0;

__at(0x0FD6) __sfr TMR0L;

__at(0x0FD7) __sfr TMR0H;

__at(0x0FD8) __sfr STATUS;
__at(0x0FD8) volatile __STATUSbits_t STATUSbits;

__at(0x0FD9) __sfr FSR2L;

__at(0x0FDA) __sfr FSR2H;

__at(0x0FDB) __sfr PLUSW2;

__at(0x0FDC) __sfr PREINC2;

__at(0x0FDD) __sfr POSTDEC2;

__at(0x0FDE) __sfr POSTINC2;

__at(0x0FDF) __sfr INDF2;

__at(0x0FE0) __sfr BSR;

__at(0x0FE1) __sfr FSR1L;

__at(0x0FE2) __sfr FSR1H;

__at(0x0FE3) __sfr PLUSW1;

__at(0x0FE4) __sfr PREINC1;

__at(0x0FE5) __sfr POSTDEC1;

__at(0x0FE6) __sfr POSTINC1;

__at(0x0FE7) __sfr INDF1;

__at(0x0FE8) __sfr WREG;

__at(0x0FE9) __sfr FSR0L;

__at(0x0FEA) __sfr FSR0H;

__at(0x0FEB) __sfr PLUSW0;

__at(0x0FEC) __sfr PREINC0;

__at(0x0FED) __sfr POSTDEC0;

__at(0x0FEE) __sfr POSTINC0;

__at(0x0FEF) __sfr INDF0;

__at(0x0FF0) __sfr INTCON3;
__at(0x0FF0) volatile __INTCON3bits_t INTCON3bits;

__at(0x0FF1) __sfr INTCON2;
__at(0x0FF1) volatile __INTCON2bits_t INTCON2bits;

__at(0x0FF2) __sfr INTCON;
__at(0x0FF2) volatile __INTCONbits_t INTCONbits;

__at(0x0FF3) __sfr PROD;

__at(0x0FF3) __sfr PRODL;

__at(0x0FF4) __sfr PRODH;

__at(0x0FF5) __sfr TABLAT;

__at(0x0FF6) __sfr TBLPTR;

__at(0x0FF6) __sfr TBLPTRL;

__at(0x0FF7) __sfr TBLPTRH;

__at(0x0FF8) __sfr TBLPTRU;

__at(0x0FF9) __sfr PC;

__at(0x0FF9) __sfr PCL;

__at(0x0FFA) __sfr PCLATH;

__at(0x0FFB) __sfr PCLATU;

__at(0x0FFC) __sfr STKPTR;
__at(0x0FFC) volatile __STKPTRbits_t STKPTRbits;

__at(0x0FFD) __sfr TOS;

__at(0x0FFD) __sfr TOSL;

__at(0x0FFE) __sfr TOSH;

__at(0x0FFF) __sfr TOSU;
