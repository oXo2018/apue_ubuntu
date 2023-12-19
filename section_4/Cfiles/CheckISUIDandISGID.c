#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    const char * filename = argv[1];
    struct stat file_stat;

    // get file information
    if (stat(filename, &file_stat) == -1)
    {
        printf("Error gettting file information");
        return -1;
    }

    // check S_ISUID bit
    if (file_stat.st_mode & S_ISUID)
    {
        printf("S_ISUID bit is set.\n");
    }else{
        file_stat.st_mode |= S_ISUID;
    }

    // check S_ISGID bit
    if (file_stat.st_mode & S_ISGID)
    {
        printf("S_ISGID bit is set.\n");
    }else{
        file_stat.st_mode |= S_ISGID;
    }
    

    // update file permissions
    if (chmod(filename, file_stat.st_mode) == -1)
    {
        printf("Error setting file permissions");
        return -2;
    }
    
    return 0;
}
/*
    using system command to set ISUID or ISGID:
    chmod u+s filename -> to set ISUID
    chmod g+s filename -> to set ISGID
    chmod ug+s filename -> to set both ISUID and ISGID

    chmod 7777 filename -> the last 7 mean set both ISUID and ISGID
*/
/*
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./CheckISUIDandISGID ./FileType 
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./CheckISUIDandISGID ./FileType 
S_ISUID bit is set.
S_ISGID bit is set.

*/