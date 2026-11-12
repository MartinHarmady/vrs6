



#include "lps25hb.h"
#include <math.h>


static lps25hb_transfer_cb lps25hb_read_reg;
static lps25hb_transfer_cb lps25hb_write_reg;






static uint8_t lps25hb_read_raw_pressure(int32_t *raw_press)
{
	uint8_t buf[3];
	int32_t value;

	if ((lps25hb_read_reg == NULL) || (raw_press == NULL))
	{
		return 1U;
	}
	if (0U != lps25hb_read_reg(LPS25HB_I2C_ADDRESS, LPS25HB_PRESS_OUT_XL_REG, buf, 3U))
	{
		return 1U;
	}


	value = ((int32_t)buf[2] << 16) | ((int32_t)buf[1] << 8) | (int32_t)buf[0];
	if ((value & 0x00800000L) != 0L)
	{
		value |= 0xFF000000L;
	}
	*raw_press = value;
	return 0U;
}






static uint8_t lps25hb_read_raw_temperature(int16_t *raw_temp)
{
	uint8_t buf[2];

	if ((lps25hb_read_reg == NULL) || (raw_temp == NULL))
	{
		return 1U;
	}
	if (0U != lps25hb_read_reg(LPS25HB_I2C_ADDRESS, LPS25HB_TEMP_OUT_L_REG, buf, 2U))
	{
		return 1U;
	}


	*raw_temp = (int16_t)((uint16_t)buf[0] | ((uint16_t)buf[1] << 8));
	return 0U;
}









uint8_t lps25hb_init(lps25hb_transfer_cb read_cb, lps25hb_transfer_cb write_cb)
{
	uint8_t who_am_i;
	uint8_t config;

	if ((read_cb == NULL) || (write_cb == NULL))
	{
		return 1U;
	}
	lps25hb_read_reg  = read_cb;
	lps25hb_write_reg = write_cb;


	if (0U != read_cb(LPS25HB_I2C_ADDRESS, LPS25HB_WHO_AM_I_REG, &who_am_i, 1U))
	{
		return 1U;
	}
	if (who_am_i != LPS25HB_WHO_AM_I_VALUE)
	{
		return 1U;
	}


	config = LPS25HB_RES_CONF_CONFIG;
	if (0U != write_cb(LPS25HB_I2C_ADDRESS, LPS25HB_RES_CONF_REG, &config, 1U))
	{
		return 1U;
	}
	config = LPS25HB_CTRL_REG1_CONFIG;
	if (0U != write_cb(LPS25HB_I2C_ADDRESS, LPS25HB_CTRL_REG1, &config, 1U))
	{
		return 1U;
	}
	return 0U;
}






uint8_t lps25hb_read_pressure(float *pressure_hpa)
{
	int32_t raw;

	if (0U != lps25hb_read_raw_pressure(&raw))
	{
		return 1U;
	}
	*pressure_hpa = (float)raw / LPS25HB_PRESS_LSB_PER_HPA;
	return 0U;
}






uint8_t lps25hb_read_temperature(float *temperature_deg_c)
{
	int16_t raw;

	if (0U != lps25hb_read_raw_temperature(&raw))
	{
		return 1U;
	}
	*temperature_deg_c = LPS25HB_TEMP_OFFSET_DEGC + (float)raw / LPS25HB_TEMP_LSB_PER_DEGC;
	return 0U;
}










float lps25hb_calc_altitude(float pressure_hpa, float sea_level_hpa)
{
	return 44330.0f * (1.0f - powf(pressure_hpa / sea_level_hpa, 0.1902949572f));
}
