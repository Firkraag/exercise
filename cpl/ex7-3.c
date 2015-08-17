#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...) {
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	void *ptr;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'i':
			ival = va_arg(ap, int);
			printf("%i", ival);
			break;
		case 'o':
			ival = va_arg(ap, int);
			printf("%o", ival);
			break;
		case 'x':
			ival = va_arg(ap, int);
			printf("%x", ival);
			break;
		case 'X':
			ival = va_arg(ap, int);
			printf("%X", ival);
			break;
		case 'u':
			ival = va_arg(ap, int);
			printf("%u", ival);
			break;
		case 'c':
			ival = va_arg(ap, int);
			putchar(ival);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 'e':
			dval = va_arg(ap, double);
			printf("%e", dval);
			break;
		case 'E':
			dval = va_arg(ap, double);
			printf("%E", dval);
			break;
		case 'g':
			dval = va_arg(ap, double);
			printf("%g", dval);
			break;
		case 'G':
			dval = va_arg(ap, double);
			printf("%G", dval);
			break;
		case 'p':
			ptr = va_arg(ap, void *);
			printf("%p", ptr);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}
