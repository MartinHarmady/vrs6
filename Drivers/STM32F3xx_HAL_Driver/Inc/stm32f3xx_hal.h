




































#ifndef __STM32F3xx_HAL_H
#define __STM32F3xx_HAL_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_conf.h"













#define IS_SYSCFG_FASTMODEPLUS(__PIN__) ((((__PIN__) & SYSCFG_FASTMODEPLUS_PB6)  == SYSCFG_FASTMODEPLUS_PB6)  || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB7)  == SYSCFG_FASTMODEPLUS_PB7)  || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB8)  == SYSCFG_FASTMODEPLUS_PB8)  || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB9)  == SYSCFG_FASTMODEPLUS_PB9))













typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;















#define SYSCFG_OFFSET                (SYSCFG_BASE - PERIPH_BASE)


#define CFGR2_OFFSET                 (SYSCFG_OFFSET + 0x18U)
#define BYPADDRPAR_BitNumber          0x04U
#define CFGR2_BYPADDRPAR_BB          (PERIPH_BB_BASE + (CFGR2_OFFSET * 32U) + (BYPADDRPAR_BitNumber * 4U))




#if defined(SYSCFG_CFGR1_DMA_RMP)








#define HAL_REMAPDMA_ADC24_DMA2_CH34         (0x00000100U)

#define HAL_REMAPDMA_TIM16_DMA1_CH6          (0x00000800U)

#define HAL_REMAPDMA_TIM17_DMA1_CH7          (0x00001000U)

#define HAL_REMAPDMA_TIM6_DAC1_CH1_DMA1_CH3  (0x00002000U)

#define HAL_REMAPDMA_TIM7_DAC1_CH2_DMA1_CH4  (0x00004000U)

#define HAL_REMAPDMA_DAC2_CH1_DMA1_CH5       (0x00008000U)

#define HAL_REMAPDMA_TIM18_DAC2_CH1_DMA1_CH5 (0x00008000U)

#if defined(SYSCFG_CFGR3_DMA_RMP)
#if !defined(HAL_REMAP_CFGR3_MASK)
#define HAL_REMAP_CFGR3_MASK                 (0x01000000U)
#endif

#define HAL_REMAPDMA_SPI1_RX_DMA1_CH2        (0x01000003U)

#define HAL_REMAPDMA_SPI1_RX_DMA1_CH4        (0x01000001U)

#define HAL_REMAPDMA_SPI1_RX_DMA1_CH6        (0x01000002U)

#define HAL_REMAPDMA_SPI1_TX_DMA1_CH3        (0x0100000CU)

#define HAL_REMAPDMA_SPI1_TX_DMA1_CH5        (0x01000004U)

#define HAL_REMAPDMA_SPI1_TX_DMA1_CH7        (0x01000008U)

#define HAL_REMAPDMA_I2C1_RX_DMA1_CH7        (0x01000030U)

#define HAL_REMAPDMA_I2C1_RX_DMA1_CH3        (0x01000010U)

#define HAL_REMAPDMA_I2C1_RX_DMA1_CH5        (0x01000020U)

#define HAL_REMAPDMA_I2C1_TX_DMA1_CH6        (0x010000C0U)

#define HAL_REMAPDMA_I2C1_TX_DMA1_CH2        (0x01000040U)

#define HAL_REMAPDMA_I2C1_TX_DMA1_CH4        (0x01000080U)

#define HAL_REMAPDMA_ADC2_DMA1_CH2           (0x01000100U)


#define HAL_REMAPDMA_ADC2_DMA1_CH4           (0x01000300U)

#endif

