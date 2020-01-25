 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
int iter;
int inner_iter;
int product;

int main (){
    for (iter = 0; iter < 10; ++iter){
        for (inner_iter = 0; inner_iter < 10; ++inner_iter){
            product =  iter * inner_iter;
            if (product < 10){
                if (inner_iter != 0){
                   printf(" %d ", product); 
                } else{
                    printf("%d ", product);
                }
                
            } else {
                printf("%d ", product);
            }
            
        }
        printf("\n");
    }
	return(0);
}