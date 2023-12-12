#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include <fcntl.h>

int  set_fl(int fd, int flags) // flags are file status flags to turn on
{
    int val;
    if ( (val = fcntl(fd, F_GETFL , 0)) < 0)
    {
        printf("fcntl F_GETFL error");
        return -1;
    }

    val |= flags; // turn on flags

    if (fcntl(fd, F_SETFL, val) < 0)
    {
        printf("fcntl F_SETFL error");
        return -1;
    }
    return 0;
}

int  clr_fl(int fd, int flags) // flags are file status flags to turn off
{
    int val;
    if ( (val = fcntl(fd, F_GETFL , 0)) < 0)
    {
        printf("fcntl F_GETFL error");
        return -1;
    }

    val &= ~flags; // turn off flags

    if (fcntl(fd, F_SETFL, val) < 0)
    {
        printf("fcntl F_SETFL error");
        return -1;
    }
    return 0;
}


int main(int argc, char *argv[])
{
    int val;
    if (argc != 2){
        printf("usage: FD <descriptor#>");
        return -1;
    }

    // when using the `F_GETFL` operation, the third argument is typically ignored or set to 0.
    if ( (val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0){
        printf("fcntl error for fd %d", atoi(argv[1]));
        return -1;
    }

    // By utilizing bitwise operations and a mask, `val & O_ACCMODE` preserves the portion of files status flags related to access mode, while zeroing out other bits. 
    switch (val & O_ACCMODE)
    {
    case O_RDONLY:
        printf("read only");
        break;
    case O_WRONLY:
        printf("write only");
        break;
    case O_RDWR:
        printf("read write");
        break;
    default:
        printf("unknown access mode");
        return -1;
    }
    
    if (val & O_APPEND) printf(", append");
    if (val & O_NONBLOCK) printf(", nonblocking");
    if (val & O_SYNC) printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC) printf(", synchronous writes");
#endif

    putchar('\n');
    return 0;
}
/*
firmon@ubt:~/Dev/apue/apue_ubuntu/section_3/out$ ./fd 0 < /dev/tty
read only
firmon@ubt:~/Dev/apue/apue_ubuntu/section_3/out$ ./fd 1 > temp.foo
firmon@ubt:~/Dev/apue/apue_ubuntu/section_3/out$ cat temp.foo 
write only
firmon@ubt:~/Dev/apue/apue_ubuntu/section_3/out$ ./fd 2 2>>temp.foo 
write only, append
firmon@ubt:~/Dev/apue/apue_ubuntu/section_3/out$ ./fd 5 5<>temp.foo
read write
*/