 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
float numbers[] = {1, 2};
float sum = 0;
int number_elements;
float average;
int iter;

int main (){
    number_elements = (sizeof(numbers) / sizeof(numbers[0]));

    for(iter = 0; iter < number_elements; ++iter){
        sum += numbers[iter];

    }
    
    average = sum / number_elements;
    
    printf("The average of the numbers is %f \n", average);
	return(0);
}