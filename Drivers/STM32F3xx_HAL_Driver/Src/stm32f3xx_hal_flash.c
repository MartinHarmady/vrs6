



































































































#include "stm32f3xx_hal.h"





#ifdef HAL_FLASH_MODULE_ENABLED





























FLASH_ProcessTypeDef pFlash;








static  void   FLASH_Program_HalfWord(uint32_t Address, uint16_t Data);
static  void   FLASH_SetErrorCode(void);
extern void    FLASH_PageErase(uint32_t PageAddress);



































HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  uint8_t index = 0U;
  uint8_t nbiterations = 0U;


  __HAL_LOCK(&pFlash);


  assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));
  assert_param(IS_FLASH_PROGRAM_ADDRESS(Address));


    status = FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {
    if(TypeProgram == FLASH_TYPEPROGRAM_HALFWORD)
    {

      nbiterations = 1U;
    }
    else if(TypeProgram == FLASH_TYPEPROGRAM_WORD)
    {

      nbiterations = 2U;
    }
    else
    {

      nbiterations = 4U;
    }

    for (index = 0U; index < nbiterations; index++)
    {
      FLASH_Program_HalfWord((Address + (2U*index)), (uint16_t)(Data >> (16U*index)));


        status = FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);


        CLEAR_BIT(FLASH->CR, FLASH_CR_PG);

      if (status != HAL_OK)
      {
        break;
      }
    }
  }


  __HAL_UNLOCK(&pFlash);

  return status;
}
















HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  HAL_StatusTypeDef status = HAL_OK;


  __HAL_LOCK(&pFlash);


  assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));
  assert_param(IS_FLASH_PROGRAM_ADDRESS(Address));


  __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP | FLASH_IT_ERR);

  pFlash.Address = Address;
  pFlash.Data = Data;

  if(TypeProgram == FLASH_TYPEPROGRAM_HALFWORD)
  {
    pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAMHALFWORD;

    pFlash.DataRemaining = 1U;
  }
  else if(TypeProgram == FLASH_TYPEPROGRAM_WORD)
  {
    pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAMWORD;

    pFlash.DataRemaining = 2U;
  }
  else
  {
    pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAMDOUBLEWORD;

    pFlash.DataRemaining = 4U;
  }


  FLASH_Program_HalfWord(Address, (uint16_t)Data);

  return status;
}





void HAL_FLASH_IRQHandler(void)
{
  uint32_t addresstmp = 0U;


  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR) ||__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR))
  {

    addresstmp = pFlash.Address;

    pFlash.Address = 0xFFFFFFFFU;


    FLASH_SetErrorCode();


    HAL_FLASH_OperationErrorCallback(addresstmp);


    pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
  }


  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP))
  {

    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP);


    if(pFlash.ProcedureOnGoing != FLASH_PROC_NONE)
    {
      if(pFlash.ProcedureOnGoing == FLASH_PROC_PAGEERASE)
      {

        pFlash.DataRemaining--;


        if(pFlash.DataRemaining != 0U)
        {
          addresstmp = pFlash.Address;

          HAL_FLASH_EndOfOperationCallback(addresstmp);


          addresstmp = pFlash.Address + FLASH_PAGE_SIZE;
          pFlash.Address = addresstmp;


          CLEAR_BIT(FLASH->CR, FLASH_CR_PER);

          FLASH_PageErase(addresstmp);
        }
        else
        {


          pFlash.Address = addresstmp = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;

          HAL_FLASH_EndOfOperationCallback(addresstmp);
        }
      }
      else if(pFlash.ProcedureOnGoing == FLASH_PROC_MASSERASE)
      {

        CLEAR_BIT(FLASH->CR, FLASH_CR_MER);



          HAL_FLASH_EndOfOperationCallback(0U);


          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
      else
      {

        pFlash.DataRemaining--;


        if(pFlash.DataRemaining != 0U)
        {

          pFlash.Address += 2U;
          addresstmp = pFlash.Address;


          pFlash.Data = (pFlash.Data >> 16U);


          CLEAR_BIT(FLASH->CR, FLASH_CR_PG);


          FLASH_Program_HalfWord(addresstmp, (uint16_t)pFlash.Data);
        }
        else
        {


          if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMHALFWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address);
          }
          else if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address - 2U);
          }
          else
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address - 6U);
          }


          pFlash.Address = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
      }
    }
  }


  if(pFlash.ProcedureOnGoing == FLASH_PROC_NONE)
  {

    CLEAR_BIT(FLASH->CR, (FLASH_CR_PG | FLASH_CR_PER | FLASH_CR_MER));


    __HAL_FLASH_DISABLE_IT(FLASH_IT_EOP | FLASH_IT_ERR);


    __HAL_UNLOCK(&pFlash);
  }
}










__weak void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue)
{

  UNUSED(ReturnValue);




}









__weak void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue)
{

  UNUSED(ReturnValue);




}
























HAL_StatusTypeDef HAL_FLASH_Unlock(void)
{
  HAL_StatusTypeDef status = HAL_OK;

  if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
  {

    WRITE_REG(FLASH->KEYR, FLASH_KEY1);
    WRITE_REG(FLASH->KEYR, FLASH_KEY2);


    if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
    {
      status = HAL_ERROR;
    }
  }

  return status;
}





HAL_StatusTypeDef HAL_FLASH_Lock(void)
{

  SET_BIT(FLASH->CR, FLASH_CR_LOCK);

  return HAL_OK;
}





HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void)
{
  if (HAL_IS_BIT_CLR(FLASH->CR, FLASH_CR_OPTWRE))
  {

    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY1);
    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY2);
  }
  else
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}





HAL_StatusTypeDef HAL_FLASH_OB_Lock(void)
{

  CLEAR_BIT(FLASH->CR, FLASH_CR_OPTWRE);

  return HAL_OK;
}






HAL_StatusTypeDef HAL_FLASH_OB_Launch(void)
{

  SET_BIT(FLASH->CR, FLASH_CR_OBL_LAUNCH);


  return(FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE));
}
























uint32_t HAL_FLASH_GetError(void)
{
   return pFlash.ErrorCode;
}



















static void FLASH_Program_HalfWord(uint32_t Address, uint16_t Data)
{

  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;


    SET_BIT(FLASH->CR, FLASH_CR_PG);


  *(__IO uint16_t*)Address = Data;
}






HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout)
{




  uint32_t tickstart = HAL_GetTick();

  while(__HAL_FLASH_GET_FLAG(FLASH_FLAG_BSY))
  {
    if (Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick()-tickstart) > Timeout))
      {
        return HAL_TIMEOUT;
      }
    }
  }


  if (__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP))
  {

    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP);
  }

  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR)  ||
     __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR))
  {

    FLASH_SetErrorCode();
    return HAL_ERROR;
  }


  return HAL_OK;
}






static void FLASH_SetErrorCode(void)
{
  uint32_t flags = 0U;

  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR))
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_WRP;
    flags |= FLASH_FLAG_WRPERR;
  }
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR))
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_PROG;
    flags |= FLASH_FLAG_PGERR;
  }

  __HAL_FLASH_CLEAR_FLAG(flags);
}








#endif






