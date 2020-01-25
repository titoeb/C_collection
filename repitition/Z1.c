#include<stdio.h>
#include<string.h>

int bin_to_dec(char input[], int len){
	int result = 0;
	int pow = 1;
	for(int i = len; i >= 0; i--){
		result += pow * (input[i] - '0');
		pow *= 2;
	}
	return result;
}

int main(){
	char read[64];

	// Read the binary number
	char cur_char = getchar();
	int pos = 0;
	while((cur_char != '\n') & (pos < 64)){
		if ((cur_char == '0') | (cur_char == '1')){
			read[pos] = cur_char;
			cur_char = getchar();
			pos++;
		} else {
			printf("Fehler bei der Eingabe!\n");
			return 0;			
		}
	}
	for(int i = 0; i < pos; i++){
		printf("%c", read[i]);
	}
	printf("\n");

	printf("Dezimal: %d\n", bin_to_dec(read, pos - 1));
	return 0;
}
