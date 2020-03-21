/**************************************************
 *
 * This file declares the ARM intrinsic inline functions.
 *
 * Copyright 1999-2017 IAR Systems. All rights reserved.
 *
 * $Revision: 121017 $
 *
 **************************************************/

#ifndef __INTRINSICS_INCLUDED
#define __INTRINSICS_INCLUDED

#ifndef _SYSTEM_BUILD
  #pragma system_include
#endif

/*
 * Check that the correct C compiler is used.
 */
#if ((__TID__ >> 8) & 0x007F) != 79
  #error "File intrinsics.h can only be used together with iccarm."
#endif

#ifndef __ICCARM_INTRINSICS_VERSION__
  #error "Unknown compiler intrinsics version"
#elif __ICCARM_INTRINSICS_VERSION__ != 2
  #error "Compiler intrinsics version does not match this file"
#endif

#include <iccarm_builtin.h>

#define __no_operation __iar_builtin_no_operation
#define __disable_interrupt __iar_builtin_disable_interrupt
#define __enable_interrupt __iar_builtin_enable_interrupt
#define __get_interrupt_state __iar_builtin_get_interrupt_state
#define __set_interrupt_state __iar_builtin_set_interrupt_state

#ifdef __ARM_PROFILE_M__
  /* System control access for Cortex-M cores */
  #define __get_PSR __iar_builtin_get_PSR
  #define __get_IPSR __iar_builtin_get_IPSR
  #define __get_MSP __iar_builtin_get_MSP
  #define __set_MSP __iar_builtin_set_MSP
  #define __get_PSP __iar_builtin_get_PSP
  #define __set_PSP __iar_builtin_set_PSP
  #define __get_PRIMASK __iar_builtin_get_PRIMASK
  #define __set_PRIMASK __iar_builtin_set_PRIMASK
  #define __get_CONTROL __iar_builtin_get_CONTROL
  #define __set_CONTROL __iar_builtin_set_CONTROL

  #ifdef __ARM7__
    /* These are only available for v7M */
    #define __get_FAULTMASK __iar_builtin_get_FAULTMASK
    #define __set_FAULTMASK __iar_builtin_set_FAULTMASK
    #define __get_BASEPRI __iar_builtin_get_BASEPRI
    #define __set_BASEPRI __iar_builtin_set_BASEPRI
  #endif /* __ARM7__ */

#else /* __ARM_PROFILE_M__ */

  /* "Old" style intrerrupt control routines */
  #define __disable_irq __iar_builtin_disable_irq
  #define __enable_irq __iar_builtin_enable_irq
#endif /* __ARM_PROFILE_M__ */

#define __disable_fiq __iar_builtin_disable_fiq
#define __enable_fiq __iar_builtin_enable_fiq

/* ARM-mode intrinsics */
#define __SWP __iar_builtin_SWP
#define __SWPB __iar_builtin_SWPB

/*  Co-processor operations */
#define __CDP __iar_builtin_CDP
#define __CDP2 __iar_builtin_CDP2

/*  Co-processor access */
#define __MCR __iar_builtin_MCR
#define __MRC __iar_builtin_MRC
#define __MCR2 __iar_builtin_MCR2
#define __MRC2 __iar_builtin_MRC2
#define __MCRR __iar_builtin_MCRR
#define __MCRR2 __iar_builtin_MCRR2
#define __MRRC __iar_builtin_MRRC
#define __MRRC2 __iar_builtin_MRRC2

/* Load coprocessor register. */
#define __LDC __iar_builtin_LDC
#define __LDCL __iar_builtin_LDCL
#define __LDC2 __iar_builtin_LDC2
#define __LDC2L __iar_builtin_LDC2L

/* Store coprocessor register. */
#define __STC __iar_builtin_STC
#define __STCL __iar_builtin_STCL
#define __STC2 __iar_builtin_STC2
#define __STC2L __iar_builtin_STC2L

/* Load coprocessor register (noindexed version with coprocessor option). */
#define __LDC_noidx __iar_builtin_LDC_noidx
#define __LDCL_noidx __iar_builtin_LDCL_noidx
#define __LDC2_noidx __iar_builtin_LDC2_noidx
#define __LDC2L_noidx __iar_builtin_LDC2L_noidx

