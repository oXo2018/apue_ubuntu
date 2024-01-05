#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("usage: a.out <pathname>");
        return -1;
    }
/*
Test for access to NAME using the real UID and real GID.  
extern int access (const char *__name, int __type) __THROW __nonnull ((1));
*/
    // additional codes.
    if(access(argv[1], F_OK) < 0) // F_OK means to check this file whether exist or not.
    {
        printf("%s this file don't exist!\n", argv[1]);
        return -1;
    }
    else
    {
        printf("%s this file is exist!\n");
    }


    if (access(argv[1], R_OK) < 0) // check this process whether have the read permission of the file or not.
    {
        printf("access error for %s\n", argv[1]);
    }
    else
    {
        printf("Have read permission\n");
    }

    if (open(argv[1], O_RDONLY) < 0 ) // open function will return FD if open success! and FD number > 0
    {
        printf("open error for %s\n", argv[1]);
    }
    else
    {
        printf("open for reading OK\n");
    }
    
    return 0;
    
}

/**

firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -l accessFileDemo 
-rwxrwxr-x 1 firmon firmon 16096  1月  5 23:53 accessFileDemo
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./accessFileDemo accessFileDemo 
Have read permission
open for reading OK
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -l /etc/shadow
-rw-r----- 1 root shadow 1563  1月  5 23:44 /etc/shadow
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./accessFileDemo /etc/shadow
access error for /etc/shadow
open error for /etc/shadow

--- become superuser
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ su root
密码： 

--- change file's user ID to root by use root role.
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# chown root ./accessFileDemo

--- and turn on set-user-ID bit
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# chmod u+s ./accessFileDemo 

--- check owner and SUID bit
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# ls -l ./accessFileDemo 
-rwsrwxr-x 1 root firmon 16096  1月  5 23:53 ./accessFileDemo

--- change role to firmon
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# exit
exit

--- this pocess real user is firmon and accessFileDemo's permission is -rwsrwxr-x. Other user have read permission to read this file.
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./accessFileDemo  accessFileDemo 
Have read permission
open for reading OK

 */