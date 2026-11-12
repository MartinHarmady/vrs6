

































#if defined(USE_FULL_LL_DRIVER)


#include "stm32f3xx_ll_rcc.h"
#ifdef  USE_FULL_ASSERT
  #include "stm32_assert.h"
#else
  #define assert_param(expr) ((void)0U)
#endif




#if defined(RCC)










#if defined(RCC_CFGR2_ADC1PRES) || defined(RCC_CFGR2_ADCPRE12) || defined(RCC_CFGR2_ADCPRE34)
const uint16_t aADCPrescTable[16]       = {1U, 2U, 4U, 6U, 8U, 10U, 12U, 16U, 32U, 64U, 128U, 256U, 256U, 256U, 256U, 256U};
#endif
#if defined(RCC_CFGR_SDPRE)
const uint8_t aSDADCPrescTable[16]       = {2U, 4U, 6U, 8U, 10U, 12U, 14U, 16U, 20U, 24U, 28U, 32U, 36U, 40U, 44U, 48U};
#endif










#if defined(RCC_CFGR3_USART2SW) && defined(RCC_CFGR3_USART3SW)
#define IS_LL_RCC_USART_CLKSOURCE(__VALUE__)  (((__VALUE__) == LL_RCC_USART1_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_USART2_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_USART3_CLKSOURCE))
#elif defined(RCC_CFGR3_USART2SW) && !defined(RCC_CFGR3_USART3SW)
#define IS_LL_RCC_USART_CLKSOURCE(__VALUE__)  (((__VALUE__) == LL_RCC_USART1_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_USART2_CLKSOURCE))
#elif defined(RCC_CFGR3_USART3SW) && !defined(RCC_CFGR3_USART2SW)
#define IS_LL_RCC_USART_CLKSOURCE(__VALUE__)  (((__VALUE__) == LL_RCC_USART1_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_USART3_CLKSOURCE))
#else
#define IS_LL_RCC_USART_CLKSOURCE(__VALUE__)  (((__VALUE__) == LL_RCC_USART1_CLKSOURCE))
#endif

#if defined(UART4) && defined(UART5)
#define IS_LL_RCC_UART_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_UART4_CLKSOURCE) \
                                             || ((__VALUE__) == LL_RCC_UART5_CLKSOURCE))
#elif defined(UART4)
#define IS_LL_RCC_UART_INSTANCE(__VALUE__)     ((__VALUE__) == LL_RCC_UART4_CLKSOURCE)
#elif defined(UART5)
#define IS_LL_RCC_UART_INSTANCE(__VALUE__)     ((__VALUE__) == LL_RCC_UART5_CLKSOURCE)
#endif

#if defined(RCC_CFGR3_I2C2SW) && defined(RCC_CFGR3_I2C3SW)
#define IS_LL_RCC_I2C_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_I2C1_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_I2C2_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_I2C3_CLKSOURCE))

#elif defined(RCC_CFGR3_I2C2SW) && !defined(RCC_CFGR3_I2C3SW)
#define IS_LL_RCC_I2C_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_I2C1_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_I2C2_CLKSOURCE))

#elif defined(RCC_CFGR3_I2C3SW) && !defined(RCC_CFGR3_I2C2SW)
#define IS_LL_RCC_I2C_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_I2C1_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_I2C3_CLKSOURCE))

#else
#define IS_LL_RCC_I2C_CLKSOURCE(__VALUE__)     ((__VALUE__) == LL_RCC_I2C1_CLKSOURCE)
#endif

#define IS_LL_RCC_I2S_CLKSOURCE(__VALUE__)     ((__VALUE__) == LL_RCC_I2S_CLKSOURCE)

#if defined(USB)
#define IS_LL_RCC_USB_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_USB_CLKSOURCE))
#endif

#if defined(RCC_CFGR_ADCPRE)
#define IS_LL_RCC_ADC_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_ADC_CLKSOURCE))
#else
#if defined(RCC_CFGR2_ADC1PRES)
#define IS_LL_RCC_ADC_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_ADC1_CLKSOURCE))
#elif  defined(RCC_CFGR2_ADCPRE12) && defined(RCC_CFGR2_ADCPRE34)
#define IS_LL_RCC_ADC_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_ADC12_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_ADC34_CLKSOURCE))
#else
#define IS_LL_RCC_ADC_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_ADC12_CLKSOURCE))
#endif
#endif