/* Store coprocessor register (version with coprocessor option). */
#define __STC_noidx __iar_builtin_STC_noidx
#define __STCL_noidx __iar_builtin_STCL_noidx
#define __STC2_noidx __iar_builtin_STC2_noidx
#define __STC2L_noidx __iar_builtin_STC2L_noidx

/* Reads a system register */
#define __arm_rsr __iar_builtin_rsr
#define __arm_rsr64 __iar_builtin_rsr64
#define __arm_rsrp __iar_builtin_rsrp

/* Writes a system register */
#define __arm_wsr __iar_builtin_wsr
#define __arm_wsr64 __iar_builtin_wsr64
#define __arm_wsrp __iar_builtin_wsrp

/* Co-processor intrinsics, ACLE-style */
#define __arm_cdp __iar_builtin_CDP
#define __arm_cdp2 __iar_builtin_CDP2
#define __arm_ldc __iar_builtin_LDC
#define __arm_ldcl __iar_builtin_LDCL
#define __arm_ldc2 __iar_builtin_LDC2
#define __arm_ldc2l __iar_builtin_LDC2L
#define __arm_stc __iar_builtin_STC
#define __arm_stcl __iar_builtin_STCL
#define __arm_stc2 __iar_builtin_STC2
#define __arm_stc2l __iar_builtin_STC2L
#define __arm_mcr __iar_builtin_MCR
#define __arm_mcr2 __iar_builtin_MCR2
#define __arm_mrc __iar_builtin_MRC
#define __arm_mrc2 __iar_builtin_MRC2
#define __arm_mcrr __iar_builtin_MCRR
#define __arm_mcrr2 __iar_builtin_MCRR2
#define __arm_mrrc __iar_builtin_MRRC
#define __arm_mrrc2 __iar_builtin_MRRC2

/* ACLE: square root */
#define __sqrt(x)  __iar_builtin_VSQRT_F64(x)
#define __sqrtf(x) __iar_builtin_VSQRT_F32(x)

/* ACLE: fused mac */
#define __fma(x,y,z)  __iar_builtin_VFMA_F64((z), (x), (y))
#define __fmaf(x,y,z) __iar_builtin_VFMA_F32((z), (x), (y))

/* ACLE: Round to nearest with ties to even */
#define __rintn(x)  __iar_builtin_VRINTN_F64(x)
#define __rintnf(x) __iar_builtin_VRINTN_F32(x)

/* ACLE: CRC32 extension */
#define __crc32b(x,y)  __iar_builtin_CRC32B((x), (y))
#define __crc32h(x,y)  __iar_builtin_CRC32H((x), (y))
#define __crc32w(x,y)  __iar_builtin_CRC32W((x), (y))
#define __crc32cb(x,y) __iar_builtin_CRC32CB((x), (y))
#define __crc32ch(x,y) __iar_builtin_CRC32CH((x), (y))
#define __crc32cw(x,y) __iar_builtin_CRC32CW((x), (y))
#ifdef __ARM_FEATURE_CRC32
_Pragma("inline=forced") __intrinsic
unsigned int __crc32d(unsigned int crc, unsigned long long data)
{
  crc = __crc32w(crc, (unsigned int)(data));
  crc = __crc32w(crc, (unsigned int)(data >> 32));
  return crc;
}
_Pragma("inline=forced") __intrinsic
unsigned int __crc32cd(unsigned int crc, unsigned long long data)
{
  crc = __crc32cw(crc, (unsigned int)(data));
  crc = __crc32cw(crc, (unsigned int)(data >> 32));
  return crc;
}
#endif

/* square root */
#define __VSQRT_F64(x) __iar_builtin_VSQRT_F64(x)
#define __VSQRT_F32(x) __iar_builtin_VSQRT_F32(x)

