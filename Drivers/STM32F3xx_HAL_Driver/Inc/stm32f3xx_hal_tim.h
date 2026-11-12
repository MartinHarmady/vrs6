



































#ifndef __STM32F3xx_HAL_TIM_H
#define __STM32F3xx_HAL_TIM_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"
















typedef struct
{
  uint32_t Prescaler;


  uint32_t CounterMode;


  uint32_t Period;



  uint32_t ClockDivision;


  uint32_t RepetitionCounter;








  uint32_t AutoReloadPreload;

} TIM_Base_InitTypeDef;




typedef struct
{
  uint32_t OCMode;


  uint32_t Pulse;


  uint32_t OCPolarity;


  uint32_t OCNPolarity;



  uint32_t OCFastMode;




  uint32_t OCIdleState;



  uint32_t OCNIdleState;


} TIM_OC_InitTypeDef;




typedef struct
{
  uint32_t OCMode;


  uint32_t Pulse;


  uint32_t OCPolarity;


  uint32_t OCNPolarity;



  uint32_t OCIdleState;



  uint32_t OCNIdleState;



  uint32_t ICPolarity;


  uint32_t ICSelection;


  uint32_t ICFilter;

} TIM_OnePulse_InitTypeDef;





typedef struct
{
  uint32_t  ICPolarity;


  uint32_t ICSelection;


  uint32_t ICPrescaler;


  uint32_t ICFilter;

} TIM_IC_InitTypeDef;




typedef struct
{
  uint32_t EncoderMode;


  uint32_t IC1Polarity;


  uint32_t IC1Selection;


  uint32_t IC1Prescaler;


  uint32_t IC1Filter;


  uint32_t IC2Polarity;


  uint32_t IC2Selection;


  uint32_t IC2Prescaler;


  uint32_t IC2Filter;

} TIM_Encoder_InitTypeDef;





typedef struct
{
  uint32_t ClockSource;

  uint32_t ClockPolarity;

  uint32_t ClockPrescaler;

  uint32_t ClockFilter;

}TIM_ClockConfigTypeDef;




typedef struct
{
  uint32_t ClearInputState;

  uint32_t ClearInputSource;

  uint32_t ClearInputPolarity;

  uint32_t ClearInputPrescaler;

  uint32_t ClearInputFilter;

}TIM_ClearInputConfigTypeDef;




typedef struct {
  uint32_t  SlaveMode;

  uint32_t  InputTrigger;

  uint32_t  TriggerPolarity;

  uint32_t  TriggerPrescaler;

  uint32_t  TriggerFilter;


}TIM_SlaveConfigTypeDef;




typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,
  HAL_TIM_STATE_READY             = 0x01U,
  HAL_TIM_STATE_BUSY              = 0x02U,
  HAL_TIM_STATE_TIMEOUT           = 0x03U,
  HAL_TIM_STATE_ERROR             = 0x04
}HAL_TIM_StateTypeDef;




typedef enum
{
  HAL_TIM_ACTIVE_CHANNEL_1        = 0x01U,
  HAL_TIM_ACTIVE_CHANNEL_2        = 0x02U,
  HAL_TIM_ACTIVE_CHANNEL_3        = 0x04U,
  HAL_TIM_ACTIVE_CHANNEL_4        = 0x08U,
  HAL_TIM_ACTIVE_CHANNEL_CLEARED  = 0x00
}HAL_TIM_ActiveChannel;




typedef struct
{
  TIM_TypeDef              *Instance;
  TIM_Base_InitTypeDef     Init;
  HAL_TIM_ActiveChannel    Channel;
  DMA_HandleTypeDef        *hdma[7];

  HAL_LockTypeDef          Lock;
  __IO HAL_TIM_StateTypeDef   State;
}TIM_HandleTypeDef;














#define  TIM_INPUTCHANNELPOLARITY_RISING      (0x00000000U)
#define  TIM_INPUTCHANNELPOLARITY_FALLING     (TIM_CCER_CC1P)
#define  TIM_INPUTCHANNELPOLARITY_BOTHEDGE    (TIM_CCER_CC1P | TIM_CCER_CC1NP)







#define TIM_ETRPOLARITY_INVERTED              (TIM_SMCR_ETP)
#define TIM_ETRPOLARITY_NONINVERTED           (0x0000U)







#define TIM_ETRPRESCALER_DIV1                 (0x0000U)
#define TIM_ETRPRESCALER_DIV2                 (TIM_SMCR_ETPS_0)
#define TIM_ETRPRESCALER_DIV4                 (TIM_SMCR_ETPS_1)
#define TIM_ETRPRESCALER_DIV8                 (TIM_SMCR_ETPS)







#define TIM_COUNTERMODE_UP                 (0x0000U)
#define TIM_COUNTERMODE_DOWN               TIM_CR1_DIR
#define TIM_COUNTERMODE_CENTERALIGNED1     TIM_CR1_CMS_0
#define TIM_COUNTERMODE_CENTERALIGNED2     TIM_CR1_CMS_1
#define TIM_COUNTERMODE_CENTERALIGNED3     TIM_CR1_CMS







#define TIM_CLOCKDIVISION_DIV1                       (0x0000U)
#define TIM_CLOCKDIVISION_DIV2                       (TIM_CR1_CKD_0)
#define TIM_CLOCKDIVISION_DIV4                       (TIM_CR1_CKD_1)







