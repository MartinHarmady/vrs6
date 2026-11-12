




















#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"
#include "lps25hb.h"
#include "hts221.h"


#include <stdio.h>



#define LED_PIN   LL_GPIO_PIN_3
#define LED_PORT  GPIOB







#define TEMP_DECIMALS      1U
#define HUM_DECIMALS       0U
#define PRESS_DECIMALS     2U
#define ALT_DECIMALS       2U


#define PERIOD_MS          100U

void SystemClock_Config(void);








int main(void)
{

  float temperature;
  float humidity;
  float pressure;
  float altitude;
  char temp_str[16];
  char hum_str[16];
  char press_str[16];
  char alt_str[16];
  char csv_line[64];
  int line_len;


  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  SystemClock_Config();

  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_Init();




  while ((0U != lps25hb_init(i2c_master_read, i2c_master_write)) ||
         (0U != hts221_init(i2c_master_read, i2c_master_write)))
  {

    LL_GPIO_TogglePin(LED_PORT, LED_PIN);
    LL_mDelay(PERIOD_MS);
  }
  LL_GPIO_SetOutputPin(LED_PORT, LED_PIN);


  while (1)
  {

    if ((0U == hts221_read_temperature(&temperature)) &&
        (0U == hts221_read_humidity(&humidity)) &&
        (0U == lps25hb_read_pressure(&pressure)))
    {

      altitude = lps25hb_calc_altitude(pressure, LPS25HB_SEA_LEVEL_HPA);


      usart_format_fixed(temp_str, (int32_t)(temperature * 10.0f), TEMP_DECIMALS);
      usart_format_fixed(hum_str, (int32_t)(humidity * 1.0f + 0.5f), HUM_DECIMALS);
      usart_format_fixed(press_str, (int32_t)(pressure * 100.0f), PRESS_DECIMALS);
      usart_format_fixed(alt_str, (int32_t)(altitude * 100.0f), ALT_DECIMALS);


      line_len = snprintf(csv_line, sizeof(csv_line), "%s,%s,%s,%s\r\n",
                          temp_str, hum_str, press_str, alt_str);
      if (line_len > 0)
      {
        usart_send_string(csv_line);
      }
      LL_GPIO_TogglePin(LED_PORT, LED_PIN);
    }



    LL_mDelay(PERIOD_MS);

  }
}





void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

  if(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_0)
  {
  Error_Handler();
  }
  LL_RCC_HSI_Enable();


  while(LL_RCC_HSI_IsReady() != 1)
  {

  }
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);


  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {

  }
  LL_Init1msTick(8000000);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
  LL_SetSystemCoreClock(8000000);
  LL_RCC_SetI2CClockSource(LL_RCC_I2C1_CLKSOURCE_HSI);
}






void Error_Handler(void)
{




}

#ifdef  USE_FULL_ASSERT







void assert_failed(char *file, uint32_t line)
{




}
#endif


