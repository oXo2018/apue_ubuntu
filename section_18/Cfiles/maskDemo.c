#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main (void)
{
    struct termios term;

    if (tcgetattr(STDIN_FILENO, &term) < 0)
    {
        printf("tcgetattr error!");
        return -1;
    }

    switch (term.c_cflag & CSIZE)
    {
    case CS5:
        printf("5 bits/byte \n");
        break;
    case CS6:
        printf("6 bits/byte \n");
        break;
    case CS7:
        printf("7 bits/byte \n");
        break;
    case CS8:
        printf("8 bits/byte \n");
        break;
    default:
        printf("unknown bits/byte \n");
    }

    term.c_cflag &= ~CSIZE; // zero out the bits
    term.c_cflag |= CS8;  // set 8 bits/byte

    printf("print again \n");
    switch (term.c_cflag & CSIZE)
    {
    case CS5:
        printf("5 bits/byte \n");
        break;
    case CS6:
        printf("6 bits/byte \n");
        break;
    case CS7:
        printf("7 bits/byte \n");
        break;
    case CS8:
        printf("8 bits/byte \n");
        break;
    default:
        printf("unknown bits/byte \n");
    }

    if (tcsetattr(STDIN_FILENO, TCSANOW, &term) < 0)
    {
        printf("tcsetattr error");
    }

    return 0;
    
    
}