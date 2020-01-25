#include <stdio.h>
#include <string.h>

int numbers[100];

void simple_sort(int *input_ptr, int length);
int *find_min(int *first_ptr, int length);
int is_integer(char *first_ptr, int len);


int main(){
	/* Input of the numbers */
	int iter = 0;
	int cur_input;
	char input[100];

	printf("Bitte bis zu 100 ganze Zahlen eingeben:\n");
	while(fgets(input, sizeof(input), stdin)){
		if (!sscanf(input, "%d", &cur_input)){
			printf("Fehler bei der Eingabe.\n");
			continue;		
		}
		if (is_integer(&input[0], strlen(input)) != 1){
			printf("Fehler bei der Eingabe.\n");
			continue;		
		}
		numbers[iter] = cur_input;	
		++iter;
		if (iter >= 99){
			break;
		}
	}
	
	/* Sorting the numbers */
	int *numbers_ptr = numbers;
	int length = iter;
	printf("Die zu sortierenden Zahlen:");
	for (iter = 0; iter < length; ++iter){
		printf(" %d", numbers[iter]);	
	}
	simple_sort(numbers_ptr, length);
	printf("\nDie Zahlen sortiert:");
	for (iter = 0; iter < length; ++iter){
		printf(" %d", numbers[iter]);	
	}
	printf("\n");

	return 0;
}

void simple_sort(int *input_ptr, int length){
	int *cur_min;
	int temp;
	if (length <= 1){
	
	} else {
		cur_min = find_min(input_ptr, length);
		temp = *input_ptr;
		*input_ptr = *cur_min;
		*cur_min = temp;
		++input_ptr;
		simple_sort(input_ptr, (length - 1));
	}
}

int *find_min(int *first_ptr, int length){
	int *cur_min = first_ptr;
	int iter;
	for(iter = 1; iter < length; ++iter){
		++first_ptr;
		if (*cur_min > *first_ptr){
			cur_min = first_ptr;		
		}
	}
	return cur_min;	
}

int is_integer(char *first_ptr, int len){
	int iter;	
	char  cur_char;
	/* Check for each char whether it is a number. If it is something else it can't be an integer */
	for (iter = 0; iter < (len-1); ++iter){
		cur_char = *(first_ptr + iter);
		if ( ((cur_char < 48) || (cur_char > 57)) && (cur_char != 45)){
				return 0;
		}		
	}
	return 1;
}
