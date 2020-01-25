#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int is_palindrom(char *input){
	int len = strlen(input);
	int mid = len / 2;
	for(int i = 0; i < mid; i++){
		if(toupper(input[i]) != toupper(input[len - 1 - i])){
			return 0;
		}
	}
	return 1;
}

int main(){
	char *input_string = malloc(100);
	int len = 100;
	int pos = 0;
	char cur_char = getchar();
	while((cur_char != '\n') & (cur_char != '\0')){
		if (pos >= len - 2){
			len *= 2;
			input_string = realloc(input_string, len);
		}
		input_string[pos] = cur_char;
		pos++;
		cur_char = getchar();	
	}
	input_string[pos] = '\0';

	if (is_palindrom(input_string) == 1){
		printf("Palindrom\n");
	} else {
		printf("Kein Palindrom\n");	
	}
	free(input_string);
	return 0;
}
