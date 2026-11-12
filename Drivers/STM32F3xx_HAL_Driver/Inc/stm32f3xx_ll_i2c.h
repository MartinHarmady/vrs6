



































#ifndef __STM32F3xx_LL_I2C_H
#define __STM32F3xx_LL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f3xx.h"





#if defined (I2C1) || defined (I2C2) || defined (I2C3)

















#if defined(USE_FULL_LL_DRIVER)






#endif


#if defined(USE_FULL_LL_DRIVER)



typedef struct
{
  uint32_t PeripheralMode;




  uint32_t Timing;





  uint32_t AnalogFilter;




  uint32_t DigitalFilter;




  uint32_t OwnAddress1;




  uint32_t TypeAcknowledge;




  uint32_t OwnAddrSize;



} LL_I2C_InitTypeDef;



#endif










#define LL_I2C_ICR_ADDRCF                   I2C_ICR_ADDRCF
#define LL_I2C_ICR_NACKCF                   I2C_ICR_NACKCF
#define LL_I2C_ICR_STOPCF                   I2C_ICR_STOPCF
#define LL_I2C_ICR_BERRCF                   I2C_ICR_BERRCF
#define LL_I2C_ICR_ARLOCF                   I2C_ICR_ARLOCF
#define LL_I2C_ICR_OVRCF                    I2C_ICR_OVRCF
#define LL_I2C_ICR_PECCF                    I2C_ICR_PECCF
#define LL_I2C_ICR_TIMOUTCF                 I2C_ICR_TIMOUTCF
#define LL_I2C_ICR_ALERTCF                  I2C_ICR_ALERTCF








#define LL_I2C_ISR_TXE                      I2C_ISR_TXE
#define LL_I2C_ISR_TXIS                     I2C_ISR_TXIS
#define LL_I2C_ISR_RXNE                     I2C_ISR_RXNE
#define LL_I2C_ISR_ADDR                     I2C_ISR_ADDR
#define LL_I2C_ISR_NACKF                    I2C_ISR_NACKF
#define LL_I2C_ISR_STOPF                    I2C_ISR_STOPF
#define LL_I2C_ISR_TC                       I2C_ISR_TC
#define LL_I2C_ISR_TCR                      I2C_ISR_TCR
#define LL_I2C_ISR_BERR                     I2C_ISR_BERR
#define LL_I2C_ISR_ARLO                     I2C_ISR_ARLO
#define LL_I2C_ISR_OVR                      I2C_ISR_OVR
#define LL_I2C_ISR_PECERR                   I2C_ISR_PECERR
#define LL_I2C_ISR_TIMEOUT                  I2C_ISR_TIMEOUT
#define LL_I2C_ISR_ALERT                    I2C_ISR_ALERT
#define LL_I2C_ISR_BUSY                     I2C_ISR_BUSY








#define LL_I2C_CR1_TXIE                     I2C_CR1_TXIE
#define LL_I2C_CR1_RXIE                     I2C_CR1_RXIE
#define LL_I2C_CR1_ADDRIE                   I2C_CR1_ADDRIE
#define LL_I2C_CR1_NACKIE                   I2C_CR1_NACKIE
#define LL_I2C_CR1_STOPIE                   I2C_CR1_STOPIE
#define LL_I2C_CR1_TCIE                     I2C_CR1_TCIE
#define LL_I2C_CR1_ERRIE                    I2C_CR1_ERRIE







#define LL_I2C_MODE_I2C                    0x00000000U
#define LL_I2C_MODE_SMBUS_HOST             I2C_CR1_SMBHEN
#define LL_I2C_MODE_SMBUS_DEVICE           0x00000000U
#define LL_I2C_MODE_SMBUS_DEVICE_ARP       I2C_CR1_SMBDEN







#define LL_I2C_ANALOGFILTER_ENABLE          0x00000000U
#define LL_I2C_ANALOGFILTER_DISABLE         I2C_CR1_ANFOFF







#define LL_I2C_ADDRESSING_MODE_7BIT         0x00000000U
#define LL_I2C_ADDRESSING_MODE_10BIT        I2C_CR2_ADD10







#define LL_I2C_OWNADDRESS1_7BIT             0x00000000U
#define LL_I2C_OWNADDRESS1_10BIT            I2C_OAR1_OA1MODE







