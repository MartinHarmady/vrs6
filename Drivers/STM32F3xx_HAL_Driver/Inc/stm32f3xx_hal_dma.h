



































#ifndef __STM32F3xx_HAL_DMA_H
#define __STM32F3xx_HAL_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"


















typedef struct
{
  uint32_t Direction;



  uint32_t PeriphInc;


  uint32_t MemInc;


  uint32_t PeriphDataAlignment;


  uint32_t MemDataAlignment;


  uint32_t Mode;




  uint32_t Priority;

} DMA_InitTypeDef;




typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,
  HAL_DMA_STATE_READY             = 0x01U,
  HAL_DMA_STATE_BUSY              = 0x02U,
  HAL_DMA_STATE_TIMEOUT           = 0x03
}HAL_DMA_StateTypeDef;




typedef enum
{
  HAL_DMA_FULL_TRANSFER      = 0x00U,
  HAL_DMA_HALF_TRANSFER      = 0x01
}HAL_DMA_LevelCompleteTypeDef;




typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID          = 0x00U,
  HAL_DMA_XFER_HALFCPLT_CB_ID      = 0x01U,
  HAL_DMA_XFER_ERROR_CB_ID         = 0x02U,
  HAL_DMA_XFER_ABORT_CB_ID         = 0x03U,
  HAL_DMA_XFER_ALL_CB_ID           = 0x04
}HAL_DMA_CallbackIDTypeDef;




typedef struct __DMA_HandleTypeDef
{
  DMA_Channel_TypeDef   *Instance;

  DMA_InitTypeDef       Init;

  HAL_LockTypeDef       Lock;

  HAL_DMA_StateTypeDef  State;

  void                  *Parent;

  void                  (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);

  void                  (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);

  void                  (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);

  void                  (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);

  __IO uint32_t         ErrorCode;

  DMA_TypeDef          *DmaBaseAddress;

  uint32_t              ChannelIndex;
} DMA_HandleTypeDef;













#define HAL_DMA_ERROR_NONE          (0x00000000U)
#define HAL_DMA_ERROR_TE            (0x00000001U)
#define HAL_DMA_ERROR_NO_XFER       (0x00000004U)
#define HAL_DMA_ERROR_TIMEOUT       (0x00000020U)
#define HAL_DMA_ERROR_NOT_SUPPORTED (0x00000100U)







#define DMA_PERIPH_TO_MEMORY         (0x00000000U)
#define DMA_MEMORY_TO_PERIPH         ((uint32_t)DMA_CCR_DIR)
#define DMA_MEMORY_TO_MEMORY         ((uint32_t)DMA_CCR_MEM2MEM)








#define DMA_PINC_ENABLE        ((uint32_t)DMA_CCR_PINC)
#define DMA_PINC_DISABLE       (0x00000000U)







#define DMA_MINC_ENABLE         ((uint32_t)DMA_CCR_MINC)
#define DMA_MINC_DISABLE        (0x00000000U)







#define DMA_PDATAALIGN_BYTE          (0x00000000U)
#define DMA_PDATAALIGN_HALFWORD      ((uint32_t)DMA_CCR_PSIZE_0)
#define DMA_PDATAALIGN_WORD          ((uint32_t)DMA_CCR_PSIZE_1)







#define DMA_MDATAALIGN_BYTE          (0x00000000U)
#define DMA_MDATAALIGN_HALFWORD      ((uint32_t)DMA_CCR_MSIZE_0)
#define DMA_MDATAALIGN_WORD          ((uint32_t)DMA_CCR_MSIZE_1)







#define DMA_NORMAL         (0x00000000U)
#define DMA_CIRCULAR       ((uint32_t)DMA_CCR_CIRC)







#define DMA_PRIORITY_LOW             (0x00000000U)
#define DMA_PRIORITY_MEDIUM          ((uint32_t)DMA_CCR_PL_0)
#define DMA_PRIORITY_HIGH            ((uint32_t)DMA_CCR_PL_1)
#define DMA_PRIORITY_VERY_HIGH       ((uint32_t)DMA_CCR_PL)








#define DMA_IT_TC                         ((uint32_t)DMA_CCR_TCIE)
#define DMA_IT_HT                         ((uint32_t)DMA_CCR_HTIE)
#define DMA_IT_TE                         ((uint32_t)DMA_CCR_TEIE)







