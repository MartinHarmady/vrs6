

































#if   defined ( __ICCARM__ )
 #pragma system_include
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang system_header
#endif

#ifndef __CORE_CM0PLUS_H_GENERIC
#define __CORE_CM0PLUS_H_GENERIC

#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

























#define __CM0PLUS_CMSIS_VERSION_MAIN (0x04U)
#define __CM0PLUS_CMSIS_VERSION_SUB  (0x1EU)
#define __CM0PLUS_CMSIS_VERSION      ((__CM0PLUS_CMSIS_VERSION_MAIN << 16U) | \
                                       __CM0PLUS_CMSIS_VERSION_SUB           )

#define __CORTEX_M                (0x00U)


#if   defined ( __CC_ARM )
  #define __ASM            __asm
  #define __INLINE         __inline
  #define __STATIC_INLINE  static __inline

#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #define __ASM            __asm
  #define __INLINE         __inline
  #define __STATIC_INLINE  static __inline

#elif defined ( __GNUC__ )
  #define __ASM            __asm
  #define __INLINE         inline
  #define __STATIC_INLINE  static inline

#elif defined ( __ICCARM__ )
  #define __ASM            __asm
  #define __INLINE         inline
  #define __STATIC_INLINE  static inline

#elif defined ( __TMS470__ )
  #define __ASM            __asm
  #define __STATIC_INLINE  static inline

#elif defined ( __TASKING__ )
  #define __ASM            __asm
  #define __INLINE         inline
  #define __STATIC_INLINE  static inline

#elif defined ( __CSMC__ )
  #define __packed
  #define __ASM            _asm
  #define __INLINE         inline
  #define __STATIC_INLINE  static inline

#else
  #error Unknown compiler
#endif




#define __FPU_USED       0U

#if defined ( __CC_ARM )
  #if defined __TARGET_FPU_VFP
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #if defined __ARM_PCS_VFP
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __GNUC__ )
  #if defined (__VFP_FP__) && !defined(__SOFTFP__)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __ICCARM__ )
  #if defined __ARMVFP__
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __TMS470__ )
  #if defined __TI_VFP_SUPPORT__
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __TASKING__ )
  #if defined __FPU_VFP__
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __CSMC__ )
  #if ( __CSMC__ & 0x400U)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#endif

#include "core_cmInstr.h"
#include "core_cmFunc.h"

#ifdef __cplusplus
}
#endif

#endif

#ifndef __CMSIS_GENERIC

#ifndef __CORE_CM0PLUS_H_DEPENDANT
#define __CORE_CM0PLUS_H_DEPENDANT

#ifdef __cplusplus
 extern "C" {
#endif


#if defined __CHECK_DEVICE_DEFINES
  #ifndef __CM0PLUS_REV
    #define __CM0PLUS_REV             0x0000U
    #warning "__CM0PLUS_REV not defined in device header file; using default!"
  #endif

  #ifndef __MPU_PRESENT
    #define __MPU_PRESENT             0U
    #warning "__MPU_PRESENT not defined in device header file; using default!"
  #endif

  #ifndef __VTOR_PRESENT
    #define __VTOR_PRESENT            0U
    #warning "__VTOR_PRESENT not defined in device header file; using default!"
  #endif

  #ifndef __NVIC_PRIO_BITS
    #define __NVIC_PRIO_BITS          2U
    #warning "__NVIC_PRIO_BITS not defined in device header file; using default!"
  #endif

  #ifndef __Vendor_SysTickConfig
    #define __Vendor_SysTickConfig    0U
    #warning "__Vendor_SysTickConfig not defined in device header file; using default!"
  #endif
#endif









#ifdef __cplusplus
  #define   __I     volatile
#else
  #define   __I     volatile const
#endif
#define     __O     volatile
#define     __IO    volatile


#define     __IM     volatile const
#define     __OM     volatile
#define     __IOM    volatile





























typedef union
{
  struct
  {
    uint32_t _reserved0:28;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} APSR_Type;


#define APSR_N_Pos                         31U
#define APSR_N_Msk                         (1UL << APSR_N_Pos)

#define APSR_Z_Pos                         30U
#define APSR_Z_Msk                         (1UL << APSR_Z_Pos)

#define APSR_C_Pos                         29U
#define APSR_C_Msk                         (1UL << APSR_C_Pos)

#define APSR_V_Pos                         28U
#define APSR_V_Msk                         (1UL << APSR_V_Pos)





typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:23;
  } b;
  uint32_t w;
} IPSR_Type;


