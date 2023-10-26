#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main (int argc, char* argv[])
{
    fprintf(stderr, "EACCESS: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]); //  extern void perror (const char *__s);  this function will print the s and descript that the errno mean. So much power function. 
    exit(0);
}