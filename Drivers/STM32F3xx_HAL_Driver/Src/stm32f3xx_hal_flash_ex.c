

























































#include "stm32f3xx_hal.h"




#ifdef HAL_FLASH_MODULE_ENABLED








extern FLASH_ProcessTypeDef pFlash;


















#define FLASH_POSITION_IWDGSW_BIT        (uint32_t)POSITION_VAL(FLASH_OBR_IWDG_SW)
#define FLASH_POSITION_OB_USERDATA0_BIT  (uint32_t)POSITION_VAL(FLASH_OBR_DATA0)
#define FLASH_POSITION_OB_USERDATA1_BIT  (uint32_t)POSITION_VAL(FLASH_OBR_DATA1)


















static void              FLASH_MassErase(void);
void    FLASH_PageErase(uint32_t PageAddress);


static HAL_StatusTypeDef FLASH_OB_EnableWRP(uint32_t WriteProtectPage);
static HAL_StatusTypeDef FLASH_OB_DisableWRP(uint32_t WriteProtectPage);
static HAL_StatusTypeDef FLASH_OB_RDP_LevelConfig(uint8_t ReadProtectLevel);
static HAL_StatusTypeDef FLASH_OB_UserConfig(uint8_t UserConfig);
static HAL_StatusTypeDef FLASH_OB_ProgramData(uint32_t Address, uint8_t Data);
static uint32_t          FLASH_OB_GetWRP(void);
static uint32_t          FLASH_OB_GetRDP(void);
static uint8_t           FLASH_OB_GetUser(void);


















































HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  uint32_t address = 0U;


  __HAL_LOCK(&pFlash);


  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

  if (pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE)
  {


      if (FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK)
      {

        FLASH_MassErase();


        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);


        CLEAR_BIT(FLASH->CR, FLASH_CR_MER);
      }
  }
  else
  {


    assert_param(IS_FLASH_PROGRAM_ADDRESS(pEraseInit->PageAddress));
    assert_param(IS_FLASH_NB_PAGES(pEraseInit->PageAddress, pEraseInit->NbPages));



      if (FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK)
      {

        *PageError = 0xFFFFFFFFU;


        for(address = pEraseInit->PageAddress;
            address < ((pEraseInit->NbPages * FLASH_PAGE_SIZE) + pEraseInit->PageAddress);
            address += FLASH_PAGE_SIZE)
        {
          FLASH_PageErase(address);


          status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);


          CLEAR_BIT(FLASH->CR, FLASH_CR_PER);

          if (status != HAL_OK)
          {

            *PageError = address;
            break;
          }
        }
      }
  }


  __HAL_UNLOCK(&pFlash);

  return status;
}












HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit)
{
  HAL_StatusTypeDef status = HAL_OK;


  __HAL_LOCK(&pFlash);


  if (pFlash.ProcedureOnGoing != FLASH_PROC_NONE)
  {
    return HAL_ERROR;
  }


  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));


  __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP | FLASH_IT_ERR);

  if (pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE)
  {

    pFlash.ProcedureOnGoing = FLASH_PROC_MASSERASE;
        FLASH_MassErase();
  }
  else
  {



    assert_param(IS_FLASH_PROGRAM_ADDRESS(pEraseInit->PageAddress));
    assert_param(IS_FLASH_NB_PAGES(pEraseInit->PageAddress, pEraseInit->NbPages));

    pFlash.ProcedureOnGoing = FLASH_PROC_PAGEERASE;
    pFlash.DataRemaining = pEraseInit->NbPages;
    pFlash.Address = pEraseInit->PageAddress;


    FLASH_PageErase(pEraseInit->PageAddress);
  }

  return status;
}






























