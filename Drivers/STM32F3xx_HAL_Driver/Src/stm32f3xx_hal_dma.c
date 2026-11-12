




























































































#include "stm32f3xx_hal.h"










#ifdef HAL_DMA_MODULE_ENABLED









static void DMA_SetConfig(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
static void DMA_CalcBaseAndBitshift(DMA_HandleTypeDef *hdma);




































HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma)
{
  uint32_t tmp = 0U;


  if(NULL == hdma)
  {
    return HAL_ERROR;
  }


  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
  assert_param(IS_DMA_DIRECTION(hdma->Init.Direction));
  assert_param(IS_DMA_PERIPHERAL_INC_STATE(hdma->Init.PeriphInc));
  assert_param(IS_DMA_MEMORY_INC_STATE(hdma->Init.MemInc));
  assert_param(IS_DMA_PERIPHERAL_DATA_SIZE(hdma->Init.PeriphDataAlignment));
  assert_param(IS_DMA_MEMORY_DATA_SIZE(hdma->Init.MemDataAlignment));
  assert_param(IS_DMA_MODE(hdma->Init.Mode));
  assert_param(IS_DMA_PRIORITY(hdma->Init.Priority));


  hdma->State = HAL_DMA_STATE_BUSY;


  tmp = hdma->Instance->CCR;


  tmp &= ((uint32_t)~(DMA_CCR_PL    | DMA_CCR_MSIZE  | DMA_CCR_PSIZE  | \
                      DMA_CCR_MINC  | DMA_CCR_PINC   | DMA_CCR_CIRC   | \
                      DMA_CCR_DIR));


  tmp |=  hdma->Init.Direction        |
          hdma->Init.PeriphInc           | hdma->Init.MemInc           |
          hdma->Init.PeriphDataAlignment | hdma->Init.MemDataAlignment |
          hdma->Init.Mode                | hdma->Init.Priority;


  hdma->Instance->CCR = tmp;



  DMA_CalcBaseAndBitshift(hdma);


  hdma->ErrorCode = HAL_DMA_ERROR_NONE;


  hdma->State = HAL_DMA_STATE_READY;


  hdma->Lock = HAL_UNLOCKED;

  return HAL_OK;
}







HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma)
{

  if(NULL == hdma)
  {
    return HAL_ERROR;
  }


  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));


  hdma->Instance->CCR &= ~DMA_CCR_EN;


  hdma->Instance->CCR  = 0U;


  hdma->Instance->CNDTR = 0U;


  hdma->Instance->CPAR  = 0U;


  hdma->Instance->CMAR = 0U;


  DMA_CalcBaseAndBitshift(hdma);


  hdma->DmaBaseAddress->IFCR = DMA_FLAG_GL1 << hdma->ChannelIndex;


  hdma->XferCpltCallback = NULL;
  hdma->XferHalfCpltCallback = NULL;
  hdma->XferErrorCallback = NULL;
  hdma->XferAbortCallback = NULL;


  hdma->ErrorCode = HAL_DMA_ERROR_NONE;


  hdma->State = HAL_DMA_STATE_RESET;


  __HAL_UNLOCK(hdma);

  return HAL_OK;
}

































HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
	HAL_StatusTypeDef status = HAL_OK;


  assert_param(IS_DMA_BUFFER_SIZE(DataLength));


  __HAL_LOCK(hdma);

  if(HAL_DMA_STATE_READY == hdma->State)
  {

  	hdma->State = HAL_DMA_STATE_BUSY;

  	hdma->ErrorCode = HAL_DMA_ERROR_NONE;


  	hdma->Instance->CCR &= ~DMA_CCR_EN;


  	DMA_SetConfig(hdma, SrcAddress, DstAddress, DataLength);


  	hdma->Instance->CCR |= DMA_CCR_EN;
  }
  else
  {

  	__HAL_UNLOCK(hdma);


  	status = HAL_BUSY;
  }

  return status;
}










HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
	HAL_StatusTypeDef status = HAL_OK;


  assert_param(IS_DMA_BUFFER_SIZE(DataLength));


  __HAL_LOCK(hdma);

  if(HAL_DMA_STATE_READY == hdma->State)
  {

  	hdma->State = HAL_DMA_STATE_BUSY;

  	hdma->ErrorCode = HAL_DMA_ERROR_NONE;


  	hdma->Instance->CCR &= ~DMA_CCR_EN;


  	DMA_SetConfig(hdma, SrcAddress, DstAddress, DataLength);



    if(NULL != hdma->XferHalfCpltCallback )
    {
      hdma->Instance->CCR |= (DMA_IT_TC | DMA_IT_HT | DMA_IT_TE);
    }
  	else
  	{
  		hdma->Instance->CCR |= (DMA_IT_TC | DMA_IT_TE);
  		hdma->Instance->CCR &= ~DMA_IT_HT;
  	}


  	hdma->Instance->CCR |= DMA_CCR_EN;
  }
  else
  {

    __HAL_UNLOCK(hdma);


    status = HAL_BUSY;
  }

  return status;
}







HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma)
{

	 hdma->Instance->CCR &= ~(DMA_IT_TC | DMA_IT_HT | DMA_IT_TE);


	hdma->Instance->CCR &= ~DMA_CCR_EN;


	hdma->DmaBaseAddress->IFCR = (DMA_FLAG_GL1 << hdma->ChannelIndex);


	hdma->State = HAL_DMA_STATE_READY;


	__HAL_UNLOCK(hdma);

	return HAL_OK;
}







HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma)
{
  HAL_StatusTypeDef status = HAL_OK;

  if(HAL_DMA_STATE_BUSY != hdma->State)
  {

    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;

    status = HAL_ERROR;
  }
  else
  {


    hdma->Instance->CCR &= ~(DMA_IT_TC | DMA_IT_HT | DMA_IT_TE);


    hdma->Instance->CCR &= ~DMA_CCR_EN;


    hdma->DmaBaseAddress->IFCR = DMA_FLAG_GL1 << hdma->ChannelIndex;


    hdma->State = HAL_DMA_STATE_READY;


    __HAL_UNLOCK(hdma);


    if(hdma->XferAbortCallback != NULL)
    {
      hdma->XferAbortCallback(hdma);
    }
  }
  return status;
}









HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, uint32_t CompleteLevel, uint32_t Timeout)
{
  uint32_t temp;
  uint32_t tickstart = 0U;

  if(HAL_DMA_STATE_BUSY != hdma->State)
  {

    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;
    __HAL_UNLOCK(hdma);
    return HAL_ERROR;
  }


  if (RESET != (hdma->Instance->CCR & DMA_CCR_CIRC))
  {
    hdma->ErrorCode = HAL_DMA_ERROR_NOT_SUPPORTED;
    return HAL_ERROR;
  }


  if(HAL_DMA_FULL_TRANSFER == CompleteLevel)
  {

    temp = DMA_FLAG_TC1 << hdma->ChannelIndex;
  }
  else
  {

    temp = DMA_FLAG_HT1 << hdma->ChannelIndex;
  }


  tickstart = HAL_GetTick();

  while(RESET == (hdma->DmaBaseAddress->ISR & temp))
  {
    if(RESET != (hdma->DmaBaseAddress->ISR & (DMA_FLAG_TE1 << hdma->ChannelIndex)))
    {



      hdma->DmaBaseAddress->IFCR = DMA_FLAG_GL1 << hdma->ChannelIndex;


      hdma->ErrorCode = HAL_DMA_ERROR_TE;


      hdma->State= HAL_DMA_STATE_READY;


      __HAL_UNLOCK(hdma);

      return HAL_ERROR;
    }

    if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick() - tickstart) > Timeout))
      {

        hdma->ErrorCode = HAL_DMA_ERROR_TIMEOUT;


        hdma->State = HAL_DMA_STATE_READY;


        __HAL_UNLOCK(hdma);

        return HAL_ERROR;
      }
    }
  }

  if(HAL_DMA_FULL_TRANSFER == CompleteLevel)
  {

    hdma->DmaBaseAddress->IFCR = DMA_FLAG_TC1 << hdma->ChannelIndex;



    hdma->State = HAL_DMA_STATE_READY;
  }
  else
  {

    hdma->DmaBaseAddress->IFCR = DMA_FLAG_HT1 << hdma->ChannelIndex;
  }


  __HAL_UNLOCK(hdma);

  return HAL_OK;
}







