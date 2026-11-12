




















































































#include "stm32f3xx.h"
















#if !defined  (HSE_VALUE)
  #define HSE_VALUE    ((uint32_t)8000000)

#endif

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    ((uint32_t)8000000)

#endif




#define VECT_TAB_OFFSET  0x0
























uint32_t SystemCoreClock = 8000000;

const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8]  = {0, 0, 0, 0, 1, 2, 3, 4};























void SystemInit(void)
{

  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));
  #endif



  RCC->CR |= 0x00000001U;


  RCC->CFGR &= 0xF87FC00CU;


  RCC->CR &= 0xFEF6FFFFU;


  RCC->CR &= 0xFFFBFFFFU;


  RCC->CFGR &= 0xFF80FFFFU;


  RCC->CFGR2 &= 0xFFFFFFF0U;


  RCC->CFGR3 &= 0xFF00FCCCU;


  RCC->CIR = 0x00000000U;

#ifdef VECT_TAB_SRAM
  SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET;
#else
  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET;
#endif
}





































void SystemCoreClockUpdate (void)
{
  uint32_t tmp = 0, pllmull = 0, pllsource = 0, predivfactor = 0;


  tmp = RCC->CFGR & RCC_CFGR_SWS;

  switch (tmp)
  {
    case RCC_CFGR_SWS_HSI:
      SystemCoreClock = HSI_VALUE;
      break;
    case RCC_CFGR_SWS_HSE:
      SystemCoreClock = HSE_VALUE;
      break;
    case RCC_CFGR_SWS_PLL:

      pllmull = RCC->CFGR & RCC_CFGR_PLLMUL;
      pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;
      pllmull = ( pllmull >> 18) + 2;

#if defined (STM32F302xE) || defined (STM32F303xE) || defined (STM32F398xx)
        predivfactor = (RCC->CFGR2 & RCC_CFGR2_PREDIV) + 1;
      if (pllsource == RCC_CFGR_PLLSRC_HSE_PREDIV)
      {

        SystemCoreClock = (HSE_VALUE / predivfactor) * pllmull;
      }
      else
      {

        SystemCoreClock = (HSI_VALUE / predivfactor) * pllmull;
      }
#else
      if (pllsource == RCC_CFGR_PLLSRC_HSI_DIV2)
      {

        SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
      }
      else
      {
        predivfactor = (RCC->CFGR2 & RCC_CFGR2_PREDIV) + 1;

        SystemCoreClock = (HSE_VALUE / predivfactor) * pllmull;
      }
#endif
      break;
    default:
      SystemCoreClock = HSI_VALUE;
      break;
  }


  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];

  SystemCoreClock >>= tmp;
}















