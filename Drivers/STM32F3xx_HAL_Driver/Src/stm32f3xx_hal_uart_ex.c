





















































#include "stm32f3xx_hal.h"










#ifdef HAL_UART_MODULE_ENABLED







































































































HAL_StatusTypeDef HAL_RS485Ex_Init(UART_HandleTypeDef *huart, uint32_t Polarity, uint32_t AssertionTime, uint32_t DeassertionTime)
{
  uint32_t temp = 0x0U;


  if(huart == NULL)
  {
    return HAL_ERROR;
  }

  assert_param(IS_UART_DRIVER_ENABLE_INSTANCE(huart->Instance));


  assert_param(IS_UART_DE_POLARITY(Polarity));


  assert_param(IS_UART_ASSERTIONTIME(AssertionTime));


  assert_param(IS_UART_DEASSERTIONTIME(DeassertionTime));

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

  if(huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT)
  {
    UART_AdvFeatureConfig(huart);
  }


  SET_BIT(huart->Instance->CR3, USART_CR3_DEM);


  MODIFY_REG(huart->Instance->CR3, USART_CR3_DEP, Polarity);


  temp = (AssertionTime << UART_CR1_DEAT_ADDRESS_LSB_POS);
  temp |= (DeassertionTime << UART_CR1_DEDT_ADDRESS_LSB_POS);
  MODIFY_REG(huart->Instance->CR1, (USART_CR1_DEDT|USART_CR1_DEAT), temp);


  __HAL_UART_ENABLE(huart);


  return (UART_CheckIdleState(huart));
}






























__weak void HAL_UARTEx_WakeupCallback(UART_HandleTypeDef *huart)
{

  UNUSED(huart);




}



































HAL_StatusTypeDef HAL_UARTEx_StopModeWakeUpSourceConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = 0U;


  assert_param(IS_UART_WAKEUP_FROMSTOP_INSTANCE(huart->Instance));

  assert_param(IS_UART_WAKEUP_SELECTION(WakeUpSelection.WakeUpEvent));


  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;


  __HAL_UART_DISABLE(huart);


  MODIFY_REG(huart->Instance->CR3, USART_CR3_WUS, WakeUpSelection.WakeUpEvent);

  if (WakeUpSelection.WakeUpEvent == UART_WAKEUP_ON_ADDRESS)
  {
    UART_Wakeup_AddressConfig(huart, WakeUpSelection);
  }


  __HAL_UART_ENABLE(huart);


  tickstart = HAL_GetTick();


  if(UART_WaitOnFlagUntilTimeout(huart, USART_ISR_REACK, RESET, tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK)
  {
    status = HAL_TIMEOUT;
  }
  else
  {

    huart->gState = HAL_UART_STATE_READY;
  }


  __HAL_UNLOCK(huart);

  return status;
}








HAL_StatusTypeDef HAL_UARTEx_EnableStopMode(UART_HandleTypeDef *huart)
{

  assert_param(IS_UART_WAKEUP_FROMSTOP_INSTANCE(huart->Instance));


  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;


  SET_BIT(huart->Instance->CR1, USART_CR1_UESM);

  huart->gState = HAL_UART_STATE_READY;


  __HAL_UNLOCK(huart);

  return HAL_OK;
}






HAL_StatusTypeDef HAL_UARTEx_DisableStopMode(UART_HandleTypeDef *huart)
{

  assert_param(IS_UART_WAKEUP_FROMSTOP_INSTANCE(huart->Instance));


  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;


  CLEAR_BIT(huart->Instance->CR1, USART_CR1_UESM);

  huart->gState = HAL_UART_STATE_READY;


  __HAL_UNLOCK(huart);

  return HAL_OK;
}














HAL_StatusTypeDef HAL_MultiProcessorEx_AddressLength_Set(UART_HandleTypeDef *huart, uint32_t AddressLength)
{

  if(huart == NULL)
  {
    return HAL_ERROR;
  }


  assert_param(IS_UART_ADDRESSLENGTH_DETECT(AddressLength));

  huart->gState = HAL_UART_STATE_BUSY;


  __HAL_UART_DISABLE(huart);


  MODIFY_REG(huart->Instance->CR2, USART_CR2_ADDM7, AddressLength);


  __HAL_UART_ENABLE(huart);


  return (UART_CheckIdleState(huart));
}











#endif










