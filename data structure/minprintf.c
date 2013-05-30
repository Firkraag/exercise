#include <stdarg.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...) {
	va_list ap;	/* points to each unamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;


