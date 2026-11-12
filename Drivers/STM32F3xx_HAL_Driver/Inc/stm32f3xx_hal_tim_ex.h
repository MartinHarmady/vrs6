



































#ifndef __STM32F3xx_HAL_TIM_EX_H
#define __STM32F3xx_HAL_TIM_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"


















typedef struct
{

  uint32_t IC1Polarity;


  uint32_t IC1Prescaler;


  uint32_t IC1Filter;

  uint32_t Commutation_Delay;

} TIM_HallSensor_InitTypeDef;

#if defined(STM32F373xC) || defined(STM32F378xx)





typedef struct {
  uint32_t  MasterOutputTrigger;

  uint32_t  MasterSlaveMode;

}TIM_MasterConfigTypeDef;





typedef struct
{
  uint32_t OffStateRunMode;

  uint32_t OffStateIDLEMode;

  uint32_t LockLevel;

  uint32_t DeadTime;

  uint32_t BreakState;

  uint32_t BreakPolarity;

  uint32_t AutomaticOutput;

} TIM_BreakDeadTimeConfigTypeDef;

#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)





typedef struct
{
  uint32_t OffStateRunMode;

  uint32_t OffStateIDLEMode;

  uint32_t LockLevel;

  uint32_t DeadTime;

  uint32_t BreakState;

  uint32_t BreakPolarity;

  uint32_t BreakFilter;

  uint32_t Break2State;

  uint32_t Break2Polarity;

  uint32_t Break2Filter;

  uint32_t AutomaticOutput;

} TIM_BreakDeadTimeConfigTypeDef;






typedef struct {
  uint32_t  MasterOutputTrigger;

  uint32_t  MasterOutputTrigger2;

  uint32_t  MasterSlaveMode;

}TIM_MasterConfigTypeDef;
#endif












#if defined(STM32F373xC) || defined(STM32F378xx)



#define TIM_CHANNEL_1                      (0x0000U)
#define TIM_CHANNEL_2                      (0x0004U)
#define TIM_CHANNEL_3                      (0x0008U)
#define TIM_CHANNEL_4                      (0x000CU)
#define TIM_CHANNEL_ALL                    (0x0018U)







#define TIM_OCMODE_TIMING                   (0x0000U)
#define TIM_OCMODE_ACTIVE                   ((uint32_t)TIM_CCMR1_OC1M_0)
#define TIM_OCMODE_INACTIVE                 ((uint32_t)TIM_CCMR1_OC1M_1)
#define TIM_OCMODE_TOGGLE                   ((uint32_t)TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1)
#define TIM_OCMODE_PWM1                     ((uint32_t)TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2)
#define TIM_OCMODE_PWM2                     ((uint32_t)TIM_CCMR1_OC1M)
#define TIM_OCMODE_FORCED_ACTIVE            ((uint32_t)TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_2)
#define TIM_OCMODE_FORCED_INACTIVE          ((uint32_t)TIM_CCMR1_OC1M_2)







#define TIM_CLEARINPUTSOURCE_ETR           (0x0001U)
#define TIM_CLEARINPUTSOURCE_NONE          (0x0000U)







#define TIM_SLAVEMODE_DISABLE                (0x0000U)
#define TIM_SLAVEMODE_RESET                  ((uint32_t)(TIM_SMCR_SMS_2))
#define TIM_SLAVEMODE_GATED                  ((uint32_t)(TIM_SMCR_SMS_2 | TIM_SMCR_SMS_0))
#define TIM_SLAVEMODE_TRIGGER                ((uint32_t)(TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1))
#define TIM_SLAVEMODE_EXTERNAL1              ((uint32_t)(TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0))







#define TIM_EVENTSOURCE_UPDATE              TIM_EGR_UG
#define TIM_EVENTSOURCE_CC1                 TIM_EGR_CC1G
#define TIM_EVENTSOURCE_CC2                 TIM_EGR_CC2G
#define TIM_EVENTSOURCE_CC3                 TIM_EGR_CC3G
#define TIM_EVENTSOURCE_CC4                 TIM_EGR_CC4G
#define TIM_EVENTSOURCE_COM                 TIM_EGR_COMG
#define TIM_EVENTSOURCE_TRIGGER             TIM_EGR_TG
#define TIM_EVENTSOURCE_BREAK               TIM_EGR_BG







#define TIM_DMABASE_CR1                    (0x00000000U)
#define TIM_DMABASE_CR2                    (0x00000001U)
#define TIM_DMABASE_SMCR                   (0x00000002U)
#define TIM_DMABASE_DIER                   (0x00000003U)
#define TIM_DMABASE_SR                     (0x00000004U)
#define TIM_DMABASE_EGR                    (0x00000005U)
#define TIM_DMABASE_CCMR1                  (0x00000006U)
#define TIM_DMABASE_CCMR2                  (0x00000007U)
#define TIM_DMABASE_CCER                   (0x00000008U)
#define TIM_DMABASE_CNT                    (0x00000009U)
#define TIM_DMABASE_PSC                    (0x0000000AU)
#define TIM_DMABASE_ARR                    (0x0000000BU)
#define TIM_DMABASE_RCR                    (0x0000000CU)
#define TIM_DMABASE_CCR1                   (0x0000000DU)
#define TIM_DMABASE_CCR2                   (0x0000000EU)
#define TIM_DMABASE_CCR3                   (0x0000000FU)
#define TIM_DMABASE_CCR4                   (0x00000010U)
#define TIM_DMABASE_BDTR                   (0x00000011U)
#define TIM_DMABASE_DCR                    (0x00000012U)
#define TIM_DMABASE_OR                     (0x00000013U)



