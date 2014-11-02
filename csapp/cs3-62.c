#define M 3

void transpose(int A[M][M]) {
	int i, j;
	
	for (i = 0; i < M; i++)
		for (j = 0; j < i; j++) {
			int t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
}
void transpose_opt(int A[M][M]) {
	int i, j;
	
	for (i = 0; i < M; i++) {
			int *A1 = (int *) A + i; // &A[0][i] 
			int *A2 = (int *) (A + i); // &A[i][0]
		for (j = 0; j < i; j++) {
			int t = *A1; 
			int s = A2[j];
			A2[j] = t;
			*A1 = s;
			A1 += M;
		}
	}
}
