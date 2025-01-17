/*-
 * Copyright (c) 1996-1997 John D. Polstra.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: releng/12.3/sys/arm64/include/elf.h 365996 2020-09-22 14:15:06Z mhorne $
 */

#ifndef	_MACHINE_ELF_H_
#define	_MACHINE_ELF_H_

/*
 * ELF definitions for the AArch64 architecture.
 */

#include <sys/elf32.h>	/* Definitions common to all 32 bit architectures. */
#include <sys/elf64.h>	/* Definitions common to all 64 bit architectures. */

#ifndef __ELF_WORD_SIZE
#define	__ELF_WORD_SIZE	64	/* Used by <sys/elf_generic.h> */
#endif

#include <sys/elf_generic.h>

/*
 * Auxiliary vector entries for passing information to the interpreter.
 */

typedef struct {	/* Auxiliary vector entry on initial stack */
	int	a_type;			/* Entry type. */
	union {
		int	a_val;		/* Integer value. */
	} a_un;
} Elf32_Auxinfo;

typedef struct {	/* Auxiliary vector entry on initial stack */
	long	a_type;			/* Entry type. */
	union {
		long	a_val;		/* Integer value. */
		void	*a_ptr;		/* Address. */
		void	(*a_fcn)(void);	/* Function pointer (not used). */
	} a_un;
} Elf64_Auxinfo;

__ElfType(Auxinfo);

#define	ELF_ARCH	EM_AARCH64

#define	ELF_MACHINE_OK(x) ((x) == (ELF_ARCH))

/* Values for a_type. */
#define	AT_NULL		0	/* Terminates the vector. */
#define	AT_IGNORE	1	/* Ignored entry. */
#define	AT_EXECFD	2	/* File descriptor of program to load. */
#define	AT_PHDR		3	/* Program header of program already loaded. */
#define	AT_PHENT	4	/* Size of each program header entry. */
#define	AT_PHNUM	5	/* Number of program header entries. */
#define	AT_PAGESZ	6	/* Page size in bytes. */
#define	AT_BASE		7	/* Interpreter's base address. */
#define	AT_FLAGS	8	/* Flags (unused). */
#define	AT_ENTRY	9	/* Where interpreter should transfer control. */
#define	AT_NOTELF	10	/* Program is not ELF ?? */
#define	AT_UID		11	/* Real uid. */
#define	AT_EUID		12	/* Effective uid. */
#define	AT_GID		13	/* Real gid. */
#define	AT_EGID		14	/* Effective gid. */
#define	AT_EXECPATH	15	/* Path to the executable. */
#define	AT_CANARY	16	/* Canary for SSP */
#define	AT_CANARYLEN	17	/* Length of the canary. */
#define	AT_OSRELDATE	18	/* OSRELDATE. */
#define	AT_NCPUS	19	/* Number of CPUs. */
#define	AT_PAGESIZES	20	/* Pagesizes. */
#define	AT_PAGESIZESLEN	21	/* Number of pagesizes. */
#define	AT_TIMEKEEP	22	/* Pointer to timehands. */
#define	AT_STACKPROT	23	/* Initial stack protection. */
#define	AT_EHDRFLAGS	24	/* e_flags field from elf hdr */
#define	AT_HWCAP	25	/* CPU feature flags. */
#define	AT_HWCAP2	26	/* CPU feature flags 2. */

#define	AT_COUNT	27	/* Count of defined aux entry types. */

/* Define "machine" characteristics */
#if __ELF_WORD_SIZE == 64
#define	ELF_TARG_CLASS	ELFCLASS64
#define	ELF_TARG_DATA	ELFDATA2LSB
#define	ELF_TARG_MACH	EM_AARCH64
#define	ELF_TARG_VER	1
#else
#define	ELF_TARG_CLASS	ELFCLASS32
#define	ELF_TARG_DATA	ELFDATA2LSB
#define	ELF_TARG_MACH	EM_ARM
#define	ELF_TARG_VER	1
#endif

#define	ET_DYN_LOAD_ADDR 0x100000

/* HWCAP */
#define	HWCAP_FP		0x00000001
#define	HWCAP_ASIMD		0x00000002
#define	HWCAP_EVTSTRM		0x00000004
#define	HWCAP_AES		0x00000008
#define	HWCAP_PMULL		0x00000010
#define	HWCAP_SHA1		0x00000020
#define	HWCAP_SHA2		0x00000040
#define	HWCAP_CRC32		0x00000080
#define	HWCAP_ATOMICS		0x00000100
#define	HWCAP_FPHP		0x00000200
#define	HWCAP_ASIMDHP		0x00000400
/*
 * XXX: The following bits (from CPUID to FLAGM) were originally incorrect,
 * but later changed to match the Linux definitions. No compatibility code is
 * provided, as the fix was expected to result in near-zero fallout.
 */
#define	HWCAP_CPUID		0x00000800
#define	HWCAP_ASIMDRDM		0x00001000
#define	HWCAP_JSCVT		0x00002000
#define	HWCAP_FCMA		0x00004000
#define	HWCAP_LRCPC		0x00008000
#define	HWCAP_DCPOP		0x00010000
#define	HWCAP_SHA3		0x00020000
#define	HWCAP_SM3		0x00040000
#define	HWCAP_SM4		0x00080000
#define	HWCAP_ASIMDDP		0x00100000
#define	HWCAP_SHA512		0x00200000
#define	HWCAP_SVE		0x00400000
#define	HWCAP_ASIMDFHM		0x00800000
#define	HWCAP_DIT		0x01000000
#define	HWCAP_USCAT		0x02000000
#define	HWCAP_ILRCPC		0x04000000
#define	HWCAP_FLAGM		0x08000000
#define	HWCAP_SSBS		0x10000000
#define	HWCAP_SB		0x20000000
#define	HWCAP_PACA		0x40000000
#define	HWCAP_PACG		0x80000000

/* HWCAP2 */
#define	HWCAP2_DCPODP		0x00000001
#define	HWCAP2_SVE2		0x00000002
#define	HWCAP2_SVEAES		0x00000004
#define	HWCAP2_SVEPMULL		0x00000008
#define	HWCAP2_SVEBITPERM	0x00000010
#define	HWCAP2_SVESHA3		0x00000020
#define	HWCAP2_SVESM4		0x00000040
#define	HWCAP2_FLAGM2		0x00000080
#define	HWCAP2_FRINT		0x00000100
#define	HWCAP2_SVEI8MM		0x00000200
#define	HWCAP2_SVEF32MM		0x00000400
#define	HWCAP2_SVEF64MM		0x00000800
#define	HWCAP2_SVEBF16		0x00001000
#define	HWCAP2_I8MM		0x00002000
#define	HWCAP2_BF16		0x00004000
#define	HWCAP2_DGH		0x00008000
#define	HWCAP2_RNG		0x00010000
#define	HWCAP2_BTI		0x00020000

#endif /* !_MACHINE_ELF_H_ */
