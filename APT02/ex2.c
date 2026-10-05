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
	char buffer[100];
	ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);
	if(bytes == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
		close(fd);
	}
	
	buffer[bytes] = '\0';
	printf("Read file content: %s\n", buffer);
	if(close(fd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}
