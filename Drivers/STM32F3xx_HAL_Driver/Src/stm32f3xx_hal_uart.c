






























































































































































#include "stm32f3xx_hal.h"










#ifdef HAL_UART_MODULE_ENABLED






#define UART_CR1_FIELDS  ((uint32_t)(USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | \
                                     USART_CR1_TE | USART_CR1_RE | USART_CR1_OVER8))










static void UART_EndTxTransfer(UART_HandleTypeDef *huart);
static void UART_EndRxTransfer(UART_HandleTypeDef *huart);
static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma);
static void UART_DMATxHalfCplt(DMA_HandleTypeDef *hdma);
static void UART_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void UART_DMARxHalfCplt(DMA_HandleTypeDef *hdma);
static void UART_DMAError(DMA_HandleTypeDef *hdma);
static void UART_DMAAbortOnError(DMA_HandleTypeDef *hdma);
static void UART_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef UART_Transmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_EndTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_Receive_IT(UART_HandleTypeDef *huart);

























































































HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart)
{

  if(huart == NULL)
  {
    return HAL_ERROR;
  }

  if(huart->Init.HwFlowCtl != UART_HWCONTROL_NONE)
  {

    assert_param(IS_UART_HWFLOW_INSTANCE(huart->Instance));
  }
  else
  {

    assert_param(IS_UART_INSTANCE(huart->Instance));
  }

  if(huart->gState == HAL_UART_STATE_RESET)
  {

    huart->Lock = HAL_UNLOCKED;


    HAL_UART_MspInit(huart);
  }

  huart->gState = HAL_UART_STATE_BUSY;


  __HAL_UART_DISABLE(huart);


  if (UART_SetConfig(huart) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

  if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT)
  {
    UART_AdvFeatureConfig(huart);
  }




  CLEAR_BIT(huart->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(huart->Instance->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));


  __HAL_UART_ENABLE(huart);


  return (UART_CheckIdleState(huart));
}







HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart)
{

  if(huart == NULL)
  {
    return HAL_ERROR;
  }


  assert_param(IS_UART_HALFDUPLEX_INSTANCE(huart->Instance));

  if(huart->gState == HAL_UART_STATE_RESET)
  {

    huart->Lock = HAL_UNLOCKED;


    HAL_UART_MspInit(huart);
  }

  huart->gState = HAL_UART_STATE_BUSY;


  __HAL_UART_DISABLE(huart);


  if (UART_SetConfig(huart) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

  if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT)
  {
    UART_AdvFeatureConfig(huart);
  }




  CLEAR_BIT(huart->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(huart->Instance->CR3, (USART_CR3_IREN | USART_CR3_SCEN));


  SET_BIT(huart->Instance->CR3, USART_CR3_HDSEL);


  __HAL_UART_ENABLE(huart);


  return (UART_CheckIdleState(huart));
}












HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength)
{

  if(huart == NULL)
  {
    return HAL_ERROR;
  }


  assert_param(IS_UART_LIN_INSTANCE(huart->Instance));

  assert_param(IS_UART_LIN_BREAK_DETECT_LENGTH(BreakDetectLength));


  if(huart->Init.OverSampling == UART_OVERSAMPLING_8)
  {
    return HAL_ERROR;
  }

  if(huart->Init.WordLength != UART_WORDLENGTH_8B)
  {
    return HAL_ERROR;
  }

  if(huart->gState == HAL_UART_STATE_RESET)
  {

    huart->Lock = HAL_UNLOCKED;


    HAL_UART_MspInit(huart);
  }

  huart->gState = HAL_UART_STATE_BUSY;


  __HAL_UART_DISABLE(huart);


  if (UART_SetConfig(huart) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

  if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT)
  {
    UART_AdvFeatureConfig(huart);
  }




  CLEAR_BIT(huart->Instance->CR2, USART_CR2_CLKEN);
  CLEAR_BIT(huart->Instance->CR3, (USART_CR3_HDSEL | USART_CR3_IREN | USART_CR3_SCEN));


  SET_BIT(huart->Instance->CR2, USART_CR2_LINEN);


  MODIFY_REG(huart->Instance->CR2, USART_CR2_LBDL, BreakDetectLength);


  __HAL_UART_ENABLE(huart);


  return (UART_CheckIdleState(huart));
}




















HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod)
{

  if(huart == NULL)
  {
    return HAL_ERROR;
  }


  assert_param(IS_UART_WAKEUPMETHOD(WakeUpMethod));

  if(huart->gState == HAL_UART_STATE_RESET)
  {

    huart->Lock = HAL_UNLOCKED;


    HAL_UART_MspInit(huart);
  }

  huart->gState = HAL_UART_STATE_BUSY;


  __HAL_UART_DISABLE(huart);


  if (UART_SetConfig(huart) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

  if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT)
  {
    UART_AdvFeatureConfig(huart);
  }




  CLEAR_BIT(huart->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(huart->Instance->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

  if (WakeUpMethod == UART_WAKEUPMETHOD_ADDRESSMARK)
  {

    MODIFY_REG(huart->Instance->CR2, USART_CR2_ADD, ((uint32_t)Address << UART_CR2_ADDRESS_LSB_POS));
  }


  MODIFY_REG(huart->Instance->CR1, USART_CR1_WAKE, WakeUpMethod);


  __HAL_UART_ENABLE(huart);


  return (UART_CheckIdleState(huart));
}







HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart)
{

  if(huart == NULL)
  {
    return HAL_ERROR;
  }


  assert_param(IS_UART_INSTANCE(huart->Instance));

  huart->gState = HAL_UART_STATE_BUSY;


  __HAL_UART_DISABLE(huart);

  huart->Instance->CR1 = 0x0U;
  huart->Instance->CR2 = 0x0U;
  huart->Instance->CR3 = 0x0U;


  HAL_UART_MspDeInit(huart);

  huart->ErrorCode = HAL_UART_ERROR_NONE;
  huart->gState    = HAL_UART_STATE_RESET;
  huart->RxState   = HAL_UART_STATE_RESET;


  __HAL_UNLOCK(huart);

  return HAL_OK;
}






__weak void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}






__weak void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}


























































































HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint16_t* tmp;
  uint32_t tickstart = 0U;


  if(huart->gState == HAL_UART_STATE_READY)
  {
    if((pData == NULL ) || (Size == 0U))
    {
      return  HAL_ERROR;
    }


    __HAL_LOCK(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;


    tickstart = HAL_GetTick();

    huart->TxXferSize = Size;
    huart->TxXferCount = Size;
    while(huart->TxXferCount > 0U)
    {
      huart->TxXferCount--;
      if(UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_TXE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
      if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.Parity == UART_PARITY_NONE))
      {
        tmp = (uint16_t*) pData;
        huart->Instance->TDR = (*tmp & (uint16_t)0x01FFU);
        pData += 2U;
      }
      else
      {
        huart->Instance->TDR = (*pData++ & (uint8_t)0xFFU);
      }
    }
    if(UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_TC, RESET, tickstart, Timeout) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }


    huart->gState = HAL_UART_STATE_READY;


    __HAL_UNLOCK(huart);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}









HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint16_t* tmp;
  uint16_t uhMask;
  uint32_t tickstart = 0U;


  if(huart->RxState == HAL_UART_STATE_READY)
  {
    if((pData == NULL ) || (Size == 0U))
    {
      return  HAL_ERROR;
    }


    __HAL_LOCK(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->RxState = HAL_UART_STATE_BUSY_RX;


    tickstart = HAL_GetTick();

    huart->RxXferSize = Size;
    huart->RxXferCount = Size;


    UART_MASK_COMPUTATION(huart);
    uhMask = huart->Mask;


    while(huart->RxXferCount > 0U)
    {
      huart->RxXferCount--;
      if(UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_RXNE, RESET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
      if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.Parity == UART_PARITY_NONE))
      {
        tmp = (uint16_t*) pData ;
        *tmp = (uint16_t)(huart->Instance->RDR & uhMask);
        pData +=2U;
      }
      else
      {
        *pData++ = (uint8_t)(huart->Instance->RDR & (uint8_t)uhMask);
      }
    }


    huart->RxState = HAL_UART_STATE_READY;


    __HAL_UNLOCK(huart);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}








HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{

  if(huart->gState == HAL_UART_STATE_READY)
  {
    if((pData == NULL ) || (Size == 0U))
    {
      return HAL_ERROR;
    }


    __HAL_LOCK(huart);

    huart->pTxBuffPtr = pData;
    huart->TxXferSize = Size;
    huart->TxXferCount = Size;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;


    __HAL_UNLOCK(huart);


    SET_BIT(huart->Instance->CR1, USART_CR1_TXEIE);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}








HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{

  if(huart->RxState == HAL_UART_STATE_READY)
  {
    if((pData == NULL ) || (Size == 0U))
    {
      return HAL_ERROR;
    }


    __HAL_LOCK(huart);

    huart->pRxBuffPtr = pData;
    huart->RxXferSize = Size;
    huart->RxXferCount = Size;


    UART_MASK_COMPUTATION(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->RxState = HAL_UART_STATE_BUSY_RX;


    __HAL_UNLOCK(huart);


    SET_BIT(huart->Instance->CR3, USART_CR3_EIE);


    SET_BIT(huart->Instance->CR1, USART_CR1_PEIE | USART_CR1_RXNEIE);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}











HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{

  assert_param(IS_UART_DMA_INSTANCE(huart->Instance));


  if(huart->gState == HAL_UART_STATE_READY)
  {
    if((pData == NULL ) || (Size == 0U))
    {
      return HAL_ERROR;
    }


    __HAL_LOCK(huart);

    huart->pTxBuffPtr = pData;
    huart->TxXferSize = Size;
    huart->TxXferCount = Size;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;


    huart->hdmatx->XferCpltCallback = UART_DMATransmitCplt;


    huart->hdmatx->XferHalfCpltCallback = UART_DMATxHalfCplt;


    huart->hdmatx->XferErrorCallback = UART_DMAError;


    huart->hdmatx->XferAbortCallback = NULL;


    HAL_DMA_Start_IT(huart->hdmatx, (uint32_t)huart->pTxBuffPtr, (uint32_t)&huart->Instance->TDR, Size);


    __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_TCF);


    __HAL_UNLOCK(huart);



    SET_BIT(huart->Instance->CR3, USART_CR3_DMAT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}













HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{

  assert_param(IS_UART_DMA_INSTANCE(huart->Instance));


  if(huart->RxState == HAL_UART_STATE_READY)
  {
    if((pData == NULL ) || (Size == 0U))
    {
      return HAL_ERROR;
    }


    __HAL_LOCK(huart);

    huart->pRxBuffPtr = pData;
    huart->RxXferSize = Size;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->RxState = HAL_UART_STATE_BUSY_RX;


    huart->hdmarx->XferCpltCallback = UART_DMAReceiveCplt;


    huart->hdmarx->XferHalfCpltCallback = UART_DMARxHalfCplt;


    huart->hdmarx->XferErrorCallback = UART_DMAError;


    huart->hdmarx->XferAbortCallback = NULL;


    HAL_DMA_Start_IT(huart->hdmarx, (uint32_t)&huart->Instance->RDR, (uint32_t)huart->pRxBuffPtr, Size);


    __HAL_UNLOCK(huart);


    SET_BIT(huart->Instance->CR1, USART_CR1_PEIE);


    SET_BIT(huart->Instance->CR3, USART_CR3_EIE);



    SET_BIT(huart->Instance->CR3, USART_CR3_DMAR);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}






HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart)
{

  __HAL_LOCK(huart);

  if ((huart->gState == HAL_UART_STATE_BUSY_TX) &&
      (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT)))
  {

    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);
  }
  if ((huart->RxState == HAL_UART_STATE_BUSY_RX) &&
      (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)))
  {

    CLEAR_BIT(huart->Instance->CR1, USART_CR1_PEIE);
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);


    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);
  }


  __HAL_UNLOCK(huart);

  return HAL_OK;
}






HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart)
{

  __HAL_LOCK(huart);

  if(huart->gState == HAL_UART_STATE_BUSY_TX)
  {

    SET_BIT(huart->Instance->CR3, USART_CR3_DMAT);
  }
  if(huart->RxState == HAL_UART_STATE_BUSY_RX)
  {

    __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF);


    SET_BIT(huart->Instance->CR1, USART_CR1_PEIE);
    SET_BIT(huart->Instance->CR3, USART_CR3_EIE);


    SET_BIT(huart->Instance->CR3, USART_CR3_DMAR);
  }


  __HAL_UNLOCK(huart);

  return HAL_OK;
}






HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart)
{








  if ((huart->gState == HAL_UART_STATE_BUSY_TX) &&
      (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT)))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);


    if(huart->hdmatx != NULL)
    {
      HAL_DMA_Abort(huart->hdmatx);
    }

    UART_EndTxTransfer(huart);
  }


  if ((huart->RxState == HAL_UART_STATE_BUSY_RX) &&
      (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);


    if(huart->hdmarx != NULL)
    {
      HAL_DMA_Abort(huart->hdmarx);
    }

    UART_EndRxTransfer(huart);
  }

  return HAL_OK;
}













HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart)
{

  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE | USART_CR1_TCIE));
  CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);


  if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);


    if(huart->hdmatx != NULL)
    {


      huart->hdmatx->XferAbortCallback = NULL;

      HAL_DMA_Abort(huart->hdmatx);
    }
  }


  if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);


    if(huart->hdmarx != NULL)
    {


      huart->hdmarx->XferAbortCallback = NULL;

      HAL_DMA_Abort(huart->hdmarx);
    }
  }


  huart->TxXferCount = 0U;
  huart->RxXferCount = 0U;


  __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);


  huart->gState  = HAL_UART_STATE_READY;
  huart->RxState = HAL_UART_STATE_READY;


  huart->ErrorCode = HAL_UART_ERROR_NONE;

  return HAL_OK;
}













HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart)
{

  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TXEIE | USART_CR1_TCIE));


  if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);


    if(huart->hdmatx != NULL)
    {


      huart->hdmatx->XferAbortCallback = NULL;

      HAL_DMA_Abort(huart->hdmatx);
    }
  }


  huart->TxXferCount = 0U;


  huart->gState = HAL_UART_STATE_READY;

  return HAL_OK;
}













HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart)
{

  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
  CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);


  if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);


    if(huart->hdmarx != NULL)
    {


      huart->hdmarx->XferAbortCallback = NULL;

      HAL_DMA_Abort(huart->hdmarx);
    }
  }


  huart->RxXferCount = 0U;


  __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);


  huart->RxState = HAL_UART_STATE_READY;

  return HAL_OK;
}















HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart)
{
  uint32_t abortcplt = 1U;


  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE | USART_CR1_TCIE));
  CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);




  if(huart->hdmatx != NULL)
  {


    if(HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT))
    {
      huart->hdmatx->XferAbortCallback = UART_DMATxAbortCallback;
    }
    else
    {
      huart->hdmatx->XferAbortCallback = NULL;
    }
  }

  if(huart->hdmarx != NULL)
  {


    if(HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
    {
      huart->hdmarx->XferAbortCallback = UART_DMARxAbortCallback;
    }
    else
    {
      huart->hdmarx->XferAbortCallback = NULL;
    }
  }


  if(HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT))
  {

    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);


    if(huart->hdmatx != NULL)
    {




      if(HAL_DMA_Abort_IT(huart->hdmatx) != HAL_OK)
      {
        huart->hdmatx->XferAbortCallback = NULL;
      }
      else
      {
        abortcplt = 0U;
      }
    }
  }


  if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);


    if(huart->hdmarx != NULL)
    {




      if(HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK)
      {
        huart->hdmarx->XferAbortCallback = NULL;
        abortcplt = 1U;
      }
      else
      {
        abortcplt = 0U;
      }
    }
  }


  if (abortcplt == 1U)
  {

    huart->TxXferCount = 0U;
    huart->RxXferCount = 0U;


    huart->ErrorCode = HAL_UART_ERROR_NONE;


    __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);


    huart->gState  = HAL_UART_STATE_READY;
    huart->RxState = HAL_UART_STATE_READY;


    HAL_UART_AbortCpltCallback(huart);
  }

  return HAL_OK;
}















HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart)
{

  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TXEIE | USART_CR1_TCIE));


  if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);


    if(huart->hdmatx != NULL)
    {


      huart->hdmatx->XferAbortCallback = UART_DMATxOnlyAbortCallback;


      if(HAL_DMA_Abort_IT(huart->hdmatx) != HAL_OK)
      {

        huart->hdmatx->XferAbortCallback(huart->hdmatx);
      }
    }
    else
    {

      huart->TxXferCount = 0U;


      huart->gState = HAL_UART_STATE_READY;


      HAL_UART_AbortTransmitCpltCallback(huart);
    }
  }
  else
  {

    huart->TxXferCount = 0U;


    huart->gState = HAL_UART_STATE_READY;


    HAL_UART_AbortTransmitCpltCallback(huart);
  }

  return HAL_OK;
}















HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart)
{

  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
  CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);


  if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);


    if(huart->hdmarx != NULL)
    {


      huart->hdmarx->XferAbortCallback = UART_DMARxOnlyAbortCallback;


      if(HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK)
      {

        huart->hdmarx->XferAbortCallback(huart->hdmarx);
      }
    }
    else
    {

      huart->RxXferCount = 0U;


      __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);


      huart->RxState = HAL_UART_STATE_READY;


      HAL_UART_AbortReceiveCpltCallback(huart);
    }
  }
  else
  {

    huart->RxXferCount = 0U;


    __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);


    huart->RxState = HAL_UART_STATE_READY;


    HAL_UART_AbortReceiveCpltCallback(huart);
  }

  return HAL_OK;
}






void HAL_UART_IRQHandler(UART_HandleTypeDef *huart)
{
  uint32_t isrflags   = READ_REG(huart->Instance->ISR);
  uint32_t cr1its     = READ_REG(huart->Instance->CR1);
  uint32_t cr3its;
  uint32_t errorflags;


  errorflags = (isrflags & (uint32_t)(USART_ISR_PE | USART_ISR_FE | USART_ISR_ORE | USART_ISR_NE));
  if (errorflags == RESET)
  {

    if(((isrflags & USART_ISR_RXNE) != RESET) && ((cr1its & USART_CR1_RXNEIE) != RESET))
    {
      UART_Receive_IT(huart);
      return;
    }
  }


  cr3its = READ_REG(huart->Instance->CR3);
  if(   (errorflags != RESET)
     && (   ((cr3its & USART_CR3_EIE) != RESET)
         || ((cr1its & (USART_CR1_RXNEIE | USART_CR1_PEIE)) != RESET)) )
  {

    if(((isrflags & USART_ISR_PE) != RESET) && ((cr1its & USART_CR1_PEIE) != RESET))
    {
      __HAL_UART_CLEAR_IT(huart, UART_CLEAR_PEF);

      huart->ErrorCode |= HAL_UART_ERROR_PE;
    }


    if(((isrflags & USART_ISR_FE) != RESET) && ((cr3its & USART_CR3_EIE) != RESET))
    {
      __HAL_UART_CLEAR_IT(huart, UART_CLEAR_FEF);

      huart->ErrorCode |= HAL_UART_ERROR_FE;
    }


    if(((isrflags & USART_ISR_NE) != RESET) && ((cr3its & USART_CR3_EIE) != RESET))
    {
      __HAL_UART_CLEAR_IT(huart, UART_CLEAR_NEF);

      huart->ErrorCode |= HAL_UART_ERROR_NE;
    }


    if(((isrflags & USART_ISR_ORE) != RESET) &&
       (((cr1its & USART_CR1_RXNEIE) != RESET) || ((cr3its & USART_CR3_EIE) != RESET)))
    {
      __HAL_UART_CLEAR_IT(huart, UART_CLEAR_OREF);

      huart->ErrorCode |= HAL_UART_ERROR_ORE;
    }


    if(huart->ErrorCode != HAL_UART_ERROR_NONE)
    {

      if(((isrflags & USART_ISR_RXNE) != RESET) && ((cr1its & USART_CR1_RXNEIE) != RESET))
      {
        UART_Receive_IT(huart);
      }



      if (((huart->ErrorCode & HAL_UART_ERROR_ORE) != RESET) ||
          (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)))
      {



        UART_EndRxTransfer(huart);


        if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
        {
          CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);


          if(huart->hdmarx != NULL)
          {


            huart->hdmarx->XferAbortCallback = UART_DMAAbortOnError;


            if(HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK)
            {

              huart->hdmarx->XferAbortCallback(huart->hdmarx);
            }
          }
          else
          {

            HAL_UART_ErrorCallback(huart);
          }
        }
        else
        {

          HAL_UART_ErrorCallback(huart);
        }
      }
      else
      {


        HAL_UART_ErrorCallback(huart);
        huart->ErrorCode = HAL_UART_ERROR_NONE;
      }
    }
    return;

  }


  if(((isrflags & USART_ISR_WUF) != RESET) && ((cr3its & USART_CR3_WUFIE) != RESET))
  {
    __HAL_UART_CLEAR_IT(huart, UART_CLEAR_WUF);

    huart->gState  = HAL_UART_STATE_READY;
    huart->RxState = HAL_UART_STATE_READY;
    HAL_UARTEx_WakeupCallback(huart);
    return;
  }


  if(((isrflags & USART_ISR_TXE) != RESET) && ((cr1its & USART_CR1_TXEIE) != RESET))
  {
    UART_Transmit_IT(huart);
    return;
  }


  if(((isrflags & USART_ISR_TC) != RESET) && ((cr1its & USART_CR1_TCIE) != RESET))
  {
    UART_EndTransmit_IT(huart);
    return;
  }

}






