



































#ifndef __STM32F3xx_HAL_RCC_H
#define __STM32F3xx_HAL_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"


















#define RCC_DBP_TIMEOUT_VALUE      (100U)

#define RCC_LSE_TIMEOUT_VALUE      LSE_STARTUP_TIMEOUT
#define CLOCKSWITCH_TIMEOUT_VALUE  (5000U)
#define HSE_TIMEOUT_VALUE          HSE_STARTUP_TIMEOUT
#define HSI_TIMEOUT_VALUE          (2U)
#define LSI_TIMEOUT_VALUE          (2U)
#define PLL_TIMEOUT_VALUE          (2U)







#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE)
#define RCC_CR_OFFSET             0x00
#define RCC_CFGR_OFFSET           0x04
#define RCC_CIR_OFFSET            0x08
#define RCC_BDCR_OFFSET           0x20
#define RCC_CSR_OFFSET            0x24









#define RCC_CR_OFFSET_BB          (RCC_OFFSET + RCC_CR_OFFSET)
#define RCC_CFGR_OFFSET_BB        (RCC_OFFSET + RCC_CFGR_OFFSET)
#define RCC_CIR_OFFSET_BB         (RCC_OFFSET + RCC_CIR_OFFSET)
#define RCC_BDCR_OFFSET_BB        (RCC_OFFSET + RCC_BDCR_OFFSET)
#define RCC_CSR_OFFSET_BB         (RCC_OFFSET + RCC_CSR_OFFSET)



#define RCC_HSION_BIT_NUMBER      POSITION_VAL(RCC_CR_HSION)
#define RCC_CR_HSION_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSION_BIT_NUMBER * 4U)))

#define RCC_HSEON_BIT_NUMBER      POSITION_VAL(RCC_CR_HSEON)
#define RCC_CR_HSEON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSEON_BIT_NUMBER * 4U)))

#define RCC_CSSON_BIT_NUMBER      POSITION_VAL(RCC_CR_CSSON)
#define RCC_CR_CSSON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_CSSON_BIT_NUMBER * 4U)))

#define RCC_PLLON_BIT_NUMBER      POSITION_VAL(RCC_CR_PLLON)
#define RCC_CR_PLLON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_PLLON_BIT_NUMBER * 4U)))



#define RCC_LSION_BIT_NUMBER      POSITION_VAL(RCC_CSR_LSION)
#define RCC_CSR_LSION_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_LSION_BIT_NUMBER * 4U)))


#define RCC_RMVF_BIT_NUMBER       POSITION_VAL(RCC_CSR_RMVF)
#define RCC_CSR_RMVF_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_RMVF_BIT_NUMBER * 4U)))



#define RCC_LSEON_BIT_NUMBER      POSITION_VAL(RCC_BDCR_LSEON)
#define RCC_BDCR_LSEON_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEON_BIT_NUMBER * 4U)))


#define RCC_LSEBYP_BIT_NUMBER     POSITION_VAL(RCC_BDCR_LSEBYP)
#define RCC_BDCR_LSEBYP_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEBYP_BIT_NUMBER * 4U)))


#define RCC_RTCEN_BIT_NUMBER      POSITION_VAL(RCC_BDCR_RTCEN)
#define RCC_BDCR_RTCEN_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_RTCEN_BIT_NUMBER * 4U)))


#define RCC_BDRST_BIT_NUMBER          POSITION_VAL(RCC_BDCR_BDRST)
#define RCC_BDCR_BDRST_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_BDRST_BIT_NUMBER * 4U)))






#define RCC_CR_BYTE2_ADDRESS          ((uint32_t)(RCC_BASE + RCC_CR_OFFSET + 0x02U))


#define RCC_CIR_BYTE1_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x01U))


#define RCC_CIR_BYTE2_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x02U))


#define CR_REG_INDEX                     ((uint8_t)1U)
#define BDCR_REG_INDEX                   ((uint8_t)2U)
#define CSR_REG_INDEX                    ((uint8_t)3U)
#define CFGR_REG_INDEX                   ((uint8_t)4U)

#define RCC_FLAG_MASK                    ((uint8_t)0x1FU)








#define IS_RCC_PLLSOURCE(__SOURCE__) (((__SOURCE__) == RCC_PLLSOURCE_HSI) || \
                                      ((__SOURCE__) == RCC_PLLSOURCE_HSE))
#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__) (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE)                           || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE))
#define IS_RCC_HSE(__HSE__) (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON) || \
                             ((__HSE__) == RCC_HSE_BYPASS))
#define IS_RCC_LSE(__LSE__) (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON) || \
                             ((__LSE__) == RCC_LSE_BYPASS))
#define IS_RCC_HSI(__HSI__) (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON))
#define IS_RCC_CALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= 0x1FU)
#define IS_RCC_LSI(__LSI__) (((__LSI__) == RCC_LSI_OFF) || ((__LSI__) == RCC_LSI_ON))
#define IS_RCC_PLL(__PLL__) (((__PLL__) == RCC_PLL_NONE) || ((__PLL__) == RCC_PLL_OFF) || \
                             ((__PLL__) == RCC_PLL_ON))
