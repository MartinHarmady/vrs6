



#include "hts221.h"
#include <math.h>


static hts221_transfer_cb hts221_read_reg;
static hts221_transfer_cb hts221_write_reg;


static float hts221_h0_rh;
static float hts221_h1_rh;
static float hts221_t0_deg_c;
static float hts221_t1_deg_c;
static float hts221_h0_t0_out;
static float hts221_h1_t0_out;
static float hts221_t0_out;
static float hts221_t1_out;







static uint8_t hts221_read_raw_output(uint8_t reg_addr, int16_t *raw)
{
	uint8_t buf[2];

	if (0U != hts221_read_reg(HTS221_I2C_ADDRESS, reg_addr, buf, 2U))
	{
		return 1U;
	}

	*raw = (int16_t)((uint16_t)buf[0] | ((uint16_t)buf[1] << 8));
	return 0U;
}





static uint8_t hts221_read_calibration(void)
{
	uint8_t calib[HTS221_CALIB_BYTES];
	int16_t h0_t0_out;
	int16_t h1_t0_out;
	int16_t t0_out;
	int16_t t1_out;

	if (0U != hts221_read_reg(HTS221_I2C_ADDRESS, HTS221_CALIB_START_REG, calib, HTS221_CALIB_BYTES))
	{
		return 1U;
	}


	hts221_h0_rh = (float)calib[0x00U] / 2.0f;
	hts221_h1_rh = (float)calib[0x01U] / 2.0f;


	hts221_t0_deg_c = (float)((((uint16_t)calib[0x05U] & 0x03U) << 8) | calib[0x02U]) / 8.0f;
	hts221_t1_deg_c = (float)((((uint16_t)calib[0x05U] & 0x0CU) << 6) | calib[0x03U]) / 8.0f;


	h0_t0_out = (int16_t)((uint16_t)calib[0x06U] | ((uint16_t)calib[0x07U] << 8));
	h1_t0_out = (int16_t)((uint16_t)calib[0x0AU] | ((uint16_t)calib[0x0BU] << 8));
	t0_out    = (int16_t)((uint16_t)calib[0x0CU] | ((uint16_t)calib[0x0DU] << 8));
	t1_out    = (int16_t)((uint16_t)calib[0x0EU] | ((uint16_t)calib[0x0FU] << 8));

	hts221_h0_t0_out = (float)h0_t0_out;
	hts221_h1_t0_out = (float)h1_t0_out;
	hts221_t0_out    = (float)t0_out;
	hts221_t1_out    = (float)t1_out;


	if ((hts221_h1_t0_out == hts221_h0_t0_out) || (hts221_t1_out == hts221_t0_out))
	{
		return 1U;
	}
	return 0U;
}









uint8_t hts221_init(hts221_transfer_cb read_cb, hts221_transfer_cb write_cb)
{
	uint8_t config;

	if ((read_cb == NULL) || (write_cb == NULL))
	{
		return 1U;
	}
	hts221_read_reg  = read_cb;
	hts221_write_reg = write_cb;


	uint8_t who_am_i;
	if (0U != read_cb(HTS221_I2C_ADDRESS, HTS221_WHO_AM_I_REG, &who_am_i, 1U))
	{
		return 1U;
	}
	if (who_am_i != HTS221_WHO_AM_I_VALUE)
	{
		return 1U;
	}


	config = HTS221_AV_CONF_CONFIG;
	if (0U != write_cb(HTS221_I2C_ADDRESS, HTS221_AV_CONF_REG, &config, 1U))
	{
		return 1U;
	}
	config = HTS221_CTRL_REG1_CONFIG;
	if (0U != write_cb(HTS221_I2C_ADDRESS, HTS221_CTRL_REG1, &config, 1U))
	{
		return 1U;
	}

	return hts221_read_calibration();
}







uint8_t hts221_read_humidity(float *humidity_rh)
{
	int16_t raw;
	float value;

	if ((hts221_read_reg == NULL) || (humidity_rh == NULL))
	{
		return 1U;
	}
	if (0U != hts221_read_raw_output(HTS221_HUMIDITY_OUT_L_REG, &raw))
	{
		return 1U;
	}


	value = hts221_h0_rh + ((float)raw - hts221_h0_t0_out)
	        * (hts221_h1_rh - hts221_h0_rh) / (hts221_h1_t0_out - hts221_h0_t0_out);

	if (value < 0.0f)
	{
		value = 0.0f;
	}
	if (value > 100.0f)
	{
		value = 100.0f;
	}
	*humidity_rh = value;
	return 0U;
}






uint8_t hts221_read_temperature(float *temperature_deg_c)
{
	int16_t raw;

	if ((temperature_deg_c == NULL) || (hts221_read_reg == NULL))
	{
		return 1U;
	}
	if (0U != hts221_read_raw_output(HTS221_TEMP_OUT_L_REG, &raw))
	{
		return 1U;
	}


	*temperature_deg_c = hts221_t0_deg_c + ((float)raw - hts221_t0_out)
	                     * (hts221_t1_deg_c - hts221_t0_deg_c) / (hts221_t1_out - hts221_t0_out);
	return 0U;
}
