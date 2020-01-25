 
#include <stdio.h>
#include <string.h>

/* Variable declaration */

int count(int number, int array[], int length);

int main (){
    int number = 10;
    int array[5] = {0, 0, 0, 0, 0};
    int length = 5;
    
    printf("The number %d occurs %d times in the array", number, 
    count(number, array, length));

    return (1);
}


int count(int number, int array[], int length){
    if (length == 0){
        return 0;
    } else {
        if (array[length - 1] == number) {
            return 1 + count(number, array, length -1);
        } else {
            return 0 + count(number, array, length -1);
        }
    }
        
}



