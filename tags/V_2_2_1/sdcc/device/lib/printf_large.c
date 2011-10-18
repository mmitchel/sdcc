/*-------------------------------------------------------------------------
  printf.c - formatted output conversion
 
             Written By - Martijn van Balen aed@iae.nl (1999)

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

#include <stdarg.h>
#include <stdio.h>

#if defined(SDCC_MODEL_LARGE) || defined(SDCC_MODEL_FLAT24)
#define XSPEC xdata
#else
#define XSPEC
#endif

int printf (XSPEC const char *format, ...) reentrant
{
  va_list arg;
  int done;

  va_start (arg, format);
  done = vprintf (format, arg);
  va_end (arg);

  return done;
}

int sprintf (const char *buf, XSPEC const char *format, ...) reentrant
{
  va_list arg;
  int done;

  va_start (arg, format);
  done = vsprintf (buf, format, arg);
  va_end (arg);

  return done;
}