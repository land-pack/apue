#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int
main(void)
{
    int     c;
    while ((c = getc(stdin)) != EOF)
        if(putc(c, stdout) == EOF){
            perror("Output error");
            exit(-1);
        }
    
    if (ferror(stdin)){
        perror("input error");
        exit(-1);
     }

     exit(0);
}

    

