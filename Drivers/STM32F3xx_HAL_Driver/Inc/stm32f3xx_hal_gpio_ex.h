



































#ifndef __STM32F3xx_HAL_GPIO_EX_H
#define __STM32F3xx_HAL_GPIO_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"




















#if defined (STM32F302xC)




#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)



#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM2           ((uint8_t)0x02U)
#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_COMP1          ((uint8_t)0x02U)



#define GPIO_AF3_TSC           ((uint8_t)0x03U)
#define GPIO_AF3_TIM15         ((uint8_t)0x03U)




#define GPIO_AF4_TIM1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM16         ((uint8_t)0x04U)
#define GPIO_AF4_TIM17         ((uint8_t)0x04U)
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)
#define GPIO_AF5_I2S           ((uint8_t)0x05U)
#define GPIO_AF5_I2S2ext       ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)
#define GPIO_AF5_UART4         ((uint8_t)0x05U)
#define GPIO_AF5_UART5         ((uint8_t)0x05U)



#define GPIO_AF6_SPI2          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)
#define GPIO_AF6_I2S3ext       ((uint8_t)0x06U)
#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_COMP6         ((uint8_t)0x07U)
#define GPIO_AF7_CAN           ((uint8_t)0x07U)




#define GPIO_AF8_COMP1         ((uint8_t)0x08U)
#define GPIO_AF8_COMP2         ((uint8_t)0x08U)
#define GPIO_AF8_COMP4         ((uint8_t)0x08U)
#define GPIO_AF8_COMP6         ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)




#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM4           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)



#define GPIO_AF11_TIM1           ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1            ((uint8_t)0xCU)





#define GPIO_AF14_USB           ((uint8_t)0x0EU)



#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0CU) || ((AF) == (uint8_t)0x0EU) || ((AF) == (uint8_t)0x0FU))

#endif

#if defined (STM32F303xC)




#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)



#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM2           ((uint8_t)0x02U)
#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)
#define GPIO_AF2_TIM8           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_COMP1          ((uint8_t)0x02U)



#define GPIO_AF3_TSC           ((uint8_t)0x03U)
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)
#define GPIO_AF3_COMP7         ((uint8_t)0x03U)
#define GPIO_AF3_TIM15         ((uint8_t)0x03U)




#define GPIO_AF4_TIM1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM8          ((uint8_t)0x04U)
#define GPIO_AF4_TIM16         ((uint8_t)0x04U)
#define GPIO_AF4_TIM17         ((uint8_t)0x04U)
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)
#define GPIO_AF5_I2S           ((uint8_t)0x05U)
#define GPIO_AF5_I2S2ext       ((uint8_t)0x05U)
#define GPIO_AF5_TIM8          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)
#define GPIO_AF5_UART4         ((uint8_t)0x05U)
#define GPIO_AF5_UART5         ((uint8_t)0x05U)



#define GPIO_AF6_SPI2          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)
#define GPIO_AF6_I2S3ext       ((uint8_t)0x06U)
#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_TIM8          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_COMP3         ((uint8_t)0x07U)
#define GPIO_AF7_COMP5         ((uint8_t)0x07U)
#define GPIO_AF7_COMP6         ((uint8_t)0x07U)
#define GPIO_AF7_CAN           ((uint8_t)0x07U)




#define GPIO_AF8_COMP1         ((uint8_t)0x08U)
#define GPIO_AF8_COMP2         ((uint8_t)0x08U)
#define GPIO_AF8_COMP3         ((uint8_t)0x08U)
#define GPIO_AF8_COMP4         ((uint8_t)0x08U)
#define GPIO_AF8_COMP5         ((uint8_t)0x08U)
#define GPIO_AF8_COMP6         ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM8          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)




#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM4           ((uint8_t)0xAU)
#define GPIO_AF10_TIM8           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)



#define GPIO_AF11_TIM1           ((uint8_t)0x0BU)
#define GPIO_AF11_TIM8           ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1            ((uint8_t)0xCU)





#define GPIO_AF14_USB           ((uint8_t)0x0EU)



#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0CU) || ((AF) == (uint8_t)0x0EU) || ((AF) == (uint8_t)0x0FU))

#endif

#if defined (STM32F303xE)




#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)




#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM2           ((uint8_t)0x02U)
#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)
#define GPIO_AF2_TIM8           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_COMP1          ((uint8_t)0x02U)
#define GPIO_AF2_I2C3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM20          ((uint8_t)0x02U)




