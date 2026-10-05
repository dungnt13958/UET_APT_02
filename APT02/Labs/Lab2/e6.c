#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	DIR *dir = opendir(".");
	if(dir == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	struct dirent* entry;
	errno = 0;
	while((entry = readdir(dir)) != NULL)
	{
		printf("%s\n", entry->d_name);
	}

	if(errno != 0)
	{
		perror("readdir");
		closedir(dir);
		exit(EXIT_FAILURE);
	}
	if(closedir(dir) == -1)
	{
		perror("closedir");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}
