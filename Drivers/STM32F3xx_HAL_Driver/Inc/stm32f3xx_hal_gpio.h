



































#ifndef __STM32F3xx_HAL_GPIO_H
#define __STM32F3xx_HAL_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"

















typedef struct
{
  uint32_t Pin;


  uint32_t Mode;


  uint32_t Pull;


  uint32_t Speed;


  uint32_t Alternate;

}GPIO_InitTypeDef;




typedef enum
{
  GPIO_PIN_RESET = 0U,
  GPIO_PIN_SET
}GPIO_PinState;











#define GPIO_PIN_0                 ((uint16_t)0x0001U)
#define GPIO_PIN_1                 ((uint16_t)0x0002U)
#define GPIO_PIN_2                 ((uint16_t)0x0004U)
#define GPIO_PIN_3                 ((uint16_t)0x0008U)
#define GPIO_PIN_4                 ((uint16_t)0x0010U)
#define GPIO_PIN_5                 ((uint16_t)0x0020U)
#define GPIO_PIN_6                 ((uint16_t)0x0040U)
#define GPIO_PIN_7                 ((uint16_t)0x0080U)
#define GPIO_PIN_8                 ((uint16_t)0x0100U)
#define GPIO_PIN_9                 ((uint16_t)0x0200U)
#define GPIO_PIN_10                ((uint16_t)0x0400U)
#define GPIO_PIN_11                ((uint16_t)0x0800U)
#define GPIO_PIN_12                ((uint16_t)0x1000U)
#define GPIO_PIN_13                ((uint16_t)0x2000U)
#define GPIO_PIN_14                ((uint16_t)0x4000U)
#define GPIO_PIN_15                ((uint16_t)0x8000U)
#define GPIO_PIN_All               ((uint16_t)0xFFFFU)

#define GPIO_PIN_MASK              (0x0000FFFFU)














#define  GPIO_MODE_INPUT                        (0x00000000U)
#define  GPIO_MODE_OUTPUT_PP                    (0x00000001U)
#define  GPIO_MODE_OUTPUT_OD                    (0x00000011U)
#define  GPIO_MODE_AF_PP                        (0x00000002U)
#define  GPIO_MODE_AF_OD                        (0x00000012U)
#define  GPIO_MODE_ANALOG                       (0x00000003U)
#define  GPIO_MODE_IT_RISING                    (0x10110000U)
#define  GPIO_MODE_IT_FALLING                   (0x10210000U)
#define  GPIO_MODE_IT_RISING_FALLING            (0x10310000U)
#define  GPIO_MODE_EVT_RISING                   (0x10120000U)
#define  GPIO_MODE_EVT_FALLING                  (0x10220000U)
#define  GPIO_MODE_EVT_RISING_FALLING           (0x10320000U)








#define  GPIO_SPEED_FREQ_LOW      (0x00000000U)
#define  GPIO_SPEED_FREQ_MEDIUM   (0x00000001U)
#define  GPIO_SPEED_FREQ_HIGH     (0x00000003U)








#define  GPIO_NOPULL        (0x00000000U)
#define  GPIO_PULLUP        (0x00000001U)
#define  GPIO_PULLDOWN      (0x00000002U)



















#define __HAL_GPIO_EXTI_GET_FLAG(__EXTI_LINE__)       (EXTI->PR & (__EXTI_LINE__))







#define __HAL_GPIO_EXTI_CLEAR_FLAG(__EXTI_LINE__)     (EXTI->PR = (__EXTI_LINE__))







#define __HAL_GPIO_EXTI_GET_IT(__EXTI_LINE__)         (EXTI->PR & (__EXTI_LINE__))







#define __HAL_GPIO_EXTI_CLEAR_IT(__EXTI_LINE__)       (EXTI->PR = (__EXTI_LINE__))







#define __HAL_GPIO_EXTI_GENERATE_SWIT(__EXTI_LINE__)  (EXTI->SWIER |= (__EXTI_LINE__))









#define IS_GPIO_PIN_ACTION(ACTION)  (((ACTION) == GPIO_PIN_RESET) || ((ACTION) == GPIO_PIN_SET))

#define IS_GPIO_PIN(__PIN__)        ((((__PIN__) & GPIO_PIN_MASK) != 0x00U) &&\
                                     (((__PIN__) & ~GPIO_PIN_MASK) == 0x00U))

#define IS_GPIO_MODE(__MODE__)      (((__MODE__) == GPIO_MODE_INPUT)              ||\
                                     ((__MODE__) == GPIO_MODE_OUTPUT_PP)          ||\
                                     ((__MODE__) == GPIO_MODE_OUTPUT_OD)          ||\
                                     ((__MODE__) == GPIO_MODE_AF_PP)              ||\
                                     ((__MODE__) == GPIO_MODE_AF_OD)              ||\
                                     ((__MODE__) == GPIO_MODE_IT_RISING)          ||\
                                     ((__MODE__) == GPIO_MODE_IT_FALLING)         ||\
                                     ((__MODE__) == GPIO_MODE_IT_RISING_FALLING)  ||\
                                     ((__MODE__) == GPIO_MODE_EVT_RISING)         ||\
                                     ((__MODE__) == GPIO_MODE_EVT_FALLING)        ||\
                                     ((__MODE__) == GPIO_MODE_EVT_RISING_FALLING) ||\
                                     ((__MODE__) == GPIO_MODE_ANALOG))

#define IS_GPIO_SPEED(__SPEED__)    (((__SPEED__) == GPIO_SPEED_FREQ_LOW)    ||\
                                     ((__SPEED__) == GPIO_SPEED_FREQ_MEDIUM) ||\
                                     ((__SPEED__) == GPIO_SPEED_FREQ_HIGH))

#define IS_GPIO_PULL(__PULL__)      (((__PULL__) == GPIO_NOPULL)   ||\
                                     ((__PULL__) == GPIO_PULLUP)   || \
                                     ((__PULL__) == GPIO_PULLDOWN))





#include "stm32f3xx_hal_gpio_ex.h"












void              HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void              HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);










GPIO_PinState     HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void              HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void              HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void              HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void              HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

















#ifdef __cplusplus
}
#endif

#endif