#define TIM_AUTORELOAD_PRELOAD_DISABLE                (0x0000U)
#define TIM_AUTORELOAD_PRELOAD_ENABLE                 (TIM_CR1_ARPE)








#define TIM_OCFAST_DISABLE                (0x0000U)
#define TIM_OCFAST_ENABLE                 (TIM_CCMR1_OC1FE)







#define TIM_OCPOLARITY_HIGH                (0x0000U)
#define TIM_OCPOLARITY_LOW                 (TIM_CCER_CC1P)







#define TIM_OCNPOLARITY_HIGH               (0x0000U)
#define TIM_OCNPOLARITY_LOW                (TIM_CCER_CC1NP)







#define TIM_OCIDLESTATE_SET                (TIM_CR2_OIS1)
#define TIM_OCIDLESTATE_RESET              (0x0000U)







#define TIM_OCNIDLESTATE_SET               (TIM_CR2_OIS1N)
#define TIM_OCNIDLESTATE_RESET             (0x0000U)







#define  TIM_ICPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING
#define  TIM_ICPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING
#define  TIM_ICPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE







#define TIM_ICSELECTION_DIRECTTI           (TIM_CCMR1_CC1S_0)

#define TIM_ICSELECTION_INDIRECTTI         (TIM_CCMR1_CC1S_1)

#define TIM_ICSELECTION_TRC                (TIM_CCMR1_CC1S)







#define TIM_ICPSC_DIV1                     (0x0000U)
#define TIM_ICPSC_DIV2                     (TIM_CCMR1_IC1PSC_0)
#define TIM_ICPSC_DIV4                     (TIM_CCMR1_IC1PSC_1)
#define TIM_ICPSC_DIV8                     (TIM_CCMR1_IC1PSC)







#define TIM_OPMODE_SINGLE                  (TIM_CR1_OPM)
#define TIM_OPMODE_REPETITIVE              (0x0000U)







#define TIM_ENCODERMODE_TI1                (TIM_SMCR_SMS_0)
#define TIM_ENCODERMODE_TI2                (TIM_SMCR_SMS_1)
#define TIM_ENCODERMODE_TI12               (TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0)







#define TIM_IT_UPDATE           (TIM_DIER_UIE)
#define TIM_IT_CC1              (TIM_DIER_CC1IE)
#define TIM_IT_CC2              (TIM_DIER_CC2IE)
#define TIM_IT_CC3              (TIM_DIER_CC3IE)
#define TIM_IT_CC4              (TIM_DIER_CC4IE)
#define TIM_IT_COM              (TIM_DIER_COMIE)
#define TIM_IT_TRIGGER          (TIM_DIER_TIE)
#define TIM_IT_BREAK            (TIM_DIER_BIE)







#define TIM_COMMUTATION_TRGI              (TIM_CR2_CCUS)
#define TIM_COMMUTATION_SOFTWARE          (0x0000U)








#define TIM_DMA_UPDATE                     (TIM_DIER_UDE)
#define TIM_DMA_CC1                        (TIM_DIER_CC1DE)
#define TIM_DMA_CC2                        (TIM_DIER_CC2DE)
#define TIM_DMA_CC3                        (TIM_DIER_CC3DE)
#define TIM_DMA_CC4                        (TIM_DIER_CC4DE)
#define TIM_DMA_COM                        (TIM_DIER_COMDE)
#define TIM_DMA_TRIGGER                    (TIM_DIER_TDE)







#define TIM_FLAG_UPDATE                    (TIM_SR_UIF)
#define TIM_FLAG_CC1                       (TIM_SR_CC1IF)
#define TIM_FLAG_CC2                       (TIM_SR_CC2IF)
#define TIM_FLAG_CC3                       (TIM_SR_CC3IF)
#define TIM_FLAG_CC4                       (TIM_SR_CC4IF)
#define TIM_FLAG_COM                       (TIM_SR_COMIF)
#define TIM_FLAG_TRIGGER                   (TIM_SR_TIF)
#define TIM_FLAG_BREAK                     (TIM_SR_BIF)
#if defined(TIM_SR_B2IF)
#define TIM_FLAG_BREAK2                    (TIM_SR_B2IF)
#endif
#define TIM_FLAG_CC1OF                     (TIM_SR_CC1OF)
#define TIM_FLAG_CC2OF                     (TIM_SR_CC2OF)
#define TIM_FLAG_CC3OF                     (TIM_SR_CC3OF)
#define TIM_FLAG_CC4OF                     (TIM_SR_CC4OF)







#define TIM_CLOCKSOURCE_ETRMODE2    (TIM_SMCR_ETPS_1)
#define TIM_CLOCKSOURCE_INTERNAL    (TIM_SMCR_ETPS_0)
#define TIM_CLOCKSOURCE_ITR0        (0x0000U)
#define TIM_CLOCKSOURCE_ITR1        (TIM_SMCR_TS_0)
#define TIM_CLOCKSOURCE_ITR2        (TIM_SMCR_TS_1)
#define TIM_CLOCKSOURCE_ITR3        (TIM_SMCR_TS_0 | TIM_SMCR_TS_1)
#define TIM_CLOCKSOURCE_TI1ED       (TIM_SMCR_TS_2)
#define TIM_CLOCKSOURCE_TI1         (TIM_SMCR_TS_0 | TIM_SMCR_TS_2)
#define TIM_CLOCKSOURCE_TI2         (TIM_SMCR_TS_1 | TIM_SMCR_TS_2)
#define TIM_CLOCKSOURCE_ETRMODE1    (TIM_SMCR_TS)







