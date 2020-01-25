#include<stdio.h>


int sudokucheck(const int** p);
int pt_ar_check_row(const int *p);

int pt_ar_check_row(const int *p);
int pt_ar_check_row(const int *p){
	int exists[9] ={0};
	// In p we got an array of 9 pointers, each pointing to an integer value.
	// I use the integer value to set the number at the correct position in the 
	// integer matrix exists to one. All numbers from zero to nine exist if 
	// all elements in exists are one!	
	for (int i = 0; i < 9; ++i){
		exists[*(p + i) - 1] = 1;
	}
	
	// Check whether all elements in exists are one!
	for (int i = 0; i < 9; ++i){
		if (exists[i] != 1){
			return 0;		
		}	
	}
	return 1;

}

int sudokucheck(const int** p){

	// make the doulbe pointer back to matrix.
	int matrix[9][9];
	int selection[9];
	 for(int i=0; i<9; i++){
		for (int j = 0; j < 9; ++j){
		  matrix[i][j] = *(p[i] + j);	
		}	
	} 
	// Check for rows
	for (int iter = 0; iter < 9; ++iter){
		if (pt_ar_check_row(p[iter]) == 0){
		return 0;
		}
	}

	// Check for columns
	for (int iter = 0; iter < 9; ++iter){
		for (int inner_iter = 0; inner_iter < 9; ++inner_iter){
			selection[inner_iter] = matrix[inner_iter][iter];
		}	
		if (pt_ar_check_row(selection) == 0){
			return 0;
		}
	}

	int num;
	// Check for the blocks
	for (int iter = 0; iter < 9; iter += 3){
		for (int inner_iter = 0; inner_iter < 9; inner_iter+= 3){
			num = 0;
			for (int row = 0; row < 3; ++row){
				for (int col = 0; col < 3; ++col){
					selection[num] = matrix[iter + row][inner_iter + col]; 	
					++num;		
				}
				

			}
			if (pt_ar_check_row(selection) == 0){
				return 0;
			}
		}	

	}
	return 1;
}


int main(){
int laenge=9;
  int matrix[9][9] = {  {5,3,4,6,7,8,9,1,2},
                        {6,7,2,1,9,5,3,4,8},
		        {1,9,8,3,4,2,5,6,7},
			{8,5,9,7,6,1,4,2,3},
			{4,2,6,8,5,3,7,9,1},
			{7,1,3,9,2,4,8,5,6},
			{9,6,1,5,3,7,2,8,4},
			{2,8,7,4,1,9,6,3,5},
			{3,4,5,2,8,6,1,7,9}};
  const int* m[9];
  for (int i=0; i<laenge; i++) m[i] = matrix[i];
	printf("%d\n", sudokucheck(m));
   if (sudokucheck(m) == 1) {
	printf("hi!");
  }

}
