#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int sortieren(int *von, int *bis);
int *min(int *von, int* bis){
	int *min = von;
	for(von++; von <= bis; von++){
		if(*von < *min){
			min = von;		
		}
	}
	return min;
	
}

int sortieren(int *von, int *bis){
	int count = 0;
	int tmp;
	int *cur_min;
	for(von; von <= bis; von++){
		cur_min = min(von, bis);
		if(*von > *cur_min){
			// Have to replace!
			tmp = *von;
			*von = *cur_min;
			*cur_min = tmp;
			count++;
					
		}
	}
	return count;
}

int main(){

	int len = 100000;
	int *test = malloc(sizeof(int) * len);
	for(int i = 0; i < len; i++){
		test[i] = rand() / 100000;
	}

	printf("The array before: ");	
	for(int i = 0; i < len; i++){
		printf("%d ", test[i]);
		
	}
	printf("\n");

	printf("Did %d replacements.\n", sortieren(&test[0], &test[len - 1]));
	printf("The array afterwards: ");	
	for(int i = 0; i < len; i++){
		printf("%d ", test[i]);
		
	}
	printf("\n");

	free(test);
	return 0;
}
