







































#include "stm32f3xx_hal.h"





#ifdef HAL_RCC_MODULE_ENABLED



















#if defined(RCC_CFGR2_ADC1PRES) || defined(RCC_CFGR2_ADCPRE12) || defined(RCC_CFGR2_ADCPRE34) || defined(RCC_CFGR_USBPRE) \
 || defined(RCC_CFGR3_TIM1SW) || defined(RCC_CFGR3_TIM2SW) || defined(RCC_CFGR3_TIM8SW) || defined(RCC_CFGR3_TIM15SW)     \
 || defined(RCC_CFGR3_TIM16SW) || defined(RCC_CFGR3_TIM17SW) || defined(RCC_CFGR3_TIM20SW) || defined(RCC_CFGR3_TIM34SW)  \
 || defined(RCC_CFGR3_HRTIM1SW)



static uint32_t RCC_GetPLLCLKFreq(void);




#endif







































HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{
  uint32_t tickstart = 0U;
  uint32_t temp_reg = 0U;


  assert_param(IS_RCC_PERIPHCLOCK(PeriphClkInit->PeriphClockSelection));


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_RTC) == (RCC_PERIPHCLK_RTC))
  {

    assert_param(IS_RCC_RTCCLKSOURCE(PeriphClkInit->RTCClockSelection));

    FlagStatus       pwrclkchanged = RESET;




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


    temp_reg = (RCC->BDCR & RCC_BDCR_RTCSEL);
    if((temp_reg != 0x00000000U) && (temp_reg != (PeriphClkInit->RTCClockSelection & RCC_BDCR_RTCSEL)))
    {

      temp_reg = (RCC->BDCR & ~(RCC_BDCR_RTCSEL));

      __HAL_RCC_BACKUPRESET_FORCE();
      __HAL_RCC_BACKUPRESET_RELEASE();

      RCC->BDCR = temp_reg;


      if (HAL_IS_BIT_SET(temp_reg, RCC_BDCR_LSEON))
      {

        tickstart = HAL_GetTick();


        while(__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) == RESET)
        {
            if((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
    __HAL_RCC_RTC_CONFIG(PeriphClkInit->RTCClockSelection);


    if(pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_USART1) == RCC_PERIPHCLK_USART1)
  {

    assert_param(IS_RCC_USART1CLKSOURCE(PeriphClkInit->Usart1ClockSelection));


    __HAL_RCC_USART1_CONFIG(PeriphClkInit->Usart1ClockSelection);
  }

#if defined(RCC_CFGR3_USART2SW)

  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_USART2) == RCC_PERIPHCLK_USART2)
  {

    assert_param(IS_RCC_USART2CLKSOURCE(PeriphClkInit->Usart2ClockSelection));


    __HAL_RCC_USART2_CONFIG(PeriphClkInit->Usart2ClockSelection);
  }
#endif

#if defined(RCC_CFGR3_USART3SW)

  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_USART3) == RCC_PERIPHCLK_USART3)
  {

    assert_param(IS_RCC_USART3CLKSOURCE(PeriphClkInit->Usart3ClockSelection));


    __HAL_RCC_USART3_CONFIG(PeriphClkInit->Usart3ClockSelection);
  }
#endif


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_I2C1) == RCC_PERIPHCLK_I2C1)
  {

    assert_param(IS_RCC_I2C1CLKSOURCE(PeriphClkInit->I2c1ClockSelection));


    __HAL_RCC_I2C1_CONFIG(PeriphClkInit->I2c1ClockSelection);
  }

#if defined(STM32F302xE) || defined(STM32F303xE)\
 || defined(STM32F302xC) || defined(STM32F303xC)\
 || defined(STM32F302x8)                        \
 || defined(STM32F373xC)

  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_USB) == RCC_PERIPHCLK_USB)
  {

    assert_param(IS_RCC_USBCLKSOURCE(PeriphClkInit->USBClockSelection));


    __HAL_RCC_USB_CONFIG(PeriphClkInit->USBClockSelection);
  }

#endif