#define TIM_CLOCKPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED
#define TIM_CLOCKPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED
#define TIM_CLOCKPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING
#define TIM_CLOCKPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING
#define TIM_CLOCKPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE







#define TIM_CLOCKPRESCALER_DIV1                 TIM_ETRPRESCALER_DIV1
#define TIM_CLOCKPRESCALER_DIV2                 TIM_ETRPRESCALER_DIV2
#define TIM_CLOCKPRESCALER_DIV4                 TIM_ETRPRESCALER_DIV4
#define TIM_CLOCKPRESCALER_DIV8                 TIM_ETRPRESCALER_DIV8







#define TIM_CLEARINPUTPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED
#define TIM_CLEARINPUTPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED







#define TIM_CLEARINPUTPRESCALER_DIV1                    TIM_ETRPRESCALER_DIV1
#define TIM_CLEARINPUTPRESCALER_DIV2                    TIM_ETRPRESCALER_DIV2
#define TIM_CLEARINPUTPRESCALER_DIV4                    TIM_ETRPRESCALER_DIV4
#define TIM_CLEARINPUTPRESCALER_DIV8                    TIM_ETRPRESCALER_DIV8







#define TIM_OSSR_ENABLE        (TIM_BDTR_OSSR)
#define TIM_OSSR_DISABLE              (0x0000U)







#define TIM_OSSI_ENABLE       (TIM_BDTR_OSSI)
#define TIM_OSSI_DISABLE            (0x0000U)







#define TIM_LOCKLEVEL_OFF    (0x0000U)
#define TIM_LOCKLEVEL_1            (TIM_BDTR_LOCK_0)
#define TIM_LOCKLEVEL_2            (TIM_BDTR_LOCK_1)
#define TIM_LOCKLEVEL_3            (TIM_BDTR_LOCK)







#define TIM_BREAK_ENABLE          (TIM_BDTR_BKE)
#define TIM_BREAK_DISABLE         (0x0000U)







#define TIM_BREAKPOLARITY_LOW        (0x0000U)
#define TIM_BREAKPOLARITY_HIGH       (TIM_BDTR_BKP)






#define TIM_AUTOMATICOUTPUT_ENABLE           (TIM_BDTR_AOE)
#define TIM_AUTOMATICOUTPUT_DISABLE          (0x0000U)







#define TIM_TRGO_RESET            (0x0000U)
#define TIM_TRGO_ENABLE           (TIM_CR2_MMS_0)
#define TIM_TRGO_UPDATE           (TIM_CR2_MMS_1)
#define TIM_TRGO_OC1              ((TIM_CR2_MMS_1 | TIM_CR2_MMS_0))
#define TIM_TRGO_OC1REF           (TIM_CR2_MMS_2)
#define TIM_TRGO_OC2REF           ((TIM_CR2_MMS_2 | TIM_CR2_MMS_0))
#define TIM_TRGO_OC3REF           ((TIM_CR2_MMS_2 | TIM_CR2_MMS_1))
#define TIM_TRGO_OC4REF           ((TIM_CR2_MMS_2 | TIM_CR2_MMS_1 | TIM_CR2_MMS_0))







#define TIM_MASTERSLAVEMODE_ENABLE          (0x0080U)
#define TIM_MASTERSLAVEMODE_DISABLE         (0x0000U)







#define TIM_TS_ITR0                        (0x0000U)
#define TIM_TS_ITR1                        (0x0010U)
#define TIM_TS_ITR2                        (0x0020U)
#define TIM_TS_ITR3                        (0x0030U)
#define TIM_TS_TI1F_ED                     (0x0040U)
#define TIM_TS_TI1FP1                      (0x0050U)
#define TIM_TS_TI2FP2                      (0x0060U)
#define TIM_TS_ETRF                        (0x0070U)
#define TIM_TS_NONE                        (0xFFFFU)







#define TIM_TRIGGERPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED
#define TIM_TRIGGERPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED
#define TIM_TRIGGERPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING
#define TIM_TRIGGERPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING
#define TIM_TRIGGERPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE







#define TIM_TRIGGERPRESCALER_DIV1             TIM_ETRPRESCALER_DIV1
#define TIM_TRIGGERPRESCALER_DIV2             TIM_ETRPRESCALER_DIV2
#define TIM_TRIGGERPRESCALER_DIV4             TIM_ETRPRESCALER_DIV4
#define TIM_TRIGGERPRESCALER_DIV8             TIM_ETRPRESCALER_DIV8







#define TIM_TI1SELECTION_CH1                (0x0000U)
#define TIM_TI1SELECTION_XORCOMBINATION     (TIM_CR2_TI1S)







