




















































#ifndef __STM32F3xx_H
#define __STM32F3xx_H

#ifdef __cplusplus
 extern "C" {
#endif








#if !defined (STM32F3)
#define STM32F3
#endif





#if !defined (STM32F301x8) && !defined (STM32F302x8) && !defined (STM32F318xx) && \
    !defined (STM32F302xC) && !defined (STM32F303xC) && !defined (STM32F358xx) && \
    !defined (STM32F303x8) && !defined (STM32F334x8) && !defined (STM32F328xx) && \
    !defined (STM32F302xE) && !defined (STM32F303xE) && !defined (STM32F398xx) && \
    !defined (STM32F373xC) && !defined (STM32F378xx)


























#endif




#if !defined  (USE_HAL_DRIVER)






#endif




#define __STM32F3_CMSIS_VERSION_MAIN   (0x02)
#define __STM32F3_CMSIS_VERSION_SUB1   (0x03)
#define __STM32F3_CMSIS_VERSION_SUB2   (0x02)
#define __STM32F3_CMSIS_VERSION_RC     (0x00)
#define __STM32F3_CMSIS_VERSION        ((__STM32F3_CMSIS_VERSION_MAIN     << 24)\
                                       |(__STM32F3_CMSIS_VERSION_SUB1 << 16)\
                                       |(__STM32F3_CMSIS_VERSION_SUB2 << 8 )\
                                       |(__STM32F3_CMSIS_VERSION_RC))









#if defined(STM32F301x8)
  #include "stm32f301x8.h"
#elif defined(STM32F302x8)
  #include "stm32f302x8.h"
#elif defined(STM32F302xC)
  #include "stm32f302xc.h"
#elif defined(STM32F302xE)
  #include "stm32f302xe.h"
#elif defined(STM32F303x8)
  #include "stm32f303x8.h"
#elif defined(STM32F303xC)
  #include "stm32f303xc.h"
#elif defined(STM32F303xE)
  #include "stm32f303xe.h"
#elif defined(STM32F373xC)
  #include "stm32f373xc.h"
#elif defined(STM32F334x8)
  #include "stm32f334x8.h"
#elif defined(STM32F318xx)
  #include "stm32f318xx.h"
#elif defined(STM32F328xx)
  #include "stm32f328xx.h"
#elif defined(STM32F358xx)
  #include "stm32f358xx.h"
#elif defined(STM32F378xx)
  #include "stm32f378xx.h"
#elif defined(STM32F398xx)
  #include "stm32f398xx.h"
#else
 #error "Please select first the target STM32F3xx device used in your application (in stm32f3xx.h file)"
#endif








typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
  SUCCESS = 0,
  ERROR = !SUCCESS
} ErrorStatus;









#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))


#if defined (USE_HAL_DRIVER)
 #include "stm32f3xx_hal.h"
#endif







#ifdef __cplusplus
}
#endif

#endif












