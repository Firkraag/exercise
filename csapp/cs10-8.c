/* $begin statcheck */
#include "csapp.h"

int main (int argc, char **argv) 
{
    struct stat stat;
    char *type, *readok;
	int fd;
	char *c = argv[1];

    if (argc != 2) {
		fprintf(stderr, "usage: %s <file descriptor>\n", argv[0]);
		exit(0);
    }
//	while (1) {
//			if (isalpha(*c)) {
//				fprintf(stderr, "%s: not a number\n", argv[1]);
//				return 1;
//			}
//			if (*c == '\0')
//				break;
//			c += 1;
//	}
    /* $begin statcheck */
    Fstat(atoi(argv[1]), &stat);
    if (S_ISREG(stat.st_mode))     /* Determine file type */
		type = "regular";
    else if (S_ISDIR(stat.st_mode))
		type = "directory";
    else 
		type = "other";
    if ((stat.st_mode & S_IRUSR)) /* Check read access */
		readok = "yes";
    else
		readok = "no";

    printf("type: %s, read: %s\n", type, readok);
    exit(0);
}
/* $end statcheck */