#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)



#define TIM_CHANNEL_1                      (0x0000U)
#define TIM_CHANNEL_2                      (0x0004U)
#define TIM_CHANNEL_3                      (0x0008U)
#define TIM_CHANNEL_4                      (0x000CU)
#define TIM_CHANNEL_5                      (0x0010U)
#define TIM_CHANNEL_6                      (0x0014U)
#define TIM_CHANNEL_ALL                    (0x003CU)







#define TIM_OCMODE_TIMING                   (0x0000U)
#define TIM_OCMODE_ACTIVE                   ((uint32_t)TIM_CCMR1_OC1M_0)
#define TIM_OCMODE_INACTIVE                 ((uint32_t)TIM_CCMR1_OC1M_1)
#define TIM_OCMODE_TOGGLE                   ((uint32_t)TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0)
#define TIM_OCMODE_PWM1                     ((uint32_t)TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1)
#define TIM_OCMODE_PWM2                     ((uint32_t)TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0)
#define TIM_OCMODE_FORCED_ACTIVE            ((uint32_t)TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0)
#define TIM_OCMODE_FORCED_INACTIVE          ((uint32_t)TIM_CCMR1_OC1M_2)

#define TIM_OCMODE_RETRIGERRABLE_OPM1      ((uint32_t)TIM_CCMR1_OC1M_3)
#define TIM_OCMODE_RETRIGERRABLE_OPM2      ((uint32_t)TIM_CCMR1_OC1M_3 | TIM_CCMR1_OC1M_0)
#define TIM_OCMODE_COMBINED_PWM1           ((uint32_t)TIM_CCMR1_OC1M_3 | TIM_CCMR1_OC1M_2)
#define TIM_OCMODE_COMBINED_PWM2           ((uint32_t)TIM_CCMR1_OC1M_3 | TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_2)
#define TIM_OCMODE_ASSYMETRIC_PWM1         ((uint32_t)TIM_CCMR1_OC1M_3 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2)
#define TIM_OCMODE_ASSYMETRIC_PWM2         ((uint32_t)TIM_CCMR1_OC1M_3 | TIM_CCMR1_OC1M)








#define TIM_CLEARINPUTSOURCE_ETR            (0x0001U)
#define TIM_CLEARINPUTSOURCE_OCREFCLR       (0x0002U)
#define TIM_CLEARINPUTSOURCE_NONE           (0x0000U)







#define TIM_BREAK2_DISABLE         (0x00000000U)
#define TIM_BREAK2_ENABLE          ((uint32_t)TIM_BDTR_BK2E)







#define TIM_BREAK2POLARITY_LOW        (0x00000000U)
#define TIM_BREAK2POLARITY_HIGH       ((uint32_t)TIM_BDTR_BK2P)







#define  TIM_TRGO2_RESET                          (0x00000000U)
#define  TIM_TRGO2_ENABLE                         ((uint32_t)(TIM_CR2_MMS2_0))
#define  TIM_TRGO2_UPDATE                         ((uint32_t)(TIM_CR2_MMS2_1))
#define  TIM_TRGO2_OC1                            ((uint32_t)(TIM_CR2_MMS2_1 | TIM_CR2_MMS2_0))
#define  TIM_TRGO2_OC1REF                         ((uint32_t)(TIM_CR2_MMS2_2))
#define  TIM_TRGO2_OC2REF                         ((uint32_t)(TIM_CR2_MMS2_2 | TIM_CR2_MMS2_0))
#define  TIM_TRGO2_OC3REF                         ((uint32_t)(TIM_CR2_MMS2_2 | TIM_CR2_MMS2_1))
#define  TIM_TRGO2_OC4REF                         ((uint32_t)(TIM_CR2_MMS2_2 | TIM_CR2_MMS2_1 | TIM_CR2_MMS2_0))
#define  TIM_TRGO2_OC5REF                         ((uint32_t)(TIM_CR2_MMS2_3))
#define  TIM_TRGO2_OC6REF                         ((uint32_t)(TIM_CR2_MMS2_3 | TIM_CR2_MMS2_0))
#define  TIM_TRGO2_OC4REF_RISINGFALLING           ((uint32_t)(TIM_CR2_MMS2_3 | TIM_CR2_MMS2_1))
#define  TIM_TRGO2_OC6REF_RISINGFALLING           ((uint32_t)(TIM_CR2_MMS2_3 | TIM_CR2_MMS2_1 | TIM_CR2_MMS2_0))
#define  TIM_TRGO2_OC4REF_RISING_OC6REF_RISING    ((uint32_t)(TIM_CR2_MMS2_3 | TIM_CR2_MMS2_2))
#define  TIM_TRGO2_OC4REF_RISING_OC6REF_FALLING   ((uint32_t)(TIM_CR2_MMS2_3 | TIM_CR2_MMS2_2 | TIM_CR2_MMS2_0))
#define  TIM_TRGO2_OC5REF_RISING_OC6REF_RISING    ((uint32_t)(TIM_CR2_MMS2_3 | TIM_CR2_MMS2_2 |TIM_CR2_MMS2_1))
#define  TIM_TRGO2_OC5REF_RISING_OC6REF_FALLING   ((uint32_t)(TIM_CR2_MMS2_3 | TIM_CR2_MMS2_2 | TIM_CR2_MMS2_1 | TIM_CR2_MMS2_0))