#if defined(RCC_CFGR_SDPRE)
#define IS_LL_RCC_SDADC_CLKSOURCE(__VALUE__)  (((__VALUE__) == LL_RCC_SDADC_CLKSOURCE))
#endif

#if defined(CEC)
#define IS_LL_RCC_CEC_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_CEC_CLKSOURCE))
#endif

#if defined(RCC_CFGR3_TIMSW)
#if defined(RCC_CFGR3_TIM8SW) && defined(RCC_CFGR3_TIM15SW) && defined(RCC_CFGR3_TIM16SW) \
 && defined(RCC_CFGR3_TIM17SW) && defined(RCC_CFGR3_TIM20SW) && defined(RCC_CFGR3_TIM2SW) \
 && defined(RCC_CFGR3_TIM34SW)

#define IS_LL_RCC_TIM_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_TIM1_CLKSOURCE)  \
                                            || ((__VALUE__) == LL_RCC_TIM2_CLKSOURCE)  \
                                            || ((__VALUE__) == LL_RCC_TIM8_CLKSOURCE)  \
                                            || ((__VALUE__) == LL_RCC_TIM15_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_TIM16_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_TIM17_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_TIM20_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_TIM34_CLKSOURCE))

#elif !defined(RCC_CFGR3_TIM8SW) && defined(RCC_CFGR3_TIM15SW) && defined(RCC_CFGR3_TIM16SW) \
 && defined(RCC_CFGR3_TIM17SW) && !defined(RCC_CFGR3_TIM20SW) && defined(RCC_CFGR3_TIM2SW) \
 && defined(RCC_CFGR3_TIM34SW)

#define IS_LL_RCC_TIM_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_TIM1_CLKSOURCE)  \
                                            || ((__VALUE__) == LL_RCC_TIM2_CLKSOURCE)  \
                                            || ((__VALUE__) == LL_RCC_TIM15_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_TIM16_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_TIM17_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_TIM34_CLKSOURCE))

#elif defined(RCC_CFGR3_TIM8SW) && !defined(RCC_CFGR3_TIM15SW) && !defined(RCC_CFGR3_TIM16SW) \
 && !defined(RCC_CFGR3_TIM17SW) && !defined(RCC_CFGR3_TIM20SW) && !defined(RCC_CFGR3_TIM2SW) \
 && !defined(RCC_CFGR3_TIM34SW)

#define IS_LL_RCC_TIM_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_TIM1_CLKSOURCE)  \
                                            || ((__VALUE__) == LL_RCC_TIM8_CLKSOURCE))

#elif !defined(RCC_CFGR3_TIM8SW) && defined(RCC_CFGR3_TIM15SW) && defined(RCC_CFGR3_TIM16SW) \
 && defined(RCC_CFGR3_TIM17SW) && !defined(RCC_CFGR3_TIM20SW) && !defined(RCC_CFGR3_TIM2SW) \
 && !defined(RCC_CFGR3_TIM34SW)

#define IS_LL_RCC_TIM_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_TIM1_CLKSOURCE)  \
                                            || ((__VALUE__) == LL_RCC_TIM15_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_TIM16_CLKSOURCE) \
                                            || ((__VALUE__) == LL_RCC_TIM17_CLKSOURCE))

#elif !defined(RCC_CFGR3_TIM8SW) && !defined(RCC_CFGR3_TIM15SW) && !defined(RCC_CFGR3_TIM16SW) \
 && !defined(RCC_CFGR3_TIM17SW) && !defined(RCC_CFGR3_TIM20SW) && !defined(RCC_CFGR3_TIM2SW) \
 && !defined(RCC_CFGR3_TIM34SW)

#define IS_LL_RCC_TIM_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_TIM1_CLKSOURCE))

#else
#error "Miss macro"
#endif
#endif

#if defined(HRTIM1)
#define IS_LL_RCC_HRTIM_CLKSOURCE(__VALUE__)  (((__VALUE__) == LL_RCC_HRTIM1_CLKSOURCE))
#endif









