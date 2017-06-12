#pragma once

#include <stdint.h>

uint8_t decode_85(uint8_t *dst, uint8_t *buffer, uint8_t len);

void encode_85(uint8_t *buf, uint8_t *data, uint8_t bytes);