HAL_StatusTypeDef HAL_FLASHEx_OBErase(void)
{
  uint8_t rdptmp = OB_RDP_LEVEL_0;
  HAL_StatusTypeDef status = HAL_ERROR;


  rdptmp = FLASH_OB_GetRDP();


  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {

    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;


    SET_BIT(FLASH->CR, FLASH_CR_OPTER);
    SET_BIT(FLASH->CR, FLASH_CR_STRT);


    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);


    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTER);

    if(status == HAL_OK)
    {

      status = FLASH_OB_RDP_LevelConfig(rdptmp);
    }
  }


  return status;
}













HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit)
{
  HAL_StatusTypeDef status = HAL_ERROR;


  __HAL_LOCK(&pFlash);


  assert_param(IS_OPTIONBYTE(pOBInit->OptionType));


  if((pOBInit->OptionType & OPTIONBYTE_WRP) == OPTIONBYTE_WRP)
  {
    assert_param(IS_WRPSTATE(pOBInit->WRPState));
    if (pOBInit->WRPState == OB_WRPSTATE_ENABLE)
    {

      status = FLASH_OB_EnableWRP(pOBInit->WRPPage);
    }
    else
    {

      status = FLASH_OB_DisableWRP(pOBInit->WRPPage);
    }
    if (status != HAL_OK)
    {

      __HAL_UNLOCK(&pFlash);
      return status;
    }
  }


  if((pOBInit->OptionType & OPTIONBYTE_RDP) == OPTIONBYTE_RDP)
  {
    status = FLASH_OB_RDP_LevelConfig(pOBInit->RDPLevel);
    if (status != HAL_OK)
    {

      __HAL_UNLOCK(&pFlash);
      return status;
    }
  }


  if((pOBInit->OptionType & OPTIONBYTE_USER) == OPTIONBYTE_USER)
  {
    status = FLASH_OB_UserConfig(pOBInit->USERConfig);
    if (status != HAL_OK)
    {

      __HAL_UNLOCK(&pFlash);
      return status;
    }
  }


  if((pOBInit->OptionType & OPTIONBYTE_DATA) == OPTIONBYTE_DATA)
  {
    status = FLASH_OB_ProgramData(pOBInit->DATAAddress, pOBInit->DATAData);
    if (status != HAL_OK)
    {

      __HAL_UNLOCK(&pFlash);
      return status;
    }
  }


  __HAL_UNLOCK(&pFlash);

  return status;
}








void HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit)
{
  pOBInit->OptionType = OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER;


  pOBInit->WRPPage = FLASH_OB_GetWRP();


  pOBInit->RDPLevel = FLASH_OB_GetRDP();


  pOBInit->USERConfig = FLASH_OB_GetUser();
}









uint32_t HAL_FLASHEx_OBGetUserData(uint32_t DATAAdress)
{
  uint32_t value = 0U;

  if (DATAAdress == OB_DATA_ADDRESS_DATA0)
  {

    value = READ_BIT(FLASH->OBR, FLASH_OBR_DATA0) >> FLASH_POSITION_OB_USERDATA0_BIT;
  }
  else
  {

    value = READ_BIT(FLASH->OBR, FLASH_OBR_DATA1) >> FLASH_POSITION_OB_USERDATA1_BIT;
  }

  return value;
}


















static void FLASH_MassErase(void)
{

  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;


    SET_BIT(FLASH->CR, FLASH_CR_MER);
    SET_BIT(FLASH->CR, FLASH_CR_STRT);
}












static HAL_StatusTypeDef FLASH_OB_EnableWRP(uint32_t WriteProtectPage)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint16_t WRP0_Data = 0xFFFFU;
#if defined(OB_WRP1_WRP1)
  uint16_t WRP1_Data = 0xFFFFU;
#endif
#if defined(OB_WRP2_WRP2)
  uint16_t WRP2_Data = 0xFFFFU;
#endif
#if defined(OB_WRP3_WRP3)
  uint16_t WRP3_Data = 0xFFFFU;
#endif


  assert_param(IS_OB_WRP(WriteProtectPage));


  WriteProtectPage = (uint32_t)(~((~FLASH_OB_GetWRP()) | WriteProtectPage));

