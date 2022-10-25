/* This file is automatically generated.
   It defines macros to allow user program to find the shared
   library files which come as part of GNU libc.  */
#ifndef __GNU_LIB_NAMES_H
#define __GNU_LIB_NAMES_H	1

#include <bits/wordsize.h>

#if __WORDSIZE == 32 && defined __riscv_float_abi_soft
# include <gnu/lib-names-ilp32.h>
#endif
#if __WORDSIZE == 32 && defined __riscv_float_abi_double
# include <gnu/lib-names-ilp32d.h>
#endif
#if __WORDSIZE == 64 && defined __riscv_float_abi_soft
# include <gnu/lib-names-lp64.h>
#endif
#if __WORDSIZE == 64 && defined __riscv_float_abi_double
# include <gnu/lib-names-lp64d.h>
#endif

#endif	/* gnu/lib-names.h */