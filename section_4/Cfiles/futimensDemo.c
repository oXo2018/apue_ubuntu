#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main (int argc, char* argv[])
{
    int i,fd;
    struct stat statbuf;
    struct timespec times[2];

    for ( i = 1; i < argc; i++)
    {
        if (stat(argv[i], &statbuf) < 0){ //fetch current times
            printf("%s: stat error", argv[i]);
            continue;
        }
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) //truncate
        {
            printf("%s: open error", argv[i]);
            continue;
        }
        times[0].tv_sec = statbuf.st_atime;
        times[1].tv_sec = statbuf.st_mtime;

        if (futimens(fd, times) < 0) // reset times
        {
            printf("%s: futimens error", argv[i]);
            close(fd);
        }
        return 0;
        
    }
    
}

/*
-- look at sizes and last-modification times
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -l changemodFile 
-rwxrwxr-x 1 firmon firmon 16096  1月 15 23:35 changemodFile

-- look at last-access times
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -lu changemodFile 
-rwxrwxr-x 1 firmon firmon 16096  1月 15 23:35 changemodFile

-- print today's date
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ date
2024年 01月 15日 星期一 23:36:04 CST

-- run the program 
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./futimensDemo changemodFile 

-- and check the results (last-modification will be change just due to truncate the file, the content set to 0)
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -l changemodFile 
-rwxrwxr-x 1 firmon firmon 0  1月 15 23:36 changemodFile

-- check the last-access times also (the last-access times no changes just due to `open` funtion use the O_TRUNC pameter to open the file.(It actully not open the file's content))
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -lu changemodFile 
-rwxrwxr-x 1 firmon firmon 0  1月 15 23:35 changemodFile

-- and the changed-status times (The changed-status times have changed to the time that the program was run  [The `futimens` function will change the changed-status times] )
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -lc changemodFile 
-rwxrwxr-x 1 firmon firmon 0  1月 15 23:36 changemodFile
*/