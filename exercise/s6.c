#include <stdio.h>
#include <string.h>

int is_decimal(char *first_ptr, int len);

int main(){
	int input_f;
	char line[100];
	while(fgets(line, sizeof(line), stdin)){
		/* Test the char */
		if (is_decimal(&line[0], strlen(line)) == 0){
			return 1;		
		}
	
		/* If it survived give the resulting numbers out */
		sscanf(line, "%d", &input_f);
		printf("OKT: %o HEX: %x\n",input_f, input_f);
	}
	return 0;
}


int is_decimal(char *first_ptr, int len){
	int iter;	
	char  cur_char;
	/* Check for each char whether it is a number or a point. If it is something else it can't be a float */
	for (iter = 0; iter < (len-1); ++iter){
		cur_char = *(first_ptr + iter);
		if ( (cur_char < 48) | (cur_char > 57)){
			return 0;
		}		

	}
	return 1;	
}
