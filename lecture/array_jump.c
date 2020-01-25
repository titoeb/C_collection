
#include<stdio.h>

int main(){
        int laenge = 9;
        int breite = 6;
        int hoehe = 12;
        int a[laenge][breite][hoehe];

        printf("%p = %p\n", a + 1, &a[1][0][0]);
	printf("%p = %p\n", a[0] + 1,&a[0][1][0]);
	printf("%p = %p\n", a[0][0] + 1, &a[0][0][1]);
}



