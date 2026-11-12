








#ifndef HTS221_H
#define HTS221_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


typedef uint8_t (*hts221_transfer_cb)(uint8_t slave_address, uint8_t register_address, uint8_t *data, uint16_t len);


#define HTS221_I2C_ADDRESS        (0xBEU)


#define HTS221_WHO_AM_I_REG       (0x0FU)
#define HTS221_AV_CONF_REG        (0x10U)
#define HTS221_CTRL_REG1          (0x20U)
#define HTS221_CTRL_REG2          (0x21U)
#define HTS221_STATUS_REG         (0x27U)
#define HTS221_HUMIDITY_OUT_L_REG (0x28U)
#define HTS221_TEMP_OUT_L_REG     (0x2AU)
#define HTS221_CALIB_START_REG    (0x30U)


#define HTS221_WHO_AM_I_VALUE     (0xBCU)


#define HTS221_AV_CONF_CONFIG     (0x1BU)


#define HTS221_PD_ENABLE          (0x80U)
#define HTS221_ODR_ONE_SHOT       (0x00U)
#define HTS221_ODR_1HZ            (0x01U)
#define HTS221_ODR_7HZ            (0x02U)
#define HTS221_ODR_12_5HZ         (0x03U)
#define HTS221_BDU_ENABLE         (0x04U)
#define HTS221_CTRL_REG1_CONFIG   (HTS221_PD_ENABLE | HTS221_ODR_7HZ | HTS221_BDU_ENABLE)


#define HTS221_CALIB_BYTES        (16U)

uint8_t hts221_init(hts221_transfer_cb read_cb, hts221_transfer_cb write_cb);
uint8_t hts221_read_humidity(float *humidity_rh);
uint8_t hts221_read_temperature(float *temperature_deg_c);

#ifdef __cplusplus
}
#endif

#endif
