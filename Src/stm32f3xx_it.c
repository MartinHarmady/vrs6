




















#include "main.h"
#include "stm32f3xx_it.h"














































void NMI_Handler(void)
{






}




void HardFault_Handler(void)
{



  while (1)
  {


  }
}




void MemManage_Handler(void)
{



  while (1)
  {


  }
}




void BusFault_Handler(void)
{



  while (1)
  {


  }
}




void UsageFault_Handler(void)
{



  while (1)
  {


  }
}




void SVC_Handler(void)
{






}




void DebugMon_Handler(void)
{






}




void PendSV_Handler(void)
{






}




void SysTick_Handler(void)
{







}











void DMA1_Channel7_IRQHandler(void)
{
	if(LL_DMA_IsActiveFlag_TC7(DMA1) == SET)
	{
		LL_DMA_ClearFlag_TC7(DMA1);

		while(LL_USART_IsActiveFlag_TC(USART2) == RESET);
		LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_7);
	}
}





