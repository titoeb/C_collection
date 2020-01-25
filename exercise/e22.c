
#include<stdio.h>

int permatcheck(const int** p, int laenge){
	for(int iter = 0; iter < laenge; ++iter){
		int found = 0;
		for (int inner_iter = 0; inner_iter < laenge; ++inner_iter){
			if(*(*(p + iter) + inner_iter) == 0){}	
			else{

				if(*(*(p + iter) + inner_iter) == 1){
					++found;
					if (found > 1){
						return 0;			
					}	
				} else {
					return 0;
				}				
							
			}	
		}
		if(found == 0){
			return 0;
		}	
	}
	return 1;
}

int main(){
	//int permu[2][2] = {{0, 1}, {1, 0}};
  	int permu[1][1] = {{1}};
	permu[0][0] = 0;
	const int* m[1];
	m[0] = permu[0];
	printf("%d\n",permatcheck(m, 1));
}
