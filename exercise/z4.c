#include <stdio.h>
#include <string.h>


int strend (const char *s, const char *t);
char *strrchr (const char *s, int c);
char *strstr (const char *s, const char *t);

int main(){

	const char *s = "ABFCDF";
	const char *t = "FC";
	printf("%p\n", strstr(s, t));
	printf("%p\n", &s[2]);

	
}

int strend (const char *s, const char *t){
	int s_len = strlen(s);
	int t_len = strlen(t);
	int start_point = s_len - t_len - 1;
	for (int iter = start_point; iter < s_len; ++iter){
		if (*(s + iter + 1) != *(t + iter - start_point)){
			return 0;		
		}	
	}
	return 1;
}


char *strrchr (const char *s, int c){
	char *result = NULL;	
	int s_len = strlen(s);
	
	for(int iter = 0; iter < s_len; ++iter){
		if (*(s + iter) == c){
			result = s+iter;		
		}		
	}

	
	return result;
}

char *strstr (const char *s, const char *t){
	int s_len = strlen(s);
	int t_len = strlen(t);
	int inner_iter;
	char *result = NULL;
	for (int iter = 0; iter < s_len; ++iter){
		if (*(s + iter) == *t){
			result = (s + iter);
			for(inner_iter = 0; inner_iter < t_len; ++inner_iter){
				printf("We are at position %d of s, %d of t and found a match between %c from s and %c from t\n",inner_iter, iter, *(s + iter + inner_iter), *(t + inner_iter) );
				if (*(s + iter + inner_iter) != *(t + inner_iter)){
					result = NULL;	
				}
			}
			if (inner_iter == (t_len - 1)){
				return result;			
			}		
		}
	}

	return result;

}
