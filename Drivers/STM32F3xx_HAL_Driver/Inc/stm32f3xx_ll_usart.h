



































#ifndef __STM32F3xx_LL_USART_H
#define __STM32F3xx_LL_USART_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f3xx.h"





#if defined (USART1) || defined (USART2) || defined (USART3) || defined (UART4) || defined (UART5)

















#if defined(USE_FULL_LL_DRIVER)






#endif


#if defined(USE_FULL_LL_DRIVER)







typedef struct
{
  uint32_t BaudRate;



  uint32_t DataWidth;




  uint32_t StopBits;




  uint32_t Parity;




  uint32_t TransferDirection;




  uint32_t HardwareFlowControl;




  uint32_t OverSampling;




} LL_USART_InitTypeDef;




typedef struct
{
  uint32_t ClockOutput;






  uint32_t ClockPolarity;





  uint32_t ClockPhase;





  uint32_t LastBitClockPulse;






} LL_USART_ClockInitTypeDef;




#endif










#define LL_USART_ICR_PECF                       USART_ICR_PECF
#define LL_USART_ICR_FECF                       USART_ICR_FECF
#define LL_USART_ICR_NCF                        USART_ICR_NCF
#define LL_USART_ICR_ORECF                      USART_ICR_ORECF
#define LL_USART_ICR_IDLECF                     USART_ICR_IDLECF
#define LL_USART_ICR_TCCF                       USART_ICR_TCCF
#define LL_USART_ICR_LBDCF                      USART_ICR_LBDCF
#define LL_USART_ICR_CTSCF                      USART_ICR_CTSCF
#define LL_USART_ICR_RTOCF                      USART_ICR_RTOCF
#define LL_USART_ICR_EOBCF                      USART_ICR_EOBCF
#define LL_USART_ICR_CMCF                       USART_ICR_CMCF
#define LL_USART_ICR_WUCF                       USART_ICR_WUCF








#define LL_USART_ISR_PE                         USART_ISR_PE
#define LL_USART_ISR_FE                         USART_ISR_FE
#define LL_USART_ISR_NE                         USART_ISR_NE
#define LL_USART_ISR_ORE                        USART_ISR_ORE
#define LL_USART_ISR_IDLE                       USART_ISR_IDLE
#define LL_USART_ISR_RXNE                       USART_ISR_RXNE
#define LL_USART_ISR_TC                         USART_ISR_TC
#define LL_USART_ISR_TXE                        USART_ISR_TXE
#define LL_USART_ISR_LBDF                       USART_ISR_LBDF
#define LL_USART_ISR_CTSIF                      USART_ISR_CTSIF
#define LL_USART_ISR_CTS                        USART_ISR_CTS
#define LL_USART_ISR_RTOF                       USART_ISR_RTOF
#define LL_USART_ISR_EOBF                       USART_ISR_EOBF
#define LL_USART_ISR_ABRE                       USART_ISR_ABRE
#define LL_USART_ISR_ABRF                       USART_ISR_ABRF
#define LL_USART_ISR_BUSY                       USART_ISR_BUSY
#define LL_USART_ISR_CMF                        USART_ISR_CMF
#define LL_USART_ISR_SBKF                       USART_ISR_SBKF
#define LL_USART_ISR_RWU                        USART_ISR_RWU
#define LL_USART_ISR_WUF                        USART_ISR_WUF
#define LL_USART_ISR_TEACK                      USART_ISR_TEACK
#define LL_USART_ISR_REACK                      USART_ISR_REACK








#define LL_USART_CR1_IDLEIE                     USART_CR1_IDLEIE
#define LL_USART_CR1_RXNEIE                     USART_CR1_RXNEIE
#define LL_USART_CR1_TCIE                       USART_CR1_TCIE
#define LL_USART_CR1_TXEIE                      USART_CR1_TXEIE
#define LL_USART_CR1_PEIE                       USART_CR1_PEIE
#define LL_USART_CR1_CMIE                       USART_CR1_CMIE
#define LL_USART_CR1_RTOIE                      USART_CR1_RTOIE
#define LL_USART_CR1_EOBIE                      USART_CR1_EOBIE
#define LL_USART_CR2_LBDIE                      USART_CR2_LBDIE
#define LL_USART_CR3_EIE                        USART_CR3_EIE
#define LL_USART_CR3_CTSIE                      USART_CR3_CTSIE
#define LL_USART_CR3_WUFIE                      USART_CR3_WUFIE







#define LL_USART_DIRECTION_NONE                 0x00000000U
#define LL_USART_DIRECTION_RX                   USART_CR1_RE
#define LL_USART_DIRECTION_TX                   USART_CR1_TE
#define LL_USART_DIRECTION_TX_RX                (USART_CR1_TE |USART_CR1_RE)