__weak void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}






__weak void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}






__weak void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}






__weak void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}






__weak void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}






__weak void HAL_UART_AbortCpltCallback (UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}






__weak void HAL_UART_AbortTransmitCpltCallback (UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}






__weak void HAL_UART_AbortReceiveCpltCallback (UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}






























HAL_StatusTypeDef HAL_MultiProcessor_EnableMuteMode(UART_HandleTypeDef *huart)
{

  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;


  SET_BIT(huart->Instance->CR1, USART_CR1_MME);

  huart->gState = HAL_UART_STATE_READY;

  return (UART_CheckIdleState(huart));
}







HAL_StatusTypeDef HAL_MultiProcessor_DisableMuteMode(UART_HandleTypeDef *huart)
{

  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;


  CLEAR_BIT(huart->Instance->CR1, USART_CR1_MME);

  huart->gState = HAL_UART_STATE_READY;

  return (UART_CheckIdleState(huart));
}







void HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart)
{
  __HAL_UART_SEND_REQ(huart, UART_MUTE_MODE_REQUEST);
}






HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart)
{

  __HAL_LOCK(huart);
  huart->gState = HAL_UART_STATE_BUSY;


  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TE | USART_CR1_RE));

  SET_BIT(huart->Instance->CR1, USART_CR1_TE);

  huart->gState = HAL_UART_STATE_READY;


  __HAL_UNLOCK(huart);

  return HAL_OK;
}






HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart)
{

  __HAL_LOCK(huart);
  huart->gState = HAL_UART_STATE_BUSY;


  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TE | USART_CR1_RE));

  SET_BIT(huart->Instance->CR1, USART_CR1_RE);

  huart->gState = HAL_UART_STATE_READY;

  __HAL_UNLOCK(huart);

  return HAL_OK;
}







HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart)
{

  assert_param(IS_UART_LIN_INSTANCE(huart->Instance));


  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;


  huart->Instance->RQR |= UART_SENDBREAK_REQUEST;

  huart->gState = HAL_UART_STATE_READY;


  __HAL_UNLOCK(huart);

  return HAL_OK;
}




























HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart)
{
  uint32_t temp1= 0x00U, temp2 = 0x00U;
  temp1 = huart->gState;
  temp2 = huart->RxState;

  return (HAL_UART_StateTypeDef)(temp1 | temp2);
}







uint32_t HAL_UART_GetError(UART_HandleTypeDef *huart)
{
  return huart->ErrorCode;
}

















