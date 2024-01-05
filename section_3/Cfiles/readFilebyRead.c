#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


#define BUFFSIZE 4096
int main ()
{
    char* file = "1.txt";
    int fileFD;
    char readbuf[BUFFSIZE];
    const char* writebuf = "Hello World! from firmon";

    // open the file with read and write mode and set O_SYNC to ask kernel write immediately.
    // AT_FDCWD  == -1 , AT_FDCWD is special file descriptor for the current working directory. 
    // The vscode think AT_FDCWD cannot find definition just due to openat function above have `#ifdef __USE_ATFILE` in fcntl.h. Just ignore it!!!
    /*
        firmon@ubt:~/Dev/apue/apue_ubuntu/section_3/Cfiles$ cc readFilebyRead.c  -o ../out/readFilebyRead
        readFilebyRead.c:7: warning: "__USE_ATFILE" redefined
                7 | #define __USE_ATFILE
                    | 
                In file included from /usr/include/x86_64-linux-gnu/bits/libc-header-start.h:33,
                 from /usr/include/stdio.h:27,
                 from readFilebyRead.c:1:
            /usr/include/features.h:399: note: this is the location of the previous definition
                399 | # define __USE_ATFILE   1
    */
    // openat(AT_FDCWD, file, O_RDWR|O_SYNC))
    if ( (fileFD = open(file, O_RDWR|O_SYNC)) == -1) // If the first parameter is absolute pathname, then open it. If pathname is relative pathname, will use the current dirtory to join it!!!.
    {   
        printf("open file error\n");
        return -1;
    }
    
    if (read(fileFD, readbuf, 100) == -1)
    {
        printf("read file error\n");
        return -2;
    }

    printf("The content of file is : %s \n", readbuf);

    // strlen()
    if (write(fileFD, writebuf, strlen(writebuf)) == -1)
    {
        printf("write file error\n");
        return -2;
    }

    printf("Write %s to file is OK \n", writebuf);

    return 0;

}
