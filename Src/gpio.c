



















#include "gpio.h"













void MX_GPIO_Init(void)
{


  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);


  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);

}






