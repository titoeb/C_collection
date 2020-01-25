#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **cartesian_neighbor(int x, int y){    
    int pos = 0;
    int *result = (int*) malloc(8 * 2 * sizeof(int));
    for (int i = x - 1; i <= x + 1; ++i){
      for (int j  = y - 1; j <= y + 1; ++j){
        if(!((x == i) && (y == j))){
          *(result + pos) = i;
          *(result + 1 + pos) = j;
          printf(" %d %d \n", *(result + pos), *(result + 1 + pos));
          pos += 2;
        }
      }
    }

    printf("Survived first for loop!\n");
    int **res = (int**) malloc(8 * sizeof(int*));
	printf("%p\n", res);
    int **res_itr = res;
	printf("%p\n", res_itr);
    //res = &result;
   

    
    printf("lets go!\n");
    for(int i = 0; i < 8; i++){
      res = &result;
	printf("Current result is at %p and hols value %d \n res_itr is pointing to %p with value %d\n", result, *result, *res, **res);
      res++;
      result++;
      result++;
    } 

    for(int i = 0; i < 8; i++){
	res--;
    }  
   return res;
}

int main(){
	
	int **res = cartesian_neighbor(1,2);
	printf("%p\n", res);
	/*for (int i = 0; i < 8; i++){
		printf("%d %d ", **res, *(*(res)+1));
	} */	
	free(res); 

}
