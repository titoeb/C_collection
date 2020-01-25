 
#include <stdio.h>
#include <string.h>

/* Variable declaration */

int prim_hash(char string[]);
int iter;


int main (){
    char array[] = "Tim is the best";

    
    printf("The primitive hash code is %d", prim_hash(array));

    return (1);
}


int prim_hash(char string[]){
    int hash_code = 0;
    
    for (iter = 0; iter < strlen(string); ++iter){
        hash_code += (int)string[iter];
    }  
    
    return(hash_code);
}



