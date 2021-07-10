#pragma once

#define I2C_STRUCTS_VERSION 1

#include <applibs/log.h>
#include <applibs/i2c.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

#define AS1115_REG_DECODE        0x09                        // "decode mode" register
#define AS1115_REG_INTENSITY     0x0a                        // "intensity" register
#define AS1115_REG_SCAN_LIMIT    0x0b                        // "scan limit" register
#define AS1115_REG_SHUTDOWN      0x0c                        // "shutdown" register
#define AS1115_REG_DISPLAY_TEST  0x0f                        // "display test" register
#define KEYA_r 0x1C

#define AS1115_I2C_ADDRESS		0x00

typedef struct {
	I2C_InterfaceId interfaceId;
	int handle;
	union {
		unsigned char bitmap[8];
		uint64_t bitmap64;
	};
	uint16_t keypad;	
} as1115_t;

void as1115_clear(as1115_t* retro_click);
void as1115_display_test(as1115_t* retro_click, bool state);
bool as1115_init(as1115_t* retro_click, unsigned char intialBrightness);
void as1115_panel_clear(as1115_t* retro_click);
void as1115_panel_write(as1115_t* retro_click);
void as1115_set_brightness(as1115_t* retro_click, unsigned char brightness);
void as1115_write(as1115_t* retro_click, unsigned char reg_number, unsigned char dataout);
bool as1115_read_key(as1115_t* retro_click);
