#ifndef SERIAL
#define SERIAL

#include <stdint.h>

int serial_init(int, uint32_t, uint8_t);
void serail_write(uint8_t);

#endif