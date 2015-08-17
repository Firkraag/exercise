#include <unistd.h>
#include "syscall.h"

int fflush(FILE *fp) {
	int bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

	if ((fp->flag & _WRITE) != 0) {
		if (write(fp->fd, fp->base, fp->ptr - fp->base) < 0 ) {
			printf("fflush write failed\n");
			return EOF;
		}
		else {
			printf("fflush write success\n");
			fp->ptr = fp->base;
			fp->cnt = bufsize;
			return 0;
		}
	}
	else if ((fp->flag & _READ) != 0) {
		fp->ptr = fp->base;
		fp->cnt = 0;
		return 0;
	}
	return 0;
}