#define LL_USART_PARITY_NONE                    0x00000000U
#define LL_USART_PARITY_EVEN                    USART_CR1_PCE
#define LL_USART_PARITY_ODD                     (USART_CR1_PCE | USART_CR1_PS)







#define LL_USART_WAKEUP_IDLELINE                0x00000000U
#define LL_USART_WAKEUP_ADDRESSMARK             USART_CR1_WAKE







#if defined(USART_7BITS_SUPPORT)
#define LL_USART_DATAWIDTH_7B                   USART_CR1_M1
#define LL_USART_DATAWIDTH_8B                   0x00000000U
#define LL_USART_DATAWIDTH_9B                   USART_CR1_M0
#else
#define LL_USART_DATAWIDTH_8B                   0x00000000U
#define LL_USART_DATAWIDTH_9B                   USART_CR1_M
#endif







#define LL_USART_OVERSAMPLING_16                0x00000000U
#define LL_USART_OVERSAMPLING_8                 USART_CR1_OVER8




#if defined(USE_FULL_LL_DRIVER)




#define LL_USART_CLOCK_DISABLE                  0x00000000U
#define LL_USART_CLOCK_ENABLE                   USART_CR2_CLKEN



#endif




#define LL_USART_LASTCLKPULSE_NO_OUTPUT         0x00000000U
#define LL_USART_LASTCLKPULSE_OUTPUT            USART_CR2_LBCL







#define LL_USART_PHASE_1EDGE                    0x00000000U
#define LL_USART_PHASE_2EDGE                    USART_CR2_CPHA







#define LL_USART_POLARITY_LOW                   0x00000000U
#define LL_USART_POLARITY_HIGH                  USART_CR2_CPOL







#define LL_USART_STOPBITS_0_5                   USART_CR2_STOP_0
#define LL_USART_STOPBITS_1                     0x00000000U
#define LL_USART_STOPBITS_1_5                   (USART_CR2_STOP_0 | USART_CR2_STOP_1)
#define LL_USART_STOPBITS_2                     USART_CR2_STOP_1







#define LL_USART_TXRX_STANDARD                  0x00000000U
#define LL_USART_TXRX_SWAPPED                   (USART_CR2_SWAP)







#define LL_USART_RXPIN_LEVEL_STANDARD           0x00000000U
#define LL_USART_RXPIN_LEVEL_INVERTED           (USART_CR2_RXINV)







#define LL_USART_TXPIN_LEVEL_STANDARD           0x00000000U
#define LL_USART_TXPIN_LEVEL_INVERTED           (USART_CR2_TXINV)







#define LL_USART_BINARY_LOGIC_POSITIVE          0x00000000U
#define LL_USART_BINARY_LOGIC_NEGATIVE          USART_CR2_DATAINV







#define LL_USART_BITORDER_LSBFIRST              0x00000000U
#define LL_USART_BITORDER_MSBFIRST              USART_CR2_MSBFIRST







#define LL_USART_AUTOBAUD_DETECT_ON_STARTBIT    0x00000000U
#define LL_USART_AUTOBAUD_DETECT_ON_FALLINGEDGE USART_CR2_ABRMODE_0
#define LL_USART_AUTOBAUD_DETECT_ON_7F_FRAME    USART_CR2_ABRMODE_1
#define LL_USART_AUTOBAUD_DETECT_ON_55_FRAME    (USART_CR2_ABRMODE_1 | USART_CR2_ABRMODE_0)







#define LL_USART_ADDRESS_DETECT_4B              0x00000000U
#define LL_USART_ADDRESS_DETECT_7B              USART_CR2_ADDM7







#define LL_USART_HWCONTROL_NONE                 0x00000000U
#define LL_USART_HWCONTROL_RTS                  USART_CR3_RTSE
#define LL_USART_HWCONTROL_CTS                  USART_CR3_CTSE
#define LL_USART_HWCONTROL_RTS_CTS              (USART_CR3_RTSE | USART_CR3_CTSE)







#define LL_USART_WAKEUP_ON_ADDRESS              0x00000000U
#define LL_USART_WAKEUP_ON_STARTBIT             USART_CR3_WUS_1
#define LL_USART_WAKEUP_ON_RXNE                 (USART_CR3_WUS_0 | USART_CR3_WUS_1)







#define LL_USART_IRDA_POWER_NORMAL              0x00000000U
#define LL_USART_IRDA_POWER_LOW                 USART_CR3_IRLP







#define LL_USART_LINBREAK_DETECT_10B            0x00000000U
#define LL_USART_LINBREAK_DETECT_11B            USART_CR2_LBDL







