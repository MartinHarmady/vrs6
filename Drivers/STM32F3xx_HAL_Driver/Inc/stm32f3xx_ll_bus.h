




















































#ifndef __STM32F3xx_LL_BUS_H
#define __STM32F3xx_LL_BUS_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f3xx.h"





#if defined(RCC)





















#define LL_AHB1_GRP1_PERIPH_ALL            (uint32_t)0xFFFFFFFFU
#define LL_AHB1_GRP1_PERIPH_DMA1           RCC_AHBENR_DMA1EN
#if defined(DMA2)
#define LL_AHB1_GRP1_PERIPH_DMA2           RCC_AHBENR_DMA2EN
#endif
#define LL_AHB1_GRP1_PERIPH_SRAM           RCC_AHBENR_SRAMEN
#define LL_AHB1_GRP1_PERIPH_FLASH          RCC_AHBENR_FLITFEN
#if defined(FMC_Bank1)
#define LL_AHB1_GRP1_PERIPH_FMC            RCC_AHBENR_FMCEN
#endif
#define LL_AHB1_GRP1_PERIPH_CRC            RCC_AHBENR_CRCEN
#if defined(GPIOH)
#define LL_AHB1_GRP1_PERIPH_GPIOH          RCC_AHBENR_GPIOHEN
#endif
#define LL_AHB1_GRP1_PERIPH_GPIOA          RCC_AHBENR_GPIOAEN
#define LL_AHB1_GRP1_PERIPH_GPIOB          RCC_AHBENR_GPIOBEN
#define LL_AHB1_GRP1_PERIPH_GPIOC          RCC_AHBENR_GPIOCEN
#define LL_AHB1_GRP1_PERIPH_GPIOD          RCC_AHBENR_GPIODEN
#if defined(GPIOE)
#define LL_AHB1_GRP1_PERIPH_GPIOE          RCC_AHBENR_GPIOEEN
#endif
#define LL_AHB1_GRP1_PERIPH_GPIOF          RCC_AHBENR_GPIOFEN
#if defined(GPIOG)
#define LL_AHB1_GRP1_PERIPH_GPIOG          RCC_AHBENR_GPIOGEN
#endif
#define LL_AHB1_GRP1_PERIPH_TSC            RCC_AHBENR_TSCEN
#if defined(RCC_AHBENR_ADC1EN)
#define LL_AHB1_GRP1_PERIPH_ADC1           RCC_AHBENR_ADC1EN
#endif
#if defined(ADC1_2_COMMON)
#define LL_AHB1_GRP1_PERIPH_ADC12          RCC_AHBENR_ADC12EN
#endif
#if defined(ADC3_4_COMMON)
#define LL_AHB1_GRP1_PERIPH_ADC34          RCC_AHBENR_ADC34EN
#endif







#define LL_APB1_GRP1_PERIPH_ALL            (uint32_t)0xFFFFFFFFU
#define LL_APB1_GRP1_PERIPH_TIM2           RCC_APB1ENR_TIM2EN
#if defined(TIM3)
#define LL_APB1_GRP1_PERIPH_TIM3           RCC_APB1ENR_TIM3EN
#endif
#if defined(TIM4)
#define LL_APB1_GRP1_PERIPH_TIM4           RCC_APB1ENR_TIM4EN
#endif
#if defined(TIM5)
#define LL_APB1_GRP1_PERIPH_TIM5           RCC_APB1ENR_TIM5EN
#endif
#define LL_APB1_GRP1_PERIPH_TIM6           RCC_APB1ENR_TIM6EN
#if defined(TIM7)
#define LL_APB1_GRP1_PERIPH_TIM7           RCC_APB1ENR_TIM7EN
#endif
#if defined(TIM12)
#define LL_APB1_GRP1_PERIPH_TIM12          RCC_APB1ENR_TIM12EN
#endif
#if defined(TIM13)
#define LL_APB1_GRP1_PERIPH_TIM13          RCC_APB1ENR_TIM13EN
#endif
#if defined(TIM14)
#define LL_APB1_GRP1_PERIPH_TIM14          RCC_APB1ENR_TIM14EN
#endif
#if defined(TIM18)
#define LL_APB1_GRP1_PERIPH_TIM18          RCC_APB1ENR_TIM18EN
#endif
#define LL_APB1_GRP1_PERIPH_WWDG           RCC_APB1ENR_WWDGEN
#if defined(SPI2)
#define LL_APB1_GRP1_PERIPH_SPI2           RCC_APB1ENR_SPI2EN
#endif
#if defined(SPI3)
#define LL_APB1_GRP1_PERIPH_SPI3           RCC_APB1ENR_SPI3EN
#endif
#define LL_APB1_GRP1_PERIPH_USART2         RCC_APB1ENR_USART2EN
#define LL_APB1_GRP1_PERIPH_USART3         RCC_APB1ENR_USART3EN
#if defined(UART4)
#define LL_APB1_GRP1_PERIPH_UART4          RCC_APB1ENR_UART4EN
#endif
#if defined(UART5)
#define LL_APB1_GRP1_PERIPH_UART5          RCC_APB1ENR_UART5EN
#endif
#define LL_APB1_GRP1_PERIPH_I2C1           RCC_APB1ENR_I2C1EN
#if defined(I2C2)
#define LL_APB1_GRP1_PERIPH_I2C2           RCC_APB1ENR_I2C2EN
#endif
#if defined(USB)
#define LL_APB1_GRP1_PERIPH_USB            RCC_APB1ENR_USBEN
#endif
#if defined(CAN)
#define LL_APB1_GRP1_PERIPH_CAN            RCC_APB1ENR_CANEN
#endif
#if defined(DAC2)
#define LL_APB1_GRP1_PERIPH_DAC2           RCC_APB1ENR_DAC2EN
#endif
#define LL_APB1_GRP1_PERIPH_PWR            RCC_APB1ENR_PWREN
#define LL_APB1_GRP1_PERIPH_DAC1           RCC_APB1ENR_DAC1EN
#if defined(CEC)
#define LL_APB1_GRP1_PERIPH_CEC            RCC_APB1ENR_CECEN
#endif
#if defined(I2C3)
#define LL_APB1_GRP1_PERIPH_I2C3           RCC_APB1ENR_I2C3EN
#endif







