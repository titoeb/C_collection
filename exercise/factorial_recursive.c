 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
int fact(int number);

int main (){
    int number = -3;
    printf("%d \n", fact(number));
    return(0);
}

int fact(int number){
    if (number == 0)
        return (1);
    /* else */
    return(number * fact(number - 1));
}
