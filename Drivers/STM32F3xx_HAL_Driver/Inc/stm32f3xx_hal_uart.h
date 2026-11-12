



































#ifndef __STM32F3xx_HAL_UART_H
#define __STM32F3xx_HAL_UART_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"

















typedef struct
{
  uint32_t BaudRate;








  uint32_t WordLength;


  uint32_t StopBits;


  uint32_t Parity;






  uint32_t Mode;


  uint32_t HwFlowCtl;



  uint32_t OverSampling;


  uint32_t OneBitSampling;


}UART_InitTypeDef;




typedef struct
{
  uint32_t AdvFeatureInit;



  uint32_t TxPinLevelInvert;


  uint32_t RxPinLevelInvert;


  uint32_t DataInvert;



  uint32_t Swap;


  uint32_t OverrunDisable;


  uint32_t DMADisableonRxError;


  uint32_t AutoBaudRateEnable;


  uint32_t AutoBaudRateMode;



  uint32_t MSBFirst;

} UART_AdvFeatureInitTypeDef;




typedef struct
{
  uint32_t WakeUpEvent;




  uint16_t AddressLength;


  uint8_t Address;
} UART_WakeUpTypeDef;








































typedef enum
{
  HAL_UART_STATE_RESET             = 0x00U,

  HAL_UART_STATE_READY             = 0x20U,

  HAL_UART_STATE_BUSY              = 0x24U,

  HAL_UART_STATE_BUSY_TX           = 0x21U,

  HAL_UART_STATE_BUSY_RX           = 0x22U,

  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,


  HAL_UART_STATE_TIMEOUT           = 0xA0U,

  HAL_UART_STATE_ERROR             = 0xE0U

}HAL_UART_StateTypeDef;




typedef enum
{
  UART_CLOCKSOURCE_PCLK1      = 0x00U,
  UART_CLOCKSOURCE_PCLK2      = 0x01U,
  UART_CLOCKSOURCE_HSI        = 0x02U,
  UART_CLOCKSOURCE_SYSCLK     = 0x04U,
  UART_CLOCKSOURCE_LSE        = 0x08U,
  UART_CLOCKSOURCE_UNDEFINED  = 0x10U
}UART_ClockSourceTypeDef;




typedef struct
{
  USART_TypeDef            *Instance;

  UART_InitTypeDef         Init;

  UART_AdvFeatureInitTypeDef AdvancedInit;

  uint8_t                  *pTxBuffPtr;

  uint16_t                 TxXferSize;

  __IO uint16_t            TxXferCount;

  uint8_t                  *pRxBuffPtr;

  uint16_t                 RxXferSize;

  __IO uint16_t            RxXferCount;

  uint16_t                 Mask;

  DMA_HandleTypeDef        *hdmatx;

  DMA_HandleTypeDef        *hdmarx;

  HAL_LockTypeDef           Lock;

  __IO HAL_UART_StateTypeDef    gState;



  __IO HAL_UART_StateTypeDef    RxState;


  __IO uint32_t             ErrorCode;

}UART_HandleTypeDef;













#define HAL_UART_ERROR_NONE      (0x00000000U)
#define HAL_UART_ERROR_PE        (0x00000001U)
#define HAL_UART_ERROR_NE        (0x00000002U)
#define HAL_UART_ERROR_FE        (0x00000004U)
#define HAL_UART_ERROR_ORE       (0x00000008U)
#define HAL_UART_ERROR_DMA       (0x00000010U)
#define HAL_UART_ERROR_BUSY      (0x00000020U)







#define UART_STOPBITS_0_5                   USART_CR2_STOP_0
#define UART_STOPBITS_1                     (0x00000000U)
#define UART_STOPBITS_1_5                   ((uint32_t)(USART_CR2_STOP_0 | USART_CR2_STOP_1))
#define UART_STOPBITS_2                     ((uint32_t)USART_CR2_STOP_1)







#define UART_PARITY_NONE                    (0x00000000U)
#define UART_PARITY_EVEN                    ((uint32_t)USART_CR1_PCE)
#define UART_PARITY_ODD                     ((uint32_t)(USART_CR1_PCE | USART_CR1_PS))







