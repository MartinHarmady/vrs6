



































#ifndef __STM32F3xx_HAL_RCC_EX_H
#define __STM32F3xx_HAL_RCC_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"













#if defined(RCC_CFGR_PLLNODIV)
#define IS_RCC_MCO1SOURCE(SOURCE)  (((SOURCE) == RCC_MCO1SOURCE_NOCLOCK)        || \
                                   ((SOURCE) == RCC_MCO1SOURCE_LSI)         || \
                                   ((SOURCE) == RCC_MCO1SOURCE_LSE)         || \
                                   ((SOURCE) == RCC_MCO1SOURCE_SYSCLK)      || \
                                   ((SOURCE) == RCC_MCO1SOURCE_HSI)         || \
                                   ((SOURCE) == RCC_MCO1SOURCE_HSE)         || \
                                   ((SOURCE) == RCC_MCO1SOURCE_PLLCLK) || \
                                   ((SOURCE) == RCC_MCO1SOURCE_PLLCLK_DIV2))
#else
#define IS_RCC_MCO1SOURCE(SOURCE)  (((SOURCE) == RCC_MCO1SOURCE_NOCLOCK)    || \
                                   ((SOURCE) == RCC_MCO1SOURCE_LSI)     || \
                                   ((SOURCE) == RCC_MCO1SOURCE_LSE)     || \
                                   ((SOURCE) == RCC_MCO1SOURCE_SYSCLK)  || \
                                   ((SOURCE) == RCC_MCO1SOURCE_HSI)     || \
                                   ((SOURCE) == RCC_MCO1SOURCE_HSE)     || \
                                   ((SOURCE) == RCC_MCO1SOURCE_PLLCLK_DIV2))
#endif

#if defined(STM32F301x8) || defined(STM32F318xx)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | \
                                                       RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                       RCC_PERIPHCLK_ADC1   | RCC_PERIPHCLK_I2S    | \
                                                       RCC_PERIPHCLK_I2C3   | RCC_PERIPHCLK_TIM1   | \
                                                       RCC_PERIPHCLK_TIM15  | RCC_PERIPHCLK_TIM16  | \
                                                       RCC_PERIPHCLK_TIM17  | RCC_PERIPHCLK_RTC))
#endif
#if defined(STM32F302x8)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | \
                                                       RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                       RCC_PERIPHCLK_ADC1   | RCC_PERIPHCLK_I2S    | \
                                                       RCC_PERIPHCLK_I2C3   | RCC_PERIPHCLK_TIM1   | \
                                                       RCC_PERIPHCLK_RTC    | RCC_PERIPHCLK_USB    |  \
                                                       RCC_PERIPHCLK_TIM15  | RCC_PERIPHCLK_TIM16  |  \
                                                       RCC_PERIPHCLK_TIM17))
#endif
#if defined(STM32F302xC)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                                     RCC_PERIPHCLK_UART4  | RCC_PERIPHCLK_UART5  | \
                                                     RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                     RCC_PERIPHCLK_ADC12  | RCC_PERIPHCLK_I2S    | \
                                                     RCC_PERIPHCLK_TIM1   | RCC_PERIPHCLK_RTC    | \
                                                     RCC_PERIPHCLK_USB))
#endif
#if defined(STM32F303xC)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                                     RCC_PERIPHCLK_UART4  | RCC_PERIPHCLK_UART5  | \
                                                     RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                     RCC_PERIPHCLK_ADC12  | RCC_PERIPHCLK_ADC34  | \
                                                     RCC_PERIPHCLK_I2S    | RCC_PERIPHCLK_TIM1   | \
                                                     RCC_PERIPHCLK_TIM8   | RCC_PERIPHCLK_RTC    | \
                                                     RCC_PERIPHCLK_USB))
#endif
#if defined(STM32F302xE)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                                     RCC_PERIPHCLK_UART4  | RCC_PERIPHCLK_UART5  | \
                                                     RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                     RCC_PERIPHCLK_ADC12  | RCC_PERIPHCLK_I2S    | \
                                                     RCC_PERIPHCLK_TIM1   | RCC_PERIPHCLK_RTC    | \
                                                     RCC_PERIPHCLK_USB    | RCC_PERIPHCLK_I2C3   | \
                                                     RCC_PERIPHCLK_TIM2   | RCC_PERIPHCLK_TIM34  | \
                                                     RCC_PERIPHCLK_TIM15  | RCC_PERIPHCLK_TIM16  | \
                                                     RCC_PERIPHCLK_TIM17))
#endif
#if defined(STM32F303xE)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                                     RCC_PERIPHCLK_UART4  | RCC_PERIPHCLK_UART5  | \
                                                     RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                     RCC_PERIPHCLK_ADC12  | RCC_PERIPHCLK_ADC34  | \
                                                     RCC_PERIPHCLK_I2S    | RCC_PERIPHCLK_TIM1   | \
                                                     RCC_PERIPHCLK_TIM8   | RCC_PERIPHCLK_RTC    | \
                                                     RCC_PERIPHCLK_USB    | RCC_PERIPHCLK_I2C3   | \
                                                     RCC_PERIPHCLK_TIM2   | RCC_PERIPHCLK_TIM34  | \
                                                     RCC_PERIPHCLK_TIM15  | RCC_PERIPHCLK_TIM16  | \
                                                     RCC_PERIPHCLK_TIM17  | RCC_PERIPHCLK_TIM20))
#endif
#if defined(STM32F398xx)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                                     RCC_PERIPHCLK_UART4  | RCC_PERIPHCLK_UART5  | \
                                                     RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                     RCC_PERIPHCLK_ADC12  | RCC_PERIPHCLK_ADC34  | \
                                                     RCC_PERIPHCLK_I2S    | RCC_PERIPHCLK_TIM1   | \
                                                     RCC_PERIPHCLK_TIM8   | RCC_PERIPHCLK_RTC    | \
                                                     RCC_PERIPHCLK_I2C3   | RCC_PERIPHCLK_TIM2   | \
                                                     RCC_PERIPHCLK_TIM34  | RCC_PERIPHCLK_TIM15  | \
                                                     RCC_PERIPHCLK_TIM16  | RCC_PERIPHCLK_TIM17  | \
                                                     RCC_PERIPHCLK_TIM20))
#endif
#if defined(STM32F358xx)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                                     RCC_PERIPHCLK_UART4  | RCC_PERIPHCLK_UART5  | \
                                                     RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                     RCC_PERIPHCLK_ADC12  | RCC_PERIPHCLK_ADC34  | \
                                                     RCC_PERIPHCLK_I2S    | RCC_PERIPHCLK_TIM1   | \
                                                     RCC_PERIPHCLK_TIM8   | RCC_PERIPHCLK_RTC))
#endif
#if defined(STM32F303x8)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | \
                                                       RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_ADC12  | \
                                                       RCC_PERIPHCLK_TIM1   | RCC_PERIPHCLK_RTC))
#endif
#if defined(STM32F334x8)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | \
                                                       RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_ADC12  | \
                                                       RCC_PERIPHCLK_TIM1   | RCC_PERIPHCLK_HRTIM1 | \
                                                       RCC_PERIPHCLK_RTC))
#endif
#if defined(STM32F328xx)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | \
                                                       RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_ADC12  | \
                                                       RCC_PERIPHCLK_TIM1   | RCC_PERIPHCLK_RTC))
#endif
#if defined(STM32F373xC)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                                     RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                     RCC_PERIPHCLK_ADC1   | RCC_PERIPHCLK_SDADC  | \
                                                     RCC_PERIPHCLK_CEC    | RCC_PERIPHCLK_RTC    | \
                                                     RCC_PERIPHCLK_USB))
#endif
#if defined(STM32F378xx)
#define IS_RCC_PERIPHCLOCK(SELECTION) ((SELECTION) <= (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                                     RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_I2C2   | \
                                                     RCC_PERIPHCLK_ADC1   | RCC_PERIPHCLK_SDADC  | \
                                                     RCC_PERIPHCLK_CEC    | RCC_PERIPHCLK_RTC))
#endif

#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define IS_RCC_USART1CLKSOURCE(SOURCE)  (((SOURCE) == RCC_USART1CLKSOURCE_PCLK1)  || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_SYSCLK) || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_LSE)    || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_HSI))
#define IS_RCC_I2C2CLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2C2CLKSOURCE_HSI) || \
                                       ((SOURCE) == RCC_I2C2CLKSOURCE_SYSCLK))
#define IS_RCC_I2C3CLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2C3CLKSOURCE_HSI) || \
                                       ((SOURCE) == RCC_I2C3CLKSOURCE_SYSCLK))
#define IS_RCC_ADC1PLLCLK_DIV(ADCCLK) (((ADCCLK) == RCC_ADC1PLLCLK_OFF)   || ((ADCCLK) == RCC_ADC1PLLCLK_DIV1)   || \
                                       ((ADCCLK) == RCC_ADC1PLLCLK_DIV2)  || ((ADCCLK) == RCC_ADC1PLLCLK_DIV4)   || \
                                       ((ADCCLK) == RCC_ADC1PLLCLK_DIV6)  || ((ADCCLK) == RCC_ADC1PLLCLK_DIV8)   || \
                                       ((ADCCLK) == RCC_ADC1PLLCLK_DIV10) || ((ADCCLK) == RCC_ADC1PLLCLK_DIV12)  || \
                                       ((ADCCLK) == RCC_ADC1PLLCLK_DIV16) || ((ADCCLK) == RCC_ADC1PLLCLK_DIV32)  || \
                                       ((ADCCLK) == RCC_ADC1PLLCLK_DIV64) || ((ADCCLK) == RCC_ADC1PLLCLK_DIV128) || \
                                       ((ADCCLK) == RCC_ADC1PLLCLK_DIV256))
#define IS_RCC_I2SCLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2SCLKSOURCE_SYSCLK) || \
                                      ((SOURCE) == RCC_I2SCLKSOURCE_EXT))
#define IS_RCC_TIM1CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM1CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM1CLK_PLLCLK))
#define IS_RCC_TIM15CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM15CLK_HCLK) || \
                                       ((SOURCE) == RCC_TIM15CLK_PLLCLK))
#define IS_RCC_TIM16CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM16CLK_HCLK) || \
                                       ((SOURCE) == RCC_TIM16CLK_PLLCLK))
#define IS_RCC_TIM17CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM17CLK_HCLK) || \
                                       ((SOURCE) == RCC_TIM17CLK_PLLCLK))
