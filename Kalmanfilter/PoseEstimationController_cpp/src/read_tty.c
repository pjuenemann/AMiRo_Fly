#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>    
//#include <base85.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>

#define MAXBYTES 1024

typedef union {
    uint8_t data[44];
    struct {
        int32_t accSmooth[3];
        int32_t gyroADC[3];
        int32_t baroAlt;
        int32_t baroTemp;
        int32_t magADC[3];
    } values;
} sensorData_t;

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

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main(int argc, char* argv[]) {
    printf("0");
    char buffer[MAXBYTES];
    char buf_decode[55];
    sensorData_t decoded;
    int count, count_decode, count_msgs;
    printf("1");
    int fd = open("/dev/ttyACM0", O_RDWR);
    char buf = '#';
    write(fd, &buf, 1);
    count_decode = 0;
    count_msgs = 0;
    
    struct timeval t0;
    struct timeval t1;
    float elapsed;
    time_t mtime;
    char buff[80];
    struct tm * timeinfo;

    /*gettimeofday(&t0, 0);
    FILE *fp;
    fp=fopen(argv[1], "w");
    fprintf(fp, "timestamp,accSmooth[0],accSmooth[1],accSmooth[2],gyroADC[0],gyroADC[1],gyroADC[2],baroAlt,baroTemp,magADC[0],magADC[1],magADC[2]\n");
*/
    while(1) {
		count = read(fd, buffer, MAXBYTES); //TODO: check when read finished
		gettimeofday(&t1, 0);
   		//elapsed = timedifference_msec(t0, t1);
		//if (elapsed > 1000) {
		//	printf("Messages/Second: %i\n", count_msgs);
		//	gettimeofday(&t0, 0);
		//	count_msgs = 0;
		//}

		for (int i = 0; i < count; i++) {
			if (buffer[i] == '\n') {
				// decode data and put into struct
				decode_85(decoded.data, (uint8_t*) buf_decode, 55);
				time(&mtime);				
				timeinfo = localtime (&mtime);
				strftime(buff, sizeof(buff), "%Y-%m-%dT%H:%M:%S.", timeinfo);
				// print with timestamp formatted in same way as in data from TWB
				printf("%s%06ld+02:00,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\n", buff, t1.tv_usec, decoded.values.accSmooth[0], decoded.values.accSmooth[1], decoded.values.accSmooth[2], decoded.values.gyroADC[0], decoded.values.gyroADC[1], decoded.values.gyroADC[2], decoded.values.baroAlt, decoded.values.baroTemp, decoded.values.magADC[0], decoded.values.magADC[1], decoded.values.magADC[2]);
				count_decode = 0;
				count_msgs++;
			} else {
				buf_decode[count_decode] = buffer[i];
				count_decode++;
			}
		}
	}
	//fclose(fp);
    return 0;
}