#define UART_HWCONTROL_NONE                  (0x00000000U)
#define UART_HWCONTROL_RTS                   ((uint32_t)USART_CR3_RTSE)
#define UART_HWCONTROL_CTS                   ((uint32_t)USART_CR3_CTSE)
#define UART_HWCONTROL_RTS_CTS               ((uint32_t)(USART_CR3_RTSE | USART_CR3_CTSE))







#define UART_MODE_RX                        ((uint32_t)USART_CR1_RE)
#define UART_MODE_TX                        ((uint32_t)USART_CR1_TE)
#define UART_MODE_TX_RX                     ((uint32_t)(USART_CR1_TE |USART_CR1_RE))







#define UART_STATE_DISABLE                  (0x00000000U)
#define UART_STATE_ENABLE                   ((uint32_t)USART_CR1_UE)







#define UART_OVERSAMPLING_16                (0x00000000U)
#define UART_OVERSAMPLING_8                 ((uint32_t)USART_CR1_OVER8)







#define UART_ONE_BIT_SAMPLE_DISABLE         (0x00000000U)
#define UART_ONE_BIT_SAMPLE_ENABLE          ((uint32_t)USART_CR3_ONEBIT)







#define UART_ADVFEATURE_AUTOBAUDRATE_ONSTARTBIT    (0x00000000U)
#define UART_ADVFEATURE_AUTOBAUDRATE_ONFALLINGEDGE ((uint32_t)USART_CR2_ABRMODE_0)
#define UART_ADVFEATURE_AUTOBAUDRATE_ON0X7FFRAME   ((uint32_t)USART_CR2_ABRMODE_1)
#define UART_ADVFEATURE_AUTOBAUDRATE_ON0X55FRAME   ((uint32_t)USART_CR2_ABRMODE)







#define UART_RECEIVER_TIMEOUT_DISABLE       (0x00000000U)
#define UART_RECEIVER_TIMEOUT_ENABLE        ((uint32_t)USART_CR2_RTOEN)







#define UART_LIN_DISABLE                    (0x00000000U)
#define UART_LIN_ENABLE                     ((uint32_t)USART_CR2_LINEN)







#define UART_LINBREAKDETECTLENGTH_10B       (0x00000000U)
#define UART_LINBREAKDETECTLENGTH_11B       ((uint32_t)USART_CR2_LBDL)







#define UART_DMA_TX_DISABLE                 (0x00000000U)
#define UART_DMA_TX_ENABLE                  ((uint32_t)USART_CR3_DMAT)







#define UART_DMA_RX_DISABLE                 (0x00000000U)
#define UART_DMA_RX_ENABLE                  ((uint32_t)USART_CR3_DMAR)







#define UART_HALF_DUPLEX_DISABLE            (0x00000000U)
#define UART_HALF_DUPLEX_ENABLE             ((uint32_t)USART_CR3_HDSEL)







#define UART_ADDRESS_DETECT_4B              (0x00000000U)
#define UART_ADDRESS_DETECT_7B              ((uint32_t)USART_CR2_ADDM7)







#define UART_WAKEUPMETHOD_IDLELINE          (0x00000000U)
#define UART_WAKEUPMETHOD_ADDRESSMARK       ((uint32_t)USART_CR1_WAKE)









#define UART_FLAG_REACK                     (0x00400000U)
#define UART_FLAG_TEACK                     (0x00200000U)
#define UART_FLAG_WUF                       (0x00100000U)
#define UART_FLAG_RWU                       (0x00080000U)
#define UART_FLAG_SBKF                      (0x00040000U)
#define UART_FLAG_CMF                       (0x00020000U)
#define UART_FLAG_BUSY                      (0x00010000U)
#define UART_FLAG_ABRF                      (0x00008000U)
#define UART_FLAG_ABRE                      (0x00004000U)
#define UART_FLAG_EOBF                      (0x00001000U)
#define UART_FLAG_RTOF                      (0x00000800U)
#define UART_FLAG_CTS                       (0x00000400U)
#define UART_FLAG_CTSIF                     (0x00000200U)
#define UART_FLAG_LBDF                      (0x00000100U)
#define UART_FLAG_TXE                       (0x00000080U)
#define UART_FLAG_TC                        (0x00000040U)
#define UART_FLAG_RXNE                      (0x00000020U)
#define UART_FLAG_IDLE                      (0x00000010U)
#define UART_FLAG_ORE                       (0x00000008U)
#define UART_FLAG_NE                        (0x00000004U)
#define UART_FLAG_FE                        (0x00000002U)
#define UART_FLAG_PE                        (0x00000001U)