#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
 || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
 || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)\
 || defined(STM32F373xC) || defined(STM32F378xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_I2C2) == RCC_PERIPHCLK_I2C2)
  {

    assert_param(IS_RCC_I2C2CLKSOURCE(PeriphClkInit->I2c2ClockSelection));


    __HAL_RCC_I2C2_CONFIG(PeriphClkInit->I2c2ClockSelection);
  }

#endif




#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
 || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_I2C3) == RCC_PERIPHCLK_I2C3)
  {

    assert_param(IS_RCC_I2C3CLKSOURCE(PeriphClkInit->I2c3ClockSelection));


    __HAL_RCC_I2C3_CONFIG(PeriphClkInit->I2c3ClockSelection);
  }
#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
 || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_UART4) == RCC_PERIPHCLK_UART4)
  {

    assert_param(IS_RCC_UART4CLKSOURCE(PeriphClkInit->Uart4ClockSelection));


    __HAL_RCC_UART4_CONFIG(PeriphClkInit->Uart4ClockSelection);
  }


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_UART5) == RCC_PERIPHCLK_UART5)
  {

    assert_param(IS_RCC_UART5CLKSOURCE(PeriphClkInit->Uart5ClockSelection));


    __HAL_RCC_UART5_CONFIG(PeriphClkInit->Uart5ClockSelection);
  }

#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
 || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
 || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_I2S) == RCC_PERIPHCLK_I2S)
  {

    assert_param(IS_RCC_I2SCLKSOURCE(PeriphClkInit->I2sClockSelection));


    __HAL_RCC_I2S_CONFIG(PeriphClkInit->I2sClockSelection);
  }

#endif



#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_ADC1) == RCC_PERIPHCLK_ADC1)
  {

    assert_param(IS_RCC_ADC1PLLCLK_DIV(PeriphClkInit->Adc1ClockSelection));


    __HAL_RCC_ADC1_CONFIG(PeriphClkInit->Adc1ClockSelection);
  }

#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
 || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
 || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_ADC12) == RCC_PERIPHCLK_ADC12)
  {

    assert_param(IS_RCC_ADC12PLLCLK_DIV(PeriphClkInit->Adc12ClockSelection));


    __HAL_RCC_ADC12_CONFIG(PeriphClkInit->Adc12ClockSelection);
  }

#endif



#if defined(STM32F303xE) || defined(STM32F398xx)\
 || defined(STM32F303xC) || defined(STM32F358xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_ADC34) == RCC_PERIPHCLK_ADC34)
  {

    assert_param(IS_RCC_ADC34PLLCLK_DIV(PeriphClkInit->Adc34ClockSelection));


    __HAL_RCC_ADC34_CONFIG(PeriphClkInit->Adc34ClockSelection);
  }

#endif


#if defined(STM32F373xC) || defined(STM32F378xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_ADC1) == RCC_PERIPHCLK_ADC1)
  {

    assert_param(IS_RCC_ADC1PCLK2_DIV(PeriphClkInit->Adc1ClockSelection));


    __HAL_RCC_ADC1_CONFIG(PeriphClkInit->Adc1ClockSelection);
  }

#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
 || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
 || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
 || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM1) == RCC_PERIPHCLK_TIM1)
  {

    assert_param(IS_RCC_TIM1CLKSOURCE(PeriphClkInit->Tim1ClockSelection));


    __HAL_RCC_TIM1_CONFIG(PeriphClkInit->Tim1ClockSelection);
  }

#endif




#if defined(STM32F303xE) || defined(STM32F398xx)\
 || defined(STM32F303xC) || defined(STM32F358xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM8) == RCC_PERIPHCLK_TIM8)
  {

    assert_param(IS_RCC_TIM8CLKSOURCE(PeriphClkInit->Tim8ClockSelection));


    __HAL_RCC_TIM8_CONFIG(PeriphClkInit->Tim8ClockSelection);
  }

#endif