#define TIM_SLAVEMODE_DISABLE                (0x0000U)
#define TIM_SLAVEMODE_RESET                  ((uint32_t)(TIM_SMCR_SMS_2))
#define TIM_SLAVEMODE_GATED                  ((uint32_t)(TIM_SMCR_SMS_2 | TIM_SMCR_SMS_0))
#define TIM_SLAVEMODE_TRIGGER                ((uint32_t)(TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1))
#define TIM_SLAVEMODE_EXTERNAL1              ((uint32_t)(TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0))
#define TIM_SLAVEMODE_COMBINED_RESETTRIGGER  ((uint32_t)(TIM_SMCR_SMS_3))







#define TIM_EVENTSOURCE_UPDATE              TIM_EGR_UG
#define TIM_EVENTSOURCE_CC1                 TIM_EGR_CC1G
#define TIM_EVENTSOURCE_CC2                 TIM_EGR_CC2G
#define TIM_EVENTSOURCE_CC3                 TIM_EGR_CC3G
#define TIM_EVENTSOURCE_CC4                 TIM_EGR_CC4G
#define TIM_EVENTSOURCE_COM                 TIM_EGR_COMG
#define TIM_EVENTSOURCE_TRIGGER             TIM_EGR_TG
#define TIM_EVENTSOURCE_BREAK               TIM_EGR_BG
#define TIM_EVENTSOURCE_BREAK2              TIM_EGR_B2G







#define TIM_DMABASE_CR1                    (0x00000000U)
#define TIM_DMABASE_CR2                    (0x00000001U)
#define TIM_DMABASE_SMCR                   (0x00000002U)
#define TIM_DMABASE_DIER                   (0x00000003U)
#define TIM_DMABASE_SR                     (0x00000004U)
#define TIM_DMABASE_EGR                    (0x00000005U)
#define TIM_DMABASE_CCMR1                  (0x00000006U)
#define TIM_DMABASE_CCMR2                  (0x00000007U)
#define TIM_DMABASE_CCER                   (0x00000008U)
#define TIM_DMABASE_CNT                    (0x00000009U)
#define TIM_DMABASE_PSC                    (0x0000000AU)
#define TIM_DMABASE_ARR                    (0x0000000BU)
#define TIM_DMABASE_RCR                    (0x0000000CU)
#define TIM_DMABASE_CCR1                   (0x0000000DU)
#define TIM_DMABASE_CCR2                   (0x0000000EU)
#define TIM_DMABASE_CCR3                   (0x0000000FU)
#define TIM_DMABASE_CCR4                   (0x00000010U)
#define TIM_DMABASE_BDTR                   (0x00000011U)
#define TIM_DMABASE_DCR                    (0x00000012U)
#define TIM_DMABASE_CCMR3                  (0x00000015U)
#define TIM_DMABASE_CCR5                   (0x00000016U)
#define TIM_DMABASE_CCR6                   (0x00000017U)
#define TIM_DMABASE_OR                     (0x00000018U)



#endif




#if defined(STM32F302xE)                                                 || \
    defined(STM32F302xC)                                                 || \
    defined(STM32F303x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)



#define TIM_TIM1_ADC1_NONE                     (0x00000000U)
#define TIM_TIM1_ADC1_AWD1                     (0x00000001U)
#define TIM_TIM1_ADC1_AWD2                     (0x00000002U)
#define TIM_TIM1_ADC1_AWD3                     (0x00000003U)
#define TIM_TIM16_GPIO                         (0x00000000U)
#define TIM_TIM16_RTC                          (0x00000001U)
#define TIM_TIM16_HSE                          (0x00000002U)
#define TIM_TIM16_MCO                          (0x00000003U)



#endif





#if defined(STM32F334x8)



#define TIM_TIM1_ADC1_NONE                     (0x00000000U)
#define TIM_TIM1_ADC1_AWD1                     (0x00000001U)
#define TIM_TIM1_ADC1_AWD2                     (0x00000002U)
#define TIM_TIM1_ADC1_AWD3                     (0x00000003U)
#define TIM_TIM16_GPIO                         (0x00000000U)
#define TIM_TIM16_RTC                          (0x00000001U)
#define TIM_TIM16_HSE                          (0x00000002U)
#define TIM_TIM16_MCO                          (0x00000003U)







#define TIM_TIM1_ADC2_NONE                     (0x00000000U)
#define TIM_TIM1_ADC2_AWD1                     (0x00000004U)
#define TIM_TIM1_ADC2_AWD2                     (0x00000008U)
#define TIM_TIM1_ADC2_AWD3                     (0x0000000CU)
#define TIM_TIM16_NONE                         (0x00000000U)



#endif

#if defined(STM32F303xC) || defined(STM32F358xx)



#define TIM_TIM1_ADC1_NONE                     (0x00000000U)
#define TIM_TIM1_ADC1_AWD1                     (0x00000001U)
#define TIM_TIM1_ADC1_AWD2                     (0x00000002U)
#define TIM_TIM1_ADC1_AWD3                     (0x00000003U)
#define TIM_TIM8_ADC2_NONE                     (0x00000000U)
#define TIM_TIM8_ADC2_AWD1                     (0x00000001U)
#define TIM_TIM8_ADC2_AWD2                     (0x00000002U)
#define TIM_TIM8_ADC2_AWD3                     (0x00000003U)
#define TIM_TIM16_GPIO                         (0x00000000U)
#define TIM_TIM16_RTC                          (0x00000001U)
#define TIM_TIM16_HSE                          (0x00000002U)
#define TIM_TIM16_MCO                          (0x00000003U)