uint32_t RCC_GetSystemClockFreq(void);
uint32_t RCC_GetHCLKClockFreq(uint32_t SYSCLK_Frequency);
uint32_t RCC_GetPCLK1ClockFreq(uint32_t HCLK_Frequency);
uint32_t RCC_GetPCLK2ClockFreq(uint32_t HCLK_Frequency);
uint32_t RCC_PLL_GetFreqDomain_SYS(void);





























ErrorStatus LL_RCC_DeInit(void)
{
  uint32_t vl_mask = 0U;


  LL_RCC_HSI_Enable();


  while(LL_RCC_HSI_IsReady() != 1U)
  {}


  LL_RCC_HSI_SetCalibTrimming(0x10U);


  vl_mask = 0xFFFFFFFFU;
  CLEAR_BIT(vl_mask, (RCC_CFGR_SW | RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2 | RCC_CFGR_MCOSEL));
  LL_RCC_WriteReg(CFGR, vl_mask);


  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {}


  vl_mask = 0xFFFFFFFFU;
  CLEAR_BIT(vl_mask, (RCC_CR_PLLON | RCC_CR_CSSON | RCC_CR_HSEON));
  LL_RCC_WriteReg(CR, vl_mask);


  while(LL_RCC_PLL_IsReady() != 0U)
  {}


  LL_RCC_HSE_DisableBypass();


  LL_RCC_WriteReg(CFGR, 0x00000000U);


  LL_RCC_WriteReg(CFGR2, 0x00000000U);


  LL_RCC_WriteReg(CFGR3, 0x00000000U);


  vl_mask = (LL_RCC_CIR_LSIRDYC | LL_RCC_CIR_LSERDYC | LL_RCC_CIR_HSIRDYC | LL_RCC_CIR_HSERDYC | LL_RCC_CIR_PLLRDYC | LL_RCC_CIR_CSSC);
  SET_BIT(RCC->CIR, vl_mask);


  LL_RCC_WriteReg(CIR, 0x00000000U);


  LL_RCC_ClearResetFlags();

  return SUCCESS;
}
































void LL_RCC_GetSystemClocksFreq(LL_RCC_ClocksTypeDef *RCC_Clocks)
{

  RCC_Clocks->SYSCLK_Frequency = RCC_GetSystemClockFreq();


  RCC_Clocks->HCLK_Frequency   = RCC_GetHCLKClockFreq(RCC_Clocks->SYSCLK_Frequency);


  RCC_Clocks->PCLK1_Frequency  = RCC_GetPCLK1ClockFreq(RCC_Clocks->HCLK_Frequency);


  RCC_Clocks->PCLK2_Frequency  = RCC_GetPCLK2ClockFreq(RCC_Clocks->HCLK_Frequency);
}












uint32_t LL_RCC_GetUSARTClockFreq(uint32_t USARTxSource)
{
  uint32_t usart_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_USART_CLKSOURCE(USARTxSource));
#if defined(RCC_CFGR3_USART1SW)
  if (USARTxSource == LL_RCC_USART1_CLKSOURCE)
  {

    switch (LL_RCC_GetUSARTClockSource(USARTxSource))
    {
      case LL_RCC_USART1_CLKSOURCE_SYSCLK:
        usart_frequency = RCC_GetSystemClockFreq();
        break;

      case LL_RCC_USART1_CLKSOURCE_HSI:
        if (LL_RCC_HSI_IsReady())
        {
          usart_frequency = HSI_VALUE;
        }
        break;

      case LL_RCC_USART1_CLKSOURCE_LSE:
        if (LL_RCC_LSE_IsReady())
        {
          usart_frequency = LSE_VALUE;
        }
        break;

#if defined(RCC_CFGR3_USART1SW_PCLK1)
      case LL_RCC_USART1_CLKSOURCE_PCLK1:
      default:
        usart_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
#else
      case LL_RCC_USART1_CLKSOURCE_PCLK2:
      default:
        usart_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
#endif
        break;
    }
  }
#endif