#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM15) == RCC_PERIPHCLK_TIM15)
  {

    assert_param(IS_RCC_TIM15CLKSOURCE(PeriphClkInit->Tim15ClockSelection));


    __HAL_RCC_TIM15_CONFIG(PeriphClkInit->Tim15ClockSelection);
  }


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM16) == RCC_PERIPHCLK_TIM16)
  {

    assert_param(IS_RCC_TIM16CLKSOURCE(PeriphClkInit->Tim16ClockSelection));


    __HAL_RCC_TIM16_CONFIG(PeriphClkInit->Tim16ClockSelection);
  }


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM17) == RCC_PERIPHCLK_TIM17)
  {

    assert_param(IS_RCC_TIM17CLKSOURCE(PeriphClkInit->Tim17ClockSelection));


    __HAL_RCC_TIM17_CONFIG(PeriphClkInit->Tim17ClockSelection);
  }

#endif

#if defined(STM32F334x8)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_HRTIM1) == RCC_PERIPHCLK_HRTIM1)
  {

    assert_param(IS_RCC_HRTIM1CLKSOURCE(PeriphClkInit->Hrtim1ClockSelection));


    __HAL_RCC_HRTIM1_CONFIG(PeriphClkInit->Hrtim1ClockSelection);
  }

#endif

#if defined(STM32F373xC) || defined(STM32F378xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_SDADC) == RCC_PERIPHCLK_SDADC)
  {

    assert_param(IS_RCC_SDADCSYSCLK_DIV(PeriphClkInit->SdadcClockSelection));


    __HAL_RCC_SDADC_CONFIG(PeriphClkInit->SdadcClockSelection);
  }


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_CEC) == RCC_PERIPHCLK_CEC)
  {

    assert_param(IS_RCC_CECCLKSOURCE(PeriphClkInit->CecClockSelection));


    __HAL_RCC_CEC_CONFIG(PeriphClkInit->CecClockSelection);
  }

#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM2) == RCC_PERIPHCLK_TIM2)
  {

    assert_param(IS_RCC_TIM2CLKSOURCE(PeriphClkInit->Tim2ClockSelection));


    __HAL_RCC_TIM2_CONFIG(PeriphClkInit->Tim2ClockSelection);
  }


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM34) == RCC_PERIPHCLK_TIM34)
  {

    assert_param(IS_RCC_TIM3CLKSOURCE(PeriphClkInit->Tim34ClockSelection));


    __HAL_RCC_TIM34_CONFIG(PeriphClkInit->Tim34ClockSelection);
  }


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM15) == RCC_PERIPHCLK_TIM15)
  {

    assert_param(IS_RCC_TIM15CLKSOURCE(PeriphClkInit->Tim15ClockSelection));


    __HAL_RCC_TIM15_CONFIG(PeriphClkInit->Tim15ClockSelection);
  }


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM16) == RCC_PERIPHCLK_TIM16)
  {

    assert_param(IS_RCC_TIM16CLKSOURCE(PeriphClkInit->Tim16ClockSelection));


    __HAL_RCC_TIM16_CONFIG(PeriphClkInit->Tim16ClockSelection);
  }


  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM17) == RCC_PERIPHCLK_TIM17)
  {

    assert_param(IS_RCC_TIM17CLKSOURCE(PeriphClkInit->Tim17ClockSelection));


    __HAL_RCC_TIM17_CONFIG(PeriphClkInit->Tim17ClockSelection);
  }

#endif

#if defined(STM32F303xE) || defined(STM32F398xx)

  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIM20) == RCC_PERIPHCLK_TIM20)
  {

    assert_param(IS_RCC_TIM20CLKSOURCE(PeriphClkInit->Tim20ClockSelection));


    __HAL_RCC_TIM20_CONFIG(PeriphClkInit->Tim20ClockSelection);
  }
#endif


  return HAL_OK;
}









void HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{


#if defined(RCC_CFGR3_USART2SW) && defined(RCC_CFGR3_USART3SW)
  PeriphClkInit->PeriphClockSelection = RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                        RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_RTC;
#else
  PeriphClkInit->PeriphClockSelection = RCC_PERIPHCLK_USART1 | \
                                        RCC_PERIPHCLK_I2C1   | RCC_PERIPHCLK_RTC;
#endif


  PeriphClkInit->RTCClockSelection = __HAL_RCC_GET_RTC_SOURCE();

  PeriphClkInit->Usart1ClockSelection = __HAL_RCC_GET_USART1_SOURCE();
#if defined(RCC_CFGR3_USART2SW)

  PeriphClkInit->Usart2ClockSelection = __HAL_RCC_GET_USART2_SOURCE();
#endif
#if defined(RCC_CFGR3_USART3SW)

  PeriphClkInit->Usart3ClockSelection = __HAL_RCC_GET_USART3_SOURCE();
#endif

  PeriphClkInit->I2c1ClockSelection = __HAL_RCC_GET_I2C1_SOURCE();

#if defined(STM32F302xE) || defined(STM32F303xE)\
    || defined(STM32F302xC) || defined(STM32F303xC)\
    || defined(STM32F302x8)                        \
    || defined(STM32F373xC)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_USB;

  PeriphClkInit->USBClockSelection = __HAL_RCC_GET_USB_SOURCE();

#endif




#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
    || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
    || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)\
    || defined(STM32F373xC) || defined(STM32F378xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_I2C2;

  PeriphClkInit->I2c2ClockSelection = __HAL_RCC_GET_I2C2_SOURCE();

#endif




#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
    || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_I2C3;

  PeriphClkInit->I2c3ClockSelection = __HAL_RCC_GET_I2C3_SOURCE();

#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
    || defined(STM32F302xC) || defined(STM32F303xC) ||defined(STM32F358xx)

  PeriphClkInit->PeriphClockSelection |= (RCC_PERIPHCLK_UART4  | RCC_PERIPHCLK_UART5);

  PeriphClkInit->Uart4ClockSelection = __HAL_RCC_GET_UART4_SOURCE();

  PeriphClkInit->Uart5ClockSelection = __HAL_RCC_GET_UART5_SOURCE();

#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
    || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
    || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_I2S;

  PeriphClkInit->I2sClockSelection = __HAL_RCC_GET_I2S_SOURCE();

#endif



#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)\
    || defined(STM32F373xC) || defined(STM32F378xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_ADC1;

  PeriphClkInit->Adc1ClockSelection = __HAL_RCC_GET_ADC1_SOURCE();

#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
    || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
    || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_ADC12;

  PeriphClkInit->Adc12ClockSelection = __HAL_RCC_GET_ADC12_SOURCE();

#endif



#if defined(STM32F303xE) || defined(STM32F398xx)\
    || defined(STM32F303xC) || defined(STM32F358xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_ADC34;

  PeriphClkInit->Adc34ClockSelection = __HAL_RCC_GET_ADC34_SOURCE();

#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)\
    || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx)\
    || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)\
    || defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_TIM1;

  PeriphClkInit->Tim1ClockSelection = __HAL_RCC_GET_TIM1_SOURCE();

#endif




#if defined(STM32F303xE) || defined(STM32F398xx)\
    || defined(STM32F303xC) || defined(STM32F358xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_TIM8;

  PeriphClkInit->Tim8ClockSelection = __HAL_RCC_GET_TIM8_SOURCE();

#endif


#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)

  PeriphClkInit->PeriphClockSelection |= (RCC_PERIPHCLK_TIM15 | RCC_PERIPHCLK_TIM16 | RCC_PERIPHCLK_TIM17);

  PeriphClkInit->Tim15ClockSelection = __HAL_RCC_GET_TIM15_SOURCE();

  PeriphClkInit->Tim16ClockSelection = __HAL_RCC_GET_TIM16_SOURCE();

  PeriphClkInit->Tim17ClockSelection = __HAL_RCC_GET_TIM17_SOURCE();

#endif

#if defined(STM32F334x8)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_HRTIM1;

  PeriphClkInit->Hrtim1ClockSelection = __HAL_RCC_GET_HRTIM1_SOURCE();

#endif

#if defined(STM32F373xC) || defined(STM32F378xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_SDADC;

  PeriphClkInit->SdadcClockSelection = __HAL_RCC_GET_SDADC_SOURCE();

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_CEC;

  PeriphClkInit->CecClockSelection = __HAL_RCC_GET_CEC_SOURCE();

#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_TIM2;

  PeriphClkInit->Tim2ClockSelection = __HAL_RCC_GET_TIM2_SOURCE();

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_TIM34;

  PeriphClkInit->Tim34ClockSelection = __HAL_RCC_GET_TIM34_SOURCE();

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_TIM15;

  PeriphClkInit->Tim15ClockSelection = __HAL_RCC_GET_TIM15_SOURCE();

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_TIM16;

  PeriphClkInit->Tim16ClockSelection = __HAL_RCC_GET_TIM16_SOURCE();

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_TIM17;

  PeriphClkInit->Tim17ClockSelection = __HAL_RCC_GET_TIM17_SOURCE();

#endif

#if defined (STM32F303xE) || defined(STM32F398xx)
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_TIM20;

  PeriphClkInit->Tim20ClockSelection = __HAL_RCC_GET_TIM20_SOURCE();
#endif
}




































































































































































uint32_t HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk)
{

  uint32_t frequency = 0U;

  uint32_t srcclk = 0U;
#if defined(RCC_CFGR2_ADC1PRES) || defined(RCC_CFGR2_ADCPRE12) || defined(RCC_CFGR2_ADCPRE34)
  uint16_t adc_pll_prediv_table[16] = { 1U,  2U,  4U,  6U, 8U, 10U, 12U, 16U, 32U, 64U, 128U, 256U, 256U, 256U, 256U, 256U};
#endif
#if defined(RCC_CFGR_SDPRE)
  uint8_t sdadc_prescaler_table[16] = { 2U,  4U,  6U, 8U, 10U, 12U, 14U, 16U, 20U, 24U, 28U, 32U, 36U, 40U, 44U, 48U};
#endif


  assert_param(IS_RCC_PERIPHCLOCK(PeriphClk));

  switch (PeriphClk)
  {
  case RCC_PERIPHCLK_RTC:
    {

      srcclk = __HAL_RCC_GET_RTC_SOURCE();


      if ((srcclk == RCC_RTCCLKSOURCE_LSE) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }

      else if ((srcclk == RCC_RTCCLKSOURCE_LSI) && (HAL_IS_BIT_SET(RCC->CSR, RCC_CSR_LSIRDY)))
      {
        frequency = LSI_VALUE;
      }

      else if ((srcclk == RCC_RTCCLKSOURCE_HSE_DIV32) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSERDY)))
      {
        frequency = HSE_VALUE / 32U;
      }
      break;
    }
  case RCC_PERIPHCLK_USART1:
    {

      srcclk = __HAL_RCC_GET_USART1_SOURCE();


#if defined(RCC_USART1CLKSOURCE_PCLK2)
      if (srcclk == RCC_USART1CLKSOURCE_PCLK2)
      {
        frequency = HAL_RCC_GetPCLK2Freq();
      }
#else
      if (srcclk == RCC_USART1CLKSOURCE_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }
#endif

      else if ((srcclk == RCC_USART1CLKSOURCE_HSI) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)))
      {
        frequency = HSI_VALUE;
      }

      else if (srcclk == RCC_USART1CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }

      else if ((srcclk == RCC_USART1CLKSOURCE_LSE) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }
      break;
    }
