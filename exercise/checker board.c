 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char full_line[] = "+-----+-----+";
char partial_line[] = "|     |     |";
int iter;

int main ()
{   for(iter = 0; iter < 9; ++iter){
    switch (iter){
        case 0:
            printf("%s\n", full_line);
            break;
        case 1:
            printf("%s\n", partial_line);
            break;
        case 2:
            printf("%s\n", partial_line);
            break;
        case 3:
            printf("%s\n", partial_line);
            break;
        case 4:
            printf("%s\n", full_line);
            break;
        case 5:
            printf("%s\n", partial_line);
            break;
        case 6:
            printf("%s\n", partial_line);
            break;
        case 7:
            printf("%s\n", partial_line);
            break;
        case 8:
            printf("%s\n", full_line);
            break;
    }
    
}
	return(0);
}