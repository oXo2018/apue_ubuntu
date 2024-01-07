#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH ) //those constant define in sys/stat.h

int main (void)
{
    umask(0); // set file mode creation mask to 0
    // creat a file by process will calculate the permissions which equals ~umask AND RWRWRW 
    if (creat("foo",RWRWRW) < 0)
    {
        printf("create error for foo");
        return -1;
    }

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRWRW) < 0)
    {
        printf("create error for bar");
        return -2;
    }
    
    return 0;
    
}
/*
-- first print the current file mode creation mask
-- 0002 means that other-write.
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ umask
0002

-- creat a file by process will calculate the permissions which equals ~umask AND RWRWRW 
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./umaskDemo 
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -l foo bar 
-rw------- 1 firmon firmon 0  1月  7 23:39 bar
-rw-rw-rw- 1 firmon firmon 0  1月  7 23:39 foo

-- !! This shows us that changing the file mode creation mask of a process doesn't affect the mask of its parent(often a shell)
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ umask
0002

-- first print the current file mode creation mask
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ umask
0002

-- print the symbolic form (The symbolic format specifies which permissions are to be allowed.)
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ umask -S
u=rwx,g=rwx,o=rx

-- change the file mode creation mask
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ umask 027

-- print the symbolic form
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ umask -S
u=rwx,g=rx,o=

*/