#if   defined(RCC_CFGR_PLLSRC_HSI_PREDIV)
#define IS_RCC_PREDIV(__PREDIV__) (((__PREDIV__) == RCC_PREDIV_DIV1)  || ((__PREDIV__) == RCC_PREDIV_DIV2)   || \
                                  ((__PREDIV__) == RCC_PREDIV_DIV3)  || ((__PREDIV__) == RCC_PREDIV_DIV4)   || \
                                  ((__PREDIV__) == RCC_PREDIV_DIV5)  || ((__PREDIV__) == RCC_PREDIV_DIV6)   || \
                                  ((__PREDIV__) == RCC_PREDIV_DIV7)  || ((__PREDIV__) == RCC_PREDIV_DIV8)   || \
                                  ((__PREDIV__) == RCC_PREDIV_DIV9)  || ((__PREDIV__) == RCC_PREDIV_DIV10)  || \
                                  ((__PREDIV__) == RCC_PREDIV_DIV11) || ((__PREDIV__) == RCC_PREDIV_DIV12)  || \
                                  ((__PREDIV__) == RCC_PREDIV_DIV13) || ((__PREDIV__) == RCC_PREDIV_DIV14)  || \
                                  ((__PREDIV__) == RCC_PREDIV_DIV15) || ((__PREDIV__) == RCC_PREDIV_DIV16))
#else
#define IS_RCC_PLL_DIV(__DIV__) (((__DIV__) == RCC_PLL_DIV2) || \
                                 ((__DIV__) == RCC_PLL_DIV3) || ((__DIV__) == RCC_PLL_DIV4))
#endif
#if defined(RCC_CFGR_PLLSRC_HSI_DIV2)
#define IS_RCC_HSE_PREDIV(DIV) (((DIV) == RCC_HSE_PREDIV_DIV1)  || ((DIV) == RCC_HSE_PREDIV_DIV2)  || \
                                ((DIV) == RCC_HSE_PREDIV_DIV3)  || ((DIV) == RCC_HSE_PREDIV_DIV4)  || \
                                ((DIV) == RCC_HSE_PREDIV_DIV5)  || ((DIV) == RCC_HSE_PREDIV_DIV6)  || \
                                ((DIV) == RCC_HSE_PREDIV_DIV7)  || ((DIV) == RCC_HSE_PREDIV_DIV8)  || \
                                ((DIV) == RCC_HSE_PREDIV_DIV9)  || ((DIV) == RCC_HSE_PREDIV_DIV10) || \
                                ((DIV) == RCC_HSE_PREDIV_DIV11) || ((DIV) == RCC_HSE_PREDIV_DIV12) || \
                                ((DIV) == RCC_HSE_PREDIV_DIV13) || ((DIV) == RCC_HSE_PREDIV_DIV14) || \
                                ((DIV) == RCC_HSE_PREDIV_DIV15) || ((DIV) == RCC_HSE_PREDIV_DIV16))
#endif

#define IS_RCC_PLL_MUL(__MUL__) (((__MUL__) == RCC_PLL_MUL2)  || ((__MUL__) == RCC_PLL_MUL3)   || \
                                 ((__MUL__) == RCC_PLL_MUL4)  || ((__MUL__) == RCC_PLL_MUL5)   || \
                                 ((__MUL__) == RCC_PLL_MUL6)  || ((__MUL__) == RCC_PLL_MUL7)   || \
                                 ((__MUL__) == RCC_PLL_MUL8)  || ((__MUL__) == RCC_PLL_MUL9)   || \
                                 ((__MUL__) == RCC_PLL_MUL10) || ((__MUL__) == RCC_PLL_MUL11)  || \
                                 ((__MUL__) == RCC_PLL_MUL12) || ((__MUL__) == RCC_PLL_MUL13)  || \
                                 ((__MUL__) == RCC_PLL_MUL14) || ((__MUL__) == RCC_PLL_MUL15)  || \
                                 ((__MUL__) == RCC_PLL_MUL16))
#define IS_RCC_CLOCKTYPE(CLK) ((((CLK) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK) || \
                               (((CLK) & RCC_CLOCKTYPE_HCLK)   == RCC_CLOCKTYPE_HCLK)   || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK1)  == RCC_CLOCKTYPE_PCLK1)  || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK2)  == RCC_CLOCKTYPE_PCLK2))
#define IS_RCC_SYSCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_HSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSE) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_PLLCLK))
#define IS_RCC_SYSCLKSOURCE_STATUS(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSI) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSE) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_PLLCLK))
#define IS_RCC_HCLK(__HCLK__) (((__HCLK__) == RCC_SYSCLK_DIV1) || ((__HCLK__) == RCC_SYSCLK_DIV2) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV4) || ((__HCLK__) == RCC_SYSCLK_DIV8) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV16) || ((__HCLK__) == RCC_SYSCLK_DIV64) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV128) || ((__HCLK__) == RCC_SYSCLK_DIV256) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV512))
#define IS_RCC_PCLK(__PCLK__) (((__PCLK__) == RCC_HCLK_DIV1) || ((__PCLK__) == RCC_HCLK_DIV2) || \
                               ((__PCLK__) == RCC_HCLK_DIV4) || ((__PCLK__) == RCC_HCLK_DIV8) || \
                               ((__PCLK__) == RCC_HCLK_DIV16))
#define IS_RCC_MCO(__MCO__)  ((__MCO__) == RCC_MCO)
#define IS_RCC_RTCCLKSOURCE(__SOURCE__)  (((__SOURCE__) == RCC_RTCCLKSOURCE_NO_CLK) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSE)  || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSI)  || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV32))
#if defined(RCC_CFGR3_USART2SW)
#define IS_RCC_USART2CLKSOURCE(__SOURCE__)  (((__SOURCE__) == RCC_USART2CLKSOURCE_PCLK1)  || \
                                             ((__SOURCE__) == RCC_USART2CLKSOURCE_SYSCLK) || \
                                             ((__SOURCE__) == RCC_USART2CLKSOURCE_LSE)    || \
                                             ((__SOURCE__) == RCC_USART2CLKSOURCE_HSI))