#endif
#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define IS_RCC_USART1CLKSOURCE(SOURCE)  (((SOURCE) == RCC_USART1CLKSOURCE_PCLK2)  || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_SYSCLK) || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_LSE)    || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_HSI))
#define IS_RCC_I2C2CLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2C2CLKSOURCE_HSI) || \
                                       ((SOURCE) == RCC_I2C2CLKSOURCE_SYSCLK))
#define IS_RCC_ADC12PLLCLK_DIV(ADCCLK) (((ADCCLK) == RCC_ADC12PLLCLK_OFF)   || ((ADCCLK) == RCC_ADC12PLLCLK_DIV1)   || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV2)  || ((ADCCLK) == RCC_ADC12PLLCLK_DIV4)   || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV6)  || ((ADCCLK) == RCC_ADC12PLLCLK_DIV8)   || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV10) || ((ADCCLK) == RCC_ADC12PLLCLK_DIV12)  || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV16) || ((ADCCLK) == RCC_ADC12PLLCLK_DIV32)  || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV64) || ((ADCCLK) == RCC_ADC12PLLCLK_DIV128) || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV256))
#define IS_RCC_I2SCLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2SCLKSOURCE_SYSCLK) || \
                                      ((SOURCE) == RCC_I2SCLKSOURCE_EXT))
#define IS_RCC_TIM1CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM1CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM1CLK_PLLCLK))
#define IS_RCC_UART4CLKSOURCE(SOURCE)  (((SOURCE) == RCC_UART4CLKSOURCE_PCLK1)  || \
                                        ((SOURCE) == RCC_UART4CLKSOURCE_SYSCLK) || \
                                        ((SOURCE) == RCC_UART4CLKSOURCE_LSE)    || \
                                        ((SOURCE) == RCC_UART4CLKSOURCE_HSI))
#define IS_RCC_UART5CLKSOURCE(SOURCE)  (((SOURCE) == RCC_UART5CLKSOURCE_PCLK1)  || \
                                        ((SOURCE) == RCC_UART5CLKSOURCE_SYSCLK) || \
                                        ((SOURCE) == RCC_UART5CLKSOURCE_LSE)    || \
                                        ((SOURCE) == RCC_UART5CLKSOURCE_HSI))
#endif
#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define IS_RCC_USART1CLKSOURCE(SOURCE)  (((SOURCE) == RCC_USART1CLKSOURCE_PCLK2)  || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_SYSCLK) || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_LSE)    || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_HSI))
#define IS_RCC_I2C2CLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2C2CLKSOURCE_HSI) || \
                                       ((SOURCE) == RCC_I2C2CLKSOURCE_SYSCLK))
#define IS_RCC_I2C3CLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2C3CLKSOURCE_HSI) || \
                                       ((SOURCE) == RCC_I2C3CLKSOURCE_SYSCLK))
#define IS_RCC_ADC12PLLCLK_DIV(ADCCLK) (((ADCCLK) == RCC_ADC12PLLCLK_OFF)   || ((ADCCLK) == RCC_ADC12PLLCLK_DIV1)   || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV2)  || ((ADCCLK) == RCC_ADC12PLLCLK_DIV4)   || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV6)  || ((ADCCLK) == RCC_ADC12PLLCLK_DIV8)   || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV10) || ((ADCCLK) == RCC_ADC12PLLCLK_DIV12)  || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV16) || ((ADCCLK) == RCC_ADC12PLLCLK_DIV32)  || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV64) || ((ADCCLK) == RCC_ADC12PLLCLK_DIV128) || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV256))
#define IS_RCC_I2SCLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2SCLKSOURCE_SYSCLK) || \
                                      ((SOURCE) == RCC_I2SCLKSOURCE_EXT))
#define IS_RCC_TIM1CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM1CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM1CLK_PLLCLK))
#define IS_RCC_TIM2CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM2CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM2CLK_PLLCLK))
#define IS_RCC_TIM3CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM34CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM34CLK_PLLCLK))
#define IS_RCC_TIM15CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM15CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM15CLK_PLLCLK))
#define IS_RCC_TIM16CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM16CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM16CLK_PLLCLK))
#define IS_RCC_TIM17CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM17CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM17CLK_PLLCLK))
#define IS_RCC_UART4CLKSOURCE(SOURCE)  (((SOURCE) == RCC_UART4CLKSOURCE_PCLK1)  || \
                                        ((SOURCE) == RCC_UART4CLKSOURCE_SYSCLK) || \
                                        ((SOURCE) == RCC_UART4CLKSOURCE_LSE)    || \
                                        ((SOURCE) == RCC_UART4CLKSOURCE_HSI))
#define IS_RCC_UART5CLKSOURCE(SOURCE)  (((SOURCE) == RCC_UART5CLKSOURCE_PCLK1)  || \
                                        ((SOURCE) == RCC_UART5CLKSOURCE_SYSCLK) || \
                                        ((SOURCE) == RCC_UART5CLKSOURCE_LSE)    || \
                                        ((SOURCE) == RCC_UART5CLKSOURCE_HSI))
#endif
#if defined(STM32F303xE) ||  defined(STM32F398xx)
#define IS_RCC_TIM20CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM20CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM20CLK_PLLCLK))
#endif
#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)
#define IS_RCC_ADC34PLLCLK_DIV(ADCCLK) (((ADCCLK) == RCC_ADC34PLLCLK_OFF)   || ((ADCCLK) == RCC_ADC34PLLCLK_DIV1)   || \
                                        ((ADCCLK) == RCC_ADC34PLLCLK_DIV2)  || ((ADCCLK) == RCC_ADC34PLLCLK_DIV4)   || \
                                        ((ADCCLK) == RCC_ADC34PLLCLK_DIV6)  || ((ADCCLK) == RCC_ADC34PLLCLK_DIV8)   || \
                                        ((ADCCLK) == RCC_ADC34PLLCLK_DIV10) || ((ADCCLK) == RCC_ADC34PLLCLK_DIV12)  || \
                                        ((ADCCLK) == RCC_ADC34PLLCLK_DIV16) || ((ADCCLK) == RCC_ADC34PLLCLK_DIV32)  || \
                                        ((ADCCLK) == RCC_ADC34PLLCLK_DIV64) || ((ADCCLK) == RCC_ADC34PLLCLK_DIV128) || \
                                        ((ADCCLK) == RCC_ADC34PLLCLK_DIV256))
#define IS_RCC_TIM8CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM8CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM8CLK_PLLCLK))
#endif
#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define IS_RCC_USART1CLKSOURCE(SOURCE)  (((SOURCE) == RCC_USART1CLKSOURCE_PCLK1)  || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_SYSCLK) || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_LSE)    || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_HSI))
#define IS_RCC_ADC12PLLCLK_DIV(ADCCLK) (((ADCCLK) == RCC_ADC12PLLCLK_OFF)   || ((ADCCLK) == RCC_ADC12PLLCLK_DIV1)   || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV2)  || ((ADCCLK) == RCC_ADC12PLLCLK_DIV4)   || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV6)  || ((ADCCLK) == RCC_ADC12PLLCLK_DIV8)   || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV10) || ((ADCCLK) == RCC_ADC12PLLCLK_DIV12)  || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV16) || ((ADCCLK) == RCC_ADC12PLLCLK_DIV32)  || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV64) || ((ADCCLK) == RCC_ADC12PLLCLK_DIV128) || \
                                        ((ADCCLK) == RCC_ADC12PLLCLK_DIV256))
#define IS_RCC_TIM1CLKSOURCE(SOURCE) (((SOURCE) == RCC_TIM1CLK_HCLK) || \
                                      ((SOURCE) == RCC_TIM1CLK_PLLCLK))
#endif
#if defined(STM32F334x8)
#define IS_RCC_HRTIM1CLKSOURCE(SOURCE) (((SOURCE) == RCC_HRTIM1CLK_HCLK) || \
                                        ((SOURCE) == RCC_HRTIM1CLK_PLLCLK))
#endif
#if defined(STM32F373xC) || defined(STM32F378xx)
#define IS_RCC_USART1CLKSOURCE(SOURCE)  (((SOURCE) == RCC_USART1CLKSOURCE_PCLK2)  || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_SYSCLK) || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_LSE)    || \
                                         ((SOURCE) == RCC_USART1CLKSOURCE_HSI))
#define IS_RCC_I2C2CLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2C2CLKSOURCE_HSI) || \
                                       ((SOURCE) == RCC_I2C2CLKSOURCE_SYSCLK))
#define IS_RCC_ADC1PCLK2_DIV(ADCCLK) (((ADCCLK) == RCC_ADC1PCLK2_DIV2) || ((ADCCLK) == RCC_ADC1PCLK2_DIV4) || \
                                      ((ADCCLK) == RCC_ADC1PCLK2_DIV6) || ((ADCCLK) == RCC_ADC1PCLK2_DIV8))
#define IS_RCC_CECCLKSOURCE(SOURCE)  (((SOURCE) == RCC_CECCLKSOURCE_HSI) || \
                                      ((SOURCE) == RCC_CECCLKSOURCE_LSE))
#define IS_RCC_SDADCSYSCLK_DIV(DIV) (((DIV) == RCC_SDADCSYSCLK_DIV1)  || ((DIV) == RCC_SDADCSYSCLK_DIV2)   || \
                                     ((DIV) == RCC_SDADCSYSCLK_DIV4)  || ((DIV) == RCC_SDADCSYSCLK_DIV6)   || \
                                     ((DIV) == RCC_SDADCSYSCLK_DIV8)  || ((DIV) == RCC_SDADCSYSCLK_DIV10)  || \
                                     ((DIV) == RCC_SDADCSYSCLK_DIV12) || ((DIV) == RCC_SDADCSYSCLK_DIV14)  || \
                                     ((DIV) == RCC_SDADCSYSCLK_DIV16) || ((DIV) == RCC_SDADCSYSCLK_DIV20)  || \
                                     ((DIV) == RCC_SDADCSYSCLK_DIV24) || ((DIV) == RCC_SDADCSYSCLK_DIV28)  || \
                                     ((DIV) == RCC_SDADCSYSCLK_DIV32) || ((DIV) == RCC_SDADCSYSCLK_DIV36)  || \
                                     ((DIV) == RCC_SDADCSYSCLK_DIV40) || ((DIV) == RCC_SDADCSYSCLK_DIV44)  || \
                                     ((DIV) == RCC_SDADCSYSCLK_DIV48))
#endif
#if defined(STM32F302xE) || defined(STM32F303xE)\
  || defined(STM32F302xC) || defined(STM32F303xC)\
  || defined(STM32F302x8)                        \
  || defined(STM32F373xC)
