#include <stdio.h>

int numbers[] = {9,8,7,6,5,4,3,2,1};

void simple_sort(int *input_ptr, int length);
int *find_min(int *first_ptr, int length);

int main(){
	int *numbers_ptr = numbers;
	int iter;
	printf("The numbers before were:\n");
	for (iter = 0; iter < 9; ++iter){
		printf(" %d", numbers[iter]);	
	}
	simple_sort(numbers_ptr, 9);
	printf("\nThe numbers aftewards are:\n");
	for (iter = 0; iter < 9; ++iter){
		printf(" %d", numbers[iter]);	
	}
	printf("\n");
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