#endif
#if defined(RCC_CFGR3_USART3SW)
#define IS_RCC_USART3CLKSOURCE(__SOURCE__)  (((__SOURCE__) == RCC_USART3CLKSOURCE_PCLK1)  || \
                                             ((__SOURCE__) == RCC_USART3CLKSOURCE_SYSCLK) || \
                                             ((__SOURCE__) == RCC_USART3CLKSOURCE_LSE)    || \
                                             ((__SOURCE__) == RCC_USART3CLKSOURCE_HSI))
#endif
#define IS_RCC_I2C1CLKSOURCE(__SOURCE__)  (((__SOURCE__) == RCC_I2C1CLKSOURCE_HSI) || \
                                           ((__SOURCE__) == RCC_I2C1CLKSOURCE_SYSCLK))














typedef struct
{
  uint32_t PLLState;


  uint32_t PLLSource;


  uint32_t PLLMUL;


#if defined(RCC_CFGR_PLLSRC_HSI_PREDIV)
  uint32_t PREDIV;


#endif
} RCC_PLLInitTypeDef;




typedef struct
{
  uint32_t OscillatorType;


  uint32_t HSEState;


#if defined(RCC_CFGR_PLLSRC_HSI_DIV2)
  uint32_t HSEPredivValue;


#endif
  uint32_t LSEState;


  uint32_t HSIState;


  uint32_t HSICalibrationValue;


  uint32_t LSIState;


  RCC_PLLInitTypeDef PLL;

} RCC_OscInitTypeDef;




typedef struct
{
  uint32_t ClockType;


  uint32_t SYSCLKSource;


  uint32_t AHBCLKDivider;


  uint32_t APB1CLKDivider;


  uint32_t APB2CLKDivider;

} RCC_ClkInitTypeDef;














#if defined(RCC_CFGR_PLLSRC_HSI_PREDIV)
#define RCC_PLLSOURCE_HSI           RCC_CFGR_PLLSRC_HSI_PREDIV
#endif
#if defined(RCC_CFGR_PLLSRC_HSI_DIV2)
#define RCC_PLLSOURCE_HSI           RCC_CFGR_PLLSRC_HSI_DIV2
#endif
#define RCC_PLLSOURCE_HSE           RCC_CFGR_PLLSRC_HSE_PREDIV








#define RCC_OSCILLATORTYPE_NONE            (0x00000000U)
#define RCC_OSCILLATORTYPE_HSE             (0x00000001U)
#define RCC_OSCILLATORTYPE_HSI             (0x00000002U)
#define RCC_OSCILLATORTYPE_LSE             (0x00000004U)
#define RCC_OSCILLATORTYPE_LSI             (0x00000008U)







#define RCC_HSE_OFF                      (0x00000000U)
#define RCC_HSE_ON                       RCC_CR_HSEON
#define RCC_HSE_BYPASS                   ((uint32_t)(RCC_CR_HSEBYP | RCC_CR_HSEON))







#define RCC_LSE_OFF                      (0x00000000U)
#define RCC_LSE_ON                       RCC_BDCR_LSEON
#define RCC_LSE_BYPASS                   ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSEON))








#define RCC_HSI_OFF                      (0x00000000U)
#define RCC_HSI_ON                       RCC_CR_HSION

#define RCC_HSICALIBRATION_DEFAULT       (0x10U)








#define RCC_LSI_OFF                      (0x00000000U)
#define RCC_LSI_ON                       RCC_CSR_LSION








#define RCC_PLL_NONE                      (0x00000000U)
#define RCC_PLL_OFF                       (0x00000001U)
#define RCC_PLL_ON                        (0x00000002U)








#define RCC_CLOCKTYPE_SYSCLK             (0x00000001U)
#define RCC_CLOCKTYPE_HCLK               (0x00000002U)
#define RCC_CLOCKTYPE_PCLK1              (0x00000004U)
#define RCC_CLOCKTYPE_PCLK2              (0x00000008U)








#define RCC_SYSCLKSOURCE_HSI             RCC_CFGR_SW_HSI
#define RCC_SYSCLKSOURCE_HSE             RCC_CFGR_SW_HSE
#define RCC_SYSCLKSOURCE_PLLCLK          RCC_CFGR_SW_PLL








#define RCC_SYSCLKSOURCE_STATUS_HSI      RCC_CFGR_SWS_HSI
#define RCC_SYSCLKSOURCE_STATUS_HSE      RCC_CFGR_SWS_HSE
#define RCC_SYSCLKSOURCE_STATUS_PLLCLK   RCC_CFGR_SWS_PLL








#define RCC_SYSCLK_DIV1                  RCC_CFGR_HPRE_DIV1
#define RCC_SYSCLK_DIV2                  RCC_CFGR_HPRE_DIV2
#define RCC_SYSCLK_DIV4                  RCC_CFGR_HPRE_DIV4
#define RCC_SYSCLK_DIV8                  RCC_CFGR_HPRE_DIV8
#define RCC_SYSCLK_DIV16                 RCC_CFGR_HPRE_DIV16
#define RCC_SYSCLK_DIV64                 RCC_CFGR_HPRE_DIV64
#define RCC_SYSCLK_DIV128                RCC_CFGR_HPRE_DIV128
#define RCC_SYSCLK_DIV256                RCC_CFGR_HPRE_DIV256
#define RCC_SYSCLK_DIV512                RCC_CFGR_HPRE_DIV512