/* fused mac */
#define __VFMA_F64(a,x,y)  __iar_builtin_VFMA_F64((a), (x), (y))
#define __VFMS_F64(a,x,y)  __iar_builtin_VFMS_F64((a), (x), (y))
#define __VFNMA_F64(a,x,y) __iar_builtin_VFNMA_F64((a), (x), (y))
#define __VFNMS_F64(a,x,y) __iar_builtin_VFNMS_F64((a), (x), (y))
#define __VFMA_F32(a,x,y)  __iar_builtin_VFMA_F32((a), (x), (y))
#define __VFMS_F32(a,x,y)  __iar_builtin_VFMS_F32((a), (x), (y))
#define __VFNMA_F32(a,x,y) __iar_builtin_VFNMA_F32((a), (x), (y))
#define __VFNMS_F32(a,x,y) __iar_builtin_VFNMS_F32((a), (x), (y))

/* directed rounding.
 * NOTE: for example VRINTA becomes VCVTA when converted to int.
 */
#define __VRINTA_F64(x) __iar_builtin_VRINTA_F64(x)
#define __VRINTM_F64(x) __iar_builtin_VRINTM_F64(x)
#define __VRINTN_F64(x) __iar_builtin_VRINTN_F64(x)
#define __VRINTP_F64(x) __iar_builtin_VRINTP_F64(x)
#define __VRINTX_F64(x) __iar_builtin_VRINTX_F64(x)
#define __VRINTR_F64(x) __iar_builtin_VRINTR_F64(x)
#define __VRINTZ_F64(x) __iar_builtin_VRINTZ_F64(x)
#define __VRINTA_F32(x) __iar_builtin_VRINTA_F32(x)
#define __VRINTM_F32(x) __iar_builtin_VRINTM_F32(x)
#define __VRINTN_F32(x) __iar_builtin_VRINTN_F32(x)
#define __VRINTP_F32(x) __iar_builtin_VRINTP_F32(x)
#define __VRINTX_F32(x) __iar_builtin_VRINTX_F32(x)
#define __VRINTR_F32(x) __iar_builtin_VRINTR_F32(x)
#define __VRINTZ_F32(x) __iar_builtin_VRINTZ_F32(x)

/* numeric min/max */
#define __VMINNM_F64(x,y) __iar_builtin_VMINNM_F64((x), (y))
#define __VMAXNM_F64(x,y) __iar_builtin_VMAXNM_F64((x), (y))
#define __VMINNM_F32(x,y) __iar_builtin_VMINNM_F32((x), (y))
#define __VMAXNM_F32(x,y) __iar_builtin_VMAXNM_F32((x), (y))

/* CRC32 extension */
#define __CRC32B(x,y)  __iar_builtin_CRC32B((x), (y))
#define __CRC32H(x,y)  __iar_builtin_CRC32H((x), (y))
#define __CRC32W(x,y)  __iar_builtin_CRC32W((x), (y))
#define __CRC32CB(x,y) __iar_builtin_CRC32CB((x), (y))
#define __CRC32CH(x,y) __iar_builtin_CRC32CH((x), (y))
#define __CRC32CW(x,y) __iar_builtin_CRC32CW((x), (y))

#ifdef __ARM_PROFILE_M__
  /* Status register access, v7M: */
  #define __get_APSR __iar_builtin_get_APSR
  #define __set_APSR __iar_builtin_set_APSR
#else /* __ARM_PROFILE_M__ */
  /* Status register access */
  #define __get_CPSR __iar_builtin_get_CPSR
  #define __set_CPSR __iar_builtin_set_CPSR
#endif /* __ARM_PROFILE_M__ */

/* Floating-point status and control register access */
#define __get_FPSCR __iar_builtin_get_FPSCR
#define __set_FPSCR __iar_builtin_set_FPSCR

/* Architecture v5T, CLZ is also available in Thumb mode for Thumb2 cores */
#if !defined(__CMSIS_IAR_H__) && !defined(__CMSIS_ICCARM_H__)
  #define __CLZ __iar_builtin_CLZ
#endif  
#define __ROR __iar_builtin_ROR
#define __RRX __iar_builtin_RRX

/* Architecture v5TE */
#if !defined(__ARM_PROFILE_M__) || defined(__ARM_MEDIA__)
  #define __QADD __iar_builtin_QADD
  #define __QDADD __iar_builtin_QDADD
  #define __QSUB __iar_builtin_QSUB
  #define __QDSUB __iar_builtin_QDSUB

  #define __QDOUBLE __iar_builtin_QDOUBLE

  #define __QFlag __iar_builtin_QFlag
  #define __reset_Q_flag __iar_builtin_reset_Q_flag