#define TIM_TIM1_ADC4_NONE                     (0x00000000U)
#define TIM_TIM1_ADC4_AWD1                     (0x00000004U)
#define TIM_TIM1_ADC4_AWD2                     (0x00000008U)
#define TIM_TIM1_ADC4_AWD3                     (0x0000000CU)
#define TIM_TIM8_ADC3_NONE                     (0x00000000U)
#define TIM_TIM8_ADC3_AWD1                     (0x00000004U)
#define TIM_TIM8_ADC3_AWD2                     (0x00000008U)
#define TIM_TIM8_ADC3_AWD3                     (0x0000000CU)
#define TIM_TIM16_NONE                         (0x00000000U)



#endif

#if defined(STM32F303xE) || defined(STM32F398xx)



#define TIM_TIM1_ADC1_NONE                     (0x00000000U)
#define TIM_TIM1_ADC1_AWD1                     (0x00000001U)
#define TIM_TIM1_ADC1_AWD2                     (0x00000002U)
#define TIM_TIM1_ADC1_AWD3                     (0x00000003U)
#define TIM_TIM8_ADC2_NONE                     (0x00000000U)
#define TIM_TIM8_ADC2_AWD1                     (0x00000001U)
#define TIM_TIM8_ADC2_AWD2                     (0x00000002U)
#define TIM_TIM8_ADC2_AWD3                     (0x00000003U)
#define TIM_TIM16_GPIO                         (0x00000000U)
#define TIM_TIM16_RTC                          (0x00000001U)
#define TIM_TIM16_HSE                          (0x00000002U)
#define TIM_TIM16_MCO                          (0x00000003U)
#define TIM_TIM20_ADC3_NONE                    (0x00000000U)
#define TIM_TIM20_ADC3_AWD1                    (0x00000001U)
#define TIM_TIM20_ADC3_AWD2                    (0x00000002U)
#define TIM_TIM20_ADC3_AWD3                    (0x00000003U)







#define TIM_TIM1_ADC4_NONE                     (0x00000000U)
#define TIM_TIM1_ADC4_AWD1                     (0x00000004U)
#define TIM_TIM1_ADC4_AWD2                     (0x00000008U)
#define TIM_TIM1_ADC4_AWD3                     (0x0000000CU)
#define TIM_TIM8_ADC3_NONE                     (0x00000000U)
#define TIM_TIM8_ADC3_AWD1                     (0x00000004U)
#define TIM_TIM8_ADC3_AWD2                     (0x00000008U)
#define TIM_TIM8_ADC3_AWD3                     (0x0000000CU)
#define TIM_TIM16_NONE                         (0x00000000U)
#define TIM_TIM20_ADC4_NONE                    (0x00000000U)
#define TIM_TIM20_ADC4_AWD1                    (0x00000004U)
#define TIM_TIM20_ADC4_AWD2                    (0x00000008U)
#define TIM_TIM20_ADC4_AWD3                    (0x0000000CU)



#endif


#if defined(STM32F373xC) || defined(STM32F378xx)



#define TIM_TIM2_TIM8_TRGO      (0x00000000U)
#define TIM_TIM2_ETH_PTP        (0x00000400U)
#define TIM_TIM2_USBFS_SOF      (0x00000800U)
#define TIM_TIM2_USBHS_SOF      (0x00000C00U)
#define TIM_TIM14_GPIO          (0x00000000U)
#define TIM_TIM14_RTC           (0x00000001U)
#define TIM_TIM14_HSE           (0x00000002U)
#define TIM_TIM14_MCO           (0x00000003U)



#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)



#define TIM_GROUPCH5_NONE       0x00000000
#define TIM_GROUPCH5_OC1REFC    (TIM_CCR5_GC5C1)
#define TIM_GROUPCH5_OC2REFC    (TIM_CCR5_GC5C2)
#define TIM_GROUPCH5_OC3REFC    (TIM_CCR5_GC5C3)



#endif













#if defined(STM32F373xC) || defined(STM32F378xx)

#define IS_TIM_CHANNELS(CHANNEL) (((CHANNEL) == TIM_CHANNEL_1) || \
                                  ((CHANNEL) == TIM_CHANNEL_2) || \
                                  ((CHANNEL) == TIM_CHANNEL_3) || \
                                  ((CHANNEL) == TIM_CHANNEL_4) || \
                                  ((CHANNEL) == TIM_CHANNEL_ALL))

#define IS_TIM_OPM_CHANNELS(CHANNEL) (((CHANNEL) == TIM_CHANNEL_1) || \
                                      ((CHANNEL) == TIM_CHANNEL_2))

#define IS_TIM_COMPLEMENTARY_CHANNELS(CHANNEL) (((CHANNEL) == TIM_CHANNEL_1) || \
                                                ((CHANNEL) == TIM_CHANNEL_2) || \
                                                ((CHANNEL) == TIM_CHANNEL_3))

#define IS_TIM_PWM_MODE(MODE) (((MODE) == TIM_OCMODE_PWM1) || \
	                       ((MODE) == TIM_OCMODE_PWM2))

#define IS_TIM_OC_MODE(MODE) (((MODE) == TIM_OCMODE_TIMING)           || \
                              ((MODE) == TIM_OCMODE_ACTIVE)           || \
                              ((MODE) == TIM_OCMODE_INACTIVE)         || \
                              ((MODE) == TIM_OCMODE_TOGGLE)           || \
                              ((MODE) == TIM_OCMODE_FORCED_ACTIVE)    || \
                              ((MODE) == TIM_OCMODE_FORCED_INACTIVE))

#define IS_TIM_CLEARINPUT_SOURCE(SOURCE)  (((SOURCE) == TIM_CLEARINPUTSOURCE_NONE) || \
                                           ((SOURCE) == TIM_CLEARINPUTSOURCE_ETR))

