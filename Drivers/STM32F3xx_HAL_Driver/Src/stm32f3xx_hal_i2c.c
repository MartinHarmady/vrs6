






















































































































































































































































#include "stm32f3xx_hal.h"










#ifdef HAL_I2C_MODULE_ENABLED







#define TIMING_CLEAR_MASK   (0xF0FFFFFFU)
#define I2C_TIMEOUT_ADDR    (10000U)
#define I2C_TIMEOUT_BUSY    (25U)
#define I2C_TIMEOUT_DIR     (25U)
#define I2C_TIMEOUT_RXNE    (25U)
#define I2C_TIMEOUT_STOPF   (25U)
#define I2C_TIMEOUT_TC      (25U)
#define I2C_TIMEOUT_TCR     (25U)
#define I2C_TIMEOUT_TXIS    (25U)
#define I2C_TIMEOUT_FLAG    (25U)

#define MAX_NBYTE_SIZE      255U
#define SlaveAddr_SHIFT     7U
#define SlaveAddr_MSK       0x06U


#define I2C_STATE_MSK             ((uint32_t)((HAL_I2C_STATE_BUSY_TX | HAL_I2C_STATE_BUSY_RX) & (~((uint32_t)HAL_I2C_STATE_READY))))
#define I2C_STATE_NONE            ((uint32_t)(HAL_I2C_MODE_NONE))
#define I2C_STATE_MASTER_BUSY_TX  ((uint32_t)((HAL_I2C_STATE_BUSY_TX & I2C_STATE_MSK) | HAL_I2C_MODE_MASTER))
#define I2C_STATE_MASTER_BUSY_RX  ((uint32_t)((HAL_I2C_STATE_BUSY_RX & I2C_STATE_MSK) | HAL_I2C_MODE_MASTER))
#define I2C_STATE_SLAVE_BUSY_TX   ((uint32_t)((HAL_I2C_STATE_BUSY_TX & I2C_STATE_MSK) | HAL_I2C_MODE_SLAVE))
#define I2C_STATE_SLAVE_BUSY_RX   ((uint32_t)((HAL_I2C_STATE_BUSY_RX & I2C_STATE_MSK) | HAL_I2C_MODE_SLAVE))
#define I2C_STATE_MEM_BUSY_TX     ((uint32_t)((HAL_I2C_STATE_BUSY_TX & I2C_STATE_MSK) | HAL_I2C_MODE_MEM))
#define I2C_STATE_MEM_BUSY_RX     ((uint32_t)((HAL_I2C_STATE_BUSY_RX & I2C_STATE_MSK) | HAL_I2C_MODE_MEM))



#define I2C_XFER_TX_IT          (0x00000001U)
#define I2C_XFER_RX_IT          (0x00000002U)
#define I2C_XFER_LISTEN_IT      (0x00000004U)

#define I2C_XFER_ERROR_IT       (0x00000011U)
#define I2C_XFER_CPLT_IT        (0x00000012U)
#define I2C_XFER_RELOAD_IT      (0x00000012U)


#define I2C_NO_OPTION_FRAME     (0xFFFF0000U)





#define I2C_GET_DMA_REMAIN_DATA(__HANDLE__) ((((__HANDLE__)->State) == HAL_I2C_STATE_BUSY_TX)   ? \
                                            ((uint32_t)(((DMA_Channel_TypeDef *)(__HANDLE__)->hdmatx->Instance)->CNDTR)) : \
                                            ((uint32_t)(((DMA_Channel_TypeDef *)(__HANDLE__)->hdmarx->Instance)->CNDTR)))








static void I2C_DMAMasterTransmitCplt(DMA_HandleTypeDef *hdma);
static void I2C_DMAMasterReceiveCplt(DMA_HandleTypeDef *hdma);
static void I2C_DMASlaveTransmitCplt(DMA_HandleTypeDef *hdma);
static void I2C_DMASlaveReceiveCplt(DMA_HandleTypeDef *hdma);
static void I2C_DMAError(DMA_HandleTypeDef *hdma);
static void I2C_DMAAbort(DMA_HandleTypeDef *hdma);


static void I2C_ITAddrCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags);
static void I2C_ITMasterSequentialCplt(I2C_HandleTypeDef *hi2c);
static void I2C_ITSlaveSequentialCplt(I2C_HandleTypeDef *hi2c);
static void I2C_ITMasterCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags);
static void I2C_ITSlaveCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags);
static void I2C_ITListenCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags);
static void I2C_ITError(I2C_HandleTypeDef *hi2c, uint32_t ErrorCode);


static HAL_StatusTypeDef I2C_RequestMemoryWrite(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint32_t Timeout, uint32_t Tickstart);
static HAL_StatusTypeDef I2C_RequestMemoryRead(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint32_t Timeout, uint32_t Tickstart);


static HAL_StatusTypeDef I2C_Master_ISR_IT(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources);
static HAL_StatusTypeDef I2C_Slave_ISR_IT(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources);
static HAL_StatusTypeDef I2C_Master_ISR_DMA(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources);
static HAL_StatusTypeDef I2C_Slave_ISR_DMA(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources);


static HAL_StatusTypeDef I2C_WaitOnFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Flag, FlagStatus Status, uint32_t Timeout, uint32_t Tickstart);
static HAL_StatusTypeDef I2C_WaitOnTXISFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart);
static HAL_StatusTypeDef I2C_WaitOnRXNEFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart);
static HAL_StatusTypeDef I2C_WaitOnSTOPFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart);
static HAL_StatusTypeDef I2C_IsAcknowledgeFailed(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart);


static HAL_StatusTypeDef I2C_Enable_IRQ(I2C_HandleTypeDef *hi2c, uint16_t InterruptRequest);
static HAL_StatusTypeDef I2C_Disable_IRQ(I2C_HandleTypeDef *hi2c, uint16_t InterruptRequest);


static void I2C_Flush_TXDR(I2C_HandleTypeDef *hi2c);


static void I2C_TransferConfig(I2C_HandleTypeDef *hi2c,  uint16_t DevAddress, uint8_t Size, uint32_t Mode, uint32_t Request);
















































HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c)
{

  if (hi2c == NULL)
  {
    return HAL_ERROR;
  }


  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));
  assert_param(IS_I2C_OWN_ADDRESS1(hi2c->Init.OwnAddress1));
  assert_param(IS_I2C_ADDRESSING_MODE(hi2c->Init.AddressingMode));
  assert_param(IS_I2C_DUAL_ADDRESS(hi2c->Init.DualAddressMode));
  assert_param(IS_I2C_OWN_ADDRESS2(hi2c->Init.OwnAddress2));
  assert_param(IS_I2C_OWN_ADDRESS2_MASK(hi2c->Init.OwnAddress2Masks));
  assert_param(IS_I2C_GENERAL_CALL(hi2c->Init.GeneralCallMode));
  assert_param(IS_I2C_NO_STRETCH(hi2c->Init.NoStretchMode));

  if (hi2c->State == HAL_I2C_STATE_RESET)
  {

    hi2c->Lock = HAL_UNLOCKED;


    HAL_I2C_MspInit(hi2c);
  }

  hi2c->State = HAL_I2C_STATE_BUSY;


  __HAL_I2C_DISABLE(hi2c);



  hi2c->Instance->TIMINGR = hi2c->Init.Timing & TIMING_CLEAR_MASK;



  hi2c->Instance->OAR1 &= ~I2C_OAR1_OA1EN;


  if (hi2c->Init.AddressingMode == I2C_ADDRESSINGMODE_7BIT)
  {
    hi2c->Instance->OAR1 = (I2C_OAR1_OA1EN | hi2c->Init.OwnAddress1);
  }
  else
  {
    hi2c->Instance->OAR1 = (I2C_OAR1_OA1EN | I2C_OAR1_OA1MODE | hi2c->Init.OwnAddress1);
  }



  if (hi2c->Init.AddressingMode == I2C_ADDRESSINGMODE_10BIT)
  {
    hi2c->Instance->CR2 = (I2C_CR2_ADD10);
  }

  hi2c->Instance->CR2 |= (I2C_CR2_AUTOEND | I2C_CR2_NACK);



  hi2c->Instance->OAR2 &= ~I2C_DUALADDRESS_ENABLE;


  hi2c->Instance->OAR2 = (hi2c->Init.DualAddressMode | hi2c->Init.OwnAddress2 | (hi2c->Init.OwnAddress2Masks << 8));



  hi2c->Instance->CR1 = (hi2c->Init.GeneralCallMode | hi2c->Init.NoStretchMode);


  __HAL_I2C_ENABLE(hi2c);

  hi2c->ErrorCode = HAL_I2C_ERROR_NONE;
  hi2c->State = HAL_I2C_STATE_READY;
  hi2c->PreviousState = I2C_STATE_NONE;
  hi2c->Mode = HAL_I2C_MODE_NONE;

  return HAL_OK;
}







HAL_StatusTypeDef HAL_I2C_DeInit(I2C_HandleTypeDef *hi2c)
{

  if (hi2c == NULL)
  {
    return HAL_ERROR;
  }


  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));

  hi2c->State = HAL_I2C_STATE_BUSY;


  __HAL_I2C_DISABLE(hi2c);


  HAL_I2C_MspDeInit(hi2c);

  hi2c->ErrorCode = HAL_I2C_ERROR_NONE;
  hi2c->State = HAL_I2C_STATE_RESET;
  hi2c->PreviousState = I2C_STATE_NONE;
  hi2c->Mode = HAL_I2C_MODE_NONE;


  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}







__weak void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}







__weak void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}











































































HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart = 0U;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {

    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, I2C_TIMEOUT_BUSY, tickstart) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    hi2c->State     = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode      = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;



    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_RELOAD_MODE, I2C_GENERATE_START_WRITE);
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_GENERATE_START_WRITE);
    }

    while (hi2c->XferCount > 0U)
    {

      if (I2C_WaitOnTXISFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
      {
        if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
        {
          return HAL_ERROR;
        }
        else
        {
          return HAL_TIMEOUT;
        }
      }

      hi2c->Instance->TXDR = (*hi2c->pBuffPtr++);
      hi2c->XferCount--;
      hi2c->XferSize--;

      if ((hi2c->XferSize == 0U) && (hi2c->XferCount != 0U))
      {

        if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TCR, RESET, Timeout, tickstart) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }

        if (hi2c->XferCount > MAX_NBYTE_SIZE)
        {
          hi2c->XferSize = MAX_NBYTE_SIZE;
          I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_RELOAD_MODE, I2C_NO_STARTSTOP);
        }
        else
        {
          hi2c->XferSize = hi2c->XferCount;
          I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_NO_STARTSTOP);
        }
      }
    }



    if (I2C_WaitOnSTOPFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {
        return HAL_ERROR;
      }
      else
      {
        return HAL_TIMEOUT;
      }
    }


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


    I2C_RESET_CR2(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode  = HAL_I2C_MODE_NONE;


    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}












HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart = 0U;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {

    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, I2C_TIMEOUT_BUSY, tickstart) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    hi2c->State     = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode      = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;



    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_RELOAD_MODE, I2C_GENERATE_START_READ);
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_GENERATE_START_READ);
    }

    while (hi2c->XferCount > 0U)
    {

      if (I2C_WaitOnRXNEFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
      {
        if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
        {
          return HAL_ERROR;
        }
        else
        {
          return HAL_TIMEOUT;
        }
      }


      (*hi2c->pBuffPtr++) = hi2c->Instance->RXDR;
      hi2c->XferSize--;
      hi2c->XferCount--;

      if ((hi2c->XferSize == 0U) && (hi2c->XferCount != 0U))
      {

        if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TCR, RESET, Timeout, tickstart) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }

        if (hi2c->XferCount > MAX_NBYTE_SIZE)
        {
          hi2c->XferSize = MAX_NBYTE_SIZE;
          I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_RELOAD_MODE, I2C_NO_STARTSTOP);
        }
        else
        {
          hi2c->XferSize = hi2c->XferCount;
          I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_NO_STARTSTOP);
        }
      }
    }



    if (I2C_WaitOnSTOPFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {
        return HAL_ERROR;
      }
      else
      {
        return HAL_TIMEOUT;
      }
    }


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


    I2C_RESET_CR2(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode  = HAL_I2C_MODE_NONE;


    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}










HAL_StatusTypeDef HAL_I2C_Slave_Transmit(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart = 0U;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    hi2c->State     = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode      = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;


    hi2c->Instance->CR2 &= ~I2C_CR2_NACK;


    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_ADDR, RESET, Timeout, tickstart) != HAL_OK)
    {

      hi2c->Instance->CR2 |= I2C_CR2_NACK;
      return HAL_TIMEOUT;
    }


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ADDR);


    if (hi2c->Init.AddressingMode == I2C_ADDRESSINGMODE_10BIT)
    {

      if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_ADDR, RESET, Timeout, tickstart) != HAL_OK)
      {

        hi2c->Instance->CR2 |= I2C_CR2_NACK;
        return HAL_TIMEOUT;
      }


      __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ADDR);
    }


    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_DIR, RESET, Timeout, tickstart) != HAL_OK)
    {

      hi2c->Instance->CR2 |= I2C_CR2_NACK;
      return HAL_TIMEOUT;
    }

    while (hi2c->XferCount > 0U)
    {

      if (I2C_WaitOnTXISFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
      {

        hi2c->Instance->CR2 |= I2C_CR2_NACK;

        if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
        {
          return HAL_ERROR;
        }
        else
        {
          return HAL_TIMEOUT;
        }
      }


      hi2c->Instance->TXDR = (*hi2c->pBuffPtr++);
      hi2c->XferCount--;
    }


    if (I2C_WaitOnSTOPFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
    {

      hi2c->Instance->CR2 |= I2C_CR2_NACK;

      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {


        hi2c->ErrorCode = HAL_I2C_ERROR_NONE;
      }
      else
      {
        return HAL_TIMEOUT;
      }
    }


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
    {

      hi2c->Instance->CR2 |= I2C_CR2_NACK;
      return HAL_TIMEOUT;
    }


    hi2c->Instance->CR2 |= I2C_CR2_NACK;

    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode  = HAL_I2C_MODE_NONE;


    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}










HAL_StatusTypeDef HAL_I2C_Slave_Receive(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart = 0U;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    hi2c->State     = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode      = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;


    hi2c->Instance->CR2 &= ~I2C_CR2_NACK;


    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_ADDR, RESET, Timeout, tickstart) != HAL_OK)
    {

      hi2c->Instance->CR2 |= I2C_CR2_NACK;
      return HAL_TIMEOUT;
    }


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ADDR);


    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_DIR, SET, Timeout, tickstart) != HAL_OK)
    {

      hi2c->Instance->CR2 |= I2C_CR2_NACK;
      return HAL_TIMEOUT;
    }

    while (hi2c->XferCount > 0U)
    {

      if (I2C_WaitOnRXNEFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
      {

        hi2c->Instance->CR2 |= I2C_CR2_NACK;


        if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_RXNE) == SET)
        {

          (*hi2c->pBuffPtr++) = hi2c->Instance->RXDR;
          hi2c->XferCount--;
        }

        if (hi2c->ErrorCode == HAL_I2C_ERROR_TIMEOUT)
        {
          return HAL_TIMEOUT;
        }
        else
        {
          return HAL_ERROR;
        }
      }


      (*hi2c->pBuffPtr++) = hi2c->Instance->RXDR;
      hi2c->XferCount--;
    }


    if (I2C_WaitOnSTOPFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
    {

      hi2c->Instance->CR2 |= I2C_CR2_NACK;

      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {
        return HAL_ERROR;
      }
      else
      {
        return HAL_TIMEOUT;
      }
    }


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, Timeout, tickstart) != HAL_OK)
    {

      hi2c->Instance->CR2 |= I2C_CR2_NACK;
      return HAL_TIMEOUT;
    }


    hi2c->Instance->CR2 |= I2C_CR2_NACK;

    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode  = HAL_I2C_MODE_NONE;


    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}











HAL_StatusTypeDef HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
  uint32_t xfermode = 0U;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BUSY) == SET)
    {
      return HAL_BUSY;
    }


    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Master_ISR_IT;

    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = I2C_AUTOEND_MODE;
    }



    I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, I2C_GENERATE_START_WRITE);


    __HAL_UNLOCK(hi2c);








    I2C_Enable_IRQ(hi2c, I2C_XFER_TX_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}











HAL_StatusTypeDef HAL_I2C_Master_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
  uint32_t xfermode = 0U;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BUSY) == SET)
    {
      return HAL_BUSY;
    }


    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Master_ISR_IT;

    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = I2C_AUTOEND_MODE;
    }



    I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, I2C_GENERATE_START_READ);


    __HAL_UNLOCK(hi2c);








    I2C_Enable_IRQ(hi2c, I2C_XFER_RX_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}









HAL_StatusTypeDef HAL_I2C_Slave_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {

    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->Instance->CR2 &= ~I2C_CR2_NACK;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferSize    = hi2c->XferCount;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Slave_ISR_IT;


    __HAL_UNLOCK(hi2c);








    I2C_Enable_IRQ(hi2c, I2C_XFER_TX_IT | I2C_XFER_LISTEN_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}









HAL_StatusTypeDef HAL_I2C_Slave_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {

    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->Instance->CR2 &= ~I2C_CR2_NACK;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferSize    = hi2c->XferCount;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Slave_ISR_IT;


    __HAL_UNLOCK(hi2c);








    I2C_Enable_IRQ(hi2c, I2C_XFER_RX_IT | I2C_XFER_LISTEN_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}











HAL_StatusTypeDef HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
  uint32_t xfermode = 0U;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BUSY) == SET)
    {
      return HAL_BUSY;
    }


    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Master_ISR_DMA;

    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = I2C_AUTOEND_MODE;
    }

    if (hi2c->XferSize > 0U)
    {

      hi2c->hdmatx->XferCpltCallback = I2C_DMAMasterTransmitCplt;


      hi2c->hdmatx->XferErrorCallback = I2C_DMAError;


      hi2c->hdmatx->XferHalfCpltCallback = NULL;
      hi2c->hdmatx->XferAbortCallback = NULL;


      HAL_DMA_Start_IT(hi2c->hdmatx, (uint32_t)pData, (uint32_t)&hi2c->Instance->TXDR, hi2c->XferSize);



      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, I2C_GENERATE_START_WRITE);


      hi2c->XferCount -= hi2c->XferSize;


      __HAL_UNLOCK(hi2c);





      I2C_Enable_IRQ(hi2c, I2C_XFER_ERROR_IT);


      hi2c->Instance->CR1 |= I2C_CR1_TXDMAEN;
    }
    else
    {

      hi2c->XferISR = I2C_Master_ISR_IT;



      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_GENERATE_START_WRITE);


      __HAL_UNLOCK(hi2c);







      I2C_Enable_IRQ(hi2c, I2C_XFER_TX_IT);
    }

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}