#define TIM_DMABURSTLENGTH_1TRANSFER           (0x00000000U)
#define TIM_DMABURSTLENGTH_2TRANSFERS          (0x00000100U)
#define TIM_DMABURSTLENGTH_3TRANSFERS          (0x00000200U)
#define TIM_DMABURSTLENGTH_4TRANSFERS          (0x00000300U)
#define TIM_DMABURSTLENGTH_5TRANSFERS          (0x00000400U)
#define TIM_DMABURSTLENGTH_6TRANSFERS          (0x00000500U)
#define TIM_DMABURSTLENGTH_7TRANSFERS          (0x00000600U)
#define TIM_DMABURSTLENGTH_8TRANSFERS          (0x00000700U)
#define TIM_DMABURSTLENGTH_9TRANSFERS          (0x00000800U)
#define TIM_DMABURSTLENGTH_10TRANSFERS         (0x00000900U)
#define TIM_DMABURSTLENGTH_11TRANSFERS         (0x00000A00U)
#define TIM_DMABURSTLENGTH_12TRANSFERS         (0x00000B00U)
#define TIM_DMABURSTLENGTH_13TRANSFERS         (0x00000C00U)
#define TIM_DMABURSTLENGTH_14TRANSFERS         (0x00000D00U)
#define TIM_DMABURSTLENGTH_15TRANSFERS         (0x00000E00U)
#define TIM_DMABURSTLENGTH_16TRANSFERS         (0x00000F00U)
#define TIM_DMABURSTLENGTH_17TRANSFERS         (0x00001000U)
#define TIM_DMABURSTLENGTH_18TRANSFERS         (0x00001100U)







#define TIM_DMA_ID_UPDATE                ((uint16_t) 0x0U)
#define TIM_DMA_ID_CC1                   ((uint16_t) 0x1U)
#define TIM_DMA_ID_CC2                   ((uint16_t) 0x2U)
#define TIM_DMA_ID_CC3                   ((uint16_t) 0x3U)
#define TIM_DMA_ID_CC4                   ((uint16_t) 0x4U)
#define TIM_DMA_ID_COMMUTATION           ((uint16_t) 0x5U)
#define TIM_DMA_ID_TRIGGER               ((uint16_t) 0x6U)







#define TIM_CCx_ENABLE                   (0x0001U)
#define TIM_CCx_DISABLE                  (0x0000U)
#define TIM_CCxN_ENABLE                  (0x0004U)
#define TIM_CCxN_DISABLE                 (0x0000U)


















#define __HAL_TIM_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_TIM_STATE_RESET)






#define __HAL_TIM_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1|=(TIM_CR1_CEN))






#define __HAL_TIM_MOE_ENABLE(__HANDLE__)             ((__HANDLE__)->Instance->BDTR|=(TIM_BDTR_MOE))






#define __HAL_TIM_DISABLE(__HANDLE__) \
                        do { \
                          if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0U) \
                            { \
                            if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0U) \
                            { \
                              (__HANDLE__)->Instance->CR1 &= ~(TIM_CR1_CEN); \
                            } \
                          } \
                        } while(0U)








#define __HAL_TIM_MOE_DISABLE(__HANDLE__) \
                        do { \
                          if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0U) \
                          { \
                            if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0U) \
                            { \
                              (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE); \
                            } \
                            } \
                        } while(0U)








#define __HAL_TIM_MOE_DISABLE_UNCONDITIONALLY(__HANDLE__)  (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE)
















#define __HAL_TIM_ENABLE_IT(__HANDLE__, __INTERRUPT__)  ((__HANDLE__)->Instance->DIER |= (__INTERRUPT__))
















#define __HAL_TIM_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((__HANDLE__)->Instance->DIER &= ~(__INTERRUPT__))















#define __HAL_TIM_ENABLE_DMA(__HANDLE__, __DMA__)  ((__HANDLE__)->Instance->DIER |= (__DMA__))















#define __HAL_TIM_DISABLE_DMA(__HANDLE__, __DMA__)  ((__HANDLE__)->Instance->DIER &= ~(__DMA__))




















#define __HAL_TIM_GET_FLAG(__HANDLE__, __FLAG__)       (((__HANDLE__)->Instance->SR &(__FLAG__)) == (__FLAG__))




















#define __HAL_TIM_CLEAR_FLAG(__HANDLE__, __FLAG__)       ((__HANDLE__)->Instance->SR = ~(__FLAG__))







#define __HAL_TIM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->DIER & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)







#define __HAL_TIM_CLEAR_IT(__HANDLE__, __INTERRUPT__)     ((__HANDLE__)->Instance->SR = ~(__INTERRUPT__))







#define __HAL_TIM_IS_TIM_COUNTING_DOWN(__HANDLE__)       (((__HANDLE__)->Instance->CR1 &(TIM_CR1_DIR)) == (TIM_CR1_DIR))







#define __HAL_TIM_SET_PRESCALER(__HANDLE__, __PRESC__)  ((__HANDLE__)->Instance->PSC = (__PRESC__))







#define __HAL_TIM_SET_COUNTER(__HANDLE__, __COUNTER__)  ((__HANDLE__)->Instance->CNT = (__COUNTER__))






#define __HAL_TIM_GET_COUNTER(__HANDLE__) \
   ((__HANDLE__)->Instance->CNT)








