#include <stdio.h>
#include <string.h>

/* expand shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, 
and be prepared to handle cases like a-b-c and a-z0-9. Arrange that a leading or trailing is taken literally. */
void expand(char s1[], char s2[]) {
	int i,j=0;
	char a,b;
	int length = strlen(s1);
	for (i = 0; i < length ; i++) {
/* when s1[i] is '-', judge whether s1[i-1] and s1[i+1] are both digits or letters, if so, expansion is takeni, thus a leading or trailing - is taken literally */
		if (s1[i] == '-' &&  ((isalpha(s1[i-1]) && isalpha(s1[i+1])) || (isdigit(s1[i-1]) && isdigit(s1[i+1])))) {
				a = s1[i-1]+1;
				b = s1[i+1];
				i++;
				while ( a <= b)
					s2[j++] = a++;
			}
				
		else 
			s2[j++] = s1[i];
	}
	s2[j] = '\0';
}
main() {
		char a[30] = "-abcde-h-n-1-5-7";
		char b[50];
		expand(a,b);
		printf("%s\n", b);
}
