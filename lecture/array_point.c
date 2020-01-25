
#include<stdio.h>

int main(){
        int laenge = 9;
        int breite = 6;
        int hoehe = 12;
        int a[laenge][breite][hoehe];
	int ptr = &a[0][0][0];
	int iter = 0;
	while(i < (laenge * breite * hoehe)){
		*ptr = iter;
		++ptr;
		++iter;		
	}
}