#define RCC_HCLK_DIV1                    RCC_CFGR_PPRE1_DIV1
#define RCC_HCLK_DIV2                    RCC_CFGR_PPRE1_DIV2
#define RCC_HCLK_DIV4                    RCC_CFGR_PPRE1_DIV4
#define RCC_HCLK_DIV8                    RCC_CFGR_PPRE1_DIV8
#define RCC_HCLK_DIV16                   RCC_CFGR_PPRE1_DIV16








#define RCC_RTCCLKSOURCE_NO_CLK          RCC_BDCR_RTCSEL_NOCLOCK
#define RCC_RTCCLKSOURCE_LSE             RCC_BDCR_RTCSEL_LSE
#define RCC_RTCCLKSOURCE_LSI             RCC_BDCR_RTCSEL_LSI
#define RCC_RTCCLKSOURCE_HSE_DIV32       RCC_BDCR_RTCSEL_HSE







#define RCC_PLL_MUL2                     RCC_CFGR_PLLMUL2
#define RCC_PLL_MUL3                     RCC_CFGR_PLLMUL3
#define RCC_PLL_MUL4                     RCC_CFGR_PLLMUL4
#define RCC_PLL_MUL5                     RCC_CFGR_PLLMUL5
#define RCC_PLL_MUL6                     RCC_CFGR_PLLMUL6
#define RCC_PLL_MUL7                     RCC_CFGR_PLLMUL7
#define RCC_PLL_MUL8                     RCC_CFGR_PLLMUL8
#define RCC_PLL_MUL9                     RCC_CFGR_PLLMUL9
#define RCC_PLL_MUL10                    RCC_CFGR_PLLMUL10
#define RCC_PLL_MUL11                    RCC_CFGR_PLLMUL11
#define RCC_PLL_MUL12                    RCC_CFGR_PLLMUL12
#define RCC_PLL_MUL13                    RCC_CFGR_PLLMUL13
#define RCC_PLL_MUL14                    RCC_CFGR_PLLMUL14
#define RCC_PLL_MUL15                    RCC_CFGR_PLLMUL15
#define RCC_PLL_MUL16                    RCC_CFGR_PLLMUL16





#if defined(RCC_CFGR_PLLSRC_HSI_PREDIV)




#define RCC_PREDIV_DIV1                  RCC_CFGR2_PREDIV_DIV1
#define RCC_PREDIV_DIV2                  RCC_CFGR2_PREDIV_DIV2
#define RCC_PREDIV_DIV3                  RCC_CFGR2_PREDIV_DIV3
#define RCC_PREDIV_DIV4                  RCC_CFGR2_PREDIV_DIV4
#define RCC_PREDIV_DIV5                  RCC_CFGR2_PREDIV_DIV5
#define RCC_PREDIV_DIV6                  RCC_CFGR2_PREDIV_DIV6
#define RCC_PREDIV_DIV7                  RCC_CFGR2_PREDIV_DIV7
#define RCC_PREDIV_DIV8                  RCC_CFGR2_PREDIV_DIV8
#define RCC_PREDIV_DIV9                  RCC_CFGR2_PREDIV_DIV9
#define RCC_PREDIV_DIV10                 RCC_CFGR2_PREDIV_DIV10
#define RCC_PREDIV_DIV11                 RCC_CFGR2_PREDIV_DIV11
#define RCC_PREDIV_DIV12                 RCC_CFGR2_PREDIV_DIV12
#define RCC_PREDIV_DIV13                 RCC_CFGR2_PREDIV_DIV13
#define RCC_PREDIV_DIV14                 RCC_CFGR2_PREDIV_DIV14
#define RCC_PREDIV_DIV15                 RCC_CFGR2_PREDIV_DIV15
#define RCC_PREDIV_DIV16                 RCC_CFGR2_PREDIV_DIV16





#endif
#if defined(RCC_CFGR_PLLSRC_HSI_DIV2)




#define RCC_HSE_PREDIV_DIV1              RCC_CFGR2_PREDIV_DIV1
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR2_PREDIV_DIV2
#define RCC_HSE_PREDIV_DIV3              RCC_CFGR2_PREDIV_DIV3
#define RCC_HSE_PREDIV_DIV4              RCC_CFGR2_PREDIV_DIV4
#define RCC_HSE_PREDIV_DIV5              RCC_CFGR2_PREDIV_DIV5
#define RCC_HSE_PREDIV_DIV6              RCC_CFGR2_PREDIV_DIV6
#define RCC_HSE_PREDIV_DIV7              RCC_CFGR2_PREDIV_DIV7
#define RCC_HSE_PREDIV_DIV8              RCC_CFGR2_PREDIV_DIV8
#define RCC_HSE_PREDIV_DIV9              RCC_CFGR2_PREDIV_DIV9
#define RCC_HSE_PREDIV_DIV10             RCC_CFGR2_PREDIV_DIV10
#define RCC_HSE_PREDIV_DIV11             RCC_CFGR2_PREDIV_DIV11
#define RCC_HSE_PREDIV_DIV12             RCC_CFGR2_PREDIV_DIV12
#define RCC_HSE_PREDIV_DIV13             RCC_CFGR2_PREDIV_DIV13
#define RCC_HSE_PREDIV_DIV14             RCC_CFGR2_PREDIV_DIV14
#define RCC_HSE_PREDIV_DIV15             RCC_CFGR2_PREDIV_DIV15
#define RCC_HSE_PREDIV_DIV16             RCC_CFGR2_PREDIV_DIV16




