#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <errno.h>
#undef NAME_MAX
// 50 is too small for NAME_MAX
//#define NAME_MAX 50
#define NAME_MAX 250
#define MAX_PATH 1024
#define BUF_SIZE 1024

typedef struct {
	long ino;
	char name[NAME_MAX + 1];
} Dirent;

typedef struct {
	int fd;
	char buf[BUF_SIZE];
	int nread;
	int bpos;
} DIR;

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
Dirent *readdir1(DIR *dfd);
void closedir(DIR *dfd);
void fsize(char *);
void dirwalk(char *, void (*)(char*));
