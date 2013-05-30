/* This program is an application for trees. 
Its purpose is to list all the files recursively 
in the directory given by argv[1]. 
Output format will be that files that are depth d 
will have their names indented by d tabs. */

/* pseudo code:
void list_directory ( Directory_or_file D ) {
	list_dir ( D, 0 );
}

void
list_dir ( Directory_or_file D, unsigned int depth ) {
	if ( D is a legitimate entry)
	{ 
		print_name ( depth, D );
		if( D is a directory )
			for each child, c, of D
			list_dir( c, depth+1 );
	}
}
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/* Output format will be that files that are depth d will have their names indented by d tabs. */
void print_name(int depth, char *filename) {
	while (depth-- > 0)
		printf("    ");
	printf("%s\n", filename);
}

/* basename is the characters after the last /. This routine returns pointer to the first characters after the last /. */

char *basename(char *filename) {
	char *s;

	for (;*filename != '\0'; filename++)
		if (*filename == '/')
			s = filename;
	return ++s;
}

void list_dir(char *D, int depth) {
		DIR *d;
		struct dirent *dir;
		char s[200];
		char *p;

		if (depth > 0)
			p = basename(D);
		print_name(depth, p);
		d = opendir(D);
		if (d) {
			while ((dir = readdir(d)) != NULL) {
				/* exclude the child "." and ".." of D which reprensent itself and its parent. Otherwise, there will be an infinite loop */
				if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
					continue;
				/* Set the absolute path of the child of D or it will fail when opening child of D */
				sprintf(s, "%s/%s", D, dir->d_name);
				list_dir(s, depth + 1);
			}
			closedir(d);
		}
}
int is_dir(char *file) {
	struct stat stbuf;

	stat(file, &stbuf);
	return S_ISDIR(stbuf.st_mode);
}
list_directory (char *D) {
	list_dir(D, 0);
}
main(int argc, char *argv[]) {
	list_directory(argv[1]);
}