#if defined(RCC_CFGR3_USART2SW)
  case RCC_PERIPHCLK_USART2:
    {

      srcclk = __HAL_RCC_GET_USART2_SOURCE();


      if (srcclk == RCC_USART2CLKSOURCE_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }

      else if ((srcclk == RCC_USART2CLKSOURCE_HSI) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)))
      {
        frequency = HSI_VALUE;
      }

      else if (srcclk == RCC_USART2CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }

      else if ((srcclk == RCC_USART2CLKSOURCE_LSE) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_USART3SW)
  case RCC_PERIPHCLK_USART3:
    {

      srcclk = __HAL_RCC_GET_USART3_SOURCE();


      if (srcclk == RCC_USART3CLKSOURCE_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }

      else if ((srcclk == RCC_USART3CLKSOURCE_HSI) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)))
      {
        frequency = HSI_VALUE;
      }

      else if (srcclk == RCC_USART3CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }

      else if ((srcclk == RCC_USART3CLKSOURCE_LSE) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }
     break;
    }
#endif
#if defined(RCC_CFGR3_UART4SW)
  case RCC_PERIPHCLK_UART4:
    {

      srcclk = __HAL_RCC_GET_UART4_SOURCE();


      if (srcclk == RCC_UART4CLKSOURCE_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }

      else if ((srcclk == RCC_UART4CLKSOURCE_HSI) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)))
      {
        frequency = HSI_VALUE;
      }

      else if (srcclk == RCC_UART4CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }

      else if ((srcclk == RCC_UART4CLKSOURCE_LSE) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_UART5SW)
  case RCC_PERIPHCLK_UART5:
    {

      srcclk = __HAL_RCC_GET_UART5_SOURCE();


      if (srcclk == RCC_UART5CLKSOURCE_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }

      else if ((srcclk == RCC_UART5CLKSOURCE_HSI) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)))
      {
        frequency = HSI_VALUE;
      }

      else if (srcclk == RCC_UART5CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }

      else if ((srcclk == RCC_UART5CLKSOURCE_LSE) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }
      break;
    }