HAL_StatusTypeDef HAL_I2C_Master_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
  uint32_t xfermode = 0U;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BUSY) == SET)
    {
      return HAL_BUSY;
    }


    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Master_ISR_DMA;

    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = I2C_AUTOEND_MODE;
    }

    if (hi2c->XferSize > 0U)
    {

      hi2c->hdmarx->XferCpltCallback = I2C_DMAMasterReceiveCplt;


      hi2c->hdmarx->XferErrorCallback = I2C_DMAError;


      hi2c->hdmarx->XferHalfCpltCallback = NULL;
      hi2c->hdmarx->XferAbortCallback = NULL;


      HAL_DMA_Start_IT(hi2c->hdmarx, (uint32_t)&hi2c->Instance->RXDR, (uint32_t)pData, hi2c->XferSize);



      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, I2C_GENERATE_START_READ);


      hi2c->XferCount -= hi2c->XferSize;


      __HAL_UNLOCK(hi2c);





      I2C_Enable_IRQ(hi2c, I2C_XFER_ERROR_IT);


      hi2c->Instance->CR1 |= I2C_CR1_RXDMAEN;
    }
    else
    {

      hi2c->XferISR = I2C_Master_ISR_IT;



      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_GENERATE_START_READ);


      __HAL_UNLOCK(hi2c);







      I2C_Enable_IRQ(hi2c, I2C_XFER_TX_IT);
    }
    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}









HAL_StatusTypeDef HAL_I2C_Slave_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferSize    = hi2c->XferCount;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Slave_ISR_DMA;


    hi2c->hdmatx->XferCpltCallback = I2C_DMASlaveTransmitCplt;


    hi2c->hdmatx->XferErrorCallback = I2C_DMAError;


    hi2c->hdmatx->XferHalfCpltCallback = NULL;
    hi2c->hdmatx->XferAbortCallback = NULL;


    HAL_DMA_Start_IT(hi2c->hdmatx, (uint32_t)pData, (uint32_t)&hi2c->Instance->TXDR, hi2c->XferSize);


    hi2c->Instance->CR2 &= ~I2C_CR2_NACK;


    __HAL_UNLOCK(hi2c);





    I2C_Enable_IRQ(hi2c, I2C_XFER_LISTEN_IT);


    hi2c->Instance->CR1 |= I2C_CR1_TXDMAEN;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}









HAL_StatusTypeDef HAL_I2C_Slave_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferSize    = hi2c->XferCount;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Slave_ISR_DMA;


    hi2c->hdmarx->XferCpltCallback = I2C_DMASlaveReceiveCplt;


    hi2c->hdmarx->XferErrorCallback = I2C_DMAError;


    hi2c->hdmarx->XferHalfCpltCallback = NULL;
    hi2c->hdmarx->XferAbortCallback = NULL;


    HAL_DMA_Start_IT(hi2c->hdmarx, (uint32_t)&hi2c->Instance->RXDR, (uint32_t)pData, hi2c->XferSize);


    hi2c->Instance->CR2 &= ~I2C_CR2_NACK;


    __HAL_UNLOCK(hi2c);





    I2C_Enable_IRQ(hi2c, I2C_XFER_LISTEN_IT);


    hi2c->Instance->CR1 |= I2C_CR1_RXDMAEN;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}













HAL_StatusTypeDef HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart = 0U;


  assert_param(IS_I2C_MEMADD_SIZE(MemAddSize));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }


    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, I2C_TIMEOUT_BUSY, tickstart) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    hi2c->State     = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode      = HAL_I2C_MODE_MEM;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;


    if (I2C_RequestMemoryWrite(hi2c, DevAddress, MemAddress, MemAddSize, Timeout, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {

        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
      else
      {

        __HAL_UNLOCK(hi2c);
        return HAL_TIMEOUT;
      }
    }


    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_RELOAD_MODE, I2C_NO_STARTSTOP);
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_NO_STARTSTOP);
    }

    do
    {

      if (I2C_WaitOnTXISFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
      {
        if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
        {
          return HAL_ERROR;
        }
        else
        {
          return HAL_TIMEOUT;
        }
      }


      hi2c->Instance->TXDR = (*hi2c->pBuffPtr++);
      hi2c->XferCount--;
      hi2c->XferSize--;

      if ((hi2c->XferSize == 0U) && (hi2c->XferCount != 0U))
      {

        if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TCR, RESET, Timeout, tickstart) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }

        if (hi2c->XferCount > MAX_NBYTE_SIZE)
        {
          hi2c->XferSize = MAX_NBYTE_SIZE;
          I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_RELOAD_MODE, I2C_NO_STARTSTOP);
        }
        else
        {
          hi2c->XferSize = hi2c->XferCount;
          I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_NO_STARTSTOP);
        }
      }

    }
    while (hi2c->XferCount > 0U);



    if (I2C_WaitOnSTOPFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {
        return HAL_ERROR;
      }
      else
      {
        return HAL_TIMEOUT;
      }
    }


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


    I2C_RESET_CR2(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode  = HAL_I2C_MODE_NONE;


    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}














HAL_StatusTypeDef HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart = 0U;


  assert_param(IS_I2C_MEMADD_SIZE(MemAddSize));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }


    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, I2C_TIMEOUT_BUSY, tickstart) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    hi2c->State     = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode      = HAL_I2C_MODE_MEM;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;


    if (I2C_RequestMemoryRead(hi2c, DevAddress, MemAddress, MemAddSize, Timeout, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {

        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
      else
      {

        __HAL_UNLOCK(hi2c);
        return HAL_TIMEOUT;
      }
    }



    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_RELOAD_MODE, I2C_GENERATE_START_READ);
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_GENERATE_START_READ);
    }

    do
    {

      if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_RXNE, RESET, Timeout, tickstart) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }


      (*hi2c->pBuffPtr++) = hi2c->Instance->RXDR;
      hi2c->XferSize--;
      hi2c->XferCount--;

      if ((hi2c->XferSize == 0U) && (hi2c->XferCount != 0U))
      {

        if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TCR, RESET, Timeout, tickstart) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }

        if (hi2c->XferCount > MAX_NBYTE_SIZE)
        {
          hi2c->XferSize = MAX_NBYTE_SIZE;
          I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_RELOAD_MODE, I2C_NO_STARTSTOP);
        }
        else
        {
          hi2c->XferSize = hi2c->XferCount;
          I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_NO_STARTSTOP);
        }
      }
    }
    while (hi2c->XferCount > 0U);



    if (I2C_WaitOnSTOPFlagUntilTimeout(hi2c, Timeout, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {
        return HAL_ERROR;
      }
      else
      {
        return HAL_TIMEOUT;
      }
    }


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


    I2C_RESET_CR2(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode  = HAL_I2C_MODE_NONE;


    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}












HAL_StatusTypeDef HAL_I2C_Mem_Write_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)
{
  uint32_t tickstart = 0U;
  uint32_t xfermode = 0U;


  assert_param(IS_I2C_MEMADD_SIZE(MemAddSize));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BUSY) == SET)
    {
      return HAL_BUSY;
    }


    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_MEM;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Master_ISR_IT;

    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = I2C_AUTOEND_MODE;
    }


    if (I2C_RequestMemoryWrite(hi2c, DevAddress, MemAddress, MemAddSize, I2C_TIMEOUT_FLAG, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {

        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
      else
      {

        __HAL_UNLOCK(hi2c);
        return HAL_TIMEOUT;
      }
    }


    I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, I2C_NO_STARTSTOP);


    __HAL_UNLOCK(hi2c);








    I2C_Enable_IRQ(hi2c, I2C_XFER_TX_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}













HAL_StatusTypeDef HAL_I2C_Mem_Read_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)
{
  uint32_t tickstart = 0U;
  uint32_t xfermode = 0U;


  assert_param(IS_I2C_MEMADD_SIZE(MemAddSize));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BUSY) == SET)
    {
      return HAL_BUSY;
    }


    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_MEM;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Master_ISR_IT;

    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = I2C_AUTOEND_MODE;
    }


    if (I2C_RequestMemoryRead(hi2c, DevAddress, MemAddress, MemAddSize, I2C_TIMEOUT_FLAG, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {

        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
      else
      {

        __HAL_UNLOCK(hi2c);
        return HAL_TIMEOUT;
      }
    }


    I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, I2C_GENERATE_START_READ);


    __HAL_UNLOCK(hi2c);








    I2C_Enable_IRQ(hi2c, I2C_XFER_RX_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}












HAL_StatusTypeDef HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)
{
  uint32_t tickstart = 0U;
  uint32_t xfermode = 0U;


  assert_param(IS_I2C_MEMADD_SIZE(MemAddSize));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BUSY) == SET)
    {
      return HAL_BUSY;
    }


    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_MEM;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Master_ISR_DMA;

    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = I2C_AUTOEND_MODE;
    }


    if (I2C_RequestMemoryWrite(hi2c, DevAddress, MemAddress, MemAddSize, I2C_TIMEOUT_FLAG, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {

        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
      else
      {

        __HAL_UNLOCK(hi2c);
        return HAL_TIMEOUT;
      }
    }


    hi2c->hdmatx->XferCpltCallback = I2C_DMAMasterTransmitCplt;


    hi2c->hdmatx->XferErrorCallback = I2C_DMAError;


    hi2c->hdmatx->XferHalfCpltCallback = NULL;
    hi2c->hdmatx->XferAbortCallback = NULL;


    HAL_DMA_Start_IT(hi2c->hdmatx, (uint32_t)pData, (uint32_t)&hi2c->Instance->TXDR, hi2c->XferSize);



    I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, I2C_NO_STARTSTOP);


    hi2c->XferCount -= hi2c->XferSize;


    __HAL_UNLOCK(hi2c);





    I2C_Enable_IRQ(hi2c, I2C_XFER_ERROR_IT);


    hi2c->Instance->CR1 |= I2C_CR1_TXDMAEN;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}













