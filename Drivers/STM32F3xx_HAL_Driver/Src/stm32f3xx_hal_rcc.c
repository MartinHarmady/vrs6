













































































#include "stm32f3xx_hal.h"










#ifdef HAL_RCC_MODULE_ENABLED







#define RCC_CFGR_HPRE_BITNUMBER           POSITION_VAL(RCC_CFGR_HPRE)
#define RCC_CFGR_PPRE1_BITNUMBER          POSITION_VAL(RCC_CFGR_PPRE1)
#define RCC_CFGR_PPRE2_BITNUMBER          POSITION_VAL(RCC_CFGR_PPRE2)








#define MCO1_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define MCO1_GPIO_PORT        GPIOA
#define MCO1_PIN              GPIO_PIN_8









const uint8_t aPLLMULFactorTable[16] = { 2U,  3U,  4U,  5U,  6U,  7U,  8U,  9U,
                                       10U, 11U, 12U, 13U, 14U, 15U, 16U, 16U};
const uint8_t aPredivFactorTable[16] = { 1U, 2U,  3U,  4U,  5U,  6U,  7U,  8U,
                                         9U,10U, 11U, 12U, 13U, 14U, 15U, 16U};











































































































HAL_StatusTypeDef HAL_RCC_DeInit(void)
{
  uint32_t tickstart = 0;


  SET_BIT(RCC->CR, RCC_CR_HSION);



  tickstart = HAL_GetTick();


  while(READ_BIT(RCC->CR, RCC_CR_HSIRDY) == RESET)
  {
    if((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }


  MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, RCC_CR_HSITRIM_4);


  CLEAR_BIT(RCC->CFGR, RCC_CFGR_SW | RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2 | RCC_CFGR_MCO);



  tickstart = HAL_GetTick();


  while(READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
  {
    if((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }


  SystemCoreClock = HSI_VALUE;


  if(HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK)
  {
    return HAL_ERROR;
  }


  CLEAR_BIT(RCC->CR, RCC_CR_PLLON | RCC_CR_CSSON | RCC_CR_HSEON);


  CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);



  tickstart = HAL_GetTick();
  while(READ_BIT(RCC->CR, RCC_CR_PLLRDY) != 0U)
  {
    if((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }


  CLEAR_REG(RCC->CFGR);


  CLEAR_REG(RCC->CFGR2);


  CLEAR_REG(RCC->CFGR3);


  SET_BIT(RCC->CIR, RCC_CIR_LSIRDYC | RCC_CIR_LSERDYC | RCC_CIR_HSIRDYC | RCC_CIR_HSERDYC | RCC_CIR_PLLRDYC | RCC_CIR_CSSC);


  CLEAR_REG(RCC->CIR);


  __HAL_RCC_CLEAR_RESET_FLAGS();

  return HAL_OK;
}















HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  uint32_t tickstart;


  if(RCC_OscInitStruct == NULL)
  {
    return HAL_ERROR;
  }


  assert_param(IS_RCC_OSCILLATORTYPE(RCC_OscInitStruct->OscillatorType));


  if(((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE)
  {

    assert_param(IS_RCC_HSE(RCC_OscInitStruct->HSEState));


    if((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSE)
       || ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) && (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE)))
    {
      if((__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET) && (RCC_OscInitStruct->HSEState == RCC_HSE_OFF))
      {
        return HAL_ERROR;
      }
    }
    else
    {

      __HAL_RCC_HSE_CONFIG(RCC_OscInitStruct->HSEState);

#if defined(RCC_CFGR_PLLSRC_HSI_DIV2)

      __HAL_RCC_HSE_PREDIV_CONFIG(RCC_OscInitStruct->HSEPredivValue);
#endif


      if(RCC_OscInitStruct->HSEState != RCC_HSE_OFF)
      {

        tickstart = HAL_GetTick();


        while(__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET)
        {
          if((HAL_GetTick() - tickstart ) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {

        tickstart = HAL_GetTick();


        while(__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET)
        {
           if((HAL_GetTick() - tickstart ) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }

  if(((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI)
  {

    assert_param(IS_RCC_HSI(RCC_OscInitStruct->HSIState));
    assert_param(IS_RCC_CALIBRATION_VALUE(RCC_OscInitStruct->HSICalibrationValue));


    if((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSI)
       || ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) && (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSI)))
    {

      if((__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET) && (RCC_OscInitStruct->HSIState != RCC_HSI_ON))
      {
        return HAL_ERROR;
      }

      else
      {

        __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);
      }
    }
    else
    {

      if(RCC_OscInitStruct->HSIState != RCC_HSI_OFF)
      {

        __HAL_RCC_HSI_ENABLE();


        tickstart = HAL_GetTick();


        while(__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) == RESET)
        {
          if((HAL_GetTick() - tickstart ) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }


        __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);
      }
      else
      {

        __HAL_RCC_HSI_DISABLE();


        tickstart = HAL_GetTick();


        while(__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET)
        {
          if((HAL_GetTick() - tickstart ) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }

  if(((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI)
  {

    assert_param(IS_RCC_LSI(RCC_OscInitStruct->LSIState));


    if(RCC_OscInitStruct->LSIState != RCC_LSI_OFF)
    {

      __HAL_RCC_LSI_ENABLE();


      tickstart = HAL_GetTick();


      while(__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) == RESET)
      {
        if((HAL_GetTick() - tickstart ) > LSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {

      __HAL_RCC_LSI_DISABLE();


      tickstart = HAL_GetTick();


      while(__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) != RESET)
      {
        if((HAL_GetTick() - tickstart ) > LSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
  }

  if(((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE)
  {
    FlagStatus       pwrclkchanged = RESET;


    assert_param(IS_RCC_LSE(RCC_OscInitStruct->LSEState));



    if(__HAL_RCC_PWR_IS_CLK_DISABLED())
    {
      __HAL_RCC_PWR_CLK_ENABLE();
      pwrclkchanged = SET;
    }

    if(HAL_IS_BIT_CLR(PWR->CR, PWR_CR_DBP))
    {

      SET_BIT(PWR->CR, PWR_CR_DBP);


      tickstart = HAL_GetTick();

      while(HAL_IS_BIT_CLR(PWR->CR, PWR_CR_DBP))
      {
        if((HAL_GetTick() - tickstart) > RCC_DBP_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }


    __HAL_RCC_LSE_CONFIG(RCC_OscInitStruct->LSEState);

    if(RCC_OscInitStruct->LSEState != RCC_LSE_OFF)
    {

      tickstart = HAL_GetTick();


      while(__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) == RESET)
      {
        if((HAL_GetTick() - tickstart ) > RCC_LSE_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {

      tickstart = HAL_GetTick();


      while(__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) != RESET)
      {
        if((HAL_GetTick() - tickstart ) > RCC_LSE_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }


    if(pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }



  assert_param(IS_RCC_PLL(RCC_OscInitStruct->PLL.PLLState));
  if ((RCC_OscInitStruct->PLL.PLLState) != RCC_PLL_NONE)
  {

    if(__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_SYSCLKSOURCE_STATUS_PLLCLK)
    {
      if((RCC_OscInitStruct->PLL.PLLState) == RCC_PLL_ON)
      {

        assert_param(IS_RCC_PLLSOURCE(RCC_OscInitStruct->PLL.PLLSource));
        assert_param(IS_RCC_PLL_MUL(RCC_OscInitStruct->PLL.PLLMUL));
#if   defined(RCC_CFGR_PLLSRC_HSI_PREDIV)
        assert_param(IS_RCC_PREDIV(RCC_OscInitStruct->PLL.PREDIV));
#endif


        __HAL_RCC_PLL_DISABLE();


        tickstart = HAL_GetTick();


        while(__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  != RESET)
        {
          if((HAL_GetTick() - tickstart ) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }

#if defined(RCC_CFGR_PLLSRC_HSI_PREDIV)

        __HAL_RCC_PLL_CONFIG(RCC_OscInitStruct->PLL.PLLSource,
                             RCC_OscInitStruct->PLL.PREDIV,
                             RCC_OscInitStruct->PLL.PLLMUL);
#else

      __HAL_RCC_PLL_CONFIG(RCC_OscInitStruct->PLL.PLLSource,
                           RCC_OscInitStruct->PLL.PLLMUL);
#endif

        __HAL_RCC_PLL_ENABLE();


        tickstart = HAL_GetTick();


        while(__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  == RESET)
        {
          if((HAL_GetTick() - tickstart ) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {

        __HAL_RCC_PLL_DISABLE();


        tickstart = HAL_GetTick();


        while(__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  != RESET)
        {
          if((HAL_GetTick() - tickstart ) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
    else
    {
      return HAL_ERROR;
    }
  }

  return HAL_OK;
}
























HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency)
{
  uint32_t tickstart = 0U;


  if(RCC_ClkInitStruct == NULL)
  {
    return HAL_ERROR;
  }


  assert_param(IS_RCC_CLOCKTYPE(RCC_ClkInitStruct->ClockType));
  assert_param(IS_FLASH_LATENCY(FLatency));






  if(FLatency > __HAL_FLASH_GET_LATENCY())
  {

    __HAL_FLASH_SET_LATENCY(FLatency);



    if(__HAL_FLASH_GET_LATENCY() != FLatency)
    {
      return HAL_ERROR;
    }
  }


  if(((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_HCLK) == RCC_CLOCKTYPE_HCLK)
  {
    assert_param(IS_RCC_HCLK(RCC_ClkInitStruct->AHBCLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_ClkInitStruct->AHBCLKDivider);
  }


  if(((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK)
  {
    assert_param(IS_RCC_SYSCLKSOURCE(RCC_ClkInitStruct->SYSCLKSource));


    if(RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_HSE)
    {

      if(__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET)
      {
        return HAL_ERROR;
      }
    }

    else if(RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_PLLCLK)
    {

      if(__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY) == RESET)
      {
        return HAL_ERROR;
      }
    }

    else
    {

      if(__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) == RESET)
      {
        return HAL_ERROR;
      }
    }

    __HAL_RCC_SYSCLK_CONFIG(RCC_ClkInitStruct->SYSCLKSource);


    tickstart = HAL_GetTick();

    while (__HAL_RCC_GET_SYSCLK_SOURCE() != (RCC_ClkInitStruct->SYSCLKSource << RCC_CFGR_SWS_Pos))
    {
      if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }
  }

  if(FLatency < __HAL_FLASH_GET_LATENCY())
  {

    __HAL_FLASH_SET_LATENCY(FLatency);



    if(__HAL_FLASH_GET_LATENCY() != FLatency)
    {
      return HAL_ERROR;
    }
  }


  if(((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK1) == RCC_CLOCKTYPE_PCLK1)
  {
    assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB1CLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_ClkInitStruct->APB1CLKDivider);
  }


  if(((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK2) == RCC_CLOCKTYPE_PCLK2)
  {
    assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB2CLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, ((RCC_ClkInitStruct->APB2CLKDivider) << 3U));
  }


  SystemCoreClock = HAL_RCC_GetSysClockFreq() >> AHBPrescTable[(RCC->CFGR & RCC_CFGR_HPRE)>> RCC_CFGR_HPRE_BITNUMBER];


  HAL_InitTick (TICK_INT_PRIORITY);

  return HAL_OK;
}




















#if defined(RCC_CFGR_MCOPRE)




























#else




















#endif
void HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv)
{
  GPIO_InitTypeDef gpio;


  assert_param(IS_RCC_MCO(RCC_MCOx));
  assert_param(IS_RCC_MCODIV(RCC_MCODiv));
  assert_param(IS_RCC_MCO1SOURCE(RCC_MCOSource));


  gpio.Mode      = GPIO_MODE_AF_PP;
  gpio.Speed     = GPIO_SPEED_FREQ_HIGH;
  gpio.Pull      = GPIO_NOPULL;
  gpio.Pin       = MCO1_PIN;
  gpio.Alternate = GPIO_AF0_MCO;


  MCO1_CLK_ENABLE();

  HAL_GPIO_Init(MCO1_GPIO_PORT, &gpio);


  __HAL_RCC_MCO1_CONFIG(RCC_MCOSource, RCC_MCODiv);
}










void HAL_RCC_EnableCSS(void)
{
  *(__IO uint32_t *) RCC_CR_CSSON_BB = (uint32_t)ENABLE;
}





void HAL_RCC_DisableCSS(void)
{
  *(__IO uint32_t *) RCC_CR_CSSON_BB = (uint32_t)DISABLE;
}






























uint32_t HAL_RCC_GetSysClockFreq(void)
{
  uint32_t tmpreg = 0U, prediv = 0U, pllclk = 0U, pllmul = 0U;
  uint32_t sysclockfreq = 0U;

  tmpreg = RCC->CFGR;


  switch (tmpreg & RCC_CFGR_SWS)
  {
    case RCC_SYSCLKSOURCE_STATUS_HSE:
    {
      sysclockfreq = HSE_VALUE;
      break;
    }
    case RCC_SYSCLKSOURCE_STATUS_PLLCLK:
    {
      pllmul = aPLLMULFactorTable[(uint32_t)(tmpreg & RCC_CFGR_PLLMUL) >> POSITION_VAL(RCC_CFGR_PLLMUL)];
      prediv = aPredivFactorTable[(uint32_t)(RCC->CFGR2 & RCC_CFGR2_PREDIV) >> POSITION_VAL(RCC_CFGR2_PREDIV)];
#if defined(RCC_CFGR_PLLSRC_HSI_DIV2)
      if ((tmpreg & RCC_CFGR_PLLSRC) != RCC_PLLSOURCE_HSI)
      {

        pllclk = (HSE_VALUE / prediv) * pllmul;
      }
      else
      {

        pllclk = (HSI_VALUE >> 1U) * pllmul;
      }
#else
      if ((tmpreg & RCC_CFGR_PLLSRC_HSE_PREDIV) == RCC_CFGR_PLLSRC_HSE_PREDIV)
      {

        pllclk = (HSE_VALUE / prediv) * pllmul;
      }
      else
      {

        pllclk = (HSI_VALUE / prediv) * pllmul;
      }
#endif
      sysclockfreq = pllclk;
      break;
    }
    case RCC_SYSCLKSOURCE_STATUS_HSI:
    default:
    {
      sysclockfreq = HSI_VALUE;
      break;
    }
  }
  return sysclockfreq;
}










uint32_t HAL_RCC_GetHCLKFreq(void)
{
  return SystemCoreClock;
}







uint32_t HAL_RCC_GetPCLK1Freq(void)
{

  return (HAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_BITNUMBER]);
}







uint32_t HAL_RCC_GetPCLK2Freq(void)
{

  return (HAL_RCC_GetHCLKFreq()>> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_BITNUMBER]);
}








void HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{

  assert_param(RCC_OscInitStruct != NULL);


  RCC_OscInitStruct->OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI  \
                  | RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI;



  if((RCC->CR &RCC_CR_HSEBYP) == RCC_CR_HSEBYP)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_BYPASS;
  }
  else if((RCC->CR &RCC_CR_HSEON) == RCC_CR_HSEON)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_ON;
  }
  else
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_OFF;
  }
#if defined(RCC_CFGR_PLLSRC_HSI_DIV2)
  RCC_OscInitStruct->HSEPredivValue = __HAL_RCC_HSE_GET_PREDIV();
#endif


  if((RCC->CR &RCC_CR_HSION) == RCC_CR_HSION)
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_ON;
  }
  else
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_OFF;
  }

  RCC_OscInitStruct->HSICalibrationValue = (uint32_t)((RCC->CR & RCC_CR_HSITRIM) >> POSITION_VAL(RCC_CR_HSITRIM));


  if((RCC->BDCR &RCC_BDCR_LSEBYP) == RCC_BDCR_LSEBYP)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_BYPASS;
  }
  else if((RCC->BDCR &RCC_BDCR_LSEON) == RCC_BDCR_LSEON)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_ON;
  }
  else
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_OFF;
  }


  if((RCC->CSR &RCC_CSR_LSION) == RCC_CSR_LSION)
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_ON;
  }
  else
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_OFF;
  }



  if((RCC->CR &RCC_CR_PLLON) == RCC_CR_PLLON)
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_ON;
  }
  else
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_OFF;
  }
  RCC_OscInitStruct->PLL.PLLSource = (uint32_t)(RCC->CFGR & RCC_CFGR_PLLSRC);
  RCC_OscInitStruct->PLL.PLLMUL = (uint32_t)(RCC->CFGR & RCC_CFGR_PLLMUL);
#if defined(RCC_CFGR_PLLSRC_HSI_PREDIV)
  RCC_OscInitStruct->PLL.PREDIV = (uint32_t)(RCC->CFGR2 & RCC_CFGR2_PREDIV);
#endif
}









void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency)
{

  assert_param(RCC_ClkInitStruct != NULL);
  assert_param(pFLatency != NULL);


  RCC_ClkInitStruct->ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;


  RCC_ClkInitStruct->SYSCLKSource = (uint32_t)(RCC->CFGR & RCC_CFGR_SW);


  RCC_ClkInitStruct->AHBCLKDivider = (uint32_t)(RCC->CFGR & RCC_CFGR_HPRE);


  RCC_ClkInitStruct->APB1CLKDivider = (uint32_t)(RCC->CFGR & RCC_CFGR_PPRE1);


  RCC_ClkInitStruct->APB2CLKDivider = (uint32_t)((RCC->CFGR & RCC_CFGR_PPRE2) >> 3U);


  *pFLatency = (uint32_t)(FLASH->ACR & FLASH_ACR_LATENCY);
}






void HAL_RCC_NMI_IRQHandler(void)
{

  if(__HAL_RCC_GET_IT(RCC_IT_CSS))
  {

    HAL_RCC_CSSCallback();


    __HAL_RCC_CLEAR_IT(RCC_IT_CSS);
  }
}





__weak void HAL_RCC_CSSCallback(void)
{



}









#endif