void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma)
{
	uint32_t flag_it = hdma->DmaBaseAddress->ISR;
  uint32_t source_it = hdma->Instance->CCR;


  if ((RESET != (flag_it & (DMA_FLAG_HT1 << hdma->ChannelIndex))) && (RESET != (source_it & DMA_IT_HT)))
  {

  	if((hdma->Instance->CCR & DMA_CCR_CIRC) == 0U)
  	{

  		hdma->Instance->CCR &= ~DMA_IT_HT;
  	}


  	hdma->DmaBaseAddress->IFCR = DMA_FLAG_HT1 << hdma->ChannelIndex;




  	if(hdma->XferHalfCpltCallback != NULL)
  	{

  		hdma->XferHalfCpltCallback(hdma);
  	}
  }


  else if ((RESET != (flag_it & (DMA_FLAG_TC1 << hdma->ChannelIndex))) && (RESET != (source_it & DMA_IT_TC)))
  {
  	if((hdma->Instance->CCR & DMA_CCR_CIRC) == 0U)
  	{


  		hdma->Instance->CCR &= ~(DMA_IT_TC | DMA_IT_TE);


  		hdma->State = HAL_DMA_STATE_READY;
  	}


  	hdma->DmaBaseAddress->IFCR = DMA_FLAG_TC1 << hdma->ChannelIndex;


  	__HAL_UNLOCK(hdma);

  	if(hdma->XferCpltCallback != NULL)
  	{

  		hdma->XferCpltCallback(hdma);
  	}
  }


  else if (( RESET != (flag_it & (DMA_FLAG_TE1 << hdma->ChannelIndex))) && (RESET != (source_it & DMA_IT_TE)))
  {



    hdma->Instance->CCR &= ~(DMA_IT_TC | DMA_IT_HT | DMA_IT_TE);


    hdma->DmaBaseAddress->IFCR = DMA_FLAG_GL1 << hdma->ChannelIndex;


    hdma->ErrorCode = HAL_DMA_ERROR_TE;


    hdma->State = HAL_DMA_STATE_READY;


    __HAL_UNLOCK(hdma);

    if(hdma->XferErrorCallback != NULL)
    {

    	hdma->XferErrorCallback(hdma);
    }
  }
}











HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)( DMA_HandleTypeDef * _hdma))
{
  HAL_StatusTypeDef status = HAL_OK;


  __HAL_LOCK(hdma);

  if(HAL_DMA_STATE_READY == hdma->State)
  {
    switch (CallbackID)
    {
     case  HAL_DMA_XFER_CPLT_CB_ID:
           hdma->XferCpltCallback = pCallback;
           break;

     case  HAL_DMA_XFER_HALFCPLT_CB_ID:
           hdma->XferHalfCpltCallback = pCallback;
           break;

     case  HAL_DMA_XFER_ERROR_CB_ID:
           hdma->XferErrorCallback = pCallback;
           break;

     case  HAL_DMA_XFER_ABORT_CB_ID:
           hdma->XferAbortCallback = pCallback;
           break;

     default:
           status = HAL_ERROR;
           break;
    }
  }
  else
  {
    status = HAL_ERROR;
  }


  __HAL_UNLOCK(hdma);

  return status;
}









HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;


  __HAL_LOCK(hdma);

  if(HAL_DMA_STATE_READY == hdma->State)
  {
    switch (CallbackID)
    {
     case  HAL_DMA_XFER_CPLT_CB_ID:
           hdma->XferCpltCallback = NULL;
           break;

     case  HAL_DMA_XFER_HALFCPLT_CB_ID:
           hdma->XferHalfCpltCallback = NULL;
           break;

     case  HAL_DMA_XFER_ERROR_CB_ID:
           hdma->XferErrorCallback = NULL;
           break;

     case  HAL_DMA_XFER_ABORT_CB_ID:
           hdma->XferAbortCallback = NULL;
           break;

    case   HAL_DMA_XFER_ALL_CB_ID:
           hdma->XferCpltCallback = NULL;
           hdma->XferHalfCpltCallback = NULL;
           hdma->XferErrorCallback = NULL;
           hdma->XferAbortCallback = NULL;
           break;

    default:
           status = HAL_ERROR;
           break;
    }
  }
  else
  {
    status = HAL_ERROR;
  }


  __HAL_UNLOCK(hdma);

  return status;
}



























HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma)
{
  return hdma->State;
}







uint32_t HAL_DMA_GetError(DMA_HandleTypeDef *hdma)
{
  return hdma->ErrorCode;
}






















static void DMA_SetConfig(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{

  hdma->DmaBaseAddress->IFCR  = (DMA_FLAG_GL1 << hdma->ChannelIndex);


  hdma->Instance->CNDTR = DataLength;


  if((hdma->Init.Direction) == DMA_MEMORY_TO_PERIPH)
  {

    hdma->Instance->CPAR = DstAddress;


    hdma->Instance->CMAR = SrcAddress;
  }

  else
  {

    hdma->Instance->CPAR = SrcAddress;


    hdma->Instance->CMAR = DstAddress;
  }
}







static void DMA_CalcBaseAndBitshift(DMA_HandleTypeDef *hdma)
{
#if defined (DMA2)

  if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel1))
  {

    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2U;
    hdma->DmaBaseAddress = DMA1;
  }
  else
  {

    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA2_Channel1) / ((uint32_t)DMA2_Channel2 - (uint32_t)DMA2_Channel1)) << 2U;
    hdma->DmaBaseAddress = DMA2;
  }
#else


  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2U;
  hdma->DmaBaseAddress = DMA1;
#endif
}








#endif