HAL_StatusTypeDef UART_SetConfig(UART_HandleTypeDef *huart)
{
  uint32_t tmpreg                     = 0x00000000U;
  UART_ClockSourceTypeDef clocksource = UART_CLOCKSOURCE_UNDEFINED;
  uint16_t brrtemp                    = 0x0000U;
  uint16_t usartdiv                   = 0x0000U;
  HAL_StatusTypeDef ret               = HAL_OK;


  assert_param(IS_UART_BAUDRATE(huart->Init.BaudRate));
  assert_param(IS_UART_WORD_LENGTH(huart->Init.WordLength));
  assert_param(IS_UART_STOPBITS(huart->Init.StopBits));
  assert_param(IS_UART_PARITY(huart->Init.Parity));
  assert_param(IS_UART_MODE(huart->Init.Mode));
  assert_param(IS_UART_HARDWARE_FLOW_CONTROL(huart->Init.HwFlowCtl));
  assert_param(IS_UART_ONE_BIT_SAMPLE(huart->Init.OneBitSampling));
  assert_param(IS_UART_OVERSAMPLING(huart->Init.OverSampling));









  tmpreg = (uint32_t)huart->Init.WordLength | huart->Init.Parity | huart->Init.Mode | huart->Init.OverSampling ;
  MODIFY_REG(huart->Instance->CR1, UART_CR1_FIELDS, tmpreg);




  MODIFY_REG(huart->Instance->CR2, USART_CR2_STOP, huart->Init.StopBits);







  tmpreg = (uint32_t)huart->Init.HwFlowCtl | huart->Init.OneBitSampling ;
  MODIFY_REG(huart->Instance->CR3, (USART_CR3_RTSE | USART_CR3_CTSE | USART_CR3_ONEBIT), tmpreg);


  UART_GETCLOCKSOURCE(huart, clocksource);


  if (huart->Init.OverSampling == UART_OVERSAMPLING_8)
  {
    switch (clocksource)
    {
      case UART_CLOCKSOURCE_PCLK1:
        usartdiv = (uint16_t)(UART_DIV_SAMPLING8(HAL_RCC_GetPCLK1Freq(), huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_PCLK2:
        usartdiv = (uint16_t)(UART_DIV_SAMPLING8(HAL_RCC_GetPCLK2Freq(), huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_HSI:
        usartdiv = (uint16_t)(UART_DIV_SAMPLING8(HSI_VALUE, huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_SYSCLK:
        usartdiv = (uint16_t)(UART_DIV_SAMPLING8(HAL_RCC_GetSysClockFreq(), huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_LSE:
        usartdiv = (uint16_t)(UART_DIV_SAMPLING8(LSE_VALUE, huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_UNDEFINED:
      default:
        ret = HAL_ERROR;
        break;
    }

    brrtemp = usartdiv & 0xFFF0U;
    brrtemp |= (uint16_t)((usartdiv & (uint16_t)0x000FU) >> 1U);
    huart->Instance->BRR = brrtemp;
  }
  else
  {
    switch (clocksource)
    {
      case UART_CLOCKSOURCE_PCLK1:
        huart->Instance->BRR = (uint16_t)(UART_DIV_SAMPLING16(HAL_RCC_GetPCLK1Freq(), huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_PCLK2:
        huart->Instance->BRR = (uint16_t)(UART_DIV_SAMPLING16(HAL_RCC_GetPCLK2Freq(), huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_HSI:
        huart->Instance->BRR = (uint16_t)(UART_DIV_SAMPLING16(HSI_VALUE, huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_SYSCLK:
        huart->Instance->BRR = (uint16_t)(UART_DIV_SAMPLING16(HAL_RCC_GetSysClockFreq(), huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_LSE:
        huart->Instance->BRR = (uint16_t)(UART_DIV_SAMPLING16(LSE_VALUE, huart->Init.BaudRate));
        break;
      case UART_CLOCKSOURCE_UNDEFINED:
      default:
        ret = HAL_ERROR;
        break;
    }
  }

  return ret;

}






void UART_AdvFeatureConfig(UART_HandleTypeDef *huart)
{

  assert_param(IS_UART_ADVFEATURE_INIT(huart->AdvancedInit.AdvFeatureInit));


  if(HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit, UART_ADVFEATURE_TXINVERT_INIT))
  {
    assert_param(IS_UART_ADVFEATURE_TXINV(huart->AdvancedInit.TxPinLevelInvert));
    MODIFY_REG(huart->Instance->CR2, USART_CR2_TXINV, huart->AdvancedInit.TxPinLevelInvert);
  }


  if(HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit, UART_ADVFEATURE_RXINVERT_INIT))
  {
    assert_param(IS_UART_ADVFEATURE_RXINV(huart->AdvancedInit.RxPinLevelInvert));
    MODIFY_REG(huart->Instance->CR2, USART_CR2_RXINV, huart->AdvancedInit.RxPinLevelInvert);
  }


  if(HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit, UART_ADVFEATURE_DATAINVERT_INIT))
  {
    assert_param(IS_UART_ADVFEATURE_DATAINV(huart->AdvancedInit.DataInvert));
    MODIFY_REG(huart->Instance->CR2, USART_CR2_DATAINV, huart->AdvancedInit.DataInvert);
  }


  if(HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit, UART_ADVFEATURE_SWAP_INIT))
  {
    assert_param(IS_UART_ADVFEATURE_SWAP(huart->AdvancedInit.Swap));
    MODIFY_REG(huart->Instance->CR2, USART_CR2_SWAP, huart->AdvancedInit.Swap);
  }


  if(HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit, UART_ADVFEATURE_RXOVERRUNDISABLE_INIT))
  {
    assert_param(IS_UART_OVERRUN(huart->AdvancedInit.OverrunDisable));
    MODIFY_REG(huart->Instance->CR3, USART_CR3_OVRDIS, huart->AdvancedInit.OverrunDisable);
  }


  if(HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit, UART_ADVFEATURE_DMADISABLEONERROR_INIT))
  {
    assert_param(IS_UART_ADVFEATURE_DMAONRXERROR(huart->AdvancedInit.DMADisableonRxError));
    MODIFY_REG(huart->Instance->CR3, USART_CR3_DDRE, huart->AdvancedInit.DMADisableonRxError);
  }


  if(HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit, UART_ADVFEATURE_AUTOBAUDRATE_INIT))
  {
    assert_param(IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(huart->Instance));
    assert_param(IS_UART_ADVFEATURE_AUTOBAUDRATE(huart->AdvancedInit.AutoBaudRateEnable));
    MODIFY_REG(huart->Instance->CR2, USART_CR2_ABREN, huart->AdvancedInit.AutoBaudRateEnable);

    if(huart->AdvancedInit.AutoBaudRateEnable == UART_ADVFEATURE_AUTOBAUDRATE_ENABLE)
    {
      assert_param(IS_UART_ADVFEATURE_AUTOBAUDRATEMODE(huart->AdvancedInit.AutoBaudRateMode));
      MODIFY_REG(huart->Instance->CR2, USART_CR2_ABRMODE, huart->AdvancedInit.AutoBaudRateMode);
    }
  }


  if(HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit, UART_ADVFEATURE_MSBFIRST_INIT))
  {
    assert_param(IS_UART_ADVFEATURE_MSBFIRST(huart->AdvancedInit.MSBFirst));
    MODIFY_REG(huart->Instance->CR2, USART_CR2_MSBFIRST, huart->AdvancedInit.MSBFirst);
  }
}






HAL_StatusTypeDef UART_CheckIdleState(UART_HandleTypeDef *huart)
{
  uint32_t tickstart = 0U;


  huart->ErrorCode = HAL_UART_ERROR_NONE;


  tickstart = HAL_GetTick();


  if((huart->Instance->CR1 & USART_CR1_TE) == USART_CR1_TE)
  {

    if(UART_WaitOnFlagUntilTimeout(huart, USART_ISR_TEACK, RESET, tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK)
    {

      return HAL_TIMEOUT;
    }
  }

  if((huart->Instance->CR1 & USART_CR1_RE) == USART_CR1_RE)
  {

    if(UART_WaitOnFlagUntilTimeout(huart, USART_ISR_REACK, RESET, tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK)
    {

      return HAL_TIMEOUT;
    }
  }


  huart->gState  = HAL_UART_STATE_READY;
  huart->RxState = HAL_UART_STATE_READY;


  __HAL_UNLOCK(huart);

  return HAL_OK;
}










HAL_StatusTypeDef UART_WaitOnFlagUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout)
{

  while((__HAL_UART_GET_FLAG(huart, Flag) ? SET : RESET) == Status)
  {

    if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick()-Tickstart) > Timeout))
      {

        CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE));
        CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

        huart->gState  = HAL_UART_STATE_READY;
        huart->RxState = HAL_UART_STATE_READY;


        __HAL_UNLOCK(huart);
        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}







static void UART_EndTxTransfer(UART_HandleTypeDef *huart)
{

  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TXEIE | USART_CR1_TCIE));


  huart->gState = HAL_UART_STATE_READY;
}







static void UART_EndRxTransfer(UART_HandleTypeDef *huart)
{

  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
  CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);


  huart->RxState = HAL_UART_STATE_READY;
}







static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef*)(hdma->Parent);


  if ( HAL_IS_BIT_CLR(hdma->Instance->CCR, DMA_CCR_CIRC) )
  {
    huart->TxXferCount = 0U;



    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);


    SET_BIT(huart->Instance->CR1, USART_CR1_TCIE);
  }

  else
  {
    HAL_UART_TxCpltCallback(huart);
  }

}






static void UART_DMATxHalfCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef*)(hdma->Parent);

  HAL_UART_TxHalfCpltCallback(huart);
}






