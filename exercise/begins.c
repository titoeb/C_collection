 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
int iter;
int begins(char string1[], char string2[]);


int main (){
    char string1[] = "Tim is cool";
    char string2[] = "Tim";
    
    printf("This should return true: \n");
    printf("%d \n", begins(string1, string2));
    
    strcpy(string2, "tim");
    printf("This should return false: \n");
    printf("%d \n", begins(string1, string2));

    return (1);
}

int begins(char string1[], char string2[]){
    for(iter = 0; iter < strlen(string2); ++iter){
        if (string1[iter] != string2[iter]){
            return (0);
        }
    }
    
    return (1);
}




