#include <string.h>
#include <stdio.h>
#include "base85.h"

static const uint8_t en85[] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
	'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
	'u', 'v', 'w', 'x', 'y', 'z',
	'!', '#', '$', '%', '&', '(', ')', '*', '+', '-',
	';', '<', '=', '>', '?', '@', '^', '_',	'`', '{',
	'|', '}', '~'
};

static uint8_t de85[256];
static void prep_base85(void)
{
	uint8_t i;
	if (de85['Z'])
		return;
	for (i = 0; i < 85; i++) {
		uint8_t ch = en85[i];
		de85[ch] = i + 1;
	}
}

uint8_t decode_85(uint8_t *dst, uint8_t *buffer, uint8_t len)
{
	prep_base85();

	while (len) {
		unsigned acc = 0;
		int32_t de, cnt = 4;
		uint8_t ch;
		do {
			ch = *buffer++;
			de = de85[ch];
			if (--de < 0)
				return -1;
			acc = acc * 85 + de;
		} while (--cnt);
		ch = *buffer++;
		de = de85[ch];
		if (--de < 0)
			return -1;
		/* Detect overflow. */
		if (0xffffffff / 85 < acc ||
		    0xffffffff - de < (acc *= 85))
			return -1;
		acc += de;

		cnt = (len < 4) ? len : 4;
		len -= cnt;
		do {
			acc = (acc << 8) | (acc >> 24);
			*dst++ = acc;
		} while (--cnt);
	}

	return 0;
}

void encode_85(uint8_t *buf, uint8_t *data, uint8_t bytes)
{
	while (bytes) {
		unsigned acc = 0;
    int8_t cnt;
		for (cnt = 24; cnt >= 0; cnt -= 8) {
			unsigned ch = *data++;
			acc |= ch << cnt;
			if (--bytes == 0)
				break;
		}
		for (cnt = 4; cnt >= 0; cnt--) {
			uint32_t val = acc % 85;
			acc /= 85;
			buf[cnt] = en85[val];
		}
		buf += 5;
	}

	*buf = 0;
}
