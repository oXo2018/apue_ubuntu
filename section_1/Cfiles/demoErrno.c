#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *file = fopen("nonexistent_file.txt","r");
    if(file == NULL){
        perror("Error opening file");  // extern void perror (const char *__s);  this function will print the s and descript that the errno mean. So much power function. 
        printf("Error code: %d\n", errno);
    }

    return 0;
}