#define GPIO_AF3_TSC           ((uint8_t)0x03U)
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)
#define GPIO_AF3_COMP7         ((uint8_t)0x03U)
#define GPIO_AF3_TIM15         ((uint8_t)0x03U)
#define GPIO_AF3_I2C3          ((uint8_t)0x03U)
#define GPIO_AF3_TIM20         ((uint8_t)0x03U)




#define GPIO_AF4_TIM1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM8          ((uint8_t)0x04U)
#define GPIO_AF4_TIM16         ((uint8_t)0x04U)
#define GPIO_AF4_TIM17         ((uint8_t)0x04U)
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)
#define GPIO_AF5_I2S           ((uint8_t)0x05U)
#define GPIO_AF5_I2S2ext       ((uint8_t)0x05U)
#define GPIO_AF5_TIM8          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)
#define GPIO_AF5_UART4         ((uint8_t)0x05U)
#define GPIO_AF5_UART5         ((uint8_t)0x05U)
#define GPIO_AF5_SPI4          ((uint8_t)0x05U)




#define GPIO_AF6_SPI2          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)
#define GPIO_AF6_I2S3ext       ((uint8_t)0x06U)
#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_TIM8          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)
#define GPIO_AF6_TIM20         ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_COMP3         ((uint8_t)0x07U)
#define GPIO_AF7_COMP5         ((uint8_t)0x07U)
#define GPIO_AF7_COMP6         ((uint8_t)0x07U)
#define GPIO_AF7_CAN           ((uint8_t)0x07U)




#define GPIO_AF8_COMP1         ((uint8_t)0x08U)
#define GPIO_AF8_COMP2         ((uint8_t)0x08U)
#define GPIO_AF8_COMP3         ((uint8_t)0x08U)
#define GPIO_AF8_COMP4         ((uint8_t)0x08U)
#define GPIO_AF8_COMP5         ((uint8_t)0x08U)
#define GPIO_AF8_COMP6         ((uint8_t)0x08U)
#define GPIO_AF8_I2C3          ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM8          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)




#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM4           ((uint8_t)0xAU)
#define GPIO_AF10_TIM8           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)



#define GPIO_AF11_TIM1           ((uint8_t)0x0BU)
#define GPIO_AF11_TIM8           ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1            ((uint8_t)0xCU)
#define GPIO_AF12_FMC             ((uint8_t)0xCU)
#define GPIO_AF12_SDIO            ((uint8_t)0xCU)




#define GPIO_AF14_USB           ((uint8_t)0x0EU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0CU) || ((AF) == (uint8_t)0x0EU) || ((AF) == (uint8_t)0x0FU))

#endif

#if defined (STM32F302xE)




#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)




#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM2           ((uint8_t)0x02U)
#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_COMP1          ((uint8_t)0x02U)
#define GPIO_AF2_I2C3           ((uint8_t)0x02U)




#define GPIO_AF3_TSC           ((uint8_t)0x03U)
#define GPIO_AF3_TIM15         ((uint8_t)0x03U)
#define GPIO_AF3_I2C3          ((uint8_t)0x03U)




#define GPIO_AF4_TIM1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM16         ((uint8_t)0x04U)
#define GPIO_AF4_TIM17         ((uint8_t)0x04U)
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)
#define GPIO_AF5_I2S           ((uint8_t)0x05U)
#define GPIO_AF5_I2S2ext       ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)
#define GPIO_AF5_UART4         ((uint8_t)0x05U)
#define GPIO_AF5_UART5         ((uint8_t)0x05U)
#define GPIO_AF5_SPI4          ((uint8_t)0x05U)




#define GPIO_AF6_SPI2          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)
#define GPIO_AF6_I2S3ext       ((uint8_t)0x06U)
#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_COMP6         ((uint8_t)0x07U)
#define GPIO_AF7_CAN           ((uint8_t)0x07U)




#define GPIO_AF8_COMP1         ((uint8_t)0x08U)
#define GPIO_AF8_COMP2         ((uint8_t)0x08U)
#define GPIO_AF8_COMP4         ((uint8_t)0x08U)
#define GPIO_AF8_COMP6         ((uint8_t)0x08U)
#define GPIO_AF8_I2C3          ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)




#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM4           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)



#define GPIO_AF11_TIM1           ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1            ((uint8_t)0xCU)
#define GPIO_AF12_FMC             ((uint8_t)0xCU)
#define GPIO_AF12_SDIO            ((uint8_t)0xCU)




#define GPIO_AF14_USB           ((uint8_t)0x0EU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0CU) || ((AF) == (uint8_t)0x0EU) || ((AF) == (uint8_t)0x0FU))

