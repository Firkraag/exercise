#include <stdio.h>
#include <string.h>
void reverse(char s[]) {
        int c, i, j;
        for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}
int strindex(char s[], char t[]) {
	int i, j, k;
	
	reverse(s);
	reverse(t);
	for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0;t[k] != '\0' && s[j] == t[k];j++, k++)
            ;
        if ( k > 0 && t[k] == '\0')
            return strlen(s) -strlen(t) - i;
    }
    return -1;
} 	
main() {
	char s[20] = "abcdfjalfdbaabcfj";
	char t[4] = "abc";
	
	printf("%d\n", strindex(s, t));
}