#if defined(RCC_CFGR3_USART2SW)
  if (USARTxSource == LL_RCC_USART2_CLKSOURCE)
  {

    switch (LL_RCC_GetUSARTClockSource(USARTxSource))
    {
      case LL_RCC_USART2_CLKSOURCE_SYSCLK:
        usart_frequency = RCC_GetSystemClockFreq();
        break;

      case LL_RCC_USART2_CLKSOURCE_HSI:
        if (LL_RCC_HSI_IsReady())
        {
          usart_frequency = HSI_VALUE;
        }
        break;

      case LL_RCC_USART2_CLKSOURCE_LSE:
        if (LL_RCC_LSE_IsReady())
        {
          usart_frequency = LSE_VALUE;
        }
        break;

      case LL_RCC_USART2_CLKSOURCE_PCLK1:
      default:
        usart_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
        break;
    }
  }
#endif

#if defined(RCC_CFGR3_USART3SW)
  if (USARTxSource == LL_RCC_USART3_CLKSOURCE)
  {

    switch (LL_RCC_GetUSARTClockSource(USARTxSource))
    {
      case LL_RCC_USART3_CLKSOURCE_SYSCLK:
        usart_frequency = RCC_GetSystemClockFreq();
        break;

      case LL_RCC_USART3_CLKSOURCE_HSI:
        if (LL_RCC_HSI_IsReady())
        {
          usart_frequency = HSI_VALUE;
        }
        break;

      case LL_RCC_USART3_CLKSOURCE_LSE:
        if (LL_RCC_LSE_IsReady())
        {
          usart_frequency = LSE_VALUE;
        }
        break;

      case LL_RCC_USART3_CLKSOURCE_PCLK1:
      default:
        usart_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
        break;
    }
  }

#endif
  return usart_frequency;
}

#if defined(UART4) || defined(UART5)








uint32_t LL_RCC_GetUARTClockFreq(uint32_t UARTxSource)
{
  uint32_t uart_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_UART_CLKSOURCE(UARTxSource));

#if defined(UART4)
  if (UARTxSource == LL_RCC_UART4_CLKSOURCE)
  {

    switch (LL_RCC_GetUARTClockSource(UARTxSource))
    {
      case LL_RCC_UART4_CLKSOURCE_SYSCLK:
        uart_frequency = RCC_GetSystemClockFreq();
        break;

      case LL_RCC_UART4_CLKSOURCE_HSI:
        if (LL_RCC_HSI_IsReady())
        {
          uart_frequency = HSI_VALUE;
        }
        break;

      case LL_RCC_UART4_CLKSOURCE_LSE:
        if (LL_RCC_LSE_IsReady())
        {
          uart_frequency = LSE_VALUE;
        }
        break;

      case LL_RCC_UART4_CLKSOURCE_PCLK1:
      default:
        uart_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
        break;
    }
  }
#endif

#if defined(UART5)
  if (UARTxSource == LL_RCC_UART5_CLKSOURCE)
  {

    switch (LL_RCC_GetUARTClockSource(UARTxSource))
    {
      case LL_RCC_UART5_CLKSOURCE_SYSCLK:
        uart_frequency = RCC_GetSystemClockFreq();
        break;

      case LL_RCC_UART5_CLKSOURCE_HSI:
        if (LL_RCC_HSI_IsReady())
        {
          uart_frequency = HSI_VALUE;
        }
        break;

      case LL_RCC_UART5_CLKSOURCE_LSE:
        if (LL_RCC_LSE_IsReady())
        {
          uart_frequency = LSE_VALUE;
        }
        break;

      case LL_RCC_UART5_CLKSOURCE_PCLK1:
      default:
        uart_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
        break;
    }
  }
#endif

  return uart_frequency;
}
#endif












uint32_t LL_RCC_GetI2CClockFreq(uint32_t I2CxSource)
{
  uint32_t i2c_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_I2C_CLKSOURCE(I2CxSource));


  if (I2CxSource == LL_RCC_I2C1_CLKSOURCE)
  {
    switch (LL_RCC_GetI2CClockSource(I2CxSource))
    {
      case LL_RCC_I2C1_CLKSOURCE_SYSCLK:
        i2c_frequency = RCC_GetSystemClockFreq();
        break;

      case LL_RCC_I2C1_CLKSOURCE_HSI:
      default:
        if (LL_RCC_HSI_IsReady())
        {
          i2c_frequency = HSI_VALUE;
        }
        break;
    }
  }