#endif

#if defined (STM32F398xx)




#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)




#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM2           ((uint8_t)0x02U)
#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)
#define GPIO_AF2_TIM8           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_COMP1          ((uint8_t)0x02U)
#define GPIO_AF2_I2C3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM20          ((uint8_t)0x02U)




#define GPIO_AF3_TSC           ((uint8_t)0x03U)
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)
#define GPIO_AF3_COMP7         ((uint8_t)0x03U)
#define GPIO_AF3_TIM15         ((uint8_t)0x03U)
#define GPIO_AF3_I2C3          ((uint8_t)0x03U)
#define GPIO_AF3_TIM20         ((uint8_t)0x03U)




#define GPIO_AF4_TIM1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM8          ((uint8_t)0x04U)
#define GPIO_AF4_TIM16         ((uint8_t)0x04U)
#define GPIO_AF4_TIM17         ((uint8_t)0x04U)
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)
#define GPIO_AF5_I2S           ((uint8_t)0x05U)
#define GPIO_AF5_I2S2ext       ((uint8_t)0x05U)
#define GPIO_AF5_TIM8          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)
#define GPIO_AF5_UART4         ((uint8_t)0x05U)
#define GPIO_AF5_UART5         ((uint8_t)0x05U)
#define GPIO_AF5_SPI4          ((uint8_t)0x05U)




#define GPIO_AF6_SPI2          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)
#define GPIO_AF6_I2S3ext       ((uint8_t)0x06U)
#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_TIM8          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)
#define GPIO_AF6_TIM20         ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_COMP3         ((uint8_t)0x07U)
#define GPIO_AF7_COMP5         ((uint8_t)0x07U)
#define GPIO_AF7_COMP6         ((uint8_t)0x07U)
#define GPIO_AF7_CAN           ((uint8_t)0x07U)




#define GPIO_AF8_COMP1         ((uint8_t)0x08U)
#define GPIO_AF8_COMP2         ((uint8_t)0x08U)
#define GPIO_AF8_COMP3         ((uint8_t)0x08U)
#define GPIO_AF8_COMP4         ((uint8_t)0x08U)
#define GPIO_AF8_COMP5         ((uint8_t)0x08U)
#define GPIO_AF8_COMP6         ((uint8_t)0x08U)
#define GPIO_AF8_I2C3          ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM8          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)




#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM4           ((uint8_t)0xAU)
#define GPIO_AF10_TIM8           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)



#define GPIO_AF11_TIM1           ((uint8_t)0x0BU)
#define GPIO_AF11_TIM8           ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1            ((uint8_t)0xCU)
#define GPIO_AF12_FMC             ((uint8_t)0xCU)
#define GPIO_AF12_SDIO            ((uint8_t)0xCU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0CU) || ((AF) == (uint8_t)0x0FU))

#endif

#if defined (STM32F358xx)




#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)



#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM2           ((uint8_t)0x02U)
#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)
#define GPIO_AF2_TIM8           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_COMP1          ((uint8_t)0x02U)



#define GPIO_AF3_TSC           ((uint8_t)0x03U)
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)
#define GPIO_AF3_COMP7         ((uint8_t)0x03U)
#define GPIO_AF3_TIM15         ((uint8_t)0x03U)




#define GPIO_AF4_TIM1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM8          ((uint8_t)0x04U)
#define GPIO_AF4_TIM16         ((uint8_t)0x04U)
#define GPIO_AF4_TIM17         ((uint8_t)0x04U)
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)
#define GPIO_AF5_I2S           ((uint8_t)0x05U)
#define GPIO_AF5_I2S2ext       ((uint8_t)0x05U)
#define GPIO_AF5_TIM8          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)
#define GPIO_AF5_UART4         ((uint8_t)0x05U)
#define GPIO_AF5_UART5         ((uint8_t)0x05U)



#define GPIO_AF6_SPI2          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)
#define GPIO_AF6_I2S3ext       ((uint8_t)0x06U)
#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_TIM8          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_COMP3         ((uint8_t)0x07U)
#define GPIO_AF7_COMP5         ((uint8_t)0x07U)
#define GPIO_AF7_COMP6         ((uint8_t)0x07U)
#define GPIO_AF7_CAN           ((uint8_t)0x07U)




#define GPIO_AF8_COMP1         ((uint8_t)0x08U)
#define GPIO_AF8_COMP2         ((uint8_t)0x08U)
#define GPIO_AF8_COMP3         ((uint8_t)0x08U)
#define GPIO_AF8_COMP4         ((uint8_t)0x08U)
#define GPIO_AF8_COMP5         ((uint8_t)0x08U)
#define GPIO_AF8_COMP6         ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM8          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)




