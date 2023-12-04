#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char buf1[] = "adcdefghij";
char buf2[] = "ABCDEFGHIJ";

mode_t FILE_MODE = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; //0644  #include <sys/stat.h>
// set to read and write for the user, and read-only for the group and others

int main(void)
{
    int fd;
    if ( (fd = creat("file.hole", FILE_MODE)) < 0) printf("creat error!");

/*  Write N bytes of BUF to FD.  Return the number written, or -1.
    extern ssize_t write (int __fd, const void *__buf, size_t __n) 
*/

    if ( write(fd, buf1 , 10 ) != 10) printf("buf1 write error!");
    // offset now = 10

    if ( lseek(fd, 16384, SEEK_SET) == -1) printf("lseek error");
    // offset now = 16384

    if ( write(fd, buf2, 10) != 10) printf("buf2 write error");
    // offset now = 16394

    return 0;

}

/*
ls -l file.hole 
-rw-r--r-- 1 firmon firmon 16394 12月  4 23:43 file.hole

od -c file.hole 
0000000   a   d   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000   A   B   C   D   E   F   G   H   I   J
0040012

od command to look at the contents of the file. The -c flag tells it to print the contents as characters.

*/