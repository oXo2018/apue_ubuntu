#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> // include pid_t
#include <signal.h>  // include SIGINT 
#include <string.h> // strlen
#include <sys/wait.h> // watipid

#define	MAXLINE	4096

// our signal-catching funciton
static void sig_int(int);


int main ()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR) printf("signal error");

    printf("%% "); // print prompt

    // char* fgets ( char* str, int num, FILE* stream );
    // Reads characters from stream and stores them as a C string into str until (num-1) characters have been read or either a newline or the end-of-file is reached, whichever happens first.
    while (fgets(buf, MAXLINE, stdin) != NULL){
        if (buf[strlen(buf) - 1] == '\n') buf[strlen(buf) -1] = 0; // replace newline with null

        if ( (pid = fork()) < 0 ) printf("fork error");
        
        else if (pid == 0){ // child process
            execlp(buf, buf, (char *) 0);
            /*
                execlp(buf, buf, (char *) 0); is intended to be executed in the child process image with a new one specified by 'buf', and if 'execlp' is successful, the code that follows it in the child process will not be executed.

                So if 'execlp' is bale to execute the new process successfully, the child process image is replaced, and any code written afer 'execlp' will not run.

                The 'print' and 'return 127' lines are there as a fallback in case 'execlp' fails. If 'execlp' fails to execute the new process, these lines will be executed in the child process to report an error and exit the child process.
            
            */
            printf("couldn't execute: %s", buf);
            return 127;
        }

        // waitpid(pid, &status, 0) mains that wait pid terminal. If the child process terminal corrtely, will return child process PID, if not will return -1. 
        // pid_t waitpid(pid_t pid, int* status, int options);
        if ((pid = waitpid(pid, &status, 0)) < 0) printf("waitpid error");
        printf ("%% ");
    }
    return 0;
}

void sig_int(int signo)
{
    printf("interrupt\n%% ");
}
