#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char * filename = argv[1];

    struct stat file_info;

    // use stat to get information about the file
    if (stat(filename, &file_info) == 0)
    {
        // print the owner user ID and owner group ID
        // The owner user ID equals the effective UID
        // The owner group ID equals the effective GID
        printf("File: %s, Owner UID: %u, Owner GID: %u\n", filename, (unsigned int)file_info.st_uid, (unsigned int)file_info.st_gid);
        return 0;
    }else{
        printf("Error in stat");
        return -1;
    }
    
}

/*
    using stat command to check file informations.
        stat filename
        stat -c "File: %n , EUID: %u , EGID: %g" filename

    To check the effecive user ID and effective group ID of the current user, can use the `id` command
        id -u  # prints the effective user ID
        id -g  # prints the effective group ID
*/

/*
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./getUIDandGID ./FileType 
File: ./FileType, Owner UID: 1000, Owner GID: 1000
*/

