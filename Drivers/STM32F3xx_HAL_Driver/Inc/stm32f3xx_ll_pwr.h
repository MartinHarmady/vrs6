



































#ifndef __STM32F3xx_LL_PWR_H
#define __STM32F3xx_LL_PWR_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f3xx.h"





#if defined(PWR)



















#define LL_PWR_CR_CSBF                     PWR_CR_CSBF
#define LL_PWR_CR_CWUF                     PWR_CR_CWUF








#define LL_PWR_CSR_WUF                     PWR_CSR_WUF
#define LL_PWR_CSR_SBF                     PWR_CSR_SBF
#if defined(PWR_PVD_SUPPORT)
#define LL_PWR_CSR_PVDO                    PWR_CSR_PVDO
#endif
#if defined(PWR_CSR_VREFINTRDYF)
#define LL_PWR_CSR_VREFINTRDYF             PWR_CSR_VREFINTRDYF
#endif
#define LL_PWR_CSR_EWUP1                   PWR_CSR_EWUP1
#define LL_PWR_CSR_EWUP2                   PWR_CSR_EWUP2
#if defined(PWR_CSR_EWUP3)
#define LL_PWR_CSR_EWUP3                   PWR_CSR_EWUP3
#endif








#define LL_PWR_MODE_STOP_MAINREGU             0x00000000U
#define LL_PWR_MODE_STOP_LPREGU               (PWR_CR_LPDS)
#define LL_PWR_MODE_STANDBY                   (PWR_CR_PDDS)




#if defined(PWR_CR_LPDS)



#define LL_PWR_REGU_DSMODE_MAIN        0x00000000U
#define LL_PWR_REGU_DSMODE_LOW_POWER   (PWR_CR_LPDS)



#endif

#if defined(PWR_PVD_SUPPORT)



#define LL_PWR_PVDLEVEL_0                  (PWR_CR_PLS_LEV0)
#define LL_PWR_PVDLEVEL_1                  (PWR_CR_PLS_LEV1)
#define LL_PWR_PVDLEVEL_2                  (PWR_CR_PLS_LEV2)
#define LL_PWR_PVDLEVEL_3                  (PWR_CR_PLS_LEV3)
#define LL_PWR_PVDLEVEL_4                  (PWR_CR_PLS_LEV4)
#define LL_PWR_PVDLEVEL_5                  (PWR_CR_PLS_LEV5)
#define LL_PWR_PVDLEVEL_6                  (PWR_CR_PLS_LEV6)
#define LL_PWR_PVDLEVEL_7                  (PWR_CR_PLS_LEV7)



#endif



#define LL_PWR_WAKEUP_PIN1                 (PWR_CSR_EWUP1)
#define LL_PWR_WAKEUP_PIN2                 (PWR_CSR_EWUP2)
#if defined(PWR_CSR_EWUP3)
#define LL_PWR_WAKEUP_PIN3                 (PWR_CSR_EWUP3)
#endif







#if defined(SDADC1)
#define LL_PWR_SDADC_ANALOG1              (PWR_CR_ENSD1)
#endif
#if defined(SDADC2)
#define LL_PWR_SDADC_ANALOG2              (PWR_CR_ENSD2)
#endif
#if defined(SDADC3)
#define LL_PWR_SDADC_ANALOG3              (PWR_CR_ENSD3)
#endif























#define LL_PWR_WriteReg(__REG__, __VALUE__) WRITE_REG(PWR->__REG__, (__VALUE__))






#define LL_PWR_ReadReg(__REG__) READ_REG(PWR->__REG__)



























__STATIC_INLINE void LL_PWR_EnableSDADC(uint32_t Analogx)
{
  SET_BIT(PWR->CR, Analogx);
}












__STATIC_INLINE void LL_PWR_DisableSDADC(uint32_t Analogx)
{
  CLEAR_BIT(PWR->CR, Analogx);
}












__STATIC_INLINE uint32_t LL_PWR_IsEnabledSDADC(uint32_t Analogx)
{
  return (READ_BIT(PWR->CR, Analogx) == (Analogx));
}