#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM4           ((uint8_t)0xAU)
#define GPIO_AF10_TIM8           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)



#define GPIO_AF11_TIM1           ((uint8_t)0x0BU)
#define GPIO_AF11_TIM8           ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1            ((uint8_t)0xCU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0CU) || ((AF) == (uint8_t)0x0FU))

#endif

#if  defined (STM32F373xC)




#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)



#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)
#define GPIO_AF2_TIM5           ((uint8_t)0x02U)
#define GPIO_AF2_TIM13          ((uint8_t)0x02U)
#define GPIO_AF2_TIM14          ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_TIM19          ((uint8_t)0x02U)




#define GPIO_AF3_TSC           ((uint8_t)0x03U)



#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)



#define GPIO_AF6_SPI1          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)
#define GPIO_AF6_CEC           ((uint8_t)0x06U)



#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_CAN           ((uint8_t)0x07U)
#define GPIO_AF7_CEC           ((uint8_t)0x07U)




#define GPIO_AF8_COMP1         ((uint8_t)0x08U)
#define GPIO_AF8_COMP2         ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM12         ((uint8_t)0x09U)
#define GPIO_AF9_TIM13         ((uint8_t)0x09U)
#define GPIO_AF9_TIM14         ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)



#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM4           ((uint8_t)0xAU)
#define GPIO_AF10_TIM12          ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)



#define GPIO_AF11_TIM19          ((uint8_t)0x0BU)





#define GPIO_AF14_USB           ((uint8_t)0x0EU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0BU) || ((AF) == (uint8_t)0x0EU) || ((AF) == (uint8_t)0x0FU))

#endif


#if defined (STM32F378xx)




#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)



#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)
#define GPIO_AF2_TIM5           ((uint8_t)0x02U)
#define GPIO_AF2_TIM13          ((uint8_t)0x02U)
#define GPIO_AF2_TIM14          ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_TIM19          ((uint8_t)0x02U)




#define GPIO_AF3_TSC           ((uint8_t)0x03U)



#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)




#define GPIO_AF6_SPI1          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)
#define GPIO_AF6_CEC           ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_CAN           ((uint8_t)0x07U)
#define GPIO_AF7_CEC           ((uint8_t)0x07U)




#define GPIO_AF8_COMP1         ((uint8_t)0x08U)
#define GPIO_AF8_COMP2         ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM12         ((uint8_t)0x09U)
#define GPIO_AF9_TIM13         ((uint8_t)0x09U)
#define GPIO_AF9_TIM14         ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)




#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM4           ((uint8_t)0xAU)
#define GPIO_AF10_TIM12          ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)




#define GPIO_AF11_TIM19          ((uint8_t)0x0BU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0BU) || ((AF) == (uint8_t)0x0FU))

#endif

#if defined (STM32F303x8)




#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)



#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_TIM16          ((uint8_t)0x02U)




#define GPIO_AF3_TSC           ((uint8_t)0x03U)




#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM1          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)



#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_GPCOMP6       ((uint8_t)0x07U)




#define GPIO_AF8_GPCOMP2         ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP4         ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP6         ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)



#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)




#define GPIO_AF11_TIM1          ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1          ((uint8_t)0x0CU)




#define GPIO_AF13_OPAMP2        ((uint8_t)0x0DU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0DU) || ((AF) == (uint8_t)0x0FU))

#endif

#if defined (STM32F334x8) || defined (STM32F328xx)




#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)



#define GPIO_AF2_TIM3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_TIM16          ((uint8_t)0x02U)




#define GPIO_AF3_TSC           ((uint8_t)0x03U)
#define GPIO_AF3_HRTIM1        ((uint8_t)0x03U)




#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM1          ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)



#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_GPCOMP6       ((uint8_t)0x07U)




#define GPIO_AF8_GPCOMP2         ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP4         ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP6         ((uint8_t)0x08U)




#define GPIO_AF9_CAN           ((uint8_t)0x09U)
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)



#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)




#define GPIO_AF11_TIM1          ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1          ((uint8_t)0x0CU)
#define GPIO_AF12_HRTIM1        ((uint8_t)0x0CU)




#define GPIO_AF13_OPAMP2        ((uint8_t)0x0DU)
#define GPIO_AF13_HRTIM1        ((uint8_t)0x0DU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0DU) || ((AF) == (uint8_t)0x0FU))

#endif

#if defined (STM32F301x8) || defined (STM32F318xx)




#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)



