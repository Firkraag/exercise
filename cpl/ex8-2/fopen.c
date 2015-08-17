#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#include "syscall.h"
#define PERMS 0666

FILE _iob[OPEN_MAX] = { 
    {0, (char *) 0, (char *) 0, _READ, 0}, 
	{0, (char *) 0, (char *) 0, _WRITE, 1}, 
	{0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};


FILE *fopen(char *name, char *mode) {
	int fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp->flag & (_READ | _WRITE)) == 0)
			break;
	if (fp >= _iob + OPEN_MAX)
		return NULL;
	if (*mode == 'w') {
		fd = creat(name, PERMS);
		printf("write mode\n");
	}
	else if (*mode == 'a') {
		printf("append mode\n");
		if ((fd = open(name, O_WRONLY, 0)) == -1) {
			printf("%s not exists, create it\n", name);
			fd = creat(name, PERMS);
		}
		lseek(fd, 0L, 2);
	} 
	else {
		fd = open(name, O_RDONLY, 0);
		printf("open mode\n");
	}
	if (fd == -1)
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}