HAL_StatusTypeDef HAL_I2C_Mem_Read_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)
{
  uint32_t tickstart = 0U;
  uint32_t xfermode = 0U;


  assert_param(IS_I2C_MEMADD_SIZE(MemAddSize));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BUSY) == SET)
    {
      return HAL_BUSY;
    }


    __HAL_LOCK(hi2c);


    tickstart = HAL_GetTick();

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_MEM;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Master_ISR_DMA;

    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = I2C_AUTOEND_MODE;
    }


    if (I2C_RequestMemoryRead(hi2c, DevAddress, MemAddress, MemAddSize, I2C_TIMEOUT_FLAG, tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {

        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
      else
      {

        __HAL_UNLOCK(hi2c);
        return HAL_TIMEOUT;
      }
    }


    hi2c->hdmarx->XferCpltCallback = I2C_DMAMasterReceiveCplt;


    hi2c->hdmarx->XferErrorCallback = I2C_DMAError;


    hi2c->hdmarx->XferHalfCpltCallback = NULL;
    hi2c->hdmarx->XferAbortCallback = NULL;


    HAL_DMA_Start_IT(hi2c->hdmarx, (uint32_t)&hi2c->Instance->RXDR, (uint32_t)pData, hi2c->XferSize);


    I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, I2C_GENERATE_START_READ);


    hi2c->XferCount -= hi2c->XferSize;


    __HAL_UNLOCK(hi2c);


    hi2c->Instance->CR1 |= I2C_CR1_RXDMAEN;





    I2C_Enable_IRQ(hi2c, I2C_XFER_ERROR_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}












HAL_StatusTypeDef HAL_I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout)
{
  uint32_t tickstart = 0U;

  __IO uint32_t I2C_Trials = 0U;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BUSY) == SET)
    {
      return HAL_BUSY;
    }


    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;

    do
    {

      hi2c->Instance->CR2 = I2C_GENERATE_START(hi2c->Init.AddressingMode, DevAddress);



      tickstart = HAL_GetTick();
      while ((__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_STOPF) == RESET) && (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_AF) == RESET) && (hi2c->State != HAL_I2C_STATE_TIMEOUT))
      {
        if (Timeout != HAL_MAX_DELAY)
        {
          if ((Timeout == 0U) || ((HAL_GetTick() - tickstart) > Timeout))
          {

            hi2c->State = HAL_I2C_STATE_READY;

            __HAL_UNLOCK(hi2c);
            return HAL_TIMEOUT;
          }
        }
      }


      if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_AF) == RESET)
      {

        if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_STOPF, RESET, Timeout, tickstart) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }


        __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


        hi2c->State = HAL_I2C_STATE_READY;


        __HAL_UNLOCK(hi2c);

        return HAL_OK;
      }
      else
      {

        if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_STOPF, RESET, Timeout, tickstart) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }


        __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);


        __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);
      }


      if (I2C_Trials++ == Trials)
      {

        hi2c->Instance->CR2 |= I2C_CR2_STOP;


        if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_STOPF, RESET, Timeout, tickstart) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }


        __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);
      }
    }
    while (I2C_Trials < Trials);

    hi2c->State = HAL_I2C_STATE_READY;


    __HAL_UNLOCK(hi2c);

    return HAL_TIMEOUT;
  }
  else
  {
    return HAL_BUSY;
  }
}













HAL_StatusTypeDef HAL_I2C_Master_Sequential_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions)
{
  uint32_t xfermode = 0U;
  uint32_t xferrequest = I2C_GENERATE_START_WRITE;


  assert_param(IS_I2C_TRANSFER_OPTIONS_REQUEST(XferOptions));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {

    __HAL_LOCK(hi2c);

    hi2c->State     = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode      = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = XferOptions;
    hi2c->XferISR     = I2C_Master_ISR_IT;


    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = hi2c->XferOptions;
    }



    if (hi2c->PreviousState == I2C_STATE_MASTER_BUSY_TX)
    {
      xferrequest = I2C_NO_STARTSTOP;
    }


    I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, xferrequest);


    __HAL_UNLOCK(hi2c);




    I2C_Enable_IRQ(hi2c, I2C_XFER_TX_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}













HAL_StatusTypeDef HAL_I2C_Master_Sequential_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions)
{
  uint32_t xfermode = 0U;
  uint32_t xferrequest = I2C_GENERATE_START_READ;


  assert_param(IS_I2C_TRANSFER_OPTIONS_REQUEST(XferOptions));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {

    __HAL_LOCK(hi2c);

    hi2c->State     = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode      = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferOptions = XferOptions;
    hi2c->XferISR     = I2C_Master_ISR_IT;


    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
      xfermode = I2C_RELOAD_MODE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
      xfermode = hi2c->XferOptions;
    }



    if (hi2c->PreviousState == I2C_STATE_MASTER_BUSY_RX)
    {
      xferrequest = I2C_NO_STARTSTOP;
    }


    I2C_TransferConfig(hi2c, DevAddress, hi2c->XferSize, xfermode, xferrequest);


    __HAL_UNLOCK(hi2c);




    I2C_Enable_IRQ(hi2c, I2C_XFER_RX_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}











HAL_StatusTypeDef HAL_I2C_Slave_Sequential_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions)
{

  assert_param(IS_I2C_TRANSFER_OPTIONS_REQUEST(XferOptions));

  if ((hi2c->State & HAL_I2C_STATE_LISTEN) == HAL_I2C_STATE_LISTEN)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }


    I2C_Disable_IRQ(hi2c, I2C_XFER_LISTEN_IT | I2C_XFER_TX_IT);


    __HAL_LOCK(hi2c);



    if (hi2c->State == HAL_I2C_STATE_BUSY_RX_LISTEN)
    {

      I2C_Disable_IRQ(hi2c, I2C_XFER_RX_IT);
    }

    hi2c->State     = HAL_I2C_STATE_BUSY_TX_LISTEN;
    hi2c->Mode      = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->Instance->CR2 &= ~I2C_CR2_NACK;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferSize    = hi2c->XferCount;
    hi2c->XferOptions = XferOptions;
    hi2c->XferISR     = I2C_Slave_ISR_IT;

    if (I2C_GET_DIR(hi2c) == I2C_DIRECTION_RECEIVE)
    {


      __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ADDR);
    }


    __HAL_UNLOCK(hi2c);





    I2C_Enable_IRQ(hi2c, I2C_XFER_TX_IT | I2C_XFER_LISTEN_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
}











HAL_StatusTypeDef HAL_I2C_Slave_Sequential_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions)
{

  assert_param(IS_I2C_TRANSFER_OPTIONS_REQUEST(XferOptions));

  if ((hi2c->State & HAL_I2C_STATE_LISTEN) == HAL_I2C_STATE_LISTEN)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }


    I2C_Disable_IRQ(hi2c, I2C_XFER_LISTEN_IT | I2C_XFER_RX_IT);


    __HAL_LOCK(hi2c);



    if (hi2c->State == HAL_I2C_STATE_BUSY_TX_LISTEN)
    {

      I2C_Disable_IRQ(hi2c, I2C_XFER_TX_IT);
    }

    hi2c->State     = HAL_I2C_STATE_BUSY_RX_LISTEN;
    hi2c->Mode      = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;


    hi2c->Instance->CR2 &= ~I2C_CR2_NACK;


    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferSize    = hi2c->XferCount;
    hi2c->XferOptions = XferOptions;
    hi2c->XferISR     = I2C_Slave_ISR_IT;

    if (I2C_GET_DIR(hi2c) == I2C_DIRECTION_TRANSMIT)
    {


      __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ADDR);
    }


    __HAL_UNLOCK(hi2c);





    I2C_Enable_IRQ(hi2c, I2C_XFER_RX_IT | I2C_XFER_LISTEN_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
}







HAL_StatusTypeDef HAL_I2C_EnableListen_IT(I2C_HandleTypeDef *hi2c)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    hi2c->State = HAL_I2C_STATE_LISTEN;
    hi2c->XferISR = I2C_Slave_ISR_IT;


    I2C_Enable_IRQ(hi2c, I2C_XFER_LISTEN_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}







HAL_StatusTypeDef HAL_I2C_DisableListen_IT(I2C_HandleTypeDef *hi2c)
{

  uint32_t tmp;


  if (hi2c->State == HAL_I2C_STATE_LISTEN)
  {
    tmp = (uint32_t)(hi2c->State) & I2C_STATE_MSK;
    hi2c->PreviousState = tmp | (uint32_t)(hi2c->Mode);
    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode = HAL_I2C_MODE_NONE;
    hi2c->XferISR = NULL;


    I2C_Disable_IRQ(hi2c, I2C_XFER_LISTEN_IT);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}









HAL_StatusTypeDef HAL_I2C_Master_Abort_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress)
{
  if (hi2c->Mode == HAL_I2C_MODE_MASTER)
  {

    __HAL_LOCK(hi2c);


    I2C_Disable_IRQ(hi2c, I2C_XFER_RX_IT);
    I2C_Disable_IRQ(hi2c, I2C_XFER_TX_IT);


    hi2c->State = HAL_I2C_STATE_ABORT;



    I2C_TransferConfig(hi2c, DevAddress, 1, I2C_AUTOEND_MODE, I2C_GENERATE_STOP);


    __HAL_UNLOCK(hi2c);




    I2C_Enable_IRQ(hi2c, I2C_XFER_CPLT_IT);

    return HAL_OK;
  }
  else
  {


    return HAL_ERROR;
  }
}















void HAL_I2C_EV_IRQHandler(I2C_HandleTypeDef *hi2c)
{

  uint32_t itflags   = READ_REG(hi2c->Instance->ISR);
  uint32_t itsources = READ_REG(hi2c->Instance->CR1);


  if (hi2c->XferISR != NULL)
  {
    hi2c->XferISR(hi2c, itflags, itsources);
  }
}