#if defined(RCC_CFGR3_I2C2SW)

  if (I2CxSource == LL_RCC_I2C2_CLKSOURCE)
  {
    switch (LL_RCC_GetI2CClockSource(I2CxSource))
    {
      case LL_RCC_I2C2_CLKSOURCE_SYSCLK:
        i2c_frequency = RCC_GetSystemClockFreq();
        break;

      case LL_RCC_I2C2_CLKSOURCE_HSI:
      default:
        if (LL_RCC_HSI_IsReady())
        {
          i2c_frequency = HSI_VALUE;
        }
        break;
    }
  }
#endif

#if defined(RCC_CFGR3_I2C3SW)

  if (I2CxSource == LL_RCC_I2C3_CLKSOURCE)
  {
    switch (LL_RCC_GetI2CClockSource(I2CxSource))
    {
      case LL_RCC_I2C3_CLKSOURCE_SYSCLK:
        i2c_frequency = RCC_GetSystemClockFreq();
        break;

      case LL_RCC_I2C3_CLKSOURCE_HSI:
      default:
        if (LL_RCC_HSI_IsReady())
        {
          i2c_frequency = HSI_VALUE;
        }
        break;
    }
  }
#endif

  return i2c_frequency;
}

#if  defined(RCC_CFGR_I2SSRC)






uint32_t LL_RCC_GetI2SClockFreq(uint32_t I2SxSource)
{
  uint32_t i2s_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_I2S_CLKSOURCE(I2SxSource));


  switch (LL_RCC_GetI2SClockSource(I2SxSource))
  {
    case LL_RCC_I2S_CLKSOURCE_SYSCLK:
      i2s_frequency = RCC_GetSystemClockFreq();
      break;

    case LL_RCC_I2S_CLKSOURCE_PIN:
    default:
      i2s_frequency = LL_RCC_PERIPH_FREQUENCY_NA;
      break;
  }

  return i2s_frequency;
}
#endif
#if defined(USB)








uint32_t LL_RCC_GetUSBClockFreq(uint32_t USBxSource)
{
  uint32_t usb_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_USB_CLKSOURCE(USBxSource));


  switch (LL_RCC_GetUSBClockSource(USBxSource))
  {
    case LL_RCC_USB_CLKSOURCE_PLL:
      if (LL_RCC_PLL_IsReady())
      {
        usb_frequency = RCC_PLL_GetFreqDomain_SYS();
      }
      break;

    case LL_RCC_USB_CLKSOURCE_PLL_DIV_1_5:
    default:
      if (LL_RCC_PLL_IsReady())
      {
        usb_frequency = (RCC_PLL_GetFreqDomain_SYS() * 3U) / 2U;
      }
      break;
  }

  return usb_frequency;
}
#endif

#if defined(RCC_CFGR_ADCPRE) || defined(RCC_CFGR2_ADC1PRES) || defined(RCC_CFGR2_ADCPRE12) || defined(RCC_CFGR2_ADCPRE34)











uint32_t LL_RCC_GetADCClockFreq(uint32_t ADCxSource)
{
  uint32_t adc_prescaler = 0U;
  uint32_t adc_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_ADC_CLKSOURCE(ADCxSource));


  adc_prescaler = LL_RCC_GetADCClockSource(ADCxSource);

#if defined(RCC_CFGR_ADCPRE)

  adc_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()))
                  / (((adc_prescaler >> POSITION_VAL(ADCxSource)) + 1U) * 2U);
#else
  if ((adc_prescaler & 0x0000FFFFU) == ((uint32_t)0x00000000U))
  {

    adc_frequency = RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq());
  }
  else
  {

    adc_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()))
                    / (aADCPrescTable[((adc_prescaler & 0x0000FFFFU) >> POSITION_VAL(ADCxSource)) & 0xFU]);
  }
#endif

  return adc_frequency;
}
#endif

#if defined(RCC_CFGR_SDPRE)






uint32_t LL_RCC_GetSDADCClockFreq(uint32_t SDADCxSource)
{
  uint32_t sdadc_prescaler = 0U;
  uint32_t sdadc_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_SDADC_CLKSOURCE(SDADCxSource));


  sdadc_prescaler = LL_RCC_GetSDADCClockSource(SDADCxSource);


  sdadc_frequency = RCC_GetSystemClockFreq()
                    / (aSDADCPrescTable[(sdadc_prescaler >> POSITION_VAL(SDADCxSource)) & 0xFU]);

  return sdadc_frequency;
}
#endif

