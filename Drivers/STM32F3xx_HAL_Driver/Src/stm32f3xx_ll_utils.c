


































#include "stm32f3xx_ll_rcc.h"
#include "stm32f3xx_ll_utils.h"
#include "stm32f3xx_ll_system.h"
#include "stm32f3xx_ll_pwr.h"
#ifdef  USE_FULL_ASSERT
#include "stm32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif

















#define UTILS_PLL_OUTPUT_MAX        72000000U


#define UTILS_HSE_FREQUENCY_MIN      4000000U
#define UTILS_HSE_FREQUENCY_MAX     32000000U


#define UTILS_LATENCY1_FREQ         24000000U
#define UTILS_LATENCY2_FREQ         48000000U







#define IS_LL_UTILS_SYSCLK_DIV(__VALUE__) (((__VALUE__) == LL_RCC_SYSCLK_DIV_1)   \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_2)   \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_4)   \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_8)   \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_16)  \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_64)  \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_128) \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_256) \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_512))

#define IS_LL_UTILS_APB1_DIV(__VALUE__) (((__VALUE__) == LL_RCC_APB1_DIV_1) \
                                      || ((__VALUE__) == LL_RCC_APB1_DIV_2) \
                                      || ((__VALUE__) == LL_RCC_APB1_DIV_4) \
                                      || ((__VALUE__) == LL_RCC_APB1_DIV_8) \
                                      || ((__VALUE__) == LL_RCC_APB1_DIV_16))

#define IS_LL_UTILS_APB2_DIV(__VALUE__) (((__VALUE__) == LL_RCC_APB2_DIV_1) \
                                      || ((__VALUE__) == LL_RCC_APB2_DIV_2) \
                                      || ((__VALUE__) == LL_RCC_APB2_DIV_4) \
                                      || ((__VALUE__) == LL_RCC_APB2_DIV_8) \
                                      || ((__VALUE__) == LL_RCC_APB2_DIV_16))

#define IS_LL_UTILS_PLLMUL_VALUE(__VALUE__) (((__VALUE__) == LL_RCC_PLL_MUL_2) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_3) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_4) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_5) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_6) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_7) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_8) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_9) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_10) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_11) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_12) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_13) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_14) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_15) \
                                          || ((__VALUE__) == LL_RCC_PLL_MUL_16))

#define IS_LL_UTILS_PREDIV_VALUE(__VALUE__) (((__VALUE__) == LL_RCC_PREDIV_DIV_1)  || ((__VALUE__) == LL_RCC_PREDIV_DIV_2)   || \
                                             ((__VALUE__) == LL_RCC_PREDIV_DIV_3)  || ((__VALUE__) == LL_RCC_PREDIV_DIV_4)   || \
                                             ((__VALUE__) == LL_RCC_PREDIV_DIV_5)  || ((__VALUE__) == LL_RCC_PREDIV_DIV_6)   || \
                                             ((__VALUE__) == LL_RCC_PREDIV_DIV_7)  || ((__VALUE__) == LL_RCC_PREDIV_DIV_8)   || \
                                             ((__VALUE__) == LL_RCC_PREDIV_DIV_9)  || ((__VALUE__) == LL_RCC_PREDIV_DIV_10)  || \
                                             ((__VALUE__) == LL_RCC_PREDIV_DIV_11) || ((__VALUE__) == LL_RCC_PREDIV_DIV_12)  || \
                                             ((__VALUE__) == LL_RCC_PREDIV_DIV_13) || ((__VALUE__) == LL_RCC_PREDIV_DIV_14)  || \
                                             ((__VALUE__) == LL_RCC_PREDIV_DIV_15) || ((__VALUE__) == LL_RCC_PREDIV_DIV_16))

#define IS_LL_UTILS_PLL_FREQUENCY(__VALUE__) ((__VALUE__) <= UTILS_PLL_OUTPUT_MAX)


#define IS_LL_UTILS_HSE_BYPASS(__STATE__) (((__STATE__) == LL_UTILS_HSEBYPASS_ON) \
                                        || ((__STATE__) == LL_UTILS_HSEBYPASS_OFF))