#endif

#if defined(RCC_CFGR3_USART2SW)



#define RCC_USART2CLKSOURCE_PCLK1        RCC_CFGR3_USART2SW_PCLK
#define RCC_USART2CLKSOURCE_SYSCLK       RCC_CFGR3_USART2SW_SYSCLK
#define RCC_USART2CLKSOURCE_LSE          RCC_CFGR3_USART2SW_LSE
#define RCC_USART2CLKSOURCE_HSI          RCC_CFGR3_USART2SW_HSI




#endif

#if defined(RCC_CFGR3_USART3SW)



#define RCC_USART3CLKSOURCE_PCLK1        RCC_CFGR3_USART3SW_PCLK
#define RCC_USART3CLKSOURCE_SYSCLK       RCC_CFGR3_USART3SW_SYSCLK
#define RCC_USART3CLKSOURCE_LSE          RCC_CFGR3_USART3SW_LSE
#define RCC_USART3CLKSOURCE_HSI          RCC_CFGR3_USART3SW_HSI




#endif




#define RCC_I2C1CLKSOURCE_HSI            RCC_CFGR3_I2C1SW_HSI
#define RCC_I2C1CLKSOURCE_SYSCLK         RCC_CFGR3_I2C1SW_SYSCLK







#define RCC_MCO1                         (0x00000000U)
#define RCC_MCO                          RCC_MCO1








#define RCC_IT_LSIRDY                    ((uint8_t)RCC_CIR_LSIRDYF)
#define RCC_IT_LSERDY                    ((uint8_t)RCC_CIR_LSERDYF)
#define RCC_IT_HSIRDY                    ((uint8_t)RCC_CIR_HSIRDYF)
#define RCC_IT_HSERDY                    ((uint8_t)RCC_CIR_HSERDYF)
#define RCC_IT_PLLRDY                    ((uint8_t)RCC_CIR_PLLRDYF)
#define RCC_IT_CSS                       ((uint8_t)RCC_CIR_CSSF)















#define RCC_FLAG_HSIRDY                  ((uint8_t)((CR_REG_INDEX << 5U) | POSITION_VAL(RCC_CR_HSIRDY)))
#define RCC_FLAG_HSERDY                  ((uint8_t)((CR_REG_INDEX << 5U) | POSITION_VAL(RCC_CR_HSERDY)))
#define RCC_FLAG_PLLRDY                  ((uint8_t)((CR_REG_INDEX << 5U) | POSITION_VAL(RCC_CR_PLLRDY)))


#define RCC_FLAG_LSIRDY                  ((uint8_t)((CSR_REG_INDEX << 5U) | POSITION_VAL(RCC_CSR_LSIRDY)))
#if   defined(RCC_CSR_V18PWRRSTF)
#define RCC_FLAG_V18PWRRST               ((uint8_t)((CSR_REG_INDEX << 5U) | POSITION_VAL(RCC_CSR_V18PWRRSTF)))
#endif
#define RCC_FLAG_OBLRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | POSITION_VAL(RCC_CSR_OBLRSTF)))
#define RCC_FLAG_PINRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | POSITION_VAL(RCC_CSR_PINRSTF)))
#define RCC_FLAG_PORRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | POSITION_VAL(RCC_CSR_PORRSTF)))
#define RCC_FLAG_SFTRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | POSITION_VAL(RCC_CSR_SFTRSTF)))
#define RCC_FLAG_IWDGRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | POSITION_VAL(RCC_CSR_IWDGRSTF)))
#define RCC_FLAG_WWDGRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | POSITION_VAL(RCC_CSR_WWDGRSTF)))
#define RCC_FLAG_LPWRRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | POSITION_VAL(RCC_CSR_LPWRRSTF)))


#define RCC_FLAG_LSERDY                  ((uint8_t)((BDCR_REG_INDEX << 5U) | POSITION_VAL(RCC_BDCR_LSERDY)))


#if defined(RCC_CFGR_MCOF)
#define RCC_FLAG_MCO                     ((uint8_t)((CFGR_REG_INDEX << 5U) | POSITION_VAL(RCC_CFGR_MCOF)))
#endif






















#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOAEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOAEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_GPIOB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOBEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOBEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_GPIOC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOCEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_GPIOD_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIODEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIODEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOFEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_GPIOFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_CRC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_CRCEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_CRCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_DMA1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SRAM_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_SRAMEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_SRAMEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_FLITF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_FLITFEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_FLITFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TSC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_TSCEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_TSCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOA_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_GPIOAEN))
#define __HAL_RCC_GPIOB_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_GPIOBEN))
#define __HAL_RCC_GPIOC_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_GPIOCEN))
#define __HAL_RCC_GPIOD_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_GPIODEN))
#define __HAL_RCC_GPIOF_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_GPIOFEN))
#define __HAL_RCC_CRC_CLK_DISABLE()          (RCC->AHBENR &= ~(RCC_AHBENR_CRCEN))
#define __HAL_RCC_DMA1_CLK_DISABLE()         (RCC->AHBENR &= ~(RCC_AHBENR_DMA1EN))
#define __HAL_RCC_SRAM_CLK_DISABLE()         (RCC->AHBENR &= ~(RCC_AHBENR_SRAMEN))
#define __HAL_RCC_FLITF_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_FLITFEN))
#define __HAL_RCC_TSC_CLK_DISABLE()          (RCC->AHBENR &= ~(RCC_AHBENR_TSCEN))











