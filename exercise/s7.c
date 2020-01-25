#include <stdio.h>
#include <string.h>

int is_decimal(char *first_ptr, int len);
int quersumme(int input){
	int result = 0;
	while (input > 0){
		result += input % 10;
		input /= 10;		
	}
	return result;	
}

int main(){
	int user_input;
	char line[100];
	fgets(line, sizeof(line), stdin);
	if (is_decimal(&line[0], strlen(line)) == 0 || strlen(line) == 1){
		printf("Fehler bei der Eingabe\n");
		return 1;		
	}
	sscanf(line, "%d", &user_input);

	printf("Quersumme: %d\n..", quersumme(user_input));
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
