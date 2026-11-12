


































































































#include "stm32f3xx_hal.h"










#ifdef HAL_TIM_MODULE_ENABLED



#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

#define BDTR_BKF_SHIFT (16U)
#define BDTR_BK2F_SHIFT (20U)
#endif











static void TIM_CCxNChannelCmd(TIM_TypeDef* TIMx, uint32_t Channel, uint32_t ChannelNState);

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
static void TIM_OC5_SetConfig(TIM_TypeDef *TIMx,
                              TIM_OC_InitTypeDef *OC_Config);

static void TIM_OC6_SetConfig(TIM_TypeDef *TIMx,
                              TIM_OC_InitTypeDef *OC_Config);
#endif









































HAL_StatusTypeDef HAL_TIMEx_HallSensor_Init(TIM_HandleTypeDef *htim, TIM_HallSensor_InitTypeDef* sConfig)
{
  TIM_OC_InitTypeDef OC_Config;


  if(htim == NULL)
  {
    return HAL_ERROR;
  }

  assert_param(IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(htim->Instance));
  assert_param(IS_TIM_COUNTER_MODE(htim->Init.CounterMode));
  assert_param(IS_TIM_CLOCKDIVISION_DIV(htim->Init.ClockDivision));
  assert_param(IS_TIM_AUTORELOAD_PRELOAD(htim->Init.AutoReloadPreload));
  assert_param(IS_TIM_IC_POLARITY(sConfig->IC1Polarity));
  assert_param(IS_TIM_IC_PRESCALER(sConfig->IC1Prescaler));
  assert_param(IS_TIM_IC_FILTER(sConfig->IC1Filter));

  if(htim->State == HAL_TIM_STATE_RESET)
  {

    htim->Lock = HAL_UNLOCKED;


    HAL_TIMEx_HallSensor_MspInit(htim);
  }


  htim->State = HAL_TIM_STATE_BUSY;


  TIM_Base_SetConfig(htim->Instance, &htim->Init);


  TIM_TI1_SetConfig(htim->Instance, sConfig->IC1Polarity, TIM_ICSELECTION_TRC, sConfig->IC1Filter);


  htim->Instance->CCMR1 &= ~TIM_CCMR1_IC1PSC;

  htim->Instance->CCMR1 |= sConfig->IC1Prescaler;


  htim->Instance->CR2 |= TIM_CR2_TI1S;


  htim->Instance->SMCR &= ~TIM_SMCR_TS;
  htim->Instance->SMCR |= TIM_TS_TI1F_ED;


  htim->Instance->SMCR &= ~TIM_SMCR_SMS;
  htim->Instance->SMCR |= TIM_SLAVEMODE_RESET;


  OC_Config.OCFastMode = TIM_OCFAST_DISABLE;
  OC_Config.OCIdleState = TIM_OCIDLESTATE_RESET;
  OC_Config.OCMode = TIM_OCMODE_PWM2;
  OC_Config.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  OC_Config.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  OC_Config.OCPolarity = TIM_OCPOLARITY_HIGH;
  OC_Config.Pulse = sConfig->Commutation_Delay;

  TIM_OC2_SetConfig(htim->Instance, &OC_Config);



  htim->Instance->CR2 &= ~TIM_CR2_MMS;
  htim->Instance->CR2 |= TIM_TRGO_OC2REF;


  htim->State= HAL_TIM_STATE_READY;

  return HAL_OK;
}






HAL_StatusTypeDef HAL_TIMEx_HallSensor_DeInit(TIM_HandleTypeDef *htim)
{

  assert_param(IS_TIM_INSTANCE(htim->Instance));

  htim->State = HAL_TIM_STATE_BUSY;


  __HAL_TIM_DISABLE(htim);


  HAL_TIMEx_HallSensor_MspDeInit(htim);


  htim->State = HAL_TIM_STATE_RESET;


  __HAL_UNLOCK(htim);

  return HAL_OK;
}






__weak void HAL_TIMEx_HallSensor_MspInit(TIM_HandleTypeDef *htim)
{

  UNUSED(htim);




}






__weak void HAL_TIMEx_HallSensor_MspDeInit(TIM_HandleTypeDef *htim)
{

  UNUSED(htim);




}






HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start(TIM_HandleTypeDef *htim)
{

  assert_param(IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(htim->Instance));



  TIM_CCxChannelCmd(htim->Instance, TIM_CHANNEL_1, TIM_CCx_ENABLE);


  __HAL_TIM_ENABLE(htim);


  return HAL_OK;
}






HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop(TIM_HandleTypeDef *htim)
{

  assert_param(IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(htim->Instance));



  TIM_CCxChannelCmd(htim->Instance, TIM_CHANNEL_1, TIM_CCx_DISABLE);


  __HAL_TIM_DISABLE(htim);


  return HAL_OK;
}






HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_IT(TIM_HandleTypeDef *htim)
{

  assert_param(IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(htim->Instance));


  __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC1);



  TIM_CCxChannelCmd(htim->Instance, TIM_CHANNEL_1, TIM_CCx_ENABLE);


  __HAL_TIM_ENABLE(htim);


  return HAL_OK;
}






HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_IT(TIM_HandleTypeDef *htim)
{

  assert_param(IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(htim->Instance));



  TIM_CCxChannelCmd(htim->Instance, TIM_CHANNEL_1, TIM_CCx_DISABLE);


  __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);


  __HAL_TIM_DISABLE(htim);


  return HAL_OK;
}








HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length)
{

  assert_param(IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(htim->Instance));

   if((htim->State == HAL_TIM_STATE_BUSY))
  {
     return HAL_BUSY;
  }
  else if((htim->State == HAL_TIM_STATE_READY))
  {
    if(((uint32_t)pData == 0U ) && (Length > 0U))
    {
      return HAL_ERROR;
    }
    else
    {
      htim->State = HAL_TIM_STATE_BUSY;
    }
  }


  TIM_CCxChannelCmd(htim->Instance, TIM_CHANNEL_1, TIM_CCx_ENABLE);


  htim->hdma[TIM_DMA_ID_CC1]->XferCpltCallback = TIM_DMACaptureCplt;

  htim->hdma[TIM_DMA_ID_CC1]->XferErrorCallback = TIM_DMAError ;


  HAL_DMA_Start_IT(htim->hdma[TIM_DMA_ID_CC1], (uint32_t)&htim->Instance->CCR1, (uint32_t)pData, Length);


  __HAL_TIM_ENABLE_DMA(htim, TIM_DMA_CC1);


  __HAL_TIM_ENABLE(htim);


  return HAL_OK;
}






HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_DMA(TIM_HandleTypeDef *htim)
{

  assert_param(IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(htim->Instance));



  TIM_CCxChannelCmd(htim->Instance, TIM_CHANNEL_1, TIM_CCx_DISABLE);



  __HAL_TIM_DISABLE_DMA(htim, TIM_DMA_CC1);


  __HAL_TIM_DISABLE(htim);


  return HAL_OK;
}




































HAL_StatusTypeDef HAL_TIMEx_OCN_Start(TIM_HandleTypeDef *htim, uint32_t Channel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));


     TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_ENABLE);


    __HAL_TIM_MOE_ENABLE(htim);


  __HAL_TIM_ENABLE(htim);


  return HAL_OK;
}












HAL_StatusTypeDef HAL_TIMEx_OCN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_DISABLE);


    __HAL_TIM_MOE_DISABLE(htim);


  __HAL_TIM_DISABLE(htim);


  return HAL_OK;
}












HAL_StatusTypeDef HAL_TIMEx_OCN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC1);
    }
    break;

    case TIM_CHANNEL_2:
    {

      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC2);
    }
    break;

    case TIM_CHANNEL_3:
    {

      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC3);
    }
    break;

    default:
    break;
  }


  __HAL_TIM_ENABLE_IT(htim, TIM_IT_BREAK);


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_ENABLE);


    __HAL_TIM_MOE_ENABLE(htim);


  __HAL_TIM_ENABLE(htim);


  return HAL_OK;
}












HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  uint32_t tmpccer = 0U;


  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
    }
    break;

    case TIM_CHANNEL_2:
    {

      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC2);
    }
    break;

    case TIM_CHANNEL_3:
    {

      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC3);
    }
    break;

    default:
    break;
  }


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_DISABLE);


  tmpccer = htim->Instance->CCER;
  if ((tmpccer & (TIM_CCER_CC1NE | TIM_CCER_CC2NE | TIM_CCER_CC3NE)) == RESET)
  {
    __HAL_TIM_DISABLE_IT(htim, TIM_IT_BREAK);
  }


  __HAL_TIM_MOE_DISABLE(htim);


  __HAL_TIM_DISABLE(htim);


  return HAL_OK;
}














HAL_StatusTypeDef HAL_TIMEx_OCN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));

  if((htim->State == HAL_TIM_STATE_BUSY))
  {
     return HAL_BUSY;
  }
  else if((htim->State == HAL_TIM_STATE_READY))
  {
    if(((uint32_t)pData == 0U ) && (Length > 0U))
    {
      return HAL_ERROR;
    }
    else
    {
      htim->State = HAL_TIM_STATE_BUSY;
    }
  }
  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      htim->hdma[TIM_DMA_ID_CC1]->XferCpltCallback = TIM_DMADelayPulseCplt;


      htim->hdma[TIM_DMA_ID_CC1]->XferErrorCallback = TIM_DMAError ;


      HAL_DMA_Start_IT(htim->hdma[TIM_DMA_ID_CC1], (uint32_t)pData, (uint32_t)&htim->Instance->CCR1, Length);


      __HAL_TIM_ENABLE_DMA(htim, TIM_DMA_CC1);
    }
    break;

    case TIM_CHANNEL_2:
    {

      htim->hdma[TIM_DMA_ID_CC2]->XferCpltCallback = TIM_DMADelayPulseCplt;


      htim->hdma[TIM_DMA_ID_CC2]->XferErrorCallback = TIM_DMAError ;


      HAL_DMA_Start_IT(htim->hdma[TIM_DMA_ID_CC2], (uint32_t)pData, (uint32_t)&htim->Instance->CCR2, Length);


      __HAL_TIM_ENABLE_DMA(htim, TIM_DMA_CC2);
    }
    break;

    case TIM_CHANNEL_3:
    {

      htim->hdma[TIM_DMA_ID_CC3]->XferCpltCallback = TIM_DMADelayPulseCplt;


      htim->hdma[TIM_DMA_ID_CC3]->XferErrorCallback = TIM_DMAError ;


      HAL_DMA_Start_IT(htim->hdma[TIM_DMA_ID_CC3], (uint32_t)pData, (uint32_t)&htim->Instance->CCR3,Length);


      __HAL_TIM_ENABLE_DMA(htim, TIM_DMA_CC3);
    }
    break;

    default:
    break;
  }


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_ENABLE);


  __HAL_TIM_MOE_ENABLE(htim);


  __HAL_TIM_ENABLE(htim);


  return HAL_OK;
}












HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      __HAL_TIM_DISABLE_DMA(htim, TIM_DMA_CC1);
    }
    break;

    case TIM_CHANNEL_2:
    {

      __HAL_TIM_DISABLE_DMA(htim, TIM_DMA_CC2);
    }
    break;

    case TIM_CHANNEL_3:
    {

      __HAL_TIM_DISABLE_DMA(htim, TIM_DMA_CC3);
    }
    break;

    default:
    break;
  }


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_DISABLE);


  __HAL_TIM_MOE_DISABLE(htim);


  __HAL_TIM_DISABLE(htim);


  htim->State = HAL_TIM_STATE_READY;


  return HAL_OK;
}













































HAL_StatusTypeDef HAL_TIMEx_PWMN_Start(TIM_HandleTypeDef *htim, uint32_t Channel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_ENABLE);


  __HAL_TIM_MOE_ENABLE(htim);


  __HAL_TIM_ENABLE(htim);


  return HAL_OK;
}











HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_DISABLE);


  __HAL_TIM_MOE_DISABLE(htim);


  __HAL_TIM_DISABLE(htim);


  return HAL_OK;
}












HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC1);
    }
    break;

    case TIM_CHANNEL_2:
    {

      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC2);
    }
    break;

    case TIM_CHANNEL_3:
    {

      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC3);
    }
    break;

    default:
    break;
  }


  __HAL_TIM_ENABLE_IT(htim, TIM_IT_BREAK);


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_ENABLE);


  __HAL_TIM_MOE_ENABLE(htim);


  __HAL_TIM_ENABLE(htim);


  return HAL_OK;
}












HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_IT (TIM_HandleTypeDef *htim, uint32_t Channel)
{
  uint32_t tmpccer = 0U;


  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
    }
    break;

    case TIM_CHANNEL_2:
    {

      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC2);
    }
    break;

    case TIM_CHANNEL_3:
    {

      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC3);
    }
    break;

    default:
    break;
  }


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_DISABLE);


  tmpccer = htim->Instance->CCER;
  if ((tmpccer & (TIM_CCER_CC1NE | TIM_CCER_CC2NE | TIM_CCER_CC3NE)) == RESET)
  {
    __HAL_TIM_DISABLE_IT(htim, TIM_IT_BREAK);
  }


  __HAL_TIM_MOE_DISABLE(htim);


  __HAL_TIM_DISABLE(htim);


  return HAL_OK;
}














HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));

  if((htim->State == HAL_TIM_STATE_BUSY))
  {
     return HAL_BUSY;
  }
  else if((htim->State == HAL_TIM_STATE_READY))
  {
    if(((uint32_t)pData == 0U ) && (Length > 0U))
    {
      return HAL_ERROR;
    }
    else
    {
      htim->State = HAL_TIM_STATE_BUSY;
    }
  }
  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      htim->hdma[TIM_DMA_ID_CC1]->XferCpltCallback = TIM_DMADelayPulseCplt;


      htim->hdma[TIM_DMA_ID_CC1]->XferErrorCallback = TIM_DMAError ;


      HAL_DMA_Start_IT(htim->hdma[TIM_DMA_ID_CC1], (uint32_t)pData, (uint32_t)&htim->Instance->CCR1, Length);


      __HAL_TIM_ENABLE_DMA(htim, TIM_DMA_CC1);
    }
    break;

    case TIM_CHANNEL_2:
    {

      htim->hdma[TIM_DMA_ID_CC2]->XferCpltCallback = TIM_DMADelayPulseCplt;


      htim->hdma[TIM_DMA_ID_CC2]->XferErrorCallback = TIM_DMAError ;


      HAL_DMA_Start_IT(htim->hdma[TIM_DMA_ID_CC2], (uint32_t)pData, (uint32_t)&htim->Instance->CCR2, Length);


      __HAL_TIM_ENABLE_DMA(htim, TIM_DMA_CC2);
    }
    break;

    case TIM_CHANNEL_3:
    {

      htim->hdma[TIM_DMA_ID_CC3]->XferCpltCallback = TIM_DMADelayPulseCplt;


      htim->hdma[TIM_DMA_ID_CC3]->XferErrorCallback = TIM_DMAError ;


      HAL_DMA_Start_IT(htim->hdma[TIM_DMA_ID_CC3], (uint32_t)pData, (uint32_t)&htim->Instance->CCR3,Length);


      __HAL_TIM_ENABLE_DMA(htim, TIM_DMA_CC3);
    }
    break;

    default:
    break;
  }


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_ENABLE);


  __HAL_TIM_MOE_ENABLE(htim);


  __HAL_TIM_ENABLE(htim);


  return HAL_OK;
}












HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, Channel));

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      __HAL_TIM_DISABLE_DMA(htim, TIM_DMA_CC1);
    }
    break;

    case TIM_CHANNEL_2:
    {

      __HAL_TIM_DISABLE_DMA(htim, TIM_DMA_CC2);
    }
    break;

    case TIM_CHANNEL_3:
    {

      __HAL_TIM_DISABLE_DMA(htim, TIM_DMA_CC3);
    }
    break;

    default:
    break;
  }


  TIM_CCxNChannelCmd(htim->Instance, Channel, TIM_CCxN_DISABLE);


  __HAL_TIM_MOE_DISABLE(htim);


  __HAL_TIM_DISABLE(htim);


  htim->State = HAL_TIM_STATE_READY;


  return HAL_OK;
}

































HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, OutputChannel));


  TIM_CCxNChannelCmd(htim->Instance, OutputChannel, TIM_CCxN_ENABLE);


  __HAL_TIM_MOE_ENABLE(htim);


  return HAL_OK;
}











HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel)
{


  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, OutputChannel));


  TIM_CCxNChannelCmd(htim->Instance, OutputChannel, TIM_CCxN_DISABLE);


  __HAL_TIM_MOE_DISABLE(htim);


  __HAL_TIM_DISABLE(htim);


  return HAL_OK;
}











HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, OutputChannel));


  __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC1);


  __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC2);


  TIM_CCxNChannelCmd(htim->Instance, OutputChannel, TIM_CCxN_ENABLE);


  __HAL_TIM_MOE_ENABLE(htim);


  return HAL_OK;
}











HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel)
{

  assert_param(IS_TIM_CCXN_INSTANCE(htim->Instance, OutputChannel));


  __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);


  __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC2);


  TIM_CCxNChannelCmd(htim->Instance, OutputChannel, TIM_CCxN_DISABLE);


  __HAL_TIM_MOE_DISABLE(htim);


  __HAL_TIM_DISABLE(htim);


  return HAL_OK;
}
























#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)






















HAL_StatusTypeDef HAL_TIMEx_ConfigCommutationEvent(TIM_HandleTypeDef *htim, uint32_t  InputTrigger, uint32_t  CommutationSource)
{

  assert_param(IS_TIM_COMMUTATION_EVENT_INSTANCE(htim->Instance));
  assert_param(IS_TIM_INTERNAL_TRIGGEREVENT_SELECTION(InputTrigger));

  __HAL_LOCK(htim);

  if ((InputTrigger == TIM_TS_ITR0) || (InputTrigger == TIM_TS_ITR1) ||
      (InputTrigger == TIM_TS_ITR2) || (InputTrigger == TIM_TS_ITR3))
  {

    htim->Instance->SMCR &= ~TIM_SMCR_TS;
    htim->Instance->SMCR |= InputTrigger;
  }


  htim->Instance->CR2 |= TIM_CR2_CCPC;

  htim->Instance->CR2 &= ~TIM_CR2_CCUS;
  htim->Instance->CR2 |= CommutationSource;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}























HAL_StatusTypeDef HAL_TIMEx_ConfigCommutationEvent_IT(TIM_HandleTypeDef *htim, uint32_t  InputTrigger, uint32_t  CommutationSource)
{

  assert_param(IS_TIM_COMMUTATION_EVENT_INSTANCE(htim->Instance));
  assert_param(IS_TIM_INTERNAL_TRIGGEREVENT_SELECTION(InputTrigger));

  __HAL_LOCK(htim);

  if ((InputTrigger == TIM_TS_ITR0) || (InputTrigger == TIM_TS_ITR1) ||
      (InputTrigger == TIM_TS_ITR2) || (InputTrigger == TIM_TS_ITR3))
  {

    htim->Instance->SMCR &= ~TIM_SMCR_TS;
    htim->Instance->SMCR |= InputTrigger;
  }


  htim->Instance->CR2 |= TIM_CR2_CCPC;

  htim->Instance->CR2 &= ~TIM_CR2_CCUS;
  htim->Instance->CR2 |= CommutationSource;


  __HAL_TIM_ENABLE_IT(htim, TIM_IT_COM);

  __HAL_UNLOCK(htim);

  return HAL_OK;
}
























HAL_StatusTypeDef HAL_TIMEx_ConfigCommutationEvent_DMA(TIM_HandleTypeDef *htim, uint32_t  InputTrigger, uint32_t  CommutationSource)
{

  assert_param(IS_TIM_COMMUTATION_EVENT_INSTANCE(htim->Instance));
  assert_param(IS_TIM_INTERNAL_TRIGGEREVENT_SELECTION(InputTrigger));

  __HAL_LOCK(htim);

  if ((InputTrigger == TIM_TS_ITR0) || (InputTrigger == TIM_TS_ITR1) ||
      (InputTrigger == TIM_TS_ITR2) || (InputTrigger == TIM_TS_ITR3))
  {

    htim->Instance->SMCR &= ~TIM_SMCR_TS;
    htim->Instance->SMCR |= InputTrigger;
  }


  htim->Instance->CR2 |= TIM_CR2_CCPC;

  htim->Instance->CR2 &= ~TIM_CR2_CCUS;
  htim->Instance->CR2 |= CommutationSource;



  htim->hdma[TIM_DMA_ID_COMMUTATION]->XferCpltCallback = TIMEx_DMACommutationCplt;

  htim->hdma[TIM_DMA_ID_COMMUTATION]->XferErrorCallback = TIM_DMAError;


  __HAL_TIM_ENABLE_DMA(htim, TIM_DMA_COM);

  __HAL_UNLOCK(htim);

  return HAL_OK;
}


















HAL_StatusTypeDef HAL_TIM_OC_ConfigChannel(TIM_HandleTypeDef *htim,
                                           TIM_OC_InitTypeDef* sConfig,
                                           uint32_t Channel)
{

  assert_param(IS_TIM_CHANNELS(Channel));
  assert_param(IS_TIM_OC_MODE(sConfig->OCMode));
  assert_param(IS_TIM_OC_POLARITY(sConfig->OCPolarity));


  __HAL_LOCK(htim);

  htim->State = HAL_TIM_STATE_BUSY;

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      assert_param(IS_TIM_CC1_INSTANCE(htim->Instance));


      TIM_OC1_SetConfig(htim->Instance, sConfig);
    }
    break;

    case TIM_CHANNEL_2:
    {

      assert_param(IS_TIM_CC2_INSTANCE(htim->Instance));


      TIM_OC2_SetConfig(htim->Instance, sConfig);
    }
    break;

    case TIM_CHANNEL_3:
    {

      assert_param(IS_TIM_CC3_INSTANCE(htim->Instance));


      TIM_OC3_SetConfig(htim->Instance, sConfig);
    }
    break;

    case TIM_CHANNEL_4:
    {

      assert_param(IS_TIM_CC4_INSTANCE(htim->Instance));


       TIM_OC4_SetConfig(htim->Instance, sConfig);
    }
    break;

    case TIM_CHANNEL_5:
    {

      assert_param(IS_TIM_CC5_INSTANCE(htim->Instance));


       TIM_OC5_SetConfig(htim->Instance, sConfig);
    }
    break;

    case TIM_CHANNEL_6:
    {

      assert_param(IS_TIM_CC6_INSTANCE(htim->Instance));


       TIM_OC6_SetConfig(htim->Instance, sConfig);
    }
    break;

    default:
    break;
  }

  htim->State = HAL_TIM_STATE_READY;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}


















HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim,
                                            TIM_OC_InitTypeDef* sConfig,
                                            uint32_t Channel)
{

  assert_param(IS_TIM_CHANNELS(Channel));
  assert_param(IS_TIM_PWM_MODE(sConfig->OCMode));
  assert_param(IS_TIM_OC_POLARITY(sConfig->OCPolarity));
  assert_param(IS_TIM_FAST_STATE(sConfig->OCFastMode));


  __HAL_LOCK(htim);

  htim->State = HAL_TIM_STATE_BUSY;

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {

      assert_param(IS_TIM_CC1_INSTANCE(htim->Instance));


      TIM_OC1_SetConfig(htim->Instance, sConfig);


      htim->Instance->CCMR1 |= TIM_CCMR1_OC1PE;


      htim->Instance->CCMR1 &= ~TIM_CCMR1_OC1FE;
      htim->Instance->CCMR1 |= sConfig->OCFastMode;
    }
    break;

    case TIM_CHANNEL_2:
    {

      assert_param(IS_TIM_CC2_INSTANCE(htim->Instance));


      TIM_OC2_SetConfig(htim->Instance, sConfig);


      htim->Instance->CCMR1 |= TIM_CCMR1_OC2PE;


      htim->Instance->CCMR1 &= ~TIM_CCMR1_OC2FE;
      htim->Instance->CCMR1 |= sConfig->OCFastMode << 8U;
    }
    break;

    case TIM_CHANNEL_3:
    {

      assert_param(IS_TIM_CC3_INSTANCE(htim->Instance));


      TIM_OC3_SetConfig(htim->Instance, sConfig);


      htim->Instance->CCMR2 |= TIM_CCMR2_OC3PE;


      htim->Instance->CCMR2 &= ~TIM_CCMR2_OC3FE;
      htim->Instance->CCMR2 |= sConfig->OCFastMode;
    }
    break;

    case TIM_CHANNEL_4:
    {

      assert_param(IS_TIM_CC4_INSTANCE(htim->Instance));


      TIM_OC4_SetConfig(htim->Instance, sConfig);


      htim->Instance->CCMR2 |= TIM_CCMR2_OC4PE;


      htim->Instance->CCMR2 &= ~TIM_CCMR2_OC4FE;
      htim->Instance->CCMR2 |= sConfig->OCFastMode << 8U;
    }
    break;

    case TIM_CHANNEL_5:
    {

      assert_param(IS_TIM_CC5_INSTANCE(htim->Instance));


      TIM_OC5_SetConfig(htim->Instance, sConfig);


      htim->Instance->CCMR3 |= TIM_CCMR3_OC5PE;


      htim->Instance->CCMR3 &= ~TIM_CCMR3_OC5FE;
      htim->Instance->CCMR3 |= sConfig->OCFastMode;
    }
    break;

    case TIM_CHANNEL_6:
    {

      assert_param(IS_TIM_CC6_INSTANCE(htim->Instance));


      TIM_OC6_SetConfig(htim->Instance, sConfig);


      htim->Instance->CCMR3 |= TIM_CCMR3_OC6PE;


      htim->Instance->CCMR3 &= ~TIM_CCMR3_OC6FE;
      htim->Instance->CCMR3 |= sConfig->OCFastMode << 8U;
    }
    break;

    default:
    break;
  }

  htim->State = HAL_TIM_STATE_READY;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}










HAL_StatusTypeDef HAL_TIMEx_MasterConfigSynchronization(TIM_HandleTypeDef *htim,
                                                      TIM_MasterConfigTypeDef * sMasterConfig)
{
  uint32_t tmpcr2;
  uint32_t tmpsmcr;


  assert_param(IS_TIM_SYNCHRO_INSTANCE(htim->Instance));
  assert_param(IS_TIM_TRGO_SOURCE(sMasterConfig->MasterOutputTrigger));
  assert_param(IS_TIM_MSM_STATE(sMasterConfig->MasterSlaveMode));


  __HAL_LOCK(htim);


  tmpcr2 = htim->Instance->CR2;


  tmpsmcr = htim->Instance->SMCR;


  if (IS_TIM_TRGO2_INSTANCE(htim->Instance))
  {

    assert_param(IS_TIM_TRGO2_SOURCE(sMasterConfig->MasterOutputTrigger2));


    tmpcr2 &= ~TIM_CR2_MMS2;

    tmpcr2 |= sMasterConfig->MasterOutputTrigger2;
  }


  tmpcr2 &= ~TIM_CR2_MMS;

  tmpcr2 |=  sMasterConfig->MasterOutputTrigger;


  tmpsmcr &= ~TIM_SMCR_MSM;

  tmpsmcr |= sMasterConfig->MasterSlaveMode;


  htim->Instance->CR2 = tmpcr2;


  htim->Instance->SMCR = tmpsmcr;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}
#endif




#if defined(STM32F373xC) || defined(STM32F378xx)








