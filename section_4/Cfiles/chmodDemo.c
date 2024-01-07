#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main (void)
{
    struct stat statbuf;

    /* turn on set-group-ID and turn off group-execute */
    if (stat("foo", &statbuf) < 0)
    {
        printf("stat error for foo");
        return -1;
    }
    /* set relative mode by stat struct */
    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    {
        printf("chmod error for foo");
        return -2;
    }

    /* set absolute mode to "rw-r--r--" */
    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
    {
        printf("chmod error for bar");
        return -3;
    }

    return 0;
    
}

/*
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./chmodDemo 
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -l foo bar 
-rw-r--r-- 1 firmon firmon 0  1月  7 23:39 bar
-rw-rwSrw- 1 firmon firmon 0  1月  7 23:39 foo

-- note that the time and data listed by the `ls` command did not change after we ran the program!!!
-- By default, the `ls -l` lists the time when the contents of the file were last modified.
-- The chmod function updates only the time that the i-node was last changed.
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ stat foo
  文件：foo
  大小：0               块：0          IO 块大小：4096   普通空文件
设备：803h/2051d        Inode：923982      硬链接：1
权限：(2666/-rw-rwSrw-)  Uid: ( 1000/  firmon)   Gid: ( 1000/  firmon)
访问时间：2024-01-07 23:39:41.787250883 +0800
修改时间：2024-01-07 23:39:41.787250883 +0800
变更时间：2024-01-08 00:32:18.766452751 +0800
创建时间：2024-01-07 23:39:41.787250883 +0800
*/