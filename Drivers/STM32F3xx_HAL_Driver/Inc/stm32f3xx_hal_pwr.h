



































#ifndef __STM32F3xx_HAL_PWR_H
#define __STM32F3xx_HAL_PWR_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"



















#define PWR_WAKEUP_PIN1                 ((uint32_t)PWR_CSR_EWUP1)
#define PWR_WAKEUP_PIN2                 ((uint32_t)PWR_CSR_EWUP2)
#define PWR_WAKEUP_PIN3                 ((uint32_t)PWR_CSR_EWUP3)







#define PWR_MAINREGULATOR_ON         (0x00000000U)
#define PWR_LOWPOWERREGULATOR_ON     PWR_CR_LPDS







#define PWR_SLEEPENTRY_WFI              ((uint8_t)0x01U)
#define PWR_SLEEPENTRY_WFE              ((uint8_t)0x02U)







#define PWR_STOPENTRY_WFI               ((uint8_t)0x01U)
#define PWR_STOPENTRY_WFE               ((uint8_t)0x02U)







#define PWR_FLAG_WU                     PWR_CSR_WUF
#define PWR_FLAG_SB                     PWR_CSR_SBF
#define PWR_FLAG_PVDO                   PWR_CSR_PVDO
#define PWR_FLAG_VREFINTRDY             PWR_CSR_VREFINTRDYF































#define __HAL_PWR_GET_FLAG(__FLAG__) ((PWR->CSR & (__FLAG__)) == (__FLAG__))







#define __HAL_PWR_CLEAR_FLAG(__FLAG__) (PWR->CR |=  (__FLAG__) << 2U)










#define IS_PWR_WAKEUP_PIN(PIN) (((PIN) == PWR_WAKEUP_PIN1) || \
                                ((PIN) == PWR_WAKEUP_PIN2) || \
                                ((PIN) == PWR_WAKEUP_PIN3))

#define IS_PWR_REGULATOR(REGULATOR) (((REGULATOR) == PWR_MAINREGULATOR_ON) || \
                                     ((REGULATOR) == PWR_LOWPOWERREGULATOR_ON))

#define IS_PWR_SLEEP_ENTRY(ENTRY) (((ENTRY) == PWR_SLEEPENTRY_WFI) || ((ENTRY) == PWR_SLEEPENTRY_WFE))

#define IS_PWR_STOP_ENTRY(ENTRY) (((ENTRY) == PWR_STOPENTRY_WFI) || ((ENTRY) == PWR_STOPENTRY_WFE))






#include "stm32f3xx_hal_pwr_ex.h"












void HAL_PWR_DeInit(void);










void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);


void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinx);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx);


void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry);
void HAL_PWR_EnterSTANDBYMode(void);

void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);
















#ifdef __cplusplus
}
#endif


#endif