#define IS_LL_UTILS_HSE_FREQUENCY(__FREQUENCY__) (((__FREQUENCY__) >= UTILS_HSE_FREQUENCY_MIN) && ((__FREQUENCY__) <= UTILS_HSE_FREQUENCY_MAX))







static uint32_t    UTILS_GetPLLOutputFrequency(uint32_t PLL_InputFrequency,
                                               LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct);
#if defined(FLASH_ACR_LATENCY)
static ErrorStatus UTILS_SetFlashLatency(uint32_t Frequency);
#endif
static ErrorStatus UTILS_EnablePLLAndSwitchSystem(uint32_t SYSCLK_Frequency, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);
static ErrorStatus UTILS_PLL_IsBusy(void);





















void LL_Init1msTick(uint32_t HCLKFrequency)
{

  LL_InitTick(HCLKFrequency, 1000U);
}











void LL_mDelay(uint32_t Delay)
{
  __IO uint32_t  tmp = SysTick->CTRL;

  ((void)tmp);


  if (Delay < LL_MAX_DELAY)
  {
    Delay++;
  }

  while (Delay)
  {
    if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U)
    {
      Delay--;
    }
  }
}






































void LL_SetSystemCoreClock(uint32_t HCLKFrequency)
{

  SystemCoreClock = HCLKFrequency;
}


















ErrorStatus LL_PLL_ConfigSystemClock_HSI(LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct,
                                         LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct)
{
  ErrorStatus status = SUCCESS;
  uint32_t pllfreq = 0U;


  if (UTILS_PLL_IsBusy() == SUCCESS)
  {
#if defined(RCC_PLLSRC_PREDIV1_SUPPORT)

    assert_param(IS_LL_UTILS_PREDIV_VALUE(UTILS_PLLInitStruct->PLLDiv));
#else

    UTILS_PLLInitStruct->Prediv = LL_RCC_PREDIV_DIV_2;
#endif

    pllfreq = UTILS_GetPLLOutputFrequency(HSI_VALUE, UTILS_PLLInitStruct);


    if (LL_RCC_HSI_IsReady() != 1U)
    {
      LL_RCC_HSI_Enable();
      while (LL_RCC_HSI_IsReady() != 1U)
      {

      }
    }


#if defined(RCC_PLLSRC_PREDIV1_SUPPORT)
    LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI, UTILS_PLLInitStruct->PLLMul, UTILS_PLLInitStruct->PLLDiv);
#else
    LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI_DIV_2, UTILS_PLLInitStruct->PLLMul);
#endif


    status = UTILS_EnablePLLAndSwitchSystem(pllfreq, UTILS_ClkInitStruct);
  }
  else
  {

    status = ERROR;
  }

  return status;
}






















ErrorStatus LL_PLL_ConfigSystemClock_HSE(uint32_t HSEFrequency, uint32_t HSEBypass,
                                         LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct)
{
  ErrorStatus status = SUCCESS;
  uint32_t pllfreq = 0U;


  assert_param(IS_LL_UTILS_HSE_FREQUENCY(HSEFrequency));
  assert_param(IS_LL_UTILS_HSE_BYPASS(HSEBypass));


  if (UTILS_PLL_IsBusy() == SUCCESS)
  {

#if defined(RCC_PLLSRC_PREDIV1_SUPPORT)
    assert_param(IS_LL_UTILS_PREDIV_VALUE(UTILS_PLLInitStruct->PLLDiv));
#else
    assert_param(IS_LL_UTILS_PREDIV_VALUE(UTILS_PLLInitStruct->Prediv));
#endif


    pllfreq = UTILS_GetPLLOutputFrequency(HSEFrequency, UTILS_PLLInitStruct);


    if (LL_RCC_HSE_IsReady() != 1U)
    {

      if (HSEBypass == LL_UTILS_HSEBYPASS_ON)
      {
        LL_RCC_HSE_EnableBypass();
      }
      else
      {
        LL_RCC_HSE_DisableBypass();
      }


      LL_RCC_HSE_Enable();
      while (LL_RCC_HSE_IsReady() != 1U)
      {

      }
    }


#if defined(RCC_PLLSRC_PREDIV1_SUPPORT)
      LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, UTILS_PLLInitStruct->PLLMul, UTILS_PLLInitStruct->PLLDiv);
#else
    LL_RCC_PLL_ConfigDomain_SYS((RCC_CFGR_PLLSRC_HSE_PREDIV | UTILS_PLLInitStruct->Prediv), UTILS_PLLInitStruct->PLLMul);
#endif


    status = UTILS_EnablePLLAndSwitchSystem(pllfreq, UTILS_ClkInitStruct);
  }
  else
  {

    status = ERROR;
  }

  return status;
}




















