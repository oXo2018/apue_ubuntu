#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

int main (void)
{
    struct termios  term;
    long    vdisable;

    /*
    Return 1 if FD is a valid descriptor associated with a terminal, zero if not.  
        extern int isatty (int __fd) __THROW;
    */
    if (isatty(STDIN_FILENO) == 0)
    {
        printf("standard input is not a terminal device");
        return -1;
    }

    /*
    Get file-specific configuration about descriptor FD.  
            extern long int fpathconf (int __fd, int __name) __THROW;
    */
    if ( (vdisable = fpathconf(STDIN_FILENO, _PC_VDISABLE)) < 0)
    {
        printf("fpathconf error or _POSIX_VDISABLE not in effect");
        return -2;
    }

    /* 
    Put the state of FD into *TERMIOS_P.  
        extern int tcgetattr (int __fd, struct termios *__termios_p) __THROW;
    */
    if (tcgetattr(STDIN_FILENO, &term) < 0) /* fetch tty state*/
    {
        printf("tcgetattr error");
        return -3;
    }

    term.c_cc[VINTR] = vdisable; /*diable INTR character*/
    term.c_cc[VEOF] = 2; /* EOF is Control-B */

    /*
    Set the state of FD to *TERMIOS_P. Values for OPTIONAL_ACTIONS (TCSA*) are in <bits/termios.h>.  
        extern int tcsetattr (int __fd, int __optional_actions, const struct termios *__termios_p) __THROW;
    */
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) < 0)
    {
        printf("tcsetattr error");
        return -4;
    }
    else{
        printf("tcsetattr ok!\n");
    }
    
    return 0;




    
    
    
}