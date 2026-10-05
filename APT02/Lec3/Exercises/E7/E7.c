#include<stdio.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
	int p[2];
	if(pipe(p) < 0)
	{
		perror("pipe");
		return 1;
	}
	char cmd = 
}