#if defined(SYSCFG_CFGR3_DMA_RMP)
#define IS_DMA_REMAP(RMP) ((((RMP) & HAL_REMAPDMA_ADC24_DMA2_CH34)         == HAL_REMAPDMA_ADC24_DMA2_CH34)         || \
                              (((RMP) & HAL_REMAPDMA_TIM16_DMA1_CH6)          == HAL_REMAPDMA_TIM16_DMA1_CH6)          || \
                              (((RMP) & HAL_REMAPDMA_TIM17_DMA1_CH7)          == HAL_REMAPDMA_TIM17_DMA1_CH7)          || \
                              (((RMP) & HAL_REMAPDMA_TIM6_DAC1_CH1_DMA1_CH3)  == HAL_REMAPDMA_TIM6_DAC1_CH1_DMA1_CH3)  || \
                              (((RMP) & HAL_REMAPDMA_TIM7_DAC1_CH2_DMA1_CH4)  == HAL_REMAPDMA_TIM7_DAC1_CH2_DMA1_CH4)  || \
                              (((RMP) & HAL_REMAPDMA_DAC2_CH1_DMA1_CH5)       == HAL_REMAPDMA_DAC2_CH1_DMA1_CH5)       || \
                              (((RMP) & HAL_REMAPDMA_TIM18_DAC2_CH1_DMA1_CH5) == HAL_REMAPDMA_TIM18_DAC2_CH1_DMA1_CH5) || \
                              (((RMP) & HAL_REMAPDMA_SPI1_RX_DMA1_CH2)        == HAL_REMAPDMA_SPI1_RX_DMA1_CH2)  || \
                              (((RMP) & HAL_REMAPDMA_SPI1_RX_DMA1_CH4)        == HAL_REMAPDMA_SPI1_RX_DMA1_CH4)  || \
                              (((RMP) & HAL_REMAPDMA_SPI1_RX_DMA1_CH6)        == HAL_REMAPDMA_SPI1_RX_DMA1_CH6)  || \
                              (((RMP) & HAL_REMAPDMA_SPI1_TX_DMA1_CH3)        == HAL_REMAPDMA_SPI1_TX_DMA1_CH3)  || \
                              (((RMP) & HAL_REMAPDMA_SPI1_TX_DMA1_CH5)        == HAL_REMAPDMA_SPI1_TX_DMA1_CH5)  || \
                              (((RMP) & HAL_REMAPDMA_SPI1_TX_DMA1_CH7)        == HAL_REMAPDMA_SPI1_TX_DMA1_CH7)  || \
                              (((RMP) & HAL_REMAPDMA_I2C1_RX_DMA1_CH7)        == HAL_REMAPDMA_I2C1_RX_DMA1_CH7)  || \
                              (((RMP) & HAL_REMAPDMA_I2C1_RX_DMA1_CH3)        == HAL_REMAPDMA_I2C1_RX_DMA1_CH3)  || \
                              (((RMP) & HAL_REMAPDMA_I2C1_RX_DMA1_CH5)        == HAL_REMAPDMA_I2C1_RX_DMA1_CH5)  || \
                              (((RMP) & HAL_REMAPDMA_I2C1_TX_DMA1_CH6)        == HAL_REMAPDMA_I2C1_TX_DMA1_CH6)  || \
                              (((RMP) & HAL_REMAPDMA_I2C1_TX_DMA1_CH2)        == HAL_REMAPDMA_I2C1_TX_DMA1_CH2)  || \
                              (((RMP) & HAL_REMAPDMA_I2C1_TX_DMA1_CH4)        == HAL_REMAPDMA_I2C1_TX_DMA1_CH4)  || \
                              (((RMP) & HAL_REMAPDMA_ADC2_DMA1_CH2)           == HAL_REMAPDMA_ADC2_DMA1_CH2)     || \
                              (((RMP) & HAL_REMAPDMA_ADC2_DMA1_CH4)           == HAL_REMAPDMA_ADC2_DMA1_CH4))
#else
#define IS_DMA_REMAP(RMP) ((((RMP) & HAL_REMAPDMA_ADC24_DMA2_CH34)         == HAL_REMAPDMA_ADC24_DMA2_CH34)         || \
                              (((RMP) & HAL_REMAPDMA_TIM16_DMA1_CH6)          == HAL_REMAPDMA_TIM16_DMA1_CH6)          || \
                              (((RMP) & HAL_REMAPDMA_TIM17_DMA1_CH7)          == HAL_REMAPDMA_TIM17_DMA1_CH7)          || \
                              (((RMP) & HAL_REMAPDMA_TIM6_DAC1_CH1_DMA1_CH3)  == HAL_REMAPDMA_TIM6_DAC1_CH1_DMA1_CH3)  || \
                              (((RMP) & HAL_REMAPDMA_TIM7_DAC1_CH2_DMA1_CH4)  == HAL_REMAPDMA_TIM7_DAC1_CH2_DMA1_CH4)  || \
                              (((RMP) & HAL_REMAPDMA_DAC2_CH1_DMA1_CH5)       == HAL_REMAPDMA_DAC2_CH1_DMA1_CH5)       || \
                              (((RMP) & HAL_REMAPDMA_TIM18_DAC2_CH1_DMA1_CH5) == HAL_REMAPDMA_TIM18_DAC2_CH1_DMA1_CH5))
#endif



#endif









#define HAL_REMAPTRIGGER_DAC1_TRIG         (0x00000080U)


#define HAL_REMAPTRIGGER_TIM1_ITR3         (0x00000040U)


#if defined(SYSCFG_CFGR3_TRIGGER_RMP)
#if !defined(HAL_REMAP_CFGR3_MASK)
#define HAL_REMAP_CFGR3_MASK               (0x01000000U)
#endif
#define HAL_REMAPTRIGGER_DAC1_TRIG3        (0x01010000U)


#define HAL_REMAPTRIGGER_DAC1_TRIG5        (0x01020000U)


#define IS_HAL_REMAPTRIGGER(RMP) ((((RMP) & HAL_REMAPTRIGGER_DAC1)       == HAL_REMAPTRIGGER_DAC1)       || \
                                  (((RMP) & HAL_REMAPTRIGGER_TIM1_ITR3)  == HAL_REMAPTRIGGER_TIM1_ITR3)  || \
                                  (((RMP) & HAL_REMAPTRIGGER_DAC1_TRIG3) == HAL_REMAPTRIGGER_DAC1_TRIG3) || \
                                  (((RMP) & HAL_REMAPTRIGGER_DAC1_TRIG5) == HAL_REMAPTRIGGER_DAC1_TRIG5))
