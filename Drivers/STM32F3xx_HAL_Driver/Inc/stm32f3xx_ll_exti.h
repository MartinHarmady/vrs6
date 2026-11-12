



































#ifndef __STM32F3xx_LL_EXTI_H
#define __STM32F3xx_LL_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f3xx.h"





#if defined (EXTI)









#if defined(USE_FULL_LL_DRIVER)






#endif

#if defined(USE_FULL_LL_DRIVER)



typedef struct
{

  uint32_t Line_0_31;

#if defined(EXTI_32_63_SUPPORT)

  uint32_t Line_32_63;

#endif

  FunctionalState LineCommand;


  uint8_t Mode;


  uint8_t Trigger;

} LL_EXTI_InitTypeDef;




#endif









#define LL_EXTI_LINE_0                 EXTI_IMR_IM0
#define LL_EXTI_LINE_1                 EXTI_IMR_IM1
#define LL_EXTI_LINE_2                 EXTI_IMR_IM2
#define LL_EXTI_LINE_3                 EXTI_IMR_IM3
#define LL_EXTI_LINE_4                 EXTI_IMR_IM4
#define LL_EXTI_LINE_5                 EXTI_IMR_IM5
#define LL_EXTI_LINE_6                 EXTI_IMR_IM6
#define LL_EXTI_LINE_7                 EXTI_IMR_IM7
#define LL_EXTI_LINE_8                 EXTI_IMR_IM8
#define LL_EXTI_LINE_9                 EXTI_IMR_IM9
#define LL_EXTI_LINE_10                EXTI_IMR_IM10
#define LL_EXTI_LINE_11                EXTI_IMR_IM11
#define LL_EXTI_LINE_12                EXTI_IMR_IM12
#define LL_EXTI_LINE_13                EXTI_IMR_IM13
#define LL_EXTI_LINE_14                EXTI_IMR_IM14
#define LL_EXTI_LINE_15                EXTI_IMR_IM15
#if defined(EXTI_IMR_IM16)
#define LL_EXTI_LINE_16                EXTI_IMR_IM16
#endif
#define LL_EXTI_LINE_17                EXTI_IMR_IM17
#if defined(EXTI_IMR_IM18)
#define LL_EXTI_LINE_18                EXTI_IMR_IM18
#endif
#define LL_EXTI_LINE_19                EXTI_IMR_IM19
#if defined(EXTI_IMR_IM20)
#define LL_EXTI_LINE_20                EXTI_IMR_IM20
#endif
#if defined(EXTI_IMR_IM21)
#define LL_EXTI_LINE_21                EXTI_IMR_IM21
#endif
#if defined(EXTI_IMR_IM22)
#define LL_EXTI_LINE_22                EXTI_IMR_IM22
#endif
#define LL_EXTI_LINE_23                EXTI_IMR_IM23
#if defined(EXTI_IMR_IM24)
#define LL_EXTI_LINE_24                EXTI_IMR_IM24
#endif
#if defined(EXTI_IMR_IM25)
#define LL_EXTI_LINE_25                EXTI_IMR_IM25
#endif
#if defined(EXTI_IMR_IM26)
#define LL_EXTI_LINE_26                EXTI_IMR_IM26
#endif
#if defined(EXTI_IMR_IM27)
#define LL_EXTI_LINE_27                EXTI_IMR_IM27
#endif
#if defined(EXTI_IMR_IM28)
#define LL_EXTI_LINE_28                EXTI_IMR_IM28
#endif
#if defined(EXTI_IMR_IM29)
#define LL_EXTI_LINE_29                EXTI_IMR_IM29
#endif
#if defined(EXTI_IMR_IM30)
#define LL_EXTI_LINE_30                EXTI_IMR_IM30
#endif
#if defined(EXTI_IMR_IM31)
#define LL_EXTI_LINE_31                EXTI_IMR_IM31
#endif
#define LL_EXTI_LINE_ALL_0_31          EXTI_IMR_IM

#if defined(EXTI_32_63_SUPPORT)
#define LL_EXTI_LINE_32                EXTI_IMR2_IM32
#if defined(EXTI_IMR2_IM33)
#define LL_EXTI_LINE_33                EXTI_IMR2_IM33
#endif
#if defined(EXTI_IMR2_IM34)
#define LL_EXTI_LINE_34                EXTI_IMR2_IM34
#endif
#if defined(EXTI_IMR2_IM35)
#define LL_EXTI_LINE_35                EXTI_IMR2_IM35
#endif
#if defined(EXTI_IMR2_IM36)
#define LL_EXTI_LINE_36                EXTI_IMR2_IM36
#endif
#if defined(EXTI_IMR2_IM37)
#define LL_EXTI_LINE_37                EXTI_IMR2_IM37
#endif
#if defined(EXTI_IMR2_IM38)
#define LL_EXTI_LINE_38                EXTI_IMR2_IM38
#endif
#if defined(EXTI_IMR2_IM39)
#define LL_EXTI_LINE_39                EXTI_IMR2_IM39
#endif
#if defined(EXTI_IMR2_IM40)
#define LL_EXTI_LINE_40                EXTI_IMR2_IM40
#endif
#define LL_EXTI_LINE_ALL_32_63         EXTI_IMR2_IM