#define LL_APB2_GRP1_PERIPH_ALL            (uint32_t)0xFFFFFFFFU
#define LL_APB2_GRP1_PERIPH_SYSCFG         RCC_APB2ENR_SYSCFGEN
#if defined(RCC_APB2ENR_ADC1EN)
#define LL_APB2_GRP1_PERIPH_ADC1           RCC_APB2ENR_ADC1EN
#endif
#if defined(TIM1)
#define LL_APB2_GRP1_PERIPH_TIM1           RCC_APB2ENR_TIM1EN
#endif
#if defined(SPI1)
#define LL_APB2_GRP1_PERIPH_SPI1           RCC_APB2ENR_SPI1EN
#endif
#if defined(TIM8)
#define LL_APB2_GRP1_PERIPH_TIM8           RCC_APB2ENR_TIM8EN
#endif
#define LL_APB2_GRP1_PERIPH_USART1         RCC_APB2ENR_USART1EN
#if defined(SPI4)
#define LL_APB2_GRP1_PERIPH_SPI4           RCC_APB2ENR_SPI4EN
#endif
#define LL_APB2_GRP1_PERIPH_TIM15          RCC_APB2ENR_TIM15EN
#define LL_APB2_GRP1_PERIPH_TIM16          RCC_APB2ENR_TIM16EN
#define LL_APB2_GRP1_PERIPH_TIM17          RCC_APB2ENR_TIM17EN
#if defined(TIM19)
#define LL_APB2_GRP1_PERIPH_TIM19          RCC_APB2ENR_TIM19EN
#endif
#if defined(TIM20)
#define LL_APB2_GRP1_PERIPH_TIM20          RCC_APB2ENR_TIM20EN
#endif
#if defined(HRTIM1)
#define LL_APB2_GRP1_PERIPH_HRTIM1         RCC_APB2ENR_HRTIM1EN
#endif
#if defined(SDADC1)
#define LL_APB2_GRP1_PERIPH_SDADC1         RCC_APB2ENR_SDADC1EN
#endif
#if defined(SDADC2)
#define LL_APB2_GRP1_PERIPH_SDADC2         RCC_APB2ENR_SDADC2EN
#endif
#if defined(SDADC3)
#define LL_APB2_GRP1_PERIPH_SDADC3         RCC_APB2ENR_SDADC3EN
#endif






























































__STATIC_INLINE void LL_AHB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->AHBENR, Periphs);

  tmpreg = READ_BIT(RCC->AHBENR, Periphs);
  (void)tmpreg;
}












































__STATIC_INLINE uint32_t LL_AHB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCC->AHBENR, Periphs) == Periphs);
}












































__STATIC_INLINE void LL_AHB1_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHBENR, Periphs);
}



































__STATIC_INLINE void LL_AHB1_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->AHBRSTR, Periphs);
}



































__STATIC_INLINE void LL_AHB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHBRSTR, Periphs);
}




































































__STATIC_INLINE void LL_APB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB1ENR, Periphs);

  tmpreg = READ_BIT(RCC->APB1ENR, Periphs);
  (void)tmpreg;
}




























































__STATIC_INLINE uint32_t LL_APB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCC->APB1ENR, Periphs) == Periphs);
}




























































__STATIC_INLINE void LL_APB1_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1ENR, Periphs);
}





























































__STATIC_INLINE void LL_APB1_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->APB1RSTR, Periphs);
}





























































__STATIC_INLINE void LL_APB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1RSTR, Periphs);
}
















































__STATIC_INLINE void LL_APB2_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB2ENR, Periphs);

  tmpreg = READ_BIT(RCC->APB2ENR, Periphs);
  (void)tmpreg;
}








































__STATIC_INLINE uint32_t LL_APB2_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCC->APB2ENR, Periphs) == Periphs);
}








































__STATIC_INLINE void LL_APB2_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB2ENR, Periphs);
}









































__STATIC_INLINE void LL_APB2_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->APB2RSTR, Periphs);
}









































__STATIC_INLINE void LL_APB2_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB2RSTR, Periphs);
}














#endif





#ifdef __cplusplus
}
#endif

#endif