#if defined(CEC)







uint32_t LL_RCC_GetCECClockFreq(uint32_t CECxSource)
{
  uint32_t cec_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_CEC_CLKSOURCE(CECxSource));


  switch (LL_RCC_GetCECClockSource(CECxSource))
  {
    case LL_RCC_CEC_CLKSOURCE_HSI_DIV244:
      if (LL_RCC_HSI_IsReady())
      {
        cec_frequency = HSI_VALUE / 244U;
      }
      break;

    case LL_RCC_CEC_CLKSOURCE_LSE:
    default:
      if (LL_RCC_LSE_IsReady())
      {
        cec_frequency = LSE_VALUE;
      }
      break;
  }

  return cec_frequency;
}
#endif

#if defined(RCC_CFGR3_TIMSW)















uint32_t LL_RCC_GetTIMClockFreq(uint32_t TIMxSource)
{
  uint32_t tim_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_TIM_CLKSOURCE(TIMxSource));

  if (TIMxSource == LL_RCC_TIM1_CLKSOURCE)
  {

    if (LL_RCC_GetTIMClockSource(LL_RCC_TIM1_CLKSOURCE) == LL_RCC_TIM1_CLKSOURCE_PCLK2)
    {

      tim_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
    }
    else
    {

      tim_frequency = RCC_PLL_GetFreqDomain_SYS();
    }
  }

#if defined(RCC_CFGR3_TIM8SW)
  if (TIMxSource == LL_RCC_TIM8_CLKSOURCE)
  {

    if (LL_RCC_GetTIMClockSource(LL_RCC_TIM8_CLKSOURCE) == LL_RCC_TIM8_CLKSOURCE_PCLK2)
    {

      tim_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
    }
    else
    {

      tim_frequency = RCC_PLL_GetFreqDomain_SYS();
    }
  }
#endif

#if defined(RCC_CFGR3_TIM15SW)
  if (TIMxSource == LL_RCC_TIM15_CLKSOURCE)
  {

    if (LL_RCC_GetTIMClockSource(LL_RCC_TIM15_CLKSOURCE) == LL_RCC_TIM15_CLKSOURCE_PCLK2)
    {

      tim_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
    }
    else
    {

      tim_frequency = RCC_PLL_GetFreqDomain_SYS();
    }
  }
#endif

#if defined(RCC_CFGR3_TIM16SW)
  if (TIMxSource == LL_RCC_TIM16_CLKSOURCE)
  {

    if (LL_RCC_GetTIMClockSource(LL_RCC_TIM16_CLKSOURCE) == LL_RCC_TIM16_CLKSOURCE_PCLK2)
    {

      tim_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
    }
    else
    {

      tim_frequency = RCC_PLL_GetFreqDomain_SYS();
    }
  }
#endif

#if defined(RCC_CFGR3_TIM17SW)
  if (TIMxSource == LL_RCC_TIM17_CLKSOURCE)
  {

    if (LL_RCC_GetTIMClockSource(LL_RCC_TIM17_CLKSOURCE) == LL_RCC_TIM17_CLKSOURCE_PCLK2)
    {

      tim_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
    }
    else
    {

      tim_frequency = RCC_PLL_GetFreqDomain_SYS();
    }
  }
#endif

#if defined(RCC_CFGR3_TIM20SW)
  if (TIMxSource == LL_RCC_TIM20_CLKSOURCE)
  {

    if (LL_RCC_GetTIMClockSource(LL_RCC_TIM20_CLKSOURCE) == LL_RCC_TIM20_CLKSOURCE_PCLK2)
    {

      tim_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
    }
    else
    {

      tim_frequency = RCC_PLL_GetFreqDomain_SYS();
    }
  }
#endif

#if defined(RCC_CFGR3_TIM2SW)
  if (TIMxSource == LL_RCC_TIM2_CLKSOURCE)
  {

    if (LL_RCC_GetTIMClockSource(LL_RCC_TIM2_CLKSOURCE) == LL_RCC_TIM2_CLKSOURCE_PCLK1)
    {

      tim_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
    }
    else
    {

      tim_frequency = RCC_PLL_GetFreqDomain_SYS();
    }
  }
