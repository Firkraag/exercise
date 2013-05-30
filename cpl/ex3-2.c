#include <stdio.h>
/* escape(s,t) converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s, using a switch */
void escape(char s[], char t[]) {
	int i,j;
	for (i = 0,j=0;t[i] != '\0';i++)
		switch(t[i]) {
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n'; 
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:
			s[j++] = t[i];
			break;
		}	
	s[j] = '\0';
} 
main() {
	char t[20] = "abc\tcde\n";
	char s[30];
	printf("%s", t);
	escape(s,t);
	printf("%s\n", s);
	
}