static void UART_DMAReceiveCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef*)(hdma->Parent);


  if ( HAL_IS_BIT_CLR(hdma->Instance->CCR, DMA_CCR_CIRC) )
  {
    huart->RxXferCount = 0U;


    CLEAR_BIT(huart->Instance->CR1, USART_CR1_PEIE);
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);



    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);


    huart->RxState = HAL_UART_STATE_READY;
  }

  HAL_UART_RxCpltCallback(huart);
}






static void UART_DMARxHalfCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef*)(hdma->Parent);

  HAL_UART_RxHalfCpltCallback(huart);
}






static void UART_DMAError(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef*)(hdma->Parent);


  if (  (huart->gState == HAL_UART_STATE_BUSY_TX)
      &&(HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT)) )
  {
    huart->TxXferCount = 0U;
    UART_EndTxTransfer(huart);
  }


  if (  (huart->RxState == HAL_UART_STATE_BUSY_RX)
      &&(HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)) )
  {
    huart->RxXferCount = 0U;
    UART_EndRxTransfer(huart);
  }

  huart->ErrorCode |= HAL_UART_ERROR_DMA;
  HAL_UART_ErrorCallback(huart);
}







static void UART_DMAAbortOnError(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef*)(hdma->Parent);
  huart->RxXferCount = 0U;
  huart->TxXferCount = 0U;

  HAL_UART_ErrorCallback(huart);
}









