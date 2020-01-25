#include <string.h>
#include<ctype.h>

char *accum(const char *source){
    
	int len = strlen(source);
    int iter = 0;
	int inner_iter = 0;
	/* Calculate output length */
	int output_length = 0;
	for (iter = 1; iter <= len; ++iter){
		output_length += iter;
	}
	output_length += len - 1;
	
	char output[output_length];
	char *output_ptr = &output[0];
    
    iter = 0;
    while(iter < len){
        for (inner_iter = 1; inner_iter <= iter; ++inner_iter){
			if (inner_iter == 1){
				*output_ptr = toupper(*source);
			} else {
				*output_ptr = tolower(*source);
			}
			++output_ptr;
		}
		*output_ptr = '-';
		++output_ptr;
        ++source;
        ++iter;
    }
	--output_ptr;
	*output_ptr = '\0';
	
	printf("\n%s \n", output);

    return (output);
}

int main(void){
	char test[] = "abcd";
	accum(test);
}