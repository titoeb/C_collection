#include <stdio.h>
#include <string.h>

int is_float(char *first_ptr, int len);

int main(){
	double sum;
	double input_f;
	int iter = 0;
	char input[100];
	while(fgets(input, sizeof(input), stdin)){
		if (!sscanf(input, "%lf", &input_f)){
			printf("Fehler bei der Eingabe.\n");
			continue;		
		}
		
		if (is_float(&input[0], strlen(input)) == 0){
			printf("Fehler bei der Eingabe.\n");
			continue;		
		}

		sum += input_f;		
		++iter;
	}
	printf("Lösung: %lf\n", sum / (double) iter);
	return 0;	
}

int is_float(char *first_ptr, int len){
	int iter;	
	int decimal_point = 0;
	char  cur_char;
	/* Check for each char whether it is a number or a point. If it is something else it can't be a float */
	for (iter = 0; iter < (len-1); ++iter){
		cur_char = *(first_ptr + iter);
		if (cur_char == 46) {
			decimal_point = 1;
		} else {
			if ( ((cur_char < 48) || (cur_char > 57)) && (cur_char != 45)){
				return 0;
			}		
		}

	}
	if (decimal_point == 1){
		return 1;
	} else {
		return 0;	
	}
}
