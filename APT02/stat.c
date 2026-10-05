#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	struct stat st;
	if(stat("data.txt", &st) == -1)
	{
		perror("stat");
		return EXIT_FAILURE;
	}
	
	printf("Size: %lld bytes\n", (long long)st.st_size);

	printf("Inode: %llu\n", (unsigned long long)st.st_ino);
	
	printf("Owner: UID %u\n", (unsigned int)st.st_uid);
	
	printf("Links: %lu\n", (unsigned long)st.st_nlink);
	
	return EXIT_SUCCESS;
}