#define IS_RCC_USBCLKSOURCE(SOURCE)  (((SOURCE) == RCC_USBCLKSOURCE_PLL) || \
                                      ((SOURCE) == RCC_USBCLKSOURCE_PLL_DIV1_5))
#endif



#if defined(RCC_CFGR_MCOPRE)
#define IS_RCC_MCODIV(DIV) (((DIV) == RCC_MCODIV_1)  || ((DIV) == RCC_MCODIV_2)   || \
                            ((DIV) == RCC_MCODIV_4)  || ((DIV) == RCC_MCODIV_8)   || \
                            ((DIV) == RCC_MCODIV_16) || ((DIV) == RCC_MCODIV_32)  || \
                            ((DIV) == RCC_MCODIV_64) || ((DIV) == RCC_MCODIV_128))
#else
#define IS_RCC_MCODIV(DIV) (((DIV) == RCC_MCODIV_1))
#endif

#define IS_RCC_LSE_DRIVE(__DRIVE__) (((__DRIVE__) == RCC_LSEDRIVE_LOW)        || \
                                     ((__DRIVE__) == RCC_LSEDRIVE_MEDIUMLOW)  || \
                                     ((__DRIVE__) == RCC_LSEDRIVE_MEDIUMHIGH) || \
                                     ((__DRIVE__) == RCC_LSEDRIVE_HIGH))













#if defined(STM32F301x8) || defined(STM32F318xx)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t I2c3ClockSelection;


  uint32_t Adc1ClockSelection;


  uint32_t I2sClockSelection;


  uint32_t Tim1ClockSelection;


  uint32_t Tim15ClockSelection;


  uint32_t Tim16ClockSelection;


  uint32_t Tim17ClockSelection;

}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F302x8)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t I2c3ClockSelection;


  uint32_t Adc1ClockSelection;


  uint32_t I2sClockSelection;


  uint32_t Tim1ClockSelection;


  uint32_t Tim15ClockSelection;


  uint32_t Tim16ClockSelection;


  uint32_t Tim17ClockSelection;


  uint32_t USBClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F302xC)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t Usart2ClockSelection;


  uint32_t Usart3ClockSelection;


  uint32_t Uart4ClockSelection;


  uint32_t Uart5ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t Adc12ClockSelection;


  uint32_t I2sClockSelection;


  uint32_t Tim1ClockSelection;


  uint32_t USBClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F303xC)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t Usart2ClockSelection;


  uint32_t Usart3ClockSelection;


  uint32_t Uart4ClockSelection;


  uint32_t Uart5ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t Adc12ClockSelection;


  uint32_t Adc34ClockSelection;


  uint32_t I2sClockSelection;


  uint32_t Tim1ClockSelection;


  uint32_t Tim8ClockSelection;


  uint32_t USBClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F302xE)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t Usart2ClockSelection;


  uint32_t Usart3ClockSelection;


  uint32_t Uart4ClockSelection;


  uint32_t Uart5ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t I2c3ClockSelection;


  uint32_t Adc12ClockSelection;


  uint32_t I2sClockSelection;


  uint32_t Tim1ClockSelection;


  uint32_t Tim2ClockSelection;


  uint32_t Tim34ClockSelection;


  uint32_t Tim15ClockSelection;


  uint32_t Tim16ClockSelection;


  uint32_t Tim17ClockSelection;


  uint32_t USBClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F303xE)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t Usart2ClockSelection;


  uint32_t Usart3ClockSelection;


  uint32_t Uart4ClockSelection;


  uint32_t Uart5ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t I2c3ClockSelection;


  uint32_t Adc12ClockSelection;


  uint32_t Adc34ClockSelection;


  uint32_t I2sClockSelection;


  uint32_t Tim1ClockSelection;


  uint32_t Tim2ClockSelection;


  uint32_t Tim34ClockSelection;


  uint32_t Tim8ClockSelection;


  uint32_t Tim15ClockSelection;


  uint32_t Tim16ClockSelection;


  uint32_t Tim17ClockSelection;


  uint32_t Tim20ClockSelection;


  uint32_t USBClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F398xx)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t Usart2ClockSelection;


  uint32_t Usart3ClockSelection;


  uint32_t Uart4ClockSelection;


  uint32_t Uart5ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t I2c3ClockSelection;


  uint32_t Adc12ClockSelection;


  uint32_t Adc34ClockSelection;


  uint32_t I2sClockSelection;


  uint32_t Tim1ClockSelection;


  uint32_t Tim2ClockSelection;


  uint32_t Tim34ClockSelection;


  uint32_t Tim8ClockSelection;


  uint32_t Tim15ClockSelection;


  uint32_t Tim16ClockSelection;


  uint32_t Tim17ClockSelection;


  uint32_t Tim20ClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F358xx)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t Usart2ClockSelection;


  uint32_t Usart3ClockSelection;


  uint32_t Uart4ClockSelection;


  uint32_t Uart5ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t Adc12ClockSelection;


  uint32_t Adc34ClockSelection;


  uint32_t I2sClockSelection;


  uint32_t Tim1ClockSelection;


  uint32_t Tim8ClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F303x8)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t Adc12ClockSelection;


  uint32_t Tim1ClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F334x8)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t Adc12ClockSelection;


  uint32_t Tim1ClockSelection;


  uint32_t Hrtim1ClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F328xx)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t Adc12ClockSelection;


  uint32_t Tim1ClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F373xC)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t Usart2ClockSelection;


  uint32_t Usart3ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t Adc1ClockSelection;


  uint32_t SdadcClockSelection;


  uint32_t CecClockSelection;


  uint32_t USBClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif

#if defined(STM32F378xx)
typedef struct
{
  uint32_t PeriphClockSelection;


  uint32_t RTCClockSelection;


  uint32_t Usart1ClockSelection;


  uint32_t Usart2ClockSelection;


  uint32_t Usart3ClockSelection;


  uint32_t I2c1ClockSelection;


  uint32_t I2c2ClockSelection;


  uint32_t Adc1ClockSelection;


  uint32_t SdadcClockSelection;


  uint32_t CecClockSelection;


}RCC_PeriphCLKInitTypeDef;
#endif












#define RCC_MCO1SOURCE_NOCLOCK            RCC_CFGR_MCO_NOCLOCK
#define RCC_MCO1SOURCE_LSI                RCC_CFGR_MCO_LSI
#define RCC_MCO1SOURCE_LSE                RCC_CFGR_MCO_LSE
#define RCC_MCO1SOURCE_SYSCLK             RCC_CFGR_MCO_SYSCLK
#define RCC_MCO1SOURCE_HSI                RCC_CFGR_MCO_HSI
#define RCC_MCO1SOURCE_HSE                RCC_CFGR_MCO_HSE
#if defined(RCC_CFGR_PLLNODIV)
#define RCC_MCO1SOURCE_PLLCLK             (RCC_CFGR_PLLNODIV | RCC_CFGR_MCO_PLL)
#endif
#define RCC_MCO1SOURCE_PLLCLK_DIV2        RCC_CFGR_MCO_PLL








#if defined(STM32F301x8) || defined(STM32F318xx)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC1             (0x00000080U)
#define RCC_PERIPHCLK_I2S              (0x00000200U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_I2C3             (0x00008000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)
#define RCC_PERIPHCLK_TIM15            (0x00040000U)
#define RCC_PERIPHCLK_TIM16            (0x00080000U)
#define RCC_PERIPHCLK_TIM17            (0x00100000U)

#endif

#if defined(STM32F302x8)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC1             (0x00000080U)
#define RCC_PERIPHCLK_I2S              (0x00000200U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_I2C3             (0x00008000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)
#define RCC_PERIPHCLK_USB              (0x00020000U)
#define RCC_PERIPHCLK_TIM15            (0x00040000U)
#define RCC_PERIPHCLK_TIM16            (0x00080000U)
#define RCC_PERIPHCLK_TIM17            (0x00100000U)


#endif

#if defined(STM32F302xC)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_USART2           (0x00000002U)
#define RCC_PERIPHCLK_USART3           (0x00000004U)
#define RCC_PERIPHCLK_UART4            (0x00000008U)
#define RCC_PERIPHCLK_UART5            (0x00000010U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC12            (0x00000080U)
#define RCC_PERIPHCLK_I2S              (0x00000200U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)
#define RCC_PERIPHCLK_USB              (0x00020000U)

#endif

#if defined(STM32F303xC)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_USART2           (0x00000002U)
#define RCC_PERIPHCLK_USART3           (0x00000004U)
#define RCC_PERIPHCLK_UART4            (0x00000008U)
#define RCC_PERIPHCLK_UART5            (0x00000010U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC12            (0x00000080U)
#define RCC_PERIPHCLK_ADC34            (0x00000100U)
#define RCC_PERIPHCLK_I2S              (0x00000200U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_TIM8             (0x00002000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)
#define RCC_PERIPHCLK_USB              (0x00020000U)

#endif

#if defined(STM32F302xE)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_USART2           (0x00000002U)
#define RCC_PERIPHCLK_USART3           (0x00000004U)
#define RCC_PERIPHCLK_UART4            (0x00000008U)
#define RCC_PERIPHCLK_UART5            (0x00000010U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC12            (0x00000080U)
#define RCC_PERIPHCLK_I2S              (0x00000200U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)
#define RCC_PERIPHCLK_USB              (0x00020000U)
#define RCC_PERIPHCLK_I2C3             (0x00040000U)
#define RCC_PERIPHCLK_TIM2             (0x00100000U)
#define RCC_PERIPHCLK_TIM34            (0x00200000U)
#define RCC_PERIPHCLK_TIM15            (0x00400000U)
#define RCC_PERIPHCLK_TIM16            (0x00800000U)
#define RCC_PERIPHCLK_TIM17            (0x01000000U)

#endif

#if defined(STM32F303xE)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_USART2           (0x00000002U)
#define RCC_PERIPHCLK_USART3           (0x00000004U)
#define RCC_PERIPHCLK_UART4            (0x00000008U)
#define RCC_PERIPHCLK_UART5            (0x00000010U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC12            (0x00000080U)
#define RCC_PERIPHCLK_ADC34            (0x00000100U)
#define RCC_PERIPHCLK_I2S              (0x00000200U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_TIM8             (0x00002000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)
#define RCC_PERIPHCLK_USB              (0x00020000U)
#define RCC_PERIPHCLK_I2C3             (0x00040000U)
#define RCC_PERIPHCLK_TIM2             (0x00100000U)
#define RCC_PERIPHCLK_TIM34            (0x00200000U)
#define RCC_PERIPHCLK_TIM15            (0x00400000U)
#define RCC_PERIPHCLK_TIM16            (0x00800000U)
#define RCC_PERIPHCLK_TIM17            (0x01000000U)
#define RCC_PERIPHCLK_TIM20            (0x02000000U)

