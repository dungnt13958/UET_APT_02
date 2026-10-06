#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		       return 1;
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	char buffer[100];
	ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
	if(bytesRead < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	buffer[bytesRead] = '\0';
       if(close(fd) < 0)
       {
	       perror("close");
	       exit(EXIT_FAILURE);
       }
	printf("Read source file done\n");
       fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
       if(fd < 0)
       {
	       perror("open/create");
	       exit(EXIT_FAILURE);
       }
       ssize_t bytesWritten = write(fd, buffer, strlen(buffer));
       if(bytesWritten < 0)
       {
	       perror("write");
	       exit(EXIT_FAILURE);
       }
       printf("Written bytes: %ld (bytes)\n", bytesWritten);
       if(close(fd) < 0)
       {
	       perror("close");
	       exit(EXIT_FAILURE);
       }
       printf("Program done successfully");
       return EXIT_SUCCESS;
}
