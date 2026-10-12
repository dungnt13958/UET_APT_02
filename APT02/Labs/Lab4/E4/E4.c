#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(int argc, char*argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s <filename_1> <filename_2>\n", argv[0]);
	       return 1;
	}
	pid_t child_pid = fork();
	if(child_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(child_pid == 0)
	{
		struct stat st;
		off_t file_size = 0;
		if(stat(argv[2], &st) == 0)
		{
			file_size = st.st_size;
		}
		else 
		{
			perror("stat");
			exit(EXIT_FAILURE);
		}
		int fd = open(argv[2], O_RDONLY);
		if(fd < 0)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		char *buffer = malloc(file_size);
		if(buffer == NULL)
		{
			perror("malloc");
			close(fd);
			exit(EXIT_FAILURE);
		}
		ssize_t bytesRead = read(fd, buffer, file_size);
		if(bytesRead < 0)
		{
			perror("read");
			close(fd);
			exit(EXIT_FAILURE);
		}
		printf("PID: %d\n Filename: %s\n Byte: %ld\n", getpid(), argv[2], bytesRead);
		if(close(fd) < 0)
		{
			perror("close");
			exit(EXIT_FAILURE);
		}
		free(buffer);
	} else
	{
		pid_t wait_pid = waitpid(child_pid, NULL, 0);
		if(wait_pid < 0)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		struct stat st;
		off_t file_size = 0;
		if(stat(argv[1], &st) == 0)
		{
			file_size = st.st_size;
		}
		else
		{
			perror("stat");
			exit(EXIT_FAILURE);
		}
		char * buffer = malloc(file_size);
		if(buffer == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		int fd = open(argv[1], O_RDONLY);
		if(fd < 0)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		ssize_t bytesRead = read(fd, buffer, file_size);
		if(bytesRead < 0)
		{
			perror("read");
			close(fd);
			exit(EXIT_FAILURE);
		}
		printf("PID: %d\n Filename: %s\n Byte: %ld\n", getpid(), argv[1], bytesRead);
		if(close(fd) < 0)
		{
			perror("close");
			exit(EXIT_FAILURE);
		}
		free(buffer);
	}
	return EXIT_SUCCESS;
}