#define DMA_FLAG_GL1                      (0x00000001U)
#define DMA_FLAG_TC1                      (0x00000002U)
#define DMA_FLAG_HT1                      (0x00000004U)
#define DMA_FLAG_TE1                      (0x00000008U)
#define DMA_FLAG_GL2                      (0x00000010U)
#define DMA_FLAG_TC2                      (0x00000020U)
#define DMA_FLAG_HT2                      (0x00000040U)
#define DMA_FLAG_TE2                      (0x00000080U)
#define DMA_FLAG_GL3                      (0x00000100U)
#define DMA_FLAG_TC3                      (0x00000200U)
#define DMA_FLAG_HT3                      (0x00000400U)
#define DMA_FLAG_TE3                      (0x00000800U)
#define DMA_FLAG_GL4                      (0x00001000U)
#define DMA_FLAG_TC4                      (0x00002000U)
#define DMA_FLAG_HT4                      (0x00004000U)
#define DMA_FLAG_TE4                      (0x00008000U)
#define DMA_FLAG_GL5                      (0x00010000U)
#define DMA_FLAG_TC5                      (0x00020000U)
#define DMA_FLAG_HT5                      (0x00040000U)
#define DMA_FLAG_TE5                      (0x00080000U)
#define DMA_FLAG_GL6                      (0x00100000U)
#define DMA_FLAG_TC6                      (0x00200000U)
#define DMA_FLAG_HT6                      (0x00400000U)
#define DMA_FLAG_TE6                      (0x00800000U)
#define DMA_FLAG_GL7                      (0x01000000U)
#define DMA_FLAG_TC7                      (0x02000000U)
#define DMA_FLAG_HT7                      (0x04000000U)
#define DMA_FLAG_TE7                      (0x08000000U)


















#define __HAL_DMA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DMA_STATE_RESET)






#define __HAL_DMA_ENABLE(__HANDLE__)        ((__HANDLE__)->Instance->CCR |= DMA_CCR_EN)






#define __HAL_DMA_DISABLE(__HANDLE__)       ((__HANDLE__)->Instance->CCR &= ~DMA_CCR_EN)














#define __HAL_DMA_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->CCR |= (__INTERRUPT__))











#define __HAL_DMA_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((__HANDLE__)->Instance->CCR &= ~(__INTERRUPT__))











#define __HAL_DMA_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)  (((__HANDLE__)->Instance->CCR & (__INTERRUPT__)))







#define __HAL_DMA_GET_COUNTER(__HANDLE__) ((__HANDLE__)->Instance->CNDTR)






#include "stm32f3xx_hal_dma_ex.h"










HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DeInit (DMA_HandleTypeDef *hdma);








HAL_StatusTypeDef HAL_DMA_Start (DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, uint32_t CompleteLevel, uint32_t Timeout);
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)( DMA_HandleTypeDef * _hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);








HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t             HAL_DMA_GetError(DMA_HandleTypeDef *hdma);













#define IS_DMA_BUFFER_SIZE(SIZE) (((SIZE) >= 0x1U) && ((SIZE) < 0x10000U))

#define IS_DMA_DIRECTION(DIRECTION) (((DIRECTION) == DMA_PERIPH_TO_MEMORY ) || \
                                     ((DIRECTION) == DMA_MEMORY_TO_PERIPH)  || \
                                     ((DIRECTION) == DMA_MEMORY_TO_MEMORY))

#define IS_DMA_PERIPHERAL_INC_STATE(STATE) (((STATE) == DMA_PINC_ENABLE) || \
                                            ((STATE) == DMA_PINC_DISABLE))

#define IS_DMA_MEMORY_INC_STATE(STATE) (((STATE) == DMA_MINC_ENABLE)  || \
                                        ((STATE) == DMA_MINC_DISABLE))

#define IS_DMA_PERIPHERAL_DATA_SIZE(SIZE) (((SIZE) == DMA_PDATAALIGN_BYTE)     || \
                                           ((SIZE) == DMA_PDATAALIGN_HALFWORD) || \
                                           ((SIZE) == DMA_PDATAALIGN_WORD))

#define IS_DMA_MEMORY_DATA_SIZE(SIZE) (((SIZE) == DMA_MDATAALIGN_BYTE)     || \
                                       ((SIZE) == DMA_MDATAALIGN_HALFWORD) || \
                                       ((SIZE) == DMA_MDATAALIGN_WORD ))

#define IS_DMA_MODE(MODE) (((MODE) == DMA_NORMAL )  || \
                           ((MODE) == DMA_CIRCULAR))

#define IS_DMA_PRIORITY(PRIORITY) (((PRIORITY) == DMA_PRIORITY_LOW )   || \
                                   ((PRIORITY) == DMA_PRIORITY_MEDIUM) || \
                                   ((PRIORITY) == DMA_PRIORITY_HIGH)   || \
                                   ((PRIORITY) == DMA_PRIORITY_VERY_HIGH))














#ifdef __cplusplus
}
#endif

#endif


