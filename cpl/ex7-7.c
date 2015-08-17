#include <stdio.h>
#include <string.h>
#define MAXLINE 8096

int getline2(char s[],int lim) {
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


int main(int argc, char *argv[]) {
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch(c) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				fprintf(stderr, "find: illegal option %c\n", c);
				fprintf(stderr, "Usage: find [-x] [-n] pattern [file...]\n");
				return 255;
			}
	if (argc == 0) {
		fprintf(stderr, "find: no pattern\n");
		fprintf(stderr, "Usage: find [-x] [-n] pattern [file...]\n");
		return 254;
	}
	char *pattern = *argv++;
	if (--argc == 0) {
		while (getline2(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, pattern) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	}
	else {
		FILE *fp;
		char *flag;
		while (argc-- > 0) {
			lineno = 0;
			fp = fopen(*argv, "r");
			if (fp == NULL) {
				fprintf(stderr, "Open file %s error\n", *argv++);
				continue;
			}
			while ((flag = fgets(line, MAXLINE, fp)) != NULL) {
				lineno++;
				if ((strstr(line, pattern) != NULL) != except) {
					printf("%s:", *argv);
					if (number)
						printf("%ld:", lineno);
					printf("%s", line);
					found++;
				}
			}
			if (ferror(fp)) 
				fprintf(stderr, "Handling file %s error\n", *argv);
			fclose(fp);
			argv++;
		}
	}
	return found;
}
