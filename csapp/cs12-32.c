#include "csapp.h"

char *tfgets(char *s, int size, FILE *stream)
{
	struct timeval sleep = {5, 0};
	fd_set read_set;
	int fd = fileno(stream);

	FD_ZERO(&read_set);
	FD_SET(fd, &read_set);
	Select(fd + 1, &read_set, NULL, NULL, &sleep);
	printf("select: %ld, %ld\n", sleep.tv_sec, sleep.tv_usec);
	if ((sleep.tv_sec == 0l) && (sleep.tv_usec == 0l))
		return NULL;
	else
	{
		return fgets(s, size, stream);
	}
}