#define LL_USART_DE_POLARITY_HIGH               0x00000000U
#define LL_USART_DE_POLARITY_LOW                USART_CR3_DEP







#define LL_USART_DMA_REG_DATA_TRANSMIT          0x00000000U
#define LL_USART_DMA_REG_DATA_RECEIVE           0x00000001U
























#define LL_USART_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))







#define LL_USART_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)















#define __LL_USART_DIV_SAMPLING8(__PERIPHCLK__, __BAUDRATE__) ((((__PERIPHCLK__)*2) + ((__BAUDRATE__)/2))/(__BAUDRATE__))








#define __LL_USART_DIV_SAMPLING16(__PERIPHCLK__, __BAUDRATE__) (((__PERIPHCLK__) + ((__BAUDRATE__)/2))/(__BAUDRATE__))

























__STATIC_INLINE void LL_USART_Enable(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_UE);
}










__STATIC_INLINE void LL_USART_Disable(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_UE);
}







__STATIC_INLINE uint32_t LL_USART_IsEnabled(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_UE) == (USART_CR1_UE));
}











__STATIC_INLINE void LL_USART_EnableInStopMode(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_UESM);
}










__STATIC_INLINE void LL_USART_DisableInStopMode(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_UESM);
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledInStopMode(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_UESM) == (USART_CR1_UESM));
}







__STATIC_INLINE void LL_USART_EnableDirectionRx(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_RE);
}







__STATIC_INLINE void LL_USART_DisableDirectionRx(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_RE);
}







__STATIC_INLINE void LL_USART_EnableDirectionTx(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_TE);
}







__STATIC_INLINE void LL_USART_DisableDirectionTx(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_TE);
}














__STATIC_INLINE void LL_USART_SetTransferDirection(USART_TypeDef *USARTx, uint32_t TransferDirection)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_RE | USART_CR1_TE, TransferDirection);
}












__STATIC_INLINE uint32_t LL_USART_GetTransferDirection(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_RE | USART_CR1_TE));
}















__STATIC_INLINE void LL_USART_SetParity(USART_TypeDef *USARTx, uint32_t Parity)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE, Parity);
}











__STATIC_INLINE uint32_t LL_USART_GetParity(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE));
}










__STATIC_INLINE void LL_USART_SetWakeUpMethod(USART_TypeDef *USARTx, uint32_t Method)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_WAKE, Method);
}









__STATIC_INLINE uint32_t LL_USART_GetWakeUpMethod(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_WAKE));
}














__STATIC_INLINE void LL_USART_SetDataWidth(USART_TypeDef *USARTx, uint32_t DataWidth)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_M, DataWidth);
}













__STATIC_INLINE uint32_t LL_USART_GetDataWidth(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_M));
}







__STATIC_INLINE void LL_USART_EnableMuteMode(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_MME);
}







__STATIC_INLINE void LL_USART_DisableMuteMode(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_MME);
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledMuteMode(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_MME) == (USART_CR1_MME));
}










__STATIC_INLINE void LL_USART_SetOverSampling(USART_TypeDef *USARTx, uint32_t OverSampling)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_OVER8, OverSampling);
}









__STATIC_INLINE uint32_t LL_USART_GetOverSampling(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_OVER8));
}












__STATIC_INLINE void LL_USART_SetLastClkPulseOutput(USART_TypeDef *USARTx, uint32_t LastBitClockPulse)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_LBCL, LastBitClockPulse);
}












__STATIC_INLINE uint32_t LL_USART_GetLastClkPulseOutput(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_LBCL));
}












__STATIC_INLINE void LL_USART_SetClockPhase(USART_TypeDef *USARTx, uint32_t ClockPhase)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_CPHA, ClockPhase);
}











__STATIC_INLINE uint32_t LL_USART_GetClockPhase(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_CPHA));
}












__STATIC_INLINE void LL_USART_SetClockPolarity(USART_TypeDef *USARTx, uint32_t ClockPolarity)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_CPOL, ClockPolarity);
}











__STATIC_INLINE uint32_t LL_USART_GetClockPolarity(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_CPOL));
}
























__STATIC_INLINE void LL_USART_ConfigClock(USART_TypeDef *USARTx, uint32_t Phase, uint32_t Polarity, uint32_t LBCPOutput)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_CPHA | USART_CR2_CPOL | USART_CR2_LBCL, Phase | Polarity | LBCPOutput);
}









__STATIC_INLINE void LL_USART_EnableSCLKOutput(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_CLKEN);
}









__STATIC_INLINE void LL_USART_DisableSCLKOutput(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_CLKEN);
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledSCLKOutput(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR2, USART_CR2_CLKEN) == (USART_CR2_CLKEN));
}