#else
#define IS_HAL_REMAPTRIGGER(RMP) ((((RMP) & HAL_REMAPTRIGGER_DAC1)       == HAL_REMAPTRIGGER_DAC1)       || \
                                  (((RMP) & HAL_REMAPTRIGGER_TIM1_ITR3)  == HAL_REMAPTRIGGER_TIM1_ITR3))
#endif




#if defined (STM32F302xE)



#define HAL_REMAPADCTRIGGER_ADC12_EXT2        SYSCFG_CFGR4_ADC12_EXT2_RMP


#define HAL_REMAPADCTRIGGER_ADC12_EXT3        SYSCFG_CFGR4_ADC12_EXT3_RMP


#define HAL_REMAPADCTRIGGER_ADC12_EXT5        SYSCFG_CFGR4_ADC12_EXT5_RMP


#define HAL_REMAPADCTRIGGER_ADC12_EXT13       SYSCFG_CFGR4_ADC12_EXT13_RMP


#define HAL_REMAPADCTRIGGER_ADC12_EXT15       SYSCFG_CFGR4_ADC12_EXT15_RMP


#define HAL_REMAPADCTRIGGER_ADC12_JEXT3       SYSCFG_CFGR4_ADC12_JEXT3_RMP


#define HAL_REMAPADCTRIGGER_ADC12_JEXT6       SYSCFG_CFGR4_ADC12_JEXT6_RMP


#define HAL_REMAPADCTRIGGER_ADC12_JEXT13      SYSCFG_CFGR4_ADC12_JEXT13_RMP



#define IS_HAL_REMAPADCTRIGGER(RMP)  ((((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT2)   == HAL_REMAPADCTRIGGER_ADC12_EXT2)   || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT3)   == HAL_REMAPADCTRIGGER_ADC12_EXT3)   || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT5)   == HAL_REMAPADCTRIGGER_ADC12_EXT5)   || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT13)  == HAL_REMAPADCTRIGGER_ADC12_EXT13)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT15)  == HAL_REMAPADCTRIGGER_ADC12_EXT15)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_JEXT3)  == HAL_REMAPADCTRIGGER_ADC12_JEXT3)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_JEXT6)  == HAL_REMAPADCTRIGGER_ADC12_JEXT6)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_JEXT13) == HAL_REMAPADCTRIGGER_ADC12_JEXT13))



#endif

#if defined (STM32F303xE) || defined (STM32F398xx)



#define HAL_REMAPADCTRIGGER_ADC12_EXT2        SYSCFG_CFGR4_ADC12_EXT2_RMP


#define HAL_REMAPADCTRIGGER_ADC12_EXT3        SYSCFG_CFGR4_ADC12_EXT3_RMP


#define HAL_REMAPADCTRIGGER_ADC12_EXT5        SYSCFG_CFGR4_ADC12_EXT5_RMP


#define HAL_REMAPADCTRIGGER_ADC12_EXT13       SYSCFG_CFGR4_ADC12_EXT13_RMP


#define HAL_REMAPADCTRIGGER_ADC12_EXT15       SYSCFG_CFGR4_ADC12_EXT15_RMP


#define HAL_REMAPADCTRIGGER_ADC12_JEXT3       SYSCFG_CFGR4_ADC12_JEXT3_RMP


#define HAL_REMAPADCTRIGGER_ADC12_JEXT6       SYSCFG_CFGR4_ADC12_JEXT6_RMP


#define HAL_REMAPADCTRIGGER_ADC12_JEXT13      SYSCFG_CFGR4_ADC12_JEXT13_RMP


#define HAL_REMAPADCTRIGGER_ADC34_EXT5        SYSCFG_CFGR4_ADC34_EXT5_RMP


#define HAL_REMAPADCTRIGGER_ADC34_EXT6        SYSCFG_CFGR4_ADC34_EXT6_RMP


#define HAL_REMAPADCTRIGGER_ADC34_EXT15       SYSCFG_CFGR4_ADC34_EXT15_RMP


#define HAL_REMAPADCTRIGGER_ADC34_JEXT5       SYSCFG_CFGR4_ADC34_JEXT5_RMP


#define HAL_REMAPADCTRIGGER_ADC34_JEXT11      SYSCFG_CFGR4_ADC34_JEXT11_RMP


#define HAL_REMAPADCTRIGGER_ADC34_JEXT14      SYSCFG_CFGR4_ADC34_JEXT14_RMP



