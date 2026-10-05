#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	char buffer[50] = "Hello Linux\nThis is Lab 3";
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	ssize_t byteWritten = write(fd, buffer, strlen(buffer));
	if(byteWritten < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	if(close(fd) < 0)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;	
}
