#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void)
{
	pid_t child_pid = fork();
	if(child_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(child_pid == 0)
	{
		execlp("ls", "ls", "-l", NULL);
	}
	else {
		pid_t wait_pid = wait(NULL);
		if(wait_pid < 0)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		printf("Command finished.\n");
	}
	return EXIT_SUCCESS;
}
