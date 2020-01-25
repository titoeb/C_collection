#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* All helper functions */
char *new_space(char *begin, int num);
char *add_val_pos(char *begin, int val, int pos);
char *add_string_pos(char *begin, char *val, int pos);
char *multiply_char(char *a, char b);
char *clean_string(char *input);


/* -------------- */
char *clean_string(char *input){
	int count_lead_zero = 0;
	for(int i =0; i < strlen(input); i++){
		if (input[i] == '0')
			++count_lead_zero;
		else
			break;
	}
	if(count_lead_zero > 0){
		char * output = malloc(sizeof(char) * (strlen(input) + 1 - count_lead_zero));
		strcpy(output, input + count_lead_zero);
		free(input);
		return output;
	}
	return input;
}

char *multiply(char *a, char *b) {
	if(atoi(a) == 0 || atoi(b) == 0){
		char *out = malloc(sizeof(char) * 2);
		out[0] = '0';
		out[1] = '\n';
		return out;
	}
	if (a[0] == '0')
		a = clean_string(a);

	if(b[0] == '0')
		b = clean_string(b);


	char *tmp = NULL;
	char *out = malloc(sizeof(int) * (strlen(a) + 1));
	for(int i = 0; i < strlen(a); i++){
		out[i] = '0';
	}
	out[strlen(a)] = '\0';
	int pos = 0;
	//printf("initial out is %s\n", out);
	for(int i = strlen(b) - 1; i >= 0; --i){
		tmp = multiply_char(a, b[i]);
		
		out = add_string_pos(out,tmp, strlen(out) - pos - 1);
		//printf("tmp was %s inserted into  out at pos %ld and the result was is %s\n",tmp, strlen(out) - 1 - pos, out);
		++pos;
	}

	return out;
}
char *multiply_char(char *a, char b) {
	// Create the output string
 	char *out = malloc(sizeof(char) * (strlen(a) + 1));
	
	// Fill the string with zeros
	for(int i = 0; i < strlen(a); ++i){
		out[i] = '0';
	}
	out[strlen(a)] = '\0';
	
	// Iterate over the elements of the original string and multiply the elements
	int val = 0;
	int mult = b - 48;
	for(int i = (strlen(a) - 1); i >= 0; --i){
		val = (*(a + i) - 48) * mult;
		//printf("val is %d and pos is %d\n", val, i);
		out = add_val_pos(out, val, i);
		//printf("New output is %s\n", out);
	}

	return out;
}

char* add_val_pos(char *begin, int val, int pos){
	int prod = 0;
	if (pos < 0){
		while(pos < 0){
			begin = new_space(begin, 0);
			++pos;
		}
	}	
	while(val > 0 || prod > 0){
		prod += (val % 10) + (*(begin + pos) - 48);
		*(begin + pos) = prod % 10 + 48;
		prod = prod / 10;
		val = val / 10;
		--pos;
		if (pos < 0 && (val > 0 || prod > 0)){
			begin = new_space(begin, 0);
			pos = 0;
		}
	}

	return begin;
}

char *new_space(char *begin, int num){
	int len = strlen(begin);
	// Reallocate begin with one more place
	char* new = malloc(sizeof(char)  * (len + 2));
	len = len + 1;	
	sprintf(new,"%d%s",num, begin);
	free(begin);

	return new;
}

char *add_string_pos(char *begin, char *val, int pos){
	int init_dif = strlen(begin) - (pos + 1);
	int curpos;
	//printf("init dif is %d\n", init_dif);
	for(int i = 0; i < strlen(val); i++){	
		curpos = i + init_dif + 1;
		//printf("begin was %s before adding %d at position %ld and afterwards ", begin, val[strlen(val) - 1 - i] - 48, strlen(begin) - curpos);		
		begin = add_val_pos(begin, val[strlen(val) -1- i] - 48, strlen(begin) - curpos);
		//printf("%s\n", begin);
	}
	return begin;
}


int main(int argc, char* argv[]){
	char *test1 = malloc(sizeof(char) * 5);
	strcpy(test1, "2");

	char *test2 = malloc(sizeof(char) * 5);
	char *out;
	strcpy(test2, "0");
	//test2 = add_val_pos(test2, 18, 0);
	out = multiply(test1, test2);
	//out = add_string_pos(test1, test2, 1);
	//out = add_val_pos(test1, 8, 0);

	printf("%s\n", out);
	
	free(out);
	free(test2);
	free(test1);

}