#define LL_I2C_OWNADDRESS2_NOMASK           I2C_OAR2_OA2NOMASK
#define LL_I2C_OWNADDRESS2_MASK01           I2C_OAR2_OA2MASK01
#define LL_I2C_OWNADDRESS2_MASK02           I2C_OAR2_OA2MASK02
#define LL_I2C_OWNADDRESS2_MASK03           I2C_OAR2_OA2MASK03
#define LL_I2C_OWNADDRESS2_MASK04           I2C_OAR2_OA2MASK04
#define LL_I2C_OWNADDRESS2_MASK05           I2C_OAR2_OA2MASK05
#define LL_I2C_OWNADDRESS2_MASK06           I2C_OAR2_OA2MASK06
#define LL_I2C_OWNADDRESS2_MASK07           I2C_OAR2_OA2MASK07







#define LL_I2C_ACK                          0x00000000U
#define LL_I2C_NACK                         I2C_CR2_NACK







#define LL_I2C_ADDRSLAVE_7BIT               0x00000000U
#define LL_I2C_ADDRSLAVE_10BIT              I2C_CR2_ADD10







#define LL_I2C_REQUEST_WRITE                0x00000000U
#define LL_I2C_REQUEST_READ                 I2C_CR2_RD_WRN







#define LL_I2C_MODE_RELOAD                  I2C_CR2_RELOAD
#define LL_I2C_MODE_AUTOEND                 I2C_CR2_AUTOEND
#define LL_I2C_MODE_SOFTEND                 0x00000000U
#define LL_I2C_MODE_SMBUS_RELOAD            LL_I2C_MODE_RELOAD
#define LL_I2C_MODE_SMBUS_AUTOEND_NO_PEC    LL_I2C_MODE_AUTOEND
#define LL_I2C_MODE_SMBUS_SOFTEND_NO_PEC    LL_I2C_MODE_SOFTEND
#define LL_I2C_MODE_SMBUS_AUTOEND_WITH_PEC  (uint32_t)(LL_I2C_MODE_AUTOEND | I2C_CR2_PECBYTE)
#define LL_I2C_MODE_SMBUS_SOFTEND_WITH_PEC  (uint32_t)(LL_I2C_MODE_SOFTEND | I2C_CR2_PECBYTE)







#define LL_I2C_GENERATE_NOSTARTSTOP         0x00000000U
#define LL_I2C_GENERATE_STOP                (uint32_t)(0x80000000U | I2C_CR2_STOP)
#define LL_I2C_GENERATE_START_READ          (uint32_t)(0x80000000U | I2C_CR2_START | I2C_CR2_RD_WRN)
#define LL_I2C_GENERATE_START_WRITE         (uint32_t)(0x80000000U | I2C_CR2_START)
#define LL_I2C_GENERATE_RESTART_7BIT_READ   (uint32_t)(0x80000000U | I2C_CR2_START | I2C_CR2_RD_WRN)
#define LL_I2C_GENERATE_RESTART_7BIT_WRITE  (uint32_t)(0x80000000U | I2C_CR2_START)
#define LL_I2C_GENERATE_RESTART_10BIT_READ  (uint32_t)(0x80000000U | I2C_CR2_START | I2C_CR2_RD_WRN | I2C_CR2_HEAD10R)
#define LL_I2C_GENERATE_RESTART_10BIT_WRITE (uint32_t)(0x80000000U | I2C_CR2_START)







#define LL_I2C_DIRECTION_WRITE              0x00000000U
#define LL_I2C_DIRECTION_READ               I2C_ISR_DIR







#define LL_I2C_DMA_REG_DATA_TRANSMIT        0x00000000U
#define LL_I2C_DMA_REG_DATA_RECEIVE         0x00000001U







#define LL_I2C_SMBUS_TIMEOUTA_MODE_SCL_LOW      0x00000000U
#define LL_I2C_SMBUS_TIMEOUTA_MODE_SDA_SCL_HIGH I2C_TIMEOUTR_TIDLE







#define LL_I2C_SMBUS_TIMEOUTA               I2C_TIMEOUTR_TIMOUTEN
#define LL_I2C_SMBUS_TIMEOUTB               I2C_TIMEOUTR_TEXTEN
#define LL_I2C_SMBUS_ALL_TIMEOUT            (uint32_t)(I2C_TIMEOUTR_TIMOUTEN | I2C_TIMEOUTR_TEXTEN)
