#define UART_IT_PE                          (0x0028U)
#define UART_IT_TXE                         (0x0727U)
#define UART_IT_TC                          (0x0626U)
#define UART_IT_RXNE                        (0x0525U)
#define UART_IT_IDLE                        (0x0424U)
#define UART_IT_LBD                         (0x0846U)
#define UART_IT_CTS                         (0x096AU)
#define UART_IT_CM                          (0x112EU)
#define UART_IT_WUF                         (0x1476U)
#define UART_IT_ERR                         (0x0060U)
#define UART_IT_ORE                         (0x0300U)
#define UART_IT_NE                          (0x0200U)
#define UART_IT_FE                          (0x0100U)







#define UART_CLEAR_PEF                       USART_ICR_PECF
#define UART_CLEAR_FEF                       USART_ICR_FECF
#define UART_CLEAR_NEF                       USART_ICR_NCF
#define UART_CLEAR_OREF                      USART_ICR_ORECF
#define UART_CLEAR_IDLEF                     USART_ICR_IDLECF
#define UART_CLEAR_TCF                       USART_ICR_TCCF
#define UART_CLEAR_LBDF                      USART_ICR_LBDCF
#define UART_CLEAR_CTSF                      USART_ICR_CTSCF
#define UART_CLEAR_RTOF                      USART_ICR_RTOCF
#define UART_CLEAR_EOBF                      USART_ICR_EOBCF
#define UART_CLEAR_CMF                       USART_ICR_CMCF
#define UART_CLEAR_WUF                       USART_ICR_WUCF







#define UART_AUTOBAUD_REQUEST               ((uint32_t)USART_RQR_ABRRQ)
#define UART_SENDBREAK_REQUEST              ((uint32_t)USART_RQR_SBKRQ)
#define UART_MUTE_MODE_REQUEST              ((uint32_t)USART_RQR_MMRQ)
#define UART_RXDATA_FLUSH_REQUEST           ((uint32_t)USART_RQR_RXFRQ)
#define UART_TXDATA_FLUSH_REQUEST           ((uint32_t)USART_RQR_TXFRQ)







#define UART_ADVFEATURE_NO_INIT                 (0x00000000U)
#define UART_ADVFEATURE_TXINVERT_INIT           (0x00000001U)
#define UART_ADVFEATURE_RXINVERT_INIT           (0x00000002U)
#define UART_ADVFEATURE_DATAINVERT_INIT         (0x00000004U)
#define UART_ADVFEATURE_SWAP_INIT               (0x00000008U)
#define UART_ADVFEATURE_RXOVERRUNDISABLE_INIT   (0x00000010U)
#define UART_ADVFEATURE_DMADISABLEONERROR_INIT  (0x00000020U)
#define UART_ADVFEATURE_AUTOBAUDRATE_INIT       (0x00000040U)
#define UART_ADVFEATURE_MSBFIRST_INIT           (0x00000080U)







#define UART_ADVFEATURE_TXINV_DISABLE       (0x00000000U)
#define UART_ADVFEATURE_TXINV_ENABLE        ((uint32_t)USART_CR2_TXINV)







#define UART_ADVFEATURE_RXINV_DISABLE       (0x00000000U)
#define UART_ADVFEATURE_RXINV_ENABLE        ((uint32_t)USART_CR2_RXINV)







#define UART_ADVFEATURE_DATAINV_DISABLE     (0x00000000U)
#define UART_ADVFEATURE_DATAINV_ENABLE      ((uint32_t)USART_CR2_DATAINV)







#define UART_ADVFEATURE_SWAP_DISABLE        (0x00000000U)
#define UART_ADVFEATURE_SWAP_ENABLE         ((uint32_t)USART_CR2_SWAP)







#define UART_ADVFEATURE_OVERRUN_ENABLE      (0x00000000U)
#define UART_ADVFEATURE_OVERRUN_DISABLE     ((uint32_t)USART_CR3_OVRDIS)







