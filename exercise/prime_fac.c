#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int is_prime(int cand){
	if(cand % 2 == 0){
		if(cand == 2) return 1;
		else return 0;
	}
	for(int i = 3; i < (int) sqrt(cand) + 1; i++){
		if(cand % 2 == 0) return 0;
	}
	return 1;
}

char* factors(int lst) {
	int len = (int) sqrt(lst) + 1;
	char *out = malloc(sizeof(char) * (6 * len + 1)); // maybe too short!
	int cur_num = 2;
	int count_cur = 0;
	int pos = 0;
	while(lst > 1){
		if(lst % cur_num == 0){
			count_cur++;
			lst = lst / cur_num;
		} else {
			// Write current in string
			if(count_cur > 0){
				if(count_cur == 1){
					out[pos] = '(';
					pos++;
					out[pos] = cur_num + '0';
					pos++;
					out[pos] = ')';
					pos++;
				} else {
					out[pos] = '(';
					pos++;
					out[pos] = cur_num + '0';
					pos++;
					out[pos] = '*';
					pos++;
					out[pos] = '*';
					pos++;
					out[pos] = count_cur + '0';
					pos++;
					out[pos] = ')';
					pos++;
				}
			}
			
			// raise value to next prime and clean count_cur;
			cur_num++;
			while(!is_prime(cur_num) && cur_num <= len) cur_num++;
			count_cur = 0;
			printf("cur_num is %d\n", cur_num);
		}
	}
	if(count_cur > 0){
		printf("cur_num is %d\n", cur_num);
		if(count_cur == 1){
			out[pos] = '(';
			pos++;
			out[pos] = cur_num + '0';
			pos++;
			out[pos] = ')';
			pos++;
		} else {
			out[pos] = '(';
			pos++;
			out[pos] = cur_num + '0';
			pos++;
			out[pos] = '*';
			pos++;
			out[pos] = '*';
			pos++;
			out[pos] = count_cur + '0';
			pos++;
			out[pos] = ')';
			pos++;
		}
	}
	out[pos] = '\0';
	return out;
}

int main(){
	char *res = factors(86240);
	printf("%s\n", res);
	free(res);
}


