#include<stdio.h>


int schaltjahr(int jahr);

int main(){

}


int schaltjahr(int jahr){
	if (jahr %% 4 == 0){
		if (jahr % 100 == 0){
			if (jahr % 400 == 0){
				return 1;		
			}
			return 0;
		}
		return 1;
	}
	return 0;
}