#endif

#define LL_EXTI_LINE_ALL               (0xFFFFFFFFU)

#if defined(USE_FULL_LL_DRIVER)
#define LL_EXTI_LINE_NONE              (0x00000000U)
#endif




#if defined(USE_FULL_LL_DRIVER)




#define LL_EXTI_MODE_IT                 ((uint8_t)0x00U)
#define LL_EXTI_MODE_EVENT              ((uint8_t)0x01U)
#define LL_EXTI_MODE_IT_EVENT           ((uint8_t)0x02U)







#define LL_EXTI_TRIGGER_NONE            ((uint8_t)0x00U)
#define LL_EXTI_TRIGGER_RISING          ((uint8_t)0x01U)
#define LL_EXTI_TRIGGER_FALLING         ((uint8_t)0x02U)
#define LL_EXTI_TRIGGER_RISING_FALLING  ((uint8_t)0x03U)






#endif





















#define LL_EXTI_WriteReg(__REG__, __VALUE__) WRITE_REG(EXTI->__REG__, (__VALUE__))






#define LL_EXTI_ReadReg(__REG__) READ_REG(EXTI->__REG__)






























































__STATIC_INLINE void LL_EXTI_EnableIT_0_31(uint32_t ExtiLine)
{
  SET_BIT(EXTI->IMR, ExtiLine);
}
#if defined(EXTI_32_63_SUPPORT)


















__STATIC_INLINE void LL_EXTI_EnableIT_32_63(uint32_t ExtiLine)
{
  SET_BIT(EXTI->IMR2, ExtiLine);
}
#endif












































__STATIC_INLINE void LL_EXTI_DisableIT_0_31(uint32_t ExtiLine)
{
  CLEAR_BIT(EXTI->IMR, ExtiLine);
}

#if defined(EXTI_32_63_SUPPORT)


















__STATIC_INLINE void LL_EXTI_DisableIT_32_63(uint32_t ExtiLine)
{
  CLEAR_BIT(EXTI->IMR2, ExtiLine);
}
#endif












































__STATIC_INLINE uint32_t LL_EXTI_IsEnabledIT_0_31(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->IMR, ExtiLine) == (ExtiLine));
}

#if defined(EXTI_32_63_SUPPORT)


















__STATIC_INLINE uint32_t LL_EXTI_IsEnabledIT_32_63(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->IMR2, ExtiLine) == (ExtiLine));
}
#endif

















































__STATIC_INLINE void LL_EXTI_EnableEvent_0_31(uint32_t ExtiLine)
{
  SET_BIT(EXTI->EMR, ExtiLine);

}

#if defined(EXTI_32_63_SUPPORT)















__STATIC_INLINE void LL_EXTI_EnableEvent_32_63(uint32_t ExtiLine)
{
  SET_BIT(EXTI->EMR2, ExtiLine);
}
#endif









































__STATIC_INLINE void LL_EXTI_DisableEvent_0_31(uint32_t ExtiLine)
{
  CLEAR_BIT(EXTI->EMR, ExtiLine);
}

#if defined(EXTI_32_63_SUPPORT)















__STATIC_INLINE void LL_EXTI_DisableEvent_32_63(uint32_t ExtiLine)
{
  CLEAR_BIT(EXTI->EMR2, ExtiLine);
}
#endif









































__STATIC_INLINE uint32_t LL_EXTI_IsEnabledEvent_0_31(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->EMR, ExtiLine) == (ExtiLine));

}

#if defined(EXTI_32_63_SUPPORT)















__STATIC_INLINE uint32_t LL_EXTI_IsEnabledEvent_32_63(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->EMR2, ExtiLine) == (ExtiLine));
}
#endif
















































__STATIC_INLINE void LL_EXTI_EnableRisingTrig_0_31(uint32_t ExtiLine)
{
  SET_BIT(EXTI->RTSR, ExtiLine);

}

#if defined(EXTI_32_63_SUPPORT)
















