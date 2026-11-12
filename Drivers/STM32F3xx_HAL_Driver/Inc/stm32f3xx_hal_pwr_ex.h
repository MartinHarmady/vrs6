



































#ifndef __STM32F3xx_HAL_PWR_EX_H
#define __STM32F3xx_HAL_PWR_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"














#if defined(STM32F302xE) || defined(STM32F303xE) || \
    defined(STM32F302xC) || defined(STM32F303xC) || \
    defined(STM32F303x8) || defined(STM32F334x8) || \
    defined(STM32F301x8) || defined(STM32F302x8) || \
    defined(STM32F373xC)



typedef struct
{
  uint32_t PVDLevel;


  uint32_t Mode;

}PWR_PVDTypeDef;
#endif














#if defined(STM32F302xE) || defined(STM32F303xE) || \
    defined(STM32F302xC) || defined(STM32F303xC) || \
    defined(STM32F303x8) || defined(STM32F334x8) || \
    defined(STM32F301x8) || defined(STM32F302x8) || \
    defined(STM32F373xC)




#define PWR_PVDLEVEL_0                  PWR_CR_PLS_LEV0
#define PWR_PVDLEVEL_1                  PWR_CR_PLS_LEV1
#define PWR_PVDLEVEL_2                  PWR_CR_PLS_LEV2
#define PWR_PVDLEVEL_3                  PWR_CR_PLS_LEV3
#define PWR_PVDLEVEL_4                  PWR_CR_PLS_LEV4
#define PWR_PVDLEVEL_5                  PWR_CR_PLS_LEV5
#define PWR_PVDLEVEL_6                  PWR_CR_PLS_LEV6
#define PWR_PVDLEVEL_7                  PWR_CR_PLS_LEV7







#define PWR_PVD_MODE_NORMAL                 (0x00000000U)
#define PWR_PVD_MODE_IT_RISING              (0x00010001U)
#define PWR_PVD_MODE_IT_FALLING             (0x00010002U)
#define PWR_PVD_MODE_IT_RISING_FALLING      (0x00010003U)
#define PWR_PVD_MODE_EVENT_RISING           (0x00020001U)
#define PWR_PVD_MODE_EVENT_FALLING          (0x00020002U)
#define PWR_PVD_MODE_EVENT_RISING_FALLING   (0x00020003U)




#define PWR_EXTI_LINE_PVD  EXTI_IMR_MR16

#endif





#if defined(STM32F373xC) || defined(STM32F378xx)



#define PWR_SDADC_ANALOG1              ((uint32_t)PWR_CR_ENSD1)
#define PWR_SDADC_ANALOG2              ((uint32_t)PWR_CR_ENSD2)
#define PWR_SDADC_ANALOG3              ((uint32_t)PWR_CR_ENSD3)



#endif










#if defined(STM32F302xE) || defined(STM32F303xE) || \
    defined(STM32F302xC) || defined(STM32F303xC) || \
    defined(STM32F303x8) || defined(STM32F334x8) || \
    defined(STM32F301x8) || defined(STM32F302x8) || \
    defined(STM32F373xC)





#define __HAL_PWR_PVD_EXTI_ENABLE_IT()      (EXTI->IMR |= (PWR_EXTI_LINE_PVD))





#define __HAL_PWR_PVD_EXTI_DISABLE_IT()     (EXTI->IMR &= ~(PWR_EXTI_LINE_PVD))





#define __HAL_PWR_PVD_EXTI_GENERATE_SWIT()  (EXTI->SWIER |= (PWR_EXTI_LINE_PVD))





#define __HAL_PWR_PVD_EXTI_ENABLE_EVENT()   (EXTI->EMR |= (PWR_EXTI_LINE_PVD))





#define __HAL_PWR_PVD_EXTI_DISABLE_EVENT()  (EXTI->EMR &= ~(PWR_EXTI_LINE_PVD))





#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR, PWR_EXTI_LINE_PVD)





#define __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR, PWR_EXTI_LINE_PVD)





#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_FALLING_EDGE()  __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE();





#define __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE()  EXTI->FTSR |= (PWR_EXTI_LINE_PVD)





#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE()   EXTI->RTSR |= (PWR_EXTI_LINE_PVD)





#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_FALLING_EDGE()   __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE();





#define __HAL_PWR_PVD_EXTI_GET_FLAG()       (EXTI->PR & (PWR_EXTI_LINE_PVD))





#define __HAL_PWR_PVD_EXTI_CLEAR_FLAG()     (EXTI->PR = (PWR_EXTI_LINE_PVD))

#endif














#if defined(STM32F302xE) || defined(STM32F303xE) || \
    defined(STM32F302xC) || defined(STM32F303xC) || \
    defined(STM32F303x8) || defined(STM32F334x8) || \
    defined(STM32F301x8) || defined(STM32F302x8) || \
    defined(STM32F373xC)
#define IS_PWR_PVD_LEVEL(LEVEL) (((LEVEL) == PWR_PVDLEVEL_0) || ((LEVEL) == PWR_PVDLEVEL_1)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_2) || ((LEVEL) == PWR_PVDLEVEL_3)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_4) || ((LEVEL) == PWR_PVDLEVEL_5)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_6) || ((LEVEL) == PWR_PVDLEVEL_7))

#define IS_PWR_PVD_MODE(MODE) (((MODE) == PWR_PVD_MODE_IT_RISING)|| ((MODE) == PWR_PVD_MODE_IT_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_IT_RISING_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING) || \
                              ((MODE) == PWR_PVD_MODE_EVENT_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_NORMAL))
#endif





#if defined(STM32F373xC) || defined(STM32F378xx)
#define IS_PWR_SDADC_ANALOG(SDADC) (((SDADC) == PWR_SDADC_ANALOG1) || \
                                    ((SDADC) == PWR_SDADC_ANALOG2) || \
                                    ((SDADC) == PWR_SDADC_ANALOG3))
#endif
















#if defined(STM32F302xE) || defined(STM32F303xE) || \
    defined(STM32F302xC) || defined(STM32F303xC) || \
    defined(STM32F303x8) || defined(STM32F334x8) || \
    defined(STM32F301x8) || defined(STM32F302x8) || \
    defined(STM32F373xC)
void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD);
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);
void HAL_PWR_PVD_IRQHandler(void);
void HAL_PWR_PVDCallback(void);
#endif





#if defined(STM32F373xC) || defined(STM32F378xx)
void HAL_PWREx_EnableSDADC(uint32_t Analogx);
void HAL_PWREx_DisableSDADC(uint32_t Analogx);
#endif

















#ifdef __cplusplus
}
#endif

#endif


