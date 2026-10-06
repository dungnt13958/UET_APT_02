#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	if(argc != 2) {
		printf ("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	int fd = open(argv[1], O_RDONLY);
	if(fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	char buffer[11];
	ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
	if(bytesRead < 0) {
		perror("read");
		close(fd);
		exit(EXIT_FAILURE);
	}
	buffer[bytesRead] = '\0';
	printf("10 byte dau: %s\n", buffer);

	if(lseek(fd, 20, SEEK_SET) < 0) {
		perror("lseek");
		close(fd);
		exit(EXIT_FAILURE);
	}
	bytesRead = read(fd, buffer, sizeof(buffer) - 1);
	if(bytesRead < 0){
		perror("read");
		close(fd);
		exit(EXIT_FAILURE);
	}
	buffer[bytesRead] = '\0';
	printf("10 byte tu vi tri 20: %s\n", buffer);
	off_t fileSize = lseek(fd, 0, SEEK_END);
	if(fileSize < 0){
		perror("lseek");
		close(fd);
		exit(EXIT_FAILURE);
	}

	printf("File size: %ld bytes\n", fileSize);
	if(close(fd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}
