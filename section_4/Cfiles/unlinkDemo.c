#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    if(open("tempfile",O_RDWR) < 0)
    {
        printf("open file have a error");
        return -1;
    }

    if (unlink("tempfile") < 0) // cannot find the file when unlink it
    {
        printf("unlink error");
        return -2;
    }

    printf("file unlinked\n");
    sleep(15);
    printf("done\n"); 
    return 0; // only this process closed, the kernel will be check the link count of the file and it is 0, the kernel should remove it form disk.
}
/*
-- look at how big the file is
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -l tempfile  
-rwxr-xr-x 1 firmon firmon 16144  1月 11 23:51 tempfile

-- check how much free space is available (23324388)
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ df .
文件系统         1K的块     已用     可用 已用% 挂载点
/dev/sda3      40453376 15041872 23324388   40% /

-- run the program in other shell window
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./unlinkDemo 
file unlinked -- the file is unlinked

-- see if the filename is still there
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ls -l tempfile 
ls: 无法访问 'tempfile': 没有那个文件或目录

-- see if the space is available yet (23324388)
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ df .
文件系统         1K的块     已用     可用 已用% 挂载点
/dev/sda3      40453376 15041872 23324388   40% /

-- run the program in other shell window and the program is done now!
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./unlinkDemo 
file unlinked -- the file is unlinked
done

-- now the disk space should be available. (23324420)
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ df .
文件系统         1K的块     已用     可用 已用% 挂载点
/dev/sda3      40453376 15041840 23324420   40% /

*/

/*
    This property of unlink is often used by a program to ensure that a temporary file it creates won't be left around in case the program crashes!!!!
    The process creates a file using either open or create and then immediately calls unlink. The file is not deleted now, however, because it is still open. Only when the process either closes the file or terminates, which causes the kernel to close all its open files, is the file deleted. 

    If pathname is a symbolic link, unlink removes the symbolic link, not the file referenced by the link. There is no function to remove the file referenced by a symbolic link given the name of the link.


*/