void HAL_I2C_ER_IRQHandler(I2C_HandleTypeDef *hi2c)
{
  uint32_t itflags   = READ_REG(hi2c->Instance->ISR);
  uint32_t itsources = READ_REG(hi2c->Instance->CR1);


  if (((itflags & I2C_FLAG_BERR) != RESET) && ((itsources & I2C_IT_ERRI) != RESET))
  {
    hi2c->ErrorCode |= HAL_I2C_ERROR_BERR;


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_BERR);
  }


  if (((itflags & I2C_FLAG_OVR) != RESET) && ((itsources & I2C_IT_ERRI) != RESET))
  {
    hi2c->ErrorCode |= HAL_I2C_ERROR_OVR;


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_OVR);
  }


  if (((itflags & I2C_FLAG_ARLO) != RESET) && ((itsources & I2C_IT_ERRI) != RESET))
  {
    hi2c->ErrorCode |= HAL_I2C_ERROR_ARLO;


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ARLO);
  }


  if ((hi2c->ErrorCode & (HAL_I2C_ERROR_BERR | HAL_I2C_ERROR_OVR | HAL_I2C_ERROR_ARLO)) !=  HAL_I2C_ERROR_NONE)
  {
    I2C_ITError(hi2c, hi2c->ErrorCode);
  }
}







__weak void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}







__weak void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}






__weak void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}







__weak void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}









__weak void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
{

  UNUSED(hi2c);
  UNUSED(TransferDirection);
  UNUSED(AddrMatchCode);




}







__weak void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}







__weak void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}







__weak void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}







__weak void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}







__weak void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c)
{

  UNUSED(hi2c);




}


























HAL_I2C_StateTypeDef HAL_I2C_GetState(I2C_HandleTypeDef *hi2c)
{

  return hi2c->State;
}







HAL_I2C_ModeTypeDef HAL_I2C_GetMode(I2C_HandleTypeDef *hi2c)
{
  return hi2c->Mode;
}







uint32_t HAL_I2C_GetError(I2C_HandleTypeDef *hi2c)
{
  return hi2c->ErrorCode;
}





















static HAL_StatusTypeDef I2C_Master_ISR_IT(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources)
{
  uint16_t devaddress = 0U;


  __HAL_LOCK(hi2c);

  if (((ITFlags & I2C_FLAG_AF) != RESET) && ((ITSources & I2C_IT_NACKI) != RESET))
  {

    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);




    hi2c->ErrorCode |= HAL_I2C_ERROR_AF;


    I2C_Flush_TXDR(hi2c);
  }
  else if (((ITFlags & I2C_FLAG_RXNE) != RESET) && ((ITSources & I2C_IT_RXI) != RESET))
  {

    (*hi2c->pBuffPtr++) = hi2c->Instance->RXDR;
    hi2c->XferSize--;
    hi2c->XferCount--;
  }
  else if (((ITFlags & I2C_FLAG_TXIS) != RESET) && ((ITSources & I2C_IT_TXI) != RESET))
  {

    hi2c->Instance->TXDR = (*hi2c->pBuffPtr++);
    hi2c->XferSize--;
    hi2c->XferCount--;
  }
  else if (((ITFlags & I2C_FLAG_TCR) != RESET) && ((ITSources & I2C_IT_TCI) != RESET))
  {
    if ((hi2c->XferSize == 0U) && (hi2c->XferCount != 0U))
    {
      devaddress = (hi2c->Instance->CR2 & I2C_CR2_SADD);

      if (hi2c->XferCount > MAX_NBYTE_SIZE)
      {
        hi2c->XferSize = MAX_NBYTE_SIZE;
        I2C_TransferConfig(hi2c, devaddress, hi2c->XferSize, I2C_RELOAD_MODE, I2C_NO_STARTSTOP);
      }
      else
      {
        hi2c->XferSize = hi2c->XferCount;
        if (hi2c->XferOptions != I2C_NO_OPTION_FRAME)
        {
          I2C_TransferConfig(hi2c, devaddress, hi2c->XferSize, hi2c->XferOptions, I2C_NO_STARTSTOP);
        }
        else
        {
          I2C_TransferConfig(hi2c, devaddress, hi2c->XferSize, I2C_AUTOEND_MODE, I2C_NO_STARTSTOP);
        }
      }
    }
    else
    {

      if (I2C_GET_STOP_MODE(hi2c) != I2C_AUTOEND_MODE)
      {

        I2C_ITMasterSequentialCplt(hi2c);
      }
      else
      {


        I2C_ITError(hi2c, HAL_I2C_ERROR_SIZE);
      }
    }
  }
  else if (((ITFlags & I2C_FLAG_TC) != RESET) && ((ITSources & I2C_IT_TCI) != RESET))
  {
    if (hi2c->XferCount == 0U)
    {
      if (I2C_GET_STOP_MODE(hi2c) != I2C_AUTOEND_MODE)
      {

        if (hi2c->XferOptions == I2C_NO_OPTION_FRAME)
        {

          hi2c->Instance->CR2 |= I2C_CR2_STOP;
        }
        else
        {

          I2C_ITMasterSequentialCplt(hi2c);
        }
      }
    }
    else
    {


      I2C_ITError(hi2c, HAL_I2C_ERROR_SIZE);
    }
  }

  if (((ITFlags & I2C_FLAG_STOPF) != RESET) && ((ITSources & I2C_IT_STOPI) != RESET))
  {

    I2C_ITMasterCplt(hi2c, ITFlags);
  }


  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}









static HAL_StatusTypeDef I2C_Slave_ISR_IT(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources)
{

  __HAL_LOCK(hi2c);

  if (((ITFlags & I2C_FLAG_AF) != RESET) && ((ITSources & I2C_IT_NACKI) != RESET))
  {




    if (hi2c->XferCount == 0U)
    {
      if (((hi2c->XferOptions == I2C_FIRST_AND_LAST_FRAME) || (hi2c->XferOptions == I2C_LAST_FRAME)) && \
          (hi2c->State == HAL_I2C_STATE_LISTEN))
      {

        I2C_ITListenCplt(hi2c, ITFlags);
      }
      else if ((hi2c->XferOptions != I2C_NO_OPTION_FRAME) && (hi2c->State == HAL_I2C_STATE_BUSY_TX_LISTEN))
      {

        __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);


        I2C_Flush_TXDR(hi2c);



        I2C_ITSlaveSequentialCplt(hi2c);
      }
      else
      {

        __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);
      }
    }
    else
    {


      __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);


      hi2c->ErrorCode |= HAL_I2C_ERROR_AF;
    }
  }
  else if (((ITFlags & I2C_FLAG_RXNE) != RESET) && ((ITSources & I2C_IT_RXI) != RESET))
  {
    if (hi2c->XferCount > 0U)
    {

      (*hi2c->pBuffPtr++) = hi2c->Instance->RXDR;
      hi2c->XferSize--;
      hi2c->XferCount--;
    }

    if ((hi2c->XferCount == 0U) && \
        (hi2c->XferOptions != I2C_NO_OPTION_FRAME))
    {

      I2C_ITSlaveSequentialCplt(hi2c);
    }
  }
  else if (((ITFlags & I2C_FLAG_ADDR) != RESET) && ((ITSources & I2C_IT_ADDRI) != RESET))
  {
    I2C_ITAddrCplt(hi2c, ITFlags);
  }
  else if (((ITFlags & I2C_FLAG_TXIS) != RESET) && ((ITSources & I2C_IT_TXI) != RESET))
  {




    if (hi2c->XferCount > 0U)
    {

      hi2c->Instance->TXDR = (*hi2c->pBuffPtr++);
      hi2c->XferCount--;
      hi2c->XferSize--;
    }
    else
    {
      if ((hi2c->XferOptions == I2C_NEXT_FRAME) || (hi2c->XferOptions == I2C_FIRST_FRAME))
      {


        I2C_ITSlaveSequentialCplt(hi2c);
      }
    }
  }


  if (((ITFlags & I2C_FLAG_STOPF) != RESET) && ((ITSources & I2C_IT_STOPI) != RESET))
  {

    I2C_ITSlaveCplt(hi2c, ITFlags);
  }


  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}









static HAL_StatusTypeDef I2C_Master_ISR_DMA(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources)
{
  uint16_t devaddress = 0U;
  uint32_t xfermode = 0U;


  __HAL_LOCK(hi2c);

  if (((ITFlags & I2C_FLAG_AF) != RESET) && ((ITSources & I2C_IT_NACKI) != RESET))
  {

    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);


    hi2c->ErrorCode |= HAL_I2C_ERROR_AF;




    I2C_Enable_IRQ(hi2c, I2C_XFER_CPLT_IT);


    I2C_Flush_TXDR(hi2c);
  }
  else if (((ITFlags & I2C_FLAG_TCR) != RESET) && ((ITSources & I2C_IT_TCI) != RESET))
  {

    __HAL_I2C_DISABLE_IT(hi2c, I2C_IT_TCI);

    if (hi2c->XferCount != 0U)
    {

      devaddress = (hi2c->Instance->CR2 & I2C_CR2_SADD);


      if (hi2c->XferCount > MAX_NBYTE_SIZE)
      {
        hi2c->XferSize = MAX_NBYTE_SIZE;
        xfermode = I2C_RELOAD_MODE;
      }
      else
      {
        hi2c->XferSize = hi2c->XferCount;
        xfermode = I2C_AUTOEND_MODE;
      }


      I2C_TransferConfig(hi2c, devaddress, hi2c->XferSize, xfermode, I2C_NO_STARTSTOP);


      hi2c->XferCount -= hi2c->XferSize;


      if (hi2c->State == HAL_I2C_STATE_BUSY_RX)
      {
        hi2c->Instance->CR1 |= I2C_CR1_RXDMAEN;
      }
      else
      {
        hi2c->Instance->CR1 |= I2C_CR1_TXDMAEN;
      }
    }
    else
    {


      I2C_ITError(hi2c, HAL_I2C_ERROR_SIZE);
    }
  }
  else if (((ITFlags & I2C_FLAG_STOPF) != RESET) && ((ITSources & I2C_IT_STOPI) != RESET))
  {

    I2C_ITMasterCplt(hi2c, ITFlags);
  }


  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}









