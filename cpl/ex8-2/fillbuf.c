#include <unistd.h>
#include <stdlib.h>
#include "syscall.h"

int _fillbuf(FILE *fp) {
	int bufsize;

	if ((fp->flag & _READ) == 0)
		return EOF;
	if ((fp->flag & _EOF) != 0)
		return EOF;
	if ((fp->flag & _ERR) != 0)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL)
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}