#define UART_ADVFEATURE_AUTOBAUDRATE_DISABLE   (0x00000000U)
#define UART_ADVFEATURE_AUTOBAUDRATE_ENABLE    ((uint32_t)USART_CR2_ABREN)







#define UART_ADVFEATURE_DMA_ENABLEONRXERROR    (0x00000000U)
#define UART_ADVFEATURE_DMA_DISABLEONRXERROR   ((uint32_t)USART_CR3_DDRE)







#define UART_ADVFEATURE_MSBFIRST_DISABLE    (0x00000000U)
#define UART_ADVFEATURE_MSBFIRST_ENABLE     ((uint32_t)USART_CR2_MSBFIRST)







#define UART_ADVFEATURE_STOPMODE_DISABLE    (0x00000000U)
#define UART_ADVFEATURE_STOPMODE_ENABLE     ((uint32_t)USART_CR1_UESM)







#define UART_ADVFEATURE_MUTEMODE_DISABLE    (0x00000000U)
#define UART_ADVFEATURE_MUTEMODE_ENABLE     ((uint32_t)USART_CR1_MME)







#define UART_CR2_ADDRESS_LSB_POS            ( 24U)







#define UART_WAKEUP_ON_ADDRESS              (0x00000000U)
#define UART_WAKEUP_ON_STARTBIT             ((uint32_t)USART_CR3_WUS_1)
#define UART_WAKEUP_ON_READDATA_NONEMPTY    ((uint32_t)USART_CR3_WUS)







#define UART_DE_POLARITY_HIGH               (0x00000000U)
#define UART_DE_POLARITY_LOW                ((uint32_t)USART_CR3_DEP)







#define UART_CR1_DEAT_ADDRESS_LSB_POS       ( 21U)







#define UART_CR1_DEDT_ADDRESS_LSB_POS       ( 16U)







#define UART_IT_MASK                        (0x001FU)







#define HAL_UART_TIMEOUT_VALUE              0x1FFFFFF

















#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \
                                                     } while(0U)




#define __HAL_UART_FLUSH_DRREGISTER(__HANDLE__)  \
  do{                \
      SET_BIT((__HANDLE__)->Instance->RQR, UART_RXDATA_FLUSH_REQUEST); \
      SET_BIT((__HANDLE__)->Instance->RQR, UART_TXDATA_FLUSH_REQUEST); \
    }  while(0U)



















#define __HAL_UART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))





#define __HAL_UART_CLEAR_PEFLAG(__HANDLE__)   __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_PEF)





#define __HAL_UART_CLEAR_FEFLAG(__HANDLE__)   __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_FEF)





#define __HAL_UART_CLEAR_NEFLAG(__HANDLE__)  __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_NEF)





#define __HAL_UART_CLEAR_OREFLAG(__HANDLE__)   __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_OREF)





#define __HAL_UART_CLEAR_IDLEFLAG(__HANDLE__)   __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_IDLEF)




























#define __HAL_UART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->ISR & (__FLAG__)) == (__FLAG__))

















#define __HAL_UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (((((uint8_t)(__INTERRUPT__)) >> 5U) == 1U)? ((__HANDLE__)->Instance->CR1 |= (1U << ((__INTERRUPT__) & UART_IT_MASK))): \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == 2U)? ((__HANDLE__)->Instance->CR2 |= (1U << ((__INTERRUPT__) & UART_IT_MASK))): \
                                                           ((__HANDLE__)->Instance->CR3 |= (1U << ((__INTERRUPT__) & UART_IT_MASK))))


















#define __HAL_UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (((((uint8_t)(__INTERRUPT__)) >> 5U) == 1U)? ((__HANDLE__)->Instance->CR1 &= ~ (1U << ((__INTERRUPT__) & UART_IT_MASK))): \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == 2U)? ((__HANDLE__)->Instance->CR2 &= ~ (1U << ((__INTERRUPT__) & UART_IT_MASK))): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~ (1U << ((__INTERRUPT__) & UART_IT_MASK))))



















#define __HAL_UART_GET_IT(__HANDLE__, __IT__) ((__HANDLE__)->Instance->ISR & (1U << ((__IT__)>> 0x08U)))

















