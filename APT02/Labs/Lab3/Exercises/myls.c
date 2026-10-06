#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<dirent.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	DIR *dir;
	struct dirent *entry;
	dir = opendir(argv[1]);
	if( dir == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	while((entry = readdir(dir)) != NULL)
	{
		printf("%s\n", entry->d_name);
	}
	closedir(dir);
	return 0;
}
