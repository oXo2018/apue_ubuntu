#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#define BUFFSIZE 4096

int main (void)
{
    int n;
    char buf[BUFFSIZE];

    while ( (n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)  printf("write error");
    }

    if ( n < 0 ) printf("read error");

    return 0;
    
}

/*
    All normal UNIX system shells provide a way to open a file for reading on standard input and to create(or rewrite) a file on standard output.
    The program doesn't close the input file or output file. Instead, the program used the feature of the UNIX kernel that closes all open file descriptors in a process when that process terminates.
    This example works for both text files and binary files.

    *** the buff size sets beyond st_blksize value (4096-byts blocks) has little positive performance! 
*/