#define IS_HAL_REMAPADCTRIGGER(RMP)  ((((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT2)   == HAL_REMAPADCTRIGGER_ADC12_EXT2)   || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT3)   == HAL_REMAPADCTRIGGER_ADC12_EXT3)   || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT5)   == HAL_REMAPADCTRIGGER_ADC12_EXT5)   || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT13)  == HAL_REMAPADCTRIGGER_ADC12_EXT13)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_EXT15)  == HAL_REMAPADCTRIGGER_ADC12_EXT15)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_JEXT3)  == HAL_REMAPADCTRIGGER_ADC12_JEXT3)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_JEXT6)  == HAL_REMAPADCTRIGGER_ADC12_JEXT6)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC12_JEXT13) == HAL_REMAPADCTRIGGER_ADC12_JEXT13) || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC34_EXT5)   == HAL_REMAPADCTRIGGER_ADC34_EXT5)   || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC34_EXT6)   == HAL_REMAPADCTRIGGER_ADC34_EXT6)   || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC34_EXT15)  == HAL_REMAPADCTRIGGER_ADC34_EXT15)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC34_JEXT5)  == HAL_REMAPADCTRIGGER_ADC34_JEXT5)  || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC34_JEXT11) == HAL_REMAPADCTRIGGER_ADC34_JEXT11) || \
                                      (((RMP) & HAL_REMAPADCTRIGGER_ADC34_JEXT14) == HAL_REMAPADCTRIGGER_ADC34_JEXT14))



#endif







#if defined(SYSCFG_CFGR1_I2C_PB6_FMP)
#define SYSCFG_FASTMODEPLUS_PB6    ((uint32_t)SYSCFG_CFGR1_I2C_PB6_FMP)
#endif

#if defined(SYSCFG_CFGR1_I2C_PB7_FMP)
#define SYSCFG_FASTMODEPLUS_PB7    ((uint32_t)SYSCFG_CFGR1_I2C_PB7_FMP)
#endif

#if defined(SYSCFG_CFGR1_I2C_PB8_FMP)
#define SYSCFG_FASTMODEPLUS_PB8    ((uint32_t)SYSCFG_CFGR1_I2C_PB8_FMP)
#endif

#if defined(SYSCFG_CFGR1_I2C_PB9_FMP)
#define SYSCFG_FASTMODEPLUS_PB9    ((uint32_t)SYSCFG_CFGR1_I2C_PB9_FMP)
#endif




#if defined(SYSCFG_RCR_PAGE0)




#define HAL_SYSCFG_WP_PAGE0                    (SYSCFG_RCR_PAGE0)
#define HAL_SYSCFG_WP_PAGE1                    (SYSCFG_RCR_PAGE1)
#define HAL_SYSCFG_WP_PAGE2                    (SYSCFG_RCR_PAGE2)
#define HAL_SYSCFG_WP_PAGE3                    (SYSCFG_RCR_PAGE3)
#if defined(SYSCFG_RCR_PAGE4)

#define HAL_SYSCFG_WP_PAGE4                    (SYSCFG_RCR_PAGE4)
#define HAL_SYSCFG_WP_PAGE5                    (SYSCFG_RCR_PAGE5)
#define HAL_SYSCFG_WP_PAGE6                    (SYSCFG_RCR_PAGE6)
#define HAL_SYSCFG_WP_PAGE7                    (SYSCFG_RCR_PAGE7)
#endif
#if defined(SYSCFG_RCR_PAGE8)
#define HAL_SYSCFG_WP_PAGE8                    (SYSCFG_RCR_PAGE8)
#define HAL_SYSCFG_WP_PAGE9                    (SYSCFG_RCR_PAGE9)
#define HAL_SYSCFG_WP_PAGE10                   (SYSCFG_RCR_PAGE10)
#define HAL_SYSCFG_WP_PAGE11                   (SYSCFG_RCR_PAGE11)
#define HAL_SYSCFG_WP_PAGE12                   (SYSCFG_RCR_PAGE12)
#define HAL_SYSCFG_WP_PAGE13                   (SYSCFG_RCR_PAGE13)
#define HAL_SYSCFG_WP_PAGE14                   (SYSCFG_RCR_PAGE14)
#define HAL_SYSCFG_WP_PAGE15                   (SYSCFG_RCR_PAGE15)
#endif

#if defined(SYSCFG_RCR_PAGE8)
#define IS_HAL_SYSCFG_WP_PAGE(__PAGE__)        (((__PAGE__) > 0U) && ((__PAGE__) <= 0xFFFFU))
#elif defined(SYSCFG_RCR_PAGE4)
#define IS_HAL_SYSCFG_WP_PAGE(__PAGE__)        (((__PAGE__) > 0U) && ((__PAGE__) <= 0x00FFU))
#else
#define IS_HAL_SYSCFG_WP_PAGE(__PAGE__)        (((__PAGE__) > 0U) && ((__PAGE__) <= 0x000FU))
#endif



#endif




#define HAL_SYSCFG_IT_FPU_IOC                  (SYSCFG_CFGR1_FPU_IE_0)
#define HAL_SYSCFG_IT_FPU_DZC                  (SYSCFG_CFGR1_FPU_IE_1)
#define HAL_SYSCFG_IT_FPU_UFC                  (SYSCFG_CFGR1_FPU_IE_2)
#define HAL_SYSCFG_IT_FPU_OFC                  (SYSCFG_CFGR1_FPU_IE_3)
#define HAL_SYSCFG_IT_FPU_IDC                  (SYSCFG_CFGR1_FPU_IE_4)
#define HAL_SYSCFG_IT_FPU_IXC                  (SYSCFG_CFGR1_FPU_IE_5)

