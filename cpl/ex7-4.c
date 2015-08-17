#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...) {
	va_list ap;
	char *p, *sptr;
	int *iptr;
	unsigned *uiptr;
	float *dptr;
	char *cp;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') 
			continue;
		switch (*++p) {
		case 'd':
			iptr = va_arg(ap, int *);
			scanf("%d", iptr);
			break;
		case 'i':
			iptr = va_arg(ap, int *);
			scanf("%i", iptr);
			break;
		case 'o':
			iptr = va_arg(ap, int *);
			scanf("%o", iptr);
			break;
		case 'x':
			iptr = va_arg(ap, int *);
			scanf("%x", iptr);
			break;
		case 'X':
			iptr = va_arg(ap, int *);
			scanf("%X", iptr);
			break;
		case 'u':
			uiptr = va_arg(ap, unsigned int *);
			scanf("%u", uiptr);
			break;
		case 'c':
			cp = va_arg(ap, char *);
			scanf("%c", cp);
			break;
		case 's':
			sptr = va_arg(ap, char *);
			scanf("%s", sptr);
			break;
		case 'f':
			dptr = va_arg(ap, float *);
			scanf("%f", dptr);
			break;
		case 'e':
			dptr = va_arg(ap, float *);
			scanf("%e", dptr);
			break;
		case 'E':
			dptr = va_arg(ap, float *);
			scanf("%E", dptr);
			break;
		case 'g':
			dptr = va_arg(ap, float *);
			scanf("%g", dptr);
			break;
		case 'G':
			dptr = va_arg(ap, float *);
			scanf("%G", dptr);
			break;
		default:
			break;
		}
	}
	va_end(ap);
}
