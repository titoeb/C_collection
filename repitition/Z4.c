#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int strend(const char *s, const char *t){
	if(strlen(t) > strlen(s))
		return 0;
	for(int i = strlen(s) - strlen(t); i < strlen(s); i++){
		if(*(s+i) != *(t+i - (strlen(s) - strlen(t))))
			return 0;
	}
	return 1;
}

char *strrchr (const char *s, int c){
	char *output = NULL;
	for(int i = 0; i < strlen(s); i++){
		if(s[i] == c){
			output = &s[i];
		}
	}
	return output;
}

char *strstr (const char *s, const char *t){
	int found = 0;
	for(int i = 0; i < strlen(s) - strlen(t); i++){
		for(int j = 0; j < strlen(t); j++){
			if(*(s + i + j) == *(t + j)){
				found = 1;		
			} else {
				found = 0;
				break;			
			}
		}
		if(found == 1){
			return s + i;
		}
	}
	return NULL;
}

int main(){
	printf("%d\n", strend("o", "Hallo"));

	char test[] = "timmi the beeast";
	printf("%c diff to start is %ld\n", *strrchr(test, 'e'), strrchr(test, 'e') -  &test[0]);
	printf("%c\n", *strstr("Hallo", "Hallo"));
	printf("%p\n", strstr("o", "Hallo"));
	printf("%c\n", *strstr("Eisenbahn", "bahn"));	
	return 0;
}



