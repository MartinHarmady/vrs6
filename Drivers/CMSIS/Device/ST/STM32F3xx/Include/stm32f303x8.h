
















































#ifndef __STM32F303x8_H
#define __STM32F303x8_H

#ifdef __cplusplus
 extern "C" {
#endif








#define __CM4_REV                 0x0001U
#define __MPU_PRESENT             0U
#define __NVIC_PRIO_BITS          4U
#define __Vendor_SysTickConfig    0U
#define __FPU_PRESENT             1U













typedef enum
{

  NonMaskableInt_IRQn         = -14,
  HardFault_IRQn              = -13,
  MemoryManagement_IRQn       = -12,
  BusFault_IRQn               = -11,
  UsageFault_IRQn             = -10,
  SVCall_IRQn                 = -5,
  DebugMonitor_IRQn           = -4,
  PendSV_IRQn                 = -2,
  SysTick_IRQn                = -1,

  WWDG_IRQn                   = 0,
  PVD_IRQn                    = 1,
  TAMP_STAMP_IRQn             = 2,
  RTC_WKUP_IRQn               = 3,
  FLASH_IRQn                  = 4,
  RCC_IRQn                    = 5,
  EXTI0_IRQn                  = 6,
  EXTI1_IRQn                  = 7,
  EXTI2_TSC_IRQn              = 8,
  EXTI3_IRQn                  = 9,
  EXTI4_IRQn                  = 10,
  DMA1_Channel1_IRQn          = 11,
  DMA1_Channel2_IRQn          = 12,
  DMA1_Channel3_IRQn          = 13,
  DMA1_Channel4_IRQn          = 14,
  DMA1_Channel5_IRQn          = 15,
  DMA1_Channel6_IRQn          = 16,
  DMA1_Channel7_IRQn          = 17,
  ADC1_2_IRQn                 = 18,
  CAN_TX_IRQn                 = 19,
  CAN_RX0_IRQn                = 20,
  CAN_RX1_IRQn                = 21,
  CAN_SCE_IRQn                = 22,
  EXTI9_5_IRQn                = 23,
  TIM1_BRK_TIM15_IRQn         = 24,
  TIM1_UP_TIM16_IRQn          = 25,
  TIM1_TRG_COM_TIM17_IRQn     = 26,
  TIM1_CC_IRQn                = 27,
  TIM2_IRQn                   = 28,
  TIM3_IRQn                   = 29,
  I2C1_EV_IRQn                = 31,
  I2C1_ER_IRQn                = 32,
  SPI1_IRQn                   = 35,
  USART1_IRQn                 = 37,
  USART2_IRQn                 = 38,
  USART3_IRQn                 = 39,
  EXTI15_10_IRQn              = 40,
  RTC_Alarm_IRQn              = 41,
  TIM6_DAC1_IRQn              = 54,
  TIM7_DAC2_IRQn              = 55,
  COMP2_IRQn                  = 64,
  COMP4_6_IRQn                = 65,
  FPU_IRQn                    = 81,
} IRQn_Type;





#include "core_cm4.h"
#include "system_stm32f3xx.h"
#include <stdint.h>









typedef struct
{
  __IO uint32_t ISR;
  __IO uint32_t IER;
  __IO uint32_t CR;
  __IO uint32_t CFGR;
  uint32_t      RESERVED0;
  __IO uint32_t SMPR1;
  __IO uint32_t SMPR2;
  uint32_t      RESERVED1;
  __IO uint32_t TR1;
  __IO uint32_t TR2;
  __IO uint32_t TR3;
  uint32_t      RESERVED2;
  __IO uint32_t SQR1;
  __IO uint32_t SQR2;
  __IO uint32_t SQR3;
  __IO uint32_t SQR4;
  __IO uint32_t DR;
  uint32_t      RESERVED3;
  uint32_t      RESERVED4;
  __IO uint32_t JSQR;
  uint32_t      RESERVED5[4];
  __IO uint32_t OFR1;
  __IO uint32_t OFR2;
  __IO uint32_t OFR3;
  __IO uint32_t OFR4;
  uint32_t      RESERVED6[4];
  __IO uint32_t JDR1;
  __IO uint32_t JDR2;
  __IO uint32_t JDR3;
  __IO uint32_t JDR4;
  uint32_t      RESERVED7[4];
  __IO uint32_t AWD2CR;
  __IO uint32_t AWD3CR;
  uint32_t      RESERVED8;
  uint32_t      RESERVED9;
  __IO uint32_t DIFSEL;
  __IO uint32_t CALFACT;

} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CSR;
  uint32_t      RESERVED;
  __IO uint32_t CCR;
  __IO uint32_t CDR;

} ADC_Common_TypeDef;




typedef struct
{
  __IO uint32_t TIR;
  __IO uint32_t TDTR;
  __IO uint32_t TDLR;
  __IO uint32_t TDHR;
} CAN_TxMailBox_TypeDef;




typedef struct
{
  __IO uint32_t RIR;
  __IO uint32_t RDTR;
  __IO uint32_t RDLR;
  __IO uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;




typedef struct
{
  __IO uint32_t FR1;
  __IO uint32_t FR2;
} CAN_FilterRegister_TypeDef;




typedef struct
{
  __IO uint32_t              MCR;
  __IO uint32_t              MSR;
  __IO uint32_t              TSR;
  __IO uint32_t              RF0R;
  __IO uint32_t              RF1R;
  __IO uint32_t              IER;
  __IO uint32_t              ESR;
  __IO uint32_t              BTR;
  uint32_t                   RESERVED0[88];
  CAN_TxMailBox_TypeDef      sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];
  uint32_t                   RESERVED1[12];
  __IO uint32_t              FMR;
  __IO uint32_t              FM1R;
  uint32_t                   RESERVED2;
  __IO uint32_t              FS1R;
  uint32_t                   RESERVED3;
  __IO uint32_t              FFA1R;
  uint32_t                   RESERVED4;
  __IO uint32_t              FA1R;
  uint32_t                   RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[28];
} CAN_TypeDef;




typedef struct
{
  __IO uint32_t CSR;
} COMP_TypeDef;

typedef struct
{
  __IO uint32_t CSR;
} COMP_Common_TypeDef;





typedef struct
{
  __IO uint32_t DR;
  __IO uint8_t  IDR;
  uint8_t       RESERVED0;
  uint16_t      RESERVED1;
  __IO uint32_t CR;
  uint32_t      RESERVED2;
  __IO uint32_t INIT;
  __IO uint32_t POL;
} CRC_TypeDef;





typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t SWTRIGR;
  __IO uint32_t DHR12R1;
  __IO uint32_t DHR12L1;
  __IO uint32_t DHR8R1;
  __IO uint32_t DHR12R2;
  __IO uint32_t DHR12L2;
  __IO uint32_t DHR8R2;
  __IO uint32_t DHR12RD;
  __IO uint32_t DHR12LD;
  __IO uint32_t DHR8RD;
  __IO uint32_t DOR1;
  __IO uint32_t DOR2;
  __IO uint32_t SR;
} DAC_TypeDef;





typedef struct
{
  __IO uint32_t IDCODE;
  __IO uint32_t CR;
  __IO uint32_t APB1FZ;
  __IO uint32_t APB2FZ;
}DBGMCU_TypeDef;





typedef struct
{
  __IO uint32_t CCR;
  __IO uint32_t CNDTR;
  __IO uint32_t CPAR;
  __IO uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;
  __IO uint32_t IFCR;
} DMA_TypeDef;





typedef struct
{
  __IO uint32_t IMR;
  __IO uint32_t EMR;
  __IO uint32_t RTSR;
  __IO uint32_t FTSR;
  __IO uint32_t SWIER;
  __IO uint32_t PR;
  uint32_t      RESERVED1;
  uint32_t      RESERVED2;
  __IO uint32_t IMR2;
  __IO uint32_t EMR2;
  __IO uint32_t RTSR2;
  __IO uint32_t FTSR2;
  __IO uint32_t SWIER2;
  __IO uint32_t PR2;
}EXTI_TypeDef;





typedef struct
{
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t AR;
  uint32_t      RESERVED;
  __IO uint32_t OBR;
  __IO uint32_t WRPR;

} FLASH_TypeDef;




typedef struct
{
  __IO uint16_t RDP;
  __IO uint16_t USER;
  uint16_t RESERVED0;
  uint16_t RESERVED1;
  __IO uint16_t WRP0;
  __IO uint16_t WRP1;
  __IO uint16_t WRP2;
  __IO uint16_t WRP3;
} OB_TypeDef;





typedef struct
{
  __IO uint32_t MODER;
  __IO uint32_t OTYPER;
  __IO uint32_t OSPEEDR;
  __IO uint32_t PUPDR;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t LCKR;
  __IO uint32_t AFR[2];
  __IO uint32_t BRR;
}GPIO_TypeDef;





typedef struct
{
  __IO uint32_t CSR;
} OPAMP_TypeDef;





typedef struct
{
  __IO uint32_t CFGR1;
  __IO uint32_t RCR;
  __IO uint32_t EXTICR[4];
  __IO uint32_t CFGR2;
  __IO uint32_t RESERVED0;
  __IO uint32_t RESERVED1;
  __IO uint32_t RESERVED2;
  __IO uint32_t RESERVED4;
  __IO uint32_t RESERVED5;
  __IO uint32_t RESERVED6;
  __IO uint32_t RESERVED7;
  __IO uint32_t RESERVED8;
  __IO uint32_t RESERVED9;
  __IO uint32_t RESERVED10;
  __IO uint32_t RESERVED11;
  __IO uint32_t RESERVED12;
  __IO uint32_t RESERVED13;
  __IO uint32_t CFGR3;
} SYSCFG_TypeDef;





typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t OAR1;
  __IO uint32_t OAR2;
  __IO uint32_t TIMINGR;
  __IO uint32_t TIMEOUTR;
  __IO uint32_t ISR;
  __IO uint32_t ICR;
  __IO uint32_t PECR;
  __IO uint32_t RXDR;
  __IO uint32_t TXDR;
}I2C_TypeDef;





typedef struct
{
  __IO uint32_t KR;
  __IO uint32_t PR;
  __IO uint32_t RLR;
  __IO uint32_t SR;
  __IO uint32_t WINR;
} IWDG_TypeDef;





typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CSR;
} PWR_TypeDef;




typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t APB2RSTR;
  __IO uint32_t APB1RSTR;
  __IO uint32_t AHBENR;
  __IO uint32_t APB2ENR;
  __IO uint32_t APB1ENR;
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
  __IO uint32_t AHBRSTR;
  __IO uint32_t CFGR2;
  __IO uint32_t CFGR3;
} RCC_TypeDef;





typedef struct
{
  __IO uint32_t TR;
  __IO uint32_t DR;
  __IO uint32_t CR;
  __IO uint32_t ISR;
  __IO uint32_t PRER;
  __IO uint32_t WUTR;
  uint32_t RESERVED0;
  __IO uint32_t ALRMAR;
  __IO uint32_t ALRMBR;
  __IO uint32_t WPR;
  __IO uint32_t SSR;
  __IO uint32_t SHIFTR;
  __IO uint32_t TSTR;
  __IO uint32_t TSDR;
  __IO uint32_t TSSSR;
  __IO uint32_t CALR;
  __IO uint32_t TAFCR;
  __IO uint32_t ALRMASSR;
  __IO uint32_t ALRMBSSR;
  uint32_t RESERVED7;
  __IO uint32_t BKP0R;
  __IO uint32_t BKP1R;
  __IO uint32_t BKP2R;
  __IO uint32_t BKP3R;
  __IO uint32_t BKP4R;
} RTC_TypeDef;






typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SR;
  __IO uint32_t DR;
  __IO uint32_t CRCPR;
  __IO uint32_t RXCRCR;
  __IO uint32_t TXCRCR;
} SPI_TypeDef;




typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SMCR;
  __IO uint32_t DIER;
  __IO uint32_t SR;
  __IO uint32_t EGR;
  __IO uint32_t CCMR1;
  __IO uint32_t CCMR2;
  __IO uint32_t CCER;
  __IO uint32_t CNT;
  __IO uint32_t PSC;
  __IO uint32_t ARR;
  __IO uint32_t RCR;
  __IO uint32_t CCR1;
  __IO uint32_t CCR2;
  __IO uint32_t CCR3;
  __IO uint32_t CCR4;
  __IO uint32_t BDTR;
  __IO uint32_t DCR;
  __IO uint32_t DMAR;
  __IO uint32_t OR;
  __IO uint32_t CCMR3;
  __IO uint32_t CCR5;
  __IO uint32_t CCR6;
} TIM_TypeDef;




typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t IER;
  __IO uint32_t ICR;
  __IO uint32_t ISR;
  __IO uint32_t IOHCR;
  uint32_t      RESERVED1;
  __IO uint32_t IOASCR;
  uint32_t      RESERVED2;
  __IO uint32_t IOSCR;
  uint32_t      RESERVED3;
  __IO uint32_t IOCCR;
  uint32_t      RESERVED4;
  __IO uint32_t IOGCSR;
  __IO uint32_t IOGXCR[8];
} TSC_TypeDef;





typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t CR3;
  __IO uint32_t BRR;
  __IO uint32_t GTPR;
  __IO uint32_t RTOR;
  __IO uint32_t RQR;
  __IO uint32_t ISR;
  __IO uint32_t ICR;
  __IO uint16_t RDR;
  uint16_t  RESERVED1;
  __IO uint16_t TDR;
  uint16_t  RESERVED2;
} USART_TypeDef;




typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFR;
  __IO uint32_t SR;
} WWDG_TypeDef;





#define FLASH_BASE            ((uint32_t)0x08000000U)
#define CCMDATARAM_BASE       ((uint32_t)0x10000000U)
#define SRAM_BASE             ((uint32_t)0x20000000U)
#define PERIPH_BASE           ((uint32_t)0x40000000U)
#define SRAM_BB_BASE          ((uint32_t)0x22000000U)
#define PERIPH_BB_BASE        ((uint32_t)0x42000000U)



#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000U)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000U)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000U)
#define AHB3PERIPH_BASE       (PERIPH_BASE + 0x10000000U)


#define TIM2_BASE             (APB1PERIPH_BASE + 0x00000000U)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x00000400U)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x00001000U)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x00001400U)
#define RTC_BASE              (APB1PERIPH_BASE + 0x00002800U)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x00002C00U)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x00003000U)
#define USART2_BASE           (APB1PERIPH_BASE + 0x00004400U)
#define USART3_BASE           (APB1PERIPH_BASE + 0x00004800U)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x00005400U)
#define CAN_BASE              (APB1PERIPH_BASE + 0x00006400U)
#define PWR_BASE              (APB1PERIPH_BASE + 0x00007000U)
#define DAC1_BASE             (APB1PERIPH_BASE + 0x00007400U)
#define DAC2_BASE             (APB1PERIPH_BASE + 0x00009800U)
#define DAC_BASE               DAC1_BASE


#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x00000000U)
#define COMP2_BASE            (APB2PERIPH_BASE + 0x00000020U)
#define COMP4_BASE            (APB2PERIPH_BASE + 0x00000028U)
#define COMP6_BASE            (APB2PERIPH_BASE + 0x00000030U)
#define COMP_BASE             COMP2_BASE
#define OPAMP2_BASE           (APB2PERIPH_BASE + 0x0000003CU)
#define OPAMP_BASE            OPAMP2_BASE
#define EXTI_BASE             (APB2PERIPH_BASE + 0x00000400U)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x00002C00U)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00003000U)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00003800U)
#define TIM15_BASE            (APB2PERIPH_BASE + 0x00004000U)
#define TIM16_BASE            (APB2PERIPH_BASE + 0x00004400U)
#define TIM17_BASE            (APB2PERIPH_BASE + 0x00004800U)


#define DMA1_BASE             (AHB1PERIPH_BASE + 0x00000000U)
#define DMA1_Channel1_BASE    (AHB1PERIPH_BASE + 0x00000008U)
#define DMA1_Channel2_BASE    (AHB1PERIPH_BASE + 0x0000001CU)
#define DMA1_Channel3_BASE    (AHB1PERIPH_BASE + 0x00000030U)
#define DMA1_Channel4_BASE    (AHB1PERIPH_BASE + 0x00000044U)
#define DMA1_Channel5_BASE    (AHB1PERIPH_BASE + 0x00000058U)
#define DMA1_Channel6_BASE    (AHB1PERIPH_BASE + 0x0000006CU)
#define DMA1_Channel7_BASE    (AHB1PERIPH_BASE + 0x00000080U)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x00001000U)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x00002000U)
#define OB_BASE               ((uint32_t)0x1FFFF800U)
#define FLASHSIZE_BASE        ((uint32_t)0x1FFFF7CCU)
#define UID_BASE              ((uint32_t)0x1FFFF7ACU)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x00003000U)
#define TSC_BASE              (AHB1PERIPH_BASE + 0x00004000U)


#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x00000000U)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x00000400U)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x00000800U)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x00000C00U)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x00001400U)


#define ADC1_BASE             (AHB3PERIPH_BASE + 0x00000000U)
#define ADC2_BASE             (AHB3PERIPH_BASE + 0x00000100U)
#define ADC1_2_COMMON_BASE    (AHB3PERIPH_BASE + 0x00000300U)

#define DBGMCU_BASE          ((uint32_t)0xE0042000U)







#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3              ((USART_TypeDef *) USART3_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define CAN                 ((CAN_TypeDef *) CAN_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define DAC                 ((DAC_TypeDef *) DAC_BASE)
#define DAC1                ((DAC_TypeDef *) DAC1_BASE)
#define DAC2                ((DAC_TypeDef *) DAC2_BASE)
#define COMP2               ((COMP_TypeDef *) COMP2_BASE)
#define COMP4               ((COMP_TypeDef *) COMP4_BASE)
#define COMP6               ((COMP_TypeDef *) COMP6_BASE)

#define COMP                ((COMP_TypeDef *) COMP_BASE)
#define OPAMP               ((OPAMP_TypeDef *) OPAMP_BASE)
#define OPAMP2              ((OPAMP_TypeDef *) OPAMP2_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define TIM15               ((TIM_TypeDef *) TIM15_BASE)
#define TIM16               ((TIM_TypeDef *) TIM16_BASE)
#define TIM17               ((TIM_TypeDef *) TIM17_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#define DMA1                ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#define OB                  ((OB_TypeDef *) OB_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define TSC                 ((TSC_TypeDef *) TSC_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#define ADC12_COMMON        ((ADC_Common_TypeDef *) ADC1_2_COMMON_BASE)

#define ADC1_2_COMMON       ADC12_COMMON























#define ADC5_V1_1




#define ADC_MULTIMODE_SUPPORT


#define ADC_ISR_ADRDY_Pos              (0U)
#define ADC_ISR_ADRDY_Msk              (0x1U << ADC_ISR_ADRDY_Pos)
#define ADC_ISR_ADRDY                  ADC_ISR_ADRDY_Msk
#define ADC_ISR_EOSMP_Pos              (1U)
#define ADC_ISR_EOSMP_Msk              (0x1U << ADC_ISR_EOSMP_Pos)
#define ADC_ISR_EOSMP                  ADC_ISR_EOSMP_Msk
#define ADC_ISR_EOC_Pos                (2U)
#define ADC_ISR_EOC_Msk                (0x1U << ADC_ISR_EOC_Pos)
#define ADC_ISR_EOC                    ADC_ISR_EOC_Msk
#define ADC_ISR_EOS_Pos                (3U)
#define ADC_ISR_EOS_Msk                (0x1U << ADC_ISR_EOS_Pos)
#define ADC_ISR_EOS                    ADC_ISR_EOS_Msk
#define ADC_ISR_OVR_Pos                (4U)
#define ADC_ISR_OVR_Msk                (0x1U << ADC_ISR_OVR_Pos)
#define ADC_ISR_OVR                    ADC_ISR_OVR_Msk
#define ADC_ISR_JEOC_Pos               (5U)
#define ADC_ISR_JEOC_Msk               (0x1U << ADC_ISR_JEOC_Pos)
#define ADC_ISR_JEOC                   ADC_ISR_JEOC_Msk
#define ADC_ISR_JEOS_Pos               (6U)
#define ADC_ISR_JEOS_Msk               (0x1U << ADC_ISR_JEOS_Pos)
#define ADC_ISR_JEOS                   ADC_ISR_JEOS_Msk
#define ADC_ISR_AWD1_Pos               (7U)
#define ADC_ISR_AWD1_Msk               (0x1U << ADC_ISR_AWD1_Pos)
#define ADC_ISR_AWD1                   ADC_ISR_AWD1_Msk
#define ADC_ISR_AWD2_Pos               (8U)
#define ADC_ISR_AWD2_Msk               (0x1U << ADC_ISR_AWD2_Pos)
#define ADC_ISR_AWD2                   ADC_ISR_AWD2_Msk
#define ADC_ISR_AWD3_Pos               (9U)
#define ADC_ISR_AWD3_Msk               (0x1U << ADC_ISR_AWD3_Pos)
#define ADC_ISR_AWD3                   ADC_ISR_AWD3_Msk
#define ADC_ISR_JQOVF_Pos              (10U)
#define ADC_ISR_JQOVF_Msk              (0x1U << ADC_ISR_JQOVF_Pos)
#define ADC_ISR_JQOVF                  ADC_ISR_JQOVF_Msk


#define ADC_ISR_ADRD            (ADC_ISR_ADRDY)


#define ADC_IER_ADRDYIE_Pos            (0U)
#define ADC_IER_ADRDYIE_Msk            (0x1U << ADC_IER_ADRDYIE_Pos)
#define ADC_IER_ADRDYIE                ADC_IER_ADRDYIE_Msk
#define ADC_IER_EOSMPIE_Pos            (1U)
#define ADC_IER_EOSMPIE_Msk            (0x1U << ADC_IER_EOSMPIE_Pos)
#define ADC_IER_EOSMPIE                ADC_IER_EOSMPIE_Msk
#define ADC_IER_EOCIE_Pos              (2U)
#define ADC_IER_EOCIE_Msk              (0x1U << ADC_IER_EOCIE_Pos)
#define ADC_IER_EOCIE                  ADC_IER_EOCIE_Msk
#define ADC_IER_EOSIE_Pos              (3U)
#define ADC_IER_EOSIE_Msk              (0x1U << ADC_IER_EOSIE_Pos)
#define ADC_IER_EOSIE                  ADC_IER_EOSIE_Msk
#define ADC_IER_OVRIE_Pos              (4U)
#define ADC_IER_OVRIE_Msk              (0x1U << ADC_IER_OVRIE_Pos)
#define ADC_IER_OVRIE                  ADC_IER_OVRIE_Msk
#define ADC_IER_JEOCIE_Pos             (5U)
#define ADC_IER_JEOCIE_Msk             (0x1U << ADC_IER_JEOCIE_Pos)
#define ADC_IER_JEOCIE                 ADC_IER_JEOCIE_Msk
#define ADC_IER_JEOSIE_Pos             (6U)
#define ADC_IER_JEOSIE_Msk             (0x1U << ADC_IER_JEOSIE_Pos)
#define ADC_IER_JEOSIE                 ADC_IER_JEOSIE_Msk
#define ADC_IER_AWD1IE_Pos             (7U)
#define ADC_IER_AWD1IE_Msk             (0x1U << ADC_IER_AWD1IE_Pos)
#define ADC_IER_AWD1IE                 ADC_IER_AWD1IE_Msk
#define ADC_IER_AWD2IE_Pos             (8U)
#define ADC_IER_AWD2IE_Msk             (0x1U << ADC_IER_AWD2IE_Pos)
#define ADC_IER_AWD2IE                 ADC_IER_AWD2IE_Msk
#define ADC_IER_AWD3IE_Pos             (9U)
#define ADC_IER_AWD3IE_Msk             (0x1U << ADC_IER_AWD3IE_Pos)
#define ADC_IER_AWD3IE                 ADC_IER_AWD3IE_Msk
#define ADC_IER_JQOVFIE_Pos            (10U)
#define ADC_IER_JQOVFIE_Msk            (0x1U << ADC_IER_JQOVFIE_Pos)
#define ADC_IER_JQOVFIE                ADC_IER_JQOVFIE_Msk


#define ADC_IER_RDY             (ADC_IER_ADRDYIE)
#define ADC_IER_EOSMP           (ADC_IER_EOSMPIE)
#define ADC_IER_EOC             (ADC_IER_EOCIE)
#define ADC_IER_EOS             (ADC_IER_EOSIE)
#define ADC_IER_OVR             (ADC_IER_OVRIE)
#define ADC_IER_JEOC            (ADC_IER_JEOCIE)
#define ADC_IER_JEOS            (ADC_IER_JEOSIE)
#define ADC_IER_AWD1            (ADC_IER_AWD1IE)
#define ADC_IER_AWD2            (ADC_IER_AWD2IE)
#define ADC_IER_AWD3            (ADC_IER_AWD3IE)
#define ADC_IER_JQOVF           (ADC_IER_JQOVFIE)


#define ADC_CR_ADEN_Pos                (0U)
#define ADC_CR_ADEN_Msk                (0x1U << ADC_CR_ADEN_Pos)
#define ADC_CR_ADEN                    ADC_CR_ADEN_Msk
#define ADC_CR_ADDIS_Pos               (1U)
#define ADC_CR_ADDIS_Msk               (0x1U << ADC_CR_ADDIS_Pos)
#define ADC_CR_ADDIS                   ADC_CR_ADDIS_Msk
#define ADC_CR_ADSTART_Pos             (2U)
#define ADC_CR_ADSTART_Msk             (0x1U << ADC_CR_ADSTART_Pos)
#define ADC_CR_ADSTART                 ADC_CR_ADSTART_Msk
#define ADC_CR_JADSTART_Pos            (3U)
#define ADC_CR_JADSTART_Msk            (0x1U << ADC_CR_JADSTART_Pos)
#define ADC_CR_JADSTART                ADC_CR_JADSTART_Msk
#define ADC_CR_ADSTP_Pos               (4U)
#define ADC_CR_ADSTP_Msk               (0x1U << ADC_CR_ADSTP_Pos)
#define ADC_CR_ADSTP                   ADC_CR_ADSTP_Msk
#define ADC_CR_JADSTP_Pos              (5U)
#define ADC_CR_JADSTP_Msk              (0x1U << ADC_CR_JADSTP_Pos)
#define ADC_CR_JADSTP                  ADC_CR_JADSTP_Msk
#define ADC_CR_ADVREGEN_Pos            (28U)
#define ADC_CR_ADVREGEN_Msk            (0x3U << ADC_CR_ADVREGEN_Pos)
#define ADC_CR_ADVREGEN                ADC_CR_ADVREGEN_Msk
#define ADC_CR_ADVREGEN_0              (0x1U << ADC_CR_ADVREGEN_Pos)
#define ADC_CR_ADVREGEN_1              (0x2U << ADC_CR_ADVREGEN_Pos)
#define ADC_CR_ADCALDIF_Pos            (30U)
#define ADC_CR_ADCALDIF_Msk            (0x1U << ADC_CR_ADCALDIF_Pos)
#define ADC_CR_ADCALDIF                ADC_CR_ADCALDIF_Msk
#define ADC_CR_ADCAL_Pos               (31U)
#define ADC_CR_ADCAL_Msk               (0x1U << ADC_CR_ADCAL_Pos)
#define ADC_CR_ADCAL                   ADC_CR_ADCAL_Msk


#define ADC_CFGR_DMAEN_Pos             (0U)
#define ADC_CFGR_DMAEN_Msk             (0x1U << ADC_CFGR_DMAEN_Pos)
#define ADC_CFGR_DMAEN                 ADC_CFGR_DMAEN_Msk
#define ADC_CFGR_DMACFG_Pos            (1U)
#define ADC_CFGR_DMACFG_Msk            (0x1U << ADC_CFGR_DMACFG_Pos)
#define ADC_CFGR_DMACFG                ADC_CFGR_DMACFG_Msk

#define ADC_CFGR_RES_Pos               (3U)
#define ADC_CFGR_RES_Msk               (0x3U << ADC_CFGR_RES_Pos)
#define ADC_CFGR_RES                   ADC_CFGR_RES_Msk
#define ADC_CFGR_RES_0                 (0x1U << ADC_CFGR_RES_Pos)
#define ADC_CFGR_RES_1                 (0x2U << ADC_CFGR_RES_Pos)

#define ADC_CFGR_ALIGN_Pos             (5U)
#define ADC_CFGR_ALIGN_Msk             (0x1U << ADC_CFGR_ALIGN_Pos)
#define ADC_CFGR_ALIGN                 ADC_CFGR_ALIGN_Msk

#define ADC_CFGR_EXTSEL_Pos            (6U)
#define ADC_CFGR_EXTSEL_Msk            (0xFU << ADC_CFGR_EXTSEL_Pos)
#define ADC_CFGR_EXTSEL                ADC_CFGR_EXTSEL_Msk
#define ADC_CFGR_EXTSEL_0              (0x1U << ADC_CFGR_EXTSEL_Pos)
#define ADC_CFGR_EXTSEL_1              (0x2U << ADC_CFGR_EXTSEL_Pos)
#define ADC_CFGR_EXTSEL_2              (0x4U << ADC_CFGR_EXTSEL_Pos)
#define ADC_CFGR_EXTSEL_3              (0x8U << ADC_CFGR_EXTSEL_Pos)

#define ADC_CFGR_EXTEN_Pos             (10U)
#define ADC_CFGR_EXTEN_Msk             (0x3U << ADC_CFGR_EXTEN_Pos)
#define ADC_CFGR_EXTEN                 ADC_CFGR_EXTEN_Msk
#define ADC_CFGR_EXTEN_0               (0x1U << ADC_CFGR_EXTEN_Pos)
#define ADC_CFGR_EXTEN_1               (0x2U << ADC_CFGR_EXTEN_Pos)

#define ADC_CFGR_OVRMOD_Pos            (12U)
#define ADC_CFGR_OVRMOD_Msk            (0x1U << ADC_CFGR_OVRMOD_Pos)
#define ADC_CFGR_OVRMOD                ADC_CFGR_OVRMOD_Msk
#define ADC_CFGR_CONT_Pos              (13U)
#define ADC_CFGR_CONT_Msk              (0x1U << ADC_CFGR_CONT_Pos)
#define ADC_CFGR_CONT                  ADC_CFGR_CONT_Msk
#define ADC_CFGR_AUTDLY_Pos            (14U)
#define ADC_CFGR_AUTDLY_Msk            (0x1U << ADC_CFGR_AUTDLY_Pos)
#define ADC_CFGR_AUTDLY                ADC_CFGR_AUTDLY_Msk

#define ADC_CFGR_DISCEN_Pos            (16U)
#define ADC_CFGR_DISCEN_Msk            (0x1U << ADC_CFGR_DISCEN_Pos)
#define ADC_CFGR_DISCEN                ADC_CFGR_DISCEN_Msk

#define ADC_CFGR_DISCNUM_Pos           (17U)
#define ADC_CFGR_DISCNUM_Msk           (0x7U << ADC_CFGR_DISCNUM_Pos)
#define ADC_CFGR_DISCNUM               ADC_CFGR_DISCNUM_Msk
#define ADC_CFGR_DISCNUM_0             (0x1U << ADC_CFGR_DISCNUM_Pos)
#define ADC_CFGR_DISCNUM_1             (0x2U << ADC_CFGR_DISCNUM_Pos)
#define ADC_CFGR_DISCNUM_2             (0x4U << ADC_CFGR_DISCNUM_Pos)

#define ADC_CFGR_JDISCEN_Pos           (20U)
#define ADC_CFGR_JDISCEN_Msk           (0x1U << ADC_CFGR_JDISCEN_Pos)
#define ADC_CFGR_JDISCEN               ADC_CFGR_JDISCEN_Msk
#define ADC_CFGR_JQM_Pos               (21U)
#define ADC_CFGR_JQM_Msk               (0x1U << ADC_CFGR_JQM_Pos)
#define ADC_CFGR_JQM                   ADC_CFGR_JQM_Msk
#define ADC_CFGR_AWD1SGL_Pos           (22U)
#define ADC_CFGR_AWD1SGL_Msk           (0x1U << ADC_CFGR_AWD1SGL_Pos)
#define ADC_CFGR_AWD1SGL               ADC_CFGR_AWD1SGL_Msk
#define ADC_CFGR_AWD1EN_Pos            (23U)
#define ADC_CFGR_AWD1EN_Msk            (0x1U << ADC_CFGR_AWD1EN_Pos)
#define ADC_CFGR_AWD1EN                ADC_CFGR_AWD1EN_Msk
#define ADC_CFGR_JAWD1EN_Pos           (24U)
#define ADC_CFGR_JAWD1EN_Msk           (0x1U << ADC_CFGR_JAWD1EN_Pos)
#define ADC_CFGR_JAWD1EN               ADC_CFGR_JAWD1EN_Msk
#define ADC_CFGR_JAUTO_Pos             (25U)
#define ADC_CFGR_JAUTO_Msk             (0x1U << ADC_CFGR_JAUTO_Pos)
#define ADC_CFGR_JAUTO                 ADC_CFGR_JAUTO_Msk

#define ADC_CFGR_AWD1CH_Pos            (26U)
#define ADC_CFGR_AWD1CH_Msk            (0x1FU << ADC_CFGR_AWD1CH_Pos)
#define ADC_CFGR_AWD1CH                ADC_CFGR_AWD1CH_Msk
#define ADC_CFGR_AWD1CH_0              (0x01U << ADC_CFGR_AWD1CH_Pos)
#define ADC_CFGR_AWD1CH_1              (0x02U << ADC_CFGR_AWD1CH_Pos)
#define ADC_CFGR_AWD1CH_2              (0x04U << ADC_CFGR_AWD1CH_Pos)
#define ADC_CFGR_AWD1CH_3              (0x08U << ADC_CFGR_AWD1CH_Pos)
#define ADC_CFGR_AWD1CH_4              (0x10U << ADC_CFGR_AWD1CH_Pos)


#define ADC_CFGR_AUTOFF_Pos            (15U)
#define ADC_CFGR_AUTOFF_Msk            (0x1U << ADC_CFGR_AUTOFF_Pos)
#define ADC_CFGR_AUTOFF                ADC_CFGR_AUTOFF_Msk


#define ADC_SMPR1_SMP0_Pos             (0U)
#define ADC_SMPR1_SMP0_Msk             (0x7U << ADC_SMPR1_SMP0_Pos)
#define ADC_SMPR1_SMP0                 ADC_SMPR1_SMP0_Msk
#define ADC_SMPR1_SMP0_0               (0x1U << ADC_SMPR1_SMP0_Pos)
#define ADC_SMPR1_SMP0_1               (0x2U << ADC_SMPR1_SMP0_Pos)
#define ADC_SMPR1_SMP0_2               (0x4U << ADC_SMPR1_SMP0_Pos)

#define ADC_SMPR1_SMP1_Pos             (3U)
#define ADC_SMPR1_SMP1_Msk             (0x7U << ADC_SMPR1_SMP1_Pos)
#define ADC_SMPR1_SMP1                 ADC_SMPR1_SMP1_Msk
#define ADC_SMPR1_SMP1_0               (0x1U << ADC_SMPR1_SMP1_Pos)
#define ADC_SMPR1_SMP1_1               (0x2U << ADC_SMPR1_SMP1_Pos)
#define ADC_SMPR1_SMP1_2               (0x4U << ADC_SMPR1_SMP1_Pos)

#define ADC_SMPR1_SMP2_Pos             (6U)
#define ADC_SMPR1_SMP2_Msk             (0x7U << ADC_SMPR1_SMP2_Pos)
#define ADC_SMPR1_SMP2                 ADC_SMPR1_SMP2_Msk
#define ADC_SMPR1_SMP2_0               (0x1U << ADC_SMPR1_SMP2_Pos)
#define ADC_SMPR1_SMP2_1               (0x2U << ADC_SMPR1_SMP2_Pos)
#define ADC_SMPR1_SMP2_2               (0x4U << ADC_SMPR1_SMP2_Pos)

#define ADC_SMPR1_SMP3_Pos             (9U)
#define ADC_SMPR1_SMP3_Msk             (0x7U << ADC_SMPR1_SMP3_Pos)
#define ADC_SMPR1_SMP3                 ADC_SMPR1_SMP3_Msk
#define ADC_SMPR1_SMP3_0               (0x1U << ADC_SMPR1_SMP3_Pos)
#define ADC_SMPR1_SMP3_1               (0x2U << ADC_SMPR1_SMP3_Pos)
#define ADC_SMPR1_SMP3_2               (0x4U << ADC_SMPR1_SMP3_Pos)

#define ADC_SMPR1_SMP4_Pos             (12U)
#define ADC_SMPR1_SMP4_Msk             (0x7U << ADC_SMPR1_SMP4_Pos)
#define ADC_SMPR1_SMP4                 ADC_SMPR1_SMP4_Msk
#define ADC_SMPR1_SMP4_0               (0x1U << ADC_SMPR1_SMP4_Pos)
#define ADC_SMPR1_SMP4_1               (0x2U << ADC_SMPR1_SMP4_Pos)
#define ADC_SMPR1_SMP4_2               (0x4U << ADC_SMPR1_SMP4_Pos)

#define ADC_SMPR1_SMP5_Pos             (15U)
#define ADC_SMPR1_SMP5_Msk             (0x7U << ADC_SMPR1_SMP5_Pos)
#define ADC_SMPR1_SMP5                 ADC_SMPR1_SMP5_Msk
#define ADC_SMPR1_SMP5_0               (0x1U << ADC_SMPR1_SMP5_Pos)
#define ADC_SMPR1_SMP5_1               (0x2U << ADC_SMPR1_SMP5_Pos)
#define ADC_SMPR1_SMP5_2               (0x4U << ADC_SMPR1_SMP5_Pos)

#define ADC_SMPR1_SMP6_Pos             (18U)
#define ADC_SMPR1_SMP6_Msk             (0x7U << ADC_SMPR1_SMP6_Pos)
#define ADC_SMPR1_SMP6                 ADC_SMPR1_SMP6_Msk
#define ADC_SMPR1_SMP6_0               (0x1U << ADC_SMPR1_SMP6_Pos)
#define ADC_SMPR1_SMP6_1               (0x2U << ADC_SMPR1_SMP6_Pos)
#define ADC_SMPR1_SMP6_2               (0x4U << ADC_SMPR1_SMP6_Pos)

#define ADC_SMPR1_SMP7_Pos             (21U)
#define ADC_SMPR1_SMP7_Msk             (0x7U << ADC_SMPR1_SMP7_Pos)
#define ADC_SMPR1_SMP7                 ADC_SMPR1_SMP7_Msk
#define ADC_SMPR1_SMP7_0               (0x1U << ADC_SMPR1_SMP7_Pos)
#define ADC_SMPR1_SMP7_1               (0x2U << ADC_SMPR1_SMP7_Pos)
#define ADC_SMPR1_SMP7_2               (0x4U << ADC_SMPR1_SMP7_Pos)

#define ADC_SMPR1_SMP8_Pos             (24U)
#define ADC_SMPR1_SMP8_Msk             (0x7U << ADC_SMPR1_SMP8_Pos)
#define ADC_SMPR1_SMP8                 ADC_SMPR1_SMP8_Msk
#define ADC_SMPR1_SMP8_0               (0x1U << ADC_SMPR1_SMP8_Pos)
#define ADC_SMPR1_SMP8_1               (0x2U << ADC_SMPR1_SMP8_Pos)
#define ADC_SMPR1_SMP8_2               (0x4U << ADC_SMPR1_SMP8_Pos)

#define ADC_SMPR1_SMP9_Pos             (27U)
#define ADC_SMPR1_SMP9_Msk             (0x7U << ADC_SMPR1_SMP9_Pos)
#define ADC_SMPR1_SMP9                 ADC_SMPR1_SMP9_Msk
#define ADC_SMPR1_SMP9_0               (0x1U << ADC_SMPR1_SMP9_Pos)
#define ADC_SMPR1_SMP9_1               (0x2U << ADC_SMPR1_SMP9_Pos)
#define ADC_SMPR1_SMP9_2               (0x4U << ADC_SMPR1_SMP9_Pos)


#define ADC_SMPR2_SMP10_Pos            (0U)
#define ADC_SMPR2_SMP10_Msk            (0x7U << ADC_SMPR2_SMP10_Pos)
#define ADC_SMPR2_SMP10                ADC_SMPR2_SMP10_Msk
#define ADC_SMPR2_SMP10_0              (0x1U << ADC_SMPR2_SMP10_Pos)
#define ADC_SMPR2_SMP10_1              (0x2U << ADC_SMPR2_SMP10_Pos)
#define ADC_SMPR2_SMP10_2              (0x4U << ADC_SMPR2_SMP10_Pos)

#define ADC_SMPR2_SMP11_Pos            (3U)
#define ADC_SMPR2_SMP11_Msk            (0x7U << ADC_SMPR2_SMP11_Pos)
#define ADC_SMPR2_SMP11                ADC_SMPR2_SMP11_Msk
#define ADC_SMPR2_SMP11_0              (0x1U << ADC_SMPR2_SMP11_Pos)
#define ADC_SMPR2_SMP11_1              (0x2U << ADC_SMPR2_SMP11_Pos)
#define ADC_SMPR2_SMP11_2              (0x4U << ADC_SMPR2_SMP11_Pos)

#define ADC_SMPR2_SMP12_Pos            (6U)
#define ADC_SMPR2_SMP12_Msk            (0x7U << ADC_SMPR2_SMP12_Pos)
#define ADC_SMPR2_SMP12                ADC_SMPR2_SMP12_Msk
#define ADC_SMPR2_SMP12_0              (0x1U << ADC_SMPR2_SMP12_Pos)
#define ADC_SMPR2_SMP12_1              (0x2U << ADC_SMPR2_SMP12_Pos)
#define ADC_SMPR2_SMP12_2              (0x4U << ADC_SMPR2_SMP12_Pos)

#define ADC_SMPR2_SMP13_Pos            (9U)
#define ADC_SMPR2_SMP13_Msk            (0x7U << ADC_SMPR2_SMP13_Pos)
#define ADC_SMPR2_SMP13                ADC_SMPR2_SMP13_Msk
#define ADC_SMPR2_SMP13_0              (0x1U << ADC_SMPR2_SMP13_Pos)
#define ADC_SMPR2_SMP13_1              (0x2U << ADC_SMPR2_SMP13_Pos)
#define ADC_SMPR2_SMP13_2              (0x4U << ADC_SMPR2_SMP13_Pos)

#define ADC_SMPR2_SMP14_Pos            (12U)
#define ADC_SMPR2_SMP14_Msk            (0x7U << ADC_SMPR2_SMP14_Pos)
#define ADC_SMPR2_SMP14                ADC_SMPR2_SMP14_Msk
#define ADC_SMPR2_SMP14_0              (0x1U << ADC_SMPR2_SMP14_Pos)
#define ADC_SMPR2_SMP14_1              (0x2U << ADC_SMPR2_SMP14_Pos)
#define ADC_SMPR2_SMP14_2              (0x4U << ADC_SMPR2_SMP14_Pos)

#define ADC_SMPR2_SMP15_Pos            (15U)
#define ADC_SMPR2_SMP15_Msk            (0x7U << ADC_SMPR2_SMP15_Pos)
#define ADC_SMPR2_SMP15                ADC_SMPR2_SMP15_Msk
#define ADC_SMPR2_SMP15_0              (0x1U << ADC_SMPR2_SMP15_Pos)
#define ADC_SMPR2_SMP15_1              (0x2U << ADC_SMPR2_SMP15_Pos)
#define ADC_SMPR2_SMP15_2              (0x4U << ADC_SMPR2_SMP15_Pos)

#define ADC_SMPR2_SMP16_Pos            (18U)
#define ADC_SMPR2_SMP16_Msk            (0x7U << ADC_SMPR2_SMP16_Pos)
#define ADC_SMPR2_SMP16                ADC_SMPR2_SMP16_Msk
#define ADC_SMPR2_SMP16_0              (0x1U << ADC_SMPR2_SMP16_Pos)
#define ADC_SMPR2_SMP16_1              (0x2U << ADC_SMPR2_SMP16_Pos)
#define ADC_SMPR2_SMP16_2              (0x4U << ADC_SMPR2_SMP16_Pos)

#define ADC_SMPR2_SMP17_Pos            (21U)
#define ADC_SMPR2_SMP17_Msk            (0x7U << ADC_SMPR2_SMP17_Pos)
#define ADC_SMPR2_SMP17                ADC_SMPR2_SMP17_Msk
#define ADC_SMPR2_SMP17_0              (0x1U << ADC_SMPR2_SMP17_Pos)
#define ADC_SMPR2_SMP17_1              (0x2U << ADC_SMPR2_SMP17_Pos)
#define ADC_SMPR2_SMP17_2              (0x4U << ADC_SMPR2_SMP17_Pos)

#define ADC_SMPR2_SMP18_Pos            (24U)
#define ADC_SMPR2_SMP18_Msk            (0x7U << ADC_SMPR2_SMP18_Pos)
#define ADC_SMPR2_SMP18                ADC_SMPR2_SMP18_Msk
#define ADC_SMPR2_SMP18_0              (0x1U << ADC_SMPR2_SMP18_Pos)
#define ADC_SMPR2_SMP18_1              (0x2U << ADC_SMPR2_SMP18_Pos)
#define ADC_SMPR2_SMP18_2              (0x4U << ADC_SMPR2_SMP18_Pos)


#define ADC_TR1_LT1_Pos                (0U)
#define ADC_TR1_LT1_Msk                (0xFFFU << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1                    ADC_TR1_LT1_Msk
#define ADC_TR1_LT1_0                  (0x001U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_1                  (0x002U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_2                  (0x004U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_3                  (0x008U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_4                  (0x010U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_5                  (0x020U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_6                  (0x040U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_7                  (0x080U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_8                  (0x100U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_9                  (0x200U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_10                 (0x400U << ADC_TR1_LT1_Pos)
#define ADC_TR1_LT1_11                 (0x800U << ADC_TR1_LT1_Pos)

#define ADC_TR1_HT1_Pos                (16U)
#define ADC_TR1_HT1_Msk                (0xFFFU << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1                    ADC_TR1_HT1_Msk
#define ADC_TR1_HT1_0                  (0x001U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_1                  (0x002U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_2                  (0x004U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_3                  (0x008U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_4                  (0x010U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_5                  (0x020U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_6                  (0x040U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_7                  (0x080U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_8                  (0x100U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_9                  (0x200U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_10                 (0x400U << ADC_TR1_HT1_Pos)
#define ADC_TR1_HT1_11                 (0x800U << ADC_TR1_HT1_Pos)


#define ADC_TR2_LT2_Pos                (0U)
#define ADC_TR2_LT2_Msk                (0xFFU << ADC_TR2_LT2_Pos)
#define ADC_TR2_LT2                    ADC_TR2_LT2_Msk
#define ADC_TR2_LT2_0                  (0x01U << ADC_TR2_LT2_Pos)
#define ADC_TR2_LT2_1                  (0x02U << ADC_TR2_LT2_Pos)
#define ADC_TR2_LT2_2                  (0x04U << ADC_TR2_LT2_Pos)
#define ADC_TR2_LT2_3                  (0x08U << ADC_TR2_LT2_Pos)
#define ADC_TR2_LT2_4                  (0x10U << ADC_TR2_LT2_Pos)
#define ADC_TR2_LT2_5                  (0x20U << ADC_TR2_LT2_Pos)
#define ADC_TR2_LT2_6                  (0x40U << ADC_TR2_LT2_Pos)
#define ADC_TR2_LT2_7                  (0x80U << ADC_TR2_LT2_Pos)

#define ADC_TR2_HT2_Pos                (16U)
#define ADC_TR2_HT2_Msk                (0xFFU << ADC_TR2_HT2_Pos)
#define ADC_TR2_HT2                    ADC_TR2_HT2_Msk
#define ADC_TR2_HT2_0                  (0x01U << ADC_TR2_HT2_Pos)
#define ADC_TR2_HT2_1                  (0x02U << ADC_TR2_HT2_Pos)
#define ADC_TR2_HT2_2                  (0x04U << ADC_TR2_HT2_Pos)
#define ADC_TR2_HT2_3                  (0x08U << ADC_TR2_HT2_Pos)
#define ADC_TR2_HT2_4                  (0x10U << ADC_TR2_HT2_Pos)
#define ADC_TR2_HT2_5                  (0x20U << ADC_TR2_HT2_Pos)
#define ADC_TR2_HT2_6                  (0x40U << ADC_TR2_HT2_Pos)
#define ADC_TR2_HT2_7                  (0x80U << ADC_TR2_HT2_Pos)


#define ADC_TR3_LT3_Pos                (0U)
#define ADC_TR3_LT3_Msk                (0xFFU << ADC_TR3_LT3_Pos)
#define ADC_TR3_LT3                    ADC_TR3_LT3_Msk
#define ADC_TR3_LT3_0                  (0x01U << ADC_TR3_LT3_Pos)
#define ADC_TR3_LT3_1                  (0x02U << ADC_TR3_LT3_Pos)
#define ADC_TR3_LT3_2                  (0x04U << ADC_TR3_LT3_Pos)
#define ADC_TR3_LT3_3                  (0x08U << ADC_TR3_LT3_Pos)
#define ADC_TR3_LT3_4                  (0x10U << ADC_TR3_LT3_Pos)
#define ADC_TR3_LT3_5                  (0x20U << ADC_TR3_LT3_Pos)
#define ADC_TR3_LT3_6                  (0x40U << ADC_TR3_LT3_Pos)
#define ADC_TR3_LT3_7                  (0x80U << ADC_TR3_LT3_Pos)

#define ADC_TR3_HT3_Pos                (16U)
#define ADC_TR3_HT3_Msk                (0xFFU << ADC_TR3_HT3_Pos)
#define ADC_TR3_HT3                    ADC_TR3_HT3_Msk
#define ADC_TR3_HT3_0                  (0x01U << ADC_TR3_HT3_Pos)
#define ADC_TR3_HT3_1                  (0x02U << ADC_TR3_HT3_Pos)
#define ADC_TR3_HT3_2                  (0x04U << ADC_TR3_HT3_Pos)
#define ADC_TR3_HT3_3                  (0x08U << ADC_TR3_HT3_Pos)
#define ADC_TR3_HT3_4                  (0x10U << ADC_TR3_HT3_Pos)
#define ADC_TR3_HT3_5                  (0x20U << ADC_TR3_HT3_Pos)
#define ADC_TR3_HT3_6                  (0x40U << ADC_TR3_HT3_Pos)
#define ADC_TR3_HT3_7                  (0x80U << ADC_TR3_HT3_Pos)


#define ADC_SQR1_L_Pos                 (0U)
#define ADC_SQR1_L_Msk                 (0xFU << ADC_SQR1_L_Pos)
#define ADC_SQR1_L                     ADC_SQR1_L_Msk
#define ADC_SQR1_L_0                   (0x1U << ADC_SQR1_L_Pos)
#define ADC_SQR1_L_1                   (0x2U << ADC_SQR1_L_Pos)
#define ADC_SQR1_L_2                   (0x4U << ADC_SQR1_L_Pos)
#define ADC_SQR1_L_3                   (0x8U << ADC_SQR1_L_Pos)

#define ADC_SQR1_SQ1_Pos               (6U)
#define ADC_SQR1_SQ1_Msk               (0x1FU << ADC_SQR1_SQ1_Pos)
#define ADC_SQR1_SQ1                   ADC_SQR1_SQ1_Msk
#define ADC_SQR1_SQ1_0                 (0x01U << ADC_SQR1_SQ1_Pos)
#define ADC_SQR1_SQ1_1                 (0x02U << ADC_SQR1_SQ1_Pos)
#define ADC_SQR1_SQ1_2                 (0x04U << ADC_SQR1_SQ1_Pos)
#define ADC_SQR1_SQ1_3                 (0x08U << ADC_SQR1_SQ1_Pos)
#define ADC_SQR1_SQ1_4                 (0x10U << ADC_SQR1_SQ1_Pos)

#define ADC_SQR1_SQ2_Pos               (12U)
#define ADC_SQR1_SQ2_Msk               (0x1FU << ADC_SQR1_SQ2_Pos)
#define ADC_SQR1_SQ2                   ADC_SQR1_SQ2_Msk
#define ADC_SQR1_SQ2_0                 (0x01U << ADC_SQR1_SQ2_Pos)
#define ADC_SQR1_SQ2_1                 (0x02U << ADC_SQR1_SQ2_Pos)
#define ADC_SQR1_SQ2_2                 (0x04U << ADC_SQR1_SQ2_Pos)
#define ADC_SQR1_SQ2_3                 (0x08U << ADC_SQR1_SQ2_Pos)
#define ADC_SQR1_SQ2_4                 (0x10U << ADC_SQR1_SQ2_Pos)

#define ADC_SQR1_SQ3_Pos               (18U)
#define ADC_SQR1_SQ3_Msk               (0x1FU << ADC_SQR1_SQ3_Pos)
#define ADC_SQR1_SQ3                   ADC_SQR1_SQ3_Msk
#define ADC_SQR1_SQ3_0                 (0x01U << ADC_SQR1_SQ3_Pos)
#define ADC_SQR1_SQ3_1                 (0x02U << ADC_SQR1_SQ3_Pos)
#define ADC_SQR1_SQ3_2                 (0x04U << ADC_SQR1_SQ3_Pos)
#define ADC_SQR1_SQ3_3                 (0x08U << ADC_SQR1_SQ3_Pos)
#define ADC_SQR1_SQ3_4                 (0x10U << ADC_SQR1_SQ3_Pos)

#define ADC_SQR1_SQ4_Pos               (24U)
#define ADC_SQR1_SQ4_Msk               (0x1FU << ADC_SQR1_SQ4_Pos)
#define ADC_SQR1_SQ4                   ADC_SQR1_SQ4_Msk
#define ADC_SQR1_SQ4_0                 (0x01U << ADC_SQR1_SQ4_Pos)
#define ADC_SQR1_SQ4_1                 (0x02U << ADC_SQR1_SQ4_Pos)
#define ADC_SQR1_SQ4_2                 (0x04U << ADC_SQR1_SQ4_Pos)
#define ADC_SQR1_SQ4_3                 (0x08U << ADC_SQR1_SQ4_Pos)
#define ADC_SQR1_SQ4_4                 (0x10U << ADC_SQR1_SQ4_Pos)


#define ADC_SQR2_SQ5_Pos               (0U)
#define ADC_SQR2_SQ5_Msk               (0x1FU << ADC_SQR2_SQ5_Pos)
#define ADC_SQR2_SQ5                   ADC_SQR2_SQ5_Msk
#define ADC_SQR2_SQ5_0                 (0x01U << ADC_SQR2_SQ5_Pos)
#define ADC_SQR2_SQ5_1                 (0x02U << ADC_SQR2_SQ5_Pos)
#define ADC_SQR2_SQ5_2                 (0x04U << ADC_SQR2_SQ5_Pos)
#define ADC_SQR2_SQ5_3                 (0x08U << ADC_SQR2_SQ5_Pos)
#define ADC_SQR2_SQ5_4                 (0x10U << ADC_SQR2_SQ5_Pos)

#define ADC_SQR2_SQ6_Pos               (6U)
#define ADC_SQR2_SQ6_Msk               (0x1FU << ADC_SQR2_SQ6_Pos)
#define ADC_SQR2_SQ6                   ADC_SQR2_SQ6_Msk
#define ADC_SQR2_SQ6_0                 (0x01U << ADC_SQR2_SQ6_Pos)
#define ADC_SQR2_SQ6_1                 (0x02U << ADC_SQR2_SQ6_Pos)
#define ADC_SQR2_SQ6_2                 (0x04U << ADC_SQR2_SQ6_Pos)
#define ADC_SQR2_SQ6_3                 (0x08U << ADC_SQR2_SQ6_Pos)
#define ADC_SQR2_SQ6_4                 (0x10U << ADC_SQR2_SQ6_Pos)

#define ADC_SQR2_SQ7_Pos               (12U)
#define ADC_SQR2_SQ7_Msk               (0x1FU << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7                   ADC_SQR2_SQ7_Msk
#define ADC_SQR2_SQ7_0                 (0x01U << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7_1                 (0x02U << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7_2                 (0x04U << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7_3                 (0x08U << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7_4                 (0x10U << ADC_SQR2_SQ7_Pos)

#define ADC_SQR2_SQ8_Pos               (18U)
#define ADC_SQR2_SQ8_Msk               (0x1FU << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8                   ADC_SQR2_SQ8_Msk
#define ADC_SQR2_SQ8_0                 (0x01U << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8_1                 (0x02U << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8_2                 (0x04U << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8_3                 (0x08U << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8_4                 (0x10U << ADC_SQR2_SQ8_Pos)

#define ADC_SQR2_SQ9_Pos               (24U)
#define ADC_SQR2_SQ9_Msk               (0x1FU << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9                   ADC_SQR2_SQ9_Msk
#define ADC_SQR2_SQ9_0                 (0x01U << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9_1                 (0x02U << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9_2                 (0x04U << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9_3                 (0x08U << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9_4                 (0x10U << ADC_SQR2_SQ9_Pos)


#define ADC_SQR3_SQ10_Pos              (0U)
#define ADC_SQR3_SQ10_Msk              (0x1FU << ADC_SQR3_SQ10_Pos)
#define ADC_SQR3_SQ10                  ADC_SQR3_SQ10_Msk
#define ADC_SQR3_SQ10_0                (0x01U << ADC_SQR3_SQ10_Pos)
#define ADC_SQR3_SQ10_1                (0x02U << ADC_SQR3_SQ10_Pos)
#define ADC_SQR3_SQ10_2                (0x04U << ADC_SQR3_SQ10_Pos)
#define ADC_SQR3_SQ10_3                (0x08U << ADC_SQR3_SQ10_Pos)
#define ADC_SQR3_SQ10_4                (0x10U << ADC_SQR3_SQ10_Pos)

#define ADC_SQR3_SQ11_Pos              (6U)
#define ADC_SQR3_SQ11_Msk              (0x1FU << ADC_SQR3_SQ11_Pos)
#define ADC_SQR3_SQ11                  ADC_SQR3_SQ11_Msk
#define ADC_SQR3_SQ11_0                (0x01U << ADC_SQR3_SQ11_Pos)
#define ADC_SQR3_SQ11_1                (0x02U << ADC_SQR3_SQ11_Pos)
#define ADC_SQR3_SQ11_2                (0x04U << ADC_SQR3_SQ11_Pos)
#define ADC_SQR3_SQ11_3                (0x08U << ADC_SQR3_SQ11_Pos)
#define ADC_SQR3_SQ11_4                (0x10U << ADC_SQR3_SQ11_Pos)

#define ADC_SQR3_SQ12_Pos              (12U)
#define ADC_SQR3_SQ12_Msk              (0x1FU << ADC_SQR3_SQ12_Pos)
#define ADC_SQR3_SQ12                  ADC_SQR3_SQ12_Msk
#define ADC_SQR3_SQ12_0                (0x01U << ADC_SQR3_SQ12_Pos)
#define ADC_SQR3_SQ12_1                (0x02U << ADC_SQR3_SQ12_Pos)
#define ADC_SQR3_SQ12_2                (0x04U << ADC_SQR3_SQ12_Pos)
#define ADC_SQR3_SQ12_3                (0x08U << ADC_SQR3_SQ12_Pos)
#define ADC_SQR3_SQ12_4                (0x10U << ADC_SQR3_SQ12_Pos)

#define ADC_SQR3_SQ13_Pos              (18U)
#define ADC_SQR3_SQ13_Msk              (0x1FU << ADC_SQR3_SQ13_Pos)
#define ADC_SQR3_SQ13                  ADC_SQR3_SQ13_Msk
#define ADC_SQR3_SQ13_0                (0x01U << ADC_SQR3_SQ13_Pos)
#define ADC_SQR3_SQ13_1                (0x02U << ADC_SQR3_SQ13_Pos)
#define ADC_SQR3_SQ13_2                (0x04U << ADC_SQR3_SQ13_Pos)
#define ADC_SQR3_SQ13_3                (0x08U << ADC_SQR3_SQ13_Pos)
#define ADC_SQR3_SQ13_4                (0x10U << ADC_SQR3_SQ13_Pos)

#define ADC_SQR3_SQ14_Pos              (24U)
#define ADC_SQR3_SQ14_Msk              (0x1FU << ADC_SQR3_SQ14_Pos)
#define ADC_SQR3_SQ14                  ADC_SQR3_SQ14_Msk
#define ADC_SQR3_SQ14_0                (0x01U << ADC_SQR3_SQ14_Pos)
#define ADC_SQR3_SQ14_1                (0x02U << ADC_SQR3_SQ14_Pos)
#define ADC_SQR3_SQ14_2                (0x04U << ADC_SQR3_SQ14_Pos)
#define ADC_SQR3_SQ14_3                (0x08U << ADC_SQR3_SQ14_Pos)
#define ADC_SQR3_SQ14_4                (0x10U << ADC_SQR3_SQ14_Pos)


#define ADC_SQR4_SQ15_Pos              (0U)
#define ADC_SQR4_SQ15_Msk              (0x1FU << ADC_SQR4_SQ15_Pos)
#define ADC_SQR4_SQ15                  ADC_SQR4_SQ15_Msk
#define ADC_SQR4_SQ15_0                (0x01U << ADC_SQR4_SQ15_Pos)
#define ADC_SQR4_SQ15_1                (0x02U << ADC_SQR4_SQ15_Pos)
#define ADC_SQR4_SQ15_2                (0x04U << ADC_SQR4_SQ15_Pos)
#define ADC_SQR4_SQ15_3                (0x08U << ADC_SQR4_SQ15_Pos)
#define ADC_SQR4_SQ15_4                (0x10U << ADC_SQR4_SQ15_Pos)

#define ADC_SQR4_SQ16_Pos              (6U)
#define ADC_SQR4_SQ16_Msk              (0x1FU << ADC_SQR4_SQ16_Pos)
#define ADC_SQR4_SQ16                  ADC_SQR4_SQ16_Msk
#define ADC_SQR4_SQ16_0                (0x01U << ADC_SQR4_SQ16_Pos)
#define ADC_SQR4_SQ16_1                (0x02U << ADC_SQR4_SQ16_Pos)
#define ADC_SQR4_SQ16_2                (0x04U << ADC_SQR4_SQ16_Pos)
#define ADC_SQR4_SQ16_3                (0x08U << ADC_SQR4_SQ16_Pos)
#define ADC_SQR4_SQ16_4                (0x10U << ADC_SQR4_SQ16_Pos)


#define ADC_DR_RDATA_Pos               (0U)
#define ADC_DR_RDATA_Msk               (0xFFFFU << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA                   ADC_DR_RDATA_Msk
#define ADC_DR_RDATA_0                 (0x0001U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_1                 (0x0002U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_2                 (0x0004U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_3                 (0x0008U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_4                 (0x0010U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_5                 (0x0020U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_6                 (0x0040U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_7                 (0x0080U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_8                 (0x0100U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_9                 (0x0200U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_10                (0x0400U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_11                (0x0800U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_12                (0x1000U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_13                (0x2000U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_14                (0x4000U << ADC_DR_RDATA_Pos)
#define ADC_DR_RDATA_15                (0x8000U << ADC_DR_RDATA_Pos)


#define ADC_JSQR_JL_Pos                (0U)
#define ADC_JSQR_JL_Msk                (0x3U << ADC_JSQR_JL_Pos)
#define ADC_JSQR_JL                    ADC_JSQR_JL_Msk
#define ADC_JSQR_JL_0                  (0x1U << ADC_JSQR_JL_Pos)
#define ADC_JSQR_JL_1                  (0x2U << ADC_JSQR_JL_Pos)

#define ADC_JSQR_JEXTSEL_Pos           (2U)
#define ADC_JSQR_JEXTSEL_Msk           (0xFU << ADC_JSQR_JEXTSEL_Pos)
#define ADC_JSQR_JEXTSEL               ADC_JSQR_JEXTSEL_Msk
#define ADC_JSQR_JEXTSEL_0             (0x1U << ADC_JSQR_JEXTSEL_Pos)
#define ADC_JSQR_JEXTSEL_1             (0x2U << ADC_JSQR_JEXTSEL_Pos)
#define ADC_JSQR_JEXTSEL_2             (0x4U << ADC_JSQR_JEXTSEL_Pos)
#define ADC_JSQR_JEXTSEL_3             (0x8U << ADC_JSQR_JEXTSEL_Pos)

#define ADC_JSQR_JEXTEN_Pos            (6U)
#define ADC_JSQR_JEXTEN_Msk            (0x3U << ADC_JSQR_JEXTEN_Pos)
#define ADC_JSQR_JEXTEN                ADC_JSQR_JEXTEN_Msk
#define ADC_JSQR_JEXTEN_0              (0x1U << ADC_JSQR_JEXTEN_Pos)
#define ADC_JSQR_JEXTEN_1              (0x2U << ADC_JSQR_JEXTEN_Pos)

#define ADC_JSQR_JSQ1_Pos              (8U)
#define ADC_JSQR_JSQ1_Msk              (0x1FU << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1                  ADC_JSQR_JSQ1_Msk
#define ADC_JSQR_JSQ1_0                (0x01U << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1_1                (0x02U << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1_2                (0x04U << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1_3                (0x08U << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1_4                (0x10U << ADC_JSQR_JSQ1_Pos)

#define ADC_JSQR_JSQ2_Pos              (14U)
#define ADC_JSQR_JSQ2_Msk              (0x1FU << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2                  ADC_JSQR_JSQ2_Msk
#define ADC_JSQR_JSQ2_0                (0x01U << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2_1                (0x02U << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2_2                (0x04U << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2_3                (0x08U << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2_4                (0x10U << ADC_JSQR_JSQ2_Pos)

#define ADC_JSQR_JSQ3_Pos              (20U)
#define ADC_JSQR_JSQ3_Msk              (0x1FU << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3                  ADC_JSQR_JSQ3_Msk
#define ADC_JSQR_JSQ3_0                (0x01U << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3_1                (0x02U << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3_2                (0x04U << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3_3                (0x08U << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3_4                (0x10U << ADC_JSQR_JSQ3_Pos)

#define ADC_JSQR_JSQ4_Pos              (26U)
#define ADC_JSQR_JSQ4_Msk              (0x1FU << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4                  ADC_JSQR_JSQ4_Msk
#define ADC_JSQR_JSQ4_0                (0x01U << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4_1                (0x02U << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4_2                (0x04U << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4_3                (0x08U << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4_4                (0x10U << ADC_JSQR_JSQ4_Pos)



#define ADC_OFR1_OFFSET1_Pos           (0U)
#define ADC_OFR1_OFFSET1_Msk           (0xFFFU << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1               ADC_OFR1_OFFSET1_Msk
#define ADC_OFR1_OFFSET1_0             (0x001U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_1             (0x002U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_2             (0x004U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_3             (0x008U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_4             (0x010U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_5             (0x020U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_6             (0x040U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_7             (0x080U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_8             (0x100U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_9             (0x200U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_10            (0x400U << ADC_OFR1_OFFSET1_Pos)
#define ADC_OFR1_OFFSET1_11            (0x800U << ADC_OFR1_OFFSET1_Pos)

#define ADC_OFR1_OFFSET1_CH_Pos        (26U)
#define ADC_OFR1_OFFSET1_CH_Msk        (0x1FU << ADC_OFR1_OFFSET1_CH_Pos)
#define ADC_OFR1_OFFSET1_CH            ADC_OFR1_OFFSET1_CH_Msk
#define ADC_OFR1_OFFSET1_CH_0          (0x01U << ADC_OFR1_OFFSET1_CH_Pos)
#define ADC_OFR1_OFFSET1_CH_1          (0x02U << ADC_OFR1_OFFSET1_CH_Pos)
#define ADC_OFR1_OFFSET1_CH_2          (0x04U << ADC_OFR1_OFFSET1_CH_Pos)
#define ADC_OFR1_OFFSET1_CH_3          (0x08U << ADC_OFR1_OFFSET1_CH_Pos)
#define ADC_OFR1_OFFSET1_CH_4          (0x10U << ADC_OFR1_OFFSET1_CH_Pos)

#define ADC_OFR1_OFFSET1_EN_Pos        (31U)
#define ADC_OFR1_OFFSET1_EN_Msk        (0x1U << ADC_OFR1_OFFSET1_EN_Pos)
#define ADC_OFR1_OFFSET1_EN            ADC_OFR1_OFFSET1_EN_Msk


#define ADC_OFR2_OFFSET2_Pos           (0U)
#define ADC_OFR2_OFFSET2_Msk           (0xFFFU << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2               ADC_OFR2_OFFSET2_Msk
#define ADC_OFR2_OFFSET2_0             (0x001U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_1             (0x002U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_2             (0x004U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_3             (0x008U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_4             (0x010U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_5             (0x020U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_6             (0x040U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_7             (0x080U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_8             (0x100U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_9             (0x200U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_10            (0x400U << ADC_OFR2_OFFSET2_Pos)
#define ADC_OFR2_OFFSET2_11            (0x800U << ADC_OFR2_OFFSET2_Pos)

#define ADC_OFR2_OFFSET2_CH_Pos        (26U)
#define ADC_OFR2_OFFSET2_CH_Msk        (0x1FU << ADC_OFR2_OFFSET2_CH_Pos)
#define ADC_OFR2_OFFSET2_CH            ADC_OFR2_OFFSET2_CH_Msk
#define ADC_OFR2_OFFSET2_CH_0          (0x01U << ADC_OFR2_OFFSET2_CH_Pos)
#define ADC_OFR2_OFFSET2_CH_1          (0x02U << ADC_OFR2_OFFSET2_CH_Pos)
#define ADC_OFR2_OFFSET2_CH_2          (0x04U << ADC_OFR2_OFFSET2_CH_Pos)
#define ADC_OFR2_OFFSET2_CH_3          (0x08U << ADC_OFR2_OFFSET2_CH_Pos)
#define ADC_OFR2_OFFSET2_CH_4          (0x10U << ADC_OFR2_OFFSET2_CH_Pos)

#define ADC_OFR2_OFFSET2_EN_Pos        (31U)
#define ADC_OFR2_OFFSET2_EN_Msk        (0x1U << ADC_OFR2_OFFSET2_EN_Pos)
#define ADC_OFR2_OFFSET2_EN            ADC_OFR2_OFFSET2_EN_Msk


#define ADC_OFR3_OFFSET3_Pos           (0U)
#define ADC_OFR3_OFFSET3_Msk           (0xFFFU << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3               ADC_OFR3_OFFSET3_Msk
#define ADC_OFR3_OFFSET3_0             (0x001U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_1             (0x002U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_2             (0x004U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_3             (0x008U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_4             (0x010U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_5             (0x020U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_6             (0x040U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_7             (0x080U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_8             (0x100U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_9             (0x200U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_10            (0x400U << ADC_OFR3_OFFSET3_Pos)
#define ADC_OFR3_OFFSET3_11            (0x800U << ADC_OFR3_OFFSET3_Pos)

#define ADC_OFR3_OFFSET3_CH_Pos        (26U)
#define ADC_OFR3_OFFSET3_CH_Msk        (0x1FU << ADC_OFR3_OFFSET3_CH_Pos)
#define ADC_OFR3_OFFSET3_CH            ADC_OFR3_OFFSET3_CH_Msk
#define ADC_OFR3_OFFSET3_CH_0          (0x01U << ADC_OFR3_OFFSET3_CH_Pos)
#define ADC_OFR3_OFFSET3_CH_1          (0x02U << ADC_OFR3_OFFSET3_CH_Pos)
#define ADC_OFR3_OFFSET3_CH_2          (0x04U << ADC_OFR3_OFFSET3_CH_Pos)
#define ADC_OFR3_OFFSET3_CH_3          (0x08U << ADC_OFR3_OFFSET3_CH_Pos)
#define ADC_OFR3_OFFSET3_CH_4          (0x10U << ADC_OFR3_OFFSET3_CH_Pos)

#define ADC_OFR3_OFFSET3_EN_Pos        (31U)
#define ADC_OFR3_OFFSET3_EN_Msk        (0x1U << ADC_OFR3_OFFSET3_EN_Pos)
#define ADC_OFR3_OFFSET3_EN            ADC_OFR3_OFFSET3_EN_Msk


#define ADC_OFR4_OFFSET4_Pos           (0U)
#define ADC_OFR4_OFFSET4_Msk           (0xFFFU << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4               ADC_OFR4_OFFSET4_Msk
#define ADC_OFR4_OFFSET4_0             (0x001U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_1             (0x002U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_2             (0x004U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_3             (0x008U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_4             (0x010U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_5             (0x020U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_6             (0x040U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_7             (0x080U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_8             (0x100U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_9             (0x200U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_10            (0x400U << ADC_OFR4_OFFSET4_Pos)
#define ADC_OFR4_OFFSET4_11            (0x800U << ADC_OFR4_OFFSET4_Pos)

#define ADC_OFR4_OFFSET4_CH_Pos        (26U)
#define ADC_OFR4_OFFSET4_CH_Msk        (0x1FU << ADC_OFR4_OFFSET4_CH_Pos)
#define ADC_OFR4_OFFSET4_CH            ADC_OFR4_OFFSET4_CH_Msk
#define ADC_OFR4_OFFSET4_CH_0          (0x01U << ADC_OFR4_OFFSET4_CH_Pos)
#define ADC_OFR4_OFFSET4_CH_1          (0x02U << ADC_OFR4_OFFSET4_CH_Pos)
#define ADC_OFR4_OFFSET4_CH_2          (0x04U << ADC_OFR4_OFFSET4_CH_Pos)
#define ADC_OFR4_OFFSET4_CH_3          (0x08U << ADC_OFR4_OFFSET4_CH_Pos)
#define ADC_OFR4_OFFSET4_CH_4          (0x10U << ADC_OFR4_OFFSET4_CH_Pos)

#define ADC_OFR4_OFFSET4_EN_Pos        (31U)
#define ADC_OFR4_OFFSET4_EN_Msk        (0x1U << ADC_OFR4_OFFSET4_EN_Pos)
#define ADC_OFR4_OFFSET4_EN            ADC_OFR4_OFFSET4_EN_Msk


#define ADC_JDR1_JDATA_Pos             (0U)
#define ADC_JDR1_JDATA_Msk             (0xFFFFU << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA                 ADC_JDR1_JDATA_Msk
#define ADC_JDR1_JDATA_0               (0x0001U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_1               (0x0002U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_2               (0x0004U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_3               (0x0008U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_4               (0x0010U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_5               (0x0020U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_6               (0x0040U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_7               (0x0080U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_8               (0x0100U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_9               (0x0200U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_10              (0x0400U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_11              (0x0800U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_12              (0x1000U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_13              (0x2000U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_14              (0x4000U << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA_15              (0x8000U << ADC_JDR1_JDATA_Pos)


#define ADC_JDR2_JDATA_Pos             (0U)
#define ADC_JDR2_JDATA_Msk             (0xFFFFU << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA                 ADC_JDR2_JDATA_Msk
#define ADC_JDR2_JDATA_0               (0x0001U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_1               (0x0002U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_2               (0x0004U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_3               (0x0008U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_4               (0x0010U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_5               (0x0020U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_6               (0x0040U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_7               (0x0080U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_8               (0x0100U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_9               (0x0200U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_10              (0x0400U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_11              (0x0800U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_12              (0x1000U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_13              (0x2000U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_14              (0x4000U << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA_15              (0x8000U << ADC_JDR2_JDATA_Pos)


#define ADC_JDR3_JDATA_Pos             (0U)
#define ADC_JDR3_JDATA_Msk             (0xFFFFU << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA                 ADC_JDR3_JDATA_Msk
#define ADC_JDR3_JDATA_0               (0x0001U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_1               (0x0002U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_2               (0x0004U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_3               (0x0008U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_4               (0x0010U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_5               (0x0020U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_6               (0x0040U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_7               (0x0080U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_8               (0x0100U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_9               (0x0200U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_10              (0x0400U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_11              (0x0800U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_12              (0x1000U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_13              (0x2000U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_14              (0x4000U << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA_15              (0x8000U << ADC_JDR3_JDATA_Pos)


#define ADC_JDR4_JDATA_Pos             (0U)
#define ADC_JDR4_JDATA_Msk             (0xFFFFU << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA                 ADC_JDR4_JDATA_Msk
#define ADC_JDR4_JDATA_0               (0x0001U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_1               (0x0002U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_2               (0x0004U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_3               (0x0008U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_4               (0x0010U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_5               (0x0020U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_6               (0x0040U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_7               (0x0080U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_8               (0x0100U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_9               (0x0200U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_10              (0x0400U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_11              (0x0800U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_12              (0x1000U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_13              (0x2000U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_14              (0x4000U << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA_15              (0x8000U << ADC_JDR4_JDATA_Pos)


#define ADC_AWD2CR_AWD2CH_Pos          (0U)
#define ADC_AWD2CR_AWD2CH_Msk          (0x7FFFFU << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH              ADC_AWD2CR_AWD2CH_Msk
#define ADC_AWD2CR_AWD2CH_0            (0x00001U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_1            (0x00002U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_2            (0x00004U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_3            (0x00008U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_4            (0x00010U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_5            (0x00020U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_6            (0x00040U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_7            (0x00080U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_8            (0x00100U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_9            (0x00200U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_10           (0x00400U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_11           (0x00800U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_12           (0x01000U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_13           (0x02000U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_14           (0x04000U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_15           (0x08000U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_16           (0x10000U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_17           (0x20000U << ADC_AWD2CR_AWD2CH_Pos)
#define ADC_AWD2CR_AWD2CH_18           (0x40000U << ADC_AWD2CR_AWD2CH_Pos)


#define ADC_AWD3CR_AWD3CH_Pos          (0U)
#define ADC_AWD3CR_AWD3CH_Msk          (0x7FFFFU << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH              ADC_AWD3CR_AWD3CH_Msk
#define ADC_AWD3CR_AWD3CH_0            (0x00001U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_1            (0x00002U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_2            (0x00004U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_3            (0x00008U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_4            (0x00010U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_5            (0x00020U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_6            (0x00040U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_7            (0x00080U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_8            (0x00100U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_9            (0x00200U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_10           (0x00400U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_11           (0x00800U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_12           (0x01000U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_13           (0x02000U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_14           (0x04000U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_15           (0x08000U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_16           (0x10000U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_17           (0x20000U << ADC_AWD3CR_AWD3CH_Pos)
#define ADC_AWD3CR_AWD3CH_18           (0x40000U << ADC_AWD3CR_AWD3CH_Pos)


#define ADC_DIFSEL_DIFSEL_Pos          (0U)
#define ADC_DIFSEL_DIFSEL_Msk          (0x7FFFFU << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL              ADC_DIFSEL_DIFSEL_Msk
#define ADC_DIFSEL_DIFSEL_0            (0x00001U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_1            (0x00002U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_2            (0x00004U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_3            (0x00008U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_4            (0x00010U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_5            (0x00020U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_6            (0x00040U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_7            (0x00080U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_8            (0x00100U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_9            (0x00200U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_10           (0x00400U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_11           (0x00800U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_12           (0x01000U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_13           (0x02000U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_14           (0x04000U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_15           (0x08000U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_16           (0x10000U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_17           (0x20000U << ADC_DIFSEL_DIFSEL_Pos)
#define ADC_DIFSEL_DIFSEL_18           (0x40000U << ADC_DIFSEL_DIFSEL_Pos)


#define ADC_CALFACT_CALFACT_S_Pos      (0U)
#define ADC_CALFACT_CALFACT_S_Msk      (0x7FU << ADC_CALFACT_CALFACT_S_Pos)
#define ADC_CALFACT_CALFACT_S          ADC_CALFACT_CALFACT_S_Msk
#define ADC_CALFACT_CALFACT_S_0        (0x01U << ADC_CALFACT_CALFACT_S_Pos)
#define ADC_CALFACT_CALFACT_S_1        (0x02U << ADC_CALFACT_CALFACT_S_Pos)
#define ADC_CALFACT_CALFACT_S_2        (0x04U << ADC_CALFACT_CALFACT_S_Pos)
#define ADC_CALFACT_CALFACT_S_3        (0x08U << ADC_CALFACT_CALFACT_S_Pos)
#define ADC_CALFACT_CALFACT_S_4        (0x10U << ADC_CALFACT_CALFACT_S_Pos)
#define ADC_CALFACT_CALFACT_S_5        (0x20U << ADC_CALFACT_CALFACT_S_Pos)
#define ADC_CALFACT_CALFACT_S_6        (0x40U << ADC_CALFACT_CALFACT_S_Pos)

#define ADC_CALFACT_CALFACT_D_Pos      (16U)
#define ADC_CALFACT_CALFACT_D_Msk      (0x7FU << ADC_CALFACT_CALFACT_D_Pos)
#define ADC_CALFACT_CALFACT_D          ADC_CALFACT_CALFACT_D_Msk
#define ADC_CALFACT_CALFACT_D_0        (0x01U << ADC_CALFACT_CALFACT_D_Pos)
#define ADC_CALFACT_CALFACT_D_1        (0x02U << ADC_CALFACT_CALFACT_D_Pos)
#define ADC_CALFACT_CALFACT_D_2        (0x04U << ADC_CALFACT_CALFACT_D_Pos)
#define ADC_CALFACT_CALFACT_D_3        (0x08U << ADC_CALFACT_CALFACT_D_Pos)
#define ADC_CALFACT_CALFACT_D_4        (0x10U << ADC_CALFACT_CALFACT_D_Pos)
#define ADC_CALFACT_CALFACT_D_5        (0x20U << ADC_CALFACT_CALFACT_D_Pos)
#define ADC_CALFACT_CALFACT_D_6        (0x40U << ADC_CALFACT_CALFACT_D_Pos)



#define ADC12_CSR_ADRDY_MST_Pos          (0U)
#define ADC12_CSR_ADRDY_MST_Msk          (0x1U << ADC12_CSR_ADRDY_MST_Pos)
#define ADC12_CSR_ADRDY_MST              ADC12_CSR_ADRDY_MST_Msk
#define ADC12_CSR_ADRDY_EOSMP_MST_Pos    (1U)
#define ADC12_CSR_ADRDY_EOSMP_MST_Msk    (0x1U << ADC12_CSR_ADRDY_EOSMP_MST_Pos)
#define ADC12_CSR_ADRDY_EOSMP_MST        ADC12_CSR_ADRDY_EOSMP_MST_Msk
#define ADC12_CSR_ADRDY_EOC_MST_Pos      (2U)
#define ADC12_CSR_ADRDY_EOC_MST_Msk      (0x1U << ADC12_CSR_ADRDY_EOC_MST_Pos)
#define ADC12_CSR_ADRDY_EOC_MST          ADC12_CSR_ADRDY_EOC_MST_Msk
#define ADC12_CSR_ADRDY_EOS_MST_Pos      (3U)
#define ADC12_CSR_ADRDY_EOS_MST_Msk      (0x1U << ADC12_CSR_ADRDY_EOS_MST_Pos)
#define ADC12_CSR_ADRDY_EOS_MST          ADC12_CSR_ADRDY_EOS_MST_Msk
#define ADC12_CSR_ADRDY_OVR_MST_Pos      (4U)
#define ADC12_CSR_ADRDY_OVR_MST_Msk      (0x1U << ADC12_CSR_ADRDY_OVR_MST_Pos)
#define ADC12_CSR_ADRDY_OVR_MST          ADC12_CSR_ADRDY_OVR_MST_Msk
#define ADC12_CSR_ADRDY_JEOC_MST_Pos     (5U)
#define ADC12_CSR_ADRDY_JEOC_MST_Msk     (0x1U << ADC12_CSR_ADRDY_JEOC_MST_Pos)
#define ADC12_CSR_ADRDY_JEOC_MST         ADC12_CSR_ADRDY_JEOC_MST_Msk
#define ADC12_CSR_ADRDY_JEOS_MST_Pos     (6U)
#define ADC12_CSR_ADRDY_JEOS_MST_Msk     (0x1U << ADC12_CSR_ADRDY_JEOS_MST_Pos)
#define ADC12_CSR_ADRDY_JEOS_MST         ADC12_CSR_ADRDY_JEOS_MST_Msk
#define ADC12_CSR_AWD1_MST_Pos           (7U)
#define ADC12_CSR_AWD1_MST_Msk           (0x1U << ADC12_CSR_AWD1_MST_Pos)
#define ADC12_CSR_AWD1_MST               ADC12_CSR_AWD1_MST_Msk
#define ADC12_CSR_AWD2_MST_Pos           (8U)
#define ADC12_CSR_AWD2_MST_Msk           (0x1U << ADC12_CSR_AWD2_MST_Pos)
#define ADC12_CSR_AWD2_MST               ADC12_CSR_AWD2_MST_Msk
#define ADC12_CSR_AWD3_MST_Pos           (9U)
#define ADC12_CSR_AWD3_MST_Msk           (0x1U << ADC12_CSR_AWD3_MST_Pos)
#define ADC12_CSR_AWD3_MST               ADC12_CSR_AWD3_MST_Msk
#define ADC12_CSR_JQOVF_MST_Pos          (10U)
#define ADC12_CSR_JQOVF_MST_Msk          (0x1U << ADC12_CSR_JQOVF_MST_Pos)
#define ADC12_CSR_JQOVF_MST              ADC12_CSR_JQOVF_MST_Msk
#define ADC12_CSR_ADRDY_SLV_Pos          (16U)
#define ADC12_CSR_ADRDY_SLV_Msk          (0x1U << ADC12_CSR_ADRDY_SLV_Pos)
#define ADC12_CSR_ADRDY_SLV              ADC12_CSR_ADRDY_SLV_Msk
#define ADC12_CSR_ADRDY_EOSMP_SLV_Pos    (17U)
#define ADC12_CSR_ADRDY_EOSMP_SLV_Msk    (0x1U << ADC12_CSR_ADRDY_EOSMP_SLV_Pos)
#define ADC12_CSR_ADRDY_EOSMP_SLV        ADC12_CSR_ADRDY_EOSMP_SLV_Msk
#define ADC12_CSR_ADRDY_EOC_SLV_Pos      (18U)
#define ADC12_CSR_ADRDY_EOC_SLV_Msk      (0x1U << ADC12_CSR_ADRDY_EOC_SLV_Pos)
#define ADC12_CSR_ADRDY_EOC_SLV          ADC12_CSR_ADRDY_EOC_SLV_Msk
#define ADC12_CSR_ADRDY_EOS_SLV_Pos      (19U)
#define ADC12_CSR_ADRDY_EOS_SLV_Msk      (0x1U << ADC12_CSR_ADRDY_EOS_SLV_Pos)
#define ADC12_CSR_ADRDY_EOS_SLV          ADC12_CSR_ADRDY_EOS_SLV_Msk
#define ADC12_CSR_ADRDY_OVR_SLV_Pos      (20U)
#define ADC12_CSR_ADRDY_OVR_SLV_Msk      (0x1U << ADC12_CSR_ADRDY_OVR_SLV_Pos)
#define ADC12_CSR_ADRDY_OVR_SLV          ADC12_CSR_ADRDY_OVR_SLV_Msk
#define ADC12_CSR_ADRDY_JEOC_SLV_Pos     (21U)
#define ADC12_CSR_ADRDY_JEOC_SLV_Msk     (0x1U << ADC12_CSR_ADRDY_JEOC_SLV_Pos)
#define ADC12_CSR_ADRDY_JEOC_SLV         ADC12_CSR_ADRDY_JEOC_SLV_Msk
#define ADC12_CSR_ADRDY_JEOS_SLV_Pos     (22U)
#define ADC12_CSR_ADRDY_JEOS_SLV_Msk     (0x1U << ADC12_CSR_ADRDY_JEOS_SLV_Pos)
#define ADC12_CSR_ADRDY_JEOS_SLV         ADC12_CSR_ADRDY_JEOS_SLV_Msk
#define ADC12_CSR_AWD1_SLV_Pos           (23U)
#define ADC12_CSR_AWD1_SLV_Msk           (0x1U << ADC12_CSR_AWD1_SLV_Pos)
#define ADC12_CSR_AWD1_SLV               ADC12_CSR_AWD1_SLV_Msk
#define ADC12_CSR_AWD2_SLV_Pos           (24U)
#define ADC12_CSR_AWD2_SLV_Msk           (0x1U << ADC12_CSR_AWD2_SLV_Pos)
#define ADC12_CSR_AWD2_SLV               ADC12_CSR_AWD2_SLV_Msk
#define ADC12_CSR_AWD3_SLV_Pos           (25U)
#define ADC12_CSR_AWD3_SLV_Msk           (0x1U << ADC12_CSR_AWD3_SLV_Pos)
#define ADC12_CSR_AWD3_SLV               ADC12_CSR_AWD3_SLV_Msk
#define ADC12_CSR_JQOVF_SLV_Pos          (26U)
#define ADC12_CSR_JQOVF_SLV_Msk          (0x1U << ADC12_CSR_JQOVF_SLV_Pos)
#define ADC12_CSR_JQOVF_SLV              ADC12_CSR_JQOVF_SLV_Msk


#define ADC12_CCR_MULTI_Pos              (0U)
#define ADC12_CCR_MULTI_Msk              (0x1FU << ADC12_CCR_MULTI_Pos)
#define ADC12_CCR_MULTI                  ADC12_CCR_MULTI_Msk
#define ADC12_CCR_MULTI_0                (0x01U << ADC12_CCR_MULTI_Pos)
#define ADC12_CCR_MULTI_1                (0x02U << ADC12_CCR_MULTI_Pos)
#define ADC12_CCR_MULTI_2                (0x04U << ADC12_CCR_MULTI_Pos)
#define ADC12_CCR_MULTI_3                (0x08U << ADC12_CCR_MULTI_Pos)
#define ADC12_CCR_MULTI_4                (0x10U << ADC12_CCR_MULTI_Pos)
#define ADC12_CCR_DELAY_Pos              (8U)
#define ADC12_CCR_DELAY_Msk              (0xFU << ADC12_CCR_DELAY_Pos)
#define ADC12_CCR_DELAY                  ADC12_CCR_DELAY_Msk
#define ADC12_CCR_DELAY_0                (0x1U << ADC12_CCR_DELAY_Pos)
#define ADC12_CCR_DELAY_1                (0x2U << ADC12_CCR_DELAY_Pos)
#define ADC12_CCR_DELAY_2                (0x4U << ADC12_CCR_DELAY_Pos)
#define ADC12_CCR_DELAY_3                (0x8U << ADC12_CCR_DELAY_Pos)
#define ADC12_CCR_DMACFG_Pos             (13U)
#define ADC12_CCR_DMACFG_Msk             (0x1U << ADC12_CCR_DMACFG_Pos)
#define ADC12_CCR_DMACFG                 ADC12_CCR_DMACFG_Msk
#define ADC12_CCR_MDMA_Pos               (14U)
#define ADC12_CCR_MDMA_Msk               (0x3U << ADC12_CCR_MDMA_Pos)
#define ADC12_CCR_MDMA                   ADC12_CCR_MDMA_Msk
#define ADC12_CCR_MDMA_0                 (0x1U << ADC12_CCR_MDMA_Pos)
#define ADC12_CCR_MDMA_1                 (0x2U << ADC12_CCR_MDMA_Pos)
#define ADC12_CCR_CKMODE_Pos             (16U)
#define ADC12_CCR_CKMODE_Msk             (0x3U << ADC12_CCR_CKMODE_Pos)
#define ADC12_CCR_CKMODE                 ADC12_CCR_CKMODE_Msk
#define ADC12_CCR_CKMODE_0               (0x1U << ADC12_CCR_CKMODE_Pos)
#define ADC12_CCR_CKMODE_1               (0x2U << ADC12_CCR_CKMODE_Pos)
#define ADC12_CCR_VREFEN_Pos             (22U)
#define ADC12_CCR_VREFEN_Msk             (0x1U << ADC12_CCR_VREFEN_Pos)
#define ADC12_CCR_VREFEN                 ADC12_CCR_VREFEN_Msk
#define ADC12_CCR_TSEN_Pos               (23U)
#define ADC12_CCR_TSEN_Msk               (0x1U << ADC12_CCR_TSEN_Pos)
#define ADC12_CCR_TSEN                   ADC12_CCR_TSEN_Msk
#define ADC12_CCR_VBATEN_Pos             (24U)
#define ADC12_CCR_VBATEN_Msk             (0x1U << ADC12_CCR_VBATEN_Pos)
#define ADC12_CCR_VBATEN                 ADC12_CCR_VBATEN_Msk


#define ADC12_CDR_RDATA_MST_Pos          (0U)
#define ADC12_CDR_RDATA_MST_Msk          (0xFFFFU << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST              ADC12_CDR_RDATA_MST_Msk
#define ADC12_CDR_RDATA_MST_0            (0x0001U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_1            (0x0002U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_2            (0x0004U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_3            (0x0008U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_4            (0x0010U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_5            (0x0020U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_6            (0x0040U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_7            (0x0080U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_8            (0x0100U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_9            (0x0200U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_10           (0x0400U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_11           (0x0800U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_12           (0x1000U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_13           (0x2000U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_14           (0x4000U << ADC12_CDR_RDATA_MST_Pos)
#define ADC12_CDR_RDATA_MST_15           (0x8000U << ADC12_CDR_RDATA_MST_Pos)

#define ADC12_CDR_RDATA_SLV_Pos          (16U)
#define ADC12_CDR_RDATA_SLV_Msk          (0xFFFFU << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV              ADC12_CDR_RDATA_SLV_Msk
#define ADC12_CDR_RDATA_SLV_0            (0x0001U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_1            (0x0002U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_2            (0x0004U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_3            (0x0008U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_4            (0x0010U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_5            (0x0020U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_6            (0x0040U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_7            (0x0080U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_8            (0x0100U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_9            (0x0200U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_10           (0x0400U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_11           (0x0800U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_12           (0x1000U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_13           (0x2000U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_14           (0x4000U << ADC12_CDR_RDATA_SLV_Pos)
#define ADC12_CDR_RDATA_SLV_15           (0x8000U << ADC12_CDR_RDATA_SLV_Pos)


#define ADC_CSR_ADRDY_MST_Pos          (0U)
#define ADC_CSR_ADRDY_MST_Msk          (0x1U << ADC_CSR_ADRDY_MST_Pos)
#define ADC_CSR_ADRDY_MST              ADC_CSR_ADRDY_MST_Msk
#define ADC_CSR_EOSMP_MST_Pos          (1U)
#define ADC_CSR_EOSMP_MST_Msk          (0x1U << ADC_CSR_EOSMP_MST_Pos)
#define ADC_CSR_EOSMP_MST              ADC_CSR_EOSMP_MST_Msk
#define ADC_CSR_EOC_MST_Pos            (2U)
#define ADC_CSR_EOC_MST_Msk            (0x1U << ADC_CSR_EOC_MST_Pos)
#define ADC_CSR_EOC_MST                ADC_CSR_EOC_MST_Msk
#define ADC_CSR_EOS_MST_Pos            (3U)
#define ADC_CSR_EOS_MST_Msk            (0x1U << ADC_CSR_EOS_MST_Pos)
#define ADC_CSR_EOS_MST                ADC_CSR_EOS_MST_Msk
#define ADC_CSR_OVR_MST_Pos            (4U)
#define ADC_CSR_OVR_MST_Msk            (0x1U << ADC_CSR_OVR_MST_Pos)
#define ADC_CSR_OVR_MST                ADC_CSR_OVR_MST_Msk
#define ADC_CSR_JEOC_MST_Pos           (5U)
#define ADC_CSR_JEOC_MST_Msk           (0x1U << ADC_CSR_JEOC_MST_Pos)
#define ADC_CSR_JEOC_MST               ADC_CSR_JEOC_MST_Msk
#define ADC_CSR_JEOS_MST_Pos           (6U)
#define ADC_CSR_JEOS_MST_Msk           (0x1U << ADC_CSR_JEOS_MST_Pos)
#define ADC_CSR_JEOS_MST               ADC_CSR_JEOS_MST_Msk
#define ADC_CSR_AWD1_MST_Pos           (7U)
#define ADC_CSR_AWD1_MST_Msk           (0x1U << ADC_CSR_AWD1_MST_Pos)
#define ADC_CSR_AWD1_MST               ADC_CSR_AWD1_MST_Msk
#define ADC_CSR_AWD2_MST_Pos           (8U)
#define ADC_CSR_AWD2_MST_Msk           (0x1U << ADC_CSR_AWD2_MST_Pos)
#define ADC_CSR_AWD2_MST               ADC_CSR_AWD2_MST_Msk
#define ADC_CSR_AWD3_MST_Pos           (9U)
#define ADC_CSR_AWD3_MST_Msk           (0x1U << ADC_CSR_AWD3_MST_Pos)
#define ADC_CSR_AWD3_MST               ADC_CSR_AWD3_MST_Msk
#define ADC_CSR_JQOVF_MST_Pos          (10U)
#define ADC_CSR_JQOVF_MST_Msk          (0x1U << ADC_CSR_JQOVF_MST_Pos)
#define ADC_CSR_JQOVF_MST              ADC_CSR_JQOVF_MST_Msk

#define ADC_CSR_ADRDY_SLV_Pos          (16U)
#define ADC_CSR_ADRDY_SLV_Msk          (0x1U << ADC_CSR_ADRDY_SLV_Pos)
#define ADC_CSR_ADRDY_SLV              ADC_CSR_ADRDY_SLV_Msk
#define ADC_CSR_EOSMP_SLV_Pos          (17U)
#define ADC_CSR_EOSMP_SLV_Msk          (0x1U << ADC_CSR_EOSMP_SLV_Pos)
#define ADC_CSR_EOSMP_SLV              ADC_CSR_EOSMP_SLV_Msk
#define ADC_CSR_EOC_SLV_Pos            (18U)
#define ADC_CSR_EOC_SLV_Msk            (0x1U << ADC_CSR_EOC_SLV_Pos)
#define ADC_CSR_EOC_SLV                ADC_CSR_EOC_SLV_Msk
#define ADC_CSR_EOS_SLV_Pos            (19U)
#define ADC_CSR_EOS_SLV_Msk            (0x1U << ADC_CSR_EOS_SLV_Pos)
#define ADC_CSR_EOS_SLV                ADC_CSR_EOS_SLV_Msk
#define ADC_CSR_OVR_SLV_Pos            (20U)
#define ADC_CSR_OVR_SLV_Msk            (0x1U << ADC_CSR_OVR_SLV_Pos)
#define ADC_CSR_OVR_SLV                ADC_CSR_OVR_SLV_Msk
#define ADC_CSR_JEOC_SLV_Pos           (21U)
#define ADC_CSR_JEOC_SLV_Msk           (0x1U << ADC_CSR_JEOC_SLV_Pos)
#define ADC_CSR_JEOC_SLV               ADC_CSR_JEOC_SLV_Msk
#define ADC_CSR_JEOS_SLV_Pos           (22U)
#define ADC_CSR_JEOS_SLV_Msk           (0x1U << ADC_CSR_JEOS_SLV_Pos)
#define ADC_CSR_JEOS_SLV               ADC_CSR_JEOS_SLV_Msk
#define ADC_CSR_AWD1_SLV_Pos           (23U)
#define ADC_CSR_AWD1_SLV_Msk           (0x1U << ADC_CSR_AWD1_SLV_Pos)
#define ADC_CSR_AWD1_SLV               ADC_CSR_AWD1_SLV_Msk
#define ADC_CSR_AWD2_SLV_Pos           (24U)
#define ADC_CSR_AWD2_SLV_Msk           (0x1U << ADC_CSR_AWD2_SLV_Pos)
#define ADC_CSR_AWD2_SLV               ADC_CSR_AWD2_SLV_Msk
#define ADC_CSR_AWD3_SLV_Pos           (25U)
#define ADC_CSR_AWD3_SLV_Msk           (0x1U << ADC_CSR_AWD3_SLV_Pos)
#define ADC_CSR_AWD3_SLV               ADC_CSR_AWD3_SLV_Msk
#define ADC_CSR_JQOVF_SLV_Pos          (26U)
#define ADC_CSR_JQOVF_SLV_Msk          (0x1U << ADC_CSR_JQOVF_SLV_Pos)
#define ADC_CSR_JQOVF_SLV              ADC_CSR_JQOVF_SLV_Msk


#define ADC_CSR_ADRDY_EOSMP_MST   ADC_CSR_EOSMP_MST
#define ADC_CSR_ADRDY_EOC_MST     ADC_CSR_EOC_MST
#define ADC_CSR_ADRDY_EOS_MST     ADC_CSR_EOS_MST
#define ADC_CSR_ADRDY_OVR_MST     ADC_CSR_OVR_MST
#define ADC_CSR_ADRDY_JEOC_MST    ADC_CSR_JEOC_MST
#define ADC_CSR_ADRDY_JEOS_MST    ADC_CSR_JEOS_MST

#define ADC_CSR_ADRDY_EOSMP_SLV   ADC_CSR_EOSMP_SLV
#define ADC_CSR_ADRDY_EOC_SLV     ADC_CSR_EOC_SLV
#define ADC_CSR_ADRDY_EOS_SLV     ADC_CSR_EOS_SLV
#define ADC_CSR_ADRDY_OVR_SLV     ADC_CSR_OVR_SLV
#define ADC_CSR_ADRDY_JEOC_SLV    ADC_CSR_JEOC_SLV
#define ADC_CSR_ADRDY_JEOS_SLV    ADC_CSR_JEOS_SLV


#define ADC_CCR_DUAL_Pos               (0U)
#define ADC_CCR_DUAL_Msk               (0x1FU << ADC_CCR_DUAL_Pos)
#define ADC_CCR_DUAL                   ADC_CCR_DUAL_Msk
#define ADC_CCR_DUAL_0                 (0x01U << ADC_CCR_DUAL_Pos)
#define ADC_CCR_DUAL_1                 (0x02U << ADC_CCR_DUAL_Pos)
#define ADC_CCR_DUAL_2                 (0x04U << ADC_CCR_DUAL_Pos)
#define ADC_CCR_DUAL_3                 (0x08U << ADC_CCR_DUAL_Pos)
#define ADC_CCR_DUAL_4                 (0x10U << ADC_CCR_DUAL_Pos)

#define ADC_CCR_DELAY_Pos              (8U)
#define ADC_CCR_DELAY_Msk              (0xFU << ADC_CCR_DELAY_Pos)
#define ADC_CCR_DELAY                  ADC_CCR_DELAY_Msk
#define ADC_CCR_DELAY_0                (0x1U << ADC_CCR_DELAY_Pos)
#define ADC_CCR_DELAY_1                (0x2U << ADC_CCR_DELAY_Pos)
#define ADC_CCR_DELAY_2                (0x4U << ADC_CCR_DELAY_Pos)
#define ADC_CCR_DELAY_3                (0x8U << ADC_CCR_DELAY_Pos)

#define ADC_CCR_DMACFG_Pos             (13U)
#define ADC_CCR_DMACFG_Msk             (0x1U << ADC_CCR_DMACFG_Pos)
#define ADC_CCR_DMACFG                 ADC_CCR_DMACFG_Msk

#define ADC_CCR_MDMA_Pos               (14U)
#define ADC_CCR_MDMA_Msk               (0x3U << ADC_CCR_MDMA_Pos)
#define ADC_CCR_MDMA                   ADC_CCR_MDMA_Msk
#define ADC_CCR_MDMA_0                 (0x1U << ADC_CCR_MDMA_Pos)
#define ADC_CCR_MDMA_1                 (0x2U << ADC_CCR_MDMA_Pos)

#define ADC_CCR_CKMODE_Pos             (16U)
#define ADC_CCR_CKMODE_Msk             (0x3U << ADC_CCR_CKMODE_Pos)
#define ADC_CCR_CKMODE                 ADC_CCR_CKMODE_Msk
#define ADC_CCR_CKMODE_0               (0x1U << ADC_CCR_CKMODE_Pos)
#define ADC_CCR_CKMODE_1               (0x2U << ADC_CCR_CKMODE_Pos)

#define ADC_CCR_VREFEN_Pos             (22U)
#define ADC_CCR_VREFEN_Msk             (0x1U << ADC_CCR_VREFEN_Pos)
#define ADC_CCR_VREFEN                 ADC_CCR_VREFEN_Msk
#define ADC_CCR_TSEN_Pos               (23U)
#define ADC_CCR_TSEN_Msk               (0x1U << ADC_CCR_TSEN_Pos)
#define ADC_CCR_TSEN                   ADC_CCR_TSEN_Msk
#define ADC_CCR_VBATEN_Pos             (24U)
#define ADC_CCR_VBATEN_Msk             (0x1U << ADC_CCR_VBATEN_Pos)
#define ADC_CCR_VBATEN                 ADC_CCR_VBATEN_Msk


#define ADC_CCR_MULTI           (ADC_CCR_DUAL)
#define ADC_CCR_MULTI_0         (ADC_CCR_DUAL_0)
#define ADC_CCR_MULTI_1         (ADC_CCR_DUAL_1)
#define ADC_CCR_MULTI_2         (ADC_CCR_DUAL_2)
#define ADC_CCR_MULTI_3         (ADC_CCR_DUAL_3)
#define ADC_CCR_MULTI_4         (ADC_CCR_DUAL_4)


#define ADC_CDR_RDATA_MST_Pos          (0U)
#define ADC_CDR_RDATA_MST_Msk          (0xFFFFU << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST              ADC_CDR_RDATA_MST_Msk
#define ADC_CDR_RDATA_MST_0            (0x0001U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_1            (0x0002U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_2            (0x0004U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_3            (0x0008U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_4            (0x0010U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_5            (0x0020U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_6            (0x0040U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_7            (0x0080U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_8            (0x0100U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_9            (0x0200U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_10           (0x0400U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_11           (0x0800U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_12           (0x1000U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_13           (0x2000U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_14           (0x4000U << ADC_CDR_RDATA_MST_Pos)
#define ADC_CDR_RDATA_MST_15           (0x8000U << ADC_CDR_RDATA_MST_Pos)

#define ADC_CDR_RDATA_SLV_Pos          (16U)
#define ADC_CDR_RDATA_SLV_Msk          (0xFFFFU << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV              ADC_CDR_RDATA_SLV_Msk
#define ADC_CDR_RDATA_SLV_0            (0x0001U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_1            (0x0002U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_2            (0x0004U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_3            (0x0008U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_4            (0x0010U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_5            (0x0020U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_6            (0x0040U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_7            (0x0080U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_8            (0x0100U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_9            (0x0200U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_10           (0x0400U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_11           (0x0800U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_12           (0x1000U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_13           (0x2000U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_14           (0x4000U << ADC_CDR_RDATA_SLV_Pos)
#define ADC_CDR_RDATA_SLV_15           (0x8000U << ADC_CDR_RDATA_SLV_Pos)







#define COMP_V1_3_0_0


#define COMP2_CSR_COMP2EN_Pos            (0U)
#define COMP2_CSR_COMP2EN_Msk            (0x1U << COMP2_CSR_COMP2EN_Pos)
#define COMP2_CSR_COMP2EN                COMP2_CSR_COMP2EN_Msk
#define COMP2_CSR_COMP2INSEL_Pos         (4U)
#define COMP2_CSR_COMP2INSEL_Msk         (0x40007U << COMP2_CSR_COMP2INSEL_Pos)
#define COMP2_CSR_COMP2INSEL             COMP2_CSR_COMP2INSEL_Msk
#define COMP2_CSR_COMP2INSEL_0           (0x00000010U)
#define COMP2_CSR_COMP2INSEL_1           (0x00000020U)
#define COMP2_CSR_COMP2INSEL_2           (0x00000040U)
#define COMP2_CSR_COMP2INSEL_3           (0x00400000U)
#define COMP2_CSR_COMP2OUTSEL_Pos        (10U)
#define COMP2_CSR_COMP2OUTSEL_Msk        (0xFU << COMP2_CSR_COMP2OUTSEL_Pos)
#define COMP2_CSR_COMP2OUTSEL            COMP2_CSR_COMP2OUTSEL_Msk
#define COMP2_CSR_COMP2OUTSEL_0          (0x1U << COMP2_CSR_COMP2OUTSEL_Pos)
#define COMP2_CSR_COMP2OUTSEL_1          (0x2U << COMP2_CSR_COMP2OUTSEL_Pos)
#define COMP2_CSR_COMP2OUTSEL_2          (0x4U << COMP2_CSR_COMP2OUTSEL_Pos)
#define COMP2_CSR_COMP2OUTSEL_3          (0x8U << COMP2_CSR_COMP2OUTSEL_Pos)
#define COMP2_CSR_COMP2POL_Pos           (15U)
#define COMP2_CSR_COMP2POL_Msk           (0x1U << COMP2_CSR_COMP2POL_Pos)
#define COMP2_CSR_COMP2POL               COMP2_CSR_COMP2POL_Msk
#define COMP2_CSR_COMP2BLANKING_Pos      (18U)
#define COMP2_CSR_COMP2BLANKING_Msk      (0x3U << COMP2_CSR_COMP2BLANKING_Pos)
#define COMP2_CSR_COMP2BLANKING          COMP2_CSR_COMP2BLANKING_Msk
#define COMP2_CSR_COMP2BLANKING_0        (0x1U << COMP2_CSR_COMP2BLANKING_Pos)
#define COMP2_CSR_COMP2BLANKING_1        (0x2U << COMP2_CSR_COMP2BLANKING_Pos)
#define COMP2_CSR_COMP2BLANKING_2        (0x4U << COMP2_CSR_COMP2BLANKING_Pos)
#define COMP2_CSR_COMP2OUT_Pos           (30U)
#define COMP2_CSR_COMP2OUT_Msk           (0x1U << COMP2_CSR_COMP2OUT_Pos)
#define COMP2_CSR_COMP2OUT               COMP2_CSR_COMP2OUT_Msk
#define COMP2_CSR_COMP2LOCK_Pos          (31U)
#define COMP2_CSR_COMP2LOCK_Msk          (0x1U << COMP2_CSR_COMP2LOCK_Pos)
#define COMP2_CSR_COMP2LOCK              COMP2_CSR_COMP2LOCK_Msk


#define COMP4_CSR_COMP4EN_Pos            (0U)
#define COMP4_CSR_COMP4EN_Msk            (0x1U << COMP4_CSR_COMP4EN_Pos)
#define COMP4_CSR_COMP4EN                COMP4_CSR_COMP4EN_Msk
#define COMP4_CSR_COMP4INSEL_Pos         (4U)
#define COMP4_CSR_COMP4INSEL_Msk         (0x40007U << COMP4_CSR_COMP4INSEL_Pos)
#define COMP4_CSR_COMP4INSEL             COMP4_CSR_COMP4INSEL_Msk
#define COMP4_CSR_COMP4INSEL_0           (0x00000010U)
#define COMP4_CSR_COMP4INSEL_1           (0x00000020U)
#define COMP4_CSR_COMP4INSEL_2           (0x00000040U)
#define COMP4_CSR_COMP4INSEL_3           (0x00400000U)
#define COMP4_CSR_COMP4OUTSEL_Pos        (10U)
#define COMP4_CSR_COMP4OUTSEL_Msk        (0xFU << COMP4_CSR_COMP4OUTSEL_Pos)
#define COMP4_CSR_COMP4OUTSEL            COMP4_CSR_COMP4OUTSEL_Msk
#define COMP4_CSR_COMP4OUTSEL_0          (0x1U << COMP4_CSR_COMP4OUTSEL_Pos)
#define COMP4_CSR_COMP4OUTSEL_1          (0x2U << COMP4_CSR_COMP4OUTSEL_Pos)
#define COMP4_CSR_COMP4OUTSEL_2          (0x4U << COMP4_CSR_COMP4OUTSEL_Pos)
#define COMP4_CSR_COMP4OUTSEL_3          (0x8U << COMP4_CSR_COMP4OUTSEL_Pos)
#define COMP4_CSR_COMP4POL_Pos           (15U)
#define COMP4_CSR_COMP4POL_Msk           (0x1U << COMP4_CSR_COMP4POL_Pos)
#define COMP4_CSR_COMP4POL               COMP4_CSR_COMP4POL_Msk
#define COMP4_CSR_COMP4BLANKING_Pos      (18U)
#define COMP4_CSR_COMP4BLANKING_Msk      (0x3U << COMP4_CSR_COMP4BLANKING_Pos)
#define COMP4_CSR_COMP4BLANKING          COMP4_CSR_COMP4BLANKING_Msk
#define COMP4_CSR_COMP4BLANKING_0        (0x1U << COMP4_CSR_COMP4BLANKING_Pos)
#define COMP4_CSR_COMP4BLANKING_1        (0x2U << COMP4_CSR_COMP4BLANKING_Pos)
#define COMP4_CSR_COMP4BLANKING_2        (0x4U << COMP4_CSR_COMP4BLANKING_Pos)
#define COMP4_CSR_COMP4OUT_Pos           (30U)
#define COMP4_CSR_COMP4OUT_Msk           (0x1U << COMP4_CSR_COMP4OUT_Pos)
#define COMP4_CSR_COMP4OUT               COMP4_CSR_COMP4OUT_Msk
#define COMP4_CSR_COMP4LOCK_Pos          (31U)
#define COMP4_CSR_COMP4LOCK_Msk          (0x1U << COMP4_CSR_COMP4LOCK_Pos)
#define COMP4_CSR_COMP4LOCK              COMP4_CSR_COMP4LOCK_Msk


#define COMP6_CSR_COMP6EN_Pos            (0U)
#define COMP6_CSR_COMP6EN_Msk            (0x1U << COMP6_CSR_COMP6EN_Pos)
#define COMP6_CSR_COMP6EN                COMP6_CSR_COMP6EN_Msk
#define COMP6_CSR_COMP6INSEL_Pos         (4U)
#define COMP6_CSR_COMP6INSEL_Msk         (0x40007U << COMP6_CSR_COMP6INSEL_Pos)
#define COMP6_CSR_COMP6INSEL             COMP6_CSR_COMP6INSEL_Msk
#define COMP6_CSR_COMP6INSEL_0           (0x00000010U)
#define COMP6_CSR_COMP6INSEL_1           (0x00000020U)
#define COMP6_CSR_COMP6INSEL_2           (0x00000040U)
#define COMP6_CSR_COMP6INSEL_3           (0x00400000U)
#define COMP6_CSR_COMP6OUTSEL_Pos        (10U)
#define COMP6_CSR_COMP6OUTSEL_Msk        (0xFU << COMP6_CSR_COMP6OUTSEL_Pos)
#define COMP6_CSR_COMP6OUTSEL            COMP6_CSR_COMP6OUTSEL_Msk
#define COMP6_CSR_COMP6OUTSEL_0          (0x1U << COMP6_CSR_COMP6OUTSEL_Pos)
#define COMP6_CSR_COMP6OUTSEL_1          (0x2U << COMP6_CSR_COMP6OUTSEL_Pos)
#define COMP6_CSR_COMP6OUTSEL_2          (0x4U << COMP6_CSR_COMP6OUTSEL_Pos)
#define COMP6_CSR_COMP6OUTSEL_3          (0x8U << COMP6_CSR_COMP6OUTSEL_Pos)
#define COMP6_CSR_COMP6POL_Pos           (15U)
#define COMP6_CSR_COMP6POL_Msk           (0x1U << COMP6_CSR_COMP6POL_Pos)
#define COMP6_CSR_COMP6POL               COMP6_CSR_COMP6POL_Msk
#define COMP6_CSR_COMP6BLANKING_Pos      (18U)
#define COMP6_CSR_COMP6BLANKING_Msk      (0x3U << COMP6_CSR_COMP6BLANKING_Pos)
#define COMP6_CSR_COMP6BLANKING          COMP6_CSR_COMP6BLANKING_Msk
#define COMP6_CSR_COMP6BLANKING_0        (0x1U << COMP6_CSR_COMP6BLANKING_Pos)
#define COMP6_CSR_COMP6BLANKING_1        (0x2U << COMP6_CSR_COMP6BLANKING_Pos)
#define COMP6_CSR_COMP6BLANKING_2        (0x4U << COMP6_CSR_COMP6BLANKING_Pos)
#define COMP6_CSR_COMP6OUT_Pos           (30U)
#define COMP6_CSR_COMP6OUT_Msk           (0x1U << COMP6_CSR_COMP6OUT_Pos)
#define COMP6_CSR_COMP6OUT               COMP6_CSR_COMP6OUT_Msk
#define COMP6_CSR_COMP6LOCK_Pos          (31U)
#define COMP6_CSR_COMP6LOCK_Msk          (0x1U << COMP6_CSR_COMP6LOCK_Pos)
#define COMP6_CSR_COMP6LOCK              COMP6_CSR_COMP6LOCK_Msk


#define COMP_CSR_COMPxEN_Pos            (0U)
#define COMP_CSR_COMPxEN_Msk            (0x1U << COMP_CSR_COMPxEN_Pos)
#define COMP_CSR_COMPxEN                COMP_CSR_COMPxEN_Msk
#define COMP_CSR_COMPxINSEL_Pos         (4U)
#define COMP_CSR_COMPxINSEL_Msk         (0x40007U << COMP_CSR_COMPxINSEL_Pos)
#define COMP_CSR_COMPxINSEL             COMP_CSR_COMPxINSEL_Msk
#define COMP_CSR_COMPxINSEL_0           (0x00000010U)
#define COMP_CSR_COMPxINSEL_1           (0x00000020U)
#define COMP_CSR_COMPxINSEL_2           (0x00000040U)
#define COMP_CSR_COMPxINSEL_3           (0x00400000U)
#define COMP_CSR_COMPxOUTSEL_Pos        (10U)
#define COMP_CSR_COMPxOUTSEL_Msk        (0xFU << COMP_CSR_COMPxOUTSEL_Pos)
#define COMP_CSR_COMPxOUTSEL            COMP_CSR_COMPxOUTSEL_Msk
#define COMP_CSR_COMPxOUTSEL_0          (0x1U << COMP_CSR_COMPxOUTSEL_Pos)
#define COMP_CSR_COMPxOUTSEL_1          (0x2U << COMP_CSR_COMPxOUTSEL_Pos)
#define COMP_CSR_COMPxOUTSEL_2          (0x4U << COMP_CSR_COMPxOUTSEL_Pos)
#define COMP_CSR_COMPxOUTSEL_3          (0x8U << COMP_CSR_COMPxOUTSEL_Pos)
#define COMP_CSR_COMPxPOL_Pos           (15U)
#define COMP_CSR_COMPxPOL_Msk           (0x1U << COMP_CSR_COMPxPOL_Pos)
#define COMP_CSR_COMPxPOL               COMP_CSR_COMPxPOL_Msk
#define COMP_CSR_COMPxBLANKING_Pos      (18U)
#define COMP_CSR_COMPxBLANKING_Msk      (0x3U << COMP_CSR_COMPxBLANKING_Pos)
#define COMP_CSR_COMPxBLANKING          COMP_CSR_COMPxBLANKING_Msk
#define COMP_CSR_COMPxBLANKING_0        (0x1U << COMP_CSR_COMPxBLANKING_Pos)
#define COMP_CSR_COMPxBLANKING_1        (0x2U << COMP_CSR_COMPxBLANKING_Pos)
#define COMP_CSR_COMPxBLANKING_2        (0x4U << COMP_CSR_COMPxBLANKING_Pos)
#define COMP_CSR_COMPxOUT_Pos           (30U)
#define COMP_CSR_COMPxOUT_Msk           (0x1U << COMP_CSR_COMPxOUT_Pos)
#define COMP_CSR_COMPxOUT               COMP_CSR_COMPxOUT_Msk
#define COMP_CSR_COMPxLOCK_Pos          (31U)
#define COMP_CSR_COMPxLOCK_Msk          (0x1U << COMP_CSR_COMPxLOCK_Pos)
#define COMP_CSR_COMPxLOCK              COMP_CSR_COMPxLOCK_Msk







#define OPAMP2_CSR_OPAMP2EN_Pos       (0U)
#define OPAMP2_CSR_OPAMP2EN_Msk       (0x1U << OPAMP2_CSR_OPAMP2EN_Pos)
#define OPAMP2_CSR_OPAMP2EN           OPAMP2_CSR_OPAMP2EN_Msk
#define OPAMP2_CSR_FORCEVP_Pos        (1U)
#define OPAMP2_CSR_FORCEVP_Msk        (0x1U << OPAMP2_CSR_FORCEVP_Pos)
#define OPAMP2_CSR_FORCEVP            OPAMP2_CSR_FORCEVP_Msk
#define OPAMP2_CSR_VPSEL_Pos          (2U)
#define OPAMP2_CSR_VPSEL_Msk          (0x3U << OPAMP2_CSR_VPSEL_Pos)
#define OPAMP2_CSR_VPSEL              OPAMP2_CSR_VPSEL_Msk
#define OPAMP2_CSR_VPSEL_0            (0x1U << OPAMP2_CSR_VPSEL_Pos)
#define OPAMP2_CSR_VPSEL_1            (0x2U << OPAMP2_CSR_VPSEL_Pos)
#define OPAMP2_CSR_VMSEL_Pos          (5U)
#define OPAMP2_CSR_VMSEL_Msk          (0x3U << OPAMP2_CSR_VMSEL_Pos)
#define OPAMP2_CSR_VMSEL              OPAMP2_CSR_VMSEL_Msk
#define OPAMP2_CSR_VMSEL_0            (0x1U << OPAMP2_CSR_VMSEL_Pos)
#define OPAMP2_CSR_VMSEL_1            (0x2U << OPAMP2_CSR_VMSEL_Pos)
#define OPAMP2_CSR_TCMEN_Pos          (7U)
#define OPAMP2_CSR_TCMEN_Msk          (0x1U << OPAMP2_CSR_TCMEN_Pos)
#define OPAMP2_CSR_TCMEN              OPAMP2_CSR_TCMEN_Msk
#define OPAMP2_CSR_VMSSEL_Pos         (8U)
#define OPAMP2_CSR_VMSSEL_Msk         (0x1U << OPAMP2_CSR_VMSSEL_Pos)
#define OPAMP2_CSR_VMSSEL             OPAMP2_CSR_VMSSEL_Msk
#define OPAMP2_CSR_VPSSEL_Pos         (9U)
#define OPAMP2_CSR_VPSSEL_Msk         (0x3U << OPAMP2_CSR_VPSSEL_Pos)
#define OPAMP2_CSR_VPSSEL             OPAMP2_CSR_VPSSEL_Msk
#define OPAMP2_CSR_VPSSEL_0           (0x1U << OPAMP2_CSR_VPSSEL_Pos)
#define OPAMP2_CSR_VPSSEL_1           (0x2U << OPAMP2_CSR_VPSSEL_Pos)
#define OPAMP2_CSR_CALON_Pos          (11U)
#define OPAMP2_CSR_CALON_Msk          (0x1U << OPAMP2_CSR_CALON_Pos)
#define OPAMP2_CSR_CALON              OPAMP2_CSR_CALON_Msk
#define OPAMP2_CSR_CALSEL_Pos         (12U)
#define OPAMP2_CSR_CALSEL_Msk         (0x3U << OPAMP2_CSR_CALSEL_Pos)
#define OPAMP2_CSR_CALSEL             OPAMP2_CSR_CALSEL_Msk
#define OPAMP2_CSR_CALSEL_0           (0x1U << OPAMP2_CSR_CALSEL_Pos)
#define OPAMP2_CSR_CALSEL_1           (0x2U << OPAMP2_CSR_CALSEL_Pos)
#define OPAMP2_CSR_PGGAIN_Pos         (14U)
#define OPAMP2_CSR_PGGAIN_Msk         (0xFU << OPAMP2_CSR_PGGAIN_Pos)
#define OPAMP2_CSR_PGGAIN             OPAMP2_CSR_PGGAIN_Msk
#define OPAMP2_CSR_PGGAIN_0           (0x1U << OPAMP2_CSR_PGGAIN_Pos)
#define OPAMP2_CSR_PGGAIN_1           (0x2U << OPAMP2_CSR_PGGAIN_Pos)
#define OPAMP2_CSR_PGGAIN_2           (0x4U << OPAMP2_CSR_PGGAIN_Pos)
#define OPAMP2_CSR_PGGAIN_3           (0x8U << OPAMP2_CSR_PGGAIN_Pos)
#define OPAMP2_CSR_USERTRIM_Pos       (18U)
#define OPAMP2_CSR_USERTRIM_Msk       (0x1U << OPAMP2_CSR_USERTRIM_Pos)
#define OPAMP2_CSR_USERTRIM           OPAMP2_CSR_USERTRIM_Msk
#define OPAMP2_CSR_TRIMOFFSETP_Pos    (19U)
#define OPAMP2_CSR_TRIMOFFSETP_Msk    (0x1FU << OPAMP2_CSR_TRIMOFFSETP_Pos)
#define OPAMP2_CSR_TRIMOFFSETP        OPAMP2_CSR_TRIMOFFSETP_Msk
#define OPAMP2_CSR_TRIMOFFSETN_Pos    (24U)
#define OPAMP2_CSR_TRIMOFFSETN_Msk    (0x1FU << OPAMP2_CSR_TRIMOFFSETN_Pos)
#define OPAMP2_CSR_TRIMOFFSETN        OPAMP2_CSR_TRIMOFFSETN_Msk
#define OPAMP2_CSR_TSTREF_Pos         (29U)
#define OPAMP2_CSR_TSTREF_Msk         (0x1U << OPAMP2_CSR_TSTREF_Pos)
#define OPAMP2_CSR_TSTREF             OPAMP2_CSR_TSTREF_Msk
#define OPAMP2_CSR_OUTCAL_Pos         (30U)
#define OPAMP2_CSR_OUTCAL_Msk         (0x1U << OPAMP2_CSR_OUTCAL_Pos)
#define OPAMP2_CSR_OUTCAL             OPAMP2_CSR_OUTCAL_Msk
#define OPAMP2_CSR_LOCK_Pos           (31U)
#define OPAMP2_CSR_LOCK_Msk           (0x1U << OPAMP2_CSR_LOCK_Pos)
#define OPAMP2_CSR_LOCK               OPAMP2_CSR_LOCK_Msk


#define OPAMP_CSR_OPAMPxEN_Pos       (0U)
#define OPAMP_CSR_OPAMPxEN_Msk       (0x1U << OPAMP_CSR_OPAMPxEN_Pos)
#define OPAMP_CSR_OPAMPxEN           OPAMP_CSR_OPAMPxEN_Msk
#define OPAMP_CSR_FORCEVP_Pos        (1U)
#define OPAMP_CSR_FORCEVP_Msk        (0x1U << OPAMP_CSR_FORCEVP_Pos)
#define OPAMP_CSR_FORCEVP            OPAMP_CSR_FORCEVP_Msk
#define OPAMP_CSR_VPSEL_Pos          (2U)
#define OPAMP_CSR_VPSEL_Msk          (0x3U << OPAMP_CSR_VPSEL_Pos)
#define OPAMP_CSR_VPSEL              OPAMP_CSR_VPSEL_Msk
#define OPAMP_CSR_VPSEL_0            (0x1U << OPAMP_CSR_VPSEL_Pos)
#define OPAMP_CSR_VPSEL_1            (0x2U << OPAMP_CSR_VPSEL_Pos)
#define OPAMP_CSR_VMSEL_Pos          (5U)
#define OPAMP_CSR_VMSEL_Msk          (0x3U << OPAMP_CSR_VMSEL_Pos)
#define OPAMP_CSR_VMSEL              OPAMP_CSR_VMSEL_Msk
#define OPAMP_CSR_VMSEL_0            (0x1U << OPAMP_CSR_VMSEL_Pos)
#define OPAMP_CSR_VMSEL_1            (0x2U << OPAMP_CSR_VMSEL_Pos)
#define OPAMP_CSR_TCMEN_Pos          (7U)
#define OPAMP_CSR_TCMEN_Msk          (0x1U << OPAMP_CSR_TCMEN_Pos)
#define OPAMP_CSR_TCMEN              OPAMP_CSR_TCMEN_Msk
#define OPAMP_CSR_VMSSEL_Pos         (8U)
#define OPAMP_CSR_VMSSEL_Msk         (0x1U << OPAMP_CSR_VMSSEL_Pos)
#define OPAMP_CSR_VMSSEL             OPAMP_CSR_VMSSEL_Msk
#define OPAMP_CSR_VPSSEL_Pos         (9U)
#define OPAMP_CSR_VPSSEL_Msk         (0x3U << OPAMP_CSR_VPSSEL_Pos)
#define OPAMP_CSR_VPSSEL             OPAMP_CSR_VPSSEL_Msk
#define OPAMP_CSR_VPSSEL_0           (0x1U << OPAMP_CSR_VPSSEL_Pos)
#define OPAMP_CSR_VPSSEL_1           (0x2U << OPAMP_CSR_VPSSEL_Pos)
#define OPAMP_CSR_CALON_Pos          (11U)
#define OPAMP_CSR_CALON_Msk          (0x1U << OPAMP_CSR_CALON_Pos)
#define OPAMP_CSR_CALON              OPAMP_CSR_CALON_Msk
#define OPAMP_CSR_CALSEL_Pos         (12U)
#define OPAMP_CSR_CALSEL_Msk         (0x3U << OPAMP_CSR_CALSEL_Pos)
#define OPAMP_CSR_CALSEL             OPAMP_CSR_CALSEL_Msk
#define OPAMP_CSR_CALSEL_0           (0x1U << OPAMP_CSR_CALSEL_Pos)
#define OPAMP_CSR_CALSEL_1           (0x2U << OPAMP_CSR_CALSEL_Pos)
#define OPAMP_CSR_PGGAIN_Pos         (14U)
#define OPAMP_CSR_PGGAIN_Msk         (0xFU << OPAMP_CSR_PGGAIN_Pos)
#define OPAMP_CSR_PGGAIN             OPAMP_CSR_PGGAIN_Msk
#define OPAMP_CSR_PGGAIN_0           (0x1U << OPAMP_CSR_PGGAIN_Pos)
#define OPAMP_CSR_PGGAIN_1           (0x2U << OPAMP_CSR_PGGAIN_Pos)
#define OPAMP_CSR_PGGAIN_2           (0x4U << OPAMP_CSR_PGGAIN_Pos)
#define OPAMP_CSR_PGGAIN_3           (0x8U << OPAMP_CSR_PGGAIN_Pos)
#define OPAMP_CSR_USERTRIM_Pos       (18U)
#define OPAMP_CSR_USERTRIM_Msk       (0x1U << OPAMP_CSR_USERTRIM_Pos)
#define OPAMP_CSR_USERTRIM           OPAMP_CSR_USERTRIM_Msk
#define OPAMP_CSR_TRIMOFFSETP_Pos    (19U)
#define OPAMP_CSR_TRIMOFFSETP_Msk    (0x1FU << OPAMP_CSR_TRIMOFFSETP_Pos)
#define OPAMP_CSR_TRIMOFFSETP        OPAMP_CSR_TRIMOFFSETP_Msk
#define OPAMP_CSR_TRIMOFFSETN_Pos    (24U)
#define OPAMP_CSR_TRIMOFFSETN_Msk    (0x1FU << OPAMP_CSR_TRIMOFFSETN_Pos)
#define OPAMP_CSR_TRIMOFFSETN        OPAMP_CSR_TRIMOFFSETN_Msk
#define OPAMP_CSR_TSTREF_Pos         (29U)
#define OPAMP_CSR_TSTREF_Msk         (0x1U << OPAMP_CSR_TSTREF_Pos)
#define OPAMP_CSR_TSTREF             OPAMP_CSR_TSTREF_Msk
#define OPAMP_CSR_OUTCAL_Pos         (30U)
#define OPAMP_CSR_OUTCAL_Msk         (0x1U << OPAMP_CSR_OUTCAL_Pos)
#define OPAMP_CSR_OUTCAL             OPAMP_CSR_OUTCAL_Msk
#define OPAMP_CSR_LOCK_Pos           (31U)
#define OPAMP_CSR_LOCK_Msk           (0x1U << OPAMP_CSR_LOCK_Pos)
#define OPAMP_CSR_LOCK               OPAMP_CSR_LOCK_Msk







#define CAN_MCR_INRQ_Pos       (0U)
#define CAN_MCR_INRQ_Msk       (0x1U << CAN_MCR_INRQ_Pos)
#define CAN_MCR_INRQ           CAN_MCR_INRQ_Msk
#define CAN_MCR_SLEEP_Pos      (1U)
#define CAN_MCR_SLEEP_Msk      (0x1U << CAN_MCR_SLEEP_Pos)
#define CAN_MCR_SLEEP          CAN_MCR_SLEEP_Msk
#define CAN_MCR_TXFP_Pos       (2U)
#define CAN_MCR_TXFP_Msk       (0x1U << CAN_MCR_TXFP_Pos)
#define CAN_MCR_TXFP           CAN_MCR_TXFP_Msk
#define CAN_MCR_RFLM_Pos       (3U)
#define CAN_MCR_RFLM_Msk       (0x1U << CAN_MCR_RFLM_Pos)
#define CAN_MCR_RFLM           CAN_MCR_RFLM_Msk
#define CAN_MCR_NART_Pos       (4U)
#define CAN_MCR_NART_Msk       (0x1U << CAN_MCR_NART_Pos)
#define CAN_MCR_NART           CAN_MCR_NART_Msk
#define CAN_MCR_AWUM_Pos       (5U)
#define CAN_MCR_AWUM_Msk       (0x1U << CAN_MCR_AWUM_Pos)
#define CAN_MCR_AWUM           CAN_MCR_AWUM_Msk
#define CAN_MCR_ABOM_Pos       (6U)
#define CAN_MCR_ABOM_Msk       (0x1U << CAN_MCR_ABOM_Pos)
#define CAN_MCR_ABOM           CAN_MCR_ABOM_Msk
#define CAN_MCR_TTCM_Pos       (7U)
#define CAN_MCR_TTCM_Msk       (0x1U << CAN_MCR_TTCM_Pos)
#define CAN_MCR_TTCM           CAN_MCR_TTCM_Msk
#define CAN_MCR_RESET_Pos      (15U)
#define CAN_MCR_RESET_Msk      (0x1U << CAN_MCR_RESET_Pos)
#define CAN_MCR_RESET          CAN_MCR_RESET_Msk


#define CAN_MSR_INAK_Pos       (0U)
#define CAN_MSR_INAK_Msk       (0x1U << CAN_MSR_INAK_Pos)
#define CAN_MSR_INAK           CAN_MSR_INAK_Msk
#define CAN_MSR_SLAK_Pos       (1U)
#define CAN_MSR_SLAK_Msk       (0x1U << CAN_MSR_SLAK_Pos)
#define CAN_MSR_SLAK           CAN_MSR_SLAK_Msk
#define CAN_MSR_ERRI_Pos       (2U)
#define CAN_MSR_ERRI_Msk       (0x1U << CAN_MSR_ERRI_Pos)
#define CAN_MSR_ERRI           CAN_MSR_ERRI_Msk
#define CAN_MSR_WKUI_Pos       (3U)
#define CAN_MSR_WKUI_Msk       (0x1U << CAN_MSR_WKUI_Pos)
#define CAN_MSR_WKUI           CAN_MSR_WKUI_Msk
#define CAN_MSR_SLAKI_Pos      (4U)
#define CAN_MSR_SLAKI_Msk      (0x1U << CAN_MSR_SLAKI_Pos)
#define CAN_MSR_SLAKI          CAN_MSR_SLAKI_Msk
#define CAN_MSR_TXM_Pos        (8U)
#define CAN_MSR_TXM_Msk        (0x1U << CAN_MSR_TXM_Pos)
#define CAN_MSR_TXM            CAN_MSR_TXM_Msk
#define CAN_MSR_RXM_Pos        (9U)
#define CAN_MSR_RXM_Msk        (0x1U << CAN_MSR_RXM_Pos)
#define CAN_MSR_RXM            CAN_MSR_RXM_Msk
#define CAN_MSR_SAMP_Pos       (10U)
#define CAN_MSR_SAMP_Msk       (0x1U << CAN_MSR_SAMP_Pos)
#define CAN_MSR_SAMP           CAN_MSR_SAMP_Msk
#define CAN_MSR_RX_Pos         (11U)
#define CAN_MSR_RX_Msk         (0x1U << CAN_MSR_RX_Pos)
#define CAN_MSR_RX             CAN_MSR_RX_Msk


#define CAN_TSR_RQCP0_Pos      (0U)
#define CAN_TSR_RQCP0_Msk      (0x1U << CAN_TSR_RQCP0_Pos)
#define CAN_TSR_RQCP0          CAN_TSR_RQCP0_Msk
#define CAN_TSR_TXOK0_Pos      (1U)
#define CAN_TSR_TXOK0_Msk      (0x1U << CAN_TSR_TXOK0_Pos)
#define CAN_TSR_TXOK0          CAN_TSR_TXOK0_Msk
#define CAN_TSR_ALST0_Pos      (2U)
#define CAN_TSR_ALST0_Msk      (0x1U << CAN_TSR_ALST0_Pos)
#define CAN_TSR_ALST0          CAN_TSR_ALST0_Msk
#define CAN_TSR_TERR0_Pos      (3U)
#define CAN_TSR_TERR0_Msk      (0x1U << CAN_TSR_TERR0_Pos)
#define CAN_TSR_TERR0          CAN_TSR_TERR0_Msk
#define CAN_TSR_ABRQ0_Pos      (7U)
#define CAN_TSR_ABRQ0_Msk      (0x1U << CAN_TSR_ABRQ0_Pos)
#define CAN_TSR_ABRQ0          CAN_TSR_ABRQ0_Msk
#define CAN_TSR_RQCP1_Pos      (8U)
#define CAN_TSR_RQCP1_Msk      (0x1U << CAN_TSR_RQCP1_Pos)
#define CAN_TSR_RQCP1          CAN_TSR_RQCP1_Msk
#define CAN_TSR_TXOK1_Pos      (9U)
#define CAN_TSR_TXOK1_Msk      (0x1U << CAN_TSR_TXOK1_Pos)
#define CAN_TSR_TXOK1          CAN_TSR_TXOK1_Msk
#define CAN_TSR_ALST1_Pos      (10U)
#define CAN_TSR_ALST1_Msk      (0x1U << CAN_TSR_ALST1_Pos)
#define CAN_TSR_ALST1          CAN_TSR_ALST1_Msk
#define CAN_TSR_TERR1_Pos      (11U)
#define CAN_TSR_TERR1_Msk      (0x1U << CAN_TSR_TERR1_Pos)
#define CAN_TSR_TERR1          CAN_TSR_TERR1_Msk
#define CAN_TSR_ABRQ1_Pos      (15U)
#define CAN_TSR_ABRQ1_Msk      (0x1U << CAN_TSR_ABRQ1_Pos)
#define CAN_TSR_ABRQ1          CAN_TSR_ABRQ1_Msk
#define CAN_TSR_RQCP2_Pos      (16U)
#define CAN_TSR_RQCP2_Msk      (0x1U << CAN_TSR_RQCP2_Pos)
#define CAN_TSR_RQCP2          CAN_TSR_RQCP2_Msk
#define CAN_TSR_TXOK2_Pos      (17U)
#define CAN_TSR_TXOK2_Msk      (0x1U << CAN_TSR_TXOK2_Pos)
#define CAN_TSR_TXOK2          CAN_TSR_TXOK2_Msk
#define CAN_TSR_ALST2_Pos      (18U)
#define CAN_TSR_ALST2_Msk      (0x1U << CAN_TSR_ALST2_Pos)
#define CAN_TSR_ALST2          CAN_TSR_ALST2_Msk
#define CAN_TSR_TERR2_Pos      (19U)
#define CAN_TSR_TERR2_Msk      (0x1U << CAN_TSR_TERR2_Pos)
#define CAN_TSR_TERR2          CAN_TSR_TERR2_Msk
#define CAN_TSR_ABRQ2_Pos      (23U)
#define CAN_TSR_ABRQ2_Msk      (0x1U << CAN_TSR_ABRQ2_Pos)
#define CAN_TSR_ABRQ2          CAN_TSR_ABRQ2_Msk
#define CAN_TSR_CODE_Pos       (24U)
#define CAN_TSR_CODE_Msk       (0x3U << CAN_TSR_CODE_Pos)
#define CAN_TSR_CODE           CAN_TSR_CODE_Msk

#define CAN_TSR_TME_Pos        (26U)
#define CAN_TSR_TME_Msk        (0x7U << CAN_TSR_TME_Pos)
#define CAN_TSR_TME            CAN_TSR_TME_Msk
#define CAN_TSR_TME0_Pos       (26U)
#define CAN_TSR_TME0_Msk       (0x1U << CAN_TSR_TME0_Pos)
#define CAN_TSR_TME0           CAN_TSR_TME0_Msk
#define CAN_TSR_TME1_Pos       (27U)
#define CAN_TSR_TME1_Msk       (0x1U << CAN_TSR_TME1_Pos)
#define CAN_TSR_TME1           CAN_TSR_TME1_Msk
#define CAN_TSR_TME2_Pos       (28U)
#define CAN_TSR_TME2_Msk       (0x1U << CAN_TSR_TME2_Pos)
#define CAN_TSR_TME2           CAN_TSR_TME2_Msk

#define CAN_TSR_LOW_Pos        (29U)
#define CAN_TSR_LOW_Msk        (0x7U << CAN_TSR_LOW_Pos)
#define CAN_TSR_LOW            CAN_TSR_LOW_Msk
#define CAN_TSR_LOW0_Pos       (29U)
#define CAN_TSR_LOW0_Msk       (0x1U << CAN_TSR_LOW0_Pos)
#define CAN_TSR_LOW0           CAN_TSR_LOW0_Msk
#define CAN_TSR_LOW1_Pos       (30U)
#define CAN_TSR_LOW1_Msk       (0x1U << CAN_TSR_LOW1_Pos)
#define CAN_TSR_LOW1           CAN_TSR_LOW1_Msk
#define CAN_TSR_LOW2_Pos       (31U)
#define CAN_TSR_LOW2_Msk       (0x1U << CAN_TSR_LOW2_Pos)
#define CAN_TSR_LOW2           CAN_TSR_LOW2_Msk


#define CAN_RF0R_FMP0_Pos      (0U)
#define CAN_RF0R_FMP0_Msk      (0x3U << CAN_RF0R_FMP0_Pos)
#define CAN_RF0R_FMP0          CAN_RF0R_FMP0_Msk
#define CAN_RF0R_FULL0_Pos     (3U)
#define CAN_RF0R_FULL0_Msk     (0x1U << CAN_RF0R_FULL0_Pos)
#define CAN_RF0R_FULL0         CAN_RF0R_FULL0_Msk
#define CAN_RF0R_FOVR0_Pos     (4U)
#define CAN_RF0R_FOVR0_Msk     (0x1U << CAN_RF0R_FOVR0_Pos)
#define CAN_RF0R_FOVR0         CAN_RF0R_FOVR0_Msk
#define CAN_RF0R_RFOM0_Pos     (5U)
#define CAN_RF0R_RFOM0_Msk     (0x1U << CAN_RF0R_RFOM0_Pos)
#define CAN_RF0R_RFOM0         CAN_RF0R_RFOM0_Msk


#define CAN_RF1R_FMP1_Pos      (0U)
#define CAN_RF1R_FMP1_Msk      (0x3U << CAN_RF1R_FMP1_Pos)
#define CAN_RF1R_FMP1          CAN_RF1R_FMP1_Msk
#define CAN_RF1R_FULL1_Pos     (3U)
#define CAN_RF1R_FULL1_Msk     (0x1U << CAN_RF1R_FULL1_Pos)
#define CAN_RF1R_FULL1         CAN_RF1R_FULL1_Msk
#define CAN_RF1R_FOVR1_Pos     (4U)
#define CAN_RF1R_FOVR1_Msk     (0x1U << CAN_RF1R_FOVR1_Pos)
#define CAN_RF1R_FOVR1         CAN_RF1R_FOVR1_Msk
#define CAN_RF1R_RFOM1_Pos     (5U)
#define CAN_RF1R_RFOM1_Msk     (0x1U << CAN_RF1R_RFOM1_Pos)
#define CAN_RF1R_RFOM1         CAN_RF1R_RFOM1_Msk


#define CAN_IER_TMEIE_Pos      (0U)
#define CAN_IER_TMEIE_Msk      (0x1U << CAN_IER_TMEIE_Pos)
#define CAN_IER_TMEIE          CAN_IER_TMEIE_Msk
#define CAN_IER_FMPIE0_Pos     (1U)
#define CAN_IER_FMPIE0_Msk     (0x1U << CAN_IER_FMPIE0_Pos)
#define CAN_IER_FMPIE0         CAN_IER_FMPIE0_Msk
#define CAN_IER_FFIE0_Pos      (2U)
#define CAN_IER_FFIE0_Msk      (0x1U << CAN_IER_FFIE0_Pos)
#define CAN_IER_FFIE0          CAN_IER_FFIE0_Msk
#define CAN_IER_FOVIE0_Pos     (3U)
#define CAN_IER_FOVIE0_Msk     (0x1U << CAN_IER_FOVIE0_Pos)
#define CAN_IER_FOVIE0         CAN_IER_FOVIE0_Msk
#define CAN_IER_FMPIE1_Pos     (4U)
#define CAN_IER_FMPIE1_Msk     (0x1U << CAN_IER_FMPIE1_Pos)
#define CAN_IER_FMPIE1         CAN_IER_FMPIE1_Msk
#define CAN_IER_FFIE1_Pos      (5U)
#define CAN_IER_FFIE1_Msk      (0x1U << CAN_IER_FFIE1_Pos)
#define CAN_IER_FFIE1          CAN_IER_FFIE1_Msk
#define CAN_IER_FOVIE1_Pos     (6U)
#define CAN_IER_FOVIE1_Msk     (0x1U << CAN_IER_FOVIE1_Pos)
#define CAN_IER_FOVIE1         CAN_IER_FOVIE1_Msk
#define CAN_IER_EWGIE_Pos      (8U)
#define CAN_IER_EWGIE_Msk      (0x1U << CAN_IER_EWGIE_Pos)
#define CAN_IER_EWGIE          CAN_IER_EWGIE_Msk
#define CAN_IER_EPVIE_Pos      (9U)
#define CAN_IER_EPVIE_Msk      (0x1U << CAN_IER_EPVIE_Pos)
#define CAN_IER_EPVIE          CAN_IER_EPVIE_Msk
#define CAN_IER_BOFIE_Pos      (10U)
#define CAN_IER_BOFIE_Msk      (0x1U << CAN_IER_BOFIE_Pos)
#define CAN_IER_BOFIE          CAN_IER_BOFIE_Msk
#define CAN_IER_LECIE_Pos      (11U)
#define CAN_IER_LECIE_Msk      (0x1U << CAN_IER_LECIE_Pos)
#define CAN_IER_LECIE          CAN_IER_LECIE_Msk
#define CAN_IER_ERRIE_Pos      (15U)
#define CAN_IER_ERRIE_Msk      (0x1U << CAN_IER_ERRIE_Pos)
#define CAN_IER_ERRIE          CAN_IER_ERRIE_Msk
#define CAN_IER_WKUIE_Pos      (16U)
#define CAN_IER_WKUIE_Msk      (0x1U << CAN_IER_WKUIE_Pos)
#define CAN_IER_WKUIE          CAN_IER_WKUIE_Msk
#define CAN_IER_SLKIE_Pos      (17U)
#define CAN_IER_SLKIE_Msk      (0x1U << CAN_IER_SLKIE_Pos)
#define CAN_IER_SLKIE          CAN_IER_SLKIE_Msk


#define CAN_ESR_EWGF_Pos       (0U)
#define CAN_ESR_EWGF_Msk       (0x1U << CAN_ESR_EWGF_Pos)
#define CAN_ESR_EWGF           CAN_ESR_EWGF_Msk
#define CAN_ESR_EPVF_Pos       (1U)
#define CAN_ESR_EPVF_Msk       (0x1U << CAN_ESR_EPVF_Pos)
#define CAN_ESR_EPVF           CAN_ESR_EPVF_Msk
#define CAN_ESR_BOFF_Pos       (2U)
#define CAN_ESR_BOFF_Msk       (0x1U << CAN_ESR_BOFF_Pos)
#define CAN_ESR_BOFF           CAN_ESR_BOFF_Msk

#define CAN_ESR_LEC_Pos        (4U)
#define CAN_ESR_LEC_Msk        (0x7U << CAN_ESR_LEC_Pos)
#define CAN_ESR_LEC            CAN_ESR_LEC_Msk
#define CAN_ESR_LEC_0          (0x1U << CAN_ESR_LEC_Pos)
#define CAN_ESR_LEC_1          (0x2U << CAN_ESR_LEC_Pos)
#define CAN_ESR_LEC_2          (0x4U << CAN_ESR_LEC_Pos)

#define CAN_ESR_TEC_Pos        (16U)
#define CAN_ESR_TEC_Msk        (0xFFU << CAN_ESR_TEC_Pos)
#define CAN_ESR_TEC            CAN_ESR_TEC_Msk
#define CAN_ESR_REC_Pos        (24U)
#define CAN_ESR_REC_Msk        (0xFFU << CAN_ESR_REC_Pos)
#define CAN_ESR_REC            CAN_ESR_REC_Msk


#define CAN_BTR_BRP_Pos        (0U)
#define CAN_BTR_BRP_Msk        (0x3FFU << CAN_BTR_BRP_Pos)
#define CAN_BTR_BRP            CAN_BTR_BRP_Msk
#define CAN_BTR_TS1_Pos        (16U)
#define CAN_BTR_TS1_Msk        (0xFU << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS1            CAN_BTR_TS1_Msk
#define CAN_BTR_TS1_0          (0x1U << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS1_1          (0x2U << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS1_2          (0x4U << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS1_3          (0x8U << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS2_Pos        (20U)
#define CAN_BTR_TS2_Msk        (0x7U << CAN_BTR_TS2_Pos)
#define CAN_BTR_TS2            CAN_BTR_TS2_Msk
#define CAN_BTR_TS2_0          (0x1U << CAN_BTR_TS2_Pos)
#define CAN_BTR_TS2_1          (0x2U << CAN_BTR_TS2_Pos)
#define CAN_BTR_TS2_2          (0x4U << CAN_BTR_TS2_Pos)
#define CAN_BTR_SJW_Pos        (24U)
#define CAN_BTR_SJW_Msk        (0x3U << CAN_BTR_SJW_Pos)
#define CAN_BTR_SJW            CAN_BTR_SJW_Msk
#define CAN_BTR_SJW_0          (0x1U << CAN_BTR_SJW_Pos)
#define CAN_BTR_SJW_1          (0x2U << CAN_BTR_SJW_Pos)
#define CAN_BTR_LBKM_Pos       (30U)
#define CAN_BTR_LBKM_Msk       (0x1U << CAN_BTR_LBKM_Pos)
#define CAN_BTR_LBKM           CAN_BTR_LBKM_Msk
#define CAN_BTR_SILM_Pos       (31U)
#define CAN_BTR_SILM_Msk       (0x1U << CAN_BTR_SILM_Pos)
#define CAN_BTR_SILM           CAN_BTR_SILM_Msk



#define CAN_TI0R_TXRQ_Pos      (0U)
#define CAN_TI0R_TXRQ_Msk      (0x1U << CAN_TI0R_TXRQ_Pos)
#define CAN_TI0R_TXRQ          CAN_TI0R_TXRQ_Msk
#define CAN_TI0R_RTR_Pos       (1U)
#define CAN_TI0R_RTR_Msk       (0x1U << CAN_TI0R_RTR_Pos)
#define CAN_TI0R_RTR           CAN_TI0R_RTR_Msk
#define CAN_TI0R_IDE_Pos       (2U)
#define CAN_TI0R_IDE_Msk       (0x1U << CAN_TI0R_IDE_Pos)
#define CAN_TI0R_IDE           CAN_TI0R_IDE_Msk
#define CAN_TI0R_EXID_Pos      (3U)
#define CAN_TI0R_EXID_Msk      (0x3FFFFU << CAN_TI0R_EXID_Pos)
#define CAN_TI0R_EXID          CAN_TI0R_EXID_Msk
#define CAN_TI0R_STID_Pos      (21U)
#define CAN_TI0R_STID_Msk      (0x7FFU << CAN_TI0R_STID_Pos)
#define CAN_TI0R_STID          CAN_TI0R_STID_Msk


#define CAN_TDT0R_DLC_Pos      (0U)
#define CAN_TDT0R_DLC_Msk      (0xFU << CAN_TDT0R_DLC_Pos)
#define CAN_TDT0R_DLC          CAN_TDT0R_DLC_Msk
#define CAN_TDT0R_TGT_Pos      (8U)
#define CAN_TDT0R_TGT_Msk      (0x1U << CAN_TDT0R_TGT_Pos)
#define CAN_TDT0R_TGT          CAN_TDT0R_TGT_Msk
#define CAN_TDT0R_TIME_Pos     (16U)
#define CAN_TDT0R_TIME_Msk     (0xFFFFU << CAN_TDT0R_TIME_Pos)
#define CAN_TDT0R_TIME         CAN_TDT0R_TIME_Msk


#define CAN_TDL0R_DATA0_Pos    (0U)
#define CAN_TDL0R_DATA0_Msk    (0xFFU << CAN_TDL0R_DATA0_Pos)
#define CAN_TDL0R_DATA0        CAN_TDL0R_DATA0_Msk
#define CAN_TDL0R_DATA1_Pos    (8U)
#define CAN_TDL0R_DATA1_Msk    (0xFFU << CAN_TDL0R_DATA1_Pos)
#define CAN_TDL0R_DATA1        CAN_TDL0R_DATA1_Msk
#define CAN_TDL0R_DATA2_Pos    (16U)
#define CAN_TDL0R_DATA2_Msk    (0xFFU << CAN_TDL0R_DATA2_Pos)
#define CAN_TDL0R_DATA2        CAN_TDL0R_DATA2_Msk
#define CAN_TDL0R_DATA3_Pos    (24U)
#define CAN_TDL0R_DATA3_Msk    (0xFFU << CAN_TDL0R_DATA3_Pos)
#define CAN_TDL0R_DATA3        CAN_TDL0R_DATA3_Msk


#define CAN_TDH0R_DATA4_Pos    (0U)
#define CAN_TDH0R_DATA4_Msk    (0xFFU << CAN_TDH0R_DATA4_Pos)
#define CAN_TDH0R_DATA4        CAN_TDH0R_DATA4_Msk
#define CAN_TDH0R_DATA5_Pos    (8U)
#define CAN_TDH0R_DATA5_Msk    (0xFFU << CAN_TDH0R_DATA5_Pos)
#define CAN_TDH0R_DATA5        CAN_TDH0R_DATA5_Msk
#define CAN_TDH0R_DATA6_Pos    (16U)
#define CAN_TDH0R_DATA6_Msk    (0xFFU << CAN_TDH0R_DATA6_Pos)
#define CAN_TDH0R_DATA6        CAN_TDH0R_DATA6_Msk
#define CAN_TDH0R_DATA7_Pos    (24U)
#define CAN_TDH0R_DATA7_Msk    (0xFFU << CAN_TDH0R_DATA7_Pos)
#define CAN_TDH0R_DATA7        CAN_TDH0R_DATA7_Msk


#define CAN_TI1R_TXRQ_Pos      (0U)
#define CAN_TI1R_TXRQ_Msk      (0x1U << CAN_TI1R_TXRQ_Pos)
#define CAN_TI1R_TXRQ          CAN_TI1R_TXRQ_Msk
#define CAN_TI1R_RTR_Pos       (1U)
#define CAN_TI1R_RTR_Msk       (0x1U << CAN_TI1R_RTR_Pos)
#define CAN_TI1R_RTR           CAN_TI1R_RTR_Msk
#define CAN_TI1R_IDE_Pos       (2U)
#define CAN_TI1R_IDE_Msk       (0x1U << CAN_TI1R_IDE_Pos)
#define CAN_TI1R_IDE           CAN_TI1R_IDE_Msk
#define CAN_TI1R_EXID_Pos      (3U)
#define CAN_TI1R_EXID_Msk      (0x3FFFFU << CAN_TI1R_EXID_Pos)
#define CAN_TI1R_EXID          CAN_TI1R_EXID_Msk
#define CAN_TI1R_STID_Pos      (21U)
#define CAN_TI1R_STID_Msk      (0x7FFU << CAN_TI1R_STID_Pos)
#define CAN_TI1R_STID          CAN_TI1R_STID_Msk


#define CAN_TDT1R_DLC_Pos      (0U)
#define CAN_TDT1R_DLC_Msk      (0xFU << CAN_TDT1R_DLC_Pos)
#define CAN_TDT1R_DLC          CAN_TDT1R_DLC_Msk
#define CAN_TDT1R_TGT_Pos      (8U)
#define CAN_TDT1R_TGT_Msk      (0x1U << CAN_TDT1R_TGT_Pos)
#define CAN_TDT1R_TGT          CAN_TDT1R_TGT_Msk
#define CAN_TDT1R_TIME_Pos     (16U)
#define CAN_TDT1R_TIME_Msk     (0xFFFFU << CAN_TDT1R_TIME_Pos)
#define CAN_TDT1R_TIME         CAN_TDT1R_TIME_Msk


#define CAN_TDL1R_DATA0_Pos    (0U)
#define CAN_TDL1R_DATA0_Msk    (0xFFU << CAN_TDL1R_DATA0_Pos)
#define CAN_TDL1R_DATA0        CAN_TDL1R_DATA0_Msk
#define CAN_TDL1R_DATA1_Pos    (8U)
#define CAN_TDL1R_DATA1_Msk    (0xFFU << CAN_TDL1R_DATA1_Pos)
#define CAN_TDL1R_DATA1        CAN_TDL1R_DATA1_Msk
#define CAN_TDL1R_DATA2_Pos    (16U)
#define CAN_TDL1R_DATA2_Msk    (0xFFU << CAN_TDL1R_DATA2_Pos)
#define CAN_TDL1R_DATA2        CAN_TDL1R_DATA2_Msk
#define CAN_TDL1R_DATA3_Pos    (24U)
#define CAN_TDL1R_DATA3_Msk    (0xFFU << CAN_TDL1R_DATA3_Pos)
#define CAN_TDL1R_DATA3        CAN_TDL1R_DATA3_Msk


#define CAN_TDH1R_DATA4_Pos    (0U)
#define CAN_TDH1R_DATA4_Msk    (0xFFU << CAN_TDH1R_DATA4_Pos)
#define CAN_TDH1R_DATA4        CAN_TDH1R_DATA4_Msk
#define CAN_TDH1R_DATA5_Pos    (8U)
#define CAN_TDH1R_DATA5_Msk    (0xFFU << CAN_TDH1R_DATA5_Pos)
#define CAN_TDH1R_DATA5        CAN_TDH1R_DATA5_Msk
#define CAN_TDH1R_DATA6_Pos    (16U)
#define CAN_TDH1R_DATA6_Msk    (0xFFU << CAN_TDH1R_DATA6_Pos)
#define CAN_TDH1R_DATA6        CAN_TDH1R_DATA6_Msk
#define CAN_TDH1R_DATA7_Pos    (24U)
#define CAN_TDH1R_DATA7_Msk    (0xFFU << CAN_TDH1R_DATA7_Pos)
#define CAN_TDH1R_DATA7        CAN_TDH1R_DATA7_Msk


#define CAN_TI2R_TXRQ_Pos      (0U)
#define CAN_TI2R_TXRQ_Msk      (0x1U << CAN_TI2R_TXRQ_Pos)
#define CAN_TI2R_TXRQ          CAN_TI2R_TXRQ_Msk
#define CAN_TI2R_RTR_Pos       (1U)
#define CAN_TI2R_RTR_Msk       (0x1U << CAN_TI2R_RTR_Pos)
#define CAN_TI2R_RTR           CAN_TI2R_RTR_Msk
#define CAN_TI2R_IDE_Pos       (2U)
#define CAN_TI2R_IDE_Msk       (0x1U << CAN_TI2R_IDE_Pos)
#define CAN_TI2R_IDE           CAN_TI2R_IDE_Msk
#define CAN_TI2R_EXID_Pos      (3U)
#define CAN_TI2R_EXID_Msk      (0x3FFFFU << CAN_TI2R_EXID_Pos)
#define CAN_TI2R_EXID          CAN_TI2R_EXID_Msk
#define CAN_TI2R_STID_Pos      (21U)
#define CAN_TI2R_STID_Msk      (0x7FFU << CAN_TI2R_STID_Pos)
#define CAN_TI2R_STID          CAN_TI2R_STID_Msk


#define CAN_TDT2R_DLC_Pos      (0U)
#define CAN_TDT2R_DLC_Msk      (0xFU << CAN_TDT2R_DLC_Pos)
#define CAN_TDT2R_DLC          CAN_TDT2R_DLC_Msk
#define CAN_TDT2R_TGT_Pos      (8U)
#define CAN_TDT2R_TGT_Msk      (0x1U << CAN_TDT2R_TGT_Pos)
#define CAN_TDT2R_TGT          CAN_TDT2R_TGT_Msk
#define CAN_TDT2R_TIME_Pos     (16U)
#define CAN_TDT2R_TIME_Msk     (0xFFFFU << CAN_TDT2R_TIME_Pos)
#define CAN_TDT2R_TIME         CAN_TDT2R_TIME_Msk


#define CAN_TDL2R_DATA0_Pos    (0U)
#define CAN_TDL2R_DATA0_Msk    (0xFFU << CAN_TDL2R_DATA0_Pos)
#define CAN_TDL2R_DATA0        CAN_TDL2R_DATA0_Msk
#define CAN_TDL2R_DATA1_Pos    (8U)
#define CAN_TDL2R_DATA1_Msk    (0xFFU << CAN_TDL2R_DATA1_Pos)
#define CAN_TDL2R_DATA1        CAN_TDL2R_DATA1_Msk
#define CAN_TDL2R_DATA2_Pos    (16U)
#define CAN_TDL2R_DATA2_Msk    (0xFFU << CAN_TDL2R_DATA2_Pos)
#define CAN_TDL2R_DATA2        CAN_TDL2R_DATA2_Msk
#define CAN_TDL2R_DATA3_Pos    (24U)
#define CAN_TDL2R_DATA3_Msk    (0xFFU << CAN_TDL2R_DATA3_Pos)
#define CAN_TDL2R_DATA3        CAN_TDL2R_DATA3_Msk


#define CAN_TDH2R_DATA4_Pos    (0U)
#define CAN_TDH2R_DATA4_Msk    (0xFFU << CAN_TDH2R_DATA4_Pos)
#define CAN_TDH2R_DATA4        CAN_TDH2R_DATA4_Msk
#define CAN_TDH2R_DATA5_Pos    (8U)
#define CAN_TDH2R_DATA5_Msk    (0xFFU << CAN_TDH2R_DATA5_Pos)
#define CAN_TDH2R_DATA5        CAN_TDH2R_DATA5_Msk
#define CAN_TDH2R_DATA6_Pos    (16U)
#define CAN_TDH2R_DATA6_Msk    (0xFFU << CAN_TDH2R_DATA6_Pos)
#define CAN_TDH2R_DATA6        CAN_TDH2R_DATA6_Msk
#define CAN_TDH2R_DATA7_Pos    (24U)
#define CAN_TDH2R_DATA7_Msk    (0xFFU << CAN_TDH2R_DATA7_Pos)
#define CAN_TDH2R_DATA7        CAN_TDH2R_DATA7_Msk


#define CAN_RI0R_RTR_Pos       (1U)
#define CAN_RI0R_RTR_Msk       (0x1U << CAN_RI0R_RTR_Pos)
#define CAN_RI0R_RTR           CAN_RI0R_RTR_Msk
#define CAN_RI0R_IDE_Pos       (2U)
#define CAN_RI0R_IDE_Msk       (0x1U << CAN_RI0R_IDE_Pos)
#define CAN_RI0R_IDE           CAN_RI0R_IDE_Msk
#define CAN_RI0R_EXID_Pos      (3U)
#define CAN_RI0R_EXID_Msk      (0x3FFFFU << CAN_RI0R_EXID_Pos)
#define CAN_RI0R_EXID          CAN_RI0R_EXID_Msk
#define CAN_RI0R_STID_Pos      (21U)
#define CAN_RI0R_STID_Msk      (0x7FFU << CAN_RI0R_STID_Pos)
#define CAN_RI0R_STID          CAN_RI0R_STID_Msk


#define CAN_RDT0R_DLC_Pos      (0U)
#define CAN_RDT0R_DLC_Msk      (0xFU << CAN_RDT0R_DLC_Pos)
#define CAN_RDT0R_DLC          CAN_RDT0R_DLC_Msk
#define CAN_RDT0R_FMI_Pos      (8U)
#define CAN_RDT0R_FMI_Msk      (0xFFU << CAN_RDT0R_FMI_Pos)
#define CAN_RDT0R_FMI          CAN_RDT0R_FMI_Msk
#define CAN_RDT0R_TIME_Pos     (16U)
#define CAN_RDT0R_TIME_Msk     (0xFFFFU << CAN_RDT0R_TIME_Pos)
#define CAN_RDT0R_TIME         CAN_RDT0R_TIME_Msk


#define CAN_RDL0R_DATA0_Pos    (0U)
#define CAN_RDL0R_DATA0_Msk    (0xFFU << CAN_RDL0R_DATA0_Pos)
#define CAN_RDL0R_DATA0        CAN_RDL0R_DATA0_Msk
#define CAN_RDL0R_DATA1_Pos    (8U)
#define CAN_RDL0R_DATA1_Msk    (0xFFU << CAN_RDL0R_DATA1_Pos)
#define CAN_RDL0R_DATA1        CAN_RDL0R_DATA1_Msk
#define CAN_RDL0R_DATA2_Pos    (16U)
#define CAN_RDL0R_DATA2_Msk    (0xFFU << CAN_RDL0R_DATA2_Pos)
#define CAN_RDL0R_DATA2        CAN_RDL0R_DATA2_Msk
#define CAN_RDL0R_DATA3_Pos    (24U)
#define CAN_RDL0R_DATA3_Msk    (0xFFU << CAN_RDL0R_DATA3_Pos)
#define CAN_RDL0R_DATA3        CAN_RDL0R_DATA3_Msk


#define CAN_RDH0R_DATA4_Pos    (0U)
#define CAN_RDH0R_DATA4_Msk    (0xFFU << CAN_RDH0R_DATA4_Pos)
#define CAN_RDH0R_DATA4        CAN_RDH0R_DATA4_Msk
#define CAN_RDH0R_DATA5_Pos    (8U)
#define CAN_RDH0R_DATA5_Msk    (0xFFU << CAN_RDH0R_DATA5_Pos)
#define CAN_RDH0R_DATA5        CAN_RDH0R_DATA5_Msk
#define CAN_RDH0R_DATA6_Pos    (16U)
#define CAN_RDH0R_DATA6_Msk    (0xFFU << CAN_RDH0R_DATA6_Pos)
#define CAN_RDH0R_DATA6        CAN_RDH0R_DATA6_Msk
#define CAN_RDH0R_DATA7_Pos    (24U)
#define CAN_RDH0R_DATA7_Msk    (0xFFU << CAN_RDH0R_DATA7_Pos)
#define CAN_RDH0R_DATA7        CAN_RDH0R_DATA7_Msk


#define CAN_RI1R_RTR_Pos       (1U)
#define CAN_RI1R_RTR_Msk       (0x1U << CAN_RI1R_RTR_Pos)
#define CAN_RI1R_RTR           CAN_RI1R_RTR_Msk
#define CAN_RI1R_IDE_Pos       (2U)
#define CAN_RI1R_IDE_Msk       (0x1U << CAN_RI1R_IDE_Pos)
#define CAN_RI1R_IDE           CAN_RI1R_IDE_Msk
#define CAN_RI1R_EXID_Pos      (3U)
#define CAN_RI1R_EXID_Msk      (0x3FFFFU << CAN_RI1R_EXID_Pos)
#define CAN_RI1R_EXID          CAN_RI1R_EXID_Msk
#define CAN_RI1R_STID_Pos      (21U)
#define CAN_RI1R_STID_Msk      (0x7FFU << CAN_RI1R_STID_Pos)
#define CAN_RI1R_STID          CAN_RI1R_STID_Msk


#define CAN_RDT1R_DLC_Pos      (0U)
#define CAN_RDT1R_DLC_Msk      (0xFU << CAN_RDT1R_DLC_Pos)
#define CAN_RDT1R_DLC          CAN_RDT1R_DLC_Msk
#define CAN_RDT1R_FMI_Pos      (8U)
#define CAN_RDT1R_FMI_Msk      (0xFFU << CAN_RDT1R_FMI_Pos)
#define CAN_RDT1R_FMI          CAN_RDT1R_FMI_Msk
#define CAN_RDT1R_TIME_Pos     (16U)
#define CAN_RDT1R_TIME_Msk     (0xFFFFU << CAN_RDT1R_TIME_Pos)
#define CAN_RDT1R_TIME         CAN_RDT1R_TIME_Msk


#define CAN_RDL1R_DATA0_Pos    (0U)
#define CAN_RDL1R_DATA0_Msk    (0xFFU << CAN_RDL1R_DATA0_Pos)
#define CAN_RDL1R_DATA0        CAN_RDL1R_DATA0_Msk
#define CAN_RDL1R_DATA1_Pos    (8U)
#define CAN_RDL1R_DATA1_Msk    (0xFFU << CAN_RDL1R_DATA1_Pos)
#define CAN_RDL1R_DATA1        CAN_RDL1R_DATA1_Msk
#define CAN_RDL1R_DATA2_Pos    (16U)
#define CAN_RDL1R_DATA2_Msk    (0xFFU << CAN_RDL1R_DATA2_Pos)
#define CAN_RDL1R_DATA2        CAN_RDL1R_DATA2_Msk
#define CAN_RDL1R_DATA3_Pos    (24U)
#define CAN_RDL1R_DATA3_Msk    (0xFFU << CAN_RDL1R_DATA3_Pos)
#define CAN_RDL1R_DATA3        CAN_RDL1R_DATA3_Msk


#define CAN_RDH1R_DATA4_Pos    (0U)
#define CAN_RDH1R_DATA4_Msk    (0xFFU << CAN_RDH1R_DATA4_Pos)
#define CAN_RDH1R_DATA4        CAN_RDH1R_DATA4_Msk
#define CAN_RDH1R_DATA5_Pos    (8U)
#define CAN_RDH1R_DATA5_Msk    (0xFFU << CAN_RDH1R_DATA5_Pos)
#define CAN_RDH1R_DATA5        CAN_RDH1R_DATA5_Msk
#define CAN_RDH1R_DATA6_Pos    (16U)
#define CAN_RDH1R_DATA6_Msk    (0xFFU << CAN_RDH1R_DATA6_Pos)
#define CAN_RDH1R_DATA6        CAN_RDH1R_DATA6_Msk
#define CAN_RDH1R_DATA7_Pos    (24U)
#define CAN_RDH1R_DATA7_Msk    (0xFFU << CAN_RDH1R_DATA7_Pos)
#define CAN_RDH1R_DATA7        CAN_RDH1R_DATA7_Msk



#define CAN_FMR_FINIT_Pos      (0U)
#define CAN_FMR_FINIT_Msk      (0x1U << CAN_FMR_FINIT_Pos)
#define CAN_FMR_FINIT          CAN_FMR_FINIT_Msk


#define CAN_FM1R_FBM_Pos       (0U)
#define CAN_FM1R_FBM_Msk       (0x3FFFU << CAN_FM1R_FBM_Pos)
#define CAN_FM1R_FBM           CAN_FM1R_FBM_Msk
#define CAN_FM1R_FBM0_Pos      (0U)
#define CAN_FM1R_FBM0_Msk      (0x1U << CAN_FM1R_FBM0_Pos)
#define CAN_FM1R_FBM0          CAN_FM1R_FBM0_Msk
#define CAN_FM1R_FBM1_Pos      (1U)
#define CAN_FM1R_FBM1_Msk      (0x1U << CAN_FM1R_FBM1_Pos)
#define CAN_FM1R_FBM1          CAN_FM1R_FBM1_Msk
#define CAN_FM1R_FBM2_Pos      (2U)
#define CAN_FM1R_FBM2_Msk      (0x1U << CAN_FM1R_FBM2_Pos)
#define CAN_FM1R_FBM2          CAN_FM1R_FBM2_Msk
#define CAN_FM1R_FBM3_Pos      (3U)
#define CAN_FM1R_FBM3_Msk      (0x1U << CAN_FM1R_FBM3_Pos)
#define CAN_FM1R_FBM3          CAN_FM1R_FBM3_Msk
#define CAN_FM1R_FBM4_Pos      (4U)
#define CAN_FM1R_FBM4_Msk      (0x1U << CAN_FM1R_FBM4_Pos)
#define CAN_FM1R_FBM4          CAN_FM1R_FBM4_Msk
#define CAN_FM1R_FBM5_Pos      (5U)
#define CAN_FM1R_FBM5_Msk      (0x1U << CAN_FM1R_FBM5_Pos)
#define CAN_FM1R_FBM5          CAN_FM1R_FBM5_Msk
#define CAN_FM1R_FBM6_Pos      (6U)
#define CAN_FM1R_FBM6_Msk      (0x1U << CAN_FM1R_FBM6_Pos)
#define CAN_FM1R_FBM6          CAN_FM1R_FBM6_Msk
#define CAN_FM1R_FBM7_Pos      (7U)
#define CAN_FM1R_FBM7_Msk      (0x1U << CAN_FM1R_FBM7_Pos)
#define CAN_FM1R_FBM7          CAN_FM1R_FBM7_Msk
#define CAN_FM1R_FBM8_Pos      (8U)
#define CAN_FM1R_FBM8_Msk      (0x1U << CAN_FM1R_FBM8_Pos)
#define CAN_FM1R_FBM8          CAN_FM1R_FBM8_Msk
#define CAN_FM1R_FBM9_Pos      (9U)
#define CAN_FM1R_FBM9_Msk      (0x1U << CAN_FM1R_FBM9_Pos)
#define CAN_FM1R_FBM9          CAN_FM1R_FBM9_Msk
#define CAN_FM1R_FBM10_Pos     (10U)
#define CAN_FM1R_FBM10_Msk     (0x1U << CAN_FM1R_FBM10_Pos)
#define CAN_FM1R_FBM10         CAN_FM1R_FBM10_Msk
#define CAN_FM1R_FBM11_Pos     (11U)
#define CAN_FM1R_FBM11_Msk     (0x1U << CAN_FM1R_FBM11_Pos)
#define CAN_FM1R_FBM11         CAN_FM1R_FBM11_Msk
#define CAN_FM1R_FBM12_Pos     (12U)
#define CAN_FM1R_FBM12_Msk     (0x1U << CAN_FM1R_FBM12_Pos)
#define CAN_FM1R_FBM12         CAN_FM1R_FBM12_Msk
#define CAN_FM1R_FBM13_Pos     (13U)
#define CAN_FM1R_FBM13_Msk     (0x1U << CAN_FM1R_FBM13_Pos)
#define CAN_FM1R_FBM13         CAN_FM1R_FBM13_Msk


#define CAN_FS1R_FSC_Pos       (0U)
#define CAN_FS1R_FSC_Msk       (0x3FFFU << CAN_FS1R_FSC_Pos)
#define CAN_FS1R_FSC           CAN_FS1R_FSC_Msk
#define CAN_FS1R_FSC0_Pos      (0U)
#define CAN_FS1R_FSC0_Msk      (0x1U << CAN_FS1R_FSC0_Pos)
#define CAN_FS1R_FSC0          CAN_FS1R_FSC0_Msk
#define CAN_FS1R_FSC1_Pos      (1U)
#define CAN_FS1R_FSC1_Msk      (0x1U << CAN_FS1R_FSC1_Pos)
#define CAN_FS1R_FSC1          CAN_FS1R_FSC1_Msk
#define CAN_FS1R_FSC2_Pos      (2U)
#define CAN_FS1R_FSC2_Msk      (0x1U << CAN_FS1R_FSC2_Pos)
#define CAN_FS1R_FSC2          CAN_FS1R_FSC2_Msk
#define CAN_FS1R_FSC3_Pos      (3U)
#define CAN_FS1R_FSC3_Msk      (0x1U << CAN_FS1R_FSC3_Pos)
#define CAN_FS1R_FSC3          CAN_FS1R_FSC3_Msk
#define CAN_FS1R_FSC4_Pos      (4U)
#define CAN_FS1R_FSC4_Msk      (0x1U << CAN_FS1R_FSC4_Pos)
#define CAN_FS1R_FSC4          CAN_FS1R_FSC4_Msk
#define CAN_FS1R_FSC5_Pos      (5U)
#define CAN_FS1R_FSC5_Msk      (0x1U << CAN_FS1R_FSC5_Pos)
#define CAN_FS1R_FSC5          CAN_FS1R_FSC5_Msk
#define CAN_FS1R_FSC6_Pos      (6U)
#define CAN_FS1R_FSC6_Msk      (0x1U << CAN_FS1R_FSC6_Pos)
#define CAN_FS1R_FSC6          CAN_FS1R_FSC6_Msk
#define CAN_FS1R_FSC7_Pos      (7U)
#define CAN_FS1R_FSC7_Msk      (0x1U << CAN_FS1R_FSC7_Pos)
#define CAN_FS1R_FSC7          CAN_FS1R_FSC7_Msk
#define CAN_FS1R_FSC8_Pos      (8U)
#define CAN_FS1R_FSC8_Msk      (0x1U << CAN_FS1R_FSC8_Pos)
#define CAN_FS1R_FSC8          CAN_FS1R_FSC8_Msk
#define CAN_FS1R_FSC9_Pos      (9U)
#define CAN_FS1R_FSC9_Msk      (0x1U << CAN_FS1R_FSC9_Pos)
#define CAN_FS1R_FSC9          CAN_FS1R_FSC9_Msk
#define CAN_FS1R_FSC10_Pos     (10U)
#define CAN_FS1R_FSC10_Msk     (0x1U << CAN_FS1R_FSC10_Pos)
#define CAN_FS1R_FSC10         CAN_FS1R_FSC10_Msk
#define CAN_FS1R_FSC11_Pos     (11U)
#define CAN_FS1R_FSC11_Msk     (0x1U << CAN_FS1R_FSC11_Pos)
#define CAN_FS1R_FSC11         CAN_FS1R_FSC11_Msk
#define CAN_FS1R_FSC12_Pos     (12U)
#define CAN_FS1R_FSC12_Msk     (0x1U << CAN_FS1R_FSC12_Pos)
#define CAN_FS1R_FSC12         CAN_FS1R_FSC12_Msk
#define CAN_FS1R_FSC13_Pos     (13U)
#define CAN_FS1R_FSC13_Msk     (0x1U << CAN_FS1R_FSC13_Pos)
#define CAN_FS1R_FSC13         CAN_FS1R_FSC13_Msk


#define CAN_FFA1R_FFA_Pos      (0U)
#define CAN_FFA1R_FFA_Msk      (0x3FFFU << CAN_FFA1R_FFA_Pos)
#define CAN_FFA1R_FFA          CAN_FFA1R_FFA_Msk
#define CAN_FFA1R_FFA0_Pos     (0U)
#define CAN_FFA1R_FFA0_Msk     (0x1U << CAN_FFA1R_FFA0_Pos)
#define CAN_FFA1R_FFA0         CAN_FFA1R_FFA0_Msk
#define CAN_FFA1R_FFA1_Pos     (1U)
#define CAN_FFA1R_FFA1_Msk     (0x1U << CAN_FFA1R_FFA1_Pos)
#define CAN_FFA1R_FFA1         CAN_FFA1R_FFA1_Msk
#define CAN_FFA1R_FFA2_Pos     (2U)
#define CAN_FFA1R_FFA2_Msk     (0x1U << CAN_FFA1R_FFA2_Pos)
#define CAN_FFA1R_FFA2         CAN_FFA1R_FFA2_Msk
#define CAN_FFA1R_FFA3_Pos     (3U)
#define CAN_FFA1R_FFA3_Msk     (0x1U << CAN_FFA1R_FFA3_Pos)
#define CAN_FFA1R_FFA3         CAN_FFA1R_FFA3_Msk
#define CAN_FFA1R_FFA4_Pos     (4U)
#define CAN_FFA1R_FFA4_Msk     (0x1U << CAN_FFA1R_FFA4_Pos)
#define CAN_FFA1R_FFA4         CAN_FFA1R_FFA4_Msk
#define CAN_FFA1R_FFA5_Pos     (5U)
#define CAN_FFA1R_FFA5_Msk     (0x1U << CAN_FFA1R_FFA5_Pos)
#define CAN_FFA1R_FFA5         CAN_FFA1R_FFA5_Msk
#define CAN_FFA1R_FFA6_Pos     (6U)
#define CAN_FFA1R_FFA6_Msk     (0x1U << CAN_FFA1R_FFA6_Pos)
#define CAN_FFA1R_FFA6         CAN_FFA1R_FFA6_Msk
#define CAN_FFA1R_FFA7_Pos     (7U)
#define CAN_FFA1R_FFA7_Msk     (0x1U << CAN_FFA1R_FFA7_Pos)
#define CAN_FFA1R_FFA7         CAN_FFA1R_FFA7_Msk
#define CAN_FFA1R_FFA8_Pos     (8U)
#define CAN_FFA1R_FFA8_Msk     (0x1U << CAN_FFA1R_FFA8_Pos)
#define CAN_FFA1R_FFA8         CAN_FFA1R_FFA8_Msk
#define CAN_FFA1R_FFA9_Pos     (9U)
#define CAN_FFA1R_FFA9_Msk     (0x1U << CAN_FFA1R_FFA9_Pos)
#define CAN_FFA1R_FFA9         CAN_FFA1R_FFA9_Msk
#define CAN_FFA1R_FFA10_Pos    (10U)
#define CAN_FFA1R_FFA10_Msk    (0x1U << CAN_FFA1R_FFA10_Pos)
#define CAN_FFA1R_FFA10        CAN_FFA1R_FFA10_Msk
#define CAN_FFA1R_FFA11_Pos    (11U)
#define CAN_FFA1R_FFA11_Msk    (0x1U << CAN_FFA1R_FFA11_Pos)
#define CAN_FFA1R_FFA11        CAN_FFA1R_FFA11_Msk
#define CAN_FFA1R_FFA12_Pos    (12U)
#define CAN_FFA1R_FFA12_Msk    (0x1U << CAN_FFA1R_FFA12_Pos)
#define CAN_FFA1R_FFA12        CAN_FFA1R_FFA12_Msk
#define CAN_FFA1R_FFA13_Pos    (13U)
#define CAN_FFA1R_FFA13_Msk    (0x1U << CAN_FFA1R_FFA13_Pos)
#define CAN_FFA1R_FFA13        CAN_FFA1R_FFA13_Msk


#define CAN_FA1R_FACT_Pos      (0U)
#define CAN_FA1R_FACT_Msk      (0x3FFFU << CAN_FA1R_FACT_Pos)
#define CAN_FA1R_FACT          CAN_FA1R_FACT_Msk
#define CAN_FA1R_FACT0_Pos     (0U)
#define CAN_FA1R_FACT0_Msk     (0x1U << CAN_FA1R_FACT0_Pos)
#define CAN_FA1R_FACT0         CAN_FA1R_FACT0_Msk
#define CAN_FA1R_FACT1_Pos     (1U)
#define CAN_FA1R_FACT1_Msk     (0x1U << CAN_FA1R_FACT1_Pos)
#define CAN_FA1R_FACT1         CAN_FA1R_FACT1_Msk
#define CAN_FA1R_FACT2_Pos     (2U)
#define CAN_FA1R_FACT2_Msk     (0x1U << CAN_FA1R_FACT2_Pos)
#define CAN_FA1R_FACT2         CAN_FA1R_FACT2_Msk
#define CAN_FA1R_FACT3_Pos     (3U)
#define CAN_FA1R_FACT3_Msk     (0x1U << CAN_FA1R_FACT3_Pos)
#define CAN_FA1R_FACT3         CAN_FA1R_FACT3_Msk
#define CAN_FA1R_FACT4_Pos     (4U)
#define CAN_FA1R_FACT4_Msk     (0x1U << CAN_FA1R_FACT4_Pos)
#define CAN_FA1R_FACT4         CAN_FA1R_FACT4_Msk
#define CAN_FA1R_FACT5_Pos     (5U)
#define CAN_FA1R_FACT5_Msk     (0x1U << CAN_FA1R_FACT5_Pos)
#define CAN_FA1R_FACT5         CAN_FA1R_FACT5_Msk
#define CAN_FA1R_FACT6_Pos     (6U)
#define CAN_FA1R_FACT6_Msk     (0x1U << CAN_FA1R_FACT6_Pos)
#define CAN_FA1R_FACT6         CAN_FA1R_FACT6_Msk
#define CAN_FA1R_FACT7_Pos     (7U)
#define CAN_FA1R_FACT7_Msk     (0x1U << CAN_FA1R_FACT7_Pos)
#define CAN_FA1R_FACT7         CAN_FA1R_FACT7_Msk
#define CAN_FA1R_FACT8_Pos     (8U)
#define CAN_FA1R_FACT8_Msk     (0x1U << CAN_FA1R_FACT8_Pos)
#define CAN_FA1R_FACT8         CAN_FA1R_FACT8_Msk
#define CAN_FA1R_FACT9_Pos     (9U)
#define CAN_FA1R_FACT9_Msk     (0x1U << CAN_FA1R_FACT9_Pos)
#define CAN_FA1R_FACT9         CAN_FA1R_FACT9_Msk
#define CAN_FA1R_FACT10_Pos    (10U)
#define CAN_FA1R_FACT10_Msk    (0x1U << CAN_FA1R_FACT10_Pos)
#define CAN_FA1R_FACT10        CAN_FA1R_FACT10_Msk
#define CAN_FA1R_FACT11_Pos    (11U)
#define CAN_FA1R_FACT11_Msk    (0x1U << CAN_FA1R_FACT11_Pos)
#define CAN_FA1R_FACT11        CAN_FA1R_FACT11_Msk
#define CAN_FA1R_FACT12_Pos    (12U)
#define CAN_FA1R_FACT12_Msk    (0x1U << CAN_FA1R_FACT12_Pos)
#define CAN_FA1R_FACT12        CAN_FA1R_FACT12_Msk
#define CAN_FA1R_FACT13_Pos    (13U)
#define CAN_FA1R_FACT13_Msk    (0x1U << CAN_FA1R_FACT13_Pos)
#define CAN_FA1R_FACT13        CAN_FA1R_FACT13_Msk


#define CAN_F0R1_FB0_Pos       (0U)
#define CAN_F0R1_FB0_Msk       (0x1U << CAN_F0R1_FB0_Pos)
#define CAN_F0R1_FB0           CAN_F0R1_FB0_Msk
#define CAN_F0R1_FB1_Pos       (1U)
#define CAN_F0R1_FB1_Msk       (0x1U << CAN_F0R1_FB1_Pos)
#define CAN_F0R1_FB1           CAN_F0R1_FB1_Msk
#define CAN_F0R1_FB2_Pos       (2U)
#define CAN_F0R1_FB2_Msk       (0x1U << CAN_F0R1_FB2_Pos)
#define CAN_F0R1_FB2           CAN_F0R1_FB2_Msk
#define CAN_F0R1_FB3_Pos       (3U)
#define CAN_F0R1_FB3_Msk       (0x1U << CAN_F0R1_FB3_Pos)
#define CAN_F0R1_FB3           CAN_F0R1_FB3_Msk
#define CAN_F0R1_FB4_Pos       (4U)
#define CAN_F0R1_FB4_Msk       (0x1U << CAN_F0R1_FB4_Pos)
#define CAN_F0R1_FB4           CAN_F0R1_FB4_Msk
#define CAN_F0R1_FB5_Pos       (5U)
#define CAN_F0R1_FB5_Msk       (0x1U << CAN_F0R1_FB5_Pos)
#define CAN_F0R1_FB5           CAN_F0R1_FB5_Msk
#define CAN_F0R1_FB6_Pos       (6U)
#define CAN_F0R1_FB6_Msk       (0x1U << CAN_F0R1_FB6_Pos)
#define CAN_F0R1_FB6           CAN_F0R1_FB6_Msk
#define CAN_F0R1_FB7_Pos       (7U)
#define CAN_F0R1_FB7_Msk       (0x1U << CAN_F0R1_FB7_Pos)
#define CAN_F0R1_FB7           CAN_F0R1_FB7_Msk
#define CAN_F0R1_FB8_Pos       (8U)
#define CAN_F0R1_FB8_Msk       (0x1U << CAN_F0R1_FB8_Pos)
#define CAN_F0R1_FB8           CAN_F0R1_FB8_Msk
#define CAN_F0R1_FB9_Pos       (9U)
#define CAN_F0R1_FB9_Msk       (0x1U << CAN_F0R1_FB9_Pos)
#define CAN_F0R1_FB9           CAN_F0R1_FB9_Msk
#define CAN_F0R1_FB10_Pos      (10U)
#define CAN_F0R1_FB10_Msk      (0x1U << CAN_F0R1_FB10_Pos)
#define CAN_F0R1_FB10          CAN_F0R1_FB10_Msk
#define CAN_F0R1_FB11_Pos      (11U)
#define CAN_F0R1_FB11_Msk      (0x1U << CAN_F0R1_FB11_Pos)
#define CAN_F0R1_FB11          CAN_F0R1_FB11_Msk
#define CAN_F0R1_FB12_Pos      (12U)
#define CAN_F0R1_FB12_Msk      (0x1U << CAN_F0R1_FB12_Pos)
#define CAN_F0R1_FB12          CAN_F0R1_FB12_Msk
#define CAN_F0R1_FB13_Pos      (13U)
#define CAN_F0R1_FB13_Msk      (0x1U << CAN_F0R1_FB13_Pos)
#define CAN_F0R1_FB13          CAN_F0R1_FB13_Msk
#define CAN_F0R1_FB14_Pos      (14U)
#define CAN_F0R1_FB14_Msk      (0x1U << CAN_F0R1_FB14_Pos)
#define CAN_F0R1_FB14          CAN_F0R1_FB14_Msk
#define CAN_F0R1_FB15_Pos      (15U)
#define CAN_F0R1_FB15_Msk      (0x1U << CAN_F0R1_FB15_Pos)
#define CAN_F0R1_FB15          CAN_F0R1_FB15_Msk
#define CAN_F0R1_FB16_Pos      (16U)
#define CAN_F0R1_FB16_Msk      (0x1U << CAN_F0R1_FB16_Pos)
#define CAN_F0R1_FB16          CAN_F0R1_FB16_Msk
#define CAN_F0R1_FB17_Pos      (17U)
#define CAN_F0R1_FB17_Msk      (0x1U << CAN_F0R1_FB17_Pos)
#define CAN_F0R1_FB17          CAN_F0R1_FB17_Msk
#define CAN_F0R1_FB18_Pos      (18U)
#define CAN_F0R1_FB18_Msk      (0x1U << CAN_F0R1_FB18_Pos)
#define CAN_F0R1_FB18          CAN_F0R1_FB18_Msk
#define CAN_F0R1_FB19_Pos      (19U)
#define CAN_F0R1_FB19_Msk      (0x1U << CAN_F0R1_FB19_Pos)
#define CAN_F0R1_FB19          CAN_F0R1_FB19_Msk
#define CAN_F0R1_FB20_Pos      (20U)
#define CAN_F0R1_FB20_Msk      (0x1U << CAN_F0R1_FB20_Pos)
#define CAN_F0R1_FB20          CAN_F0R1_FB20_Msk
#define CAN_F0R1_FB21_Pos      (21U)
#define CAN_F0R1_FB21_Msk      (0x1U << CAN_F0R1_FB21_Pos)
#define CAN_F0R1_FB21          CAN_F0R1_FB21_Msk
#define CAN_F0R1_FB22_Pos      (22U)
#define CAN_F0R1_FB22_Msk      (0x1U << CAN_F0R1_FB22_Pos)
#define CAN_F0R1_FB22          CAN_F0R1_FB22_Msk
#define CAN_F0R1_FB23_Pos      (23U)
#define CAN_F0R1_FB23_Msk      (0x1U << CAN_F0R1_FB23_Pos)
#define CAN_F0R1_FB23          CAN_F0R1_FB23_Msk
#define CAN_F0R1_FB24_Pos      (24U)
#define CAN_F0R1_FB24_Msk      (0x1U << CAN_F0R1_FB24_Pos)
#define CAN_F0R1_FB24          CAN_F0R1_FB24_Msk
#define CAN_F0R1_FB25_Pos      (25U)
#define CAN_F0R1_FB25_Msk      (0x1U << CAN_F0R1_FB25_Pos)
#define CAN_F0R1_FB25          CAN_F0R1_FB25_Msk
#define CAN_F0R1_FB26_Pos      (26U)
#define CAN_F0R1_FB26_Msk      (0x1U << CAN_F0R1_FB26_Pos)
#define CAN_F0R1_FB26          CAN_F0R1_FB26_Msk
#define CAN_F0R1_FB27_Pos      (27U)
#define CAN_F0R1_FB27_Msk      (0x1U << CAN_F0R1_FB27_Pos)
#define CAN_F0R1_FB27          CAN_F0R1_FB27_Msk
#define CAN_F0R1_FB28_Pos      (28U)
#define CAN_F0R1_FB28_Msk      (0x1U << CAN_F0R1_FB28_Pos)
#define CAN_F0R1_FB28          CAN_F0R1_FB28_Msk
#define CAN_F0R1_FB29_Pos      (29U)
#define CAN_F0R1_FB29_Msk      (0x1U << CAN_F0R1_FB29_Pos)
#define CAN_F0R1_FB29          CAN_F0R1_FB29_Msk
#define CAN_F0R1_FB30_Pos      (30U)
#define CAN_F0R1_FB30_Msk      (0x1U << CAN_F0R1_FB30_Pos)
#define CAN_F0R1_FB30          CAN_F0R1_FB30_Msk
#define CAN_F0R1_FB31_Pos      (31U)
#define CAN_F0R1_FB31_Msk      (0x1U << CAN_F0R1_FB31_Pos)
#define CAN_F0R1_FB31          CAN_F0R1_FB31_Msk


#define CAN_F1R1_FB0_Pos       (0U)
#define CAN_F1R1_FB0_Msk       (0x1U << CAN_F1R1_FB0_Pos)
#define CAN_F1R1_FB0           CAN_F1R1_FB0_Msk
#define CAN_F1R1_FB1_Pos       (1U)
#define CAN_F1R1_FB1_Msk       (0x1U << CAN_F1R1_FB1_Pos)
#define CAN_F1R1_FB1           CAN_F1R1_FB1_Msk
#define CAN_F1R1_FB2_Pos       (2U)
#define CAN_F1R1_FB2_Msk       (0x1U << CAN_F1R1_FB2_Pos)
#define CAN_F1R1_FB2           CAN_F1R1_FB2_Msk
#define CAN_F1R1_FB3_Pos       (3U)
#define CAN_F1R1_FB3_Msk       (0x1U << CAN_F1R1_FB3_Pos)
#define CAN_F1R1_FB3           CAN_F1R1_FB3_Msk
#define CAN_F1R1_FB4_Pos       (4U)
#define CAN_F1R1_FB4_Msk       (0x1U << CAN_F1R1_FB4_Pos)
#define CAN_F1R1_FB4           CAN_F1R1_FB4_Msk
#define CAN_F1R1_FB5_Pos       (5U)
#define CAN_F1R1_FB5_Msk       (0x1U << CAN_F1R1_FB5_Pos)
#define CAN_F1R1_FB5           CAN_F1R1_FB5_Msk
#define CAN_F1R1_FB6_Pos       (6U)
#define CAN_F1R1_FB6_Msk       (0x1U << CAN_F1R1_FB6_Pos)
#define CAN_F1R1_FB6           CAN_F1R1_FB6_Msk
#define CAN_F1R1_FB7_Pos       (7U)
#define CAN_F1R1_FB7_Msk       (0x1U << CAN_F1R1_FB7_Pos)
#define CAN_F1R1_FB7           CAN_F1R1_FB7_Msk
#define CAN_F1R1_FB8_Pos       (8U)
#define CAN_F1R1_FB8_Msk       (0x1U << CAN_F1R1_FB8_Pos)
#define CAN_F1R1_FB8           CAN_F1R1_FB8_Msk
#define CAN_F1R1_FB9_Pos       (9U)
#define CAN_F1R1_FB9_Msk       (0x1U << CAN_F1R1_FB9_Pos)
#define CAN_F1R1_FB9           CAN_F1R1_FB9_Msk
#define CAN_F1R1_FB10_Pos      (10U)
#define CAN_F1R1_FB10_Msk      (0x1U << CAN_F1R1_FB10_Pos)
#define CAN_F1R1_FB10          CAN_F1R1_FB10_Msk
#define CAN_F1R1_FB11_Pos      (11U)
#define CAN_F1R1_FB11_Msk      (0x1U << CAN_F1R1_FB11_Pos)
#define CAN_F1R1_FB11          CAN_F1R1_FB11_Msk
#define CAN_F1R1_FB12_Pos      (12U)
#define CAN_F1R1_FB12_Msk      (0x1U << CAN_F1R1_FB12_Pos)
#define CAN_F1R1_FB12          CAN_F1R1_FB12_Msk
#define CAN_F1R1_FB13_Pos      (13U)
#define CAN_F1R1_FB13_Msk      (0x1U << CAN_F1R1_FB13_Pos)
#define CAN_F1R1_FB13          CAN_F1R1_FB13_Msk
#define CAN_F1R1_FB14_Pos      (14U)
#define CAN_F1R1_FB14_Msk      (0x1U << CAN_F1R1_FB14_Pos)
#define CAN_F1R1_FB14          CAN_F1R1_FB14_Msk
#define CAN_F1R1_FB15_Pos      (15U)
#define CAN_F1R1_FB15_Msk      (0x1U << CAN_F1R1_FB15_Pos)
#define CAN_F1R1_FB15          CAN_F1R1_FB15_Msk
#define CAN_F1R1_FB16_Pos      (16U)
#define CAN_F1R1_FB16_Msk      (0x1U << CAN_F1R1_FB16_Pos)
#define CAN_F1R1_FB16          CAN_F1R1_FB16_Msk
#define CAN_F1R1_FB17_Pos      (17U)
#define CAN_F1R1_FB17_Msk      (0x1U << CAN_F1R1_FB17_Pos)
#define CAN_F1R1_FB17          CAN_F1R1_FB17_Msk
#define CAN_F1R1_FB18_Pos      (18U)
#define CAN_F1R1_FB18_Msk      (0x1U << CAN_F1R1_FB18_Pos)
#define CAN_F1R1_FB18          CAN_F1R1_FB18_Msk
#define CAN_F1R1_FB19_Pos      (19U)
#define CAN_F1R1_FB19_Msk      (0x1U << CAN_F1R1_FB19_Pos)
#define CAN_F1R1_FB19          CAN_F1R1_FB19_Msk
#define CAN_F1R1_FB20_Pos      (20U)
#define CAN_F1R1_FB20_Msk      (0x1U << CAN_F1R1_FB20_Pos)
#define CAN_F1R1_FB20          CAN_F1R1_FB20_Msk
#define CAN_F1R1_FB21_Pos      (21U)
#define CAN_F1R1_FB21_Msk      (0x1U << CAN_F1R1_FB21_Pos)
#define CAN_F1R1_FB21          CAN_F1R1_FB21_Msk
#define CAN_F1R1_FB22_Pos      (22U)
#define CAN_F1R1_FB22_Msk      (0x1U << CAN_F1R1_FB22_Pos)
#define CAN_F1R1_FB22          CAN_F1R1_FB22_Msk
#define CAN_F1R1_FB23_Pos      (23U)
#define CAN_F1R1_FB23_Msk      (0x1U << CAN_F1R1_FB23_Pos)
#define CAN_F1R1_FB23          CAN_F1R1_FB23_Msk
#define CAN_F1R1_FB24_Pos      (24U)
#define CAN_F1R1_FB24_Msk      (0x1U << CAN_F1R1_FB24_Pos)
#define CAN_F1R1_FB24          CAN_F1R1_FB24_Msk
#define CAN_F1R1_FB25_Pos      (25U)
#define CAN_F1R1_FB25_Msk      (0x1U << CAN_F1R1_FB25_Pos)
#define CAN_F1R1_FB25          CAN_F1R1_FB25_Msk
#define CAN_F1R1_FB26_Pos      (26U)
#define CAN_F1R1_FB26_Msk      (0x1U << CAN_F1R1_FB26_Pos)
#define CAN_F1R1_FB26          CAN_F1R1_FB26_Msk
#define CAN_F1R1_FB27_Pos      (27U)
#define CAN_F1R1_FB27_Msk      (0x1U << CAN_F1R1_FB27_Pos)
#define CAN_F1R1_FB27          CAN_F1R1_FB27_Msk
#define CAN_F1R1_FB28_Pos      (28U)
#define CAN_F1R1_FB28_Msk      (0x1U << CAN_F1R1_FB28_Pos)
#define CAN_F1R1_FB28          CAN_F1R1_FB28_Msk
#define CAN_F1R1_FB29_Pos      (29U)
#define CAN_F1R1_FB29_Msk      (0x1U << CAN_F1R1_FB29_Pos)
#define CAN_F1R1_FB29          CAN_F1R1_FB29_Msk
#define CAN_F1R1_FB30_Pos      (30U)
#define CAN_F1R1_FB30_Msk      (0x1U << CAN_F1R1_FB30_Pos)
#define CAN_F1R1_FB30          CAN_F1R1_FB30_Msk
#define CAN_F1R1_FB31_Pos      (31U)
#define CAN_F1R1_FB31_Msk      (0x1U << CAN_F1R1_FB31_Pos)
#define CAN_F1R1_FB31          CAN_F1R1_FB31_Msk


#define CAN_F2R1_FB0_Pos       (0U)
#define CAN_F2R1_FB0_Msk       (0x1U << CAN_F2R1_FB0_Pos)
#define CAN_F2R1_FB0           CAN_F2R1_FB0_Msk
#define CAN_F2R1_FB1_Pos       (1U)
#define CAN_F2R1_FB1_Msk       (0x1U << CAN_F2R1_FB1_Pos)
#define CAN_F2R1_FB1           CAN_F2R1_FB1_Msk
#define CAN_F2R1_FB2_Pos       (2U)
#define CAN_F2R1_FB2_Msk       (0x1U << CAN_F2R1_FB2_Pos)
#define CAN_F2R1_FB2           CAN_F2R1_FB2_Msk
#define CAN_F2R1_FB3_Pos       (3U)
#define CAN_F2R1_FB3_Msk       (0x1U << CAN_F2R1_FB3_Pos)
#define CAN_F2R1_FB3           CAN_F2R1_FB3_Msk
#define CAN_F2R1_FB4_Pos       (4U)
#define CAN_F2R1_FB4_Msk       (0x1U << CAN_F2R1_FB4_Pos)
#define CAN_F2R1_FB4           CAN_F2R1_FB4_Msk
#define CAN_F2R1_FB5_Pos       (5U)
#define CAN_F2R1_FB5_Msk       (0x1U << CAN_F2R1_FB5_Pos)
#define CAN_F2R1_FB5           CAN_F2R1_FB5_Msk
#define CAN_F2R1_FB6_Pos       (6U)
#define CAN_F2R1_FB6_Msk       (0x1U << CAN_F2R1_FB6_Pos)
#define CAN_F2R1_FB6           CAN_F2R1_FB6_Msk
#define CAN_F2R1_FB7_Pos       (7U)
#define CAN_F2R1_FB7_Msk       (0x1U << CAN_F2R1_FB7_Pos)
#define CAN_F2R1_FB7           CAN_F2R1_FB7_Msk
#define CAN_F2R1_FB8_Pos       (8U)
#define CAN_F2R1_FB8_Msk       (0x1U << CAN_F2R1_FB8_Pos)
#define CAN_F2R1_FB8           CAN_F2R1_FB8_Msk
#define CAN_F2R1_FB9_Pos       (9U)
#define CAN_F2R1_FB9_Msk       (0x1U << CAN_F2R1_FB9_Pos)
#define CAN_F2R1_FB9           CAN_F2R1_FB9_Msk
#define CAN_F2R1_FB10_Pos      (10U)
#define CAN_F2R1_FB10_Msk      (0x1U << CAN_F2R1_FB10_Pos)
#define CAN_F2R1_FB10          CAN_F2R1_FB10_Msk
#define CAN_F2R1_FB11_Pos      (11U)
#define CAN_F2R1_FB11_Msk      (0x1U << CAN_F2R1_FB11_Pos)
#define CAN_F2R1_FB11          CAN_F2R1_FB11_Msk
#define CAN_F2R1_FB12_Pos      (12U)
#define CAN_F2R1_FB12_Msk      (0x1U << CAN_F2R1_FB12_Pos)
#define CAN_F2R1_FB12          CAN_F2R1_FB12_Msk
#define CAN_F2R1_FB13_Pos      (13U)
#define CAN_F2R1_FB13_Msk      (0x1U << CAN_F2R1_FB13_Pos)
#define CAN_F2R1_FB13          CAN_F2R1_FB13_Msk
#define CAN_F2R1_FB14_Pos      (14U)
#define CAN_F2R1_FB14_Msk      (0x1U << CAN_F2R1_FB14_Pos)
#define CAN_F2R1_FB14          CAN_F2R1_FB14_Msk
#define CAN_F2R1_FB15_Pos      (15U)
#define CAN_F2R1_FB15_Msk      (0x1U << CAN_F2R1_FB15_Pos)
#define CAN_F2R1_FB15          CAN_F2R1_FB15_Msk
#define CAN_F2R1_FB16_Pos      (16U)
#define CAN_F2R1_FB16_Msk      (0x1U << CAN_F2R1_FB16_Pos)
#define CAN_F2R1_FB16          CAN_F2R1_FB16_Msk
#define CAN_F2R1_FB17_Pos      (17U)
#define CAN_F2R1_FB17_Msk      (0x1U << CAN_F2R1_FB17_Pos)
#define CAN_F2R1_FB17          CAN_F2R1_FB17_Msk
#define CAN_F2R1_FB18_Pos      (18U)
#define CAN_F2R1_FB18_Msk      (0x1U << CAN_F2R1_FB18_Pos)
#define CAN_F2R1_FB18          CAN_F2R1_FB18_Msk
#define CAN_F2R1_FB19_Pos      (19U)
#define CAN_F2R1_FB19_Msk      (0x1U << CAN_F2R1_FB19_Pos)
#define CAN_F2R1_FB19          CAN_F2R1_FB19_Msk
#define CAN_F2R1_FB20_Pos      (20U)
#define CAN_F2R1_FB20_Msk      (0x1U << CAN_F2R1_FB20_Pos)
#define CAN_F2R1_FB20          CAN_F2R1_FB20_Msk
#define CAN_F2R1_FB21_Pos      (21U)
#define CAN_F2R1_FB21_Msk      (0x1U << CAN_F2R1_FB21_Pos)
#define CAN_F2R1_FB21          CAN_F2R1_FB21_Msk
#define CAN_F2R1_FB22_Pos      (22U)
#define CAN_F2R1_FB22_Msk      (0x1U << CAN_F2R1_FB22_Pos)
#define CAN_F2R1_FB22          CAN_F2R1_FB22_Msk
#define CAN_F2R1_FB23_Pos      (23U)
#define CAN_F2R1_FB23_Msk      (0x1U << CAN_F2R1_FB23_Pos)
#define CAN_F2R1_FB23          CAN_F2R1_FB23_Msk
#define CAN_F2R1_FB24_Pos      (24U)
#define CAN_F2R1_FB24_Msk      (0x1U << CAN_F2R1_FB24_Pos)
#define CAN_F2R1_FB24          CAN_F2R1_FB24_Msk
#define CAN_F2R1_FB25_Pos      (25U)
#define CAN_F2R1_FB25_Msk      (0x1U << CAN_F2R1_FB25_Pos)
#define CAN_F2R1_FB25          CAN_F2R1_FB25_Msk
#define CAN_F2R1_FB26_Pos      (26U)
#define CAN_F2R1_FB26_Msk      (0x1U << CAN_F2R1_FB26_Pos)
#define CAN_F2R1_FB26          CAN_F2R1_FB26_Msk
#define CAN_F2R1_FB27_Pos      (27U)
#define CAN_F2R1_FB27_Msk      (0x1U << CAN_F2R1_FB27_Pos)
#define CAN_F2R1_FB27          CAN_F2R1_FB27_Msk
#define CAN_F2R1_FB28_Pos      (28U)
#define CAN_F2R1_FB28_Msk      (0x1U << CAN_F2R1_FB28_Pos)
#define CAN_F2R1_FB28          CAN_F2R1_FB28_Msk
#define CAN_F2R1_FB29_Pos      (29U)
#define CAN_F2R1_FB29_Msk      (0x1U << CAN_F2R1_FB29_Pos)
#define CAN_F2R1_FB29          CAN_F2R1_FB29_Msk
#define CAN_F2R1_FB30_Pos      (30U)
#define CAN_F2R1_FB30_Msk      (0x1U << CAN_F2R1_FB30_Pos)
#define CAN_F2R1_FB30          CAN_F2R1_FB30_Msk
#define CAN_F2R1_FB31_Pos      (31U)
#define CAN_F2R1_FB31_Msk      (0x1U << CAN_F2R1_FB31_Pos)
#define CAN_F2R1_FB31          CAN_F2R1_FB31_Msk


#define CAN_F3R1_FB0_Pos       (0U)
#define CAN_F3R1_FB0_Msk       (0x1U << CAN_F3R1_FB0_Pos)
#define CAN_F3R1_FB0           CAN_F3R1_FB0_Msk
#define CAN_F3R1_FB1_Pos       (1U)
#define CAN_F3R1_FB1_Msk       (0x1U << CAN_F3R1_FB1_Pos)
#define CAN_F3R1_FB1           CAN_F3R1_FB1_Msk
#define CAN_F3R1_FB2_Pos       (2U)
#define CAN_F3R1_FB2_Msk       (0x1U << CAN_F3R1_FB2_Pos)
#define CAN_F3R1_FB2           CAN_F3R1_FB2_Msk
#define CAN_F3R1_FB3_Pos       (3U)
#define CAN_F3R1_FB3_Msk       (0x1U << CAN_F3R1_FB3_Pos)
#define CAN_F3R1_FB3           CAN_F3R1_FB3_Msk
#define CAN_F3R1_FB4_Pos       (4U)
#define CAN_F3R1_FB4_Msk       (0x1U << CAN_F3R1_FB4_Pos)
#define CAN_F3R1_FB4           CAN_F3R1_FB4_Msk
#define CAN_F3R1_FB5_Pos       (5U)
#define CAN_F3R1_FB5_Msk       (0x1U << CAN_F3R1_FB5_Pos)
#define CAN_F3R1_FB5           CAN_F3R1_FB5_Msk
#define CAN_F3R1_FB6_Pos       (6U)
#define CAN_F3R1_FB6_Msk       (0x1U << CAN_F3R1_FB6_Pos)
#define CAN_F3R1_FB6           CAN_F3R1_FB6_Msk
#define CAN_F3R1_FB7_Pos       (7U)
#define CAN_F3R1_FB7_Msk       (0x1U << CAN_F3R1_FB7_Pos)
#define CAN_F3R1_FB7           CAN_F3R1_FB7_Msk
#define CAN_F3R1_FB8_Pos       (8U)
#define CAN_F3R1_FB8_Msk       (0x1U << CAN_F3R1_FB8_Pos)
#define CAN_F3R1_FB8           CAN_F3R1_FB8_Msk
#define CAN_F3R1_FB9_Pos       (9U)
#define CAN_F3R1_FB9_Msk       (0x1U << CAN_F3R1_FB9_Pos)
#define CAN_F3R1_FB9           CAN_F3R1_FB9_Msk
#define CAN_F3R1_FB10_Pos      (10U)
#define CAN_F3R1_FB10_Msk      (0x1U << CAN_F3R1_FB10_Pos)
#define CAN_F3R1_FB10          CAN_F3R1_FB10_Msk
#define CAN_F3R1_FB11_Pos      (11U)
#define CAN_F3R1_FB11_Msk      (0x1U << CAN_F3R1_FB11_Pos)
#define CAN_F3R1_FB11          CAN_F3R1_FB11_Msk
#define CAN_F3R1_FB12_Pos      (12U)
#define CAN_F3R1_FB12_Msk      (0x1U << CAN_F3R1_FB12_Pos)
#define CAN_F3R1_FB12          CAN_F3R1_FB12_Msk
#define CAN_F3R1_FB13_Pos      (13U)
#define CAN_F3R1_FB13_Msk      (0x1U << CAN_F3R1_FB13_Pos)
#define CAN_F3R1_FB13          CAN_F3R1_FB13_Msk
#define CAN_F3R1_FB14_Pos      (14U)
#define CAN_F3R1_FB14_Msk      (0x1U << CAN_F3R1_FB14_Pos)
#define CAN_F3R1_FB14          CAN_F3R1_FB14_Msk
#define CAN_F3R1_FB15_Pos      (15U)
#define CAN_F3R1_FB15_Msk      (0x1U << CAN_F3R1_FB15_Pos)
#define CAN_F3R1_FB15          CAN_F3R1_FB15_Msk
#define CAN_F3R1_FB16_Pos      (16U)
#define CAN_F3R1_FB16_Msk      (0x1U << CAN_F3R1_FB16_Pos)
#define CAN_F3R1_FB16          CAN_F3R1_FB16_Msk
#define CAN_F3R1_FB17_Pos      (17U)
#define CAN_F3R1_FB17_Msk      (0x1U << CAN_F3R1_FB17_Pos)
#define CAN_F3R1_FB17          CAN_F3R1_FB17_Msk
#define CAN_F3R1_FB18_Pos      (18U)
#define CAN_F3R1_FB18_Msk      (0x1U << CAN_F3R1_FB18_Pos)
#define CAN_F3R1_FB18          CAN_F3R1_FB18_Msk
#define CAN_F3R1_FB19_Pos      (19U)
#define CAN_F3R1_FB19_Msk      (0x1U << CAN_F3R1_FB19_Pos)
#define CAN_F3R1_FB19          CAN_F3R1_FB19_Msk
#define CAN_F3R1_FB20_Pos      (20U)
#define CAN_F3R1_FB20_Msk      (0x1U << CAN_F3R1_FB20_Pos)
#define CAN_F3R1_FB20          CAN_F3R1_FB20_Msk
#define CAN_F3R1_FB21_Pos      (21U)
#define CAN_F3R1_FB21_Msk      (0x1U << CAN_F3R1_FB21_Pos)
#define CAN_F3R1_FB21          CAN_F3R1_FB21_Msk
#define CAN_F3R1_FB22_Pos      (22U)
#define CAN_F3R1_FB22_Msk      (0x1U << CAN_F3R1_FB22_Pos)
#define CAN_F3R1_FB22          CAN_F3R1_FB22_Msk
#define CAN_F3R1_FB23_Pos      (23U)
#define CAN_F3R1_FB23_Msk      (0x1U << CAN_F3R1_FB23_Pos)
#define CAN_F3R1_FB23          CAN_F3R1_FB23_Msk
#define CAN_F3R1_FB24_Pos      (24U)
#define CAN_F3R1_FB24_Msk      (0x1U << CAN_F3R1_FB24_Pos)
#define CAN_F3R1_FB24          CAN_F3R1_FB24_Msk
#define CAN_F3R1_FB25_Pos      (25U)
#define CAN_F3R1_FB25_Msk      (0x1U << CAN_F3R1_FB25_Pos)
#define CAN_F3R1_FB25          CAN_F3R1_FB25_Msk
#define CAN_F3R1_FB26_Pos      (26U)
#define CAN_F3R1_FB26_Msk      (0x1U << CAN_F3R1_FB26_Pos)
#define CAN_F3R1_FB26          CAN_F3R1_FB26_Msk
#define CAN_F3R1_FB27_Pos      (27U)
#define CAN_F3R1_FB27_Msk      (0x1U << CAN_F3R1_FB27_Pos)
#define CAN_F3R1_FB27          CAN_F3R1_FB27_Msk
#define CAN_F3R1_FB28_Pos      (28U)
#define CAN_F3R1_FB28_Msk      (0x1U << CAN_F3R1_FB28_Pos)
#define CAN_F3R1_FB28          CAN_F3R1_FB28_Msk
#define CAN_F3R1_FB29_Pos      (29U)
#define CAN_F3R1_FB29_Msk      (0x1U << CAN_F3R1_FB29_Pos)
#define CAN_F3R1_FB29          CAN_F3R1_FB29_Msk
#define CAN_F3R1_FB30_Pos      (30U)
#define CAN_F3R1_FB30_Msk      (0x1U << CAN_F3R1_FB30_Pos)
#define CAN_F3R1_FB30          CAN_F3R1_FB30_Msk
#define CAN_F3R1_FB31_Pos      (31U)
#define CAN_F3R1_FB31_Msk      (0x1U << CAN_F3R1_FB31_Pos)
#define CAN_F3R1_FB31          CAN_F3R1_FB31_Msk


#define CAN_F4R1_FB0_Pos       (0U)
#define CAN_F4R1_FB0_Msk       (0x1U << CAN_F4R1_FB0_Pos)
#define CAN_F4R1_FB0           CAN_F4R1_FB0_Msk
#define CAN_F4R1_FB1_Pos       (1U)
#define CAN_F4R1_FB1_Msk       (0x1U << CAN_F4R1_FB1_Pos)
#define CAN_F4R1_FB1           CAN_F4R1_FB1_Msk
#define CAN_F4R1_FB2_Pos       (2U)
#define CAN_F4R1_FB2_Msk       (0x1U << CAN_F4R1_FB2_Pos)
#define CAN_F4R1_FB2           CAN_F4R1_FB2_Msk
#define CAN_F4R1_FB3_Pos       (3U)
#define CAN_F4R1_FB3_Msk       (0x1U << CAN_F4R1_FB3_Pos)
#define CAN_F4R1_FB3           CAN_F4R1_FB3_Msk
#define CAN_F4R1_FB4_Pos       (4U)
#define CAN_F4R1_FB4_Msk       (0x1U << CAN_F4R1_FB4_Pos)
#define CAN_F4R1_FB4           CAN_F4R1_FB4_Msk
#define CAN_F4R1_FB5_Pos       (5U)
#define CAN_F4R1_FB5_Msk       (0x1U << CAN_F4R1_FB5_Pos)
#define CAN_F4R1_FB5           CAN_F4R1_FB5_Msk
#define CAN_F4R1_FB6_Pos       (6U)
#define CAN_F4R1_FB6_Msk       (0x1U << CAN_F4R1_FB6_Pos)
#define CAN_F4R1_FB6           CAN_F4R1_FB6_Msk
#define CAN_F4R1_FB7_Pos       (7U)
#define CAN_F4R1_FB7_Msk       (0x1U << CAN_F4R1_FB7_Pos)
#define CAN_F4R1_FB7           CAN_F4R1_FB7_Msk
#define CAN_F4R1_FB8_Pos       (8U)
#define CAN_F4R1_FB8_Msk       (0x1U << CAN_F4R1_FB8_Pos)
#define CAN_F4R1_FB8           CAN_F4R1_FB8_Msk
#define CAN_F4R1_FB9_Pos       (9U)
#define CAN_F4R1_FB9_Msk       (0x1U << CAN_F4R1_FB9_Pos)
#define CAN_F4R1_FB9           CAN_F4R1_FB9_Msk
#define CAN_F4R1_FB10_Pos      (10U)
#define CAN_F4R1_FB10_Msk      (0x1U << CAN_F4R1_FB10_Pos)
#define CAN_F4R1_FB10          CAN_F4R1_FB10_Msk
#define CAN_F4R1_FB11_Pos      (11U)
#define CAN_F4R1_FB11_Msk      (0x1U << CAN_F4R1_FB11_Pos)
#define CAN_F4R1_FB11          CAN_F4R1_FB11_Msk
#define CAN_F4R1_FB12_Pos      (12U)
#define CAN_F4R1_FB12_Msk      (0x1U << CAN_F4R1_FB12_Pos)
#define CAN_F4R1_FB12          CAN_F4R1_FB12_Msk
#define CAN_F4R1_FB13_Pos      (13U)
#define CAN_F4R1_FB13_Msk      (0x1U << CAN_F4R1_FB13_Pos)
#define CAN_F4R1_FB13          CAN_F4R1_FB13_Msk
#define CAN_F4R1_FB14_Pos      (14U)
#define CAN_F4R1_FB14_Msk      (0x1U << CAN_F4R1_FB14_Pos)
#define CAN_F4R1_FB14          CAN_F4R1_FB14_Msk
#define CAN_F4R1_FB15_Pos      (15U)
#define CAN_F4R1_FB15_Msk      (0x1U << CAN_F4R1_FB15_Pos)
#define CAN_F4R1_FB15          CAN_F4R1_FB15_Msk
#define CAN_F4R1_FB16_Pos      (16U)
#define CAN_F4R1_FB16_Msk      (0x1U << CAN_F4R1_FB16_Pos)
#define CAN_F4R1_FB16          CAN_F4R1_FB16_Msk
#define CAN_F4R1_FB17_Pos      (17U)
#define CAN_F4R1_FB17_Msk      (0x1U << CAN_F4R1_FB17_Pos)
#define CAN_F4R1_FB17          CAN_F4R1_FB17_Msk
#define CAN_F4R1_FB18_Pos      (18U)
#define CAN_F4R1_FB18_Msk      (0x1U << CAN_F4R1_FB18_Pos)
#define CAN_F4R1_FB18          CAN_F4R1_FB18_Msk
#define CAN_F4R1_FB19_Pos      (19U)
#define CAN_F4R1_FB19_Msk      (0x1U << CAN_F4R1_FB19_Pos)
#define CAN_F4R1_FB19          CAN_F4R1_FB19_Msk
#define CAN_F4R1_FB20_Pos      (20U)
#define CAN_F4R1_FB20_Msk      (0x1U << CAN_F4R1_FB20_Pos)
#define CAN_F4R1_FB20          CAN_F4R1_FB20_Msk
#define CAN_F4R1_FB21_Pos      (21U)
#define CAN_F4R1_FB21_Msk      (0x1U << CAN_F4R1_FB21_Pos)
#define CAN_F4R1_FB21          CAN_F4R1_FB21_Msk
#define CAN_F4R1_FB22_Pos      (22U)
#define CAN_F4R1_FB22_Msk      (0x1U << CAN_F4R1_FB22_Pos)
#define CAN_F4R1_FB22          CAN_F4R1_FB22_Msk
#define CAN_F4R1_FB23_Pos      (23U)
#define CAN_F4R1_FB23_Msk      (0x1U << CAN_F4R1_FB23_Pos)
#define CAN_F4R1_FB23          CAN_F4R1_FB23_Msk
#define CAN_F4R1_FB24_Pos      (24U)
#define CAN_F4R1_FB24_Msk      (0x1U << CAN_F4R1_FB24_Pos)
#define CAN_F4R1_FB24          CAN_F4R1_FB24_Msk
#define CAN_F4R1_FB25_Pos      (25U)
#define CAN_F4R1_FB25_Msk      (0x1U << CAN_F4R1_FB25_Pos)
#define CAN_F4R1_FB25          CAN_F4R1_FB25_Msk
#define CAN_F4R1_FB26_Pos      (26U)
#define CAN_F4R1_FB26_Msk      (0x1U << CAN_F4R1_FB26_Pos)
#define CAN_F4R1_FB26          CAN_F4R1_FB26_Msk
#define CAN_F4R1_FB27_Pos      (27U)
#define CAN_F4R1_FB27_Msk      (0x1U << CAN_F4R1_FB27_Pos)
#define CAN_F4R1_FB27          CAN_F4R1_FB27_Msk
#define CAN_F4R1_FB28_Pos      (28U)
#define CAN_F4R1_FB28_Msk      (0x1U << CAN_F4R1_FB28_Pos)
#define CAN_F4R1_FB28          CAN_F4R1_FB28_Msk
#define CAN_F4R1_FB29_Pos      (29U)
#define CAN_F4R1_FB29_Msk      (0x1U << CAN_F4R1_FB29_Pos)
#define CAN_F4R1_FB29          CAN_F4R1_FB29_Msk
#define CAN_F4R1_FB30_Pos      (30U)
#define CAN_F4R1_FB30_Msk      (0x1U << CAN_F4R1_FB30_Pos)
#define CAN_F4R1_FB30          CAN_F4R1_FB30_Msk
#define CAN_F4R1_FB31_Pos      (31U)
#define CAN_F4R1_FB31_Msk      (0x1U << CAN_F4R1_FB31_Pos)
#define CAN_F4R1_FB31          CAN_F4R1_FB31_Msk


#define CAN_F5R1_FB0_Pos       (0U)
#define CAN_F5R1_FB0_Msk       (0x1U << CAN_F5R1_FB0_Pos)
#define CAN_F5R1_FB0           CAN_F5R1_FB0_Msk
#define CAN_F5R1_FB1_Pos       (1U)
#define CAN_F5R1_FB1_Msk       (0x1U << CAN_F5R1_FB1_Pos)
#define CAN_F5R1_FB1           CAN_F5R1_FB1_Msk
#define CAN_F5R1_FB2_Pos       (2U)
#define CAN_F5R1_FB2_Msk       (0x1U << CAN_F5R1_FB2_Pos)
#define CAN_F5R1_FB2           CAN_F5R1_FB2_Msk
#define CAN_F5R1_FB3_Pos       (3U)
#define CAN_F5R1_FB3_Msk       (0x1U << CAN_F5R1_FB3_Pos)
#define CAN_F5R1_FB3           CAN_F5R1_FB3_Msk
#define CAN_F5R1_FB4_Pos       (4U)
#define CAN_F5R1_FB4_Msk       (0x1U << CAN_F5R1_FB4_Pos)
#define CAN_F5R1_FB4           CAN_F5R1_FB4_Msk
#define CAN_F5R1_FB5_Pos       (5U)
#define CAN_F5R1_FB5_Msk       (0x1U << CAN_F5R1_FB5_Pos)
#define CAN_F5R1_FB5           CAN_F5R1_FB5_Msk
#define CAN_F5R1_FB6_Pos       (6U)
#define CAN_F5R1_FB6_Msk       (0x1U << CAN_F5R1_FB6_Pos)
#define CAN_F5R1_FB6           CAN_F5R1_FB6_Msk
#define CAN_F5R1_FB7_Pos       (7U)
#define CAN_F5R1_FB7_Msk       (0x1U << CAN_F5R1_FB7_Pos)
#define CAN_F5R1_FB7           CAN_F5R1_FB7_Msk
#define CAN_F5R1_FB8_Pos       (8U)
#define CAN_F5R1_FB8_Msk       (0x1U << CAN_F5R1_FB8_Pos)
#define CAN_F5R1_FB8           CAN_F5R1_FB8_Msk
#define CAN_F5R1_FB9_Pos       (9U)
#define CAN_F5R1_FB9_Msk       (0x1U << CAN_F5R1_FB9_Pos)
#define CAN_F5R1_FB9           CAN_F5R1_FB9_Msk
#define CAN_F5R1_FB10_Pos      (10U)
#define CAN_F5R1_FB10_Msk      (0x1U << CAN_F5R1_FB10_Pos)
#define CAN_F5R1_FB10          CAN_F5R1_FB10_Msk
#define CAN_F5R1_FB11_Pos      (11U)
#define CAN_F5R1_FB11_Msk      (0x1U << CAN_F5R1_FB11_Pos)
#define CAN_F5R1_FB11          CAN_F5R1_FB11_Msk
#define CAN_F5R1_FB12_Pos      (12U)
#define CAN_F5R1_FB12_Msk      (0x1U << CAN_F5R1_FB12_Pos)
#define CAN_F5R1_FB12          CAN_F5R1_FB12_Msk
#define CAN_F5R1_FB13_Pos      (13U)
#define CAN_F5R1_FB13_Msk      (0x1U << CAN_F5R1_FB13_Pos)
#define CAN_F5R1_FB13          CAN_F5R1_FB13_Msk
#define CAN_F5R1_FB14_Pos      (14U)
#define CAN_F5R1_FB14_Msk      (0x1U << CAN_F5R1_FB14_Pos)
#define CAN_F5R1_FB14          CAN_F5R1_FB14_Msk
#define CAN_F5R1_FB15_Pos      (15U)
#define CAN_F5R1_FB15_Msk      (0x1U << CAN_F5R1_FB15_Pos)
#define CAN_F5R1_FB15          CAN_F5R1_FB15_Msk
#define CAN_F5R1_FB16_Pos      (16U)
#define CAN_F5R1_FB16_Msk      (0x1U << CAN_F5R1_FB16_Pos)
#define CAN_F5R1_FB16          CAN_F5R1_FB16_Msk
#define CAN_F5R1_FB17_Pos      (17U)
#define CAN_F5R1_FB17_Msk      (0x1U << CAN_F5R1_FB17_Pos)
#define CAN_F5R1_FB17          CAN_F5R1_FB17_Msk
#define CAN_F5R1_FB18_Pos      (18U)
#define CAN_F5R1_FB18_Msk      (0x1U << CAN_F5R1_FB18_Pos)
#define CAN_F5R1_FB18          CAN_F5R1_FB18_Msk
#define CAN_F5R1_FB19_Pos      (19U)
#define CAN_F5R1_FB19_Msk      (0x1U << CAN_F5R1_FB19_Pos)
#define CAN_F5R1_FB19          CAN_F5R1_FB19_Msk
#define CAN_F5R1_FB20_Pos      (20U)
#define CAN_F5R1_FB20_Msk      (0x1U << CAN_F5R1_FB20_Pos)
#define CAN_F5R1_FB20          CAN_F5R1_FB20_Msk
#define CAN_F5R1_FB21_Pos      (21U)
#define CAN_F5R1_FB21_Msk      (0x1U << CAN_F5R1_FB21_Pos)
#define CAN_F5R1_FB21          CAN_F5R1_FB21_Msk
#define CAN_F5R1_FB22_Pos      (22U)
#define CAN_F5R1_FB22_Msk      (0x1U << CAN_F5R1_FB22_Pos)
#define CAN_F5R1_FB22          CAN_F5R1_FB22_Msk
#define CAN_F5R1_FB23_Pos      (23U)
#define CAN_F5R1_FB23_Msk      (0x1U << CAN_F5R1_FB23_Pos)
#define CAN_F5R1_FB23          CAN_F5R1_FB23_Msk
#define CAN_F5R1_FB24_Pos      (24U)
#define CAN_F5R1_FB24_Msk      (0x1U << CAN_F5R1_FB24_Pos)
#define CAN_F5R1_FB24          CAN_F5R1_FB24_Msk
#define CAN_F5R1_FB25_Pos      (25U)
#define CAN_F5R1_FB25_Msk      (0x1U << CAN_F5R1_FB25_Pos)
#define CAN_F5R1_FB25          CAN_F5R1_FB25_Msk
#define CAN_F5R1_FB26_Pos      (26U)
#define CAN_F5R1_FB26_Msk      (0x1U << CAN_F5R1_FB26_Pos)
#define CAN_F5R1_FB26          CAN_F5R1_FB26_Msk
#define CAN_F5R1_FB27_Pos      (27U)
#define CAN_F5R1_FB27_Msk      (0x1U << CAN_F5R1_FB27_Pos)
#define CAN_F5R1_FB27          CAN_F5R1_FB27_Msk
#define CAN_F5R1_FB28_Pos      (28U)
#define CAN_F5R1_FB28_Msk      (0x1U << CAN_F5R1_FB28_Pos)
#define CAN_F5R1_FB28          CAN_F5R1_FB28_Msk
#define CAN_F5R1_FB29_Pos      (29U)
#define CAN_F5R1_FB29_Msk      (0x1U << CAN_F5R1_FB29_Pos)
#define CAN_F5R1_FB29          CAN_F5R1_FB29_Msk
#define CAN_F5R1_FB30_Pos      (30U)
#define CAN_F5R1_FB30_Msk      (0x1U << CAN_F5R1_FB30_Pos)
#define CAN_F5R1_FB30          CAN_F5R1_FB30_Msk
#define CAN_F5R1_FB31_Pos      (31U)
#define CAN_F5R1_FB31_Msk      (0x1U << CAN_F5R1_FB31_Pos)
#define CAN_F5R1_FB31          CAN_F5R1_FB31_Msk


#define CAN_F6R1_FB0_Pos       (0U)
#define CAN_F6R1_FB0_Msk       (0x1U << CAN_F6R1_FB0_Pos)
#define CAN_F6R1_FB0           CAN_F6R1_FB0_Msk
#define CAN_F6R1_FB1_Pos       (1U)
#define CAN_F6R1_FB1_Msk       (0x1U << CAN_F6R1_FB1_Pos)
#define CAN_F6R1_FB1           CAN_F6R1_FB1_Msk
#define CAN_F6R1_FB2_Pos       (2U)
#define CAN_F6R1_FB2_Msk       (0x1U << CAN_F6R1_FB2_Pos)
#define CAN_F6R1_FB2           CAN_F6R1_FB2_Msk
#define CAN_F6R1_FB3_Pos       (3U)
#define CAN_F6R1_FB3_Msk       (0x1U << CAN_F6R1_FB3_Pos)
#define CAN_F6R1_FB3           CAN_F6R1_FB3_Msk
#define CAN_F6R1_FB4_Pos       (4U)
#define CAN_F6R1_FB4_Msk       (0x1U << CAN_F6R1_FB4_Pos)
#define CAN_F6R1_FB4           CAN_F6R1_FB4_Msk
#define CAN_F6R1_FB5_Pos       (5U)
#define CAN_F6R1_FB5_Msk       (0x1U << CAN_F6R1_FB5_Pos)
#define CAN_F6R1_FB5           CAN_F6R1_FB5_Msk
#define CAN_F6R1_FB6_Pos       (6U)
#define CAN_F6R1_FB6_Msk       (0x1U << CAN_F6R1_FB6_Pos)
#define CAN_F6R1_FB6           CAN_F6R1_FB6_Msk
#define CAN_F6R1_FB7_Pos       (7U)
#define CAN_F6R1_FB7_Msk       (0x1U << CAN_F6R1_FB7_Pos)
#define CAN_F6R1_FB7           CAN_F6R1_FB7_Msk
#define CAN_F6R1_FB8_Pos       (8U)
#define CAN_F6R1_FB8_Msk       (0x1U << CAN_F6R1_FB8_Pos)
#define CAN_F6R1_FB8           CAN_F6R1_FB8_Msk
#define CAN_F6R1_FB9_Pos       (9U)
#define CAN_F6R1_FB9_Msk       (0x1U << CAN_F6R1_FB9_Pos)
#define CAN_F6R1_FB9           CAN_F6R1_FB9_Msk
#define CAN_F6R1_FB10_Pos      (10U)
#define CAN_F6R1_FB10_Msk      (0x1U << CAN_F6R1_FB10_Pos)
#define CAN_F6R1_FB10          CAN_F6R1_FB10_Msk
#define CAN_F6R1_FB11_Pos      (11U)
#define CAN_F6R1_FB11_Msk      (0x1U << CAN_F6R1_FB11_Pos)
#define CAN_F6R1_FB11          CAN_F6R1_FB11_Msk
#define CAN_F6R1_FB12_Pos      (12U)
#define CAN_F6R1_FB12_Msk      (0x1U << CAN_F6R1_FB12_Pos)
#define CAN_F6R1_FB12          CAN_F6R1_FB12_Msk
#define CAN_F6R1_FB13_Pos      (13U)
#define CAN_F6R1_FB13_Msk      (0x1U << CAN_F6R1_FB13_Pos)
#define CAN_F6R1_FB13          CAN_F6R1_FB13_Msk
#define CAN_F6R1_FB14_Pos      (14U)
#define CAN_F6R1_FB14_Msk      (0x1U << CAN_F6R1_FB14_Pos)
#define CAN_F6R1_FB14          CAN_F6R1_FB14_Msk
#define CAN_F6R1_FB15_Pos      (15U)
#define CAN_F6R1_FB15_Msk      (0x1U << CAN_F6R1_FB15_Pos)
#define CAN_F6R1_FB15          CAN_F6R1_FB15_Msk
#define CAN_F6R1_FB16_Pos      (16U)
#define CAN_F6R1_FB16_Msk      (0x1U << CAN_F6R1_FB16_Pos)
#define CAN_F6R1_FB16          CAN_F6R1_FB16_Msk
#define CAN_F6R1_FB17_Pos      (17U)
#define CAN_F6R1_FB17_Msk      (0x1U << CAN_F6R1_FB17_Pos)
#define CAN_F6R1_FB17          CAN_F6R1_FB17_Msk
#define CAN_F6R1_FB18_Pos      (18U)
#define CAN_F6R1_FB18_Msk      (0x1U << CAN_F6R1_FB18_Pos)
#define CAN_F6R1_FB18          CAN_F6R1_FB18_Msk
#define CAN_F6R1_FB19_Pos      (19U)
#define CAN_F6R1_FB19_Msk      (0x1U << CAN_F6R1_FB19_Pos)
#define CAN_F6R1_FB19          CAN_F6R1_FB19_Msk
#define CAN_F6R1_FB20_Pos      (20U)
#define CAN_F6R1_FB20_Msk      (0x1U << CAN_F6R1_FB20_Pos)
#define CAN_F6R1_FB20          CAN_F6R1_FB20_Msk
#define CAN_F6R1_FB21_Pos      (21U)
#define CAN_F6R1_FB21_Msk      (0x1U << CAN_F6R1_FB21_Pos)
#define CAN_F6R1_FB21          CAN_F6R1_FB21_Msk
#define CAN_F6R1_FB22_Pos      (22U)
#define CAN_F6R1_FB22_Msk      (0x1U << CAN_F6R1_FB22_Pos)
#define CAN_F6R1_FB22          CAN_F6R1_FB22_Msk
#define CAN_F6R1_FB23_Pos      (23U)
#define CAN_F6R1_FB23_Msk      (0x1U << CAN_F6R1_FB23_Pos)
#define CAN_F6R1_FB23          CAN_F6R1_FB23_Msk
#define CAN_F6R1_FB24_Pos      (24U)
#define CAN_F6R1_FB24_Msk      (0x1U << CAN_F6R1_FB24_Pos)
#define CAN_F6R1_FB24          CAN_F6R1_FB24_Msk
#define CAN_F6R1_FB25_Pos      (25U)
#define CAN_F6R1_FB25_Msk      (0x1U << CAN_F6R1_FB25_Pos)
#define CAN_F6R1_FB25          CAN_F6R1_FB25_Msk
#define CAN_F6R1_FB26_Pos      (26U)
#define CAN_F6R1_FB26_Msk      (0x1U << CAN_F6R1_FB26_Pos)
#define CAN_F6R1_FB26          CAN_F6R1_FB26_Msk
#define CAN_F6R1_FB27_Pos      (27U)
#define CAN_F6R1_FB27_Msk      (0x1U << CAN_F6R1_FB27_Pos)
#define CAN_F6R1_FB27          CAN_F6R1_FB27_Msk
#define CAN_F6R1_FB28_Pos      (28U)
#define CAN_F6R1_FB28_Msk      (0x1U << CAN_F6R1_FB28_Pos)
#define CAN_F6R1_FB28          CAN_F6R1_FB28_Msk
#define CAN_F6R1_FB29_Pos      (29U)
#define CAN_F6R1_FB29_Msk      (0x1U << CAN_F6R1_FB29_Pos)
#define CAN_F6R1_FB29          CAN_F6R1_FB29_Msk
#define CAN_F6R1_FB30_Pos      (30U)
#define CAN_F6R1_FB30_Msk      (0x1U << CAN_F6R1_FB30_Pos)
#define CAN_F6R1_FB30          CAN_F6R1_FB30_Msk
#define CAN_F6R1_FB31_Pos      (31U)
#define CAN_F6R1_FB31_Msk      (0x1U << CAN_F6R1_FB31_Pos)
#define CAN_F6R1_FB31          CAN_F6R1_FB31_Msk


#define CAN_F7R1_FB0_Pos       (0U)
#define CAN_F7R1_FB0_Msk       (0x1U << CAN_F7R1_FB0_Pos)
#define CAN_F7R1_FB0           CAN_F7R1_FB0_Msk
#define CAN_F7R1_FB1_Pos       (1U)
#define CAN_F7R1_FB1_Msk       (0x1U << CAN_F7R1_FB1_Pos)
#define CAN_F7R1_FB1           CAN_F7R1_FB1_Msk
#define CAN_F7R1_FB2_Pos       (2U)
#define CAN_F7R1_FB2_Msk       (0x1U << CAN_F7R1_FB2_Pos)
#define CAN_F7R1_FB2           CAN_F7R1_FB2_Msk
#define CAN_F7R1_FB3_Pos       (3U)
#define CAN_F7R1_FB3_Msk       (0x1U << CAN_F7R1_FB3_Pos)
#define CAN_F7R1_FB3           CAN_F7R1_FB3_Msk
#define CAN_F7R1_FB4_Pos       (4U)
#define CAN_F7R1_FB4_Msk       (0x1U << CAN_F7R1_FB4_Pos)
#define CAN_F7R1_FB4           CAN_F7R1_FB4_Msk
#define CAN_F7R1_FB5_Pos       (5U)
#define CAN_F7R1_FB5_Msk       (0x1U << CAN_F7R1_FB5_Pos)
#define CAN_F7R1_FB5           CAN_F7R1_FB5_Msk
#define CAN_F7R1_FB6_Pos       (6U)
#define CAN_F7R1_FB6_Msk       (0x1U << CAN_F7R1_FB6_Pos)
#define CAN_F7R1_FB6           CAN_F7R1_FB6_Msk
#define CAN_F7R1_FB7_Pos       (7U)
#define CAN_F7R1_FB7_Msk       (0x1U << CAN_F7R1_FB7_Pos)
#define CAN_F7R1_FB7           CAN_F7R1_FB7_Msk
#define CAN_F7R1_FB8_Pos       (8U)
#define CAN_F7R1_FB8_Msk       (0x1U << CAN_F7R1_FB8_Pos)
#define CAN_F7R1_FB8           CAN_F7R1_FB8_Msk
#define CAN_F7R1_FB9_Pos       (9U)
#define CAN_F7R1_FB9_Msk       (0x1U << CAN_F7R1_FB9_Pos)
#define CAN_F7R1_FB9           CAN_F7R1_FB9_Msk
#define CAN_F7R1_FB10_Pos      (10U)
#define CAN_F7R1_FB10_Msk      (0x1U << CAN_F7R1_FB10_Pos)
#define CAN_F7R1_FB10          CAN_F7R1_FB10_Msk
#define CAN_F7R1_FB11_Pos      (11U)
#define CAN_F7R1_FB11_Msk      (0x1U << CAN_F7R1_FB11_Pos)
#define CAN_F7R1_FB11          CAN_F7R1_FB11_Msk
#define CAN_F7R1_FB12_Pos      (12U)
#define CAN_F7R1_FB12_Msk      (0x1U << CAN_F7R1_FB12_Pos)
#define CAN_F7R1_FB12          CAN_F7R1_FB12_Msk
#define CAN_F7R1_FB13_Pos      (13U)
#define CAN_F7R1_FB13_Msk      (0x1U << CAN_F7R1_FB13_Pos)
#define CAN_F7R1_FB13          CAN_F7R1_FB13_Msk
#define CAN_F7R1_FB14_Pos      (14U)
#define CAN_F7R1_FB14_Msk      (0x1U << CAN_F7R1_FB14_Pos)
#define CAN_F7R1_FB14          CAN_F7R1_FB14_Msk
#define CAN_F7R1_FB15_Pos      (15U)
#define CAN_F7R1_FB15_Msk      (0x1U << CAN_F7R1_FB15_Pos)
#define CAN_F7R1_FB15          CAN_F7R1_FB15_Msk
#define CAN_F7R1_FB16_Pos      (16U)
#define CAN_F7R1_FB16_Msk      (0x1U << CAN_F7R1_FB16_Pos)
#define CAN_F7R1_FB16          CAN_F7R1_FB16_Msk
#define CAN_F7R1_FB17_Pos      (17U)
#define CAN_F7R1_FB17_Msk      (0x1U << CAN_F7R1_FB17_Pos)
#define CAN_F7R1_FB17          CAN_F7R1_FB17_Msk
#define CAN_F7R1_FB18_Pos      (18U)
#define CAN_F7R1_FB18_Msk      (0x1U << CAN_F7R1_FB18_Pos)
#define CAN_F7R1_FB18          CAN_F7R1_FB18_Msk
#define CAN_F7R1_FB19_Pos      (19U)
#define CAN_F7R1_FB19_Msk      (0x1U << CAN_F7R1_FB19_Pos)
#define CAN_F7R1_FB19          CAN_F7R1_FB19_Msk
#define CAN_F7R1_FB20_Pos      (20U)
#define CAN_F7R1_FB20_Msk      (0x1U << CAN_F7R1_FB20_Pos)
#define CAN_F7R1_FB20          CAN_F7R1_FB20_Msk
#define CAN_F7R1_FB21_Pos      (21U)
#define CAN_F7R1_FB21_Msk      (0x1U << CAN_F7R1_FB21_Pos)
#define CAN_F7R1_FB21          CAN_F7R1_FB21_Msk
#define CAN_F7R1_FB22_Pos      (22U)
#define CAN_F7R1_FB22_Msk      (0x1U << CAN_F7R1_FB22_Pos)
#define CAN_F7R1_FB22          CAN_F7R1_FB22_Msk
#define CAN_F7R1_FB23_Pos      (23U)
#define CAN_F7R1_FB23_Msk      (0x1U << CAN_F7R1_FB23_Pos)
#define CAN_F7R1_FB23          CAN_F7R1_FB23_Msk
#define CAN_F7R1_FB24_Pos      (24U)
#define CAN_F7R1_FB24_Msk      (0x1U << CAN_F7R1_FB24_Pos)
#define CAN_F7R1_FB24          CAN_F7R1_FB24_Msk
#define CAN_F7R1_FB25_Pos      (25U)
#define CAN_F7R1_FB25_Msk      (0x1U << CAN_F7R1_FB25_Pos)
#define CAN_F7R1_FB25          CAN_F7R1_FB25_Msk
#define CAN_F7R1_FB26_Pos      (26U)
#define CAN_F7R1_FB26_Msk      (0x1U << CAN_F7R1_FB26_Pos)
#define CAN_F7R1_FB26          CAN_F7R1_FB26_Msk
#define CAN_F7R1_FB27_Pos      (27U)
#define CAN_F7R1_FB27_Msk      (0x1U << CAN_F7R1_FB27_Pos)
#define CAN_F7R1_FB27          CAN_F7R1_FB27_Msk
#define CAN_F7R1_FB28_Pos      (28U)
#define CAN_F7R1_FB28_Msk      (0x1U << CAN_F7R1_FB28_Pos)
#define CAN_F7R1_FB28          CAN_F7R1_FB28_Msk
#define CAN_F7R1_FB29_Pos      (29U)
#define CAN_F7R1_FB29_Msk      (0x1U << CAN_F7R1_FB29_Pos)
#define CAN_F7R1_FB29          CAN_F7R1_FB29_Msk
#define CAN_F7R1_FB30_Pos      (30U)
#define CAN_F7R1_FB30_Msk      (0x1U << CAN_F7R1_FB30_Pos)
#define CAN_F7R1_FB30          CAN_F7R1_FB30_Msk
#define CAN_F7R1_FB31_Pos      (31U)
#define CAN_F7R1_FB31_Msk      (0x1U << CAN_F7R1_FB31_Pos)
#define CAN_F7R1_FB31          CAN_F7R1_FB31_Msk


#define CAN_F8R1_FB0_Pos       (0U)
#define CAN_F8R1_FB0_Msk       (0x1U << CAN_F8R1_FB0_Pos)
#define CAN_F8R1_FB0           CAN_F8R1_FB0_Msk
#define CAN_F8R1_FB1_Pos       (1U)
#define CAN_F8R1_FB1_Msk       (0x1U << CAN_F8R1_FB1_Pos)
#define CAN_F8R1_FB1           CAN_F8R1_FB1_Msk
#define CAN_F8R1_FB2_Pos       (2U)
#define CAN_F8R1_FB2_Msk       (0x1U << CAN_F8R1_FB2_Pos)
#define CAN_F8R1_FB2           CAN_F8R1_FB2_Msk
#define CAN_F8R1_FB3_Pos       (3U)
#define CAN_F8R1_FB3_Msk       (0x1U << CAN_F8R1_FB3_Pos)
#define CAN_F8R1_FB3           CAN_F8R1_FB3_Msk
#define CAN_F8R1_FB4_Pos       (4U)
#define CAN_F8R1_FB4_Msk       (0x1U << CAN_F8R1_FB4_Pos)
#define CAN_F8R1_FB4           CAN_F8R1_FB4_Msk
#define CAN_F8R1_FB5_Pos       (5U)
#define CAN_F8R1_FB5_Msk       (0x1U << CAN_F8R1_FB5_Pos)
#define CAN_F8R1_FB5           CAN_F8R1_FB5_Msk
#define CAN_F8R1_FB6_Pos       (6U)
#define CAN_F8R1_FB6_Msk       (0x1U << CAN_F8R1_FB6_Pos)
#define CAN_F8R1_FB6           CAN_F8R1_FB6_Msk
#define CAN_F8R1_FB7_Pos       (7U)
#define CAN_F8R1_FB7_Msk       (0x1U << CAN_F8R1_FB7_Pos)
#define CAN_F8R1_FB7           CAN_F8R1_FB7_Msk
#define CAN_F8R1_FB8_Pos       (8U)
#define CAN_F8R1_FB8_Msk       (0x1U << CAN_F8R1_FB8_Pos)
#define CAN_F8R1_FB8           CAN_F8R1_FB8_Msk
#define CAN_F8R1_FB9_Pos       (9U)
#define CAN_F8R1_FB9_Msk       (0x1U << CAN_F8R1_FB9_Pos)
#define CAN_F8R1_FB9           CAN_F8R1_FB9_Msk
#define CAN_F8R1_FB10_Pos      (10U)
#define CAN_F8R1_FB10_Msk      (0x1U << CAN_F8R1_FB10_Pos)
#define CAN_F8R1_FB10          CAN_F8R1_FB10_Msk
#define CAN_F8R1_FB11_Pos      (11U)
#define CAN_F8R1_FB11_Msk      (0x1U << CAN_F8R1_FB11_Pos)
#define CAN_F8R1_FB11          CAN_F8R1_FB11_Msk
#define CAN_F8R1_FB12_Pos      (12U)
#define CAN_F8R1_FB12_Msk      (0x1U << CAN_F8R1_FB12_Pos)
#define CAN_F8R1_FB12          CAN_F8R1_FB12_Msk
#define CAN_F8R1_FB13_Pos      (13U)
#define CAN_F8R1_FB13_Msk      (0x1U << CAN_F8R1_FB13_Pos)
#define CAN_F8R1_FB13          CAN_F8R1_FB13_Msk
#define CAN_F8R1_FB14_Pos      (14U)
#define CAN_F8R1_FB14_Msk      (0x1U << CAN_F8R1_FB14_Pos)
#define CAN_F8R1_FB14          CAN_F8R1_FB14_Msk
#define CAN_F8R1_FB15_Pos      (15U)
#define CAN_F8R1_FB15_Msk      (0x1U << CAN_F8R1_FB15_Pos)
#define CAN_F8R1_FB15          CAN_F8R1_FB15_Msk
#define CAN_F8R1_FB16_Pos      (16U)
#define CAN_F8R1_FB16_Msk      (0x1U << CAN_F8R1_FB16_Pos)
#define CAN_F8R1_FB16          CAN_F8R1_FB16_Msk
#define CAN_F8R1_FB17_Pos      (17U)
#define CAN_F8R1_FB17_Msk      (0x1U << CAN_F8R1_FB17_Pos)
#define CAN_F8R1_FB17          CAN_F8R1_FB17_Msk
#define CAN_F8R1_FB18_Pos      (18U)
#define CAN_F8R1_FB18_Msk      (0x1U << CAN_F8R1_FB18_Pos)
#define CAN_F8R1_FB18          CAN_F8R1_FB18_Msk
#define CAN_F8R1_FB19_Pos      (19U)
#define CAN_F8R1_FB19_Msk      (0x1U << CAN_F8R1_FB19_Pos)
#define CAN_F8R1_FB19          CAN_F8R1_FB19_Msk
#define CAN_F8R1_FB20_Pos      (20U)
#define CAN_F8R1_FB20_Msk      (0x1U << CAN_F8R1_FB20_Pos)
#define CAN_F8R1_FB20          CAN_F8R1_FB20_Msk
#define CAN_F8R1_FB21_Pos      (21U)
#define CAN_F8R1_FB21_Msk      (0x1U << CAN_F8R1_FB21_Pos)
#define CAN_F8R1_FB21          CAN_F8R1_FB21_Msk
#define CAN_F8R1_FB22_Pos      (22U)
#define CAN_F8R1_FB22_Msk      (0x1U << CAN_F8R1_FB22_Pos)
#define CAN_F8R1_FB22          CAN_F8R1_FB22_Msk
#define CAN_F8R1_FB23_Pos      (23U)
#define CAN_F8R1_FB23_Msk      (0x1U << CAN_F8R1_FB23_Pos)
#define CAN_F8R1_FB23          CAN_F8R1_FB23_Msk
#define CAN_F8R1_FB24_Pos      (24U)
#define CAN_F8R1_FB24_Msk      (0x1U << CAN_F8R1_FB24_Pos)
#define CAN_F8R1_FB24          CAN_F8R1_FB24_Msk
#define CAN_F8R1_FB25_Pos      (25U)
#define CAN_F8R1_FB25_Msk      (0x1U << CAN_F8R1_FB25_Pos)
#define CAN_F8R1_FB25          CAN_F8R1_FB25_Msk
#define CAN_F8R1_FB26_Pos      (26U)
#define CAN_F8R1_FB26_Msk      (0x1U << CAN_F8R1_FB26_Pos)
#define CAN_F8R1_FB26          CAN_F8R1_FB26_Msk
#define CAN_F8R1_FB27_Pos      (27U)
#define CAN_F8R1_FB27_Msk      (0x1U << CAN_F8R1_FB27_Pos)
#define CAN_F8R1_FB27          CAN_F8R1_FB27_Msk
#define CAN_F8R1_FB28_Pos      (28U)
#define CAN_F8R1_FB28_Msk      (0x1U << CAN_F8R1_FB28_Pos)
#define CAN_F8R1_FB28          CAN_F8R1_FB28_Msk
#define CAN_F8R1_FB29_Pos      (29U)
#define CAN_F8R1_FB29_Msk      (0x1U << CAN_F8R1_FB29_Pos)
#define CAN_F8R1_FB29          CAN_F8R1_FB29_Msk
#define CAN_F8R1_FB30_Pos      (30U)
#define CAN_F8R1_FB30_Msk      (0x1U << CAN_F8R1_FB30_Pos)
#define CAN_F8R1_FB30          CAN_F8R1_FB30_Msk
#define CAN_F8R1_FB31_Pos      (31U)
#define CAN_F8R1_FB31_Msk      (0x1U << CAN_F8R1_FB31_Pos)
#define CAN_F8R1_FB31          CAN_F8R1_FB31_Msk


#define CAN_F9R1_FB0_Pos       (0U)
#define CAN_F9R1_FB0_Msk       (0x1U << CAN_F9R1_FB0_Pos)
#define CAN_F9R1_FB0           CAN_F9R1_FB0_Msk
#define CAN_F9R1_FB1_Pos       (1U)
#define CAN_F9R1_FB1_Msk       (0x1U << CAN_F9R1_FB1_Pos)
#define CAN_F9R1_FB1           CAN_F9R1_FB1_Msk
#define CAN_F9R1_FB2_Pos       (2U)
#define CAN_F9R1_FB2_Msk       (0x1U << CAN_F9R1_FB2_Pos)
#define CAN_F9R1_FB2           CAN_F9R1_FB2_Msk
#define CAN_F9R1_FB3_Pos       (3U)
#define CAN_F9R1_FB3_Msk       (0x1U << CAN_F9R1_FB3_Pos)
#define CAN_F9R1_FB3           CAN_F9R1_FB3_Msk
#define CAN_F9R1_FB4_Pos       (4U)
#define CAN_F9R1_FB4_Msk       (0x1U << CAN_F9R1_FB4_Pos)
#define CAN_F9R1_FB4           CAN_F9R1_FB4_Msk
#define CAN_F9R1_FB5_Pos       (5U)
#define CAN_F9R1_FB5_Msk       (0x1U << CAN_F9R1_FB5_Pos)
#define CAN_F9R1_FB5           CAN_F9R1_FB5_Msk
#define CAN_F9R1_FB6_Pos       (6U)
#define CAN_F9R1_FB6_Msk       (0x1U << CAN_F9R1_FB6_Pos)
#define CAN_F9R1_FB6           CAN_F9R1_FB6_Msk
#define CAN_F9R1_FB7_Pos       (7U)
#define CAN_F9R1_FB7_Msk       (0x1U << CAN_F9R1_FB7_Pos)
#define CAN_F9R1_FB7           CAN_F9R1_FB7_Msk
#define CAN_F9R1_FB8_Pos       (8U)
#define CAN_F9R1_FB8_Msk       (0x1U << CAN_F9R1_FB8_Pos)
#define CAN_F9R1_FB8           CAN_F9R1_FB8_Msk
#define CAN_F9R1_FB9_Pos       (9U)
#define CAN_F9R1_FB9_Msk       (0x1U << CAN_F9R1_FB9_Pos)
#define CAN_F9R1_FB9           CAN_F9R1_FB9_Msk
#define CAN_F9R1_FB10_Pos      (10U)
#define CAN_F9R1_FB10_Msk      (0x1U << CAN_F9R1_FB10_Pos)
#define CAN_F9R1_FB10          CAN_F9R1_FB10_Msk
#define CAN_F9R1_FB11_Pos      (11U)
#define CAN_F9R1_FB11_Msk      (0x1U << CAN_F9R1_FB11_Pos)
#define CAN_F9R1_FB11          CAN_F9R1_FB11_Msk
#define CAN_F9R1_FB12_Pos      (12U)
#define CAN_F9R1_FB12_Msk      (0x1U << CAN_F9R1_FB12_Pos)
#define CAN_F9R1_FB12          CAN_F9R1_FB12_Msk
#define CAN_F9R1_FB13_Pos      (13U)
#define CAN_F9R1_FB13_Msk      (0x1U << CAN_F9R1_FB13_Pos)
#define CAN_F9R1_FB13          CAN_F9R1_FB13_Msk
#define CAN_F9R1_FB14_Pos      (14U)
#define CAN_F9R1_FB14_Msk      (0x1U << CAN_F9R1_FB14_Pos)
#define CAN_F9R1_FB14          CAN_F9R1_FB14_Msk
#define CAN_F9R1_FB15_Pos      (15U)
#define CAN_F9R1_FB15_Msk      (0x1U << CAN_F9R1_FB15_Pos)
#define CAN_F9R1_FB15          CAN_F9R1_FB15_Msk
#define CAN_F9R1_FB16_Pos      (16U)
#define CAN_F9R1_FB16_Msk      (0x1U << CAN_F9R1_FB16_Pos)
#define CAN_F9R1_FB16          CAN_F9R1_FB16_Msk
#define CAN_F9R1_FB17_Pos      (17U)
#define CAN_F9R1_FB17_Msk      (0x1U << CAN_F9R1_FB17_Pos)
#define CAN_F9R1_FB17          CAN_F9R1_FB17_Msk
#define CAN_F9R1_FB18_Pos      (18U)
#define CAN_F9R1_FB18_Msk      (0x1U << CAN_F9R1_FB18_Pos)
#define CAN_F9R1_FB18          CAN_F9R1_FB18_Msk
#define CAN_F9R1_FB19_Pos      (19U)
#define CAN_F9R1_FB19_Msk      (0x1U << CAN_F9R1_FB19_Pos)
#define CAN_F9R1_FB19          CAN_F9R1_FB19_Msk
#define CAN_F9R1_FB20_Pos      (20U)
#define CAN_F9R1_FB20_Msk      (0x1U << CAN_F9R1_FB20_Pos)
#define CAN_F9R1_FB20          CAN_F9R1_FB20_Msk
#define CAN_F9R1_FB21_Pos      (21U)
#define CAN_F9R1_FB21_Msk      (0x1U << CAN_F9R1_FB21_Pos)
#define CAN_F9R1_FB21          CAN_F9R1_FB21_Msk
#define CAN_F9R1_FB22_Pos      (22U)
#define CAN_F9R1_FB22_Msk      (0x1U << CAN_F9R1_FB22_Pos)
#define CAN_F9R1_FB22          CAN_F9R1_FB22_Msk
#define CAN_F9R1_FB23_Pos      (23U)
#define CAN_F9R1_FB23_Msk      (0x1U << CAN_F9R1_FB23_Pos)
#define CAN_F9R1_FB23          CAN_F9R1_FB23_Msk
#define CAN_F9R1_FB24_Pos      (24U)
#define CAN_F9R1_FB24_Msk      (0x1U << CAN_F9R1_FB24_Pos)
#define CAN_F9R1_FB24          CAN_F9R1_FB24_Msk
#define CAN_F9R1_FB25_Pos      (25U)
#define CAN_F9R1_FB25_Msk      (0x1U << CAN_F9R1_FB25_Pos)
#define CAN_F9R1_FB25          CAN_F9R1_FB25_Msk
#define CAN_F9R1_FB26_Pos      (26U)
#define CAN_F9R1_FB26_Msk      (0x1U << CAN_F9R1_FB26_Pos)
#define CAN_F9R1_FB26          CAN_F9R1_FB26_Msk
#define CAN_F9R1_FB27_Pos      (27U)
#define CAN_F9R1_FB27_Msk      (0x1U << CAN_F9R1_FB27_Pos)
#define CAN_F9R1_FB27          CAN_F9R1_FB27_Msk
#define CAN_F9R1_FB28_Pos      (28U)
#define CAN_F9R1_FB28_Msk      (0x1U << CAN_F9R1_FB28_Pos)
#define CAN_F9R1_FB28          CAN_F9R1_FB28_Msk
#define CAN_F9R1_FB29_Pos      (29U)
#define CAN_F9R1_FB29_Msk      (0x1U << CAN_F9R1_FB29_Pos)
#define CAN_F9R1_FB29          CAN_F9R1_FB29_Msk
#define CAN_F9R1_FB30_Pos      (30U)
#define CAN_F9R1_FB30_Msk      (0x1U << CAN_F9R1_FB30_Pos)
#define CAN_F9R1_FB30          CAN_F9R1_FB30_Msk
#define CAN_F9R1_FB31_Pos      (31U)
#define CAN_F9R1_FB31_Msk      (0x1U << CAN_F9R1_FB31_Pos)
#define CAN_F9R1_FB31          CAN_F9R1_FB31_Msk


#define CAN_F10R1_FB0_Pos      (0U)
#define CAN_F10R1_FB0_Msk      (0x1U << CAN_F10R1_FB0_Pos)
#define CAN_F10R1_FB0          CAN_F10R1_FB0_Msk
#define CAN_F10R1_FB1_Pos      (1U)
#define CAN_F10R1_FB1_Msk      (0x1U << CAN_F10R1_FB1_Pos)
#define CAN_F10R1_FB1          CAN_F10R1_FB1_Msk
#define CAN_F10R1_FB2_Pos      (2U)
#define CAN_F10R1_FB2_Msk      (0x1U << CAN_F10R1_FB2_Pos)
#define CAN_F10R1_FB2          CAN_F10R1_FB2_Msk
#define CAN_F10R1_FB3_Pos      (3U)
#define CAN_F10R1_FB3_Msk      (0x1U << CAN_F10R1_FB3_Pos)
#define CAN_F10R1_FB3          CAN_F10R1_FB3_Msk
#define CAN_F10R1_FB4_Pos      (4U)
#define CAN_F10R1_FB4_Msk      (0x1U << CAN_F10R1_FB4_Pos)
#define CAN_F10R1_FB4          CAN_F10R1_FB4_Msk
#define CAN_F10R1_FB5_Pos      (5U)
#define CAN_F10R1_FB5_Msk      (0x1U << CAN_F10R1_FB5_Pos)
#define CAN_F10R1_FB5          CAN_F10R1_FB5_Msk
#define CAN_F10R1_FB6_Pos      (6U)
#define CAN_F10R1_FB6_Msk      (0x1U << CAN_F10R1_FB6_Pos)
#define CAN_F10R1_FB6          CAN_F10R1_FB6_Msk
#define CAN_F10R1_FB7_Pos      (7U)
#define CAN_F10R1_FB7_Msk      (0x1U << CAN_F10R1_FB7_Pos)
#define CAN_F10R1_FB7          CAN_F10R1_FB7_Msk
#define CAN_F10R1_FB8_Pos      (8U)
#define CAN_F10R1_FB8_Msk      (0x1U << CAN_F10R1_FB8_Pos)
#define CAN_F10R1_FB8          CAN_F10R1_FB8_Msk
#define CAN_F10R1_FB9_Pos      (9U)
#define CAN_F10R1_FB9_Msk      (0x1U << CAN_F10R1_FB9_Pos)
#define CAN_F10R1_FB9          CAN_F10R1_FB9_Msk
#define CAN_F10R1_FB10_Pos     (10U)
#define CAN_F10R1_FB10_Msk     (0x1U << CAN_F10R1_FB10_Pos)
#define CAN_F10R1_FB10         CAN_F10R1_FB10_Msk
#define CAN_F10R1_FB11_Pos     (11U)
#define CAN_F10R1_FB11_Msk     (0x1U << CAN_F10R1_FB11_Pos)
#define CAN_F10R1_FB11         CAN_F10R1_FB11_Msk
#define CAN_F10R1_FB12_Pos     (12U)
#define CAN_F10R1_FB12_Msk     (0x1U << CAN_F10R1_FB12_Pos)
#define CAN_F10R1_FB12         CAN_F10R1_FB12_Msk
#define CAN_F10R1_FB13_Pos     (13U)
#define CAN_F10R1_FB13_Msk     (0x1U << CAN_F10R1_FB13_Pos)
#define CAN_F10R1_FB13         CAN_F10R1_FB13_Msk
#define CAN_F10R1_FB14_Pos     (14U)
#define CAN_F10R1_FB14_Msk     (0x1U << CAN_F10R1_FB14_Pos)
#define CAN_F10R1_FB14         CAN_F10R1_FB14_Msk
#define CAN_F10R1_FB15_Pos     (15U)
#define CAN_F10R1_FB15_Msk     (0x1U << CAN_F10R1_FB15_Pos)
#define CAN_F10R1_FB15         CAN_F10R1_FB15_Msk
#define CAN_F10R1_FB16_Pos     (16U)
#define CAN_F10R1_FB16_Msk     (0x1U << CAN_F10R1_FB16_Pos)
#define CAN_F10R1_FB16         CAN_F10R1_FB16_Msk
#define CAN_F10R1_FB17_Pos     (17U)
#define CAN_F10R1_FB17_Msk     (0x1U << CAN_F10R1_FB17_Pos)
#define CAN_F10R1_FB17         CAN_F10R1_FB17_Msk
#define CAN_F10R1_FB18_Pos     (18U)
#define CAN_F10R1_FB18_Msk     (0x1U << CAN_F10R1_FB18_Pos)
#define CAN_F10R1_FB18         CAN_F10R1_FB18_Msk
#define CAN_F10R1_FB19_Pos     (19U)
#define CAN_F10R1_FB19_Msk     (0x1U << CAN_F10R1_FB19_Pos)
#define CAN_F10R1_FB19         CAN_F10R1_FB19_Msk
#define CAN_F10R1_FB20_Pos     (20U)
#define CAN_F10R1_FB20_Msk     (0x1U << CAN_F10R1_FB20_Pos)
#define CAN_F10R1_FB20         CAN_F10R1_FB20_Msk
#define CAN_F10R1_FB21_Pos     (21U)
#define CAN_F10R1_FB21_Msk     (0x1U << CAN_F10R1_FB21_Pos)
#define CAN_F10R1_FB21         CAN_F10R1_FB21_Msk
#define CAN_F10R1_FB22_Pos     (22U)
#define CAN_F10R1_FB22_Msk     (0x1U << CAN_F10R1_FB22_Pos)
#define CAN_F10R1_FB22         CAN_F10R1_FB22_Msk
#define CAN_F10R1_FB23_Pos     (23U)
#define CAN_F10R1_FB23_Msk     (0x1U << CAN_F10R1_FB23_Pos)
#define CAN_F10R1_FB23         CAN_F10R1_FB23_Msk
#define CAN_F10R1_FB24_Pos     (24U)
#define CAN_F10R1_FB24_Msk     (0x1U << CAN_F10R1_FB24_Pos)
#define CAN_F10R1_FB24         CAN_F10R1_FB24_Msk
#define CAN_F10R1_FB25_Pos     (25U)
#define CAN_F10R1_FB25_Msk     (0x1U << CAN_F10R1_FB25_Pos)
#define CAN_F10R1_FB25         CAN_F10R1_FB25_Msk
#define CAN_F10R1_FB26_Pos     (26U)
#define CAN_F10R1_FB26_Msk     (0x1U << CAN_F10R1_FB26_Pos)
#define CAN_F10R1_FB26         CAN_F10R1_FB26_Msk
#define CAN_F10R1_FB27_Pos     (27U)
#define CAN_F10R1_FB27_Msk     (0x1U << CAN_F10R1_FB27_Pos)
#define CAN_F10R1_FB27         CAN_F10R1_FB27_Msk
#define CAN_F10R1_FB28_Pos     (28U)
#define CAN_F10R1_FB28_Msk     (0x1U << CAN_F10R1_FB28_Pos)
#define CAN_F10R1_FB28         CAN_F10R1_FB28_Msk
#define CAN_F10R1_FB29_Pos     (29U)
#define CAN_F10R1_FB29_Msk     (0x1U << CAN_F10R1_FB29_Pos)
#define CAN_F10R1_FB29         CAN_F10R1_FB29_Msk
#define CAN_F10R1_FB30_Pos     (30U)
#define CAN_F10R1_FB30_Msk     (0x1U << CAN_F10R1_FB30_Pos)
#define CAN_F10R1_FB30         CAN_F10R1_FB30_Msk
#define CAN_F10R1_FB31_Pos     (31U)
#define CAN_F10R1_FB31_Msk     (0x1U << CAN_F10R1_FB31_Pos)
#define CAN_F10R1_FB31         CAN_F10R1_FB31_Msk


#define CAN_F11R1_FB0_Pos      (0U)
#define CAN_F11R1_FB0_Msk      (0x1U << CAN_F11R1_FB0_Pos)
#define CAN_F11R1_FB0          CAN_F11R1_FB0_Msk
#define CAN_F11R1_FB1_Pos      (1U)
#define CAN_F11R1_FB1_Msk      (0x1U << CAN_F11R1_FB1_Pos)
#define CAN_F11R1_FB1          CAN_F11R1_FB1_Msk
#define CAN_F11R1_FB2_Pos      (2U)
#define CAN_F11R1_FB2_Msk      (0x1U << CAN_F11R1_FB2_Pos)
#define CAN_F11R1_FB2          CAN_F11R1_FB2_Msk
#define CAN_F11R1_FB3_Pos      (3U)
#define CAN_F11R1_FB3_Msk      (0x1U << CAN_F11R1_FB3_Pos)
#define CAN_F11R1_FB3          CAN_F11R1_FB3_Msk
#define CAN_F11R1_FB4_Pos      (4U)
#define CAN_F11R1_FB4_Msk      (0x1U << CAN_F11R1_FB4_Pos)
#define CAN_F11R1_FB4          CAN_F11R1_FB4_Msk
#define CAN_F11R1_FB5_Pos      (5U)
#define CAN_F11R1_FB5_Msk      (0x1U << CAN_F11R1_FB5_Pos)
#define CAN_F11R1_FB5          CAN_F11R1_FB5_Msk
#define CAN_F11R1_FB6_Pos      (6U)
#define CAN_F11R1_FB6_Msk      (0x1U << CAN_F11R1_FB6_Pos)
#define CAN_F11R1_FB6          CAN_F11R1_FB6_Msk
#define CAN_F11R1_FB7_Pos      (7U)
#define CAN_F11R1_FB7_Msk      (0x1U << CAN_F11R1_FB7_Pos)
#define CAN_F11R1_FB7          CAN_F11R1_FB7_Msk
#define CAN_F11R1_FB8_Pos      (8U)
#define CAN_F11R1_FB8_Msk      (0x1U << CAN_F11R1_FB8_Pos)
#define CAN_F11R1_FB8          CAN_F11R1_FB8_Msk
#define CAN_F11R1_FB9_Pos      (9U)
#define CAN_F11R1_FB9_Msk      (0x1U << CAN_F11R1_FB9_Pos)
#define CAN_F11R1_FB9          CAN_F11R1_FB9_Msk
#define CAN_F11R1_FB10_Pos     (10U)
#define CAN_F11R1_FB10_Msk     (0x1U << CAN_F11R1_FB10_Pos)
#define CAN_F11R1_FB10         CAN_F11R1_FB10_Msk
#define CAN_F11R1_FB11_Pos     (11U)
#define CAN_F11R1_FB11_Msk     (0x1U << CAN_F11R1_FB11_Pos)
#define CAN_F11R1_FB11         CAN_F11R1_FB11_Msk
#define CAN_F11R1_FB12_Pos     (12U)
#define CAN_F11R1_FB12_Msk     (0x1U << CAN_F11R1_FB12_Pos)
#define CAN_F11R1_FB12         CAN_F11R1_FB12_Msk
#define CAN_F11R1_FB13_Pos     (13U)
#define CAN_F11R1_FB13_Msk     (0x1U << CAN_F11R1_FB13_Pos)
#define CAN_F11R1_FB13         CAN_F11R1_FB13_Msk
#define CAN_F11R1_FB14_Pos     (14U)
#define CAN_F11R1_FB14_Msk     (0x1U << CAN_F11R1_FB14_Pos)
#define CAN_F11R1_FB14         CAN_F11R1_FB14_Msk
#define CAN_F11R1_FB15_Pos     (15U)
#define CAN_F11R1_FB15_Msk     (0x1U << CAN_F11R1_FB15_Pos)
#define CAN_F11R1_FB15         CAN_F11R1_FB15_Msk
#define CAN_F11R1_FB16_Pos     (16U)
#define CAN_F11R1_FB16_Msk     (0x1U << CAN_F11R1_FB16_Pos)
#define CAN_F11R1_FB16         CAN_F11R1_FB16_Msk
#define CAN_F11R1_FB17_Pos     (17U)
#define CAN_F11R1_FB17_Msk     (0x1U << CAN_F11R1_FB17_Pos)
#define CAN_F11R1_FB17         CAN_F11R1_FB17_Msk
#define CAN_F11R1_FB18_Pos     (18U)
#define CAN_F11R1_FB18_Msk     (0x1U << CAN_F11R1_FB18_Pos)
#define CAN_F11R1_FB18         CAN_F11R1_FB18_Msk
#define CAN_F11R1_FB19_Pos     (19U)
#define CAN_F11R1_FB19_Msk     (0x1U << CAN_F11R1_FB19_Pos)
#define CAN_F11R1_FB19         CAN_F11R1_FB19_Msk
#define CAN_F11R1_FB20_Pos     (20U)
#define CAN_F11R1_FB20_Msk     (0x1U << CAN_F11R1_FB20_Pos)
#define CAN_F11R1_FB20         CAN_F11R1_FB20_Msk
#define CAN_F11R1_FB21_Pos     (21U)
#define CAN_F11R1_FB21_Msk     (0x1U << CAN_F11R1_FB21_Pos)
#define CAN_F11R1_FB21         CAN_F11R1_FB21_Msk
#define CAN_F11R1_FB22_Pos     (22U)
#define CAN_F11R1_FB22_Msk     (0x1U << CAN_F11R1_FB22_Pos)
#define CAN_F11R1_FB22         CAN_F11R1_FB22_Msk
#define CAN_F11R1_FB23_Pos     (23U)
#define CAN_F11R1_FB23_Msk     (0x1U << CAN_F11R1_FB23_Pos)
#define CAN_F11R1_FB23         CAN_F11R1_FB23_Msk
#define CAN_F11R1_FB24_Pos     (24U)
#define CAN_F11R1_FB24_Msk     (0x1U << CAN_F11R1_FB24_Pos)
#define CAN_F11R1_FB24         CAN_F11R1_FB24_Msk
#define CAN_F11R1_FB25_Pos     (25U)
#define CAN_F11R1_FB25_Msk     (0x1U << CAN_F11R1_FB25_Pos)
#define CAN_F11R1_FB25         CAN_F11R1_FB25_Msk
#define CAN_F11R1_FB26_Pos     (26U)
#define CAN_F11R1_FB26_Msk     (0x1U << CAN_F11R1_FB26_Pos)
#define CAN_F11R1_FB26         CAN_F11R1_FB26_Msk
#define CAN_F11R1_FB27_Pos     (27U)
#define CAN_F11R1_FB27_Msk     (0x1U << CAN_F11R1_FB27_Pos)
#define CAN_F11R1_FB27         CAN_F11R1_FB27_Msk
#define CAN_F11R1_FB28_Pos     (28U)
#define CAN_F11R1_FB28_Msk     (0x1U << CAN_F11R1_FB28_Pos)
#define CAN_F11R1_FB28         CAN_F11R1_FB28_Msk
#define CAN_F11R1_FB29_Pos     (29U)
#define CAN_F11R1_FB29_Msk     (0x1U << CAN_F11R1_FB29_Pos)
#define CAN_F11R1_FB29         CAN_F11R1_FB29_Msk
#define CAN_F11R1_FB30_Pos     (30U)
#define CAN_F11R1_FB30_Msk     (0x1U << CAN_F11R1_FB30_Pos)
#define CAN_F11R1_FB30         CAN_F11R1_FB30_Msk
#define CAN_F11R1_FB31_Pos     (31U)
#define CAN_F11R1_FB31_Msk     (0x1U << CAN_F11R1_FB31_Pos)
#define CAN_F11R1_FB31         CAN_F11R1_FB31_Msk


#define CAN_F12R1_FB0_Pos      (0U)
#define CAN_F12R1_FB0_Msk      (0x1U << CAN_F12R1_FB0_Pos)
#define CAN_F12R1_FB0          CAN_F12R1_FB0_Msk
#define CAN_F12R1_FB1_Pos      (1U)
#define CAN_F12R1_FB1_Msk      (0x1U << CAN_F12R1_FB1_Pos)
#define CAN_F12R1_FB1          CAN_F12R1_FB1_Msk
#define CAN_F12R1_FB2_Pos      (2U)
#define CAN_F12R1_FB2_Msk      (0x1U << CAN_F12R1_FB2_Pos)
#define CAN_F12R1_FB2          CAN_F12R1_FB2_Msk
#define CAN_F12R1_FB3_Pos      (3U)
#define CAN_F12R1_FB3_Msk      (0x1U << CAN_F12R1_FB3_Pos)
#define CAN_F12R1_FB3          CAN_F12R1_FB3_Msk
#define CAN_F12R1_FB4_Pos      (4U)
#define CAN_F12R1_FB4_Msk      (0x1U << CAN_F12R1_FB4_Pos)
#define CAN_F12R1_FB4          CAN_F12R1_FB4_Msk
#define CAN_F12R1_FB5_Pos      (5U)
#define CAN_F12R1_FB5_Msk      (0x1U << CAN_F12R1_FB5_Pos)
#define CAN_F12R1_FB5          CAN_F12R1_FB5_Msk
#define CAN_F12R1_FB6_Pos      (6U)
#define CAN_F12R1_FB6_Msk      (0x1U << CAN_F12R1_FB6_Pos)
#define CAN_F12R1_FB6          CAN_F12R1_FB6_Msk
#define CAN_F12R1_FB7_Pos      (7U)
#define CAN_F12R1_FB7_Msk      (0x1U << CAN_F12R1_FB7_Pos)
#define CAN_F12R1_FB7          CAN_F12R1_FB7_Msk
#define CAN_F12R1_FB8_Pos      (8U)
#define CAN_F12R1_FB8_Msk      (0x1U << CAN_F12R1_FB8_Pos)
#define CAN_F12R1_FB8          CAN_F12R1_FB8_Msk
#define CAN_F12R1_FB9_Pos      (9U)
#define CAN_F12R1_FB9_Msk      (0x1U << CAN_F12R1_FB9_Pos)
#define CAN_F12R1_FB9          CAN_F12R1_FB9_Msk
#define CAN_F12R1_FB10_Pos     (10U)
#define CAN_F12R1_FB10_Msk     (0x1U << CAN_F12R1_FB10_Pos)
#define CAN_F12R1_FB10         CAN_F12R1_FB10_Msk
#define CAN_F12R1_FB11_Pos     (11U)
#define CAN_F12R1_FB11_Msk     (0x1U << CAN_F12R1_FB11_Pos)
#define CAN_F12R1_FB11         CAN_F12R1_FB11_Msk
#define CAN_F12R1_FB12_Pos     (12U)
#define CAN_F12R1_FB12_Msk     (0x1U << CAN_F12R1_FB12_Pos)
#define CAN_F12R1_FB12         CAN_F12R1_FB12_Msk
#define CAN_F12R1_FB13_Pos     (13U)
#define CAN_F12R1_FB13_Msk     (0x1U << CAN_F12R1_FB13_Pos)
#define CAN_F12R1_FB13         CAN_F12R1_FB13_Msk
#define CAN_F12R1_FB14_Pos     (14U)
#define CAN_F12R1_FB14_Msk     (0x1U << CAN_F12R1_FB14_Pos)
#define CAN_F12R1_FB14         CAN_F12R1_FB14_Msk
#define CAN_F12R1_FB15_Pos     (15U)
#define CAN_F12R1_FB15_Msk     (0x1U << CAN_F12R1_FB15_Pos)
#define CAN_F12R1_FB15         CAN_F12R1_FB15_Msk
#define CAN_F12R1_FB16_Pos     (16U)
#define CAN_F12R1_FB16_Msk     (0x1U << CAN_F12R1_FB16_Pos)
#define CAN_F12R1_FB16         CAN_F12R1_FB16_Msk
#define CAN_F12R1_FB17_Pos     (17U)
#define CAN_F12R1_FB17_Msk     (0x1U << CAN_F12R1_FB17_Pos)
#define CAN_F12R1_FB17         CAN_F12R1_FB17_Msk
#define CAN_F12R1_FB18_Pos     (18U)
#define CAN_F12R1_FB18_Msk     (0x1U << CAN_F12R1_FB18_Pos)
#define CAN_F12R1_FB18         CAN_F12R1_FB18_Msk
#define CAN_F12R1_FB19_Pos     (19U)
#define CAN_F12R1_FB19_Msk     (0x1U << CAN_F12R1_FB19_Pos)
#define CAN_F12R1_FB19         CAN_F12R1_FB19_Msk
#define CAN_F12R1_FB20_Pos     (20U)
#define CAN_F12R1_FB20_Msk     (0x1U << CAN_F12R1_FB20_Pos)
#define CAN_F12R1_FB20         CAN_F12R1_FB20_Msk
#define CAN_F12R1_FB21_Pos     (21U)
#define CAN_F12R1_FB21_Msk     (0x1U << CAN_F12R1_FB21_Pos)
#define CAN_F12R1_FB21         CAN_F12R1_FB21_Msk
#define CAN_F12R1_FB22_Pos     (22U)
#define CAN_F12R1_FB22_Msk     (0x1U << CAN_F12R1_FB22_Pos)
#define CAN_F12R1_FB22         CAN_F12R1_FB22_Msk
#define CAN_F12R1_FB23_Pos     (23U)
#define CAN_F12R1_FB23_Msk     (0x1U << CAN_F12R1_FB23_Pos)
#define CAN_F12R1_FB23         CAN_F12R1_FB23_Msk
#define CAN_F12R1_FB24_Pos     (24U)
#define CAN_F12R1_FB24_Msk     (0x1U << CAN_F12R1_FB24_Pos)
#define CAN_F12R1_FB24         CAN_F12R1_FB24_Msk
#define CAN_F12R1_FB25_Pos     (25U)
#define CAN_F12R1_FB25_Msk     (0x1U << CAN_F12R1_FB25_Pos)
#define CAN_F12R1_FB25         CAN_F12R1_FB25_Msk
#define CAN_F12R1_FB26_Pos     (26U)
#define CAN_F12R1_FB26_Msk     (0x1U << CAN_F12R1_FB26_Pos)
#define CAN_F12R1_FB26         CAN_F12R1_FB26_Msk
#define CAN_F12R1_FB27_Pos     (27U)
#define CAN_F12R1_FB27_Msk     (0x1U << CAN_F12R1_FB27_Pos)
#define CAN_F12R1_FB27         CAN_F12R1_FB27_Msk
#define CAN_F12R1_FB28_Pos     (28U)
#define CAN_F12R1_FB28_Msk     (0x1U << CAN_F12R1_FB28_Pos)
#define CAN_F12R1_FB28         CAN_F12R1_FB28_Msk
#define CAN_F12R1_FB29_Pos     (29U)
#define CAN_F12R1_FB29_Msk     (0x1U << CAN_F12R1_FB29_Pos)
#define CAN_F12R1_FB29         CAN_F12R1_FB29_Msk
#define CAN_F12R1_FB30_Pos     (30U)
#define CAN_F12R1_FB30_Msk     (0x1U << CAN_F12R1_FB30_Pos)
#define CAN_F12R1_FB30         CAN_F12R1_FB30_Msk
#define CAN_F12R1_FB31_Pos     (31U)
#define CAN_F12R1_FB31_Msk     (0x1U << CAN_F12R1_FB31_Pos)
#define CAN_F12R1_FB31         CAN_F12R1_FB31_Msk


#define CAN_F13R1_FB0_Pos      (0U)
#define CAN_F13R1_FB0_Msk      (0x1U << CAN_F13R1_FB0_Pos)
#define CAN_F13R1_FB0          CAN_F13R1_FB0_Msk
#define CAN_F13R1_FB1_Pos      (1U)
#define CAN_F13R1_FB1_Msk      (0x1U << CAN_F13R1_FB1_Pos)
#define CAN_F13R1_FB1          CAN_F13R1_FB1_Msk
#define CAN_F13R1_FB2_Pos      (2U)
#define CAN_F13R1_FB2_Msk      (0x1U << CAN_F13R1_FB2_Pos)
#define CAN_F13R1_FB2          CAN_F13R1_FB2_Msk
#define CAN_F13R1_FB3_Pos      (3U)
#define CAN_F13R1_FB3_Msk      (0x1U << CAN_F13R1_FB3_Pos)
#define CAN_F13R1_FB3          CAN_F13R1_FB3_Msk
#define CAN_F13R1_FB4_Pos      (4U)
#define CAN_F13R1_FB4_Msk      (0x1U << CAN_F13R1_FB4_Pos)
#define CAN_F13R1_FB4          CAN_F13R1_FB4_Msk
#define CAN_F13R1_FB5_Pos      (5U)
#define CAN_F13R1_FB5_Msk      (0x1U << CAN_F13R1_FB5_Pos)
#define CAN_F13R1_FB5          CAN_F13R1_FB5_Msk
#define CAN_F13R1_FB6_Pos      (6U)
#define CAN_F13R1_FB6_Msk      (0x1U << CAN_F13R1_FB6_Pos)
#define CAN_F13R1_FB6          CAN_F13R1_FB6_Msk
#define CAN_F13R1_FB7_Pos      (7U)
#define CAN_F13R1_FB7_Msk      (0x1U << CAN_F13R1_FB7_Pos)
#define CAN_F13R1_FB7          CAN_F13R1_FB7_Msk
#define CAN_F13R1_FB8_Pos      (8U)
#define CAN_F13R1_FB8_Msk      (0x1U << CAN_F13R1_FB8_Pos)
#define CAN_F13R1_FB8          CAN_F13R1_FB8_Msk
#define CAN_F13R1_FB9_Pos      (9U)
#define CAN_F13R1_FB9_Msk      (0x1U << CAN_F13R1_FB9_Pos)
#define CAN_F13R1_FB9          CAN_F13R1_FB9_Msk
#define CAN_F13R1_FB10_Pos     (10U)
#define CAN_F13R1_FB10_Msk     (0x1U << CAN_F13R1_FB10_Pos)
#define CAN_F13R1_FB10         CAN_F13R1_FB10_Msk
#define CAN_F13R1_FB11_Pos     (11U)
#define CAN_F13R1_FB11_Msk     (0x1U << CAN_F13R1_FB11_Pos)
#define CAN_F13R1_FB11         CAN_F13R1_FB11_Msk
#define CAN_F13R1_FB12_Pos     (12U)
#define CAN_F13R1_FB12_Msk     (0x1U << CAN_F13R1_FB12_Pos)
#define CAN_F13R1_FB12         CAN_F13R1_FB12_Msk
#define CAN_F13R1_FB13_Pos     (13U)
#define CAN_F13R1_FB13_Msk     (0x1U << CAN_F13R1_FB13_Pos)
#define CAN_F13R1_FB13         CAN_F13R1_FB13_Msk
#define CAN_F13R1_FB14_Pos     (14U)
#define CAN_F13R1_FB14_Msk     (0x1U << CAN_F13R1_FB14_Pos)
#define CAN_F13R1_FB14         CAN_F13R1_FB14_Msk
#define CAN_F13R1_FB15_Pos     (15U)
#define CAN_F13R1_FB15_Msk     (0x1U << CAN_F13R1_FB15_Pos)
#define CAN_F13R1_FB15         CAN_F13R1_FB15_Msk
#define CAN_F13R1_FB16_Pos     (16U)
#define CAN_F13R1_FB16_Msk     (0x1U << CAN_F13R1_FB16_Pos)
#define CAN_F13R1_FB16         CAN_F13R1_FB16_Msk
#define CAN_F13R1_FB17_Pos     (17U)
#define CAN_F13R1_FB17_Msk     (0x1U << CAN_F13R1_FB17_Pos)
#define CAN_F13R1_FB17         CAN_F13R1_FB17_Msk
#define CAN_F13R1_FB18_Pos     (18U)
#define CAN_F13R1_FB18_Msk     (0x1U << CAN_F13R1_FB18_Pos)
#define CAN_F13R1_FB18         CAN_F13R1_FB18_Msk
#define CAN_F13R1_FB19_Pos     (19U)
#define CAN_F13R1_FB19_Msk     (0x1U << CAN_F13R1_FB19_Pos)
#define CAN_F13R1_FB19         CAN_F13R1_FB19_Msk
#define CAN_F13R1_FB20_Pos     (20U)
#define CAN_F13R1_FB20_Msk     (0x1U << CAN_F13R1_FB20_Pos)
#define CAN_F13R1_FB20         CAN_F13R1_FB20_Msk
#define CAN_F13R1_FB21_Pos     (21U)
#define CAN_F13R1_FB21_Msk     (0x1U << CAN_F13R1_FB21_Pos)
#define CAN_F13R1_FB21         CAN_F13R1_FB21_Msk
#define CAN_F13R1_FB22_Pos     (22U)
#define CAN_F13R1_FB22_Msk     (0x1U << CAN_F13R1_FB22_Pos)
#define CAN_F13R1_FB22         CAN_F13R1_FB22_Msk
#define CAN_F13R1_FB23_Pos     (23U)
#define CAN_F13R1_FB23_Msk     (0x1U << CAN_F13R1_FB23_Pos)
#define CAN_F13R1_FB23         CAN_F13R1_FB23_Msk
#define CAN_F13R1_FB24_Pos     (24U)
#define CAN_F13R1_FB24_Msk     (0x1U << CAN_F13R1_FB24_Pos)
#define CAN_F13R1_FB24         CAN_F13R1_FB24_Msk
#define CAN_F13R1_FB25_Pos     (25U)
#define CAN_F13R1_FB25_Msk     (0x1U << CAN_F13R1_FB25_Pos)
#define CAN_F13R1_FB25         CAN_F13R1_FB25_Msk
#define CAN_F13R1_FB26_Pos     (26U)
#define CAN_F13R1_FB26_Msk     (0x1U << CAN_F13R1_FB26_Pos)
#define CAN_F13R1_FB26         CAN_F13R1_FB26_Msk
#define CAN_F13R1_FB27_Pos     (27U)
#define CAN_F13R1_FB27_Msk     (0x1U << CAN_F13R1_FB27_Pos)
#define CAN_F13R1_FB27         CAN_F13R1_FB27_Msk
#define CAN_F13R1_FB28_Pos     (28U)
#define CAN_F13R1_FB28_Msk     (0x1U << CAN_F13R1_FB28_Pos)
#define CAN_F13R1_FB28         CAN_F13R1_FB28_Msk
#define CAN_F13R1_FB29_Pos     (29U)
#define CAN_F13R1_FB29_Msk     (0x1U << CAN_F13R1_FB29_Pos)
#define CAN_F13R1_FB29         CAN_F13R1_FB29_Msk
#define CAN_F13R1_FB30_Pos     (30U)
#define CAN_F13R1_FB30_Msk     (0x1U << CAN_F13R1_FB30_Pos)
#define CAN_F13R1_FB30         CAN_F13R1_FB30_Msk
#define CAN_F13R1_FB31_Pos     (31U)
#define CAN_F13R1_FB31_Msk     (0x1U << CAN_F13R1_FB31_Pos)
#define CAN_F13R1_FB31         CAN_F13R1_FB31_Msk


#define CAN_F0R2_FB0_Pos       (0U)
#define CAN_F0R2_FB0_Msk       (0x1U << CAN_F0R2_FB0_Pos)
#define CAN_F0R2_FB0           CAN_F0R2_FB0_Msk
#define CAN_F0R2_FB1_Pos       (1U)
#define CAN_F0R2_FB1_Msk       (0x1U << CAN_F0R2_FB1_Pos)
#define CAN_F0R2_FB1           CAN_F0R2_FB1_Msk
#define CAN_F0R2_FB2_Pos       (2U)
#define CAN_F0R2_FB2_Msk       (0x1U << CAN_F0R2_FB2_Pos)
#define CAN_F0R2_FB2           CAN_F0R2_FB2_Msk
#define CAN_F0R2_FB3_Pos       (3U)
#define CAN_F0R2_FB3_Msk       (0x1U << CAN_F0R2_FB3_Pos)
#define CAN_F0R2_FB3           CAN_F0R2_FB3_Msk
#define CAN_F0R2_FB4_Pos       (4U)
#define CAN_F0R2_FB4_Msk       (0x1U << CAN_F0R2_FB4_Pos)
#define CAN_F0R2_FB4           CAN_F0R2_FB4_Msk
#define CAN_F0R2_FB5_Pos       (5U)
#define CAN_F0R2_FB5_Msk       (0x1U << CAN_F0R2_FB5_Pos)
#define CAN_F0R2_FB5           CAN_F0R2_FB5_Msk
#define CAN_F0R2_FB6_Pos       (6U)
#define CAN_F0R2_FB6_Msk       (0x1U << CAN_F0R2_FB6_Pos)
#define CAN_F0R2_FB6           CAN_F0R2_FB6_Msk
#define CAN_F0R2_FB7_Pos       (7U)
#define CAN_F0R2_FB7_Msk       (0x1U << CAN_F0R2_FB7_Pos)
#define CAN_F0R2_FB7           CAN_F0R2_FB7_Msk
#define CAN_F0R2_FB8_Pos       (8U)
#define CAN_F0R2_FB8_Msk       (0x1U << CAN_F0R2_FB8_Pos)
#define CAN_F0R2_FB8           CAN_F0R2_FB8_Msk
#define CAN_F0R2_FB9_Pos       (9U)
#define CAN_F0R2_FB9_Msk       (0x1U << CAN_F0R2_FB9_Pos)
#define CAN_F0R2_FB9           CAN_F0R2_FB9_Msk
#define CAN_F0R2_FB10_Pos      (10U)
#define CAN_F0R2_FB10_Msk      (0x1U << CAN_F0R2_FB10_Pos)
#define CAN_F0R2_FB10          CAN_F0R2_FB10_Msk
#define CAN_F0R2_FB11_Pos      (11U)
#define CAN_F0R2_FB11_Msk      (0x1U << CAN_F0R2_FB11_Pos)
#define CAN_F0R2_FB11          CAN_F0R2_FB11_Msk
#define CAN_F0R2_FB12_Pos      (12U)
#define CAN_F0R2_FB12_Msk      (0x1U << CAN_F0R2_FB12_Pos)
#define CAN_F0R2_FB12          CAN_F0R2_FB12_Msk
#define CAN_F0R2_FB13_Pos      (13U)
#define CAN_F0R2_FB13_Msk      (0x1U << CAN_F0R2_FB13_Pos)
#define CAN_F0R2_FB13          CAN_F0R2_FB13_Msk
#define CAN_F0R2_FB14_Pos      (14U)
#define CAN_F0R2_FB14_Msk      (0x1U << CAN_F0R2_FB14_Pos)
#define CAN_F0R2_FB14          CAN_F0R2_FB14_Msk
#define CAN_F0R2_FB15_Pos      (15U)
#define CAN_F0R2_FB15_Msk      (0x1U << CAN_F0R2_FB15_Pos)
#define CAN_F0R2_FB15          CAN_F0R2_FB15_Msk
#define CAN_F0R2_FB16_Pos      (16U)
#define CAN_F0R2_FB16_Msk      (0x1U << CAN_F0R2_FB16_Pos)
#define CAN_F0R2_FB16          CAN_F0R2_FB16_Msk
#define CAN_F0R2_FB17_Pos      (17U)
#define CAN_F0R2_FB17_Msk      (0x1U << CAN_F0R2_FB17_Pos)
#define CAN_F0R2_FB17          CAN_F0R2_FB17_Msk
#define CAN_F0R2_FB18_Pos      (18U)
#define CAN_F0R2_FB18_Msk      (0x1U << CAN_F0R2_FB18_Pos)
#define CAN_F0R2_FB18          CAN_F0R2_FB18_Msk
#define CAN_F0R2_FB19_Pos      (19U)
#define CAN_F0R2_FB19_Msk      (0x1U << CAN_F0R2_FB19_Pos)
#define CAN_F0R2_FB19          CAN_F0R2_FB19_Msk
#define CAN_F0R2_FB20_Pos      (20U)
#define CAN_F0R2_FB20_Msk      (0x1U << CAN_F0R2_FB20_Pos)
#define CAN_F0R2_FB20          CAN_F0R2_FB20_Msk
#define CAN_F0R2_FB21_Pos      (21U)
#define CAN_F0R2_FB21_Msk      (0x1U << CAN_F0R2_FB21_Pos)
#define CAN_F0R2_FB21          CAN_F0R2_FB21_Msk
#define CAN_F0R2_FB22_Pos      (22U)
#define CAN_F0R2_FB22_Msk      (0x1U << CAN_F0R2_FB22_Pos)
#define CAN_F0R2_FB22          CAN_F0R2_FB22_Msk
#define CAN_F0R2_FB23_Pos      (23U)
#define CAN_F0R2_FB23_Msk      (0x1U << CAN_F0R2_FB23_Pos)
#define CAN_F0R2_FB23          CAN_F0R2_FB23_Msk
#define CAN_F0R2_FB24_Pos      (24U)
#define CAN_F0R2_FB24_Msk      (0x1U << CAN_F0R2_FB24_Pos)
#define CAN_F0R2_FB24          CAN_F0R2_FB24_Msk
#define CAN_F0R2_FB25_Pos      (25U)
#define CAN_F0R2_FB25_Msk      (0x1U << CAN_F0R2_FB25_Pos)
#define CAN_F0R2_FB25          CAN_F0R2_FB25_Msk
#define CAN_F0R2_FB26_Pos      (26U)
#define CAN_F0R2_FB26_Msk      (0x1U << CAN_F0R2_FB26_Pos)
#define CAN_F0R2_FB26          CAN_F0R2_FB26_Msk
#define CAN_F0R2_FB27_Pos      (27U)
#define CAN_F0R2_FB27_Msk      (0x1U << CAN_F0R2_FB27_Pos)
#define CAN_F0R2_FB27          CAN_F0R2_FB27_Msk
#define CAN_F0R2_FB28_Pos      (28U)
#define CAN_F0R2_FB28_Msk      (0x1U << CAN_F0R2_FB28_Pos)
#define CAN_F0R2_FB28          CAN_F0R2_FB28_Msk
#define CAN_F0R2_FB29_Pos      (29U)
#define CAN_F0R2_FB29_Msk      (0x1U << CAN_F0R2_FB29_Pos)
#define CAN_F0R2_FB29          CAN_F0R2_FB29_Msk
#define CAN_F0R2_FB30_Pos      (30U)
#define CAN_F0R2_FB30_Msk      (0x1U << CAN_F0R2_FB30_Pos)
#define CAN_F0R2_FB30          CAN_F0R2_FB30_Msk
#define CAN_F0R2_FB31_Pos      (31U)
#define CAN_F0R2_FB31_Msk      (0x1U << CAN_F0R2_FB31_Pos)
#define CAN_F0R2_FB31          CAN_F0R2_FB31_Msk


#define CAN_F1R2_FB0_Pos       (0U)
#define CAN_F1R2_FB0_Msk       (0x1U << CAN_F1R2_FB0_Pos)
#define CAN_F1R2_FB0           CAN_F1R2_FB0_Msk
#define CAN_F1R2_FB1_Pos       (1U)
#define CAN_F1R2_FB1_Msk       (0x1U << CAN_F1R2_FB1_Pos)
#define CAN_F1R2_FB1           CAN_F1R2_FB1_Msk
#define CAN_F1R2_FB2_Pos       (2U)
#define CAN_F1R2_FB2_Msk       (0x1U << CAN_F1R2_FB2_Pos)
#define CAN_F1R2_FB2           CAN_F1R2_FB2_Msk
#define CAN_F1R2_FB3_Pos       (3U)
#define CAN_F1R2_FB3_Msk       (0x1U << CAN_F1R2_FB3_Pos)
#define CAN_F1R2_FB3           CAN_F1R2_FB3_Msk
#define CAN_F1R2_FB4_Pos       (4U)
#define CAN_F1R2_FB4_Msk       (0x1U << CAN_F1R2_FB4_Pos)
#define CAN_F1R2_FB4           CAN_F1R2_FB4_Msk
#define CAN_F1R2_FB5_Pos       (5U)
#define CAN_F1R2_FB5_Msk       (0x1U << CAN_F1R2_FB5_Pos)
#define CAN_F1R2_FB5           CAN_F1R2_FB5_Msk
#define CAN_F1R2_FB6_Pos       (6U)
#define CAN_F1R2_FB6_Msk       (0x1U << CAN_F1R2_FB6_Pos)
#define CAN_F1R2_FB6           CAN_F1R2_FB6_Msk
#define CAN_F1R2_FB7_Pos       (7U)
#define CAN_F1R2_FB7_Msk       (0x1U << CAN_F1R2_FB7_Pos)
#define CAN_F1R2_FB7           CAN_F1R2_FB7_Msk
#define CAN_F1R2_FB8_Pos       (8U)
#define CAN_F1R2_FB8_Msk       (0x1U << CAN_F1R2_FB8_Pos)
#define CAN_F1R2_FB8           CAN_F1R2_FB8_Msk
#define CAN_F1R2_FB9_Pos       (9U)
#define CAN_F1R2_FB9_Msk       (0x1U << CAN_F1R2_FB9_Pos)
#define CAN_F1R2_FB9           CAN_F1R2_FB9_Msk
#define CAN_F1R2_FB10_Pos      (10U)
#define CAN_F1R2_FB10_Msk      (0x1U << CAN_F1R2_FB10_Pos)
#define CAN_F1R2_FB10          CAN_F1R2_FB10_Msk
#define CAN_F1R2_FB11_Pos      (11U)
#define CAN_F1R2_FB11_Msk      (0x1U << CAN_F1R2_FB11_Pos)
#define CAN_F1R2_FB11          CAN_F1R2_FB11_Msk
#define CAN_F1R2_FB12_Pos      (12U)
#define CAN_F1R2_FB12_Msk      (0x1U << CAN_F1R2_FB12_Pos)
#define CAN_F1R2_FB12          CAN_F1R2_FB12_Msk
#define CAN_F1R2_FB13_Pos      (13U)
#define CAN_F1R2_FB13_Msk      (0x1U << CAN_F1R2_FB13_Pos)
#define CAN_F1R2_FB13          CAN_F1R2_FB13_Msk
#define CAN_F1R2_FB14_Pos      (14U)
#define CAN_F1R2_FB14_Msk      (0x1U << CAN_F1R2_FB14_Pos)
#define CAN_F1R2_FB14          CAN_F1R2_FB14_Msk
#define CAN_F1R2_FB15_Pos      (15U)
#define CAN_F1R2_FB15_Msk      (0x1U << CAN_F1R2_FB15_Pos)
#define CAN_F1R2_FB15          CAN_F1R2_FB15_Msk
#define CAN_F1R2_FB16_Pos      (16U)
#define CAN_F1R2_FB16_Msk      (0x1U << CAN_F1R2_FB16_Pos)
#define CAN_F1R2_FB16          CAN_F1R2_FB16_Msk
#define CAN_F1R2_FB17_Pos      (17U)
#define CAN_F1R2_FB17_Msk      (0x1U << CAN_F1R2_FB17_Pos)
#define CAN_F1R2_FB17          CAN_F1R2_FB17_Msk
#define CAN_F1R2_FB18_Pos      (18U)
#define CAN_F1R2_FB18_Msk      (0x1U << CAN_F1R2_FB18_Pos)
#define CAN_F1R2_FB18          CAN_F1R2_FB18_Msk
#define CAN_F1R2_FB19_Pos      (19U)
#define CAN_F1R2_FB19_Msk      (0x1U << CAN_F1R2_FB19_Pos)
#define CAN_F1R2_FB19          CAN_F1R2_FB19_Msk
#define CAN_F1R2_FB20_Pos      (20U)
#define CAN_F1R2_FB20_Msk      (0x1U << CAN_F1R2_FB20_Pos)
#define CAN_F1R2_FB20          CAN_F1R2_FB20_Msk
#define CAN_F1R2_FB21_Pos      (21U)
#define CAN_F1R2_FB21_Msk      (0x1U << CAN_F1R2_FB21_Pos)
#define CAN_F1R2_FB21          CAN_F1R2_FB21_Msk
#define CAN_F1R2_FB22_Pos      (22U)
#define CAN_F1R2_FB22_Msk      (0x1U << CAN_F1R2_FB22_Pos)
#define CAN_F1R2_FB22          CAN_F1R2_FB22_Msk
#define CAN_F1R2_FB23_Pos      (23U)
#define CAN_F1R2_FB23_Msk      (0x1U << CAN_F1R2_FB23_Pos)
#define CAN_F1R2_FB23          CAN_F1R2_FB23_Msk
#define CAN_F1R2_FB24_Pos      (24U)
#define CAN_F1R2_FB24_Msk      (0x1U << CAN_F1R2_FB24_Pos)
#define CAN_F1R2_FB24          CAN_F1R2_FB24_Msk
#define CAN_F1R2_FB25_Pos      (25U)
#define CAN_F1R2_FB25_Msk      (0x1U << CAN_F1R2_FB25_Pos)
#define CAN_F1R2_FB25          CAN_F1R2_FB25_Msk
#define CAN_F1R2_FB26_Pos      (26U)
#define CAN_F1R2_FB26_Msk      (0x1U << CAN_F1R2_FB26_Pos)
#define CAN_F1R2_FB26          CAN_F1R2_FB26_Msk
#define CAN_F1R2_FB27_Pos      (27U)
#define CAN_F1R2_FB27_Msk      (0x1U << CAN_F1R2_FB27_Pos)
#define CAN_F1R2_FB27          CAN_F1R2_FB27_Msk
#define CAN_F1R2_FB28_Pos      (28U)
#define CAN_F1R2_FB28_Msk      (0x1U << CAN_F1R2_FB28_Pos)
#define CAN_F1R2_FB28          CAN_F1R2_FB28_Msk
#define CAN_F1R2_FB29_Pos      (29U)
#define CAN_F1R2_FB29_Msk      (0x1U << CAN_F1R2_FB29_Pos)
#define CAN_F1R2_FB29          CAN_F1R2_FB29_Msk
#define CAN_F1R2_FB30_Pos      (30U)
#define CAN_F1R2_FB30_Msk      (0x1U << CAN_F1R2_FB30_Pos)
#define CAN_F1R2_FB30          CAN_F1R2_FB30_Msk
#define CAN_F1R2_FB31_Pos      (31U)
#define CAN_F1R2_FB31_Msk      (0x1U << CAN_F1R2_FB31_Pos)
#define CAN_F1R2_FB31          CAN_F1R2_FB31_Msk


#define CAN_F2R2_FB0_Pos       (0U)
#define CAN_F2R2_FB0_Msk       (0x1U << CAN_F2R2_FB0_Pos)
#define CAN_F2R2_FB0           CAN_F2R2_FB0_Msk
#define CAN_F2R2_FB1_Pos       (1U)
#define CAN_F2R2_FB1_Msk       (0x1U << CAN_F2R2_FB1_Pos)
#define CAN_F2R2_FB1           CAN_F2R2_FB1_Msk
#define CAN_F2R2_FB2_Pos       (2U)
#define CAN_F2R2_FB2_Msk       (0x1U << CAN_F2R2_FB2_Pos)
#define CAN_F2R2_FB2           CAN_F2R2_FB2_Msk
#define CAN_F2R2_FB3_Pos       (3U)
#define CAN_F2R2_FB3_Msk       (0x1U << CAN_F2R2_FB3_Pos)
#define CAN_F2R2_FB3           CAN_F2R2_FB3_Msk
#define CAN_F2R2_FB4_Pos       (4U)
#define CAN_F2R2_FB4_Msk       (0x1U << CAN_F2R2_FB4_Pos)
#define CAN_F2R2_FB4           CAN_F2R2_FB4_Msk
#define CAN_F2R2_FB5_Pos       (5U)
#define CAN_F2R2_FB5_Msk       (0x1U << CAN_F2R2_FB5_Pos)
#define CAN_F2R2_FB5           CAN_F2R2_FB5_Msk
#define CAN_F2R2_FB6_Pos       (6U)
#define CAN_F2R2_FB6_Msk       (0x1U << CAN_F2R2_FB6_Pos)
#define CAN_F2R2_FB6           CAN_F2R2_FB6_Msk
#define CAN_F2R2_FB7_Pos       (7U)
#define CAN_F2R2_FB7_Msk       (0x1U << CAN_F2R2_FB7_Pos)
#define CAN_F2R2_FB7           CAN_F2R2_FB7_Msk
#define CAN_F2R2_FB8_Pos       (8U)
#define CAN_F2R2_FB8_Msk       (0x1U << CAN_F2R2_FB8_Pos)
#define CAN_F2R2_FB8           CAN_F2R2_FB8_Msk
#define CAN_F2R2_FB9_Pos       (9U)
#define CAN_F2R2_FB9_Msk       (0x1U << CAN_F2R2_FB9_Pos)
#define CAN_F2R2_FB9           CAN_F2R2_FB9_Msk
#define CAN_F2R2_FB10_Pos      (10U)
#define CAN_F2R2_FB10_Msk      (0x1U << CAN_F2R2_FB10_Pos)
#define CAN_F2R2_FB10          CAN_F2R2_FB10_Msk
#define CAN_F2R2_FB11_Pos      (11U)
#define CAN_F2R2_FB11_Msk      (0x1U << CAN_F2R2_FB11_Pos)
#define CAN_F2R2_FB11          CAN_F2R2_FB11_Msk
#define CAN_F2R2_FB12_Pos      (12U)
#define CAN_F2R2_FB12_Msk      (0x1U << CAN_F2R2_FB12_Pos)
#define CAN_F2R2_FB12          CAN_F2R2_FB12_Msk
#define CAN_F2R2_FB13_Pos      (13U)
#define CAN_F2R2_FB13_Msk      (0x1U << CAN_F2R2_FB13_Pos)
#define CAN_F2R2_FB13          CAN_F2R2_FB13_Msk
#define CAN_F2R2_FB14_Pos      (14U)
#define CAN_F2R2_FB14_Msk      (0x1U << CAN_F2R2_FB14_Pos)
#define CAN_F2R2_FB14          CAN_F2R2_FB14_Msk
#define CAN_F2R2_FB15_Pos      (15U)
#define CAN_F2R2_FB15_Msk      (0x1U << CAN_F2R2_FB15_Pos)
#define CAN_F2R2_FB15          CAN_F2R2_FB15_Msk
#define CAN_F2R2_FB16_Pos      (16U)
#define CAN_F2R2_FB16_Msk      (0x1U << CAN_F2R2_FB16_Pos)
#define CAN_F2R2_FB16          CAN_F2R2_FB16_Msk
#define CAN_F2R2_FB17_Pos      (17U)
#define CAN_F2R2_FB17_Msk      (0x1U << CAN_F2R2_FB17_Pos)
#define CAN_F2R2_FB17          CAN_F2R2_FB17_Msk
#define CAN_F2R2_FB18_Pos      (18U)
#define CAN_F2R2_FB18_Msk      (0x1U << CAN_F2R2_FB18_Pos)
#define CAN_F2R2_FB18          CAN_F2R2_FB18_Msk
#define CAN_F2R2_FB19_Pos      (19U)
#define CAN_F2R2_FB19_Msk      (0x1U << CAN_F2R2_FB19_Pos)
#define CAN_F2R2_FB19          CAN_F2R2_FB19_Msk
#define CAN_F2R2_FB20_Pos      (20U)
#define CAN_F2R2_FB20_Msk      (0x1U << CAN_F2R2_FB20_Pos)
#define CAN_F2R2_FB20          CAN_F2R2_FB20_Msk
#define CAN_F2R2_FB21_Pos      (21U)
#define CAN_F2R2_FB21_Msk      (0x1U << CAN_F2R2_FB21_Pos)
#define CAN_F2R2_FB21          CAN_F2R2_FB21_Msk
#define CAN_F2R2_FB22_Pos      (22U)
#define CAN_F2R2_FB22_Msk      (0x1U << CAN_F2R2_FB22_Pos)
#define CAN_F2R2_FB22          CAN_F2R2_FB22_Msk
#define CAN_F2R2_FB23_Pos      (23U)
#define CAN_F2R2_FB23_Msk      (0x1U << CAN_F2R2_FB23_Pos)
#define CAN_F2R2_FB23          CAN_F2R2_FB23_Msk
#define CAN_F2R2_FB24_Pos      (24U)
#define CAN_F2R2_FB24_Msk      (0x1U << CAN_F2R2_FB24_Pos)
#define CAN_F2R2_FB24          CAN_F2R2_FB24_Msk
#define CAN_F2R2_FB25_Pos      (25U)
#define CAN_F2R2_FB25_Msk      (0x1U << CAN_F2R2_FB25_Pos)
#define CAN_F2R2_FB25          CAN_F2R2_FB25_Msk
#define CAN_F2R2_FB26_Pos      (26U)
#define CAN_F2R2_FB26_Msk      (0x1U << CAN_F2R2_FB26_Pos)
#define CAN_F2R2_FB26          CAN_F2R2_FB26_Msk
#define CAN_F2R2_FB27_Pos      (27U)
#define CAN_F2R2_FB27_Msk      (0x1U << CAN_F2R2_FB27_Pos)
#define CAN_F2R2_FB27          CAN_F2R2_FB27_Msk
#define CAN_F2R2_FB28_Pos      (28U)
#define CAN_F2R2_FB28_Msk      (0x1U << CAN_F2R2_FB28_Pos)
#define CAN_F2R2_FB28          CAN_F2R2_FB28_Msk
#define CAN_F2R2_FB29_Pos      (29U)
#define CAN_F2R2_FB29_Msk      (0x1U << CAN_F2R2_FB29_Pos)
#define CAN_F2R2_FB29          CAN_F2R2_FB29_Msk
#define CAN_F2R2_FB30_Pos      (30U)
#define CAN_F2R2_FB30_Msk      (0x1U << CAN_F2R2_FB30_Pos)
#define CAN_F2R2_FB30          CAN_F2R2_FB30_Msk
#define CAN_F2R2_FB31_Pos      (31U)
#define CAN_F2R2_FB31_Msk      (0x1U << CAN_F2R2_FB31_Pos)
#define CAN_F2R2_FB31          CAN_F2R2_FB31_Msk


#define CAN_F3R2_FB0_Pos       (0U)
#define CAN_F3R2_FB0_Msk       (0x1U << CAN_F3R2_FB0_Pos)
#define CAN_F3R2_FB0           CAN_F3R2_FB0_Msk
#define CAN_F3R2_FB1_Pos       (1U)
#define CAN_F3R2_FB1_Msk       (0x1U << CAN_F3R2_FB1_Pos)
#define CAN_F3R2_FB1           CAN_F3R2_FB1_Msk
#define CAN_F3R2_FB2_Pos       (2U)
#define CAN_F3R2_FB2_Msk       (0x1U << CAN_F3R2_FB2_Pos)
#define CAN_F3R2_FB2           CAN_F3R2_FB2_Msk
#define CAN_F3R2_FB3_Pos       (3U)
#define CAN_F3R2_FB3_Msk       (0x1U << CAN_F3R2_FB3_Pos)
#define CAN_F3R2_FB3           CAN_F3R2_FB3_Msk
#define CAN_F3R2_FB4_Pos       (4U)
#define CAN_F3R2_FB4_Msk       (0x1U << CAN_F3R2_FB4_Pos)
#define CAN_F3R2_FB4           CAN_F3R2_FB4_Msk
#define CAN_F3R2_FB5_Pos       (5U)
#define CAN_F3R2_FB5_Msk       (0x1U << CAN_F3R2_FB5_Pos)
#define CAN_F3R2_FB5           CAN_F3R2_FB5_Msk
#define CAN_F3R2_FB6_Pos       (6U)
#define CAN_F3R2_FB6_Msk       (0x1U << CAN_F3R2_FB6_Pos)
#define CAN_F3R2_FB6           CAN_F3R2_FB6_Msk
#define CAN_F3R2_FB7_Pos       (7U)
#define CAN_F3R2_FB7_Msk       (0x1U << CAN_F3R2_FB7_Pos)
#define CAN_F3R2_FB7           CAN_F3R2_FB7_Msk
#define CAN_F3R2_FB8_Pos       (8U)
#define CAN_F3R2_FB8_Msk       (0x1U << CAN_F3R2_FB8_Pos)
#define CAN_F3R2_FB8           CAN_F3R2_FB8_Msk
#define CAN_F3R2_FB9_Pos       (9U)
#define CAN_F3R2_FB9_Msk       (0x1U << CAN_F3R2_FB9_Pos)
#define CAN_F3R2_FB9           CAN_F3R2_FB9_Msk
#define CAN_F3R2_FB10_Pos      (10U)
#define CAN_F3R2_FB10_Msk      (0x1U << CAN_F3R2_FB10_Pos)
#define CAN_F3R2_FB10          CAN_F3R2_FB10_Msk
#define CAN_F3R2_FB11_Pos      (11U)
#define CAN_F3R2_FB11_Msk      (0x1U << CAN_F3R2_FB11_Pos)
#define CAN_F3R2_FB11          CAN_F3R2_FB11_Msk
#define CAN_F3R2_FB12_Pos      (12U)
#define CAN_F3R2_FB12_Msk      (0x1U << CAN_F3R2_FB12_Pos)
#define CAN_F3R2_FB12          CAN_F3R2_FB12_Msk
#define CAN_F3R2_FB13_Pos      (13U)
#define CAN_F3R2_FB13_Msk      (0x1U << CAN_F3R2_FB13_Pos)
#define CAN_F3R2_FB13          CAN_F3R2_FB13_Msk
#define CAN_F3R2_FB14_Pos      (14U)
#define CAN_F3R2_FB14_Msk      (0x1U << CAN_F3R2_FB14_Pos)
#define CAN_F3R2_FB14          CAN_F3R2_FB14_Msk
#define CAN_F3R2_FB15_Pos      (15U)
#define CAN_F3R2_FB15_Msk      (0x1U << CAN_F3R2_FB15_Pos)
#define CAN_F3R2_FB15          CAN_F3R2_FB15_Msk
#define CAN_F3R2_FB16_Pos      (16U)
#define CAN_F3R2_FB16_Msk      (0x1U << CAN_F3R2_FB16_Pos)
#define CAN_F3R2_FB16          CAN_F3R2_FB16_Msk
#define CAN_F3R2_FB17_Pos      (17U)
#define CAN_F3R2_FB17_Msk      (0x1U << CAN_F3R2_FB17_Pos)
#define CAN_F3R2_FB17          CAN_F3R2_FB17_Msk
#define CAN_F3R2_FB18_Pos      (18U)
#define CAN_F3R2_FB18_Msk      (0x1U << CAN_F3R2_FB18_Pos)
#define CAN_F3R2_FB18          CAN_F3R2_FB18_Msk
#define CAN_F3R2_FB19_Pos      (19U)
#define CAN_F3R2_FB19_Msk      (0x1U << CAN_F3R2_FB19_Pos)
#define CAN_F3R2_FB19          CAN_F3R2_FB19_Msk
#define CAN_F3R2_FB20_Pos      (20U)
#define CAN_F3R2_FB20_Msk      (0x1U << CAN_F3R2_FB20_Pos)
#define CAN_F3R2_FB20          CAN_F3R2_FB20_Msk
#define CAN_F3R2_FB21_Pos      (21U)
#define CAN_F3R2_FB21_Msk      (0x1U << CAN_F3R2_FB21_Pos)
#define CAN_F3R2_FB21          CAN_F3R2_FB21_Msk
#define CAN_F3R2_FB22_Pos      (22U)
#define CAN_F3R2_FB22_Msk      (0x1U << CAN_F3R2_FB22_Pos)
#define CAN_F3R2_FB22          CAN_F3R2_FB22_Msk
#define CAN_F3R2_FB23_Pos      (23U)
#define CAN_F3R2_FB23_Msk      (0x1U << CAN_F3R2_FB23_Pos)
#define CAN_F3R2_FB23          CAN_F3R2_FB23_Msk
#define CAN_F3R2_FB24_Pos      (24U)
#define CAN_F3R2_FB24_Msk      (0x1U << CAN_F3R2_FB24_Pos)
#define CAN_F3R2_FB24          CAN_F3R2_FB24_Msk
#define CAN_F3R2_FB25_Pos      (25U)
#define CAN_F3R2_FB25_Msk      (0x1U << CAN_F3R2_FB25_Pos)
#define CAN_F3R2_FB25          CAN_F3R2_FB25_Msk
#define CAN_F3R2_FB26_Pos      (26U)
#define CAN_F3R2_FB26_Msk      (0x1U << CAN_F3R2_FB26_Pos)
#define CAN_F3R2_FB26          CAN_F3R2_FB26_Msk
#define CAN_F3R2_FB27_Pos      (27U)
#define CAN_F3R2_FB27_Msk      (0x1U << CAN_F3R2_FB27_Pos)
#define CAN_F3R2_FB27          CAN_F3R2_FB27_Msk
#define CAN_F3R2_FB28_Pos      (28U)
#define CAN_F3R2_FB28_Msk      (0x1U << CAN_F3R2_FB28_Pos)
#define CAN_F3R2_FB28          CAN_F3R2_FB28_Msk
#define CAN_F3R2_FB29_Pos      (29U)
#define CAN_F3R2_FB29_Msk      (0x1U << CAN_F3R2_FB29_Pos)
#define CAN_F3R2_FB29          CAN_F3R2_FB29_Msk
#define CAN_F3R2_FB30_Pos      (30U)
#define CAN_F3R2_FB30_Msk      (0x1U << CAN_F3R2_FB30_Pos)
#define CAN_F3R2_FB30          CAN_F3R2_FB30_Msk
#define CAN_F3R2_FB31_Pos      (31U)
#define CAN_F3R2_FB31_Msk      (0x1U << CAN_F3R2_FB31_Pos)
#define CAN_F3R2_FB31          CAN_F3R2_FB31_Msk


#define CAN_F4R2_FB0_Pos       (0U)
#define CAN_F4R2_FB0_Msk       (0x1U << CAN_F4R2_FB0_Pos)
#define CAN_F4R2_FB0           CAN_F4R2_FB0_Msk
#define CAN_F4R2_FB1_Pos       (1U)
#define CAN_F4R2_FB1_Msk       (0x1U << CAN_F4R2_FB1_Pos)
#define CAN_F4R2_FB1           CAN_F4R2_FB1_Msk
#define CAN_F4R2_FB2_Pos       (2U)
#define CAN_F4R2_FB2_Msk       (0x1U << CAN_F4R2_FB2_Pos)
#define CAN_F4R2_FB2           CAN_F4R2_FB2_Msk
#define CAN_F4R2_FB3_Pos       (3U)
#define CAN_F4R2_FB3_Msk       (0x1U << CAN_F4R2_FB3_Pos)
#define CAN_F4R2_FB3           CAN_F4R2_FB3_Msk
#define CAN_F4R2_FB4_Pos       (4U)
#define CAN_F4R2_FB4_Msk       (0x1U << CAN_F4R2_FB4_Pos)
#define CAN_F4R2_FB4           CAN_F4R2_FB4_Msk
#define CAN_F4R2_FB5_Pos       (5U)
#define CAN_F4R2_FB5_Msk       (0x1U << CAN_F4R2_FB5_Pos)
#define CAN_F4R2_FB5           CAN_F4R2_FB5_Msk
#define CAN_F4R2_FB6_Pos       (6U)
#define CAN_F4R2_FB6_Msk       (0x1U << CAN_F4R2_FB6_Pos)
#define CAN_F4R2_FB6           CAN_F4R2_FB6_Msk
#define CAN_F4R2_FB7_Pos       (7U)
#define CAN_F4R2_FB7_Msk       (0x1U << CAN_F4R2_FB7_Pos)
#define CAN_F4R2_FB7           CAN_F4R2_FB7_Msk
#define CAN_F4R2_FB8_Pos       (8U)
#define CAN_F4R2_FB8_Msk       (0x1U << CAN_F4R2_FB8_Pos)
#define CAN_F4R2_FB8           CAN_F4R2_FB8_Msk
#define CAN_F4R2_FB9_Pos       (9U)
#define CAN_F4R2_FB9_Msk       (0x1U << CAN_F4R2_FB9_Pos)
#define CAN_F4R2_FB9           CAN_F4R2_FB9_Msk
#define CAN_F4R2_FB10_Pos      (10U)
#define CAN_F4R2_FB10_Msk      (0x1U << CAN_F4R2_FB10_Pos)
#define CAN_F4R2_FB10          CAN_F4R2_FB10_Msk
#define CAN_F4R2_FB11_Pos      (11U)
#define CAN_F4R2_FB11_Msk      (0x1U << CAN_F4R2_FB11_Pos)
#define CAN_F4R2_FB11          CAN_F4R2_FB11_Msk
#define CAN_F4R2_FB12_Pos      (12U)
#define CAN_F4R2_FB12_Msk      (0x1U << CAN_F4R2_FB12_Pos)
#define CAN_F4R2_FB12          CAN_F4R2_FB12_Msk
#define CAN_F4R2_FB13_Pos      (13U)
#define CAN_F4R2_FB13_Msk      (0x1U << CAN_F4R2_FB13_Pos)
#define CAN_F4R2_FB13          CAN_F4R2_FB13_Msk
#define CAN_F4R2_FB14_Pos      (14U)
#define CAN_F4R2_FB14_Msk      (0x1U << CAN_F4R2_FB14_Pos)
#define CAN_F4R2_FB14          CAN_F4R2_FB14_Msk
#define CAN_F4R2_FB15_Pos      (15U)
#define CAN_F4R2_FB15_Msk      (0x1U << CAN_F4R2_FB15_Pos)
#define CAN_F4R2_FB15          CAN_F4R2_FB15_Msk
#define CAN_F4R2_FB16_Pos      (16U)
#define CAN_F4R2_FB16_Msk      (0x1U << CAN_F4R2_FB16_Pos)
#define CAN_F4R2_FB16          CAN_F4R2_FB16_Msk
#define CAN_F4R2_FB17_Pos      (17U)
#define CAN_F4R2_FB17_Msk      (0x1U << CAN_F4R2_FB17_Pos)
#define CAN_F4R2_FB17          CAN_F4R2_FB17_Msk
#define CAN_F4R2_FB18_Pos      (18U)
#define CAN_F4R2_FB18_Msk      (0x1U << CAN_F4R2_FB18_Pos)
#define CAN_F4R2_FB18          CAN_F4R2_FB18_Msk
#define CAN_F4R2_FB19_Pos      (19U)
#define CAN_F4R2_FB19_Msk      (0x1U << CAN_F4R2_FB19_Pos)
#define CAN_F4R2_FB19          CAN_F4R2_FB19_Msk
#define CAN_F4R2_FB20_Pos      (20U)
#define CAN_F4R2_FB20_Msk      (0x1U << CAN_F4R2_FB20_Pos)
#define CAN_F4R2_FB20          CAN_F4R2_FB20_Msk
#define CAN_F4R2_FB21_Pos      (21U)
#define CAN_F4R2_FB21_Msk      (0x1U << CAN_F4R2_FB21_Pos)
#define CAN_F4R2_FB21          CAN_F4R2_FB21_Msk
#define CAN_F4R2_FB22_Pos      (22U)
#define CAN_F4R2_FB22_Msk      (0x1U << CAN_F4R2_FB22_Pos)
#define CAN_F4R2_FB22          CAN_F4R2_FB22_Msk
#define CAN_F4R2_FB23_Pos      (23U)
#define CAN_F4R2_FB23_Msk      (0x1U << CAN_F4R2_FB23_Pos)
#define CAN_F4R2_FB23          CAN_F4R2_FB23_Msk
#define CAN_F4R2_FB24_Pos      (24U)
#define CAN_F4R2_FB24_Msk      (0x1U << CAN_F4R2_FB24_Pos)
#define CAN_F4R2_FB24          CAN_F4R2_FB24_Msk
#define CAN_F4R2_FB25_Pos      (25U)
#define CAN_F4R2_FB25_Msk      (0x1U << CAN_F4R2_FB25_Pos)
#define CAN_F4R2_FB25          CAN_F4R2_FB25_Msk
#define CAN_F4R2_FB26_Pos      (26U)
#define CAN_F4R2_FB26_Msk      (0x1U << CAN_F4R2_FB26_Pos)
#define CAN_F4R2_FB26          CAN_F4R2_FB26_Msk
#define CAN_F4R2_FB27_Pos      (27U)
#define CAN_F4R2_FB27_Msk      (0x1U << CAN_F4R2_FB27_Pos)
#define CAN_F4R2_FB27          CAN_F4R2_FB27_Msk
#define CAN_F4R2_FB28_Pos      (28U)
#define CAN_F4R2_FB28_Msk      (0x1U << CAN_F4R2_FB28_Pos)
#define CAN_F4R2_FB28          CAN_F4R2_FB28_Msk
#define CAN_F4R2_FB29_Pos      (29U)
#define CAN_F4R2_FB29_Msk      (0x1U << CAN_F4R2_FB29_Pos)
#define CAN_F4R2_FB29          CAN_F4R2_FB29_Msk
#define CAN_F4R2_FB30_Pos      (30U)
#define CAN_F4R2_FB30_Msk      (0x1U << CAN_F4R2_FB30_Pos)
#define CAN_F4R2_FB30          CAN_F4R2_FB30_Msk
#define CAN_F4R2_FB31_Pos      (31U)
#define CAN_F4R2_FB31_Msk      (0x1U << CAN_F4R2_FB31_Pos)
#define CAN_F4R2_FB31          CAN_F4R2_FB31_Msk


#define CAN_F5R2_FB0_Pos       (0U)
#define CAN_F5R2_FB0_Msk       (0x1U << CAN_F5R2_FB0_Pos)
#define CAN_F5R2_FB0           CAN_F5R2_FB0_Msk
#define CAN_F5R2_FB1_Pos       (1U)
#define CAN_F5R2_FB1_Msk       (0x1U << CAN_F5R2_FB1_Pos)
#define CAN_F5R2_FB1           CAN_F5R2_FB1_Msk
#define CAN_F5R2_FB2_Pos       (2U)
#define CAN_F5R2_FB2_Msk       (0x1U << CAN_F5R2_FB2_Pos)
#define CAN_F5R2_FB2           CAN_F5R2_FB2_Msk
#define CAN_F5R2_FB3_Pos       (3U)
#define CAN_F5R2_FB3_Msk       (0x1U << CAN_F5R2_FB3_Pos)
#define CAN_F5R2_FB3           CAN_F5R2_FB3_Msk
#define CAN_F5R2_FB4_Pos       (4U)
#define CAN_F5R2_FB4_Msk       (0x1U << CAN_F5R2_FB4_Pos)
#define CAN_F5R2_FB4           CAN_F5R2_FB4_Msk
#define CAN_F5R2_FB5_Pos       (5U)
#define CAN_F5R2_FB5_Msk       (0x1U << CAN_F5R2_FB5_Pos)
#define CAN_F5R2_FB5           CAN_F5R2_FB5_Msk
#define CAN_F5R2_FB6_Pos       (6U)
#define CAN_F5R2_FB6_Msk       (0x1U << CAN_F5R2_FB6_Pos)
#define CAN_F5R2_FB6           CAN_F5R2_FB6_Msk
#define CAN_F5R2_FB7_Pos       (7U)
#define CAN_F5R2_FB7_Msk       (0x1U << CAN_F5R2_FB7_Pos)
#define CAN_F5R2_FB7           CAN_F5R2_FB7_Msk
#define CAN_F5R2_FB8_Pos       (8U)
#define CAN_F5R2_FB8_Msk       (0x1U << CAN_F5R2_FB8_Pos)
#define CAN_F5R2_FB8           CAN_F5R2_FB8_Msk
#define CAN_F5R2_FB9_Pos       (9U)
#define CAN_F5R2_FB9_Msk       (0x1U << CAN_F5R2_FB9_Pos)
#define CAN_F5R2_FB9           CAN_F5R2_FB9_Msk
#define CAN_F5R2_FB10_Pos      (10U)
#define CAN_F5R2_FB10_Msk      (0x1U << CAN_F5R2_FB10_Pos)
#define CAN_F5R2_FB10          CAN_F5R2_FB10_Msk
#define CAN_F5R2_FB11_Pos      (11U)
#define CAN_F5R2_FB11_Msk      (0x1U << CAN_F5R2_FB11_Pos)
#define CAN_F5R2_FB11          CAN_F5R2_FB11_Msk
#define CAN_F5R2_FB12_Pos      (12U)
#define CAN_F5R2_FB12_Msk      (0x1U << CAN_F5R2_FB12_Pos)
#define CAN_F5R2_FB12          CAN_F5R2_FB12_Msk
#define CAN_F5R2_FB13_Pos      (13U)
#define CAN_F5R2_FB13_Msk      (0x1U << CAN_F5R2_FB13_Pos)
#define CAN_F5R2_FB13          CAN_F5R2_FB13_Msk
#define CAN_F5R2_FB14_Pos      (14U)
#define CAN_F5R2_FB14_Msk      (0x1U << CAN_F5R2_FB14_Pos)
#define CAN_F5R2_FB14          CAN_F5R2_FB14_Msk
#define CAN_F5R2_FB15_Pos      (15U)
#define CAN_F5R2_FB15_Msk      (0x1U << CAN_F5R2_FB15_Pos)
#define CAN_F5R2_FB15          CAN_F5R2_FB15_Msk
#define CAN_F5R2_FB16_Pos      (16U)
#define CAN_F5R2_FB16_Msk      (0x1U << CAN_F5R2_FB16_Pos)
#define CAN_F5R2_FB16          CAN_F5R2_FB16_Msk
#define CAN_F5R2_FB17_Pos      (17U)
#define CAN_F5R2_FB17_Msk      (0x1U << CAN_F5R2_FB17_Pos)
#define CAN_F5R2_FB17          CAN_F5R2_FB17_Msk
#define CAN_F5R2_FB18_Pos      (18U)
#define CAN_F5R2_FB18_Msk      (0x1U << CAN_F5R2_FB18_Pos)
#define CAN_F5R2_FB18          CAN_F5R2_FB18_Msk
#define CAN_F5R2_FB19_Pos      (19U)
#define CAN_F5R2_FB19_Msk      (0x1U << CAN_F5R2_FB19_Pos)
#define CAN_F5R2_FB19          CAN_F5R2_FB19_Msk
#define CAN_F5R2_FB20_Pos      (20U)
#define CAN_F5R2_FB20_Msk      (0x1U << CAN_F5R2_FB20_Pos)
#define CAN_F5R2_FB20          CAN_F5R2_FB20_Msk
#define CAN_F5R2_FB21_Pos      (21U)
#define CAN_F5R2_FB21_Msk      (0x1U << CAN_F5R2_FB21_Pos)
#define CAN_F5R2_FB21          CAN_F5R2_FB21_Msk
#define CAN_F5R2_FB22_Pos      (22U)
#define CAN_F5R2_FB22_Msk      (0x1U << CAN_F5R2_FB22_Pos)
#define CAN_F5R2_FB22          CAN_F5R2_FB22_Msk
#define CAN_F5R2_FB23_Pos      (23U)
#define CAN_F5R2_FB23_Msk      (0x1U << CAN_F5R2_FB23_Pos)
#define CAN_F5R2_FB23          CAN_F5R2_FB23_Msk
#define CAN_F5R2_FB24_Pos      (24U)
#define CAN_F5R2_FB24_Msk      (0x1U << CAN_F5R2_FB24_Pos)
#define CAN_F5R2_FB24          CAN_F5R2_FB24_Msk
#define CAN_F5R2_FB25_Pos      (25U)
#define CAN_F5R2_FB25_Msk      (0x1U << CAN_F5R2_FB25_Pos)
#define CAN_F5R2_FB25          CAN_F5R2_FB25_Msk
#define CAN_F5R2_FB26_Pos      (26U)
#define CAN_F5R2_FB26_Msk      (0x1U << CAN_F5R2_FB26_Pos)
#define CAN_F5R2_FB26          CAN_F5R2_FB26_Msk
#define CAN_F5R2_FB27_Pos      (27U)
#define CAN_F5R2_FB27_Msk      (0x1U << CAN_F5R2_FB27_Pos)
#define CAN_F5R2_FB27          CAN_F5R2_FB27_Msk
#define CAN_F5R2_FB28_Pos      (28U)
#define CAN_F5R2_FB28_Msk      (0x1U << CAN_F5R2_FB28_Pos)
#define CAN_F5R2_FB28          CAN_F5R2_FB28_Msk
#define CAN_F5R2_FB29_Pos      (29U)
#define CAN_F5R2_FB29_Msk      (0x1U << CAN_F5R2_FB29_Pos)
#define CAN_F5R2_FB29          CAN_F5R2_FB29_Msk
#define CAN_F5R2_FB30_Pos      (30U)
#define CAN_F5R2_FB30_Msk      (0x1U << CAN_F5R2_FB30_Pos)
#define CAN_F5R2_FB30          CAN_F5R2_FB30_Msk
#define CAN_F5R2_FB31_Pos      (31U)
#define CAN_F5R2_FB31_Msk      (0x1U << CAN_F5R2_FB31_Pos)
#define CAN_F5R2_FB31          CAN_F5R2_FB31_Msk


#define CAN_F6R2_FB0_Pos       (0U)
#define CAN_F6R2_FB0_Msk       (0x1U << CAN_F6R2_FB0_Pos)
#define CAN_F6R2_FB0           CAN_F6R2_FB0_Msk
#define CAN_F6R2_FB1_Pos       (1U)
#define CAN_F6R2_FB1_Msk       (0x1U << CAN_F6R2_FB1_Pos)
#define CAN_F6R2_FB1           CAN_F6R2_FB1_Msk
#define CAN_F6R2_FB2_Pos       (2U)
#define CAN_F6R2_FB2_Msk       (0x1U << CAN_F6R2_FB2_Pos)
#define CAN_F6R2_FB2           CAN_F6R2_FB2_Msk
#define CAN_F6R2_FB3_Pos       (3U)
#define CAN_F6R2_FB3_Msk       (0x1U << CAN_F6R2_FB3_Pos)
#define CAN_F6R2_FB3           CAN_F6R2_FB3_Msk
#define CAN_F6R2_FB4_Pos       (4U)
#define CAN_F6R2_FB4_Msk       (0x1U << CAN_F6R2_FB4_Pos)
#define CAN_F6R2_FB4           CAN_F6R2_FB4_Msk
#define CAN_F6R2_FB5_Pos       (5U)
#define CAN_F6R2_FB5_Msk       (0x1U << CAN_F6R2_FB5_Pos)
#define CAN_F6R2_FB5           CAN_F6R2_FB5_Msk
#define CAN_F6R2_FB6_Pos       (6U)
#define CAN_F6R2_FB6_Msk       (0x1U << CAN_F6R2_FB6_Pos)
#define CAN_F6R2_FB6           CAN_F6R2_FB6_Msk
#define CAN_F6R2_FB7_Pos       (7U)
#define CAN_F6R2_FB7_Msk       (0x1U << CAN_F6R2_FB7_Pos)
#define CAN_F6R2_FB7           CAN_F6R2_FB7_Msk
#define CAN_F6R2_FB8_Pos       (8U)
#define CAN_F6R2_FB8_Msk       (0x1U << CAN_F6R2_FB8_Pos)
#define CAN_F6R2_FB8           CAN_F6R2_FB8_Msk
#define CAN_F6R2_FB9_Pos       (9U)
#define CAN_F6R2_FB9_Msk       (0x1U << CAN_F6R2_FB9_Pos)
#define CAN_F6R2_FB9           CAN_F6R2_FB9_Msk
#define CAN_F6R2_FB10_Pos      (10U)
#define CAN_F6R2_FB10_Msk      (0x1U << CAN_F6R2_FB10_Pos)
#define CAN_F6R2_FB10          CAN_F6R2_FB10_Msk
#define CAN_F6R2_FB11_Pos      (11U)
#define CAN_F6R2_FB11_Msk      (0x1U << CAN_F6R2_FB11_Pos)
#define CAN_F6R2_FB11          CAN_F6R2_FB11_Msk
#define CAN_F6R2_FB12_Pos      (12U)
#define CAN_F6R2_FB12_Msk      (0x1U << CAN_F6R2_FB12_Pos)
#define CAN_F6R2_FB12          CAN_F6R2_FB12_Msk
#define CAN_F6R2_FB13_Pos      (13U)
#define CAN_F6R2_FB13_Msk      (0x1U << CAN_F6R2_FB13_Pos)
#define CAN_F6R2_FB13          CAN_F6R2_FB13_Msk
#define CAN_F6R2_FB14_Pos      (14U)
#define CAN_F6R2_FB14_Msk      (0x1U << CAN_F6R2_FB14_Pos)
#define CAN_F6R2_FB14          CAN_F6R2_FB14_Msk
#define CAN_F6R2_FB15_Pos      (15U)
#define CAN_F6R2_FB15_Msk      (0x1U << CAN_F6R2_FB15_Pos)
#define CAN_F6R2_FB15          CAN_F6R2_FB15_Msk
#define CAN_F6R2_FB16_Pos      (16U)
#define CAN_F6R2_FB16_Msk      (0x1U << CAN_F6R2_FB16_Pos)
#define CAN_F6R2_FB16          CAN_F6R2_FB16_Msk
#define CAN_F6R2_FB17_Pos      (17U)
#define CAN_F6R2_FB17_Msk      (0x1U << CAN_F6R2_FB17_Pos)
#define CAN_F6R2_FB17          CAN_F6R2_FB17_Msk
#define CAN_F6R2_FB18_Pos      (18U)
#define CAN_F6R2_FB18_Msk      (0x1U << CAN_F6R2_FB18_Pos)
#define CAN_F6R2_FB18          CAN_F6R2_FB18_Msk
#define CAN_F6R2_FB19_Pos      (19U)
#define CAN_F6R2_FB19_Msk      (0x1U << CAN_F6R2_FB19_Pos)
#define CAN_F6R2_FB19          CAN_F6R2_FB19_Msk
#define CAN_F6R2_FB20_Pos      (20U)
#define CAN_F6R2_FB20_Msk      (0x1U << CAN_F6R2_FB20_Pos)
#define CAN_F6R2_FB20          CAN_F6R2_FB20_Msk
#define CAN_F6R2_FB21_Pos      (21U)
#define CAN_F6R2_FB21_Msk      (0x1U << CAN_F6R2_FB21_Pos)
#define CAN_F6R2_FB21          CAN_F6R2_FB21_Msk
#define CAN_F6R2_FB22_Pos      (22U)
#define CAN_F6R2_FB22_Msk      (0x1U << CAN_F6R2_FB22_Pos)
#define CAN_F6R2_FB22          CAN_F6R2_FB22_Msk
#define CAN_F6R2_FB23_Pos      (23U)
#define CAN_F6R2_FB23_Msk      (0x1U << CAN_F6R2_FB23_Pos)
#define CAN_F6R2_FB23          CAN_F6R2_FB23_Msk
#define CAN_F6R2_FB24_Pos      (24U)
#define CAN_F6R2_FB24_Msk      (0x1U << CAN_F6R2_FB24_Pos)
#define CAN_F6R2_FB24          CAN_F6R2_FB24_Msk
#define CAN_F6R2_FB25_Pos      (25U)
#define CAN_F6R2_FB25_Msk      (0x1U << CAN_F6R2_FB25_Pos)
#define CAN_F6R2_FB25          CAN_F6R2_FB25_Msk
#define CAN_F6R2_FB26_Pos      (26U)
#define CAN_F6R2_FB26_Msk      (0x1U << CAN_F6R2_FB26_Pos)
#define CAN_F6R2_FB26          CAN_F6R2_FB26_Msk
#define CAN_F6R2_FB27_Pos      (27U)
#define CAN_F6R2_FB27_Msk      (0x1U << CAN_F6R2_FB27_Pos)
#define CAN_F6R2_FB27          CAN_F6R2_FB27_Msk
#define CAN_F6R2_FB28_Pos      (28U)
#define CAN_F6R2_FB28_Msk      (0x1U << CAN_F6R2_FB28_Pos)
#define CAN_F6R2_FB28          CAN_F6R2_FB28_Msk
#define CAN_F6R2_FB29_Pos      (29U)
#define CAN_F6R2_FB29_Msk      (0x1U << CAN_F6R2_FB29_Pos)
#define CAN_F6R2_FB29          CAN_F6R2_FB29_Msk
#define CAN_F6R2_FB30_Pos      (30U)
#define CAN_F6R2_FB30_Msk      (0x1U << CAN_F6R2_FB30_Pos)
#define CAN_F6R2_FB30          CAN_F6R2_FB30_Msk
#define CAN_F6R2_FB31_Pos      (31U)
#define CAN_F6R2_FB31_Msk      (0x1U << CAN_F6R2_FB31_Pos)
#define CAN_F6R2_FB31          CAN_F6R2_FB31_Msk


#define CAN_F7R2_FB0_Pos       (0U)
#define CAN_F7R2_FB0_Msk       (0x1U << CAN_F7R2_FB0_Pos)
#define CAN_F7R2_FB0           CAN_F7R2_FB0_Msk
#define CAN_F7R2_FB1_Pos       (1U)
#define CAN_F7R2_FB1_Msk       (0x1U << CAN_F7R2_FB1_Pos)
#define CAN_F7R2_FB1           CAN_F7R2_FB1_Msk
#define CAN_F7R2_FB2_Pos       (2U)
#define CAN_F7R2_FB2_Msk       (0x1U << CAN_F7R2_FB2_Pos)
#define CAN_F7R2_FB2           CAN_F7R2_FB2_Msk
#define CAN_F7R2_FB3_Pos       (3U)
#define CAN_F7R2_FB3_Msk       (0x1U << CAN_F7R2_FB3_Pos)
#define CAN_F7R2_FB3           CAN_F7R2_FB3_Msk
#define CAN_F7R2_FB4_Pos       (4U)
#define CAN_F7R2_FB4_Msk       (0x1U << CAN_F7R2_FB4_Pos)
#define CAN_F7R2_FB4           CAN_F7R2_FB4_Msk
#define CAN_F7R2_FB5_Pos       (5U)
#define CAN_F7R2_FB5_Msk       (0x1U << CAN_F7R2_FB5_Pos)
#define CAN_F7R2_FB5           CAN_F7R2_FB5_Msk
#define CAN_F7R2_FB6_Pos       (6U)
#define CAN_F7R2_FB6_Msk       (0x1U << CAN_F7R2_FB6_Pos)
#define CAN_F7R2_FB6           CAN_F7R2_FB6_Msk
#define CAN_F7R2_FB7_Pos       (7U)
#define CAN_F7R2_FB7_Msk       (0x1U << CAN_F7R2_FB7_Pos)
#define CAN_F7R2_FB7           CAN_F7R2_FB7_Msk
#define CAN_F7R2_FB8_Pos       (8U)
#define CAN_F7R2_FB8_Msk       (0x1U << CAN_F7R2_FB8_Pos)
#define CAN_F7R2_FB8           CAN_F7R2_FB8_Msk
#define CAN_F7R2_FB9_Pos       (9U)
#define CAN_F7R2_FB9_Msk       (0x1U << CAN_F7R2_FB9_Pos)
#define CAN_F7R2_FB9           CAN_F7R2_FB9_Msk
#define CAN_F7R2_FB10_Pos      (10U)
#define CAN_F7R2_FB10_Msk      (0x1U << CAN_F7R2_FB10_Pos)
#define CAN_F7R2_FB10          CAN_F7R2_FB10_Msk
#define CAN_F7R2_FB11_Pos      (11U)
#define CAN_F7R2_FB11_Msk      (0x1U << CAN_F7R2_FB11_Pos)
#define CAN_F7R2_FB11          CAN_F7R2_FB11_Msk
#define CAN_F7R2_FB12_Pos      (12U)
#define CAN_F7R2_FB12_Msk      (0x1U << CAN_F7R2_FB12_Pos)
#define CAN_F7R2_FB12          CAN_F7R2_FB12_Msk
#define CAN_F7R2_FB13_Pos      (13U)
#define CAN_F7R2_FB13_Msk      (0x1U << CAN_F7R2_FB13_Pos)
#define CAN_F7R2_FB13          CAN_F7R2_FB13_Msk
#define CAN_F7R2_FB14_Pos      (14U)
#define CAN_F7R2_FB14_Msk      (0x1U << CAN_F7R2_FB14_Pos)
#define CAN_F7R2_FB14          CAN_F7R2_FB14_Msk
#define CAN_F7R2_FB15_Pos      (15U)
#define CAN_F7R2_FB15_Msk      (0x1U << CAN_F7R2_FB15_Pos)
#define CAN_F7R2_FB15          CAN_F7R2_FB15_Msk
#define CAN_F7R2_FB16_Pos      (16U)
#define CAN_F7R2_FB16_Msk      (0x1U << CAN_F7R2_FB16_Pos)
#define CAN_F7R2_FB16          CAN_F7R2_FB16_Msk
#define CAN_F7R2_FB17_Pos      (17U)
#define CAN_F7R2_FB17_Msk      (0x1U << CAN_F7R2_FB17_Pos)
#define CAN_F7R2_FB17          CAN_F7R2_FB17_Msk
#define CAN_F7R2_FB18_Pos      (18U)
#define CAN_F7R2_FB18_Msk      (0x1U << CAN_F7R2_FB18_Pos)
#define CAN_F7R2_FB18          CAN_F7R2_FB18_Msk
#define CAN_F7R2_FB19_Pos      (19U)
#define CAN_F7R2_FB19_Msk      (0x1U << CAN_F7R2_FB19_Pos)
#define CAN_F7R2_FB19          CAN_F7R2_FB19_Msk
#define CAN_F7R2_FB20_Pos      (20U)
#define CAN_F7R2_FB20_Msk      (0x1U << CAN_F7R2_FB20_Pos)
#define CAN_F7R2_FB20          CAN_F7R2_FB20_Msk
#define CAN_F7R2_FB21_Pos      (21U)
#define CAN_F7R2_FB21_Msk      (0x1U << CAN_F7R2_FB21_Pos)
#define CAN_F7R2_FB21          CAN_F7R2_FB21_Msk
#define CAN_F7R2_FB22_Pos      (22U)
#define CAN_F7R2_FB22_Msk      (0x1U << CAN_F7R2_FB22_Pos)
#define CAN_F7R2_FB22          CAN_F7R2_FB22_Msk
#define CAN_F7R2_FB23_Pos      (23U)
#define CAN_F7R2_FB23_Msk      (0x1U << CAN_F7R2_FB23_Pos)
#define CAN_F7R2_FB23          CAN_F7R2_FB23_Msk
#define CAN_F7R2_FB24_Pos      (24U)
#define CAN_F7R2_FB24_Msk      (0x1U << CAN_F7R2_FB24_Pos)
#define CAN_F7R2_FB24          CAN_F7R2_FB24_Msk
#define CAN_F7R2_FB25_Pos      (25U)
#define CAN_F7R2_FB25_Msk      (0x1U << CAN_F7R2_FB25_Pos)
#define CAN_F7R2_FB25          CAN_F7R2_FB25_Msk
#define CAN_F7R2_FB26_Pos      (26U)
#define CAN_F7R2_FB26_Msk      (0x1U << CAN_F7R2_FB26_Pos)
#define CAN_F7R2_FB26          CAN_F7R2_FB26_Msk
#define CAN_F7R2_FB27_Pos      (27U)
#define CAN_F7R2_FB27_Msk      (0x1U << CAN_F7R2_FB27_Pos)
#define CAN_F7R2_FB27          CAN_F7R2_FB27_Msk
#define CAN_F7R2_FB28_Pos      (28U)
#define CAN_F7R2_FB28_Msk      (0x1U << CAN_F7R2_FB28_Pos)
#define CAN_F7R2_FB28          CAN_F7R2_FB28_Msk
#define CAN_F7R2_FB29_Pos      (29U)
#define CAN_F7R2_FB29_Msk      (0x1U << CAN_F7R2_FB29_Pos)
#define CAN_F7R2_FB29          CAN_F7R2_FB29_Msk
#define CAN_F7R2_FB30_Pos      (30U)
#define CAN_F7R2_FB30_Msk      (0x1U << CAN_F7R2_FB30_Pos)
#define CAN_F7R2_FB30          CAN_F7R2_FB30_Msk
#define CAN_F7R2_FB31_Pos      (31U)
#define CAN_F7R2_FB31_Msk      (0x1U << CAN_F7R2_FB31_Pos)
#define CAN_F7R2_FB31          CAN_F7R2_FB31_Msk


#define CAN_F8R2_FB0_Pos       (0U)
#define CAN_F8R2_FB0_Msk       (0x1U << CAN_F8R2_FB0_Pos)
#define CAN_F8R2_FB0           CAN_F8R2_FB0_Msk
#define CAN_F8R2_FB1_Pos       (1U)
#define CAN_F8R2_FB1_Msk       (0x1U << CAN_F8R2_FB1_Pos)
#define CAN_F8R2_FB1           CAN_F8R2_FB1_Msk
#define CAN_F8R2_FB2_Pos       (2U)
#define CAN_F8R2_FB2_Msk       (0x1U << CAN_F8R2_FB2_Pos)
#define CAN_F8R2_FB2           CAN_F8R2_FB2_Msk
#define CAN_F8R2_FB3_Pos       (3U)
#define CAN_F8R2_FB3_Msk       (0x1U << CAN_F8R2_FB3_Pos)
#define CAN_F8R2_FB3           CAN_F8R2_FB3_Msk
#define CAN_F8R2_FB4_Pos       (4U)
#define CAN_F8R2_FB4_Msk       (0x1U << CAN_F8R2_FB4_Pos)
#define CAN_F8R2_FB4           CAN_F8R2_FB4_Msk
#define CAN_F8R2_FB5_Pos       (5U)
#define CAN_F8R2_FB5_Msk       (0x1U << CAN_F8R2_FB5_Pos)
#define CAN_F8R2_FB5           CAN_F8R2_FB5_Msk
#define CAN_F8R2_FB6_Pos       (6U)
#define CAN_F8R2_FB6_Msk       (0x1U << CAN_F8R2_FB6_Pos)
#define CAN_F8R2_FB6           CAN_F8R2_FB6_Msk
#define CAN_F8R2_FB7_Pos       (7U)
#define CAN_F8R2_FB7_Msk       (0x1U << CAN_F8R2_FB7_Pos)
#define CAN_F8R2_FB7           CAN_F8R2_FB7_Msk
#define CAN_F8R2_FB8_Pos       (8U)
#define CAN_F8R2_FB8_Msk       (0x1U << CAN_F8R2_FB8_Pos)
#define CAN_F8R2_FB8           CAN_F8R2_FB8_Msk
#define CAN_F8R2_FB9_Pos       (9U)
#define CAN_F8R2_FB9_Msk       (0x1U << CAN_F8R2_FB9_Pos)
#define CAN_F8R2_FB9           CAN_F8R2_FB9_Msk
#define CAN_F8R2_FB10_Pos      (10U)
#define CAN_F8R2_FB10_Msk      (0x1U << CAN_F8R2_FB10_Pos)
#define CAN_F8R2_FB10          CAN_F8R2_FB10_Msk
#define CAN_F8R2_FB11_Pos      (11U)
#define CAN_F8R2_FB11_Msk      (0x1U << CAN_F8R2_FB11_Pos)
#define CAN_F8R2_FB11          CAN_F8R2_FB11_Msk
#define CAN_F8R2_FB12_Pos      (12U)
#define CAN_F8R2_FB12_Msk      (0x1U << CAN_F8R2_FB12_Pos)
#define CAN_F8R2_FB12          CAN_F8R2_FB12_Msk
#define CAN_F8R2_FB13_Pos      (13U)
#define CAN_F8R2_FB13_Msk      (0x1U << CAN_F8R2_FB13_Pos)
#define CAN_F8R2_FB13          CAN_F8R2_FB13_Msk
#define CAN_F8R2_FB14_Pos      (14U)
#define CAN_F8R2_FB14_Msk      (0x1U << CAN_F8R2_FB14_Pos)
#define CAN_F8R2_FB14          CAN_F8R2_FB14_Msk
#define CAN_F8R2_FB15_Pos      (15U)
#define CAN_F8R2_FB15_Msk      (0x1U << CAN_F8R2_FB15_Pos)
#define CAN_F8R2_FB15          CAN_F8R2_FB15_Msk
#define CAN_F8R2_FB16_Pos      (16U)
#define CAN_F8R2_FB16_Msk      (0x1U << CAN_F8R2_FB16_Pos)
#define CAN_F8R2_FB16          CAN_F8R2_FB16_Msk
#define CAN_F8R2_FB17_Pos      (17U)
#define CAN_F8R2_FB17_Msk      (0x1U << CAN_F8R2_FB17_Pos)
#define CAN_F8R2_FB17          CAN_F8R2_FB17_Msk
#define CAN_F8R2_FB18_Pos      (18U)
#define CAN_F8R2_FB18_Msk      (0x1U << CAN_F8R2_FB18_Pos)
#define CAN_F8R2_FB18          CAN_F8R2_FB18_Msk
#define CAN_F8R2_FB19_Pos      (19U)
#define CAN_F8R2_FB19_Msk      (0x1U << CAN_F8R2_FB19_Pos)
#define CAN_F8R2_FB19          CAN_F8R2_FB19_Msk
#define CAN_F8R2_FB20_Pos      (20U)
#define CAN_F8R2_FB20_Msk      (0x1U << CAN_F8R2_FB20_Pos)
#define CAN_F8R2_FB20          CAN_F8R2_FB20_Msk
#define CAN_F8R2_FB21_Pos      (21U)
#define CAN_F8R2_FB21_Msk      (0x1U << CAN_F8R2_FB21_Pos)
#define CAN_F8R2_FB21          CAN_F8R2_FB21_Msk
#define CAN_F8R2_FB22_Pos      (22U)
#define CAN_F8R2_FB22_Msk      (0x1U << CAN_F8R2_FB22_Pos)
#define CAN_F8R2_FB22          CAN_F8R2_FB22_Msk
#define CAN_F8R2_FB23_Pos      (23U)
#define CAN_F8R2_FB23_Msk      (0x1U << CAN_F8R2_FB23_Pos)
#define CAN_F8R2_FB23          CAN_F8R2_FB23_Msk
#define CAN_F8R2_FB24_Pos      (24U)
#define CAN_F8R2_FB24_Msk      (0x1U << CAN_F8R2_FB24_Pos)
#define CAN_F8R2_FB24          CAN_F8R2_FB24_Msk
#define CAN_F8R2_FB25_Pos      (25U)
#define CAN_F8R2_FB25_Msk      (0x1U << CAN_F8R2_FB25_Pos)
#define CAN_F8R2_FB25          CAN_F8R2_FB25_Msk
#define CAN_F8R2_FB26_Pos      (26U)
#define CAN_F8R2_FB26_Msk      (0x1U << CAN_F8R2_FB26_Pos)
#define CAN_F8R2_FB26          CAN_F8R2_FB26_Msk
#define CAN_F8R2_FB27_Pos      (27U)
#define CAN_F8R2_FB27_Msk      (0x1U << CAN_F8R2_FB27_Pos)
#define CAN_F8R2_FB27          CAN_F8R2_FB27_Msk
#define CAN_F8R2_FB28_Pos      (28U)
#define CAN_F8R2_FB28_Msk      (0x1U << CAN_F8R2_FB28_Pos)
#define CAN_F8R2_FB28          CAN_F8R2_FB28_Msk
#define CAN_F8R2_FB29_Pos      (29U)
#define CAN_F8R2_FB29_Msk      (0x1U << CAN_F8R2_FB29_Pos)
#define CAN_F8R2_FB29          CAN_F8R2_FB29_Msk
#define CAN_F8R2_FB30_Pos      (30U)
#define CAN_F8R2_FB30_Msk      (0x1U << CAN_F8R2_FB30_Pos)
#define CAN_F8R2_FB30          CAN_F8R2_FB30_Msk
#define CAN_F8R2_FB31_Pos      (31U)
#define CAN_F8R2_FB31_Msk      (0x1U << CAN_F8R2_FB31_Pos)
#define CAN_F8R2_FB31          CAN_F8R2_FB31_Msk


#define CAN_F9R2_FB0_Pos       (0U)
#define CAN_F9R2_FB0_Msk       (0x1U << CAN_F9R2_FB0_Pos)
#define CAN_F9R2_FB0           CAN_F9R2_FB0_Msk
#define CAN_F9R2_FB1_Pos       (1U)
#define CAN_F9R2_FB1_Msk       (0x1U << CAN_F9R2_FB1_Pos)
#define CAN_F9R2_FB1           CAN_F9R2_FB1_Msk
#define CAN_F9R2_FB2_Pos       (2U)
#define CAN_F9R2_FB2_Msk       (0x1U << CAN_F9R2_FB2_Pos)
#define CAN_F9R2_FB2           CAN_F9R2_FB2_Msk
#define CAN_F9R2_FB3_Pos       (3U)
#define CAN_F9R2_FB3_Msk       (0x1U << CAN_F9R2_FB3_Pos)
#define CAN_F9R2_FB3           CAN_F9R2_FB3_Msk
#define CAN_F9R2_FB4_Pos       (4U)
#define CAN_F9R2_FB4_Msk       (0x1U << CAN_F9R2_FB4_Pos)
#define CAN_F9R2_FB4           CAN_F9R2_FB4_Msk
#define CAN_F9R2_FB5_Pos       (5U)
#define CAN_F9R2_FB5_Msk       (0x1U << CAN_F9R2_FB5_Pos)
#define CAN_F9R2_FB5           CAN_F9R2_FB5_Msk
#define CAN_F9R2_FB6_Pos       (6U)
#define CAN_F9R2_FB6_Msk       (0x1U << CAN_F9R2_FB6_Pos)
#define CAN_F9R2_FB6           CAN_F9R2_FB6_Msk
#define CAN_F9R2_FB7_Pos       (7U)
#define CAN_F9R2_FB7_Msk       (0x1U << CAN_F9R2_FB7_Pos)
#define CAN_F9R2_FB7           CAN_F9R2_FB7_Msk
#define CAN_F9R2_FB8_Pos       (8U)
#define CAN_F9R2_FB8_Msk       (0x1U << CAN_F9R2_FB8_Pos)
#define CAN_F9R2_FB8           CAN_F9R2_FB8_Msk
#define CAN_F9R2_FB9_Pos       (9U)
#define CAN_F9R2_FB9_Msk       (0x1U << CAN_F9R2_FB9_Pos)
#define CAN_F9R2_FB9           CAN_F9R2_FB9_Msk
#define CAN_F9R2_FB10_Pos      (10U)
#define CAN_F9R2_FB10_Msk      (0x1U << CAN_F9R2_FB10_Pos)
#define CAN_F9R2_FB10          CAN_F9R2_FB10_Msk
#define CAN_F9R2_FB11_Pos      (11U)
#define CAN_F9R2_FB11_Msk      (0x1U << CAN_F9R2_FB11_Pos)
#define CAN_F9R2_FB11          CAN_F9R2_FB11_Msk
#define CAN_F9R2_FB12_Pos      (12U)
#define CAN_F9R2_FB12_Msk      (0x1U << CAN_F9R2_FB12_Pos)
#define CAN_F9R2_FB12          CAN_F9R2_FB12_Msk
#define CAN_F9R2_FB13_Pos      (13U)
#define CAN_F9R2_FB13_Msk      (0x1U << CAN_F9R2_FB13_Pos)
#define CAN_F9R2_FB13          CAN_F9R2_FB13_Msk
#define CAN_F9R2_FB14_Pos      (14U)
#define CAN_F9R2_FB14_Msk      (0x1U << CAN_F9R2_FB14_Pos)
#define CAN_F9R2_FB14          CAN_F9R2_FB14_Msk
#define CAN_F9R2_FB15_Pos      (15U)
#define CAN_F9R2_FB15_Msk      (0x1U << CAN_F9R2_FB15_Pos)
#define CAN_F9R2_FB15          CAN_F9R2_FB15_Msk
#define CAN_F9R2_FB16_Pos      (16U)
#define CAN_F9R2_FB16_Msk      (0x1U << CAN_F9R2_FB16_Pos)
#define CAN_F9R2_FB16          CAN_F9R2_FB16_Msk
#define CAN_F9R2_FB17_Pos      (17U)
#define CAN_F9R2_FB17_Msk      (0x1U << CAN_F9R2_FB17_Pos)
#define CAN_F9R2_FB17          CAN_F9R2_FB17_Msk
#define CAN_F9R2_FB18_Pos      (18U)
#define CAN_F9R2_FB18_Msk      (0x1U << CAN_F9R2_FB18_Pos)
#define CAN_F9R2_FB18          CAN_F9R2_FB18_Msk
#define CAN_F9R2_FB19_Pos      (19U)
#define CAN_F9R2_FB19_Msk      (0x1U << CAN_F9R2_FB19_Pos)
#define CAN_F9R2_FB19          CAN_F9R2_FB19_Msk
#define CAN_F9R2_FB20_Pos      (20U)
#define CAN_F9R2_FB20_Msk      (0x1U << CAN_F9R2_FB20_Pos)
#define CAN_F9R2_FB20          CAN_F9R2_FB20_Msk
#define CAN_F9R2_FB21_Pos      (21U)
#define CAN_F9R2_FB21_Msk      (0x1U << CAN_F9R2_FB21_Pos)
#define CAN_F9R2_FB21          CAN_F9R2_FB21_Msk
#define CAN_F9R2_FB22_Pos      (22U)
#define CAN_F9R2_FB22_Msk      (0x1U << CAN_F9R2_FB22_Pos)
#define CAN_F9R2_FB22          CAN_F9R2_FB22_Msk
#define CAN_F9R2_FB23_Pos      (23U)
#define CAN_F9R2_FB23_Msk      (0x1U << CAN_F9R2_FB23_Pos)
#define CAN_F9R2_FB23          CAN_F9R2_FB23_Msk
#define CAN_F9R2_FB24_Pos      (24U)
#define CAN_F9R2_FB24_Msk      (0x1U << CAN_F9R2_FB24_Pos)
#define CAN_F9R2_FB24          CAN_F9R2_FB24_Msk
#define CAN_F9R2_FB25_Pos      (25U)
#define CAN_F9R2_FB25_Msk      (0x1U << CAN_F9R2_FB25_Pos)
#define CAN_F9R2_FB25          CAN_F9R2_FB25_Msk
#define CAN_F9R2_FB26_Pos      (26U)
#define CAN_F9R2_FB26_Msk      (0x1U << CAN_F9R2_FB26_Pos)
#define CAN_F9R2_FB26          CAN_F9R2_FB26_Msk
#define CAN_F9R2_FB27_Pos      (27U)
#define CAN_F9R2_FB27_Msk      (0x1U << CAN_F9R2_FB27_Pos)
#define CAN_F9R2_FB27          CAN_F9R2_FB27_Msk
#define CAN_F9R2_FB28_Pos      (28U)
#define CAN_F9R2_FB28_Msk      (0x1U << CAN_F9R2_FB28_Pos)
#define CAN_F9R2_FB28          CAN_F9R2_FB28_Msk
#define CAN_F9R2_FB29_Pos      (29U)
#define CAN_F9R2_FB29_Msk      (0x1U << CAN_F9R2_FB29_Pos)
#define CAN_F9R2_FB29          CAN_F9R2_FB29_Msk
#define CAN_F9R2_FB30_Pos      (30U)
#define CAN_F9R2_FB30_Msk      (0x1U << CAN_F9R2_FB30_Pos)
#define CAN_F9R2_FB30          CAN_F9R2_FB30_Msk
#define CAN_F9R2_FB31_Pos      (31U)
#define CAN_F9R2_FB31_Msk      (0x1U << CAN_F9R2_FB31_Pos)
#define CAN_F9R2_FB31          CAN_F9R2_FB31_Msk


#define CAN_F10R2_FB0_Pos      (0U)
#define CAN_F10R2_FB0_Msk      (0x1U << CAN_F10R2_FB0_Pos)
#define CAN_F10R2_FB0          CAN_F10R2_FB0_Msk
#define CAN_F10R2_FB1_Pos      (1U)
#define CAN_F10R2_FB1_Msk      (0x1U << CAN_F10R2_FB1_Pos)
#define CAN_F10R2_FB1          CAN_F10R2_FB1_Msk
#define CAN_F10R2_FB2_Pos      (2U)
#define CAN_F10R2_FB2_Msk      (0x1U << CAN_F10R2_FB2_Pos)
#define CAN_F10R2_FB2          CAN_F10R2_FB2_Msk
#define CAN_F10R2_FB3_Pos      (3U)
#define CAN_F10R2_FB3_Msk      (0x1U << CAN_F10R2_FB3_Pos)
#define CAN_F10R2_FB3          CAN_F10R2_FB3_Msk
#define CAN_F10R2_FB4_Pos      (4U)
#define CAN_F10R2_FB4_Msk      (0x1U << CAN_F10R2_FB4_Pos)
#define CAN_F10R2_FB4          CAN_F10R2_FB4_Msk
#define CAN_F10R2_FB5_Pos      (5U)
#define CAN_F10R2_FB5_Msk      (0x1U << CAN_F10R2_FB5_Pos)
#define CAN_F10R2_FB5          CAN_F10R2_FB5_Msk
#define CAN_F10R2_FB6_Pos      (6U)
#define CAN_F10R2_FB6_Msk      (0x1U << CAN_F10R2_FB6_Pos)
#define CAN_F10R2_FB6          CAN_F10R2_FB6_Msk
#define CAN_F10R2_FB7_Pos      (7U)
#define CAN_F10R2_FB7_Msk      (0x1U << CAN_F10R2_FB7_Pos)
#define CAN_F10R2_FB7          CAN_F10R2_FB7_Msk
#define CAN_F10R2_FB8_Pos      (8U)
#define CAN_F10R2_FB8_Msk      (0x1U << CAN_F10R2_FB8_Pos)
#define CAN_F10R2_FB8          CAN_F10R2_FB8_Msk
#define CAN_F10R2_FB9_Pos      (9U)
#define CAN_F10R2_FB9_Msk      (0x1U << CAN_F10R2_FB9_Pos)
#define CAN_F10R2_FB9          CAN_F10R2_FB9_Msk
#define CAN_F10R2_FB10_Pos     (10U)
#define CAN_F10R2_FB10_Msk     (0x1U << CAN_F10R2_FB10_Pos)
#define CAN_F10R2_FB10         CAN_F10R2_FB10_Msk
#define CAN_F10R2_FB11_Pos     (11U)
#define CAN_F10R2_FB11_Msk     (0x1U << CAN_F10R2_FB11_Pos)
#define CAN_F10R2_FB11         CAN_F10R2_FB11_Msk
#define CAN_F10R2_FB12_Pos     (12U)
#define CAN_F10R2_FB12_Msk     (0x1U << CAN_F10R2_FB12_Pos)
#define CAN_F10R2_FB12         CAN_F10R2_FB12_Msk
#define CAN_F10R2_FB13_Pos     (13U)
#define CAN_F10R2_FB13_Msk     (0x1U << CAN_F10R2_FB13_Pos)
#define CAN_F10R2_FB13         CAN_F10R2_FB13_Msk
#define CAN_F10R2_FB14_Pos     (14U)
#define CAN_F10R2_FB14_Msk     (0x1U << CAN_F10R2_FB14_Pos)
#define CAN_F10R2_FB14         CAN_F10R2_FB14_Msk
#define CAN_F10R2_FB15_Pos     (15U)
#define CAN_F10R2_FB15_Msk     (0x1U << CAN_F10R2_FB15_Pos)
#define CAN_F10R2_FB15         CAN_F10R2_FB15_Msk
#define CAN_F10R2_FB16_Pos     (16U)
#define CAN_F10R2_FB16_Msk     (0x1U << CAN_F10R2_FB16_Pos)
#define CAN_F10R2_FB16         CAN_F10R2_FB16_Msk
#define CAN_F10R2_FB17_Pos     (17U)
#define CAN_F10R2_FB17_Msk     (0x1U << CAN_F10R2_FB17_Pos)
#define CAN_F10R2_FB17         CAN_F10R2_FB17_Msk
#define CAN_F10R2_FB18_Pos     (18U)
#define CAN_F10R2_FB18_Msk     (0x1U << CAN_F10R2_FB18_Pos)
#define CAN_F10R2_FB18         CAN_F10R2_FB18_Msk
#define CAN_F10R2_FB19_Pos     (19U)
#define CAN_F10R2_FB19_Msk     (0x1U << CAN_F10R2_FB19_Pos)
#define CAN_F10R2_FB19         CAN_F10R2_FB19_Msk
#define CAN_F10R2_FB20_Pos     (20U)
#define CAN_F10R2_FB20_Msk     (0x1U << CAN_F10R2_FB20_Pos)
#define CAN_F10R2_FB20         CAN_F10R2_FB20_Msk
#define CAN_F10R2_FB21_Pos     (21U)
#define CAN_F10R2_FB21_Msk     (0x1U << CAN_F10R2_FB21_Pos)
#define CAN_F10R2_FB21         CAN_F10R2_FB21_Msk
#define CAN_F10R2_FB22_Pos     (22U)
#define CAN_F10R2_FB22_Msk     (0x1U << CAN_F10R2_FB22_Pos)
#define CAN_F10R2_FB22         CAN_F10R2_FB22_Msk
#define CAN_F10R2_FB23_Pos     (23U)
#define CAN_F10R2_FB23_Msk     (0x1U << CAN_F10R2_FB23_Pos)
#define CAN_F10R2_FB23         CAN_F10R2_FB23_Msk
#define CAN_F10R2_FB24_Pos     (24U)
#define CAN_F10R2_FB24_Msk     (0x1U << CAN_F10R2_FB24_Pos)
#define CAN_F10R2_FB24         CAN_F10R2_FB24_Msk
#define CAN_F10R2_FB25_Pos     (25U)
#define CAN_F10R2_FB25_Msk     (0x1U << CAN_F10R2_FB25_Pos)
#define CAN_F10R2_FB25         CAN_F10R2_FB25_Msk
#define CAN_F10R2_FB26_Pos     (26U)
#define CAN_F10R2_FB26_Msk     (0x1U << CAN_F10R2_FB26_Pos)
#define CAN_F10R2_FB26         CAN_F10R2_FB26_Msk
#define CAN_F10R2_FB27_Pos     (27U)
#define CAN_F10R2_FB27_Msk     (0x1U << CAN_F10R2_FB27_Pos)
#define CAN_F10R2_FB27         CAN_F10R2_FB27_Msk
#define CAN_F10R2_FB28_Pos     (28U)
#define CAN_F10R2_FB28_Msk     (0x1U << CAN_F10R2_FB28_Pos)
#define CAN_F10R2_FB28         CAN_F10R2_FB28_Msk
#define CAN_F10R2_FB29_Pos     (29U)
#define CAN_F10R2_FB29_Msk     (0x1U << CAN_F10R2_FB29_Pos)
#define CAN_F10R2_FB29         CAN_F10R2_FB29_Msk
#define CAN_F10R2_FB30_Pos     (30U)
#define CAN_F10R2_FB30_Msk     (0x1U << CAN_F10R2_FB30_Pos)
#define CAN_F10R2_FB30         CAN_F10R2_FB30_Msk
#define CAN_F10R2_FB31_Pos     (31U)
#define CAN_F10R2_FB31_Msk     (0x1U << CAN_F10R2_FB31_Pos)
#define CAN_F10R2_FB31         CAN_F10R2_FB31_Msk


#define CAN_F11R2_FB0_Pos      (0U)
#define CAN_F11R2_FB0_Msk      (0x1U << CAN_F11R2_FB0_Pos)
#define CAN_F11R2_FB0          CAN_F11R2_FB0_Msk
#define CAN_F11R2_FB1_Pos      (1U)
#define CAN_F11R2_FB1_Msk      (0x1U << CAN_F11R2_FB1_Pos)
#define CAN_F11R2_FB1          CAN_F11R2_FB1_Msk
#define CAN_F11R2_FB2_Pos      (2U)
#define CAN_F11R2_FB2_Msk      (0x1U << CAN_F11R2_FB2_Pos)
#define CAN_F11R2_FB2          CAN_F11R2_FB2_Msk
#define CAN_F11R2_FB3_Pos      (3U)
#define CAN_F11R2_FB3_Msk      (0x1U << CAN_F11R2_FB3_Pos)
#define CAN_F11R2_FB3          CAN_F11R2_FB3_Msk
#define CAN_F11R2_FB4_Pos      (4U)
#define CAN_F11R2_FB4_Msk      (0x1U << CAN_F11R2_FB4_Pos)
#define CAN_F11R2_FB4          CAN_F11R2_FB4_Msk
#define CAN_F11R2_FB5_Pos      (5U)
#define CAN_F11R2_FB5_Msk      (0x1U << CAN_F11R2_FB5_Pos)
#define CAN_F11R2_FB5          CAN_F11R2_FB5_Msk
#define CAN_F11R2_FB6_Pos      (6U)
#define CAN_F11R2_FB6_Msk      (0x1U << CAN_F11R2_FB6_Pos)
#define CAN_F11R2_FB6          CAN_F11R2_FB6_Msk
#define CAN_F11R2_FB7_Pos      (7U)
#define CAN_F11R2_FB7_Msk      (0x1U << CAN_F11R2_FB7_Pos)
#define CAN_F11R2_FB7          CAN_F11R2_FB7_Msk
#define CAN_F11R2_FB8_Pos      (8U)
#define CAN_F11R2_FB8_Msk      (0x1U << CAN_F11R2_FB8_Pos)
#define CAN_F11R2_FB8          CAN_F11R2_FB8_Msk
#define CAN_F11R2_FB9_Pos      (9U)
#define CAN_F11R2_FB9_Msk      (0x1U << CAN_F11R2_FB9_Pos)
#define CAN_F11R2_FB9          CAN_F11R2_FB9_Msk
#define CAN_F11R2_FB10_Pos     (10U)
#define CAN_F11R2_FB10_Msk     (0x1U << CAN_F11R2_FB10_Pos)
#define CAN_F11R2_FB10         CAN_F11R2_FB10_Msk
#define CAN_F11R2_FB11_Pos     (11U)
#define CAN_F11R2_FB11_Msk     (0x1U << CAN_F11R2_FB11_Pos)
#define CAN_F11R2_FB11         CAN_F11R2_FB11_Msk
#define CAN_F11R2_FB12_Pos     (12U)
#define CAN_F11R2_FB12_Msk     (0x1U << CAN_F11R2_FB12_Pos)
#define CAN_F11R2_FB12         CAN_F11R2_FB12_Msk
#define CAN_F11R2_FB13_Pos     (13U)
#define CAN_F11R2_FB13_Msk     (0x1U << CAN_F11R2_FB13_Pos)
#define CAN_F11R2_FB13         CAN_F11R2_FB13_Msk
#define CAN_F11R2_FB14_Pos     (14U)
#define CAN_F11R2_FB14_Msk     (0x1U << CAN_F11R2_FB14_Pos)
#define CAN_F11R2_FB14         CAN_F11R2_FB14_Msk
#define CAN_F11R2_FB15_Pos     (15U)
#define CAN_F11R2_FB15_Msk     (0x1U << CAN_F11R2_FB15_Pos)
#define CAN_F11R2_FB15         CAN_F11R2_FB15_Msk
#define CAN_F11R2_FB16_Pos     (16U)
#define CAN_F11R2_FB16_Msk     (0x1U << CAN_F11R2_FB16_Pos)
#define CAN_F11R2_FB16         CAN_F11R2_FB16_Msk
#define CAN_F11R2_FB17_Pos     (17U)
#define CAN_F11R2_FB17_Msk     (0x1U << CAN_F11R2_FB17_Pos)
#define CAN_F11R2_FB17         CAN_F11R2_FB17_Msk
#define CAN_F11R2_FB18_Pos     (18U)
#define CAN_F11R2_FB18_Msk     (0x1U << CAN_F11R2_FB18_Pos)
#define CAN_F11R2_FB18         CAN_F11R2_FB18_Msk
#define CAN_F11R2_FB19_Pos     (19U)
#define CAN_F11R2_FB19_Msk     (0x1U << CAN_F11R2_FB19_Pos)
#define CAN_F11R2_FB19         CAN_F11R2_FB19_Msk
#define CAN_F11R2_FB20_Pos     (20U)
#define CAN_F11R2_FB20_Msk     (0x1U << CAN_F11R2_FB20_Pos)
#define CAN_F11R2_FB20         CAN_F11R2_FB20_Msk
#define CAN_F11R2_FB21_Pos     (21U)
#define CAN_F11R2_FB21_Msk     (0x1U << CAN_F11R2_FB21_Pos)
#define CAN_F11R2_FB21         CAN_F11R2_FB21_Msk
#define CAN_F11R2_FB22_Pos     (22U)
#define CAN_F11R2_FB22_Msk     (0x1U << CAN_F11R2_FB22_Pos)
#define CAN_F11R2_FB22         CAN_F11R2_FB22_Msk
#define CAN_F11R2_FB23_Pos     (23U)
#define CAN_F11R2_FB23_Msk     (0x1U << CAN_F11R2_FB23_Pos)
#define CAN_F11R2_FB23         CAN_F11R2_FB23_Msk
#define CAN_F11R2_FB24_Pos     (24U)
#define CAN_F11R2_FB24_Msk     (0x1U << CAN_F11R2_FB24_Pos)
#define CAN_F11R2_FB24         CAN_F11R2_FB24_Msk
#define CAN_F11R2_FB25_Pos     (25U)
#define CAN_F11R2_FB25_Msk     (0x1U << CAN_F11R2_FB25_Pos)
#define CAN_F11R2_FB25         CAN_F11R2_FB25_Msk
#define CAN_F11R2_FB26_Pos     (26U)
#define CAN_F11R2_FB26_Msk     (0x1U << CAN_F11R2_FB26_Pos)
#define CAN_F11R2_FB26         CAN_F11R2_FB26_Msk
#define CAN_F11R2_FB27_Pos     (27U)
#define CAN_F11R2_FB27_Msk     (0x1U << CAN_F11R2_FB27_Pos)
#define CAN_F11R2_FB27         CAN_F11R2_FB27_Msk
#define CAN_F11R2_FB28_Pos     (28U)
#define CAN_F11R2_FB28_Msk     (0x1U << CAN_F11R2_FB28_Pos)
#define CAN_F11R2_FB28         CAN_F11R2_FB28_Msk
#define CAN_F11R2_FB29_Pos     (29U)
#define CAN_F11R2_FB29_Msk     (0x1U << CAN_F11R2_FB29_Pos)
#define CAN_F11R2_FB29         CAN_F11R2_FB29_Msk
#define CAN_F11R2_FB30_Pos     (30U)
#define CAN_F11R2_FB30_Msk     (0x1U << CAN_F11R2_FB30_Pos)
#define CAN_F11R2_FB30         CAN_F11R2_FB30_Msk
#define CAN_F11R2_FB31_Pos     (31U)
#define CAN_F11R2_FB31_Msk     (0x1U << CAN_F11R2_FB31_Pos)
#define CAN_F11R2_FB31         CAN_F11R2_FB31_Msk


#define CAN_F12R2_FB0_Pos      (0U)
#define CAN_F12R2_FB0_Msk      (0x1U << CAN_F12R2_FB0_Pos)
#define CAN_F12R2_FB0          CAN_F12R2_FB0_Msk
#define CAN_F12R2_FB1_Pos      (1U)
#define CAN_F12R2_FB1_Msk      (0x1U << CAN_F12R2_FB1_Pos)
#define CAN_F12R2_FB1          CAN_F12R2_FB1_Msk
#define CAN_F12R2_FB2_Pos      (2U)
#define CAN_F12R2_FB2_Msk      (0x1U << CAN_F12R2_FB2_Pos)
#define CAN_F12R2_FB2          CAN_F12R2_FB2_Msk
#define CAN_F12R2_FB3_Pos      (3U)
#define CAN_F12R2_FB3_Msk      (0x1U << CAN_F12R2_FB3_Pos)
#define CAN_F12R2_FB3          CAN_F12R2_FB3_Msk
#define CAN_F12R2_FB4_Pos      (4U)
#define CAN_F12R2_FB4_Msk      (0x1U << CAN_F12R2_FB4_Pos)
#define CAN_F12R2_FB4          CAN_F12R2_FB4_Msk
#define CAN_F12R2_FB5_Pos      (5U)
#define CAN_F12R2_FB5_Msk      (0x1U << CAN_F12R2_FB5_Pos)
#define CAN_F12R2_FB5          CAN_F12R2_FB5_Msk
#define CAN_F12R2_FB6_Pos      (6U)
#define CAN_F12R2_FB6_Msk      (0x1U << CAN_F12R2_FB6_Pos)
#define CAN_F12R2_FB6          CAN_F12R2_FB6_Msk
#define CAN_F12R2_FB7_Pos      (7U)
#define CAN_F12R2_FB7_Msk      (0x1U << CAN_F12R2_FB7_Pos)
#define CAN_F12R2_FB7          CAN_F12R2_FB7_Msk
#define CAN_F12R2_FB8_Pos      (8U)
#define CAN_F12R2_FB8_Msk      (0x1U << CAN_F12R2_FB8_Pos)
#define CAN_F12R2_FB8          CAN_F12R2_FB8_Msk
#define CAN_F12R2_FB9_Pos      (9U)
#define CAN_F12R2_FB9_Msk      (0x1U << CAN_F12R2_FB9_Pos)
#define CAN_F12R2_FB9          CAN_F12R2_FB9_Msk
#define CAN_F12R2_FB10_Pos     (10U)
#define CAN_F12R2_FB10_Msk     (0x1U << CAN_F12R2_FB10_Pos)
#define CAN_F12R2_FB10         CAN_F12R2_FB10_Msk
#define CAN_F12R2_FB11_Pos     (11U)
#define CAN_F12R2_FB11_Msk     (0x1U << CAN_F12R2_FB11_Pos)
#define CAN_F12R2_FB11         CAN_F12R2_FB11_Msk
#define CAN_F12R2_FB12_Pos     (12U)
#define CAN_F12R2_FB12_Msk     (0x1U << CAN_F12R2_FB12_Pos)
#define CAN_F12R2_FB12         CAN_F12R2_FB12_Msk
#define CAN_F12R2_FB13_Pos     (13U)
#define CAN_F12R2_FB13_Msk     (0x1U << CAN_F12R2_FB13_Pos)
#define CAN_F12R2_FB13         CAN_F12R2_FB13_Msk
#define CAN_F12R2_FB14_Pos     (14U)
#define CAN_F12R2_FB14_Msk     (0x1U << CAN_F12R2_FB14_Pos)
#define CAN_F12R2_FB14         CAN_F12R2_FB14_Msk
#define CAN_F12R2_FB15_Pos     (15U)
#define CAN_F12R2_FB15_Msk     (0x1U << CAN_F12R2_FB15_Pos)
#define CAN_F12R2_FB15         CAN_F12R2_FB15_Msk
#define CAN_F12R2_FB16_Pos     (16U)
#define CAN_F12R2_FB16_Msk     (0x1U << CAN_F12R2_FB16_Pos)
#define CAN_F12R2_FB16         CAN_F12R2_FB16_Msk
#define CAN_F12R2_FB17_Pos     (17U)
#define CAN_F12R2_FB17_Msk     (0x1U << CAN_F12R2_FB17_Pos)
#define CAN_F12R2_FB17         CAN_F12R2_FB17_Msk
#define CAN_F12R2_FB18_Pos     (18U)
#define CAN_F12R2_FB18_Msk     (0x1U << CAN_F12R2_FB18_Pos)
#define CAN_F12R2_FB18         CAN_F12R2_FB18_Msk
#define CAN_F12R2_FB19_Pos     (19U)
#define CAN_F12R2_FB19_Msk     (0x1U << CAN_F12R2_FB19_Pos)
#define CAN_F12R2_FB19         CAN_F12R2_FB19_Msk
#define CAN_F12R2_FB20_Pos     (20U)
#define CAN_F12R2_FB20_Msk     (0x1U << CAN_F12R2_FB20_Pos)
#define CAN_F12R2_FB20         CAN_F12R2_FB20_Msk
#define CAN_F12R2_FB21_Pos     (21U)
#define CAN_F12R2_FB21_Msk     (0x1U << CAN_F12R2_FB21_Pos)
#define CAN_F12R2_FB21         CAN_F12R2_FB21_Msk
#define CAN_F12R2_FB22_Pos     (22U)
#define CAN_F12R2_FB22_Msk     (0x1U << CAN_F12R2_FB22_Pos)
#define CAN_F12R2_FB22         CAN_F12R2_FB22_Msk
#define CAN_F12R2_FB23_Pos     (23U)
#define CAN_F12R2_FB23_Msk     (0x1U << CAN_F12R2_FB23_Pos)
#define CAN_F12R2_FB23         CAN_F12R2_FB23_Msk
#define CAN_F12R2_FB24_Pos     (24U)
#define CAN_F12R2_FB24_Msk     (0x1U << CAN_F12R2_FB24_Pos)
#define CAN_F12R2_FB24         CAN_F12R2_FB24_Msk
#define CAN_F12R2_FB25_Pos     (25U)
#define CAN_F12R2_FB25_Msk     (0x1U << CAN_F12R2_FB25_Pos)
#define CAN_F12R2_FB25         CAN_F12R2_FB25_Msk
#define CAN_F12R2_FB26_Pos     (26U)
#define CAN_F12R2_FB26_Msk     (0x1U << CAN_F12R2_FB26_Pos)
#define CAN_F12R2_FB26         CAN_F12R2_FB26_Msk
#define CAN_F12R2_FB27_Pos     (27U)
#define CAN_F12R2_FB27_Msk     (0x1U << CAN_F12R2_FB27_Pos)
#define CAN_F12R2_FB27         CAN_F12R2_FB27_Msk
#define CAN_F12R2_FB28_Pos     (28U)
#define CAN_F12R2_FB28_Msk     (0x1U << CAN_F12R2_FB28_Pos)
#define CAN_F12R2_FB28         CAN_F12R2_FB28_Msk
#define CAN_F12R2_FB29_Pos     (29U)
#define CAN_F12R2_FB29_Msk     (0x1U << CAN_F12R2_FB29_Pos)
#define CAN_F12R2_FB29         CAN_F12R2_FB29_Msk
#define CAN_F12R2_FB30_Pos     (30U)
#define CAN_F12R2_FB30_Msk     (0x1U << CAN_F12R2_FB30_Pos)
#define CAN_F12R2_FB30         CAN_F12R2_FB30_Msk
#define CAN_F12R2_FB31_Pos     (31U)
#define CAN_F12R2_FB31_Msk     (0x1U << CAN_F12R2_FB31_Pos)
#define CAN_F12R2_FB31         CAN_F12R2_FB31_Msk


#define CAN_F13R2_FB0_Pos      (0U)
#define CAN_F13R2_FB0_Msk      (0x1U << CAN_F13R2_FB0_Pos)
#define CAN_F13R2_FB0          CAN_F13R2_FB0_Msk
#define CAN_F13R2_FB1_Pos      (1U)
#define CAN_F13R2_FB1_Msk      (0x1U << CAN_F13R2_FB1_Pos)
#define CAN_F13R2_FB1          CAN_F13R2_FB1_Msk
#define CAN_F13R2_FB2_Pos      (2U)
#define CAN_F13R2_FB2_Msk      (0x1U << CAN_F13R2_FB2_Pos)
#define CAN_F13R2_FB2          CAN_F13R2_FB2_Msk
#define CAN_F13R2_FB3_Pos      (3U)
#define CAN_F13R2_FB3_Msk      (0x1U << CAN_F13R2_FB3_Pos)
#define CAN_F13R2_FB3          CAN_F13R2_FB3_Msk
#define CAN_F13R2_FB4_Pos      (4U)
#define CAN_F13R2_FB4_Msk      (0x1U << CAN_F13R2_FB4_Pos)
#define CAN_F13R2_FB4          CAN_F13R2_FB4_Msk
#define CAN_F13R2_FB5_Pos      (5U)
#define CAN_F13R2_FB5_Msk      (0x1U << CAN_F13R2_FB5_Pos)
#define CAN_F13R2_FB5          CAN_F13R2_FB5_Msk
#define CAN_F13R2_FB6_Pos      (6U)
#define CAN_F13R2_FB6_Msk      (0x1U << CAN_F13R2_FB6_Pos)
#define CAN_F13R2_FB6          CAN_F13R2_FB6_Msk
#define CAN_F13R2_FB7_Pos      (7U)
#define CAN_F13R2_FB7_Msk      (0x1U << CAN_F13R2_FB7_Pos)
#define CAN_F13R2_FB7          CAN_F13R2_FB7_Msk
#define CAN_F13R2_FB8_Pos      (8U)
#define CAN_F13R2_FB8_Msk      (0x1U << CAN_F13R2_FB8_Pos)
#define CAN_F13R2_FB8          CAN_F13R2_FB8_Msk
#define CAN_F13R2_FB9_Pos      (9U)
#define CAN_F13R2_FB9_Msk      (0x1U << CAN_F13R2_FB9_Pos)
#define CAN_F13R2_FB9          CAN_F13R2_FB9_Msk
#define CAN_F13R2_FB10_Pos     (10U)
#define CAN_F13R2_FB10_Msk     (0x1U << CAN_F13R2_FB10_Pos)
#define CAN_F13R2_FB10         CAN_F13R2_FB10_Msk
#define CAN_F13R2_FB11_Pos     (11U)
#define CAN_F13R2_FB11_Msk     (0x1U << CAN_F13R2_FB11_Pos)
#define CAN_F13R2_FB11         CAN_F13R2_FB11_Msk
#define CAN_F13R2_FB12_Pos     (12U)
#define CAN_F13R2_FB12_Msk     (0x1U << CAN_F13R2_FB12_Pos)
#define CAN_F13R2_FB12         CAN_F13R2_FB12_Msk
#define CAN_F13R2_FB13_Pos     (13U)
#define CAN_F13R2_FB13_Msk     (0x1U << CAN_F13R2_FB13_Pos)
#define CAN_F13R2_FB13         CAN_F13R2_FB13_Msk
#define CAN_F13R2_FB14_Pos     (14U)
#define CAN_F13R2_FB14_Msk     (0x1U << CAN_F13R2_FB14_Pos)
#define CAN_F13R2_FB14         CAN_F13R2_FB14_Msk
#define CAN_F13R2_FB15_Pos     (15U)
#define CAN_F13R2_FB15_Msk     (0x1U << CAN_F13R2_FB15_Pos)
#define CAN_F13R2_FB15         CAN_F13R2_FB15_Msk
#define CAN_F13R2_FB16_Pos     (16U)
#define CAN_F13R2_FB16_Msk     (0x1U << CAN_F13R2_FB16_Pos)
#define CAN_F13R2_FB16         CAN_F13R2_FB16_Msk
#define CAN_F13R2_FB17_Pos     (17U)
#define CAN_F13R2_FB17_Msk     (0x1U << CAN_F13R2_FB17_Pos)
#define CAN_F13R2_FB17         CAN_F13R2_FB17_Msk
#define CAN_F13R2_FB18_Pos     (18U)
#define CAN_F13R2_FB18_Msk     (0x1U << CAN_F13R2_FB18_Pos)
#define CAN_F13R2_FB18         CAN_F13R2_FB18_Msk
#define CAN_F13R2_FB19_Pos     (19U)
#define CAN_F13R2_FB19_Msk     (0x1U << CAN_F13R2_FB19_Pos)
#define CAN_F13R2_FB19         CAN_F13R2_FB19_Msk
#define CAN_F13R2_FB20_Pos     (20U)
#define CAN_F13R2_FB20_Msk     (0x1U << CAN_F13R2_FB20_Pos)
#define CAN_F13R2_FB20         CAN_F13R2_FB20_Msk
#define CAN_F13R2_FB21_Pos     (21U)
#define CAN_F13R2_FB21_Msk     (0x1U << CAN_F13R2_FB21_Pos)
#define CAN_F13R2_FB21         CAN_F13R2_FB21_Msk
#define CAN_F13R2_FB22_Pos     (22U)
#define CAN_F13R2_FB22_Msk     (0x1U << CAN_F13R2_FB22_Pos)
#define CAN_F13R2_FB22         CAN_F13R2_FB22_Msk
#define CAN_F13R2_FB23_Pos     (23U)
#define CAN_F13R2_FB23_Msk     (0x1U << CAN_F13R2_FB23_Pos)
#define CAN_F13R2_FB23         CAN_F13R2_FB23_Msk
#define CAN_F13R2_FB24_Pos     (24U)
#define CAN_F13R2_FB24_Msk     (0x1U << CAN_F13R2_FB24_Pos)
#define CAN_F13R2_FB24         CAN_F13R2_FB24_Msk
#define CAN_F13R2_FB25_Pos     (25U)
#define CAN_F13R2_FB25_Msk     (0x1U << CAN_F13R2_FB25_Pos)
#define CAN_F13R2_FB25         CAN_F13R2_FB25_Msk
#define CAN_F13R2_FB26_Pos     (26U)
#define CAN_F13R2_FB26_Msk     (0x1U << CAN_F13R2_FB26_Pos)
#define CAN_F13R2_FB26         CAN_F13R2_FB26_Msk
#define CAN_F13R2_FB27_Pos     (27U)
#define CAN_F13R2_FB27_Msk     (0x1U << CAN_F13R2_FB27_Pos)
#define CAN_F13R2_FB27         CAN_F13R2_FB27_Msk
#define CAN_F13R2_FB28_Pos     (28U)
#define CAN_F13R2_FB28_Msk     (0x1U << CAN_F13R2_FB28_Pos)
#define CAN_F13R2_FB28         CAN_F13R2_FB28_Msk
#define CAN_F13R2_FB29_Pos     (29U)
#define CAN_F13R2_FB29_Msk     (0x1U << CAN_F13R2_FB29_Pos)
#define CAN_F13R2_FB29         CAN_F13R2_FB29_Msk
#define CAN_F13R2_FB30_Pos     (30U)
#define CAN_F13R2_FB30_Msk     (0x1U << CAN_F13R2_FB30_Pos)
#define CAN_F13R2_FB30         CAN_F13R2_FB30_Msk
#define CAN_F13R2_FB31_Pos     (31U)
#define CAN_F13R2_FB31_Msk     (0x1U << CAN_F13R2_FB31_Pos)
#define CAN_F13R2_FB31         CAN_F13R2_FB31_Msk







#define CRC_DR_DR_Pos            (0U)
#define CRC_DR_DR_Msk            (0xFFFFFFFFU << CRC_DR_DR_Pos)
#define CRC_DR_DR                CRC_DR_DR_Msk


#define CRC_IDR_IDR              ((uint8_t)0xFFU)


#define CRC_CR_RESET_Pos         (0U)
#define CRC_CR_RESET_Msk         (0x1U << CRC_CR_RESET_Pos)
#define CRC_CR_RESET             CRC_CR_RESET_Msk
#define CRC_CR_POLYSIZE_Pos      (3U)
#define CRC_CR_POLYSIZE_Msk      (0x3U << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_POLYSIZE          CRC_CR_POLYSIZE_Msk
#define CRC_CR_POLYSIZE_0        (0x1U << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_POLYSIZE_1        (0x2U << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_REV_IN_Pos        (5U)
#define CRC_CR_REV_IN_Msk        (0x3U << CRC_CR_REV_IN_Pos)
#define CRC_CR_REV_IN            CRC_CR_REV_IN_Msk
#define CRC_CR_REV_IN_0          (0x1U << CRC_CR_REV_IN_Pos)
#define CRC_CR_REV_IN_1          (0x2U << CRC_CR_REV_IN_Pos)
#define CRC_CR_REV_OUT_Pos       (7U)
#define CRC_CR_REV_OUT_Msk       (0x1U << CRC_CR_REV_OUT_Pos)
#define CRC_CR_REV_OUT           CRC_CR_REV_OUT_Msk


#define CRC_INIT_INIT_Pos        (0U)
#define CRC_INIT_INIT_Msk        (0xFFFFFFFFU << CRC_INIT_INIT_Pos)
#define CRC_INIT_INIT            CRC_INIT_INIT_Msk


#define CRC_POL_POL_Pos          (0U)
#define CRC_POL_POL_Msk          (0xFFFFFFFFU << CRC_POL_POL_Pos)
#define CRC_POL_POL              CRC_POL_POL_Msk










#define DAC_CHANNEL2_SUPPORT



#define DAC_CR_EN1_Pos              (0U)
#define DAC_CR_EN1_Msk              (0x1U << DAC_CR_EN1_Pos)
#define DAC_CR_EN1                  DAC_CR_EN1_Msk
#define DAC_CR_BOFF1_Pos            (1U)
#define DAC_CR_BOFF1_Msk            (0x1U << DAC_CR_BOFF1_Pos)
#define DAC_CR_BOFF1                DAC_CR_BOFF1_Msk
#define DAC_CR_OUTEN1_Pos           (1U)
#define DAC_CR_OUTEN1_Msk           (0x1U << DAC_CR_OUTEN1_Pos)
#define DAC_CR_OUTEN1               DAC_CR_OUTEN1_Msk
#define DAC_CR_TEN1_Pos             (2U)
#define DAC_CR_TEN1_Msk             (0x1U << DAC_CR_TEN1_Pos)
#define DAC_CR_TEN1                 DAC_CR_TEN1_Msk

#define DAC_CR_TSEL1_Pos            (3U)
#define DAC_CR_TSEL1_Msk            (0x7U << DAC_CR_TSEL1_Pos)
#define DAC_CR_TSEL1                DAC_CR_TSEL1_Msk
#define DAC_CR_TSEL1_0              (0x1U << DAC_CR_TSEL1_Pos)
#define DAC_CR_TSEL1_1              (0x2U << DAC_CR_TSEL1_Pos)
#define DAC_CR_TSEL1_2              (0x4U << DAC_CR_TSEL1_Pos)

#define DAC_CR_WAVE1_Pos            (6U)
#define DAC_CR_WAVE1_Msk            (0x3U << DAC_CR_WAVE1_Pos)
#define DAC_CR_WAVE1                DAC_CR_WAVE1_Msk
#define DAC_CR_WAVE1_0              (0x1U << DAC_CR_WAVE1_Pos)
#define DAC_CR_WAVE1_1              (0x2U << DAC_CR_WAVE1_Pos)

#define DAC_CR_MAMP1_Pos            (8U)
#define DAC_CR_MAMP1_Msk            (0xFU << DAC_CR_MAMP1_Pos)
#define DAC_CR_MAMP1                DAC_CR_MAMP1_Msk
#define DAC_CR_MAMP1_0              (0x1U << DAC_CR_MAMP1_Pos)
#define DAC_CR_MAMP1_1              (0x2U << DAC_CR_MAMP1_Pos)
#define DAC_CR_MAMP1_2              (0x4U << DAC_CR_MAMP1_Pos)
#define DAC_CR_MAMP1_3              (0x8U << DAC_CR_MAMP1_Pos)

#define DAC_CR_DMAEN1_Pos           (12U)
#define DAC_CR_DMAEN1_Msk           (0x1U << DAC_CR_DMAEN1_Pos)
#define DAC_CR_DMAEN1               DAC_CR_DMAEN1_Msk
#define DAC_CR_DMAUDRIE1_Pos        (13U)
#define DAC_CR_DMAUDRIE1_Msk        (0x1U << DAC_CR_DMAUDRIE1_Pos)
#define DAC_CR_DMAUDRIE1            DAC_CR_DMAUDRIE1_Msk
#define DAC_CR_EN2_Pos              (16U)
#define DAC_CR_EN2_Msk              (0x1U << DAC_CR_EN2_Pos)
#define DAC_CR_EN2                  DAC_CR_EN2_Msk
#define DAC_CR_BOFF2_Pos            (17U)
#define DAC_CR_BOFF2_Msk            (0x1U << DAC_CR_BOFF2_Pos)
#define DAC_CR_BOFF2                DAC_CR_BOFF2_Msk
#define DAC_CR_OUTEN2_Pos           (17U)
#define DAC_CR_OUTEN2_Msk           (0x1U << DAC_CR_OUTEN2_Pos)
#define DAC_CR_OUTEN2               DAC_CR_OUTEN2_Msk
#define DAC_CR_TEN2_Pos             (18U)
#define DAC_CR_TEN2_Msk             (0x1U << DAC_CR_TEN2_Pos)
#define DAC_CR_TEN2                 DAC_CR_TEN2_Msk

#define DAC_CR_TSEL2_Pos            (19U)
#define DAC_CR_TSEL2_Msk            (0x7U << DAC_CR_TSEL2_Pos)
#define DAC_CR_TSEL2                DAC_CR_TSEL2_Msk
#define DAC_CR_TSEL2_0              (0x1U << DAC_CR_TSEL2_Pos)
#define DAC_CR_TSEL2_1              (0x2U << DAC_CR_TSEL2_Pos)
#define DAC_CR_TSEL2_2              (0x4U << DAC_CR_TSEL2_Pos)

#define DAC_CR_WAVE2_Pos            (22U)
#define DAC_CR_WAVE2_Msk            (0x3U << DAC_CR_WAVE2_Pos)
#define DAC_CR_WAVE2                DAC_CR_WAVE2_Msk
#define DAC_CR_WAVE2_0              (0x1U << DAC_CR_WAVE2_Pos)
#define DAC_CR_WAVE2_1              (0x2U << DAC_CR_WAVE2_Pos)

#define DAC_CR_MAMP2_Pos            (24U)
#define DAC_CR_MAMP2_Msk            (0xFU << DAC_CR_MAMP2_Pos)
#define DAC_CR_MAMP2                DAC_CR_MAMP2_Msk
#define DAC_CR_MAMP2_0              (0x1U << DAC_CR_MAMP2_Pos)
#define DAC_CR_MAMP2_1              (0x2U << DAC_CR_MAMP2_Pos)
#define DAC_CR_MAMP2_2              (0x4U << DAC_CR_MAMP2_Pos)
#define DAC_CR_MAMP2_3              (0x8U << DAC_CR_MAMP2_Pos)

#define DAC_CR_DMAEN2_Pos           (28U)
#define DAC_CR_DMAEN2_Msk           (0x1U << DAC_CR_DMAEN2_Pos)
#define DAC_CR_DMAEN2               DAC_CR_DMAEN2_Msk
#define DAC_CR_DMAUDRIE2_Pos        (29U)
#define DAC_CR_DMAUDRIE2_Msk        (0x1U << DAC_CR_DMAUDRIE2_Pos)
#define DAC_CR_DMAUDRIE2            DAC_CR_DMAUDRIE2_Msk


#define DAC_SWTRIGR_SWTRIG1_Pos     (0U)
#define DAC_SWTRIGR_SWTRIG1_Msk     (0x1U << DAC_SWTRIGR_SWTRIG1_Pos)
#define DAC_SWTRIGR_SWTRIG1         DAC_SWTRIGR_SWTRIG1_Msk
#define DAC_SWTRIGR_SWTRIG2_Pos     (1U)
#define DAC_SWTRIGR_SWTRIG2_Msk     (0x1U << DAC_SWTRIGR_SWTRIG2_Pos)
#define DAC_SWTRIGR_SWTRIG2         DAC_SWTRIGR_SWTRIG2_Msk


#define DAC_DHR12R1_DACC1DHR_Pos    (0U)
#define DAC_DHR12R1_DACC1DHR_Msk    (0xFFFU << DAC_DHR12R1_DACC1DHR_Pos)
#define DAC_DHR12R1_DACC1DHR        DAC_DHR12R1_DACC1DHR_Msk


#define DAC_DHR12L1_DACC1DHR_Pos    (4U)
#define DAC_DHR12L1_DACC1DHR_Msk    (0xFFFU << DAC_DHR12L1_DACC1DHR_Pos)
#define DAC_DHR12L1_DACC1DHR        DAC_DHR12L1_DACC1DHR_Msk


#define DAC_DHR8R1_DACC1DHR_Pos     (0U)
#define DAC_DHR8R1_DACC1DHR_Msk     (0xFFU << DAC_DHR8R1_DACC1DHR_Pos)
#define DAC_DHR8R1_DACC1DHR         DAC_DHR8R1_DACC1DHR_Msk


#define DAC_DHR12R2_DACC2DHR_Pos    (0U)
#define DAC_DHR12R2_DACC2DHR_Msk    (0xFFFU << DAC_DHR12R2_DACC2DHR_Pos)
#define DAC_DHR12R2_DACC2DHR        DAC_DHR12R2_DACC2DHR_Msk


#define DAC_DHR12L2_DACC2DHR_Pos    (4U)
#define DAC_DHR12L2_DACC2DHR_Msk    (0xFFFU << DAC_DHR12L2_DACC2DHR_Pos)
#define DAC_DHR12L2_DACC2DHR        DAC_DHR12L2_DACC2DHR_Msk


#define DAC_DHR8R2_DACC2DHR_Pos     (0U)
#define DAC_DHR8R2_DACC2DHR_Msk     (0xFFU << DAC_DHR8R2_DACC2DHR_Pos)
#define DAC_DHR8R2_DACC2DHR         DAC_DHR8R2_DACC2DHR_Msk


#define DAC_DHR12RD_DACC1DHR_Pos    (0U)
#define DAC_DHR12RD_DACC1DHR_Msk    (0xFFFU << DAC_DHR12RD_DACC1DHR_Pos)
#define DAC_DHR12RD_DACC1DHR        DAC_DHR12RD_DACC1DHR_Msk
#define DAC_DHR12RD_DACC2DHR_Pos    (16U)
#define DAC_DHR12RD_DACC2DHR_Msk    (0xFFFU << DAC_DHR12RD_DACC2DHR_Pos)
#define DAC_DHR12RD_DACC2DHR        DAC_DHR12RD_DACC2DHR_Msk


#define DAC_DHR12LD_DACC1DHR_Pos    (4U)
#define DAC_DHR12LD_DACC1DHR_Msk    (0xFFFU << DAC_DHR12LD_DACC1DHR_Pos)
#define DAC_DHR12LD_DACC1DHR        DAC_DHR12LD_DACC1DHR_Msk
#define DAC_DHR12LD_DACC2DHR_Pos    (20U)
#define DAC_DHR12LD_DACC2DHR_Msk    (0xFFFU << DAC_DHR12LD_DACC2DHR_Pos)
#define DAC_DHR12LD_DACC2DHR        DAC_DHR12LD_DACC2DHR_Msk


#define DAC_DHR8RD_DACC1DHR_Pos     (0U)
#define DAC_DHR8RD_DACC1DHR_Msk     (0xFFU << DAC_DHR8RD_DACC1DHR_Pos)
#define DAC_DHR8RD_DACC1DHR         DAC_DHR8RD_DACC1DHR_Msk
#define DAC_DHR8RD_DACC2DHR_Pos     (8U)
#define DAC_DHR8RD_DACC2DHR_Msk     (0xFFU << DAC_DHR8RD_DACC2DHR_Pos)
#define DAC_DHR8RD_DACC2DHR         DAC_DHR8RD_DACC2DHR_Msk


#define DAC_DOR1_DACC1DOR_Pos       (0U)
#define DAC_DOR1_DACC1DOR_Msk       (0xFFFU << DAC_DOR1_DACC1DOR_Pos)
#define DAC_DOR1_DACC1DOR           DAC_DOR1_DACC1DOR_Msk


#define DAC_DOR2_DACC2DOR_Pos       (0U)
#define DAC_DOR2_DACC2DOR_Msk       (0xFFFU << DAC_DOR2_DACC2DOR_Pos)
#define DAC_DOR2_DACC2DOR           DAC_DOR2_DACC2DOR_Msk


#define DAC_SR_DMAUDR1_Pos          (13U)
#define DAC_SR_DMAUDR1_Msk          (0x1U << DAC_SR_DMAUDR1_Pos)
#define DAC_SR_DMAUDR1              DAC_SR_DMAUDR1_Msk
#define DAC_SR_DMAUDR2_Pos          (29U)
#define DAC_SR_DMAUDR2_Msk          (0x1U << DAC_SR_DMAUDR2_Pos)
#define DAC_SR_DMAUDR2              DAC_SR_DMAUDR2_Msk







#define DBGMCU_IDCODE_DEV_ID_Pos                     (0U)
#define DBGMCU_IDCODE_DEV_ID_Msk                     (0xFFFU << DBGMCU_IDCODE_DEV_ID_Pos)
#define DBGMCU_IDCODE_DEV_ID                         DBGMCU_IDCODE_DEV_ID_Msk
#define DBGMCU_IDCODE_REV_ID_Pos                     (16U)
#define DBGMCU_IDCODE_REV_ID_Msk                     (0xFFFFU << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID                         DBGMCU_IDCODE_REV_ID_Msk


#define DBGMCU_CR_DBG_SLEEP_Pos                      (0U)
#define DBGMCU_CR_DBG_SLEEP_Msk                      (0x1U << DBGMCU_CR_DBG_SLEEP_Pos)
#define DBGMCU_CR_DBG_SLEEP                          DBGMCU_CR_DBG_SLEEP_Msk
#define DBGMCU_CR_DBG_STOP_Pos                       (1U)
#define DBGMCU_CR_DBG_STOP_Msk                       (0x1U << DBGMCU_CR_DBG_STOP_Pos)
#define DBGMCU_CR_DBG_STOP                           DBGMCU_CR_DBG_STOP_Msk
#define DBGMCU_CR_DBG_STANDBY_Pos                    (2U)
#define DBGMCU_CR_DBG_STANDBY_Msk                    (0x1U << DBGMCU_CR_DBG_STANDBY_Pos)
#define DBGMCU_CR_DBG_STANDBY                        DBGMCU_CR_DBG_STANDBY_Msk
#define DBGMCU_CR_TRACE_IOEN_Pos                     (5U)
#define DBGMCU_CR_TRACE_IOEN_Msk                     (0x1U << DBGMCU_CR_TRACE_IOEN_Pos)
#define DBGMCU_CR_TRACE_IOEN                         DBGMCU_CR_TRACE_IOEN_Msk

#define DBGMCU_CR_TRACE_MODE_Pos                     (6U)
#define DBGMCU_CR_TRACE_MODE_Msk                     (0x3U << DBGMCU_CR_TRACE_MODE_Pos)
#define DBGMCU_CR_TRACE_MODE                         DBGMCU_CR_TRACE_MODE_Msk
#define DBGMCU_CR_TRACE_MODE_0                       (0x1U << DBGMCU_CR_TRACE_MODE_Pos)
#define DBGMCU_CR_TRACE_MODE_1                       (0x2U << DBGMCU_CR_TRACE_MODE_Pos)


#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos             (0U)
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos)
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP                 DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos             (1U)
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos)
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP                 DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos             (4U)
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos)
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP                 DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos             (5U)
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos)
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP                 DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos              (10U)
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk              (0x1U << DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos)
#define DBGMCU_APB1_FZ_DBG_RTC_STOP                  DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos             (11U)
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos)
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP                 DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos             (12U)
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk             (0x1U << DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos)
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP                 DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos    (21U)
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk    (0x1U << DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos)
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT        DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk
#define DBGMCU_APB1_FZ_DBG_CAN_STOP_Pos              (25U)
#define DBGMCU_APB1_FZ_DBG_CAN_STOP_Msk              (0x1U << DBGMCU_APB1_FZ_DBG_CAN_STOP_Pos)
#define DBGMCU_APB1_FZ_DBG_CAN_STOP                  DBGMCU_APB1_FZ_DBG_CAN_STOP_Msk


#define DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos             (0U)
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk             (0x1U << DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos)
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP                 DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk
#define DBGMCU_APB2_FZ_DBG_TIM15_STOP_Pos            (2U)
#define DBGMCU_APB2_FZ_DBG_TIM15_STOP_Msk            (0x1U << DBGMCU_APB2_FZ_DBG_TIM15_STOP_Pos)
#define DBGMCU_APB2_FZ_DBG_TIM15_STOP                DBGMCU_APB2_FZ_DBG_TIM15_STOP_Msk
#define DBGMCU_APB2_FZ_DBG_TIM16_STOP_Pos            (3U)
#define DBGMCU_APB2_FZ_DBG_TIM16_STOP_Msk            (0x1U << DBGMCU_APB2_FZ_DBG_TIM16_STOP_Pos)
#define DBGMCU_APB2_FZ_DBG_TIM16_STOP                DBGMCU_APB2_FZ_DBG_TIM16_STOP_Msk
#define DBGMCU_APB2_FZ_DBG_TIM17_STOP_Pos            (4U)
#define DBGMCU_APB2_FZ_DBG_TIM17_STOP_Msk            (0x1U << DBGMCU_APB2_FZ_DBG_TIM17_STOP_Pos)
#define DBGMCU_APB2_FZ_DBG_TIM17_STOP                DBGMCU_APB2_FZ_DBG_TIM17_STOP_Msk







#define DMA_ISR_GIF1_Pos       (0U)
#define DMA_ISR_GIF1_Msk       (0x1U << DMA_ISR_GIF1_Pos)
#define DMA_ISR_GIF1           DMA_ISR_GIF1_Msk
#define DMA_ISR_TCIF1_Pos      (1U)
#define DMA_ISR_TCIF1_Msk      (0x1U << DMA_ISR_TCIF1_Pos)
#define DMA_ISR_TCIF1          DMA_ISR_TCIF1_Msk
#define DMA_ISR_HTIF1_Pos      (2U)
#define DMA_ISR_HTIF1_Msk      (0x1U << DMA_ISR_HTIF1_Pos)
#define DMA_ISR_HTIF1          DMA_ISR_HTIF1_Msk
#define DMA_ISR_TEIF1_Pos      (3U)
#define DMA_ISR_TEIF1_Msk      (0x1U << DMA_ISR_TEIF1_Pos)
#define DMA_ISR_TEIF1          DMA_ISR_TEIF1_Msk
#define DMA_ISR_GIF2_Pos       (4U)
#define DMA_ISR_GIF2_Msk       (0x1U << DMA_ISR_GIF2_Pos)
#define DMA_ISR_GIF2           DMA_ISR_GIF2_Msk
#define DMA_ISR_TCIF2_Pos      (5U)
#define DMA_ISR_TCIF2_Msk      (0x1U << DMA_ISR_TCIF2_Pos)
#define DMA_ISR_TCIF2          DMA_ISR_TCIF2_Msk
#define DMA_ISR_HTIF2_Pos      (6U)
#define DMA_ISR_HTIF2_Msk      (0x1U << DMA_ISR_HTIF2_Pos)
#define DMA_ISR_HTIF2          DMA_ISR_HTIF2_Msk
#define DMA_ISR_TEIF2_Pos      (7U)
#define DMA_ISR_TEIF2_Msk      (0x1U << DMA_ISR_TEIF2_Pos)
#define DMA_ISR_TEIF2          DMA_ISR_TEIF2_Msk
#define DMA_ISR_GIF3_Pos       (8U)
#define DMA_ISR_GIF3_Msk       (0x1U << DMA_ISR_GIF3_Pos)
#define DMA_ISR_GIF3           DMA_ISR_GIF3_Msk
#define DMA_ISR_TCIF3_Pos      (9U)
#define DMA_ISR_TCIF3_Msk      (0x1U << DMA_ISR_TCIF3_Pos)
#define DMA_ISR_TCIF3          DMA_ISR_TCIF3_Msk
#define DMA_ISR_HTIF3_Pos      (10U)
#define DMA_ISR_HTIF3_Msk      (0x1U << DMA_ISR_HTIF3_Pos)
#define DMA_ISR_HTIF3          DMA_ISR_HTIF3_Msk
#define DMA_ISR_TEIF3_Pos      (11U)
#define DMA_ISR_TEIF3_Msk      (0x1U << DMA_ISR_TEIF3_Pos)
#define DMA_ISR_TEIF3          DMA_ISR_TEIF3_Msk
#define DMA_ISR_GIF4_Pos       (12U)
#define DMA_ISR_GIF4_Msk       (0x1U << DMA_ISR_GIF4_Pos)
#define DMA_ISR_GIF4           DMA_ISR_GIF4_Msk
#define DMA_ISR_TCIF4_Pos      (13U)
#define DMA_ISR_TCIF4_Msk      (0x1U << DMA_ISR_TCIF4_Pos)
#define DMA_ISR_TCIF4          DMA_ISR_TCIF4_Msk
#define DMA_ISR_HTIF4_Pos      (14U)
#define DMA_ISR_HTIF4_Msk      (0x1U << DMA_ISR_HTIF4_Pos)
#define DMA_ISR_HTIF4          DMA_ISR_HTIF4_Msk
#define DMA_ISR_TEIF4_Pos      (15U)
#define DMA_ISR_TEIF4_Msk      (0x1U << DMA_ISR_TEIF4_Pos)
#define DMA_ISR_TEIF4          DMA_ISR_TEIF4_Msk
#define DMA_ISR_GIF5_Pos       (16U)
#define DMA_ISR_GIF5_Msk       (0x1U << DMA_ISR_GIF5_Pos)
#define DMA_ISR_GIF5           DMA_ISR_GIF5_Msk
#define DMA_ISR_TCIF5_Pos      (17U)
#define DMA_ISR_TCIF5_Msk      (0x1U << DMA_ISR_TCIF5_Pos)
#define DMA_ISR_TCIF5          DMA_ISR_TCIF5_Msk
#define DMA_ISR_HTIF5_Pos      (18U)
#define DMA_ISR_HTIF5_Msk      (0x1U << DMA_ISR_HTIF5_Pos)
#define DMA_ISR_HTIF5          DMA_ISR_HTIF5_Msk
#define DMA_ISR_TEIF5_Pos      (19U)
#define DMA_ISR_TEIF5_Msk      (0x1U << DMA_ISR_TEIF5_Pos)
#define DMA_ISR_TEIF5          DMA_ISR_TEIF5_Msk
#define DMA_ISR_GIF6_Pos       (20U)
#define DMA_ISR_GIF6_Msk       (0x1U << DMA_ISR_GIF6_Pos)
#define DMA_ISR_GIF6           DMA_ISR_GIF6_Msk
#define DMA_ISR_TCIF6_Pos      (21U)
#define DMA_ISR_TCIF6_Msk      (0x1U << DMA_ISR_TCIF6_Pos)
#define DMA_ISR_TCIF6          DMA_ISR_TCIF6_Msk
#define DMA_ISR_HTIF6_Pos      (22U)
#define DMA_ISR_HTIF6_Msk      (0x1U << DMA_ISR_HTIF6_Pos)
#define DMA_ISR_HTIF6          DMA_ISR_HTIF6_Msk
#define DMA_ISR_TEIF6_Pos      (23U)
#define DMA_ISR_TEIF6_Msk      (0x1U << DMA_ISR_TEIF6_Pos)
#define DMA_ISR_TEIF6          DMA_ISR_TEIF6_Msk
#define DMA_ISR_GIF7_Pos       (24U)
#define DMA_ISR_GIF7_Msk       (0x1U << DMA_ISR_GIF7_Pos)
#define DMA_ISR_GIF7           DMA_ISR_GIF7_Msk
#define DMA_ISR_TCIF7_Pos      (25U)
#define DMA_ISR_TCIF7_Msk      (0x1U << DMA_ISR_TCIF7_Pos)
#define DMA_ISR_TCIF7          DMA_ISR_TCIF7_Msk
#define DMA_ISR_HTIF7_Pos      (26U)
#define DMA_ISR_HTIF7_Msk      (0x1U << DMA_ISR_HTIF7_Pos)
#define DMA_ISR_HTIF7          DMA_ISR_HTIF7_Msk
#define DMA_ISR_TEIF7_Pos      (27U)
#define DMA_ISR_TEIF7_Msk      (0x1U << DMA_ISR_TEIF7_Pos)
#define DMA_ISR_TEIF7          DMA_ISR_TEIF7_Msk


#define DMA_IFCR_CGIF1_Pos     (0U)
#define DMA_IFCR_CGIF1_Msk     (0x1U << DMA_IFCR_CGIF1_Pos)
#define DMA_IFCR_CGIF1         DMA_IFCR_CGIF1_Msk
#define DMA_IFCR_CTCIF1_Pos    (1U)
#define DMA_IFCR_CTCIF1_Msk    (0x1U << DMA_IFCR_CTCIF1_Pos)
#define DMA_IFCR_CTCIF1        DMA_IFCR_CTCIF1_Msk
#define DMA_IFCR_CHTIF1_Pos    (2U)
#define DMA_IFCR_CHTIF1_Msk    (0x1U << DMA_IFCR_CHTIF1_Pos)
#define DMA_IFCR_CHTIF1        DMA_IFCR_CHTIF1_Msk
#define DMA_IFCR_CTEIF1_Pos    (3U)
#define DMA_IFCR_CTEIF1_Msk    (0x1U << DMA_IFCR_CTEIF1_Pos)
#define DMA_IFCR_CTEIF1        DMA_IFCR_CTEIF1_Msk
#define DMA_IFCR_CGIF2_Pos     (4U)
#define DMA_IFCR_CGIF2_Msk     (0x1U << DMA_IFCR_CGIF2_Pos)
#define DMA_IFCR_CGIF2         DMA_IFCR_CGIF2_Msk
#define DMA_IFCR_CTCIF2_Pos    (5U)
#define DMA_IFCR_CTCIF2_Msk    (0x1U << DMA_IFCR_CTCIF2_Pos)
#define DMA_IFCR_CTCIF2        DMA_IFCR_CTCIF2_Msk
#define DMA_IFCR_CHTIF2_Pos    (6U)
#define DMA_IFCR_CHTIF2_Msk    (0x1U << DMA_IFCR_CHTIF2_Pos)
#define DMA_IFCR_CHTIF2        DMA_IFCR_CHTIF2_Msk
#define DMA_IFCR_CTEIF2_Pos    (7U)
#define DMA_IFCR_CTEIF2_Msk    (0x1U << DMA_IFCR_CTEIF2_Pos)
#define DMA_IFCR_CTEIF2        DMA_IFCR_CTEIF2_Msk
#define DMA_IFCR_CGIF3_Pos     (8U)
#define DMA_IFCR_CGIF3_Msk     (0x1U << DMA_IFCR_CGIF3_Pos)
#define DMA_IFCR_CGIF3         DMA_IFCR_CGIF3_Msk
#define DMA_IFCR_CTCIF3_Pos    (9U)
#define DMA_IFCR_CTCIF3_Msk    (0x1U << DMA_IFCR_CTCIF3_Pos)
#define DMA_IFCR_CTCIF3        DMA_IFCR_CTCIF3_Msk
#define DMA_IFCR_CHTIF3_Pos    (10U)
#define DMA_IFCR_CHTIF3_Msk    (0x1U << DMA_IFCR_CHTIF3_Pos)
#define DMA_IFCR_CHTIF3        DMA_IFCR_CHTIF3_Msk
#define DMA_IFCR_CTEIF3_Pos    (11U)
#define DMA_IFCR_CTEIF3_Msk    (0x1U << DMA_IFCR_CTEIF3_Pos)
#define DMA_IFCR_CTEIF3        DMA_IFCR_CTEIF3_Msk
#define DMA_IFCR_CGIF4_Pos     (12U)
#define DMA_IFCR_CGIF4_Msk     (0x1U << DMA_IFCR_CGIF4_Pos)
#define DMA_IFCR_CGIF4         DMA_IFCR_CGIF4_Msk
#define DMA_IFCR_CTCIF4_Pos    (13U)
#define DMA_IFCR_CTCIF4_Msk    (0x1U << DMA_IFCR_CTCIF4_Pos)
#define DMA_IFCR_CTCIF4        DMA_IFCR_CTCIF4_Msk
#define DMA_IFCR_CHTIF4_Pos    (14U)
#define DMA_IFCR_CHTIF4_Msk    (0x1U << DMA_IFCR_CHTIF4_Pos)
#define DMA_IFCR_CHTIF4        DMA_IFCR_CHTIF4_Msk
#define DMA_IFCR_CTEIF4_Pos    (15U)
#define DMA_IFCR_CTEIF4_Msk    (0x1U << DMA_IFCR_CTEIF4_Pos)
#define DMA_IFCR_CTEIF4        DMA_IFCR_CTEIF4_Msk
#define DMA_IFCR_CGIF5_Pos     (16U)
#define DMA_IFCR_CGIF5_Msk     (0x1U << DMA_IFCR_CGIF5_Pos)
#define DMA_IFCR_CGIF5         DMA_IFCR_CGIF5_Msk
#define DMA_IFCR_CTCIF5_Pos    (17U)
#define DMA_IFCR_CTCIF5_Msk    (0x1U << DMA_IFCR_CTCIF5_Pos)
#define DMA_IFCR_CTCIF5        DMA_IFCR_CTCIF5_Msk
#define DMA_IFCR_CHTIF5_Pos    (18U)
#define DMA_IFCR_CHTIF5_Msk    (0x1U << DMA_IFCR_CHTIF5_Pos)
#define DMA_IFCR_CHTIF5        DMA_IFCR_CHTIF5_Msk
#define DMA_IFCR_CTEIF5_Pos    (19U)
#define DMA_IFCR_CTEIF5_Msk    (0x1U << DMA_IFCR_CTEIF5_Pos)
#define DMA_IFCR_CTEIF5        DMA_IFCR_CTEIF5_Msk
#define DMA_IFCR_CGIF6_Pos     (20U)
#define DMA_IFCR_CGIF6_Msk     (0x1U << DMA_IFCR_CGIF6_Pos)
#define DMA_IFCR_CGIF6         DMA_IFCR_CGIF6_Msk
#define DMA_IFCR_CTCIF6_Pos    (21U)
#define DMA_IFCR_CTCIF6_Msk    (0x1U << DMA_IFCR_CTCIF6_Pos)
#define DMA_IFCR_CTCIF6        DMA_IFCR_CTCIF6_Msk
#define DMA_IFCR_CHTIF6_Pos    (22U)
#define DMA_IFCR_CHTIF6_Msk    (0x1U << DMA_IFCR_CHTIF6_Pos)
#define DMA_IFCR_CHTIF6        DMA_IFCR_CHTIF6_Msk
#define DMA_IFCR_CTEIF6_Pos    (23U)
#define DMA_IFCR_CTEIF6_Msk    (0x1U << DMA_IFCR_CTEIF6_Pos)
#define DMA_IFCR_CTEIF6        DMA_IFCR_CTEIF6_Msk
#define DMA_IFCR_CGIF7_Pos     (24U)
#define DMA_IFCR_CGIF7_Msk     (0x1U << DMA_IFCR_CGIF7_Pos)
#define DMA_IFCR_CGIF7         DMA_IFCR_CGIF7_Msk
#define DMA_IFCR_CTCIF7_Pos    (25U)
#define DMA_IFCR_CTCIF7_Msk    (0x1U << DMA_IFCR_CTCIF7_Pos)
#define DMA_IFCR_CTCIF7        DMA_IFCR_CTCIF7_Msk
#define DMA_IFCR_CHTIF7_Pos    (26U)
#define DMA_IFCR_CHTIF7_Msk    (0x1U << DMA_IFCR_CHTIF7_Pos)
#define DMA_IFCR_CHTIF7        DMA_IFCR_CHTIF7_Msk
#define DMA_IFCR_CTEIF7_Pos    (27U)
#define DMA_IFCR_CTEIF7_Msk    (0x1U << DMA_IFCR_CTEIF7_Pos)
#define DMA_IFCR_CTEIF7        DMA_IFCR_CTEIF7_Msk


#define DMA_CCR_EN_Pos         (0U)
#define DMA_CCR_EN_Msk         (0x1U << DMA_CCR_EN_Pos)
#define DMA_CCR_EN             DMA_CCR_EN_Msk
#define DMA_CCR_TCIE_Pos       (1U)
#define DMA_CCR_TCIE_Msk       (0x1U << DMA_CCR_TCIE_Pos)
#define DMA_CCR_TCIE           DMA_CCR_TCIE_Msk
#define DMA_CCR_HTIE_Pos       (2U)
#define DMA_CCR_HTIE_Msk       (0x1U << DMA_CCR_HTIE_Pos)
#define DMA_CCR_HTIE           DMA_CCR_HTIE_Msk
#define DMA_CCR_TEIE_Pos       (3U)
#define DMA_CCR_TEIE_Msk       (0x1U << DMA_CCR_TEIE_Pos)
#define DMA_CCR_TEIE           DMA_CCR_TEIE_Msk
#define DMA_CCR_DIR_Pos        (4U)
#define DMA_CCR_DIR_Msk        (0x1U << DMA_CCR_DIR_Pos)
#define DMA_CCR_DIR            DMA_CCR_DIR_Msk
#define DMA_CCR_CIRC_Pos       (5U)
#define DMA_CCR_CIRC_Msk       (0x1U << DMA_CCR_CIRC_Pos)
#define DMA_CCR_CIRC           DMA_CCR_CIRC_Msk
#define DMA_CCR_PINC_Pos       (6U)
#define DMA_CCR_PINC_Msk       (0x1U << DMA_CCR_PINC_Pos)
#define DMA_CCR_PINC           DMA_CCR_PINC_Msk
#define DMA_CCR_MINC_Pos       (7U)
#define DMA_CCR_MINC_Msk       (0x1U << DMA_CCR_MINC_Pos)
#define DMA_CCR_MINC           DMA_CCR_MINC_Msk

#define DMA_CCR_PSIZE_Pos      (8U)
#define DMA_CCR_PSIZE_Msk      (0x3U << DMA_CCR_PSIZE_Pos)
#define DMA_CCR_PSIZE          DMA_CCR_PSIZE_Msk
#define DMA_CCR_PSIZE_0        (0x1U << DMA_CCR_PSIZE_Pos)
#define DMA_CCR_PSIZE_1        (0x2U << DMA_CCR_PSIZE_Pos)

#define DMA_CCR_MSIZE_Pos      (10U)
#define DMA_CCR_MSIZE_Msk      (0x3U << DMA_CCR_MSIZE_Pos)
#define DMA_CCR_MSIZE          DMA_CCR_MSIZE_Msk
#define DMA_CCR_MSIZE_0        (0x1U << DMA_CCR_MSIZE_Pos)
#define DMA_CCR_MSIZE_1        (0x2U << DMA_CCR_MSIZE_Pos)

#define DMA_CCR_PL_Pos         (12U)
#define DMA_CCR_PL_Msk         (0x3U << DMA_CCR_PL_Pos)
#define DMA_CCR_PL             DMA_CCR_PL_Msk
#define DMA_CCR_PL_0           (0x1U << DMA_CCR_PL_Pos)
#define DMA_CCR_PL_1           (0x2U << DMA_CCR_PL_Pos)

#define DMA_CCR_MEM2MEM_Pos    (14U)
#define DMA_CCR_MEM2MEM_Msk    (0x1U << DMA_CCR_MEM2MEM_Pos)
#define DMA_CCR_MEM2MEM        DMA_CCR_MEM2MEM_Msk


#define DMA_CNDTR_NDT_Pos      (0U)
#define DMA_CNDTR_NDT_Msk      (0xFFFFU << DMA_CNDTR_NDT_Pos)
#define DMA_CNDTR_NDT          DMA_CNDTR_NDT_Msk


#define DMA_CPAR_PA_Pos        (0U)
#define DMA_CPAR_PA_Msk        (0xFFFFFFFFU << DMA_CPAR_PA_Pos)
#define DMA_CPAR_PA            DMA_CPAR_PA_Msk


#define DMA_CMAR_MA_Pos        (0U)
#define DMA_CMAR_MA_Msk        (0xFFFFFFFFU << DMA_CMAR_MA_Pos)
#define DMA_CMAR_MA            DMA_CMAR_MA_Msk







#define EXTI_IMR_MR0_Pos           (0U)
#define EXTI_IMR_MR0_Msk           (0x1U << EXTI_IMR_MR0_Pos)
#define EXTI_IMR_MR0               EXTI_IMR_MR0_Msk
#define EXTI_IMR_MR1_Pos           (1U)
#define EXTI_IMR_MR1_Msk           (0x1U << EXTI_IMR_MR1_Pos)
#define EXTI_IMR_MR1               EXTI_IMR_MR1_Msk
#define EXTI_IMR_MR2_Pos           (2U)
#define EXTI_IMR_MR2_Msk           (0x1U << EXTI_IMR_MR2_Pos)
#define EXTI_IMR_MR2               EXTI_IMR_MR2_Msk
#define EXTI_IMR_MR3_Pos           (3U)
#define EXTI_IMR_MR3_Msk           (0x1U << EXTI_IMR_MR3_Pos)
#define EXTI_IMR_MR3               EXTI_IMR_MR3_Msk
#define EXTI_IMR_MR4_Pos           (4U)
#define EXTI_IMR_MR4_Msk           (0x1U << EXTI_IMR_MR4_Pos)
#define EXTI_IMR_MR4               EXTI_IMR_MR4_Msk
#define EXTI_IMR_MR5_Pos           (5U)
#define EXTI_IMR_MR5_Msk           (0x1U << EXTI_IMR_MR5_Pos)
#define EXTI_IMR_MR5               EXTI_IMR_MR5_Msk
#define EXTI_IMR_MR6_Pos           (6U)
#define EXTI_IMR_MR6_Msk           (0x1U << EXTI_IMR_MR6_Pos)
#define EXTI_IMR_MR6               EXTI_IMR_MR6_Msk
#define EXTI_IMR_MR7_Pos           (7U)
#define EXTI_IMR_MR7_Msk           (0x1U << EXTI_IMR_MR7_Pos)
#define EXTI_IMR_MR7               EXTI_IMR_MR7_Msk
#define EXTI_IMR_MR8_Pos           (8U)
#define EXTI_IMR_MR8_Msk           (0x1U << EXTI_IMR_MR8_Pos)
#define EXTI_IMR_MR8               EXTI_IMR_MR8_Msk
#define EXTI_IMR_MR9_Pos           (9U)
#define EXTI_IMR_MR9_Msk           (0x1U << EXTI_IMR_MR9_Pos)
#define EXTI_IMR_MR9               EXTI_IMR_MR9_Msk
#define EXTI_IMR_MR10_Pos          (10U)
#define EXTI_IMR_MR10_Msk          (0x1U << EXTI_IMR_MR10_Pos)
#define EXTI_IMR_MR10              EXTI_IMR_MR10_Msk
#define EXTI_IMR_MR11_Pos          (11U)
#define EXTI_IMR_MR11_Msk          (0x1U << EXTI_IMR_MR11_Pos)
#define EXTI_IMR_MR11              EXTI_IMR_MR11_Msk
#define EXTI_IMR_MR12_Pos          (12U)
#define EXTI_IMR_MR12_Msk          (0x1U << EXTI_IMR_MR12_Pos)
#define EXTI_IMR_MR12              EXTI_IMR_MR12_Msk
#define EXTI_IMR_MR13_Pos          (13U)
#define EXTI_IMR_MR13_Msk          (0x1U << EXTI_IMR_MR13_Pos)
#define EXTI_IMR_MR13              EXTI_IMR_MR13_Msk
#define EXTI_IMR_MR14_Pos          (14U)
#define EXTI_IMR_MR14_Msk          (0x1U << EXTI_IMR_MR14_Pos)
#define EXTI_IMR_MR14              EXTI_IMR_MR14_Msk
#define EXTI_IMR_MR15_Pos          (15U)
#define EXTI_IMR_MR15_Msk          (0x1U << EXTI_IMR_MR15_Pos)
#define EXTI_IMR_MR15              EXTI_IMR_MR15_Msk
#define EXTI_IMR_MR16_Pos          (16U)
#define EXTI_IMR_MR16_Msk          (0x1U << EXTI_IMR_MR16_Pos)
#define EXTI_IMR_MR16              EXTI_IMR_MR16_Msk
#define EXTI_IMR_MR17_Pos          (17U)
#define EXTI_IMR_MR17_Msk          (0x1U << EXTI_IMR_MR17_Pos)
#define EXTI_IMR_MR17              EXTI_IMR_MR17_Msk
#define EXTI_IMR_MR19_Pos          (19U)
#define EXTI_IMR_MR19_Msk          (0x1U << EXTI_IMR_MR19_Pos)
#define EXTI_IMR_MR19              EXTI_IMR_MR19_Msk
#define EXTI_IMR_MR20_Pos          (20U)
#define EXTI_IMR_MR20_Msk          (0x1U << EXTI_IMR_MR20_Pos)
#define EXTI_IMR_MR20              EXTI_IMR_MR20_Msk
#define EXTI_IMR_MR22_Pos          (22U)
#define EXTI_IMR_MR22_Msk          (0x1U << EXTI_IMR_MR22_Pos)
#define EXTI_IMR_MR22              EXTI_IMR_MR22_Msk
#define EXTI_IMR_MR23_Pos          (23U)
#define EXTI_IMR_MR23_Msk          (0x1U << EXTI_IMR_MR23_Pos)
#define EXTI_IMR_MR23              EXTI_IMR_MR23_Msk
#define EXTI_IMR_MR25_Pos          (25U)
#define EXTI_IMR_MR25_Msk          (0x1U << EXTI_IMR_MR25_Pos)
#define EXTI_IMR_MR25              EXTI_IMR_MR25_Msk
#define EXTI_IMR_MR30_Pos          (30U)
#define EXTI_IMR_MR30_Msk          (0x1U << EXTI_IMR_MR30_Pos)
#define EXTI_IMR_MR30              EXTI_IMR_MR30_Msk


#define  EXTI_IMR_IM0 EXTI_IMR_MR0
#define  EXTI_IMR_IM1 EXTI_IMR_MR1
#define  EXTI_IMR_IM2 EXTI_IMR_MR2
#define  EXTI_IMR_IM3 EXTI_IMR_MR3
#define  EXTI_IMR_IM4 EXTI_IMR_MR4
#define  EXTI_IMR_IM5 EXTI_IMR_MR5
#define  EXTI_IMR_IM6 EXTI_IMR_MR6
#define  EXTI_IMR_IM7 EXTI_IMR_MR7
#define  EXTI_IMR_IM8 EXTI_IMR_MR8
#define  EXTI_IMR_IM9 EXTI_IMR_MR9
#define  EXTI_IMR_IM10 EXTI_IMR_MR10
#define  EXTI_IMR_IM11 EXTI_IMR_MR11
#define  EXTI_IMR_IM12 EXTI_IMR_MR12
#define  EXTI_IMR_IM13 EXTI_IMR_MR13
#define  EXTI_IMR_IM14 EXTI_IMR_MR14
#define  EXTI_IMR_IM15 EXTI_IMR_MR15
#define  EXTI_IMR_IM16 EXTI_IMR_MR16
#define  EXTI_IMR_IM17 EXTI_IMR_MR17
#if defined(EXTI_IMR_MR18)
#define  EXTI_IMR_IM18 EXTI_IMR_MR18
#endif
#define  EXTI_IMR_IM19 EXTI_IMR_MR19
#define  EXTI_IMR_IM20 EXTI_IMR_MR20
#if defined(EXTI_IMR_MR21)
#define  EXTI_IMR_IM21 EXTI_IMR_MR21
#endif
#define  EXTI_IMR_IM22 EXTI_IMR_MR22
#define  EXTI_IMR_IM23 EXTI_IMR_MR23
#if defined(EXTI_IMR_MR24)
#define  EXTI_IMR_IM24 EXTI_IMR_MR24
#endif
#define  EXTI_IMR_IM25 EXTI_IMR_MR25
#if defined(EXTI_IMR_MR26)
#define  EXTI_IMR_IM26 EXTI_IMR_MR26
#endif
#if defined(EXTI_IMR_MR27)
#define  EXTI_IMR_IM27 EXTI_IMR_MR27
#endif
#if defined(EXTI_IMR_MR28)
#define  EXTI_IMR_IM28 EXTI_IMR_MR28
#endif
#if defined(EXTI_IMR_MR29)
#define  EXTI_IMR_IM29 EXTI_IMR_MR29
#endif
#define  EXTI_IMR_IM30 EXTI_IMR_MR30
#if defined(EXTI_IMR_MR31)
#define  EXTI_IMR_IM31 EXTI_IMR_MR31
#endif

#define EXTI_IMR_IM_Pos            (0U)
#define EXTI_IMR_IM_Msk            (0xFFFFFFFFU << EXTI_IMR_IM_Pos)
#define EXTI_IMR_IM                EXTI_IMR_IM_Msk


#define EXTI_EMR_MR0_Pos           (0U)
#define EXTI_EMR_MR0_Msk           (0x1U << EXTI_EMR_MR0_Pos)
#define EXTI_EMR_MR0               EXTI_EMR_MR0_Msk
#define EXTI_EMR_MR1_Pos           (1U)
#define EXTI_EMR_MR1_Msk           (0x1U << EXTI_EMR_MR1_Pos)
#define EXTI_EMR_MR1               EXTI_EMR_MR1_Msk
#define EXTI_EMR_MR2_Pos           (2U)
#define EXTI_EMR_MR2_Msk           (0x1U << EXTI_EMR_MR2_Pos)
#define EXTI_EMR_MR2               EXTI_EMR_MR2_Msk
#define EXTI_EMR_MR3_Pos           (3U)
#define EXTI_EMR_MR3_Msk           (0x1U << EXTI_EMR_MR3_Pos)
#define EXTI_EMR_MR3               EXTI_EMR_MR3_Msk
#define EXTI_EMR_MR4_Pos           (4U)
#define EXTI_EMR_MR4_Msk           (0x1U << EXTI_EMR_MR4_Pos)
#define EXTI_EMR_MR4               EXTI_EMR_MR4_Msk
#define EXTI_EMR_MR5_Pos           (5U)
#define EXTI_EMR_MR5_Msk           (0x1U << EXTI_EMR_MR5_Pos)
#define EXTI_EMR_MR5               EXTI_EMR_MR5_Msk
#define EXTI_EMR_MR6_Pos           (6U)
#define EXTI_EMR_MR6_Msk           (0x1U << EXTI_EMR_MR6_Pos)
#define EXTI_EMR_MR6               EXTI_EMR_MR6_Msk
#define EXTI_EMR_MR7_Pos           (7U)
#define EXTI_EMR_MR7_Msk           (0x1U << EXTI_EMR_MR7_Pos)
#define EXTI_EMR_MR7               EXTI_EMR_MR7_Msk
#define EXTI_EMR_MR8_Pos           (8U)
#define EXTI_EMR_MR8_Msk           (0x1U << EXTI_EMR_MR8_Pos)
#define EXTI_EMR_MR8               EXTI_EMR_MR8_Msk
#define EXTI_EMR_MR9_Pos           (9U)
#define EXTI_EMR_MR9_Msk           (0x1U << EXTI_EMR_MR9_Pos)
#define EXTI_EMR_MR9               EXTI_EMR_MR9_Msk
#define EXTI_EMR_MR10_Pos          (10U)
#define EXTI_EMR_MR10_Msk          (0x1U << EXTI_EMR_MR10_Pos)
#define EXTI_EMR_MR10              EXTI_EMR_MR10_Msk
#define EXTI_EMR_MR11_Pos          (11U)
#define EXTI_EMR_MR11_Msk          (0x1U << EXTI_EMR_MR11_Pos)
#define EXTI_EMR_MR11              EXTI_EMR_MR11_Msk
#define EXTI_EMR_MR12_Pos          (12U)
#define EXTI_EMR_MR12_Msk          (0x1U << EXTI_EMR_MR12_Pos)
#define EXTI_EMR_MR12              EXTI_EMR_MR12_Msk
#define EXTI_EMR_MR13_Pos          (13U)
#define EXTI_EMR_MR13_Msk          (0x1U << EXTI_EMR_MR13_Pos)
#define EXTI_EMR_MR13              EXTI_EMR_MR13_Msk
#define EXTI_EMR_MR14_Pos          (14U)
#define EXTI_EMR_MR14_Msk          (0x1U << EXTI_EMR_MR14_Pos)
#define EXTI_EMR_MR14              EXTI_EMR_MR14_Msk
#define EXTI_EMR_MR15_Pos          (15U)
#define EXTI_EMR_MR15_Msk          (0x1U << EXTI_EMR_MR15_Pos)
#define EXTI_EMR_MR15              EXTI_EMR_MR15_Msk
#define EXTI_EMR_MR16_Pos          (16U)
#define EXTI_EMR_MR16_Msk          (0x1U << EXTI_EMR_MR16_Pos)
#define EXTI_EMR_MR16              EXTI_EMR_MR16_Msk
#define EXTI_EMR_MR17_Pos          (17U)
#define EXTI_EMR_MR17_Msk          (0x1U << EXTI_EMR_MR17_Pos)
#define EXTI_EMR_MR17              EXTI_EMR_MR17_Msk
#define EXTI_EMR_MR19_Pos          (19U)
#define EXTI_EMR_MR19_Msk          (0x1U << EXTI_EMR_MR19_Pos)
#define EXTI_EMR_MR19              EXTI_EMR_MR19_Msk
#define EXTI_EMR_MR20_Pos          (20U)
#define EXTI_EMR_MR20_Msk          (0x1U << EXTI_EMR_MR20_Pos)
#define EXTI_EMR_MR20              EXTI_EMR_MR20_Msk
#define EXTI_EMR_MR22_Pos          (22U)
#define EXTI_EMR_MR22_Msk          (0x1U << EXTI_EMR_MR22_Pos)
#define EXTI_EMR_MR22              EXTI_EMR_MR22_Msk
#define EXTI_EMR_MR23_Pos          (23U)
#define EXTI_EMR_MR23_Msk          (0x1U << EXTI_EMR_MR23_Pos)
#define EXTI_EMR_MR23              EXTI_EMR_MR23_Msk
#define EXTI_EMR_MR25_Pos          (25U)
#define EXTI_EMR_MR25_Msk          (0x1U << EXTI_EMR_MR25_Pos)
#define EXTI_EMR_MR25              EXTI_EMR_MR25_Msk
#define EXTI_EMR_MR30_Pos          (30U)
#define EXTI_EMR_MR30_Msk          (0x1U << EXTI_EMR_MR30_Pos)
#define EXTI_EMR_MR30              EXTI_EMR_MR30_Msk


#define  EXTI_EMR_EM0 EXTI_EMR_MR0
#define  EXTI_EMR_EM1 EXTI_EMR_MR1
#define  EXTI_EMR_EM2 EXTI_EMR_MR2
#define  EXTI_EMR_EM3 EXTI_EMR_MR3
#define  EXTI_EMR_EM4 EXTI_EMR_MR4
#define  EXTI_EMR_EM5 EXTI_EMR_MR5
#define  EXTI_EMR_EM6 EXTI_EMR_MR6
#define  EXTI_EMR_EM7 EXTI_EMR_MR7
#define  EXTI_EMR_EM8 EXTI_EMR_MR8
#define  EXTI_EMR_EM9 EXTI_EMR_MR9
#define  EXTI_EMR_EM10 EXTI_EMR_MR10
#define  EXTI_EMR_EM11 EXTI_EMR_MR11
#define  EXTI_EMR_EM12 EXTI_EMR_MR12
#define  EXTI_EMR_EM13 EXTI_EMR_MR13
#define  EXTI_EMR_EM14 EXTI_EMR_MR14
#define  EXTI_EMR_EM15 EXTI_EMR_MR15
#define  EXTI_EMR_EM16 EXTI_EMR_MR16
#define  EXTI_EMR_EM17 EXTI_EMR_MR17
#if defined(EXTI_EMR_MR18)
#define  EXTI_EMR_EM18 EXTI_EMR_MR18
#endif
#define  EXTI_EMR_EM19 EXTI_EMR_MR19
#define  EXTI_EMR_EM20 EXTI_EMR_MR20
#if defined(EXTI_EMR_MR21)
#define  EXTI_EMR_EM21 EXTI_EMR_MR21
#endif
#define  EXTI_EMR_EM22 EXTI_EMR_MR22
#define  EXTI_EMR_EM23 EXTI_EMR_MR23
#if defined(EXTI_EMR_MR24)
#define  EXTI_EMR_EM24 EXTI_EMR_MR24
#endif
#define  EXTI_EMR_EM25 EXTI_EMR_MR25
#if defined(EXTI_EMR_MR26)
#define  EXTI_EMR_EM26 EXTI_EMR_MR26
#endif
#if defined(EXTI_EMR_MR27)
#define  EXTI_EMR_EM27 EXTI_EMR_MR27
#endif
#if defined(EXTI_EMR_MR28)
#define  EXTI_EMR_EM28 EXTI_EMR_MR28
#endif
#if defined(EXTI_EMR_MR29)
#define  EXTI_EMR_EM29 EXTI_EMR_MR29
#endif
#define  EXTI_EMR_EM30 EXTI_EMR_MR30
#if defined(EXTI_EMR_MR31)
#define  EXTI_EMR_EM31 EXTI_EMR_MR31
#endif


#define EXTI_RTSR_TR0_Pos          (0U)
#define EXTI_RTSR_TR0_Msk          (0x1U << EXTI_RTSR_TR0_Pos)
#define EXTI_RTSR_TR0              EXTI_RTSR_TR0_Msk
#define EXTI_RTSR_TR1_Pos          (1U)
#define EXTI_RTSR_TR1_Msk          (0x1U << EXTI_RTSR_TR1_Pos)
#define EXTI_RTSR_TR1              EXTI_RTSR_TR1_Msk
#define EXTI_RTSR_TR2_Pos          (2U)
#define EXTI_RTSR_TR2_Msk          (0x1U << EXTI_RTSR_TR2_Pos)
#define EXTI_RTSR_TR2              EXTI_RTSR_TR2_Msk
#define EXTI_RTSR_TR3_Pos          (3U)
#define EXTI_RTSR_TR3_Msk          (0x1U << EXTI_RTSR_TR3_Pos)
#define EXTI_RTSR_TR3              EXTI_RTSR_TR3_Msk
#define EXTI_RTSR_TR4_Pos          (4U)
#define EXTI_RTSR_TR4_Msk          (0x1U << EXTI_RTSR_TR4_Pos)
#define EXTI_RTSR_TR4              EXTI_RTSR_TR4_Msk
#define EXTI_RTSR_TR5_Pos          (5U)
#define EXTI_RTSR_TR5_Msk          (0x1U << EXTI_RTSR_TR5_Pos)
#define EXTI_RTSR_TR5              EXTI_RTSR_TR5_Msk
#define EXTI_RTSR_TR6_Pos          (6U)
#define EXTI_RTSR_TR6_Msk          (0x1U << EXTI_RTSR_TR6_Pos)
#define EXTI_RTSR_TR6              EXTI_RTSR_TR6_Msk
#define EXTI_RTSR_TR7_Pos          (7U)
#define EXTI_RTSR_TR7_Msk          (0x1U << EXTI_RTSR_TR7_Pos)
#define EXTI_RTSR_TR7              EXTI_RTSR_TR7_Msk
#define EXTI_RTSR_TR8_Pos          (8U)
#define EXTI_RTSR_TR8_Msk          (0x1U << EXTI_RTSR_TR8_Pos)
#define EXTI_RTSR_TR8              EXTI_RTSR_TR8_Msk
#define EXTI_RTSR_TR9_Pos          (9U)
#define EXTI_RTSR_TR9_Msk          (0x1U << EXTI_RTSR_TR9_Pos)
#define EXTI_RTSR_TR9              EXTI_RTSR_TR9_Msk
#define EXTI_RTSR_TR10_Pos         (10U)
#define EXTI_RTSR_TR10_Msk         (0x1U << EXTI_RTSR_TR10_Pos)
#define EXTI_RTSR_TR10             EXTI_RTSR_TR10_Msk
#define EXTI_RTSR_TR11_Pos         (11U)
#define EXTI_RTSR_TR11_Msk         (0x1U << EXTI_RTSR_TR11_Pos)
#define EXTI_RTSR_TR11             EXTI_RTSR_TR11_Msk
#define EXTI_RTSR_TR12_Pos         (12U)
#define EXTI_RTSR_TR12_Msk         (0x1U << EXTI_RTSR_TR12_Pos)
#define EXTI_RTSR_TR12             EXTI_RTSR_TR12_Msk
#define EXTI_RTSR_TR13_Pos         (13U)
#define EXTI_RTSR_TR13_Msk         (0x1U << EXTI_RTSR_TR13_Pos)
#define EXTI_RTSR_TR13             EXTI_RTSR_TR13_Msk
#define EXTI_RTSR_TR14_Pos         (14U)
#define EXTI_RTSR_TR14_Msk         (0x1U << EXTI_RTSR_TR14_Pos)
#define EXTI_RTSR_TR14             EXTI_RTSR_TR14_Msk
#define EXTI_RTSR_TR15_Pos         (15U)
#define EXTI_RTSR_TR15_Msk         (0x1U << EXTI_RTSR_TR15_Pos)
#define EXTI_RTSR_TR15             EXTI_RTSR_TR15_Msk
#define EXTI_RTSR_TR16_Pos         (16U)
#define EXTI_RTSR_TR16_Msk         (0x1U << EXTI_RTSR_TR16_Pos)
#define EXTI_RTSR_TR16             EXTI_RTSR_TR16_Msk
#define EXTI_RTSR_TR17_Pos         (17U)
#define EXTI_RTSR_TR17_Msk         (0x1U << EXTI_RTSR_TR17_Pos)
#define EXTI_RTSR_TR17             EXTI_RTSR_TR17_Msk
#define EXTI_RTSR_TR19_Pos         (19U)
#define EXTI_RTSR_TR19_Msk         (0x1U << EXTI_RTSR_TR19_Pos)
#define EXTI_RTSR_TR19             EXTI_RTSR_TR19_Msk
#define EXTI_RTSR_TR20_Pos         (20U)
#define EXTI_RTSR_TR20_Msk         (0x1U << EXTI_RTSR_TR20_Pos)
#define EXTI_RTSR_TR20             EXTI_RTSR_TR20_Msk
#define EXTI_RTSR_TR22_Pos         (22U)
#define EXTI_RTSR_TR22_Msk         (0x1U << EXTI_RTSR_TR22_Pos)
#define EXTI_RTSR_TR22             EXTI_RTSR_TR22_Msk
#define EXTI_RTSR_TR30_Pos         (30U)
#define EXTI_RTSR_TR30_Msk         (0x1U << EXTI_RTSR_TR30_Pos)
#define EXTI_RTSR_TR30             EXTI_RTSR_TR30_Msk


#define EXTI_RTSR_RT0 EXTI_RTSR_TR0
#define EXTI_RTSR_RT1 EXTI_RTSR_TR1
#define EXTI_RTSR_RT2 EXTI_RTSR_TR2
#define EXTI_RTSR_RT3 EXTI_RTSR_TR3
#define EXTI_RTSR_RT4 EXTI_RTSR_TR4
#define EXTI_RTSR_RT5 EXTI_RTSR_TR5
#define EXTI_RTSR_RT6 EXTI_RTSR_TR6
#define EXTI_RTSR_RT7 EXTI_RTSR_TR7
#define EXTI_RTSR_RT8 EXTI_RTSR_TR8
#define EXTI_RTSR_RT9 EXTI_RTSR_TR9
#define EXTI_RTSR_RT10 EXTI_RTSR_TR10
#define EXTI_RTSR_RT11 EXTI_RTSR_TR11
#define EXTI_RTSR_RT12 EXTI_RTSR_TR12
#define EXTI_RTSR_RT13 EXTI_RTSR_TR13
#define EXTI_RTSR_RT14 EXTI_RTSR_TR14
#define EXTI_RTSR_RT15 EXTI_RTSR_TR15
#define EXTI_RTSR_RT16 EXTI_RTSR_TR16
#define EXTI_RTSR_RT17 EXTI_RTSR_TR17
#if defined(EXTI_RTSR_TR18)
#define EXTI_RTSR_RT18 EXTI_RTSR_TR18
#endif
#define EXTI_RTSR_RT19 EXTI_RTSR_TR19
#define EXTI_RTSR_RT20 EXTI_RTSR_TR20
#if defined(EXTI_RTSR_TR21)
#define EXTI_RTSR_RT21 EXTI_RTSR_TR21
#endif
#define EXTI_RTSR_RT22 EXTI_RTSR_TR22
#if defined(EXTI_RTSR_TR23)
#define EXTI_RTSR_RT23 EXTI_RTSR_TR23
#endif
#if defined(EXTI_RTSR_TR24)
#define EXTI_RTSR_RT24 EXTI_RTSR_TR24
#endif
#if defined(EXTI_RTSR_TR25)
#define EXTI_RTSR_RT25 EXTI_RTSR_TR25
#endif
#if defined(EXTI_RTSR_TR26)
#define EXTI_RTSR_RT26 EXTI_RTSR_TR26
#endif
#if defined(EXTI_RTSR_TR27)
#define EXTI_RTSR_RT27 EXTI_RTSR_TR27
#endif
#if defined(EXTI_RTSR_TR28)
#define EXTI_RTSR_RT28 EXTI_RTSR_TR28
#endif
#if defined(EXTI_RTSR_TR29)
#define EXTI_RTSR_RT29 EXTI_RTSR_TR29
#endif
#define EXTI_RTSR_RT30 EXTI_RTSR_TR30
#if defined(EXTI_RTSR_TR31)
#define EXTI_RTSR_RT31 EXTI_RTSR_TR31
#endif


#define EXTI_FTSR_TR0_Pos          (0U)
#define EXTI_FTSR_TR0_Msk          (0x1U << EXTI_FTSR_TR0_Pos)
#define EXTI_FTSR_TR0              EXTI_FTSR_TR0_Msk
#define EXTI_FTSR_TR1_Pos          (1U)
#define EXTI_FTSR_TR1_Msk          (0x1U << EXTI_FTSR_TR1_Pos)
#define EXTI_FTSR_TR1              EXTI_FTSR_TR1_Msk
#define EXTI_FTSR_TR2_Pos          (2U)
#define EXTI_FTSR_TR2_Msk          (0x1U << EXTI_FTSR_TR2_Pos)
#define EXTI_FTSR_TR2              EXTI_FTSR_TR2_Msk
#define EXTI_FTSR_TR3_Pos          (3U)
#define EXTI_FTSR_TR3_Msk          (0x1U << EXTI_FTSR_TR3_Pos)
#define EXTI_FTSR_TR3              EXTI_FTSR_TR3_Msk
#define EXTI_FTSR_TR4_Pos          (4U)
#define EXTI_FTSR_TR4_Msk          (0x1U << EXTI_FTSR_TR4_Pos)
#define EXTI_FTSR_TR4              EXTI_FTSR_TR4_Msk
#define EXTI_FTSR_TR5_Pos          (5U)
#define EXTI_FTSR_TR5_Msk          (0x1U << EXTI_FTSR_TR5_Pos)
#define EXTI_FTSR_TR5              EXTI_FTSR_TR5_Msk
#define EXTI_FTSR_TR6_Pos          (6U)
#define EXTI_FTSR_TR6_Msk          (0x1U << EXTI_FTSR_TR6_Pos)
#define EXTI_FTSR_TR6              EXTI_FTSR_TR6_Msk
#define EXTI_FTSR_TR7_Pos          (7U)
#define EXTI_FTSR_TR7_Msk          (0x1U << EXTI_FTSR_TR7_Pos)
#define EXTI_FTSR_TR7              EXTI_FTSR_TR7_Msk
#define EXTI_FTSR_TR8_Pos          (8U)
#define EXTI_FTSR_TR8_Msk          (0x1U << EXTI_FTSR_TR8_Pos)
#define EXTI_FTSR_TR8              EXTI_FTSR_TR8_Msk
#define EXTI_FTSR_TR9_Pos          (9U)
#define EXTI_FTSR_TR9_Msk          (0x1U << EXTI_FTSR_TR9_Pos)
#define EXTI_FTSR_TR9              EXTI_FTSR_TR9_Msk
#define EXTI_FTSR_TR10_Pos         (10U)
#define EXTI_FTSR_TR10_Msk         (0x1U << EXTI_FTSR_TR10_Pos)
#define EXTI_FTSR_TR10             EXTI_FTSR_TR10_Msk
#define EXTI_FTSR_TR11_Pos         (11U)
#define EXTI_FTSR_TR11_Msk         (0x1U << EXTI_FTSR_TR11_Pos)
#define EXTI_FTSR_TR11             EXTI_FTSR_TR11_Msk
#define EXTI_FTSR_TR12_Pos         (12U)
#define EXTI_FTSR_TR12_Msk         (0x1U << EXTI_FTSR_TR12_Pos)
#define EXTI_FTSR_TR12             EXTI_FTSR_TR12_Msk
#define EXTI_FTSR_TR13_Pos         (13U)
#define EXTI_FTSR_TR13_Msk         (0x1U << EXTI_FTSR_TR13_Pos)
#define EXTI_FTSR_TR13             EXTI_FTSR_TR13_Msk
#define EXTI_FTSR_TR14_Pos         (14U)
#define EXTI_FTSR_TR14_Msk         (0x1U << EXTI_FTSR_TR14_Pos)
#define EXTI_FTSR_TR14             EXTI_FTSR_TR14_Msk
#define EXTI_FTSR_TR15_Pos         (15U)
#define EXTI_FTSR_TR15_Msk         (0x1U << EXTI_FTSR_TR15_Pos)
#define EXTI_FTSR_TR15             EXTI_FTSR_TR15_Msk
#define EXTI_FTSR_TR16_Pos         (16U)
#define EXTI_FTSR_TR16_Msk         (0x1U << EXTI_FTSR_TR16_Pos)
#define EXTI_FTSR_TR16             EXTI_FTSR_TR16_Msk
#define EXTI_FTSR_TR17_Pos         (17U)
#define EXTI_FTSR_TR17_Msk         (0x1U << EXTI_FTSR_TR17_Pos)
#define EXTI_FTSR_TR17             EXTI_FTSR_TR17_Msk
#define EXTI_FTSR_TR19_Pos         (19U)
#define EXTI_FTSR_TR19_Msk         (0x1U << EXTI_FTSR_TR19_Pos)
#define EXTI_FTSR_TR19             EXTI_FTSR_TR19_Msk
#define EXTI_FTSR_TR20_Pos         (20U)
#define EXTI_FTSR_TR20_Msk         (0x1U << EXTI_FTSR_TR20_Pos)
#define EXTI_FTSR_TR20             EXTI_FTSR_TR20_Msk
#define EXTI_FTSR_TR22_Pos         (22U)
#define EXTI_FTSR_TR22_Msk         (0x1U << EXTI_FTSR_TR22_Pos)
#define EXTI_FTSR_TR22             EXTI_FTSR_TR22_Msk
#define EXTI_FTSR_TR30_Pos         (30U)
#define EXTI_FTSR_TR30_Msk         (0x1U << EXTI_FTSR_TR30_Pos)
#define EXTI_FTSR_TR30             EXTI_FTSR_TR30_Msk


#define EXTI_FTSR_FT0 EXTI_FTSR_TR0
#define EXTI_FTSR_FT1 EXTI_FTSR_TR1
#define EXTI_FTSR_FT2 EXTI_FTSR_TR2
#define EXTI_FTSR_FT3 EXTI_FTSR_TR3
#define EXTI_FTSR_FT4 EXTI_FTSR_TR4
#define EXTI_FTSR_FT5 EXTI_FTSR_TR5
#define EXTI_FTSR_FT6 EXTI_FTSR_TR6
#define EXTI_FTSR_FT7 EXTI_FTSR_TR7
#define EXTI_FTSR_FT8 EXTI_FTSR_TR8
#define EXTI_FTSR_FT9 EXTI_FTSR_TR9
#define EXTI_FTSR_FT10 EXTI_FTSR_TR10
#define EXTI_FTSR_FT11 EXTI_FTSR_TR11
#define EXTI_FTSR_FT12 EXTI_FTSR_TR12
#define EXTI_FTSR_FT13 EXTI_FTSR_TR13
#define EXTI_FTSR_FT14 EXTI_FTSR_TR14
#define EXTI_FTSR_FT15 EXTI_FTSR_TR15
#define EXTI_FTSR_FT16 EXTI_FTSR_TR16
#define EXTI_FTSR_FT17 EXTI_FTSR_TR17
#if defined(EXTI_FTSR_TR18)
#define EXTI_FTSR_FT18 EXTI_FTSR_TR18
#endif
#define EXTI_FTSR_FT19 EXTI_FTSR_TR19
#define EXTI_FTSR_FT20 EXTI_FTSR_TR20
#if defined(EXTI_FTSR_TR21)
#define EXTI_FTSR_FT21 EXTI_FTSR_TR21
#endif
#define EXTI_FTSR_FT22 EXTI_FTSR_TR22
#if defined(EXTI_FTSR_TR23)
#define EXTI_FTSR_FT23 EXTI_FTSR_TR23
#endif
#if defined(EXTI_FTSR_TR24)
#define EXTI_FTSR_FT24 EXTI_FTSR_TR24
#endif
#if defined(EXTI_FTSR_TR25)
#define EXTI_FTSR_FT25 EXTI_FTSR_TR25
#endif
#if defined(EXTI_FTSR_TR26)
#define EXTI_FTSR_FT26 EXTI_FTSR_TR26
#endif
#if defined(EXTI_FTSR_TR27)
#define EXTI_FTSR_FT27 EXTI_FTSR_TR27
#endif
#if defined(EXTI_FTSR_TR28)
#define EXTI_FTSR_FT28 EXTI_FTSR_TR28
#endif
#if defined(EXTI_FTSR_TR29)
#define EXTI_FTSR_FT29 EXTI_FTSR_TR29
#endif
#define EXTI_FTSR_FT30 EXTI_FTSR_TR30
#if defined(EXTI_FTSR_TR31)
#define EXTI_FTSR_FT31 EXTI_FTSR_TR31
#endif


#define EXTI_SWIER_SWIER0_Pos      (0U)
#define EXTI_SWIER_SWIER0_Msk      (0x1U << EXTI_SWIER_SWIER0_Pos)
#define EXTI_SWIER_SWIER0          EXTI_SWIER_SWIER0_Msk
#define EXTI_SWIER_SWIER1_Pos      (1U)
#define EXTI_SWIER_SWIER1_Msk      (0x1U << EXTI_SWIER_SWIER1_Pos)
#define EXTI_SWIER_SWIER1          EXTI_SWIER_SWIER1_Msk
#define EXTI_SWIER_SWIER2_Pos      (2U)
#define EXTI_SWIER_SWIER2_Msk      (0x1U << EXTI_SWIER_SWIER2_Pos)
#define EXTI_SWIER_SWIER2          EXTI_SWIER_SWIER2_Msk
#define EXTI_SWIER_SWIER3_Pos      (3U)
#define EXTI_SWIER_SWIER3_Msk      (0x1U << EXTI_SWIER_SWIER3_Pos)
#define EXTI_SWIER_SWIER3          EXTI_SWIER_SWIER3_Msk
#define EXTI_SWIER_SWIER4_Pos      (4U)
#define EXTI_SWIER_SWIER4_Msk      (0x1U << EXTI_SWIER_SWIER4_Pos)
#define EXTI_SWIER_SWIER4          EXTI_SWIER_SWIER4_Msk
#define EXTI_SWIER_SWIER5_Pos      (5U)
#define EXTI_SWIER_SWIER5_Msk      (0x1U << EXTI_SWIER_SWIER5_Pos)
#define EXTI_SWIER_SWIER5          EXTI_SWIER_SWIER5_Msk
#define EXTI_SWIER_SWIER6_Pos      (6U)
#define EXTI_SWIER_SWIER6_Msk      (0x1U << EXTI_SWIER_SWIER6_Pos)
#define EXTI_SWIER_SWIER6          EXTI_SWIER_SWIER6_Msk
#define EXTI_SWIER_SWIER7_Pos      (7U)
#define EXTI_SWIER_SWIER7_Msk      (0x1U << EXTI_SWIER_SWIER7_Pos)
#define EXTI_SWIER_SWIER7          EXTI_SWIER_SWIER7_Msk
#define EXTI_SWIER_SWIER8_Pos      (8U)
#define EXTI_SWIER_SWIER8_Msk      (0x1U << EXTI_SWIER_SWIER8_Pos)
#define EXTI_SWIER_SWIER8          EXTI_SWIER_SWIER8_Msk
#define EXTI_SWIER_SWIER9_Pos      (9U)
#define EXTI_SWIER_SWIER9_Msk      (0x1U << EXTI_SWIER_SWIER9_Pos)
#define EXTI_SWIER_SWIER9          EXTI_SWIER_SWIER9_Msk
#define EXTI_SWIER_SWIER10_Pos     (10U)
#define EXTI_SWIER_SWIER10_Msk     (0x1U << EXTI_SWIER_SWIER10_Pos)
#define EXTI_SWIER_SWIER10         EXTI_SWIER_SWIER10_Msk
#define EXTI_SWIER_SWIER11_Pos     (11U)
#define EXTI_SWIER_SWIER11_Msk     (0x1U << EXTI_SWIER_SWIER11_Pos)
#define EXTI_SWIER_SWIER11         EXTI_SWIER_SWIER11_Msk
#define EXTI_SWIER_SWIER12_Pos     (12U)
#define EXTI_SWIER_SWIER12_Msk     (0x1U << EXTI_SWIER_SWIER12_Pos)
#define EXTI_SWIER_SWIER12         EXTI_SWIER_SWIER12_Msk
#define EXTI_SWIER_SWIER13_Pos     (13U)
#define EXTI_SWIER_SWIER13_Msk     (0x1U << EXTI_SWIER_SWIER13_Pos)
#define EXTI_SWIER_SWIER13         EXTI_SWIER_SWIER13_Msk
#define EXTI_SWIER_SWIER14_Pos     (14U)
#define EXTI_SWIER_SWIER14_Msk     (0x1U << EXTI_SWIER_SWIER14_Pos)
#define EXTI_SWIER_SWIER14         EXTI_SWIER_SWIER14_Msk
#define EXTI_SWIER_SWIER15_Pos     (15U)
#define EXTI_SWIER_SWIER15_Msk     (0x1U << EXTI_SWIER_SWIER15_Pos)
#define EXTI_SWIER_SWIER15         EXTI_SWIER_SWIER15_Msk
#define EXTI_SWIER_SWIER16_Pos     (16U)
#define EXTI_SWIER_SWIER16_Msk     (0x1U << EXTI_SWIER_SWIER16_Pos)
#define EXTI_SWIER_SWIER16         EXTI_SWIER_SWIER16_Msk
#define EXTI_SWIER_SWIER17_Pos     (17U)
#define EXTI_SWIER_SWIER17_Msk     (0x1U << EXTI_SWIER_SWIER17_Pos)
#define EXTI_SWIER_SWIER17         EXTI_SWIER_SWIER17_Msk
#define EXTI_SWIER_SWIER19_Pos     (19U)
#define EXTI_SWIER_SWIER19_Msk     (0x1U << EXTI_SWIER_SWIER19_Pos)
#define EXTI_SWIER_SWIER19         EXTI_SWIER_SWIER19_Msk
#define EXTI_SWIER_SWIER20_Pos     (20U)
#define EXTI_SWIER_SWIER20_Msk     (0x1U << EXTI_SWIER_SWIER20_Pos)
#define EXTI_SWIER_SWIER20         EXTI_SWIER_SWIER20_Msk
#define EXTI_SWIER_SWIER22_Pos     (22U)
#define EXTI_SWIER_SWIER22_Msk     (0x1U << EXTI_SWIER_SWIER22_Pos)
#define EXTI_SWIER_SWIER22         EXTI_SWIER_SWIER22_Msk
#define EXTI_SWIER_SWIER30_Pos     (30U)
#define EXTI_SWIER_SWIER30_Msk     (0x1U << EXTI_SWIER_SWIER30_Pos)
#define EXTI_SWIER_SWIER30         EXTI_SWIER_SWIER30_Msk


#define EXTI_SWIER_SWI0 EXTI_SWIER_SWIER0
#define EXTI_SWIER_SWI1 EXTI_SWIER_SWIER1
#define EXTI_SWIER_SWI2 EXTI_SWIER_SWIER2
#define EXTI_SWIER_SWI3 EXTI_SWIER_SWIER3
#define EXTI_SWIER_SWI4 EXTI_SWIER_SWIER4
#define EXTI_SWIER_SWI5 EXTI_SWIER_SWIER5
#define EXTI_SWIER_SWI6 EXTI_SWIER_SWIER6
#define EXTI_SWIER_SWI7 EXTI_SWIER_SWIER7
#define EXTI_SWIER_SWI8 EXTI_SWIER_SWIER8
#define EXTI_SWIER_SWI9 EXTI_SWIER_SWIER9
#define EXTI_SWIER_SWI10 EXTI_SWIER_SWIER10
#define EXTI_SWIER_SWI11 EXTI_SWIER_SWIER11
#define EXTI_SWIER_SWI12 EXTI_SWIER_SWIER12
#define EXTI_SWIER_SWI13 EXTI_SWIER_SWIER13
#define EXTI_SWIER_SWI14 EXTI_SWIER_SWIER14
#define EXTI_SWIER_SWI15 EXTI_SWIER_SWIER15
#define EXTI_SWIER_SWI16 EXTI_SWIER_SWIER16
#define EXTI_SWIER_SWI17 EXTI_SWIER_SWIER17
#if defined(EXTI_SWIER_SWIER18)
#define EXTI_SWIER_SWI18 EXTI_SWIER_SWIER18
#endif
#define EXTI_SWIER_SWI19 EXTI_SWIER_SWIER19
#define EXTI_SWIER_SWI20 EXTI_SWIER_SWIER20
#if defined(EXTI_SWIER_SWIER21)
#define EXTI_SWIER_SWI21 EXTI_SWIER_SWIER21
#endif
#define EXTI_SWIER_SWI22 EXTI_SWIER_SWIER22
#if defined(EXTI_SWIER_SWIER23)
#define EXTI_SWIER_SWI23 EXTI_SWIER_SWIER23
#endif
#if defined(EXTI_SWIER_SWIER24)
#define EXTI_SWIER_SWI24 EXTI_SWIER_SWIER24
#endif
#if defined(EXTI_SWIER_SWIER25)
#define EXTI_SWIER_SWI25 EXTI_SWIER_SWIER25
#endif
#if defined(EXTI_SWIER_SWIER26)
#define EXTI_SWIER_SWI26 EXTI_SWIER_SWIER26
#endif
#if defined(EXTI_SWIER_SWIER27)
#define EXTI_SWIER_SWI27 EXTI_SWIER_SWIER27
#endif
#if defined(EXTI_SWIER_SWIER28)
#define EXTI_SWIER_SWI28 EXTI_SWIER_SWIER28
#endif
#if defined(EXTI_SWIER_SWIER29)
#define EXTI_SWIER_SWI29 EXTI_SWIER_SWIER29
#endif
#define EXTI_SWIER_SWI30 EXTI_SWIER_SWIER30
#if defined(EXTI_SWIER_SWIER31)
#define EXTI_SWIER_SWI31 EXTI_SWIER_SWIER31
#endif


#define EXTI_PR_PR0_Pos            (0U)
#define EXTI_PR_PR0_Msk            (0x1U << EXTI_PR_PR0_Pos)
#define EXTI_PR_PR0                EXTI_PR_PR0_Msk
#define EXTI_PR_PR1_Pos            (1U)
#define EXTI_PR_PR1_Msk            (0x1U << EXTI_PR_PR1_Pos)
#define EXTI_PR_PR1                EXTI_PR_PR1_Msk
#define EXTI_PR_PR2_Pos            (2U)
#define EXTI_PR_PR2_Msk            (0x1U << EXTI_PR_PR2_Pos)
#define EXTI_PR_PR2                EXTI_PR_PR2_Msk
#define EXTI_PR_PR3_Pos            (3U)
#define EXTI_PR_PR3_Msk            (0x1U << EXTI_PR_PR3_Pos)
#define EXTI_PR_PR3                EXTI_PR_PR3_Msk
#define EXTI_PR_PR4_Pos            (4U)
#define EXTI_PR_PR4_Msk            (0x1U << EXTI_PR_PR4_Pos)
#define EXTI_PR_PR4                EXTI_PR_PR4_Msk
#define EXTI_PR_PR5_Pos            (5U)
#define EXTI_PR_PR5_Msk            (0x1U << EXTI_PR_PR5_Pos)
#define EXTI_PR_PR5                EXTI_PR_PR5_Msk
#define EXTI_PR_PR6_Pos            (6U)
#define EXTI_PR_PR6_Msk            (0x1U << EXTI_PR_PR6_Pos)
#define EXTI_PR_PR6                EXTI_PR_PR6_Msk
#define EXTI_PR_PR7_Pos            (7U)
#define EXTI_PR_PR7_Msk            (0x1U << EXTI_PR_PR7_Pos)
#define EXTI_PR_PR7                EXTI_PR_PR7_Msk
#define EXTI_PR_PR8_Pos            (8U)
#define EXTI_PR_PR8_Msk            (0x1U << EXTI_PR_PR8_Pos)
#define EXTI_PR_PR8                EXTI_PR_PR8_Msk
#define EXTI_PR_PR9_Pos            (9U)
#define EXTI_PR_PR9_Msk            (0x1U << EXTI_PR_PR9_Pos)
#define EXTI_PR_PR9                EXTI_PR_PR9_Msk
#define EXTI_PR_PR10_Pos           (10U)
#define EXTI_PR_PR10_Msk           (0x1U << EXTI_PR_PR10_Pos)
#define EXTI_PR_PR10               EXTI_PR_PR10_Msk
#define EXTI_PR_PR11_Pos           (11U)
#define EXTI_PR_PR11_Msk           (0x1U << EXTI_PR_PR11_Pos)
#define EXTI_PR_PR11               EXTI_PR_PR11_Msk
#define EXTI_PR_PR12_Pos           (12U)
#define EXTI_PR_PR12_Msk           (0x1U << EXTI_PR_PR12_Pos)
#define EXTI_PR_PR12               EXTI_PR_PR12_Msk
#define EXTI_PR_PR13_Pos           (13U)
#define EXTI_PR_PR13_Msk           (0x1U << EXTI_PR_PR13_Pos)
#define EXTI_PR_PR13               EXTI_PR_PR13_Msk
#define EXTI_PR_PR14_Pos           (14U)
#define EXTI_PR_PR14_Msk           (0x1U << EXTI_PR_PR14_Pos)
#define EXTI_PR_PR14               EXTI_PR_PR14_Msk
#define EXTI_PR_PR15_Pos           (15U)
#define EXTI_PR_PR15_Msk           (0x1U << EXTI_PR_PR15_Pos)
#define EXTI_PR_PR15               EXTI_PR_PR15_Msk
#define EXTI_PR_PR16_Pos           (16U)
#define EXTI_PR_PR16_Msk           (0x1U << EXTI_PR_PR16_Pos)
#define EXTI_PR_PR16               EXTI_PR_PR16_Msk
#define EXTI_PR_PR17_Pos           (17U)
#define EXTI_PR_PR17_Msk           (0x1U << EXTI_PR_PR17_Pos)
#define EXTI_PR_PR17               EXTI_PR_PR17_Msk
#define EXTI_PR_PR19_Pos           (19U)
#define EXTI_PR_PR19_Msk           (0x1U << EXTI_PR_PR19_Pos)
#define EXTI_PR_PR19               EXTI_PR_PR19_Msk
#define EXTI_PR_PR20_Pos           (20U)
#define EXTI_PR_PR20_Msk           (0x1U << EXTI_PR_PR20_Pos)
#define EXTI_PR_PR20               EXTI_PR_PR20_Msk
#define EXTI_PR_PR22_Pos           (22U)
#define EXTI_PR_PR22_Msk           (0x1U << EXTI_PR_PR22_Pos)
#define EXTI_PR_PR22               EXTI_PR_PR22_Msk
#define EXTI_PR_PR30_Pos           (30U)
#define EXTI_PR_PR30_Msk           (0x1U << EXTI_PR_PR30_Pos)
#define EXTI_PR_PR30               EXTI_PR_PR30_Msk


#define EXTI_PR_PIF0 EXTI_PR_PR0
#define EXTI_PR_PIF1 EXTI_PR_PR1
#define EXTI_PR_PIF2 EXTI_PR_PR2
#define EXTI_PR_PIF3 EXTI_PR_PR3
#define EXTI_PR_PIF4 EXTI_PR_PR4
#define EXTI_PR_PIF5 EXTI_PR_PR5
#define EXTI_PR_PIF6 EXTI_PR_PR6
#define EXTI_PR_PIF6 EXTI_PR_PR6
#define EXTI_PR_PIF7 EXTI_PR_PR7
#define EXTI_PR_PIF8 EXTI_PR_PR8
#define EXTI_PR_PIF9 EXTI_PR_PR9
#define EXTI_PR_PIF10 EXTI_PR_PR10
#define EXTI_PR_PIF11 EXTI_PR_PR11
#define EXTI_PR_PIF12 EXTI_PR_PR12
#define EXTI_PR_PIF13 EXTI_PR_PR13
#define EXTI_PR_PIF14 EXTI_PR_PR14
#define EXTI_PR_PIF15 EXTI_PR_PR15
#define EXTI_PR_PIF16 EXTI_PR_PR16
#define EXTI_PR_PIF17 EXTI_PR_PR17
#if defined(EXTI_PR_PR18)
#define EXTI_PR_PIF18 EXTI_PR_PR18
#endif
#define EXTI_PR_PIF19 EXTI_PR_PR19
#define EXTI_PR_PIF20 EXTI_PR_PR20
#if defined(EXTI_PR_PR21)
#define EXTI_PR_PIF21 EXTI_PR_PR21
#endif
#define EXTI_PR_PIF22 EXTI_PR_PR22
#if defined(EXTI_PR_PR23)
#define EXTI_PR_PIF23 EXTI_PR_PR23
#endif
#if defined(EXTI_PR_PR24)
#define EXTI_PR_PIF24 EXTI_PR_PR24
#endif
#if defined(EXTI_PR_PR25)
#define EXTI_PR_PIF25 EXTI_PR_PR25
#endif
#if defined(EXTI_PR_PR26)
#define EXTI_PR_PIF26 EXTI_PR_PR26
#endif
#if defined(EXTI_PR_PR27)
#define EXTI_PR_PIF27 EXTI_PR_PR27
#endif
#if defined(EXTI_PR_PR28)
#define EXTI_PR_PIF28 EXTI_PR_PR28
#endif
#if defined(EXTI_PR_PR29)
#define EXTI_PR_PIF29 EXTI_PR_PR29
#endif
#define EXTI_PR_PIF30 EXTI_PR_PR30
#if defined(EXTI_PR_PR31)
#define EXTI_PR_PIF31 EXTI_PR_PR31
#endif

#define EXTI_32_63_SUPPORT


#define EXTI_IMR2_MR32_Pos         (0U)
#define EXTI_IMR2_MR32_Msk         (0x1U << EXTI_IMR2_MR32_Pos)
#define EXTI_IMR2_MR32             EXTI_IMR2_MR32_Msk



#define EXTI_IMR2_IM32 EXTI_IMR2_MR32
#if defined(EXTI_IMR2_MR33)
#define EXTI_IMR2_IM33 EXTI_IMR2_MR33
#endif
#if defined(EXTI_IMR2_MR34)
#define EXTI_IMR2_IM34 EXTI_IMR2_MR34
#endif
#if defined(EXTI_IMR2_MR35)
#define EXTI_IMR2_IM35 EXTI_IMR2_MR35
#endif

#if defined(EXTI_IMR2_MR33) && defined(EXTI_IMR2_MR34) && defined(EXTI_IMR2_MR35)
#define EXTI_IMR2_IM_Pos           (0U)
#define EXTI_IMR2_IM_Msk           (0xFU << EXTI_IMR2_IM_Pos)
#define EXTI_IMR2_IM               EXTI_IMR2_IM_Msk
#elif defined(EXTI_IMR2_MR34) && defined(EXTI_IMR2_MR35)
#define EXTI_IMR2_IM_Pos           (0U)
#define EXTI_IMR2_IM_Msk           (0xDU << EXTI_IMR2_IM_Pos)
#define EXTI_IMR2_IM               EXTI_IMR2_IM_Msk
#else
#define EXTI_IMR2_IM_Pos           (0U)
#define EXTI_IMR2_IM_Msk           (0x1U << EXTI_IMR2_IM_Pos)
#define EXTI_IMR2_IM               EXTI_IMR2_IM_Msk
#endif


#define EXTI_EMR2_MR32_Pos         (0U)
#define EXTI_EMR2_MR32_Msk         (0x1U << EXTI_EMR2_MR32_Pos)
#define EXTI_EMR2_MR32             EXTI_EMR2_MR32_Msk


#define EXTI_EMR2_EM32 EXTI_EMR2_MR32
#if defined(EXTI_EMR2_MR33)
#define EXTI_EMR2_EM33 EXTI_EMR2_MR33
#endif
#if defined(EXTI_EMR2_MR34)
#define EXTI_EMR2_EM34 EXTI_EMR2_MR34
#endif
#if defined(EXTI_EMR2_MR35)
#define EXTI_EMR2_EM35 EXTI_EMR2_MR35
#endif

#if defined(EXTI_EMR2_MR33) && defined(EXTI_EMR2_MR34) && defined(EXTI_EMR2_MR35)
#define EXTI_EMR2_EM_Pos           (0U)
#define EXTI_EMR2_EM_Msk           (0xFU << EXTI_EMR2_EM_Pos)
#define EXTI_EMR2_EM               EXTI_EMR2_EM_Msk
#elif defined(EXTI_EMR2_MR34) && defined(EXTI_EMR2_MR35)
#define EXTI_EMR2_EM_Pos           (0U)
#define EXTI_EMR2_EM_Msk           (0xDU << EXTI_EMR2_EM_Pos)
#define EXTI_EMR2_EM               EXTI_EMR2_EM_Msk
#else
#define EXTI_EMR2_EM_Pos           (0U)
#define EXTI_EMR2_EM_Msk           (0x1U << EXTI_EMR2_EM_Pos)
#define EXTI_EMR2_EM               EXTI_EMR2_EM_Msk
#endif


#define EXTI_RTSR2_TR32_Pos        (0U)
#define EXTI_RTSR2_TR32_Msk        (0x1U << EXTI_RTSR2_TR32_Pos)
#define EXTI_RTSR2_TR32            EXTI_RTSR2_TR32_Msk


#define EXTI_RTSR2_RT32 EXTI_RTSR2_TR32
#if defined(EXTI_RTSR2_TR33)
#define EXTI_RTSR2_RT33 EXTI_RTSR2_TR33
#endif
#if defined(EXTI_RTSR2_TR34)
#define EXTI_RTSR2_RT34 EXTI_RTSR2_TR34
#endif
#if defined(EXTI_RTSR2_TR35)
#define EXTI_RTSR2_RT35 EXTI_RTSR2_TR35
#endif


#define EXTI_FTSR2_TR32_Pos        (0U)
#define EXTI_FTSR2_TR32_Msk        (0x1U << EXTI_FTSR2_TR32_Pos)
#define EXTI_FTSR2_TR32            EXTI_FTSR2_TR32_Msk


#define EXTI_FTSR2_FT32 EXTI_FTSR2_TR32
#if defined(EXTI_FTSR2_TR33)
#define EXTI_FTSR2_FT33 EXTI_FTSR2_TR33
#endif
#if defined(EXTI_FTSR2_TR34)
#define EXTI_FTSR2_FT34 EXTI_FTSR2_TR34
#endif
#if defined(EXTI_FTSR2_TR35)
#define EXTI_FTSR2_FT35 EXTI_FTSR2_TR35
#endif


#define EXTI_SWIER2_SWIER32_Pos    (0U)
#define EXTI_SWIER2_SWIER32_Msk    (0x1U << EXTI_SWIER2_SWIER32_Pos)
#define EXTI_SWIER2_SWIER32        EXTI_SWIER2_SWIER32_Msk


#define EXTI_SWIER2_SWI32 EXTI_SWIER2_SWIER32
#if defined(EXTI_SWIER2_SWIER33)
#define EXTI_SWIER2_SWI33 EXTI_SWIER2_SWIER33
#endif
#if defined(EXTI_SWIER2_SWIER34)
#define EXTI_SWIER2_SWI34 EXTI_SWIER2_SWIER34
#endif
#if defined(EXTI_SWIER2_SWIER35)
#define EXTI_SWIER2_SWI35 EXTI_SWIER2_SWIER35
#endif


#define EXTI_PR2_PR32_Pos          (0U)
#define EXTI_PR2_PR32_Msk          (0x1U << EXTI_PR2_PR32_Pos)
#define EXTI_PR2_PR32              EXTI_PR2_PR32_Msk


#define EXTI_PR2_PIF32 EXTI_PR2_PR32
#if defined(EXTI_PR2_PR33)
#define EXTI_PR2_PIF33 EXTI_PR2_PR33
#endif
#if defined(EXTI_PR2_PR34)
#define EXTI_PR2_PIF34 EXTI_PR2_PR34
#endif
#if defined(EXTI_PR2_PR35)
#define EXTI_PR2_PIF35 EXTI_PR2_PR35
#endif








#define FLASH_ACR_LATENCY_Pos                (0U)
#define FLASH_ACR_LATENCY_Msk                (0x7U << FLASH_ACR_LATENCY_Pos)
#define FLASH_ACR_LATENCY                    FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0                  (0x1U << FLASH_ACR_LATENCY_Pos)
#define FLASH_ACR_LATENCY_1                  (0x2U << FLASH_ACR_LATENCY_Pos)
#define FLASH_ACR_LATENCY_2                  (0x4U << FLASH_ACR_LATENCY_Pos)

#define FLASH_ACR_HLFCYA_Pos                 (3U)
#define FLASH_ACR_HLFCYA_Msk                 (0x1U << FLASH_ACR_HLFCYA_Pos)
#define FLASH_ACR_HLFCYA                     FLASH_ACR_HLFCYA_Msk
#define FLASH_ACR_PRFTBE_Pos                 (4U)
#define FLASH_ACR_PRFTBE_Msk                 (0x1U << FLASH_ACR_PRFTBE_Pos)
#define FLASH_ACR_PRFTBE                     FLASH_ACR_PRFTBE_Msk
#define FLASH_ACR_PRFTBS_Pos                 (5U)
#define FLASH_ACR_PRFTBS_Msk                 (0x1U << FLASH_ACR_PRFTBS_Pos)
#define FLASH_ACR_PRFTBS                     FLASH_ACR_PRFTBS_Msk


#define FLASH_KEYR_FKEYR_Pos                 (0U)
#define FLASH_KEYR_FKEYR_Msk                 (0xFFFFFFFFU << FLASH_KEYR_FKEYR_Pos)
#define FLASH_KEYR_FKEYR                     FLASH_KEYR_FKEYR_Msk

#define RDP_KEY_Pos    (0U)
#define RDP_KEY_Msk    (0xA5U << RDP_KEY_Pos)
#define RDP_KEY        RDP_KEY_Msk
#define FLASH_KEY1_Pos                       (0U)
#define FLASH_KEY1_Msk                       (0x45670123U << FLASH_KEY1_Pos)
#define FLASH_KEY1                           FLASH_KEY1_Msk
#define FLASH_KEY2_Pos                       (0U)
#define FLASH_KEY2_Msk                       (0xCDEF89ABU << FLASH_KEY2_Pos)
#define FLASH_KEY2                           FLASH_KEY2_Msk


#define FLASH_OPTKEYR_OPTKEYR_Pos            (0U)
#define FLASH_OPTKEYR_OPTKEYR_Msk            (0xFFFFFFFFU << FLASH_OPTKEYR_OPTKEYR_Pos)
#define FLASH_OPTKEYR_OPTKEYR                FLASH_OPTKEYR_OPTKEYR_Msk

#define  FLASH_OPTKEY1                       FLASH_KEY1
#define  FLASH_OPTKEY2                       FLASH_KEY2


#define FLASH_SR_BSY_Pos                     (0U)
#define FLASH_SR_BSY_Msk                     (0x1U << FLASH_SR_BSY_Pos)
#define FLASH_SR_BSY                         FLASH_SR_BSY_Msk
#define FLASH_SR_PGERR_Pos                   (2U)
#define FLASH_SR_PGERR_Msk                   (0x1U << FLASH_SR_PGERR_Pos)
#define FLASH_SR_PGERR                       FLASH_SR_PGERR_Msk
#define FLASH_SR_WRPERR_Pos                  (4U)
#define FLASH_SR_WRPERR_Msk                  (0x1U << FLASH_SR_WRPERR_Pos)
#define FLASH_SR_WRPERR                      FLASH_SR_WRPERR_Msk
#define FLASH_SR_EOP_Pos                     (5U)
#define FLASH_SR_EOP_Msk                     (0x1U << FLASH_SR_EOP_Pos)
#define FLASH_SR_EOP                         FLASH_SR_EOP_Msk


#define FLASH_CR_PG_Pos                      (0U)
#define FLASH_CR_PG_Msk                      (0x1U << FLASH_CR_PG_Pos)
#define FLASH_CR_PG                          FLASH_CR_PG_Msk
#define FLASH_CR_PER_Pos                     (1U)
#define FLASH_CR_PER_Msk                     (0x1U << FLASH_CR_PER_Pos)
#define FLASH_CR_PER                         FLASH_CR_PER_Msk
#define FLASH_CR_MER_Pos                     (2U)
#define FLASH_CR_MER_Msk                     (0x1U << FLASH_CR_MER_Pos)
#define FLASH_CR_MER                         FLASH_CR_MER_Msk
#define FLASH_CR_OPTPG_Pos                   (4U)
#define FLASH_CR_OPTPG_Msk                   (0x1U << FLASH_CR_OPTPG_Pos)
#define FLASH_CR_OPTPG                       FLASH_CR_OPTPG_Msk
#define FLASH_CR_OPTER_Pos                   (5U)
#define FLASH_CR_OPTER_Msk                   (0x1U << FLASH_CR_OPTER_Pos)
#define FLASH_CR_OPTER                       FLASH_CR_OPTER_Msk
#define FLASH_CR_STRT_Pos                    (6U)
#define FLASH_CR_STRT_Msk                    (0x1U << FLASH_CR_STRT_Pos)
#define FLASH_CR_STRT                        FLASH_CR_STRT_Msk
#define FLASH_CR_LOCK_Pos                    (7U)
#define FLASH_CR_LOCK_Msk                    (0x1U << FLASH_CR_LOCK_Pos)
#define FLASH_CR_LOCK                        FLASH_CR_LOCK_Msk
#define FLASH_CR_OPTWRE_Pos                  (9U)
#define FLASH_CR_OPTWRE_Msk                  (0x1U << FLASH_CR_OPTWRE_Pos)
#define FLASH_CR_OPTWRE                      FLASH_CR_OPTWRE_Msk
#define FLASH_CR_ERRIE_Pos                   (10U)
#define FLASH_CR_ERRIE_Msk                   (0x1U << FLASH_CR_ERRIE_Pos)
#define FLASH_CR_ERRIE                       FLASH_CR_ERRIE_Msk
#define FLASH_CR_EOPIE_Pos                   (12U)
#define FLASH_CR_EOPIE_Msk                   (0x1U << FLASH_CR_EOPIE_Pos)
#define FLASH_CR_EOPIE                       FLASH_CR_EOPIE_Msk
#define FLASH_CR_OBL_LAUNCH_Pos              (13U)
#define FLASH_CR_OBL_LAUNCH_Msk              (0x1U << FLASH_CR_OBL_LAUNCH_Pos)
#define FLASH_CR_OBL_LAUNCH                  FLASH_CR_OBL_LAUNCH_Msk


#define FLASH_AR_FAR_Pos                     (0U)
#define FLASH_AR_FAR_Msk                     (0xFFFFFFFFU << FLASH_AR_FAR_Pos)
#define FLASH_AR_FAR                         FLASH_AR_FAR_Msk


#define FLASH_OBR_OPTERR_Pos                 (0U)
#define FLASH_OBR_OPTERR_Msk                 (0x1U << FLASH_OBR_OPTERR_Pos)
#define FLASH_OBR_OPTERR                     FLASH_OBR_OPTERR_Msk
#define FLASH_OBR_RDPRT_Pos                  (1U)
#define FLASH_OBR_RDPRT_Msk                  (0x3U << FLASH_OBR_RDPRT_Pos)
#define FLASH_OBR_RDPRT                      FLASH_OBR_RDPRT_Msk
#define FLASH_OBR_RDPRT_1                    (0x1U << FLASH_OBR_RDPRT_Pos)
#define FLASH_OBR_RDPRT_2                    (0x3U << FLASH_OBR_RDPRT_Pos)

#define FLASH_OBR_USER_Pos                   (8U)
#define FLASH_OBR_USER_Msk                   (0x77U << FLASH_OBR_USER_Pos)
#define FLASH_OBR_USER                       FLASH_OBR_USER_Msk
#define FLASH_OBR_IWDG_SW_Pos                (8U)
#define FLASH_OBR_IWDG_SW_Msk                (0x1U << FLASH_OBR_IWDG_SW_Pos)
#define FLASH_OBR_IWDG_SW                    FLASH_OBR_IWDG_SW_Msk
#define FLASH_OBR_nRST_STOP_Pos              (9U)
#define FLASH_OBR_nRST_STOP_Msk              (0x1U << FLASH_OBR_nRST_STOP_Pos)
#define FLASH_OBR_nRST_STOP                  FLASH_OBR_nRST_STOP_Msk
#define FLASH_OBR_nRST_STDBY_Pos             (10U)
#define FLASH_OBR_nRST_STDBY_Msk             (0x1U << FLASH_OBR_nRST_STDBY_Pos)
#define FLASH_OBR_nRST_STDBY                 FLASH_OBR_nRST_STDBY_Msk
#define FLASH_OBR_nBOOT1_Pos                 (12U)
#define FLASH_OBR_nBOOT1_Msk                 (0x1U << FLASH_OBR_nBOOT1_Pos)
#define FLASH_OBR_nBOOT1                     FLASH_OBR_nBOOT1_Msk
#define FLASH_OBR_VDDA_MONITOR_Pos           (13U)
#define FLASH_OBR_VDDA_MONITOR_Msk           (0x1U << FLASH_OBR_VDDA_MONITOR_Pos)
#define FLASH_OBR_VDDA_MONITOR               FLASH_OBR_VDDA_MONITOR_Msk
#define FLASH_OBR_SRAM_PE_Pos                (14U)
#define FLASH_OBR_SRAM_PE_Msk                (0x1U << FLASH_OBR_SRAM_PE_Pos)
#define FLASH_OBR_SRAM_PE                    FLASH_OBR_SRAM_PE_Msk
#define FLASH_OBR_DATA0_Pos                  (16U)
#define FLASH_OBR_DATA0_Msk                  (0xFFU << FLASH_OBR_DATA0_Pos)
#define FLASH_OBR_DATA0                      FLASH_OBR_DATA0_Msk
#define FLASH_OBR_DATA1_Pos                  (24U)
#define FLASH_OBR_DATA1_Msk                  (0xFFU << FLASH_OBR_DATA1_Pos)
#define FLASH_OBR_DATA1                      FLASH_OBR_DATA1_Msk


#define FLASH_OBR_WDG_SW FLASH_OBR_IWDG_SW


#define FLASH_WRPR_WRP_Pos                   (0U)
#define FLASH_WRPR_WRP_Msk                   (0xFFFFFFFFU << FLASH_WRPR_WRP_Pos)
#define FLASH_WRPR_WRP                       FLASH_WRPR_WRP_Msk




#define OB_RDP_RDP_Pos       (0U)
#define OB_RDP_RDP_Msk       (0xFFU << OB_RDP_RDP_Pos)
#define OB_RDP_RDP           OB_RDP_RDP_Msk
#define OB_RDP_nRDP_Pos      (8U)
#define OB_RDP_nRDP_Msk      (0xFFU << OB_RDP_nRDP_Pos)
#define OB_RDP_nRDP          OB_RDP_nRDP_Msk


#define OB_USER_USER_Pos     (16U)
#define OB_USER_USER_Msk     (0xFFU << OB_USER_USER_Pos)
#define OB_USER_USER         OB_USER_USER_Msk
#define OB_USER_nUSER_Pos    (24U)
#define OB_USER_nUSER_Msk    (0xFFU << OB_USER_nUSER_Pos)
#define OB_USER_nUSER        OB_USER_nUSER_Msk


#define OB_WRP0_WRP0_Pos     (0U)
#define OB_WRP0_WRP0_Msk     (0xFFU << OB_WRP0_WRP0_Pos)
#define OB_WRP0_WRP0         OB_WRP0_WRP0_Msk
#define OB_WRP0_nWRP0_Pos    (8U)
#define OB_WRP0_nWRP0_Msk    (0xFFU << OB_WRP0_nWRP0_Pos)
#define OB_WRP0_nWRP0        OB_WRP0_nWRP0_Msk


#define OB_WRP1_WRP1_Pos     (16U)
#define OB_WRP1_WRP1_Msk     (0xFFU << OB_WRP1_WRP1_Pos)
#define OB_WRP1_WRP1         OB_WRP1_WRP1_Msk
#define OB_WRP1_nWRP1_Pos    (24U)
#define OB_WRP1_nWRP1_Msk    (0xFFU << OB_WRP1_nWRP1_Pos)
#define OB_WRP1_nWRP1        OB_WRP1_nWRP1_Msk








#define GPIO_MODER_MODER0_Pos            (0U)
#define GPIO_MODER_MODER0_Msk            (0x3U << GPIO_MODER_MODER0_Pos)
#define GPIO_MODER_MODER0                GPIO_MODER_MODER0_Msk
#define GPIO_MODER_MODER0_0              (0x1U << GPIO_MODER_MODER0_Pos)
#define GPIO_MODER_MODER0_1              (0x2U << GPIO_MODER_MODER0_Pos)
#define GPIO_MODER_MODER1_Pos            (2U)
#define GPIO_MODER_MODER1_Msk            (0x3U << GPIO_MODER_MODER1_Pos)
#define GPIO_MODER_MODER1                GPIO_MODER_MODER1_Msk
#define GPIO_MODER_MODER1_0              (0x1U << GPIO_MODER_MODER1_Pos)
#define GPIO_MODER_MODER1_1              (0x2U << GPIO_MODER_MODER1_Pos)
#define GPIO_MODER_MODER2_Pos            (4U)
#define GPIO_MODER_MODER2_Msk            (0x3U << GPIO_MODER_MODER2_Pos)
#define GPIO_MODER_MODER2                GPIO_MODER_MODER2_Msk
#define GPIO_MODER_MODER2_0              (0x1U << GPIO_MODER_MODER2_Pos)
#define GPIO_MODER_MODER2_1              (0x2U << GPIO_MODER_MODER2_Pos)
#define GPIO_MODER_MODER3_Pos            (6U)
#define GPIO_MODER_MODER3_Msk            (0x3U << GPIO_MODER_MODER3_Pos)
#define GPIO_MODER_MODER3                GPIO_MODER_MODER3_Msk
#define GPIO_MODER_MODER3_0              (0x1U << GPIO_MODER_MODER3_Pos)
#define GPIO_MODER_MODER3_1              (0x2U << GPIO_MODER_MODER3_Pos)
#define GPIO_MODER_MODER4_Pos            (8U)
#define GPIO_MODER_MODER4_Msk            (0x3U << GPIO_MODER_MODER4_Pos)
#define GPIO_MODER_MODER4                GPIO_MODER_MODER4_Msk
#define GPIO_MODER_MODER4_0              (0x1U << GPIO_MODER_MODER4_Pos)
#define GPIO_MODER_MODER4_1              (0x2U << GPIO_MODER_MODER4_Pos)
#define GPIO_MODER_MODER5_Pos            (10U)
#define GPIO_MODER_MODER5_Msk            (0x3U << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER5                GPIO_MODER_MODER5_Msk
#define GPIO_MODER_MODER5_0              (0x1U << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER5_1              (0x2U << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER6_Pos            (12U)
#define GPIO_MODER_MODER6_Msk            (0x3U << GPIO_MODER_MODER6_Pos)
#define GPIO_MODER_MODER6                GPIO_MODER_MODER6_Msk
#define GPIO_MODER_MODER6_0              (0x1U << GPIO_MODER_MODER6_Pos)
#define GPIO_MODER_MODER6_1              (0x2U << GPIO_MODER_MODER6_Pos)
#define GPIO_MODER_MODER7_Pos            (14U)
#define GPIO_MODER_MODER7_Msk            (0x3U << GPIO_MODER_MODER7_Pos)
#define GPIO_MODER_MODER7                GPIO_MODER_MODER7_Msk
#define GPIO_MODER_MODER7_0              (0x1U << GPIO_MODER_MODER7_Pos)
#define GPIO_MODER_MODER7_1              (0x2U << GPIO_MODER_MODER7_Pos)
#define GPIO_MODER_MODER8_Pos            (16U)
#define GPIO_MODER_MODER8_Msk            (0x3U << GPIO_MODER_MODER8_Pos)
#define GPIO_MODER_MODER8                GPIO_MODER_MODER8_Msk
#define GPIO_MODER_MODER8_0              (0x1U << GPIO_MODER_MODER8_Pos)
#define GPIO_MODER_MODER8_1              (0x2U << GPIO_MODER_MODER8_Pos)
#define GPIO_MODER_MODER9_Pos            (18U)
#define GPIO_MODER_MODER9_Msk            (0x3U << GPIO_MODER_MODER9_Pos)
#define GPIO_MODER_MODER9                GPIO_MODER_MODER9_Msk
#define GPIO_MODER_MODER9_0              (0x1U << GPIO_MODER_MODER9_Pos)
#define GPIO_MODER_MODER9_1              (0x2U << GPIO_MODER_MODER9_Pos)
#define GPIO_MODER_MODER10_Pos           (20U)
#define GPIO_MODER_MODER10_Msk           (0x3U << GPIO_MODER_MODER10_Pos)
#define GPIO_MODER_MODER10               GPIO_MODER_MODER10_Msk
#define GPIO_MODER_MODER10_0             (0x1U << GPIO_MODER_MODER10_Pos)
#define GPIO_MODER_MODER10_1             (0x2U << GPIO_MODER_MODER10_Pos)
#define GPIO_MODER_MODER11_Pos           (22U)
#define GPIO_MODER_MODER11_Msk           (0x3U << GPIO_MODER_MODER11_Pos)
#define GPIO_MODER_MODER11               GPIO_MODER_MODER11_Msk
#define GPIO_MODER_MODER11_0             (0x1U << GPIO_MODER_MODER11_Pos)
#define GPIO_MODER_MODER11_1             (0x2U << GPIO_MODER_MODER11_Pos)
#define GPIO_MODER_MODER12_Pos           (24U)
#define GPIO_MODER_MODER12_Msk           (0x3U << GPIO_MODER_MODER12_Pos)
#define GPIO_MODER_MODER12               GPIO_MODER_MODER12_Msk
#define GPIO_MODER_MODER12_0             (0x1U << GPIO_MODER_MODER12_Pos)
#define GPIO_MODER_MODER12_1             (0x2U << GPIO_MODER_MODER12_Pos)
#define GPIO_MODER_MODER13_Pos           (26U)
#define GPIO_MODER_MODER13_Msk           (0x3U << GPIO_MODER_MODER13_Pos)
#define GPIO_MODER_MODER13               GPIO_MODER_MODER13_Msk
#define GPIO_MODER_MODER13_0             (0x1U << GPIO_MODER_MODER13_Pos)
#define GPIO_MODER_MODER13_1             (0x2U << GPIO_MODER_MODER13_Pos)
#define GPIO_MODER_MODER14_Pos           (28U)
#define GPIO_MODER_MODER14_Msk           (0x3U << GPIO_MODER_MODER14_Pos)
#define GPIO_MODER_MODER14               GPIO_MODER_MODER14_Msk
#define GPIO_MODER_MODER14_0             (0x1U << GPIO_MODER_MODER14_Pos)
#define GPIO_MODER_MODER14_1             (0x2U << GPIO_MODER_MODER14_Pos)
#define GPIO_MODER_MODER15_Pos           (30U)
#define GPIO_MODER_MODER15_Msk           (0x3U << GPIO_MODER_MODER15_Pos)
#define GPIO_MODER_MODER15               GPIO_MODER_MODER15_Msk
#define GPIO_MODER_MODER15_0             (0x1U << GPIO_MODER_MODER15_Pos)
#define GPIO_MODER_MODER15_1             (0x2U << GPIO_MODER_MODER15_Pos)


#define GPIO_OTYPER_OT_0                 (0x00000001U)
#define GPIO_OTYPER_OT_1                 (0x00000002U)
#define GPIO_OTYPER_OT_2                 (0x00000004U)
#define GPIO_OTYPER_OT_3                 (0x00000008U)
#define GPIO_OTYPER_OT_4                 (0x00000010U)
#define GPIO_OTYPER_OT_5                 (0x00000020U)
#define GPIO_OTYPER_OT_6                 (0x00000040U)
#define GPIO_OTYPER_OT_7                 (0x00000080U)
#define GPIO_OTYPER_OT_8                 (0x00000100U)
#define GPIO_OTYPER_OT_9                 (0x00000200U)
#define GPIO_OTYPER_OT_10                (0x00000400U)
#define GPIO_OTYPER_OT_11                (0x00000800U)
#define GPIO_OTYPER_OT_12                (0x00001000U)
#define GPIO_OTYPER_OT_13                (0x00002000U)
#define GPIO_OTYPER_OT_14                (0x00004000U)
#define GPIO_OTYPER_OT_15                (0x00008000U)


#define GPIO_OSPEEDER_OSPEEDR0_Pos       (0U)
#define GPIO_OSPEEDER_OSPEEDR0_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR0_Pos)
#define GPIO_OSPEEDER_OSPEEDR0           GPIO_OSPEEDER_OSPEEDR0_Msk
#define GPIO_OSPEEDER_OSPEEDR0_0         (0x1U << GPIO_OSPEEDER_OSPEEDR0_Pos)
#define GPIO_OSPEEDER_OSPEEDR0_1         (0x2U << GPIO_OSPEEDER_OSPEEDR0_Pos)
#define GPIO_OSPEEDER_OSPEEDR1_Pos       (2U)
#define GPIO_OSPEEDER_OSPEEDR1_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR1_Pos)
#define GPIO_OSPEEDER_OSPEEDR1           GPIO_OSPEEDER_OSPEEDR1_Msk
#define GPIO_OSPEEDER_OSPEEDR1_0         (0x1U << GPIO_OSPEEDER_OSPEEDR1_Pos)
#define GPIO_OSPEEDER_OSPEEDR1_1         (0x2U << GPIO_OSPEEDER_OSPEEDR1_Pos)
#define GPIO_OSPEEDER_OSPEEDR2_Pos       (4U)
#define GPIO_OSPEEDER_OSPEEDR2_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR2_Pos)
#define GPIO_OSPEEDER_OSPEEDR2           GPIO_OSPEEDER_OSPEEDR2_Msk
#define GPIO_OSPEEDER_OSPEEDR2_0         (0x1U << GPIO_OSPEEDER_OSPEEDR2_Pos)
#define GPIO_OSPEEDER_OSPEEDR2_1         (0x2U << GPIO_OSPEEDER_OSPEEDR2_Pos)
#define GPIO_OSPEEDER_OSPEEDR3_Pos       (6U)
#define GPIO_OSPEEDER_OSPEEDR3_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR3_Pos)
#define GPIO_OSPEEDER_OSPEEDR3           GPIO_OSPEEDER_OSPEEDR3_Msk
#define GPIO_OSPEEDER_OSPEEDR3_0         (0x1U << GPIO_OSPEEDER_OSPEEDR3_Pos)
#define GPIO_OSPEEDER_OSPEEDR3_1         (0x2U << GPIO_OSPEEDER_OSPEEDR3_Pos)
#define GPIO_OSPEEDER_OSPEEDR4_Pos       (8U)
#define GPIO_OSPEEDER_OSPEEDR4_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR4_Pos)
#define GPIO_OSPEEDER_OSPEEDR4           GPIO_OSPEEDER_OSPEEDR4_Msk
#define GPIO_OSPEEDER_OSPEEDR4_0         (0x1U << GPIO_OSPEEDER_OSPEEDR4_Pos)
#define GPIO_OSPEEDER_OSPEEDR4_1         (0x2U << GPIO_OSPEEDER_OSPEEDR4_Pos)
#define GPIO_OSPEEDER_OSPEEDR5_Pos       (10U)
#define GPIO_OSPEEDER_OSPEEDR5_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR5_Pos)
#define GPIO_OSPEEDER_OSPEEDR5           GPIO_OSPEEDER_OSPEEDR5_Msk
#define GPIO_OSPEEDER_OSPEEDR5_0         (0x1U << GPIO_OSPEEDER_OSPEEDR5_Pos)
#define GPIO_OSPEEDER_OSPEEDR5_1         (0x2U << GPIO_OSPEEDER_OSPEEDR5_Pos)
#define GPIO_OSPEEDER_OSPEEDR6_Pos       (12U)
#define GPIO_OSPEEDER_OSPEEDR6_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR6_Pos)
#define GPIO_OSPEEDER_OSPEEDR6           GPIO_OSPEEDER_OSPEEDR6_Msk
#define GPIO_OSPEEDER_OSPEEDR6_0         (0x1U << GPIO_OSPEEDER_OSPEEDR6_Pos)
#define GPIO_OSPEEDER_OSPEEDR6_1         (0x2U << GPIO_OSPEEDER_OSPEEDR6_Pos)
#define GPIO_OSPEEDER_OSPEEDR7_Pos       (14U)
#define GPIO_OSPEEDER_OSPEEDR7_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR7_Pos)
#define GPIO_OSPEEDER_OSPEEDR7           GPIO_OSPEEDER_OSPEEDR7_Msk
#define GPIO_OSPEEDER_OSPEEDR7_0         (0x1U << GPIO_OSPEEDER_OSPEEDR7_Pos)
#define GPIO_OSPEEDER_OSPEEDR7_1         (0x2U << GPIO_OSPEEDER_OSPEEDR7_Pos)
#define GPIO_OSPEEDER_OSPEEDR8_Pos       (16U)
#define GPIO_OSPEEDER_OSPEEDR8_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR8_Pos)
#define GPIO_OSPEEDER_OSPEEDR8           GPIO_OSPEEDER_OSPEEDR8_Msk
#define GPIO_OSPEEDER_OSPEEDR8_0         (0x1U << GPIO_OSPEEDER_OSPEEDR8_Pos)
#define GPIO_OSPEEDER_OSPEEDR8_1         (0x2U << GPIO_OSPEEDER_OSPEEDR8_Pos)
#define GPIO_OSPEEDER_OSPEEDR9_Pos       (18U)
#define GPIO_OSPEEDER_OSPEEDR9_Msk       (0x3U << GPIO_OSPEEDER_OSPEEDR9_Pos)
#define GPIO_OSPEEDER_OSPEEDR9           GPIO_OSPEEDER_OSPEEDR9_Msk
#define GPIO_OSPEEDER_OSPEEDR9_0         (0x1U << GPIO_OSPEEDER_OSPEEDR9_Pos)
#define GPIO_OSPEEDER_OSPEEDR9_1         (0x2U << GPIO_OSPEEDER_OSPEEDR9_Pos)
#define GPIO_OSPEEDER_OSPEEDR10_Pos      (20U)
#define GPIO_OSPEEDER_OSPEEDR10_Msk      (0x3U << GPIO_OSPEEDER_OSPEEDR10_Pos)
#define GPIO_OSPEEDER_OSPEEDR10          GPIO_OSPEEDER_OSPEEDR10_Msk
#define GPIO_OSPEEDER_OSPEEDR10_0        (0x1U << GPIO_OSPEEDER_OSPEEDR10_Pos)
#define GPIO_OSPEEDER_OSPEEDR10_1        (0x2U << GPIO_OSPEEDER_OSPEEDR10_Pos)
#define GPIO_OSPEEDER_OSPEEDR11_Pos      (22U)
#define GPIO_OSPEEDER_OSPEEDR11_Msk      (0x3U << GPIO_OSPEEDER_OSPEEDR11_Pos)
#define GPIO_OSPEEDER_OSPEEDR11          GPIO_OSPEEDER_OSPEEDR11_Msk
#define GPIO_OSPEEDER_OSPEEDR11_0        (0x1U << GPIO_OSPEEDER_OSPEEDR11_Pos)
#define GPIO_OSPEEDER_OSPEEDR11_1        (0x2U << GPIO_OSPEEDER_OSPEEDR11_Pos)
#define GPIO_OSPEEDER_OSPEEDR12_Pos      (24U)
#define GPIO_OSPEEDER_OSPEEDR12_Msk      (0x3U << GPIO_OSPEEDER_OSPEEDR12_Pos)
#define GPIO_OSPEEDER_OSPEEDR12          GPIO_OSPEEDER_OSPEEDR12_Msk
#define GPIO_OSPEEDER_OSPEEDR12_0        (0x1U << GPIO_OSPEEDER_OSPEEDR12_Pos)
#define GPIO_OSPEEDER_OSPEEDR12_1        (0x2U << GPIO_OSPEEDER_OSPEEDR12_Pos)
#define GPIO_OSPEEDER_OSPEEDR13_Pos      (26U)
#define GPIO_OSPEEDER_OSPEEDR13_Msk      (0x3U << GPIO_OSPEEDER_OSPEEDR13_Pos)
#define GPIO_OSPEEDER_OSPEEDR13          GPIO_OSPEEDER_OSPEEDR13_Msk
#define GPIO_OSPEEDER_OSPEEDR13_0        (0x1U << GPIO_OSPEEDER_OSPEEDR13_Pos)
#define GPIO_OSPEEDER_OSPEEDR13_1        (0x2U << GPIO_OSPEEDER_OSPEEDR13_Pos)
#define GPIO_OSPEEDER_OSPEEDR14_Pos      (28U)
#define GPIO_OSPEEDER_OSPEEDR14_Msk      (0x3U << GPIO_OSPEEDER_OSPEEDR14_Pos)
#define GPIO_OSPEEDER_OSPEEDR14          GPIO_OSPEEDER_OSPEEDR14_Msk
#define GPIO_OSPEEDER_OSPEEDR14_0        (0x1U << GPIO_OSPEEDER_OSPEEDR14_Pos)
#define GPIO_OSPEEDER_OSPEEDR14_1        (0x2U << GPIO_OSPEEDER_OSPEEDR14_Pos)
#define GPIO_OSPEEDER_OSPEEDR15_Pos      (30U)
#define GPIO_OSPEEDER_OSPEEDR15_Msk      (0x3U << GPIO_OSPEEDER_OSPEEDR15_Pos)
#define GPIO_OSPEEDER_OSPEEDR15          GPIO_OSPEEDER_OSPEEDR15_Msk
#define GPIO_OSPEEDER_OSPEEDR15_0        (0x1U << GPIO_OSPEEDER_OSPEEDR15_Pos)
#define GPIO_OSPEEDER_OSPEEDR15_1        (0x2U << GPIO_OSPEEDER_OSPEEDR15_Pos)


#define GPIO_PUPDR_PUPDR0_Pos            (0U)
#define GPIO_PUPDR_PUPDR0_Msk            (0x3U << GPIO_PUPDR_PUPDR0_Pos)
#define GPIO_PUPDR_PUPDR0                GPIO_PUPDR_PUPDR0_Msk
#define GPIO_PUPDR_PUPDR0_0              (0x1U << GPIO_PUPDR_PUPDR0_Pos)
#define GPIO_PUPDR_PUPDR0_1              (0x2U << GPIO_PUPDR_PUPDR0_Pos)
#define GPIO_PUPDR_PUPDR1_Pos            (2U)
#define GPIO_PUPDR_PUPDR1_Msk            (0x3U << GPIO_PUPDR_PUPDR1_Pos)
#define GPIO_PUPDR_PUPDR1                GPIO_PUPDR_PUPDR1_Msk
#define GPIO_PUPDR_PUPDR1_0              (0x1U << GPIO_PUPDR_PUPDR1_Pos)
#define GPIO_PUPDR_PUPDR1_1              (0x2U << GPIO_PUPDR_PUPDR1_Pos)
#define GPIO_PUPDR_PUPDR2_Pos            (4U)
#define GPIO_PUPDR_PUPDR2_Msk            (0x3U << GPIO_PUPDR_PUPDR2_Pos)
#define GPIO_PUPDR_PUPDR2                GPIO_PUPDR_PUPDR2_Msk
#define GPIO_PUPDR_PUPDR2_0              (0x1U << GPIO_PUPDR_PUPDR2_Pos)
#define GPIO_PUPDR_PUPDR2_1              (0x2U << GPIO_PUPDR_PUPDR2_Pos)
#define GPIO_PUPDR_PUPDR3_Pos            (6U)
#define GPIO_PUPDR_PUPDR3_Msk            (0x3U << GPIO_PUPDR_PUPDR3_Pos)
#define GPIO_PUPDR_PUPDR3                GPIO_PUPDR_PUPDR3_Msk
#define GPIO_PUPDR_PUPDR3_0              (0x1U << GPIO_PUPDR_PUPDR3_Pos)
#define GPIO_PUPDR_PUPDR3_1              (0x2U << GPIO_PUPDR_PUPDR3_Pos)
#define GPIO_PUPDR_PUPDR4_Pos            (8U)
#define GPIO_PUPDR_PUPDR4_Msk            (0x3U << GPIO_PUPDR_PUPDR4_Pos)
#define GPIO_PUPDR_PUPDR4                GPIO_PUPDR_PUPDR4_Msk
#define GPIO_PUPDR_PUPDR4_0              (0x1U << GPIO_PUPDR_PUPDR4_Pos)
#define GPIO_PUPDR_PUPDR4_1              (0x2U << GPIO_PUPDR_PUPDR4_Pos)
#define GPIO_PUPDR_PUPDR5_Pos            (10U)
#define GPIO_PUPDR_PUPDR5_Msk            (0x3U << GPIO_PUPDR_PUPDR5_Pos)
#define GPIO_PUPDR_PUPDR5                GPIO_PUPDR_PUPDR5_Msk
#define GPIO_PUPDR_PUPDR5_0              (0x1U << GPIO_PUPDR_PUPDR5_Pos)
#define GPIO_PUPDR_PUPDR5_1              (0x2U << GPIO_PUPDR_PUPDR5_Pos)
#define GPIO_PUPDR_PUPDR6_Pos            (12U)
#define GPIO_PUPDR_PUPDR6_Msk            (0x3U << GPIO_PUPDR_PUPDR6_Pos)
#define GPIO_PUPDR_PUPDR6                GPIO_PUPDR_PUPDR6_Msk
#define GPIO_PUPDR_PUPDR6_0              (0x1U << GPIO_PUPDR_PUPDR6_Pos)
#define GPIO_PUPDR_PUPDR6_1              (0x2U << GPIO_PUPDR_PUPDR6_Pos)
#define GPIO_PUPDR_PUPDR7_Pos            (14U)
#define GPIO_PUPDR_PUPDR7_Msk            (0x3U << GPIO_PUPDR_PUPDR7_Pos)
#define GPIO_PUPDR_PUPDR7                GPIO_PUPDR_PUPDR7_Msk
#define GPIO_PUPDR_PUPDR7_0              (0x1U << GPIO_PUPDR_PUPDR7_Pos)
#define GPIO_PUPDR_PUPDR7_1              (0x2U << GPIO_PUPDR_PUPDR7_Pos)
#define GPIO_PUPDR_PUPDR8_Pos            (16U)
#define GPIO_PUPDR_PUPDR8_Msk            (0x3U << GPIO_PUPDR_PUPDR8_Pos)
#define GPIO_PUPDR_PUPDR8                GPIO_PUPDR_PUPDR8_Msk
#define GPIO_PUPDR_PUPDR8_0              (0x1U << GPIO_PUPDR_PUPDR8_Pos)
#define GPIO_PUPDR_PUPDR8_1              (0x2U << GPIO_PUPDR_PUPDR8_Pos)
#define GPIO_PUPDR_PUPDR9_Pos            (18U)
#define GPIO_PUPDR_PUPDR9_Msk            (0x3U << GPIO_PUPDR_PUPDR9_Pos)
#define GPIO_PUPDR_PUPDR9                GPIO_PUPDR_PUPDR9_Msk
#define GPIO_PUPDR_PUPDR9_0              (0x1U << GPIO_PUPDR_PUPDR9_Pos)
#define GPIO_PUPDR_PUPDR9_1              (0x2U << GPIO_PUPDR_PUPDR9_Pos)
#define GPIO_PUPDR_PUPDR10_Pos           (20U)
#define GPIO_PUPDR_PUPDR10_Msk           (0x3U << GPIO_PUPDR_PUPDR10_Pos)
#define GPIO_PUPDR_PUPDR10               GPIO_PUPDR_PUPDR10_Msk
#define GPIO_PUPDR_PUPDR10_0             (0x1U << GPIO_PUPDR_PUPDR10_Pos)
#define GPIO_PUPDR_PUPDR10_1             (0x2U << GPIO_PUPDR_PUPDR10_Pos)
#define GPIO_PUPDR_PUPDR11_Pos           (22U)
#define GPIO_PUPDR_PUPDR11_Msk           (0x3U << GPIO_PUPDR_PUPDR11_Pos)
#define GPIO_PUPDR_PUPDR11               GPIO_PUPDR_PUPDR11_Msk
#define GPIO_PUPDR_PUPDR11_0             (0x1U << GPIO_PUPDR_PUPDR11_Pos)
#define GPIO_PUPDR_PUPDR11_1             (0x2U << GPIO_PUPDR_PUPDR11_Pos)
#define GPIO_PUPDR_PUPDR12_Pos           (24U)
#define GPIO_PUPDR_PUPDR12_Msk           (0x3U << GPIO_PUPDR_PUPDR12_Pos)
#define GPIO_PUPDR_PUPDR12               GPIO_PUPDR_PUPDR12_Msk
#define GPIO_PUPDR_PUPDR12_0             (0x1U << GPIO_PUPDR_PUPDR12_Pos)
#define GPIO_PUPDR_PUPDR12_1             (0x2U << GPIO_PUPDR_PUPDR12_Pos)
#define GPIO_PUPDR_PUPDR13_Pos           (26U)
#define GPIO_PUPDR_PUPDR13_Msk           (0x3U << GPIO_PUPDR_PUPDR13_Pos)
#define GPIO_PUPDR_PUPDR13               GPIO_PUPDR_PUPDR13_Msk
#define GPIO_PUPDR_PUPDR13_0             (0x1U << GPIO_PUPDR_PUPDR13_Pos)
#define GPIO_PUPDR_PUPDR13_1             (0x2U << GPIO_PUPDR_PUPDR13_Pos)
#define GPIO_PUPDR_PUPDR14_Pos           (28U)
#define GPIO_PUPDR_PUPDR14_Msk           (0x3U << GPIO_PUPDR_PUPDR14_Pos)
#define GPIO_PUPDR_PUPDR14               GPIO_PUPDR_PUPDR14_Msk
#define GPIO_PUPDR_PUPDR14_0             (0x1U << GPIO_PUPDR_PUPDR14_Pos)
#define GPIO_PUPDR_PUPDR14_1             (0x2U << GPIO_PUPDR_PUPDR14_Pos)
#define GPIO_PUPDR_PUPDR15_Pos           (30U)
#define GPIO_PUPDR_PUPDR15_Msk           (0x3U << GPIO_PUPDR_PUPDR15_Pos)
#define GPIO_PUPDR_PUPDR15               GPIO_PUPDR_PUPDR15_Msk
#define GPIO_PUPDR_PUPDR15_0             (0x1U << GPIO_PUPDR_PUPDR15_Pos)
#define GPIO_PUPDR_PUPDR15_1             (0x2U << GPIO_PUPDR_PUPDR15_Pos)


#define GPIO_IDR_0                       (0x00000001U)
#define GPIO_IDR_1                       (0x00000002U)
#define GPIO_IDR_2                       (0x00000004U)
#define GPIO_IDR_3                       (0x00000008U)
#define GPIO_IDR_4                       (0x00000010U)
#define GPIO_IDR_5                       (0x00000020U)
#define GPIO_IDR_6                       (0x00000040U)
#define GPIO_IDR_7                       (0x00000080U)
#define GPIO_IDR_8                       (0x00000100U)
#define GPIO_IDR_9                       (0x00000200U)
#define GPIO_IDR_10                      (0x00000400U)
#define GPIO_IDR_11                      (0x00000800U)
#define GPIO_IDR_12                      (0x00001000U)
#define GPIO_IDR_13                      (0x00002000U)
#define GPIO_IDR_14                      (0x00004000U)
#define GPIO_IDR_15                      (0x00008000U)


#define GPIO_ODR_0                       (0x00000001U)
#define GPIO_ODR_1                       (0x00000002U)
#define GPIO_ODR_2                       (0x00000004U)
#define GPIO_ODR_3                       (0x00000008U)
#define GPIO_ODR_4                       (0x00000010U)
#define GPIO_ODR_5                       (0x00000020U)
#define GPIO_ODR_6                       (0x00000040U)
#define GPIO_ODR_7                       (0x00000080U)
#define GPIO_ODR_8                       (0x00000100U)
#define GPIO_ODR_9                       (0x00000200U)
#define GPIO_ODR_10                      (0x00000400U)
#define GPIO_ODR_11                      (0x00000800U)
#define GPIO_ODR_12                      (0x00001000U)
#define GPIO_ODR_13                      (0x00002000U)
#define GPIO_ODR_14                      (0x00004000U)
#define GPIO_ODR_15                      (0x00008000U)


#define GPIO_BSRR_BS_0                   (0x00000001U)
#define GPIO_BSRR_BS_1                   (0x00000002U)
#define GPIO_BSRR_BS_2                   (0x00000004U)
#define GPIO_BSRR_BS_3                   (0x00000008U)
#define GPIO_BSRR_BS_4                   (0x00000010U)
#define GPIO_BSRR_BS_5                   (0x00000020U)
#define GPIO_BSRR_BS_6                   (0x00000040U)
#define GPIO_BSRR_BS_7                   (0x00000080U)
#define GPIO_BSRR_BS_8                   (0x00000100U)
#define GPIO_BSRR_BS_9                   (0x00000200U)
#define GPIO_BSRR_BS_10                  (0x00000400U)
#define GPIO_BSRR_BS_11                  (0x00000800U)
#define GPIO_BSRR_BS_12                  (0x00001000U)
#define GPIO_BSRR_BS_13                  (0x00002000U)
#define GPIO_BSRR_BS_14                  (0x00004000U)
#define GPIO_BSRR_BS_15                  (0x00008000U)
#define GPIO_BSRR_BR_0                   (0x00010000U)
#define GPIO_BSRR_BR_1                   (0x00020000U)
#define GPIO_BSRR_BR_2                   (0x00040000U)
#define GPIO_BSRR_BR_3                   (0x00080000U)
#define GPIO_BSRR_BR_4                   (0x00100000U)
#define GPIO_BSRR_BR_5                   (0x00200000U)
#define GPIO_BSRR_BR_6                   (0x00400000U)
#define GPIO_BSRR_BR_7                   (0x00800000U)
#define GPIO_BSRR_BR_8                   (0x01000000U)
#define GPIO_BSRR_BR_9                   (0x02000000U)
#define GPIO_BSRR_BR_10                  (0x04000000U)
#define GPIO_BSRR_BR_11                  (0x08000000U)
#define GPIO_BSRR_BR_12                  (0x10000000U)
#define GPIO_BSRR_BR_13                  (0x20000000U)
#define GPIO_BSRR_BR_14                  (0x40000000U)
#define GPIO_BSRR_BR_15                  (0x80000000U)


#define GPIO_LCKR_LCK0_Pos               (0U)
#define GPIO_LCKR_LCK0_Msk               (0x1U << GPIO_LCKR_LCK0_Pos)
#define GPIO_LCKR_LCK0                   GPIO_LCKR_LCK0_Msk
#define GPIO_LCKR_LCK1_Pos               (1U)
#define GPIO_LCKR_LCK1_Msk               (0x1U << GPIO_LCKR_LCK1_Pos)
#define GPIO_LCKR_LCK1                   GPIO_LCKR_LCK1_Msk
#define GPIO_LCKR_LCK2_Pos               (2U)
#define GPIO_LCKR_LCK2_Msk               (0x1U << GPIO_LCKR_LCK2_Pos)
#define GPIO_LCKR_LCK2                   GPIO_LCKR_LCK2_Msk
#define GPIO_LCKR_LCK3_Pos               (3U)
#define GPIO_LCKR_LCK3_Msk               (0x1U << GPIO_LCKR_LCK3_Pos)
#define GPIO_LCKR_LCK3                   GPIO_LCKR_LCK3_Msk
#define GPIO_LCKR_LCK4_Pos               (4U)
#define GPIO_LCKR_LCK4_Msk               (0x1U << GPIO_LCKR_LCK4_Pos)
#define GPIO_LCKR_LCK4                   GPIO_LCKR_LCK4_Msk
#define GPIO_LCKR_LCK5_Pos               (5U)
#define GPIO_LCKR_LCK5_Msk               (0x1U << GPIO_LCKR_LCK5_Pos)
#define GPIO_LCKR_LCK5                   GPIO_LCKR_LCK5_Msk
#define GPIO_LCKR_LCK6_Pos               (6U)
#define GPIO_LCKR_LCK6_Msk               (0x1U << GPIO_LCKR_LCK6_Pos)
#define GPIO_LCKR_LCK6                   GPIO_LCKR_LCK6_Msk
#define GPIO_LCKR_LCK7_Pos               (7U)
#define GPIO_LCKR_LCK7_Msk               (0x1U << GPIO_LCKR_LCK7_Pos)
#define GPIO_LCKR_LCK7                   GPIO_LCKR_LCK7_Msk
#define GPIO_LCKR_LCK8_Pos               (8U)
#define GPIO_LCKR_LCK8_Msk               (0x1U << GPIO_LCKR_LCK8_Pos)
#define GPIO_LCKR_LCK8                   GPIO_LCKR_LCK8_Msk
#define GPIO_LCKR_LCK9_Pos               (9U)
#define GPIO_LCKR_LCK9_Msk               (0x1U << GPIO_LCKR_LCK9_Pos)
#define GPIO_LCKR_LCK9                   GPIO_LCKR_LCK9_Msk
#define GPIO_LCKR_LCK10_Pos              (10U)
#define GPIO_LCKR_LCK10_Msk              (0x1U << GPIO_LCKR_LCK10_Pos)
#define GPIO_LCKR_LCK10                  GPIO_LCKR_LCK10_Msk
#define GPIO_LCKR_LCK11_Pos              (11U)
#define GPIO_LCKR_LCK11_Msk              (0x1U << GPIO_LCKR_LCK11_Pos)
#define GPIO_LCKR_LCK11                  GPIO_LCKR_LCK11_Msk
#define GPIO_LCKR_LCK12_Pos              (12U)
#define GPIO_LCKR_LCK12_Msk              (0x1U << GPIO_LCKR_LCK12_Pos)
#define GPIO_LCKR_LCK12                  GPIO_LCKR_LCK12_Msk
#define GPIO_LCKR_LCK13_Pos              (13U)
#define GPIO_LCKR_LCK13_Msk              (0x1U << GPIO_LCKR_LCK13_Pos)
#define GPIO_LCKR_LCK13                  GPIO_LCKR_LCK13_Msk
#define GPIO_LCKR_LCK14_Pos              (14U)
#define GPIO_LCKR_LCK14_Msk              (0x1U << GPIO_LCKR_LCK14_Pos)
#define GPIO_LCKR_LCK14                  GPIO_LCKR_LCK14_Msk
#define GPIO_LCKR_LCK15_Pos              (15U)
#define GPIO_LCKR_LCK15_Msk              (0x1U << GPIO_LCKR_LCK15_Pos)
#define GPIO_LCKR_LCK15                  GPIO_LCKR_LCK15_Msk
#define GPIO_LCKR_LCKK_Pos               (16U)
#define GPIO_LCKR_LCKK_Msk               (0x1U << GPIO_LCKR_LCKK_Pos)
#define GPIO_LCKR_LCKK                   GPIO_LCKR_LCKK_Msk


#define GPIO_AFRL_AFRL0_Pos              (0U)
#define GPIO_AFRL_AFRL0_Msk              (0xFU << GPIO_AFRL_AFRL0_Pos)
#define GPIO_AFRL_AFRL0                  GPIO_AFRL_AFRL0_Msk
#define GPIO_AFRL_AFRL1_Pos              (4U)
#define GPIO_AFRL_AFRL1_Msk              (0xFU << GPIO_AFRL_AFRL1_Pos)
#define GPIO_AFRL_AFRL1                  GPIO_AFRL_AFRL1_Msk
#define GPIO_AFRL_AFRL2_Pos              (8U)
#define GPIO_AFRL_AFRL2_Msk              (0xFU << GPIO_AFRL_AFRL2_Pos)
#define GPIO_AFRL_AFRL2                  GPIO_AFRL_AFRL2_Msk
#define GPIO_AFRL_AFRL3_Pos              (12U)
#define GPIO_AFRL_AFRL3_Msk              (0xFU << GPIO_AFRL_AFRL3_Pos)
#define GPIO_AFRL_AFRL3                  GPIO_AFRL_AFRL3_Msk
#define GPIO_AFRL_AFRL4_Pos              (16U)
#define GPIO_AFRL_AFRL4_Msk              (0xFU << GPIO_AFRL_AFRL4_Pos)
#define GPIO_AFRL_AFRL4                  GPIO_AFRL_AFRL4_Msk
#define GPIO_AFRL_AFRL5_Pos              (20U)
#define GPIO_AFRL_AFRL5_Msk              (0xFU << GPIO_AFRL_AFRL5_Pos)
#define GPIO_AFRL_AFRL5                  GPIO_AFRL_AFRL5_Msk
#define GPIO_AFRL_AFRL6_Pos              (24U)
#define GPIO_AFRL_AFRL6_Msk              (0xFU << GPIO_AFRL_AFRL6_Pos)
#define GPIO_AFRL_AFRL6                  GPIO_AFRL_AFRL6_Msk
#define GPIO_AFRL_AFRL7_Pos              (28U)
#define GPIO_AFRL_AFRL7_Msk              (0xFU << GPIO_AFRL_AFRL7_Pos)
#define GPIO_AFRL_AFRL7                  GPIO_AFRL_AFRL7_Msk


#define GPIO_AFRH_AFRH0_Pos              (0U)
#define GPIO_AFRH_AFRH0_Msk              (0xFU << GPIO_AFRH_AFRH0_Pos)
#define GPIO_AFRH_AFRH0                  GPIO_AFRH_AFRH0_Msk
#define GPIO_AFRH_AFRH1_Pos              (4U)
#define GPIO_AFRH_AFRH1_Msk              (0xFU << GPIO_AFRH_AFRH1_Pos)
#define GPIO_AFRH_AFRH1                  GPIO_AFRH_AFRH1_Msk
#define GPIO_AFRH_AFRH2_Pos              (8U)
#define GPIO_AFRH_AFRH2_Msk              (0xFU << GPIO_AFRH_AFRH2_Pos)
#define GPIO_AFRH_AFRH2                  GPIO_AFRH_AFRH2_Msk
#define GPIO_AFRH_AFRH3_Pos              (12U)
#define GPIO_AFRH_AFRH3_Msk              (0xFU << GPIO_AFRH_AFRH3_Pos)
#define GPIO_AFRH_AFRH3                  GPIO_AFRH_AFRH3_Msk
#define GPIO_AFRH_AFRH4_Pos              (16U)
#define GPIO_AFRH_AFRH4_Msk              (0xFU << GPIO_AFRH_AFRH4_Pos)
#define GPIO_AFRH_AFRH4                  GPIO_AFRH_AFRH4_Msk
#define GPIO_AFRH_AFRH5_Pos              (20U)
#define GPIO_AFRH_AFRH5_Msk              (0xFU << GPIO_AFRH_AFRH5_Pos)
#define GPIO_AFRH_AFRH5                  GPIO_AFRH_AFRH5_Msk
#define GPIO_AFRH_AFRH6_Pos              (24U)
#define GPIO_AFRH_AFRH6_Msk              (0xFU << GPIO_AFRH_AFRH6_Pos)
#define GPIO_AFRH_AFRH6                  GPIO_AFRH_AFRH6_Msk
#define GPIO_AFRH_AFRH7_Pos              (28U)
#define GPIO_AFRH_AFRH7_Msk              (0xFU << GPIO_AFRH_AFRH7_Pos)
#define GPIO_AFRH_AFRH7                  GPIO_AFRH_AFRH7_Msk


#define GPIO_BRR_BR_0                    (0x00000001U)
#define GPIO_BRR_BR_1                    (0x00000002U)
#define GPIO_BRR_BR_2                    (0x00000004U)
#define GPIO_BRR_BR_3                    (0x00000008U)
#define GPIO_BRR_BR_4                    (0x00000010U)
#define GPIO_BRR_BR_5                    (0x00000020U)
#define GPIO_BRR_BR_6                    (0x00000040U)
#define GPIO_BRR_BR_7                    (0x00000080U)
#define GPIO_BRR_BR_8                    (0x00000100U)
#define GPIO_BRR_BR_9                    (0x00000200U)
#define GPIO_BRR_BR_10                   (0x00000400U)
#define GPIO_BRR_BR_11                   (0x00000800U)
#define GPIO_BRR_BR_12                   (0x00001000U)
#define GPIO_BRR_BR_13                   (0x00002000U)
#define GPIO_BRR_BR_14                   (0x00004000U)
#define GPIO_BRR_BR_15                   (0x00008000U)







#define I2C_CR1_PE_Pos               (0U)
#define I2C_CR1_PE_Msk               (0x1U << I2C_CR1_PE_Pos)
#define I2C_CR1_PE                   I2C_CR1_PE_Msk
#define I2C_CR1_TXIE_Pos             (1U)
#define I2C_CR1_TXIE_Msk             (0x1U << I2C_CR1_TXIE_Pos)
#define I2C_CR1_TXIE                 I2C_CR1_TXIE_Msk
#define I2C_CR1_RXIE_Pos             (2U)
#define I2C_CR1_RXIE_Msk             (0x1U << I2C_CR1_RXIE_Pos)
#define I2C_CR1_RXIE                 I2C_CR1_RXIE_Msk
#define I2C_CR1_ADDRIE_Pos           (3U)
#define I2C_CR1_ADDRIE_Msk           (0x1U << I2C_CR1_ADDRIE_Pos)
#define I2C_CR1_ADDRIE               I2C_CR1_ADDRIE_Msk
#define I2C_CR1_NACKIE_Pos           (4U)
#define I2C_CR1_NACKIE_Msk           (0x1U << I2C_CR1_NACKIE_Pos)
#define I2C_CR1_NACKIE               I2C_CR1_NACKIE_Msk
#define I2C_CR1_STOPIE_Pos           (5U)
#define I2C_CR1_STOPIE_Msk           (0x1U << I2C_CR1_STOPIE_Pos)
#define I2C_CR1_STOPIE               I2C_CR1_STOPIE_Msk
#define I2C_CR1_TCIE_Pos             (6U)
#define I2C_CR1_TCIE_Msk             (0x1U << I2C_CR1_TCIE_Pos)
#define I2C_CR1_TCIE                 I2C_CR1_TCIE_Msk
#define I2C_CR1_ERRIE_Pos            (7U)
#define I2C_CR1_ERRIE_Msk            (0x1U << I2C_CR1_ERRIE_Pos)
#define I2C_CR1_ERRIE                I2C_CR1_ERRIE_Msk
#define I2C_CR1_DNF_Pos              (8U)
#define I2C_CR1_DNF_Msk              (0xFU << I2C_CR1_DNF_Pos)
#define I2C_CR1_DNF                  I2C_CR1_DNF_Msk
#define I2C_CR1_ANFOFF_Pos           (12U)
#define I2C_CR1_ANFOFF_Msk           (0x1U << I2C_CR1_ANFOFF_Pos)
#define I2C_CR1_ANFOFF               I2C_CR1_ANFOFF_Msk
#define I2C_CR1_SWRST_Pos            (13U)
#define I2C_CR1_SWRST_Msk            (0x1U << I2C_CR1_SWRST_Pos)
#define I2C_CR1_SWRST                I2C_CR1_SWRST_Msk
#define I2C_CR1_TXDMAEN_Pos          (14U)
#define I2C_CR1_TXDMAEN_Msk          (0x1U << I2C_CR1_TXDMAEN_Pos)
#define I2C_CR1_TXDMAEN              I2C_CR1_TXDMAEN_Msk
#define I2C_CR1_RXDMAEN_Pos          (15U)
#define I2C_CR1_RXDMAEN_Msk          (0x1U << I2C_CR1_RXDMAEN_Pos)
#define I2C_CR1_RXDMAEN              I2C_CR1_RXDMAEN_Msk
#define I2C_CR1_SBC_Pos              (16U)
#define I2C_CR1_SBC_Msk              (0x1U << I2C_CR1_SBC_Pos)
#define I2C_CR1_SBC                  I2C_CR1_SBC_Msk
#define I2C_CR1_NOSTRETCH_Pos        (17U)
#define I2C_CR1_NOSTRETCH_Msk        (0x1U << I2C_CR1_NOSTRETCH_Pos)
#define I2C_CR1_NOSTRETCH            I2C_CR1_NOSTRETCH_Msk
#define I2C_CR1_WUPEN_Pos            (18U)
#define I2C_CR1_WUPEN_Msk            (0x1U << I2C_CR1_WUPEN_Pos)
#define I2C_CR1_WUPEN                I2C_CR1_WUPEN_Msk
#define I2C_CR1_GCEN_Pos             (19U)
#define I2C_CR1_GCEN_Msk             (0x1U << I2C_CR1_GCEN_Pos)
#define I2C_CR1_GCEN                 I2C_CR1_GCEN_Msk
#define I2C_CR1_SMBHEN_Pos           (20U)
#define I2C_CR1_SMBHEN_Msk           (0x1U << I2C_CR1_SMBHEN_Pos)
#define I2C_CR1_SMBHEN               I2C_CR1_SMBHEN_Msk
#define I2C_CR1_SMBDEN_Pos           (21U)
#define I2C_CR1_SMBDEN_Msk           (0x1U << I2C_CR1_SMBDEN_Pos)
#define I2C_CR1_SMBDEN               I2C_CR1_SMBDEN_Msk
#define I2C_CR1_ALERTEN_Pos          (22U)
#define I2C_CR1_ALERTEN_Msk          (0x1U << I2C_CR1_ALERTEN_Pos)
#define I2C_CR1_ALERTEN              I2C_CR1_ALERTEN_Msk
#define I2C_CR1_PECEN_Pos            (23U)
#define I2C_CR1_PECEN_Msk            (0x1U << I2C_CR1_PECEN_Pos)
#define I2C_CR1_PECEN                I2C_CR1_PECEN_Msk


#define I2C_CR1_DFN I2C_CR1_DNF


#define I2C_CR2_SADD_Pos             (0U)
#define I2C_CR2_SADD_Msk             (0x3FFU << I2C_CR2_SADD_Pos)
#define I2C_CR2_SADD                 I2C_CR2_SADD_Msk
#define I2C_CR2_RD_WRN_Pos           (10U)
#define I2C_CR2_RD_WRN_Msk           (0x1U << I2C_CR2_RD_WRN_Pos)
#define I2C_CR2_RD_WRN               I2C_CR2_RD_WRN_Msk
#define I2C_CR2_ADD10_Pos            (11U)
#define I2C_CR2_ADD10_Msk            (0x1U << I2C_CR2_ADD10_Pos)
#define I2C_CR2_ADD10                I2C_CR2_ADD10_Msk
#define I2C_CR2_HEAD10R_Pos          (12U)
#define I2C_CR2_HEAD10R_Msk          (0x1U << I2C_CR2_HEAD10R_Pos)
#define I2C_CR2_HEAD10R              I2C_CR2_HEAD10R_Msk
#define I2C_CR2_START_Pos            (13U)
#define I2C_CR2_START_Msk            (0x1U << I2C_CR2_START_Pos)
#define I2C_CR2_START                I2C_CR2_START_Msk
#define I2C_CR2_STOP_Pos             (14U)
#define I2C_CR2_STOP_Msk             (0x1U << I2C_CR2_STOP_Pos)
#define I2C_CR2_STOP                 I2C_CR2_STOP_Msk
#define I2C_CR2_NACK_Pos             (15U)
#define I2C_CR2_NACK_Msk             (0x1U << I2C_CR2_NACK_Pos)
#define I2C_CR2_NACK                 I2C_CR2_NACK_Msk
#define I2C_CR2_NBYTES_Pos           (16U)
#define I2C_CR2_NBYTES_Msk           (0xFFU << I2C_CR2_NBYTES_Pos)
#define I2C_CR2_NBYTES               I2C_CR2_NBYTES_Msk
#define I2C_CR2_RELOAD_Pos           (24U)
#define I2C_CR2_RELOAD_Msk           (0x1U << I2C_CR2_RELOAD_Pos)
#define I2C_CR2_RELOAD               I2C_CR2_RELOAD_Msk
#define I2C_CR2_AUTOEND_Pos          (25U)
#define I2C_CR2_AUTOEND_Msk          (0x1U << I2C_CR2_AUTOEND_Pos)
#define I2C_CR2_AUTOEND              I2C_CR2_AUTOEND_Msk
#define I2C_CR2_PECBYTE_Pos          (26U)
#define I2C_CR2_PECBYTE_Msk          (0x1U << I2C_CR2_PECBYTE_Pos)
#define I2C_CR2_PECBYTE              I2C_CR2_PECBYTE_Msk


#define I2C_OAR1_OA1_Pos             (0U)
#define I2C_OAR1_OA1_Msk             (0x3FFU << I2C_OAR1_OA1_Pos)
#define I2C_OAR1_OA1                 I2C_OAR1_OA1_Msk
#define I2C_OAR1_OA1MODE_Pos         (10U)
#define I2C_OAR1_OA1MODE_Msk         (0x1U << I2C_OAR1_OA1MODE_Pos)
#define I2C_OAR1_OA1MODE             I2C_OAR1_OA1MODE_Msk
#define I2C_OAR1_OA1EN_Pos           (15U)
#define I2C_OAR1_OA1EN_Msk           (0x1U << I2C_OAR1_OA1EN_Pos)
#define I2C_OAR1_OA1EN               I2C_OAR1_OA1EN_Msk


#define I2C_OAR2_OA2_Pos             (1U)
#define I2C_OAR2_OA2_Msk             (0x7FU << I2C_OAR2_OA2_Pos)
#define I2C_OAR2_OA2                 I2C_OAR2_OA2_Msk
#define I2C_OAR2_OA2MSK_Pos          (8U)
#define I2C_OAR2_OA2MSK_Msk          (0x7U << I2C_OAR2_OA2MSK_Pos)
#define I2C_OAR2_OA2MSK              I2C_OAR2_OA2MSK_Msk
#define I2C_OAR2_OA2NOMASK           (0x00000000U)
#define I2C_OAR2_OA2MASK01_Pos       (8U)
#define I2C_OAR2_OA2MASK01_Msk       (0x1U << I2C_OAR2_OA2MASK01_Pos)
#define I2C_OAR2_OA2MASK01           I2C_OAR2_OA2MASK01_Msk
#define I2C_OAR2_OA2MASK02_Pos       (9U)
#define I2C_OAR2_OA2MASK02_Msk       (0x1U << I2C_OAR2_OA2MASK02_Pos)
#define I2C_OAR2_OA2MASK02           I2C_OAR2_OA2MASK02_Msk
#define I2C_OAR2_OA2MASK03_Pos       (8U)
#define I2C_OAR2_OA2MASK03_Msk       (0x3U << I2C_OAR2_OA2MASK03_Pos)
#define I2C_OAR2_OA2MASK03           I2C_OAR2_OA2MASK03_Msk
#define I2C_OAR2_OA2MASK04_Pos       (10U)
#define I2C_OAR2_OA2MASK04_Msk       (0x1U << I2C_OAR2_OA2MASK04_Pos)
#define I2C_OAR2_OA2MASK04           I2C_OAR2_OA2MASK04_Msk
#define I2C_OAR2_OA2MASK05_Pos       (8U)
#define I2C_OAR2_OA2MASK05_Msk       (0x5U << I2C_OAR2_OA2MASK05_Pos)
#define I2C_OAR2_OA2MASK05           I2C_OAR2_OA2MASK05_Msk
#define I2C_OAR2_OA2MASK06_Pos       (9U)
#define I2C_OAR2_OA2MASK06_Msk       (0x3U << I2C_OAR2_OA2MASK06_Pos)
#define I2C_OAR2_OA2MASK06           I2C_OAR2_OA2MASK06_Msk
#define I2C_OAR2_OA2MASK07_Pos       (8U)
#define I2C_OAR2_OA2MASK07_Msk       (0x7U << I2C_OAR2_OA2MASK07_Pos)
#define I2C_OAR2_OA2MASK07           I2C_OAR2_OA2MASK07_Msk
#define I2C_OAR2_OA2EN_Pos           (15U)
#define I2C_OAR2_OA2EN_Msk           (0x1U << I2C_OAR2_OA2EN_Pos)
#define I2C_OAR2_OA2EN               I2C_OAR2_OA2EN_Msk


#define I2C_TIMINGR_SCLL_Pos         (0U)
#define I2C_TIMINGR_SCLL_Msk         (0xFFU << I2C_TIMINGR_SCLL_Pos)
#define I2C_TIMINGR_SCLL             I2C_TIMINGR_SCLL_Msk
#define I2C_TIMINGR_SCLH_Pos         (8U)
#define I2C_TIMINGR_SCLH_Msk         (0xFFU << I2C_TIMINGR_SCLH_Pos)
#define I2C_TIMINGR_SCLH             I2C_TIMINGR_SCLH_Msk
#define I2C_TIMINGR_SDADEL_Pos       (16U)
#define I2C_TIMINGR_SDADEL_Msk       (0xFU << I2C_TIMINGR_SDADEL_Pos)
#define I2C_TIMINGR_SDADEL           I2C_TIMINGR_SDADEL_Msk
#define I2C_TIMINGR_SCLDEL_Pos       (20U)
#define I2C_TIMINGR_SCLDEL_Msk       (0xFU << I2C_TIMINGR_SCLDEL_Pos)
#define I2C_TIMINGR_SCLDEL           I2C_TIMINGR_SCLDEL_Msk
#define I2C_TIMINGR_PRESC_Pos        (28U)
#define I2C_TIMINGR_PRESC_Msk        (0xFU << I2C_TIMINGR_PRESC_Pos)
#define I2C_TIMINGR_PRESC            I2C_TIMINGR_PRESC_Msk


#define I2C_TIMEOUTR_TIMEOUTA_Pos    (0U)
#define I2C_TIMEOUTR_TIMEOUTA_Msk    (0xFFFU << I2C_TIMEOUTR_TIMEOUTA_Pos)
#define I2C_TIMEOUTR_TIMEOUTA        I2C_TIMEOUTR_TIMEOUTA_Msk
#define I2C_TIMEOUTR_TIDLE_Pos       (12U)
#define I2C_TIMEOUTR_TIDLE_Msk       (0x1U << I2C_TIMEOUTR_TIDLE_Pos)
#define I2C_TIMEOUTR_TIDLE           I2C_TIMEOUTR_TIDLE_Msk
#define I2C_TIMEOUTR_TIMOUTEN_Pos    (15U)
#define I2C_TIMEOUTR_TIMOUTEN_Msk    (0x1U << I2C_TIMEOUTR_TIMOUTEN_Pos)
#define I2C_TIMEOUTR_TIMOUTEN        I2C_TIMEOUTR_TIMOUTEN_Msk
#define I2C_TIMEOUTR_TIMEOUTB_Pos    (16U)
#define I2C_TIMEOUTR_TIMEOUTB_Msk    (0xFFFU << I2C_TIMEOUTR_TIMEOUTB_Pos)
#define I2C_TIMEOUTR_TIMEOUTB        I2C_TIMEOUTR_TIMEOUTB_Msk
#define I2C_TIMEOUTR_TEXTEN_Pos      (31U)
#define I2C_TIMEOUTR_TEXTEN_Msk      (0x1U << I2C_TIMEOUTR_TEXTEN_Pos)
#define I2C_TIMEOUTR_TEXTEN          I2C_TIMEOUTR_TEXTEN_Msk


#define I2C_ISR_TXE_Pos              (0U)
#define I2C_ISR_TXE_Msk              (0x1U << I2C_ISR_TXE_Pos)
#define I2C_ISR_TXE                  I2C_ISR_TXE_Msk
#define I2C_ISR_TXIS_Pos             (1U)
#define I2C_ISR_TXIS_Msk             (0x1U << I2C_ISR_TXIS_Pos)
#define I2C_ISR_TXIS                 I2C_ISR_TXIS_Msk
#define I2C_ISR_RXNE_Pos             (2U)
#define I2C_ISR_RXNE_Msk             (0x1U << I2C_ISR_RXNE_Pos)
#define I2C_ISR_RXNE                 I2C_ISR_RXNE_Msk
#define I2C_ISR_ADDR_Pos             (3U)
#define I2C_ISR_ADDR_Msk             (0x1U << I2C_ISR_ADDR_Pos)
#define I2C_ISR_ADDR                 I2C_ISR_ADDR_Msk
#define I2C_ISR_NACKF_Pos            (4U)
#define I2C_ISR_NACKF_Msk            (0x1U << I2C_ISR_NACKF_Pos)
#define I2C_ISR_NACKF                I2C_ISR_NACKF_Msk
#define I2C_ISR_STOPF_Pos            (5U)
#define I2C_ISR_STOPF_Msk            (0x1U << I2C_ISR_STOPF_Pos)
#define I2C_ISR_STOPF                I2C_ISR_STOPF_Msk
#define I2C_ISR_TC_Pos               (6U)
#define I2C_ISR_TC_Msk               (0x1U << I2C_ISR_TC_Pos)
#define I2C_ISR_TC                   I2C_ISR_TC_Msk
#define I2C_ISR_TCR_Pos              (7U)
#define I2C_ISR_TCR_Msk              (0x1U << I2C_ISR_TCR_Pos)
#define I2C_ISR_TCR                  I2C_ISR_TCR_Msk
#define I2C_ISR_BERR_Pos             (8U)
#define I2C_ISR_BERR_Msk             (0x1U << I2C_ISR_BERR_Pos)
#define I2C_ISR_BERR                 I2C_ISR_BERR_Msk
#define I2C_ISR_ARLO_Pos             (9U)
#define I2C_ISR_ARLO_Msk             (0x1U << I2C_ISR_ARLO_Pos)
#define I2C_ISR_ARLO                 I2C_ISR_ARLO_Msk
#define I2C_ISR_OVR_Pos              (10U)
#define I2C_ISR_OVR_Msk              (0x1U << I2C_ISR_OVR_Pos)
#define I2C_ISR_OVR                  I2C_ISR_OVR_Msk
#define I2C_ISR_PECERR_Pos           (11U)
#define I2C_ISR_PECERR_Msk           (0x1U << I2C_ISR_PECERR_Pos)
#define I2C_ISR_PECERR               I2C_ISR_PECERR_Msk
#define I2C_ISR_TIMEOUT_Pos          (12U)
#define I2C_ISR_TIMEOUT_Msk          (0x1U << I2C_ISR_TIMEOUT_Pos)
#define I2C_ISR_TIMEOUT              I2C_ISR_TIMEOUT_Msk
#define I2C_ISR_ALERT_Pos            (13U)
#define I2C_ISR_ALERT_Msk            (0x1U << I2C_ISR_ALERT_Pos)
#define I2C_ISR_ALERT                I2C_ISR_ALERT_Msk
#define I2C_ISR_BUSY_Pos             (15U)
#define I2C_ISR_BUSY_Msk             (0x1U << I2C_ISR_BUSY_Pos)
#define I2C_ISR_BUSY                 I2C_ISR_BUSY_Msk
#define I2C_ISR_DIR_Pos              (16U)
#define I2C_ISR_DIR_Msk              (0x1U << I2C_ISR_DIR_Pos)
#define I2C_ISR_DIR                  I2C_ISR_DIR_Msk
#define I2C_ISR_ADDCODE_Pos          (17U)
#define I2C_ISR_ADDCODE_Msk          (0x7FU << I2C_ISR_ADDCODE_Pos)
#define I2C_ISR_ADDCODE              I2C_ISR_ADDCODE_Msk


#define I2C_ICR_ADDRCF_Pos           (3U)
#define I2C_ICR_ADDRCF_Msk           (0x1U << I2C_ICR_ADDRCF_Pos)
#define I2C_ICR_ADDRCF               I2C_ICR_ADDRCF_Msk
#define I2C_ICR_NACKCF_Pos           (4U)
#define I2C_ICR_NACKCF_Msk           (0x1U << I2C_ICR_NACKCF_Pos)
#define I2C_ICR_NACKCF               I2C_ICR_NACKCF_Msk
#define I2C_ICR_STOPCF_Pos           (5U)
#define I2C_ICR_STOPCF_Msk           (0x1U << I2C_ICR_STOPCF_Pos)
#define I2C_ICR_STOPCF               I2C_ICR_STOPCF_Msk
#define I2C_ICR_BERRCF_Pos           (8U)
#define I2C_ICR_BERRCF_Msk           (0x1U << I2C_ICR_BERRCF_Pos)
#define I2C_ICR_BERRCF               I2C_ICR_BERRCF_Msk
#define I2C_ICR_ARLOCF_Pos           (9U)
#define I2C_ICR_ARLOCF_Msk           (0x1U << I2C_ICR_ARLOCF_Pos)
#define I2C_ICR_ARLOCF               I2C_ICR_ARLOCF_Msk
#define I2C_ICR_OVRCF_Pos            (10U)
#define I2C_ICR_OVRCF_Msk            (0x1U << I2C_ICR_OVRCF_Pos)
#define I2C_ICR_OVRCF                I2C_ICR_OVRCF_Msk
#define I2C_ICR_PECCF_Pos            (11U)
#define I2C_ICR_PECCF_Msk            (0x1U << I2C_ICR_PECCF_Pos)
#define I2C_ICR_PECCF                I2C_ICR_PECCF_Msk
#define I2C_ICR_TIMOUTCF_Pos         (12U)
#define I2C_ICR_TIMOUTCF_Msk         (0x1U << I2C_ICR_TIMOUTCF_Pos)
#define I2C_ICR_TIMOUTCF             I2C_ICR_TIMOUTCF_Msk
#define I2C_ICR_ALERTCF_Pos          (13U)
#define I2C_ICR_ALERTCF_Msk          (0x1U << I2C_ICR_ALERTCF_Pos)
#define I2C_ICR_ALERTCF              I2C_ICR_ALERTCF_Msk


#define I2C_PECR_PEC_Pos             (0U)
#define I2C_PECR_PEC_Msk             (0xFFU << I2C_PECR_PEC_Pos)
#define I2C_PECR_PEC                 I2C_PECR_PEC_Msk


#define I2C_RXDR_RXDATA_Pos          (0U)
#define I2C_RXDR_RXDATA_Msk          (0xFFU << I2C_RXDR_RXDATA_Pos)
#define I2C_RXDR_RXDATA              I2C_RXDR_RXDATA_Msk


#define I2C_TXDR_TXDATA_Pos          (0U)
#define I2C_TXDR_TXDATA_Msk          (0xFFU << I2C_TXDR_TXDATA_Pos)
#define I2C_TXDR_TXDATA              I2C_TXDR_TXDATA_Msk








#define IWDG_KR_KEY_Pos      (0U)
#define IWDG_KR_KEY_Msk      (0xFFFFU << IWDG_KR_KEY_Pos)
#define IWDG_KR_KEY          IWDG_KR_KEY_Msk


#define IWDG_PR_PR_Pos       (0U)
#define IWDG_PR_PR_Msk       (0x7U << IWDG_PR_PR_Pos)
#define IWDG_PR_PR           IWDG_PR_PR_Msk
#define IWDG_PR_PR_0         (0x1U << IWDG_PR_PR_Pos)
#define IWDG_PR_PR_1         (0x2U << IWDG_PR_PR_Pos)
#define IWDG_PR_PR_2         (0x4U << IWDG_PR_PR_Pos)


#define IWDG_RLR_RL_Pos      (0U)
#define IWDG_RLR_RL_Msk      (0xFFFU << IWDG_RLR_RL_Pos)
#define IWDG_RLR_RL          IWDG_RLR_RL_Msk


#define IWDG_SR_PVU_Pos      (0U)
#define IWDG_SR_PVU_Msk      (0x1U << IWDG_SR_PVU_Pos)
#define IWDG_SR_PVU          IWDG_SR_PVU_Msk
#define IWDG_SR_RVU_Pos      (1U)
#define IWDG_SR_RVU_Msk      (0x1U << IWDG_SR_RVU_Pos)
#define IWDG_SR_RVU          IWDG_SR_RVU_Msk
#define IWDG_SR_WVU_Pos      (2U)
#define IWDG_SR_WVU_Msk      (0x1U << IWDG_SR_WVU_Pos)
#define IWDG_SR_WVU          IWDG_SR_WVU_Msk


#define IWDG_WINR_WIN_Pos    (0U)
#define IWDG_WINR_WIN_Msk    (0xFFFU << IWDG_WINR_WIN_Pos)
#define IWDG_WINR_WIN        IWDG_WINR_WIN_Msk






#define PWR_PVD_SUPPORT

#define PWR_CR_LPDS_Pos            (0U)
#define PWR_CR_LPDS_Msk            (0x1U << PWR_CR_LPDS_Pos)
#define PWR_CR_LPDS                PWR_CR_LPDS_Msk
#define PWR_CR_PDDS_Pos            (1U)
#define PWR_CR_PDDS_Msk            (0x1U << PWR_CR_PDDS_Pos)
#define PWR_CR_PDDS                PWR_CR_PDDS_Msk
#define PWR_CR_CWUF_Pos            (2U)
#define PWR_CR_CWUF_Msk            (0x1U << PWR_CR_CWUF_Pos)
#define PWR_CR_CWUF                PWR_CR_CWUF_Msk
#define PWR_CR_CSBF_Pos            (3U)
#define PWR_CR_CSBF_Msk            (0x1U << PWR_CR_CSBF_Pos)
#define PWR_CR_CSBF                PWR_CR_CSBF_Msk
#define PWR_CR_PVDE_Pos            (4U)
#define PWR_CR_PVDE_Msk            (0x1U << PWR_CR_PVDE_Pos)
#define PWR_CR_PVDE                PWR_CR_PVDE_Msk

#define PWR_CR_PLS_Pos             (5U)
#define PWR_CR_PLS_Msk             (0x7U << PWR_CR_PLS_Pos)
#define PWR_CR_PLS                 PWR_CR_PLS_Msk
#define PWR_CR_PLS_0               (0x1U << PWR_CR_PLS_Pos)
#define PWR_CR_PLS_1               (0x2U << PWR_CR_PLS_Pos)
#define PWR_CR_PLS_2               (0x4U << PWR_CR_PLS_Pos)


#define PWR_CR_PLS_LEV0            (0x00000000U)
#define PWR_CR_PLS_LEV1            (0x00000020U)
#define PWR_CR_PLS_LEV2            (0x00000040U)
#define PWR_CR_PLS_LEV3            (0x00000060U)
#define PWR_CR_PLS_LEV4            (0x00000080U)
#define PWR_CR_PLS_LEV5            (0x000000A0U)
#define PWR_CR_PLS_LEV6            (0x000000C0U)
#define PWR_CR_PLS_LEV7            (0x000000E0U)

#define PWR_CR_DBP_Pos             (8U)
#define PWR_CR_DBP_Msk             (0x1U << PWR_CR_DBP_Pos)
#define PWR_CR_DBP                 PWR_CR_DBP_Msk


#define PWR_CSR_WUF_Pos            (0U)
#define PWR_CSR_WUF_Msk            (0x1U << PWR_CSR_WUF_Pos)
#define PWR_CSR_WUF                PWR_CSR_WUF_Msk
#define PWR_CSR_SBF_Pos            (1U)
#define PWR_CSR_SBF_Msk            (0x1U << PWR_CSR_SBF_Pos)
#define PWR_CSR_SBF                PWR_CSR_SBF_Msk
#define PWR_CSR_PVDO_Pos           (2U)
#define PWR_CSR_PVDO_Msk           (0x1U << PWR_CSR_PVDO_Pos)
#define PWR_CSR_PVDO               PWR_CSR_PVDO_Msk

#define PWR_CSR_EWUP1_Pos          (8U)
#define PWR_CSR_EWUP1_Msk          (0x1U << PWR_CSR_EWUP1_Pos)
#define PWR_CSR_EWUP1              PWR_CSR_EWUP1_Msk
#define PWR_CSR_EWUP2_Pos          (9U)
#define PWR_CSR_EWUP2_Msk          (0x1U << PWR_CSR_EWUP2_Pos)
#define PWR_CSR_EWUP2              PWR_CSR_EWUP2_Msk
#define PWR_CSR_EWUP3_Pos          (10U)
#define PWR_CSR_EWUP3_Msk          (0x1U << PWR_CSR_EWUP3_Pos)
#define PWR_CSR_EWUP3              PWR_CSR_EWUP3_Msk











#define RCC_CR_HSION_Pos                         (0U)
#define RCC_CR_HSION_Msk                         (0x1U << RCC_CR_HSION_Pos)
#define RCC_CR_HSION                             RCC_CR_HSION_Msk
#define RCC_CR_HSIRDY_Pos                        (1U)
#define RCC_CR_HSIRDY_Msk                        (0x1U << RCC_CR_HSIRDY_Pos)
#define RCC_CR_HSIRDY                            RCC_CR_HSIRDY_Msk

#define RCC_CR_HSITRIM_Pos                       (3U)
#define RCC_CR_HSITRIM_Msk                       (0x1FU << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM                           RCC_CR_HSITRIM_Msk
#define RCC_CR_HSITRIM_0                         (0x01U << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_1                         (0x02U << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_2                         (0x04U << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_3                         (0x08U << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_4                         (0x10U << RCC_CR_HSITRIM_Pos)

#define RCC_CR_HSICAL_Pos                        (8U)
#define RCC_CR_HSICAL_Msk                        (0xFFU << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL                            RCC_CR_HSICAL_Msk
#define RCC_CR_HSICAL_0                          (0x01U << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_1                          (0x02U << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_2                          (0x04U << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_3                          (0x08U << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_4                          (0x10U << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_5                          (0x20U << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_6                          (0x40U << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL_7                          (0x80U << RCC_CR_HSICAL_Pos)

#define RCC_CR_HSEON_Pos                         (16U)
#define RCC_CR_HSEON_Msk                         (0x1U << RCC_CR_HSEON_Pos)
#define RCC_CR_HSEON                             RCC_CR_HSEON_Msk
#define RCC_CR_HSERDY_Pos                        (17U)
#define RCC_CR_HSERDY_Msk                        (0x1U << RCC_CR_HSERDY_Pos)
#define RCC_CR_HSERDY                            RCC_CR_HSERDY_Msk
#define RCC_CR_HSEBYP_Pos                        (18U)
#define RCC_CR_HSEBYP_Msk                        (0x1U << RCC_CR_HSEBYP_Pos)
#define RCC_CR_HSEBYP                            RCC_CR_HSEBYP_Msk
#define RCC_CR_CSSON_Pos                         (19U)
#define RCC_CR_CSSON_Msk                         (0x1U << RCC_CR_CSSON_Pos)
#define RCC_CR_CSSON                             RCC_CR_CSSON_Msk
#define RCC_CR_PLLON_Pos                         (24U)
#define RCC_CR_PLLON_Msk                         (0x1U << RCC_CR_PLLON_Pos)
#define RCC_CR_PLLON                             RCC_CR_PLLON_Msk
#define RCC_CR_PLLRDY_Pos                        (25U)
#define RCC_CR_PLLRDY_Msk                        (0x1U << RCC_CR_PLLRDY_Pos)
#define RCC_CR_PLLRDY                            RCC_CR_PLLRDY_Msk



#define RCC_CFGR_SW_Pos                          (0U)
#define RCC_CFGR_SW_Msk                          (0x3U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW                              RCC_CFGR_SW_Msk
#define RCC_CFGR_SW_0                            (0x1U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_1                            (0x2U << RCC_CFGR_SW_Pos)

#define RCC_CFGR_SW_HSI                          (0x00000000U)
#define RCC_CFGR_SW_HSE                          (0x00000001U)
#define RCC_CFGR_SW_PLL                          (0x00000002U)


#define RCC_CFGR_SWS_Pos                         (2U)
#define RCC_CFGR_SWS_Msk                         (0x3U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS                             RCC_CFGR_SWS_Msk
#define RCC_CFGR_SWS_0                           (0x1U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_1                           (0x2U << RCC_CFGR_SWS_Pos)

#define RCC_CFGR_SWS_HSI                         (0x00000000U)
#define RCC_CFGR_SWS_HSE                         (0x00000004U)
#define RCC_CFGR_SWS_PLL                         (0x00000008U)


#define RCC_CFGR_HPRE_Pos                        (4U)
#define RCC_CFGR_HPRE_Msk                        (0xFU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE                            RCC_CFGR_HPRE_Msk
#define RCC_CFGR_HPRE_0                          (0x1U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_1                          (0x2U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_2                          (0x4U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_3                          (0x8U << RCC_CFGR_HPRE_Pos)

#define RCC_CFGR_HPRE_DIV1                       (0x00000000U)
#define RCC_CFGR_HPRE_DIV2                       (0x00000080U)
#define RCC_CFGR_HPRE_DIV4                       (0x00000090U)
#define RCC_CFGR_HPRE_DIV8                       (0x000000A0U)
#define RCC_CFGR_HPRE_DIV16                      (0x000000B0U)
#define RCC_CFGR_HPRE_DIV64                      (0x000000C0U)
#define RCC_CFGR_HPRE_DIV128                     (0x000000D0U)
#define RCC_CFGR_HPRE_DIV256                     (0x000000E0U)
#define RCC_CFGR_HPRE_DIV512                     (0x000000F0U)


#define RCC_CFGR_PPRE1_Pos                       (8U)
#define RCC_CFGR_PPRE1_Msk                       (0x7U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1                           RCC_CFGR_PPRE1_Msk
#define RCC_CFGR_PPRE1_0                         (0x1U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_1                         (0x2U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_2                         (0x4U << RCC_CFGR_PPRE1_Pos)

#define RCC_CFGR_PPRE1_DIV1                      (0x00000000U)
#define RCC_CFGR_PPRE1_DIV2                      (0x00000400U)
#define RCC_CFGR_PPRE1_DIV4                      (0x00000500U)
#define RCC_CFGR_PPRE1_DIV8                      (0x00000600U)
#define RCC_CFGR_PPRE1_DIV16                     (0x00000700U)


#define RCC_CFGR_PPRE2_Pos                       (11U)
#define RCC_CFGR_PPRE2_Msk                       (0x7U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2                           RCC_CFGR_PPRE2_Msk
#define RCC_CFGR_PPRE2_0                         (0x1U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_1                         (0x2U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_2                         (0x4U << RCC_CFGR_PPRE2_Pos)

#define RCC_CFGR_PPRE2_DIV1                      (0x00000000U)
#define RCC_CFGR_PPRE2_DIV2                      (0x00002000U)
#define RCC_CFGR_PPRE2_DIV4                      (0x00002800U)
#define RCC_CFGR_PPRE2_DIV8                      (0x00003000U)
#define RCC_CFGR_PPRE2_DIV16                     (0x00003800U)

#define RCC_CFGR_PLLSRC_Pos                      (16U)
#define RCC_CFGR_PLLSRC_Msk                      (0x1U << RCC_CFGR_PLLSRC_Pos)
#define RCC_CFGR_PLLSRC                          RCC_CFGR_PLLSRC_Msk
#define RCC_CFGR_PLLSRC_HSI_DIV2                 (0x00000000U)
#define RCC_CFGR_PLLSRC_HSE_PREDIV               (0x00010000U)

#define RCC_CFGR_PLLXTPRE_Pos                    (17U)
#define RCC_CFGR_PLLXTPRE_Msk                    (0x1U << RCC_CFGR_PLLXTPRE_Pos)
#define RCC_CFGR_PLLXTPRE                        RCC_CFGR_PLLXTPRE_Msk
#define RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV1        (0x00000000U)
#define RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV2        (0x00020000U)


#define RCC_CFGR_PLLMUL_Pos                      (18U)
#define RCC_CFGR_PLLMUL_Msk                      (0xFU << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL                          RCC_CFGR_PLLMUL_Msk
#define RCC_CFGR_PLLMUL_0                        (0x1U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_1                        (0x2U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_2                        (0x4U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_3                        (0x8U << RCC_CFGR_PLLMUL_Pos)

#define RCC_CFGR_PLLMUL2                         (0x00000000U)
#define RCC_CFGR_PLLMUL3                         (0x00040000U)
#define RCC_CFGR_PLLMUL4                         (0x00080000U)
#define RCC_CFGR_PLLMUL5                         (0x000C0000U)
#define RCC_CFGR_PLLMUL6                         (0x00100000U)
#define RCC_CFGR_PLLMUL7                         (0x00140000U)
#define RCC_CFGR_PLLMUL8                         (0x00180000U)
#define RCC_CFGR_PLLMUL9                         (0x001C0000U)
#define RCC_CFGR_PLLMUL10                        (0x00200000U)
#define RCC_CFGR_PLLMUL11                        (0x00240000U)
#define RCC_CFGR_PLLMUL12                        (0x00280000U)
#define RCC_CFGR_PLLMUL13                        (0x002C0000U)
#define RCC_CFGR_PLLMUL14                        (0x00300000U)
#define RCC_CFGR_PLLMUL15                        (0x00340000U)
#define RCC_CFGR_PLLMUL16                        (0x00380000U)


#define RCC_CFGR_MCO_Pos                         (24U)
#define RCC_CFGR_MCO_Msk                         (0x7U << RCC_CFGR_MCO_Pos)
#define RCC_CFGR_MCO                             RCC_CFGR_MCO_Msk
#define RCC_CFGR_MCO_0                           (0x1U << RCC_CFGR_MCO_Pos)
#define RCC_CFGR_MCO_1                           (0x2U << RCC_CFGR_MCO_Pos)
#define RCC_CFGR_MCO_2                           (0x4U << RCC_CFGR_MCO_Pos)

#define RCC_CFGR_MCO_NOCLOCK                     (0x00000000U)
#define RCC_CFGR_MCO_LSI                         (0x02000000U)
#define RCC_CFGR_MCO_LSE                         (0x03000000U)
#define RCC_CFGR_MCO_SYSCLK                      (0x04000000U)
#define RCC_CFGR_MCO_HSI                         (0x05000000U)
#define RCC_CFGR_MCO_HSE                         (0x06000000U)
#define RCC_CFGR_MCO_PLL                         (0x07000000U)

#define RCC_CFGR_MCOPRE_Pos                      (28U)
#define RCC_CFGR_MCOPRE_Msk                      (0x7U << RCC_CFGR_MCOPRE_Pos)
#define RCC_CFGR_MCOPRE                          RCC_CFGR_MCOPRE_Msk
#define RCC_CFGR_MCOPRE_0                        (0x1U << RCC_CFGR_MCOPRE_Pos)
#define RCC_CFGR_MCOPRE_1                        (0x2U << RCC_CFGR_MCOPRE_Pos)
#define RCC_CFGR_MCOPRE_2                        (0x4U << RCC_CFGR_MCOPRE_Pos)

#define RCC_CFGR_MCOPRE_DIV1                     (0x00000000U)
#define RCC_CFGR_MCOPRE_DIV2                     (0x10000000U)
#define RCC_CFGR_MCOPRE_DIV4                     (0x20000000U)
#define RCC_CFGR_MCOPRE_DIV8                     (0x30000000U)
#define RCC_CFGR_MCOPRE_DIV16                    (0x40000000U)
#define RCC_CFGR_MCOPRE_DIV32                    (0x50000000U)
#define RCC_CFGR_MCOPRE_DIV64                    (0x60000000U)
#define RCC_CFGR_MCOPRE_DIV128                   (0x70000000U)

#define RCC_CFGR_PLLNODIV_Pos                    (31U)
#define RCC_CFGR_PLLNODIV_Msk                    (0x1U << RCC_CFGR_PLLNODIV_Pos)
#define RCC_CFGR_PLLNODIV                        RCC_CFGR_PLLNODIV_Msk


#define RCC_CFGR_MCOSEL                      RCC_CFGR_MCO
#define RCC_CFGR_MCOSEL_0                    RCC_CFGR_MCO_0
#define RCC_CFGR_MCOSEL_1                    RCC_CFGR_MCO_1
#define RCC_CFGR_MCOSEL_2                    RCC_CFGR_MCO_2
#define RCC_CFGR_MCOSEL_NOCLOCK              RCC_CFGR_MCO_NOCLOCK
#define RCC_CFGR_MCOSEL_LSI                  RCC_CFGR_MCO_LSI
#define RCC_CFGR_MCOSEL_LSE                  RCC_CFGR_MCO_LSE
#define RCC_CFGR_MCOSEL_SYSCLK               RCC_CFGR_MCO_SYSCLK
#define RCC_CFGR_MCOSEL_HSI                  RCC_CFGR_MCO_HSI
#define RCC_CFGR_MCOSEL_HSE                  RCC_CFGR_MCO_HSE
#define RCC_CFGR_MCOSEL_PLL_DIV2             RCC_CFGR_MCO_PLL


#define RCC_CIR_LSIRDYF_Pos                      (0U)
#define RCC_CIR_LSIRDYF_Msk                      (0x1U << RCC_CIR_LSIRDYF_Pos)
#define RCC_CIR_LSIRDYF                          RCC_CIR_LSIRDYF_Msk
#define RCC_CIR_LSERDYF_Pos                      (1U)
#define RCC_CIR_LSERDYF_Msk                      (0x1U << RCC_CIR_LSERDYF_Pos)
#define RCC_CIR_LSERDYF                          RCC_CIR_LSERDYF_Msk
#define RCC_CIR_HSIRDYF_Pos                      (2U)
#define RCC_CIR_HSIRDYF_Msk                      (0x1U << RCC_CIR_HSIRDYF_Pos)
#define RCC_CIR_HSIRDYF                          RCC_CIR_HSIRDYF_Msk
#define RCC_CIR_HSERDYF_Pos                      (3U)
#define RCC_CIR_HSERDYF_Msk                      (0x1U << RCC_CIR_HSERDYF_Pos)
#define RCC_CIR_HSERDYF                          RCC_CIR_HSERDYF_Msk
#define RCC_CIR_PLLRDYF_Pos                      (4U)
#define RCC_CIR_PLLRDYF_Msk                      (0x1U << RCC_CIR_PLLRDYF_Pos)
#define RCC_CIR_PLLRDYF                          RCC_CIR_PLLRDYF_Msk
#define RCC_CIR_CSSF_Pos                         (7U)
#define RCC_CIR_CSSF_Msk                         (0x1U << RCC_CIR_CSSF_Pos)
#define RCC_CIR_CSSF                             RCC_CIR_CSSF_Msk
#define RCC_CIR_LSIRDYIE_Pos                     (8U)
#define RCC_CIR_LSIRDYIE_Msk                     (0x1U << RCC_CIR_LSIRDYIE_Pos)
#define RCC_CIR_LSIRDYIE                         RCC_CIR_LSIRDYIE_Msk
#define RCC_CIR_LSERDYIE_Pos                     (9U)
#define RCC_CIR_LSERDYIE_Msk                     (0x1U << RCC_CIR_LSERDYIE_Pos)
#define RCC_CIR_LSERDYIE                         RCC_CIR_LSERDYIE_Msk
#define RCC_CIR_HSIRDYIE_Pos                     (10U)
#define RCC_CIR_HSIRDYIE_Msk                     (0x1U << RCC_CIR_HSIRDYIE_Pos)
#define RCC_CIR_HSIRDYIE                         RCC_CIR_HSIRDYIE_Msk
#define RCC_CIR_HSERDYIE_Pos                     (11U)
#define RCC_CIR_HSERDYIE_Msk                     (0x1U << RCC_CIR_HSERDYIE_Pos)
#define RCC_CIR_HSERDYIE                         RCC_CIR_HSERDYIE_Msk
#define RCC_CIR_PLLRDYIE_Pos                     (12U)
#define RCC_CIR_PLLRDYIE_Msk                     (0x1U << RCC_CIR_PLLRDYIE_Pos)
#define RCC_CIR_PLLRDYIE                         RCC_CIR_PLLRDYIE_Msk
#define RCC_CIR_LSIRDYC_Pos                      (16U)
#define RCC_CIR_LSIRDYC_Msk                      (0x1U << RCC_CIR_LSIRDYC_Pos)
#define RCC_CIR_LSIRDYC                          RCC_CIR_LSIRDYC_Msk
#define RCC_CIR_LSERDYC_Pos                      (17U)
#define RCC_CIR_LSERDYC_Msk                      (0x1U << RCC_CIR_LSERDYC_Pos)
#define RCC_CIR_LSERDYC                          RCC_CIR_LSERDYC_Msk
#define RCC_CIR_HSIRDYC_Pos                      (18U)
#define RCC_CIR_HSIRDYC_Msk                      (0x1U << RCC_CIR_HSIRDYC_Pos)
#define RCC_CIR_HSIRDYC                          RCC_CIR_HSIRDYC_Msk
#define RCC_CIR_HSERDYC_Pos                      (19U)
#define RCC_CIR_HSERDYC_Msk                      (0x1U << RCC_CIR_HSERDYC_Pos)
#define RCC_CIR_HSERDYC                          RCC_CIR_HSERDYC_Msk
#define RCC_CIR_PLLRDYC_Pos                      (20U)
#define RCC_CIR_PLLRDYC_Msk                      (0x1U << RCC_CIR_PLLRDYC_Pos)
#define RCC_CIR_PLLRDYC                          RCC_CIR_PLLRDYC_Msk
#define RCC_CIR_CSSC_Pos                         (23U)
#define RCC_CIR_CSSC_Msk                         (0x1U << RCC_CIR_CSSC_Pos)
#define RCC_CIR_CSSC                             RCC_CIR_CSSC_Msk


#define RCC_APB2RSTR_SYSCFGRST_Pos               (0U)
#define RCC_APB2RSTR_SYSCFGRST_Msk               (0x1U << RCC_APB2RSTR_SYSCFGRST_Pos)
#define RCC_APB2RSTR_SYSCFGRST                   RCC_APB2RSTR_SYSCFGRST_Msk
#define RCC_APB2RSTR_TIM1RST_Pos                 (11U)
#define RCC_APB2RSTR_TIM1RST_Msk                 (0x1U << RCC_APB2RSTR_TIM1RST_Pos)
#define RCC_APB2RSTR_TIM1RST                     RCC_APB2RSTR_TIM1RST_Msk
#define RCC_APB2RSTR_SPI1RST_Pos                 (12U)
#define RCC_APB2RSTR_SPI1RST_Msk                 (0x1U << RCC_APB2RSTR_SPI1RST_Pos)
#define RCC_APB2RSTR_SPI1RST                     RCC_APB2RSTR_SPI1RST_Msk
#define RCC_APB2RSTR_USART1RST_Pos               (14U)
#define RCC_APB2RSTR_USART1RST_Msk               (0x1U << RCC_APB2RSTR_USART1RST_Pos)
#define RCC_APB2RSTR_USART1RST                   RCC_APB2RSTR_USART1RST_Msk
#define RCC_APB2RSTR_TIM15RST_Pos                (16U)
#define RCC_APB2RSTR_TIM15RST_Msk                (0x1U << RCC_APB2RSTR_TIM15RST_Pos)
#define RCC_APB2RSTR_TIM15RST                    RCC_APB2RSTR_TIM15RST_Msk
#define RCC_APB2RSTR_TIM16RST_Pos                (17U)
#define RCC_APB2RSTR_TIM16RST_Msk                (0x1U << RCC_APB2RSTR_TIM16RST_Pos)
#define RCC_APB2RSTR_TIM16RST                    RCC_APB2RSTR_TIM16RST_Msk
#define RCC_APB2RSTR_TIM17RST_Pos                (18U)
#define RCC_APB2RSTR_TIM17RST_Msk                (0x1U << RCC_APB2RSTR_TIM17RST_Pos)
#define RCC_APB2RSTR_TIM17RST                    RCC_APB2RSTR_TIM17RST_Msk


#define RCC_APB1RSTR_TIM2RST_Pos                 (0U)
#define RCC_APB1RSTR_TIM2RST_Msk                 (0x1U << RCC_APB1RSTR_TIM2RST_Pos)
#define RCC_APB1RSTR_TIM2RST                     RCC_APB1RSTR_TIM2RST_Msk
#define RCC_APB1RSTR_TIM3RST_Pos                 (1U)
#define RCC_APB1RSTR_TIM3RST_Msk                 (0x1U << RCC_APB1RSTR_TIM3RST_Pos)
#define RCC_APB1RSTR_TIM3RST                     RCC_APB1RSTR_TIM3RST_Msk
#define RCC_APB1RSTR_TIM6RST_Pos                 (4U)
#define RCC_APB1RSTR_TIM6RST_Msk                 (0x1U << RCC_APB1RSTR_TIM6RST_Pos)
#define RCC_APB1RSTR_TIM6RST                     RCC_APB1RSTR_TIM6RST_Msk
#define RCC_APB1RSTR_TIM7RST_Pos                 (5U)
#define RCC_APB1RSTR_TIM7RST_Msk                 (0x1U << RCC_APB1RSTR_TIM7RST_Pos)
#define RCC_APB1RSTR_TIM7RST                     RCC_APB1RSTR_TIM7RST_Msk
#define RCC_APB1RSTR_WWDGRST_Pos                 (11U)
#define RCC_APB1RSTR_WWDGRST_Msk                 (0x1U << RCC_APB1RSTR_WWDGRST_Pos)
#define RCC_APB1RSTR_WWDGRST                     RCC_APB1RSTR_WWDGRST_Msk
#define RCC_APB1RSTR_USART2RST_Pos               (17U)
#define RCC_APB1RSTR_USART2RST_Msk               (0x1U << RCC_APB1RSTR_USART2RST_Pos)
#define RCC_APB1RSTR_USART2RST                   RCC_APB1RSTR_USART2RST_Msk
#define RCC_APB1RSTR_USART3RST_Pos               (18U)
#define RCC_APB1RSTR_USART3RST_Msk               (0x1U << RCC_APB1RSTR_USART3RST_Pos)
#define RCC_APB1RSTR_USART3RST                   RCC_APB1RSTR_USART3RST_Msk
#define RCC_APB1RSTR_I2C1RST_Pos                 (21U)
#define RCC_APB1RSTR_I2C1RST_Msk                 (0x1U << RCC_APB1RSTR_I2C1RST_Pos)
#define RCC_APB1RSTR_I2C1RST                     RCC_APB1RSTR_I2C1RST_Msk
#define RCC_APB1RSTR_CANRST_Pos                  (25U)
#define RCC_APB1RSTR_CANRST_Msk                  (0x1U << RCC_APB1RSTR_CANRST_Pos)
#define RCC_APB1RSTR_CANRST                      RCC_APB1RSTR_CANRST_Msk
#define RCC_APB1RSTR_DAC2RST_Pos                 (26U)
#define RCC_APB1RSTR_DAC2RST_Msk                 (0x1U << RCC_APB1RSTR_DAC2RST_Pos)
#define RCC_APB1RSTR_DAC2RST                     RCC_APB1RSTR_DAC2RST_Msk
#define RCC_APB1RSTR_PWRRST_Pos                  (28U)
#define RCC_APB1RSTR_PWRRST_Msk                  (0x1U << RCC_APB1RSTR_PWRRST_Pos)
#define RCC_APB1RSTR_PWRRST                      RCC_APB1RSTR_PWRRST_Msk
#define RCC_APB1RSTR_DAC1RST_Pos                 (29U)
#define RCC_APB1RSTR_DAC1RST_Msk                 (0x1U << RCC_APB1RSTR_DAC1RST_Pos)
#define RCC_APB1RSTR_DAC1RST                     RCC_APB1RSTR_DAC1RST_Msk


#define RCC_AHBENR_DMA1EN_Pos                    (0U)
#define RCC_AHBENR_DMA1EN_Msk                    (0x1U << RCC_AHBENR_DMA1EN_Pos)
#define RCC_AHBENR_DMA1EN                        RCC_AHBENR_DMA1EN_Msk
#define RCC_AHBENR_SRAMEN_Pos                    (2U)
#define RCC_AHBENR_SRAMEN_Msk                    (0x1U << RCC_AHBENR_SRAMEN_Pos)
#define RCC_AHBENR_SRAMEN                        RCC_AHBENR_SRAMEN_Msk
#define RCC_AHBENR_FLITFEN_Pos                   (4U)
#define RCC_AHBENR_FLITFEN_Msk                   (0x1U << RCC_AHBENR_FLITFEN_Pos)
#define RCC_AHBENR_FLITFEN                       RCC_AHBENR_FLITFEN_Msk
#define RCC_AHBENR_CRCEN_Pos                     (6U)
#define RCC_AHBENR_CRCEN_Msk                     (0x1U << RCC_AHBENR_CRCEN_Pos)
#define RCC_AHBENR_CRCEN                         RCC_AHBENR_CRCEN_Msk
#define RCC_AHBENR_GPIOAEN_Pos                   (17U)
#define RCC_AHBENR_GPIOAEN_Msk                   (0x1U << RCC_AHBENR_GPIOAEN_Pos)
#define RCC_AHBENR_GPIOAEN                       RCC_AHBENR_GPIOAEN_Msk
#define RCC_AHBENR_GPIOBEN_Pos                   (18U)
#define RCC_AHBENR_GPIOBEN_Msk                   (0x1U << RCC_AHBENR_GPIOBEN_Pos)
#define RCC_AHBENR_GPIOBEN                       RCC_AHBENR_GPIOBEN_Msk
#define RCC_AHBENR_GPIOCEN_Pos                   (19U)
#define RCC_AHBENR_GPIOCEN_Msk                   (0x1U << RCC_AHBENR_GPIOCEN_Pos)
#define RCC_AHBENR_GPIOCEN                       RCC_AHBENR_GPIOCEN_Msk
#define RCC_AHBENR_GPIODEN_Pos                   (20U)
#define RCC_AHBENR_GPIODEN_Msk                   (0x1U << RCC_AHBENR_GPIODEN_Pos)
#define RCC_AHBENR_GPIODEN                       RCC_AHBENR_GPIODEN_Msk
#define RCC_AHBENR_GPIOFEN_Pos                   (22U)
#define RCC_AHBENR_GPIOFEN_Msk                   (0x1U << RCC_AHBENR_GPIOFEN_Pos)
#define RCC_AHBENR_GPIOFEN                       RCC_AHBENR_GPIOFEN_Msk
#define RCC_AHBENR_TSCEN_Pos                     (24U)
#define RCC_AHBENR_TSCEN_Msk                     (0x1U << RCC_AHBENR_TSCEN_Pos)
#define RCC_AHBENR_TSCEN                         RCC_AHBENR_TSCEN_Msk
#define RCC_AHBENR_ADC12EN_Pos                   (28U)
#define RCC_AHBENR_ADC12EN_Msk                   (0x1U << RCC_AHBENR_ADC12EN_Pos)
#define RCC_AHBENR_ADC12EN                       RCC_AHBENR_ADC12EN_Msk


#define RCC_APB2ENR_SYSCFGEN_Pos                 (0U)
#define RCC_APB2ENR_SYSCFGEN_Msk                 (0x1U << RCC_APB2ENR_SYSCFGEN_Pos)
#define RCC_APB2ENR_SYSCFGEN                     RCC_APB2ENR_SYSCFGEN_Msk
#define RCC_APB2ENR_TIM1EN_Pos                   (11U)
#define RCC_APB2ENR_TIM1EN_Msk                   (0x1U << RCC_APB2ENR_TIM1EN_Pos)
#define RCC_APB2ENR_TIM1EN                       RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_SPI1EN_Pos                   (12U)
#define RCC_APB2ENR_SPI1EN_Msk                   (0x1U << RCC_APB2ENR_SPI1EN_Pos)
#define RCC_APB2ENR_SPI1EN                       RCC_APB2ENR_SPI1EN_Msk
#define RCC_APB2ENR_USART1EN_Pos                 (14U)
#define RCC_APB2ENR_USART1EN_Msk                 (0x1U << RCC_APB2ENR_USART1EN_Pos)
#define RCC_APB2ENR_USART1EN                     RCC_APB2ENR_USART1EN_Msk
#define RCC_APB2ENR_TIM15EN_Pos                  (16U)
#define RCC_APB2ENR_TIM15EN_Msk                  (0x1U << RCC_APB2ENR_TIM15EN_Pos)
#define RCC_APB2ENR_TIM15EN                      RCC_APB2ENR_TIM15EN_Msk
#define RCC_APB2ENR_TIM16EN_Pos                  (17U)
#define RCC_APB2ENR_TIM16EN_Msk                  (0x1U << RCC_APB2ENR_TIM16EN_Pos)
#define RCC_APB2ENR_TIM16EN                      RCC_APB2ENR_TIM16EN_Msk
#define RCC_APB2ENR_TIM17EN_Pos                  (18U)
#define RCC_APB2ENR_TIM17EN_Msk                  (0x1U << RCC_APB2ENR_TIM17EN_Pos)
#define RCC_APB2ENR_TIM17EN                      RCC_APB2ENR_TIM17EN_Msk


#define RCC_APB1ENR_TIM2EN_Pos                   (0U)
#define RCC_APB1ENR_TIM2EN_Msk                   (0x1U << RCC_APB1ENR_TIM2EN_Pos)
#define RCC_APB1ENR_TIM2EN                       RCC_APB1ENR_TIM2EN_Msk
#define RCC_APB1ENR_TIM3EN_Pos                   (1U)
#define RCC_APB1ENR_TIM3EN_Msk                   (0x1U << RCC_APB1ENR_TIM3EN_Pos)
#define RCC_APB1ENR_TIM3EN                       RCC_APB1ENR_TIM3EN_Msk
#define RCC_APB1ENR_TIM6EN_Pos                   (4U)
#define RCC_APB1ENR_TIM6EN_Msk                   (0x1U << RCC_APB1ENR_TIM6EN_Pos)
#define RCC_APB1ENR_TIM6EN                       RCC_APB1ENR_TIM6EN_Msk
#define RCC_APB1ENR_TIM7EN_Pos                   (5U)
#define RCC_APB1ENR_TIM7EN_Msk                   (0x1U << RCC_APB1ENR_TIM7EN_Pos)
#define RCC_APB1ENR_TIM7EN                       RCC_APB1ENR_TIM7EN_Msk
#define RCC_APB1ENR_WWDGEN_Pos                   (11U)
#define RCC_APB1ENR_WWDGEN_Msk                   (0x1U << RCC_APB1ENR_WWDGEN_Pos)
#define RCC_APB1ENR_WWDGEN                       RCC_APB1ENR_WWDGEN_Msk
#define RCC_APB1ENR_USART2EN_Pos                 (17U)
#define RCC_APB1ENR_USART2EN_Msk                 (0x1U << RCC_APB1ENR_USART2EN_Pos)
#define RCC_APB1ENR_USART2EN                     RCC_APB1ENR_USART2EN_Msk
#define RCC_APB1ENR_USART3EN_Pos                 (18U)
#define RCC_APB1ENR_USART3EN_Msk                 (0x1U << RCC_APB1ENR_USART3EN_Pos)
#define RCC_APB1ENR_USART3EN                     RCC_APB1ENR_USART3EN_Msk
#define RCC_APB1ENR_I2C1EN_Pos                   (21U)
#define RCC_APB1ENR_I2C1EN_Msk                   (0x1U << RCC_APB1ENR_I2C1EN_Pos)
#define RCC_APB1ENR_I2C1EN                       RCC_APB1ENR_I2C1EN_Msk
#define RCC_APB1ENR_CANEN_Pos                    (25U)
#define RCC_APB1ENR_CANEN_Msk                    (0x1U << RCC_APB1ENR_CANEN_Pos)
#define RCC_APB1ENR_CANEN                        RCC_APB1ENR_CANEN_Msk
#define RCC_APB1ENR_DAC2EN_Pos                   (26U)
#define RCC_APB1ENR_DAC2EN_Msk                   (0x1U << RCC_APB1ENR_DAC2EN_Pos)
#define RCC_APB1ENR_DAC2EN                       RCC_APB1ENR_DAC2EN_Msk
#define RCC_APB1ENR_PWREN_Pos                    (28U)
#define RCC_APB1ENR_PWREN_Msk                    (0x1U << RCC_APB1ENR_PWREN_Pos)
#define RCC_APB1ENR_PWREN                        RCC_APB1ENR_PWREN_Msk
#define RCC_APB1ENR_DAC1EN_Pos                   (29U)
#define RCC_APB1ENR_DAC1EN_Msk                   (0x1U << RCC_APB1ENR_DAC1EN_Pos)
#define RCC_APB1ENR_DAC1EN                       RCC_APB1ENR_DAC1EN_Msk


#define RCC_BDCR_LSE_Pos                         (0U)
#define RCC_BDCR_LSE_Msk                         (0x7U << RCC_BDCR_LSE_Pos)
#define RCC_BDCR_LSE                             RCC_BDCR_LSE_Msk
#define RCC_BDCR_LSEON_Pos                       (0U)
#define RCC_BDCR_LSEON_Msk                       (0x1U << RCC_BDCR_LSEON_Pos)
#define RCC_BDCR_LSEON                           RCC_BDCR_LSEON_Msk
#define RCC_BDCR_LSERDY_Pos                      (1U)
#define RCC_BDCR_LSERDY_Msk                      (0x1U << RCC_BDCR_LSERDY_Pos)
#define RCC_BDCR_LSERDY                          RCC_BDCR_LSERDY_Msk
#define RCC_BDCR_LSEBYP_Pos                      (2U)
#define RCC_BDCR_LSEBYP_Msk                      (0x1U << RCC_BDCR_LSEBYP_Pos)
#define RCC_BDCR_LSEBYP                          RCC_BDCR_LSEBYP_Msk

#define RCC_BDCR_LSEDRV_Pos                      (3U)
#define RCC_BDCR_LSEDRV_Msk                      (0x3U << RCC_BDCR_LSEDRV_Pos)
#define RCC_BDCR_LSEDRV                          RCC_BDCR_LSEDRV_Msk
#define RCC_BDCR_LSEDRV_0                        (0x1U << RCC_BDCR_LSEDRV_Pos)
#define RCC_BDCR_LSEDRV_1                        (0x2U << RCC_BDCR_LSEDRV_Pos)

#define RCC_BDCR_RTCSEL_Pos                      (8U)
#define RCC_BDCR_RTCSEL_Msk                      (0x3U << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL                          RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0                        (0x1U << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL_1                        (0x2U << RCC_BDCR_RTCSEL_Pos)


#define RCC_BDCR_RTCSEL_NOCLOCK                  (0x00000000U)
#define RCC_BDCR_RTCSEL_LSE                      (0x00000100U)
#define RCC_BDCR_RTCSEL_LSI                      (0x00000200U)
#define RCC_BDCR_RTCSEL_HSE                      (0x00000300U)

#define RCC_BDCR_RTCEN_Pos                       (15U)
#define RCC_BDCR_RTCEN_Msk                       (0x1U << RCC_BDCR_RTCEN_Pos)
#define RCC_BDCR_RTCEN                           RCC_BDCR_RTCEN_Msk
#define RCC_BDCR_BDRST_Pos                       (16U)
#define RCC_BDCR_BDRST_Msk                       (0x1U << RCC_BDCR_BDRST_Pos)
#define RCC_BDCR_BDRST                           RCC_BDCR_BDRST_Msk


#define RCC_CSR_LSION_Pos                        (0U)
#define RCC_CSR_LSION_Msk                        (0x1U << RCC_CSR_LSION_Pos)
#define RCC_CSR_LSION                            RCC_CSR_LSION_Msk
#define RCC_CSR_LSIRDY_Pos                       (1U)
#define RCC_CSR_LSIRDY_Msk                       (0x1U << RCC_CSR_LSIRDY_Pos)
#define RCC_CSR_LSIRDY                           RCC_CSR_LSIRDY_Msk
#define RCC_CSR_V18PWRRSTF_Pos                   (23U)
#define RCC_CSR_V18PWRRSTF_Msk                   (0x1U << RCC_CSR_V18PWRRSTF_Pos)
#define RCC_CSR_V18PWRRSTF                       RCC_CSR_V18PWRRSTF_Msk
#define RCC_CSR_RMVF_Pos                         (24U)
#define RCC_CSR_RMVF_Msk                         (0x1U << RCC_CSR_RMVF_Pos)
#define RCC_CSR_RMVF                             RCC_CSR_RMVF_Msk
#define RCC_CSR_OBLRSTF_Pos                      (25U)
#define RCC_CSR_OBLRSTF_Msk                      (0x1U << RCC_CSR_OBLRSTF_Pos)
#define RCC_CSR_OBLRSTF                          RCC_CSR_OBLRSTF_Msk
#define RCC_CSR_PINRSTF_Pos                      (26U)
#define RCC_CSR_PINRSTF_Msk                      (0x1U << RCC_CSR_PINRSTF_Pos)
#define RCC_CSR_PINRSTF                          RCC_CSR_PINRSTF_Msk
#define RCC_CSR_PORRSTF_Pos                      (27U)
#define RCC_CSR_PORRSTF_Msk                      (0x1U << RCC_CSR_PORRSTF_Pos)
#define RCC_CSR_PORRSTF                          RCC_CSR_PORRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos                      (28U)
#define RCC_CSR_SFTRSTF_Msk                      (0x1U << RCC_CSR_SFTRSTF_Pos)
#define RCC_CSR_SFTRSTF                          RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos                     (29U)
#define RCC_CSR_IWDGRSTF_Msk                     (0x1U << RCC_CSR_IWDGRSTF_Pos)
#define RCC_CSR_IWDGRSTF                         RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos                     (30U)
#define RCC_CSR_WWDGRSTF_Msk                     (0x1U << RCC_CSR_WWDGRSTF_Pos)
#define RCC_CSR_WWDGRSTF                         RCC_CSR_WWDGRSTF_Msk
#define RCC_CSR_LPWRRSTF_Pos                     (31U)
#define RCC_CSR_LPWRRSTF_Msk                     (0x1U << RCC_CSR_LPWRRSTF_Pos)
#define RCC_CSR_LPWRRSTF                         RCC_CSR_LPWRRSTF_Msk


#define RCC_AHBRSTR_GPIOARST_Pos                 (17U)
#define RCC_AHBRSTR_GPIOARST_Msk                 (0x1U << RCC_AHBRSTR_GPIOARST_Pos)
#define RCC_AHBRSTR_GPIOARST                     RCC_AHBRSTR_GPIOARST_Msk
#define RCC_AHBRSTR_GPIOBRST_Pos                 (18U)
#define RCC_AHBRSTR_GPIOBRST_Msk                 (0x1U << RCC_AHBRSTR_GPIOBRST_Pos)
#define RCC_AHBRSTR_GPIOBRST                     RCC_AHBRSTR_GPIOBRST_Msk
#define RCC_AHBRSTR_GPIOCRST_Pos                 (19U)
#define RCC_AHBRSTR_GPIOCRST_Msk                 (0x1U << RCC_AHBRSTR_GPIOCRST_Pos)
#define RCC_AHBRSTR_GPIOCRST                     RCC_AHBRSTR_GPIOCRST_Msk
#define RCC_AHBRSTR_GPIODRST_Pos                 (20U)
#define RCC_AHBRSTR_GPIODRST_Msk                 (0x1U << RCC_AHBRSTR_GPIODRST_Pos)
#define RCC_AHBRSTR_GPIODRST                     RCC_AHBRSTR_GPIODRST_Msk
#define RCC_AHBRSTR_GPIOFRST_Pos                 (22U)
#define RCC_AHBRSTR_GPIOFRST_Msk                 (0x1U << RCC_AHBRSTR_GPIOFRST_Pos)
#define RCC_AHBRSTR_GPIOFRST                     RCC_AHBRSTR_GPIOFRST_Msk
#define RCC_AHBRSTR_TSCRST_Pos                   (24U)
#define RCC_AHBRSTR_TSCRST_Msk                   (0x1U << RCC_AHBRSTR_TSCRST_Pos)
#define RCC_AHBRSTR_TSCRST                       RCC_AHBRSTR_TSCRST_Msk
#define RCC_AHBRSTR_ADC12RST_Pos                 (28U)
#define RCC_AHBRSTR_ADC12RST_Msk                 (0x1U << RCC_AHBRSTR_ADC12RST_Pos)
#define RCC_AHBRSTR_ADC12RST                     RCC_AHBRSTR_ADC12RST_Msk



#define RCC_CFGR2_PREDIV_Pos                     (0U)
#define RCC_CFGR2_PREDIV_Msk                     (0xFU << RCC_CFGR2_PREDIV_Pos)
#define RCC_CFGR2_PREDIV                         RCC_CFGR2_PREDIV_Msk
#define RCC_CFGR2_PREDIV_0                       (0x1U << RCC_CFGR2_PREDIV_Pos)
#define RCC_CFGR2_PREDIV_1                       (0x2U << RCC_CFGR2_PREDIV_Pos)
#define RCC_CFGR2_PREDIV_2                       (0x4U << RCC_CFGR2_PREDIV_Pos)
#define RCC_CFGR2_PREDIV_3                       (0x8U << RCC_CFGR2_PREDIV_Pos)

#define RCC_CFGR2_PREDIV_DIV1                    (0x00000000U)
#define RCC_CFGR2_PREDIV_DIV2                    (0x00000001U)
#define RCC_CFGR2_PREDIV_DIV3                    (0x00000002U)
#define RCC_CFGR2_PREDIV_DIV4                    (0x00000003U)
#define RCC_CFGR2_PREDIV_DIV5                    (0x00000004U)
#define RCC_CFGR2_PREDIV_DIV6                    (0x00000005U)
#define RCC_CFGR2_PREDIV_DIV7                    (0x00000006U)
#define RCC_CFGR2_PREDIV_DIV8                    (0x00000007U)
#define RCC_CFGR2_PREDIV_DIV9                    (0x00000008U)
#define RCC_CFGR2_PREDIV_DIV10                   (0x00000009U)
#define RCC_CFGR2_PREDIV_DIV11                   (0x0000000AU)
#define RCC_CFGR2_PREDIV_DIV12                   (0x0000000BU)
#define RCC_CFGR2_PREDIV_DIV13                   (0x0000000CU)
#define RCC_CFGR2_PREDIV_DIV14                   (0x0000000DU)
#define RCC_CFGR2_PREDIV_DIV15                   (0x0000000EU)
#define RCC_CFGR2_PREDIV_DIV16                   (0x0000000FU)


#define RCC_CFGR2_ADCPRE12_Pos                   (4U)
#define RCC_CFGR2_ADCPRE12_Msk                   (0x1FU << RCC_CFGR2_ADCPRE12_Pos)
#define RCC_CFGR2_ADCPRE12                       RCC_CFGR2_ADCPRE12_Msk
#define RCC_CFGR2_ADCPRE12_0                     (0x01U << RCC_CFGR2_ADCPRE12_Pos)
#define RCC_CFGR2_ADCPRE12_1                     (0x02U << RCC_CFGR2_ADCPRE12_Pos)
#define RCC_CFGR2_ADCPRE12_2                     (0x04U << RCC_CFGR2_ADCPRE12_Pos)
#define RCC_CFGR2_ADCPRE12_3                     (0x08U << RCC_CFGR2_ADCPRE12_Pos)
#define RCC_CFGR2_ADCPRE12_4                     (0x10U << RCC_CFGR2_ADCPRE12_Pos)

#define RCC_CFGR2_ADCPRE12_NO                    (0x00000000U)
#define RCC_CFGR2_ADCPRE12_DIV1                  (0x00000100U)
#define RCC_CFGR2_ADCPRE12_DIV2                  (0x00000110U)
#define RCC_CFGR2_ADCPRE12_DIV4                  (0x00000120U)
#define RCC_CFGR2_ADCPRE12_DIV6                  (0x00000130U)
#define RCC_CFGR2_ADCPRE12_DIV8                  (0x00000140U)
#define RCC_CFGR2_ADCPRE12_DIV10                 (0x00000150U)
#define RCC_CFGR2_ADCPRE12_DIV12                 (0x00000160U)
#define RCC_CFGR2_ADCPRE12_DIV16                 (0x00000170U)
#define RCC_CFGR2_ADCPRE12_DIV32                 (0x00000180U)
#define RCC_CFGR2_ADCPRE12_DIV64                 (0x00000190U)
#define RCC_CFGR2_ADCPRE12_DIV128                (0x000001A0U)
#define RCC_CFGR2_ADCPRE12_DIV256                (0x000001B0U)


#define RCC_CFGR3_USART1SW_Pos                   (0U)
#define RCC_CFGR3_USART1SW_Msk                   (0x3U << RCC_CFGR3_USART1SW_Pos)
#define RCC_CFGR3_USART1SW                       RCC_CFGR3_USART1SW_Msk
#define RCC_CFGR3_USART1SW_0                     (0x1U << RCC_CFGR3_USART1SW_Pos)
#define RCC_CFGR3_USART1SW_1                     (0x2U << RCC_CFGR3_USART1SW_Pos)

#define RCC_CFGR3_USART1SW_PCLK1                 (0x00000000U)
#define RCC_CFGR3_USART1SW_SYSCLK                (0x00000001U)
#define RCC_CFGR3_USART1SW_LSE                   (0x00000002U)
#define RCC_CFGR3_USART1SW_HSI                   (0x00000003U)

#define  RCC_CFGR3_USART1SW_PCLK             RCC_CFGR3_USART1SW_PCLK1

#define RCC_CFGR3_I2CSW_Pos                      (4U)
#define RCC_CFGR3_I2CSW_Msk                      (0x1U << RCC_CFGR3_I2CSW_Pos)
#define RCC_CFGR3_I2CSW                          RCC_CFGR3_I2CSW_Msk
#define RCC_CFGR3_I2C1SW_Pos                     (4U)
#define RCC_CFGR3_I2C1SW_Msk                     (0x1U << RCC_CFGR3_I2C1SW_Pos)
#define RCC_CFGR3_I2C1SW                         RCC_CFGR3_I2C1SW_Msk

#define RCC_CFGR3_I2C1SW_HSI                     (0x00000000U)
#define RCC_CFGR3_I2C1SW_SYSCLK_Pos              (4U)
#define RCC_CFGR3_I2C1SW_SYSCLK_Msk              (0x1U << RCC_CFGR3_I2C1SW_SYSCLK_Pos)
#define RCC_CFGR3_I2C1SW_SYSCLK                  RCC_CFGR3_I2C1SW_SYSCLK_Msk
#define RCC_CFGR3_TIMSW_Pos                      (8U)
#define RCC_CFGR3_TIMSW_Msk                      (0x1U << RCC_CFGR3_TIMSW_Pos)
#define RCC_CFGR3_TIMSW                          RCC_CFGR3_TIMSW_Msk
#define RCC_CFGR3_TIM1SW_Pos                     (8U)
#define RCC_CFGR3_TIM1SW_Msk                     (0x1U << RCC_CFGR3_TIM1SW_Pos)
#define RCC_CFGR3_TIM1SW                         RCC_CFGR3_TIM1SW_Msk
#define RCC_CFGR3_TIM1SW_PCLK2                   (0x00000000U)
#define RCC_CFGR3_TIM1SW_PLL_Pos                 (8U)
#define RCC_CFGR3_TIM1SW_PLL_Msk                 (0x1U << RCC_CFGR3_TIM1SW_PLL_Pos)
#define RCC_CFGR3_TIM1SW_PLL                     RCC_CFGR3_TIM1SW_PLL_Msk


#define  RCC_CFGR3_TIM1SW_HCLK                RCC_CFGR3_TIM1SW_PCLK2









#define RTC_TAMPER1_SUPPORT
#define RTC_TAMPER2_SUPPORT
#define RTC_BACKUP_SUPPORT
#define RTC_WAKEUP_SUPPORT


#define RTC_TR_PM_Pos                (22U)
#define RTC_TR_PM_Msk                (0x1U << RTC_TR_PM_Pos)
#define RTC_TR_PM                    RTC_TR_PM_Msk
#define RTC_TR_HT_Pos                (20U)
#define RTC_TR_HT_Msk                (0x3U << RTC_TR_HT_Pos)
#define RTC_TR_HT                    RTC_TR_HT_Msk
#define RTC_TR_HT_0                  (0x1U << RTC_TR_HT_Pos)
#define RTC_TR_HT_1                  (0x2U << RTC_TR_HT_Pos)
#define RTC_TR_HU_Pos                (16U)
#define RTC_TR_HU_Msk                (0xFU << RTC_TR_HU_Pos)
#define RTC_TR_HU                    RTC_TR_HU_Msk
#define RTC_TR_HU_0                  (0x1U << RTC_TR_HU_Pos)
#define RTC_TR_HU_1                  (0x2U << RTC_TR_HU_Pos)
#define RTC_TR_HU_2                  (0x4U << RTC_TR_HU_Pos)
#define RTC_TR_HU_3                  (0x8U << RTC_TR_HU_Pos)
#define RTC_TR_MNT_Pos               (12U)
#define RTC_TR_MNT_Msk               (0x7U << RTC_TR_MNT_Pos)
#define RTC_TR_MNT                   RTC_TR_MNT_Msk
#define RTC_TR_MNT_0                 (0x1U << RTC_TR_MNT_Pos)
#define RTC_TR_MNT_1                 (0x2U << RTC_TR_MNT_Pos)
#define RTC_TR_MNT_2                 (0x4U << RTC_TR_MNT_Pos)
#define RTC_TR_MNU_Pos               (8U)
#define RTC_TR_MNU_Msk               (0xFU << RTC_TR_MNU_Pos)
#define RTC_TR_MNU                   RTC_TR_MNU_Msk
#define RTC_TR_MNU_0                 (0x1U << RTC_TR_MNU_Pos)
#define RTC_TR_MNU_1                 (0x2U << RTC_TR_MNU_Pos)
#define RTC_TR_MNU_2                 (0x4U << RTC_TR_MNU_Pos)
#define RTC_TR_MNU_3                 (0x8U << RTC_TR_MNU_Pos)
#define RTC_TR_ST_Pos                (4U)
#define RTC_TR_ST_Msk                (0x7U << RTC_TR_ST_Pos)
#define RTC_TR_ST                    RTC_TR_ST_Msk
#define RTC_TR_ST_0                  (0x1U << RTC_TR_ST_Pos)
#define RTC_TR_ST_1                  (0x2U << RTC_TR_ST_Pos)
#define RTC_TR_ST_2                  (0x4U << RTC_TR_ST_Pos)
#define RTC_TR_SU_Pos                (0U)
#define RTC_TR_SU_Msk                (0xFU << RTC_TR_SU_Pos)
#define RTC_TR_SU                    RTC_TR_SU_Msk
#define RTC_TR_SU_0                  (0x1U << RTC_TR_SU_Pos)
#define RTC_TR_SU_1                  (0x2U << RTC_TR_SU_Pos)
#define RTC_TR_SU_2                  (0x4U << RTC_TR_SU_Pos)
#define RTC_TR_SU_3                  (0x8U << RTC_TR_SU_Pos)


#define RTC_DR_YT_Pos                (20U)
#define RTC_DR_YT_Msk                (0xFU << RTC_DR_YT_Pos)
#define RTC_DR_YT                    RTC_DR_YT_Msk
#define RTC_DR_YT_0                  (0x1U << RTC_DR_YT_Pos)
#define RTC_DR_YT_1                  (0x2U << RTC_DR_YT_Pos)
#define RTC_DR_YT_2                  (0x4U << RTC_DR_YT_Pos)
#define RTC_DR_YT_3                  (0x8U << RTC_DR_YT_Pos)
#define RTC_DR_YU_Pos                (16U)
#define RTC_DR_YU_Msk                (0xFU << RTC_DR_YU_Pos)
#define RTC_DR_YU                    RTC_DR_YU_Msk
#define RTC_DR_YU_0                  (0x1U << RTC_DR_YU_Pos)
#define RTC_DR_YU_1                  (0x2U << RTC_DR_YU_Pos)
#define RTC_DR_YU_2                  (0x4U << RTC_DR_YU_Pos)
#define RTC_DR_YU_3                  (0x8U << RTC_DR_YU_Pos)
#define RTC_DR_WDU_Pos               (13U)
#define RTC_DR_WDU_Msk               (0x7U << RTC_DR_WDU_Pos)
#define RTC_DR_WDU                   RTC_DR_WDU_Msk
#define RTC_DR_WDU_0                 (0x1U << RTC_DR_WDU_Pos)
#define RTC_DR_WDU_1                 (0x2U << RTC_DR_WDU_Pos)
#define RTC_DR_WDU_2                 (0x4U << RTC_DR_WDU_Pos)
#define RTC_DR_MT_Pos                (12U)
#define RTC_DR_MT_Msk                (0x1U << RTC_DR_MT_Pos)
#define RTC_DR_MT                    RTC_DR_MT_Msk
#define RTC_DR_MU_Pos                (8U)
#define RTC_DR_MU_Msk                (0xFU << RTC_DR_MU_Pos)
#define RTC_DR_MU                    RTC_DR_MU_Msk
#define RTC_DR_MU_0                  (0x1U << RTC_DR_MU_Pos)
#define RTC_DR_MU_1                  (0x2U << RTC_DR_MU_Pos)
#define RTC_DR_MU_2                  (0x4U << RTC_DR_MU_Pos)
#define RTC_DR_MU_3                  (0x8U << RTC_DR_MU_Pos)
#define RTC_DR_DT_Pos                (4U)
#define RTC_DR_DT_Msk                (0x3U << RTC_DR_DT_Pos)
#define RTC_DR_DT                    RTC_DR_DT_Msk
#define RTC_DR_DT_0                  (0x1U << RTC_DR_DT_Pos)
#define RTC_DR_DT_1                  (0x2U << RTC_DR_DT_Pos)
#define RTC_DR_DU_Pos                (0U)
#define RTC_DR_DU_Msk                (0xFU << RTC_DR_DU_Pos)
#define RTC_DR_DU                    RTC_DR_DU_Msk
#define RTC_DR_DU_0                  (0x1U << RTC_DR_DU_Pos)
#define RTC_DR_DU_1                  (0x2U << RTC_DR_DU_Pos)
#define RTC_DR_DU_2                  (0x4U << RTC_DR_DU_Pos)
#define RTC_DR_DU_3                  (0x8U << RTC_DR_DU_Pos)


#define RTC_CR_COE_Pos               (23U)
#define RTC_CR_COE_Msk               (0x1U << RTC_CR_COE_Pos)
#define RTC_CR_COE                   RTC_CR_COE_Msk
#define RTC_CR_OSEL_Pos              (21U)
#define RTC_CR_OSEL_Msk              (0x3U << RTC_CR_OSEL_Pos)
#define RTC_CR_OSEL                  RTC_CR_OSEL_Msk
#define RTC_CR_OSEL_0                (0x1U << RTC_CR_OSEL_Pos)
#define RTC_CR_OSEL_1                (0x2U << RTC_CR_OSEL_Pos)
#define RTC_CR_POL_Pos               (20U)
#define RTC_CR_POL_Msk               (0x1U << RTC_CR_POL_Pos)
#define RTC_CR_POL                   RTC_CR_POL_Msk
#define RTC_CR_COSEL_Pos             (19U)
#define RTC_CR_COSEL_Msk             (0x1U << RTC_CR_COSEL_Pos)
#define RTC_CR_COSEL                 RTC_CR_COSEL_Msk
#define RTC_CR_BKP_Pos               (18U)
#define RTC_CR_BKP_Msk               (0x1U << RTC_CR_BKP_Pos)
#define RTC_CR_BKP                   RTC_CR_BKP_Msk
#define RTC_CR_SUB1H_Pos             (17U)
#define RTC_CR_SUB1H_Msk             (0x1U << RTC_CR_SUB1H_Pos)
#define RTC_CR_SUB1H                 RTC_CR_SUB1H_Msk
#define RTC_CR_ADD1H_Pos             (16U)
#define RTC_CR_ADD1H_Msk             (0x1U << RTC_CR_ADD1H_Pos)
#define RTC_CR_ADD1H                 RTC_CR_ADD1H_Msk
#define RTC_CR_TSIE_Pos              (15U)
#define RTC_CR_TSIE_Msk              (0x1U << RTC_CR_TSIE_Pos)
#define RTC_CR_TSIE                  RTC_CR_TSIE_Msk
#define RTC_CR_WUTIE_Pos             (14U)
#define RTC_CR_WUTIE_Msk             (0x1U << RTC_CR_WUTIE_Pos)
#define RTC_CR_WUTIE                 RTC_CR_WUTIE_Msk
#define RTC_CR_ALRBIE_Pos            (13U)
#define RTC_CR_ALRBIE_Msk            (0x1U << RTC_CR_ALRBIE_Pos)
#define RTC_CR_ALRBIE                RTC_CR_ALRBIE_Msk
#define RTC_CR_ALRAIE_Pos            (12U)
#define RTC_CR_ALRAIE_Msk            (0x1U << RTC_CR_ALRAIE_Pos)
#define RTC_CR_ALRAIE                RTC_CR_ALRAIE_Msk
#define RTC_CR_TSE_Pos               (11U)
#define RTC_CR_TSE_Msk               (0x1U << RTC_CR_TSE_Pos)
#define RTC_CR_TSE                   RTC_CR_TSE_Msk
#define RTC_CR_WUTE_Pos              (10U)
#define RTC_CR_WUTE_Msk              (0x1U << RTC_CR_WUTE_Pos)
#define RTC_CR_WUTE                  RTC_CR_WUTE_Msk
#define RTC_CR_ALRBE_Pos             (9U)
#define RTC_CR_ALRBE_Msk             (0x1U << RTC_CR_ALRBE_Pos)
#define RTC_CR_ALRBE                 RTC_CR_ALRBE_Msk
#define RTC_CR_ALRAE_Pos             (8U)
#define RTC_CR_ALRAE_Msk             (0x1U << RTC_CR_ALRAE_Pos)
#define RTC_CR_ALRAE                 RTC_CR_ALRAE_Msk
#define RTC_CR_FMT_Pos               (6U)
#define RTC_CR_FMT_Msk               (0x1U << RTC_CR_FMT_Pos)
#define RTC_CR_FMT                   RTC_CR_FMT_Msk
#define RTC_CR_BYPSHAD_Pos           (5U)
#define RTC_CR_BYPSHAD_Msk           (0x1U << RTC_CR_BYPSHAD_Pos)
#define RTC_CR_BYPSHAD               RTC_CR_BYPSHAD_Msk
#define RTC_CR_REFCKON_Pos           (4U)
#define RTC_CR_REFCKON_Msk           (0x1U << RTC_CR_REFCKON_Pos)
#define RTC_CR_REFCKON               RTC_CR_REFCKON_Msk
#define RTC_CR_TSEDGE_Pos            (3U)
#define RTC_CR_TSEDGE_Msk            (0x1U << RTC_CR_TSEDGE_Pos)
#define RTC_CR_TSEDGE                RTC_CR_TSEDGE_Msk
#define RTC_CR_WUCKSEL_Pos           (0U)
#define RTC_CR_WUCKSEL_Msk           (0x7U << RTC_CR_WUCKSEL_Pos)
#define RTC_CR_WUCKSEL               RTC_CR_WUCKSEL_Msk
#define RTC_CR_WUCKSEL_0             (0x1U << RTC_CR_WUCKSEL_Pos)
#define RTC_CR_WUCKSEL_1             (0x2U << RTC_CR_WUCKSEL_Pos)
#define RTC_CR_WUCKSEL_2             (0x4U << RTC_CR_WUCKSEL_Pos)


#define RTC_CR_BCK_Pos               RTC_CR_BKP_Pos
#define RTC_CR_BCK_Msk               RTC_CR_BKP_Msk
#define RTC_CR_BCK                   RTC_CR_BKP


#define RTC_ISR_RECALPF_Pos          (16U)
#define RTC_ISR_RECALPF_Msk          (0x1U << RTC_ISR_RECALPF_Pos)
#define RTC_ISR_RECALPF              RTC_ISR_RECALPF_Msk
#define RTC_ISR_TAMP2F_Pos           (14U)
#define RTC_ISR_TAMP2F_Msk           (0x1U << RTC_ISR_TAMP2F_Pos)
#define RTC_ISR_TAMP2F               RTC_ISR_TAMP2F_Msk
#define RTC_ISR_TAMP1F_Pos           (13U)
#define RTC_ISR_TAMP1F_Msk           (0x1U << RTC_ISR_TAMP1F_Pos)
#define RTC_ISR_TAMP1F               RTC_ISR_TAMP1F_Msk
#define RTC_ISR_TSOVF_Pos            (12U)
#define RTC_ISR_TSOVF_Msk            (0x1U << RTC_ISR_TSOVF_Pos)
#define RTC_ISR_TSOVF                RTC_ISR_TSOVF_Msk
#define RTC_ISR_TSF_Pos              (11U)
#define RTC_ISR_TSF_Msk              (0x1U << RTC_ISR_TSF_Pos)
#define RTC_ISR_TSF                  RTC_ISR_TSF_Msk
#define RTC_ISR_WUTF_Pos             (10U)
#define RTC_ISR_WUTF_Msk             (0x1U << RTC_ISR_WUTF_Pos)
#define RTC_ISR_WUTF                 RTC_ISR_WUTF_Msk
#define RTC_ISR_ALRBF_Pos            (9U)
#define RTC_ISR_ALRBF_Msk            (0x1U << RTC_ISR_ALRBF_Pos)
#define RTC_ISR_ALRBF                RTC_ISR_ALRBF_Msk
#define RTC_ISR_ALRAF_Pos            (8U)
#define RTC_ISR_ALRAF_Msk            (0x1U << RTC_ISR_ALRAF_Pos)
#define RTC_ISR_ALRAF                RTC_ISR_ALRAF_Msk
#define RTC_ISR_INIT_Pos             (7U)
#define RTC_ISR_INIT_Msk             (0x1U << RTC_ISR_INIT_Pos)
#define RTC_ISR_INIT                 RTC_ISR_INIT_Msk
#define RTC_ISR_INITF_Pos            (6U)
#define RTC_ISR_INITF_Msk            (0x1U << RTC_ISR_INITF_Pos)
#define RTC_ISR_INITF                RTC_ISR_INITF_Msk
#define RTC_ISR_RSF_Pos              (5U)
#define RTC_ISR_RSF_Msk              (0x1U << RTC_ISR_RSF_Pos)
#define RTC_ISR_RSF                  RTC_ISR_RSF_Msk
#define RTC_ISR_INITS_Pos            (4U)
#define RTC_ISR_INITS_Msk            (0x1U << RTC_ISR_INITS_Pos)
#define RTC_ISR_INITS                RTC_ISR_INITS_Msk
#define RTC_ISR_SHPF_Pos             (3U)
#define RTC_ISR_SHPF_Msk             (0x1U << RTC_ISR_SHPF_Pos)
#define RTC_ISR_SHPF                 RTC_ISR_SHPF_Msk
#define RTC_ISR_WUTWF_Pos            (2U)
#define RTC_ISR_WUTWF_Msk            (0x1U << RTC_ISR_WUTWF_Pos)
#define RTC_ISR_WUTWF                RTC_ISR_WUTWF_Msk
#define RTC_ISR_ALRBWF_Pos           (1U)
#define RTC_ISR_ALRBWF_Msk           (0x1U << RTC_ISR_ALRBWF_Pos)
#define RTC_ISR_ALRBWF               RTC_ISR_ALRBWF_Msk
#define RTC_ISR_ALRAWF_Pos           (0U)
#define RTC_ISR_ALRAWF_Msk           (0x1U << RTC_ISR_ALRAWF_Pos)
#define RTC_ISR_ALRAWF               RTC_ISR_ALRAWF_Msk


#define RTC_PRER_PREDIV_A_Pos        (16U)
#define RTC_PRER_PREDIV_A_Msk        (0x7FU << RTC_PRER_PREDIV_A_Pos)
#define RTC_PRER_PREDIV_A            RTC_PRER_PREDIV_A_Msk
#define RTC_PRER_PREDIV_S_Pos        (0U)
#define RTC_PRER_PREDIV_S_Msk        (0x7FFFU << RTC_PRER_PREDIV_S_Pos)
#define RTC_PRER_PREDIV_S            RTC_PRER_PREDIV_S_Msk


#define RTC_WUTR_WUT_Pos             (0U)
#define RTC_WUTR_WUT_Msk             (0xFFFFU << RTC_WUTR_WUT_Pos)
#define RTC_WUTR_WUT                 RTC_WUTR_WUT_Msk


#define RTC_ALRMAR_MSK4_Pos          (31U)
#define RTC_ALRMAR_MSK4_Msk          (0x1U << RTC_ALRMAR_MSK4_Pos)
#define RTC_ALRMAR_MSK4              RTC_ALRMAR_MSK4_Msk
#define RTC_ALRMAR_WDSEL_Pos         (30U)
#define RTC_ALRMAR_WDSEL_Msk         (0x1U << RTC_ALRMAR_WDSEL_Pos)
#define RTC_ALRMAR_WDSEL             RTC_ALRMAR_WDSEL_Msk
#define RTC_ALRMAR_DT_Pos            (28U)
#define RTC_ALRMAR_DT_Msk            (0x3U << RTC_ALRMAR_DT_Pos)
#define RTC_ALRMAR_DT                RTC_ALRMAR_DT_Msk
#define RTC_ALRMAR_DT_0              (0x1U << RTC_ALRMAR_DT_Pos)
#define RTC_ALRMAR_DT_1              (0x2U << RTC_ALRMAR_DT_Pos)
#define RTC_ALRMAR_DU_Pos            (24U)
#define RTC_ALRMAR_DU_Msk            (0xFU << RTC_ALRMAR_DU_Pos)
#define RTC_ALRMAR_DU                RTC_ALRMAR_DU_Msk
#define RTC_ALRMAR_DU_0              (0x1U << RTC_ALRMAR_DU_Pos)
#define RTC_ALRMAR_DU_1              (0x2U << RTC_ALRMAR_DU_Pos)
#define RTC_ALRMAR_DU_2              (0x4U << RTC_ALRMAR_DU_Pos)
#define RTC_ALRMAR_DU_3              (0x8U << RTC_ALRMAR_DU_Pos)
#define RTC_ALRMAR_MSK3_Pos          (23U)
#define RTC_ALRMAR_MSK3_Msk          (0x1U << RTC_ALRMAR_MSK3_Pos)
#define RTC_ALRMAR_MSK3              RTC_ALRMAR_MSK3_Msk
#define RTC_ALRMAR_PM_Pos            (22U)
#define RTC_ALRMAR_PM_Msk            (0x1U << RTC_ALRMAR_PM_Pos)
#define RTC_ALRMAR_PM                RTC_ALRMAR_PM_Msk
#define RTC_ALRMAR_HT_Pos            (20U)
#define RTC_ALRMAR_HT_Msk            (0x3U << RTC_ALRMAR_HT_Pos)
#define RTC_ALRMAR_HT                RTC_ALRMAR_HT_Msk
#define RTC_ALRMAR_HT_0              (0x1U << RTC_ALRMAR_HT_Pos)
#define RTC_ALRMAR_HT_1              (0x2U << RTC_ALRMAR_HT_Pos)
#define RTC_ALRMAR_HU_Pos            (16U)
#define RTC_ALRMAR_HU_Msk            (0xFU << RTC_ALRMAR_HU_Pos)
#define RTC_ALRMAR_HU                RTC_ALRMAR_HU_Msk
#define RTC_ALRMAR_HU_0              (0x1U << RTC_ALRMAR_HU_Pos)
#define RTC_ALRMAR_HU_1              (0x2U << RTC_ALRMAR_HU_Pos)
#define RTC_ALRMAR_HU_2              (0x4U << RTC_ALRMAR_HU_Pos)
#define RTC_ALRMAR_HU_3              (0x8U << RTC_ALRMAR_HU_Pos)
#define RTC_ALRMAR_MSK2_Pos          (15U)
#define RTC_ALRMAR_MSK2_Msk          (0x1U << RTC_ALRMAR_MSK2_Pos)
#define RTC_ALRMAR_MSK2              RTC_ALRMAR_MSK2_Msk
#define RTC_ALRMAR_MNT_Pos           (12U)
#define RTC_ALRMAR_MNT_Msk           (0x7U << RTC_ALRMAR_MNT_Pos)
#define RTC_ALRMAR_MNT               RTC_ALRMAR_MNT_Msk
#define RTC_ALRMAR_MNT_0             (0x1U << RTC_ALRMAR_MNT_Pos)
#define RTC_ALRMAR_MNT_1             (0x2U << RTC_ALRMAR_MNT_Pos)
#define RTC_ALRMAR_MNT_2             (0x4U << RTC_ALRMAR_MNT_Pos)
#define RTC_ALRMAR_MNU_Pos           (8U)
#define RTC_ALRMAR_MNU_Msk           (0xFU << RTC_ALRMAR_MNU_Pos)
#define RTC_ALRMAR_MNU               RTC_ALRMAR_MNU_Msk
#define RTC_ALRMAR_MNU_0             (0x1U << RTC_ALRMAR_MNU_Pos)
#define RTC_ALRMAR_MNU_1             (0x2U << RTC_ALRMAR_MNU_Pos)
#define RTC_ALRMAR_MNU_2             (0x4U << RTC_ALRMAR_MNU_Pos)
#define RTC_ALRMAR_MNU_3             (0x8U << RTC_ALRMAR_MNU_Pos)
#define RTC_ALRMAR_MSK1_Pos          (7U)
#define RTC_ALRMAR_MSK1_Msk          (0x1U << RTC_ALRMAR_MSK1_Pos)
#define RTC_ALRMAR_MSK1              RTC_ALRMAR_MSK1_Msk
#define RTC_ALRMAR_ST_Pos            (4U)
#define RTC_ALRMAR_ST_Msk            (0x7U << RTC_ALRMAR_ST_Pos)
#define RTC_ALRMAR_ST                RTC_ALRMAR_ST_Msk
#define RTC_ALRMAR_ST_0              (0x1U << RTC_ALRMAR_ST_Pos)
#define RTC_ALRMAR_ST_1              (0x2U << RTC_ALRMAR_ST_Pos)
#define RTC_ALRMAR_ST_2              (0x4U << RTC_ALRMAR_ST_Pos)
#define RTC_ALRMAR_SU_Pos            (0U)
#define RTC_ALRMAR_SU_Msk            (0xFU << RTC_ALRMAR_SU_Pos)
#define RTC_ALRMAR_SU                RTC_ALRMAR_SU_Msk
#define RTC_ALRMAR_SU_0              (0x1U << RTC_ALRMAR_SU_Pos)
#define RTC_ALRMAR_SU_1              (0x2U << RTC_ALRMAR_SU_Pos)
#define RTC_ALRMAR_SU_2              (0x4U << RTC_ALRMAR_SU_Pos)
#define RTC_ALRMAR_SU_3              (0x8U << RTC_ALRMAR_SU_Pos)


#define RTC_ALRMBR_MSK4_Pos          (31U)
#define RTC_ALRMBR_MSK4_Msk          (0x1U << RTC_ALRMBR_MSK4_Pos)
#define RTC_ALRMBR_MSK4              RTC_ALRMBR_MSK4_Msk
#define RTC_ALRMBR_WDSEL_Pos         (30U)
#define RTC_ALRMBR_WDSEL_Msk         (0x1U << RTC_ALRMBR_WDSEL_Pos)
#define RTC_ALRMBR_WDSEL             RTC_ALRMBR_WDSEL_Msk
#define RTC_ALRMBR_DT_Pos            (28U)
#define RTC_ALRMBR_DT_Msk            (0x3U << RTC_ALRMBR_DT_Pos)
#define RTC_ALRMBR_DT                RTC_ALRMBR_DT_Msk
#define RTC_ALRMBR_DT_0              (0x1U << RTC_ALRMBR_DT_Pos)
#define RTC_ALRMBR_DT_1              (0x2U << RTC_ALRMBR_DT_Pos)
#define RTC_ALRMBR_DU_Pos            (24U)
#define RTC_ALRMBR_DU_Msk            (0xFU << RTC_ALRMBR_DU_Pos)
#define RTC_ALRMBR_DU                RTC_ALRMBR_DU_Msk
#define RTC_ALRMBR_DU_0              (0x1U << RTC_ALRMBR_DU_Pos)
#define RTC_ALRMBR_DU_1              (0x2U << RTC_ALRMBR_DU_Pos)
#define RTC_ALRMBR_DU_2              (0x4U << RTC_ALRMBR_DU_Pos)
#define RTC_ALRMBR_DU_3              (0x8U << RTC_ALRMBR_DU_Pos)
#define RTC_ALRMBR_MSK3_Pos          (23U)
#define RTC_ALRMBR_MSK3_Msk          (0x1U << RTC_ALRMBR_MSK3_Pos)
#define RTC_ALRMBR_MSK3              RTC_ALRMBR_MSK3_Msk
#define RTC_ALRMBR_PM_Pos            (22U)
#define RTC_ALRMBR_PM_Msk            (0x1U << RTC_ALRMBR_PM_Pos)
#define RTC_ALRMBR_PM                RTC_ALRMBR_PM_Msk
#define RTC_ALRMBR_HT_Pos            (20U)
#define RTC_ALRMBR_HT_Msk            (0x3U << RTC_ALRMBR_HT_Pos)
#define RTC_ALRMBR_HT                RTC_ALRMBR_HT_Msk
#define RTC_ALRMBR_HT_0              (0x1U << RTC_ALRMBR_HT_Pos)
#define RTC_ALRMBR_HT_1              (0x2U << RTC_ALRMBR_HT_Pos)
#define RTC_ALRMBR_HU_Pos            (16U)
#define RTC_ALRMBR_HU_Msk            (0xFU << RTC_ALRMBR_HU_Pos)
#define RTC_ALRMBR_HU                RTC_ALRMBR_HU_Msk
#define RTC_ALRMBR_HU_0              (0x1U << RTC_ALRMBR_HU_Pos)
#define RTC_ALRMBR_HU_1              (0x2U << RTC_ALRMBR_HU_Pos)
#define RTC_ALRMBR_HU_2              (0x4U << RTC_ALRMBR_HU_Pos)
#define RTC_ALRMBR_HU_3              (0x8U << RTC_ALRMBR_HU_Pos)
#define RTC_ALRMBR_MSK2_Pos          (15U)
#define RTC_ALRMBR_MSK2_Msk          (0x1U << RTC_ALRMBR_MSK2_Pos)
#define RTC_ALRMBR_MSK2              RTC_ALRMBR_MSK2_Msk
#define RTC_ALRMBR_MNT_Pos           (12U)
#define RTC_ALRMBR_MNT_Msk           (0x7U << RTC_ALRMBR_MNT_Pos)
#define RTC_ALRMBR_MNT               RTC_ALRMBR_MNT_Msk
#define RTC_ALRMBR_MNT_0             (0x1U << RTC_ALRMBR_MNT_Pos)
#define RTC_ALRMBR_MNT_1             (0x2U << RTC_ALRMBR_MNT_Pos)
#define RTC_ALRMBR_MNT_2             (0x4U << RTC_ALRMBR_MNT_Pos)
#define RTC_ALRMBR_MNU_Pos           (8U)
#define RTC_ALRMBR_MNU_Msk           (0xFU << RTC_ALRMBR_MNU_Pos)
#define RTC_ALRMBR_MNU               RTC_ALRMBR_MNU_Msk
#define RTC_ALRMBR_MNU_0             (0x1U << RTC_ALRMBR_MNU_Pos)
#define RTC_ALRMBR_MNU_1             (0x2U << RTC_ALRMBR_MNU_Pos)
#define RTC_ALRMBR_MNU_2             (0x4U << RTC_ALRMBR_MNU_Pos)
#define RTC_ALRMBR_MNU_3             (0x8U << RTC_ALRMBR_MNU_Pos)
#define RTC_ALRMBR_MSK1_Pos          (7U)
#define RTC_ALRMBR_MSK1_Msk          (0x1U << RTC_ALRMBR_MSK1_Pos)
#define RTC_ALRMBR_MSK1              RTC_ALRMBR_MSK1_Msk
#define RTC_ALRMBR_ST_Pos            (4U)
#define RTC_ALRMBR_ST_Msk            (0x7U << RTC_ALRMBR_ST_Pos)
#define RTC_ALRMBR_ST                RTC_ALRMBR_ST_Msk
#define RTC_ALRMBR_ST_0              (0x1U << RTC_ALRMBR_ST_Pos)
#define RTC_ALRMBR_ST_1              (0x2U << RTC_ALRMBR_ST_Pos)
#define RTC_ALRMBR_ST_2              (0x4U << RTC_ALRMBR_ST_Pos)
#define RTC_ALRMBR_SU_Pos            (0U)
#define RTC_ALRMBR_SU_Msk            (0xFU << RTC_ALRMBR_SU_Pos)
#define RTC_ALRMBR_SU                RTC_ALRMBR_SU_Msk
#define RTC_ALRMBR_SU_0              (0x1U << RTC_ALRMBR_SU_Pos)
#define RTC_ALRMBR_SU_1              (0x2U << RTC_ALRMBR_SU_Pos)
#define RTC_ALRMBR_SU_2              (0x4U << RTC_ALRMBR_SU_Pos)
#define RTC_ALRMBR_SU_3              (0x8U << RTC_ALRMBR_SU_Pos)


#define RTC_WPR_KEY_Pos              (0U)
#define RTC_WPR_KEY_Msk              (0xFFU << RTC_WPR_KEY_Pos)
#define RTC_WPR_KEY                  RTC_WPR_KEY_Msk


#define RTC_SSR_SS_Pos               (0U)
#define RTC_SSR_SS_Msk               (0xFFFFU << RTC_SSR_SS_Pos)
#define RTC_SSR_SS                   RTC_SSR_SS_Msk


#define RTC_SHIFTR_SUBFS_Pos         (0U)
#define RTC_SHIFTR_SUBFS_Msk         (0x7FFFU << RTC_SHIFTR_SUBFS_Pos)
#define RTC_SHIFTR_SUBFS             RTC_SHIFTR_SUBFS_Msk
#define RTC_SHIFTR_ADD1S_Pos         (31U)
#define RTC_SHIFTR_ADD1S_Msk         (0x1U << RTC_SHIFTR_ADD1S_Pos)
#define RTC_SHIFTR_ADD1S             RTC_SHIFTR_ADD1S_Msk


#define RTC_TSTR_PM_Pos              (22U)
#define RTC_TSTR_PM_Msk              (0x1U << RTC_TSTR_PM_Pos)
#define RTC_TSTR_PM                  RTC_TSTR_PM_Msk
#define RTC_TSTR_HT_Pos              (20U)
#define RTC_TSTR_HT_Msk              (0x3U << RTC_TSTR_HT_Pos)
#define RTC_TSTR_HT                  RTC_TSTR_HT_Msk
#define RTC_TSTR_HT_0                (0x1U << RTC_TSTR_HT_Pos)
#define RTC_TSTR_HT_1                (0x2U << RTC_TSTR_HT_Pos)
#define RTC_TSTR_HU_Pos              (16U)
#define RTC_TSTR_HU_Msk              (0xFU << RTC_TSTR_HU_Pos)
#define RTC_TSTR_HU                  RTC_TSTR_HU_Msk
#define RTC_TSTR_HU_0                (0x1U << RTC_TSTR_HU_Pos)
#define RTC_TSTR_HU_1                (0x2U << RTC_TSTR_HU_Pos)
#define RTC_TSTR_HU_2                (0x4U << RTC_TSTR_HU_Pos)
#define RTC_TSTR_HU_3                (0x8U << RTC_TSTR_HU_Pos)
#define RTC_TSTR_MNT_Pos             (12U)
#define RTC_TSTR_MNT_Msk             (0x7U << RTC_TSTR_MNT_Pos)
#define RTC_TSTR_MNT                 RTC_TSTR_MNT_Msk
#define RTC_TSTR_MNT_0               (0x1U << RTC_TSTR_MNT_Pos)
#define RTC_TSTR_MNT_1               (0x2U << RTC_TSTR_MNT_Pos)
#define RTC_TSTR_MNT_2               (0x4U << RTC_TSTR_MNT_Pos)
#define RTC_TSTR_MNU_Pos             (8U)
#define RTC_TSTR_MNU_Msk             (0xFU << RTC_TSTR_MNU_Pos)
#define RTC_TSTR_MNU                 RTC_TSTR_MNU_Msk
#define RTC_TSTR_MNU_0               (0x1U << RTC_TSTR_MNU_Pos)
#define RTC_TSTR_MNU_1               (0x2U << RTC_TSTR_MNU_Pos)
#define RTC_TSTR_MNU_2               (0x4U << RTC_TSTR_MNU_Pos)
#define RTC_TSTR_MNU_3               (0x8U << RTC_TSTR_MNU_Pos)
#define RTC_TSTR_ST_Pos              (4U)
#define RTC_TSTR_ST_Msk              (0x7U << RTC_TSTR_ST_Pos)
#define RTC_TSTR_ST                  RTC_TSTR_ST_Msk
#define RTC_TSTR_ST_0                (0x1U << RTC_TSTR_ST_Pos)
#define RTC_TSTR_ST_1                (0x2U << RTC_TSTR_ST_Pos)
#define RTC_TSTR_ST_2                (0x4U << RTC_TSTR_ST_Pos)
#define RTC_TSTR_SU_Pos              (0U)
#define RTC_TSTR_SU_Msk              (0xFU << RTC_TSTR_SU_Pos)
#define RTC_TSTR_SU                  RTC_TSTR_SU_Msk
#define RTC_TSTR_SU_0                (0x1U << RTC_TSTR_SU_Pos)
#define RTC_TSTR_SU_1                (0x2U << RTC_TSTR_SU_Pos)
#define RTC_TSTR_SU_2                (0x4U << RTC_TSTR_SU_Pos)
#define RTC_TSTR_SU_3                (0x8U << RTC_TSTR_SU_Pos)


#define RTC_TSDR_WDU_Pos             (13U)
#define RTC_TSDR_WDU_Msk             (0x7U << RTC_TSDR_WDU_Pos)
#define RTC_TSDR_WDU                 RTC_TSDR_WDU_Msk
#define RTC_TSDR_WDU_0               (0x1U << RTC_TSDR_WDU_Pos)
#define RTC_TSDR_WDU_1               (0x2U << RTC_TSDR_WDU_Pos)
#define RTC_TSDR_WDU_2               (0x4U << RTC_TSDR_WDU_Pos)
#define RTC_TSDR_MT_Pos              (12U)
#define RTC_TSDR_MT_Msk              (0x1U << RTC_TSDR_MT_Pos)
#define RTC_TSDR_MT                  RTC_TSDR_MT_Msk
#define RTC_TSDR_MU_Pos              (8U)
#define RTC_TSDR_MU_Msk              (0xFU << RTC_TSDR_MU_Pos)
#define RTC_TSDR_MU                  RTC_TSDR_MU_Msk
#define RTC_TSDR_MU_0                (0x1U << RTC_TSDR_MU_Pos)
#define RTC_TSDR_MU_1                (0x2U << RTC_TSDR_MU_Pos)
#define RTC_TSDR_MU_2                (0x4U << RTC_TSDR_MU_Pos)
#define RTC_TSDR_MU_3                (0x8U << RTC_TSDR_MU_Pos)
#define RTC_TSDR_DT_Pos              (4U)
#define RTC_TSDR_DT_Msk              (0x3U << RTC_TSDR_DT_Pos)
#define RTC_TSDR_DT                  RTC_TSDR_DT_Msk
#define RTC_TSDR_DT_0                (0x1U << RTC_TSDR_DT_Pos)
#define RTC_TSDR_DT_1                (0x2U << RTC_TSDR_DT_Pos)
#define RTC_TSDR_DU_Pos              (0U)
#define RTC_TSDR_DU_Msk              (0xFU << RTC_TSDR_DU_Pos)
#define RTC_TSDR_DU                  RTC_TSDR_DU_Msk
#define RTC_TSDR_DU_0                (0x1U << RTC_TSDR_DU_Pos)
#define RTC_TSDR_DU_1                (0x2U << RTC_TSDR_DU_Pos)
#define RTC_TSDR_DU_2                (0x4U << RTC_TSDR_DU_Pos)
#define RTC_TSDR_DU_3                (0x8U << RTC_TSDR_DU_Pos)


#define RTC_TSSSR_SS_Pos             (0U)
#define RTC_TSSSR_SS_Msk             (0xFFFFU << RTC_TSSSR_SS_Pos)
#define RTC_TSSSR_SS                 RTC_TSSSR_SS_Msk


#define RTC_CALR_CALP_Pos            (15U)
#define RTC_CALR_CALP_Msk            (0x1U << RTC_CALR_CALP_Pos)
#define RTC_CALR_CALP                RTC_CALR_CALP_Msk
#define RTC_CALR_CALW8_Pos           (14U)
#define RTC_CALR_CALW8_Msk           (0x1U << RTC_CALR_CALW8_Pos)
#define RTC_CALR_CALW8               RTC_CALR_CALW8_Msk
#define RTC_CALR_CALW16_Pos          (13U)
#define RTC_CALR_CALW16_Msk          (0x1U << RTC_CALR_CALW16_Pos)
#define RTC_CALR_CALW16              RTC_CALR_CALW16_Msk
#define RTC_CALR_CALM_Pos            (0U)
#define RTC_CALR_CALM_Msk            (0x1FFU << RTC_CALR_CALM_Pos)
#define RTC_CALR_CALM                RTC_CALR_CALM_Msk
#define RTC_CALR_CALM_0              (0x001U << RTC_CALR_CALM_Pos)
#define RTC_CALR_CALM_1              (0x002U << RTC_CALR_CALM_Pos)
#define RTC_CALR_CALM_2              (0x004U << RTC_CALR_CALM_Pos)
#define RTC_CALR_CALM_3              (0x008U << RTC_CALR_CALM_Pos)
#define RTC_CALR_CALM_4              (0x010U << RTC_CALR_CALM_Pos)
#define RTC_CALR_CALM_5              (0x020U << RTC_CALR_CALM_Pos)
#define RTC_CALR_CALM_6              (0x040U << RTC_CALR_CALM_Pos)
#define RTC_CALR_CALM_7              (0x080U << RTC_CALR_CALM_Pos)
#define RTC_CALR_CALM_8              (0x100U << RTC_CALR_CALM_Pos)


#define RTC_TAFCR_PC15MODE_Pos       (23U)
#define RTC_TAFCR_PC15MODE_Msk       (0x1U << RTC_TAFCR_PC15MODE_Pos)
#define RTC_TAFCR_PC15MODE           RTC_TAFCR_PC15MODE_Msk
#define RTC_TAFCR_PC15VALUE_Pos      (22U)
#define RTC_TAFCR_PC15VALUE_Msk      (0x1U << RTC_TAFCR_PC15VALUE_Pos)
#define RTC_TAFCR_PC15VALUE          RTC_TAFCR_PC15VALUE_Msk
#define RTC_TAFCR_PC14MODE_Pos       (21U)
#define RTC_TAFCR_PC14MODE_Msk       (0x1U << RTC_TAFCR_PC14MODE_Pos)
#define RTC_TAFCR_PC14MODE           RTC_TAFCR_PC14MODE_Msk
#define RTC_TAFCR_PC14VALUE_Pos      (20U)
#define RTC_TAFCR_PC14VALUE_Msk      (0x1U << RTC_TAFCR_PC14VALUE_Pos)
#define RTC_TAFCR_PC14VALUE          RTC_TAFCR_PC14VALUE_Msk
#define RTC_TAFCR_PC13MODE_Pos       (19U)
#define RTC_TAFCR_PC13MODE_Msk       (0x1U << RTC_TAFCR_PC13MODE_Pos)
#define RTC_TAFCR_PC13MODE           RTC_TAFCR_PC13MODE_Msk
#define RTC_TAFCR_PC13VALUE_Pos      (18U)
#define RTC_TAFCR_PC13VALUE_Msk      (0x1U << RTC_TAFCR_PC13VALUE_Pos)
#define RTC_TAFCR_PC13VALUE          RTC_TAFCR_PC13VALUE_Msk
#define RTC_TAFCR_TAMPPUDIS_Pos      (15U)
#define RTC_TAFCR_TAMPPUDIS_Msk      (0x1U << RTC_TAFCR_TAMPPUDIS_Pos)
#define RTC_TAFCR_TAMPPUDIS          RTC_TAFCR_TAMPPUDIS_Msk
#define RTC_TAFCR_TAMPPRCH_Pos       (13U)
#define RTC_TAFCR_TAMPPRCH_Msk       (0x3U << RTC_TAFCR_TAMPPRCH_Pos)
#define RTC_TAFCR_TAMPPRCH           RTC_TAFCR_TAMPPRCH_Msk
#define RTC_TAFCR_TAMPPRCH_0         (0x1U << RTC_TAFCR_TAMPPRCH_Pos)
#define RTC_TAFCR_TAMPPRCH_1         (0x2U << RTC_TAFCR_TAMPPRCH_Pos)
#define RTC_TAFCR_TAMPFLT_Pos        (11U)
#define RTC_TAFCR_TAMPFLT_Msk        (0x3U << RTC_TAFCR_TAMPFLT_Pos)
#define RTC_TAFCR_TAMPFLT            RTC_TAFCR_TAMPFLT_Msk
#define RTC_TAFCR_TAMPFLT_0          (0x1U << RTC_TAFCR_TAMPFLT_Pos)
#define RTC_TAFCR_TAMPFLT_1          (0x2U << RTC_TAFCR_TAMPFLT_Pos)
#define RTC_TAFCR_TAMPFREQ_Pos       (8U)
#define RTC_TAFCR_TAMPFREQ_Msk       (0x7U << RTC_TAFCR_TAMPFREQ_Pos)
#define RTC_TAFCR_TAMPFREQ           RTC_TAFCR_TAMPFREQ_Msk
#define RTC_TAFCR_TAMPFREQ_0         (0x1U << RTC_TAFCR_TAMPFREQ_Pos)
#define RTC_TAFCR_TAMPFREQ_1         (0x2U << RTC_TAFCR_TAMPFREQ_Pos)
#define RTC_TAFCR_TAMPFREQ_2         (0x4U << RTC_TAFCR_TAMPFREQ_Pos)
#define RTC_TAFCR_TAMPTS_Pos         (7U)
#define RTC_TAFCR_TAMPTS_Msk         (0x1U << RTC_TAFCR_TAMPTS_Pos)
#define RTC_TAFCR_TAMPTS             RTC_TAFCR_TAMPTS_Msk
#define RTC_TAFCR_TAMP2TRG_Pos       (4U)
#define RTC_TAFCR_TAMP2TRG_Msk       (0x1U << RTC_TAFCR_TAMP2TRG_Pos)
#define RTC_TAFCR_TAMP2TRG           RTC_TAFCR_TAMP2TRG_Msk
#define RTC_TAFCR_TAMP2E_Pos         (3U)
#define RTC_TAFCR_TAMP2E_Msk         (0x1U << RTC_TAFCR_TAMP2E_Pos)
#define RTC_TAFCR_TAMP2E             RTC_TAFCR_TAMP2E_Msk
#define RTC_TAFCR_TAMPIE_Pos         (2U)
#define RTC_TAFCR_TAMPIE_Msk         (0x1U << RTC_TAFCR_TAMPIE_Pos)
#define RTC_TAFCR_TAMPIE             RTC_TAFCR_TAMPIE_Msk
#define RTC_TAFCR_TAMP1TRG_Pos       (1U)
#define RTC_TAFCR_TAMP1TRG_Msk       (0x1U << RTC_TAFCR_TAMP1TRG_Pos)
#define RTC_TAFCR_TAMP1TRG           RTC_TAFCR_TAMP1TRG_Msk
#define RTC_TAFCR_TAMP1E_Pos         (0U)
#define RTC_TAFCR_TAMP1E_Msk         (0x1U << RTC_TAFCR_TAMP1E_Pos)
#define RTC_TAFCR_TAMP1E             RTC_TAFCR_TAMP1E_Msk


#define RTC_TAFCR_ALARMOUTTYPE               RTC_TAFCR_PC13VALUE


#define RTC_ALRMASSR_MASKSS_Pos      (24U)
#define RTC_ALRMASSR_MASKSS_Msk      (0xFU << RTC_ALRMASSR_MASKSS_Pos)
#define RTC_ALRMASSR_MASKSS          RTC_ALRMASSR_MASKSS_Msk
#define RTC_ALRMASSR_MASKSS_0        (0x1U << RTC_ALRMASSR_MASKSS_Pos)
#define RTC_ALRMASSR_MASKSS_1        (0x2U << RTC_ALRMASSR_MASKSS_Pos)
#define RTC_ALRMASSR_MASKSS_2        (0x4U << RTC_ALRMASSR_MASKSS_Pos)
#define RTC_ALRMASSR_MASKSS_3        (0x8U << RTC_ALRMASSR_MASKSS_Pos)
#define RTC_ALRMASSR_SS_Pos          (0U)
#define RTC_ALRMASSR_SS_Msk          (0x7FFFU << RTC_ALRMASSR_SS_Pos)
#define RTC_ALRMASSR_SS              RTC_ALRMASSR_SS_Msk


#define RTC_ALRMBSSR_MASKSS_Pos      (24U)
#define RTC_ALRMBSSR_MASKSS_Msk      (0xFU << RTC_ALRMBSSR_MASKSS_Pos)
#define RTC_ALRMBSSR_MASKSS          RTC_ALRMBSSR_MASKSS_Msk
#define RTC_ALRMBSSR_MASKSS_0        (0x1U << RTC_ALRMBSSR_MASKSS_Pos)
#define RTC_ALRMBSSR_MASKSS_1        (0x2U << RTC_ALRMBSSR_MASKSS_Pos)
#define RTC_ALRMBSSR_MASKSS_2        (0x4U << RTC_ALRMBSSR_MASKSS_Pos)
#define RTC_ALRMBSSR_MASKSS_3        (0x8U << RTC_ALRMBSSR_MASKSS_Pos)
#define RTC_ALRMBSSR_SS_Pos          (0U)
#define RTC_ALRMBSSR_SS_Msk          (0x7FFFU << RTC_ALRMBSSR_SS_Pos)
#define RTC_ALRMBSSR_SS              RTC_ALRMBSSR_SS_Msk


#define RTC_BKP0R_Pos                (0U)
#define RTC_BKP0R_Msk                (0xFFFFFFFFU << RTC_BKP0R_Pos)
#define RTC_BKP0R                    RTC_BKP0R_Msk


#define RTC_BKP1R_Pos                (0U)
#define RTC_BKP1R_Msk                (0xFFFFFFFFU << RTC_BKP1R_Pos)
#define RTC_BKP1R                    RTC_BKP1R_Msk


#define RTC_BKP2R_Pos                (0U)
#define RTC_BKP2R_Msk                (0xFFFFFFFFU << RTC_BKP2R_Pos)
#define RTC_BKP2R                    RTC_BKP2R_Msk


#define RTC_BKP3R_Pos                (0U)
#define RTC_BKP3R_Msk                (0xFFFFFFFFU << RTC_BKP3R_Pos)
#define RTC_BKP3R                    RTC_BKP3R_Msk


#define RTC_BKP4R_Pos                (0U)
#define RTC_BKP4R_Msk                (0xFFFFFFFFU << RTC_BKP4R_Pos)
#define RTC_BKP4R                    RTC_BKP4R_Msk


#define RTC_BKP_NUMBER                       5













#define SPI_CR1_CPHA_Pos            (0U)
#define SPI_CR1_CPHA_Msk            (0x1U << SPI_CR1_CPHA_Pos)
#define SPI_CR1_CPHA                SPI_CR1_CPHA_Msk
#define SPI_CR1_CPOL_Pos            (1U)
#define SPI_CR1_CPOL_Msk            (0x1U << SPI_CR1_CPOL_Pos)
#define SPI_CR1_CPOL                SPI_CR1_CPOL_Msk
#define SPI_CR1_MSTR_Pos            (2U)
#define SPI_CR1_MSTR_Msk            (0x1U << SPI_CR1_MSTR_Pos)
#define SPI_CR1_MSTR                SPI_CR1_MSTR_Msk
#define SPI_CR1_BR_Pos              (3U)
#define SPI_CR1_BR_Msk              (0x7U << SPI_CR1_BR_Pos)
#define SPI_CR1_BR                  SPI_CR1_BR_Msk
#define SPI_CR1_BR_0                (0x1U << SPI_CR1_BR_Pos)
#define SPI_CR1_BR_1                (0x2U << SPI_CR1_BR_Pos)
#define SPI_CR1_BR_2                (0x4U << SPI_CR1_BR_Pos)
#define SPI_CR1_SPE_Pos             (6U)
#define SPI_CR1_SPE_Msk             (0x1U << SPI_CR1_SPE_Pos)
#define SPI_CR1_SPE                 SPI_CR1_SPE_Msk
#define SPI_CR1_LSBFIRST_Pos        (7U)
#define SPI_CR1_LSBFIRST_Msk        (0x1U << SPI_CR1_LSBFIRST_Pos)
#define SPI_CR1_LSBFIRST            SPI_CR1_LSBFIRST_Msk
#define SPI_CR1_SSI_Pos             (8U)
#define SPI_CR1_SSI_Msk             (0x1U << SPI_CR1_SSI_Pos)
#define SPI_CR1_SSI                 SPI_CR1_SSI_Msk
#define SPI_CR1_SSM_Pos             (9U)
#define SPI_CR1_SSM_Msk             (0x1U << SPI_CR1_SSM_Pos)
#define SPI_CR1_SSM                 SPI_CR1_SSM_Msk
#define SPI_CR1_RXONLY_Pos          (10U)
#define SPI_CR1_RXONLY_Msk          (0x1U << SPI_CR1_RXONLY_Pos)
#define SPI_CR1_RXONLY              SPI_CR1_RXONLY_Msk
#define SPI_CR1_CRCL_Pos            (11U)
#define SPI_CR1_CRCL_Msk            (0x1U << SPI_CR1_CRCL_Pos)
#define SPI_CR1_CRCL                SPI_CR1_CRCL_Msk
#define SPI_CR1_CRCNEXT_Pos         (12U)
#define SPI_CR1_CRCNEXT_Msk         (0x1U << SPI_CR1_CRCNEXT_Pos)
#define SPI_CR1_CRCNEXT             SPI_CR1_CRCNEXT_Msk
#define SPI_CR1_CRCEN_Pos           (13U)
#define SPI_CR1_CRCEN_Msk           (0x1U << SPI_CR1_CRCEN_Pos)
#define SPI_CR1_CRCEN               SPI_CR1_CRCEN_Msk
#define SPI_CR1_BIDIOE_Pos          (14U)
#define SPI_CR1_BIDIOE_Msk          (0x1U << SPI_CR1_BIDIOE_Pos)
#define SPI_CR1_BIDIOE              SPI_CR1_BIDIOE_Msk
#define SPI_CR1_BIDIMODE_Pos        (15U)
#define SPI_CR1_BIDIMODE_Msk        (0x1U << SPI_CR1_BIDIMODE_Pos)
#define SPI_CR1_BIDIMODE            SPI_CR1_BIDIMODE_Msk


#define SPI_CR2_RXDMAEN_Pos         (0U)
#define SPI_CR2_RXDMAEN_Msk         (0x1U << SPI_CR2_RXDMAEN_Pos)
#define SPI_CR2_RXDMAEN             SPI_CR2_RXDMAEN_Msk
#define SPI_CR2_TXDMAEN_Pos         (1U)
#define SPI_CR2_TXDMAEN_Msk         (0x1U << SPI_CR2_TXDMAEN_Pos)
#define SPI_CR2_TXDMAEN             SPI_CR2_TXDMAEN_Msk
#define SPI_CR2_SSOE_Pos            (2U)
#define SPI_CR2_SSOE_Msk            (0x1U << SPI_CR2_SSOE_Pos)
#define SPI_CR2_SSOE                SPI_CR2_SSOE_Msk
#define SPI_CR2_NSSP_Pos            (3U)
#define SPI_CR2_NSSP_Msk            (0x1U << SPI_CR2_NSSP_Pos)
#define SPI_CR2_NSSP                SPI_CR2_NSSP_Msk
#define SPI_CR2_FRF_Pos             (4U)
#define SPI_CR2_FRF_Msk             (0x1U << SPI_CR2_FRF_Pos)
#define SPI_CR2_FRF                 SPI_CR2_FRF_Msk
#define SPI_CR2_ERRIE_Pos           (5U)
#define SPI_CR2_ERRIE_Msk           (0x1U << SPI_CR2_ERRIE_Pos)
#define SPI_CR2_ERRIE               SPI_CR2_ERRIE_Msk
#define SPI_CR2_RXNEIE_Pos          (6U)
#define SPI_CR2_RXNEIE_Msk          (0x1U << SPI_CR2_RXNEIE_Pos)
#define SPI_CR2_RXNEIE              SPI_CR2_RXNEIE_Msk
#define SPI_CR2_TXEIE_Pos           (7U)
#define SPI_CR2_TXEIE_Msk           (0x1U << SPI_CR2_TXEIE_Pos)
#define SPI_CR2_TXEIE               SPI_CR2_TXEIE_Msk
#define SPI_CR2_DS_Pos              (8U)
#define SPI_CR2_DS_Msk              (0xFU << SPI_CR2_DS_Pos)
#define SPI_CR2_DS                  SPI_CR2_DS_Msk
#define SPI_CR2_DS_0                (0x1U << SPI_CR2_DS_Pos)
#define SPI_CR2_DS_1                (0x2U << SPI_CR2_DS_Pos)
#define SPI_CR2_DS_2                (0x4U << SPI_CR2_DS_Pos)
#define SPI_CR2_DS_3                (0x8U << SPI_CR2_DS_Pos)
#define SPI_CR2_FRXTH_Pos           (12U)
#define SPI_CR2_FRXTH_Msk           (0x1U << SPI_CR2_FRXTH_Pos)
#define SPI_CR2_FRXTH               SPI_CR2_FRXTH_Msk
#define SPI_CR2_LDMARX_Pos          (13U)
#define SPI_CR2_LDMARX_Msk          (0x1U << SPI_CR2_LDMARX_Pos)
#define SPI_CR2_LDMARX              SPI_CR2_LDMARX_Msk
#define SPI_CR2_LDMATX_Pos          (14U)
#define SPI_CR2_LDMATX_Msk          (0x1U << SPI_CR2_LDMATX_Pos)
#define SPI_CR2_LDMATX              SPI_CR2_LDMATX_Msk


#define SPI_SR_RXNE_Pos             (0U)
#define SPI_SR_RXNE_Msk             (0x1U << SPI_SR_RXNE_Pos)
#define SPI_SR_RXNE                 SPI_SR_RXNE_Msk
#define SPI_SR_TXE_Pos              (1U)
#define SPI_SR_TXE_Msk              (0x1U << SPI_SR_TXE_Pos)
#define SPI_SR_TXE                  SPI_SR_TXE_Msk
#define SPI_SR_CRCERR_Pos           (4U)
#define SPI_SR_CRCERR_Msk           (0x1U << SPI_SR_CRCERR_Pos)
#define SPI_SR_CRCERR               SPI_SR_CRCERR_Msk
#define SPI_SR_MODF_Pos             (5U)
#define SPI_SR_MODF_Msk             (0x1U << SPI_SR_MODF_Pos)
#define SPI_SR_MODF                 SPI_SR_MODF_Msk
#define SPI_SR_OVR_Pos              (6U)
#define SPI_SR_OVR_Msk              (0x1U << SPI_SR_OVR_Pos)
#define SPI_SR_OVR                  SPI_SR_OVR_Msk
#define SPI_SR_BSY_Pos              (7U)
#define SPI_SR_BSY_Msk              (0x1U << SPI_SR_BSY_Pos)
#define SPI_SR_BSY                  SPI_SR_BSY_Msk
#define SPI_SR_FRE_Pos              (8U)
#define SPI_SR_FRE_Msk              (0x1U << SPI_SR_FRE_Pos)
#define SPI_SR_FRE                  SPI_SR_FRE_Msk
#define SPI_SR_FRLVL_Pos            (9U)
#define SPI_SR_FRLVL_Msk            (0x3U << SPI_SR_FRLVL_Pos)
#define SPI_SR_FRLVL                SPI_SR_FRLVL_Msk
#define SPI_SR_FRLVL_0              (0x1U << SPI_SR_FRLVL_Pos)
#define SPI_SR_FRLVL_1              (0x2U << SPI_SR_FRLVL_Pos)
#define SPI_SR_FTLVL_Pos            (11U)
#define SPI_SR_FTLVL_Msk            (0x3U << SPI_SR_FTLVL_Pos)
#define SPI_SR_FTLVL                SPI_SR_FTLVL_Msk
#define SPI_SR_FTLVL_0              (0x1U << SPI_SR_FTLVL_Pos)
#define SPI_SR_FTLVL_1              (0x2U << SPI_SR_FTLVL_Pos)


#define SPI_DR_DR_Pos               (0U)
#define SPI_DR_DR_Msk               (0xFFFFU << SPI_DR_DR_Pos)
#define SPI_DR_DR                   SPI_DR_DR_Msk


#define SPI_CRCPR_CRCPOLY_Pos       (0U)
#define SPI_CRCPR_CRCPOLY_Msk       (0xFFFFU << SPI_CRCPR_CRCPOLY_Pos)
#define SPI_CRCPR_CRCPOLY           SPI_CRCPR_CRCPOLY_Msk


#define SPI_RXCRCR_RXCRC_Pos        (0U)
#define SPI_RXCRCR_RXCRC_Msk        (0xFFFFU << SPI_RXCRCR_RXCRC_Pos)
#define SPI_RXCRCR_RXCRC            SPI_RXCRCR_RXCRC_Msk


#define SPI_TXCRCR_TXCRC_Pos        (0U)
#define SPI_TXCRCR_TXCRC_Msk        (0xFFFFU << SPI_TXCRCR_TXCRC_Pos)
#define SPI_TXCRCR_TXCRC            SPI_TXCRCR_TXCRC_Msk







#define SYSCFG_CFGR1_MEM_MODE_Pos                (0U)
#define SYSCFG_CFGR1_MEM_MODE_Msk                (0x3U << SYSCFG_CFGR1_MEM_MODE_Pos)
#define SYSCFG_CFGR1_MEM_MODE                    SYSCFG_CFGR1_MEM_MODE_Msk
#define SYSCFG_CFGR1_MEM_MODE_0                  (0x00000001U)
#define SYSCFG_CFGR1_MEM_MODE_1                  (0x00000002U)
#define SYSCFG_CFGR1_TIM1_ITR3_RMP_Pos           (6U)
#define SYSCFG_CFGR1_TIM1_ITR3_RMP_Msk           (0x1U << SYSCFG_CFGR1_TIM1_ITR3_RMP_Pos)
#define SYSCFG_CFGR1_TIM1_ITR3_RMP               SYSCFG_CFGR1_TIM1_ITR3_RMP_Msk
#define SYSCFG_CFGR1_DAC1_TRIG1_RMP_Pos          (7U)
#define SYSCFG_CFGR1_DAC1_TRIG1_RMP_Msk          (0x1U << SYSCFG_CFGR1_DAC1_TRIG1_RMP_Pos)
#define SYSCFG_CFGR1_DAC1_TRIG1_RMP              SYSCFG_CFGR1_DAC1_TRIG1_RMP_Msk
#define SYSCFG_CFGR1_DMA_RMP_Pos                 (11U)
#define SYSCFG_CFGR1_DMA_RMP_Msk                 (0x1FU << SYSCFG_CFGR1_DMA_RMP_Pos)
#define SYSCFG_CFGR1_DMA_RMP                     SYSCFG_CFGR1_DMA_RMP_Msk
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Pos           (11U)
#define SYSCFG_CFGR1_TIM16_DMA_RMP_Msk           (0x1U << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos)
#define SYSCFG_CFGR1_TIM16_DMA_RMP               SYSCFG_CFGR1_TIM16_DMA_RMP_Msk
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Pos           (12U)
#define SYSCFG_CFGR1_TIM17_DMA_RMP_Msk           (0x1U << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos)
#define SYSCFG_CFGR1_TIM17_DMA_RMP               SYSCFG_CFGR1_TIM17_DMA_RMP_Msk
#define SYSCFG_CFGR1_TIM6DAC1Ch1_DMA_RMP_Pos     (13U)
#define SYSCFG_CFGR1_TIM6DAC1Ch1_DMA_RMP_Msk     (0x1U << SYSCFG_CFGR1_TIM6DAC1Ch1_DMA_RMP_Pos)
#define SYSCFG_CFGR1_TIM6DAC1Ch1_DMA_RMP         SYSCFG_CFGR1_TIM6DAC1Ch1_DMA_RMP_Msk
#define SYSCFG_CFGR1_TIM7DAC1Ch2_DMA_RMP_Pos     (14U)
#define SYSCFG_CFGR1_TIM7DAC1Ch2_DMA_RMP_Msk     (0x1U << SYSCFG_CFGR1_TIM7DAC1Ch2_DMA_RMP_Pos)
#define SYSCFG_CFGR1_TIM7DAC1Ch2_DMA_RMP         SYSCFG_CFGR1_TIM7DAC1Ch2_DMA_RMP_Msk
#define SYSCFG_CFGR1_DAC2Ch1_DMA_RMP_Pos         (15U)
#define SYSCFG_CFGR1_DAC2Ch1_DMA_RMP_Msk         (0x1U << SYSCFG_CFGR1_DAC2Ch1_DMA_RMP_Pos)
#define SYSCFG_CFGR1_DAC2Ch1_DMA_RMP             SYSCFG_CFGR1_DAC2Ch1_DMA_RMP_Msk
#define SYSCFG_CFGR1_I2C_PB6_FMP_Pos             (16U)
#define SYSCFG_CFGR1_I2C_PB6_FMP_Msk             (0x1U << SYSCFG_CFGR1_I2C_PB6_FMP_Pos)
#define SYSCFG_CFGR1_I2C_PB6_FMP                 SYSCFG_CFGR1_I2C_PB6_FMP_Msk
#define SYSCFG_CFGR1_I2C_PB7_FMP_Pos             (17U)
#define SYSCFG_CFGR1_I2C_PB7_FMP_Msk             (0x1U << SYSCFG_CFGR1_I2C_PB7_FMP_Pos)
#define SYSCFG_CFGR1_I2C_PB7_FMP                 SYSCFG_CFGR1_I2C_PB7_FMP_Msk
#define SYSCFG_CFGR1_I2C_PB8_FMP_Pos             (18U)
#define SYSCFG_CFGR1_I2C_PB8_FMP_Msk             (0x1U << SYSCFG_CFGR1_I2C_PB8_FMP_Pos)
#define SYSCFG_CFGR1_I2C_PB8_FMP                 SYSCFG_CFGR1_I2C_PB8_FMP_Msk
#define SYSCFG_CFGR1_I2C_PB9_FMP_Pos             (19U)
#define SYSCFG_CFGR1_I2C_PB9_FMP_Msk             (0x1U << SYSCFG_CFGR1_I2C_PB9_FMP_Pos)
#define SYSCFG_CFGR1_I2C_PB9_FMP                 SYSCFG_CFGR1_I2C_PB9_FMP_Msk
#define SYSCFG_CFGR1_I2C1_FMP_Pos                (20U)
#define SYSCFG_CFGR1_I2C1_FMP_Msk                (0x1U << SYSCFG_CFGR1_I2C1_FMP_Pos)
#define SYSCFG_CFGR1_I2C1_FMP                    SYSCFG_CFGR1_I2C1_FMP_Msk
#define SYSCFG_CFGR1_ENCODER_MODE_Pos            (22U)
#define SYSCFG_CFGR1_ENCODER_MODE_Msk            (0x3U << SYSCFG_CFGR1_ENCODER_MODE_Pos)
#define SYSCFG_CFGR1_ENCODER_MODE                SYSCFG_CFGR1_ENCODER_MODE_Msk
#define SYSCFG_CFGR1_ENCODER_MODE_0              (0x1U << SYSCFG_CFGR1_ENCODER_MODE_Pos)
#define SYSCFG_CFGR1_ENCODER_MODE_1              (0x2U << SYSCFG_CFGR1_ENCODER_MODE_Pos)
#define SYSCFG_CFGR1_ENCODER_MODE_TIM2_Pos       (22U)
#define SYSCFG_CFGR1_ENCODER_MODE_TIM2_Msk       (0x1U << SYSCFG_CFGR1_ENCODER_MODE_TIM2_Pos)
#define SYSCFG_CFGR1_ENCODER_MODE_TIM2           SYSCFG_CFGR1_ENCODER_MODE_TIM2_Msk
#define SYSCFG_CFGR1_ENCODER_MODE_TIM3_Pos       (23U)
#define SYSCFG_CFGR1_ENCODER_MODE_TIM3_Msk       (0x1U << SYSCFG_CFGR1_ENCODER_MODE_TIM3_Pos)
#define SYSCFG_CFGR1_ENCODER_MODE_TIM3           SYSCFG_CFGR1_ENCODER_MODE_TIM3_Msk
#define SYSCFG_CFGR1_FPU_IE_Pos                  (26U)
#define SYSCFG_CFGR1_FPU_IE_Msk                  (0x3FU << SYSCFG_CFGR1_FPU_IE_Pos)
#define SYSCFG_CFGR1_FPU_IE                      SYSCFG_CFGR1_FPU_IE_Msk
#define SYSCFG_CFGR1_FPU_IE_0                    (0x01U << SYSCFG_CFGR1_FPU_IE_Pos)
#define SYSCFG_CFGR1_FPU_IE_1                    (0x02U << SYSCFG_CFGR1_FPU_IE_Pos)
#define SYSCFG_CFGR1_FPU_IE_2                    (0x04U << SYSCFG_CFGR1_FPU_IE_Pos)
#define SYSCFG_CFGR1_FPU_IE_3                    (0x08U << SYSCFG_CFGR1_FPU_IE_Pos)
#define SYSCFG_CFGR1_FPU_IE_4                    (0x10U << SYSCFG_CFGR1_FPU_IE_Pos)
#define SYSCFG_CFGR1_FPU_IE_5                    (0x20U << SYSCFG_CFGR1_FPU_IE_Pos)


#define SYSCFG_RCR_PAGE0_Pos                     (0U)
#define SYSCFG_RCR_PAGE0_Msk                     (0x1U << SYSCFG_RCR_PAGE0_Pos)
#define SYSCFG_RCR_PAGE0                         SYSCFG_RCR_PAGE0_Msk
#define SYSCFG_RCR_PAGE1_Pos                     (1U)
#define SYSCFG_RCR_PAGE1_Msk                     (0x1U << SYSCFG_RCR_PAGE1_Pos)
#define SYSCFG_RCR_PAGE1                         SYSCFG_RCR_PAGE1_Msk
#define SYSCFG_RCR_PAGE2_Pos                     (2U)
#define SYSCFG_RCR_PAGE2_Msk                     (0x1U << SYSCFG_RCR_PAGE2_Pos)
#define SYSCFG_RCR_PAGE2                         SYSCFG_RCR_PAGE2_Msk
#define SYSCFG_RCR_PAGE3_Pos                     (3U)
#define SYSCFG_RCR_PAGE3_Msk                     (0x1U << SYSCFG_RCR_PAGE3_Pos)
#define SYSCFG_RCR_PAGE3                         SYSCFG_RCR_PAGE3_Msk


#define SYSCFG_EXTICR1_EXTI0_Pos                 (0U)
#define SYSCFG_EXTICR1_EXTI0_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI0_Pos)
#define SYSCFG_EXTICR1_EXTI0                     SYSCFG_EXTICR1_EXTI0_Msk
#define SYSCFG_EXTICR1_EXTI1_Pos                 (4U)
#define SYSCFG_EXTICR1_EXTI1_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI1_Pos)
#define SYSCFG_EXTICR1_EXTI1                     SYSCFG_EXTICR1_EXTI1_Msk
#define SYSCFG_EXTICR1_EXTI2_Pos                 (8U)
#define SYSCFG_EXTICR1_EXTI2_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI2_Pos)
#define SYSCFG_EXTICR1_EXTI2                     SYSCFG_EXTICR1_EXTI2_Msk
#define SYSCFG_EXTICR1_EXTI3_Pos                 (12U)
#define SYSCFG_EXTICR1_EXTI3_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI3_Pos)
#define SYSCFG_EXTICR1_EXTI3                     SYSCFG_EXTICR1_EXTI3_Msk




#define SYSCFG_EXTICR1_EXTI0_PA                  (0x00000000U)
#define SYSCFG_EXTICR1_EXTI0_PB                  (0x00000001U)
#define SYSCFG_EXTICR1_EXTI0_PC                  (0x00000002U)
#define SYSCFG_EXTICR1_EXTI0_PD                  (0x00000003U)
#define SYSCFG_EXTICR1_EXTI0_PE                  (0x00000004U)
#define SYSCFG_EXTICR1_EXTI0_PF                  (0x00000005U)




#define SYSCFG_EXTICR1_EXTI1_PA                  (0x00000000U)
#define SYSCFG_EXTICR1_EXTI1_PB                  (0x00000010U)
#define SYSCFG_EXTICR1_EXTI1_PC                  (0x00000020U)
#define SYSCFG_EXTICR1_EXTI1_PD                  (0x00000030U)
#define SYSCFG_EXTICR1_EXTI1_PE                  (0x00000040U)
#define SYSCFG_EXTICR1_EXTI1_PF                  (0x00000050U)




#define SYSCFG_EXTICR1_EXTI2_PA                  (0x00000000U)
#define SYSCFG_EXTICR1_EXTI2_PB                  (0x00000100U)
#define SYSCFG_EXTICR1_EXTI2_PC                  (0x00000200U)
#define SYSCFG_EXTICR1_EXTI2_PD                  (0x00000300U)
#define SYSCFG_EXTICR1_EXTI2_PE                  (0x00000400U)
#define SYSCFG_EXTICR1_EXTI2_PF                  (0x00000500U)




#define SYSCFG_EXTICR1_EXTI3_PA                  (0x00000000U)
#define SYSCFG_EXTICR1_EXTI3_PB                  (0x00001000U)
#define SYSCFG_EXTICR1_EXTI3_PC                  (0x00002000U)
#define SYSCFG_EXTICR1_EXTI3_PD                  (0x00003000U)
#define SYSCFG_EXTICR1_EXTI3_PE                  (0x00004000U)


#define SYSCFG_EXTICR2_EXTI4_Pos                 (0U)
#define SYSCFG_EXTICR2_EXTI4_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI4_Pos)
#define SYSCFG_EXTICR2_EXTI4                     SYSCFG_EXTICR2_EXTI4_Msk
#define SYSCFG_EXTICR2_EXTI5_Pos                 (4U)
#define SYSCFG_EXTICR2_EXTI5_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI5_Pos)
#define SYSCFG_EXTICR2_EXTI5                     SYSCFG_EXTICR2_EXTI5_Msk
#define SYSCFG_EXTICR2_EXTI6_Pos                 (8U)
#define SYSCFG_EXTICR2_EXTI6_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI6_Pos)
#define SYSCFG_EXTICR2_EXTI6                     SYSCFG_EXTICR2_EXTI6_Msk
#define SYSCFG_EXTICR2_EXTI7_Pos                 (12U)
#define SYSCFG_EXTICR2_EXTI7_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI7_Pos)
#define SYSCFG_EXTICR2_EXTI7                     SYSCFG_EXTICR2_EXTI7_Msk




#define SYSCFG_EXTICR2_EXTI4_PA                  (0x00000000U)
#define SYSCFG_EXTICR2_EXTI4_PB                  (0x00000001U)
#define SYSCFG_EXTICR2_EXTI4_PC                  (0x00000002U)
#define SYSCFG_EXTICR2_EXTI4_PD                  (0x00000003U)
#define SYSCFG_EXTICR2_EXTI4_PE                  (0x00000004U)
#define SYSCFG_EXTICR2_EXTI4_PF                  (0x00000005U)




#define SYSCFG_EXTICR2_EXTI5_PA                  (0x00000000U)
#define SYSCFG_EXTICR2_EXTI5_PB                  (0x00000010U)
#define SYSCFG_EXTICR2_EXTI5_PC                  (0x00000020U)
#define SYSCFG_EXTICR2_EXTI5_PD                  (0x00000030U)
#define SYSCFG_EXTICR2_EXTI5_PE                  (0x00000040U)
#define SYSCFG_EXTICR2_EXTI5_PF                  (0x00000050U)




#define SYSCFG_EXTICR2_EXTI6_PA                  (0x00000000U)
#define SYSCFG_EXTICR2_EXTI6_PB                  (0x00000100U)
#define SYSCFG_EXTICR2_EXTI6_PC                  (0x00000200U)
#define SYSCFG_EXTICR2_EXTI6_PD                  (0x00000300U)
#define SYSCFG_EXTICR2_EXTI6_PE                  (0x00000400U)
#define SYSCFG_EXTICR2_EXTI6_PF                  (0x00000500U)




#define SYSCFG_EXTICR2_EXTI7_PA                  (0x00000000U)
#define SYSCFG_EXTICR2_EXTI7_PB                  (0x00001000U)
#define SYSCFG_EXTICR2_EXTI7_PC                  (0x00002000U)
#define SYSCFG_EXTICR2_EXTI7_PD                  (0x00003000U)
#define SYSCFG_EXTICR2_EXTI7_PE                  (0x00004000U)


#define SYSCFG_EXTICR3_EXTI8_Pos                 (0U)
#define SYSCFG_EXTICR3_EXTI8_Msk                 (0xFU << SYSCFG_EXTICR3_EXTI8_Pos)
#define SYSCFG_EXTICR3_EXTI8                     SYSCFG_EXTICR3_EXTI8_Msk
#define SYSCFG_EXTICR3_EXTI9_Pos                 (4U)
#define SYSCFG_EXTICR3_EXTI9_Msk                 (0xFU << SYSCFG_EXTICR3_EXTI9_Pos)
#define SYSCFG_EXTICR3_EXTI9                     SYSCFG_EXTICR3_EXTI9_Msk
#define SYSCFG_EXTICR3_EXTI10_Pos                (8U)
#define SYSCFG_EXTICR3_EXTI10_Msk                (0xFU << SYSCFG_EXTICR3_EXTI10_Pos)
#define SYSCFG_EXTICR3_EXTI10                    SYSCFG_EXTICR3_EXTI10_Msk
#define SYSCFG_EXTICR3_EXTI11_Pos                (12U)
#define SYSCFG_EXTICR3_EXTI11_Msk                (0xFU << SYSCFG_EXTICR3_EXTI11_Pos)
#define SYSCFG_EXTICR3_EXTI11                    SYSCFG_EXTICR3_EXTI11_Msk




#define SYSCFG_EXTICR3_EXTI8_PA                  (0x00000000U)
#define SYSCFG_EXTICR3_EXTI8_PB                  (0x00000001U)
#define SYSCFG_EXTICR3_EXTI8_PC                  (0x00000002U)
#define SYSCFG_EXTICR3_EXTI8_PD                  (0x00000003U)
#define SYSCFG_EXTICR3_EXTI8_PE                  (0x00000004U)




#define SYSCFG_EXTICR3_EXTI9_PA                  (0x00000000U)
#define SYSCFG_EXTICR3_EXTI9_PB                  (0x00000010U)
#define SYSCFG_EXTICR3_EXTI9_PC                  (0x00000020U)
#define SYSCFG_EXTICR3_EXTI9_PD                  (0x00000030U)
#define SYSCFG_EXTICR3_EXTI9_PE                  (0x00000040U)
#define SYSCFG_EXTICR3_EXTI9_PF                  (0x00000050U)




#define SYSCFG_EXTICR3_EXTI10_PA                 (0x00000000U)
#define SYSCFG_EXTICR3_EXTI10_PB                 (0x00000100U)
#define SYSCFG_EXTICR3_EXTI10_PC                 (0x00000200U)
#define SYSCFG_EXTICR3_EXTI10_PD                 (0x00000300U)
#define SYSCFG_EXTICR3_EXTI10_PE                 (0x00000400U)
#define SYSCFG_EXTICR3_EXTI10_PF                 (0x00000500U)




#define SYSCFG_EXTICR3_EXTI11_PA                 (0x00000000U)
#define SYSCFG_EXTICR3_EXTI11_PB                 (0x00001000U)
#define SYSCFG_EXTICR3_EXTI11_PC                 (0x00002000U)
#define SYSCFG_EXTICR3_EXTI11_PD                 (0x00003000U)
#define SYSCFG_EXTICR3_EXTI11_PE                 (0x00004000U)


#define SYSCFG_EXTICR4_EXTI12_Pos                (0U)
#define SYSCFG_EXTICR4_EXTI12_Msk                (0xFU << SYSCFG_EXTICR4_EXTI12_Pos)
#define SYSCFG_EXTICR4_EXTI12                    SYSCFG_EXTICR4_EXTI12_Msk
#define SYSCFG_EXTICR4_EXTI13_Pos                (4U)
#define SYSCFG_EXTICR4_EXTI13_Msk                (0xFU << SYSCFG_EXTICR4_EXTI13_Pos)
#define SYSCFG_EXTICR4_EXTI13                    SYSCFG_EXTICR4_EXTI13_Msk
#define SYSCFG_EXTICR4_EXTI14_Pos                (8U)
#define SYSCFG_EXTICR4_EXTI14_Msk                (0xFU << SYSCFG_EXTICR4_EXTI14_Pos)
#define SYSCFG_EXTICR4_EXTI14                    SYSCFG_EXTICR4_EXTI14_Msk
#define SYSCFG_EXTICR4_EXTI15_Pos                (12U)
#define SYSCFG_EXTICR4_EXTI15_Msk                (0xFU << SYSCFG_EXTICR4_EXTI15_Pos)
#define SYSCFG_EXTICR4_EXTI15                    SYSCFG_EXTICR4_EXTI15_Msk




#define SYSCFG_EXTICR4_EXTI12_PA                 (0x00000000U)
#define SYSCFG_EXTICR4_EXTI12_PB                 (0x00000001U)
#define SYSCFG_EXTICR4_EXTI12_PC                 (0x00000002U)
#define SYSCFG_EXTICR4_EXTI12_PD                 (0x00000003U)
#define SYSCFG_EXTICR4_EXTI12_PE                 (0x00000004U)




#define SYSCFG_EXTICR4_EXTI13_PA                 (0x00000000U)
#define SYSCFG_EXTICR4_EXTI13_PB                 (0x00000010U)
#define SYSCFG_EXTICR4_EXTI13_PC                 (0x00000020U)
#define SYSCFG_EXTICR4_EXTI13_PD                 (0x00000030U)
#define SYSCFG_EXTICR4_EXTI13_PE                 (0x00000040U)




#define SYSCFG_EXTICR4_EXTI14_PA                 (0x00000000U)
#define SYSCFG_EXTICR4_EXTI14_PB                 (0x00000100U)
#define SYSCFG_EXTICR4_EXTI14_PC                 (0x00000200U)
#define SYSCFG_EXTICR4_EXTI14_PD                 (0x00000300U)
#define SYSCFG_EXTICR4_EXTI14_PE                 (0x00000400U)




#define SYSCFG_EXTICR4_EXTI15_PA                 (0x00000000U)
#define SYSCFG_EXTICR4_EXTI15_PB                 (0x00001000U)
#define SYSCFG_EXTICR4_EXTI15_PC                 (0x00002000U)
#define SYSCFG_EXTICR4_EXTI15_PD                 (0x00003000U)
#define SYSCFG_EXTICR4_EXTI15_PE                 (0x00004000U)


#define SYSCFG_CFGR2_LOCKUP_LOCK_Pos             (0U)
#define SYSCFG_CFGR2_LOCKUP_LOCK_Msk             (0x1U << SYSCFG_CFGR2_LOCKUP_LOCK_Pos)
#define SYSCFG_CFGR2_LOCKUP_LOCK                 SYSCFG_CFGR2_LOCKUP_LOCK_Msk
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK_Pos        (1U)
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK_Msk        (0x1U << SYSCFG_CFGR2_SRAM_PARITY_LOCK_Pos)
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK            SYSCFG_CFGR2_SRAM_PARITY_LOCK_Msk
#define SYSCFG_CFGR2_PVD_LOCK_Pos                (2U)
#define SYSCFG_CFGR2_PVD_LOCK_Msk                (0x1U << SYSCFG_CFGR2_PVD_LOCK_Pos)
#define SYSCFG_CFGR2_PVD_LOCK                    SYSCFG_CFGR2_PVD_LOCK_Msk
#define SYSCFG_CFGR2_BYP_ADDR_PAR_Pos            (4U)
#define SYSCFG_CFGR2_BYP_ADDR_PAR_Msk            (0x1U << SYSCFG_CFGR2_BYP_ADDR_PAR_Pos)
#define SYSCFG_CFGR2_BYP_ADDR_PAR                SYSCFG_CFGR2_BYP_ADDR_PAR_Msk
#define SYSCFG_CFGR2_SRAM_PE_Pos                 (8U)
#define SYSCFG_CFGR2_SRAM_PE_Msk                 (0x1U << SYSCFG_CFGR2_SRAM_PE_Pos)
#define SYSCFG_CFGR2_SRAM_PE                     SYSCFG_CFGR2_SRAM_PE_Msk


#define SYSCFG_CFGR3_DMA_RMP_Pos                 (0U)
#define SYSCFG_CFGR3_DMA_RMP_Msk                 (0x3FFU << SYSCFG_CFGR3_DMA_RMP_Pos)
#define SYSCFG_CFGR3_DMA_RMP                     SYSCFG_CFGR3_DMA_RMP_Msk
#define SYSCFG_CFGR3_SPI1_RX_DMA_RMP_Pos         (0U)
#define SYSCFG_CFGR3_SPI1_RX_DMA_RMP_Msk         (0x3U << SYSCFG_CFGR3_SPI1_RX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_SPI1_RX_DMA_RMP             SYSCFG_CFGR3_SPI1_RX_DMA_RMP_Msk
#define SYSCFG_CFGR3_SPI1_RX_DMA_RMP_0           (0x1U << SYSCFG_CFGR3_SPI1_RX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_SPI1_RX_DMA_RMP_1           (0x2U << SYSCFG_CFGR3_SPI1_RX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_SPI1_TX_DMA_RMP_Pos         (2U)
#define SYSCFG_CFGR3_SPI1_TX_DMA_RMP_Msk         (0x3U << SYSCFG_CFGR3_SPI1_TX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_SPI1_TX_DMA_RMP             SYSCFG_CFGR3_SPI1_TX_DMA_RMP_Msk
#define SYSCFG_CFGR3_SPI1_TX_DMA_RMP_0           (0x1U << SYSCFG_CFGR3_SPI1_TX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_SPI1_TX_DMA_RMP_1           (0x2U << SYSCFG_CFGR3_SPI1_TX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_I2C1_RX_DMA_RMP_Pos         (4U)
#define SYSCFG_CFGR3_I2C1_RX_DMA_RMP_Msk         (0x3U << SYSCFG_CFGR3_I2C1_RX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_I2C1_RX_DMA_RMP             SYSCFG_CFGR3_I2C1_RX_DMA_RMP_Msk
#define SYSCFG_CFGR3_I2C1_RX_DMA_RMP_0           (0x1U << SYSCFG_CFGR3_I2C1_RX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_I2C1_RX_DMA_RMP_1           (0x2U << SYSCFG_CFGR3_I2C1_RX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_I2C1_TX_DMA_RMP_Pos         (6U)
#define SYSCFG_CFGR3_I2C1_TX_DMA_RMP_Msk         (0x3U << SYSCFG_CFGR3_I2C1_TX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_I2C1_TX_DMA_RMP             SYSCFG_CFGR3_I2C1_TX_DMA_RMP_Msk
#define SYSCFG_CFGR3_I2C1_TX_DMA_RMP_0           (0x1U << SYSCFG_CFGR3_I2C1_TX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_I2C1_TX_DMA_RMP_1           (0x2U << SYSCFG_CFGR3_I2C1_TX_DMA_RMP_Pos)
#define SYSCFG_CFGR3_ADC2_DMA_RMP_Pos            (8U)
#define SYSCFG_CFGR3_ADC2_DMA_RMP_Msk            (0x3U << SYSCFG_CFGR3_ADC2_DMA_RMP_Pos)
#define SYSCFG_CFGR3_ADC2_DMA_RMP                SYSCFG_CFGR3_ADC2_DMA_RMP_Msk
#define SYSCFG_CFGR3_ADC2_DMA_RMP_0              (0x1U << SYSCFG_CFGR3_ADC2_DMA_RMP_Pos)
#define SYSCFG_CFGR3_ADC2_DMA_RMP_1              (0x2U << SYSCFG_CFGR3_ADC2_DMA_RMP_Pos)







#define TIM_CR1_CEN_Pos           (0U)
#define TIM_CR1_CEN_Msk           (0x1U << TIM_CR1_CEN_Pos)
#define TIM_CR1_CEN               TIM_CR1_CEN_Msk
#define TIM_CR1_UDIS_Pos          (1U)
#define TIM_CR1_UDIS_Msk          (0x1U << TIM_CR1_UDIS_Pos)
#define TIM_CR1_UDIS              TIM_CR1_UDIS_Msk
#define TIM_CR1_URS_Pos           (2U)
#define TIM_CR1_URS_Msk           (0x1U << TIM_CR1_URS_Pos)
#define TIM_CR1_URS               TIM_CR1_URS_Msk
#define TIM_CR1_OPM_Pos           (3U)
#define TIM_CR1_OPM_Msk           (0x1U << TIM_CR1_OPM_Pos)
#define TIM_CR1_OPM               TIM_CR1_OPM_Msk
#define TIM_CR1_DIR_Pos           (4U)
#define TIM_CR1_DIR_Msk           (0x1U << TIM_CR1_DIR_Pos)
#define TIM_CR1_DIR               TIM_CR1_DIR_Msk

#define TIM_CR1_CMS_Pos           (5U)
#define TIM_CR1_CMS_Msk           (0x3U << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS               TIM_CR1_CMS_Msk
#define TIM_CR1_CMS_0             (0x1U << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS_1             (0x2U << TIM_CR1_CMS_Pos)

#define TIM_CR1_ARPE_Pos          (7U)
#define TIM_CR1_ARPE_Msk          (0x1U << TIM_CR1_ARPE_Pos)
#define TIM_CR1_ARPE              TIM_CR1_ARPE_Msk

#define TIM_CR1_CKD_Pos           (8U)
#define TIM_CR1_CKD_Msk           (0x3U << TIM_CR1_CKD_Pos)
#define TIM_CR1_CKD               TIM_CR1_CKD_Msk
#define TIM_CR1_CKD_0             (0x1U << TIM_CR1_CKD_Pos)
#define TIM_CR1_CKD_1             (0x2U << TIM_CR1_CKD_Pos)

#define TIM_CR1_UIFREMAP_Pos      (11U)
#define TIM_CR1_UIFREMAP_Msk      (0x1U << TIM_CR1_UIFREMAP_Pos)
#define TIM_CR1_UIFREMAP          TIM_CR1_UIFREMAP_Msk


#define TIM_CR2_CCPC_Pos          (0U)
#define TIM_CR2_CCPC_Msk          (0x1U << TIM_CR2_CCPC_Pos)
#define TIM_CR2_CCPC              TIM_CR2_CCPC_Msk
#define TIM_CR2_CCUS_Pos          (2U)
#define TIM_CR2_CCUS_Msk          (0x1U << TIM_CR2_CCUS_Pos)
#define TIM_CR2_CCUS              TIM_CR2_CCUS_Msk
#define TIM_CR2_CCDS_Pos          (3U)
#define TIM_CR2_CCDS_Msk          (0x1U << TIM_CR2_CCDS_Pos)
#define TIM_CR2_CCDS              TIM_CR2_CCDS_Msk

#define TIM_CR2_MMS_Pos           (4U)
#define TIM_CR2_MMS_Msk           (0x7U << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS               TIM_CR2_MMS_Msk
#define TIM_CR2_MMS_0             (0x1U << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_1             (0x2U << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_2             (0x4U << TIM_CR2_MMS_Pos)

#define TIM_CR2_TI1S_Pos          (7U)
#define TIM_CR2_TI1S_Msk          (0x1U << TIM_CR2_TI1S_Pos)
#define TIM_CR2_TI1S              TIM_CR2_TI1S_Msk
#define TIM_CR2_OIS1_Pos          (8U)
#define TIM_CR2_OIS1_Msk          (0x1U << TIM_CR2_OIS1_Pos)
#define TIM_CR2_OIS1              TIM_CR2_OIS1_Msk
#define TIM_CR2_OIS1N_Pos         (9U)
#define TIM_CR2_OIS1N_Msk         (0x1U << TIM_CR2_OIS1N_Pos)
#define TIM_CR2_OIS1N             TIM_CR2_OIS1N_Msk
#define TIM_CR2_OIS2_Pos          (10U)
#define TIM_CR2_OIS2_Msk          (0x1U << TIM_CR2_OIS2_Pos)
#define TIM_CR2_OIS2              TIM_CR2_OIS2_Msk
#define TIM_CR2_OIS2N_Pos         (11U)
#define TIM_CR2_OIS2N_Msk         (0x1U << TIM_CR2_OIS2N_Pos)
#define TIM_CR2_OIS2N             TIM_CR2_OIS2N_Msk
#define TIM_CR2_OIS3_Pos          (12U)
#define TIM_CR2_OIS3_Msk          (0x1U << TIM_CR2_OIS3_Pos)
#define TIM_CR2_OIS3              TIM_CR2_OIS3_Msk
#define TIM_CR2_OIS3N_Pos         (13U)
#define TIM_CR2_OIS3N_Msk         (0x1U << TIM_CR2_OIS3N_Pos)
#define TIM_CR2_OIS3N             TIM_CR2_OIS3N_Msk
#define TIM_CR2_OIS4_Pos          (14U)
#define TIM_CR2_OIS4_Msk          (0x1U << TIM_CR2_OIS4_Pos)
#define TIM_CR2_OIS4              TIM_CR2_OIS4_Msk

#define TIM_CR2_OIS5_Pos          (16U)
#define TIM_CR2_OIS5_Msk          (0x1U << TIM_CR2_OIS5_Pos)
#define TIM_CR2_OIS5              TIM_CR2_OIS5_Msk
#define TIM_CR2_OIS6_Pos          (18U)
#define TIM_CR2_OIS6_Msk          (0x1U << TIM_CR2_OIS6_Pos)
#define TIM_CR2_OIS6              TIM_CR2_OIS6_Msk

#define TIM_CR2_MMS2_Pos          (20U)
#define TIM_CR2_MMS2_Msk          (0xFU << TIM_CR2_MMS2_Pos)
#define TIM_CR2_MMS2              TIM_CR2_MMS2_Msk
#define TIM_CR2_MMS2_0            (0x1U << TIM_CR2_MMS2_Pos)
#define TIM_CR2_MMS2_1            (0x2U << TIM_CR2_MMS2_Pos)
#define TIM_CR2_MMS2_2            (0x4U << TIM_CR2_MMS2_Pos)
#define TIM_CR2_MMS2_3            (0x8U << TIM_CR2_MMS2_Pos)


#define TIM_SMCR_SMS_Pos          (0U)
#define TIM_SMCR_SMS_Msk          (0x10007U << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS              TIM_SMCR_SMS_Msk
#define TIM_SMCR_SMS_0            (0x00000001U)
#define TIM_SMCR_SMS_1            (0x00000002U)
#define TIM_SMCR_SMS_2            (0x00000004U)
#define TIM_SMCR_SMS_3            (0x00010000U)

#define TIM_SMCR_OCCS_Pos         (3U)
#define TIM_SMCR_OCCS_Msk         (0x1U << TIM_SMCR_OCCS_Pos)
#define TIM_SMCR_OCCS             TIM_SMCR_OCCS_Msk

#define TIM_SMCR_TS_Pos           (4U)
#define TIM_SMCR_TS_Msk           (0x7U << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS               TIM_SMCR_TS_Msk
#define TIM_SMCR_TS_0             (0x1U << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_1             (0x2U << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_2             (0x4U << TIM_SMCR_TS_Pos)

#define TIM_SMCR_MSM_Pos          (7U)
#define TIM_SMCR_MSM_Msk          (0x1U << TIM_SMCR_MSM_Pos)
#define TIM_SMCR_MSM              TIM_SMCR_MSM_Msk

#define TIM_SMCR_ETF_Pos          (8U)
#define TIM_SMCR_ETF_Msk          (0xFU << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF              TIM_SMCR_ETF_Msk
#define TIM_SMCR_ETF_0            (0x1U << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_1            (0x2U << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_2            (0x4U << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_3            (0x8U << TIM_SMCR_ETF_Pos)

#define TIM_SMCR_ETPS_Pos         (12U)
#define TIM_SMCR_ETPS_Msk         (0x3U << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS             TIM_SMCR_ETPS_Msk
#define TIM_SMCR_ETPS_0           (0x1U << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS_1           (0x2U << TIM_SMCR_ETPS_Pos)

#define TIM_SMCR_ECE_Pos          (14U)
#define TIM_SMCR_ECE_Msk          (0x1U << TIM_SMCR_ECE_Pos)
#define TIM_SMCR_ECE              TIM_SMCR_ECE_Msk
#define TIM_SMCR_ETP_Pos          (15U)
#define TIM_SMCR_ETP_Msk          (0x1U << TIM_SMCR_ETP_Pos)
#define TIM_SMCR_ETP              TIM_SMCR_ETP_Msk


#define TIM_DIER_UIE_Pos          (0U)
#define TIM_DIER_UIE_Msk          (0x1U << TIM_DIER_UIE_Pos)
#define TIM_DIER_UIE              TIM_DIER_UIE_Msk
#define TIM_DIER_CC1IE_Pos        (1U)
#define TIM_DIER_CC1IE_Msk        (0x1U << TIM_DIER_CC1IE_Pos)
#define TIM_DIER_CC1IE            TIM_DIER_CC1IE_Msk
#define TIM_DIER_CC2IE_Pos        (2U)
#define TIM_DIER_CC2IE_Msk        (0x1U << TIM_DIER_CC2IE_Pos)
#define TIM_DIER_CC2IE            TIM_DIER_CC2IE_Msk
#define TIM_DIER_CC3IE_Pos        (3U)
#define TIM_DIER_CC3IE_Msk        (0x1U << TIM_DIER_CC3IE_Pos)
#define TIM_DIER_CC3IE            TIM_DIER_CC3IE_Msk
#define TIM_DIER_CC4IE_Pos        (4U)
#define TIM_DIER_CC4IE_Msk        (0x1U << TIM_DIER_CC4IE_Pos)
#define TIM_DIER_CC4IE            TIM_DIER_CC4IE_Msk
#define TIM_DIER_COMIE_Pos        (5U)
#define TIM_DIER_COMIE_Msk        (0x1U << TIM_DIER_COMIE_Pos)
#define TIM_DIER_COMIE            TIM_DIER_COMIE_Msk
#define TIM_DIER_TIE_Pos          (6U)
#define TIM_DIER_TIE_Msk          (0x1U << TIM_DIER_TIE_Pos)
#define TIM_DIER_TIE              TIM_DIER_TIE_Msk
#define TIM_DIER_BIE_Pos          (7U)
#define TIM_DIER_BIE_Msk          (0x1U << TIM_DIER_BIE_Pos)
#define TIM_DIER_BIE              TIM_DIER_BIE_Msk
#define TIM_DIER_UDE_Pos          (8U)
#define TIM_DIER_UDE_Msk          (0x1U << TIM_DIER_UDE_Pos)
#define TIM_DIER_UDE              TIM_DIER_UDE_Msk
#define TIM_DIER_CC1DE_Pos        (9U)
#define TIM_DIER_CC1DE_Msk        (0x1U << TIM_DIER_CC1DE_Pos)
#define TIM_DIER_CC1DE            TIM_DIER_CC1DE_Msk
#define TIM_DIER_CC2DE_Pos        (10U)
#define TIM_DIER_CC2DE_Msk        (0x1U << TIM_DIER_CC2DE_Pos)
#define TIM_DIER_CC2DE            TIM_DIER_CC2DE_Msk
#define TIM_DIER_CC3DE_Pos        (11U)
#define TIM_DIER_CC3DE_Msk        (0x1U << TIM_DIER_CC3DE_Pos)
#define TIM_DIER_CC3DE            TIM_DIER_CC3DE_Msk
#define TIM_DIER_CC4DE_Pos        (12U)
#define TIM_DIER_CC4DE_Msk        (0x1U << TIM_DIER_CC4DE_Pos)
#define TIM_DIER_CC4DE            TIM_DIER_CC4DE_Msk
#define TIM_DIER_COMDE_Pos        (13U)
#define TIM_DIER_COMDE_Msk        (0x1U << TIM_DIER_COMDE_Pos)
#define TIM_DIER_COMDE            TIM_DIER_COMDE_Msk
#define TIM_DIER_TDE_Pos          (14U)
#define TIM_DIER_TDE_Msk          (0x1U << TIM_DIER_TDE_Pos)
#define TIM_DIER_TDE              TIM_DIER_TDE_Msk


#define TIM_SR_UIF_Pos            (0U)
#define TIM_SR_UIF_Msk            (0x1U << TIM_SR_UIF_Pos)
#define TIM_SR_UIF                TIM_SR_UIF_Msk
#define TIM_SR_CC1IF_Pos          (1U)
#define TIM_SR_CC1IF_Msk          (0x1U << TIM_SR_CC1IF_Pos)
#define TIM_SR_CC1IF              TIM_SR_CC1IF_Msk
#define TIM_SR_CC2IF_Pos          (2U)
#define TIM_SR_CC2IF_Msk          (0x1U << TIM_SR_CC2IF_Pos)
#define TIM_SR_CC2IF              TIM_SR_CC2IF_Msk
#define TIM_SR_CC3IF_Pos          (3U)
#define TIM_SR_CC3IF_Msk          (0x1U << TIM_SR_CC3IF_Pos)
#define TIM_SR_CC3IF              TIM_SR_CC3IF_Msk
#define TIM_SR_CC4IF_Pos          (4U)
#define TIM_SR_CC4IF_Msk          (0x1U << TIM_SR_CC4IF_Pos)
#define TIM_SR_CC4IF              TIM_SR_CC4IF_Msk
#define TIM_SR_COMIF_Pos          (5U)
#define TIM_SR_COMIF_Msk          (0x1U << TIM_SR_COMIF_Pos)
#define TIM_SR_COMIF              TIM_SR_COMIF_Msk
#define TIM_SR_TIF_Pos            (6U)
#define TIM_SR_TIF_Msk            (0x1U << TIM_SR_TIF_Pos)
#define TIM_SR_TIF                TIM_SR_TIF_Msk
#define TIM_SR_BIF_Pos            (7U)
#define TIM_SR_BIF_Msk            (0x1U << TIM_SR_BIF_Pos)
#define TIM_SR_BIF                TIM_SR_BIF_Msk
#define TIM_SR_B2IF_Pos           (8U)
#define TIM_SR_B2IF_Msk           (0x1U << TIM_SR_B2IF_Pos)
#define TIM_SR_B2IF               TIM_SR_B2IF_Msk
#define TIM_SR_CC1OF_Pos          (9U)
#define TIM_SR_CC1OF_Msk          (0x1U << TIM_SR_CC1OF_Pos)
#define TIM_SR_CC1OF              TIM_SR_CC1OF_Msk
#define TIM_SR_CC2OF_Pos          (10U)
#define TIM_SR_CC2OF_Msk          (0x1U << TIM_SR_CC2OF_Pos)
#define TIM_SR_CC2OF              TIM_SR_CC2OF_Msk
#define TIM_SR_CC3OF_Pos          (11U)
#define TIM_SR_CC3OF_Msk          (0x1U << TIM_SR_CC3OF_Pos)
#define TIM_SR_CC3OF              TIM_SR_CC3OF_Msk
#define TIM_SR_CC4OF_Pos          (12U)
#define TIM_SR_CC4OF_Msk          (0x1U << TIM_SR_CC4OF_Pos)
#define TIM_SR_CC4OF              TIM_SR_CC4OF_Msk
#define TIM_SR_CC5IF_Pos          (16U)
#define TIM_SR_CC5IF_Msk          (0x1U << TIM_SR_CC5IF_Pos)
#define TIM_SR_CC5IF              TIM_SR_CC5IF_Msk
#define TIM_SR_CC6IF_Pos          (17U)
#define TIM_SR_CC6IF_Msk          (0x1U << TIM_SR_CC6IF_Pos)
#define TIM_SR_CC6IF              TIM_SR_CC6IF_Msk


#define TIM_EGR_UG_Pos            (0U)
#define TIM_EGR_UG_Msk            (0x1U << TIM_EGR_UG_Pos)
#define TIM_EGR_UG                TIM_EGR_UG_Msk
#define TIM_EGR_CC1G_Pos          (1U)
#define TIM_EGR_CC1G_Msk          (0x1U << TIM_EGR_CC1G_Pos)
#define TIM_EGR_CC1G              TIM_EGR_CC1G_Msk
#define TIM_EGR_CC2G_Pos          (2U)
#define TIM_EGR_CC2G_Msk          (0x1U << TIM_EGR_CC2G_Pos)
#define TIM_EGR_CC2G              TIM_EGR_CC2G_Msk
#define TIM_EGR_CC3G_Pos          (3U)
#define TIM_EGR_CC3G_Msk          (0x1U << TIM_EGR_CC3G_Pos)
#define TIM_EGR_CC3G              TIM_EGR_CC3G_Msk
#define TIM_EGR_CC4G_Pos          (4U)
#define TIM_EGR_CC4G_Msk          (0x1U << TIM_EGR_CC4G_Pos)
#define TIM_EGR_CC4G              TIM_EGR_CC4G_Msk
#define TIM_EGR_COMG_Pos          (5U)
#define TIM_EGR_COMG_Msk          (0x1U << TIM_EGR_COMG_Pos)
#define TIM_EGR_COMG              TIM_EGR_COMG_Msk
#define TIM_EGR_TG_Pos            (6U)
#define TIM_EGR_TG_Msk            (0x1U << TIM_EGR_TG_Pos)
#define TIM_EGR_TG                TIM_EGR_TG_Msk
#define TIM_EGR_BG_Pos            (7U)
#define TIM_EGR_BG_Msk            (0x1U << TIM_EGR_BG_Pos)
#define TIM_EGR_BG                TIM_EGR_BG_Msk
#define TIM_EGR_B2G_Pos           (8U)
#define TIM_EGR_B2G_Msk           (0x1U << TIM_EGR_B2G_Pos)
#define TIM_EGR_B2G               TIM_EGR_B2G_Msk


#define TIM_CCMR1_CC1S_Pos        (0U)
#define TIM_CCMR1_CC1S_Msk        (0x3U << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S            TIM_CCMR1_CC1S_Msk
#define TIM_CCMR1_CC1S_0          (0x1U << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S_1          (0x2U << TIM_CCMR1_CC1S_Pos)

#define TIM_CCMR1_OC1FE_Pos       (2U)
#define TIM_CCMR1_OC1FE_Msk       (0x1U << TIM_CCMR1_OC1FE_Pos)
#define TIM_CCMR1_OC1FE           TIM_CCMR1_OC1FE_Msk
#define TIM_CCMR1_OC1PE_Pos       (3U)
#define TIM_CCMR1_OC1PE_Msk       (0x1U << TIM_CCMR1_OC1PE_Pos)
#define TIM_CCMR1_OC1PE           TIM_CCMR1_OC1PE_Msk

#define TIM_CCMR1_OC1M_Pos        (4U)
#define TIM_CCMR1_OC1M_Msk        (0x1007U << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M            TIM_CCMR1_OC1M_Msk
#define TIM_CCMR1_OC1M_0          (0x00000010U)
#define TIM_CCMR1_OC1M_1          (0x00000020U)
#define TIM_CCMR1_OC1M_2          (0x00000040U)
#define TIM_CCMR1_OC1M_3          (0x00010000U)

#define TIM_CCMR1_OC1CE_Pos       (7U)
#define TIM_CCMR1_OC1CE_Msk       (0x1U << TIM_CCMR1_OC1CE_Pos)
#define TIM_CCMR1_OC1CE           TIM_CCMR1_OC1CE_Msk

#define TIM_CCMR1_CC2S_Pos        (8U)
#define TIM_CCMR1_CC2S_Msk        (0x3U << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S            TIM_CCMR1_CC2S_Msk
#define TIM_CCMR1_CC2S_0          (0x1U << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S_1          (0x2U << TIM_CCMR1_CC2S_Pos)

#define TIM_CCMR1_OC2FE_Pos       (10U)
#define TIM_CCMR1_OC2FE_Msk       (0x1U << TIM_CCMR1_OC2FE_Pos)
#define TIM_CCMR1_OC2FE           TIM_CCMR1_OC2FE_Msk
#define TIM_CCMR1_OC2PE_Pos       (11U)
#define TIM_CCMR1_OC2PE_Msk       (0x1U << TIM_CCMR1_OC2PE_Pos)
#define TIM_CCMR1_OC2PE           TIM_CCMR1_OC2PE_Msk

#define TIM_CCMR1_OC2M_Pos        (12U)
#define TIM_CCMR1_OC2M_Msk        (0x1007U << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M            TIM_CCMR1_OC2M_Msk
#define TIM_CCMR1_OC2M_0          (0x00001000U)
#define TIM_CCMR1_OC2M_1          (0x00002000U)
#define TIM_CCMR1_OC2M_2          (0x00004000U)
#define TIM_CCMR1_OC2M_3          (0x01000000U)

#define TIM_CCMR1_OC2CE_Pos       (15U)
#define TIM_CCMR1_OC2CE_Msk       (0x1U << TIM_CCMR1_OC2CE_Pos)
#define TIM_CCMR1_OC2CE           TIM_CCMR1_OC2CE_Msk



#define TIM_CCMR1_IC1PSC_Pos      (2U)
#define TIM_CCMR1_IC1PSC_Msk      (0x3U << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC          TIM_CCMR1_IC1PSC_Msk
#define TIM_CCMR1_IC1PSC_0        (0x1U << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC_1        (0x2U << TIM_CCMR1_IC1PSC_Pos)

#define TIM_CCMR1_IC1F_Pos        (4U)
#define TIM_CCMR1_IC1F_Msk        (0xFU << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F            TIM_CCMR1_IC1F_Msk
#define TIM_CCMR1_IC1F_0          (0x1U << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_1          (0x2U << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_2          (0x4U << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_3          (0x8U << TIM_CCMR1_IC1F_Pos)

#define TIM_CCMR1_IC2PSC_Pos      (10U)
#define TIM_CCMR1_IC2PSC_Msk      (0x3U << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC          TIM_CCMR1_IC2PSC_Msk
#define TIM_CCMR1_IC2PSC_0        (0x1U << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC_1        (0x2U << TIM_CCMR1_IC2PSC_Pos)

#define TIM_CCMR1_IC2F_Pos        (12U)
#define TIM_CCMR1_IC2F_Msk        (0xFU << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F            TIM_CCMR1_IC2F_Msk
#define TIM_CCMR1_IC2F_0          (0x1U << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_1          (0x2U << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_2          (0x4U << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_3          (0x8U << TIM_CCMR1_IC2F_Pos)


#define TIM_CCMR2_CC3S_Pos        (0U)
#define TIM_CCMR2_CC3S_Msk        (0x3U << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S            TIM_CCMR2_CC3S_Msk
#define TIM_CCMR2_CC3S_0          (0x1U << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S_1          (0x2U << TIM_CCMR2_CC3S_Pos)

#define TIM_CCMR2_OC3FE_Pos       (2U)
#define TIM_CCMR2_OC3FE_Msk       (0x1U << TIM_CCMR2_OC3FE_Pos)
#define TIM_CCMR2_OC3FE           TIM_CCMR2_OC3FE_Msk
#define TIM_CCMR2_OC3PE_Pos       (3U)
#define TIM_CCMR2_OC3PE_Msk       (0x1U << TIM_CCMR2_OC3PE_Pos)
#define TIM_CCMR2_OC3PE           TIM_CCMR2_OC3PE_Msk

#define TIM_CCMR2_OC3M_Pos        (4U)
#define TIM_CCMR2_OC3M_Msk        (0x1007U << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M            TIM_CCMR2_OC3M_Msk
#define TIM_CCMR2_OC3M_0          (0x00000010U)
#define TIM_CCMR2_OC3M_1          (0x00000020U)
#define TIM_CCMR2_OC3M_2          (0x00000040U)
#define TIM_CCMR2_OC3M_3          (0x00010000U)

#define TIM_CCMR2_OC3CE_Pos       (7U)
#define TIM_CCMR2_OC3CE_Msk       (0x1U << TIM_CCMR2_OC3CE_Pos)
#define TIM_CCMR2_OC3CE           TIM_CCMR2_OC3CE_Msk

#define TIM_CCMR2_CC4S_Pos        (8U)
#define TIM_CCMR2_CC4S_Msk        (0x3U << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S            TIM_CCMR2_CC4S_Msk
#define TIM_CCMR2_CC4S_0          (0x1U << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S_1          (0x2U << TIM_CCMR2_CC4S_Pos)

#define TIM_CCMR2_OC4FE_Pos       (10U)
#define TIM_CCMR2_OC4FE_Msk       (0x1U << TIM_CCMR2_OC4FE_Pos)
#define TIM_CCMR2_OC4FE           TIM_CCMR2_OC4FE_Msk
#define TIM_CCMR2_OC4PE_Pos       (11U)
#define TIM_CCMR2_OC4PE_Msk       (0x1U << TIM_CCMR2_OC4PE_Pos)
#define TIM_CCMR2_OC4PE           TIM_CCMR2_OC4PE_Msk

#define TIM_CCMR2_OC4M_Pos        (12U)
#define TIM_CCMR2_OC4M_Msk        (0x1007U << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M            TIM_CCMR2_OC4M_Msk
#define TIM_CCMR2_OC4M_0          (0x00001000U)
#define TIM_CCMR2_OC4M_1          (0x00002000U)
#define TIM_CCMR2_OC4M_2          (0x00004000U)
#define TIM_CCMR2_OC4M_3          (0x01000000U)

#define TIM_CCMR2_OC4CE_Pos       (15U)
#define TIM_CCMR2_OC4CE_Msk       (0x1U << TIM_CCMR2_OC4CE_Pos)
#define TIM_CCMR2_OC4CE           TIM_CCMR2_OC4CE_Msk



#define TIM_CCMR2_IC3PSC_Pos      (2U)
#define TIM_CCMR2_IC3PSC_Msk      (0x3U << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC          TIM_CCMR2_IC3PSC_Msk
#define TIM_CCMR2_IC3PSC_0        (0x1U << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC_1        (0x2U << TIM_CCMR2_IC3PSC_Pos)

#define TIM_CCMR2_IC3F_Pos        (4U)
#define TIM_CCMR2_IC3F_Msk        (0xFU << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F            TIM_CCMR2_IC3F_Msk
#define TIM_CCMR2_IC3F_0          (0x1U << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_1          (0x2U << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_2          (0x4U << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_3          (0x8U << TIM_CCMR2_IC3F_Pos)

#define TIM_CCMR2_IC4PSC_Pos      (10U)
#define TIM_CCMR2_IC4PSC_Msk      (0x3U << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC          TIM_CCMR2_IC4PSC_Msk
#define TIM_CCMR2_IC4PSC_0        (0x1U << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC_1        (0x2U << TIM_CCMR2_IC4PSC_Pos)

#define TIM_CCMR2_IC4F_Pos        (12U)
#define TIM_CCMR2_IC4F_Msk        (0xFU << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F            TIM_CCMR2_IC4F_Msk
#define TIM_CCMR2_IC4F_0          (0x1U << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_1          (0x2U << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_2          (0x4U << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_3          (0x8U << TIM_CCMR2_IC4F_Pos)


#define TIM_CCER_CC1E_Pos         (0U)
#define TIM_CCER_CC1E_Msk         (0x1U << TIM_CCER_CC1E_Pos)
#define TIM_CCER_CC1E             TIM_CCER_CC1E_Msk
#define TIM_CCER_CC1P_Pos         (1U)
#define TIM_CCER_CC1P_Msk         (0x1U << TIM_CCER_CC1P_Pos)
#define TIM_CCER_CC1P             TIM_CCER_CC1P_Msk
#define TIM_CCER_CC1NE_Pos        (2U)
#define TIM_CCER_CC1NE_Msk        (0x1U << TIM_CCER_CC1NE_Pos)
#define TIM_CCER_CC1NE            TIM_CCER_CC1NE_Msk
#define TIM_CCER_CC1NP_Pos        (3U)
#define TIM_CCER_CC1NP_Msk        (0x1U << TIM_CCER_CC1NP_Pos)
#define TIM_CCER_CC1NP            TIM_CCER_CC1NP_Msk
#define TIM_CCER_CC2E_Pos         (4U)
#define TIM_CCER_CC2E_Msk         (0x1U << TIM_CCER_CC2E_Pos)
#define TIM_CCER_CC2E             TIM_CCER_CC2E_Msk
#define TIM_CCER_CC2P_Pos         (5U)
#define TIM_CCER_CC2P_Msk         (0x1U << TIM_CCER_CC2P_Pos)
#define TIM_CCER_CC2P             TIM_CCER_CC2P_Msk
#define TIM_CCER_CC2NE_Pos        (6U)
#define TIM_CCER_CC2NE_Msk        (0x1U << TIM_CCER_CC2NE_Pos)
#define TIM_CCER_CC2NE            TIM_CCER_CC2NE_Msk
#define TIM_CCER_CC2NP_Pos        (7U)
#define TIM_CCER_CC2NP_Msk        (0x1U << TIM_CCER_CC2NP_Pos)
#define TIM_CCER_CC2NP            TIM_CCER_CC2NP_Msk
#define TIM_CCER_CC3E_Pos         (8U)
#define TIM_CCER_CC3E_Msk         (0x1U << TIM_CCER_CC3E_Pos)
#define TIM_CCER_CC3E             TIM_CCER_CC3E_Msk
#define TIM_CCER_CC3P_Pos         (9U)
#define TIM_CCER_CC3P_Msk         (0x1U << TIM_CCER_CC3P_Pos)
#define TIM_CCER_CC3P             TIM_CCER_CC3P_Msk
#define TIM_CCER_CC3NE_Pos        (10U)
#define TIM_CCER_CC3NE_Msk        (0x1U << TIM_CCER_CC3NE_Pos)
#define TIM_CCER_CC3NE            TIM_CCER_CC3NE_Msk
#define TIM_CCER_CC3NP_Pos        (11U)
#define TIM_CCER_CC3NP_Msk        (0x1U << TIM_CCER_CC3NP_Pos)
#define TIM_CCER_CC3NP            TIM_CCER_CC3NP_Msk
#define TIM_CCER_CC4E_Pos         (12U)
#define TIM_CCER_CC4E_Msk         (0x1U << TIM_CCER_CC4E_Pos)
#define TIM_CCER_CC4E             TIM_CCER_CC4E_Msk
#define TIM_CCER_CC4P_Pos         (13U)
#define TIM_CCER_CC4P_Msk         (0x1U << TIM_CCER_CC4P_Pos)
#define TIM_CCER_CC4P             TIM_CCER_CC4P_Msk
#define TIM_CCER_CC4NP_Pos        (15U)
#define TIM_CCER_CC4NP_Msk        (0x1U << TIM_CCER_CC4NP_Pos)
#define TIM_CCER_CC4NP            TIM_CCER_CC4NP_Msk
#define TIM_CCER_CC5E_Pos         (16U)
#define TIM_CCER_CC5E_Msk         (0x1U << TIM_CCER_CC5E_Pos)
#define TIM_CCER_CC5E             TIM_CCER_CC5E_Msk
#define TIM_CCER_CC5P_Pos         (17U)
#define TIM_CCER_CC5P_Msk         (0x1U << TIM_CCER_CC5P_Pos)
#define TIM_CCER_CC5P             TIM_CCER_CC5P_Msk
#define TIM_CCER_CC6E_Pos         (20U)
#define TIM_CCER_CC6E_Msk         (0x1U << TIM_CCER_CC6E_Pos)
#define TIM_CCER_CC6E             TIM_CCER_CC6E_Msk
#define TIM_CCER_CC6P_Pos         (21U)
#define TIM_CCER_CC6P_Msk         (0x1U << TIM_CCER_CC6P_Pos)
#define TIM_CCER_CC6P             TIM_CCER_CC6P_Msk


#define TIM_CNT_CNT_Pos           (0U)
#define TIM_CNT_CNT_Msk           (0xFFFFFFFFU << TIM_CNT_CNT_Pos)
#define TIM_CNT_CNT               TIM_CNT_CNT_Msk
#define TIM_CNT_UIFCPY_Pos        (31U)
#define TIM_CNT_UIFCPY_Msk        (0x1U << TIM_CNT_UIFCPY_Pos)
#define TIM_CNT_UIFCPY            TIM_CNT_UIFCPY_Msk


#define TIM_PSC_PSC_Pos           (0U)
#define TIM_PSC_PSC_Msk           (0xFFFFU << TIM_PSC_PSC_Pos)
#define TIM_PSC_PSC               TIM_PSC_PSC_Msk


#define TIM_ARR_ARR_Pos           (0U)
#define TIM_ARR_ARR_Msk           (0xFFFFFFFFU << TIM_ARR_ARR_Pos)
#define TIM_ARR_ARR               TIM_ARR_ARR_Msk


#define TIM_RCR_REP_Pos           (0U)
#define TIM_RCR_REP_Msk           (0xFFFFU << TIM_RCR_REP_Pos)
#define TIM_RCR_REP               TIM_RCR_REP_Msk


#define TIM_CCR1_CCR1_Pos         (0U)
#define TIM_CCR1_CCR1_Msk         (0xFFFFU << TIM_CCR1_CCR1_Pos)
#define TIM_CCR1_CCR1             TIM_CCR1_CCR1_Msk


#define TIM_CCR2_CCR2_Pos         (0U)
#define TIM_CCR2_CCR2_Msk         (0xFFFFU << TIM_CCR2_CCR2_Pos)
#define TIM_CCR2_CCR2             TIM_CCR2_CCR2_Msk


#define TIM_CCR3_CCR3_Pos         (0U)
#define TIM_CCR3_CCR3_Msk         (0xFFFFU << TIM_CCR3_CCR3_Pos)
#define TIM_CCR3_CCR3             TIM_CCR3_CCR3_Msk


#define TIM_CCR4_CCR4_Pos         (0U)
#define TIM_CCR4_CCR4_Msk         (0xFFFFU << TIM_CCR4_CCR4_Pos)
#define TIM_CCR4_CCR4             TIM_CCR4_CCR4_Msk


#define TIM_CCR5_CCR5_Pos         (0U)
#define TIM_CCR5_CCR5_Msk         (0xFFFFFFFFU << TIM_CCR5_CCR5_Pos)
#define TIM_CCR5_CCR5             TIM_CCR5_CCR5_Msk
#define TIM_CCR5_GC5C1_Pos        (29U)
#define TIM_CCR5_GC5C1_Msk        (0x1U << TIM_CCR5_GC5C1_Pos)
#define TIM_CCR5_GC5C1            TIM_CCR5_GC5C1_Msk
#define TIM_CCR5_GC5C2_Pos        (30U)
#define TIM_CCR5_GC5C2_Msk        (0x1U << TIM_CCR5_GC5C2_Pos)
#define TIM_CCR5_GC5C2            TIM_CCR5_GC5C2_Msk
#define TIM_CCR5_GC5C3_Pos        (31U)
#define TIM_CCR5_GC5C3_Msk        (0x1U << TIM_CCR5_GC5C3_Pos)
#define TIM_CCR5_GC5C3            TIM_CCR5_GC5C3_Msk


#define TIM_CCR6_CCR6_Pos         (0U)
#define TIM_CCR6_CCR6_Msk         (0xFFFFU << TIM_CCR6_CCR6_Pos)
#define TIM_CCR6_CCR6             TIM_CCR6_CCR6_Msk


#define TIM_BDTR_DTG_Pos          (0U)
#define TIM_BDTR_DTG_Msk          (0xFFU << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG              TIM_BDTR_DTG_Msk
#define TIM_BDTR_DTG_0            (0x01U << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_1            (0x02U << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_2            (0x04U << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_3            (0x08U << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_4            (0x10U << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_5            (0x20U << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_6            (0x40U << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_7            (0x80U << TIM_BDTR_DTG_Pos)

#define TIM_BDTR_LOCK_Pos         (8U)
#define TIM_BDTR_LOCK_Msk         (0x3U << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK             TIM_BDTR_LOCK_Msk
#define TIM_BDTR_LOCK_0           (0x1U << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK_1           (0x2U << TIM_BDTR_LOCK_Pos)

#define TIM_BDTR_OSSI_Pos         (10U)
#define TIM_BDTR_OSSI_Msk         (0x1U << TIM_BDTR_OSSI_Pos)
#define TIM_BDTR_OSSI             TIM_BDTR_OSSI_Msk
#define TIM_BDTR_OSSR_Pos         (11U)
#define TIM_BDTR_OSSR_Msk         (0x1U << TIM_BDTR_OSSR_Pos)
#define TIM_BDTR_OSSR             TIM_BDTR_OSSR_Msk
#define TIM_BDTR_BKE_Pos          (12U)
#define TIM_BDTR_BKE_Msk          (0x1U << TIM_BDTR_BKE_Pos)
#define TIM_BDTR_BKE              TIM_BDTR_BKE_Msk
#define TIM_BDTR_BKP_Pos          (13U)
#define TIM_BDTR_BKP_Msk          (0x1U << TIM_BDTR_BKP_Pos)
#define TIM_BDTR_BKP              TIM_BDTR_BKP_Msk
#define TIM_BDTR_AOE_Pos          (14U)
#define TIM_BDTR_AOE_Msk          (0x1U << TIM_BDTR_AOE_Pos)
#define TIM_BDTR_AOE              TIM_BDTR_AOE_Msk
#define TIM_BDTR_MOE_Pos          (15U)
#define TIM_BDTR_MOE_Msk          (0x1U << TIM_BDTR_MOE_Pos)
#define TIM_BDTR_MOE              TIM_BDTR_MOE_Msk

#define TIM_BDTR_BKF_Pos          (16U)
#define TIM_BDTR_BKF_Msk          (0xFU << TIM_BDTR_BKF_Pos)
#define TIM_BDTR_BKF              TIM_BDTR_BKF_Msk
#define TIM_BDTR_BK2F_Pos         (20U)
#define TIM_BDTR_BK2F_Msk         (0xFU << TIM_BDTR_BK2F_Pos)
#define TIM_BDTR_BK2F             TIM_BDTR_BK2F_Msk

#define TIM_BDTR_BK2E_Pos         (24U)
#define TIM_BDTR_BK2E_Msk         (0x1U << TIM_BDTR_BK2E_Pos)
#define TIM_BDTR_BK2E             TIM_BDTR_BK2E_Msk
#define TIM_BDTR_BK2P_Pos         (25U)
#define TIM_BDTR_BK2P_Msk         (0x1U << TIM_BDTR_BK2P_Pos)
#define TIM_BDTR_BK2P             TIM_BDTR_BK2P_Msk


#define TIM_DCR_DBA_Pos           (0U)
#define TIM_DCR_DBA_Msk           (0x1FU << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA               TIM_DCR_DBA_Msk
#define TIM_DCR_DBA_0             (0x01U << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_1             (0x02U << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_2             (0x04U << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_3             (0x08U << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_4             (0x10U << TIM_DCR_DBA_Pos)

#define TIM_DCR_DBL_Pos           (8U)
#define TIM_DCR_DBL_Msk           (0x1FU << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL               TIM_DCR_DBL_Msk
#define TIM_DCR_DBL_0             (0x01U << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_1             (0x02U << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_2             (0x04U << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_3             (0x08U << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_4             (0x10U << TIM_DCR_DBL_Pos)


#define TIM_DMAR_DMAB_Pos         (0U)
#define TIM_DMAR_DMAB_Msk         (0xFFFFU << TIM_DMAR_DMAB_Pos)
#define TIM_DMAR_DMAB             TIM_DMAR_DMAB_Msk


#define TIM16_OR_TI1_RMP_Pos      (6U)
#define TIM16_OR_TI1_RMP_Msk      (0x3U << TIM16_OR_TI1_RMP_Pos)
#define TIM16_OR_TI1_RMP          TIM16_OR_TI1_RMP_Msk
#define TIM16_OR_TI1_RMP_0        (0x1U << TIM16_OR_TI1_RMP_Pos)
#define TIM16_OR_TI1_RMP_1        (0x2U << TIM16_OR_TI1_RMP_Pos)


#define TIM1_OR_ETR_RMP_Pos      (0U)
#define TIM1_OR_ETR_RMP_Msk      (0xFU << TIM1_OR_ETR_RMP_Pos)
#define TIM1_OR_ETR_RMP          TIM1_OR_ETR_RMP_Msk
#define TIM1_OR_ETR_RMP_0        (0x1U << TIM1_OR_ETR_RMP_Pos)
#define TIM1_OR_ETR_RMP_1        (0x2U << TIM1_OR_ETR_RMP_Pos)
#define TIM1_OR_ETR_RMP_2        (0x4U << TIM1_OR_ETR_RMP_Pos)
#define TIM1_OR_ETR_RMP_3        (0x8U << TIM1_OR_ETR_RMP_Pos)


#define TIM_CCMR3_OC5FE_Pos       (2U)
#define TIM_CCMR3_OC5FE_Msk       (0x1U << TIM_CCMR3_OC5FE_Pos)
#define TIM_CCMR3_OC5FE           TIM_CCMR3_OC5FE_Msk
#define TIM_CCMR3_OC5PE_Pos       (3U)
#define TIM_CCMR3_OC5PE_Msk       (0x1U << TIM_CCMR3_OC5PE_Pos)
#define TIM_CCMR3_OC5PE           TIM_CCMR3_OC5PE_Msk

#define TIM_CCMR3_OC5M_Pos        (4U)
#define TIM_CCMR3_OC5M_Msk        (0x1007U << TIM_CCMR3_OC5M_Pos)
#define TIM_CCMR3_OC5M            TIM_CCMR3_OC5M_Msk
#define TIM_CCMR3_OC5M_0          (0x0001U << TIM_CCMR3_OC5M_Pos)
#define TIM_CCMR3_OC5M_1          (0x0002U << TIM_CCMR3_OC5M_Pos)
#define TIM_CCMR3_OC5M_2          (0x0004U << TIM_CCMR3_OC5M_Pos)
#define TIM_CCMR3_OC5M_3          (0x1000U << TIM_CCMR3_OC5M_Pos)

#define TIM_CCMR3_OC5CE_Pos       (7U)
#define TIM_CCMR3_OC5CE_Msk       (0x1U << TIM_CCMR3_OC5CE_Pos)
#define TIM_CCMR3_OC5CE           TIM_CCMR3_OC5CE_Msk

#define TIM_CCMR3_OC6FE_Pos       (10U)
#define TIM_CCMR3_OC6FE_Msk       (0x1U << TIM_CCMR3_OC6FE_Pos)
#define TIM_CCMR3_OC6FE           TIM_CCMR3_OC6FE_Msk
#define TIM_CCMR3_OC6PE_Pos       (11U)
#define TIM_CCMR3_OC6PE_Msk       (0x1U << TIM_CCMR3_OC6PE_Pos)
#define TIM_CCMR3_OC6PE           TIM_CCMR3_OC6PE_Msk

#define TIM_CCMR3_OC6M_Pos        (12U)
#define TIM_CCMR3_OC6M_Msk        (0x1007U << TIM_CCMR3_OC6M_Pos)
#define TIM_CCMR3_OC6M            TIM_CCMR3_OC6M_Msk
#define TIM_CCMR3_OC6M_0          (0x0001U << TIM_CCMR3_OC6M_Pos)
#define TIM_CCMR3_OC6M_1          (0x0002U << TIM_CCMR3_OC6M_Pos)
#define TIM_CCMR3_OC6M_2          (0x0004U << TIM_CCMR3_OC6M_Pos)
#define TIM_CCMR3_OC6M_3          (0x1000U << TIM_CCMR3_OC6M_Pos)

#define TIM_CCMR3_OC6CE_Pos       (15U)
#define TIM_CCMR3_OC6CE_Msk       (0x1U << TIM_CCMR3_OC6CE_Pos)
#define TIM_CCMR3_OC6CE           TIM_CCMR3_OC6CE_Msk







#define TSC_CR_TSCE_Pos          (0U)
#define TSC_CR_TSCE_Msk          (0x1U << TSC_CR_TSCE_Pos)
#define TSC_CR_TSCE              TSC_CR_TSCE_Msk
#define TSC_CR_START_Pos         (1U)
#define TSC_CR_START_Msk         (0x1U << TSC_CR_START_Pos)
#define TSC_CR_START             TSC_CR_START_Msk
#define TSC_CR_AM_Pos            (2U)
#define TSC_CR_AM_Msk            (0x1U << TSC_CR_AM_Pos)
#define TSC_CR_AM                TSC_CR_AM_Msk
#define TSC_CR_SYNCPOL_Pos       (3U)
#define TSC_CR_SYNCPOL_Msk       (0x1U << TSC_CR_SYNCPOL_Pos)
#define TSC_CR_SYNCPOL           TSC_CR_SYNCPOL_Msk
#define TSC_CR_IODEF_Pos         (4U)
#define TSC_CR_IODEF_Msk         (0x1U << TSC_CR_IODEF_Pos)
#define TSC_CR_IODEF             TSC_CR_IODEF_Msk

#define TSC_CR_MCV_Pos           (5U)
#define TSC_CR_MCV_Msk           (0x7U << TSC_CR_MCV_Pos)
#define TSC_CR_MCV               TSC_CR_MCV_Msk
#define TSC_CR_MCV_0             (0x1U << TSC_CR_MCV_Pos)
#define TSC_CR_MCV_1             (0x2U << TSC_CR_MCV_Pos)
#define TSC_CR_MCV_2             (0x4U << TSC_CR_MCV_Pos)

#define TSC_CR_PGPSC_Pos         (12U)
#define TSC_CR_PGPSC_Msk         (0x7U << TSC_CR_PGPSC_Pos)
#define TSC_CR_PGPSC             TSC_CR_PGPSC_Msk
#define TSC_CR_PGPSC_0           (0x1U << TSC_CR_PGPSC_Pos)
#define TSC_CR_PGPSC_1           (0x2U << TSC_CR_PGPSC_Pos)
#define TSC_CR_PGPSC_2           (0x4U << TSC_CR_PGPSC_Pos)

#define TSC_CR_SSPSC_Pos         (15U)
#define TSC_CR_SSPSC_Msk         (0x1U << TSC_CR_SSPSC_Pos)
#define TSC_CR_SSPSC             TSC_CR_SSPSC_Msk
#define TSC_CR_SSE_Pos           (16U)
#define TSC_CR_SSE_Msk           (0x1U << TSC_CR_SSE_Pos)
#define TSC_CR_SSE               TSC_CR_SSE_Msk

#define TSC_CR_SSD_Pos           (17U)
#define TSC_CR_SSD_Msk           (0x7FU << TSC_CR_SSD_Pos)
#define TSC_CR_SSD               TSC_CR_SSD_Msk
#define TSC_CR_SSD_0             (0x01U << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_1             (0x02U << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_2             (0x04U << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_3             (0x08U << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_4             (0x10U << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_5             (0x20U << TSC_CR_SSD_Pos)
#define TSC_CR_SSD_6             (0x40U << TSC_CR_SSD_Pos)

#define TSC_CR_CTPL_Pos          (24U)
#define TSC_CR_CTPL_Msk          (0xFU << TSC_CR_CTPL_Pos)
#define TSC_CR_CTPL              TSC_CR_CTPL_Msk
#define TSC_CR_CTPL_0            (0x1U << TSC_CR_CTPL_Pos)
#define TSC_CR_CTPL_1            (0x2U << TSC_CR_CTPL_Pos)
#define TSC_CR_CTPL_2            (0x4U << TSC_CR_CTPL_Pos)
#define TSC_CR_CTPL_3            (0x8U << TSC_CR_CTPL_Pos)

#define TSC_CR_CTPH_Pos          (28U)
#define TSC_CR_CTPH_Msk          (0xFU << TSC_CR_CTPH_Pos)
#define TSC_CR_CTPH              TSC_CR_CTPH_Msk
#define TSC_CR_CTPH_0            (0x1U << TSC_CR_CTPH_Pos)
#define TSC_CR_CTPH_1            (0x2U << TSC_CR_CTPH_Pos)
#define TSC_CR_CTPH_2            (0x4U << TSC_CR_CTPH_Pos)
#define TSC_CR_CTPH_3            (0x8U << TSC_CR_CTPH_Pos)


#define TSC_IER_EOAIE_Pos        (0U)
#define TSC_IER_EOAIE_Msk        (0x1U << TSC_IER_EOAIE_Pos)
#define TSC_IER_EOAIE            TSC_IER_EOAIE_Msk
#define TSC_IER_MCEIE_Pos        (1U)
#define TSC_IER_MCEIE_Msk        (0x1U << TSC_IER_MCEIE_Pos)
#define TSC_IER_MCEIE            TSC_IER_MCEIE_Msk


#define TSC_ICR_EOAIC_Pos        (0U)
#define TSC_ICR_EOAIC_Msk        (0x1U << TSC_ICR_EOAIC_Pos)
#define TSC_ICR_EOAIC            TSC_ICR_EOAIC_Msk
#define TSC_ICR_MCEIC_Pos        (1U)
#define TSC_ICR_MCEIC_Msk        (0x1U << TSC_ICR_MCEIC_Pos)
#define TSC_ICR_MCEIC            TSC_ICR_MCEIC_Msk


#define TSC_ISR_EOAF_Pos         (0U)
#define TSC_ISR_EOAF_Msk         (0x1U << TSC_ISR_EOAF_Pos)
#define TSC_ISR_EOAF             TSC_ISR_EOAF_Msk
#define TSC_ISR_MCEF_Pos         (1U)
#define TSC_ISR_MCEF_Msk         (0x1U << TSC_ISR_MCEF_Pos)
#define TSC_ISR_MCEF             TSC_ISR_MCEF_Msk


#define TSC_IOHCR_G1_IO1_Pos     (0U)
#define TSC_IOHCR_G1_IO1_Msk     (0x1U << TSC_IOHCR_G1_IO1_Pos)
#define TSC_IOHCR_G1_IO1         TSC_IOHCR_G1_IO1_Msk
#define TSC_IOHCR_G1_IO2_Pos     (1U)
#define TSC_IOHCR_G1_IO2_Msk     (0x1U << TSC_IOHCR_G1_IO2_Pos)
#define TSC_IOHCR_G1_IO2         TSC_IOHCR_G1_IO2_Msk
#define TSC_IOHCR_G1_IO3_Pos     (2U)
#define TSC_IOHCR_G1_IO3_Msk     (0x1U << TSC_IOHCR_G1_IO3_Pos)
#define TSC_IOHCR_G1_IO3         TSC_IOHCR_G1_IO3_Msk
#define TSC_IOHCR_G1_IO4_Pos     (3U)
#define TSC_IOHCR_G1_IO4_Msk     (0x1U << TSC_IOHCR_G1_IO4_Pos)
#define TSC_IOHCR_G1_IO4         TSC_IOHCR_G1_IO4_Msk
#define TSC_IOHCR_G2_IO1_Pos     (4U)
#define TSC_IOHCR_G2_IO1_Msk     (0x1U << TSC_IOHCR_G2_IO1_Pos)
#define TSC_IOHCR_G2_IO1         TSC_IOHCR_G2_IO1_Msk
#define TSC_IOHCR_G2_IO2_Pos     (5U)
#define TSC_IOHCR_G2_IO2_Msk     (0x1U << TSC_IOHCR_G2_IO2_Pos)
#define TSC_IOHCR_G2_IO2         TSC_IOHCR_G2_IO2_Msk
#define TSC_IOHCR_G2_IO3_Pos     (6U)
#define TSC_IOHCR_G2_IO3_Msk     (0x1U << TSC_IOHCR_G2_IO3_Pos)
#define TSC_IOHCR_G2_IO3         TSC_IOHCR_G2_IO3_Msk
#define TSC_IOHCR_G2_IO4_Pos     (7U)
#define TSC_IOHCR_G2_IO4_Msk     (0x1U << TSC_IOHCR_G2_IO4_Pos)
#define TSC_IOHCR_G2_IO4         TSC_IOHCR_G2_IO4_Msk
#define TSC_IOHCR_G3_IO1_Pos     (8U)
#define TSC_IOHCR_G3_IO1_Msk     (0x1U << TSC_IOHCR_G3_IO1_Pos)
#define TSC_IOHCR_G3_IO1         TSC_IOHCR_G3_IO1_Msk
#define TSC_IOHCR_G3_IO2_Pos     (9U)
#define TSC_IOHCR_G3_IO2_Msk     (0x1U << TSC_IOHCR_G3_IO2_Pos)
#define TSC_IOHCR_G3_IO2         TSC_IOHCR_G3_IO2_Msk
#define TSC_IOHCR_G3_IO3_Pos     (10U)
#define TSC_IOHCR_G3_IO3_Msk     (0x1U << TSC_IOHCR_G3_IO3_Pos)
#define TSC_IOHCR_G3_IO3         TSC_IOHCR_G3_IO3_Msk
#define TSC_IOHCR_G3_IO4_Pos     (11U)
#define TSC_IOHCR_G3_IO4_Msk     (0x1U << TSC_IOHCR_G3_IO4_Pos)
#define TSC_IOHCR_G3_IO4         TSC_IOHCR_G3_IO4_Msk
#define TSC_IOHCR_G4_IO1_Pos     (12U)
#define TSC_IOHCR_G4_IO1_Msk     (0x1U << TSC_IOHCR_G4_IO1_Pos)
#define TSC_IOHCR_G4_IO1         TSC_IOHCR_G4_IO1_Msk
#define TSC_IOHCR_G4_IO2_Pos     (13U)
#define TSC_IOHCR_G4_IO2_Msk     (0x1U << TSC_IOHCR_G4_IO2_Pos)
#define TSC_IOHCR_G4_IO2         TSC_IOHCR_G4_IO2_Msk
#define TSC_IOHCR_G4_IO3_Pos     (14U)
#define TSC_IOHCR_G4_IO3_Msk     (0x1U << TSC_IOHCR_G4_IO3_Pos)
#define TSC_IOHCR_G4_IO3         TSC_IOHCR_G4_IO3_Msk
#define TSC_IOHCR_G4_IO4_Pos     (15U)
#define TSC_IOHCR_G4_IO4_Msk     (0x1U << TSC_IOHCR_G4_IO4_Pos)
#define TSC_IOHCR_G4_IO4         TSC_IOHCR_G4_IO4_Msk
#define TSC_IOHCR_G5_IO1_Pos     (16U)
#define TSC_IOHCR_G5_IO1_Msk     (0x1U << TSC_IOHCR_G5_IO1_Pos)
#define TSC_IOHCR_G5_IO1         TSC_IOHCR_G5_IO1_Msk
#define TSC_IOHCR_G5_IO2_Pos     (17U)
#define TSC_IOHCR_G5_IO2_Msk     (0x1U << TSC_IOHCR_G5_IO2_Pos)
#define TSC_IOHCR_G5_IO2         TSC_IOHCR_G5_IO2_Msk
#define TSC_IOHCR_G5_IO3_Pos     (18U)
#define TSC_IOHCR_G5_IO3_Msk     (0x1U << TSC_IOHCR_G5_IO3_Pos)
#define TSC_IOHCR_G5_IO3         TSC_IOHCR_G5_IO3_Msk
#define TSC_IOHCR_G5_IO4_Pos     (19U)
#define TSC_IOHCR_G5_IO4_Msk     (0x1U << TSC_IOHCR_G5_IO4_Pos)
#define TSC_IOHCR_G5_IO4         TSC_IOHCR_G5_IO4_Msk
#define TSC_IOHCR_G6_IO1_Pos     (20U)
#define TSC_IOHCR_G6_IO1_Msk     (0x1U << TSC_IOHCR_G6_IO1_Pos)
#define TSC_IOHCR_G6_IO1         TSC_IOHCR_G6_IO1_Msk
#define TSC_IOHCR_G6_IO2_Pos     (21U)
#define TSC_IOHCR_G6_IO2_Msk     (0x1U << TSC_IOHCR_G6_IO2_Pos)
#define TSC_IOHCR_G6_IO2         TSC_IOHCR_G6_IO2_Msk
#define TSC_IOHCR_G6_IO3_Pos     (22U)
#define TSC_IOHCR_G6_IO3_Msk     (0x1U << TSC_IOHCR_G6_IO3_Pos)
#define TSC_IOHCR_G6_IO3         TSC_IOHCR_G6_IO3_Msk
#define TSC_IOHCR_G6_IO4_Pos     (23U)
#define TSC_IOHCR_G6_IO4_Msk     (0x1U << TSC_IOHCR_G6_IO4_Pos)
#define TSC_IOHCR_G6_IO4         TSC_IOHCR_G6_IO4_Msk
#define TSC_IOHCR_G7_IO1_Pos     (24U)
#define TSC_IOHCR_G7_IO1_Msk     (0x1U << TSC_IOHCR_G7_IO1_Pos)
#define TSC_IOHCR_G7_IO1         TSC_IOHCR_G7_IO1_Msk
#define TSC_IOHCR_G7_IO2_Pos     (25U)
#define TSC_IOHCR_G7_IO2_Msk     (0x1U << TSC_IOHCR_G7_IO2_Pos)
#define TSC_IOHCR_G7_IO2         TSC_IOHCR_G7_IO2_Msk
#define TSC_IOHCR_G7_IO3_Pos     (26U)
#define TSC_IOHCR_G7_IO3_Msk     (0x1U << TSC_IOHCR_G7_IO3_Pos)
#define TSC_IOHCR_G7_IO3         TSC_IOHCR_G7_IO3_Msk
#define TSC_IOHCR_G7_IO4_Pos     (27U)
#define TSC_IOHCR_G7_IO4_Msk     (0x1U << TSC_IOHCR_G7_IO4_Pos)
#define TSC_IOHCR_G7_IO4         TSC_IOHCR_G7_IO4_Msk
#define TSC_IOHCR_G8_IO1_Pos     (28U)
#define TSC_IOHCR_G8_IO1_Msk     (0x1U << TSC_IOHCR_G8_IO1_Pos)
#define TSC_IOHCR_G8_IO1         TSC_IOHCR_G8_IO1_Msk
#define TSC_IOHCR_G8_IO2_Pos     (29U)
#define TSC_IOHCR_G8_IO2_Msk     (0x1U << TSC_IOHCR_G8_IO2_Pos)
#define TSC_IOHCR_G8_IO2         TSC_IOHCR_G8_IO2_Msk
#define TSC_IOHCR_G8_IO3_Pos     (30U)
#define TSC_IOHCR_G8_IO3_Msk     (0x1U << TSC_IOHCR_G8_IO3_Pos)
#define TSC_IOHCR_G8_IO3         TSC_IOHCR_G8_IO3_Msk
#define TSC_IOHCR_G8_IO4_Pos     (31U)
#define TSC_IOHCR_G8_IO4_Msk     (0x1U << TSC_IOHCR_G8_IO4_Pos)
#define TSC_IOHCR_G8_IO4         TSC_IOHCR_G8_IO4_Msk


#define TSC_IOASCR_G1_IO1_Pos    (0U)
#define TSC_IOASCR_G1_IO1_Msk    (0x1U << TSC_IOASCR_G1_IO1_Pos)
#define TSC_IOASCR_G1_IO1        TSC_IOASCR_G1_IO1_Msk
#define TSC_IOASCR_G1_IO2_Pos    (1U)
#define TSC_IOASCR_G1_IO2_Msk    (0x1U << TSC_IOASCR_G1_IO2_Pos)
#define TSC_IOASCR_G1_IO2        TSC_IOASCR_G1_IO2_Msk
#define TSC_IOASCR_G1_IO3_Pos    (2U)
#define TSC_IOASCR_G1_IO3_Msk    (0x1U << TSC_IOASCR_G1_IO3_Pos)
#define TSC_IOASCR_G1_IO3        TSC_IOASCR_G1_IO3_Msk
#define TSC_IOASCR_G1_IO4_Pos    (3U)
#define TSC_IOASCR_G1_IO4_Msk    (0x1U << TSC_IOASCR_G1_IO4_Pos)
#define TSC_IOASCR_G1_IO4        TSC_IOASCR_G1_IO4_Msk
#define TSC_IOASCR_G2_IO1_Pos    (4U)
#define TSC_IOASCR_G2_IO1_Msk    (0x1U << TSC_IOASCR_G2_IO1_Pos)
#define TSC_IOASCR_G2_IO1        TSC_IOASCR_G2_IO1_Msk
#define TSC_IOASCR_G2_IO2_Pos    (5U)
#define TSC_IOASCR_G2_IO2_Msk    (0x1U << TSC_IOASCR_G2_IO2_Pos)
#define TSC_IOASCR_G2_IO2        TSC_IOASCR_G2_IO2_Msk
#define TSC_IOASCR_G2_IO3_Pos    (6U)
#define TSC_IOASCR_G2_IO3_Msk    (0x1U << TSC_IOASCR_G2_IO3_Pos)
#define TSC_IOASCR_G2_IO3        TSC_IOASCR_G2_IO3_Msk
#define TSC_IOASCR_G2_IO4_Pos    (7U)
#define TSC_IOASCR_G2_IO4_Msk    (0x1U << TSC_IOASCR_G2_IO4_Pos)
#define TSC_IOASCR_G2_IO4        TSC_IOASCR_G2_IO4_Msk
#define TSC_IOASCR_G3_IO1_Pos    (8U)
#define TSC_IOASCR_G3_IO1_Msk    (0x1U << TSC_IOASCR_G3_IO1_Pos)
#define TSC_IOASCR_G3_IO1        TSC_IOASCR_G3_IO1_Msk
#define TSC_IOASCR_G3_IO2_Pos    (9U)
#define TSC_IOASCR_G3_IO2_Msk    (0x1U << TSC_IOASCR_G3_IO2_Pos)
#define TSC_IOASCR_G3_IO2        TSC_IOASCR_G3_IO2_Msk
#define TSC_IOASCR_G3_IO3_Pos    (10U)
#define TSC_IOASCR_G3_IO3_Msk    (0x1U << TSC_IOASCR_G3_IO3_Pos)
#define TSC_IOASCR_G3_IO3        TSC_IOASCR_G3_IO3_Msk
#define TSC_IOASCR_G3_IO4_Pos    (11U)
#define TSC_IOASCR_G3_IO4_Msk    (0x1U << TSC_IOASCR_G3_IO4_Pos)
#define TSC_IOASCR_G3_IO4        TSC_IOASCR_G3_IO4_Msk
#define TSC_IOASCR_G4_IO1_Pos    (12U)
#define TSC_IOASCR_G4_IO1_Msk    (0x1U << TSC_IOASCR_G4_IO1_Pos)
#define TSC_IOASCR_G4_IO1        TSC_IOASCR_G4_IO1_Msk
#define TSC_IOASCR_G4_IO2_Pos    (13U)
#define TSC_IOASCR_G4_IO2_Msk    (0x1U << TSC_IOASCR_G4_IO2_Pos)
#define TSC_IOASCR_G4_IO2        TSC_IOASCR_G4_IO2_Msk
#define TSC_IOASCR_G4_IO3_Pos    (14U)
#define TSC_IOASCR_G4_IO3_Msk    (0x1U << TSC_IOASCR_G4_IO3_Pos)
#define TSC_IOASCR_G4_IO3        TSC_IOASCR_G4_IO3_Msk
#define TSC_IOASCR_G4_IO4_Pos    (15U)
#define TSC_IOASCR_G4_IO4_Msk    (0x1U << TSC_IOASCR_G4_IO4_Pos)
#define TSC_IOASCR_G4_IO4        TSC_IOASCR_G4_IO4_Msk
#define TSC_IOASCR_G5_IO1_Pos    (16U)
#define TSC_IOASCR_G5_IO1_Msk    (0x1U << TSC_IOASCR_G5_IO1_Pos)
#define TSC_IOASCR_G5_IO1        TSC_IOASCR_G5_IO1_Msk
#define TSC_IOASCR_G5_IO2_Pos    (17U)
#define TSC_IOASCR_G5_IO2_Msk    (0x1U << TSC_IOASCR_G5_IO2_Pos)
#define TSC_IOASCR_G5_IO2        TSC_IOASCR_G5_IO2_Msk
#define TSC_IOASCR_G5_IO3_Pos    (18U)
#define TSC_IOASCR_G5_IO3_Msk    (0x1U << TSC_IOASCR_G5_IO3_Pos)
#define TSC_IOASCR_G5_IO3        TSC_IOASCR_G5_IO3_Msk
#define TSC_IOASCR_G5_IO4_Pos    (19U)
#define TSC_IOASCR_G5_IO4_Msk    (0x1U << TSC_IOASCR_G5_IO4_Pos)
#define TSC_IOASCR_G5_IO4        TSC_IOASCR_G5_IO4_Msk
#define TSC_IOASCR_G6_IO1_Pos    (20U)
#define TSC_IOASCR_G6_IO1_Msk    (0x1U << TSC_IOASCR_G6_IO1_Pos)
#define TSC_IOASCR_G6_IO1        TSC_IOASCR_G6_IO1_Msk
#define TSC_IOASCR_G6_IO2_Pos    (21U)
#define TSC_IOASCR_G6_IO2_Msk    (0x1U << TSC_IOASCR_G6_IO2_Pos)
#define TSC_IOASCR_G6_IO2        TSC_IOASCR_G6_IO2_Msk
#define TSC_IOASCR_G6_IO3_Pos    (22U)
#define TSC_IOASCR_G6_IO3_Msk    (0x1U << TSC_IOASCR_G6_IO3_Pos)
#define TSC_IOASCR_G6_IO3        TSC_IOASCR_G6_IO3_Msk
#define TSC_IOASCR_G6_IO4_Pos    (23U)
#define TSC_IOASCR_G6_IO4_Msk    (0x1U << TSC_IOASCR_G6_IO4_Pos)
#define TSC_IOASCR_G6_IO4        TSC_IOASCR_G6_IO4_Msk
#define TSC_IOASCR_G7_IO1_Pos    (24U)
#define TSC_IOASCR_G7_IO1_Msk    (0x1U << TSC_IOASCR_G7_IO1_Pos)
#define TSC_IOASCR_G7_IO1        TSC_IOASCR_G7_IO1_Msk
#define TSC_IOASCR_G7_IO2_Pos    (25U)
#define TSC_IOASCR_G7_IO2_Msk    (0x1U << TSC_IOASCR_G7_IO2_Pos)
#define TSC_IOASCR_G7_IO2        TSC_IOASCR_G7_IO2_Msk
#define TSC_IOASCR_G7_IO3_Pos    (26U)
#define TSC_IOASCR_G7_IO3_Msk    (0x1U << TSC_IOASCR_G7_IO3_Pos)
#define TSC_IOASCR_G7_IO3        TSC_IOASCR_G7_IO3_Msk
#define TSC_IOASCR_G7_IO4_Pos    (27U)
#define TSC_IOASCR_G7_IO4_Msk    (0x1U << TSC_IOASCR_G7_IO4_Pos)
#define TSC_IOASCR_G7_IO4        TSC_IOASCR_G7_IO4_Msk
#define TSC_IOASCR_G8_IO1_Pos    (28U)
#define TSC_IOASCR_G8_IO1_Msk    (0x1U << TSC_IOASCR_G8_IO1_Pos)
#define TSC_IOASCR_G8_IO1        TSC_IOASCR_G8_IO1_Msk
#define TSC_IOASCR_G8_IO2_Pos    (29U)
#define TSC_IOASCR_G8_IO2_Msk    (0x1U << TSC_IOASCR_G8_IO2_Pos)
#define TSC_IOASCR_G8_IO2        TSC_IOASCR_G8_IO2_Msk
#define TSC_IOASCR_G8_IO3_Pos    (30U)
#define TSC_IOASCR_G8_IO3_Msk    (0x1U << TSC_IOASCR_G8_IO3_Pos)
#define TSC_IOASCR_G8_IO3        TSC_IOASCR_G8_IO3_Msk
#define TSC_IOASCR_G8_IO4_Pos    (31U)
#define TSC_IOASCR_G8_IO4_Msk    (0x1U << TSC_IOASCR_G8_IO4_Pos)
#define TSC_IOASCR_G8_IO4        TSC_IOASCR_G8_IO4_Msk


#define TSC_IOSCR_G1_IO1_Pos     (0U)
#define TSC_IOSCR_G1_IO1_Msk     (0x1U << TSC_IOSCR_G1_IO1_Pos)
#define TSC_IOSCR_G1_IO1         TSC_IOSCR_G1_IO1_Msk
#define TSC_IOSCR_G1_IO2_Pos     (1U)
#define TSC_IOSCR_G1_IO2_Msk     (0x1U << TSC_IOSCR_G1_IO2_Pos)
#define TSC_IOSCR_G1_IO2         TSC_IOSCR_G1_IO2_Msk
#define TSC_IOSCR_G1_IO3_Pos     (2U)
#define TSC_IOSCR_G1_IO3_Msk     (0x1U << TSC_IOSCR_G1_IO3_Pos)
#define TSC_IOSCR_G1_IO3         TSC_IOSCR_G1_IO3_Msk
#define TSC_IOSCR_G1_IO4_Pos     (3U)
#define TSC_IOSCR_G1_IO4_Msk     (0x1U << TSC_IOSCR_G1_IO4_Pos)
#define TSC_IOSCR_G1_IO4         TSC_IOSCR_G1_IO4_Msk
#define TSC_IOSCR_G2_IO1_Pos     (4U)
#define TSC_IOSCR_G2_IO1_Msk     (0x1U << TSC_IOSCR_G2_IO1_Pos)
#define TSC_IOSCR_G2_IO1         TSC_IOSCR_G2_IO1_Msk
#define TSC_IOSCR_G2_IO2_Pos     (5U)
#define TSC_IOSCR_G2_IO2_Msk     (0x1U << TSC_IOSCR_G2_IO2_Pos)
#define TSC_IOSCR_G2_IO2         TSC_IOSCR_G2_IO2_Msk
#define TSC_IOSCR_G2_IO3_Pos     (6U)
#define TSC_IOSCR_G2_IO3_Msk     (0x1U << TSC_IOSCR_G2_IO3_Pos)
#define TSC_IOSCR_G2_IO3         TSC_IOSCR_G2_IO3_Msk
#define TSC_IOSCR_G2_IO4_Pos     (7U)
#define TSC_IOSCR_G2_IO4_Msk     (0x1U << TSC_IOSCR_G2_IO4_Pos)
#define TSC_IOSCR_G2_IO4         TSC_IOSCR_G2_IO4_Msk
#define TSC_IOSCR_G3_IO1_Pos     (8U)
#define TSC_IOSCR_G3_IO1_Msk     (0x1U << TSC_IOSCR_G3_IO1_Pos)
#define TSC_IOSCR_G3_IO1         TSC_IOSCR_G3_IO1_Msk
#define TSC_IOSCR_G3_IO2_Pos     (9U)
#define TSC_IOSCR_G3_IO2_Msk     (0x1U << TSC_IOSCR_G3_IO2_Pos)
#define TSC_IOSCR_G3_IO2         TSC_IOSCR_G3_IO2_Msk
#define TSC_IOSCR_G3_IO3_Pos     (10U)
#define TSC_IOSCR_G3_IO3_Msk     (0x1U << TSC_IOSCR_G3_IO3_Pos)
#define TSC_IOSCR_G3_IO3         TSC_IOSCR_G3_IO3_Msk
#define TSC_IOSCR_G3_IO4_Pos     (11U)
#define TSC_IOSCR_G3_IO4_Msk     (0x1U << TSC_IOSCR_G3_IO4_Pos)
#define TSC_IOSCR_G3_IO4         TSC_IOSCR_G3_IO4_Msk
#define TSC_IOSCR_G4_IO1_Pos     (12U)
#define TSC_IOSCR_G4_IO1_Msk     (0x1U << TSC_IOSCR_G4_IO1_Pos)
#define TSC_IOSCR_G4_IO1         TSC_IOSCR_G4_IO1_Msk
#define TSC_IOSCR_G4_IO2_Pos     (13U)
#define TSC_IOSCR_G4_IO2_Msk     (0x1U << TSC_IOSCR_G4_IO2_Pos)
#define TSC_IOSCR_G4_IO2         TSC_IOSCR_G4_IO2_Msk
#define TSC_IOSCR_G4_IO3_Pos     (14U)
#define TSC_IOSCR_G4_IO3_Msk     (0x1U << TSC_IOSCR_G4_IO3_Pos)
#define TSC_IOSCR_G4_IO3         TSC_IOSCR_G4_IO3_Msk
#define TSC_IOSCR_G4_IO4_Pos     (15U)
#define TSC_IOSCR_G4_IO4_Msk     (0x1U << TSC_IOSCR_G4_IO4_Pos)
#define TSC_IOSCR_G4_IO4         TSC_IOSCR_G4_IO4_Msk
#define TSC_IOSCR_G5_IO1_Pos     (16U)
#define TSC_IOSCR_G5_IO1_Msk     (0x1U << TSC_IOSCR_G5_IO1_Pos)
#define TSC_IOSCR_G5_IO1         TSC_IOSCR_G5_IO1_Msk
#define TSC_IOSCR_G5_IO2_Pos     (17U)
#define TSC_IOSCR_G5_IO2_Msk     (0x1U << TSC_IOSCR_G5_IO2_Pos)
#define TSC_IOSCR_G5_IO2         TSC_IOSCR_G5_IO2_Msk
#define TSC_IOSCR_G5_IO3_Pos     (18U)
#define TSC_IOSCR_G5_IO3_Msk     (0x1U << TSC_IOSCR_G5_IO3_Pos)
#define TSC_IOSCR_G5_IO3         TSC_IOSCR_G5_IO3_Msk
#define TSC_IOSCR_G5_IO4_Pos     (19U)
#define TSC_IOSCR_G5_IO4_Msk     (0x1U << TSC_IOSCR_G5_IO4_Pos)
#define TSC_IOSCR_G5_IO4         TSC_IOSCR_G5_IO4_Msk
#define TSC_IOSCR_G6_IO1_Pos     (20U)
#define TSC_IOSCR_G6_IO1_Msk     (0x1U << TSC_IOSCR_G6_IO1_Pos)
#define TSC_IOSCR_G6_IO1         TSC_IOSCR_G6_IO1_Msk
#define TSC_IOSCR_G6_IO2_Pos     (21U)
#define TSC_IOSCR_G6_IO2_Msk     (0x1U << TSC_IOSCR_G6_IO2_Pos)
#define TSC_IOSCR_G6_IO2         TSC_IOSCR_G6_IO2_Msk
#define TSC_IOSCR_G6_IO3_Pos     (22U)
#define TSC_IOSCR_G6_IO3_Msk     (0x1U << TSC_IOSCR_G6_IO3_Pos)
#define TSC_IOSCR_G6_IO3         TSC_IOSCR_G6_IO3_Msk
#define TSC_IOSCR_G6_IO4_Pos     (23U)
#define TSC_IOSCR_G6_IO4_Msk     (0x1U << TSC_IOSCR_G6_IO4_Pos)
#define TSC_IOSCR_G6_IO4         TSC_IOSCR_G6_IO4_Msk
#define TSC_IOSCR_G7_IO1_Pos     (24U)
#define TSC_IOSCR_G7_IO1_Msk     (0x1U << TSC_IOSCR_G7_IO1_Pos)
#define TSC_IOSCR_G7_IO1         TSC_IOSCR_G7_IO1_Msk
#define TSC_IOSCR_G7_IO2_Pos     (25U)
#define TSC_IOSCR_G7_IO2_Msk     (0x1U << TSC_IOSCR_G7_IO2_Pos)
#define TSC_IOSCR_G7_IO2         TSC_IOSCR_G7_IO2_Msk
#define TSC_IOSCR_G7_IO3_Pos     (26U)
#define TSC_IOSCR_G7_IO3_Msk     (0x1U << TSC_IOSCR_G7_IO3_Pos)
#define TSC_IOSCR_G7_IO3         TSC_IOSCR_G7_IO3_Msk
#define TSC_IOSCR_G7_IO4_Pos     (27U)
#define TSC_IOSCR_G7_IO4_Msk     (0x1U << TSC_IOSCR_G7_IO4_Pos)
#define TSC_IOSCR_G7_IO4         TSC_IOSCR_G7_IO4_Msk
#define TSC_IOSCR_G8_IO1_Pos     (28U)
#define TSC_IOSCR_G8_IO1_Msk     (0x1U << TSC_IOSCR_G8_IO1_Pos)
#define TSC_IOSCR_G8_IO1         TSC_IOSCR_G8_IO1_Msk
#define TSC_IOSCR_G8_IO2_Pos     (29U)
#define TSC_IOSCR_G8_IO2_Msk     (0x1U << TSC_IOSCR_G8_IO2_Pos)
#define TSC_IOSCR_G8_IO2         TSC_IOSCR_G8_IO2_Msk
#define TSC_IOSCR_G8_IO3_Pos     (30U)
#define TSC_IOSCR_G8_IO3_Msk     (0x1U << TSC_IOSCR_G8_IO3_Pos)
#define TSC_IOSCR_G8_IO3         TSC_IOSCR_G8_IO3_Msk
#define TSC_IOSCR_G8_IO4_Pos     (31U)
#define TSC_IOSCR_G8_IO4_Msk     (0x1U << TSC_IOSCR_G8_IO4_Pos)
#define TSC_IOSCR_G8_IO4         TSC_IOSCR_G8_IO4_Msk


#define TSC_IOCCR_G1_IO1_Pos     (0U)
#define TSC_IOCCR_G1_IO1_Msk     (0x1U << TSC_IOCCR_G1_IO1_Pos)
#define TSC_IOCCR_G1_IO1         TSC_IOCCR_G1_IO1_Msk
#define TSC_IOCCR_G1_IO2_Pos     (1U)
#define TSC_IOCCR_G1_IO2_Msk     (0x1U << TSC_IOCCR_G1_IO2_Pos)
#define TSC_IOCCR_G1_IO2         TSC_IOCCR_G1_IO2_Msk
#define TSC_IOCCR_G1_IO3_Pos     (2U)
#define TSC_IOCCR_G1_IO3_Msk     (0x1U << TSC_IOCCR_G1_IO3_Pos)
#define TSC_IOCCR_G1_IO3         TSC_IOCCR_G1_IO3_Msk
#define TSC_IOCCR_G1_IO4_Pos     (3U)
#define TSC_IOCCR_G1_IO4_Msk     (0x1U << TSC_IOCCR_G1_IO4_Pos)
#define TSC_IOCCR_G1_IO4         TSC_IOCCR_G1_IO4_Msk
#define TSC_IOCCR_G2_IO1_Pos     (4U)
#define TSC_IOCCR_G2_IO1_Msk     (0x1U << TSC_IOCCR_G2_IO1_Pos)
#define TSC_IOCCR_G2_IO1         TSC_IOCCR_G2_IO1_Msk
#define TSC_IOCCR_G2_IO2_Pos     (5U)
#define TSC_IOCCR_G2_IO2_Msk     (0x1U << TSC_IOCCR_G2_IO2_Pos)
#define TSC_IOCCR_G2_IO2         TSC_IOCCR_G2_IO2_Msk
#define TSC_IOCCR_G2_IO3_Pos     (6U)
#define TSC_IOCCR_G2_IO3_Msk     (0x1U << TSC_IOCCR_G2_IO3_Pos)
#define TSC_IOCCR_G2_IO3         TSC_IOCCR_G2_IO3_Msk
#define TSC_IOCCR_G2_IO4_Pos     (7U)
#define TSC_IOCCR_G2_IO4_Msk     (0x1U << TSC_IOCCR_G2_IO4_Pos)
#define TSC_IOCCR_G2_IO4         TSC_IOCCR_G2_IO4_Msk
#define TSC_IOCCR_G3_IO1_Pos     (8U)
#define TSC_IOCCR_G3_IO1_Msk     (0x1U << TSC_IOCCR_G3_IO1_Pos)
#define TSC_IOCCR_G3_IO1         TSC_IOCCR_G3_IO1_Msk
#define TSC_IOCCR_G3_IO2_Pos     (9U)
#define TSC_IOCCR_G3_IO2_Msk     (0x1U << TSC_IOCCR_G3_IO2_Pos)
#define TSC_IOCCR_G3_IO2         TSC_IOCCR_G3_IO2_Msk
#define TSC_IOCCR_G3_IO3_Pos     (10U)
#define TSC_IOCCR_G3_IO3_Msk     (0x1U << TSC_IOCCR_G3_IO3_Pos)
#define TSC_IOCCR_G3_IO3         TSC_IOCCR_G3_IO3_Msk
#define TSC_IOCCR_G3_IO4_Pos     (11U)
#define TSC_IOCCR_G3_IO4_Msk     (0x1U << TSC_IOCCR_G3_IO4_Pos)
#define TSC_IOCCR_G3_IO4         TSC_IOCCR_G3_IO4_Msk
#define TSC_IOCCR_G4_IO1_Pos     (12U)
#define TSC_IOCCR_G4_IO1_Msk     (0x1U << TSC_IOCCR_G4_IO1_Pos)
#define TSC_IOCCR_G4_IO1         TSC_IOCCR_G4_IO1_Msk
#define TSC_IOCCR_G4_IO2_Pos     (13U)
#define TSC_IOCCR_G4_IO2_Msk     (0x1U << TSC_IOCCR_G4_IO2_Pos)
#define TSC_IOCCR_G4_IO2         TSC_IOCCR_G4_IO2_Msk
#define TSC_IOCCR_G4_IO3_Pos     (14U)
#define TSC_IOCCR_G4_IO3_Msk     (0x1U << TSC_IOCCR_G4_IO3_Pos)
#define TSC_IOCCR_G4_IO3         TSC_IOCCR_G4_IO3_Msk
#define TSC_IOCCR_G4_IO4_Pos     (15U)
#define TSC_IOCCR_G4_IO4_Msk     (0x1U << TSC_IOCCR_G4_IO4_Pos)
#define TSC_IOCCR_G4_IO4         TSC_IOCCR_G4_IO4_Msk
#define TSC_IOCCR_G5_IO1_Pos     (16U)
#define TSC_IOCCR_G5_IO1_Msk     (0x1U << TSC_IOCCR_G5_IO1_Pos)
#define TSC_IOCCR_G5_IO1         TSC_IOCCR_G5_IO1_Msk
#define TSC_IOCCR_G5_IO2_Pos     (17U)
#define TSC_IOCCR_G5_IO2_Msk     (0x1U << TSC_IOCCR_G5_IO2_Pos)
#define TSC_IOCCR_G5_IO2         TSC_IOCCR_G5_IO2_Msk
#define TSC_IOCCR_G5_IO3_Pos     (18U)
#define TSC_IOCCR_G5_IO3_Msk     (0x1U << TSC_IOCCR_G5_IO3_Pos)
#define TSC_IOCCR_G5_IO3         TSC_IOCCR_G5_IO3_Msk
#define TSC_IOCCR_G5_IO4_Pos     (19U)
#define TSC_IOCCR_G5_IO4_Msk     (0x1U << TSC_IOCCR_G5_IO4_Pos)
#define TSC_IOCCR_G5_IO4         TSC_IOCCR_G5_IO4_Msk
#define TSC_IOCCR_G6_IO1_Pos     (20U)
#define TSC_IOCCR_G6_IO1_Msk     (0x1U << TSC_IOCCR_G6_IO1_Pos)
#define TSC_IOCCR_G6_IO1         TSC_IOCCR_G6_IO1_Msk
#define TSC_IOCCR_G6_IO2_Pos     (21U)
#define TSC_IOCCR_G6_IO2_Msk     (0x1U << TSC_IOCCR_G6_IO2_Pos)
#define TSC_IOCCR_G6_IO2         TSC_IOCCR_G6_IO2_Msk
#define TSC_IOCCR_G6_IO3_Pos     (22U)
#define TSC_IOCCR_G6_IO3_Msk     (0x1U << TSC_IOCCR_G6_IO3_Pos)
#define TSC_IOCCR_G6_IO3         TSC_IOCCR_G6_IO3_Msk
#define TSC_IOCCR_G6_IO4_Pos     (23U)
#define TSC_IOCCR_G6_IO4_Msk     (0x1U << TSC_IOCCR_G6_IO4_Pos)
#define TSC_IOCCR_G6_IO4         TSC_IOCCR_G6_IO4_Msk
#define TSC_IOCCR_G7_IO1_Pos     (24U)
#define TSC_IOCCR_G7_IO1_Msk     (0x1U << TSC_IOCCR_G7_IO1_Pos)
#define TSC_IOCCR_G7_IO1         TSC_IOCCR_G7_IO1_Msk
#define TSC_IOCCR_G7_IO2_Pos     (25U)
#define TSC_IOCCR_G7_IO2_Msk     (0x1U << TSC_IOCCR_G7_IO2_Pos)
#define TSC_IOCCR_G7_IO2         TSC_IOCCR_G7_IO2_Msk
#define TSC_IOCCR_G7_IO3_Pos     (26U)
#define TSC_IOCCR_G7_IO3_Msk     (0x1U << TSC_IOCCR_G7_IO3_Pos)
#define TSC_IOCCR_G7_IO3         TSC_IOCCR_G7_IO3_Msk
#define TSC_IOCCR_G7_IO4_Pos     (27U)
#define TSC_IOCCR_G7_IO4_Msk     (0x1U << TSC_IOCCR_G7_IO4_Pos)
#define TSC_IOCCR_G7_IO4         TSC_IOCCR_G7_IO4_Msk
#define TSC_IOCCR_G8_IO1_Pos     (28U)
#define TSC_IOCCR_G8_IO1_Msk     (0x1U << TSC_IOCCR_G8_IO1_Pos)
#define TSC_IOCCR_G8_IO1         TSC_IOCCR_G8_IO1_Msk
#define TSC_IOCCR_G8_IO2_Pos     (29U)
#define TSC_IOCCR_G8_IO2_Msk     (0x1U << TSC_IOCCR_G8_IO2_Pos)
#define TSC_IOCCR_G8_IO2         TSC_IOCCR_G8_IO2_Msk
#define TSC_IOCCR_G8_IO3_Pos     (30U)
#define TSC_IOCCR_G8_IO3_Msk     (0x1U << TSC_IOCCR_G8_IO3_Pos)
#define TSC_IOCCR_G8_IO3         TSC_IOCCR_G8_IO3_Msk
#define TSC_IOCCR_G8_IO4_Pos     (31U)
#define TSC_IOCCR_G8_IO4_Msk     (0x1U << TSC_IOCCR_G8_IO4_Pos)
#define TSC_IOCCR_G8_IO4         TSC_IOCCR_G8_IO4_Msk


#define TSC_IOGCSR_G1E_Pos       (0U)
#define TSC_IOGCSR_G1E_Msk       (0x1U << TSC_IOGCSR_G1E_Pos)
#define TSC_IOGCSR_G1E           TSC_IOGCSR_G1E_Msk
#define TSC_IOGCSR_G2E_Pos       (1U)
#define TSC_IOGCSR_G2E_Msk       (0x1U << TSC_IOGCSR_G2E_Pos)
#define TSC_IOGCSR_G2E           TSC_IOGCSR_G2E_Msk
#define TSC_IOGCSR_G3E_Pos       (2U)
#define TSC_IOGCSR_G3E_Msk       (0x1U << TSC_IOGCSR_G3E_Pos)
#define TSC_IOGCSR_G3E           TSC_IOGCSR_G3E_Msk
#define TSC_IOGCSR_G4E_Pos       (3U)
#define TSC_IOGCSR_G4E_Msk       (0x1U << TSC_IOGCSR_G4E_Pos)
#define TSC_IOGCSR_G4E           TSC_IOGCSR_G4E_Msk
#define TSC_IOGCSR_G5E_Pos       (4U)
#define TSC_IOGCSR_G5E_Msk       (0x1U << TSC_IOGCSR_G5E_Pos)
#define TSC_IOGCSR_G5E           TSC_IOGCSR_G5E_Msk
#define TSC_IOGCSR_G6E_Pos       (5U)
#define TSC_IOGCSR_G6E_Msk       (0x1U << TSC_IOGCSR_G6E_Pos)
#define TSC_IOGCSR_G6E           TSC_IOGCSR_G6E_Msk
#define TSC_IOGCSR_G7E_Pos       (6U)
#define TSC_IOGCSR_G7E_Msk       (0x1U << TSC_IOGCSR_G7E_Pos)
#define TSC_IOGCSR_G7E           TSC_IOGCSR_G7E_Msk
#define TSC_IOGCSR_G8E_Pos       (7U)
#define TSC_IOGCSR_G8E_Msk       (0x1U << TSC_IOGCSR_G8E_Pos)
#define TSC_IOGCSR_G8E           TSC_IOGCSR_G8E_Msk
#define TSC_IOGCSR_G1S_Pos       (16U)
#define TSC_IOGCSR_G1S_Msk       (0x1U << TSC_IOGCSR_G1S_Pos)
#define TSC_IOGCSR_G1S           TSC_IOGCSR_G1S_Msk
#define TSC_IOGCSR_G2S_Pos       (17U)
#define TSC_IOGCSR_G2S_Msk       (0x1U << TSC_IOGCSR_G2S_Pos)
#define TSC_IOGCSR_G2S           TSC_IOGCSR_G2S_Msk
#define TSC_IOGCSR_G3S_Pos       (18U)
#define TSC_IOGCSR_G3S_Msk       (0x1U << TSC_IOGCSR_G3S_Pos)
#define TSC_IOGCSR_G3S           TSC_IOGCSR_G3S_Msk
#define TSC_IOGCSR_G4S_Pos       (19U)
#define TSC_IOGCSR_G4S_Msk       (0x1U << TSC_IOGCSR_G4S_Pos)
#define TSC_IOGCSR_G4S           TSC_IOGCSR_G4S_Msk
#define TSC_IOGCSR_G5S_Pos       (20U)
#define TSC_IOGCSR_G5S_Msk       (0x1U << TSC_IOGCSR_G5S_Pos)
#define TSC_IOGCSR_G5S           TSC_IOGCSR_G5S_Msk
#define TSC_IOGCSR_G6S_Pos       (21U)
#define TSC_IOGCSR_G6S_Msk       (0x1U << TSC_IOGCSR_G6S_Pos)
#define TSC_IOGCSR_G6S           TSC_IOGCSR_G6S_Msk
#define TSC_IOGCSR_G7S_Pos       (22U)
#define TSC_IOGCSR_G7S_Msk       (0x1U << TSC_IOGCSR_G7S_Pos)
#define TSC_IOGCSR_G7S           TSC_IOGCSR_G7S_Msk
#define TSC_IOGCSR_G8S_Pos       (23U)
#define TSC_IOGCSR_G8S_Msk       (0x1U << TSC_IOGCSR_G8S_Pos)
#define TSC_IOGCSR_G8S           TSC_IOGCSR_G8S_Msk


#define TSC_IOGXCR_CNT_Pos       (0U)
#define TSC_IOGXCR_CNT_Msk       (0x3FFFU << TSC_IOGXCR_CNT_Pos)
#define TSC_IOGXCR_CNT           TSC_IOGXCR_CNT_Msk












#define USART_7BITS_SUPPORT


#define USART_CR1_UE_Pos              (0U)
#define USART_CR1_UE_Msk              (0x1U << USART_CR1_UE_Pos)
#define USART_CR1_UE                  USART_CR1_UE_Msk
#define USART_CR1_UESM_Pos            (1U)
#define USART_CR1_UESM_Msk            (0x1U << USART_CR1_UESM_Pos)
#define USART_CR1_UESM                USART_CR1_UESM_Msk
#define USART_CR1_RE_Pos              (2U)
#define USART_CR1_RE_Msk              (0x1U << USART_CR1_RE_Pos)
#define USART_CR1_RE                  USART_CR1_RE_Msk
#define USART_CR1_TE_Pos              (3U)
#define USART_CR1_TE_Msk              (0x1U << USART_CR1_TE_Pos)
#define USART_CR1_TE                  USART_CR1_TE_Msk
#define USART_CR1_IDLEIE_Pos          (4U)
#define USART_CR1_IDLEIE_Msk          (0x1U << USART_CR1_IDLEIE_Pos)
#define USART_CR1_IDLEIE              USART_CR1_IDLEIE_Msk
#define USART_CR1_RXNEIE_Pos          (5U)
#define USART_CR1_RXNEIE_Msk          (0x1U << USART_CR1_RXNEIE_Pos)
#define USART_CR1_RXNEIE              USART_CR1_RXNEIE_Msk
#define USART_CR1_TCIE_Pos            (6U)
#define USART_CR1_TCIE_Msk            (0x1U << USART_CR1_TCIE_Pos)
#define USART_CR1_TCIE                USART_CR1_TCIE_Msk
#define USART_CR1_TXEIE_Pos           (7U)
#define USART_CR1_TXEIE_Msk           (0x1U << USART_CR1_TXEIE_Pos)
#define USART_CR1_TXEIE               USART_CR1_TXEIE_Msk
#define USART_CR1_PEIE_Pos            (8U)
#define USART_CR1_PEIE_Msk            (0x1U << USART_CR1_PEIE_Pos)
#define USART_CR1_PEIE                USART_CR1_PEIE_Msk
#define USART_CR1_PS_Pos              (9U)
#define USART_CR1_PS_Msk              (0x1U << USART_CR1_PS_Pos)
#define USART_CR1_PS                  USART_CR1_PS_Msk
#define USART_CR1_PCE_Pos             (10U)
#define USART_CR1_PCE_Msk             (0x1U << USART_CR1_PCE_Pos)
#define USART_CR1_PCE                 USART_CR1_PCE_Msk
#define USART_CR1_WAKE_Pos            (11U)
#define USART_CR1_WAKE_Msk            (0x1U << USART_CR1_WAKE_Pos)
#define USART_CR1_WAKE                USART_CR1_WAKE_Msk
#define USART_CR1_M0_Pos              (12U)
#define USART_CR1_M0_Msk              (0x1U << USART_CR1_M0_Pos)
#define USART_CR1_M0                  USART_CR1_M0_Msk
#define USART_CR1_MME_Pos             (13U)
#define USART_CR1_MME_Msk             (0x1U << USART_CR1_MME_Pos)
#define USART_CR1_MME                 USART_CR1_MME_Msk
#define USART_CR1_CMIE_Pos            (14U)
#define USART_CR1_CMIE_Msk            (0x1U << USART_CR1_CMIE_Pos)
#define USART_CR1_CMIE                USART_CR1_CMIE_Msk
#define USART_CR1_OVER8_Pos           (15U)
#define USART_CR1_OVER8_Msk           (0x1U << USART_CR1_OVER8_Pos)
#define USART_CR1_OVER8               USART_CR1_OVER8_Msk
#define USART_CR1_DEDT_Pos            (16U)
#define USART_CR1_DEDT_Msk            (0x1FU << USART_CR1_DEDT_Pos)
#define USART_CR1_DEDT                USART_CR1_DEDT_Msk
#define USART_CR1_DEDT_0              (0x01U << USART_CR1_DEDT_Pos)
#define USART_CR1_DEDT_1              (0x02U << USART_CR1_DEDT_Pos)
#define USART_CR1_DEDT_2              (0x04U << USART_CR1_DEDT_Pos)
#define USART_CR1_DEDT_3              (0x08U << USART_CR1_DEDT_Pos)
#define USART_CR1_DEDT_4              (0x10U << USART_CR1_DEDT_Pos)
#define USART_CR1_DEAT_Pos            (21U)
#define USART_CR1_DEAT_Msk            (0x1FU << USART_CR1_DEAT_Pos)
#define USART_CR1_DEAT                USART_CR1_DEAT_Msk
#define USART_CR1_DEAT_0              (0x01U << USART_CR1_DEAT_Pos)
#define USART_CR1_DEAT_1              (0x02U << USART_CR1_DEAT_Pos)
#define USART_CR1_DEAT_2              (0x04U << USART_CR1_DEAT_Pos)
#define USART_CR1_DEAT_3              (0x08U << USART_CR1_DEAT_Pos)
#define USART_CR1_DEAT_4              (0x10U << USART_CR1_DEAT_Pos)
#define USART_CR1_RTOIE_Pos           (26U)
#define USART_CR1_RTOIE_Msk           (0x1U << USART_CR1_RTOIE_Pos)
#define USART_CR1_RTOIE               USART_CR1_RTOIE_Msk
#define USART_CR1_EOBIE_Pos           (27U)
#define USART_CR1_EOBIE_Msk           (0x1U << USART_CR1_EOBIE_Pos)
#define USART_CR1_EOBIE               USART_CR1_EOBIE_Msk
#define USART_CR1_M1_Pos              (28U)
#define USART_CR1_M1_Msk              (0x1U << USART_CR1_M1_Pos)
#define USART_CR1_M1                  USART_CR1_M1_Msk
#define USART_CR1_M_Pos               (12U)
#define USART_CR1_M_Msk               (0x10001U << USART_CR1_M_Pos)
#define USART_CR1_M                   USART_CR1_M_Msk


#define USART_CR2_ADDM7_Pos           (4U)
#define USART_CR2_ADDM7_Msk           (0x1U << USART_CR2_ADDM7_Pos)
#define USART_CR2_ADDM7               USART_CR2_ADDM7_Msk
#define USART_CR2_LBDL_Pos            (5U)
#define USART_CR2_LBDL_Msk            (0x1U << USART_CR2_LBDL_Pos)
#define USART_CR2_LBDL                USART_CR2_LBDL_Msk
#define USART_CR2_LBDIE_Pos           (6U)
#define USART_CR2_LBDIE_Msk           (0x1U << USART_CR2_LBDIE_Pos)
#define USART_CR2_LBDIE               USART_CR2_LBDIE_Msk
#define USART_CR2_LBCL_Pos            (8U)
#define USART_CR2_LBCL_Msk            (0x1U << USART_CR2_LBCL_Pos)
#define USART_CR2_LBCL                USART_CR2_LBCL_Msk
#define USART_CR2_CPHA_Pos            (9U)
#define USART_CR2_CPHA_Msk            (0x1U << USART_CR2_CPHA_Pos)
#define USART_CR2_CPHA                USART_CR2_CPHA_Msk
#define USART_CR2_CPOL_Pos            (10U)
#define USART_CR2_CPOL_Msk            (0x1U << USART_CR2_CPOL_Pos)
#define USART_CR2_CPOL                USART_CR2_CPOL_Msk
#define USART_CR2_CLKEN_Pos           (11U)
#define USART_CR2_CLKEN_Msk           (0x1U << USART_CR2_CLKEN_Pos)
#define USART_CR2_CLKEN               USART_CR2_CLKEN_Msk
#define USART_CR2_STOP_Pos            (12U)
#define USART_CR2_STOP_Msk            (0x3U << USART_CR2_STOP_Pos)
#define USART_CR2_STOP                USART_CR2_STOP_Msk
#define USART_CR2_STOP_0              (0x1U << USART_CR2_STOP_Pos)
#define USART_CR2_STOP_1              (0x2U << USART_CR2_STOP_Pos)
#define USART_CR2_LINEN_Pos           (14U)
#define USART_CR2_LINEN_Msk           (0x1U << USART_CR2_LINEN_Pos)
#define USART_CR2_LINEN               USART_CR2_LINEN_Msk
#define USART_CR2_SWAP_Pos            (15U)
#define USART_CR2_SWAP_Msk            (0x1U << USART_CR2_SWAP_Pos)
#define USART_CR2_SWAP                USART_CR2_SWAP_Msk
#define USART_CR2_RXINV_Pos           (16U)
#define USART_CR2_RXINV_Msk           (0x1U << USART_CR2_RXINV_Pos)
#define USART_CR2_RXINV               USART_CR2_RXINV_Msk
#define USART_CR2_TXINV_Pos           (17U)
#define USART_CR2_TXINV_Msk           (0x1U << USART_CR2_TXINV_Pos)
#define USART_CR2_TXINV               USART_CR2_TXINV_Msk
#define USART_CR2_DATAINV_Pos         (18U)
#define USART_CR2_DATAINV_Msk         (0x1U << USART_CR2_DATAINV_Pos)
#define USART_CR2_DATAINV             USART_CR2_DATAINV_Msk
#define USART_CR2_MSBFIRST_Pos        (19U)
#define USART_CR2_MSBFIRST_Msk        (0x1U << USART_CR2_MSBFIRST_Pos)
#define USART_CR2_MSBFIRST            USART_CR2_MSBFIRST_Msk
#define USART_CR2_ABREN_Pos           (20U)
#define USART_CR2_ABREN_Msk           (0x1U << USART_CR2_ABREN_Pos)
#define USART_CR2_ABREN               USART_CR2_ABREN_Msk
#define USART_CR2_ABRMODE_Pos         (21U)
#define USART_CR2_ABRMODE_Msk         (0x3U << USART_CR2_ABRMODE_Pos)
#define USART_CR2_ABRMODE             USART_CR2_ABRMODE_Msk
#define USART_CR2_ABRMODE_0           (0x1U << USART_CR2_ABRMODE_Pos)
#define USART_CR2_ABRMODE_1           (0x2U << USART_CR2_ABRMODE_Pos)
#define USART_CR2_RTOEN_Pos           (23U)
#define USART_CR2_RTOEN_Msk           (0x1U << USART_CR2_RTOEN_Pos)
#define USART_CR2_RTOEN               USART_CR2_RTOEN_Msk
#define USART_CR2_ADD_Pos             (24U)
#define USART_CR2_ADD_Msk             (0xFFU << USART_CR2_ADD_Pos)
#define USART_CR2_ADD                 USART_CR2_ADD_Msk


#define USART_CR3_EIE_Pos             (0U)
#define USART_CR3_EIE_Msk             (0x1U << USART_CR3_EIE_Pos)
#define USART_CR3_EIE                 USART_CR3_EIE_Msk
#define USART_CR3_IREN_Pos            (1U)
#define USART_CR3_IREN_Msk            (0x1U << USART_CR3_IREN_Pos)
#define USART_CR3_IREN                USART_CR3_IREN_Msk
#define USART_CR3_IRLP_Pos            (2U)
#define USART_CR3_IRLP_Msk            (0x1U << USART_CR3_IRLP_Pos)
#define USART_CR3_IRLP                USART_CR3_IRLP_Msk
#define USART_CR3_HDSEL_Pos           (3U)
#define USART_CR3_HDSEL_Msk           (0x1U << USART_CR3_HDSEL_Pos)
#define USART_CR3_HDSEL               USART_CR3_HDSEL_Msk
#define USART_CR3_NACK_Pos            (4U)
#define USART_CR3_NACK_Msk            (0x1U << USART_CR3_NACK_Pos)
#define USART_CR3_NACK                USART_CR3_NACK_Msk
#define USART_CR3_SCEN_Pos            (5U)
#define USART_CR3_SCEN_Msk            (0x1U << USART_CR3_SCEN_Pos)
#define USART_CR3_SCEN                USART_CR3_SCEN_Msk
#define USART_CR3_DMAR_Pos            (6U)
#define USART_CR3_DMAR_Msk            (0x1U << USART_CR3_DMAR_Pos)
#define USART_CR3_DMAR                USART_CR3_DMAR_Msk
#define USART_CR3_DMAT_Pos            (7U)
#define USART_CR3_DMAT_Msk            (0x1U << USART_CR3_DMAT_Pos)
#define USART_CR3_DMAT                USART_CR3_DMAT_Msk
#define USART_CR3_RTSE_Pos            (8U)
#define USART_CR3_RTSE_Msk            (0x1U << USART_CR3_RTSE_Pos)
#define USART_CR3_RTSE                USART_CR3_RTSE_Msk
#define USART_CR3_CTSE_Pos            (9U)
#define USART_CR3_CTSE_Msk            (0x1U << USART_CR3_CTSE_Pos)
#define USART_CR3_CTSE                USART_CR3_CTSE_Msk
#define USART_CR3_CTSIE_Pos           (10U)
#define USART_CR3_CTSIE_Msk           (0x1U << USART_CR3_CTSIE_Pos)
#define USART_CR3_CTSIE               USART_CR3_CTSIE_Msk
#define USART_CR3_ONEBIT_Pos          (11U)
#define USART_CR3_ONEBIT_Msk          (0x1U << USART_CR3_ONEBIT_Pos)
#define USART_CR3_ONEBIT              USART_CR3_ONEBIT_Msk
#define USART_CR3_OVRDIS_Pos          (12U)
#define USART_CR3_OVRDIS_Msk          (0x1U << USART_CR3_OVRDIS_Pos)
#define USART_CR3_OVRDIS              USART_CR3_OVRDIS_Msk
#define USART_CR3_DDRE_Pos            (13U)
#define USART_CR3_DDRE_Msk            (0x1U << USART_CR3_DDRE_Pos)
#define USART_CR3_DDRE                USART_CR3_DDRE_Msk
#define USART_CR3_DEM_Pos             (14U)
#define USART_CR3_DEM_Msk             (0x1U << USART_CR3_DEM_Pos)
#define USART_CR3_DEM                 USART_CR3_DEM_Msk
#define USART_CR3_DEP_Pos             (15U)
#define USART_CR3_DEP_Msk             (0x1U << USART_CR3_DEP_Pos)
#define USART_CR3_DEP                 USART_CR3_DEP_Msk
#define USART_CR3_SCARCNT_Pos         (17U)
#define USART_CR3_SCARCNT_Msk         (0x7U << USART_CR3_SCARCNT_Pos)
#define USART_CR3_SCARCNT             USART_CR3_SCARCNT_Msk
#define USART_CR3_SCARCNT_0           (0x1U << USART_CR3_SCARCNT_Pos)
#define USART_CR3_SCARCNT_1           (0x2U << USART_CR3_SCARCNT_Pos)
#define USART_CR3_SCARCNT_2           (0x4U << USART_CR3_SCARCNT_Pos)
#define USART_CR3_WUS_Pos             (20U)
#define USART_CR3_WUS_Msk             (0x3U << USART_CR3_WUS_Pos)
#define USART_CR3_WUS                 USART_CR3_WUS_Msk
#define USART_CR3_WUS_0               (0x1U << USART_CR3_WUS_Pos)
#define USART_CR3_WUS_1               (0x2U << USART_CR3_WUS_Pos)
#define USART_CR3_WUFIE_Pos           (22U)
#define USART_CR3_WUFIE_Msk           (0x1U << USART_CR3_WUFIE_Pos)
#define USART_CR3_WUFIE               USART_CR3_WUFIE_Msk


#define USART_BRR_DIV_FRACTION_Pos    (0U)
#define USART_BRR_DIV_FRACTION_Msk    (0xFU << USART_BRR_DIV_FRACTION_Pos)
#define USART_BRR_DIV_FRACTION        USART_BRR_DIV_FRACTION_Msk
#define USART_BRR_DIV_MANTISSA_Pos    (4U)
#define USART_BRR_DIV_MANTISSA_Msk    (0xFFFU << USART_BRR_DIV_MANTISSA_Pos)
#define USART_BRR_DIV_MANTISSA        USART_BRR_DIV_MANTISSA_Msk


#define USART_GTPR_PSC_Pos            (0U)
#define USART_GTPR_PSC_Msk            (0xFFU << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC                USART_GTPR_PSC_Msk
#define USART_GTPR_GT_Pos             (8U)
#define USART_GTPR_GT_Msk             (0xFFU << USART_GTPR_GT_Pos)
#define USART_GTPR_GT                 USART_GTPR_GT_Msk



#define USART_RTOR_RTO_Pos            (0U)
#define USART_RTOR_RTO_Msk            (0xFFFFFFU << USART_RTOR_RTO_Pos)
#define USART_RTOR_RTO                USART_RTOR_RTO_Msk
#define USART_RTOR_BLEN_Pos           (24U)
#define USART_RTOR_BLEN_Msk           (0xFFU << USART_RTOR_BLEN_Pos)
#define USART_RTOR_BLEN               USART_RTOR_BLEN_Msk


#define USART_RQR_ABRRQ_Pos           (0U)
#define USART_RQR_ABRRQ_Msk           (0x1U << USART_RQR_ABRRQ_Pos)
#define USART_RQR_ABRRQ               USART_RQR_ABRRQ_Msk
#define USART_RQR_SBKRQ_Pos           (1U)
#define USART_RQR_SBKRQ_Msk           (0x1U << USART_RQR_SBKRQ_Pos)
#define USART_RQR_SBKRQ               USART_RQR_SBKRQ_Msk
#define USART_RQR_MMRQ_Pos            (2U)
#define USART_RQR_MMRQ_Msk            (0x1U << USART_RQR_MMRQ_Pos)
#define USART_RQR_MMRQ                USART_RQR_MMRQ_Msk
#define USART_RQR_RXFRQ_Pos           (3U)
#define USART_RQR_RXFRQ_Msk           (0x1U << USART_RQR_RXFRQ_Pos)
#define USART_RQR_RXFRQ               USART_RQR_RXFRQ_Msk
#define USART_RQR_TXFRQ_Pos           (4U)
#define USART_RQR_TXFRQ_Msk           (0x1U << USART_RQR_TXFRQ_Pos)
#define USART_RQR_TXFRQ               USART_RQR_TXFRQ_Msk


#define USART_ISR_PE_Pos              (0U)
#define USART_ISR_PE_Msk              (0x1U << USART_ISR_PE_Pos)
#define USART_ISR_PE                  USART_ISR_PE_Msk
#define USART_ISR_FE_Pos              (1U)
#define USART_ISR_FE_Msk              (0x1U << USART_ISR_FE_Pos)
#define USART_ISR_FE                  USART_ISR_FE_Msk
#define USART_ISR_NE_Pos              (2U)
#define USART_ISR_NE_Msk              (0x1U << USART_ISR_NE_Pos)
#define USART_ISR_NE                  USART_ISR_NE_Msk
#define USART_ISR_ORE_Pos             (3U)
#define USART_ISR_ORE_Msk             (0x1U << USART_ISR_ORE_Pos)
#define USART_ISR_ORE                 USART_ISR_ORE_Msk
#define USART_ISR_IDLE_Pos            (4U)
#define USART_ISR_IDLE_Msk            (0x1U << USART_ISR_IDLE_Pos)
#define USART_ISR_IDLE                USART_ISR_IDLE_Msk
#define USART_ISR_RXNE_Pos            (5U)
#define USART_ISR_RXNE_Msk            (0x1U << USART_ISR_RXNE_Pos)
#define USART_ISR_RXNE                USART_ISR_RXNE_Msk
#define USART_ISR_TC_Pos              (6U)
#define USART_ISR_TC_Msk              (0x1U << USART_ISR_TC_Pos)
#define USART_ISR_TC                  USART_ISR_TC_Msk
#define USART_ISR_TXE_Pos             (7U)
#define USART_ISR_TXE_Msk             (0x1U << USART_ISR_TXE_Pos)
#define USART_ISR_TXE                 USART_ISR_TXE_Msk
#define USART_ISR_LBDF_Pos            (8U)
#define USART_ISR_LBDF_Msk            (0x1U << USART_ISR_LBDF_Pos)
#define USART_ISR_LBDF                USART_ISR_LBDF_Msk
#define USART_ISR_CTSIF_Pos           (9U)
#define USART_ISR_CTSIF_Msk           (0x1U << USART_ISR_CTSIF_Pos)
#define USART_ISR_CTSIF               USART_ISR_CTSIF_Msk
#define USART_ISR_CTS_Pos             (10U)
#define USART_ISR_CTS_Msk             (0x1U << USART_ISR_CTS_Pos)
#define USART_ISR_CTS                 USART_ISR_CTS_Msk
#define USART_ISR_RTOF_Pos            (11U)
#define USART_ISR_RTOF_Msk            (0x1U << USART_ISR_RTOF_Pos)
#define USART_ISR_RTOF                USART_ISR_RTOF_Msk
#define USART_ISR_EOBF_Pos            (12U)
#define USART_ISR_EOBF_Msk            (0x1U << USART_ISR_EOBF_Pos)
#define USART_ISR_EOBF                USART_ISR_EOBF_Msk
#define USART_ISR_ABRE_Pos            (14U)
#define USART_ISR_ABRE_Msk            (0x1U << USART_ISR_ABRE_Pos)
#define USART_ISR_ABRE                USART_ISR_ABRE_Msk
#define USART_ISR_ABRF_Pos            (15U)
#define USART_ISR_ABRF_Msk            (0x1U << USART_ISR_ABRF_Pos)
#define USART_ISR_ABRF                USART_ISR_ABRF_Msk
#define USART_ISR_BUSY_Pos            (16U)
#define USART_ISR_BUSY_Msk            (0x1U << USART_ISR_BUSY_Pos)
#define USART_ISR_BUSY                USART_ISR_BUSY_Msk
#define USART_ISR_CMF_Pos             (17U)
#define USART_ISR_CMF_Msk             (0x1U << USART_ISR_CMF_Pos)
#define USART_ISR_CMF                 USART_ISR_CMF_Msk
#define USART_ISR_SBKF_Pos            (18U)
#define USART_ISR_SBKF_Msk            (0x1U << USART_ISR_SBKF_Pos)
#define USART_ISR_SBKF                USART_ISR_SBKF_Msk
#define USART_ISR_RWU_Pos             (19U)
#define USART_ISR_RWU_Msk             (0x1U << USART_ISR_RWU_Pos)
#define USART_ISR_RWU                 USART_ISR_RWU_Msk
#define USART_ISR_WUF_Pos             (20U)
#define USART_ISR_WUF_Msk             (0x1U << USART_ISR_WUF_Pos)
#define USART_ISR_WUF                 USART_ISR_WUF_Msk
#define USART_ISR_TEACK_Pos           (21U)
#define USART_ISR_TEACK_Msk           (0x1U << USART_ISR_TEACK_Pos)
#define USART_ISR_TEACK               USART_ISR_TEACK_Msk
#define USART_ISR_REACK_Pos           (22U)
#define USART_ISR_REACK_Msk           (0x1U << USART_ISR_REACK_Pos)
#define USART_ISR_REACK               USART_ISR_REACK_Msk


#define USART_ICR_PECF_Pos            (0U)
#define USART_ICR_PECF_Msk            (0x1U << USART_ICR_PECF_Pos)
#define USART_ICR_PECF                USART_ICR_PECF_Msk
#define USART_ICR_FECF_Pos            (1U)
#define USART_ICR_FECF_Msk            (0x1U << USART_ICR_FECF_Pos)
#define USART_ICR_FECF                USART_ICR_FECF_Msk
#define USART_ICR_NCF_Pos             (2U)
#define USART_ICR_NCF_Msk             (0x1U << USART_ICR_NCF_Pos)
#define USART_ICR_NCF                 USART_ICR_NCF_Msk
#define USART_ICR_ORECF_Pos           (3U)
#define USART_ICR_ORECF_Msk           (0x1U << USART_ICR_ORECF_Pos)
#define USART_ICR_ORECF               USART_ICR_ORECF_Msk
#define USART_ICR_IDLECF_Pos          (4U)
#define USART_ICR_IDLECF_Msk          (0x1U << USART_ICR_IDLECF_Pos)
#define USART_ICR_IDLECF              USART_ICR_IDLECF_Msk
#define USART_ICR_TCCF_Pos            (6U)
#define USART_ICR_TCCF_Msk            (0x1U << USART_ICR_TCCF_Pos)
#define USART_ICR_TCCF                USART_ICR_TCCF_Msk
#define USART_ICR_LBDCF_Pos           (8U)
#define USART_ICR_LBDCF_Msk           (0x1U << USART_ICR_LBDCF_Pos)
#define USART_ICR_LBDCF               USART_ICR_LBDCF_Msk
#define USART_ICR_CTSCF_Pos           (9U)
#define USART_ICR_CTSCF_Msk           (0x1U << USART_ICR_CTSCF_Pos)
#define USART_ICR_CTSCF               USART_ICR_CTSCF_Msk
#define USART_ICR_RTOCF_Pos           (11U)
#define USART_ICR_RTOCF_Msk           (0x1U << USART_ICR_RTOCF_Pos)
#define USART_ICR_RTOCF               USART_ICR_RTOCF_Msk
#define USART_ICR_EOBCF_Pos           (12U)
#define USART_ICR_EOBCF_Msk           (0x1U << USART_ICR_EOBCF_Pos)
#define USART_ICR_EOBCF               USART_ICR_EOBCF_Msk
#define USART_ICR_CMCF_Pos            (17U)
#define USART_ICR_CMCF_Msk            (0x1U << USART_ICR_CMCF_Pos)
#define USART_ICR_CMCF                USART_ICR_CMCF_Msk
#define USART_ICR_WUCF_Pos            (20U)
#define USART_ICR_WUCF_Msk            (0x1U << USART_ICR_WUCF_Pos)
#define USART_ICR_WUCF                USART_ICR_WUCF_Msk


#define USART_RDR_RDR_Pos             (0U)
#define USART_RDR_RDR_Msk             (0x1FFU << USART_RDR_RDR_Pos)
#define USART_RDR_RDR                 USART_RDR_RDR_Msk


#define USART_TDR_TDR_Pos             (0U)
#define USART_TDR_TDR_Msk             (0x1FFU << USART_TDR_TDR_Pos)
#define USART_TDR_TDR                 USART_TDR_TDR_Msk







#define WWDG_CR_T_Pos           (0U)
#define WWDG_CR_T_Msk           (0x7FU << WWDG_CR_T_Pos)
#define WWDG_CR_T               WWDG_CR_T_Msk
#define WWDG_CR_T_0             (0x01U << WWDG_CR_T_Pos)
#define WWDG_CR_T_1             (0x02U << WWDG_CR_T_Pos)
#define WWDG_CR_T_2             (0x04U << WWDG_CR_T_Pos)
#define WWDG_CR_T_3             (0x08U << WWDG_CR_T_Pos)
#define WWDG_CR_T_4             (0x10U << WWDG_CR_T_Pos)
#define WWDG_CR_T_5             (0x20U << WWDG_CR_T_Pos)
#define WWDG_CR_T_6             (0x40U << WWDG_CR_T_Pos)


#define  WWDG_CR_T0 WWDG_CR_T_0
#define  WWDG_CR_T1 WWDG_CR_T_1
#define  WWDG_CR_T2 WWDG_CR_T_2
#define  WWDG_CR_T3 WWDG_CR_T_3
#define  WWDG_CR_T4 WWDG_CR_T_4
#define  WWDG_CR_T5 WWDG_CR_T_5
#define  WWDG_CR_T6 WWDG_CR_T_6

#define WWDG_CR_WDGA_Pos        (7U)
#define WWDG_CR_WDGA_Msk        (0x1U << WWDG_CR_WDGA_Pos)
#define WWDG_CR_WDGA            WWDG_CR_WDGA_Msk


#define WWDG_CFR_W_Pos          (0U)
#define WWDG_CFR_W_Msk          (0x7FU << WWDG_CFR_W_Pos)
#define WWDG_CFR_W              WWDG_CFR_W_Msk
#define WWDG_CFR_W_0            (0x01U << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_1            (0x02U << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_2            (0x04U << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_3            (0x08U << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_4            (0x10U << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_5            (0x20U << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_6            (0x40U << WWDG_CFR_W_Pos)


#define  WWDG_CFR_W0 WWDG_CFR_W_0
#define  WWDG_CFR_W1 WWDG_CFR_W_1
#define  WWDG_CFR_W2 WWDG_CFR_W_2
#define  WWDG_CFR_W3 WWDG_CFR_W_3
#define  WWDG_CFR_W4 WWDG_CFR_W_4
#define  WWDG_CFR_W5 WWDG_CFR_W_5
#define  WWDG_CFR_W6 WWDG_CFR_W_6

#define WWDG_CFR_WDGTB_Pos      (7U)
#define WWDG_CFR_WDGTB_Msk      (0x3U << WWDG_CFR_WDGTB_Pos)
#define WWDG_CFR_WDGTB          WWDG_CFR_WDGTB_Msk
#define WWDG_CFR_WDGTB_0        (0x1U << WWDG_CFR_WDGTB_Pos)
#define WWDG_CFR_WDGTB_1        (0x2U << WWDG_CFR_WDGTB_Pos)


#define  WWDG_CFR_WDGTB0 WWDG_CFR_WDGTB_0
#define  WWDG_CFR_WDGTB1 WWDG_CFR_WDGTB_1

#define WWDG_CFR_EWI_Pos        (9U)
#define WWDG_CFR_EWI_Msk        (0x1U << WWDG_CFR_EWI_Pos)
#define WWDG_CFR_EWI            WWDG_CFR_EWI_Msk


#define WWDG_SR_EWIF_Pos        (0U)
#define WWDG_SR_EWIF_Msk        (0x1U << WWDG_SR_EWIF_Pos)
#define WWDG_SR_EWIF            WWDG_SR_EWIF_Msk














#define IS_ADC_ALL_INSTANCE(INSTANCE) (((INSTANCE) == ADC1) || \
                                       ((INSTANCE) == ADC2))

#define IS_ADC_MULTIMODE_MASTER_INSTANCE(INSTANCE) (((INSTANCE) == ADC1))

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC12_COMMON)

#define IS_CAN_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CAN)


#define IS_COMP_ALL_INSTANCE(INSTANCE) (((INSTANCE) == COMP2) || \
                                        ((INSTANCE) == COMP4) || \
                                        ((INSTANCE) == COMP6))

#define IS_COMP_COMMON_INSTANCE(COMMON_INSTANCE) (0U)


#define IS_COMP_DAC1SWITCH_INSTANCE(INSTANCE) (0U)


#define IS_COMP_WINDOWMODE_INSTANCE(INSTANCE) (0U)


#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)


#define IS_DAC_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DAC1) || \
                                       ((INSTANCE) == DAC2))

#define IS_DAC_CHANNEL_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == DAC1) &&                   \
     (((CHANNEL) == DAC_CHANNEL_1) ||          \
      ((CHANNEL) == DAC_CHANNEL_2)))           \
    ||                                          \
    (((INSTANCE) == DAC2) &&                    \
     (((CHANNEL) == DAC_CHANNEL_1))))


#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA1_Channel1) || \
                                       ((INSTANCE) == DMA1_Channel2) || \
                                       ((INSTANCE) == DMA1_Channel3) || \
                                       ((INSTANCE) == DMA1_Channel4) || \
                                       ((INSTANCE) == DMA1_Channel5) || \
                                       ((INSTANCE) == DMA1_Channel6) || \
                                       ((INSTANCE) == DMA1_Channel7))


#define IS_GPIO_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == GPIOA) || \
                                         ((INSTANCE) == GPIOB) || \
                                         ((INSTANCE) == GPIOC) || \
                                         ((INSTANCE) == GPIOD) || \
                                         ((INSTANCE) == GPIOF))

#define IS_GPIO_AF_INSTANCE(INSTANCE)   (((INSTANCE) == GPIOA) || \
                                         ((INSTANCE) == GPIOB) || \
                                         ((INSTANCE) == GPIOC) || \
                                         ((INSTANCE) == GPIOD) || \
                                         ((INSTANCE) == GPIOF))

#define IS_GPIO_LOCK_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                         ((INSTANCE) == GPIOB) || \
                                         ((INSTANCE) == GPIOC) || \
                                         ((INSTANCE) == GPIOD) || \
                                         ((INSTANCE) == GPIOF))


#define IS_I2C_ALL_INSTANCE(INSTANCE) ((INSTANCE) == I2C1)


#define IS_I2C_WAKEUP_FROMSTOP_INSTANCE(INSTANCE) IS_I2C_ALL_INSTANCE(INSTANCE)



#define IS_OPAMP_ALL_INSTANCE(INSTANCE) ((INSTANCE) == OPAMP2)


#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)


#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)


#define IS_SMBUS_ALL_INSTANCE(INSTANCE) ((INSTANCE) == I2C1)


#define IS_SPI_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SPI1)


#define IS_TIM_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM7)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))


#define IS_TIM_CC1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))


#define IS_TIM_CC2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))


#define IS_TIM_CC3_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))


#define IS_TIM_CC4_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))


#define IS_TIM_CC5_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1))


#define IS_TIM_CC6_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1))




#define IS_TIM_ADVANCED_INSTANCE(INSTANCE)\
  ((INSTANCE) == TIM1)


#define IS_TIM_CLOCK_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))


#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))


#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))


#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))


#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))


#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))


#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))


#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1))


#define IS_TIM_ETR_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1)  || \
                                            ((INSTANCE) == TIM2)  || \
                                            ((INSTANCE) == TIM3))


#define IS_TIM_XOR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))


#define IS_TIM_MASTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM7)    || \
   ((INSTANCE) == TIM15))


#define IS_TIM_SLAVE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))


#define IS_TIM_SYNCHRO_INSTANCE(INSTANCE)  IS_TIM_MASTER_INSTANCE(INSTANCE)


#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE)\
    ((INSTANCE) == TIM2)


#define IS_TIM_DMABURST_INSTANCE(INSTANCE)\
    (((INSTANCE) == TIM1)    || \
     ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
     ((INSTANCE) == TIM17))


#define IS_TIM_BREAK_INSTANCE(INSTANCE)\
      (((INSTANCE) == TIM1)    || \
       ((INSTANCE) == TIM15)   || \
       ((INSTANCE) == TIM16)   || \
       ((INSTANCE) == TIM17))


#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == TIM1) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4) ||          \
      ((CHANNEL) == TIM_CHANNEL_5) ||          \
      ((CHANNEL) == TIM_CHANNEL_6)))           \
    ||                                         \
    (((INSTANCE) == TIM2) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM3) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM15) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2)))           \
    ||                                         \
    (((INSTANCE) == TIM16) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1)))           \
    ||                                         \
    (((INSTANCE) == TIM17) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1))))


#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == TIM1) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3)))            \
    ||                                          \
    (((INSTANCE) == TIM15) &&                   \
      ((CHANNEL) == TIM_CHANNEL_1))             \
    ||                                          \
    (((INSTANCE) == TIM16) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1))              \
    ||                                          \
    (((INSTANCE) == TIM17) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1)))


#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3))


#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))


#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))


#define IS_TIM_BKIN2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1))


#define IS_TIM_TRGO2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1))


#define IS_TIM_DMA_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM7)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))


#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))


#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))


#define IS_TIM_REMAP_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM16))


#define IS_TIM_COMBINED3PHASEPWM_INSTANCE(INSTANCE) \
  (((INSTANCE) == TIM1))


#define IS_TSC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == TSC)


#define IS_USART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                     ((INSTANCE) == USART2) || \
                                     ((INSTANCE) == USART3))


#define IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) ((INSTANCE) == USART1)


#define IS_UART_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                      ((INSTANCE) == USART2) || \
                                      ((INSTANCE) == USART3))


#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                                 ((INSTANCE) == USART2) || \
                                                 ((INSTANCE) == USART3))


#define IS_UART_LIN_INSTANCE(INSTANCE)   ((INSTANCE) == USART1)


#define IS_UART_WAKEUP_FROMSTOP_INSTANCE(INSTANCE)   ((INSTANCE) == USART1)


#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == USART2) || \
                                           ((INSTANCE) == USART3))


#define IS_UART_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) ((INSTANCE) == USART1)


#define IS_UART_DRIVER_ENABLE_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                  ((INSTANCE) == USART2) || \
                                                  ((INSTANCE) == USART3))


#define IS_SMARTCARD_INSTANCE(INSTANCE) ((INSTANCE) == USART1)


#define IS_IRDA_INSTANCE(INSTANCE) ((INSTANCE) == USART1)


#define IS_UART_DMA_INSTANCE(INSTANCE) (1)

#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDG)















#define ADC1_IRQn           ADC1_2_IRQn
#define USB_LP_CAN_RX0_IRQn CAN_RX0_IRQn
#define USB_HP_CAN_TX_IRQn  CAN_TX_IRQn
#define COMP_IRQn           COMP2_IRQn
#define COMP1_2_3_IRQn      COMP2_IRQn
#define COMP1_2_IRQn        COMP2_IRQn
#define COMP4_5_6_IRQn      COMP4_6_IRQn
#define TIM15_IRQn          TIM1_BRK_TIM15_IRQn
#define TIM18_DAC2_IRQn     TIM1_CC_IRQn
#define TIM17_IRQn          TIM1_TRG_COM_TIM17_IRQn
#define TIM16_IRQn          TIM1_UP_TIM16_IRQn
#define TIM6_DAC_IRQn       TIM6_DAC1_IRQn
#define TIM7_IRQn           TIM7_DAC2_IRQn



#define ADC1_IRQHandler           ADC1_2_IRQHandler
#define USB_LP_CAN_RX0_IRQHandler CAN_RX0_IRQHandler
#define USB_HP_CAN_TX_IRQHandler  CAN_TX_IRQHandler
#define COMP_IRQHandler           COMP2_IRQHandler
#define COMP1_2_3_IRQHandler      COMP2_IRQHandler
#define COMP1_2_IRQHandler        COMP2_IRQHandler
#define COMP4_5_6_IRQHandler      COMP4_6_IRQHandler
#define TIM15_IRQHandler          TIM1_BRK_TIM15_IRQHandler
#define TIM18_DAC2_IRQHandler     TIM1_CC_IRQHandler
#define TIM17_IRQHandler          TIM1_TRG_COM_TIM17_IRQHandler
#define TIM16_IRQHandler          TIM1_UP_TIM16_IRQHandler
#define TIM6_DAC_IRQHandler       TIM6_DAC1_IRQHandler
#define TIM7_IRQHandler           TIM7_DAC2_IRQHandler


#ifdef __cplusplus
}
#endif

#endif