#define __HAL_RCC_TIM2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_WWDG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_USART2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_USART3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_I2C1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_PWR_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_DAC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DAC1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DAC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM2EN))
#define __HAL_RCC_TIM6_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
#define __HAL_RCC_WWDG_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_WWDGEN))
#define __HAL_RCC_USART2_CLK_DISABLE() (RCC->APB1ENR &= ~(RCC_APB1ENR_USART2EN))
#define __HAL_RCC_USART3_CLK_DISABLE() (RCC->APB1ENR &= ~(RCC_APB1ENR_USART3EN))
#define __HAL_RCC_I2C1_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C1EN))
#define __HAL_RCC_PWR_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_PWREN))
#define __HAL_RCC_DAC1_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_DAC1EN))











#define __HAL_RCC_SYSCFG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM15_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM16_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM17_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_USART1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SYSCFG_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_SYSCFGEN))
#define __HAL_RCC_TIM15_CLK_DISABLE()  (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM15EN))
#define __HAL_RCC_TIM16_CLK_DISABLE()  (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM16EN))
#define __HAL_RCC_TIM17_CLK_DISABLE()  (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM17EN))
#define __HAL_RCC_USART1_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_USART1EN))











#define __HAL_RCC_GPIOA_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOAEN)) != RESET)
#define __HAL_RCC_GPIOB_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOBEN)) != RESET)
#define __HAL_RCC_GPIOC_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOCEN)) != RESET)
#define __HAL_RCC_GPIOD_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIODEN)) != RESET)
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_GPIOFEN)) != RESET)
#define __HAL_RCC_CRC_IS_CLK_ENABLED()           ((RCC->AHBENR & (RCC_AHBENR_CRCEN))   != RESET)
#define __HAL_RCC_DMA1_IS_CLK_ENABLED()          ((RCC->AHBENR & (RCC_AHBENR_DMA1EN))  != RESET)
#define __HAL_RCC_SRAM_IS_CLK_ENABLED()          ((RCC->AHBENR & (RCC_AHBENR_SRAMEN))  != RESET)
#define __HAL_RCC_FLITF_IS_CLK_ENABLED()         ((RCC->AHBENR & (RCC_AHBENR_FLITFEN)) != RESET)
#define __HAL_RCC_TSC_IS_CLK_ENABLED()           ((RCC->AHBENR & (RCC_AHBENR_TSCEN))   != RESET)

#define __HAL_RCC_GPIOA_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_GPIOAEN)) == RESET)
#define __HAL_RCC_GPIOB_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_GPIOBEN)) == RESET)
#define __HAL_RCC_GPIOC_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_GPIOCEN)) == RESET)
#define __HAL_RCC_GPIOD_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_GPIODEN)) == RESET)
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_GPIOFEN)) == RESET)
#define __HAL_RCC_CRC_IS_CLK_DISABLED()          ((RCC->AHBENR & (RCC_AHBENR_CRCEN))   == RESET)
#define __HAL_RCC_DMA1_IS_CLK_DISABLED()         ((RCC->AHBENR & (RCC_AHBENR_DMA1EN))  == RESET)
#define __HAL_RCC_SRAM_IS_CLK_DISABLED()         ((RCC->AHBENR & (RCC_AHBENR_SRAMEN))  == RESET)
#define __HAL_RCC_FLITF_IS_CLK_DISABLED()        ((RCC->AHBENR & (RCC_AHBENR_FLITFEN)) == RESET)
#define __HAL_RCC_TSC_IS_CLK_DISABLED()          ((RCC->AHBENR & (RCC_AHBENR_TSCEN))   == RESET)











#define __HAL_RCC_TIM2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN))   != RESET)
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN))   != RESET)
#define __HAL_RCC_WWDG_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN))   != RESET)
#define __HAL_RCC_USART2_IS_CLK_ENABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) != RESET)
#define __HAL_RCC_USART3_IS_CLK_ENABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) != RESET)
#define __HAL_RCC_I2C1_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN))   != RESET)
#define __HAL_RCC_PWR_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_PWREN))    != RESET)
#define __HAL_RCC_DAC1_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_DAC1EN))   != RESET)

#define __HAL_RCC_TIM2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN))   == RESET)
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN))   == RESET)
#define __HAL_RCC_WWDG_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN))   == RESET)
#define __HAL_RCC_USART2_IS_CLK_DISABLED() ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) == RESET)
#define __HAL_RCC_USART3_IS_CLK_DISABLED() ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) == RESET)
#define __HAL_RCC_I2C1_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN))   == RESET)
#define __HAL_RCC_PWR_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_PWREN))    == RESET)
#define __HAL_RCC_DAC1_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_DAC1EN))   == RESET)











#define __HAL_RCC_SYSCFG_IS_CLK_ENABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_SYSCFGEN))  != RESET)
#define __HAL_RCC_TIM15_IS_CLK_ENABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN))   != RESET)
#define __HAL_RCC_TIM16_IS_CLK_ENABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN))   != RESET)
#define __HAL_RCC_TIM17_IS_CLK_ENABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN))   != RESET)
#define __HAL_RCC_USART1_IS_CLK_ENABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN))  != RESET)