#define IPSR_ISR_Pos                        0U
#define IPSR_ISR_Msk                       (0x1FFUL  )





typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:15;
    uint32_t T:1;
    uint32_t _reserved1:3;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} xPSR_Type;


#define xPSR_N_Pos                         31U
#define xPSR_N_Msk                         (1UL << xPSR_N_Pos)

#define xPSR_Z_Pos                         30U
#define xPSR_Z_Msk                         (1UL << xPSR_Z_Pos)

#define xPSR_C_Pos                         29U
#define xPSR_C_Msk                         (1UL << xPSR_C_Pos)

#define xPSR_V_Pos                         28U
#define xPSR_V_Msk                         (1UL << xPSR_V_Pos)

#define xPSR_T_Pos                         24U
#define xPSR_T_Msk                         (1UL << xPSR_T_Pos)

#define xPSR_ISR_Pos                        0U
#define xPSR_ISR_Msk                       (0x1FFUL  )





typedef union
{
  struct
  {
    uint32_t nPRIV:1;
    uint32_t SPSEL:1;
    uint32_t _reserved1:30;
  } b;
  uint32_t w;
} CONTROL_Type;


#define CONTROL_SPSEL_Pos                   1U
#define CONTROL_SPSEL_Msk                  (1UL << CONTROL_SPSEL_Pos)

#define CONTROL_nPRIV_Pos                   0U
#define CONTROL_nPRIV_Msk                  (1UL  )














typedef struct
{
  __IOM uint32_t ISER[1U];
        uint32_t RESERVED0[31U];
  __IOM uint32_t ICER[1U];
        uint32_t RSERVED1[31U];
  __IOM uint32_t ISPR[1U];
        uint32_t RESERVED2[31U];
  __IOM uint32_t ICPR[1U];
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  __IOM uint32_t IP[8U];
}  NVIC_Type;














typedef struct
{
  __IM  uint32_t CPUID;
  __IOM uint32_t ICSR;
#if (__VTOR_PRESENT == 1U)
  __IOM uint32_t VTOR;
#else
        uint32_t RESERVED0;
#endif
  __IOM uint32_t AIRCR;
  __IOM uint32_t SCR;
  __IOM uint32_t CCR;
        uint32_t RESERVED1;
  __IOM uint32_t SHP[2U];
  __IOM uint32_t SHCSR;
} SCB_Type;


#define SCB_CPUID_IMPLEMENTER_Pos          24U
#define SCB_CPUID_IMPLEMENTER_Msk          (0xFFUL << SCB_CPUID_IMPLEMENTER_Pos)

#define SCB_CPUID_VARIANT_Pos              20U
#define SCB_CPUID_VARIANT_Msk              (0xFUL << SCB_CPUID_VARIANT_Pos)

#define SCB_CPUID_ARCHITECTURE_Pos         16U
#define SCB_CPUID_ARCHITECTURE_Msk         (0xFUL << SCB_CPUID_ARCHITECTURE_Pos)

#define SCB_CPUID_PARTNO_Pos                4U
#define SCB_CPUID_PARTNO_Msk               (0xFFFUL << SCB_CPUID_PARTNO_Pos)

#define SCB_CPUID_REVISION_Pos              0U
#define SCB_CPUID_REVISION_Msk             (0xFUL  )


