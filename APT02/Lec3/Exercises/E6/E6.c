#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
	int p[2];
	char msg[] = "Hello from parent";
	char buffer[50];
	if(pipe(p) == -1)
	{
		perror("pipe");
		return 1;
	}

	pid_t child_pid = fork();
	if(child_pid < 0)
	{
		perror("fork");
		return 1;
	}

	if(child_pid == 0)
	{
		dup2(p[0], 0);
		close(p[1]);
		ssize_t bytesRead = read(p[0], buffer, sizeof(buffer) - 1);
		if(bytesRead < 0)
		{
			printf("read");
			return 1;
		}
		printf("Message read from pipe: %s", buffer);
		printf("\n");
	} else
	{
		dup2(p[1], 1);
		close(p[0]);
		ssize_t bytesWritten = write(p[1], msg, strlen(msg));
		if(bytesWritten < 0)
		{
			perror("write");
			return 1;
		}
		printf("Bytes written: %ld\n", bytesWritten);
	}
	return 0;
}