#define IS_HAL_SYSCFG_INTERRUPT(__INTERRUPT__) ((((__INTERRUPT__) & SYSCFG_CFGR1_FPU_IE_0) == SYSCFG_CFGR1_FPU_IE_0) || \
                                                (((__INTERRUPT__) & SYSCFG_CFGR1_FPU_IE_1) == SYSCFG_CFGR1_FPU_IE_1) || \
                                                (((__INTERRUPT__) & SYSCFG_CFGR1_FPU_IE_2) == SYSCFG_CFGR1_FPU_IE_2) || \
                                                (((__INTERRUPT__) & SYSCFG_CFGR1_FPU_IE_3) == SYSCFG_CFGR1_FPU_IE_3) || \
                                                (((__INTERRUPT__) & SYSCFG_CFGR1_FPU_IE_4) == SYSCFG_CFGR1_FPU_IE_4) || \
                                                (((__INTERRUPT__) & SYSCFG_CFGR1_FPU_IE_5) == SYSCFG_CFGR1_FPU_IE_5))

















#if defined(DBGMCU_APB1_FZ_DBG_TIM2_STOP)
#define __HAL_DBGMCU_FREEZE_TIM2()           (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM2_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM2()         (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM2_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM3_STOP)
#define __HAL_DBGMCU_FREEZE_TIM3()           (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM3_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM3()         (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM3_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM4_STOP)
#define __HAL_DBGMCU_FREEZE_TIM4()           (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM4_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM4()         (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM4_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM5_STOP)
#define __HAL_DBGMCU_FREEZE_TIM5()           (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM5_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM5()         (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM5_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM6_STOP)
#define __HAL_DBGMCU_FREEZE_TIM6()           (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM6_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM6()         (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM6_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM7_STOP)
#define __HAL_DBGMCU_FREEZE_TIM7()           (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM7_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM7()         (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM7_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM12_STOP)
#define __HAL_DBGMCU_FREEZE_TIM12()          (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM12_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM12()        (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM12_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM13_STOP)
#define __HAL_DBGMCU_FREEZE_TIM13()          (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM13_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM13()        (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM13_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM14_STOP)
#define __HAL_DBGMCU_FREEZE_TIM14()          (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM14_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM14()        (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM14_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_TIM18_STOP)
#define __HAL_FREEZE_TIM18_DBGMCU()          (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_TIM18_STOP))
#define __HAL_UNFREEZE_TIM18_DBGMCU()        (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_TIM18_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_RTC_STOP)
#define __HAL_DBGMCU_FREEZE_RTC()            (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_RTC_STOP))
#define __HAL_DBGMCU_UNFREEZE_RTC()          (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_RTC_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_WWDG_STOP)
#define __HAL_DBGMCU_FREEZE_WWDG()           (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_WWDG_STOP))
#define __HAL_DBGMCU_UNFREEZE_WWDG()         (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_WWDG_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_IWDG_STOP)
#define __HAL_DBGMCU_FREEZE_IWDG()           (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_IWDG_STOP))
#define __HAL_DBGMCU_UNFREEZE_IWDG()         (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_IWDG_STOP))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT()   (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT))
#define __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT() (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT()   (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT))
#define __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT() (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_FREEZE_I2C3_TIMEOUT()   (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT))
#define __HAL_DBGMCU_UNFREEZE_I2C3_TIMEOUT() (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT))
#endif

#if defined(DBGMCU_APB1_FZ_DBG_CAN_STOP)
#define __HAL_FREEZE_CAN_DBGMCU()            (DBGMCU->APB1FZ |= (DBGMCU_APB1_FZ_DBG_CAN_STOP))
#define __HAL_UNFREEZE_CAN_DBGMCU()          (DBGMCU->APB1FZ &= ~(DBGMCU_APB1_FZ_DBG_CAN_STOP))
#endif







#if defined(DBGMCU_APB2_FZ_DBG_TIM1_STOP)
#define __HAL_DBGMCU_FREEZE_TIM1()           (DBGMCU->APB2FZ |= (DBGMCU_APB2_FZ_DBG_TIM1_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM1()           (DBGMCU->APB2FZ &= ~(DBGMCU_APB2_FZ_DBG_TIM1_STOP))
#endif

#if defined(DBGMCU_APB2_FZ_DBG_TIM8_STOP)
#define __HAL_DBGMCU_FREEZE_TIM8()           (DBGMCU->APB2FZ |= (DBGMCU_APB2_FZ_DBG_TIM8_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM8()         (DBGMCU->APB2FZ &= ~(DBGMCU_APB2_FZ_DBG_TIM8_STOP))
#endif

#if defined(DBGMCU_APB2_FZ_DBG_TIM15_STOP)
#define __HAL_DBGMCU_FREEZE_TIM15()          (DBGMCU->APB2FZ |= (DBGMCU_APB2_FZ_DBG_TIM15_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM15()        (DBGMCU->APB2FZ &= ~(DBGMCU_APB2_FZ_DBG_TIM15_STOP))
#endif