#endif

#if defined(RCC_CFGR3_TIM34SW)
  if (TIMxSource == LL_RCC_TIM34_CLKSOURCE)
  {

    if (LL_RCC_GetTIMClockSource(LL_RCC_TIM34_CLKSOURCE) == LL_RCC_TIM34_CLKSOURCE_PCLK1)
    {

      tim_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
    }
    else
    {

      tim_frequency = RCC_PLL_GetFreqDomain_SYS();
    }
  }
#endif

  return tim_frequency;
}
#endif

#if defined(HRTIM1)






uint32_t LL_RCC_GetHRTIMClockFreq(uint32_t HRTIMxSource)
{
  uint32_t hrtim_frequency = LL_RCC_PERIPH_FREQUENCY_NO;


  assert_param(IS_LL_RCC_HRTIM_CLKSOURCE(HRTIMxSource));


  if (LL_RCC_GetHRTIMClockSource(LL_RCC_HRTIM1_CLKSOURCE) == LL_RCC_HRTIM1_CLKSOURCE_PCLK2)
  {

    hrtim_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
  }
  else
  {

    hrtim_frequency = RCC_PLL_GetFreqDomain_SYS();
  }

  return hrtim_frequency;
}
#endif

















uint32_t RCC_GetSystemClockFreq(void)
{
  uint32_t frequency = 0U;


  switch (LL_RCC_GetSysClkSource())
  {
    case LL_RCC_SYS_CLKSOURCE_STATUS_HSI:
      frequency = HSI_VALUE;
      break;

    case LL_RCC_SYS_CLKSOURCE_STATUS_HSE:
      frequency = HSE_VALUE;
      break;

    case LL_RCC_SYS_CLKSOURCE_STATUS_PLL:
      frequency = RCC_PLL_GetFreqDomain_SYS();
      break;

    default:
      frequency = HSI_VALUE;
      break;
  }

  return frequency;
}






uint32_t RCC_GetHCLKClockFreq(uint32_t SYSCLK_Frequency)
{

  return __LL_RCC_CALC_HCLK_FREQ(SYSCLK_Frequency, LL_RCC_GetAHBPrescaler());
}






uint32_t RCC_GetPCLK1ClockFreq(uint32_t HCLK_Frequency)
{

  return __LL_RCC_CALC_PCLK1_FREQ(HCLK_Frequency, LL_RCC_GetAPB1Prescaler());
}






uint32_t RCC_GetPCLK2ClockFreq(uint32_t HCLK_Frequency)
{

  return __LL_RCC_CALC_PCLK2_FREQ(HCLK_Frequency, LL_RCC_GetAPB2Prescaler());
}





uint32_t RCC_PLL_GetFreqDomain_SYS(void)
{
  uint32_t pllinputfreq = 0U, pllsource = 0U;




  pllsource = LL_RCC_PLL_GetMainSource();

  switch (pllsource)
  {
#if defined(RCC_PLLSRC_PREDIV1_SUPPORT)
    case LL_RCC_PLLSOURCE_HSI:
      pllinputfreq = HSI_VALUE;
#else
    case LL_RCC_PLLSOURCE_HSI_DIV_2:
      pllinputfreq = HSI_VALUE / 2U;
#endif
      break;

    case LL_RCC_PLLSOURCE_HSE:
      pllinputfreq = HSE_VALUE;
      break;

    default:
#if defined(RCC_PLLSRC_PREDIV1_SUPPORT)
      pllinputfreq = HSI_VALUE;
#else
      pllinputfreq = HSI_VALUE / 2U;
#endif
      break;
  }
#if defined(RCC_PLLSRC_PREDIV1_SUPPORT)
  return __LL_RCC_CALC_PLLCLK_FREQ(pllinputfreq, LL_RCC_PLL_GetMultiplicator(), LL_RCC_PLL_GetPrediv());
#else
  return __LL_RCC_CALC_PLLCLK_FREQ((pllinputfreq / (LL_RCC_PLL_GetPrediv() + 1U)), LL_RCC_PLL_GetMultiplicator());
#endif
}








#endif





#endif


