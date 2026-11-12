








#ifndef LPS25HB_H
#define LPS25HB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


typedef uint8_t (*lps25hb_transfer_cb)(uint8_t slave_address, uint8_t register_address, uint8_t *data, uint16_t len);


#define LPS25HB_I2C_ADDRESS        (0xBAU)


#define LPS25HB_WHO_AM_I_REG       (0x0FU)
#define LPS25HB_CTRL_REG1          (0x20U)
#define LPS25HB_CTRL_REG2          (0x21U)
#define LPS25HB_CTRL_REG3          (0x22U)
#define LPS25HB_CTRL_REG4          (0x23U)
#define LPS25HB_RES_CONF_REG       (0x10U)
#define LPS25HB_PRESS_OUT_XL_REG   (0x28U)
#define LPS25HB_TEMP_OUT_L_REG     (0x2BU)


#define LPS25HB_WHO_AM_I_VALUE     (0xBDU)


#define LPS25HB_PD_ENABLE          (0x80U)
#define LPS25HB_ODR_ONE_SHOT       (0x00U)
#define LPS25HB_ODR_1HZ            (0x10U)
#define LPS25HB_ODR_7HZ            (0x20U)
#define LPS25HB_ODR_12_5HZ         (0x30U)
#define LPS25HB_ODR_25HZ           (0x40U)
#define LPS25HB_BDU_ENABLE         (0x04U)
#define LPS25HB_CTRL_REG1_CONFIG   (LPS25HB_PD_ENABLE | LPS25HB_ODR_7HZ | LPS25HB_BDU_ENABLE)


#define LPS25HB_RES_CONF_CONFIG    (0x05U)


#define LPS25HB_PRESS_LSB_PER_HPA  (4096.0f)
#define LPS25HB_TEMP_OFFSET_DEGC   (42.5f)
#define LPS25HB_TEMP_LSB_PER_DEGC  (480.0f)


#define LPS25HB_SEA_LEVEL_HPA      (1013.25f)

uint8_t lps25hb_init(lps25hb_transfer_cb read_cb, lps25hb_transfer_cb write_cb);
uint8_t lps25hb_read_pressure(float *pressure_hpa);
uint8_t lps25hb_read_temperature(float *temperature_deg_c);
float   lps25hb_calc_altitude(float pressure_hpa, float sea_level_hpa);

#ifdef __cplusplus
}
#endif

#endif