#endif
  case RCC_PERIPHCLK_I2C1:
    {

      srcclk = __HAL_RCC_GET_I2C1_SOURCE();


      if ((srcclk == RCC_I2C1CLKSOURCE_HSI) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)))
      {
        frequency = HSI_VALUE;
      }

      else if (srcclk == RCC_I2C1CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      break;
    }
#if defined(RCC_CFGR3_I2C2SW)
  case RCC_PERIPHCLK_I2C2:
    {

      srcclk = __HAL_RCC_GET_I2C2_SOURCE();


      if ((srcclk == RCC_I2C2CLKSOURCE_HSI) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)))
      {
        frequency = HSI_VALUE;
      }

      else if (srcclk == RCC_I2C2CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_I2C3SW)
  case RCC_PERIPHCLK_I2C3:
    {

      srcclk = __HAL_RCC_GET_I2C3_SOURCE();


      if ((srcclk == RCC_I2C3CLKSOURCE_HSI) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)))
      {
        frequency = HSI_VALUE;
      }

      else if (srcclk == RCC_I2C3CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      break;
    }
#endif
#if defined(RCC_CFGR_I2SSRC)
  case RCC_PERIPHCLK_I2S:
    {

      srcclk = __HAL_RCC_GET_I2S_SOURCE();


      if (srcclk == RCC_I2SCLKSOURCE_EXT)
      {

        frequency = 0xDEADDEADU;
      }

      else if (srcclk == RCC_I2SCLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      break;
    }
#endif
#if defined(RCC_CFGR_USBPRE)
  case RCC_PERIPHCLK_USB:
    {

      if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY))
      {

        srcclk = __HAL_RCC_GET_USB_SOURCE();


        if (srcclk == RCC_USBCLKSOURCE_PLL)
        {
          frequency = RCC_GetPLLCLKFreq();
        }

        else
        {
          frequency = (RCC_GetPLLCLKFreq() * 3U) / 2U;
        }
      }
      break;
    }
#endif
#if defined(RCC_CFGR2_ADC1PRES) || defined(RCC_CFGR_ADCPRE)
  case RCC_PERIPHCLK_ADC1:
    {

      srcclk = __HAL_RCC_GET_ADC1_SOURCE();
#if defined(RCC_CFGR2_ADC1PRES)

      if (srcclk == RCC_ADC1PLLCLK_OFF)
      {
          frequency = SystemCoreClock;
      }

      else
      {

        if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY))
        {

          frequency = RCC_GetPLLCLKFreq() / adc_pll_prediv_table[(srcclk >> POSITION_VAL(RCC_CFGR2_ADC1PRES)) & 0xFU];
        }
      }