#endif

#if defined(STM32F398xx)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_USART2           (0x00000002U)
#define RCC_PERIPHCLK_USART3           (0x00000004U)
#define RCC_PERIPHCLK_UART4            (0x00000008U)
#define RCC_PERIPHCLK_UART5            (0x00000010U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC12            (0x00000080U)
#define RCC_PERIPHCLK_ADC34            (0x00000100U)
#define RCC_PERIPHCLK_I2S              (0x00000200U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_TIM8             (0x00002000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)
#define RCC_PERIPHCLK_I2C3             (0x00040000U)
#define RCC_PERIPHCLK_TIM2             (0x00100000U)
#define RCC_PERIPHCLK_TIM34            (0x00200000U)
#define RCC_PERIPHCLK_TIM15            (0x00400000U)
#define RCC_PERIPHCLK_TIM16            (0x00800000U)
#define RCC_PERIPHCLK_TIM17            (0x01000000U)
#define RCC_PERIPHCLK_TIM20            (0x02000000U)


#endif

#if defined(STM32F358xx)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_USART2           (0x00000002U)
#define RCC_PERIPHCLK_USART3           (0x00000004U)
#define RCC_PERIPHCLK_UART4            (0x00000008U)
#define RCC_PERIPHCLK_UART5            (0x00000010U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC12            (0x00000080U)
#define RCC_PERIPHCLK_ADC34            (0x00000100U)
#define RCC_PERIPHCLK_I2S              (0x00000200U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_TIM8             (0x00002000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)

#endif

#if defined(STM32F303x8)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_ADC12            (0x00000080U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)

#endif

#if defined(STM32F334x8)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_ADC12            (0x00000080U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_HRTIM1           (0x00004000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)


#endif

#if defined(STM32F328xx)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_ADC12            (0x00000080U)
#define RCC_PERIPHCLK_TIM1             (0x00001000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)

#endif

#if defined(STM32F373xC)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_USART2           (0x00000002U)
#define RCC_PERIPHCLK_USART3           (0x00000004U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC1             (0x00000080U)
#define RCC_PERIPHCLK_CEC              (0x00000400U)
#define RCC_PERIPHCLK_SDADC            (0x00000800U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)
#define RCC_PERIPHCLK_USB              (0x00020000U)

#endif

#if defined(STM32F378xx)
#define RCC_PERIPHCLK_USART1           (0x00000001U)
#define RCC_PERIPHCLK_USART2           (0x00000002U)
#define RCC_PERIPHCLK_USART3           (0x00000004U)
#define RCC_PERIPHCLK_I2C1             (0x00000020U)
#define RCC_PERIPHCLK_I2C2             (0x00000040U)
#define RCC_PERIPHCLK_ADC1             (0x00000080U)
#define RCC_PERIPHCLK_CEC              (0x00000400U)
#define RCC_PERIPHCLK_SDADC            (0x00000800U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)

#endif




#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)




#define RCC_USART1CLKSOURCE_PCLK1        RCC_CFGR3_USART1SW_PCLK1
#define RCC_USART1CLKSOURCE_SYSCLK       RCC_CFGR3_USART1SW_SYSCLK
#define RCC_USART1CLKSOURCE_LSE          RCC_CFGR3_USART1SW_LSE
#define RCC_USART1CLKSOURCE_HSI          RCC_CFGR3_USART1SW_HSI








#define RCC_I2C2CLKSOURCE_HSI            RCC_CFGR3_I2C2SW_HSI
#define RCC_I2C2CLKSOURCE_SYSCLK         RCC_CFGR3_I2C2SW_SYSCLK








#define RCC_I2C3CLKSOURCE_HSI            RCC_CFGR3_I2C3SW_HSI
#define RCC_I2C3CLKSOURCE_SYSCLK         RCC_CFGR3_I2C3SW_SYSCLK








#define RCC_ADC1PLLCLK_OFF               RCC_CFGR2_ADC1PRES_NO
#define RCC_ADC1PLLCLK_DIV1              RCC_CFGR2_ADC1PRES_DIV1
#define RCC_ADC1PLLCLK_DIV2              RCC_CFGR2_ADC1PRES_DIV2
#define RCC_ADC1PLLCLK_DIV4              RCC_CFGR2_ADC1PRES_DIV4
#define RCC_ADC1PLLCLK_DIV6              RCC_CFGR2_ADC1PRES_DIV6
#define RCC_ADC1PLLCLK_DIV8              RCC_CFGR2_ADC1PRES_DIV8
#define RCC_ADC1PLLCLK_DIV10             RCC_CFGR2_ADC1PRES_DIV10
#define RCC_ADC1PLLCLK_DIV12             RCC_CFGR2_ADC1PRES_DIV12
#define RCC_ADC1PLLCLK_DIV16             RCC_CFGR2_ADC1PRES_DIV16
#define RCC_ADC1PLLCLK_DIV32             RCC_CFGR2_ADC1PRES_DIV32
#define RCC_ADC1PLLCLK_DIV64             RCC_CFGR2_ADC1PRES_DIV64
#define RCC_ADC1PLLCLK_DIV128            RCC_CFGR2_ADC1PRES_DIV128
#define RCC_ADC1PLLCLK_DIV256            RCC_CFGR2_ADC1PRES_DIV256








#define RCC_I2SCLKSOURCE_SYSCLK          RCC_CFGR_I2SSRC_SYSCLK
#define RCC_I2SCLKSOURCE_EXT             RCC_CFGR_I2SSRC_EXT








#define RCC_TIM1CLK_HCLK                  RCC_CFGR3_TIM1SW_HCLK
#define RCC_TIM1CLK_PLLCLK                RCC_CFGR3_TIM1SW_PLL








#define RCC_TIM15CLK_HCLK                 RCC_CFGR3_TIM15SW_HCLK
#define RCC_TIM15CLK_PLLCLK               RCC_CFGR3_TIM15SW_PLL








#define RCC_TIM16CLK_HCLK                 RCC_CFGR3_TIM16SW_HCLK
#define RCC_TIM16CLK_PLLCLK               RCC_CFGR3_TIM16SW_PLL








#define RCC_TIM17CLK_HCLK                 RCC_CFGR3_TIM17SW_HCLK
#define RCC_TIM17CLK_PLLCLK               RCC_CFGR3_TIM17SW_PLL





#endif

#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)




#define RCC_USART1CLKSOURCE_PCLK2        RCC_CFGR3_USART1SW_PCLK2
#define RCC_USART1CLKSOURCE_SYSCLK       RCC_CFGR3_USART1SW_SYSCLK
#define RCC_USART1CLKSOURCE_LSE          RCC_CFGR3_USART1SW_LSE
#define RCC_USART1CLKSOURCE_HSI          RCC_CFGR3_USART1SW_HSI








#define RCC_I2C2CLKSOURCE_HSI            RCC_CFGR3_I2C2SW_HSI
#define RCC_I2C2CLKSOURCE_SYSCLK         RCC_CFGR3_I2C2SW_SYSCLK










#define RCC_ADC12PLLCLK_OFF              RCC_CFGR2_ADCPRE12_NO
#define RCC_ADC12PLLCLK_DIV1             RCC_CFGR2_ADCPRE12_DIV1
#define RCC_ADC12PLLCLK_DIV2             RCC_CFGR2_ADCPRE12_DIV2
#define RCC_ADC12PLLCLK_DIV4             RCC_CFGR2_ADCPRE12_DIV4
#define RCC_ADC12PLLCLK_DIV6             RCC_CFGR2_ADCPRE12_DIV6
#define RCC_ADC12PLLCLK_DIV8             RCC_CFGR2_ADCPRE12_DIV8
#define RCC_ADC12PLLCLK_DIV10            RCC_CFGR2_ADCPRE12_DIV10
#define RCC_ADC12PLLCLK_DIV12            RCC_CFGR2_ADCPRE12_DIV12
#define RCC_ADC12PLLCLK_DIV16            RCC_CFGR2_ADCPRE12_DIV16
#define RCC_ADC12PLLCLK_DIV32            RCC_CFGR2_ADCPRE12_DIV32
#define RCC_ADC12PLLCLK_DIV64            RCC_CFGR2_ADCPRE12_DIV64
#define RCC_ADC12PLLCLK_DIV128           RCC_CFGR2_ADCPRE12_DIV128
#define RCC_ADC12PLLCLK_DIV256           RCC_CFGR2_ADCPRE12_DIV256








#define RCC_I2SCLKSOURCE_SYSCLK          RCC_CFGR_I2SSRC_SYSCLK
#define RCC_I2SCLKSOURCE_EXT             RCC_CFGR_I2SSRC_EXT







#define RCC_TIM1CLK_HCLK                  RCC_CFGR3_TIM1SW_HCLK
#define RCC_TIM1CLK_PLLCLK                RCC_CFGR3_TIM1SW_PLL








#define RCC_UART4CLKSOURCE_PCLK1         RCC_CFGR3_UART4SW_PCLK
#define RCC_UART4CLKSOURCE_SYSCLK        RCC_CFGR3_UART4SW_SYSCLK
#define RCC_UART4CLKSOURCE_LSE           RCC_CFGR3_UART4SW_LSE
#define RCC_UART4CLKSOURCE_HSI           RCC_CFGR3_UART4SW_HSI








#define RCC_UART5CLKSOURCE_PCLK1         RCC_CFGR3_UART5SW_PCLK
#define RCC_UART5CLKSOURCE_SYSCLK        RCC_CFGR3_UART5SW_SYSCLK
#define RCC_UART5CLKSOURCE_LSE           RCC_CFGR3_UART5SW_LSE
#define RCC_UART5CLKSOURCE_HSI           RCC_CFGR3_UART5SW_HSI





#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)




#define RCC_USART1CLKSOURCE_PCLK2        RCC_CFGR3_USART1SW_PCLK2
#define RCC_USART1CLKSOURCE_SYSCLK       RCC_CFGR3_USART1SW_SYSCLK
#define RCC_USART1CLKSOURCE_LSE          RCC_CFGR3_USART1SW_LSE
#define RCC_USART1CLKSOURCE_HSI          RCC_CFGR3_USART1SW_HSI








#define RCC_I2C2CLKSOURCE_HSI            RCC_CFGR3_I2C2SW_HSI
#define RCC_I2C2CLKSOURCE_SYSCLK         RCC_CFGR3_I2C2SW_SYSCLK








