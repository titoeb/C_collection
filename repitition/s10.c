#include<stdio.h>
#include<string.h>


int main(){
	char line1[50];
	char line2[50];
	int pos = 0;
	char cur_char;
	// Read-in first line 
	cur_char = getchar();
	while((cur_char != '\n') & (pos <= 49)){
		if(pos > 49){
			printf("Fehler bei der Eingabe.\n");
			return 0;
		}
		line1[pos] = cur_char;
		pos++;
		cur_char = getchar();
	}
	line1[pos] = '\0';

	// Read-in second line
	pos = 0;
	cur_char = getchar();
	while((cur_char != '\n')){
		if(pos > 49){
			printf("Fehler bei der Eingabe.\n");
			return 0;
		}
		line2[pos] = cur_char;
		pos++;
		cur_char = getchar();
	}
	line2[pos] = '\0';

	printf("%s%s\n", line1, line2);
	return 0;
}


