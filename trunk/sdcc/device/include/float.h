/*-------------------------------------------------------------------------
  float.h - ANSI functions forward declarations
 
             Written By -  Sandeep Dutta . sandeep.dutta@usa.net (1998)

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
   
   In other words, you are welcome to use, share and improve this program.
   You are forbidden to forbid anyone else to use, share and improve
   what you give them.   Help stamp out software-hoarding!  
-------------------------------------------------------------------------*/

#ifndef __SDC51_FLOAT_H
#define __SDC51_FLOAT_H 1

#include <limits.h>

#define FLT_RADIX       2
#define FLT_MANT_DIG    24
#define FLT_EPSILON     1.192092896E-07F
#define FLT_DIG         6
#define FLT_MIN_EXP     (-125)
#define FLT_MIN         1.175494351E-38F
#define FLT_MIN_10_EXP  (-37)
#define FLT_MAX_EXP     (+128)
#define FLT_MAX         3.402823466E+38F
#define FLT_MAX_10_EXP  (+38)

/* the following deal with IEEE single-precision numbers */
#define EXCESS		126
#define SIGNBIT		((unsigned long)0x80000000)
#define HIDDEN		(unsigned long)(1 << 23)
#define SIGN(fp)	((fp >> (8*sizeof(fp)-1)) & 1)
#define EXP(fp)		(((fp) >> 23) & (unsigned int) 0x00FF)
#define MANT(fp)	(((fp) & (unsigned long)0x007FFFFF) | HIDDEN)
#define NORM            0xff000000
#define PACK(s,e,m)	((s) | ((e) << 23) | (m))

float _uchar2fs (unsigned char);
float _schar2fs (signed char);
float _uint2fs (unsigned int);
float _sint2fs (signed int);
float _ulong2fs (unsigned long);
float _slong2fs (signed long);
unsigned char _fs2uchar (float);
signed char _fs2schar (float);
unsigned int _fs2uint (float);
signed int _fs2sint (float);
unsigned long _fs2ulong (float);
signed long _fs2slong (float);

float _fsadd (float, float);
float _fssub (float, float);
float _fsmul (float, float);
float _fsdiv (float, float);

char _fslt (float, float);
char _fseq (float, float);
char _fsqt (float, float);

#endif





