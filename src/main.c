/**
 * Author: Joe Biwer
 * Description: Reading data from a serial port streamed to an output file
 */


#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>

#include <string.h>

#include "../inc.h"
#include "serial.h"


int main(void) {

    FILE *fp;

    fp = fopen(OUTPUT_FILE, "w");
    fprintf(fp, "writing to file\n");

    char *portname = "/dev/tty.JOEBT3-DevB";

    int serial_fd = open (portname, O_RDWR | O_NOCTTY | O_NONBLOCK);
    if( serial_fd < 0) {
        printf("error opening serial port: %d\n", serial_fd);
        return 0;
    }

    int err = serial_init(serial_fd, B9600, 0);        // File descriptor (passed by ref), baud rate, parity
    if( err < 0) {
        printf("error initializing serial port\n");
        return 0;
    }

    char buff[128];

    char input_buffer[10];
    printf("Ready to interface with hardware\n");
    do {
        scanf("%s", input_buffer);
        write(serial_fd, input_buffer, 2);
        int bytes = read(serial_fd, buff, 128);
        if (bytes > 0) {
            printf("%s\n", buff);
        }
        sleep(1);
    } while(strcmp(input_buffer, "q"));

    return 0;

}