

































#if defined(USE_FULL_LL_DRIVER)


#include "stm32f3xx_ll_usart.h"
#include "stm32f3xx_ll_rcc.h"
#include "stm32f3xx_ll_bus.h"
#ifdef  USE_FULL_ASSERT
#include "stm32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif





#if defined (USART1) || defined (USART2) || defined (USART3) || defined (UART4) || defined (UART5)
























#define IS_LL_USART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) <= 9000000U)


#define IS_LL_USART_BRR_MIN(__VALUE__) ((__VALUE__) >= 16U)


#define IS_LL_USART_BRR_MAX(__VALUE__) ((__VALUE__) <= 0x0000FFFFU)

#define IS_LL_USART_DIRECTION(__VALUE__) (((__VALUE__) == LL_USART_DIRECTION_NONE) \
                                       || ((__VALUE__) == LL_USART_DIRECTION_RX) \
                                       || ((__VALUE__) == LL_USART_DIRECTION_TX) \
                                       || ((__VALUE__) == LL_USART_DIRECTION_TX_RX))

#define IS_LL_USART_PARITY(__VALUE__) (((__VALUE__) == LL_USART_PARITY_NONE) \
                                    || ((__VALUE__) == LL_USART_PARITY_EVEN) \
                                    || ((__VALUE__) == LL_USART_PARITY_ODD))

#if defined(USART_7BITS_SUPPORT)
#define IS_LL_USART_DATAWIDTH(__VALUE__) (((__VALUE__) == LL_USART_DATAWIDTH_7B) \
                                       || ((__VALUE__) == LL_USART_DATAWIDTH_8B) \
                                       || ((__VALUE__) == LL_USART_DATAWIDTH_9B))
#else
#define IS_LL_USART_DATAWIDTH(__VALUE__) (((__VALUE__) == LL_USART_DATAWIDTH_8B) \
                                       || ((__VALUE__) == LL_USART_DATAWIDTH_9B))
#endif

#define IS_LL_USART_OVERSAMPLING(__VALUE__) (((__VALUE__) == LL_USART_OVERSAMPLING_16) \
                                          || ((__VALUE__) == LL_USART_OVERSAMPLING_8))

#define IS_LL_USART_LASTBITCLKOUTPUT(__VALUE__) (((__VALUE__) == LL_USART_LASTCLKPULSE_NO_OUTPUT) \
                                              || ((__VALUE__) == LL_USART_LASTCLKPULSE_OUTPUT))

#define IS_LL_USART_CLOCKPHASE(__VALUE__) (((__VALUE__) == LL_USART_PHASE_1EDGE) \
                                        || ((__VALUE__) == LL_USART_PHASE_2EDGE))

#define IS_LL_USART_CLOCKPOLARITY(__VALUE__) (((__VALUE__) == LL_USART_POLARITY_LOW) \
                                           || ((__VALUE__) == LL_USART_POLARITY_HIGH))

#define IS_LL_USART_CLOCKOUTPUT(__VALUE__) (((__VALUE__) == LL_USART_CLOCK_DISABLE) \
                                         || ((__VALUE__) == LL_USART_CLOCK_ENABLE))

#define IS_LL_USART_STOPBITS(__VALUE__) (((__VALUE__) == LL_USART_STOPBITS_0_5) \
                                      || ((__VALUE__) == LL_USART_STOPBITS_1) \
                                      || ((__VALUE__) == LL_USART_STOPBITS_1_5) \
                                      || ((__VALUE__) == LL_USART_STOPBITS_2))

#define IS_LL_USART_HWCONTROL(__VALUE__) (((__VALUE__) == LL_USART_HWCONTROL_NONE) \
                                       || ((__VALUE__) == LL_USART_HWCONTROL_RTS) \
                                       || ((__VALUE__) == LL_USART_HWCONTROL_CTS) \
                                       || ((__VALUE__) == LL_USART_HWCONTROL_RTS_CTS))























ErrorStatus LL_USART_DeInit(USART_TypeDef *USARTx)
{
  ErrorStatus status = SUCCESS;


  assert_param(IS_UART_INSTANCE(USARTx));

  if (USARTx == USART1)
  {

    LL_APB2_GRP1_ForceReset(LL_APB2_GRP1_PERIPH_USART1);


    LL_APB2_GRP1_ReleaseReset(LL_APB2_GRP1_PERIPH_USART1);
  }
  else if (USARTx == USART2)
  {

    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_USART2);


    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_USART2);
  }
  else if (USARTx == USART3)
  {

    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_USART3);


    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_USART3);
  }
#if defined(UART4)
  else if (USARTx == UART4)
  {

    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_UART4);


    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_UART4);
  }
#endif
#if defined(UART5)
  else if (USARTx == UART5)
  {

    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_UART5);


    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_UART5);
  }
#endif
  else
  {
    status = ERROR;
  }

  return (status);
}














