

































#if defined(USE_FULL_LL_DRIVER)


#include "stm32f3xx_ll_dma.h"
#include "stm32f3xx_ll_bus.h"
#ifdef  USE_FULL_ASSERT
#include "stm32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif





#if defined (DMA1) || defined (DMA2)












#define IS_LL_DMA_DIRECTION(__VALUE__)          (((__VALUE__) == LL_DMA_DIRECTION_PERIPH_TO_MEMORY) || \
                                                 ((__VALUE__) == LL_DMA_DIRECTION_MEMORY_TO_PERIPH) || \
                                                 ((__VALUE__) == LL_DMA_DIRECTION_MEMORY_TO_MEMORY))

#define IS_LL_DMA_MODE(__VALUE__)               (((__VALUE__) == LL_DMA_MODE_NORMAL) || \
                                                 ((__VALUE__) == LL_DMA_MODE_CIRCULAR))

#define IS_LL_DMA_PERIPHINCMODE(__VALUE__)      (((__VALUE__) == LL_DMA_PERIPH_INCREMENT) || \
                                                 ((__VALUE__) == LL_DMA_PERIPH_NOINCREMENT))

#define IS_LL_DMA_MEMORYINCMODE(__VALUE__)      (((__VALUE__) == LL_DMA_MEMORY_INCREMENT) || \
                                                 ((__VALUE__) == LL_DMA_MEMORY_NOINCREMENT))

#define IS_LL_DMA_PERIPHDATASIZE(__VALUE__)     (((__VALUE__) == LL_DMA_PDATAALIGN_BYTE)      || \
                                                 ((__VALUE__) == LL_DMA_PDATAALIGN_HALFWORD)  || \
                                                 ((__VALUE__) == LL_DMA_PDATAALIGN_WORD))

#define IS_LL_DMA_MEMORYDATASIZE(__VALUE__)     (((__VALUE__) == LL_DMA_MDATAALIGN_BYTE)      || \
                                                 ((__VALUE__) == LL_DMA_MDATAALIGN_HALFWORD)  || \
                                                 ((__VALUE__) == LL_DMA_MDATAALIGN_WORD))

#define IS_LL_DMA_NBDATA(__VALUE__)             ((__VALUE__)  <= 0x0000FFFFU)


#define IS_LL_DMA_PRIORITY(__VALUE__)           (((__VALUE__) == LL_DMA_PRIORITY_LOW)    || \
                                                 ((__VALUE__) == LL_DMA_PRIORITY_MEDIUM) || \
                                                 ((__VALUE__) == LL_DMA_PRIORITY_HIGH)   || \
                                                 ((__VALUE__) == LL_DMA_PRIORITY_VERYHIGH))

#if defined (DMA2)
#if defined (DMA2_Channel6) && defined (DMA2_Channel7)
#define IS_LL_DMA_ALL_CHANNEL_INSTANCE(INSTANCE, CHANNEL)  ((((INSTANCE) == DMA1) && \
                                                         (((CHANNEL) == LL_DMA_CHANNEL_1) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_2) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_3) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_4) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_5) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_6) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_7))) || \
                                                         (((INSTANCE) == DMA2) && \
                                                         (((CHANNEL) == LL_DMA_CHANNEL_1) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_2) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_3) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_4) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_5) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_6) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_7))))
#else
#define IS_LL_DMA_ALL_CHANNEL_INSTANCE(INSTANCE, CHANNEL)  ((((INSTANCE) == DMA1) && \
                                                         (((CHANNEL) == LL_DMA_CHANNEL_1) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_2) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_3) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_4) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_5) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_6) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_7))) || \
                                                         (((INSTANCE) == DMA2) && \
                                                         (((CHANNEL) == LL_DMA_CHANNEL_1) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_2) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_3) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_4) || \
                                                          ((CHANNEL) == LL_DMA_CHANNEL_5))))
#endif
#else
#define IS_LL_DMA_ALL_CHANNEL_INSTANCE(INSTANCE, CHANNEL)  ((((INSTANCE) == DMA1) && \
                                                            (((CHANNEL) == LL_DMA_CHANNEL_1)|| \
                                                            ((CHANNEL) == LL_DMA_CHANNEL_2) || \
                                                            ((CHANNEL) == LL_DMA_CHANNEL_3) || \
                                                            ((CHANNEL) == LL_DMA_CHANNEL_4) || \
                                                            ((CHANNEL) == LL_DMA_CHANNEL_5) || \
                                                            ((CHANNEL) == LL_DMA_CHANNEL_6) || \
                                                            ((CHANNEL) == LL_DMA_CHANNEL_7))))
#endif






























