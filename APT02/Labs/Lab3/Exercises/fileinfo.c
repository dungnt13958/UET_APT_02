#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	struct stat file_stat;
	if(stat(argv[1], &file_stat) < 0)
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}
	printf("File name: %s\n", argv[1]);
	printf("Size: %ld bytes\n", file_stat.st_size);
	printf("Type: ");
        if (S_ISREG(file_stat.st_mode)) {
                printf("Regular file\n");
        } else if (S_ISDIR(file_stat.st_mode)) {
                printf("Directory\n");
        } else if (S_ISLNK(file_stat.st_mode)) {
                printf("Symbolic link\n");
        } else if (S_ISCHR(file_stat.st_mode)) {
                printf("Character device\n");
        } else if (S_ISBLK(file_stat.st_mode)) {
                printf("Block device\n");
        } else if (S_ISFIFO(file_stat.st_mode)) {
                printf("Named pipe\n");
        } else if (S_ISSOCK(file_stat.st_mode)) {
                printf("Socket\n");
        }
	return EXIT_SUCCESS;
}
