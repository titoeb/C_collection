#include<stdio.h>
#include<stdlib.h>

int *paint_letterboxes(int start, int end);

int main(){
	int start = 125;
	int end = 132;
	int *res = paint_letterboxes(start, end);	
	printf("The numbers were: ");
	for(int i = 0; i <= (end - start); i++){
		printf("%d ", *(res + i));
	} 	
	printf("\n");
	
}

int *paint_letterboxes(int start, int end)
{	
	int n_boxes = end - start + 1;
	int boxes[n_boxes];
	for (int i = 0; i < n_boxes; ++i){
		boxes[i] = start;
		++start;
	}
	
	int save_num[10] = {0};
	int cur_num;
	for (int i = 0; i < n_boxes; ++i){
		cur_num = boxes[i];
		while(cur_num > 0){
			++save_num[cur_num % 10];
			cur_num /= 10;
		}
	}
	int *res = (int*) calloc(10, sizeof(int));
	for(int i = 0; i < 10; ++i){
		*(res + i) = save_num[i];
	}
	return res;
}
