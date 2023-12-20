#include <stdio.h>
#include <unistd.h>

int main ()
{
    FILE *file;

    file = fopen("./1.txt", "r");

    // Check if the file is opened successfully
    if (file == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    // read and print the content of the file
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(file);

    return 0;
    
}
/*
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# ls -l 1.txt
-rwx------ 1 root root 24 12月 21 00:47 1.txt
*/
/*
----use root permissions to generate checkEffectiveofISGID
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# ls -l
总计 68
-rwx------ 1 root   root      24 12月 21 00:47 1.txt
-rwxr-xr-x 1 root   root   16144 12月 21 01:05 checkEffectiveofISGID
-rwxrwxr-x 1 firmon firmon 16152 12月 19 23:57 CheckISUIDandISGID
-rwsrwsr-x 1 firmon firmon 16096 12月 18 01:07 FileType
-rwxrwxr-x 1 firmon firmon 16064 12月 21 00:39 getUIDandGID

---- exit root permission, use normal permission
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# exit
exit

--- execute the checkEffectiveofISGID cannot read the content of 1.txt due to it's root permission.
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./checkEffectiveofISGID 
Error opening the file

--- use root permission set checkEffectiveofISGID ISUID and ISGID permission. make it have root permission when it running.
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ su root
密码： 
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# chmod ug+s checkEffectiveofISGID 
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# ls -l checkEffectiveofISGID 
-rwsr-sr-x 1 root root 16144 12月 21 01:05 checkEffectiveofISGID

--- exit root permission again.
root@ubt:/home/firmon/Dev/apue/apue_ubuntu/section_4/out# exit
exit

--- then using normal permission to execute the checkEffectiveofISGID can get content of 1.txt !!! (this is effective of set ISUID and ISGID)
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ ./checkEffectiveofISGID 
The file owner is root.
firmon@ubt:~/Dev/apue/apue_ubuntu/section_4/out$ 

*/