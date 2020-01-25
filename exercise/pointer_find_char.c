#include <stdio.h>
#include <string.h>
char *first_character(char input_string[]){
    while (*input_string != '\0'){
        if (*input_string != ' ') {
            return (input_string);
        }
        ++input_string;
    }
}

int main(void)
{   
    char test_string[] = "      let's go";
    test_string[strlen(test_string)-1] = '\0';
    printf("The first character is %c", *first_character(test_string));
    
    return(0);
}