#define SCB_ICSR_NMIPENDSET_Pos            31U
#define SCB_ICSR_NMIPENDSET_Msk            (1UL << SCB_ICSR_NMIPENDSET_Pos)

#define SCB_ICSR_PENDSVSET_Pos             28U
#define SCB_ICSR_PENDSVSET_Msk             (1UL << SCB_ICSR_PENDSVSET_Pos)

#define SCB_ICSR_PENDSVCLR_Pos             27U
#define SCB_ICSR_PENDSVCLR_Msk             (1UL << SCB_ICSR_PENDSVCLR_Pos)

#define SCB_ICSR_PENDSTSET_Pos             26U
#define SCB_ICSR_PENDSTSET_Msk             (1UL << SCB_ICSR_PENDSTSET_Pos)

#define SCB_ICSR_PENDSTCLR_Pos             25U
#define SCB_ICSR_PENDSTCLR_Msk             (1UL << SCB_ICSR_PENDSTCLR_Pos)

#define SCB_ICSR_ISRPREEMPT_Pos            23U
#define SCB_ICSR_ISRPREEMPT_Msk            (1UL << SCB_ICSR_ISRPREEMPT_Pos)

#define SCB_ICSR_ISRPENDING_Pos            22U
#define SCB_ICSR_ISRPENDING_Msk            (1UL << SCB_ICSR_ISRPENDING_Pos)

#define SCB_ICSR_VECTPENDING_Pos           12U
#define SCB_ICSR_VECTPENDING_Msk           (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)

#define SCB_ICSR_VECTACTIVE_Pos             0U
#define SCB_ICSR_VECTACTIVE_Msk            (0x1FFUL  )

#if (__VTOR_PRESENT == 1U)

#define SCB_VTOR_TBLOFF_Pos                 8U
#define SCB_VTOR_TBLOFF_Msk                (0xFFFFFFUL << SCB_VTOR_TBLOFF_Pos)
#endif


#define SCB_AIRCR_VECTKEY_Pos              16U
#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)

#define SCB_AIRCR_VECTKEYSTAT_Pos          16U
#define SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)

#define SCB_AIRCR_ENDIANESS_Pos            15U
#define SCB_AIRCR_ENDIANESS_Msk            (1UL << SCB_AIRCR_ENDIANESS_Pos)

#define SCB_AIRCR_SYSRESETREQ_Pos           2U
#define SCB_AIRCR_SYSRESETREQ_Msk          (1UL << SCB_AIRCR_SYSRESETREQ_Pos)

#define SCB_AIRCR_VECTCLRACTIVE_Pos         1U
#define SCB_AIRCR_VECTCLRACTIVE_Msk        (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)


#define SCB_SCR_SEVONPEND_Pos               4U
#define SCB_SCR_SEVONPEND_Msk              (1UL << SCB_SCR_SEVONPEND_Pos)

#define SCB_SCR_SLEEPDEEP_Pos               2U
#define SCB_SCR_SLEEPDEEP_Msk              (1UL << SCB_SCR_SLEEPDEEP_Pos)

#define SCB_SCR_SLEEPONEXIT_Pos             1U
#define SCB_SCR_SLEEPONEXIT_Msk            (1UL << SCB_SCR_SLEEPONEXIT_Pos)


#define SCB_CCR_STKALIGN_Pos                9U
#define SCB_CCR_STKALIGN_Msk               (1UL << SCB_CCR_STKALIGN_Pos)

#define SCB_CCR_UNALIGN_TRP_Pos             3U
#define SCB_CCR_UNALIGN_TRP_Msk            (1UL << SCB_CCR_UNALIGN_TRP_Pos)


#define SCB_SHCSR_SVCALLPENDED_Pos         15U
#define SCB_SHCSR_SVCALLPENDED_Msk         (1UL << SCB_SHCSR_SVCALLPENDED_Pos)














typedef struct
{
  __IOM uint32_t CTRL;
  __IOM uint32_t LOAD;
  __IOM uint32_t VAL;
  __IM  uint32_t CALIB;
} SysTick_Type;