#define __HAL_TIM_SET_AUTORELOAD(__HANDLE__, __AUTORELOAD__) \
                        do{                                                    \
                              (__HANDLE__)->Instance->ARR = (__AUTORELOAD__);  \
                              (__HANDLE__)->Init.Period = (__AUTORELOAD__);    \
                          } while(0U)






#define __HAL_TIM_GET_AUTORELOAD(__HANDLE__) \
   ((__HANDLE__)->Instance->ARR)












#define __HAL_TIM_SET_CLOCKDIVISION(__HANDLE__, __CKD__) \
                        do{                                                    \
                              (__HANDLE__)->Instance->CR1 &= (uint16_t)(~TIM_CR1_CKD);  \
                              (__HANDLE__)->Instance->CR1 |= (__CKD__);                   \
                              (__HANDLE__)->Init.ClockDivision = (__CKD__);             \
                          } while(0U)









#define __HAL_TIM_GET_CLOCKDIVISION(__HANDLE__)  \
   ((__HANDLE__)->Instance->CR1 & TIM_CR1_CKD)



















#define __HAL_TIM_SET_ICPRESCALER(__HANDLE__, __CHANNEL__, __ICPSC__) \
                        do{                                                    \
                              TIM_RESET_ICPRESCALERVALUE((__HANDLE__), (__CHANNEL__));  \
                              TIM_SET_ICPRESCALERVALUE((__HANDLE__), (__CHANNEL__), (__ICPSC__)); \
                          } while(0U)
















#define __HAL_TIM_GET_ICPRESCALER(__HANDLE__, __CHANNEL__)  \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 & TIM_CCMR1_IC1PSC) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (((__HANDLE__)->Instance->CCMR1 & TIM_CCMR1_IC2PSC) >> 8U) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 & TIM_CCMR2_IC3PSC) :\
   (((__HANDLE__)->Instance->CCMR2 & TIM_CCMR2_IC4PSC)) >> 8U)









#define __HAL_TIM_URS_ENABLE(__HANDLE__) \
    ((__HANDLE__)->Instance->CR1|= (TIM_CR1_URS))












#define __HAL_TIM_URS_DISABLE(__HANDLE__) \
      ((__HANDLE__)->Instance->CR1&=~(TIM_CR1_URS))
















#define __HAL_TIM_SET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__, __POLARITY__)    \
        do{                                                                     \
          TIM_RESET_CAPTUREPOLARITY((__HANDLE__), (__CHANNEL__));               \
          TIM_SET_CAPTUREPOLARITY((__HANDLE__), (__CHANNEL__), (__POLARITY__)); \
        }while(0U)













#define TIM_CCER_CCxE_MASK ((uint32_t)(TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E))
#define TIM_CCER_CCxNE_MASK ((uint32_t)(TIM_CCER_CC1NE | TIM_CCER_CC2NE | TIM_CCER_CC3NE))











#define IS_TIM_COUNTER_MODE(MODE) (((MODE) == TIM_COUNTERMODE_UP)              || \
                                   ((MODE) == TIM_COUNTERMODE_DOWN)            || \
                                   ((MODE) == TIM_COUNTERMODE_CENTERALIGNED1)  || \
                                   ((MODE) == TIM_COUNTERMODE_CENTERALIGNED2)  || \
                                   ((MODE) == TIM_COUNTERMODE_CENTERALIGNED3))

#define IS_TIM_CLOCKDIVISION_DIV(DIV) (((DIV) == TIM_CLOCKDIVISION_DIV1) || \
                                       ((DIV) == TIM_CLOCKDIVISION_DIV2) || \
                                       ((DIV) == TIM_CLOCKDIVISION_DIV4))

#define IS_TIM_AUTORELOAD_PRELOAD(PRELOAD) (((PRELOAD) == TIM_AUTORELOAD_PRELOAD_DISABLE) || \
                                            ((PRELOAD) == TIM_AUTORELOAD_PRELOAD_ENABLE))

#define IS_TIM_FAST_STATE(STATE) (((STATE) == TIM_OCFAST_DISABLE) || \
                                  ((STATE) == TIM_OCFAST_ENABLE))

#define IS_TIM_OC_POLARITY(POLARITY) (((POLARITY) == TIM_OCPOLARITY_HIGH) || \
                                      ((POLARITY) == TIM_OCPOLARITY_LOW))

#define IS_TIM_OCN_POLARITY(POLARITY) (((POLARITY) == TIM_OCNPOLARITY_HIGH) || \
                                       ((POLARITY) == TIM_OCNPOLARITY_LOW))

#define IS_TIM_OCIDLE_STATE(STATE) (((STATE) == TIM_OCIDLESTATE_SET) || \
                                    ((STATE) == TIM_OCIDLESTATE_RESET))

#define IS_TIM_OCNIDLE_STATE(STATE) (((STATE) == TIM_OCNIDLESTATE_SET) || \
                                     ((STATE) == TIM_OCNIDLESTATE_RESET))


#define IS_TIM_IC_POLARITY(POLARITY) (((POLARITY) == TIM_ICPOLARITY_RISING)   || \
                                      ((POLARITY) == TIM_ICPOLARITY_FALLING)  || \
                                      ((POLARITY) == TIM_ICPOLARITY_BOTHEDGE))

