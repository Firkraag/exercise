#include <stdio.h>

// convert char 0,1,2,...,d,e,f to integer 0,1,2,..,14,15,16
int h2d(char c) {
	int i;
	if (c >= 'a' && c <= 'f')
		i = c - 'a' + 10;
	else if ( c >= 'A' && c<= 'F')
		i = c - 'A' + 10;
	else 
		i = c - '0';
	return i;
}	
/* convert a string of hexadecimal digits(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.*/
int htoi(char s[]) {
        int i=0, n = 0;
	int c;
        if ( s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
                i = 2;	// skip leading 0x or 0X
        while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >='A' && s[i] <= 'F')) {
		n= n*16 + h2d(s[i]);
		i++;
        }
        return n;
}
main(int argc, char *argv[]) {
	printf("%d\n", htoi(argv[1]));
}