HAL_StatusTypeDef HAL_TIMEx_MasterConfigSynchronization(TIM_HandleTypeDef *htim, TIM_MasterConfigTypeDef * sMasterConfig)
{

  assert_param(IS_TIM_MASTER_INSTANCE(htim->Instance));
  assert_param(IS_TIM_TRGO_SOURCE(sMasterConfig->MasterOutputTrigger));
  assert_param(IS_TIM_MSM_STATE(sMasterConfig->MasterSlaveMode));

  __HAL_LOCK(htim);

  htim->State = HAL_TIM_STATE_BUSY;


  htim->Instance->CR2 &= ~TIM_CR2_MMS;

  htim->Instance->CR2 |=  sMasterConfig->MasterOutputTrigger;


  htim->Instance->SMCR &= ~TIM_SMCR_MSM;

  htim->Instance->SMCR |= sMasterConfig->MasterSlaveMode;

  htim->State = HAL_TIM_STATE_READY;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)











HAL_StatusTypeDef HAL_TIMEx_ConfigBreakDeadTime(TIM_HandleTypeDef *htim,
                                                TIM_BreakDeadTimeConfigTypeDef * sBreakDeadTimeConfig)
{
  uint32_t tmpbdtr = 0U;


  assert_param(IS_TIM_BREAK_INSTANCE(htim->Instance));
  assert_param(IS_TIM_OSSR_STATE(sBreakDeadTimeConfig->OffStateRunMode));
  assert_param(IS_TIM_OSSI_STATE(sBreakDeadTimeConfig->OffStateIDLEMode));
  assert_param(IS_TIM_LOCK_LEVEL(sBreakDeadTimeConfig->LockLevel));
  assert_param(IS_TIM_DEADTIME(sBreakDeadTimeConfig->DeadTime));
  assert_param(IS_TIM_BREAK_STATE(sBreakDeadTimeConfig->BreakState));
  assert_param(IS_TIM_BREAK_POLARITY(sBreakDeadTimeConfig->BreakPolarity));
  assert_param(IS_TIM_BREAK_FILTER(sBreakDeadTimeConfig->BreakFilter));
  assert_param(IS_TIM_AUTOMATIC_OUTPUT_STATE(sBreakDeadTimeConfig->AutomaticOutput));


  __HAL_LOCK(htim);





  MODIFY_REG(tmpbdtr, TIM_BDTR_DTG, sBreakDeadTimeConfig->DeadTime);
  MODIFY_REG(tmpbdtr, TIM_BDTR_LOCK, sBreakDeadTimeConfig->LockLevel);
  MODIFY_REG(tmpbdtr, TIM_BDTR_OSSI, sBreakDeadTimeConfig->OffStateIDLEMode);
  MODIFY_REG(tmpbdtr, TIM_BDTR_OSSR, sBreakDeadTimeConfig->OffStateRunMode);
  MODIFY_REG(tmpbdtr, TIM_BDTR_BKE, sBreakDeadTimeConfig->BreakState);
  MODIFY_REG(tmpbdtr, TIM_BDTR_BKP, sBreakDeadTimeConfig->BreakPolarity);
  MODIFY_REG(tmpbdtr, TIM_BDTR_AOE, sBreakDeadTimeConfig->AutomaticOutput);
  MODIFY_REG(tmpbdtr, TIM_BDTR_MOE, sBreakDeadTimeConfig->AutomaticOutput);
  MODIFY_REG(tmpbdtr, TIM_BDTR_BKF, (sBreakDeadTimeConfig->BreakFilter << BDTR_BKF_SHIFT));

  if (IS_TIM_BKIN2_INSTANCE(htim->Instance))
  {
    assert_param(IS_TIM_BREAK2_STATE(sBreakDeadTimeConfig->Break2State));
    assert_param(IS_TIM_BREAK2_POLARITY(sBreakDeadTimeConfig->Break2Polarity));
    assert_param(IS_TIM_BREAK_FILTER(sBreakDeadTimeConfig->Break2Filter));


    MODIFY_REG(tmpbdtr, TIM_BDTR_BK2F, (sBreakDeadTimeConfig->Break2Filter << BDTR_BK2F_SHIFT));
    MODIFY_REG(tmpbdtr, TIM_BDTR_BK2E, sBreakDeadTimeConfig->Break2State);
    MODIFY_REG(tmpbdtr, TIM_BDTR_BK2P, sBreakDeadTimeConfig->Break2Polarity);
  }


  htim->Instance->BDTR = tmpbdtr;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}
#endif




#if defined(STM32F373xC) || defined(STM32F378xx)








HAL_StatusTypeDef HAL_TIMEx_ConfigBreakDeadTime(TIM_HandleTypeDef *htim,
                                                TIM_BreakDeadTimeConfigTypeDef *sBreakDeadTimeConfig)
{
  uint32_t tmpbdtr = 0U;


  assert_param(IS_TIM_BREAK_INSTANCE(htim->Instance));
  assert_param(IS_TIM_OSSR_STATE(sBreakDeadTimeConfig->OffStateRunMode));
  assert_param(IS_TIM_OSSI_STATE(sBreakDeadTimeConfig->OffStateIDLEMode));
  assert_param(IS_TIM_LOCK_LEVEL(sBreakDeadTimeConfig->LockLevel));
  assert_param(IS_TIM_DEADTIME(sBreakDeadTimeConfig->DeadTime));
  assert_param(IS_TIM_BREAK_STATE(sBreakDeadTimeConfig->BreakState));
  assert_param(IS_TIM_BREAK_POLARITY(sBreakDeadTimeConfig->BreakPolarity));
  assert_param(IS_TIM_AUTOMATIC_OUTPUT_STATE(sBreakDeadTimeConfig->AutomaticOutput));


  __HAL_LOCK(htim);

  htim->State = HAL_TIM_STATE_BUSY;





  MODIFY_REG(tmpbdtr, TIM_BDTR_DTG, sBreakDeadTimeConfig->DeadTime);
  MODIFY_REG(tmpbdtr, TIM_BDTR_LOCK, sBreakDeadTimeConfig->LockLevel);
  MODIFY_REG(tmpbdtr, TIM_BDTR_OSSI, sBreakDeadTimeConfig->OffStateIDLEMode);
  MODIFY_REG(tmpbdtr, TIM_BDTR_OSSR, sBreakDeadTimeConfig->OffStateRunMode);
  MODIFY_REG(tmpbdtr, TIM_BDTR_BKE, sBreakDeadTimeConfig->BreakState);
  MODIFY_REG(tmpbdtr, TIM_BDTR_BKP, sBreakDeadTimeConfig->BreakPolarity);
  MODIFY_REG(tmpbdtr, TIM_BDTR_AOE, sBreakDeadTimeConfig->AutomaticOutput);
  MODIFY_REG(tmpbdtr, TIM_BDTR_MOE, sBreakDeadTimeConfig->AutomaticOutput);


  htim->Instance->BDTR = tmpbdtr;

  htim->State = HAL_TIM_STATE_READY;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}
