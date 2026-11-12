









































#include "stm32f3xx_hal.h"










#ifdef HAL_PWR_MODULE_ENABLED




































void HAL_PWR_DeInit(void)
{
  __HAL_RCC_PWR_FORCE_RESET();
  __HAL_RCC_PWR_RELEASE_RESET();
}








void HAL_PWR_EnableBkUpAccess(void)
{
  SET_BIT(PWR->CR, PWR_CR_DBP);
}








void HAL_PWR_DisableBkUpAccess(void)
{
  CLEAR_BIT(PWR->CR, PWR_CR_DBP);
}











































































































































void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinx)
{

  assert_param(IS_PWR_WAKEUP_PIN(WakeUpPinx));

  SET_BIT(PWR->CSR, WakeUpPinx);
}








void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx)
{

  assert_param(IS_PWR_WAKEUP_PIN(WakeUpPinx));

  CLEAR_BIT(PWR->CSR, WakeUpPinx);
}


















void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry)
{

  assert_param(IS_PWR_SLEEP_ENTRY(SLEEPEntry));


  SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP_Msk);


  if(SLEEPEntry == PWR_SLEEPENTRY_WFI)
  {

    __WFI();
  }
  else
  {

    __SEV();
    __WFE();
    __WFE();
  }
}




















void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry)
{
  uint32_t tmpreg = 0U;


  assert_param(IS_PWR_REGULATOR(Regulator));
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));


  tmpreg = PWR->CR;


  tmpreg &= (uint32_t)~(PWR_CR_PDDS | PWR_CR_LPDS);


  tmpreg |= Regulator;


  PWR->CR = tmpreg;


  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;


  if(STOPEntry == PWR_STOPENTRY_WFI)
  {

    __WFI();
  }
  else
  {

    __SEV();
    __WFE();
    __WFE();
  }


  SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP_Msk);
}










void HAL_PWR_EnterSTANDBYMode(void)
{

  PWR->CR |= PWR_CR_PDDS;


  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;


#if defined ( __CC_ARM)
  __force_stores();
#endif

  __WFI();
}









void HAL_PWR_EnableSleepOnExit(void)
{

  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPONEXIT_Msk));
}








void HAL_PWR_DisableSleepOnExit(void)
{

  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPONEXIT_Msk));
}









void HAL_PWR_EnableSEVOnPend(void)
{

  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SEVONPEND_Msk));
}








void HAL_PWR_DisableSEVOnPend(void)
{

  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SEVONPEND_Msk));
}








#endif