#if defined(OB_WRP_PAGES0TO15MASK)
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO15MASK);
#endif

#if defined(OB_WRP_PAGES16TO31MASK)
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES16TO31MASK) >> 8U);
#endif

#if defined(OB_WRP_PAGES32TO47MASK)
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO47MASK) >> 16U);
#endif

#if defined(OB_WRP_PAGES48TO127MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO127MASK) >> 24U);
#elif defined(OB_WRP_PAGES48TO255MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO255MASK) >> 24U);
#endif


  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {

    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;


    status = HAL_FLASHEx_OBErase();
    if (status == HAL_OK)
    {

      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

#if defined(OB_WRP0_WRP0)
      if(WRP0_Data != 0xFFU)
      {
        OB->WRP0 &= WRP0_Data;


        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif

#if defined(OB_WRP1_WRP1)
      if((status == HAL_OK) && (WRP1_Data != 0xFFU))
      {
        OB->WRP1 &= WRP1_Data;


        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif

#if defined(OB_WRP2_WRP2)
      if((status == HAL_OK) && (WRP2_Data != 0xFFU))
      {
        OB->WRP2 &= WRP2_Data;


        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif

#if defined(OB_WRP3_WRP3)
      if((status == HAL_OK) && (WRP3_Data != 0xFFU))
      {
        OB->WRP3 &= WRP3_Data;


        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif


      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }

  return status;
}












static HAL_StatusTypeDef FLASH_OB_DisableWRP(uint32_t WriteProtectPage)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint16_t WRP0_Data = 0xFFFFU;
#if defined(OB_WRP1_WRP1)
  uint16_t WRP1_Data = 0xFFFFU;
#endif
#if defined(OB_WRP2_WRP2)
  uint16_t WRP2_Data = 0xFFFFU;
#endif
#if defined(OB_WRP3_WRP3)
  uint16_t WRP3_Data = 0xFFFFU;
#endif


  assert_param(IS_OB_WRP(WriteProtectPage));


  WriteProtectPage = (FLASH_OB_GetWRP() | WriteProtectPage);

#if defined(OB_WRP_PAGES0TO15MASK)
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO15MASK);
#endif

#if defined(OB_WRP_PAGES16TO31MASK)
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES16TO31MASK) >> 8U);
#endif

#if defined(OB_WRP_PAGES32TO47MASK)
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO47MASK) >> 16U);
#endif

