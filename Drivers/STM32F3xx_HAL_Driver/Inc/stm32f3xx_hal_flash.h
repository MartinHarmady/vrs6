



































#ifndef __STM32F3xx_HAL_FLASH_H
#define __STM32F3xx_HAL_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"












#define FLASH_TIMEOUT_VALUE      (50000U)








#define IS_FLASH_TYPEPROGRAM(VALUE)  (((VALUE) == FLASH_TYPEPROGRAM_HALFWORD) || \
                                      ((VALUE) == FLASH_TYPEPROGRAM_WORD)     || \
                                      ((VALUE) == FLASH_TYPEPROGRAM_DOUBLEWORD))

#define IS_FLASH_LATENCY(__LATENCY__) (((__LATENCY__) == FLASH_LATENCY_0) || \
                                       ((__LATENCY__) == FLASH_LATENCY_1) || \
                                       ((__LATENCY__) == FLASH_LATENCY_2))













typedef enum
{
  FLASH_PROC_NONE              = 0U,
  FLASH_PROC_PAGEERASE         = 1U,
  FLASH_PROC_MASSERASE         = 2U,
  FLASH_PROC_PROGRAMHALFWORD   = 3U,
  FLASH_PROC_PROGRAMWORD       = 4U,
  FLASH_PROC_PROGRAMDOUBLEWORD = 5U
} FLASH_ProcedureTypeDef;




typedef struct
{
  __IO FLASH_ProcedureTypeDef ProcedureOnGoing;

  __IO uint32_t               DataRemaining;

  __IO uint32_t               Address;

  __IO uint64_t               Data;

  HAL_LockTypeDef             Lock;

  __IO uint32_t               ErrorCode;

} FLASH_ProcessTypeDef;














#define HAL_FLASH_ERROR_NONE      0x00U
#define HAL_FLASH_ERROR_PROG      0x01U
#define HAL_FLASH_ERROR_WRP       0x02U








#define FLASH_TYPEPROGRAM_HALFWORD   (0x01U)
#define FLASH_TYPEPROGRAM_WORD       (0x02U)
#define FLASH_TYPEPROGRAM_DOUBLEWORD (0x03U)








#define FLASH_LATENCY_0            (0x00000000U)
#define FLASH_LATENCY_1            FLASH_ACR_LATENCY_0
#define FLASH_LATENCY_2            FLASH_ACR_LATENCY_1









#define FLASH_FLAG_BSY             FLASH_SR_BSY
#define FLASH_FLAG_PGERR           FLASH_SR_PGERR
#define FLASH_FLAG_WRPERR          FLASH_SR_WRPERR
#define FLASH_FLAG_EOP             FLASH_SR_EOP







#define FLASH_IT_EOP               FLASH_CR_EOPIE
#define FLASH_IT_ERR               FLASH_CR_ERRIE
























#define __HAL_FLASH_HALF_CYCLE_ACCESS_ENABLE()  (FLASH->ACR |= FLASH_ACR_HLFCYA)





#define __HAL_FLASH_HALF_CYCLE_ACCESS_DISABLE() (FLASH->ACR &= (~FLASH_ACR_HLFCYA))



















#define __HAL_FLASH_SET_LATENCY(__LATENCY__)    (FLASH->ACR = (FLASH->ACR&(~FLASH_ACR_LATENCY)) | (__LATENCY__))










#define __HAL_FLASH_GET_LATENCY()     (READ_BIT((FLASH->ACR), FLASH_ACR_LATENCY))













#define __HAL_FLASH_PREFETCH_BUFFER_ENABLE()    (FLASH->ACR |= FLASH_ACR_PRFTBE)





#define __HAL_FLASH_PREFETCH_BUFFER_DISABLE()   (FLASH->ACR &= (~FLASH_ACR_PRFTBE))


















#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)  SET_BIT((FLASH->CR), (__INTERRUPT__))









#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)  CLEAR_BIT((FLASH->CR), (uint32_t)(__INTERRUPT__))











#define __HAL_FLASH_GET_FLAG(__FLAG__)   (((FLASH->SR) & (__FLAG__)) == (__FLAG__))










#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)   ((FLASH->SR) = (__FLAG__))










#include "stm32f3xx_hal_flash_ex.h"










HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data);


void       HAL_FLASH_IRQHandler(void);

void       HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
void       HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);









HAL_StatusTypeDef HAL_FLASH_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_Lock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Launch(void);









uint32_t HAL_FLASH_GetError(void);













HAL_StatusTypeDef       FLASH_WaitForLastOperation(uint32_t Timeout);













#ifdef __cplusplus
}
#endif

#endif



