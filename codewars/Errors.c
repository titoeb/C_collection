#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char *hist(const char *s) {
    // First get the nummer of error out of the input string
    int err[4] = {0, 0, 0, 0};
    for(int i = 0; i < strlen(s); i++){
      switch(*(s + i)){
		case 'u':
		  ++err[0];
		  break;
		case 'w':
		  ++err[1];
		  break;
		case 'x':
		  ++err[2];
		  break;
		case 'z':
		  ++err[3];
		  break;
	}
    }
	
    // make the counts to strings
    char count_u[10];   
    char count_w[10]; 
    char count_x[10];
    char count_z[10];
    sprintf(count_u, "%d", err[0]);
    sprintf(count_w, "%d", err[1]);
    sprintf(count_x, "%d", err[2]);
    sprintf(count_z, "%d", err[3]);



    // Write the result to a new string.
    int num_err = err[0] + err[1] + err[2] + err[3];
    //char *res = malloc(sizeof(char) * (37 + strlen(count_u) + strlen(count_w) + strlen(count_x) + strlen(count_z) + num_err));
    char *res = malloc(sizeof(char)*500);
    //printf("u: %d, w: %d, x: %d, z: %d\n", err[0], err[1], err[2], err[3]);
    int pos = 0;


    // Print u
    if(err[0] > 0){
    *(res + pos) = 'u';
    ++pos;
    *(res + pos) = ' ';
    ++pos;
    *(res + pos) = ' ';
    ++pos;
    for(int i = 0; i < strlen(count_u); i ++){
     *(res + pos) = count_u[i];
     ++pos;
    }
     for(int i = 0; i <= (5 - strlen(count_u)); i ++){
    	*(res + pos) = ' ';
	    ++pos;
    }	
    for(int i = 0; i < err[0]; i++){
	  *(res + pos) = '*';
          ++pos;
    }	
    *(res + pos) = '\r';
    ++pos;
    }

    // Print w
    if(err[1] > 0){
    *(res + pos) = 'w';
    ++pos;
    *(res + pos) = ' ';
    ++pos;
    *(res + pos) = ' ';
    ++pos;
    for(int i = 0; i < strlen(count_w); i ++){
     *(res + pos) = count_w[i];
     ++pos;
    }
     for(int i = 0; i <= (5 - strlen(count_w)); i ++){
    	*(res + pos) = ' ';
	    ++pos;
    }	
    for(int i = 0; i < err[1]; i++){
	  *(res + pos) = '*';
          ++pos;
    }	
    *(res + pos) = '\r';
    ++pos;
    }

   // Print x
   if(err[2] > 0){
    *(res + pos) = 'x';
    ++pos;
    *(res + pos) = ' ';
    ++pos;
    *(res + pos) = ' ';
    ++pos;
     for(int i = 0; i < strlen(count_x); i ++){
     *(res + pos) = count_x[i];
     ++pos;
    }
     for(int i = 0; i <= (5 - strlen(count_x)); i ++){
    	*(res + pos) = ' ';
	    ++pos;
    }	
    for(int i = 0; i < err[2]; i++){
	  *(res + pos) = '*';
          ++pos;
    }	
    *(res + pos) = '\r';
    ++pos;
    }

   // Print z
   if(err[3] > 0){
    *(res + pos) = 'z';
    ++pos;
    *(res + pos) = ' ';
    ++pos;
    *(res + pos) = ' ';
    ++pos;
    for(int i = 0; i < strlen(count_z); i ++){
     *(res + pos) = count_z[i];
     ++pos;
    }
     for(int i = 0; i <= (5 - strlen(count_z)); i ++){
    	*(res + pos) = ' ';
	    ++pos;
    }
    for(int i = 0; i < err[3]; i++){
	  *(res + pos) = '*';
          ++pos;
    }	
    //printf("Pos is %d and calculated array size was %d \n", pos,41 + num_err );
    }


    *(res + pos) = '\0';
    return res;
}

int main(){
 printf("%s\n",hist("aaifzlnderpeurcuqjqeywdq"));
 printf("%s\n","first_line\rsecond_line\rthird_line\n");

}