__STATIC_INLINE void LL_USART_SetStopBitsLength(USART_TypeDef *USARTx, uint32_t StopBits)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_STOP, StopBits);
}











__STATIC_INLINE uint32_t LL_USART_GetStopBitsLength(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_STOP));
}






























__STATIC_INLINE void LL_USART_ConfigCharacter(USART_TypeDef *USARTx, uint32_t DataWidth, uint32_t Parity,
                                              uint32_t StopBits)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE | USART_CR1_M, Parity | DataWidth);
  MODIFY_REG(USARTx->CR2, USART_CR2_STOP, StopBits);
}










__STATIC_INLINE void LL_USART_SetTXRXSwap(USART_TypeDef *USARTx, uint32_t SwapConfig)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_SWAP, SwapConfig);
}









__STATIC_INLINE uint32_t LL_USART_GetTXRXSwap(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_SWAP));
}










__STATIC_INLINE void LL_USART_SetRXPinLevel(USART_TypeDef *USARTx, uint32_t PinInvMethod)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_RXINV, PinInvMethod);
}









__STATIC_INLINE uint32_t LL_USART_GetRXPinLevel(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_RXINV));
}










__STATIC_INLINE void LL_USART_SetTXPinLevel(USART_TypeDef *USARTx, uint32_t PinInvMethod)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_TXINV, PinInvMethod);
}









__STATIC_INLINE uint32_t LL_USART_GetTXPinLevel(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_TXINV));
}












__STATIC_INLINE void LL_USART_SetBinaryDataLogic(USART_TypeDef *USARTx, uint32_t DataLogic)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_DATAINV, DataLogic);
}









__STATIC_INLINE uint32_t LL_USART_GetBinaryDataLogic(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_DATAINV));
}












__STATIC_INLINE void LL_USART_SetTransferBitOrder(USART_TypeDef *USARTx, uint32_t BitOrder)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_MSBFIRST, BitOrder);
}











__STATIC_INLINE uint32_t LL_USART_GetTransferBitOrder(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_MSBFIRST));
}









__STATIC_INLINE void LL_USART_EnableAutoBaudRate(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_ABREN);
}









__STATIC_INLINE void LL_USART_DisableAutoBaudRate(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_ABREN);
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledAutoBaud(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR2, USART_CR2_ABREN) == (USART_CR2_ABREN));
}














__STATIC_INLINE void LL_USART_SetAutoBaudRateMode(USART_TypeDef *USARTx, uint32_t AutoBaudRateMode)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_ABRMODE, AutoBaudRateMode);
}













__STATIC_INLINE uint32_t LL_USART_GetAutoBaudRateMode(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_ABRMODE));
}







__STATIC_INLINE void LL_USART_EnableRxTimeout(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_RTOEN);
}







__STATIC_INLINE void LL_USART_DisableRxTimeout(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_RTOEN);
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledRxTimeout(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR2, USART_CR2_RTOEN) == (USART_CR2_RTOEN));
}
























__STATIC_INLINE void LL_USART_ConfigNodeAddress(USART_TypeDef *USARTx, uint32_t AddressLen, uint32_t NodeAddress)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_ADD | USART_CR2_ADDM7,
             (uint32_t)(AddressLen | (NodeAddress << USART_CR2_ADD_Pos)));
}











__STATIC_INLINE uint32_t LL_USART_GetNodeAddress(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_ADD) >> USART_CR2_ADD_Pos);
}









__STATIC_INLINE uint32_t LL_USART_GetNodeAddressLen(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_ADDM7));
}









__STATIC_INLINE void LL_USART_EnableRTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_RTSE);
}









__STATIC_INLINE void LL_USART_DisableRTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_RTSE);
}









__STATIC_INLINE void LL_USART_EnableCTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_CTSE);
}









__STATIC_INLINE void LL_USART_DisableCTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_CTSE);
}















__STATIC_INLINE void LL_USART_SetHWFlowCtrl(USART_TypeDef *USARTx, uint32_t HardwareFlowControl)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_RTSE | USART_CR3_CTSE, HardwareFlowControl);
}














__STATIC_INLINE uint32_t LL_USART_GetHWFlowCtrl(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_RTSE | USART_CR3_CTSE));
}







__STATIC_INLINE void LL_USART_EnableOneBitSamp(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_ONEBIT);
}







__STATIC_INLINE void LL_USART_DisableOneBitSamp(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_ONEBIT);
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledOneBitSamp(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_ONEBIT) == (USART_CR3_ONEBIT));
}







__STATIC_INLINE void LL_USART_EnableOverrunDetect(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_OVRDIS);
}







