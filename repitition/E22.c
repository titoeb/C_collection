#include<stdio.h>
#include<stdlib.h>


int permatcheck(const int** p, int laenge){
	
	// Check rows
	int row_sum;
	for(int row = 0; row < laenge; row++){
		row_sum = 0;
		for(int col = 0; col < laenge; col++){
			row_sum += p[row][col];
		}
		if(row_sum != 1)
			return 0;
	}

	// Check columns
	int col_sum;
	for(int col = 0; col < laenge; col++){
		col_sum = 0;
		for(int row = 0; row < laenge; row++){
			col_sum += p[row][col];
		}
		if(col_sum != 1)
			return 0;
	}
	return 1;
	
}

int main(){
	return 0;
}