#define RCC_I2C3CLKSOURCE_HSI            RCC_CFGR3_I2C3SW_HSI
#define RCC_I2C3CLKSOURCE_SYSCLK         RCC_CFGR3_I2C3SW_SYSCLK










#define RCC_ADC12PLLCLK_OFF              RCC_CFGR2_ADCPRE12_NO
#define RCC_ADC12PLLCLK_DIV1             RCC_CFGR2_ADCPRE12_DIV1
#define RCC_ADC12PLLCLK_DIV2             RCC_CFGR2_ADCPRE12_DIV2
#define RCC_ADC12PLLCLK_DIV4             RCC_CFGR2_ADCPRE12_DIV4
#define RCC_ADC12PLLCLK_DIV6             RCC_CFGR2_ADCPRE12_DIV6
#define RCC_ADC12PLLCLK_DIV8             RCC_CFGR2_ADCPRE12_DIV8
#define RCC_ADC12PLLCLK_DIV10            RCC_CFGR2_ADCPRE12_DIV10
#define RCC_ADC12PLLCLK_DIV12            RCC_CFGR2_ADCPRE12_DIV12
#define RCC_ADC12PLLCLK_DIV16            RCC_CFGR2_ADCPRE12_DIV16
#define RCC_ADC12PLLCLK_DIV32            RCC_CFGR2_ADCPRE12_DIV32
#define RCC_ADC12PLLCLK_DIV64            RCC_CFGR2_ADCPRE12_DIV64
#define RCC_ADC12PLLCLK_DIV128           RCC_CFGR2_ADCPRE12_DIV128
#define RCC_ADC12PLLCLK_DIV256           RCC_CFGR2_ADCPRE12_DIV256








#define RCC_I2SCLKSOURCE_SYSCLK          RCC_CFGR_I2SSRC_SYSCLK
#define RCC_I2SCLKSOURCE_EXT             RCC_CFGR_I2SSRC_EXT








#define RCC_TIM1CLK_HCLK                  RCC_CFGR3_TIM1SW_HCLK
#define RCC_TIM1CLK_PLLCLK                RCC_CFGR3_TIM1SW_PLL








#define RCC_TIM2CLK_HCLK                  RCC_CFGR3_TIM2SW_HCLK
#define RCC_TIM2CLK_PLLCLK                RCC_CFGR3_TIM2SW_PLL








#define RCC_TIM34CLK_HCLK                  RCC_CFGR3_TIM34SW_HCLK
#define RCC_TIM34CLK_PLLCLK                RCC_CFGR3_TIM34SW_PLL








#define RCC_TIM15CLK_HCLK                  RCC_CFGR3_TIM15SW_HCLK
#define RCC_TIM15CLK_PLLCLK                RCC_CFGR3_TIM15SW_PLL








#define RCC_TIM16CLK_HCLK                  RCC_CFGR3_TIM16SW_HCLK
#define RCC_TIM16CLK_PLLCLK                RCC_CFGR3_TIM16SW_PLL








#define RCC_TIM17CLK_HCLK                  RCC_CFGR3_TIM17SW_HCLK
#define RCC_TIM17CLK_PLLCLK                RCC_CFGR3_TIM17SW_PLL








#define RCC_UART4CLKSOURCE_PCLK1         RCC_CFGR3_UART4SW_PCLK
#define RCC_UART4CLKSOURCE_SYSCLK        RCC_CFGR3_UART4SW_SYSCLK
#define RCC_UART4CLKSOURCE_LSE           RCC_CFGR3_UART4SW_LSE
#define RCC_UART4CLKSOURCE_HSI           RCC_CFGR3_UART4SW_HSI








#define RCC_UART5CLKSOURCE_PCLK1         RCC_CFGR3_UART5SW_PCLK
#define RCC_UART5CLKSOURCE_SYSCLK        RCC_CFGR3_UART5SW_SYSCLK
#define RCC_UART5CLKSOURCE_LSE           RCC_CFGR3_UART5SW_LSE
#define RCC_UART5CLKSOURCE_HSI           RCC_CFGR3_UART5SW_HSI





#endif

#if defined(STM32F303xE) ||  defined(STM32F398xx)



#define RCC_TIM20CLK_HCLK                  RCC_CFGR3_TIM20SW_HCLK
#define RCC_TIM20CLK_PLLCLK                RCC_CFGR3_TIM20SW_PLL




#endif

#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)






#define RCC_ADC34PLLCLK_OFF              RCC_CFGR2_ADCPRE34_NO
#define RCC_ADC34PLLCLK_DIV1             RCC_CFGR2_ADCPRE34_DIV1
#define RCC_ADC34PLLCLK_DIV2             RCC_CFGR2_ADCPRE34_DIV2
#define RCC_ADC34PLLCLK_DIV4             RCC_CFGR2_ADCPRE34_DIV4
#define RCC_ADC34PLLCLK_DIV6             RCC_CFGR2_ADCPRE34_DIV6
#define RCC_ADC34PLLCLK_DIV8             RCC_CFGR2_ADCPRE34_DIV8
#define RCC_ADC34PLLCLK_DIV10            RCC_CFGR2_ADCPRE34_DIV10
#define RCC_ADC34PLLCLK_DIV12            RCC_CFGR2_ADCPRE34_DIV12
#define RCC_ADC34PLLCLK_DIV16            RCC_CFGR2_ADCPRE34_DIV16
#define RCC_ADC34PLLCLK_DIV32            RCC_CFGR2_ADCPRE34_DIV32
#define RCC_ADC34PLLCLK_DIV64            RCC_CFGR2_ADCPRE34_DIV64
#define RCC_ADC34PLLCLK_DIV128           RCC_CFGR2_ADCPRE34_DIV128
#define RCC_ADC34PLLCLK_DIV256           RCC_CFGR2_ADCPRE34_DIV256








#define RCC_TIM8CLK_HCLK                  RCC_CFGR3_TIM8SW_HCLK
#define RCC_TIM8CLK_PLLCLK                RCC_CFGR3_TIM8SW_PLL





#endif

#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)




#define RCC_USART1CLKSOURCE_PCLK1        RCC_CFGR3_USART1SW_PCLK1
#define RCC_USART1CLKSOURCE_SYSCLK       RCC_CFGR3_USART1SW_SYSCLK
#define RCC_USART1CLKSOURCE_LSE          RCC_CFGR3_USART1SW_LSE
#define RCC_USART1CLKSOURCE_HSI          RCC_CFGR3_USART1SW_HSI









#define RCC_ADC12PLLCLK_OFF              RCC_CFGR2_ADCPRE12_NO
#define RCC_ADC12PLLCLK_DIV1             RCC_CFGR2_ADCPRE12_DIV1
#define RCC_ADC12PLLCLK_DIV2             RCC_CFGR2_ADCPRE12_DIV2
#define RCC_ADC12PLLCLK_DIV4             RCC_CFGR2_ADCPRE12_DIV4
#define RCC_ADC12PLLCLK_DIV6             RCC_CFGR2_ADCPRE12_DIV6
#define RCC_ADC12PLLCLK_DIV8             RCC_CFGR2_ADCPRE12_DIV8
#define RCC_ADC12PLLCLK_DIV10            RCC_CFGR2_ADCPRE12_DIV10
#define RCC_ADC12PLLCLK_DIV12            RCC_CFGR2_ADCPRE12_DIV12
#define RCC_ADC12PLLCLK_DIV16            RCC_CFGR2_ADCPRE12_DIV16
#define RCC_ADC12PLLCLK_DIV32            RCC_CFGR2_ADCPRE12_DIV32
#define RCC_ADC12PLLCLK_DIV64            RCC_CFGR2_ADCPRE12_DIV64
#define RCC_ADC12PLLCLK_DIV128           RCC_CFGR2_ADCPRE12_DIV128
#define RCC_ADC12PLLCLK_DIV256           RCC_CFGR2_ADCPRE12_DIV256








#define RCC_TIM1CLK_HCLK                  RCC_CFGR3_TIM1SW_HCLK
#define RCC_TIM1CLK_PLLCLK                RCC_CFGR3_TIM1SW_PLL





#endif

#if defined(STM32F334x8)




#define RCC_HRTIM1CLK_HCLK                RCC_CFGR3_HRTIM1SW_HCLK
#define RCC_HRTIM1CLK_PLLCLK              RCC_CFGR3_HRTIM1SW_PLL





#endif

#if defined(STM32F373xC) || defined(STM32F378xx)




#define RCC_USART1CLKSOURCE_PCLK2        RCC_CFGR3_USART1SW_PCLK2
#define RCC_USART1CLKSOURCE_SYSCLK       RCC_CFGR3_USART1SW_SYSCLK
#define RCC_USART1CLKSOURCE_LSE          RCC_CFGR3_USART1SW_LSE
#define RCC_USART1CLKSOURCE_HSI          RCC_CFGR3_USART1SW_HSI








#define RCC_I2C2CLKSOURCE_HSI            RCC_CFGR3_I2C2SW_HSI
#define RCC_I2C2CLKSOURCE_SYSCLK         RCC_CFGR3_I2C2SW_SYSCLK










#define RCC_ADC1PCLK2_DIV2               RCC_CFGR_ADCPRE_DIV2
#define RCC_ADC1PCLK2_DIV4               RCC_CFGR_ADCPRE_DIV4
#define RCC_ADC1PCLK2_DIV6               RCC_CFGR_ADCPRE_DIV6
#define RCC_ADC1PCLK2_DIV8               RCC_CFGR_ADCPRE_DIV8








#define RCC_CECCLKSOURCE_HSI             RCC_CFGR3_CECSW_HSI_DIV244
#define RCC_CECCLKSOURCE_LSE             RCC_CFGR3_CECSW_LSE








#define RCC_SDADCSYSCLK_DIV1             RCC_CFGR_SDPRE_DIV1
#define RCC_SDADCSYSCLK_DIV2             RCC_CFGR_SDPRE_DIV2
#define RCC_SDADCSYSCLK_DIV4             RCC_CFGR_SDPRE_DIV4
#define RCC_SDADCSYSCLK_DIV6             RCC_CFGR_SDPRE_DIV6
#define RCC_SDADCSYSCLK_DIV8             RCC_CFGR_SDPRE_DIV8
#define RCC_SDADCSYSCLK_DIV10            RCC_CFGR_SDPRE_DIV10
#define RCC_SDADCSYSCLK_DIV12            RCC_CFGR_SDPRE_DIV12
#define RCC_SDADCSYSCLK_DIV14            RCC_CFGR_SDPRE_DIV14
#define RCC_SDADCSYSCLK_DIV16            RCC_CFGR_SDPRE_DIV16
#define RCC_SDADCSYSCLK_DIV20            RCC_CFGR_SDPRE_DIV20
#define RCC_SDADCSYSCLK_DIV24            RCC_CFGR_SDPRE_DIV24
#define RCC_SDADCSYSCLK_DIV28            RCC_CFGR_SDPRE_DIV28
#define RCC_SDADCSYSCLK_DIV32            RCC_CFGR_SDPRE_DIV32
#define RCC_SDADCSYSCLK_DIV36            RCC_CFGR_SDPRE_DIV36
#define RCC_SDADCSYSCLK_DIV40            RCC_CFGR_SDPRE_DIV40
#define RCC_SDADCSYSCLK_DIV44            RCC_CFGR_SDPRE_DIV44
#define RCC_SDADCSYSCLK_DIV48            RCC_CFGR_SDPRE_DIV48





