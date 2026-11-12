

































#if defined(USE_FULL_LL_DRIVER)


#include "stm32f3xx_ll_i2c.h"
#include "stm32f3xx_ll_bus.h"
#ifdef  USE_FULL_ASSERT
#include "stm32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif





#if defined (I2C1) || defined (I2C2) || defined (I2C3)













#define IS_LL_I2C_PERIPHERAL_MODE(__VALUE__)    (((__VALUE__) == LL_I2C_MODE_I2C)          || \
                                                 ((__VALUE__) == LL_I2C_MODE_SMBUS_HOST)   || \
                                                 ((__VALUE__) == LL_I2C_MODE_SMBUS_DEVICE) || \
                                                 ((__VALUE__) == LL_I2C_MODE_SMBUS_DEVICE_ARP))

#define IS_LL_I2C_ANALOG_FILTER(__VALUE__)      (((__VALUE__) == LL_I2C_ANALOGFILTER_ENABLE) || \
                                                 ((__VALUE__) == LL_I2C_ANALOGFILTER_DISABLE))

#define IS_LL_I2C_DIGITAL_FILTER(__VALUE__)     ((__VALUE__) <= 0x0000000FU)

#define IS_LL_I2C_OWN_ADDRESS1(__VALUE__)       ((__VALUE__) <= 0x000003FFU)

#define IS_LL_I2C_TYPE_ACKNOWLEDGE(__VALUE__)   (((__VALUE__) == LL_I2C_ACK) || \
                                                 ((__VALUE__) == LL_I2C_NACK))

#define IS_LL_I2C_OWN_ADDRSIZE(__VALUE__)       (((__VALUE__) == LL_I2C_OWNADDRESS1_7BIT) || \
                                                 ((__VALUE__) == LL_I2C_OWNADDRESS1_10BIT))






















uint32_t LL_I2C_DeInit(I2C_TypeDef *I2Cx)
{
  ErrorStatus status = SUCCESS;


  assert_param(IS_I2C_ALL_INSTANCE(I2Cx));

  if (I2Cx == I2C1)
  {

    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_I2C1);


    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_I2C1);
  }
#if defined(I2C2)
  else if (I2Cx == I2C2)
  {

    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_I2C2);


    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_I2C2);

  }
#endif
#if defined(I2C3)
  else if (I2Cx == I2C3)
  {

    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_I2C3);


    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_I2C3);
  }
#endif
  else
  {
    status = ERROR;
  }

  return status;
}









uint32_t LL_I2C_Init(I2C_TypeDef *I2Cx, LL_I2C_InitTypeDef *I2C_InitStruct)
{

  assert_param(IS_I2C_ALL_INSTANCE(I2Cx));


  assert_param(IS_LL_I2C_PERIPHERAL_MODE(I2C_InitStruct->PeripheralMode));
  assert_param(IS_LL_I2C_ANALOG_FILTER(I2C_InitStruct->AnalogFilter));
  assert_param(IS_LL_I2C_DIGITAL_FILTER(I2C_InitStruct->DigitalFilter));
  assert_param(IS_LL_I2C_OWN_ADDRESS1(I2C_InitStruct->OwnAddress1));
  assert_param(IS_LL_I2C_TYPE_ACKNOWLEDGE(I2C_InitStruct->TypeAcknowledge));
  assert_param(IS_LL_I2C_OWN_ADDRSIZE(I2C_InitStruct->OwnAddrSize));


  LL_I2C_Disable(I2Cx);






  LL_I2C_ConfigFilters(I2Cx, I2C_InitStruct->AnalogFilter, I2C_InitStruct->DigitalFilter);






  LL_I2C_SetTiming(I2Cx, I2C_InitStruct->Timing);


  LL_I2C_Enable(I2Cx);






  LL_I2C_DisableOwnAddress1(I2Cx);
  LL_I2C_SetOwnAddress1(I2Cx, I2C_InitStruct->OwnAddress1, I2C_InitStruct->OwnAddrSize);


  if (I2C_InitStruct->OwnAddress1 != 0U)
  {
    LL_I2C_EnableOwnAddress1(I2Cx);
  }





  LL_I2C_SetMode(I2Cx, I2C_InitStruct->PeripheralMode);






  LL_I2C_AcknowledgeNextData(I2Cx, I2C_InitStruct->TypeAcknowledge);

  return SUCCESS;
}






void LL_I2C_StructInit(LL_I2C_InitTypeDef *I2C_InitStruct)
{

  I2C_InitStruct->PeripheralMode  = LL_I2C_MODE_I2C;
  I2C_InitStruct->Timing          = 0U;
  I2C_InitStruct->AnalogFilter    = LL_I2C_ANALOGFILTER_ENABLE;
  I2C_InitStruct->DigitalFilter   = 0U;
  I2C_InitStruct->OwnAddress1     = 0U;
  I2C_InitStruct->TypeAcknowledge = LL_I2C_NACK;
  I2C_InitStruct->OwnAddrSize     = LL_I2C_OWNADDRESS1_7BIT;
}













#endif





#endif


