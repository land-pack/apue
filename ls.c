
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int
main(int argc, char *argv[])
{
    DIR             *dp;
    struct dirent   *dirp;

    if (argc != 2){
       // err_quit("Usage: ls directory_name");
       perror("Usage: ls directory_name");
       exit(-1);
    }

    if ((dp = opendir(argv[1])) == NULL){
            //err_sys("can't open %s", argv[1]);
       perror("Can't open file");
       exit(-1);
    }
    printf("file name is [%s]\n", argv[1]);
    while ((dirp = readdir(dp)) != NULL)
       printf("%s\n", dirp->d_name);

    closedir(dp);
    exit(0);
}