#endif

#if defined(STM32F302xE) || defined(STM32F303xE)\
  || defined(STM32F302xC) || defined(STM32F303xC)\
  || defined(STM32F302x8)                        \
  || defined(STM32F373xC)




#define RCC_USBCLKSOURCE_PLL               RCC_CFGR_USBPRE_DIV1
#define RCC_USBCLKSOURCE_PLL_DIV1_5             RCC_CFGR_USBPRE_DIV1_5





#endif








#if defined(RCC_CFGR_MCOPRE)

#define RCC_MCODIV_1                     (0x00000000U)
#define RCC_MCODIV_2                     (0x10000000U)
#define RCC_MCODIV_4                     (0x20000000U)
#define RCC_MCODIV_8                     (0x30000000U)
#define RCC_MCODIV_16                    (0x40000000U)
#define RCC_MCODIV_32                    (0x50000000U)
#define RCC_MCODIV_64                    (0x60000000U)
#define RCC_MCODIV_128                   (0x70000000U)

#else

#define RCC_MCODIV_1                    (0x00000000U)

#endif









#define RCC_LSEDRIVE_LOW                 (0x00000000U)
#define RCC_LSEDRIVE_MEDIUMLOW           RCC_BDCR_LSEDRV_1
#define RCC_LSEDRIVE_MEDIUMHIGH          RCC_BDCR_LSEDRV_0
#define RCC_LSEDRIVE_HIGH                RCC_BDCR_LSEDRV

















#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)













#define __HAL_RCC_PLL_CONFIG(__RCC_PLLSource__ , __PREDIV__, __PLLMUL__) \
                  do { \
                    MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV, (__PREDIV__)); \
                    MODIFY_REG(RCC->CFGR, RCC_CFGR_PLLMUL | RCC_CFGR_PLLSRC, (uint32_t)((__PLLMUL__)|(__RCC_PLLSource__))); \
                  } while(0U)
#endif

#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
  || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
  || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)\
  || defined(STM32F373xC) || defined(STM32F378xx)











#define __HAL_RCC_PLL_CONFIG(__RCC_PLLSource__ , __PLLMUL__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_PLLMUL | RCC_CFGR_PLLSRC, (uint32_t)((__PLLMUL__)|(__RCC_PLLSource__)))
#endif







#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
  || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
  || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)\
  || defined(STM32F373xC) || defined(STM32F378xx)












#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV, (uint32_t)(__HSE_PREDIV_VALUE__))




#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV)




#endif











#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define __HAL_RCC_ADC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ADC1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ADC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC1_CLK_DISABLE()         (RCC->AHBENR &= ~(RCC_AHBENR_ADC1EN))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_DMA2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_GPIOE_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOEEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOEEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_ADC12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ADC12EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ADC12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC1_CLK_ENABLE()          __HAL_RCC_ADC12_CLK_ENABLE()
#define __HAL_RCC_ADC2_CLK_ENABLE()          __HAL_RCC_ADC12_CLK_ENABLE()

#define __HAL_RCC_DMA2_CLK_DISABLE()         (RCC->AHBENR &= ~(RCC_AHBENR_DMA2EN))
#define __HAL_RCC_GPIOE_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_GPIOEEN))
#define __HAL_RCC_ADC12_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_ADC12EN))

#define __HAL_RCC_ADC1_CLK_DISABLE()          __HAL_RCC_ADC12_CLK_DISABLE()
#define __HAL_RCC_ADC2_CLK_DISABLE()          __HAL_RCC_ADC12_CLK_DISABLE()
#endif


#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_ADC34_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ADC34EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ADC34EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_ADC34_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_ADC34EN))
#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_RCC_ADC12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ADC12EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ADC12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC1_CLK_ENABLE()          __HAL_RCC_ADC12_CLK_ENABLE()
#define __HAL_RCC_ADC2_CLK_ENABLE()          __HAL_RCC_ADC12_CLK_ENABLE()

#define __HAL_RCC_ADC12_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_ADC12EN))

#define __HAL_RCC_ADC1_CLK_DISABLE()          __HAL_RCC_ADC12_CLK_DISABLE()
#define __HAL_RCC_ADC2_CLK_DISABLE()          __HAL_RCC_ADC12_CLK_DISABLE()
#endif

#if defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_DMA2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_GPIOE_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOEEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOEEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_DMA2_CLK_DISABLE()         (RCC->AHBENR &= ~(RCC_AHBENR_DMA2EN))
#define __HAL_RCC_GPIOE_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_GPIOEEN))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_FMC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_FMCEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_FMCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOGEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_GPIOH_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOHEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOHEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_FMC_CLK_DISABLE()           (RCC->AHBENR &= ~(RCC_AHBENR_FMCEN))
#define __HAL_RCC_GPIOG_CLK_DISABLE()         (RCC->AHBENR &= ~(RCC_AHBENR_GPIOGEN))
#define __HAL_RCC_GPIOH_CLK_DISABLE()         (RCC->AHBENR &= ~(RCC_AHBENR_GPIOHEN))
#endif











#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define __HAL_RCC_SPI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_I2C2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_I2C3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
#define __HAL_RCC_SPI3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
#define __HAL_RCC_I2C2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2EN))
#define __HAL_RCC_I2C3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C3EN))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_TIM3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SPI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_I2C2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3EN))
#define __HAL_RCC_TIM4_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM4EN))
#define __HAL_RCC_SPI2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
#define __HAL_RCC_SPI3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
#define __HAL_RCC_UART4_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
#define __HAL_RCC_UART5_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
#define __HAL_RCC_I2C2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2EN))
#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_RCC_TIM3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_DAC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DAC2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DAC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3EN))
#define __HAL_RCC_DAC2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_DAC2EN))
#endif

#if defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_TIM3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM18_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM18EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM18EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SPI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_I2C2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_DAC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DAC2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DAC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_CEC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3EN))
#define __HAL_RCC_TIM4_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM4EN))
#define __HAL_RCC_TIM5_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
#define __HAL_RCC_TIM12_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
#define __HAL_RCC_TIM13_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
#define __HAL_RCC_TIM14_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
#define __HAL_RCC_TIM18_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM18EN))
#define __HAL_RCC_SPI2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
#define __HAL_RCC_SPI3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
#define __HAL_RCC_I2C2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2EN))
#define __HAL_RCC_DAC2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_DAC2EN))
#define __HAL_RCC_CEC_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_CECEN))
#endif

#if defined(STM32F303xE) || defined(STM32F398xx)                        \
  || defined(STM32F303xC) || defined(STM32F358xx)                        \
  || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
  || defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM7_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
#endif




#if defined(STM32F302xE) || defined(STM32F303xE)\
  || defined(STM32F302xC) || defined(STM32F303xC)\
  || defined(STM32F302x8)                        \
  || defined(STM32F373xC)
#define __HAL_RCC_USB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_USB_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_USBEN))
#endif




#if !defined(STM32F301x8)
#define __HAL_RCC_CAN1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CANEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CANEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_CAN1_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_CANEN))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_I2C3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_I2C3_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C3EN))
#endif











#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_SPI1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN))
#endif


#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_TIM8_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM8_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM8EN))
#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_RCC_SPI1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN))
#endif

#if defined(STM32F334x8)
#define __HAL_RCC_HRTIM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_HRTIM1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_HRTIM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_HRTIM1_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_HRTIM1EN))
#endif

#if defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_ADC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SPI1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM19_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM19EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM19EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SDADC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SDADC1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SDADC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SDADC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SDADC2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SDADC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SDADC3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SDADC3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SDADC3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC1_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC1EN))
#define __HAL_RCC_SPI1_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN))
#define __HAL_RCC_TIM19_CLK_DISABLE()    (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM19EN))
#define __HAL_RCC_SDADC1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SDADC1EN))
#define __HAL_RCC_SDADC2_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SDADC2EN))
#define __HAL_RCC_SDADC3_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SDADC3EN))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
  || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
  || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define __HAL_RCC_TIM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM1EN))
#endif




#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_SPI4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI4EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI4_CLK_DISABLE()         (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI4EN))
#endif

#if defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_TIM20_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM20EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM20EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM20_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM20EN))
#endif












#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define __HAL_RCC_ADC1_IS_CLK_ENABLED()          ((RCC->AHBENR & (RCC_AHBENR_ADC1EN)) != RESET)

#define __HAL_RCC_ADC1_IS_CLK_DISABLED()         ((RCC->AHBENR & (RCC_AHBENR_ADC1EN)) == RESET)
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_DMA2_IS_CLK_ENABLED()          ((RCC->AHBENR & (RCC_AHBENR_DMA2EN))  != RESET)
#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOEEN)) != RESET)
#define __HAL_RCC_ADC12_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_ADC12EN)) != RESET)

#define __HAL_RCC_DMA2_IS_CLK_DISABLED()         ((RCC->AHBENR & (RCC_AHBENR_DMA2EN))  == RESET)
#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_GPIOEEN)) == RESET)
#define __HAL_RCC_ADC12_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_ADC12EN)) == RESET)
#endif


#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_ADC34_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_ADC34EN)) != RESET)

#define __HAL_RCC_ADC34_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_ADC34EN)) == RESET)
#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_RCC_ADC12_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_ADC12EN)) != RESET)

#define __HAL_RCC_ADC12_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_ADC12EN)) == RESET)
#endif

#if defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_DMA2_IS_CLK_ENABLED()          ((RCC->AHBENR & (RCC_AHBENR_DMA2EN))  != RESET)
#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOEEN)) != RESET)

#define __HAL_RCC_DMA2_IS_CLK_DISABLED()         ((RCC->AHBENR & (RCC_AHBENR_DMA2EN))  == RESET)
#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_GPIOEEN)) == RESET)
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_FMC_IS_CLK_ENABLED()           ((RCC->AHBENR & (RCC_AHBENR_FMCEN))   != RESET)
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOGEN)) != RESET)
#define __HAL_RCC_GPIOH_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOHEN)) != RESET)