__STATIC_INLINE void LL_PWR_EnableBkUpAccess(void)
{
  SET_BIT(PWR->CR, PWR_CR_DBP);
}






__STATIC_INLINE void LL_PWR_DisableBkUpAccess(void)
{
  CLEAR_BIT(PWR->CR, PWR_CR_DBP);
}






__STATIC_INLINE uint32_t LL_PWR_IsEnabledBkUpAccess(void)
{
  return (READ_BIT(PWR->CR, PWR_CR_DBP) == (PWR_CR_DBP));
}

#if defined(PWR_CR_LPDS)








__STATIC_INLINE void LL_PWR_SetRegulModeDS(uint32_t RegulMode)
{
  MODIFY_REG(PWR->CR, PWR_CR_LPDS, RegulMode);
}








__STATIC_INLINE uint32_t LL_PWR_GetRegulModeDS(void)
{
  return (uint32_t)(READ_BIT(PWR->CR, PWR_CR_LPDS));
}
#endif











__STATIC_INLINE void LL_PWR_SetPowerMode(uint32_t PDMode)
{
  MODIFY_REG(PWR->CR, (PWR_CR_PDDS| PWR_CR_LPDS), PDMode);
}










__STATIC_INLINE uint32_t LL_PWR_GetPowerMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR, (PWR_CR_PDDS| PWR_CR_LPDS)));
}

#if defined(PWR_PVD_SUPPORT)














__STATIC_INLINE void LL_PWR_SetPVDLevel(uint32_t PVDLevel)
{
  MODIFY_REG(PWR->CR, PWR_CR_PLS, PVDLevel);
}














__STATIC_INLINE uint32_t LL_PWR_GetPVDLevel(void)
{
  return (uint32_t)(READ_BIT(PWR->CR, PWR_CR_PLS));
}






__STATIC_INLINE void LL_PWR_EnablePVD(void)
{
  SET_BIT(PWR->CR, PWR_CR_PVDE);
}






__STATIC_INLINE void LL_PWR_DisablePVD(void)
{
  CLEAR_BIT(PWR->CR, PWR_CR_PVDE);
}






__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVD(void)
{
  return (READ_BIT(PWR->CR, PWR_CR_PVDE) == (PWR_CR_PVDE));
}
#endif














__STATIC_INLINE void LL_PWR_EnableWakeUpPin(uint32_t WakeUpPin)
{
  SET_BIT(PWR->CSR, WakeUpPin);
}














__STATIC_INLINE void LL_PWR_DisableWakeUpPin(uint32_t WakeUpPin)
{
  CLEAR_BIT(PWR->CSR, WakeUpPin);
}














__STATIC_INLINE uint32_t LL_PWR_IsEnabledWakeUpPin(uint32_t WakeUpPin)
{
  return (READ_BIT(PWR->CSR, WakeUpPin) == (WakeUpPin));
}















__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU(void)
{
  return (READ_BIT(PWR->CSR, PWR_CSR_WUF) == (PWR_CSR_WUF));
}






__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_SB(void)
{
  return (READ_BIT(PWR->CSR, PWR_CSR_SBF) == (PWR_CSR_SBF));
}

#if defined(PWR_PVD_SUPPORT)





__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVDO(void)
{
  return (READ_BIT(PWR->CSR, PWR_CSR_PVDO) == (PWR_CSR_PVDO));
}
#endif

#if defined(PWR_CSR_VREFINTRDYF)





__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_VREFINTRDY(void)
{
  return (READ_BIT(PWR->CSR, PWR_CSR_VREFINTRDYF) == (PWR_CSR_VREFINTRDYF));
}
#endif





__STATIC_INLINE void LL_PWR_ClearFlag_SB(void)
{
  SET_BIT(PWR->CR, PWR_CR_CSBF);
}






__STATIC_INLINE void LL_PWR_ClearFlag_WU(void)
{
  SET_BIT(PWR->CR, PWR_CR_CWUF);
}





#if defined(USE_FULL_LL_DRIVER)



ErrorStatus LL_PWR_DeInit(void);



#endif









#endif





#ifdef __cplusplus
}
#endif

#endif


