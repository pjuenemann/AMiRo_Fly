#include <stdint.h>
#include <stdio.h>
#include "base85.h"

/* commands as in serial_cli of FC
 typedef enum {
 	CMD_ROLL        = 0x0,
	CMD_PITCH       = 0x1,
	CMD_YAW         = 0x2,
	CMD_THROTTLE    = 0x3,
	CMD_AUX1		= 0x4,
	CMD_AUX2		= 0x5,
	CMD_AUX3		= 0x6,
	CMD_AUX4		= 0x7,
	CMD_AUX5		= 0x8,
	CMD_AUX6		= 0x9,
	CMD_AUX7		= 0xA,
	CMD_AUX8		= 0xB,
	CMD_GET	        = 0xC,
	CMD_GET_VALUES	= 0xD
} byteCmd_t; */

int main(int argc, char* argv[]) {
	if (argc > 1) {
		uint8_t buf[5], outbuf[4];
		uint8_t inbuf[4] = {0,0,0x05,0xDC}; // 1 byte: ROLL command, 2 byte: 0 = "empty byte" to have 4 bytes for encoding with base85, 3, 4 bytes: value (3: high byte, 4: low byte)
		encode_85(buf, inbuf, 4);
		printf("encoded: %s\n", buf);
		decode_85(outbuf, buf, 5);
		printf("decoded: %X %X\n", outbuf[2], outbuf[3]);
	}
    int fd = open("/dev/ttyACM0", O_RDWR);
    // send encoded data
	write(fd, &buf, 4);
}
