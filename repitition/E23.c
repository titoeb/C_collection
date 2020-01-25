#include<stdio.h>
#include<stdlib.h>

int sudokucheck(const int** s);
int is_fullof(int *mat, int len, int value, int start);
void init_mat(int *mat, int value, int len);

int sudokucheck(const int** s){
	int checkmat[10];
	
	// Check rows
	for(int row = 0; row < 9; row++){
		init_mat(checkmat, 0, 10);
		for(int col = 0; col < 9; col++)
			checkmat[s[row][col]]++;
		if(is_fullof(checkmat, 10, 1, 1) == 0)
			return 0;
	}
	// Check columns
	for(int col = 0; col < 9; col++){
		init_mat(checkmat, 0, 10);
		for(int row = 0; row < 9; row++)
			checkmat[s[row][col]]++;
		if(is_fullof(checkmat, 10, 1, 1) == 0)
			return 0;
	}

	// Check all squares
	for(int start_row = 0; start_row < 9; start_row+=3){
		for(int start_col = 0; start_col < 9; start_col+=3){
			init_mat(checkmat, 0, 10);
			for(int row = 0; row < 3; row++){
				for(int col = 0; col < 3; col++){
					checkmat[s[start_row + row][start_col + col]]++;
				}
			}
			if(is_fullof(checkmat, 10, 1, 1) == 0)
			return 0;
		}
	}

	// If survived all the checks
	return 1;
}	



void init_mat(int *mat, int value, int len){
	for(int i = 0; i < len; i++){
		mat[i] = value;
	}
	return;
}

int is_fullof(int *mat, int len, int value, int start){
	// Check if all values in the mat are 1
	for(int i = start; i < len; i++){
		if (mat[i] != value)
			return 0;
	}
	return 1;
}

int main(){
 	/*int matrix[9][9] = {{5,3,4,6,7,8,9,1,2},
                        {6,7,2,1,9,5,3,4,8},
		        {1,9,8,3,4,2,5,6,7},
			{8,5,9,7,6,1,4,2,3},
			{4,2,6,8,5,3,7,9,1},
			{7,1,3,9,2,4,8,5,6},
			{9,6,1,5,3,7,2,8,4},
			{2,8,7,4,1,9,6,3,5},
			{3,4,5,2,8,6,1,7,9}}; */

  	int matrix[9][9] = { {5,3,4,6,7,8,9,1,2},
                        {6,4,2,1,9,5,3,7,8},
		        {1,9,8,3,4,2,5,6,7},
			{8,5,9,7,6,1,4,2,3},
			{4,2,6,8,5,3,7,9,1},
			{7,1,3,9,2,4,8,5,6},
			{9,6,1,5,3,7,2,8,4},
			{2,8,7,4,1,9,6,3,5},
			{3,7,5,2,8,6,1,4,9}};
	 const int* m[9];
 	 for (int i=0; i<9; i++) m[i] = matrix[i];
	
	printf("%d\n", sudokucheck(m));
	
	return 0;
}
