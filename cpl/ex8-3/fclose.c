#include <unistd.h>
#include <stdlib.h>
#include "syscall.h"

int fclose(FILE *fp) {
	if (fflush(fp) == EOF) {
		free(fp->base);
		close(fp->fd);
		return EOF;
	}
	free(fp->base);
	close(fp->fd);
	return 0;
}