#define __HAL_RCC_FMC_IS_CLK_DISABLED()           ((RCC->AHBENR & (RCC_AHBENR_FMCEN))   == RESET)
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOGEN)) == RESET)
#define __HAL_RCC_GPIOH_IS_CLK_DISABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOHEN)) == RESET)
#endif











#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) != RESET)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) != RESET)
#define __HAL_RCC_I2C3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_I2C3EN)) != RESET)

#define __HAL_RCC_SPI2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) == RESET)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) == RESET)
#define __HAL_RCC_I2C3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C3EN)) == RESET)
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_TIM3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN))  != RESET)
#define __HAL_RCC_TIM4_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN))  != RESET)
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN))  != RESET)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN))  != RESET)
#define __HAL_RCC_UART4_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
#define __HAL_RCC_UART5_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN))  != RESET)

#define __HAL_RCC_TIM3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN))  == RESET)
#define __HAL_RCC_TIM4_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN))  == RESET)
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN))  == RESET)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN))  == RESET)
#define __HAL_RCC_UART4_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
#define __HAL_RCC_UART5_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN))  == RESET)
#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_RCC_TIM3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) != RESET)
#define __HAL_RCC_DAC2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_DAC2EN)) != RESET)

#define __HAL_RCC_TIM3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) == RESET)
#define __HAL_RCC_DAC2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_DAC2EN)) == RESET)
#endif

#if defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_TIM3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN))  != RESET)
#define __HAL_RCC_TIM4_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN))  != RESET)
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN))  != RESET)
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
#define __HAL_RCC_TIM18_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM18EN)) != RESET)
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN))  != RESET)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN))  != RESET)
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN))  != RESET)
#define __HAL_RCC_DAC2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_DAC2EN))  != RESET)
#define __HAL_RCC_CEC_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_CECEN))   != RESET)

#define __HAL_RCC_TIM3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN))  == RESET)
#define __HAL_RCC_TIM4_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN))  == RESET)
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN))  == RESET)
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
#define __HAL_RCC_TIM18_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_TIM18EN)) == RESET)
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN))  == RESET)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN))  == RESET)
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN))  == RESET)
#define __HAL_RCC_DAC2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_DAC2EN))  == RESET)
#define __HAL_RCC_CEC_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_CECEN))   == RESET)
#endif

#if defined(STM32F303xE) || defined(STM32F398xx)                        \
  || defined(STM32F303xC) || defined(STM32F358xx)                        \
  || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
  || defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)

#define __HAL_RCC_TIM7_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
#endif




#if defined(STM32F302xE) || defined(STM32F303xE)\
  || defined(STM32F302xC) || defined(STM32F303xC)\
  || defined(STM32F302x8)                        \
  || defined(STM32F373xC)
#define __HAL_RCC_USB_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) != RESET)

#define __HAL_RCC_USB_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) == RESET)
#endif




#if !defined(STM32F301x8)
#define __HAL_RCC_CAN1_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_CANEN)) != RESET)

#define __HAL_RCC_CAN1_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_CANEN)) == RESET)
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_I2C3_IS_CLK_ENABLED()          ((RCC->APB1ENR & (RCC_APB1ENR_I2C3EN)) != RESET)

#define __HAL_RCC_I2C3_IS_CLK_DISABLED()         ((RCC->APB1ENR & (RCC_APB1ENR_I2C3EN)) == RESET)
#endif











#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_SPI1_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) != RESET)

#define __HAL_RCC_SPI1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) == RESET)
#endif


#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_TIM8_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) != RESET)

#define __HAL_RCC_TIM8_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) == RESET)
#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_RCC_SPI1_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) != RESET)

#define __HAL_RCC_SPI1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) == RESET)
#endif

#if defined(STM32F334x8)
#define __HAL_RCC_HRTIM1_IS_CLK_ENABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_HRTIM1EN)) != RESET)

#define __HAL_RCC_HRTIM1_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_HRTIM1EN)) == RESET)
#endif

#if defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_ADC1_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN))   != RESET)
#define __HAL_RCC_SPI1_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN))   != RESET)
#define __HAL_RCC_TIM19_IS_CLK_ENABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_TIM19EN))  != RESET)
#define __HAL_RCC_SDADC1_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SDADC1EN)) != RESET)
#define __HAL_RCC_SDADC2_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SDADC2EN)) != RESET)
#define __HAL_RCC_SDADC3_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SDADC3EN)) != RESET)

#define __HAL_RCC_ADC1_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN))   == RESET)
#define __HAL_RCC_SPI1_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN))   == RESET)
#define __HAL_RCC_TIM19_IS_CLK_DISABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_TIM19EN))  == RESET)
#define __HAL_RCC_SDADC1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SDADC1EN)) == RESET)
#define __HAL_RCC_SDADC2_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SDADC2EN)) == RESET)
#define __HAL_RCC_SDADC3_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SDADC3EN)) == RESET)
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
  || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
  || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define __HAL_RCC_TIM1_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) != RESET)

#define __HAL_RCC_TIM1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) == RESET)
#endif




#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_SPI4_IS_CLK_ENABLED()          ((RCC->APB2ENR & (RCC_APB2ENR_SPI4EN)) != RESET)

#define __HAL_RCC_SPI4_IS_CLK_DISABLED()         ((RCC->APB2ENR & (RCC_APB2ENR_SPI4EN)) == RESET)
#endif

#if defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_TIM20_IS_CLK_ENABLED()         ((RCC->APB2ENR & (RCC_APB2ENR_TIM20EN)) != RESET)

#define __HAL_RCC_TIM20_IS_CLK_DISABLED()        ((RCC->APB2ENR & (RCC_APB2ENR_TIM20EN)) == RESET)
#endif








#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define __HAL_RCC_ADC1_FORCE_RESET()     (RCC->AHBRSTR |= (RCC_AHBRSTR_ADC1RST))

#define __HAL_RCC_ADC1_RELEASE_RESET()  (RCC->AHBRSTR &= ~(RCC_AHBRSTR_ADC1RST))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_GPIOE_FORCE_RESET()    (RCC->AHBRSTR |= (RCC_AHBRSTR_GPIOERST))
#define __HAL_RCC_ADC12_FORCE_RESET()    (RCC->AHBRSTR |= (RCC_AHBRSTR_ADC12RST))

#define __HAL_RCC_ADC1_FORCE_RESET()     __HAL_RCC_ADC12_FORCE_RESET()
#define __HAL_RCC_ADC2_FORCE_RESET()     __HAL_RCC_ADC12_FORCE_RESET()

#define __HAL_RCC_GPIOE_RELEASE_RESET()  (RCC->AHBRSTR &= ~(RCC_AHBRSTR_GPIOERST))
#define __HAL_RCC_ADC12_RELEASE_RESET()  (RCC->AHBRSTR &= ~(RCC_AHBRSTR_ADC12RST))

#define __HAL_RCC_ADC1_RELEASE_RESET()    __HAL_RCC_ADC12_RELEASE_RESET()
#define __HAL_RCC_ADC2_RELEASE_RESET()    __HAL_RCC_ADC12_RELEASE_RESET()
#endif


#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_ADC34_FORCE_RESET()    (RCC->AHBRSTR |= (RCC_AHBRSTR_ADC34RST))

#define __HAL_RCC_ADC34_RELEASE_RESET()  (RCC->AHBRSTR &= ~(RCC_AHBRSTR_ADC34RST))
#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_RCC_ADC12_FORCE_RESET()    (RCC->AHBRSTR |= (RCC_AHBRSTR_ADC12RST))

#define __HAL_RCC_ADC1_FORCE_RESET()     __HAL_RCC_ADC12_FORCE_RESET()
#define __HAL_RCC_ADC2_FORCE_RESET()     __HAL_RCC_ADC12_FORCE_RESET()

#define __HAL_RCC_ADC12_RELEASE_RESET()  (RCC->AHBRSTR &= ~(RCC_AHBRSTR_ADC12RST))

#define __HAL_RCC_ADC1_RELEASE_RESET()    __HAL_RCC_ADC12_RELEASE_RESET()
#define __HAL_RCC_ADC2_RELEASE_RESET()    __HAL_RCC_ADC12_RELEASE_RESET()
#endif

#if defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_GPIOE_FORCE_RESET()   (RCC->AHBRSTR |= (RCC_AHBRSTR_GPIOERST))

#define __HAL_RCC_GPIOE_RELEASE_RESET() (RCC->AHBRSTR &= ~(RCC_AHBRSTR_GPIOERST))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_FMC_FORCE_RESET()            (RCC->AHBRSTR |= (RCC_AHBRSTR_FMCRST))
#define __HAL_RCC_GPIOG_FORCE_RESET()          (RCC->AHBRSTR |= (RCC_AHBRSTR_GPIOGRST))
#define __HAL_RCC_GPIOH_FORCE_RESET()          (RCC->AHBRSTR |= (RCC_AHBRSTR_GPIOHRST))

#define __HAL_RCC_FMC_RELEASE_RESET()            (RCC->AHBRSTR &= ~(RCC_AHBRSTR_FMCRST))
#define __HAL_RCC_GPIOG_RELEASE_RESET()          (RCC->AHBRSTR &= ~(RCC_AHBRSTR_GPIOGRST))
#define __HAL_RCC_GPIOH_RELEASE_RESET()          (RCC->AHBRSTR &= ~(RCC_AHBRSTR_GPIOHRST))
#endif








#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define __HAL_RCC_SPI2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_SPI3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_I2C2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C2RST))
#define __HAL_RCC_I2C3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C3RST))

#define __HAL_RCC_SPI2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_SPI3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_I2C2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C2RST))
#define __HAL_RCC_I2C3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C3RST))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_TIM3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM3RST))
#define __HAL_RCC_TIM4_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_SPI2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_SPI3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))
#define __HAL_RCC_I2C2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C2RST))

#define __HAL_RCC_TIM3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM3RST))
#define __HAL_RCC_TIM4_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_SPI2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_SPI3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
#define __HAL_RCC_I2C2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C2RST))
#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_RCC_TIM3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM3RST))
#define __HAL_RCC_DAC2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_DAC2RST))

#define __HAL_RCC_TIM3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM3RST))
#define __HAL_RCC_DAC2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DAC2RST))
#endif

#if defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_TIM3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM3RST))
#define __HAL_RCC_TIM4_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_TIM5_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM12_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))
#define __HAL_RCC_TIM18_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM18RST))
#define __HAL_RCC_SPI2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_SPI3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_I2C2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C2RST))
#define __HAL_RCC_DAC2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_DAC2RST))
#define __HAL_RCC_CEC_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_CECRST))

