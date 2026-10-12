#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv)
{
	if(argc != 2)
	{
		printf("Usage: %s <N>\n", argv[0]);
		return 1;
	}
	int N = atoi(argv[1]);
	pid_t child_pid_1 = fork();
	if(child_pid_1 < 0 || child_pid_2 < 0 || child_pid_3 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(child_pid_1 > 0)
	{
		long long sum = 0;
		for(int i = 0; i <= N; i++)
		{
			sum += i;
		}
		printf("%lld\n", sum);
		exit(EXIT_SUCCESS);
	}

	pid_t child_pid_2 = fork();
	if(child_pid_2 < 0)
	{
		perror("fork");
		exit(EXIT_SUCCESS);
	}
	if(child_pid_2 > 0)
	{
		long long sum = 0;
		for(int i = 0; i <= N; i++)
		{
			if(i %2 == 0)
			{
				sum += i;
			}
		}
		printf("%lld", sum);
		exit(EXIT_SUCCESS);
	}
	pid_t child_pid_3 = fork();
	if(child_pid_3 < 0)
	{
		perror("fork");
		exit(EXIT_SUCCESS);
	}
	if(child_pid_3 > 0)
	{
		long long sum = 0;
		for(int i = 0; i <= N; i++)
		{
			if(i%2 == 1)
			{
				sum+=i;
			}
		}
		printf("%lld", sum);
		exit(EXIT_SUCCESS);
	}
	waitpid(child_pid_1, NULL, 0);
	waitpid(child_pid_2, NULL, 0);
	waitpid(child_pid_3, NULL, 0);
	return 0;
}