#define LL_I2C_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))







#define LL_I2C_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
















#define __LL_I2C_CONVERT_TIMINGS(__PRESCALER__, __DATA_SETUP_TIME__, __DATA_HOLD_TIME__, __CLOCK_HIGH_PERIOD__, __CLOCK_LOW_PERIOD__)   \
        ((((uint32_t)(__PRESCALER__)         << I2C_TIMINGR_PRESC_Pos)  & I2C_TIMINGR_PRESC)   | \
         (((uint32_t)(__DATA_SETUP_TIME__)   << I2C_TIMINGR_SCLDEL_Pos) & I2C_TIMINGR_SCLDEL)  | \
         (((uint32_t)(__DATA_HOLD_TIME__)    << I2C_TIMINGR_SDADEL_Pos) & I2C_TIMINGR_SDADEL)  | \
         (((uint32_t)(__CLOCK_HIGH_PERIOD__) << I2C_TIMINGR_SCLH_Pos)   & I2C_TIMINGR_SCLH)    | \
         (((uint32_t)(__CLOCK_LOW_PERIOD__)  << I2C_TIMINGR_SCLL_Pos)   & I2C_TIMINGR_SCLL))























__STATIC_INLINE void LL_I2C_Enable(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_PE);
}










__STATIC_INLINE void LL_I2C_Disable(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_PE);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabled(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_PE) == (I2C_CR1_PE));
}
















__STATIC_INLINE void LL_I2C_ConfigFilters(I2C_TypeDef *I2Cx, uint32_t AnalogFilter, uint32_t DigitalFilter)
{
  MODIFY_REG(I2Cx->CR1, I2C_CR1_ANFOFF | I2C_CR1_DNF, AnalogFilter | (DigitalFilter << I2C_CR1_DNF_Pos));
}












__STATIC_INLINE void LL_I2C_SetDigitalFilter(I2C_TypeDef *I2Cx, uint32_t DigitalFilter)
{
  MODIFY_REG(I2Cx->CR1, I2C_CR1_DNF, DigitalFilter << I2C_CR1_DNF_Pos);
}







__STATIC_INLINE uint32_t LL_I2C_GetDigitalFilter(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR1, I2C_CR1_DNF) >> I2C_CR1_DNF_Pos);
}








__STATIC_INLINE void LL_I2C_EnableAnalogFilter(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_ANFOFF);
}








__STATIC_INLINE void LL_I2C_DisableAnalogFilter(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_ANFOFF);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledAnalogFilter(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_ANFOFF) != (I2C_CR1_ANFOFF));
}







__STATIC_INLINE void LL_I2C_EnableDMAReq_TX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_TXDMAEN);
}







__STATIC_INLINE void LL_I2C_DisableDMAReq_TX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_TXDMAEN);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledDMAReq_TX(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_TXDMAEN) == (I2C_CR1_TXDMAEN));
}







__STATIC_INLINE void LL_I2C_EnableDMAReq_RX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_RXDMAEN);
}







__STATIC_INLINE void LL_I2C_DisableDMAReq_RX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_RXDMAEN);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledDMAReq_RX(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_RXDMAEN) == (I2C_CR1_RXDMAEN));
}











__STATIC_INLINE uint32_t LL_I2C_DMA_GetRegAddr(I2C_TypeDef *I2Cx, uint32_t Direction)
{
  register uint32_t data_reg_addr = 0U;

  if (Direction == LL_I2C_DMA_REG_DATA_TRANSMIT)
  {

    data_reg_addr = (uint32_t) & (I2Cx->TXDR);
  }
  else
  {

    data_reg_addr = (uint32_t) & (I2Cx->RXDR);
  }

  return data_reg_addr;
}








__STATIC_INLINE void LL_I2C_EnableClockStretching(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_NOSTRETCH);
}








__STATIC_INLINE void LL_I2C_DisableClockStretching(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_NOSTRETCH);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledClockStretching(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_NOSTRETCH) != (I2C_CR1_NOSTRETCH));
}







__STATIC_INLINE void LL_I2C_EnableSlaveByteControl(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_SBC);
}