#define __HAL_UART_GET_IT_SOURCE(__HANDLE__, __IT__) ((((((uint8_t)(__IT__)) >> 5U) == 1U)? (__HANDLE__)->Instance->CR1:(((((uint8_t)(__IT__)) >> 5U) == 2U)? \
                                                       (__HANDLE__)->Instance->CR2 : (__HANDLE__)->Instance->CR3)) & (1U << (((uint16_t)(__IT__)) & UART_IT_MASK)))




















#define __HAL_UART_CLEAR_IT(__HANDLE__, __IT_CLEAR__) ((__HANDLE__)->Instance->ICR = (uint32_t)(__IT_CLEAR__))












#define __HAL_UART_SEND_REQ(__HANDLE__, __REQ__) ((__HANDLE__)->Instance->RQR |= (uint32_t)(__REQ__))





#define __HAL_UART_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)





#define __HAL_UART_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3 &= (uint32_t)~((uint32_t)USART_CR3_ONEBIT))





#define __HAL_UART_ENABLE(__HANDLE__)                   ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)





#define __HAL_UART_DISABLE(__HANDLE__)                  ((__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)













#define __HAL_UART_HWCONTROL_CTS_ENABLE(__HANDLE__)        \
  do{                                                      \
    SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE);  \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_CTSE;        \
  } while(0U)













#define __HAL_UART_HWCONTROL_CTS_DISABLE(__HANDLE__)        \
  do{                                                       \
    CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE); \
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_CTSE);      \
  } while(0U)













#define __HAL_UART_HWCONTROL_RTS_ENABLE(__HANDLE__)       \
  do{                                                     \
    SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE); \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_RTSE;       \
  } while(0U)













#define __HAL_UART_HWCONTROL_RTS_DISABLE(__HANDLE__)       \
  do{                                                      \
    CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE);\
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_RTSE);     \
  } while(0U)














#define UART_DIV_SAMPLING8(__PCLK__, __BAUD__)   ((((__PCLK__)*2U) + ((__BAUD__)/2U)) / (__BAUD__))






#define UART_DIV_SAMPLING16(__PCLK__, __BAUD__)  (((__PCLK__) + ((__BAUD__)/2U)) / (__BAUD__))







#define IS_UART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) < 9000001U)





#define IS_UART_ASSERTIONTIME(__TIME__)    ((__TIME__) <= 0x1FU)





#define IS_UART_DEASSERTIONTIME(__TIME__) ((__TIME__) <= 0x1FU)






#define IS_UART_STOPBITS(__STOPBITS__) (((__STOPBITS__) == UART_STOPBITS_0_5) || \
                                        ((__STOPBITS__) == UART_STOPBITS_1)   || \
                                        ((__STOPBITS__) == UART_STOPBITS_1_5) || \
                                        ((__STOPBITS__) == UART_STOPBITS_2))






#define IS_UART_PARITY(__PARITY__) (((__PARITY__) == UART_PARITY_NONE) || \
                                    ((__PARITY__) == UART_PARITY_EVEN) || \
                                    ((__PARITY__) == UART_PARITY_ODD))






#define IS_UART_HARDWARE_FLOW_CONTROL(__CONTROL__)\
                                   (((__CONTROL__) == UART_HWCONTROL_NONE) || \
                                    ((__CONTROL__) == UART_HWCONTROL_RTS)  || \
                                    ((__CONTROL__) == UART_HWCONTROL_CTS)  || \
                                    ((__CONTROL__) == UART_HWCONTROL_RTS_CTS))






#define IS_UART_MODE(__MODE__) ((((__MODE__) & (~((uint32_t)(UART_MODE_TX_RX)))) == 0x00U) && ((__MODE__) != 0x00U))






#define IS_UART_STATE(__STATE__) (((__STATE__) == UART_STATE_DISABLE) || \
                                  ((__STATE__) == UART_STATE_ENABLE))






#define IS_UART_OVERSAMPLING(__SAMPLING__) (((__SAMPLING__) == UART_OVERSAMPLING_16) || \
                                            ((__SAMPLING__) == UART_OVERSAMPLING_8))






