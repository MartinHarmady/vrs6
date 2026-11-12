


















#ifndef __USART_H
#define __USART_H

#ifdef __cplusplus
extern "C" {
#endif


#include "main.h"





void MX_USART2_Init(void);

void usart_send_string(const char *string);
void usart_format_fixed(char *buffer, int32_t value, uint8_t decimals);


#ifdef __cplusplus
}
#endif

#endif