#endif

#if defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F303xC) || defined(STM32F358xx) || \
	defined(STM32F334x8)
#if defined(STM32F303xE) || defined(STM32F398xx)






































#elif defined(STM32F303xC) || defined(STM32F358xx)





























#else





















#endif
HAL_StatusTypeDef HAL_TIMEx_RemapConfig(TIM_HandleTypeDef *htim, uint32_t Remap1, uint32_t Remap2)
{
  __HAL_LOCK(htim);


  assert_param(IS_TIM_REMAP_INSTANCE(htim->Instance));
  assert_param(IS_TIM_REMAP(Remap1));
  assert_param(IS_TIM_REMAP2(Remap2));


  htim->Instance->OR = Remap1 | Remap2;

  htim->State = HAL_TIM_STATE_READY;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}
#endif



#if defined(STM32F302xE)                                                 || \
    defined(STM32F302xC)                                                 || \
    defined(STM32F303x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) || \
    defined(STM32F373xC) || defined(STM32F378xx)
#if defined(STM32F302xE)                                                 || \
    defined(STM32F302xC)                                                 || \
    defined(STM32F303x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)















#else
















#endif



HAL_StatusTypeDef HAL_TIMEx_RemapConfig(TIM_HandleTypeDef *htim, uint32_t Remap)
{
  __HAL_LOCK(htim);


  assert_param(IS_TIM_REMAP_INSTANCE(htim->Instance));
  assert_param(IS_TIM_REMAP(Remap));


  htim->Instance->OR = Remap;

  htim->State = HAL_TIM_STATE_READY;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}
#endif






#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)











HAL_StatusTypeDef HAL_TIMEx_GroupChannel5(TIM_HandleTypeDef *htim, uint32_t Channels)
{

  assert_param(IS_TIM_COMBINED3PHASEPWM_INSTANCE(htim->Instance));
  assert_param(IS_TIM_GROUPCH5(Channels));


  __HAL_LOCK(htim);

  htim->State = HAL_TIM_STATE_BUSY;


  htim->Instance->CCR5 &= ~(TIM_CCR5_GC5C3|TIM_CCR5_GC5C2|TIM_CCR5_GC5C1);


  htim->Instance->CCR5 |= Channels;

  htim->State = HAL_TIM_STATE_READY;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}
#endif











#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

















HAL_StatusTypeDef HAL_TIM_ConfigOCrefClear(TIM_HandleTypeDef *htim,
                                           TIM_ClearInputConfigTypeDef *sClearInputConfig,
                                           uint32_t Channel)
{
  uint32_t tmpsmcr = 0U;


  assert_param(IS_TIM_OCXREF_CLEAR_INSTANCE(htim->Instance));
  assert_param(IS_TIM_CLEARINPUT_SOURCE(sClearInputConfig->ClearInputSource));


  __HAL_LOCK(htim);

  htim->State = HAL_TIM_STATE_BUSY;

  switch (sClearInputConfig->ClearInputSource)
  {
    case TIM_CLEARINPUTSOURCE_NONE:
    {

      tmpsmcr = htim->Instance->SMCR;


      tmpsmcr &= ~TIM_SMCR_OCCS;


      tmpsmcr &= ~(TIM_SMCR_ETF | TIM_SMCR_ETPS | TIM_SMCR_ECE | TIM_SMCR_ETP);


      htim->Instance->SMCR = tmpsmcr;
   }
    break;

    case TIM_CLEARINPUTSOURCE_OCREFCLR:
    {

      htim->Instance->SMCR &= ~TIM_SMCR_OCCS;
    }
    break;

    case TIM_CLEARINPUTSOURCE_ETR:
    {

      assert_param(IS_TIM_CLEARINPUT_POLARITY(sClearInputConfig->ClearInputPolarity));
      assert_param(IS_TIM_CLEARINPUT_PRESCALER(sClearInputConfig->ClearInputPrescaler));
      assert_param(IS_TIM_CLEARINPUT_FILTER(sClearInputConfig->ClearInputFilter));

      TIM_ETR_SetConfig(htim->Instance,
                        sClearInputConfig->ClearInputPrescaler,
                        sClearInputConfig->ClearInputPolarity,
                        sClearInputConfig->ClearInputFilter);


      htim->Instance->SMCR |= TIM_SMCR_OCCS;
    }
    break;
    default:
    break;
  }

  switch (Channel)
  {
    case TIM_CHANNEL_1:
      {
        if(sClearInputConfig->ClearInputState != RESET)
        {

          htim->Instance->CCMR1 |= TIM_CCMR1_OC1CE;
        }
        else
        {

          htim->Instance->CCMR1 &= ~TIM_CCMR1_OC1CE;
        }
      }
      break;
    case TIM_CHANNEL_2:
      {
        if(sClearInputConfig->ClearInputState != RESET)
        {

          htim->Instance->CCMR1 |= TIM_CCMR1_OC2CE;
        }
        else
        {

          htim->Instance->CCMR1 &= ~TIM_CCMR1_OC2CE;
        }
      }
    break;
    case TIM_CHANNEL_3:
      {
        if(sClearInputConfig->ClearInputState != RESET)
        {

          htim->Instance->CCMR2 |= TIM_CCMR2_OC3CE;
        }
        else
        {

          htim->Instance->CCMR2 &= ~TIM_CCMR2_OC3CE;
        }
      }
    break;
    case TIM_CHANNEL_4:
      {
        if(sClearInputConfig->ClearInputState != RESET)
        {

          htim->Instance->CCMR2 |= TIM_CCMR2_OC4CE;
        }
        else
        {

          htim->Instance->CCMR2 &= ~TIM_CCMR2_OC4CE;
        }
      }
    break;
    case TIM_CHANNEL_5:
      {
        if(sClearInputConfig->ClearInputState != RESET)
        {

          htim->Instance->CCMR3 |= TIM_CCMR3_OC5CE;
        }
        else
        {

          htim->Instance->CCMR3 &= ~TIM_CCMR3_OC5CE;
        }
      }
    break;
    case TIM_CHANNEL_6:
      {
        if(sClearInputConfig->ClearInputState != RESET)
        {

          htim->Instance->CCMR3 |= TIM_CCMR3_OC6CE;
        }
        else
        {

          htim->Instance->CCMR3 &= ~TIM_CCMR3_OC6CE;
        }
      }
    break;
    default:
    break;
  }

  htim->State = HAL_TIM_STATE_READY;

  __HAL_UNLOCK(htim);

  return HAL_OK;
}
#endif




