#define SysTick_CTRL_COUNTFLAG_Pos         16U
#define SysTick_CTRL_COUNTFLAG_Msk         (1UL << SysTick_CTRL_COUNTFLAG_Pos)

#define SysTick_CTRL_CLKSOURCE_Pos          2U
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)

#define SysTick_CTRL_TICKINT_Pos            1U
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)

#define SysTick_CTRL_ENABLE_Pos             0U
#define SysTick_CTRL_ENABLE_Msk            (1UL  )


#define SysTick_LOAD_RELOAD_Pos             0U
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFUL  )


#define SysTick_VAL_CURRENT_Pos             0U
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFUL  )


#define SysTick_CALIB_NOREF_Pos            31U
#define SysTick_CALIB_NOREF_Msk            (1UL << SysTick_CALIB_NOREF_Pos)

#define SysTick_CALIB_SKEW_Pos             30U
#define SysTick_CALIB_SKEW_Msk             (1UL << SysTick_CALIB_SKEW_Pos)

#define SysTick_CALIB_TENMS_Pos             0U
#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFUL  )



#if (__MPU_PRESENT == 1U)










typedef struct
{
  __IM  uint32_t TYPE;
  __IOM uint32_t CTRL;
  __IOM uint32_t RNR;
  __IOM uint32_t RBAR;
  __IOM uint32_t RASR;
} MPU_Type;


#define MPU_TYPE_IREGION_Pos               16U
#define MPU_TYPE_IREGION_Msk               (0xFFUL << MPU_TYPE_IREGION_Pos)

#define MPU_TYPE_DREGION_Pos                8U
#define MPU_TYPE_DREGION_Msk               (0xFFUL << MPU_TYPE_DREGION_Pos)

#define MPU_TYPE_SEPARATE_Pos               0U
#define MPU_TYPE_SEPARATE_Msk              (1UL  )


#define MPU_CTRL_PRIVDEFENA_Pos             2U
#define MPU_CTRL_PRIVDEFENA_Msk            (1UL << MPU_CTRL_PRIVDEFENA_Pos)

#define MPU_CTRL_HFNMIENA_Pos               1U
#define MPU_CTRL_HFNMIENA_Msk              (1UL << MPU_CTRL_HFNMIENA_Pos)

#define MPU_CTRL_ENABLE_Pos                 0U
#define MPU_CTRL_ENABLE_Msk                (1UL  )


#define MPU_RNR_REGION_Pos                  0U
#define MPU_RNR_REGION_Msk                 (0xFFUL  )


#define MPU_RBAR_ADDR_Pos                   8U
#define MPU_RBAR_ADDR_Msk                  (0xFFFFFFUL << MPU_RBAR_ADDR_Pos)

#define MPU_RBAR_VALID_Pos                  4U
#define MPU_RBAR_VALID_Msk                 (1UL << MPU_RBAR_VALID_Pos)

#define MPU_RBAR_REGION_Pos                 0U
#define MPU_RBAR_REGION_Msk                (0xFUL  )


#define MPU_RASR_ATTRS_Pos                 16U
#define MPU_RASR_ATTRS_Msk                 (0xFFFFUL << MPU_RASR_ATTRS_Pos)

#define MPU_RASR_XN_Pos                    28U
#define MPU_RASR_XN_Msk                    (1UL << MPU_RASR_XN_Pos)

#define MPU_RASR_AP_Pos                    24U
#define MPU_RASR_AP_Msk                    (0x7UL << MPU_RASR_AP_Pos)

#define MPU_RASR_TEX_Pos                   19U
#define MPU_RASR_TEX_Msk                   (0x7UL << MPU_RASR_TEX_Pos)

#define MPU_RASR_S_Pos                     18U
#define MPU_RASR_S_Msk                     (1UL << MPU_RASR_S_Pos)

