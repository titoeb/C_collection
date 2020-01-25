#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char *strinv(const char *s){
	int len = strlen(s);
	char *out = malloc(sizeof(char) * (len + 1));
	for(int i = 0; i < len; i++){
		out[i] = s[len - 1 - i];
	}
	out[len+1] = '\0';
	return out;
}

char *strconcat(const char *s, const char *t){
	int len = strlen(s);
	char *out = malloc(sizeof(char) * (len + strlen(t) + 1));
	int i;
	for(i = 0; i < len; i++){
		out[i] = s[i];
	}
	for(i = 0; i < strlen(t); i++){
		out[len + i] = t[i];	
	}
	out[len + i + 1] = '\0';

	return out;
}


int main(){
	char one[] = "whatever";
	char two[] = " bohnenstange";
	printf("%s + %s = %s\n", one, two, strconcat(one, two));
	printf("%s backwards is %s what is %s backwards\n", one, strinv(one), strinv(strinv(one)));
}
