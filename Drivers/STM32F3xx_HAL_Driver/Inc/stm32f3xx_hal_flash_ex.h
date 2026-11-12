



































#ifndef __STM32F3xx_HAL_FLASH_EX_H
#define __STM32F3xx_HAL_FLASH_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f3xx_hal_def.h"













#define FLASH_SIZE_DATA_REGISTER (0x1FFFF7CCU)








#define IS_FLASH_TYPEERASE(VALUE) (((VALUE) == FLASH_TYPEERASE_PAGES) || \
                             ((VALUE) == FLASH_TYPEERASE_MASSERASE))

#define IS_OPTIONBYTE(VALUE) ((VALUE) <= (OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER | OPTIONBYTE_DATA))

#define IS_WRPSTATE(VALUE) (((VALUE) == OB_WRPSTATE_DISABLE) || \
                            ((VALUE) == OB_WRPSTATE_ENABLE))

#define IS_OB_DATA_ADDRESS(ADDRESS) (((ADDRESS) == OB_DATA_ADDRESS_DATA0) || ((ADDRESS) == OB_DATA_ADDRESS_DATA1))

#define IS_OB_RDP_LEVEL(LEVEL)     (((LEVEL) == OB_RDP_LEVEL_0)   ||\
                                    ((LEVEL) == OB_RDP_LEVEL_1))


#define IS_OB_IWDG_SOURCE(SOURCE)  (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))

#define IS_OB_STOP_SOURCE(SOURCE)  (((SOURCE) == OB_STOP_NO_RST) || ((SOURCE) == OB_STOP_RST))

#define IS_OB_STDBY_SOURCE(SOURCE) (((SOURCE) == OB_STDBY_NO_RST) || ((SOURCE) == OB_STDBY_RST))

#define IS_OB_BOOT1(BOOT1)         (((BOOT1) == OB_BOOT1_RESET) || ((BOOT1) == OB_BOOT1_SET))

#define IS_OB_VDDA_ANALOG(ANALOG)  (((ANALOG) == OB_VDDA_ANALOG_ON) || ((ANALOG) == OB_VDDA_ANALOG_OFF))

#define IS_OB_SRAM_PARITY(PARITY)  (((PARITY) == OB_SRAM_PARITY_SET) || ((PARITY) == OB_SRAM_PARITY_RESET))


#if defined(FLASH_OBR_SDADC12_VDD_MONITOR)
#define IS_OB_SDACD_VDD_MONITOR(VDD_MONITOR) (((VDD_MONITOR) == OB_SDACD_VDD_MONITOR_SET) || \
                                              ((VDD_MONITOR) == OB_SDACD_VDD_MONITOR_RESET))
#endif

#define IS_OB_WRP(PAGE) (((PAGE) != 0x0000000U))

#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) \
 || defined(STM32F373xC) || defined(STM32F378xx)
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? \
                                           ((ADDRESS) <= 0x0803FFFFU) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? \
                                           ((ADDRESS) <= 0x0801FFFFU) :  ((ADDRESS) <= 0x0800FFFFU))))
#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && ((ADDRESS) <= 0x0807FFFFU))
#endif

#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) \
 || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? \
                                           ((ADDRESS) <= 0x0800FFFFU) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? \
                                           ((ADDRESS) <= 0x08007FFFU) :  ((ADDRESS) <= 0x08003FFFU))))
#endif


#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) \
 || defined(STM32F373xC) || defined(STM32F378xx)
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1U <= 0x0803FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U)  ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1U <= 0x0801FFFFU) : \
                                            ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1U <= 0x0800FFFFU)))
#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1U <= 0x0807FFFFU)
#endif

#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) \
 || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1U <= 0x0800FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1U <= 0x08007FFFU) : \
                                            ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1U <= 0x08003FFFU)))
#endif













typedef struct
{
  uint32_t TypeErase;


  uint32_t PageAddress;


  uint32_t NbPages;


} FLASH_EraseInitTypeDef;




typedef struct
{
  uint32_t OptionType;


  uint32_t WRPState;


  uint32_t WRPPage;


  uint8_t RDPLevel;


  uint8_t USERConfig;












  uint32_t DATAAddress;


  uint8_t DATAData;

} FLASH_OBProgramInitTypeDef;












#define FLASH_PAGE_SIZE          0x800







#define FLASH_TYPEERASE_PAGES     (0x00U)
#define FLASH_TYPEERASE_MASSERASE (0x01U)












#define OPTIONBYTE_WRP       (0x01U)
#define OPTIONBYTE_RDP       (0x02U)
#define OPTIONBYTE_USER      (0x04U)
#define OPTIONBYTE_DATA      (0x08U)








#define OB_WRPSTATE_DISABLE   (0x00U)
#define OB_WRPSTATE_ENABLE    (0x01U)








#define OB_WRP_PAGES0TO1               (0x00000001U)
#define OB_WRP_PAGES2TO3               (0x00000002U)
#define OB_WRP_PAGES4TO5               (0x00000004U)
#define OB_WRP_PAGES6TO7               (0x00000008U)
#define OB_WRP_PAGES8TO9               (0x00000010U)
#define OB_WRP_PAGES10TO11             (0x00000020U)
#define OB_WRP_PAGES12TO13             (0x00000040U)
#define OB_WRP_PAGES14TO15             (0x00000080U)
#define OB_WRP_PAGES16TO17             (0x00000100U)
#define OB_WRP_PAGES18TO19             (0x00000200U)
#define OB_WRP_PAGES20TO21             (0x00000400U)
#define OB_WRP_PAGES22TO23             (0x00000800U)
#define OB_WRP_PAGES24TO25             (0x00001000U)
#define OB_WRP_PAGES26TO27             (0x00002000U)
#define OB_WRP_PAGES28TO29             (0x00004000U)
#define OB_WRP_PAGES30TO31             (0x00008000U)