static HAL_StatusTypeDef I2C_Slave_ISR_DMA(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources)
{

  __HAL_LOCK(hi2c);

  if (((ITFlags & I2C_FLAG_AF) != RESET) && ((ITSources & I2C_IT_NACKI) != RESET))
  {




    if (I2C_GET_DMA_REMAIN_DATA(hi2c) == 0U)
    {

      __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);
    }
    else
    {


      __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);


      hi2c->ErrorCode |= HAL_I2C_ERROR_AF;
    }
  }
  else if (((ITFlags & I2C_FLAG_ADDR) != RESET) && ((ITSources & I2C_IT_ADDRI) != RESET))
  {

    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ADDR);
  }
  else if (((ITFlags & I2C_FLAG_STOPF) != RESET) && ((ITSources & I2C_IT_STOPI) != RESET))
  {

    I2C_ITSlaveCplt(hi2c, ITFlags);
  }


  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}













static HAL_StatusTypeDef I2C_RequestMemoryWrite(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint32_t Timeout, uint32_t Tickstart)
{
  I2C_TransferConfig(hi2c, DevAddress, MemAddSize, I2C_RELOAD_MODE, I2C_GENERATE_START_WRITE);


  if (I2C_WaitOnTXISFlagUntilTimeout(hi2c, Timeout, Tickstart) != HAL_OK)
  {
    if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
    {
      return HAL_ERROR;
    }
    else
    {
      return HAL_TIMEOUT;
    }
  }


  if (MemAddSize == I2C_MEMADD_SIZE_8BIT)
  {

    hi2c->Instance->TXDR = I2C_MEM_ADD_LSB(MemAddress);
  }

  else
  {

    hi2c->Instance->TXDR = I2C_MEM_ADD_MSB(MemAddress);


    if (I2C_WaitOnTXISFlagUntilTimeout(hi2c, Timeout, Tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {
        return HAL_ERROR;
      }
      else
      {
        return HAL_TIMEOUT;
      }
    }


    hi2c->Instance->TXDR = I2C_MEM_ADD_LSB(MemAddress);
  }


  if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TCR, RESET, Timeout, Tickstart) != HAL_OK)
  {
    return HAL_TIMEOUT;
  }

  return HAL_OK;
}













static HAL_StatusTypeDef I2C_RequestMemoryRead(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint32_t Timeout, uint32_t Tickstart)
{
  I2C_TransferConfig(hi2c, DevAddress, MemAddSize, I2C_SOFTEND_MODE, I2C_GENERATE_START_WRITE);


  if (I2C_WaitOnTXISFlagUntilTimeout(hi2c, Timeout, Tickstart) != HAL_OK)
  {
    if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
    {
      return HAL_ERROR;
    }
    else
    {
      return HAL_TIMEOUT;
    }
  }


  if (MemAddSize == I2C_MEMADD_SIZE_8BIT)
  {

    hi2c->Instance->TXDR = I2C_MEM_ADD_LSB(MemAddress);
  }

  else
  {

    hi2c->Instance->TXDR = I2C_MEM_ADD_MSB(MemAddress);


    if (I2C_WaitOnTXISFlagUntilTimeout(hi2c, Timeout, Tickstart) != HAL_OK)
    {
      if (hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {
        return HAL_ERROR;
      }
      else
      {
        return HAL_TIMEOUT;
      }
    }


    hi2c->Instance->TXDR = I2C_MEM_ADD_LSB(MemAddress);
  }


  if (I2C_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TC, RESET, Timeout, Tickstart) != HAL_OK)
  {
    return HAL_TIMEOUT;
  }

  return HAL_OK;
}







static void I2C_ITAddrCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{
  uint8_t transferdirection = 0U;
  uint16_t slaveaddrcode = 0U;
  uint16_t ownadd1code = 0U;
  uint16_t ownadd2code = 0U;


  UNUSED(ITFlags);


  if ((hi2c->State & HAL_I2C_STATE_LISTEN) == HAL_I2C_STATE_LISTEN)
  {
    transferdirection = I2C_GET_DIR(hi2c);
    slaveaddrcode     = I2C_GET_ADDR_MATCH(hi2c);
    ownadd1code       = I2C_GET_OWN_ADDRESS1(hi2c);
    ownadd2code       = I2C_GET_OWN_ADDRESS2(hi2c);


    if (hi2c->Init.AddressingMode == I2C_ADDRESSINGMODE_10BIT)
    {
      if ((slaveaddrcode & SlaveAddr_MSK) == ((ownadd1code >> SlaveAddr_SHIFT) & SlaveAddr_MSK))
      {
        slaveaddrcode = ownadd1code;
        hi2c->AddrEventCount++;
        if (hi2c->AddrEventCount == 2U)
        {

          hi2c->AddrEventCount = 0U;


          __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ADDR);


          __HAL_UNLOCK(hi2c);


          HAL_I2C_AddrCallback(hi2c, transferdirection, slaveaddrcode);
        }
      }
      else
      {
        slaveaddrcode = ownadd2code;


        I2C_Disable_IRQ(hi2c, I2C_XFER_LISTEN_IT);


        __HAL_UNLOCK(hi2c);


        HAL_I2C_AddrCallback(hi2c, transferdirection, slaveaddrcode);
      }
    }

    else
    {

      I2C_Disable_IRQ(hi2c, I2C_XFER_LISTEN_IT);


      __HAL_UNLOCK(hi2c);


      HAL_I2C_AddrCallback(hi2c, transferdirection, slaveaddrcode);
    }
  }

  else
  {

    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ADDR);


    __HAL_UNLOCK(hi2c);
  }
}






static void I2C_ITMasterSequentialCplt(I2C_HandleTypeDef *hi2c)
{

  hi2c->Mode = HAL_I2C_MODE_NONE;



  if (hi2c->State == HAL_I2C_STATE_BUSY_TX)
  {
    hi2c->State         = HAL_I2C_STATE_READY;
    hi2c->PreviousState = I2C_STATE_MASTER_BUSY_TX;
    hi2c->XferISR       = NULL;


    I2C_Disable_IRQ(hi2c, I2C_XFER_TX_IT);


    __HAL_UNLOCK(hi2c);


    HAL_I2C_MasterTxCpltCallback(hi2c);
  }

  else
  {
    hi2c->State         = HAL_I2C_STATE_READY;
    hi2c->PreviousState = I2C_STATE_MASTER_BUSY_RX;
    hi2c->XferISR       = NULL;


    I2C_Disable_IRQ(hi2c, I2C_XFER_RX_IT);


    __HAL_UNLOCK(hi2c);


    HAL_I2C_MasterRxCpltCallback(hi2c);
  }
}






static void I2C_ITSlaveSequentialCplt(I2C_HandleTypeDef *hi2c)
{

  hi2c->Mode = HAL_I2C_MODE_NONE;

  if (hi2c->State == HAL_I2C_STATE_BUSY_TX_LISTEN)
  {

    hi2c->State         = HAL_I2C_STATE_LISTEN;
    hi2c->PreviousState = I2C_STATE_SLAVE_BUSY_TX;


    I2C_Disable_IRQ(hi2c, I2C_XFER_TX_IT);


    __HAL_UNLOCK(hi2c);


    HAL_I2C_SlaveTxCpltCallback(hi2c);
  }

  else if (hi2c->State == HAL_I2C_STATE_BUSY_RX_LISTEN)
  {

    hi2c->State         = HAL_I2C_STATE_LISTEN;
    hi2c->PreviousState = I2C_STATE_SLAVE_BUSY_RX;


    I2C_Disable_IRQ(hi2c, I2C_XFER_RX_IT);


    __HAL_UNLOCK(hi2c);


    HAL_I2C_SlaveRxCpltCallback(hi2c);
  }
}







static void I2C_ITMasterCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{

  __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


  I2C_RESET_CR2(hi2c);


  hi2c->PreviousState = I2C_STATE_NONE;
  hi2c->XferISR       = NULL;
  hi2c->XferOptions   = I2C_NO_OPTION_FRAME;

  if ((ITFlags & I2C_FLAG_AF) != RESET)
  {

    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);


    hi2c->ErrorCode |= HAL_I2C_ERROR_AF;
  }


  I2C_Flush_TXDR(hi2c);


  I2C_Disable_IRQ(hi2c, I2C_XFER_TX_IT | I2C_XFER_RX_IT);


  if ((hi2c->ErrorCode != HAL_I2C_ERROR_NONE) || (hi2c->State == HAL_I2C_STATE_ABORT))
  {

    I2C_ITError(hi2c, hi2c->ErrorCode);
  }

  else if (hi2c->State == HAL_I2C_STATE_BUSY_TX)
  {
    hi2c->State = HAL_I2C_STATE_READY;

    if (hi2c->Mode == HAL_I2C_MODE_MEM)
    {
      hi2c->Mode = HAL_I2C_MODE_NONE;


      __HAL_UNLOCK(hi2c);


      HAL_I2C_MemTxCpltCallback(hi2c);
    }
    else
    {
      hi2c->Mode = HAL_I2C_MODE_NONE;


      __HAL_UNLOCK(hi2c);


      HAL_I2C_MasterTxCpltCallback(hi2c);
    }
  }

  else if (hi2c->State == HAL_I2C_STATE_BUSY_RX)
  {
    hi2c->State = HAL_I2C_STATE_READY;

    if (hi2c->Mode == HAL_I2C_MODE_MEM)
    {
      hi2c->Mode = HAL_I2C_MODE_NONE;


      __HAL_UNLOCK(hi2c);

      HAL_I2C_MemRxCpltCallback(hi2c);
    }
    else
    {
      hi2c->Mode = HAL_I2C_MODE_NONE;


      __HAL_UNLOCK(hi2c);

      HAL_I2C_MasterRxCpltCallback(hi2c);
    }
  }
}







