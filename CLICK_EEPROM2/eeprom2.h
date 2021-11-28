/* Copyright (c) Microsoft Corporation. All rights reserved.
   Licensed under the MIT License. */

#pragma once

#include "applibs/spi.h"
#include "applibs/log.h"
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

bool eeprom2_init(SPI_InterfaceId interfaceId, SPI_ChipSelectId chipSelectId);
int eeprom2_read(uint32_t memory_address, uint8_t *value);
int eeprom2_memory_enable(void);
int eeprom2_read_bytes(uint32_t memory_address, uint8_t *value, uint8_t count);
int eeprom2_write(uint32_t memory_address, uint8_t value);
int eeprom2_write_bytes(uint32_t memory_address, uint8_t *value, uint8_t count);