#if defined(DBGMCU_APB2_FZ_DBG_TIM16_STOP)
#define __HAL_DBGMCU_FREEZE_TIM16()          (DBGMCU->APB2FZ |= (DBGMCU_APB2_FZ_DBG_TIM16_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM16()        (DBGMCU->APB2FZ &= ~(DBGMCU_APB2_FZ_DBG_TIM16_STOP))
#endif

#if defined(DBGMCU_APB2_FZ_DBG_TIM17_STOP)
#define __HAL_DBGMCU_FREEZE_TIM17()          (DBGMCU->APB2FZ |= (DBGMCU_APB2_FZ_DBG_TIM17_STOP))
#define __HAL_DBGMCU_UNFREEZE_TIM17()        (DBGMCU->APB2FZ &= ~(DBGMCU_APB2_FZ_DBG_TIM17_STOP))
#endif

#if defined(DBGMCU_APB2_FZ_DBG_TIM19_STOP)
#define __HAL_FREEZE_TIM19_DBGMCU()          (DBGMCU->APB2FZ |= (DBGMCU_APB2_FZ_DBG_TIM19_STOP))
#define __HAL_UNFREEZE_TIM19_DBGMCU()        (DBGMCU->APB2FZ &= ~(DBGMCU_APB2_FZ_DBG_TIM19_STOP))
#endif

#if defined(DBGMCU_APB2_FZ_DBG_TIM20_STOP)
#define __HAL_FREEZE_TIM20_DBGMCU()          (DBGMCU->APB2FZ |= (DBGMCU_APB2_FZ_DBG_TIM20_STOP))
#define __HAL_UNFREEZE_TIM20_DBGMCU()        (DBGMCU->APB2FZ &= ~(DBGMCU_APB2_FZ_DBG_TIM20_STOP))
#endif

#if defined(DBGMCU_APB2_FZ_DBG_HRTIM1_STOP)
#define __HAL_FREEZE_HRTIM1_DBGMCU()          (DBGMCU->APB2FZ |= (DBGMCU_APB2_FZ_DBG_HRTIM1_STOP))
#define __HAL_UNFREEZE_HRTIM1_DBGMCU()        (DBGMCU->APB2FZ &= ~(DBGMCU_APB2_FZ_DBG_HRTIM1_STOP))
#endif







#if defined(SYSCFG_CFGR1_MEM_MODE)


#define __HAL_SYSCFG_REMAPMEMORY_FLASH()        (SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_MEM_MODE))
#endif

#if defined(SYSCFG_CFGR1_MEM_MODE_0)


#define __HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH()  do {SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_MEM_MODE); \
                                             SYSCFG->CFGR1 |= SYSCFG_CFGR1_MEM_MODE_0;  \
                                            }while(0U)
#endif

#if defined(SYSCFG_CFGR1_MEM_MODE_0) && defined(SYSCFG_CFGR1_MEM_MODE_1)


#define __HAL_SYSCFG_REMAPMEMORY_SRAM()         do {SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_MEM_MODE); \
                                             SYSCFG->CFGR1 |= (SYSCFG_CFGR1_MEM_MODE_0 | SYSCFG_CFGR1_MEM_MODE_1); \
                                            }while(0U)
#endif

#if defined(SYSCFG_CFGR1_MEM_MODE_2)
#define __HAL_SYSCFG_FMC_BANK()         do {SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_MEM_MODE); \
                                     SYSCFG->CFGR1 |= (SYSCFG_CFGR1_MEM_MODE_2); \
                                    }while(0U)
#endif







#if defined(SYSCFG_CFGR1_ENCODER_MODE)


#define __HAL_REMAPENCODER_NONE()        (SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_ENCODER_MODE))
#endif

#if defined(SYSCFG_CFGR1_ENCODER_MODE_0)


#define __HAL_REMAPENCODER_TIM2()        do {SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_ENCODER_MODE); \
                                             SYSCFG->CFGR1 |= SYSCFG_CFGR1_ENCODER_MODE_0;  \
                                            }while(0U)
#endif

#if defined(SYSCFG_CFGR1_ENCODER_MODE_1)


#define __HAL_REMAPENCODER_TIM3()        do {SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_ENCODER_MODE); \
                                             SYSCFG->CFGR1 |= SYSCFG_CFGR1_ENCODER_MODE_1;  \
                                            }while(0U)
#endif

#if defined(SYSCFG_CFGR1_ENCODER_MODE_0) && defined(SYSCFG_CFGR1_ENCODER_MODE_1)


#define __HAL_REMAPENCODER_TIM4()        do {SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_ENCODER_MODE); \
                                             SYSCFG->CFGR1 |= (SYSCFG_CFGR1_ENCODER_MODE_0 | SYSCFG_CFGR1_ENCODER_MODE_1);  \
                                            }while(0U)
#endif







#if defined(SYSCFG_CFGR3_DMA_RMP) && defined(SYSCFG_CFGR1_DMA_RMP)



