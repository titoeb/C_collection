 
#include <stdio.h>
#include <string.h>

/* Variable declaration */

int max(int numbers[]);
int iter;
int numbers[] = {10, 20, 100, 4, 100};

int main (){
    int curr_max = numbers[0];
    
    for (iter = 1; iter < (sizeof(numbers) / sizeof(numbers[0])); ++iter){
        if (numbers[iter] > curr_max){
            curr_max = numbers[iter];
        }
    }  
    
    
    return(curr_max);
}



