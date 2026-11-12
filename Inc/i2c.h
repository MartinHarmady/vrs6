


















#ifndef __i2c_H
#define __i2c_H
#ifdef __cplusplus
 extern "C" {
#endif


#include "main.h"









void MX_I2C1_Init(void);














typedef uint8_t (*i2c_transfer_cb)(uint8_t slave_address, uint8_t register_address, uint8_t *data, uint16_t len);

uint8_t i2c_master_read(uint8_t slave_address, uint8_t register_address, uint8_t *data, uint16_t len);
uint8_t i2c_master_write(uint8_t slave_address, uint8_t register_address, uint8_t *data, uint16_t len);


#ifdef __cplusplus
}
#endif
#endif