#define IS_TIM_IC_SELECTION(SELECTION) (((SELECTION) == TIM_ICSELECTION_DIRECTTI) || \
                                        ((SELECTION) == TIM_ICSELECTION_INDIRECTTI) || \
                                        ((SELECTION) == TIM_ICSELECTION_TRC))

#define IS_TIM_IC_PRESCALER(PRESCALER) (((PRESCALER) == TIM_ICPSC_DIV1) || \
                                        ((PRESCALER) == TIM_ICPSC_DIV2) || \
                                        ((PRESCALER) == TIM_ICPSC_DIV4) || \
                                        ((PRESCALER) == TIM_ICPSC_DIV8))

#define IS_TIM_OPM_MODE(MODE) (((MODE) == TIM_OPMODE_SINGLE) || \
                              ((MODE) == TIM_OPMODE_REPETITIVE))

#define IS_TIM_ENCODER_MODE(MODE) (((MODE) == TIM_ENCODERMODE_TI1) || \
                                   ((MODE) == TIM_ENCODERMODE_TI2) || \
                                   ((MODE) == TIM_ENCODERMODE_TI12))

#define IS_TIM_DMA_SOURCE(SOURCE) ((((SOURCE) & 0xFFFF80FFU) == 0x00000000U) && ((SOURCE) != 0x00000000U))


#define IS_TIM_CLOCKSOURCE(CLOCK) (((CLOCK) == TIM_CLOCKSOURCE_INTERNAL) || \
                                   ((CLOCK) == TIM_CLOCKSOURCE_ETRMODE2) || \
                                   ((CLOCK) == TIM_CLOCKSOURCE_ITR0)     || \
                                   ((CLOCK) == TIM_CLOCKSOURCE_ITR1)     || \
                                   ((CLOCK) == TIM_CLOCKSOURCE_ITR2)     || \
                                   ((CLOCK) == TIM_CLOCKSOURCE_ITR3)     || \
                                   ((CLOCK) == TIM_CLOCKSOURCE_TI1ED)    || \
                                   ((CLOCK) == TIM_CLOCKSOURCE_TI1)      || \
                                   ((CLOCK) == TIM_CLOCKSOURCE_TI2)      || \
                                   ((CLOCK) == TIM_CLOCKSOURCE_ETRMODE1))

#define IS_TIM_CLOCKPOLARITY(POLARITY) (((POLARITY) == TIM_CLOCKPOLARITY_INVERTED)    || \
                                        ((POLARITY) == TIM_CLOCKPOLARITY_NONINVERTED) || \
                                        ((POLARITY) == TIM_CLOCKPOLARITY_RISING)      || \
                                        ((POLARITY) == TIM_CLOCKPOLARITY_FALLING)     || \
                                        ((POLARITY) == TIM_CLOCKPOLARITY_BOTHEDGE))

#define IS_TIM_CLOCKPRESCALER(PRESCALER) (((PRESCALER) == TIM_CLOCKPRESCALER_DIV1) || \
                                          ((PRESCALER) == TIM_CLOCKPRESCALER_DIV2) || \
                                          ((PRESCALER) == TIM_CLOCKPRESCALER_DIV4) || \
                                          ((PRESCALER) == TIM_CLOCKPRESCALER_DIV8))

#define IS_TIM_CLOCKFILTER(ICFILTER)      ((ICFILTER) <= 0xFU)

#define IS_TIM_CLEARINPUT_POLARITY(POLARITY) (((POLARITY) == TIM_CLEARINPUTPOLARITY_INVERTED) || \
                                             ((POLARITY) == TIM_CLEARINPUTPOLARITY_NONINVERTED))

#define IS_TIM_CLEARINPUT_PRESCALER(PRESCALER)   (((PRESCALER) == TIM_CLEARINPUTPRESCALER_DIV1) || \
                                                ((PRESCALER) == TIM_CLEARINPUTPRESCALER_DIV2) || \
                                                ((PRESCALER) == TIM_CLEARINPUTPRESCALER_DIV4) || \
                                                ((PRESCALER) == TIM_CLEARINPUTPRESCALER_DIV8))

#define IS_TIM_CLEARINPUT_FILTER(ICFILTER) ((ICFILTER) <= 0xFU)

#define IS_TIM_OSSR_STATE(STATE) (((STATE) == TIM_OSSR_ENABLE) || \
                                  ((STATE) == TIM_OSSR_DISABLE))

#define IS_TIM_OSSI_STATE(STATE) (((STATE) == TIM_OSSI_ENABLE) || \
                                  ((STATE) == TIM_OSSI_DISABLE))

#define IS_TIM_LOCK_LEVEL(LEVEL) (((LEVEL) == TIM_LOCKLEVEL_OFF) || \
                                  ((LEVEL) == TIM_LOCKLEVEL_1) || \
                                  ((LEVEL) == TIM_LOCKLEVEL_2) || \
                                  ((LEVEL) == TIM_LOCKLEVEL_3))

#define IS_TIM_BREAK_STATE(STATE) (((STATE) == TIM_BREAK_ENABLE) || \
                                   ((STATE) == TIM_BREAK_DISABLE))

#define IS_TIM_BREAK_POLARITY(POLARITY) (((POLARITY) == TIM_BREAKPOLARITY_LOW) || \
                                         ((POLARITY) == TIM_BREAKPOLARITY_HIGH))

