#include <stdio.h>
//char *p = s;
void swap(char v[], int i, int j) {
	char temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
/* void reverse(char *s) {

	static char *p = s;
	if (*(s+1) != '\0')
		reverse(s+1);
	p++ = s;
} */
void reverse(int left, int right, char s[]) {
	int i = 0, j = 0;
	if (left >= right)
		return;
	else
		reverse(left+1, right-1, s);
	swap(s, left, right);
}

main() {
	char s[20] = "abcdef";
	reverse(0, 5, s);
	printf("%s\n", s);
}