#define GPIO_AF2_I2C3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_TIM2           ((uint8_t)0x02U)




#define GPIO_AF3_TSC           ((uint8_t)0x03U)
#define GPIO_AF3_I2C3          ((uint8_t)0x03U)
#define GPIO_AF3_TIM15         ((uint8_t)0x03U)




#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)
#define GPIO_AF4_TIM1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM16         ((uint8_t)0x04U)
#define GPIO_AF4_TIM17         ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)



#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)
#define GPIO_AF6_SPI2          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_GPCOMP6       ((uint8_t)0x07U)




#define GPIO_AF8_I2C3            ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP2         ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP4         ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP6         ((uint8_t)0x08U)




#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)




#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)




#define GPIO_AF11_TIM1          ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1          ((uint8_t)0x0CU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0CU) || ((AF) == (uint8_t)0x0FU))

#endif

#if defined (STM32F302x8)




#define GPIO_AF0_MCO           ((uint8_t)0x00U)
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)




#define GPIO_AF1_TIM2           ((uint8_t)0x01U)
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)
#define GPIO_AF1_EVENTOUT       ((uint8_t)0x01U)



#define GPIO_AF2_I2C3           ((uint8_t)0x02U)
#define GPIO_AF2_TIM1           ((uint8_t)0x02U)
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)
#define GPIO_AF2_TIM2           ((uint8_t)0x02U)




#define GPIO_AF3_TSC           ((uint8_t)0x03U)
#define GPIO_AF3_I2C3          ((uint8_t)0x03U)
#define GPIO_AF3_TIM15         ((uint8_t)0x03U)




#define GPIO_AF4_I2C1          ((uint8_t)0x04U)
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)
#define GPIO_AF4_TIM1          ((uint8_t)0x04U)
#define GPIO_AF4_TIM16         ((uint8_t)0x04U)
#define GPIO_AF4_TIM17         ((uint8_t)0x04U)




#define GPIO_AF5_SPI1          ((uint8_t)0x05U)
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)
#define GPIO_AF5_IR            ((uint8_t)0x05U)



#define GPIO_AF6_TIM1          ((uint8_t)0x06U)
#define GPIO_AF6_IR            ((uint8_t)0x06U)
#define GPIO_AF6_SPI2          ((uint8_t)0x06U)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)




#define GPIO_AF7_USART1        ((uint8_t)0x07U)
#define GPIO_AF7_USART2        ((uint8_t)0x07U)
#define GPIO_AF7_USART3        ((uint8_t)0x07U)
#define GPIO_AF7_GPCOMP6       ((uint8_t)0x07U)
#define GPIO_AF7_CAN           ((uint8_t)0x07U)




#define GPIO_AF8_I2C3   	 ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP2         ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP4         ((uint8_t)0x08U)
#define GPIO_AF8_GPCOMP6         ((uint8_t)0x08U)




#define GPIO_AF9_TIM1          ((uint8_t)0x09U)
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)
#define GPIO_AF9_CAN           ((uint8_t)0x09U)




#define GPIO_AF10_TIM2           ((uint8_t)0xAU)
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)




#define GPIO_AF11_TIM1          ((uint8_t)0x0BU)




#define GPIO_AF12_TIM1          ((uint8_t)0x0CU)




#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)

#define IS_GPIO_AF(AF)          (((AF) <= (uint8_t)0x0CU) || ((AF) == (uint8_t)0x0FU))

#endif
















#if defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA))? 0U :\
                                      ((__GPIOx__) == (GPIOB))? 1U :\
                                      ((__GPIOx__) == (GPIOC))? 2U :\
                                      ((__GPIOx__) == (GPIOD))? 3U : 5U)
#endif


#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F373xC) || defined(STM32F378xx)
#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA))? 0U :\
                                      ((__GPIOx__) == (GPIOB))? 1U :\
                                      ((__GPIOx__) == (GPIOC))? 2U :\
                                      ((__GPIOx__) == (GPIOD))? 3U :\
                                      ((__GPIOx__) == (GPIOE))? 4U : 5U)
#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA))? 0U :\
                                      ((__GPIOx__) == (GPIOB))? 1U :\
                                      ((__GPIOx__) == (GPIOC))? 2U :\
                                      ((__GPIOx__) == (GPIOD))? 3U :\
                                      ((__GPIOx__) == (GPIOE))? 4U :\
                                      ((__GPIOx__) == (GPIOF))? 5U :\
                                      ((__GPIOx__) == (GPIOG))? 6U : 7U)
#endif


















#ifdef __cplusplus
}
#endif

#endif


