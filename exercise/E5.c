#include <stdio.h>

int main(){
	/* Variable */
	double coefficients[32];
	char line[100]; 	
	double poly = 0;
	double pos;
	char temp;
	int iter = 0;

	/* Read in coefficients */
	  do {
      		scanf("%lf%c", &coefficients[iter], &temp);
      		iter++;
  		} 
	while((temp != EOF) && (iter < 32)); 
	

	/* while ((iter < 32) && (fgets(line, sizeof(line), stdin) != NULL)){	
		sscanf(line, "%lf", &coefficients[iter]);
		++iter;	
	} */

	/* Read in a */
	printf("Bitte Stellen zur Auswertung angeben:\n");
	if(!fgets(line, sizeof(line), stdin)){
			return 0;		
	}	
	sscanf(line, "%lf", &pos);

	/* Calculate value of polynomial */
	int length = iter;	
	poly = coefficients[length - 1];
	for(iter = (length - 2); iter >= 0; --iter){
		poly= coefficients[iter] + pos*poly;
	}

	printf("Wert des Polynoms an der Stelle %g: %g\n", pos, poly);
}
