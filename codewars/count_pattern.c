#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search_substr(const char *full_text, const char *search_text, bool allow_overlap) {
	int outer_len = strlen(full_text);
	int inner_len = strlen(search_text);
	int count = 0;
	int found;

	if (allow_overlap == true){
		for(int outer_pos = 0; outer_pos < outer_len; outer_pos++){
			found = 0;
			for(int inner_pos = 0; inner_pos < inner_len; inner_pos++){
				if(full_text[outer_pos + inner_pos] == search_text[inner_pos]){
					found = 1;
				} else {
					found = 0;
					break;				
					}
			}
			if (found == 1)
				count++;
		}
	} else {
		for(int outer_pos = 0; outer_pos < outer_len; outer_pos++){
			found = 0;
			for(int inner_pos = 0; inner_pos < inner_len; inner_pos++){
				if(full_text[outer_pos + inner_pos] == search_text[inner_pos]){
					found = 1;
				} else {
					found = 0;
					break;				
					}
			}
			if (found == 1){
				count++;
				outer_pos += inner_len;
			}
		}
	}

	return count;
}

int main(int argc, char *argv[]){
	printf("%d\n", search_substr(argv[1], argv[2], argv[3]));
	return 0;
}