__STATIC_INLINE void LL_USART_DisableOverrunDetect(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_OVRDIS);
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledOverrunDetect(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_OVRDIS) != USART_CR3_OVRDIS);
}













__STATIC_INLINE void LL_USART_SetWKUPType(USART_TypeDef *USARTx, uint32_t Type)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_WUS, Type);
}












__STATIC_INLINE uint32_t LL_USART_GetWKUPType(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_WUS));
}

















__STATIC_INLINE void LL_USART_SetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t OverSampling,
                                          uint32_t BaudRate)
{
  register uint32_t usartdiv = 0x0U;
  register uint32_t brrtemp = 0x0U;

  if (OverSampling == LL_USART_OVERSAMPLING_8)
  {
    usartdiv = (uint16_t)(__LL_USART_DIV_SAMPLING8(PeriphClk, BaudRate));
    brrtemp = usartdiv & 0xFFF0U;
    brrtemp |= (uint16_t)((usartdiv & (uint16_t)0x000FU) >> 1U);
    USARTx->BRR = brrtemp;
  }
  else
  {
    USARTx->BRR = (uint16_t)(__LL_USART_DIV_SAMPLING16(PeriphClk, BaudRate));
  }
}














__STATIC_INLINE uint32_t LL_USART_GetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t OverSampling)
{
  register uint32_t usartdiv = 0x0U;
  register uint32_t brrresult = 0x0U;

  usartdiv = USARTx->BRR;

  if (OverSampling == LL_USART_OVERSAMPLING_8)
  {
    if ((usartdiv & 0xFFF7U) != 0U)
    {
      usartdiv = (uint16_t)((usartdiv & 0xFFF0U) | ((usartdiv & 0x0007U) << 1U)) ;
      brrresult = (PeriphClk * 2U) / usartdiv;
    }
  }
  else
  {
    if ((usartdiv & 0xFFFFU) != 0U)
    {
      brrresult = PeriphClk / usartdiv;
    }
  }
  return (brrresult);
}








__STATIC_INLINE void LL_USART_SetRxTimeout(USART_TypeDef *USARTx, uint32_t Timeout)
{
  MODIFY_REG(USARTx->RTOR, USART_RTOR_RTO, Timeout);
}







__STATIC_INLINE uint32_t LL_USART_GetRxTimeout(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->RTOR, USART_RTOR_RTO));
}








__STATIC_INLINE void LL_USART_SetBlockLength(USART_TypeDef *USARTx, uint32_t BlockLength)
{
  MODIFY_REG(USARTx->RTOR, USART_RTOR_BLEN, BlockLength << USART_RTOR_BLEN_Pos);
}







__STATIC_INLINE uint32_t LL_USART_GetBlockLength(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->RTOR, USART_RTOR_BLEN) >> USART_RTOR_BLEN_Pos);
}

















__STATIC_INLINE void LL_USART_EnableIrda(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_IREN);
}









__STATIC_INLINE void LL_USART_DisableIrda(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_IREN);
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledIrda(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_IREN) == (USART_CR3_IREN));
}












__STATIC_INLINE void LL_USART_SetIrdaPowerMode(USART_TypeDef *USARTx, uint32_t PowerMode)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_IRLP, PowerMode);
}











__STATIC_INLINE uint32_t LL_USART_GetIrdaPowerMode(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_IRLP));
}











__STATIC_INLINE void LL_USART_SetIrdaPrescaler(USART_TypeDef *USARTx, uint32_t PrescalerValue)
{
  MODIFY_REG(USARTx->GTPR, USART_GTPR_PSC, PrescalerValue);
}










__STATIC_INLINE uint32_t LL_USART_GetIrdaPrescaler(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->GTPR, USART_GTPR_PSC));
}

















__STATIC_INLINE void LL_USART_EnableSmartcardNACK(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_NACK);
}









__STATIC_INLINE void LL_USART_DisableSmartcardNACK(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_NACK);
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledSmartcardNACK(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_NACK) == (USART_CR3_NACK));
}









__STATIC_INLINE void LL_USART_EnableSmartcard(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_SCEN);
}









__STATIC_INLINE void LL_USART_DisableSmartcard(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_SCEN);
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledSmartcard(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_SCEN) == (USART_CR3_SCEN));
}















__STATIC_INLINE void LL_USART_SetSmartcardAutoRetryCount(USART_TypeDef *USARTx, uint32_t AutoRetryCount)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_SCARCNT, AutoRetryCount << USART_CR3_SCARCNT_Pos);
}









__STATIC_INLINE uint32_t LL_USART_GetSmartcardAutoRetryCount(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_SCARCNT) >> USART_CR3_SCARCNT_Pos);
}