#define IS_TIM_SLAVE_MODE(MODE) (((MODE) == TIM_SLAVEMODE_DISABLE) || \
                                 ((MODE) == TIM_SLAVEMODE_RESET) || \
                                 ((MODE) == TIM_SLAVEMODE_GATED) || \
                                 ((MODE) == TIM_SLAVEMODE_TRIGGER) || \
                                 ((MODE) == TIM_SLAVEMODE_EXTERNAL1))

#define IS_TIM_EVENT_SOURCE(SOURCE) ((((SOURCE) & 0xFFFFFF00U) == 0x00000000U) && ((SOURCE) != 0x00000000U))

#define IS_TIM_DMA_BASE(BASE) (((BASE) == TIM_DMABASE_CR1) || \
                               ((BASE) == TIM_DMABASE_CR2) || \
                               ((BASE) == TIM_DMABASE_SMCR) || \
                               ((BASE) == TIM_DMABASE_DIER) || \
                               ((BASE) == TIM_DMABASE_SR) || \
                               ((BASE) == TIM_DMABASE_EGR) || \
                               ((BASE) == TIM_DMABASE_CCMR1) || \
                               ((BASE) == TIM_DMABASE_CCMR2) || \
                               ((BASE) == TIM_DMABASE_CCER) || \
                               ((BASE) == TIM_DMABASE_CNT) || \
                               ((BASE) == TIM_DMABASE_PSC) || \
                               ((BASE) == TIM_DMABASE_ARR) || \
                               ((BASE) == TIM_DMABASE_RCR) || \
                               ((BASE) == TIM_DMABASE_CCR1) || \
                               ((BASE) == TIM_DMABASE_CCR2) || \
                               ((BASE) == TIM_DMABASE_CCR3) || \
                               ((BASE) == TIM_DMABASE_CCR4) || \
                               ((BASE) == TIM_DMABASE_BDTR) || \
                               ((BASE) == TIM_DMABASE_DCR) || \
                               ((BASE) == TIM_DMABASE_OR))

#endif



#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

#define IS_TIM_CHANNELS(CHANNEL) (((CHANNEL) == TIM_CHANNEL_1) || \
                                  ((CHANNEL) == TIM_CHANNEL_2) || \
                                  ((CHANNEL) == TIM_CHANNEL_3) || \
                                  ((CHANNEL) == TIM_CHANNEL_4) || \
                                  ((CHANNEL) == TIM_CHANNEL_5) || \
                                  ((CHANNEL) == TIM_CHANNEL_6) || \
                                  ((CHANNEL) == TIM_CHANNEL_ALL))

#define IS_TIM_OPM_CHANNELS(CHANNEL) (((CHANNEL) == TIM_CHANNEL_1) || \
                                      ((CHANNEL) == TIM_CHANNEL_2))

#define IS_TIM_COMPLEMENTARY_CHANNELS(CHANNEL) (((CHANNEL) == TIM_CHANNEL_1) || \
                                                ((CHANNEL) == TIM_CHANNEL_2) || \
                                                ((CHANNEL) == TIM_CHANNEL_3))

#define IS_TIM_PWM_MODE(MODE) (((MODE) == TIM_OCMODE_PWM1)               || \
	                       ((MODE) == TIM_OCMODE_PWM2)               || \
                               ((MODE) == TIM_OCMODE_COMBINED_PWM1)      || \
                               ((MODE) == TIM_OCMODE_COMBINED_PWM2)      || \
                               ((MODE) == TIM_OCMODE_ASSYMETRIC_PWM1)    || \
                               ((MODE) == TIM_OCMODE_ASSYMETRIC_PWM2))

#define IS_TIM_OC_MODE(MODE) (((MODE) == TIM_OCMODE_TIMING)             || \
                             ((MODE) == TIM_OCMODE_ACTIVE)             || \
                             ((MODE) == TIM_OCMODE_INACTIVE)           || \
                             ((MODE) == TIM_OCMODE_TOGGLE)             || \
                             ((MODE) == TIM_OCMODE_FORCED_ACTIVE)      || \
                             ((MODE) == TIM_OCMODE_FORCED_INACTIVE)    || \
                             ((MODE) == TIM_OCMODE_RETRIGERRABLE_OPM1) || \
                             ((MODE) == TIM_OCMODE_RETRIGERRABLE_OPM2))

#define IS_TIM_CLEARINPUT_SOURCE(MODE) (((MODE) == TIM_CLEARINPUTSOURCE_ETR)      || \
                                        ((MODE) == TIM_CLEARINPUTSOURCE_OCREFCLR)  || \
                                        ((MODE) == TIM_CLEARINPUTSOURCE_NONE))

#define IS_TIM_BREAK_FILTER(BRKFILTER) ((BRKFILTER) <= 0xFU)

#define IS_TIM_BREAK2_STATE(STATE) (((STATE) == TIM_BREAK2_ENABLE) || \
                                    ((STATE) == TIM_BREAK2_DISABLE))

#define IS_TIM_BREAK2_POLARITY(POLARITY) (((POLARITY) == TIM_BREAK2POLARITY_LOW) || \
                                          ((POLARITY) == TIM_BREAK2POLARITY_HIGH))

