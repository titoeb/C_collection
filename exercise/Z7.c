#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char *strinv(const char *s);
char *strconcat(const char *s, const char *t);

int main(){

	char string[] = "Tim ist";
	printf("%s\n", strinv(string));

	char string2[] = "Tim ist ... ";
	char string3[] = "Der coolste!";
	printf("\"%s\"\n", strconcat(string2, string3));

}


char *strinv(const char *s){
    int len = strlen(s);
    char *inverse = (char*) malloc(len * sizeof(char));
    int iter = 0;
    for(int i = (len -1 ); i >= 0; --i){
        inverse[iter] = *(s + i);
	++iter;
    }
    return inverse;
 }
 

char *strconcat(const char *s, const char *t){
	int len_s = strlen(s);
	int len_t = strlen(t);
	char *app = (char*) malloc((len_s + len_t) * sizeof(char));
	for (int i = 0; i < len_s; ++i){
		*(app + i) = *(s + i);	
    	}
	for (int i = 0; i < len_t; ++i){
		*(app + len_s + i) = *(t + i);	
    	}
	*(app + len_s + len_t) = '\0';
	return app;
}