__STATIC_INLINE void LL_USART_SetSmartcardPrescaler(USART_TypeDef *USARTx, uint32_t PrescalerValue)
{
  MODIFY_REG(USARTx->GTPR, USART_GTPR_PSC, PrescalerValue);
}










__STATIC_INLINE uint32_t LL_USART_GetSmartcardPrescaler(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->GTPR, USART_GTPR_PSC));
}











__STATIC_INLINE void LL_USART_SetSmartcardGuardTime(USART_TypeDef *USARTx, uint32_t GuardTime)
{
  MODIFY_REG(USARTx->GTPR, USART_GTPR_GT, GuardTime << USART_GTPR_GT_Pos);
}










__STATIC_INLINE uint32_t LL_USART_GetSmartcardGuardTime(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->GTPR, USART_GTPR_GT) >> USART_GTPR_GT_Pos);
}

















__STATIC_INLINE void LL_USART_EnableHalfDuplex(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_HDSEL);
}









__STATIC_INLINE void LL_USART_DisableHalfDuplex(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_HDSEL);
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledHalfDuplex(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_HDSEL) == (USART_CR3_HDSEL));
}




















__STATIC_INLINE void LL_USART_SetLINBrkDetectionLen(USART_TypeDef *USARTx, uint32_t LINBDLength)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_LBDL, LINBDLength);
}











__STATIC_INLINE uint32_t LL_USART_GetLINBrkDetectionLen(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_LBDL));
}









__STATIC_INLINE void LL_USART_EnableLIN(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_LINEN);
}









__STATIC_INLINE void LL_USART_DisableLIN(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_LINEN);
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledLIN(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR2, USART_CR2_LINEN) == (USART_CR2_LINEN));
}


















__STATIC_INLINE void LL_USART_SetDEDeassertionTime(USART_TypeDef *USARTx, uint32_t Time)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_DEDT, Time << USART_CR1_DEDT_Pos);
}









__STATIC_INLINE uint32_t LL_USART_GetDEDeassertionTime(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_DEDT) >> USART_CR1_DEDT_Pos);
}










__STATIC_INLINE void LL_USART_SetDEAssertionTime(USART_TypeDef *USARTx, uint32_t Time)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_DEAT, Time << USART_CR1_DEAT_Pos);
}









__STATIC_INLINE uint32_t LL_USART_GetDEAssertionTime(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_DEAT) >> USART_CR1_DEAT_Pos);
}









__STATIC_INLINE void LL_USART_EnableDEMode(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_DEM);
}









__STATIC_INLINE void LL_USART_DisableDEMode(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_DEM);
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledDEMode(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_DEM) == (USART_CR3_DEM));
}












__STATIC_INLINE void LL_USART_SetDESignalPolarity(USART_TypeDef *USARTx, uint32_t Polarity)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_DEP, Polarity);
}











__STATIC_INLINE uint32_t LL_USART_GetDESignalPolarity(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_DEP));
}


































__STATIC_INLINE void LL_USART_ConfigAsyncMode(USART_TypeDef *USARTx)
{



  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_IREN | USART_CR3_HDSEL));
}




























__STATIC_INLINE void LL_USART_ConfigSyncMode(USART_TypeDef *USARTx)
{



  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_IREN | USART_CR3_HDSEL));

  SET_BIT(USARTx->CR2, USART_CR2_CLKEN);
}






























__STATIC_INLINE void LL_USART_ConfigLINMode(USART_TypeDef *USARTx)
{



  CLEAR_BIT(USARTx->CR2, (USART_CR2_CLKEN | USART_CR2_STOP));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_IREN | USART_CR3_SCEN | USART_CR3_HDSEL));

  SET_BIT(USARTx->CR2, USART_CR2_LINEN);
}




























__STATIC_INLINE void LL_USART_ConfigHalfDuplexMode(USART_TypeDef *USARTx)
{



  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_IREN));

  SET_BIT(USARTx->CR3, USART_CR3_HDSEL);
}






























__STATIC_INLINE void LL_USART_ConfigSmartcardMode(USART_TypeDef *USARTx)
{



  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_IREN | USART_CR3_HDSEL));


  SET_BIT(USARTx->CR2, (USART_CR2_STOP_0 | USART_CR2_STOP_1 | USART_CR2_CLKEN));

  SET_BIT(USARTx->CR3, USART_CR3_SCEN);
}






























__STATIC_INLINE void LL_USART_ConfigIrdaMode(USART_TypeDef *USARTx)
{



  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN | USART_CR2_STOP));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL));

  SET_BIT(USARTx->CR3, USART_CR3_IREN);
}




























__STATIC_INLINE void LL_USART_ConfigMultiProcessMode(USART_TypeDef *USARTx)
{



  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));
}















