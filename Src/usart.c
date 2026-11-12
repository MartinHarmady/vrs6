



















#include "usart.h"






void MX_USART2_Init(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};


  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);





  GPIO_InitStruct.Pin = LL_GPIO_PIN_2|LL_GPIO_PIN_3;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  LL_USART_Disable(USART2);

  LL_USART_SetDataWidth(USART2, LL_USART_DATAWIDTH_8B);
  LL_USART_SetParity(USART2, LL_USART_PARITY_NONE);
  LL_USART_SetStopBitsLength(USART2, LL_USART_STOPBITS_1);
  LL_USART_SetHWFlowCtrl(USART2, LL_USART_HWCONTROL_NONE);
  LL_USART_SetOverSampling(USART2, LL_USART_OVERSAMPLING_16);
  LL_USART_SetBaudRate(USART2, SystemCoreClock, LL_USART_OVERSAMPLING_16, 115200U);
  LL_USART_ConfigAsyncMode(USART2);

  LL_USART_EnableDirectionTx(USART2);
  LL_USART_EnableDirectionRx(USART2);

  LL_USART_Enable(USART2);
}







void usart_send_string(const char *string)
{
	while (*string != '\0')
	{
		while (!LL_USART_IsActiveFlag_TXE(USART2))
		{
		}
		LL_USART_TransmitData8(USART2, (uint8_t)*string++);
	}
	while (!LL_USART_IsActiveFlag_TC(USART2))
	{
	}
}








void usart_format_fixed(char *buffer, int32_t value, uint8_t decimals)
{
	uint32_t scale = 1U;
	uint32_t whole;
	uint32_t part;
	char digits[10];
	uint8_t len = 0U;
	char *p = buffer;

	for (uint8_t i = 0U; i < decimals; i++)
	{
		scale *= 10U;
	}

	if (value < 0)
	{
		*p++ = '-';
		value = -value;
	}
	part = (uint32_t)value;


	whole = part / scale;
	do
	{
		digits[len++] = (char)('0' + (whole % 10U));
		whole /= 10U;
	} while (whole != 0U);
	while (len > 0U)
	{
		*p++ = digits[--len];
	}


	for (uint8_t i = 0U; i < decimals; i++)
	{
		scale /= 10U;
		*p++ = (char)('0' + ((part / scale) % 10U));
	}
	*p = '\0';
}




