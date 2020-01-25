#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int strclean(char *t){
	if(t == NULL) return -1;
	int t_len = strlen(t);
	char out[t_len + 1];
	int pos = 0;
	for(int i = 0; i < t_len; i++){
		if(!((t[i] == ' ') | (iscntrl(t[i])))){
			out[pos] = t[i];
			pos++;
		}
	}
	int i = 0;	
	for(i = 0; i < pos; i++){
		t[i] = out[i];
	}
	t[i + 1] = '\0';
	return pos - 1;
}


