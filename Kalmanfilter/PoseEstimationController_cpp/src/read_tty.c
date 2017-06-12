#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>    
#include "base85.h"
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

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main(int argc, char* argv[]) {
    char buffer[MAXBYTES];
	char buf_decode[55];
	sensorData_t decoded;
	int count, count_decode, count_msgs;
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

   	gettimeofday(&t0, 0);
	FILE *fp;
	fp=fopen(argv[1], "w");
	fprintf(fp, "timestamp,accSmooth[0],accSmooth[1],accSmooth[2],gyroADC[0],gyroADC[1],gyroADC[2],baroAlt,baroTemp,magADC[0],magADC[1],magADC[2]\n");

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
				fprintf(fp, "%s%06ld+02:00,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\n", buff, t1.tv_usec, decoded.values.accSmooth[0], decoded.values.accSmooth[1], decoded.values.accSmooth[2], decoded.values.gyroADC[0], decoded.values.gyroADC[1], decoded.values.gyroADC[2], decoded.values.baroAlt, decoded.values.baroTemp, decoded.values.magADC[0], decoded.values.magADC[1], decoded.values.magADC[2]);
				count_decode = 0;
				count_msgs++;
			} else {
				buf_decode[count_decode] = buffer[i];
				count_decode++;
			}
		}
	}
	fclose(fp);
    return 0;
}
