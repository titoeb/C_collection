 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
float resistors[] = {400, 200, 1000, 10};
float inverse_sum = 0;
int number_elements;
int iter;
float result;

int main (){
    number_elements = (sizeof(resistors) / sizeof(resistors[0]));

    for(iter = 0; iter < number_elements; ++iter){
        inverse_sum = (inverse_sum + (1.0 / resistors[iter]));

    }
    
    result = (1.0 / inverse_sum);
    
    printf("The resistence is %f \n", result);
	return(0);
}