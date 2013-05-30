#include <stdarg.h>

#define MAXARGS 31

/*
 * execl is called by
 * execl(file, arg1, arg2, ..., (char *)(0));
 */

int execl(const char *file, const char *args, ...) {
	va_list ap;
	char *array[MAXARGS + 1];
	int argno = 0;

	va_start(ap, args);
	while (args != 0 && argno < MAXARGS) {
		array[argno++] = args;
		args = va_arg(ap, const char *);
	}

