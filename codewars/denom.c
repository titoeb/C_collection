#include<stdio.h>
#include<stdlib.h>


long long great_div(long long val1, long long val2){
	if (val2 == 0)
		return val1;
	else
		return great_div(val2, val1 % val2);
}

long long find_denom_intern(long long val1, long long val2){
	return (val1 * val2) / great_div(val1, val2); 
}

long long find_denom(long long denoms[], int len){
	long long denom = denoms[0];
	for(int i = 1; i < len; i++){
		denom = find_denom_intern(denom, denoms[i]);
	}
	return denom;
}

long long** convertFrac(long long lst[][2], int row) {
 	long long denoms[row];
	for(int i = 0; i < row; i++){
		denoms[i] = lst[i][1];
	}
	long long com_denom = find_denom(denoms, row);

	long long** output = malloc(sizeof(long*) * row);
	for(int i = 0; i < row; i++){
		output[i] = malloc(sizeof(long) * 2);
		output[i][0] = lst[i][0] * (com_denom / lst[i][1]);
		output[i][1] = com_denom;
	}
	return output;
	
}

int main(){
	long long input[3][2] = {{77, 130}, {84, 131}, {3, 4}};
	long long **out = convertFrac(input, 3);
	for(int i = 0; i < 3; i++){
		printf("%lld / %lld\n", out[i][0], out[i][1]);	
	}

}
