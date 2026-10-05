#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	const char msg[] = "This is a test message for write.c\n";
	
	int fd = open("outputFile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	
	ssize_t wBytes = write(fd, msg, strlen(msg));
	if(wBytes == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	
	printf("Written %zd bytes\n", wBytes);
	
	close(fd);

	return EXIT_SUCCESS;
}
