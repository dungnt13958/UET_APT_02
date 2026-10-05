#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	char source[100];
	scanf("%99s", source);
	char dest[100];
	scanf("%99s", dest);
	char buffer[100];
	int fd = open(source, O_RDONLY);
	
	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
	if(bytesRead == -1)
	{
		perror("read");
		close(fd);
		exit(EXIT_FAILURE);
	}
	// buffer[bytesRead] = '\0';
	if(close(fd) == -1)
	{
		perror("exit source");
		exit(EXIT_FAILURE);
	}
	fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd == -1)
	{
		perror("open desitnation");
		exit(EXIT_FAILURE);
	}
	ssize_t wBytes = write(fd, buffer, bytesRead);
	if(wBytes == -1)
	{
		perror("write");
		close(fd);
		exit(EXIT_FAILURE);
	}
	
	if(close(fd) == -1)
	{
		perror("exit destination");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}