#define __HAL_DMA_REMAP_CHANNEL_ENABLE(__DMA_REMAP__)   do {assert_param(IS_DMA_REMAP((__DMA_REMAP__)));                  \
                                                           (((__DMA_REMAP__) & HAL_REMAP_CFGR3_MASK) ?                      \
                                                             (SYSCFG->CFGR3 |= ((__DMA_REMAP__) & ~HAL_REMAP_CFGR3_MASK)) : \
                                                             (SYSCFG->CFGR1 |= (__DMA_REMAP__)));                           \
                                                         }while(0U)
#define __HAL_DMA_REMAP_CHANNEL_DISABLE(__DMA_REMAP__)  do {assert_param(IS_DMA_REMAP((__DMA_REMAP__)));                  \
                                                           (((__DMA_REMAP__) & HAL_REMAP_CFGR3_MASK) ?                      \
                                                             (SYSCFG->CFGR3 &= (~(__DMA_REMAP__) | HAL_REMAP_CFGR3_MASK)) : \
                                                             (SYSCFG->CFGR1 &= ~(__DMA_REMAP__)));                          \
                                                         }while(0U)
#elif defined(SYSCFG_CFGR1_DMA_RMP)



#define __HAL_DMA_REMAP_CHANNEL_ENABLE(__DMA_REMAP__)   do {assert_param(IS_DMA_REMAP((__DMA_REMAP__)));                  \
                                                           SYSCFG->CFGR1 |= (__DMA_REMAP__);                                \
                                                         }while(0U)
#define __HAL_DMA_REMAP_CHANNEL_DISABLE(__DMA_REMAP__)  do {assert_param(IS_DMA_REMAP((__DMA_REMAP__)));                  \
                                                           SYSCFG->CFGR1 &= ~(__DMA_REMAP__);                               \
                                                         }while(0U)
#endif











#define __HAL_SYSCFG_FASTMODEPLUS_ENABLE(__FASTMODEPLUS__)  do {assert_param(IS_SYSCFG_FASTMODEPLUS((__FASTMODEPLUS__)));\
                                                                SET_BIT(SYSCFG->CFGR1, (__FASTMODEPLUS__));\
                                                               }while(0U)

#define __HAL_SYSCFG_FASTMODEPLUS_DISABLE(__FASTMODEPLUS__) do {assert_param(IS_SYSCFG_FASTMODEPLUS((__FASTMODEPLUS__)));\
                                                                CLEAR_BIT(SYSCFG->CFGR1, (__FASTMODEPLUS__));\
                                                               }while(0U)










#define __HAL_SYSCFG_INTERRUPT_ENABLE(__INTERRUPT__)        do {assert_param(IS_HAL_SYSCFG_INTERRUPT((__INTERRUPT__))); \
                                                                SYSCFG->CFGR1 |= (__INTERRUPT__);                       \
                                                               }while(0U)

#define __HAL_SYSCFG_INTERRUPT_DISABLE(__INTERRUPT__)       do {assert_param(IS_HAL_SYSCFG_INTERRUPT((__INTERRUPT__))); \
                                                                SYSCFG->CFGR1 &= ~(__INTERRUPT__);                      \
                                                               }while(0U)




#if defined(SYSCFG_CFGR1_USB_IT_RMP)





#define __HAL_REMAPINTERRUPT_USB_ENABLE()              (SYSCFG->CFGR1 |= (SYSCFG_CFGR1_USB_IT_RMP))
#define __HAL_REMAPINTERRUPT_USB_DISABLE()             (SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_USB_IT_RMP))



#endif

#if defined(SYSCFG_CFGR1_VBAT)





#define __HAL_SYSCFG_VBAT_MONITORING_ENABLE()          (SYSCFG->CFGR1 |= (SYSCFG_CFGR1_VBAT))
#define __HAL_SYSCFG_VBAT_MONITORING_DISABLE()         (SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_VBAT))



#endif

#if defined(SYSCFG_CFGR2_LOCKUP_LOCK)







#define __HAL_SYSCFG_BREAK_LOCKUP_LOCK()   do {SYSCFG->CFGR2 &= ~(SYSCFG_CFGR2_LOCKUP_LOCK); \
                                               SYSCFG->CFGR2 |= SYSCFG_CFGR2_LOCKUP_LOCK;    \
                                              }while(0U)



#endif

#if defined(SYSCFG_CFGR2_PVD_LOCK)







#define __HAL_SYSCFG_BREAK_PVD_LOCK()      do {SYSCFG->CFGR2 &= ~(SYSCFG_CFGR2_PVD_LOCK); \
                                               SYSCFG->CFGR2 |= SYSCFG_CFGR2_PVD_LOCK;    \
                                              }while(0U)



#endif

#if defined(SYSCFG_CFGR2_SRAM_PARITY_LOCK)







#define __HAL_SYSCFG_BREAK_SRAMPARITY_LOCK() do {SYSCFG->CFGR2 &= ~(SYSCFG_CFGR2_SRAM_PARITY_LOCK); \
                                                 SYSCFG->CFGR2 |= SYSCFG_CFGR2_SRAM_PARITY_LOCK;    \
                                                }while(0U)



