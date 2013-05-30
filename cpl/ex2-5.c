#include <stdio.h>
// search character c in char array, return 1 when found, return 0 when not found
int search(char s[], char c) {
        int i;
        for (i = 0; s[i] != '\0';i++)
                if ( c == s[i])
                        return 1;
       return 0;
}
// return the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 

int any(char s1[], char s2[]) {
	int loca;
	int i;
	int c;
	for (i = 0;s1[i] != '\0';i++)
		if (search(s2,s1[i]))
			return ++i;
	return -1;
}

	



	
main() {
	char i;
	char s[10] = "abcdebg";
//	for (i = 'a';i <= 'h'; i++)
//		printf("%d\n", search(s, i));
	char t[10] ="hgb";
	printf("%d\n", any(s,t));
}
	
