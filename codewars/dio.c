#include<stdio.h>
#include<stdlib.h>
#include<math.h>




typedef struct Pair Pair;
struct Pair {
    long long first;
    long long snd;
};
// fill length with the number of pairs in your array of pairs
Pair** solEquaStr(long long n, int* length) {
	// Calculate all possible solution to the problem
	int max_sol = (int) (sqrt(n) + 1);
	Pair solutions[max_sol];
	int num_solutions = 0;
	for(int i = 1; i <  (sqrt(n) + 1); ++i){
		if(n % i == 0){
			solutions[num_solutions].first = i;
			solutions[num_solutions].snd = n / i;
			++num_solutions;
		}
		
	}

	// for all possible solution test whether x, y is integer and numbers
	long long x,y;
	int found_final = 0;
	for(int i = 0; i < num_solutions; ++i){
		y = (solutions[i].snd - solutions[i].first) / 4;
		x = solutions[i].first + 2 * y;
		if((x - 2*y)*(x + 2*y) == n){
			++found_final;
		}
	}
	
	*length = found_final;
	Pair **result = (Pair**) malloc(found_final * sizeof(Pair*));
	int pos = 0;
	for(int i = 0; i < num_solutions; ++i){
		y = (solutions[i].snd - solutions[i].first) / 4;
		x = solutions[i].first + 2 * y;
		if((x - 2*y)*(x + 2*y) == n){
			result[pos] = malloc(sizeof(Pair));
			result[pos]->first = x;
			result[pos]->snd = y;
			++pos;
		}
	}

	return result;
}


int main(){
	int *length;
	Pair **res = solEquaStr(90005, length);
	//printf("There were %d solutions found\n", *length);
	printf("The solutions were:\n");
	Pair *cur;
	for(int i = 0; i < *length; ++i){
		cur =  *res;
		printf("X: %lld, Y: %lld \n", *cur->first, *cur->snd);
		//++res;
	}
	free(res);
}
