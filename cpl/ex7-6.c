#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 8000

int main(int argc, char *argv[]) {
	FILE *file1;
	FILE *file2;
	char s1[MAXLINE], s2[MAXLINE];
	char *p1, *p2;
	int counter = 0;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
		exit(1);
	}
	file1 = fopen(argv[1], "r");
	file2 = fopen(argv[2], "r");
	while (1) {
		p1 = fgets(s1, MAXLINE, file1);
		p2 = fgets(s2, MAXLINE, file2);
		counter++;
//		printf("%d\n", counter);
		if (p1 == NULL && p2 != NULL) {
			printf("The first line where file %s and file %s differ is line %d\n", argv[1], argv[2], counter);
			printf("File %s has reached its end\nFile %s:\t%s", argv[1], argv[2], s2);
			exit(4);
		}
		else if (p1 != NULL && p2 == NULL) {
			printf("The first line where file %s and file %s differ is line %d\n", argv[1], argv[2], counter);
			printf("File %s:\t%sFile %s has reached its end\n", argv[1], s1, argv[2]);
			exit(3);
		}
		else if (p1 != NULL && p2 != NULL) {
			if (strcmp(s1, s2) != 0) {
				printf("The first line where file %s and file %s differ is line %d\n", argv[1], argv[2], counter);
				printf("File %s:\t%sFile %s:\t%s", argv[1], s1, argv[2], s2);
				exit(2);
			}
		}
		else
			exit(0);
	}		
}
