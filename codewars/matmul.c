#include <stdio.h>
#include <stdlib.h>

int **matrix_multiplication(int **a, int **b, int n) {

	// Create the output matrix
	int **out_mat = malloc(n * sizeof(int*));
	
	for(int row_out = 0; row_out < n; row_out++){
		out_mat[row_out] = malloc(n * sizeof(int));
		for(int col_out = 0; col_out < n; col_out++){
			out_mat[row_out][col_out] = 0;
			for(int innest = 0; innest < n; innest++){
				out_mat[row_out][col_out] += a[row_out][innest] * b[innest][col_out];
			}
		}
	}
	return out_mat;	
}

int main(){
	return 0;
}