ErrorStatus LL_USART_Init(USART_TypeDef *USARTx, LL_USART_InitTypeDef *USART_InitStruct)
{
  ErrorStatus status = ERROR;
  uint32_t periphclk = LL_RCC_PERIPH_FREQUENCY_NO;
#if defined(STM32F303x8)||defined(STM32F334x8)||defined(STM32F328xx)||defined(STM32F301x8)||defined(STM32F302x8)||defined(STM32F318xx)
  LL_RCC_ClocksTypeDef RCC_Clocks;
#endif


  assert_param(IS_UART_INSTANCE(USARTx));
  assert_param(IS_LL_USART_BAUDRATE(USART_InitStruct->BaudRate));
  assert_param(IS_LL_USART_DATAWIDTH(USART_InitStruct->DataWidth));
  assert_param(IS_LL_USART_STOPBITS(USART_InitStruct->StopBits));
  assert_param(IS_LL_USART_PARITY(USART_InitStruct->Parity));
  assert_param(IS_LL_USART_DIRECTION(USART_InitStruct->TransferDirection));
  assert_param(IS_LL_USART_HWCONTROL(USART_InitStruct->HardwareFlowControl));
  assert_param(IS_LL_USART_OVERSAMPLING(USART_InitStruct->OverSampling));



  if (LL_USART_IsEnabled(USARTx) == 0U)
  {







    MODIFY_REG(USARTx->CR1,
               (USART_CR1_M | USART_CR1_PCE | USART_CR1_PS |
                USART_CR1_TE | USART_CR1_RE | USART_CR1_OVER8),
               (USART_InitStruct->DataWidth | USART_InitStruct->Parity |
                USART_InitStruct->TransferDirection | USART_InitStruct->OverSampling));






    LL_USART_SetStopBitsLength(USARTx, USART_InitStruct->StopBits);





    LL_USART_SetHWFlowCtrl(USARTx, USART_InitStruct->HardwareFlowControl);




    if (USARTx == USART1)
    {
      periphclk = LL_RCC_GetUSARTClockFreq(LL_RCC_USART1_CLKSOURCE);
    }
    else if (USARTx == USART2)
    {
#if defined (RCC_CFGR3_USART2SW)
      periphclk = LL_RCC_GetUSARTClockFreq(LL_RCC_USART2_CLKSOURCE);
#else

      LL_RCC_GetSystemClocksFreq(&RCC_Clocks);
      periphclk = RCC_Clocks.PCLK1_Frequency;
#endif
    }
    else if (USARTx == USART3)
    {
#if defined (RCC_CFGR3_USART3SW)
      periphclk = LL_RCC_GetUSARTClockFreq(LL_RCC_USART3_CLKSOURCE);
#else

      LL_RCC_GetSystemClocksFreq(&RCC_Clocks);
      periphclk = RCC_Clocks.PCLK1_Frequency;
#endif
    }
#if defined(UART4)
    else if (USARTx == UART4)
    {
      periphclk = LL_RCC_GetUARTClockFreq(LL_RCC_UART4_CLKSOURCE);
    }
#endif
#if defined(UART5)
    else if (USARTx == UART5)
    {
      periphclk = LL_RCC_GetUARTClockFreq(LL_RCC_UART5_CLKSOURCE);
    }
#endif
    else
    {

    }





    if ((periphclk != LL_RCC_PERIPH_FREQUENCY_NO)
        && (USART_InitStruct->BaudRate != 0U))
    {
      status = SUCCESS;
      LL_USART_SetBaudRate(USARTx,
                           periphclk,
                           USART_InitStruct->OverSampling,
                           USART_InitStruct->BaudRate);


      assert_param(IS_LL_USART_BRR_MIN(USARTx->BRR));


      assert_param(IS_LL_USART_BRR_MAX(USARTx->BRR));
    }
  }


  return (status);
}








void LL_USART_StructInit(LL_USART_InitTypeDef *USART_InitStruct)
{

  USART_InitStruct->BaudRate            = 9600U;
  USART_InitStruct->DataWidth           = LL_USART_DATAWIDTH_8B;
  USART_InitStruct->StopBits            = LL_USART_STOPBITS_1;
  USART_InitStruct->Parity              = LL_USART_PARITY_NONE ;
  USART_InitStruct->TransferDirection   = LL_USART_DIRECTION_TX_RX;
  USART_InitStruct->HardwareFlowControl = LL_USART_HWCONTROL_NONE;
  USART_InitStruct->OverSampling        = LL_USART_OVERSAMPLING_16;
}













ErrorStatus LL_USART_ClockInit(USART_TypeDef *USARTx, LL_USART_ClockInitTypeDef *USART_ClockInitStruct)
{
  ErrorStatus status = SUCCESS;


  assert_param(IS_UART_INSTANCE(USARTx));
  assert_param(IS_LL_USART_CLOCKOUTPUT(USART_ClockInitStruct->ClockOutput));



  if (LL_USART_IsEnabled(USARTx) == 0U)
  {


    if (USART_ClockInitStruct->ClockOutput == LL_USART_CLOCK_DISABLE)
    {



      LL_USART_DisableSCLKOutput(USARTx);
    }
    else
    {

      assert_param(IS_USART_INSTANCE(USARTx));


      assert_param(IS_LL_USART_CLOCKPOLARITY(USART_ClockInitStruct->ClockPolarity));
      assert_param(IS_LL_USART_CLOCKPHASE(USART_ClockInitStruct->ClockPhase));
      assert_param(IS_LL_USART_LASTBITCLKOUTPUT(USART_ClockInitStruct->LastBitClockPulse));








      MODIFY_REG(USARTx->CR2,
                 USART_CR2_CLKEN | USART_CR2_CPHA | USART_CR2_CPOL | USART_CR2_LBCL,
                 USART_CR2_CLKEN | USART_ClockInitStruct->ClockPolarity |
                 USART_ClockInitStruct->ClockPhase | USART_ClockInitStruct->LastBitClockPulse);
    }
  }

  else
  {
    status = ERROR;
  }

  return (status);
}







void LL_USART_ClockStructInit(LL_USART_ClockInitTypeDef *USART_ClockInitStruct)
{

  USART_ClockInitStruct->ClockOutput       = LL_USART_CLOCK_DISABLE;
  USART_ClockInitStruct->ClockPolarity     = LL_USART_POLARITY_LOW;
  USART_ClockInitStruct->ClockPhase        = LL_USART_PHASE_1EDGE;
  USART_ClockInitStruct->LastBitClockPulse = LL_USART_LASTCLKPULSE_NO_OUTPUT;
}













#endif





#endif



