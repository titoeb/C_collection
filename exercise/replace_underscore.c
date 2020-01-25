 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
int iter;


int main (){
    char array[] = "This-is-an-example";
    char array_replace[strlen(array)];
    strcpy(array_replace, array);
    
    for (iter = 0; iter < strlen(array); ++iter){
        if (array[iter] == '-'){
            array_replace[iter] = '_';
        }
    }
    
    printf("The orginial string was\n%s \nand after replacing \'-\' with \'_\' it was \n%s \n",
    array, array_replace);
    
    return(1);
}



