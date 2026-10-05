#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	const char msg[] = "Hello Linux!\nFile I/O Practice";
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd == -1)
	{
		perror("open/create");
		exit(EXIT_FAILURE);
	}
	ssize_t wBytes = write(fd, msg, strlen(msg));
	if(wBytes == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("Written %zd bytes\n", wBytes);

	if(close(fd) == -1)
	{
		perror("exit");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}
