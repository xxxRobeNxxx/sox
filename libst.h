/* libst.h - include file for portable sound tools library
**
** Copyright (C) 1989
**
** Permission to use, copy, modify, and distribute this software and its
** documentation for any purpose and without fee is hereby granted, provided
** that the above copyright notice appear in all copies and that both that
** copyright notice and this permission notice appear in supporting
** documentation.  This software is provided "as is" without express or
** implied warranty.
*/

/*******************************************************************/
/* Common function prototypes used internal to Sound Tools library */
/*******************************************************************/

/******************************************************************/
/* Define u-law and a-law functionsto convert to linear PCM data  */
/* Can use faster lookup tables by using the appropriate defines. */
/******************************************************************/
#ifdef FAST_ULAW_CONVERSION
extern int           ulaw_exp_table[256];
extern unsigned char ulaw_comp_table[16384];
#define st_ulaw_to_linear(ulawbyte)   ulaw_exp_table[ulawbyte]
#define st_linear_to_ulaw(linearword) ulaw_comp_table[((short)linearword / 4) & 0x3fff]
#else
unsigned char st_linear_to_ulaw( /* short sample */ );
int           st_ulaw_to_linear( /* unsigned char ulawbyte */ );
#endif

#ifdef FAST_ALAW_CONVERSION
extern int           Alaw_exp_table[256];
extern unsigned char Alaw_comp_table[16384];
#define st_Alaw_to_linear(Alawbyte)   Alaw_exp_table[Alawbyte]
#define st_linear_to_Alaw(linearword) Alaw_comp_table[((short)linearword / 4) & 0x3fff]
#else
unsigned char st_linear_to_Alaw( /* short sample */ );
int           st_Alaw_to_linear( /* unsigned char ulawbyte */ );
#endif

/* Greatest Common Demoninator */
LONG st_gcd(/* a, b */);
/* Least Common Multiple */
LONG st_lcm(/* a, b */);

/****************************************************/
/* Prototypes for internal cross-platform functions */
/****************************************************/

#ifndef HAVE_RAND
extern int rand();
extern void srand(/* seed */);
#endif
extern void st_initrand();

extern LONG st_clip24();
extern void st_sine();
extern void st_triangle();

#ifndef HAVE_STRERROR
char *strerror(/*errorcode*/);
#endif
