#include<stdio.h>
#include<limits.h>


int sequence(int x, int n){
	
	for(int i = 0; i <= n; i++){
		if(i < 0){
			 x = 0;
		} else if(i == 0){
			 x = x;
		} else if (i > 0){
			if(x % 2 != 0){
				// Zahl ist ungerade!
				// Test fuer uber lauf
				if (x > (INT_MAX - 1) / 3 ){
					return -1;
				} else {
					x = 3 * x + 1;
				}
			} else {
				// Zahl ist gerade!	
				x = x / 2;
			}

		}
	}
	return x;
}



