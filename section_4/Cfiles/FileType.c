#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include <sys/stat.h>

/*
Get file attributes for FILE and put them in BUF.  
extern int stat (const char *__restrict __file, struct stat *__restrict __buf) __THROW __nonnull ((1, 2));

Get file attributes for the file, device, pipe, or socket that file descriptor FD is open on and put them in BUF.  
extern int fstat (int __fd, struct stat *__buf) __THROW __nonnull ((2));

Get file attributes about FILE and put them in BUF. If FILE is a symbolic link, do not follow it. 
extern int lstat (const char *__restrict __file, struct stat *__restrict __buf) __THROW __nonnull ((1, 2));

extern int fstatat64 (int __fd, const char *__restrict __file, struct stat64 *__restrict __buf, int __flag) __THROW __nonnull ((2, 3));
*/


int main (int argc, char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;

    for (i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);
        // the funciton lstat will fill the buf struct!
        if (lstat(argv[i], &buf) < 0){
            printf("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode)) ptr = "regular";
        else if (S_ISDIR(buf.st_mode)) ptr = "directory";
        else if (S_ISCHR(buf.st_mode)) ptr = "character special";
        else if (S_ISBLK(buf.st_mode)) ptr = "block special";
        else if (S_ISFIFO(buf.st_mode)) ptr = "fifo";
        else if (S_ISLNK(buf.st_mode)) ptr = "symoblic link"; 
        else if (S_ISSOCK(buf.st_mode)) ptr = "socket";
        else ptr = "** unknown mode **";
        printf("%s\n", ptr);
    }
    return 0;
    
}

/*
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./FileType /etc/passwd /etc /dev/log /dev/tty /dev/stdin /dev/sr0 /dev/cdrom
/etc/passwd: regular
/etc: directory
/dev/log: symoblic link    (NO socket)
/dev/tty: character special
/dev/stdin: symoblic link   (i cannot find the FIFO files)
/dev/sr0: block special
/dev/cdrom: symoblic link

*/