#define IS_TIM_TRGO2_SOURCE(SOURCE) (((SOURCE) == TIM_TRGO2_RESET)                        || \
                                     ((SOURCE) == TIM_TRGO2_ENABLE)                       || \
                                     ((SOURCE) == TIM_TRGO2_UPDATE)                       || \
                                     ((SOURCE) == TIM_TRGO2_OC1)                          || \
                                     ((SOURCE) == TIM_TRGO2_OC1REF)                       || \
                                     ((SOURCE) == TIM_TRGO2_OC2REF)                       || \
                                     ((SOURCE) == TIM_TRGO2_OC3REF)                       || \
                                     ((SOURCE) == TIM_TRGO2_OC3REF)                       || \
                                     ((SOURCE) == TIM_TRGO2_OC4REF)                       || \
                                     ((SOURCE) == TIM_TRGO2_OC5REF)                       || \
                                     ((SOURCE) == TIM_TRGO2_OC6REF)                       || \
                                     ((SOURCE) == TIM_TRGO2_OC4REF_RISINGFALLING)         || \
                                     ((SOURCE) == TIM_TRGO2_OC6REF_RISINGFALLING)         || \
                                     ((SOURCE) == TIM_TRGO2_OC4REF_RISING_OC6REF_RISING)  || \
                                     ((SOURCE) == TIM_TRGO2_OC4REF_RISING_OC6REF_FALLING) || \
                                     ((SOURCE) == TIM_TRGO2_OC5REF_RISING_OC6REF_RISING)  || \
                                     ((SOURCE) == TIM_TRGO2_OC5REF_RISING_OC6REF_FALLING))

#define IS_TIM_SLAVE_MODE(MODE) (((MODE) == TIM_SLAVEMODE_DISABLE)   || \
                                 ((MODE) == TIM_SLAVEMODE_RESET)     || \
                                 ((MODE) == TIM_SLAVEMODE_GATED)     || \
                                 ((MODE) == TIM_SLAVEMODE_TRIGGER)   || \
                                 ((MODE) == TIM_SLAVEMODE_EXTERNAL1) || \
                                 ((MODE) == TIM_SLAVEMODE_COMBINED_RESETTRIGGER))

#define IS_TIM_EVENT_SOURCE(SOURCE) ((((SOURCE) & 0xFFFFFE00U) == 0x00000000U) && ((SOURCE) != 0x00000000U))

#define IS_TIM_DMA_BASE(BASE) (((BASE) == TIM_DMABASE_CR1)   || \
                               ((BASE) == TIM_DMABASE_CR2)   || \
                               ((BASE) == TIM_DMABASE_SMCR)  || \
                               ((BASE) == TIM_DMABASE_DIER)  || \
                               ((BASE) == TIM_DMABASE_SR)    || \
                               ((BASE) == TIM_DMABASE_EGR)   || \
                               ((BASE) == TIM_DMABASE_CCMR1) || \
                               ((BASE) == TIM_DMABASE_CCMR2) || \
                               ((BASE) == TIM_DMABASE_CCER)  || \
                               ((BASE) == TIM_DMABASE_CNT)   || \
                               ((BASE) == TIM_DMABASE_PSC)   || \
                               ((BASE) == TIM_DMABASE_ARR)   || \
                               ((BASE) == TIM_DMABASE_RCR)   || \
                               ((BASE) == TIM_DMABASE_CCR1)  || \
                               ((BASE) == TIM_DMABASE_CCR2)  || \
                               ((BASE) == TIM_DMABASE_CCR3)  || \
                               ((BASE) == TIM_DMABASE_CCR4)  || \
                               ((BASE) == TIM_DMABASE_BDTR)  || \
                               ((BASE) == TIM_DMABASE_CCMR3) || \
                               ((BASE) == TIM_DMABASE_CCR5)  || \
                               ((BASE) == TIM_DMABASE_CCR6)  || \
                               ((BASE) == TIM_DMABASE_OR))

#endif




#if defined(STM32F302xE)                                                 || \
    defined(STM32F302xC)                                                 || \
    defined(STM32F303x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

#define IS_TIM_REMAP(REMAP)    (((REMAP) == TIM_TIM1_ADC1_NONE) ||\
                                ((REMAP) == TIM_TIM1_ADC1_AWD1) ||\
                                ((REMAP) == TIM_TIM1_ADC1_AWD2) ||\
                                ((REMAP) == TIM_TIM1_ADC1_AWD3) ||\
                                ((REMAP) == TIM_TIM16_GPIO)     ||\
                                ((REMAP) == TIM_TIM16_RTC)      ||\
                                ((REMAP) == TIM_TIM16_HSE)      ||\
                                ((REMAP) == TIM_TIM16_MCO))

#endif




#if defined(STM32F334x8)
#define IS_TIM_REMAP(REMAP1)   (((REMAP1) == TIM_TIM1_ADC1_NONE) ||\
                                ((REMAP1) == TIM_TIM1_ADC1_AWD1) ||\
                                ((REMAP1) == TIM_TIM1_ADC1_AWD2) ||\
                                ((REMAP1) == TIM_TIM1_ADC1_AWD3) ||\
                                ((REMAP1) == TIM_TIM16_GPIO)     ||\
                                ((REMAP1) == TIM_TIM16_RTC)      ||\
                                ((REMAP1) == TIM_TIM16_HSE)      ||\
                                ((REMAP1) == TIM_TIM16_MCO))

#define IS_TIM_REMAP2(REMAP2)  (((REMAP2) == TIM_TIM1_ADC2_NONE) ||\
                                ((REMAP2) == TIM_TIM1_ADC2_AWD1) ||\
                                ((REMAP2) == TIM_TIM1_ADC2_AWD2) ||\
                                ((REMAP2) == TIM_TIM1_ADC2_AWD3) ||\
                                ((REMAP2) == TIM_TIM16_NONE))

#endif

#if defined(STM32F303xC) || defined(STM32F358xx)