static void I2C_ITSlaveCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{

  __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


  __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_ADDR);


  I2C_Disable_IRQ(hi2c, I2C_XFER_LISTEN_IT | I2C_XFER_TX_IT | I2C_XFER_RX_IT);


  hi2c->Instance->CR2 |= I2C_CR2_NACK;


  I2C_RESET_CR2(hi2c);


  I2C_Flush_TXDR(hi2c);


  if (((hi2c->Instance->CR1 & I2C_CR1_TXDMAEN) == I2C_CR1_TXDMAEN) ||
      ((hi2c->Instance->CR1 & I2C_CR1_RXDMAEN) == I2C_CR1_RXDMAEN))
  {
    hi2c->XferCount = I2C_GET_DMA_REMAIN_DATA(hi2c);
  }


  if (hi2c->XferCount != 0U)
  {

    hi2c->ErrorCode |= HAL_I2C_ERROR_AF;
  }


  if (((ITFlags & I2C_FLAG_RXNE) != RESET))
  {

    (*hi2c->pBuffPtr++) = hi2c->Instance->RXDR;

    if ((hi2c->XferSize > 0U))
    {
      hi2c->XferSize--;
      hi2c->XferCount--;


      hi2c->ErrorCode |= HAL_I2C_ERROR_AF;
    }
  }

  hi2c->PreviousState = I2C_STATE_NONE;
  hi2c->Mode = HAL_I2C_MODE_NONE;
  hi2c->XferISR = NULL;

  if (hi2c->ErrorCode != HAL_I2C_ERROR_NONE)
  {

    I2C_ITError(hi2c, hi2c->ErrorCode);


    if (hi2c->State == HAL_I2C_STATE_LISTEN)
    {

      I2C_ITListenCplt(hi2c, ITFlags);
    }
  }
  else if (hi2c->XferOptions != I2C_NO_OPTION_FRAME)
  {
    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->State = HAL_I2C_STATE_READY;


    __HAL_UNLOCK(hi2c);


    HAL_I2C_ListenCpltCallback(hi2c);
  }

  else if (hi2c->State == HAL_I2C_STATE_BUSY_RX)
  {
    hi2c->State = HAL_I2C_STATE_READY;


    __HAL_UNLOCK(hi2c);


    HAL_I2C_SlaveRxCpltCallback(hi2c);
  }
  else
  {
    hi2c->State = HAL_I2C_STATE_READY;


    __HAL_UNLOCK(hi2c);


    HAL_I2C_SlaveTxCpltCallback(hi2c);
  }
}







static void I2C_ITListenCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{

  hi2c->XferOptions = I2C_NO_OPTION_FRAME;
  hi2c->PreviousState = I2C_STATE_NONE;
  hi2c->State = HAL_I2C_STATE_READY;
  hi2c->Mode = HAL_I2C_MODE_NONE;
  hi2c->XferISR = NULL;


  if (((ITFlags & I2C_FLAG_RXNE) != RESET))
  {

    (*hi2c->pBuffPtr++) = hi2c->Instance->RXDR;

    if ((hi2c->XferSize > 0U))
    {
      hi2c->XferSize--;
      hi2c->XferCount--;


      hi2c->ErrorCode |= HAL_I2C_ERROR_AF;
    }
  }


  I2C_Disable_IRQ(hi2c, I2C_XFER_LISTEN_IT | I2C_XFER_RX_IT | I2C_XFER_TX_IT);


  __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);


  __HAL_UNLOCK(hi2c);


  HAL_I2C_ListenCpltCallback(hi2c);
}







static void I2C_ITError(I2C_HandleTypeDef *hi2c, uint32_t ErrorCode)
{

  hi2c->Mode          = HAL_I2C_MODE_NONE;
  hi2c->XferOptions   = I2C_NO_OPTION_FRAME;
  hi2c->XferCount     = 0U;


  hi2c->ErrorCode |= ErrorCode;


  if ((hi2c->State == HAL_I2C_STATE_LISTEN)         ||
      (hi2c->State == HAL_I2C_STATE_BUSY_TX_LISTEN) ||
      (hi2c->State == HAL_I2C_STATE_BUSY_RX_LISTEN))
  {

    I2C_Disable_IRQ(hi2c, I2C_XFER_RX_IT | I2C_XFER_TX_IT);


    hi2c->State         = HAL_I2C_STATE_LISTEN;
    hi2c->PreviousState = I2C_STATE_NONE;
    hi2c->XferISR       = I2C_Slave_ISR_IT;
  }
  else
  {

    I2C_Disable_IRQ(hi2c, I2C_XFER_LISTEN_IT | I2C_XFER_RX_IT | I2C_XFER_TX_IT);



    if (hi2c->State != HAL_I2C_STATE_ABORT)
    {

      hi2c->State         = HAL_I2C_STATE_READY;
    }
    hi2c->PreviousState = I2C_STATE_NONE;
    hi2c->XferISR       = NULL;
  }


  if ((hi2c->Instance->CR1 & I2C_CR1_TXDMAEN) == I2C_CR1_TXDMAEN)
  {
    hi2c->Instance->CR1 &= ~I2C_CR1_TXDMAEN;



    hi2c->hdmatx->XferAbortCallback = I2C_DMAAbort;


    __HAL_UNLOCK(hi2c);


    if (HAL_DMA_Abort_IT(hi2c->hdmatx) != HAL_OK)
    {

      hi2c->hdmatx->XferAbortCallback(hi2c->hdmatx);
    }
  }

  else if ((hi2c->Instance->CR1 & I2C_CR1_RXDMAEN) == I2C_CR1_RXDMAEN)
  {
    hi2c->Instance->CR1 &= ~I2C_CR1_RXDMAEN;



    hi2c->hdmarx->XferAbortCallback = I2C_DMAAbort;


    __HAL_UNLOCK(hi2c);


    if (HAL_DMA_Abort_IT(hi2c->hdmarx) != HAL_OK)
    {

      hi2c->hdmarx->XferAbortCallback(hi2c->hdmarx);
    }
  }
  else if (hi2c->State == HAL_I2C_STATE_ABORT)
  {
    hi2c->State = HAL_I2C_STATE_READY;


    __HAL_UNLOCK(hi2c);


    HAL_I2C_AbortCpltCallback(hi2c);
  }
  else
  {

    __HAL_UNLOCK(hi2c);


    HAL_I2C_ErrorCallback(hi2c);
  }
}






static void I2C_Flush_TXDR(I2C_HandleTypeDef *hi2c)
{


  if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_TXIS) != RESET)
  {
    hi2c->Instance->TXDR = 0x00U;
  }


  if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_TXE) == RESET)
  {
    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_TXE);
  }
}






static void I2C_DMAMasterTransmitCplt(DMA_HandleTypeDef *hdma)
{
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;


  hi2c->Instance->CR1 &= ~I2C_CR1_TXDMAEN;


  if (hi2c->XferCount == 0U)
  {

    I2C_Enable_IRQ(hi2c, I2C_XFER_CPLT_IT);
  }

  else
  {

    hi2c->pBuffPtr += hi2c->XferSize;


    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }


    HAL_DMA_Start_IT(hi2c->hdmatx, (uint32_t)hi2c->pBuffPtr, (uint32_t)&hi2c->Instance->TXDR, hi2c->XferSize);


    I2C_Enable_IRQ(hi2c, I2C_XFER_RELOAD_IT);
  }
}






static void I2C_DMASlaveTransmitCplt(DMA_HandleTypeDef *hdma)
{

  UNUSED(hdma);




}






static void I2C_DMAMasterReceiveCplt(DMA_HandleTypeDef *hdma)
{
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;


  hi2c->Instance->CR1 &= ~I2C_CR1_RXDMAEN;


  if (hi2c->XferCount == 0U)
  {

    I2C_Enable_IRQ(hi2c, I2C_XFER_CPLT_IT);
  }

  else
  {

    hi2c->pBuffPtr += hi2c->XferSize;


    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }


    HAL_DMA_Start_IT(hi2c->hdmarx, (uint32_t)&hi2c->Instance->RXDR, (uint32_t)hi2c->pBuffPtr, hi2c->XferSize);


    I2C_Enable_IRQ(hi2c, I2C_XFER_RELOAD_IT);
  }
}






static void I2C_DMASlaveReceiveCplt(DMA_HandleTypeDef *hdma)
{

  UNUSED(hdma);




}






static void I2C_DMAError(DMA_HandleTypeDef *hdma)
{
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;


  hi2c->Instance->CR2 |= I2C_CR2_NACK;


  I2C_ITError(hi2c, HAL_I2C_ERROR_DMA);
}







static void I2C_DMAAbort(DMA_HandleTypeDef *hdma)
{
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;


  hi2c->Instance->CR2 |= I2C_CR2_NACK;


  hi2c->hdmatx->XferAbortCallback = NULL;
  hi2c->hdmarx->XferAbortCallback = NULL;


  if (hi2c->State == HAL_I2C_STATE_ABORT)
  {
    hi2c->State = HAL_I2C_STATE_READY;


    HAL_I2C_AbortCpltCallback(hi2c);
  }
  else
  {

    HAL_I2C_ErrorCallback(hi2c);
  }
}