#if defined(FLASH_ACR_LATENCY)
static ErrorStatus UTILS_SetFlashLatency(uint32_t Frequency)
{
  ErrorStatus status = SUCCESS;

  uint32_t latency = LL_FLASH_LATENCY_0;


  if (Frequency == 0U)
  {
    status = ERROR;
  }
  else
  {
    if (Frequency > UTILS_LATENCY2_FREQ)
    {

      latency = LL_FLASH_LATENCY_2;
    }
    else
    {
      if (Frequency > UTILS_LATENCY1_FREQ)
      {

        latency = LL_FLASH_LATENCY_1;
      }

    }

    LL_FLASH_SetLatency(latency);



    if (LL_FLASH_GetLatency() != latency)
    {
      status = ERROR;
    }
  }
  return status;
}
#endif








static uint32_t UTILS_GetPLLOutputFrequency(uint32_t PLL_InputFrequency, LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct)
{
  uint32_t pllfreq = 0U;


  assert_param(IS_LL_UTILS_PLLMUL_VALUE(UTILS_PLLInitStruct->PLLMul));




#if defined(RCC_PLLSRC_PREDIV1_SUPPORT)
  pllfreq = __LL_RCC_CALC_PLLCLK_FREQ(PLL_InputFrequency, UTILS_PLLInitStruct->PLLMul, UTILS_PLLInitStruct->PLLDiv);
#else
  pllfreq = __LL_RCC_CALC_PLLCLK_FREQ(PLL_InputFrequency / (UTILS_PLLInitStruct->Prediv + 1U), UTILS_PLLInitStruct->PLLMul);
#endif
  assert_param(IS_LL_UTILS_PLL_FREQUENCY(pllfreq));

  return pllfreq;
}







static ErrorStatus UTILS_PLL_IsBusy(void)
{
  ErrorStatus status = SUCCESS;


  if (LL_RCC_PLL_IsReady() != 0U)
  {

    status = ERROR;
  }

  return status;
}










static ErrorStatus UTILS_EnablePLLAndSwitchSystem(uint32_t SYSCLK_Frequency, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct)
{
  ErrorStatus status = SUCCESS;
  uint32_t sysclk_frequency_current = 0U;

  assert_param(IS_LL_UTILS_SYSCLK_DIV(UTILS_ClkInitStruct->AHBCLKDivider));
  assert_param(IS_LL_UTILS_APB1_DIV(UTILS_ClkInitStruct->APB1CLKDivider));
  assert_param(IS_LL_UTILS_APB2_DIV(UTILS_ClkInitStruct->APB2CLKDivider));


  sysclk_frequency_current = (SystemCoreClock << AHBPrescTable[LL_RCC_GetAHBPrescaler() >> RCC_POSITION_HPRE]);


  if (sysclk_frequency_current < SYSCLK_Frequency)
  {

    status = UTILS_SetFlashLatency(SYSCLK_Frequency);
  }


  if (status == SUCCESS)
  {

    LL_RCC_PLL_Enable();
    while (LL_RCC_PLL_IsReady() != 1U)
    {

    }


    LL_RCC_SetAHBPrescaler(UTILS_ClkInitStruct->AHBCLKDivider);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
    {

    }


    LL_RCC_SetAPB1Prescaler(UTILS_ClkInitStruct->APB1CLKDivider);
    LL_RCC_SetAPB2Prescaler(UTILS_ClkInitStruct->APB2CLKDivider);
  }


  if (sysclk_frequency_current > SYSCLK_Frequency)
  {

    status = UTILS_SetFlashLatency(SYSCLK_Frequency);
  }


  if (status == SUCCESS)
  {
    LL_SetSystemCoreClock(__LL_RCC_CALC_HCLK_FREQ(SYSCLK_Frequency, UTILS_ClkInitStruct->AHBCLKDivider));
  }

  return status;
}














