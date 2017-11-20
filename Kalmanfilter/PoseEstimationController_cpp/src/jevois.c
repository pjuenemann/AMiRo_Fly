#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>    
#include <string.h>

#define MAXBYTES 100

typedef struct {
    int id;
    double x;
    double y;
} Marker_t;

int main(int argc, const char *argv[])
{
    system("echo \"streamoff\" > /dev/ttyACM0");
    system("echo \"setpar serout USB\" > /dev/ttyACM0");
    system("echo \"setmapping 3\" > /dev/ttyACM0");
    system("echo \"setpar serstyle 1\" > /dev/ttyACM0");
    system("echo \"streamon\" > /dev/ttyACM0");
    char buffer[MAXBYTES];
    int fd = open("/dev/ttyACM0", O_RDWR);
    int count;
    char buf;
    int n = 0;
    char *delimiter = " ,";
    char *ptr;
    int c;
    while(1) {
		count = read(fd, &buf, 1);
        if (buf == '\n') {
            Marker_t marker;
            ptr = strtok(buffer, delimiter);
            if (strcmp(ptr,"ArUco") == 0) {
                c = 0;
                while (ptr != NULL) {
                    ptr = strtok(NULL, delimiter);
                    if (c == 0) {
                        marker.id = atoi(ptr);
                    } else if (c == 1) {
                        marker.x = atof(ptr);
                    } else if (c == 2) {
                        marker.y = atof(ptr);
                    } else {
                        ptr = NULL;
                    }
                    c++;
                }
                printf("ID: %d, X: %f, Y: %f\n", marker.id, marker.x, marker.y);
            }
            n = 0;
            memset(buffer,0,MAXBYTES);
        } else {
            buffer[n] = buf;
            n++;
        }
    }

    return 0;
}
