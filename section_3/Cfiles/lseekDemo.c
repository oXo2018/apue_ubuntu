#include "stdio.h"
#include <unistd.h>

/* Move FD's file position to OFFSET bytes from the
   beginning of the file (if WHENCE is SEEK_SET),
   the current position (if WHENCE is SEEK_CUR),
   or the end of the file (if WHENCE is SEEK_END).
   Return the new file position.  */

// extern __off_t lseek (int __fd, __off_t __offset, int __whence) __THROW;
// typedef long __off_t  Type of file sizes and offsets.

/* Standard file descriptors.  */
// #define	STDIN_FILENO	0	/* Standard input.  */
// #define	STDOUT_FILENO	1	/* Standard output.  */
// #define	STDERR_FILENO	2	/* Standard error output.  */

int main (void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) printf("cannnot seek\n");
    else printf("seek OK\n");

    return 0;
}

/*
The function lseek can also be used to determine if a file is capable of seeking. If the file descriptor refers to a pipe, FIFO, or socket, lseek sets errno to ESPIPE and returns -1.

    ./lseekDemo < /etc/passwd --> seek OK
        In the Unix/Linux command line, the '<' symbol is used for input redirection, specifically to redirect the content of a file to the standard input of a command.

    cat < /etc/passwd | ./lseekDemo  --> cannnot seek
        `|`: This is the pipe symbol, which is used to connect the output of one command to the input of another. In this case, it takes the output of `cat` and sends it as input to the next command.

    ./lseekDemo  < /var/spool/cron/FIFO  --> cannnot seek
*/