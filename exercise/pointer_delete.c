#include <stdio.h>

void set_array_zero(int array[], int length_array){
    int iter;
    for (iter = 0; iter < length_array; ++iter){
        *array = 0;
        
        ++array;
    }
}

int main()
{   
    int test_array[] = {1,2,3,4,5,6,7,8,9,0};
    int array_length = 10;

    int iter;
    for (iter = 0; iter < array_length; ++iter){
       printf("%d", test_array[iter]);
    }
    printf("\n");
    
    set_array_zero(test_array, 10);
    
    for (iter = 0; iter < array_length; ++iter){
       printf("%d", test_array[iter]);
    }
    printf("\n");
    
    return(0);
}