__STATIC_INLINE void LL_I2C_DisableSlaveByteControl(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_SBC);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledSlaveByteControl(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_SBC) == (I2C_CR1_SBC));
}










__STATIC_INLINE void LL_I2C_EnableWakeUpFromStop(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_WUPEN);
}









__STATIC_INLINE void LL_I2C_DisableWakeUpFromStop(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_WUPEN);
}









__STATIC_INLINE uint32_t LL_I2C_IsEnabledWakeUpFromStop(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_WUPEN) == (I2C_CR1_WUPEN));
}








__STATIC_INLINE void LL_I2C_EnableGeneralCall(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_GCEN);
}








__STATIC_INLINE void LL_I2C_DisableGeneralCall(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_GCEN);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledGeneralCall(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_GCEN) == (I2C_CR1_GCEN));
}











__STATIC_INLINE void LL_I2C_SetMasterAddressingMode(I2C_TypeDef *I2Cx, uint32_t AddressingMode)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_ADD10, AddressingMode);
}









__STATIC_INLINE uint32_t LL_I2C_GetMasterAddressingMode(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR2, I2C_CR2_ADD10));
}












__STATIC_INLINE void LL_I2C_SetOwnAddress1(I2C_TypeDef *I2Cx, uint32_t OwnAddress1, uint32_t OwnAddrSize)
{
  MODIFY_REG(I2Cx->OAR1, I2C_OAR1_OA1 | I2C_OAR1_OA1MODE, OwnAddress1 | OwnAddrSize);
}







__STATIC_INLINE void LL_I2C_EnableOwnAddress1(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->OAR1, I2C_OAR1_OA1EN);
}







__STATIC_INLINE void LL_I2C_DisableOwnAddress1(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->OAR1, I2C_OAR1_OA1EN);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledOwnAddress1(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->OAR1, I2C_OAR1_OA1EN) == (I2C_OAR1_OA1EN));
}



















__STATIC_INLINE void LL_I2C_SetOwnAddress2(I2C_TypeDef *I2Cx, uint32_t OwnAddress2, uint32_t OwnAddrMask)
{
  MODIFY_REG(I2Cx->OAR2, I2C_OAR2_OA2 | I2C_OAR2_OA2MSK, OwnAddress2 | OwnAddrMask);
}







__STATIC_INLINE void LL_I2C_EnableOwnAddress2(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->OAR2, I2C_OAR2_OA2EN);
}







__STATIC_INLINE void LL_I2C_DisableOwnAddress2(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->OAR2, I2C_OAR2_OA2EN);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledOwnAddress2(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->OAR2, I2C_OAR2_OA2EN) == (I2C_OAR2_OA2EN));
}










__STATIC_INLINE void LL_I2C_SetTiming(I2C_TypeDef *I2Cx, uint32_t Timing)
{
  WRITE_REG(I2Cx->TIMINGR, Timing);
}







__STATIC_INLINE uint32_t LL_I2C_GetTimingPrescaler(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_PRESC) >> I2C_TIMINGR_PRESC_Pos);
}







__STATIC_INLINE uint32_t LL_I2C_GetClockLowPeriod(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SCLL) >> I2C_TIMINGR_SCLL_Pos);
}







__STATIC_INLINE uint32_t LL_I2C_GetClockHighPeriod(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SCLH) >> I2C_TIMINGR_SCLH_Pos);
}







__STATIC_INLINE uint32_t LL_I2C_GetDataHoldTime(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SDADEL) >> I2C_TIMINGR_SDADEL_Pos);
}







__STATIC_INLINE uint32_t LL_I2C_GetDataSetupTime(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SCLDEL) >> I2C_TIMINGR_SCLDEL_Pos);
}















__STATIC_INLINE void LL_I2C_SetMode(I2C_TypeDef *I2Cx, uint32_t PeripheralMode)
{
  MODIFY_REG(I2Cx->CR1, I2C_CR1_SMBHEN | I2C_CR1_SMBDEN, PeripheralMode);
}














__STATIC_INLINE uint32_t LL_I2C_GetMode(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR1, I2C_CR1_SMBHEN | I2C_CR1_SMBDEN));
}














