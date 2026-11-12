








































#include "stm32f3xx_hal.h"










#ifdef HAL_PWR_MODULE_ENABLED






#define PVD_MODE_IT               (0x00010000U)
#define PVD_MODE_EVT              (0x00020000U)
#define PVD_RISING_EDGE           (0x00000001U)
#define PVD_FALLING_EDGE          (0x00000002U)


































































#if defined(STM32F302xE) || defined(STM32F303xE) || \
    defined(STM32F302xC) || defined(STM32F303xC) || \
    defined(STM32F303x8) || defined(STM32F334x8) || \
    defined(STM32F301x8) || defined(STM32F302x8) || \
    defined(STM32F373xC)










void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD)
{

  assert_param(IS_PWR_PVD_LEVEL(sConfigPVD->PVDLevel));
  assert_param(IS_PWR_PVD_MODE(sConfigPVD->Mode));


  MODIFY_REG(PWR->CR, PWR_CR_PLS, sConfigPVD->PVDLevel);


  __HAL_PWR_PVD_EXTI_DISABLE_EVENT();
  __HAL_PWR_PVD_EXTI_DISABLE_IT();
  __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE();


  if((sConfigPVD->Mode & PVD_MODE_IT) == PVD_MODE_IT)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_IT();
  }


  if((sConfigPVD->Mode & PVD_MODE_EVT) == PVD_MODE_EVT)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_EVENT();
  }


  if((sConfigPVD->Mode & PVD_RISING_EDGE) == PVD_RISING_EDGE)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE();
  }

  if((sConfigPVD->Mode & PVD_FALLING_EDGE) == PVD_FALLING_EDGE)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE();
  }
}





void HAL_PWR_EnablePVD(void)
{
  SET_BIT(PWR->CR, PWR_CR_PVDE);
}





void HAL_PWR_DisablePVD(void)
{
  CLEAR_BIT(PWR->CR, PWR_CR_PVDE);
}






void HAL_PWR_PVD_IRQHandler(void)
{

  if(__HAL_PWR_PVD_EXTI_GET_FLAG() != RESET)
  {

    HAL_PWR_PVDCallback();


    __HAL_PWR_PVD_EXTI_CLEAR_FLAG();
  }
}





__weak void HAL_PWR_PVDCallback(void)
{



}

#endif





#if defined(STM32F373xC) || defined(STM32F378xx)







void HAL_PWREx_EnableSDADC(uint32_t Analogx)
{

  assert_param(IS_PWR_SDADC_ANALOG(Analogx));


  __HAL_RCC_PWR_CLK_ENABLE();

  PWR->CR |= Analogx;
}







void HAL_PWREx_DisableSDADC(uint32_t Analogx)
{

  assert_param(IS_PWR_SDADC_ANALOG(Analogx));

  PWR->CR &= ~Analogx;
}

#endif









#endif