#else

      frequency = HAL_RCC_GetPCLK2Freq() / (((srcclk  >> POSITION_VAL(RCC_CFGR_ADCPRE)) + 1U) * 2U);
#endif
      break;
    }
#endif
#if defined(RCC_CFGR2_ADCPRE12)
  case RCC_PERIPHCLK_ADC12:
    {

      srcclk = __HAL_RCC_GET_ADC12_SOURCE();

      if (srcclk == RCC_ADC12PLLCLK_OFF)
      {
          frequency = SystemCoreClock;
      }

      else
      {

        if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY))
        {

          frequency = RCC_GetPLLCLKFreq() / adc_pll_prediv_table[(srcclk >> POSITION_VAL(RCC_CFGR2_ADCPRE12)) & 0xF];
        }
      }
      break;
    }
#endif
#if defined(RCC_CFGR2_ADCPRE34)
  case RCC_PERIPHCLK_ADC34:
    {

      srcclk = __HAL_RCC_GET_ADC34_SOURCE();

      if (srcclk == RCC_ADC34PLLCLK_OFF)
      {
          frequency = SystemCoreClock;
      }

      else
      {

        if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY))
        {

          frequency = RCC_GetPLLCLKFreq() / adc_pll_prediv_table[(srcclk >> POSITION_VAL(RCC_CFGR2_ADCPRE34)) & 0xF];
        }
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_TIM1SW)
  case RCC_PERIPHCLK_TIM1:
    {

      srcclk = __HAL_RCC_GET_TIM1_SOURCE();


      if ((srcclk == RCC_TIM1CLK_PLLCLK) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        frequency = RCC_GetPLLCLKFreq();
      }

      else if (srcclk == RCC_TIM1CLK_HCLK)
      {
        frequency = SystemCoreClock;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_TIM2SW)
  case RCC_PERIPHCLK_TIM2:
    {

      srcclk = __HAL_RCC_GET_TIM2_SOURCE();


      if ((srcclk == RCC_TIM2CLK_PLLCLK) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        frequency = RCC_GetPLLCLKFreq();
      }

      else if (srcclk == RCC_TIM2CLK_HCLK)
      {
        frequency = SystemCoreClock;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_TIM8SW)
  case RCC_PERIPHCLK_TIM8:
    {

      srcclk = __HAL_RCC_GET_TIM8_SOURCE();


      if ((srcclk == RCC_TIM8CLK_PLLCLK) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        frequency = RCC_GetPLLCLKFreq();
      }

      else if (srcclk == RCC_TIM8CLK_HCLK)
      {
        frequency = SystemCoreClock;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_TIM15SW)
  case RCC_PERIPHCLK_TIM15:
    {

      srcclk = __HAL_RCC_GET_TIM15_SOURCE();


      if ((srcclk == RCC_TIM15CLK_PLLCLK) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        frequency = RCC_GetPLLCLKFreq();
      }

      else if (srcclk == RCC_TIM15CLK_HCLK)
      {
        frequency = SystemCoreClock;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_TIM16SW)
  case RCC_PERIPHCLK_TIM16:
    {

      srcclk = __HAL_RCC_GET_TIM16_SOURCE();


      if ((srcclk == RCC_TIM16CLK_PLLCLK) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        frequency = RCC_GetPLLCLKFreq();
      }

      else if (srcclk == RCC_TIM16CLK_HCLK)
      {
        frequency = SystemCoreClock;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_TIM17SW)
  case RCC_PERIPHCLK_TIM17:
    {

      srcclk = __HAL_RCC_GET_TIM17_SOURCE();


      if ((srcclk == RCC_TIM17CLK_PLLCLK) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        frequency = RCC_GetPLLCLKFreq();
      }

      else if (srcclk == RCC_TIM17CLK_HCLK)
      {
        frequency = SystemCoreClock;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_TIM20SW)
  case RCC_PERIPHCLK_TIM20:
    {

      srcclk = __HAL_RCC_GET_TIM20_SOURCE();


      if ((srcclk == RCC_TIM20CLK_PLLCLK) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        frequency = RCC_GetPLLCLKFreq();
      }

      else if (srcclk == RCC_TIM20CLK_HCLK)
      {
        frequency = SystemCoreClock;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_TIM34SW)
  case RCC_PERIPHCLK_TIM34:
    {

      srcclk = __HAL_RCC_GET_TIM34_SOURCE();


      if ((srcclk == RCC_TIM34CLK_PLLCLK) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        frequency = RCC_GetPLLCLKFreq();
      }

      else if (srcclk == RCC_TIM34CLK_HCLK)
      {
        frequency = SystemCoreClock;
      }
      break;
    }
#endif
#if defined(RCC_CFGR3_HRTIM1SW)
  case RCC_PERIPHCLK_HRTIM1:
    {

      srcclk = __HAL_RCC_GET_HRTIM1_SOURCE();


      if ((srcclk == RCC_HRTIM1CLK_PLLCLK) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        frequency = RCC_GetPLLCLKFreq();
      }

      else if (srcclk == RCC_HRTIM1CLK_HCLK)
      {
        frequency = SystemCoreClock;
      }
     break;
    }
#endif
#if defined(RCC_CFGR_SDPRE)
  case RCC_PERIPHCLK_SDADC:
    {

      srcclk = __HAL_RCC_GET_SDADC_SOURCE();

      frequency = SystemCoreClock / sdadc_prescaler_table[(srcclk >> POSITION_VAL(RCC_CFGR_SDPRE)) & 0xF];
      break;
    }
#endif
#if defined(RCC_CFGR3_CECSW)
  case RCC_PERIPHCLK_CEC:
    {

      srcclk = __HAL_RCC_GET_CEC_SOURCE();


      if ((srcclk == RCC_CECCLKSOURCE_HSI) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)))
      {
        frequency = HSI_VALUE;
      }

      else if ((srcclk == RCC_CECCLKSOURCE_LSE) && (HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }
      break;
    }
#endif
  default:
    {
      break;
    }
  }
  return(frequency);
}










#if defined(RCC_CFGR2_ADC1PRES) || defined(RCC_CFGR2_ADCPRE12) || defined(RCC_CFGR2_ADCPRE34) || defined(RCC_CFGR_USBPRE) \
 || defined(RCC_CFGR3_TIM1SW) || defined(RCC_CFGR3_TIM2SW) || defined(RCC_CFGR3_TIM8SW) || defined(RCC_CFGR3_TIM15SW)     \
 || defined(RCC_CFGR3_TIM16SW) || defined(RCC_CFGR3_TIM17SW) || defined(RCC_CFGR3_TIM20SW) || defined(RCC_CFGR3_TIM34SW)  \
 || defined(RCC_CFGR3_HRTIM1SW)




static uint32_t RCC_GetPLLCLKFreq(void)
{
  uint32_t pllmul = 0U, pllsource = 0U, prediv = 0U, pllclk = 0U;

  pllmul = RCC->CFGR & RCC_CFGR_PLLMUL;
  pllmul = ( pllmul >> 18U) + 2U;
  pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;
#if defined(RCC_CFGR_PLLSRC_HSI_DIV2)
  if (pllsource != RCC_PLLSOURCE_HSI)
  {
    prediv = (RCC->CFGR2 & RCC_CFGR2_PREDIV) + 1U;

    pllclk = (HSE_VALUE/prediv) * pllmul;
  }
  else
  {

    pllclk = (HSI_VALUE >> 1U) * pllmul;
  }
#else
  prediv = (RCC->CFGR2 & RCC_CFGR2_PREDIV) + 1U;
  if (pllsource == RCC_CFGR_PLLSRC_HSE_PREDIV)
  {

    pllclk = (HSE_VALUE/prediv) * pllmul;
  }
  else
  {

    pllclk = (HSI_VALUE/prediv) * pllmul;
  }
#endif

  return pllclk;
}




#endif





#endif