#endif

#define __QCFlag __iar_builtin_QCFlag
#define __reset_QC_flag __iar_builtin_reset_QC_flag

#define __SMUL __iar_builtin_SMUL

/* Architecture v6, REV and REVSH are also available in thumb mode */
#define __REV __iar_builtin_REV
#if !defined(__CMSIS_IAR_H__) && !defined(__CMSIS_ICCARM_H__)
  #define __REVSH __iar_builtin_REVSH
#endif  

#define __REV16 __iar_builtin_REV16
#define __RBIT __iar_builtin_RBIT

#define __LDREXB __iar_builtin_LDREXB
#define __LDREXH __iar_builtin_LDREXH
#define __LDREX __iar_builtin_LDREX
#define __LDREXD __iar_builtin_LDREXD

#define __STREXB __iar_builtin_STREXB
#define __STREXH __iar_builtin_STREXH
#define __STREX __iar_builtin_STREX
#define __STREXD __iar_builtin_STREXD

#define __CLREX __iar_builtin_CLREX

#define __SEV __iar_builtin_SEV
#define __WFE __iar_builtin_WFE
#define __WFI __iar_builtin_WFI
#define __YIELD __iar_builtin_YIELD

#define __PLI __iar_builtin_PLI
#define __PLD __iar_builtin_PLD
#define __PLDW __iar_builtin_PLDW

#if !defined(__CMSIS_IAR_H__) && !defined(__CMSIS_ICCARM_H__)
  #define __SSAT __iar_builtin_SSAT
  #define __USAT __iar_builtin_USAT
#endif

