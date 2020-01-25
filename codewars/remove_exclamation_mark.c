#include <stdio.h>
#include <string.h>

char* remove_bang(char* s)
{
    int iter;
	int out_count = 0;
	static char output[1000];
	strcpy(output, s);
	for (iter = 0; iter < (strlen(s) - 1); ++iter){
		if (s[iter] != '!'){
			output[out_count] = s[iter];
			++out_count;
		}
	}
	output[out_count+ 1] = '!';
	output[out_count + 2] = '\0';
	
	return output;
}