#define MPU_RASR_C_Pos                     17U
#define MPU_RASR_C_Msk                     (1UL << MPU_RASR_C_Pos)

#define MPU_RASR_B_Pos                     16U
#define MPU_RASR_B_Msk                     (1UL << MPU_RASR_B_Pos)

#define MPU_RASR_SRD_Pos                    8U
#define MPU_RASR_SRD_Msk                   (0xFFUL << MPU_RASR_SRD_Pos)

#define MPU_RASR_SIZE_Pos                   1U
#define MPU_RASR_SIZE_Msk                  (0x1FUL << MPU_RASR_SIZE_Pos)

#define MPU_RASR_ENABLE_Pos                 0U
#define MPU_RASR_ENABLE_Msk                (1UL  )


#endif

























#define _VAL2FLD(field, value)    ((value << field ## _Pos) & field ## _Msk)







#define _FLD2VAL(field, value)    ((value & field ## _Msk) >> field ## _Pos)












#define SCS_BASE            (0xE000E000UL)
#define SysTick_BASE        (SCS_BASE +  0x0010UL)
#define NVIC_BASE           (SCS_BASE +  0x0100UL)
#define SCB_BASE            (SCS_BASE +  0x0D00UL)

#define SCB                 ((SCB_Type       *)     SCB_BASE      )
#define SysTick             ((SysTick_Type   *)     SysTick_BASE  )
#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )

#if (__MPU_PRESENT == 1U)
  #define MPU_BASE          (SCS_BASE +  0x0D90UL)
  #define MPU               ((MPU_Type       *)     MPU_BASE      )
#endif




























#define _BIT_SHIFT(IRQn)         (  ((((uint32_t)(int32_t)(IRQn))         )      &  0x03UL) * 8UL)
#define _SHP_IDX(IRQn)           ( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >>    2UL)      )
#define _IP_IDX(IRQn)            (   (((uint32_t)(int32_t)(IRQn))                >>    2UL)      )







__STATIC_INLINE void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  NVIC->ISER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}







__STATIC_INLINE void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  NVIC->ICER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}









__STATIC_INLINE uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t)(((NVIC->ISPR[0U] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}







__STATIC_INLINE void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ISPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}







__STATIC_INLINE void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}









__STATIC_INLINE void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) < 0)
  {
    SCB->SHP[_SHP_IDX(IRQn)] = ((uint32_t)(SCB->SHP[_SHP_IDX(IRQn)] & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
       (((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(IRQn)));
  }
  else
  {
    NVIC->IP[_IP_IDX(IRQn)]  = ((uint32_t)(NVIC->IP[_IP_IDX(IRQn)]  & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
       (((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(IRQn)));
  }
}











__STATIC_INLINE uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) < 0)
  {
    return((uint32_t)(((SCB->SHP[_SHP_IDX(IRQn)] >> _BIT_SHIFT(IRQn) ) & (uint32_t)0xFFUL) >> (8U - __NVIC_PRIO_BITS)));
  }
  else
  {
    return((uint32_t)(((NVIC->IP[ _IP_IDX(IRQn)] >> _BIT_SHIFT(IRQn) ) & (uint32_t)0xFFUL) >> (8U - __NVIC_PRIO_BITS)));
  }
}






__STATIC_INLINE void NVIC_SystemReset(void)
{
  __DSB();

  SCB->AIRCR  = ((0x5FAUL << SCB_AIRCR_VECTKEY_Pos) |
                 SCB_AIRCR_SYSRESETREQ_Msk);
  __DSB();

  for(;;)
  {
    __NOP();
  }
}













#if (__Vendor_SysTickConfig == 0U)












__STATIC_INLINE uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
  {
    return (1UL);
  }

  SysTick->LOAD  = (uint32_t)(ticks - 1UL);
  NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
  SysTick->VAL   = 0UL;
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;
  return (0UL);
}

#endif






#ifdef __cplusplus
}
#endif

#endif

#endif
