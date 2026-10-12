#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
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
		printf("Child process.\n");
		sleep(3);
	}
	else 
	{
		pid_t wait_pid = wait(NULL);
		if(wait_pid < 0)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		printf("Parent process.\n");
	}
	return EXIT_SUCCESS;
}