#define __HAL_RCC_TIM3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM3RST))
#define __HAL_RCC_TIM4_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_TIM5_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM12_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM14RST))
#define __HAL_RCC_TIM18_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM18RST))
#define __HAL_RCC_SPI2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_SPI3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_I2C2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C2RST))
#define __HAL_RCC_DAC2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DAC2RST))
#define __HAL_RCC_CEC_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CECRST))
#endif

#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)\
  || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
  || defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_TIM7_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))

#define __HAL_RCC_TIM7_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
#endif




#if defined(STM32F302xE) || defined(STM32F303xE)\
  || defined(STM32F302xC) || defined(STM32F303xC)\
  || defined(STM32F302x8)                        \
  || defined(STM32F373xC)
#define __HAL_RCC_USB_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_USBRST))

#define __HAL_RCC_USB_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USBRST))
#endif




#if !defined(STM32F301x8)
#define __HAL_RCC_CAN1_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_CANRST))

#define __HAL_RCC_CAN1_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CANRST))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_I2C3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C3RST))

#define __HAL_RCC_I2C3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C3RST))
#endif








#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_SPI1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI1RST))

#define __HAL_RCC_SPI1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST))
#endif


#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_RCC_TIM8_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM8RST))

#define __HAL_RCC_TIM8_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM8RST))
#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_RCC_SPI1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI1RST))

#define __HAL_RCC_SPI1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST))
#endif

#if defined(STM32F334x8)
#define __HAL_RCC_HRTIM1_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_HRTIM1RST))

#define __HAL_RCC_HRTIM1_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_HRTIM1RST))
#endif

#if defined(STM32F373xC) || defined(STM32F378xx)
#define __HAL_RCC_ADC1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC1RST))
#define __HAL_RCC_SPI1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI1RST))
#define __HAL_RCC_TIM19_FORCE_RESET()    (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM19RST))
#define __HAL_RCC_SDADC1_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_SDADC1RST))
#define __HAL_RCC_SDADC2_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_SDADC2RST))
#define __HAL_RCC_SDADC3_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_SDADC3RST))

#define __HAL_RCC_ADC1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC1RST))
#define __HAL_RCC_SPI1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST))
#define __HAL_RCC_TIM19_RELEASE_RESET()  (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM19RST))
#define __HAL_RCC_SDADC1_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SDADC1RST))
#define __HAL_RCC_SDADC2_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SDADC2RST))
#define __HAL_RCC_SDADC3_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SDADC3RST))
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
  || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
  || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define __HAL_RCC_TIM1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM1RST))

#define __HAL_RCC_TIM1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM1RST))
#endif




#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_SPI4_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI4RST))

#define __HAL_RCC_SPI4_RELEASE_RESET()    (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI4RST))
#endif

#if defined(STM32F303xE) || defined(STM32F398xx)
#define __HAL_RCC_TIM20_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM20RST))

#define __HAL_RCC_TIM20_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM20RST))
#endif





#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)










#define __HAL_RCC_I2C2_CONFIG(__I2C2CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_I2C2SW, (uint32_t)(__I2C2CLKSource__))






#define __HAL_RCC_GET_I2C2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_I2C2SW)))







#define __HAL_RCC_I2C3_CONFIG(__I2C3CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_I2C3SW, (uint32_t)(__I2C3CLKSource__))






#define __HAL_RCC_GET_I2C3_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_I2C3SW)))














#define __HAL_RCC_TIM1_CONFIG(__TIM1CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM1SW, (uint32_t)(__TIM1CLKSource__))






#define __HAL_RCC_GET_TIM1_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM1SW)))







#define __HAL_RCC_TIM15_CONFIG(__TIM15CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM15SW, (uint32_t)(__TIM15CLKSource__))






#define __HAL_RCC_GET_TIM15_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM15SW)))







#define __HAL_RCC_TIM16_CONFIG(__TIM16CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM16SW, (uint32_t)(__TIM16CLKSource__))






#define __HAL_RCC_GET_TIM16_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM16SW)))







#define __HAL_RCC_TIM17_CONFIG(__TIM17CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM17SW, (uint32_t)(__TIM17CLKSource__))






#define __HAL_RCC_GET_TIM17_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM17SW)))
















#define __HAL_RCC_I2S_CONFIG(__I2SCLKSource__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_I2SSRC, (uint32_t)(__I2SCLKSource__))







#define __HAL_RCC_GET_I2S_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_I2SSRC)))

























#define __HAL_RCC_ADC1_CONFIG(__ADC1CLKSource__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_ADC1PRES, (uint32_t)(__ADC1CLKSource__))

















#define __HAL_RCC_GET_ADC1_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_ADC1PRES)))




#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)










#define __HAL_RCC_I2C2_CONFIG(__I2C2CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_I2C2SW, (uint32_t)(__I2C2CLKSource__))






#define __HAL_RCC_GET_I2C2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_I2C2SW)))

























#define __HAL_RCC_ADC12_CONFIG(__ADC12CLKSource__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_ADCPRE12, (uint32_t)(__ADC12CLKSource__))

















#define __HAL_RCC_GET_ADC12_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_ADCPRE12)))














#define __HAL_RCC_TIM1_CONFIG(__TIM1CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM1SW, (uint32_t)(__TIM1CLKSource__))






#define __HAL_RCC_GET_TIM1_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM1SW)))
















#define __HAL_RCC_I2S_CONFIG(__I2SCLKSource__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_I2SSRC, (uint32_t)(__I2SCLKSource__))







#define __HAL_RCC_GET_I2S_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_I2SSRC)))
















#define __HAL_RCC_UART4_CONFIG(__UART4CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_UART4SW, (uint32_t)(__UART4CLKSource__))








#define __HAL_RCC_GET_UART4_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_UART4SW)))









#define __HAL_RCC_UART5_CONFIG(__UART5CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_UART5SW, (uint32_t)(__UART5CLKSource__))








#define __HAL_RCC_GET_UART5_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_UART5SW)))



#endif


#if defined(STM32F303xE) || defined(STM32F398xx)\
  || defined(STM32F303xC) || defined(STM32F358xx)





















#define __HAL_RCC_ADC34_CONFIG(__ADC34CLKSource__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_ADCPRE34, (uint32_t)(__ADC34CLKSource__))

















#define __HAL_RCC_GET_ADC34_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_ADCPRE34)))














#define __HAL_RCC_TIM8_CONFIG(__TIM8CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM8SW, (uint32_t)(__TIM8CLKSource__))






#define __HAL_RCC_GET_TIM8_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM8SW)))




#endif


#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)





















#define __HAL_RCC_ADC12_CONFIG(__ADC12CLKSource__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_ADCPRE12, (uint32_t)(__ADC12CLKSource__))

















#define __HAL_RCC_GET_ADC12_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_ADCPRE12)))













#define __HAL_RCC_TIM1_CONFIG(__TIM1CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM1SW, (uint32_t)(__TIM1CLKSource__))






#define __HAL_RCC_GET_TIM1_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM1SW)))



#endif

#if defined(STM32F334x8)









#define __HAL_RCC_HRTIM1_CONFIG(__HRTIM1CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_HRTIM1SW, (uint32_t)(__HRTIM1CLKSource__))






#define __HAL_RCC_GET_HRTIM1_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_HRTIM1SW)))



#endif

#if defined(STM32F373xC) || defined(STM32F378xx)









#define __HAL_RCC_I2C2_CONFIG(__I2C2CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_I2C2SW, (uint32_t)(__I2C2CLKSource__))






#define __HAL_RCC_GET_I2C2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_I2C2SW)))















#define __HAL_RCC_ADC1_CONFIG(__ADC1CLKSource__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_ADCPRE, (uint32_t)(__ADC1CLKSource__))








#define __HAL_RCC_GET_ADC1_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_ADCPRE)))




























#define __HAL_RCC_SDADC_CONFIG(__SDADCPrescaler__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_SDPRE, (uint32_t)(__SDADCPrescaler__))





















#define __HAL_RCC_GET_SDADC_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_SDPRE)))













#define __HAL_RCC_CEC_CONFIG(__CECCLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_CECSW, (uint32_t)(__CECCLKSource__))






#define __HAL_RCC_GET_CEC_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_CECSW)))




#endif

#if defined(STM32F302xE) || defined(STM32F303xE)\
  || defined(STM32F302xC) || defined(STM32F303xC)\
  || defined(STM32F302x8)                        \
  || defined(STM32F373xC)










#define __HAL_RCC_USB_CONFIG(__USBCLKSource__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_USBPRE, (uint32_t)(__USBCLKSource__))






#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_USBPRE)))




#endif




#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)










#define __HAL_RCC_I2C3_CONFIG(__I2C3CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_I2C3SW, (uint32_t)(__I2C3CLKSource__))






#define __HAL_RCC_GET_I2C3_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_I2C3SW)))













#define __HAL_RCC_TIM2_CONFIG(__TIM2CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM2SW, (uint32_t)(__TIM2CLKSource__))






#define __HAL_RCC_GET_TIM2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM2SW)))







#define __HAL_RCC_TIM34_CONFIG(__TIM34CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM34SW, (uint32_t)(__TIM34CLKSource__))






#define __HAL_RCC_GET_TIM34_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM34SW)))







#define __HAL_RCC_TIM15_CONFIG(__TIM15CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM15SW, (uint32_t)(__TIM15CLKSource__))






#define __HAL_RCC_GET_TIM15_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM15SW)))







#define __HAL_RCC_TIM16_CONFIG(__TIM16CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM16SW, (uint32_t)(__TIM16CLKSource__))






#define __HAL_RCC_GET_TIM16_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM16SW)))







#define __HAL_RCC_TIM17_CONFIG(__TIM17CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM17SW, (uint32_t)(__TIM17CLKSource__))






#define __HAL_RCC_GET_TIM17_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM17SW)))





#endif

#if defined(STM32F303xE) || defined(STM32F398xx)









#define __HAL_RCC_TIM20_CONFIG(__TIM20CLKSource__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_TIM20SW, (uint32_t)(__TIM20CLKSource__))






#define __HAL_RCC_GET_TIM20_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_TIM20SW)))




#endif















#define __HAL_RCC_LSEDRIVE_CONFIG(__RCC_LSEDRIVE__) (MODIFY_REG(RCC->BDCR,\
        RCC_BDCR_LSEDRV, (uint32_t)(__RCC_LSEDRIVE__) ))


















HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

















#ifdef __cplusplus
}
#endif

#endif



