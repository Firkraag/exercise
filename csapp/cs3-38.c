#define N 16
typedef int fix_matrix[N][N];

void fix_set_diag(fix_matrix A, int val) {
	int i;

	for (i = 0; i < N; i++) 
		A[i][i] = val;
}
void fix_set_diag_opt(fix_matrix A, int val) {
	int i;
	int *Aptr = &A[0][0];

	for (i = 0; i < N; i++) 
		Aptr[i * N + i] = val;
}

void fix_set_diag_opt2(fix_matrix A, int val) {
	int i;
	int *Aptr = &A[0][0];

	for (i = 0; i < (N + 1) * N; i += (N + 1)) 
		Aptr[i] = val;
}

void fix_set_diag_opt3(fix_matrix A, int val) {
	int index = 0;
	int *Abase = &A[0][0];

	do {
		Abase[index] = val;
		index += (N + 1);
	} while (index != (N + 1) * N);
}

