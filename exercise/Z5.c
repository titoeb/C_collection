 #include <stdio.h>
#include <string.h>


int *find_min(int *first_ptr, int length);
int sortieren(int *von, int *bis);



int main(){
	int numbers[] = { 3 ,7, 5, 5, 2, 1, 6, 10, 9, 4};
	int *ptr = numbers + 7;
	printf("%d\n", sortieren(&numbers[3], &numbers[5]));
	printf("The array is ... \n");
	for(int i = 0; i < (sizeof(numbers) / sizeof(numbers[0])); ++i){
		printf("%d\n", numbers[i]);
	}

}


int sortieren(int *von, int *bis){
	long int len = bis - von;
	int count = 0;
	int temp;
	int *von_temp = von;
	int *cur_min;
	for (int i = 0; i < len; ++i){
		cur_min = find_min(von, len - i);
		if (*cur_min < *von){
		temp = *von;
		*von = *cur_min;
		*cur_min = temp;	
		++count;
		}		

		++von;
	}
	
	return count;
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

 
