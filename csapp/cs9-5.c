#include "csapp.h"

// Copy an arbitrary-sized disk file to stdout, the first argument to the program is file_name
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		fprintf(stderr, "Usage: %s file_name\n", argv[0]);
		exit(1);
	}
	int fd = Open(argv[1], O_RDONLY, 0);
	struct stat stat;
	
	fstat(fd, &stat);
	void *buf = Mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	Write(1, buf, stat.st_size);
	return 0;
}
