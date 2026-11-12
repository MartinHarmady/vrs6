

































#if defined(USE_FULL_LL_DRIVER)


#include "stm32f3xx_ll_exti.h"
#ifdef  USE_FULL_ASSERT
#include "stm32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif





#if defined (EXTI)













#define IS_LL_EXTI_LINE_0_31(__VALUE__)              (((__VALUE__) & ~LL_EXTI_LINE_ALL_0_31) == 0x00000000U)
#if defined(EXTI_32_63_SUPPORT)
#define IS_LL_EXTI_LINE_32_63(__VALUE__)             (((__VALUE__) & ~LL_EXTI_LINE_ALL_32_63) == 0x00000000U)
#endif

#define IS_LL_EXTI_MODE(__VALUE__)                   (((__VALUE__) == LL_EXTI_MODE_IT)            \
                                                   || ((__VALUE__) == LL_EXTI_MODE_EVENT)         \
                                                   || ((__VALUE__) == LL_EXTI_MODE_IT_EVENT))


#define IS_LL_EXTI_TRIGGER(__VALUE__)                (((__VALUE__) == LL_EXTI_TRIGGER_NONE)       \
                                                   || ((__VALUE__) == LL_EXTI_TRIGGER_RISING)     \
                                                   || ((__VALUE__) == LL_EXTI_TRIGGER_FALLING)    \
                                                   || ((__VALUE__) == LL_EXTI_TRIGGER_RISING_FALLING))






















uint32_t LL_EXTI_DeInit(void)
{

  LL_EXTI_WriteReg(IMR,   0x1F800000U);

  LL_EXTI_WriteReg(EMR,   0x00000000U);

  LL_EXTI_WriteReg(RTSR,  0x00000000U);

  LL_EXTI_WriteReg(FTSR,  0x00000000U);

  LL_EXTI_WriteReg(SWIER, 0x00000000U);

  LL_EXTI_WriteReg(PR,    0x007FFFFFU);

#if defined(EXTI_32_63_SUPPORT)

#if defined(STM32F334x8)
  LL_EXTI_WriteReg(IMR2,        0xFFFFFFFEU);
#else
  LL_EXTI_WriteReg(IMR2,        0xFFFFFFFCU);
#endif

  LL_EXTI_WriteReg(EMR2,        0x00000000U);

  LL_EXTI_WriteReg(RTSR2,       0x00000000U);

  LL_EXTI_WriteReg(FTSR2,       0x00000000U);

  LL_EXTI_WriteReg(SWIER2,      0x00000000U);

  LL_EXTI_WriteReg(PR2,         0x00000003U);

#endif
  return SUCCESS;
}








