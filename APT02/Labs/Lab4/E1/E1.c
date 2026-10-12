#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	int number = 10;
	pid_t child_pid = fork();
	if(child_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(child_pid == 0)
	{
		number+= 5;
		printf("Child: PID=%d, number=%d\n", getpid(), number);
	}
	else {
		number-=5;
		printf("Parent: PID=%d, number=%d\n", getpid(), number);
	}
	return EXIT_SUCCESS;
}
