


















































#include "stm32f3xx_hal.h"










#ifdef HAL_MODULE_ENABLED









#define __STM32F3xx_HAL_VERSION_MAIN   (0x01U)
#define __STM32F3xx_HAL_VERSION_SUB1   (0x05U)
#define __STM32F3xx_HAL_VERSION_SUB2   (0x02U)
#define __STM32F3xx_HAL_VERSION_RC     (0x00U)
#define __STM32F3xx_HAL_VERSION         ((__STM32F3xx_HAL_VERSION_MAIN << 24U)\
                                        |(__STM32F3xx_HAL_VERSION_SUB1 << 16U)\
                                        |(__STM32F3xx_HAL_VERSION_SUB2 << 8U )\
                                        |(__STM32F3xx_HAL_VERSION_RC))

#define IDCODE_DEVID_MASK    (0x00000FFFU)









__IO uint32_t uwTick;
uint32_t uwTickPrio   = (1UL << __NVIC_PRIO_BITS);
HAL_TickFreqTypeDef uwTickFreq = HAL_TICK_FREQ_DEFAULT;



























































HAL_StatusTypeDef HAL_Init(void)
{

#if (PREFETCH_ENABLE != 0U)
  __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
#endif


  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);


  HAL_InitTick(TICK_INT_PRIORITY);


  HAL_MspInit();


  return HAL_OK;
}






HAL_StatusTypeDef HAL_DeInit(void)
{

  __HAL_RCC_APB1_FORCE_RESET();
  __HAL_RCC_APB1_RELEASE_RESET();

  __HAL_RCC_APB2_FORCE_RESET();
  __HAL_RCC_APB2_RELEASE_RESET();

  __HAL_RCC_AHB_FORCE_RESET();
  __HAL_RCC_AHB_RELEASE_RESET();


  HAL_MspDeInit();


  return HAL_OK;
}





__weak void HAL_MspInit(void)
{



}





__weak void HAL_MspDeInit(void)
{



}

















__weak HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{

  if (HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq)) > 0U)
  {
    return HAL_ERROR;
  }


  if (TickPriority < (1UL << __NVIC_PRIO_BITS))
  {
    HAL_NVIC_SetPriority(SysTick_IRQn, TickPriority, 0U);
    uwTickPrio = TickPriority;
  }
  else
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}





































__weak void HAL_IncTick(void)
{
  uwTick += uwTickFreq;
}







__weak uint32_t HAL_GetTick(void)
{
  return uwTick;
}





uint32_t HAL_GetTickPrio(void)
{
  return uwTickPrio;
}





HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq)
{
  HAL_StatusTypeDef status  = HAL_OK;
  assert_param(IS_TICKFREQ(Freq));

  if (uwTickFreq != Freq)
  {
    uwTickFreq = Freq;


    status = HAL_InitTick(uwTickPrio);
  }

  return status;
}





HAL_TickFreqTypeDef HAL_GetTickFreq(void)
{
  return uwTickFreq;
}












__weak void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;


  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }

  while((HAL_GetTick() - tickstart) < wait)
  {
  }
}











__weak void HAL_SuspendTick(void)

{

  SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;

}











__weak void HAL_ResumeTick(void)
{

  SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;

}





uint32_t HAL_GetHalVersion(void)
{
 return __STM32F3xx_HAL_VERSION;
}





uint32_t HAL_GetREVID(void)
{
  return((DBGMCU->IDCODE) >> 16U);
}





uint32_t HAL_GetDEVID(void)
{
  return((DBGMCU->IDCODE) & IDCODE_DEVID_MASK);
}





uint32_t HAL_GetUIDw0(void)
{
   return(READ_REG(*((uint32_t *)UID_BASE)));
}





uint32_t HAL_GetUIDw1(void)
{
   return(READ_REG(*((uint32_t *)(UID_BASE + 4U))));
}





uint32_t HAL_GetUIDw2(void)
{
   return(READ_REG(*((uint32_t *)(UID_BASE + 8U))));
}





void HAL_DBGMCU_EnableDBGSleepMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
}





void HAL_DBGMCU_DisableDBGSleepMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
}





void HAL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}





void HAL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}





void HAL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
}





void HAL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
}









#endif