#if defined(OB_WRP_PAGES48TO127MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO127MASK) >> 24U);
#elif defined(OB_WRP_PAGES48TO255MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO255MASK) >> 24U);
#endif



  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {

    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;


    status = HAL_FLASHEx_OBErase();
    if (status == HAL_OK)
    {
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

#if defined(OB_WRP0_WRP0)
      if(WRP0_Data != 0xFFU)
      {
        OB->WRP0 |= WRP0_Data;


        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif

#if defined(OB_WRP1_WRP1)
      if((status == HAL_OK) && (WRP1_Data != 0xFFU))
      {
        OB->WRP1 |= WRP1_Data;


        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif

#if defined(OB_WRP2_WRP2)
      if((status == HAL_OK) && (WRP2_Data != 0xFFU))
      {
        OB->WRP2 |= WRP2_Data;


        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif

#if defined(OB_WRP3_WRP3)
      if((status == HAL_OK) && (WRP3_Data != 0xFFU))
      {
        OB->WRP3 |= WRP3_Data;


        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif


      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  return status;
}











static HAL_StatusTypeDef FLASH_OB_RDP_LevelConfig(uint8_t ReadProtectLevel)
{
  HAL_StatusTypeDef status = HAL_OK;


  assert_param(IS_OB_RDP_LEVEL(ReadProtectLevel));


  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {

    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;


    SET_BIT(FLASH->CR, FLASH_CR_OPTER);
    SET_BIT(FLASH->CR, FLASH_CR_STRT);


    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);


    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTER);

    if(status == HAL_OK)
    {

      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

      WRITE_REG(OB->RDP, ReadProtectLevel);


      status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);


      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }

  return status;
}









static HAL_StatusTypeDef FLASH_OB_UserConfig(uint8_t UserConfig)
{
  HAL_StatusTypeDef status = HAL_OK;


  assert_param(IS_OB_IWDG_SOURCE((UserConfig&OB_IWDG_SW)));
  assert_param(IS_OB_STOP_SOURCE((UserConfig&OB_STOP_NO_RST)));
  assert_param(IS_OB_STDBY_SOURCE((UserConfig&OB_STDBY_NO_RST)));
  assert_param(IS_OB_BOOT1((UserConfig&OB_BOOT1_SET)));
  assert_param(IS_OB_VDDA_ANALOG((UserConfig&OB_VDDA_ANALOG_ON)));
  assert_param(IS_OB_SRAM_PARITY((UserConfig&OB_SRAM_PARITY_RESET)));
#if defined(FLASH_OBR_SDADC12_VDD_MONITOR)
  assert_param(IS_OB_SDACD_VDD_MONITOR((UserConfig&OB_SDACD_VDD_MONITOR_SET)));
#endif


  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {

    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;


    SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

#if   defined(FLASH_OBR_SDADC12_VDD_MONITOR)
    OB->USER = (UserConfig | 0x08U);
#else
    OB->USER = (UserConfig | 0x88U);
#endif


    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);


    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
  }

  return status;
}













static HAL_StatusTypeDef FLASH_OB_ProgramData(uint32_t Address, uint8_t Data)
{
  HAL_StatusTypeDef status = HAL_ERROR;


  assert_param(IS_OB_DATA_ADDRESS(Address));


  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {

    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;


    SET_BIT(FLASH->CR, FLASH_CR_OPTPG);
    *(__IO uint16_t*)Address = Data;


    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);


    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
  }

  return status;
}





static uint32_t FLASH_OB_GetWRP(void)
{

  return (uint32_t)(READ_REG(FLASH->WRPR));
}









static uint32_t FLASH_OB_GetRDP(void)
{
  uint32_t tmp_reg = 0U;


#if defined(FLASH_OBR_RDPRT)
  tmp_reg = READ_BIT(FLASH->OBR, FLASH_OBR_RDPRT);
#endif
#if defined(FLASH_OBR_LEVEL1_PROT)
  tmp_reg = READ_BIT(FLASH->OBR, (FLASH_OBR_LEVEL1_PROT | FLASH_OBR_LEVEL2_PROT));
#endif

#if defined(FLASH_OBR_RDPRT)
  if (tmp_reg == FLASH_OBR_RDPRT_1)
#endif
#if defined(FLASH_OBR_LEVEL1_PROT)
  if (tmp_reg == FLASH_OBR_LEVEL1_PROT)
#endif
  {
    return OB_RDP_LEVEL_1;
  }
#if   defined(FLASH_OBR_RDPRT)
  else if (tmp_reg == FLASH_OBR_RDPRT_2)
#elif defined(FLASH_OBR_LEVEL2_PROT)
  else if (tmp_reg == FLASH_OBR_LEVEL2_PROT)
#endif
  {
    return OB_RDP_LEVEL_2;
  }
  else
  {
    return OB_RDP_LEVEL_0;
  }
}







static uint8_t FLASH_OB_GetUser(void)
{

  return (uint8_t)((READ_REG(FLASH->OBR) & FLASH_OBR_USER) >> FLASH_POSITION_IWDGSW_BIT);
}
























void FLASH_PageErase(uint32_t PageAddress)
{

  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;


    SET_BIT(FLASH->CR, FLASH_CR_PER);
    WRITE_REG(FLASH->AR, PageAddress);
    SET_BIT(FLASH->CR, FLASH_CR_STRT);
}









#endif