__STATIC_INLINE void LL_EXTI_EnableRisingTrig_32_63(uint32_t ExtiLine)
{
  SET_BIT(EXTI->RTSR2, ExtiLine);
}
#endif








































__STATIC_INLINE void LL_EXTI_DisableRisingTrig_0_31(uint32_t ExtiLine)
{
  CLEAR_BIT(EXTI->RTSR, ExtiLine);

}

#if defined(EXTI_32_63_SUPPORT)

















__STATIC_INLINE void LL_EXTI_DisableRisingTrig_32_63(uint32_t ExtiLine)
{
  CLEAR_BIT(EXTI->RTSR2, ExtiLine);
}
#endif

































__STATIC_INLINE uint32_t LL_EXTI_IsEnabledRisingTrig_0_31(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->RTSR, ExtiLine) == (ExtiLine));
}

#if defined(EXTI_32_63_SUPPORT)










__STATIC_INLINE uint32_t LL_EXTI_IsEnabledRisingTrig_32_63(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->RTSR2, ExtiLine) == (ExtiLine));
}
#endif
















































__STATIC_INLINE void LL_EXTI_EnableFallingTrig_0_31(uint32_t ExtiLine)
{
  SET_BIT(EXTI->FTSR, ExtiLine);
}

#if defined(EXTI_32_63_SUPPORT)

















__STATIC_INLINE void LL_EXTI_EnableFallingTrig_32_63(uint32_t ExtiLine)
{
  SET_BIT(EXTI->FTSR2, ExtiLine);
}
#endif







































__STATIC_INLINE void LL_EXTI_DisableFallingTrig_0_31(uint32_t ExtiLine)
{
  CLEAR_BIT(EXTI->FTSR, ExtiLine);
}

#if defined(EXTI_32_63_SUPPORT)
















__STATIC_INLINE void LL_EXTI_DisableFallingTrig_32_63(uint32_t ExtiLine)
{
  CLEAR_BIT(EXTI->FTSR2, ExtiLine);
}
#endif

































__STATIC_INLINE uint32_t LL_EXTI_IsEnabledFallingTrig_0_31(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->FTSR, ExtiLine) == (ExtiLine));
}

#if defined(EXTI_32_63_SUPPORT)










__STATIC_INLINE uint32_t LL_EXTI_IsEnabledFallingTrig_32_63(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->FTSR2, ExtiLine) == (ExtiLine));
}
#endif














































__STATIC_INLINE void LL_EXTI_GenerateSWI_0_31(uint32_t ExtiLine)
{
  SET_BIT(EXTI->SWIER, ExtiLine);
}

#if defined(EXTI_32_63_SUPPORT)















__STATIC_INLINE void LL_EXTI_GenerateSWI_32_63(uint32_t ExtiLine)
{
  SET_BIT(EXTI->SWIER2, ExtiLine);
}
#endif











































__STATIC_INLINE uint32_t LL_EXTI_IsActiveFlag_0_31(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->PR, ExtiLine) == (ExtiLine));
}

#if defined(EXTI_32_63_SUPPORT)












__STATIC_INLINE uint32_t LL_EXTI_IsActiveFlag_32_63(uint32_t ExtiLine)
{
  return (READ_BIT(EXTI->PR2, ExtiLine) == (ExtiLine));
}
#endif



































__STATIC_INLINE uint32_t LL_EXTI_ReadFlag_0_31(uint32_t ExtiLine)
{
  return (uint32_t)(READ_BIT(EXTI->PR, ExtiLine));
}

#if defined(EXTI_32_63_SUPPORT)













__STATIC_INLINE uint32_t LL_EXTI_ReadFlag_32_63(uint32_t ExtiLine)
{
  return (uint32_t)(READ_BIT(EXTI->PR2, ExtiLine));
}
#endif



































__STATIC_INLINE void LL_EXTI_ClearFlag_0_31(uint32_t ExtiLine)
{
  WRITE_REG(EXTI->PR, ExtiLine);
}

#if defined(EXTI_32_63_SUPPORT)












__STATIC_INLINE void LL_EXTI_ClearFlag_32_63(uint32_t ExtiLine)
{
  WRITE_REG(EXTI->PR2, ExtiLine);
}
#endif





#if defined(USE_FULL_LL_DRIVER)




uint32_t LL_EXTI_Init(LL_EXTI_InitTypeDef *EXTI_InitStruct);
uint32_t LL_EXTI_DeInit(void);
void LL_EXTI_StructInit(LL_EXTI_InitTypeDef *EXTI_InitStruct);





#endif









#endif





#ifdef __cplusplus
}
#endif

#endif