#define IS_TIM_REMAP(REMAP1)   (((REMAP1) == TIM_TIM1_ADC1_NONE) ||\
                                ((REMAP1) == TIM_TIM1_ADC1_AWD1) ||\
                                ((REMAP1) == TIM_TIM1_ADC1_AWD2) ||\
                                ((REMAP1) == TIM_TIM1_ADC1_AWD3) ||\
                                ((REMAP1) == TIM_TIM8_ADC2_NONE) ||\
                                ((REMAP1) == TIM_TIM8_ADC2_AWD1) ||\
                                ((REMAP1) == TIM_TIM8_ADC2_AWD2) ||\
                                ((REMAP1) == TIM_TIM8_ADC2_AWD3) ||\
                                ((REMAP1) == TIM_TIM16_GPIO)     ||\
                                ((REMAP1) == TIM_TIM16_RTC)      ||\
                                ((REMAP1) == TIM_TIM16_HSE)      ||\
                                ((REMAP1) == TIM_TIM16_MCO))

#define IS_TIM_REMAP2(REMAP2)  (((REMAP2) == TIM_TIM1_ADC4_NONE) ||\
                                ((REMAP2) == TIM_TIM1_ADC4_AWD1) ||\
                                ((REMAP2) == TIM_TIM1_ADC4_AWD2) ||\
                                ((REMAP2) == TIM_TIM1_ADC4_AWD3) ||\
                                ((REMAP2) == TIM_TIM8_ADC3_NONE) ||\
                                ((REMAP2) == TIM_TIM8_ADC3_AWD1) ||\
                                ((REMAP2) == TIM_TIM8_ADC3_AWD2) ||\
                                ((REMAP2) == TIM_TIM8_ADC3_AWD3) ||\
                                ((REMAP2) == TIM_TIM16_NONE))

#endif

#if defined(STM32F303xE) || defined(STM32F398xx)

#define IS_TIM_REMAP(REMAP1)   (((REMAP1) == TIM_TIM1_ADC1_NONE) ||\
                                ((REMAP1) == TIM_TIM1_ADC1_AWD1) ||\
                                ((REMAP1) == TIM_TIM1_ADC1_AWD2) ||\
                                ((REMAP1) == TIM_TIM1_ADC1_AWD3) ||\
                                ((REMAP1) == TIM_TIM8_ADC2_NONE) ||\
                                ((REMAP1) == TIM_TIM8_ADC2_AWD1) ||\
                                ((REMAP1) == TIM_TIM8_ADC2_AWD2) ||\
                                ((REMAP1) == TIM_TIM8_ADC2_AWD3) ||\
                                ((REMAP1) == TIM_TIM16_GPIO)     ||\
                                ((REMAP1) == TIM_TIM16_RTC)      ||\
                                ((REMAP1) == TIM_TIM16_HSE)      ||\
                                ((REMAP1) == TIM_TIM16_MCO)      ||\
                                ((REMAP1) == TIM_TIM20_ADC3_NONE) ||\
                                ((REMAP1) == TIM_TIM20_ADC3_AWD1) ||\
                                ((REMAP1) == TIM_TIM20_ADC3_AWD2) ||\
                                ((REMAP1) == TIM_TIM20_ADC3_AWD3))

#define IS_TIM_REMAP2(REMAP2)  (((REMAP2) == TIM_TIM1_ADC4_NONE)  ||\
                                ((REMAP2) == TIM_TIM1_ADC4_AWD1)  ||\
                                ((REMAP2) == TIM_TIM1_ADC4_AWD2)  ||\
                                ((REMAP2) == TIM_TIM1_ADC4_AWD3)  ||\
                                ((REMAP2) == TIM_TIM8_ADC3_NONE)  ||\
                                ((REMAP2) == TIM_TIM8_ADC3_AWD1)  ||\
                                ((REMAP2) == TIM_TIM8_ADC3_AWD2)  ||\
                                ((REMAP2) == TIM_TIM8_ADC3_AWD3)  ||\
                                ((REMAP2) == TIM_TIM16_NONE)      ||\
                                ((REMAP2) == TIM_TIM20_ADC4_NONE) ||\
                                ((REMAP2) == TIM_TIM20_ADC4_AWD1) ||\
                                ((REMAP2) == TIM_TIM20_ADC4_AWD2) ||\
                                ((REMAP2) == TIM_TIM20_ADC4_AWD3))

#endif

#if defined(STM32F373xC) || defined(STM32F378xx)

#define IS_TIM_REMAP(REMAP)    (((REMAP) == TIM_TIM2_TIM8_TRGO)  ||\
                                ((REMAP) == TIM_TIM2_ETH_PTP)    ||\
                                ((REMAP) == TIM_TIM2_USBFS_SOF)  ||\
                                ((REMAP) == TIM_TIM2_USBHS_SOF)  ||\
                                ((REMAP) == TIM_TIM14_GPIO)      ||\
                                ((REMAP) == TIM_TIM14_RTC)       ||\
                                ((REMAP) == TIM_TIM14_HSE)       ||\
                                ((REMAP) == TIM_TIM14_MCO))

#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

#define IS_TIM_GROUPCH5(OCREF) ((((OCREF) & 0x1FFFFFFFU) == 0x00000000U))

#endif




#define IS_TIM_DEADTIME(DEADTIME)      ((DEADTIME) <= 0xFFU)












#if defined(STM32F373xC) || defined(STM32F378xx)













#define __HAL_TIM_SET_COMPARE(__HANDLE__, __CHANNEL__, __COMPARE__) \
(*(__IO uint32_t *)(&((__HANDLE__)->Instance->CCR1) + ((__CHANNEL__) >> 2U)) = (__COMPARE__))