#define IS_TIM_AUTOMATIC_OUTPUT_STATE(STATE) (((STATE) == TIM_AUTOMATICOUTPUT_ENABLE) || \
                                              ((STATE) == TIM_AUTOMATICOUTPUT_DISABLE))

#define IS_TIM_TRGO_SOURCE(SOURCE) (((SOURCE) == TIM_TRGO_RESET) || \
                                    ((SOURCE) == TIM_TRGO_ENABLE) || \
                                    ((SOURCE) == TIM_TRGO_UPDATE) || \
                                    ((SOURCE) == TIM_TRGO_OC1) || \
                                    ((SOURCE) == TIM_TRGO_OC1REF) || \
                                    ((SOURCE) == TIM_TRGO_OC2REF) || \
                                    ((SOURCE) == TIM_TRGO_OC3REF) || \
                                    ((SOURCE) == TIM_TRGO_OC4REF))

#define IS_TIM_MSM_STATE(STATE) (((STATE) == TIM_MASTERSLAVEMODE_ENABLE) || \
                                 ((STATE) == TIM_MASTERSLAVEMODE_DISABLE))

#define IS_TIM_TRIGGER_SELECTION(SELECTION) (((SELECTION) == TIM_TS_ITR0) || \
                                             ((SELECTION) == TIM_TS_ITR1) || \
                                             ((SELECTION) == TIM_TS_ITR2) || \
                                             ((SELECTION) == TIM_TS_ITR3) || \
                                             ((SELECTION) == TIM_TS_TI1F_ED) || \
                                             ((SELECTION) == TIM_TS_TI1FP1) || \
                                             ((SELECTION) == TIM_TS_TI2FP2) || \
                                             ((SELECTION) == TIM_TS_ETRF))

#define IS_TIM_INTERNAL_TRIGGEREVENT_SELECTION(SELECTION) (((SELECTION) == TIM_TS_ITR0) || \
                                                           ((SELECTION) == TIM_TS_ITR1) || \
                                                           ((SELECTION) == TIM_TS_ITR2) || \
                                                           ((SELECTION) == TIM_TS_ITR3) || \
                                                           ((SELECTION) == TIM_TS_NONE))

#define IS_TIM_TRIGGERPOLARITY(POLARITY)     (((POLARITY) == TIM_TRIGGERPOLARITY_INVERTED   ) || \
                                              ((POLARITY) == TIM_TRIGGERPOLARITY_NONINVERTED) || \
                                              ((POLARITY) == TIM_TRIGGERPOLARITY_RISING     ) || \
                                              ((POLARITY) == TIM_TRIGGERPOLARITY_FALLING    ) || \
                                              ((POLARITY) == TIM_TRIGGERPOLARITY_BOTHEDGE   ))

#define IS_TIM_TRIGGERPRESCALER(PRESCALER)  (((PRESCALER) == TIM_TRIGGERPRESCALER_DIV1) || \
                                             ((PRESCALER) == TIM_TRIGGERPRESCALER_DIV2) || \
                                             ((PRESCALER) == TIM_TRIGGERPRESCALER_DIV4) || \
                                             ((PRESCALER) == TIM_TRIGGERPRESCALER_DIV8))

#define IS_TIM_TRIGGERFILTER(ICFILTER)     ((ICFILTER) <= 0xFU)

#define IS_TIM_TI1SELECTION(TI1SELECTION)   (((TI1SELECTION) == TIM_TI1SELECTION_CH1) || \
                                             ((TI1SELECTION) == TIM_TI1SELECTION_XORCOMBINATION))

#define IS_TIM_DMA_LENGTH(LENGTH) (((LENGTH) == TIM_DMABURSTLENGTH_1TRANSFER) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_2TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_3TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_4TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_5TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_6TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_7TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_8TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_9TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_10TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_11TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_12TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_13TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_14TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_15TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_16TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_17TRANSFERS) || \
                                   ((LENGTH) == TIM_DMABURSTLENGTH_18TRANSFERS))

#define IS_TIM_DMA_DATA_LENGTH(LENGTH) (((LENGTH) >= 0x1U) && ((LENGTH) < 0x10000U))

#define IS_TIM_IC_FILTER(ICFILTER) ((ICFILTER) <= 0xFU)







#define TIM_SET_ICPRESCALERVALUE(__HANDLE__, __CHANNEL__, __ICPSC__) \
(((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= (__ICPSC__)) :\
 ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= ((__ICPSC__) << 8U)) :\
 ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= (__ICPSC__)) :\
 ((__HANDLE__)->Instance->CCMR2 |= ((__ICPSC__) << 8U)))






#define TIM_RESET_ICPRESCALERVALUE(__HANDLE__, __CHANNEL__) \
(((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= (uint16_t)~TIM_CCMR1_IC1PSC) :\
 ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= (uint16_t)~TIM_CCMR1_IC2PSC) :\
 ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= (uint16_t)~TIM_CCMR2_IC3PSC) :\
 ((__HANDLE__)->Instance->CCMR2 &= (uint16_t)~TIM_CCMR2_IC4PSC))







#define TIM_SET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__, __POLARITY__) \
(((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCER |= (__POLARITY__)) :\
 ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCER |= ((__POLARITY__) << 4U)) :\
 ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCER |= ((__POLARITY__) << 8U)) :\
 ((__HANDLE__)->Instance->CCER |= (((__POLARITY__) << 12U))))






