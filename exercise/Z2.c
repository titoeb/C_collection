#include <stdio.h>
#include <string.h>
#include <ctype.h>

void is_palin(char *begin_ptr, int len);

int main(void){
	char line[1000];
	fgets(line, sizeof(line), stdin);
	
	is_palin(&line[0], strlen(line) - 1);
}

void is_palin(char *begin_ptr, int len){
	
	int iter;
	if (len % 2 != 0){
		for (iter = 0; iter < ((len / 2) - 1); ++iter){
			if (toupper(*(begin_ptr + iter)) != toupper(*(begin_ptr + (len - 1 - iter)))){
				printf("kein Palindrom\n");	
				return;
			}	
		}
		if (*(begin_ptr + (len / 2)) == ' '){
			printf("Palindrom\n");	
		} else {
			printf("kein Palindrom\n");
		}

	} else {
		for (iter = 0; iter < (len / 2); ++iter){
			if (toupper(*(begin_ptr + iter)) != toupper(*(begin_ptr + (len - 1 - iter)))){
				printf("kein Palindrom\n");	
				return;
			}	
		}
		printf("Palindrom\n");
	}	
}
