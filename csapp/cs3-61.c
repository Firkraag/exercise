/* 
 * 参考链接：
 * https://github.com/mofaph/csapp/blob/master/exercise/ex3-61.c
 */	
/*
* 3.61
*
* $ gcc -O2 -S ex3-61.c # 这样就不会使循环的值溢出到存储器了
*/
/* Compute i,k of variable matrix product */
int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k)
{
int j;
int result = 0;
void *Arow = (void *)&A[i][0];
void *Bcol = (void *)&B[0][k];
int N = 4 * n;
for (j = 0; j < N; j += 4, Bcol += N)
	result += *(int *)(Arow + j) * *(int *)Bcol;
return result;
}

int main()
{
	int a[2][2] = {{1, 2}, {3, 4}};
	int b[2][2] = {{1, 2}, {3, 4}};

	printf("%d\n", var_prod_ele(2, a, b, 1, 0));
	return 0;
}