#define IS_UART_ONE_BIT_SAMPLE(__ONEBIT__) (((__ONEBIT__) == UART_ONE_BIT_SAMPLE_DISABLE) || \
                                            ((__ONEBIT__) == UART_ONE_BIT_SAMPLE_ENABLE))






#define IS_UART_ADDRESSLENGTH_DETECT(__ADDRESS__) (((__ADDRESS__) == UART_ADDRESS_DETECT_4B) || \
                                                   ((__ADDRESS__) == UART_ADDRESS_DETECT_7B))






#define IS_UART_ADVFEATURE_AUTOBAUDRATEMODE(__MODE__)  (((__MODE__) == UART_ADVFEATURE_AUTOBAUDRATE_ONSTARTBIT)    || \
                                                        ((__MODE__) == UART_ADVFEATURE_AUTOBAUDRATE_ONFALLINGEDGE) || \
                                                        ((__MODE__) == UART_ADVFEATURE_AUTOBAUDRATE_ON0X7FFRAME)   || \
                                                        ((__MODE__) == UART_ADVFEATURE_AUTOBAUDRATE_ON0X55FRAME))






#define IS_UART_RECEIVER_TIMEOUT(__TIMEOUT__) (((__TIMEOUT__) == UART_RECEIVER_TIMEOUT_DISABLE) || \
                                               ((__TIMEOUT__) == UART_RECEIVER_TIMEOUT_ENABLE))






#define IS_UART_LIN(__LIN__)            (((__LIN__) == UART_LIN_DISABLE) || \
                                         ((__LIN__) == UART_LIN_ENABLE))






#define IS_UART_LIN_BREAK_DETECT_LENGTH(__LENGTH__) (((__LENGTH__) == UART_LINBREAKDETECTLENGTH_10B) || \
                                                     ((__LENGTH__) == UART_LINBREAKDETECTLENGTH_11B))






#define IS_UART_DMA_TX(__DMATX__)     (((__DMATX__) == UART_DMA_TX_DISABLE) || \
                                       ((__DMATX__) == UART_DMA_TX_ENABLE))






#define IS_UART_DMA_RX(__DMARX__)     (((__DMARX__) == UART_DMA_RX_DISABLE) || \
                                       ((__DMARX__) == UART_DMA_RX_ENABLE))






#define IS_UART_HALF_DUPLEX(__HDSEL__)     (((__HDSEL__) == UART_HALF_DUPLEX_DISABLE) || \
                                            ((__HDSEL__) == UART_HALF_DUPLEX_ENABLE))






#define IS_UART_WAKEUPMETHOD(__WAKEUP__) (((__WAKEUP__) == UART_WAKEUPMETHOD_IDLELINE) || \
                                          ((__WAKEUP__) == UART_WAKEUPMETHOD_ADDRESSMARK))






#define IS_UART_ADVFEATURE_INIT(__INIT__)   ((__INIT__) <= (UART_ADVFEATURE_NO_INIT                | \
                                                            UART_ADVFEATURE_TXINVERT_INIT          | \
                                                            UART_ADVFEATURE_RXINVERT_INIT          | \
                                                            UART_ADVFEATURE_DATAINVERT_INIT        | \
                                                            UART_ADVFEATURE_SWAP_INIT              | \
                                                            UART_ADVFEATURE_RXOVERRUNDISABLE_INIT  | \
                                                            UART_ADVFEATURE_DMADISABLEONERROR_INIT | \
                                                            UART_ADVFEATURE_AUTOBAUDRATE_INIT      | \
                                                            UART_ADVFEATURE_MSBFIRST_INIT))






#define IS_UART_ADVFEATURE_TXINV(__TXINV__) (((__TXINV__) == UART_ADVFEATURE_TXINV_DISABLE) || \
                                             ((__TXINV__) == UART_ADVFEATURE_TXINV_ENABLE))






#define IS_UART_ADVFEATURE_RXINV(__RXINV__) (((__RXINV__) == UART_ADVFEATURE_RXINV_DISABLE) || \
                                             ((__RXINV__) == UART_ADVFEATURE_RXINV_ENABLE))






#define IS_UART_ADVFEATURE_DATAINV(__DATAINV__) (((__DATAINV__) == UART_ADVFEATURE_DATAINV_DISABLE) || \
                                                 ((__DATAINV__) == UART_ADVFEATURE_DATAINV_ENABLE))