__STATIC_INLINE void LL_I2C_EnableSMBusAlert(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_ALERTEN);
}














__STATIC_INLINE void LL_I2C_DisableSMBusAlert(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_ALERTEN);
}









__STATIC_INLINE uint32_t LL_I2C_IsEnabledSMBusAlert(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_ALERTEN) == (I2C_CR1_ALERTEN));
}









__STATIC_INLINE void LL_I2C_EnableSMBusPEC(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_PECEN);
}









__STATIC_INLINE void LL_I2C_DisableSMBusPEC(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_PECEN);
}









__STATIC_INLINE uint32_t LL_I2C_IsEnabledSMBusPEC(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_PECEN) == (I2C_CR1_PECEN));
}

















__STATIC_INLINE void LL_I2C_ConfigSMBusTimeout(I2C_TypeDef *I2Cx, uint32_t TimeoutA, uint32_t TimeoutAMode,
                                               uint32_t TimeoutB)
{
  MODIFY_REG(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTA | I2C_TIMEOUTR_TIDLE | I2C_TIMEOUTR_TIMEOUTB,
             TimeoutA | TimeoutAMode | (TimeoutB << I2C_TIMEOUTR_TIMEOUTB_Pos));
}











__STATIC_INLINE void LL_I2C_SetSMBusTimeoutA(I2C_TypeDef *I2Cx, uint32_t TimeoutA)
{
  WRITE_REG(I2Cx->TIMEOUTR, TimeoutA);
}









__STATIC_INLINE uint32_t LL_I2C_GetSMBusTimeoutA(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTA));
}













__STATIC_INLINE void LL_I2C_SetSMBusTimeoutAMode(I2C_TypeDef *I2Cx, uint32_t TimeoutAMode)
{
  WRITE_REG(I2Cx->TIMEOUTR, TimeoutAMode);
}











__STATIC_INLINE uint32_t LL_I2C_GetSMBusTimeoutAMode(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIDLE));
}











__STATIC_INLINE void LL_I2C_SetSMBusTimeoutB(I2C_TypeDef *I2Cx, uint32_t TimeoutB)
{
  WRITE_REG(I2Cx->TIMEOUTR, TimeoutB << I2C_TIMEOUTR_TIMEOUTB_Pos);
}









__STATIC_INLINE uint32_t LL_I2C_GetSMBusTimeoutB(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTB) >> I2C_TIMEOUTR_TIMEOUTB_Pos);
}














__STATIC_INLINE void LL_I2C_EnableSMBusTimeout(I2C_TypeDef *I2Cx, uint32_t ClockTimeout)
{
  SET_BIT(I2Cx->TIMEOUTR, ClockTimeout);
}














__STATIC_INLINE void LL_I2C_DisableSMBusTimeout(I2C_TypeDef *I2Cx, uint32_t ClockTimeout)
{
  CLEAR_BIT(I2Cx->TIMEOUTR, ClockTimeout);
}














__STATIC_INLINE uint32_t LL_I2C_IsEnabledSMBusTimeout(I2C_TypeDef *I2Cx, uint32_t ClockTimeout)
{
  return (READ_BIT(I2Cx->TIMEOUTR, (I2C_TIMEOUTR_TIMOUTEN | I2C_TIMEOUTR_TEXTEN)) == (ClockTimeout));
}















__STATIC_INLINE void LL_I2C_EnableIT_TX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_TXIE);
}







__STATIC_INLINE void LL_I2C_DisableIT_TX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_TXIE);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_TX(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_TXIE) == (I2C_CR1_TXIE));
}







__STATIC_INLINE void LL_I2C_EnableIT_RX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_RXIE);
}







__STATIC_INLINE void LL_I2C_DisableIT_RX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_RXIE);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_RX(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_RXIE) == (I2C_CR1_RXIE));
}







__STATIC_INLINE void LL_I2C_EnableIT_ADDR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_ADDRIE);
}







__STATIC_INLINE void LL_I2C_DisableIT_ADDR(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_ADDRIE);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_ADDR(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_ADDRIE) == (I2C_CR1_ADDRIE));
}







__STATIC_INLINE void LL_I2C_EnableIT_NACK(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_NACKIE);
}







__STATIC_INLINE void LL_I2C_DisableIT_NACK(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_NACKIE);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_NACK(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_NACKIE) == (I2C_CR1_NACKIE));
}