uint32_t LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel)
{
  DMA_Channel_TypeDef *tmp = (DMA_Channel_TypeDef *)DMA1_Channel1;
  ErrorStatus status = SUCCESS;


  assert_param(IS_LL_DMA_ALL_CHANNEL_INSTANCE(DMAx, Channel));

    tmp = (DMA_Channel_TypeDef *)(__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel));


    CLEAR_BIT(tmp->CCR, DMA_CCR_EN);


    LL_DMA_WriteReg(tmp, CCR, 0U);


    LL_DMA_WriteReg(tmp, CNDTR, 0U);


    LL_DMA_WriteReg(tmp, CPAR, 0U);


    LL_DMA_WriteReg(tmp, CMAR, 0U);


    if (Channel == LL_DMA_CHANNEL_1)
    {

      LL_DMA_ClearFlag_GI1(DMAx);
    }
    else if (Channel == LL_DMA_CHANNEL_2)
    {

      LL_DMA_ClearFlag_GI2(DMAx);
    }
    else if (Channel == LL_DMA_CHANNEL_3)
    {

      LL_DMA_ClearFlag_GI3(DMAx);
    }
    else if (Channel == LL_DMA_CHANNEL_4)
    {

      LL_DMA_ClearFlag_GI4(DMAx);
    }
    else if (Channel == LL_DMA_CHANNEL_5)
    {

      LL_DMA_ClearFlag_GI5(DMAx);
    }

    else if (Channel == LL_DMA_CHANNEL_6)
    {

      LL_DMA_ClearFlag_GI6(DMAx);
    }
    else if (Channel == LL_DMA_CHANNEL_7)
    {

      LL_DMA_ClearFlag_GI7(DMAx);
    }
    else
    {
      status = ERROR;
    }

  return status;
}




















uint32_t LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct)
{

  assert_param(IS_LL_DMA_ALL_CHANNEL_INSTANCE(DMAx, Channel));


  assert_param(IS_LL_DMA_DIRECTION(DMA_InitStruct->Direction));
  assert_param(IS_LL_DMA_MODE(DMA_InitStruct->Mode));
  assert_param(IS_LL_DMA_PERIPHINCMODE(DMA_InitStruct->PeriphOrM2MSrcIncMode));
  assert_param(IS_LL_DMA_MEMORYINCMODE(DMA_InitStruct->MemoryOrM2MDstIncMode));
  assert_param(IS_LL_DMA_PERIPHDATASIZE(DMA_InitStruct->PeriphOrM2MSrcDataSize));
  assert_param(IS_LL_DMA_MEMORYDATASIZE(DMA_InitStruct->MemoryOrM2MDstDataSize));
  assert_param(IS_LL_DMA_NBDATA(DMA_InitStruct->NbData));
  assert_param(IS_LL_DMA_PRIORITY(DMA_InitStruct->Priority));













  LL_DMA_ConfigTransfer(DMAx, Channel, DMA_InitStruct->Direction              | \
                        DMA_InitStruct->Mode                   | \
                        DMA_InitStruct->PeriphOrM2MSrcIncMode  | \
                        DMA_InitStruct->MemoryOrM2MDstIncMode  | \
                        DMA_InitStruct->PeriphOrM2MSrcDataSize | \
                        DMA_InitStruct->MemoryOrM2MDstDataSize | \
                        DMA_InitStruct->Priority);





  LL_DMA_SetMemoryAddress(DMAx, Channel, DMA_InitStruct->MemoryOrM2MDstAddress);





  LL_DMA_SetPeriphAddress(DMAx, Channel, DMA_InitStruct->PeriphOrM2MSrcAddress);





  LL_DMA_SetDataLength(DMAx, Channel, DMA_InitStruct->NbData);


  return SUCCESS;
}






void LL_DMA_StructInit(LL_DMA_InitTypeDef *DMA_InitStruct)
{

  DMA_InitStruct->PeriphOrM2MSrcAddress  = 0x00000000U;
  DMA_InitStruct->MemoryOrM2MDstAddress  = 0x00000000U;
  DMA_InitStruct->Direction              = LL_DMA_DIRECTION_PERIPH_TO_MEMORY;
  DMA_InitStruct->Mode                   = LL_DMA_MODE_NORMAL;
  DMA_InitStruct->PeriphOrM2MSrcIncMode  = LL_DMA_PERIPH_NOINCREMENT;
  DMA_InitStruct->MemoryOrM2MDstIncMode  = LL_DMA_MEMORY_NOINCREMENT;
  DMA_InitStruct->PeriphOrM2MSrcDataSize = LL_DMA_PDATAALIGN_BYTE;
  DMA_InitStruct->MemoryOrM2MDstDataSize = LL_DMA_MDATAALIGN_BYTE;
  DMA_InitStruct->NbData                 = 0x00000000U;
  DMA_InitStruct->Priority               = LL_DMA_PRIORITY_LOW;
}













#endif





#endif