#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) \
 || defined(STM32F373xC) || defined(STM32F378xx)
#define OB_WRP_PAGES32TO33             (0x00010000U)
#define OB_WRP_PAGES34TO35             (0x00020000U)
#define OB_WRP_PAGES36TO37             (0x00040000U)
#define OB_WRP_PAGES38TO39             (0x00080000U)
#define OB_WRP_PAGES40TO41             (0x00100000U)
#define OB_WRP_PAGES42TO43             (0x00200000U)
#define OB_WRP_PAGES44TO45             (0x00400000U)
#define OB_WRP_PAGES46TO47             (0x00800000U)
#define OB_WRP_PAGES48TO49             (0x01000000U)
#define OB_WRP_PAGES50TO51             (0x02000000U)
#define OB_WRP_PAGES52TO53             (0x04000000U)
#define OB_WRP_PAGES54TO55             (0x08000000U)
#define OB_WRP_PAGES56TO57             (0x10000000U)
#define OB_WRP_PAGES58TO59             (0x20000000U)
#define OB_WRP_PAGES60TO61             (0x40000000U)
#define OB_WRP_PAGES62TO127            (0x80000000U)
#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define OB_WRP_PAGES32TO33             (0x00010000U)
#define OB_WRP_PAGES34TO35             (0x00020000U)
#define OB_WRP_PAGES36TO37             (0x00040000U)
#define OB_WRP_PAGES38TO39             (0x00080000U)
#define OB_WRP_PAGES40TO41             (0x00100000U)
#define OB_WRP_PAGES42TO43             (0x00200000U)
#define OB_WRP_PAGES44TO45             (0x00400000U)
#define OB_WRP_PAGES46TO47             (0x00800000U)
#define OB_WRP_PAGES48TO49             (0x01000000U)
#define OB_WRP_PAGES50TO51             (0x02000000U)
#define OB_WRP_PAGES52TO53             (0x04000000U)
#define OB_WRP_PAGES54TO55             (0x08000000U)
#define OB_WRP_PAGES56TO57             (0x10000000U)
#define OB_WRP_PAGES58TO59             (0x20000000U)
#define OB_WRP_PAGES60TO61             (0x40000000U)
#define OB_WRP_PAGES62TO255            (0x80000000U)
#endif

#define OB_WRP_PAGES0TO15MASK          (0x000000FFU)
#define OB_WRP_PAGES16TO31MASK         (0x0000FF00U)

#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) \
 || defined(STM32F373xC) || defined(STM32F378xx)
#define OB_WRP_PAGES32TO47MASK         (0x00FF0000U)
#define OB_WRP_PAGES48TO127MASK        (0xFF000000U)
#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)
#define OB_WRP_PAGES32TO47MASK         (0x00FF0000U)
#define OB_WRP_PAGES48TO255MASK        (0xFF000000U)
#endif

#if defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) \
 || defined(STM32F373xC) || defined(STM32F378xx)
#define OB_WRP_PAGES32TO47MASK         (0x00FF0000U)
#define OB_WRP_PAGES48TO127MASK        (0xFF000000U)
#endif


#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) \
 || defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) \
 || defined(STM32F373xC) || defined(STM32F378xx)
#define OB_WRP_ALLPAGES                (0xFFFFFFFFU)
#endif



#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) \
 || defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx)
#define OB_WRP_ALLPAGES                (0x0000FFFFU)
#endif









#define OB_RDP_LEVEL_0             ((uint8_t)0xAAU)
#define OB_RDP_LEVEL_1             ((uint8_t)0xBBU)
#define OB_RDP_LEVEL_2             ((uint8_t)0xCCU)








#define OB_IWDG_SW                 ((uint8_t)0x01U)
#define OB_IWDG_HW                 ((uint8_t)0x00U)







#define OB_STOP_NO_RST             ((uint8_t)0x02U)
#define OB_STOP_RST                ((uint8_t)0x00U)







#define OB_STDBY_NO_RST            ((uint8_t)0x04U)
#define OB_STDBY_RST               ((uint8_t)0x00U)







#define OB_BOOT1_RESET             ((uint8_t)0x00U)
#define OB_BOOT1_SET               ((uint8_t)0x10U)







#define OB_VDDA_ANALOG_ON          ((uint8_t)0x20U)
#define OB_VDDA_ANALOG_OFF         ((uint8_t)0x00U)







#define OB_SRAM_PARITY_SET         ((uint8_t)0x00U)
#define OB_SRAM_PARITY_RESET       ((uint8_t)0x40U)





#if defined(FLASH_OBR_SDADC12_VDD_MONITOR)



#define OB_SDACD_VDD_MONITOR_RESET           ((uint8_t)0x00U)
#define OB_SDACD_VDD_MONITOR_SET             ((uint8_t)0x80U)




#endif




#define OB_DATA_ADDRESS_DATA0     (0x1FFFF804U)
#define OB_DATA_ADDRESS_DATA1     (0x1FFFF806U)





















HAL_StatusTypeDef  HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError);
HAL_StatusTypeDef  HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);









HAL_StatusTypeDef  HAL_FLASHEx_OBErase(void);
HAL_StatusTypeDef  HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
void               HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);
uint32_t           HAL_FLASHEx_OBGetUserData(uint32_t DATAAdress);

















#ifdef __cplusplus
}
#endif

#endif



