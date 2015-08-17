#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"

void fsize(char *);

int main(int argc, char **argv) {
	if (argc == 1)
		fsize(".");
	else 
		while (--argc > 0) 
			fsize(*++argv);
	return 0;
}

void fsize(char *name) {
	struct stat stbuf;

	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	printf("%8ld %s\n", stbuf.st_size, name);
}

void dirwalk(char *dir, void (*fcn)(char *)) {
	char name[MAX_PATH];
	Dirent *dp;
	DIR *dfd;

	if ((dfd = opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
	//printf("open directory %s\n", dir);
	while ((dp = readdir(dfd)) != NULL) {
//		printf("dirwalk %ld, %s\n", dp->ino, dp->name);
//		continue;
		if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
			continue;
		if ((strlen(dir) + strlen(dp->name) + 2) > sizeof(name))
			fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name);
		else {
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
	//printf("close directory %s\n", dir);
}

DIR *opendir(char *dirname) {
	int fd;
	struct stat stbuf;
	DIR *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 || (stbuf.st_mode & S_IFMT) != S_IFDIR || (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
		return NULL;
	dp->fd = fd;
	dp->nread = -2;
	dp->bpos = 0;
	return dp;
}	

void closedir(DIR *dp) {
	if (dp) {
		close(dp->fd);
		free(dp);
	}
}

Dirent *readdir(DIR *dp) {
	struct linux_dirent {
	   long           d_ino;
	   off_t          d_off;
	   unsigned short d_reclen;
	   char           d_name[];
	} *dirbuf;
	static Dirent d;

	//Can't apply read to directory, so use getdents to implement readdir
	if (dp->nread == -2)	
		dp->nread = syscall(SYS_getdents, dp->fd, dp->buf, BUF_SIZE);
//	fprintf(stderr, "readdir1 %d\n", dp->nread);
	if (errno == EINVAL)
		fprintf(stderr, "Buffer is too small\n");
	if (dp->nread == -1)
		return NULL;
	else if (dp->nread == 0)
		return NULL;
	//fprintf(stderr, "%s, %ld\n", dirbuf->d_name, dirbuf->d_ino);
	dirbuf = (struct linux_dirent *) (dp->buf + dp->bpos);
	d.ino  = dirbuf->d_ino;
	strncpy(d.name, dirbuf->d_name, NAME_MAX);
	d.name[strlen(dirbuf->d_name) < NAME_MAX ? strlen(dirbuf->d_name) : NAME_MAX ] = '\0';
	//fprintf(stderr, "getdents %s, %ld\n", d.name, d.ino);
	dp->bpos += dirbuf->d_reclen;
	if (dp->bpos >= dp->nread) {
		dp->bpos = 0;
		dp->nread = -2;
	}
	return &d;
}
