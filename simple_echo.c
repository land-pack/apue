#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define BUFFSIZE 4096

int
main(void)
{
    int     n;
    char    buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
        if (write(STDOUT_FILENO, buf, n) != n){
            perror("Write error");
            exit(-1);
        }
    }

    if (n < 0){
        perror("Read error");
        exit(-1);
    }

    exit(0);
}