#define __HAL_RCC_SYSCFG_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_SYSCFGEN))  == RESET)
#define __HAL_RCC_TIM15_IS_CLK_DISABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN))   == RESET)
#define __HAL_RCC_TIM16_IS_CLK_DISABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN))   == RESET)
#define __HAL_RCC_TIM17_IS_CLK_DISABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN))   == RESET)
#define __HAL_RCC_USART1_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN))  == RESET)








#define __HAL_RCC_AHB_FORCE_RESET()     (RCC->AHBRSTR = 0xFFFFFFFFU)
#define __HAL_RCC_GPIOA_FORCE_RESET()   (RCC->AHBRSTR |= (RCC_AHBRSTR_GPIOARST))
#define __HAL_RCC_GPIOB_FORCE_RESET()   (RCC->AHBRSTR |= (RCC_AHBRSTR_GPIOBRST))
#define __HAL_RCC_GPIOC_FORCE_RESET()   (RCC->AHBRSTR |= (RCC_AHBRSTR_GPIOCRST))
#define __HAL_RCC_GPIOD_FORCE_RESET()   (RCC->AHBRSTR |= (RCC_AHBRSTR_GPIODRST))
#define __HAL_RCC_GPIOF_FORCE_RESET()   (RCC->AHBRSTR |= (RCC_AHBRSTR_GPIOFRST))
#define __HAL_RCC_TSC_FORCE_RESET()     (RCC->AHBRSTR |= (RCC_AHBRSTR_TSCRST))

#define __HAL_RCC_AHB_RELEASE_RESET()   (RCC->AHBRSTR = 0x00000000U)
#define __HAL_RCC_GPIOA_RELEASE_RESET() (RCC->AHBRSTR &= ~(RCC_AHBRSTR_GPIOARST))
#define __HAL_RCC_GPIOB_RELEASE_RESET() (RCC->AHBRSTR &= ~(RCC_AHBRSTR_GPIOBRST))
#define __HAL_RCC_GPIOC_RELEASE_RESET() (RCC->AHBRSTR &= ~(RCC_AHBRSTR_GPIOCRST))
#define __HAL_RCC_GPIOD_RELEASE_RESET() (RCC->AHBRSTR &= ~(RCC_AHBRSTR_GPIODRST))
#define __HAL_RCC_GPIOF_RELEASE_RESET() (RCC->AHBRSTR &= ~(RCC_AHBRSTR_GPIOFRST))
#define __HAL_RCC_TSC_RELEASE_RESET()   (RCC->AHBRSTR &= ~(RCC_AHBRSTR_TSCRST))








#define __HAL_RCC_APB1_FORCE_RESET()     (RCC->APB1RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_TIM2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM2RST))
#define __HAL_RCC_TIM6_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_WWDG_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_WWDGRST))
#define __HAL_RCC_USART2_FORCE_RESET()   (RCC->APB1RSTR |= (RCC_APB1RSTR_USART2RST))
#define __HAL_RCC_USART3_FORCE_RESET()   (RCC->APB1RSTR |= (RCC_APB1RSTR_USART3RST))
#define __HAL_RCC_I2C1_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C1RST))
#define __HAL_RCC_PWR_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_PWRRST))
#define __HAL_RCC_DAC1_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_DAC1RST))

#define __HAL_RCC_APB1_RELEASE_RESET()   (RCC->APB1RSTR = 0x00000000U)
#define __HAL_RCC_TIM2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM2RST))
#define __HAL_RCC_TIM6_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_WWDG_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_WWDGRST))
#define __HAL_RCC_USART2_RELEASE_RESET() (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART2RST))
#define __HAL_RCC_USART3_RELEASE_RESET() (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART3RST))
#define __HAL_RCC_I2C1_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C1RST))
#define __HAL_RCC_PWR_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_PWRRST))
#define __HAL_RCC_DAC1_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DAC1RST))








#define __HAL_RCC_APB2_FORCE_RESET()     (RCC->APB2RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_SYSCFG_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_SYSCFGRST))
#define __HAL_RCC_TIM15_FORCE_RESET()    (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM15RST))
#define __HAL_RCC_TIM16_FORCE_RESET()    (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM16RST))
#define __HAL_RCC_TIM17_FORCE_RESET()    (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM17RST))
#define __HAL_RCC_USART1_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_USART1RST))

#define __HAL_RCC_APB2_RELEASE_RESET()   (RCC->APB2RSTR = 0x00000000U)
#define __HAL_RCC_SYSCFG_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SYSCFGRST))
#define __HAL_RCC_TIM15_RELEASE_RESET()  (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM15RST))
#define __HAL_RCC_TIM16_RELEASE_RESET()  (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM16RST))
#define __HAL_RCC_TIM17_RELEASE_RESET()  (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM17RST))
#define __HAL_RCC_USART1_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART1RST))






















#define __HAL_RCC_HSI_ENABLE()  (*(__IO uint32_t *) RCC_CR_HSION_BB = ENABLE)
#define __HAL_RCC_HSI_DISABLE() (*(__IO uint32_t *) RCC_CR_HSION_BB = DISABLE)








#define __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(_HSICALIBRATIONVALUE_) \
          (MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, (uint32_t)(_HSICALIBRATIONVALUE_) << POSITION_VAL(RCC_CR_HSITRIM)))














