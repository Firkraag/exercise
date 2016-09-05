#include "csapp.h"

struct argument {
	double *A;
	double *B;
	double *C;
	int row_start;
	int row_end;
	int col_start;
	int col_end;
	int size;
};
void matrix_mul(int n, double *A, double *B, double *C)
{
	void *block_mul(void *vargp);
	void assignment(struct argument *stat, double *A, double *B, double *C, int row_start, int row_end, int col_start, int col_end, int size);
	int i;
	pthread_t tid[4];
	struct argument stat[4];
	int floor = n / 2;
	int ceiling = (n + 1) / 2;
	assignment(&stat[0], A, B, C, 0, n / 2 - 1, 0, n / 2 - 1, n);
	assignment(&stat[1], A, B, C, n / 2, n - 1, n / 2, n - 1, n);
	assignment(&stat[2], A, B, C, 0, n / 2 - 1, n / 2, n - 1, n);
	assignment(&stat[3], A, B, C, n / 2, n - 1, 0, n / 2 - 1, n);
	for (i = 0; i < 4; i++)
		Pthread_create(&tid[i], NULL, block_mul, &stat[i]);
	for (i = 0; i < 4; i++)
		Pthread_join(tid[i], NULL);
}

void assignment(struct argument *stat, double *A, double *B, double *C, int row_start, int row_end, int col_start, int col_end, int size)
{
	stat->A = A;
	stat->B = B;
	stat->C = C;
	stat->row_start = row_start;
	stat->row_end = row_end;
	stat->col_start = col_start;
	stat->col_end = col_end;
	stat->size = size;
}

void *block_mul(void *vargp)
{
	struct argument *stat = (struct argument *) vargp;
	int row_start = stat->row_start;	
	int row_end = stat->row_end;	
	int col_start = stat->col_start;	
	int col_end = stat->col_end;	
	int size = stat->size;
	double *A = stat->A;
	double *B = stat->B;
	double *C = stat->C;
	int i, j, k;

	for (i = row_start; i <= row_end; i++)
		for (j = col_start; j <= col_end; j++)
		{
			for (k = 0; k < size; k++)
			{	
//				printf("In thread, A[%d][%d] = %f\n", i, k, A[i * size + k]);
//				printf("In thread, B[%d][%d] = %f\n", k, j, B[k * size + j]);
				C[i * size + j] += A[i * size + k] * B[k * size +  j];
//				printf("In thread, C[%d][%d] = %f\n", i, j, C[i * size + j]);
			}
//			printf("In thread, C[%d][%d] = %f\n", i, j, C[i * size + j]);
		}
	return NULL;
}	
