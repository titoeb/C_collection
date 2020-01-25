 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
int count_words(char[]);
int iter = 0;


int main (){
    char line[100];
    printf("Please type in a sentence: ");
    fgets(line, sizeof(line), stdin);
    
    printf("The number of words is %d", count_words(line));

    return (1);
}

int count_words(char sentence[]){
    int word_count = 0;
    char last_char = ' ';
    
    for (iter = 0; iter < strlen(sentence); ++iter){
        if ((sentence[iter] != ' ' && sentence[iter] != ',' && sentence[iter] != '.' && sentence[iter] != '\0') 
        && (last_char == ' ' || last_char == ',' || last_char == '.')){
            printf("%c \n", sentence[iter]);
            ++ word_count;
        }
        last_char = sentence[iter];
    }
    
    return(word_count);
}


