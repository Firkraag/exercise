#include <stdio.h>
/* find char c in char array s, return 0 if found, return 1 if not found */
int search(char s[], char c) {
	int i;
	for (i = 0; s[i] != '\0';i++)
		if ( c == s[i])
			return 0;
	return 1;
}
// delete each character in s1 that matches any character in the string s2 
void squeeze(char s1[], char s2[]) {
	int i, j;
	for (i = j = 0; s1[i] != '\0'; i++)
		if (search(s2, s1[i]))
			s1[j++] = s1[i];
	s1[j] = '\0';
}	
main() {
	char s[10] = "abcd";
	char t[10] = "ad";
	squeeze(s,t);
	printf("%s\n", s);
}
