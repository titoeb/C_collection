#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char *reverse_letter(const char *str);

int main(){
	char *result = reverse_letter("Ti&m");
	printf("%s\n", result);
	
}


char *reverse_letter(const char *str){
	// Count the number of alphatetic characters
	int len = 0;
	int iter = 0;
	while(*(str + iter) != '\0'){
		if(isalpha(*(str + iter))){
			++len;
			printf("%c was a valid char\n", *(str + iter));
		}
		++iter;		
	}

	char *ret = (char*) malloc((len + 1) * sizeof(char));
	int pos = 0;
	for(int i = strlen(str); i >= 0; --i){
		if(isalpha(*(str + i))){
			*(ret + pos) = *(str + i);
			++pos;
		}
	}
	*(ret + pos) = '\0';

	return ret;
}