static HAL_StatusTypeDef I2C_WaitOnFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Flag, FlagStatus Status, uint32_t Timeout, uint32_t Tickstart)
{
  while (__HAL_I2C_GET_FLAG(hi2c, Flag) == Status)
  {

    if (Timeout != HAL_MAX_DELAY)
    {
      if ((Timeout == 0U) || ((HAL_GetTick() - Tickstart) > Timeout))
      {
        hi2c->State = HAL_I2C_STATE_READY;
        hi2c->Mode = HAL_I2C_MODE_NONE;


        __HAL_UNLOCK(hi2c);
        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}









static HAL_StatusTypeDef I2C_WaitOnTXISFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart)
{
  while (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_TXIS) == RESET)
  {

    if (I2C_IsAcknowledgeFailed(hi2c, Timeout, Tickstart) != HAL_OK)
    {
      return HAL_ERROR;
    }


    if (Timeout != HAL_MAX_DELAY)
    {
      if ((Timeout == 0U) || ((HAL_GetTick() - Tickstart) > Timeout))
      {
        hi2c->ErrorCode |= HAL_I2C_ERROR_TIMEOUT;
        hi2c->State = HAL_I2C_STATE_READY;
        hi2c->Mode = HAL_I2C_MODE_NONE;


        __HAL_UNLOCK(hi2c);

        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}









static HAL_StatusTypeDef I2C_WaitOnSTOPFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart)
{
  while (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_STOPF) == RESET)
  {

    if (I2C_IsAcknowledgeFailed(hi2c, Timeout, Tickstart) != HAL_OK)
    {
      return HAL_ERROR;
    }


    if ((Timeout == 0U) || ((HAL_GetTick() - Tickstart) > Timeout))
    {
      hi2c->ErrorCode |= HAL_I2C_ERROR_TIMEOUT;
      hi2c->State = HAL_I2C_STATE_READY;
      hi2c->Mode = HAL_I2C_MODE_NONE;


      __HAL_UNLOCK(hi2c);

      return HAL_TIMEOUT;
    }
  }
  return HAL_OK;
}









static HAL_StatusTypeDef I2C_WaitOnRXNEFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart)
{
  while (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_RXNE) == RESET)
  {

    if (I2C_IsAcknowledgeFailed(hi2c, Timeout, Tickstart) != HAL_OK)
    {
      return HAL_ERROR;
    }


    if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_STOPF) == SET)
    {


      if ((__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_RXNE) == SET) && (hi2c->XferSize > 0U))
      {


        return HAL_OK;
      }
      else
      {

        __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


        I2C_RESET_CR2(hi2c);

        hi2c->ErrorCode = HAL_I2C_ERROR_NONE;
        hi2c->State = HAL_I2C_STATE_READY;
        hi2c->Mode = HAL_I2C_MODE_NONE;


        __HAL_UNLOCK(hi2c);

        return HAL_ERROR;
      }
    }


    if ((Timeout == 0U) || ((HAL_GetTick() - Tickstart) > Timeout))
    {
      hi2c->ErrorCode |= HAL_I2C_ERROR_TIMEOUT;
      hi2c->State = HAL_I2C_STATE_READY;


      __HAL_UNLOCK(hi2c);

      return HAL_TIMEOUT;
    }
  }
  return HAL_OK;
}









static HAL_StatusTypeDef I2C_IsAcknowledgeFailed(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart)
{
  if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_AF) == SET)
  {


    while (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_STOPF) == RESET)
    {

      if (Timeout != HAL_MAX_DELAY)
      {
        if ((Timeout == 0U) || ((HAL_GetTick() - Tickstart) > Timeout))
        {
          hi2c->State = HAL_I2C_STATE_READY;
          hi2c->Mode = HAL_I2C_MODE_NONE;


          __HAL_UNLOCK(hi2c);
          return HAL_TIMEOUT;
        }
      }
    }


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);


    __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_STOPF);


    I2C_Flush_TXDR(hi2c);


    I2C_RESET_CR2(hi2c);

    hi2c->ErrorCode = HAL_I2C_ERROR_AF;
    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode = HAL_I2C_MODE_NONE;


    __HAL_UNLOCK(hi2c);

    return HAL_ERROR;
  }
  return HAL_OK;
}




















static void I2C_TransferConfig(I2C_HandleTypeDef *hi2c,  uint16_t DevAddress, uint8_t Size, uint32_t Mode, uint32_t Request)
{

  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));
  assert_param(IS_TRANSFER_MODE(Mode));
  assert_param(IS_TRANSFER_REQUEST(Request));


  MODIFY_REG(hi2c->Instance->CR2, ((I2C_CR2_SADD | I2C_CR2_NBYTES | I2C_CR2_RELOAD | I2C_CR2_AUTOEND | (I2C_CR2_RD_WRN & (uint32_t)(Request >> (31U - I2C_CR2_RD_WRN_Pos))) | I2C_CR2_START | I2C_CR2_STOP)), \
             (uint32_t)(((uint32_t)DevAddress & I2C_CR2_SADD) | (((uint32_t)Size << I2C_CR2_NBYTES_Pos) & I2C_CR2_NBYTES) | (uint32_t)Mode | (uint32_t)Request));
}








static HAL_StatusTypeDef I2C_Enable_IRQ(I2C_HandleTypeDef *hi2c, uint16_t InterruptRequest)
{
  uint32_t tmpisr = 0U;

  if ((hi2c->XferISR == I2C_Master_ISR_DMA) || \
      (hi2c->XferISR == I2C_Slave_ISR_DMA))
  {
    if ((InterruptRequest & I2C_XFER_LISTEN_IT) == I2C_XFER_LISTEN_IT)
    {

      tmpisr |= I2C_IT_ADDRI | I2C_IT_STOPI | I2C_IT_NACKI | I2C_IT_ERRI;
    }

    if ((InterruptRequest & I2C_XFER_ERROR_IT) == I2C_XFER_ERROR_IT)
    {

      tmpisr |= I2C_IT_ERRI | I2C_IT_NACKI;
    }

    if ((InterruptRequest & I2C_XFER_CPLT_IT) == I2C_XFER_CPLT_IT)
    {

      tmpisr |= I2C_IT_STOPI;
    }

    if ((InterruptRequest & I2C_XFER_RELOAD_IT) == I2C_XFER_RELOAD_IT)
    {

      tmpisr |= I2C_IT_TCI;
    }
  }
  else
  {
    if ((InterruptRequest & I2C_XFER_LISTEN_IT) == I2C_XFER_LISTEN_IT)
    {

      tmpisr |= I2C_IT_ADDRI | I2C_IT_STOPI | I2C_IT_NACKI | I2C_IT_ERRI;
    }

    if ((InterruptRequest & I2C_XFER_TX_IT) == I2C_XFER_TX_IT)
    {

      tmpisr |= I2C_IT_ERRI | I2C_IT_TCI | I2C_IT_STOPI | I2C_IT_NACKI | I2C_IT_TXI;
    }

    if ((InterruptRequest & I2C_XFER_RX_IT) == I2C_XFER_RX_IT)
    {

      tmpisr |= I2C_IT_ERRI | I2C_IT_TCI | I2C_IT_STOPI | I2C_IT_NACKI | I2C_IT_RXI;
    }

    if ((InterruptRequest & I2C_XFER_CPLT_IT) == I2C_XFER_CPLT_IT)
    {

      tmpisr |= I2C_IT_STOPI;
    }
  }




  __HAL_I2C_ENABLE_IT(hi2c, tmpisr);

  return HAL_OK;
}








static HAL_StatusTypeDef I2C_Disable_IRQ(I2C_HandleTypeDef *hi2c, uint16_t InterruptRequest)
{
  uint32_t tmpisr = 0U;

  if ((InterruptRequest & I2C_XFER_TX_IT) == I2C_XFER_TX_IT)
  {

    tmpisr |= I2C_IT_TCI | I2C_IT_TXI;

    if ((hi2c->State & HAL_I2C_STATE_LISTEN) != HAL_I2C_STATE_LISTEN)
    {

      tmpisr |= I2C_IT_STOPI | I2C_IT_NACKI | I2C_IT_ERRI;
    }
  }

  if ((InterruptRequest & I2C_XFER_RX_IT) == I2C_XFER_RX_IT)
  {

    tmpisr |= I2C_IT_TCI | I2C_IT_RXI;

    if ((hi2c->State & HAL_I2C_STATE_LISTEN) != HAL_I2C_STATE_LISTEN)
    {

      tmpisr |= I2C_IT_STOPI | I2C_IT_NACKI | I2C_IT_ERRI;
    }
  }

  if ((InterruptRequest & I2C_XFER_LISTEN_IT) == I2C_XFER_LISTEN_IT)
  {

    tmpisr |= I2C_IT_ADDRI | I2C_IT_STOPI | I2C_IT_NACKI | I2C_IT_ERRI;
  }

  if ((InterruptRequest & I2C_XFER_ERROR_IT) == I2C_XFER_ERROR_IT)
  {

    tmpisr |= I2C_IT_ERRI | I2C_IT_NACKI;
  }

  if ((InterruptRequest & I2C_XFER_CPLT_IT) == I2C_XFER_CPLT_IT)
  {

    tmpisr |= I2C_IT_STOPI;
  }

  if ((InterruptRequest & I2C_XFER_RELOAD_IT) == I2C_XFER_RELOAD_IT)
  {

    tmpisr |= I2C_IT_TCI;
  }




  __HAL_I2C_DISABLE_IT(hi2c, tmpisr);

  return HAL_OK;
}





#endif