static void UART_DMATxAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef* )(hdma->Parent);

  huart->hdmatx->XferAbortCallback = NULL;


  if(huart->hdmarx != NULL)
  {
    if(huart->hdmarx->XferAbortCallback != NULL)
    {
      return;
    }
  }


  huart->TxXferCount = 0U;
  huart->RxXferCount = 0U;


  huart->ErrorCode = HAL_UART_ERROR_NONE;


  __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);


  huart->gState  = HAL_UART_STATE_READY;
  huart->RxState = HAL_UART_STATE_READY;


  HAL_UART_AbortCpltCallback(huart);
}










static void UART_DMARxAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef* )(hdma->Parent);

  huart->hdmarx->XferAbortCallback = NULL;


  if(huart->hdmatx != NULL)
  {
    if(huart->hdmatx->XferAbortCallback != NULL)
    {
      return;
    }
  }


  huart->TxXferCount = 0U;
  huart->RxXferCount = 0U;


  huart->ErrorCode = HAL_UART_ERROR_NONE;


  __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);


  huart->gState  = HAL_UART_STATE_READY;
  huart->RxState = HAL_UART_STATE_READY;


  HAL_UART_AbortCpltCallback(huart);
}










static void UART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef*)(hdma->Parent);

  huart->TxXferCount = 0U;


  huart->gState = HAL_UART_STATE_READY;


  HAL_UART_AbortTransmitCpltCallback(huart);
}









static void UART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = ( UART_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;

  huart->RxXferCount = 0U;


  __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);


  huart->RxState = HAL_UART_STATE_READY;


  HAL_UART_AbortReceiveCpltCallback(huart);
}








HAL_StatusTypeDef UART_Transmit_IT(UART_HandleTypeDef *huart)
{
  uint16_t* tmp;


  if (huart->gState == HAL_UART_STATE_BUSY_TX)
  {
    if(huart->TxXferCount == 0U)
    {

      CLEAR_BIT(huart->Instance->CR1, USART_CR1_TXEIE);


      SET_BIT(huart->Instance->CR1, USART_CR1_TCIE);

      return HAL_OK;
    }
    else
    {
      if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.Parity == UART_PARITY_NONE))
      {
        tmp = (uint16_t*) huart->pTxBuffPtr;
        huart->Instance->TDR = (*tmp & (uint16_t)0x01FFU);
        huart->pTxBuffPtr += 2U;
      }
      else
      {
        huart->Instance->TDR = (uint8_t)(*huart->pTxBuffPtr++ & (uint8_t)0xFFU);
      }
      huart->TxXferCount--;

      return HAL_OK;
    }
  }
  else
  {
    return HAL_BUSY;
  }
}







HAL_StatusTypeDef UART_EndTransmit_IT(UART_HandleTypeDef *huart)
{

  CLEAR_BIT(huart->Instance->CR1, USART_CR1_TCIE);


  huart->gState = HAL_UART_STATE_READY;

  HAL_UART_TxCpltCallback(huart);

  return HAL_OK;
}








HAL_StatusTypeDef UART_Receive_IT(UART_HandleTypeDef *huart)
{
  uint16_t* tmp;
  uint16_t  uhMask = huart->Mask;
  uint16_t  uhdata;


  if(huart->RxState == HAL_UART_STATE_BUSY_RX)
  {
    uhdata = (uint16_t) READ_REG(huart->Instance->RDR);
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.Parity == UART_PARITY_NONE))
    {
      tmp = (uint16_t*) huart->pRxBuffPtr ;
      *tmp = (uint16_t)(uhdata & uhMask);
      huart->pRxBuffPtr +=2U;
    }
    else
    {
      *huart->pRxBuffPtr++ = (uint8_t)(uhdata & (uint8_t)uhMask);
    }

    if(--huart->RxXferCount == 0U)
    {

      CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));


      CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);


      huart->RxState = HAL_UART_STATE_READY;

      HAL_UART_RxCpltCallback(huart);

      return HAL_OK;
    }

    return HAL_OK;
  }
  else
  {

    __HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);

    return HAL_BUSY;
  }
}







void UART_Wakeup_AddressConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection)
{
  assert_param(IS_UART_ADDRESSLENGTH_DETECT(WakeUpSelection.AddressLength));


  MODIFY_REG(huart->Instance->CR2, USART_CR2_ADDM7, WakeUpSelection.AddressLength);


  MODIFY_REG(huart->Instance->CR2, USART_CR2_ADD, ((uint32_t)WakeUpSelection.Address << UART_CR2_ADDRESS_LSB_POS));
}





#endif