__STATIC_INLINE void LL_I2C_EnableIT_STOP(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_STOPIE);
}







__STATIC_INLINE void LL_I2C_DisableIT_STOP(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_STOPIE);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_STOP(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_STOPIE) == (I2C_CR1_STOPIE));
}










__STATIC_INLINE void LL_I2C_EnableIT_TC(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_TCIE);
}










__STATIC_INLINE void LL_I2C_DisableIT_TC(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_TCIE);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_TC(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_TCIE) == (I2C_CR1_TCIE));
}
















__STATIC_INLINE void LL_I2C_EnableIT_ERR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_ERRIE);
}
















__STATIC_INLINE void LL_I2C_DisableIT_ERR(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_ERRIE);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_ERR(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR1, I2C_CR1_ERRIE) == (I2C_CR1_ERRIE));
}

















__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TXE(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_TXE) == (I2C_ISR_TXE));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TXIS(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_TXIS) == (I2C_ISR_TXIS));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_RXNE(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_RXNE) == (I2C_ISR_RXNE));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_ADDR(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_ADDR) == (I2C_ISR_ADDR));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_NACK(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_NACKF) == (I2C_ISR_NACKF));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_STOP(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_STOPF) == (I2C_ISR_STOPF));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TC(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_TC) == (I2C_ISR_TC));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TCR(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_TCR) == (I2C_ISR_TCR));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_BERR(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_BERR) == (I2C_ISR_BERR));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_ARLO(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_ARLO) == (I2C_ISR_ARLO));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_OVR(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_OVR) == (I2C_ISR_OVR));
}











__STATIC_INLINE uint32_t LL_I2C_IsActiveSMBusFlag_PECERR(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_PECERR) == (I2C_ISR_PECERR));
}











__STATIC_INLINE uint32_t LL_I2C_IsActiveSMBusFlag_TIMEOUT(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_TIMEOUT) == (I2C_ISR_TIMEOUT));
}












__STATIC_INLINE uint32_t LL_I2C_IsActiveSMBusFlag_ALERT(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_ALERT) == (I2C_ISR_ALERT));
}









__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_BUSY(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->ISR, I2C_ISR_BUSY) == (I2C_ISR_BUSY));
}







__STATIC_INLINE void LL_I2C_ClearFlag_ADDR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_ADDRCF);
}







__STATIC_INLINE void LL_I2C_ClearFlag_NACK(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_NACKCF);
}







__STATIC_INLINE void LL_I2C_ClearFlag_STOP(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_STOPCF);
}








__STATIC_INLINE void LL_I2C_ClearFlag_TXE(I2C_TypeDef *I2Cx)
{
  WRITE_REG(I2Cx->ISR, I2C_ISR_TXE);
}







__STATIC_INLINE void LL_I2C_ClearFlag_BERR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_BERRCF);
}







__STATIC_INLINE void LL_I2C_ClearFlag_ARLO(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_ARLOCF);
}







__STATIC_INLINE void LL_I2C_ClearFlag_OVR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_OVRCF);
}









__STATIC_INLINE void LL_I2C_ClearSMBusFlag_PECERR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_PECCF);
}









__STATIC_INLINE void LL_I2C_ClearSMBusFlag_TIMEOUT(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_TIMOUTCF);
}









__STATIC_INLINE void LL_I2C_ClearSMBusFlag_ALERT(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_ALERTCF);
}

















__STATIC_INLINE void LL_I2C_EnableAutoEndMode(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_AUTOEND);
}








__STATIC_INLINE void LL_I2C_DisableAutoEndMode(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR2, I2C_CR2_AUTOEND);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledAutoEndMode(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR2, I2C_CR2_AUTOEND) == (I2C_CR2_AUTOEND));
}








__STATIC_INLINE void LL_I2C_EnableReloadMode(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_RELOAD);
}








__STATIC_INLINE void LL_I2C_DisableReloadMode(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR2, I2C_CR2_RELOAD);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledReloadMode(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR2, I2C_CR2_RELOAD) == (I2C_CR2_RELOAD));
}









__STATIC_INLINE void LL_I2C_SetTransferSize(I2C_TypeDef *I2Cx, uint32_t TransferSize)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_NBYTES, TransferSize << I2C_CR2_NBYTES_Pos);
}







