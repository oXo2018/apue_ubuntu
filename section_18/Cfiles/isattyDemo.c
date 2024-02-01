#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

int main (void)
{
    printf("fd 0 : %s\n", isatty(0) ? "tty" : "not a tty");
    printf("fd 1 : %s\n", isatty(1) ? "tty" : "not a tty");
    printf("fd 2 : %s\n", isatty(2) ? "tty" : "not a tty");

    return 0;
}
/*
firmon@ubt:~/Dev/apue/apue_ubuntu/section_18/out$ ./isattyDemo 
fd 0 : tty
fd 1 : tty
fd 2 : tty
firmon@ubt:~/Dev/apue/apue_ubuntu/section_18/out$ ./isattyDemo  </etc/passwd 2>/dev/null
fd 0 : not a tty
fd 1 : tty
fd 2 : not a tty


stdin is defined to be file descriptor 0, stdout is defined to be file descriptor 1; and stderr is defined to be file descriptor 2.
*/