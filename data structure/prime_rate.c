#include <stdio.h>
double relative_prime_rate(int n) {
	int rel =0;
	int tot = 0;
	int i,j;
	for (i = 1; i <= n; i++)
		for (j = i+1; j <= n; j++) {
			tot++;
			if (gcd(i,j) == 1) {
				rel++;
				printf("%d, %d\n", i, j);
			}
		}
	printf("%d, %d\n", tot, rel);
	printf("Percentage of relatively prime pairs is %lf\n", ((double) rel)/tot);
}