__STATIC_INLINE uint32_t LL_I2C_GetTransferSize(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR2, I2C_CR2_NBYTES) >> I2C_CR2_NBYTES_Pos);
}











__STATIC_INLINE void LL_I2C_AcknowledgeNextData(I2C_TypeDef *I2Cx, uint32_t TypeAcknowledge)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_NACK, TypeAcknowledge);
}









__STATIC_INLINE void LL_I2C_GenerateStartCondition(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_START);
}







__STATIC_INLINE void LL_I2C_GenerateStopCondition(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_STOP);
}









__STATIC_INLINE void LL_I2C_EnableAuto10BitRead(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CR2, I2C_CR2_HEAD10R);
}








__STATIC_INLINE void LL_I2C_DisableAuto10BitRead(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_HEAD10R);
}







__STATIC_INLINE uint32_t LL_I2C_IsEnabledAuto10BitRead(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR2, I2C_CR2_HEAD10R) != (I2C_CR2_HEAD10R));
}











__STATIC_INLINE void LL_I2C_SetTransferRequest(I2C_TypeDef *I2Cx, uint32_t TransferRequest)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_RD_WRN, TransferRequest);
}









__STATIC_INLINE uint32_t LL_I2C_GetTransferRequest(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR2, I2C_CR2_RD_WRN));
}









__STATIC_INLINE void LL_I2C_SetSlaveAddr(I2C_TypeDef *I2Cx, uint32_t SlaveAddr)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_SADD, SlaveAddr);
}







__STATIC_INLINE uint32_t LL_I2C_GetSlaveAddr(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR2, I2C_CR2_SADD));
}







































__STATIC_INLINE void LL_I2C_HandleTransfer(I2C_TypeDef *I2Cx, uint32_t SlaveAddr, uint32_t SlaveAddrSize,
                                           uint32_t TransferSize, uint32_t EndMode, uint32_t Request)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_SADD | I2C_CR2_ADD10 | (I2C_CR2_RD_WRN & (uint32_t)(Request >> (31U - I2C_CR2_RD_WRN_Pos))) | I2C_CR2_START | I2C_CR2_STOP | I2C_CR2_RELOAD |
             I2C_CR2_NBYTES | I2C_CR2_AUTOEND | I2C_CR2_HEAD10R,
             SlaveAddr | SlaveAddrSize | TransferSize << I2C_CR2_NBYTES_Pos | EndMode | Request);
}











__STATIC_INLINE uint32_t LL_I2C_GetTransferDirection(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->ISR, I2C_ISR_DIR));
}







__STATIC_INLINE uint32_t LL_I2C_GetAddressMatchCode(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->ISR, I2C_ISR_ADDCODE) >> I2C_ISR_ADDCODE_Pos << 1);
}












__STATIC_INLINE void LL_I2C_EnableSMBusPECCompare(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_PECBYTE);
}









__STATIC_INLINE uint32_t LL_I2C_IsEnabledSMBusPECCompare(I2C_TypeDef *I2Cx)
{
  return (READ_BIT(I2Cx->CR2, I2C_CR2_PECBYTE) == (I2C_CR2_PECBYTE));
}









__STATIC_INLINE uint32_t LL_I2C_GetSMBusPEC(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->PECR, I2C_PECR_PEC));
}







__STATIC_INLINE uint8_t LL_I2C_ReceiveData8(I2C_TypeDef *I2Cx)
{
  return (uint8_t)(READ_BIT(I2Cx->RXDR, I2C_RXDR_RXDATA));
}








__STATIC_INLINE void LL_I2C_TransmitData8(I2C_TypeDef *I2Cx, uint8_t Data)
{
  WRITE_REG(I2Cx->TXDR, Data);
}





#if defined(USE_FULL_LL_DRIVER)




uint32_t LL_I2C_Init(I2C_TypeDef *I2Cx, LL_I2C_InitTypeDef *I2C_InitStruct);
uint32_t LL_I2C_DeInit(I2C_TypeDef *I2Cx);
void LL_I2C_StructInit(LL_I2C_InitTypeDef *I2C_InitStruct);





#endif









#endif





#ifdef __cplusplus
}
#endif

#endif