__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_PE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_PE) == (USART_ISR_PE));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_FE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_FE) == (USART_ISR_FE));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_NE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_NE) == (USART_ISR_NE));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_ORE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_ORE) == (USART_ISR_ORE));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_IDLE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_IDLE) == (USART_ISR_IDLE));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RXNE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_RXNE) == (USART_ISR_RXNE));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TC(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_TC) == (USART_ISR_TC));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TXE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_TXE) == (USART_ISR_TXE));
}









__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_LBD(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_LBDF) == (USART_ISR_LBDF));
}









__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_nCTS(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_CTSIF) == (USART_ISR_CTSIF));
}









__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_CTS(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_CTS) == (USART_ISR_CTS));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RTO(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_RTOF) == (USART_ISR_RTOF));
}









__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_EOB(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_EOBF) == (USART_ISR_EOBF));
}









__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_ABRE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_ABRE) == (USART_ISR_ABRE));
}









__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_ABR(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_ABRF) == (USART_ISR_ABRF));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_BUSY(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_BUSY) == (USART_ISR_BUSY));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_CM(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_CMF) == (USART_ISR_CMF));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_SBK(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_SBKF) == (USART_ISR_SBKF));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RWU(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_RWU) == (USART_ISR_RWU));
}









__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_WKUP(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_WUF) == (USART_ISR_WUF));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TEACK(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_TEACK) == (USART_ISR_TEACK));
}







__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_REACK(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->ISR, USART_ISR_REACK) == (USART_ISR_REACK));
}








__STATIC_INLINE void LL_USART_ClearFlag_PE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_PECF);
}







__STATIC_INLINE void LL_USART_ClearFlag_FE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_FECF);
}







__STATIC_INLINE void LL_USART_ClearFlag_NE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_NCF);
}







__STATIC_INLINE void LL_USART_ClearFlag_ORE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_ORECF);
}







__STATIC_INLINE void LL_USART_ClearFlag_IDLE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_IDLECF);
}







__STATIC_INLINE void LL_USART_ClearFlag_TC(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_TCCF);
}










__STATIC_INLINE void LL_USART_ClearFlag_LBD(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_LBDCF);
}









__STATIC_INLINE void LL_USART_ClearFlag_nCTS(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_CTSCF);
}







__STATIC_INLINE void LL_USART_ClearFlag_RTO(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_RTOCF);
}









__STATIC_INLINE void LL_USART_ClearFlag_EOB(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_EOBCF);
}







__STATIC_INLINE void LL_USART_ClearFlag_CM(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_CMCF);
}









__STATIC_INLINE void LL_USART_ClearFlag_WKUP(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_WUCF);
}















__STATIC_INLINE void LL_USART_EnableIT_IDLE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_IDLEIE);
}







__STATIC_INLINE void LL_USART_EnableIT_RXNE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_RXNEIE);
}







__STATIC_INLINE void LL_USART_EnableIT_TC(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_TCIE);
}







__STATIC_INLINE void LL_USART_EnableIT_TXE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_TXEIE);
}







__STATIC_INLINE void LL_USART_EnableIT_PE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_PEIE);
}







__STATIC_INLINE void LL_USART_EnableIT_CM(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_CMIE);
}







__STATIC_INLINE void LL_USART_EnableIT_RTO(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_RTOIE);
}









__STATIC_INLINE void LL_USART_EnableIT_EOB(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_EOBIE);
}









__STATIC_INLINE void LL_USART_EnableIT_LBD(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_LBDIE);
}











__STATIC_INLINE void LL_USART_EnableIT_ERROR(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_EIE);
}









__STATIC_INLINE void LL_USART_EnableIT_CTS(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_CTSIE);
}









__STATIC_INLINE void LL_USART_EnableIT_WKUP(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_WUFIE);
}








__STATIC_INLINE void LL_USART_DisableIT_IDLE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_IDLEIE);
}







__STATIC_INLINE void LL_USART_DisableIT_RXNE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_RXNEIE);
}







__STATIC_INLINE void LL_USART_DisableIT_TC(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_TCIE);
}







__STATIC_INLINE void LL_USART_DisableIT_TXE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_TXEIE);
}







__STATIC_INLINE void LL_USART_DisableIT_PE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_PEIE);
}







__STATIC_INLINE void LL_USART_DisableIT_CM(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_CMIE);
}







__STATIC_INLINE void LL_USART_DisableIT_RTO(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_RTOIE);
}









__STATIC_INLINE void LL_USART_DisableIT_EOB(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_EOBIE);
}









__STATIC_INLINE void LL_USART_DisableIT_LBD(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_LBDIE);
}











__STATIC_INLINE void LL_USART_DisableIT_ERROR(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_EIE);
}









