#include<stdio.h>
int permtest(const unsigned int* p, int laenge){
	if (laenge == 1){
		if (*p == 1){
			return 1;		
		} else {
			return 0;
		}
	}
	
	for(int iter = 1; iter < laenge; ++iter){
		int found = 0;
		for (int inner_iter = 0; inner_iter < laenge; ++inner_iter){
			if (*(p + inner_iter) == iter){
				found = 1;			
			}	
			if (*(p + inner_iter) == 0){
				return 0;			
			}		
		}
		if (found == 0){
			return 0;		
		}	
	}
	return 1;	
}

int main(){
	int a[] = {1,3,6,8,2,10,9,11,12,4,7,5};
	printf("%d\n", permtest(a, 9)); 
}
