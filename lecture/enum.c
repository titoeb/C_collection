#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


enum wochentag{Montag, Dienstag, Mittwoch, Donnerstag, Freitag, Samstag, Sonntag}

int main(){
	enum wochentag heute = Dienstag;
	printf("Heute ist der %d Wochentag \n", heute);
	return 0;
}

