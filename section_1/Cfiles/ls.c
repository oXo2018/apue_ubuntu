#include "apue.h"
#include <dirent.h>

int main (int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if (argc !=2) printf("usage: ls directory_name");
	
	// func opendir will return a pointer of DIR 
	if ((dp = opendir(argv[1])) == NULL) printf("can't open %s", argv[1]);
	
	// func readdir use DIR pointer to return a obtain information struct dirent
	while ((dirp = readdir(dp)) != NULL) printf("%s \n", dirp->d_name);

	closedir(dp);
	exit(0);
}

	