__weak void HAL_TIMEx_CommutationCallback(TIM_HandleTypeDef *htim)
{

  UNUSED(htim);




}






__weak void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef *htim)
{

  UNUSED(htim);




}






__weak void HAL_TIMEx_Break2Callback(TIM_HandleTypeDef *htim)
{

  UNUSED(htim);




}

























HAL_TIM_StateTypeDef HAL_TIMEx_HallSensor_GetState(TIM_HandleTypeDef *htim)
{
  return htim->State;
}

















void TIMEx_DMACommutationCplt(DMA_HandleTypeDef *hdma)
{
  TIM_HandleTypeDef* htim = ( TIM_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;

  htim->State= HAL_TIM_STATE_READY;

  HAL_TIMEx_CommutationCallback(htim);
}













static void TIM_CCxNChannelCmd(TIM_TypeDef* TIMx, uint32_t Channel, uint32_t ChannelNState)
{
  uint32_t tmp = 0U;

  tmp = TIM_CCER_CC1NE << Channel;


  TIMx->CCER &=  ~tmp;


  TIMx->CCER |=  (uint32_t)(ChannelNState << Channel);
}

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)






static void TIM_OC5_SetConfig(TIM_TypeDef *TIMx,
                              TIM_OC_InitTypeDef *OC_Config)
{
  uint32_t tmpccmrx = 0U;
  uint32_t tmpccer = 0U;
  uint32_t tmpcr2 = 0U;


  TIMx->CCER &= ~TIM_CCER_CC5E;


  tmpccer = TIMx->CCER;

  tmpcr2 =  TIMx->CR2;

  tmpccmrx = TIMx->CCMR3;


  tmpccmrx &= ~(TIM_CCMR3_OC5M);

  tmpccmrx |= OC_Config->OCMode;


  tmpccer &= ~TIM_CCER_CC5P;

  tmpccer |= (OC_Config->OCPolarity << 16U);

  if(IS_TIM_BREAK_INSTANCE(TIMx))
  {

    tmpcr2 &= ~TIM_CR2_OIS5;

    tmpcr2 |= (OC_Config->OCIdleState << 8U);
  }

  TIMx->CR2 = tmpcr2;


  TIMx->CCMR3 = tmpccmrx;


  TIMx->CCR5 = OC_Config->Pulse;


  TIMx->CCER = tmpccer;
}







static void TIM_OC6_SetConfig(TIM_TypeDef *TIMx,
                              TIM_OC_InitTypeDef *OC_Config)
{
  uint32_t tmpccmrx = 0U;
  uint32_t tmpccer = 0U;
  uint32_t tmpcr2 = 0U;


  TIMx->CCER &= ~TIM_CCER_CC6E;


  tmpccer = TIMx->CCER;

  tmpcr2 =  TIMx->CR2;

  tmpccmrx = TIMx->CCMR3;


  tmpccmrx &= ~(TIM_CCMR3_OC6M);

  tmpccmrx |= (OC_Config->OCMode << 8U);


  tmpccer &= (uint32_t)~TIM_CCER_CC6P;

  tmpccer |= (OC_Config->OCPolarity << 20U);

  if(IS_TIM_BREAK_INSTANCE(TIMx))
  {

    tmpcr2 &= ~TIM_CR2_OIS6;

    tmpcr2 |= (OC_Config->OCIdleState << 10U);
  }


  TIMx->CR2 = tmpcr2;


  TIMx->CCMR3 = tmpccmrx;


  TIMx->CCR6 = OC_Config->Pulse;


  TIMx->CCER = tmpccer;
}
#endif







#endif









