#include <stdio.h>
#include <string.h>


int find_pattern(char *text, char *pattern);


int main(int argc, const char * argv[]){
	char * text = argv[1];
	char * pattern = argv[2];
	int pos_pattern = find_pattern(text, pattern);
	printf("%d\n", pos_pattern);
	printf("and the char is \"%c\"\n", text[pos_pattern]);
}	


int find_pattern(char *text, char *pattern){
	int pos_text;
	int pos_pattern = 0;
	int len_text = strlen(text);
	int len_pattern = strlen(pattern);

	for (pos_text = 0; pos_text < len_text; ++pos_text){
		if(text[pos_text] == pattern[0]){
			printf("Found the first element at %d \n", pos_text);
			for (pos_pattern = 1; pos_pattern < len_pattern; ++pos_pattern){	
				if (text[pos_text + pos_pattern] != pattern[pos_pattern]){
					break;				
				}
			return pos_text;
			}			
		}
	}
	return 0;
	
}