#if __ARM_MEDIA__
  /* Architecture v6 Media instructions */
  #define __SEL __iar_builtin_SEL
  #define __SADD8 __iar_builtin_SADD8
  #define __SADD16 __iar_builtin_SADD16
  #define __SSUB8 __iar_builtin_SSUB8
  #define __SSUB16 __iar_builtin_SSUB16
  #define __SADDSUBX __iar_builtin_SADDSUBX
  #define __SSUBADDX __iar_builtin_SSUBADDX
  #define __SHADD8 __iar_builtin_SHADD8
  #define __SHADD16 __iar_builtin_SHADD16
  #define __SHSUB8 __iar_builtin_SHSUB8
  #define __SHSUB16 __iar_builtin_SHSUB16
  #define __SHADDSUBX __iar_builtin_SHADDSUBX
  #define __SHSUBADDX __iar_builtin_SHSUBADDX
  #define __QADD8 __iar_builtin_QADD8
  #define __QADD16 __iar_builtin_QADD16
  #define __QSUB8 __iar_builtin_QSUB8
  #define __QSUB16 __iar_builtin_QSUB16
  #define __QADDSUBX __iar_builtin_QADDSUBX
  #define __QSUBADDX __iar_builtin_QSUBADDX
  #define __UADD8 __iar_builtin_UADD8
  #define __UADD16 __iar_builtin_UADD16
  #define __USUB8 __iar_builtin_USUB8
  #define __USUB16 __iar_builtin_USUB16
  #define __UADDSUBX __iar_builtin_UADDSUBX
  #define __USUBADDX __iar_builtin_USUBADDX
  #define __UHADD8 __iar_builtin_UHADD8
  #define __UHADD16 __iar_builtin_UHADD16
  #define __UHSUB8 __iar_builtin_UHSUB8
  #define __UHSUB16 __iar_builtin_UHSUB16
  #define __UHADDSUBX __iar_builtin_UHADDSUBX
  #define __UHSUBADDX __iar_builtin_UHSUBADDX
  #define __UQADD8 __iar_builtin_UQADD8
  #define __UQADD16 __iar_builtin_UQADD16
  #define __UQSUB8 __iar_builtin_UQSUB8
  #define __UQSUB16 __iar_builtin_UQSUB16
  #define __UQADDSUBX __iar_builtin_UQADDSUBX
  #define __UQSUBADDX __iar_builtin_UQSUBADDX
  #define __USAD8 __iar_builtin_USAD8
  #define __USADA8 __iar_builtin_USADA8
  #define __SSAT16 __iar_builtin_SSAT16
  #define __USAT16 __iar_builtin_USAT16
  #define __SMUAD __iar_builtin_SMUAD
  #define __SMUSD __iar_builtin_SMUSD
  #define __SMUADX __iar_builtin_SMUADX
  #define __SMUSDX __iar_builtin_SMUSDX
  #define __SMLAD __iar_builtin_SMLAD
  #define __SMLSD __iar_builtin_SMLSD
  #define __SMLADX __iar_builtin_SMLADX
  #define __SMLSDX __iar_builtin_SMLSDX
  #define __SMLALD __iar_builtin_SMLALD
  #define __SMLALDX __iar_builtin_SMLALDX
  #define __SMLSLD __iar_builtin_SMLSLD
  #define __SMLSLDX __iar_builtin_SMLSLDX
  #define __PKHBT __iar_builtin_PKHBT
  #define __PKHTB __iar_builtin_PKHTB
  #define __SMLABB __iar_builtin_SMLABB
  #define __SMLABT __iar_builtin_SMLABT
  #define __SMLATB __iar_builtin_SMLATB
  #define __SMLATT __iar_builtin_SMLATT
  #define __SMLAWB __iar_builtin_SMLAWB
  #define __SMLAWT __iar_builtin_SMLAWT
  #define __SMMLA __iar_builtin_SMMLA
  #define __SMMLAR __iar_builtin_SMMLAR
  #define __SMMLS __iar_builtin_SMMLS
  #define __SMMLSR __iar_builtin_SMMLSR
  #define __SMMUL __iar_builtin_SMMUL
  #define __SMMULR __iar_builtin_SMMULR
  #define __SMULBB __iar_builtin_SMULBB
  #define __SMULBT __iar_builtin_SMULBT
  #define __SMULTB __iar_builtin_SMULTB
  #define __SMULTT __iar_builtin_SMULTT
  #define __SMULWB __iar_builtin_SMULWB
  #define __SMULWT __iar_builtin_SMULWT
  #define __SXTAB __iar_builtin_SXTAB
  #define __SXTAH __iar_builtin_SXTAH
  #define __UXTAB __iar_builtin_UXTAB
  #define __UXTAH __iar_builtin_UXTAH
  #define __UMAAL __iar_builtin_UMAAL
  #define __SMLALBB __iar_builtin_SMLALBB
  #define __SMLALBT __iar_builtin_SMLALBT
  #define __SMLALTB __iar_builtin_SMLALTB
  #define __SMLALTT __iar_builtin_SMLALTT
  #define __UXTB16 __iar_builtin_UXTB16
  #define __UXTAB16 __iar_builtin_UXTAB16
  #define __SXTB16 __iar_builtin_SXTB16
  #define __SXTAB16 __iar_builtin_SXTAB16
  #define __SASX __iar_builtin_SASX
  #define __SSAX __iar_builtin_SSAX
  #define __SHASX __iar_builtin_SHASX
  #define __SHSAX __iar_builtin_SHSAX
  #define __QASX __iar_builtin_QASX
  #define __QSAX __iar_builtin_QSAX
  #define __UASX __iar_builtin_UASX
  #define __USAX __iar_builtin_USAX
  #define __UHASX __iar_builtin_UHASX
  #define __UHSAX __iar_builtin_UHSAX
  #define __UQASX __iar_builtin_UQASX
  #define __UQSAX __iar_builtin_UQSAX
#endif /* __ARM_MEDIA__ */

/* Architecture v7 instructions */
#define __DMB __iar_builtin_DMB
#define __DSB __iar_builtin_DSB
#define __ISB __iar_builtin_ISB

/* Architecture v8-M instructions */
#define __TT __iar_builtin_TT
#define __TTT __iar_builtin_TTT
#define __TTA __iar_builtin_TTA
#define __TTAT __iar_builtin_TTAT

#define __fabs(x)  fabs(x)
#define __fabsf(x) fabsf(x)

#endif  /* __INTRINSICS_INCLUDED */
