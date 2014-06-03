#! /usr/bin/python2.7

# AUTHOR: WangQiang
# CREATE DATE:   20140528
# LAST UPDATE DATE: 20140602
# EMAIL:  cntqrxj@gmail.com

import os
from numpy import *

def square_matrix_multiply(A, B):
	shape = A.shape
	length = shape[1]
	half = length / 2
	C = zeros(shape, dtype = int64)
	if shape[1] == 1:
		C[0, 0] = A[0, 0] * B[0, 0]
	else:
		C[0:half, 0:half] = square_matrix_multiply(A[0:half, 0:half], B[0:half, 0:half]) + square_matrix_multiply(A[0:half, half:length], B[half:length, 0:half])
		C[0:half, half:length] = square_matrix_multiply(A[0:half, 0:half], B[0:half, half:length]) + square_matrix_multiply(A[0:half, half:length], B[half:length, half:length])
		C[half:length, 0:half] = square_matrix_multiply(A[half:length, 0:half], B[0:half, 0:half]) + square_matrix_multiply(A[half:length, half:length], B[half:length, 0:half])
		C[half:length, half:length] = square_matrix_multiply(A[half:length, 0:half], B[0:half, half:length]) + square_matrix_multiply(A[half:length, half:length], B[half:length, half:length])
	return C
	
A = array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])
B = array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])
print square_matrix_multiply(A, B)