uint32_t LL_EXTI_Init(LL_EXTI_InitTypeDef *EXTI_InitStruct)
{
  ErrorStatus status = SUCCESS;

  assert_param(IS_LL_EXTI_LINE_0_31(EXTI_InitStruct->Line_0_31));
#if defined(EXTI_32_63_SUPPORT)
  assert_param(IS_LL_EXTI_LINE_32_63(EXTI_InitStruct->Line_32_63));
#endif
  assert_param(IS_FUNCTIONAL_STATE(EXTI_InitStruct->LineCommand));
  assert_param(IS_LL_EXTI_MODE(EXTI_InitStruct->Mode));


  if (EXTI_InitStruct->LineCommand != DISABLE)
  {
    assert_param(IS_LL_EXTI_TRIGGER(EXTI_InitStruct->Trigger));


    if (EXTI_InitStruct->Line_0_31 != LL_EXTI_LINE_NONE)
    {
      switch (EXTI_InitStruct->Mode)
      {
        case LL_EXTI_MODE_IT:

          LL_EXTI_DisableEvent_0_31(EXTI_InitStruct->Line_0_31);

          LL_EXTI_EnableIT_0_31(EXTI_InitStruct->Line_0_31);
          break;
        case LL_EXTI_MODE_EVENT:

          LL_EXTI_DisableIT_0_31(EXTI_InitStruct->Line_0_31);

          LL_EXTI_EnableEvent_0_31(EXTI_InitStruct->Line_0_31);
          break;
        case LL_EXTI_MODE_IT_EVENT:

          LL_EXTI_EnableIT_0_31(EXTI_InitStruct->Line_0_31);
          LL_EXTI_EnableEvent_0_31(EXTI_InitStruct->Line_0_31);
          break;
        default:
          status = ERROR;
          break;
      }
      if (EXTI_InitStruct->Trigger != LL_EXTI_TRIGGER_NONE)
      {
        switch (EXTI_InitStruct->Trigger)
        {
          case LL_EXTI_TRIGGER_RISING:

            LL_EXTI_DisableFallingTrig_0_31(EXTI_InitStruct->Line_0_31);

            LL_EXTI_EnableRisingTrig_0_31(EXTI_InitStruct->Line_0_31);
            break;
          case LL_EXTI_TRIGGER_FALLING:

            LL_EXTI_DisableRisingTrig_0_31(EXTI_InitStruct->Line_0_31);

            LL_EXTI_EnableFallingTrig_0_31(EXTI_InitStruct->Line_0_31);
            break;
          case LL_EXTI_TRIGGER_RISING_FALLING:
            LL_EXTI_EnableRisingTrig_0_31(EXTI_InitStruct->Line_0_31);
            LL_EXTI_EnableFallingTrig_0_31(EXTI_InitStruct->Line_0_31);
            break;
          default:
            status = ERROR;
            break;
        }
      }
    }
#if defined(EXTI_32_63_SUPPORT)

    if (EXTI_InitStruct->Line_32_63 != LL_EXTI_LINE_NONE)
    {
      switch (EXTI_InitStruct->Mode)
      {
        case LL_EXTI_MODE_IT:

          LL_EXTI_DisableEvent_32_63(EXTI_InitStruct->Line_32_63);

          LL_EXTI_EnableIT_32_63(EXTI_InitStruct->Line_32_63);
          break;
        case LL_EXTI_MODE_EVENT:

          LL_EXTI_DisableIT_32_63(EXTI_InitStruct->Line_32_63);

          LL_EXTI_EnableEvent_32_63(EXTI_InitStruct->Line_32_63);
          break;
        case LL_EXTI_MODE_IT_EVENT:

          LL_EXTI_EnableIT_32_63(EXTI_InitStruct->Line_32_63);
          LL_EXTI_EnableEvent_32_63(EXTI_InitStruct->Line_32_63);
          break;
        default:
          status = ERROR;
          break;
      }
      if (EXTI_InitStruct->Trigger != LL_EXTI_TRIGGER_NONE)
      {
        switch (EXTI_InitStruct->Trigger)
        {
          case LL_EXTI_TRIGGER_RISING:

            LL_EXTI_DisableFallingTrig_32_63(EXTI_InitStruct->Line_32_63);

            LL_EXTI_EnableRisingTrig_32_63(EXTI_InitStruct->Line_32_63);
            break;
          case LL_EXTI_TRIGGER_FALLING:

            LL_EXTI_DisableRisingTrig_32_63(EXTI_InitStruct->Line_32_63);

            LL_EXTI_EnableFallingTrig_32_63(EXTI_InitStruct->Line_32_63);
            break;
          case LL_EXTI_TRIGGER_RISING_FALLING:
            LL_EXTI_EnableRisingTrig_32_63(EXTI_InitStruct->Line_32_63);
            LL_EXTI_EnableFallingTrig_32_63(EXTI_InitStruct->Line_32_63);
            break;
          default:
            status = ERROR;
            break;
        }
      }
    }
#endif
  }

  else
  {

    LL_EXTI_DisableIT_0_31(EXTI_InitStruct->Line_0_31);
    LL_EXTI_DisableEvent_0_31(EXTI_InitStruct->Line_0_31);
#if defined(EXTI_32_63_SUPPORT)

    LL_EXTI_DisableIT_32_63(EXTI_InitStruct->Line_32_63);
    LL_EXTI_DisableEvent_32_63(EXTI_InitStruct->Line_32_63);
#endif
  }
  return status;
}






void LL_EXTI_StructInit(LL_EXTI_InitTypeDef *EXTI_InitStruct)
{
  EXTI_InitStruct->Line_0_31      = LL_EXTI_LINE_NONE;
#if defined(EXTI_32_63_SUPPORT)
  EXTI_InitStruct->Line_32_63     = LL_EXTI_LINE_NONE;
#endif
  EXTI_InitStruct->LineCommand    = DISABLE;
  EXTI_InitStruct->Mode           = LL_EXTI_MODE_IT;
  EXTI_InitStruct->Trigger        = LL_EXTI_TRIGGER_FALLING;
}













#endif





#endif