#define TIM_RESET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__) \
(((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCER &= (uint16_t)~(TIM_CCER_CC1P | TIM_CCER_CC1NP)) :\
 ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCER &= (uint16_t)~(TIM_CCER_CC2P | TIM_CCER_CC2NP)) :\
 ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCER &= (uint16_t)~(TIM_CCER_CC3P | TIM_CCER_CC3NP)) :\
 ((__HANDLE__)->Instance->CCER &= (uint16_t)~(TIM_CCER_CC4P | TIM_CCER_CC4NP)))






#include "stm32f3xx_hal_tim_ex.h"










HAL_StatusTypeDef HAL_TIM_Base_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_Base_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_Base_Stop_DMA(TIM_HandleTypeDef *htim);








HAL_StatusTypeDef HAL_TIM_OC_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_OC_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_OC_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_OC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_OC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_OC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);









HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_PWM_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_PWM_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);








HAL_StatusTypeDef HAL_TIM_IC_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_IC_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_IC_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_IC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_IC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_IC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_IC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_IC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);








HAL_StatusTypeDef HAL_TIM_OnePulse_Init(TIM_HandleTypeDef *htim, uint32_t OnePulseMode);
HAL_StatusTypeDef HAL_TIM_OnePulse_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OnePulse_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OnePulse_MspDeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_OnePulse_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);

HAL_StatusTypeDef HAL_TIM_OnePulse_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);








HAL_StatusTypeDef HAL_TIM_Encoder_Init(TIM_HandleTypeDef *htim,  TIM_Encoder_InitTypeDef* sConfig);
HAL_StatusTypeDef HAL_TIM_Encoder_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Encoder_MspDeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_Encoder_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_Encoder_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_Encoder_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIM_Encoder_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData1, uint32_t *pData2, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);









void HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim);








HAL_StatusTypeDef HAL_TIM_OC_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OC_InitTypeDef* sConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OC_InitTypeDef* sConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_IC_ConfigChannel(TIM_HandleTypeDef *htim, TIM_IC_InitTypeDef* sConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OnePulse_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OnePulse_InitTypeDef* sConfig, uint32_t OutputChannel,  uint32_t InputChannel);
HAL_StatusTypeDef HAL_TIM_ConfigOCrefClear(TIM_HandleTypeDef *htim, TIM_ClearInputConfigTypeDef * sClearInputConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_ConfigClockSource(TIM_HandleTypeDef *htim, TIM_ClockConfigTypeDef * sClockSourceConfig);
HAL_StatusTypeDef HAL_TIM_ConfigTI1Input(TIM_HandleTypeDef *htim, uint32_t TI1_Selection);
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchronization(TIM_HandleTypeDef *htim, TIM_SlaveConfigTypeDef * sSlaveConfig);
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchronization_IT(TIM_HandleTypeDef *htim, TIM_SlaveConfigTypeDef * sSlaveConfig);
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc, \
                                              uint32_t  *BurstBuffer, uint32_t  BurstLength);
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiWriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc, \
                                                   uint32_t  *BurstBuffer, uint32_t  BurstLength, uint32_t  DataLength);
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc, \
                                              uint32_t  *BurstBuffer, uint32_t  BurstLength);
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc, \
                                                  uint32_t  *BurstBuffer, uint32_t  BurstLength, uint32_t  DataLength);
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
HAL_StatusTypeDef HAL_TIM_GenerateEvent(TIM_HandleTypeDef *htim, uint32_t EventSource);
uint32_t HAL_TIM_ReadCapturedValue(TIM_HandleTypeDef *htim, uint32_t Channel);









void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim);








HAL_TIM_StateTypeDef HAL_TIM_Base_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_OC_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_PWM_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_IC_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_OnePulse_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_Encoder_GetState(TIM_HandleTypeDef *htim);














void TIM_Base_SetConfig(TIM_TypeDef *TIMx, TIM_Base_InitTypeDef *Structure);
void TIM_TI1_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection, uint32_t TIM_ICFilter);
void TIM_OC1_SetConfig(TIM_TypeDef *TIMx, TIM_OC_InitTypeDef *OC_Config);
void TIM_OC2_SetConfig(TIM_TypeDef *TIMx, TIM_OC_InitTypeDef *OC_Config);
void TIM_OC3_SetConfig(TIM_TypeDef *TIMx, TIM_OC_InitTypeDef *OC_Config);
void TIM_OC4_SetConfig(TIM_TypeDef *TIMx, TIM_OC_InitTypeDef *OC_Config);
void TIM_ETR_SetConfig(TIM_TypeDef* TIMx, uint32_t TIM_ExtTRGPrescaler,
                       uint32_t TIM_ExtTRGPolarity, uint32_t ExtTRGFilter);
void TIM_DMADelayPulseCplt(DMA_HandleTypeDef *hdma);
void TIM_DMAError(DMA_HandleTypeDef *hdma);
void TIM_DMACaptureCplt(DMA_HandleTypeDef *hdma);
void TIM_CCxChannelCmd(TIM_TypeDef* TIMx, uint32_t Channel, uint32_t ChannelState);













#ifdef __cplusplus
}
#endif

#endif