#endif




#if defined(SYSCFG_CFGR3_TRIGGER_RMP)



#define __HAL_REMAPTRIGGER_ENABLE(__TRIGGER_REMAP__)   do {assert_param(IS_HAL_REMAPTRIGGER((__TRIGGER_REMAP__)));             \
                                                           (((__TRIGGER_REMAP__) & HAL_REMAP_CFGR3_MASK) ?                     \
                                                             (SYSCFG->CFGR3 |= ((__TRIGGER_REMAP__) & ~HAL_REMAP_CFGR3_MASK)) : \
                                                             (SYSCFG->CFGR1 |= (__TRIGGER_REMAP__)));                           \
                                                         }while(0U)
#define __HAL_REMAPTRIGGER_DISABLE(__TRIGGER_REMAP__)  do {assert_param(IS_HAL_REMAPTRIGGER((__TRIGGER_REMAP__)));             \
                                                           (((__TRIGGER_REMAP__) & HAL_REMAP_CFGR3_MASK) ?                     \
                                                             (SYSCFG->CFGR3 &= (~(__TRIGGER_REMAP__) | HAL_REMAP_CFGR3_MASK)) : \
                                                             (SYSCFG->CFGR1 &= ~(__TRIGGER_REMAP__)));                          \
                                                         }while(0U)
#else



#define __HAL_REMAPTRIGGER_ENABLE(__TRIGGER_REMAP__)   do {assert_param(IS_HAL_REMAPTRIGGER((__TRIGGER_REMAP__)));             \
                                                           (SYSCFG->CFGR1 |= (__TRIGGER_REMAP__));                           \
                                                         }while(0U)
#define __HAL_REMAPTRIGGER_DISABLE(__TRIGGER_REMAP__)  do {assert_param(IS_HAL_REMAPTRIGGER((__TRIGGER_REMAP__)));             \
                                                           (SYSCFG->CFGR1 &= ~(__TRIGGER_REMAP__));                          \
                                                         }while(0U)
#endif




#if defined (STM32F302xE) || defined (STM32F303xE) || defined (STM32F398xx)






#define __HAL_REMAPADCTRIGGER_ENABLE(__ADCTRIGGER_REMAP__)   do {assert_param(IS_HAL_REMAPADCTRIGGER((__ADCTRIGGER_REMAP__)));   \
                                                             (SYSCFG->CFGR4 |= (__ADCTRIGGER_REMAP__));                          \
                                                         }while(0U)
#define __HAL_REMAPADCTRIGGER_DISABLE(__ADCTRIGGER_REMAP__)  do {assert_param(IS_HAL_REMAPADCTRIGGER((__ADCTRIGGER_REMAP__)));   \
                                                             (SYSCFG->CFGR4 &= ~(__ADCTRIGGER_REMAP__));                         \
                                                         }while(0U)



#endif

#if defined(SYSCFG_CFGR2_BYP_ADDR_PAR)








#define __HAL_SYSCFG_RAM_PARITYCHECK_DISABLE()         (*(__IO uint32_t *) CFGR2_BYPADDRPAR_BB = 0x00000001U)



#endif

#if defined(SYSCFG_RCR_PAGE0)







#define __HAL_SYSCFG_SRAM_WRP_ENABLE(__PAGE_WP__)      do {assert_param(IS_HAL_SYSCFG_WP_PAGE((__PAGE_WP__))); \
                                                           SYSCFG->RCR |= (__PAGE_WP__);                       \
                                                          }while(0U)



#endif








#define IS_TICKFREQ(FREQ) (((FREQ) == HAL_TICK_FREQ_10HZ)  || \
                           ((FREQ) == HAL_TICK_FREQ_100HZ) || \
                           ((FREQ) == HAL_TICK_FREQ_1KHZ))













HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick (uint32_t TickPriority);








extern __IO uint32_t uwTick;
extern uint32_t uwTickPrio;
extern HAL_TickFreqTypeDef uwTickFreq;









void     HAL_IncTick(void);
void     HAL_Delay(uint32_t Delay);
void     HAL_SuspendTick(void);
void     HAL_ResumeTick(void);
uint32_t HAL_GetTick(void);
uint32_t HAL_GetTickPrio(void);
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
uint32_t HAL_GetHalVersion(void);
uint32_t HAL_GetREVID(void);
uint32_t HAL_GetDEVID(void);
uint32_t HAL_GetUIDw0(void);
uint32_t HAL_GetUIDw1(void);
uint32_t HAL_GetUIDw2(void);
void     HAL_DBGMCU_EnableDBGSleepMode(void);
void     HAL_DBGMCU_DisableDBGSleepMode(void);
void     HAL_DBGMCU_EnableDBGStopMode(void);
void     HAL_DBGMCU_DisableDBGStopMode(void);
void     HAL_DBGMCU_EnableDBGStandbyMode(void);
void     HAL_DBGMCU_DisableDBGStandbyMode(void);
















#ifdef __cplusplus
}
#endif

#endif


