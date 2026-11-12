

































#if defined(USE_FULL_LL_DRIVER)


#include "stm32f3xx_ll_gpio.h"
#include "stm32f3xx_ll_bus.h"
#ifdef  USE_FULL_ASSERT
#include "stm32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif





#if defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOD) || defined (GPIOE) || defined (GPIOF) || defined (GPIOG) || defined (GPIOH)












#define IS_LL_GPIO_PIN(__VALUE__)          (((0x00000000U) < (__VALUE__)) && ((__VALUE__) <= (LL_GPIO_PIN_ALL)))

#define IS_LL_GPIO_MODE(__VALUE__)         (((__VALUE__) == LL_GPIO_MODE_INPUT)     ||\
                                            ((__VALUE__) == LL_GPIO_MODE_OUTPUT)    ||\
                                            ((__VALUE__) == LL_GPIO_MODE_ALTERNATE) ||\
                                            ((__VALUE__) == LL_GPIO_MODE_ANALOG))

#define IS_LL_GPIO_OUTPUT_TYPE(__VALUE__)  (((__VALUE__) == LL_GPIO_OUTPUT_PUSHPULL)  ||\
                                            ((__VALUE__) == LL_GPIO_OUTPUT_OPENDRAIN))

#define IS_LL_GPIO_SPEED(__VALUE__)        (((__VALUE__) == LL_GPIO_SPEED_FREQ_LOW)       ||\
                                            ((__VALUE__) == LL_GPIO_SPEED_FREQ_MEDIUM)    ||\
                                            ((__VALUE__) == LL_GPIO_SPEED_FREQ_HIGH))

#define IS_LL_GPIO_PULL(__VALUE__)         (((__VALUE__) == LL_GPIO_PULL_NO)   ||\
                                            ((__VALUE__) == LL_GPIO_PULL_UP)   ||\
                                            ((__VALUE__) == LL_GPIO_PULL_DOWN))

#define IS_LL_GPIO_ALTERNATE(__VALUE__)    (((__VALUE__) == LL_GPIO_AF_0  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_1  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_2  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_3  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_4  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_5  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_6  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_7  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_8  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_9  )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_10 )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_11 )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_12 )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_13 )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_14 )   ||\
                                            ((__VALUE__) == LL_GPIO_AF_15 ))






















ErrorStatus LL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
  ErrorStatus status = SUCCESS;


  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));


  if (GPIOx == GPIOA)
  {
    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_GPIOA);
  }
  else if (GPIOx == GPIOB)
  {
    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_GPIOB);
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_GPIOB);
  }
  else if (GPIOx == GPIOC)
  {
    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_GPIOC);
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_GPIOC);
  }
#if defined(GPIOD)
  else if (GPIOx == GPIOD)
  {
    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_GPIOD);
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_GPIOD);
  }
#endif
#if defined(GPIOE)
  else if (GPIOx == GPIOE)
  {
    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_GPIOE);
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_GPIOE);
  }
#endif
#if defined(GPIOF)
  else if (GPIOx == GPIOF)
  {
    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_GPIOF);
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_GPIOF);
  }
#endif
#if defined(GPIOG)
  else if (GPIOx == GPIOG)
  {
    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_GPIOG);
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_GPIOG);
  }
#endif
#if defined(GPIOH)
  else if (GPIOx == GPIOH)
  {
    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_GPIOH);
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_GPIOH);
  }
#endif
  else
  {
    status = ERROR;
  }

  return (status);
}










ErrorStatus LL_GPIO_Init(GPIO_TypeDef *GPIOx, LL_GPIO_InitTypeDef *GPIO_InitStruct)
{
  uint32_t pinpos     = 0x00000000U;
  uint32_t currentpin = 0x00000000U;


  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
  assert_param(IS_LL_GPIO_PIN(GPIO_InitStruct->Pin));
  assert_param(IS_LL_GPIO_MODE(GPIO_InitStruct->Mode));
  assert_param(IS_LL_GPIO_PULL(GPIO_InitStruct->Pull));



  pinpos = POSITION_VAL(GPIO_InitStruct->Pin);


  while (((GPIO_InitStruct->Pin) >> pinpos) != 0x00000000U)
  {

    currentpin = (GPIO_InitStruct->Pin) & (0x00000001U << pinpos);

    if (currentpin)
    {

      LL_GPIO_SetPinMode(GPIOx, currentpin, GPIO_InitStruct->Mode);

      if ((GPIO_InitStruct->Mode == LL_GPIO_MODE_OUTPUT) || (GPIO_InitStruct->Mode == LL_GPIO_MODE_ALTERNATE))
      {

        assert_param(IS_LL_GPIO_SPEED(GPIO_InitStruct->Speed));


        LL_GPIO_SetPinSpeed(GPIOx, currentpin, GPIO_InitStruct->Speed);
      }


      LL_GPIO_SetPinPull(GPIOx, currentpin, GPIO_InitStruct->Pull);

      if (GPIO_InitStruct->Mode == LL_GPIO_MODE_ALTERNATE)
      {

        assert_param(IS_LL_GPIO_ALTERNATE(GPIO_InitStruct->Alternate));


        if (POSITION_VAL(currentpin) < 0x00000008U)
        {
          LL_GPIO_SetAFPin_0_7(GPIOx, currentpin, GPIO_InitStruct->Alternate);
        }
        else
        {
          LL_GPIO_SetAFPin_8_15(GPIOx, currentpin, GPIO_InitStruct->Alternate);
        }
      }
    }
    pinpos++;
  }

  if ((GPIO_InitStruct->Mode == LL_GPIO_MODE_OUTPUT) || (GPIO_InitStruct->Mode == LL_GPIO_MODE_ALTERNATE))
  {

    assert_param(IS_LL_GPIO_OUTPUT_TYPE(GPIO_InitStruct->OutputType));


    LL_GPIO_SetPinOutputType(GPIOx, GPIO_InitStruct->Pin, GPIO_InitStruct->OutputType);

  }
  return (SUCCESS);
}








void LL_GPIO_StructInit(LL_GPIO_InitTypeDef *GPIO_InitStruct)
{

  GPIO_InitStruct->Pin        = LL_GPIO_PIN_ALL;
  GPIO_InitStruct->Mode       = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct->Speed      = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct->OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct->Pull       = LL_GPIO_PULL_NO;
  GPIO_InitStruct->Alternate  = LL_GPIO_AF_0;
}













#endif





#endif


