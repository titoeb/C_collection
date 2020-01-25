#include <stdio.h>


int main(){
	int a[3][3][6] = {{{0,1,2,3,4,5}, {6, 7, 8, 9,10,11}, {12,13,14,15,16,17}},
		 {{18,19,20,21,22,23}, {24,25,26,27,28,29}, {30,31,32,33,34,35}},
		 {{36,37,38,39,40,41}, {42,43,44,45,46,47}, {48,49,50,51, 52,53}}};
	
	printf("-------------------------------------------- \n" );
	printf("With the indexing operation\n");
	int iter_x, iter_y, iter_z;
	for (iter_x = 0; iter_x < 3; ++iter_x){
		for (iter_y = 0; iter_y < 3; ++iter_y){
			for(iter_z = 0; iter_z < 6; ++iter_z){
				printf("%d ", a[iter_x][iter_y][iter_z]);		
			}
			printf("\n");		
		}
		printf("\n");
	}
	
	printf("-------------------------------------------- \n" );
	printf("With a pointer operation\n");
	
	int *a_ptr = &a[0][0][0];

	for (iter_x = 0; iter_x < 3; ++iter_x){
		for (iter_y = 0; iter_y < 3; ++iter_y){
			for(iter_z = 0; iter_z < 6; ++iter_z){
				printf("%d ", *(a_ptr + (iter_x * 3 * 6) + (iter_y * 6) + iter_z));		
			}
			printf("\n");		
		}
		printf("\n");
	}
	
}
