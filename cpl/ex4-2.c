#include <stdio.h>
#include <ctype.h>
/* atof: convert string s to double */
double atof(char s[])	{
	double val1, val2 = 1.0, power;
	int i, sign1, sign2;
	int exp; //exponent
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign1 = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val1 = 0.0; isdigit(s[i]); i++)
		val1 = 10.0 * val1 + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val1 = 10.0 * val1 + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e') 
		i++;
	sign2 = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] - '0');
	while ( exp-- > 0)
		val2 *= 10.0;
	if ( sign2 == -1)	
		return sign1 * val1 / val2 / power;
	else 
		return sign1 * val1 * val2 / power;
}

main() {
	char s[20] = "123.45";
	printf("%f, %f\n", atof(s), 1.0 / 3.0);
}
