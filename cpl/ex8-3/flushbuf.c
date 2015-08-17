#include <unistd.h>
#include <stdlib.h>
#include "syscall.h"

int _flushbuf(int x, FILE *fp) {
	int bufsize;

	if ((fp->flag & _WRITE) == 0)
		return EOF;
	if ((fp->flag & _EOF) != 0)
		return EOF;
	if ((fp->flag & _ERR) != 0)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	printf("%d\n", bufsize);
	if (fp->base == NULL) {
		printf("malloc memory space\n");
		if ((fp->base = (char *) malloc(bufsize)) == NULL) {
			printf("malloc failed\n");
			return EOF;
		}
		else {
			fp->cnt = bufsize - 1;
			fp->ptr = fp->base;
			*(fp->ptr)++ = (unsigned char) x;
			printf("first write %c\n", x);
			return (unsigned char) x;
		}
	}
	else {
		printf("%s\n", fp->base);
		if (write(fp->fd, fp->base, bufsize) != bufsize) {
			printf("write failed\n");
			fp->flag |= _ERR;
			return EOF;
		}
		else {
			printf("write success\n");
			fp->ptr = fp->base;
			fp->cnt = bufsize - 1;
			*(fp->ptr)++ = (unsigned char) x;
			printf("Common %c\n", x);
			return (unsigned char) x;
		}
	}	
}