#define __HAL_TIM_GET_COMPARE(__HANDLE__, __CHANNEL__) \
  (*(__IO uint32_t *)(&((__HANDLE__)->Instance->CCR1) + ((__CHANNEL__) >> 2U)))












#define __HAL_TIM_ENABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
        (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC1PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC2PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC3PE) :\
         ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC4PE))












#define __HAL_TIM_DISABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
        (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= (uint16_t)~TIM_CCMR1_OC1PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= (uint16_t)~TIM_CCMR1_OC2PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= (uint16_t)~TIM_CCMR2_OC3PE) :\
         ((__HANDLE__)->Instance->CCMR2 &= (uint16_t)~TIM_CCMR2_OC4PE))

#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)















#define __HAL_TIM_SET_COMPARE(__HANDLE__, __CHANNEL__, __COMPARE__) \
(((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1 = (__COMPARE__)) :\
 ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2 = (__COMPARE__)) :\
 ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3 = (__COMPARE__)) :\
 ((__CHANNEL__) == TIM_CHANNEL_4) ? ((__HANDLE__)->Instance->CCR4 = (__COMPARE__)) :\
 ((__CHANNEL__) == TIM_CHANNEL_5) ? ((__HANDLE__)->Instance->CCR5 = (__COMPARE__)) :\
 ((__HANDLE__)->Instance->CCR6 = (__COMPARE__)))














#define __HAL_TIM_GET_COMPARE(__HANDLE__, __CHANNEL__) \
(((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1) :\
 ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2) :\
 ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3) :\
 ((__CHANNEL__) == TIM_CHANNEL_4) ? ((__HANDLE__)->Instance->CCR4) :\
 ((__CHANNEL__) == TIM_CHANNEL_5) ? ((__HANDLE__)->Instance->CCR5) :\
 ((__HANDLE__)->Instance->CCR6))














#define __HAL_TIM_ENABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
        (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC1PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC2PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC3PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_4) ? ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC4PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_5) ? ((__HANDLE__)->Instance->CCMR3 |= TIM_CCMR3_OC5PE) :\
         ((__HANDLE__)->Instance->CCMR3 |= TIM_CCMR3_OC6PE))














#define __HAL_TIM_DISABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
        (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= (uint16_t)~TIM_CCMR1_OC1PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= (uint16_t)~TIM_CCMR1_OC2PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= (uint16_t)~TIM_CCMR2_OC3PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_4) ? ((__HANDLE__)->Instance->CCMR2 &= (uint16_t)~TIM_CCMR2_OC4PE) :\
         ((__CHANNEL__) == TIM_CHANNEL_5) ? ((__HANDLE__)->Instance->CCMR3 &= (uint16_t)~TIM_CCMR3_OC5PE) :\
         ((__HANDLE__)->Instance->CCMR3 &= (uint16_t)~TIM_CCMR3_OC6PE))

#endif
















HAL_StatusTypeDef HAL_TIMEx_HallSensor_Init(TIM_HandleTypeDef *htim, TIM_HallSensor_InitTypeDef* sConfig);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_DeInit(TIM_HandleTypeDef *htim);

void HAL_TIMEx_HallSensor_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIMEx_HallSensor_MspDeInit(TIM_HandleTypeDef *htim);


HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_IT(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_IT(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_DMA(TIM_HandleTypeDef *htim);









HAL_StatusTypeDef HAL_TIMEx_OCN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);


HAL_StatusTypeDef HAL_TIMEx_OCN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);


HAL_StatusTypeDef HAL_TIMEx_OCN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);









HAL_StatusTypeDef HAL_TIMEx_PWMN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);


HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);









HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);


HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);








HAL_StatusTypeDef HAL_TIMEx_ConfigCommutationEvent(TIM_HandleTypeDef *htim, uint32_t  InputTrigger, uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutationEvent_IT(TIM_HandleTypeDef *htim, uint32_t  InputTrigger, uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutationEvent_DMA(TIM_HandleTypeDef *htim, uint32_t  InputTrigger, uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_MasterConfigSynchronization(TIM_HandleTypeDef *htim, TIM_MasterConfigTypeDef * sMasterConfig);
HAL_StatusTypeDef HAL_TIMEx_ConfigBreakDeadTime(TIM_HandleTypeDef *htim, TIM_BreakDeadTimeConfigTypeDef *sBreakDeadTimeConfig);

#if defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F303xC) || defined(STM32F358xx) || defined(STM32F334x8)
HAL_StatusTypeDef HAL_TIMEx_RemapConfig(TIM_HandleTypeDef *htim, uint32_t Remap1, uint32_t Remap2);
#endif


#if defined(STM32F302xE)                                                 || \
    defined(STM32F302xC)                                                 || \
    defined(STM32F303x8)  || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) || \
    defined(STM32F373xC) || defined(STM32F378xx)
HAL_StatusTypeDef HAL_TIMEx_RemapConfig(TIM_HandleTypeDef *htim, uint32_t Remap);
#endif





#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
HAL_StatusTypeDef HAL_TIMEx_GroupChannel5(TIM_HandleTypeDef *htim, uint32_t Channels);
#endif











void HAL_TIMEx_CommutationCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_Break2Callback(TIM_HandleTypeDef *htim);








HAL_TIM_StateTypeDef HAL_TIMEx_HallSensor_GetState(TIM_HandleTypeDef *htim);













void TIMEx_DMACommutationCplt(DMA_HandleTypeDef *hdma);













#ifdef __cplusplus
}
#endif


#endif