#define __HAL_RCC_LSI_ENABLE()  (*(__IO uint32_t *) RCC_CSR_LSION_BB = ENABLE)






#define __HAL_RCC_LSI_DISABLE() (*(__IO uint32_t *) RCC_CSR_LSION_BB = DISABLE)































#define __HAL_RCC_HSE_CONFIG(__STATE__)                                     \
                    do{                                                     \
                      if ((__STATE__) == RCC_HSE_ON)                        \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_OFF)                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_BYPASS)               \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEBYP);                    \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \
                      }                                                     \
                      else                                                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \
                      }                                                     \
                    }while(0U)


























#define __HAL_RCC_LSE_CONFIG(__STATE__)                                     \
                    do{                                                     \
                      if ((__STATE__) == RCC_LSE_ON)                        \
                      {                                                     \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);                   \
                      }                                                     \
                      else if ((__STATE__) == RCC_LSE_OFF)                  \
                      {                                                     \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);                 \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                \
                      }                                                     \
                      else if ((__STATE__) == RCC_LSE_BYPASS)               \
                      {                                                     \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                  \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);                   \
                      }                                                     \
                      else                                                  \
                      {                                                     \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);                 \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                \
                      }                                                     \
                    }while(0U)


























































#define __HAL_RCC_USART1_CONFIG(__USART1CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_USART1SW, (uint32_t)(__USART1CLKSOURCE__))

















































#define __HAL_RCC_GET_USART1_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_USART1SW)))

#if defined(RCC_CFGR3_USART2SW)








#define __HAL_RCC_USART2_CONFIG(__USART2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_USART2SW, (uint32_t)(__USART2CLKSOURCE__))








#define __HAL_RCC_GET_USART2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_USART2SW)))
#endif

#if defined(RCC_CFGR3_USART3SW)








#define __HAL_RCC_USART3_CONFIG(__USART3CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_USART3SW, (uint32_t)(__USART3CLKSOURCE__))








#define __HAL_RCC_GET_USART3_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_USART3SW)))
#endif














#define __HAL_RCC_I2C1_CONFIG(__I2C1CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_I2C1SW, (uint32_t)(__I2C1CLKSOURCE__))






#define __HAL_RCC_GET_I2C1_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_I2C1SW)))














#define __HAL_RCC_PLL_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLON_BB = ENABLE)




#define __HAL_RCC_PLL_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLLON_BB = DISABLE)








#define __HAL_RCC_GET_PLL_OSCSOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_PLLSRC)))

















#define __HAL_RCC_SYSCLK_CONFIG(__SYSCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, (__SYSCLKSOURCE__))








#define __HAL_RCC_GET_SYSCLK_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR,RCC_CFGR_SWS)))









#if defined(RCC_CFGR_MCOPRE)





















#else














#endif
#if   defined(RCC_CFGR_MCOPRE)
#define __HAL_RCC_MCO1_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
                 MODIFY_REG(RCC->CFGR, (RCC_CFGR_MCO | RCC_CFGR_MCOPRE), ((__MCOCLKSOURCE__) | (__MCODIV__)))
#else

#define __HAL_RCC_MCO1_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
                 MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO, (__MCOCLKSOURCE__))

#endif































#define __HAL_RCC_RTC_CONFIG(__RTC_CLKSOURCE__) MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, (__RTC_CLKSOURCE__))








#define __HAL_RCC_GET_RTC_SOURCE() (READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL))




#define __HAL_RCC_RTC_ENABLE()          (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = ENABLE)




#define __HAL_RCC_RTC_DISABLE()         (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = DISABLE)





#define __HAL_RCC_BACKUPRESET_FORCE()   (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = ENABLE)



#define __HAL_RCC_BACKUPRESET_RELEASE() (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = DISABLE)



















#define __HAL_RCC_ENABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS |= (__INTERRUPT__))










#define __HAL_RCC_DISABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS &= (uint8_t)(~(__INTERRUPT__)))











#define __HAL_RCC_CLEAR_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE2_ADDRESS = (__INTERRUPT__))












#define __HAL_RCC_GET_IT(__INTERRUPT__) ((RCC->CIR & (__INTERRUPT__)) == (__INTERRUPT__))





#define __HAL_RCC_CLEAR_RESET_FLAGS() (*(__IO uint32_t *)RCC_CSR_RMVF_BB = ENABLE)


















































#define __HAL_RCC_GET_FLAG(__FLAG__) (((((__FLAG__) >> 5U) == CR_REG_INDEX)  ? RCC->CR   : \
                                       (((__FLAG__) >> 5U) == BDCR_REG_INDEX)? RCC->BDCR : \
                                       (((__FLAG__) >> 5U) == CFGR_REG_INDEX)? RCC->CFGR : \
                                                                              RCC->CSR) & (1U << ((__FLAG__) & RCC_FLAG_MASK)))










#include "stm32f3xx_hal_rcc_ex.h"











HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency);










void              HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void              HAL_RCC_EnableCSS(void);

void              HAL_RCC_NMI_IRQHandler(void);

void              HAL_RCC_CSSCallback(void);
void              HAL_RCC_DisableCSS(void);
uint32_t          HAL_RCC_GetSysClockFreq(void);
uint32_t          HAL_RCC_GetHCLKFreq(void);
uint32_t          HAL_RCC_GetPCLK1Freq(void);
uint32_t          HAL_RCC_GetPCLK2Freq(void);
void              HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
void              HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency);

















#ifdef __cplusplus
}
#endif

#endif