#define IS_UART_ADVFEATURE_SWAP(__SWAP__) (((__SWAP__) == UART_ADVFEATURE_SWAP_DISABLE) || \
                                           ((__SWAP__) == UART_ADVFEATURE_SWAP_ENABLE))






#define IS_UART_OVERRUN(__OVERRUN__)     (((__OVERRUN__) == UART_ADVFEATURE_OVERRUN_ENABLE) || \
                                          ((__OVERRUN__) == UART_ADVFEATURE_OVERRUN_DISABLE))






#define IS_UART_ADVFEATURE_AUTOBAUDRATE(__AUTOBAUDRATE__)  (((__AUTOBAUDRATE__) == UART_ADVFEATURE_AUTOBAUDRATE_DISABLE) || \
                                                            ((__AUTOBAUDRATE__) == UART_ADVFEATURE_AUTOBAUDRATE_ENABLE))






#define IS_UART_ADVFEATURE_DMAONRXERROR(__DMA__)  (((__DMA__) == UART_ADVFEATURE_DMA_ENABLEONRXERROR) || \
                                                   ((__DMA__) == UART_ADVFEATURE_DMA_DISABLEONRXERROR))






#define IS_UART_ADVFEATURE_MSBFIRST(__MSBFIRST__) (((__MSBFIRST__) == UART_ADVFEATURE_MSBFIRST_DISABLE) || \
                                                   ((__MSBFIRST__) == UART_ADVFEATURE_MSBFIRST_ENABLE))






#define IS_UART_ADVFEATURE_STOPMODE(__STOPMODE__) (((__STOPMODE__) == UART_ADVFEATURE_STOPMODE_DISABLE) || \
                                                   ((__STOPMODE__) == UART_ADVFEATURE_STOPMODE_ENABLE))






#define IS_UART_MUTE_MODE(__MUTE__)       (((__MUTE__) == UART_ADVFEATURE_MUTEMODE_DISABLE) || \
                                           ((__MUTE__) == UART_ADVFEATURE_MUTEMODE_ENABLE))






#define IS_UART_WAKEUP_SELECTION(__WAKE__) (((__WAKE__) == UART_WAKEUP_ON_ADDRESS) || \
                                            ((__WAKE__) == UART_WAKEUP_ON_STARTBIT) || \
                                            ((__WAKE__) == UART_WAKEUP_ON_READDATA_NONEMPTY))






#define IS_UART_DE_POLARITY(__POLARITY__)    (((__POLARITY__) == UART_DE_POLARITY_HIGH) || \
                                              ((__POLARITY__) == UART_DE_POLARITY_LOW))






#define IS_UART_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == UART_AUTOBAUD_REQUEST)     || \
                                              ((__PARAM__) == UART_SENDBREAK_REQUEST)    || \
                                              ((__PARAM__) == UART_MUTE_MODE_REQUEST)    || \
                                              ((__PARAM__) == UART_RXDATA_FLUSH_REQUEST) || \
                                              ((__PARAM__) == UART_TXDATA_FLUSH_REQUEST))






#include "stm32f3xx_hal_uart_ex.h"











HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
HAL_StatusTypeDef HAL_UART_DeInit (UART_HandleTypeDef *huart);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);










HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortCpltCallback (UART_HandleTypeDef *huart);
void HAL_UART_AbortTransmitCpltCallback (UART_HandleTypeDef *huart);
void HAL_UART_AbortReceiveCpltCallback (UART_HandleTypeDef *huart);










HAL_StatusTypeDef HAL_MultiProcessor_EnableMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_DisableMuteMode(UART_HandleTypeDef *huart);
void HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);










HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart);
uint32_t              HAL_UART_GetError(UART_HandleTypeDef *huart);













HAL_StatusTypeDef UART_SetConfig(UART_HandleTypeDef *huart);
void UART_AdvFeatureConfig(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_CheckIdleState(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_WaitOnFlagUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout);
HAL_StatusTypeDef UART_Transmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_EndTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_Receive_IT(UART_HandleTypeDef *huart);
void UART_Wakeup_AddressConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection);













#ifdef __cplusplus
}
#endif

#endif



