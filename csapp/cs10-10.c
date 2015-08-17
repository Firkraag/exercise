/* $begin cpfile */
#include "csapp.h"

int main(int argc, char **argv) 
{
    int n;
    rio_t rio;
    char buf[MAXLINE];
	int fd;

	if (argc > 1) {
		fd = Open(argv[1], O_RDONLY, 0);
		Dup2(fd, STDIN_FILENO);
		Close(fd);
	}
    Rio_readinitb(&rio, STDIN_FILENO);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) 
	Rio_writen(STDOUT_FILENO, buf, n);
    /* $end cpfile */
    exit(0);
    /* $begin cpfile */
}
/* $end cpfile */



