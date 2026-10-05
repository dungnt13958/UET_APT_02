#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int fd = open("data.txt", O_RDONLY);

	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	
	printf("File opened successfully, fd = %d\n", fd);
	
	if(close(fd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	
	return EXIT_SUCCESS;
}
