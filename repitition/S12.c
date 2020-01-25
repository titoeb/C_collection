#include<stdio.h>


int main(){
	char freq[256];

	for(int i = 0; i < 256; i++)
		freq[i] = 0;

	char cur_char = getchar();

	// read in char and count them accordingly
	while((cur_char != '\n') & (cur_char != '\0')){
		freq[cur_char]++;
		cur_char = getchar();
	}

	// Write out commands
	for(int i = 0; i < 32; i++){
		if(freq[i] > 0)
			printf("<CTRL> %d : %d\n", i, freq[i]);
	}

	// Write out actual chars
	for(int i = 32; i < 256; i++){
		if(freq[i] > 0)
			printf("%c : %d\n", i, freq[i]);
	}

	return 0;
}