__STATIC_INLINE void LL_USART_DisableIT_CTS(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_CTSIE);
}









__STATIC_INLINE void LL_USART_DisableIT_WKUP(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_WUFIE);
}








__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_IDLE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_IDLEIE) == (USART_CR1_IDLEIE));
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RXNE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_RXNEIE) == (USART_CR1_RXNEIE));
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TC(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_TCIE) == (USART_CR1_TCIE));
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TXE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_TXEIE) == (USART_CR1_TXEIE));
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_PE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_PEIE) == (USART_CR1_PEIE));
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_CM(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_CMIE) == (USART_CR1_CMIE));
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RTO(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_RTOIE) == (USART_CR1_RTOIE));
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_EOB(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR1, USART_CR1_EOBIE) == (USART_CR1_EOBIE));
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_LBD(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR2, USART_CR2_LBDIE) == (USART_CR2_LBDIE));
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_ERROR(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_EIE) == (USART_CR3_EIE));
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_CTS(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_CTSIE) == (USART_CR3_CTSIE));
}









__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_WKUP(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_WUFIE) == (USART_CR3_WUFIE));
}
















__STATIC_INLINE void LL_USART_EnableDMAReq_RX(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_DMAR);
}







__STATIC_INLINE void LL_USART_DisableDMAReq_RX(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_DMAR);
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledDMAReq_RX(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_DMAR) == (USART_CR3_DMAR));
}







__STATIC_INLINE void LL_USART_EnableDMAReq_TX(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_DMAT);
}







__STATIC_INLINE void LL_USART_DisableDMAReq_TX(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_DMAT);
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledDMAReq_TX(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_DMAT) == (USART_CR3_DMAT));
}







__STATIC_INLINE void LL_USART_EnableDMADeactOnRxErr(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_DDRE);
}







__STATIC_INLINE void LL_USART_DisableDMADeactOnRxErr(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_DDRE);
}







__STATIC_INLINE uint32_t LL_USART_IsEnabledDMADeactOnRxErr(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_DDRE) == (USART_CR3_DDRE));
}











__STATIC_INLINE uint32_t LL_USART_DMA_GetRegAddr(USART_TypeDef *USARTx, uint32_t Direction)
{
  register uint32_t data_reg_addr = 0U;

  if (Direction == LL_USART_DMA_REG_DATA_TRANSMIT)
  {

    data_reg_addr = (uint32_t) &(USARTx->TDR);
  }
  else
  {

    data_reg_addr = (uint32_t) &(USARTx->RDR);
  }

  return data_reg_addr;
}















__STATIC_INLINE uint8_t LL_USART_ReceiveData8(USART_TypeDef *USARTx)
{
  return (uint8_t)(READ_BIT(USARTx->RDR, USART_RDR_RDR));
}







__STATIC_INLINE uint16_t LL_USART_ReceiveData9(USART_TypeDef *USARTx)
{
  return (uint16_t)(READ_BIT(USARTx->RDR, USART_RDR_RDR));
}








__STATIC_INLINE void LL_USART_TransmitData8(USART_TypeDef *USARTx, uint8_t Value)
{
  USARTx->TDR = Value;
}








__STATIC_INLINE void LL_USART_TransmitData9(USART_TypeDef *USARTx, uint16_t Value)
{
  USARTx->TDR = Value & 0x1FFU;
}

















__STATIC_INLINE void LL_USART_RequestAutoBaudRate(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, USART_RQR_ABRRQ);
}







__STATIC_INLINE void LL_USART_RequestBreakSending(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, USART_RQR_SBKRQ);
}







__STATIC_INLINE void LL_USART_RequestEnterMuteMode(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, USART_RQR_MMRQ);
}







__STATIC_INLINE void LL_USART_RequestRxDataFlush(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, USART_RQR_RXFRQ);
}









__STATIC_INLINE void LL_USART_RequestTxDataFlush(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, USART_RQR_TXFRQ);
}





#if defined(USE_FULL_LL_DRIVER)



ErrorStatus LL_USART_DeInit(USART_TypeDef *USARTx);
ErrorStatus LL_USART_Init(USART_TypeDef *USARTx, LL_USART_InitTypeDef *USART_InitStruct);
void        LL_USART_StructInit(LL_USART_InitTypeDef *USART_InitStruct);
ErrorStatus LL_USART_ClockInit(USART_TypeDef *USARTx, LL_USART_ClockInitTypeDef *USART_ClockInitStruct);
void        LL_USART_ClockStructInit(LL_USART_ClockInitTypeDef *USART_ClockInitStruct);



#endif









#endif





#ifdef __cplusplus
}
#endif

#endif


