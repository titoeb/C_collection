#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// Here, the structures are only created.
struct Adresse{
	int plz;
	int hausnr;
	char strasse[32];
	char ort[32];
	char staat[32];
};

struct Student{
	int Matrikelnummer;
	char Vorname[32];
	char Nachname[32];
	struct Adresse addrs;
};

struct Studen adAnlegen(struct Student studi);
int main(){

// create the first real object of the declared structures!	

	struct Student lars = {1, "Lars", "Krismes"};
	struct Student gayview = {2, "Gayview", "Mahat"};
	lars.freund = &gayview;

	printf("Der Student %s %s hat die Matrikelnummer %d\n", lars.vorname, lars.nachname, lars.Matrikelnummber); 
		
	lars = adAnlegen(lars);
	printf("Der Student %s %s hat die Matrikelnummer %d\n", lars.vorname, lars.nachname, lars.Matrikelnummber); 
	
	return 0;
}

struct Studen adAnlegen(struct Student studi){

	printf("Bitte geben sie die Strasse ein! \n");
	scanf("%s", studi.addrs.strasse);
	printf("Bitte geben sie den staat ein! \n");
	scanf("%s", studi.addrs.staat);
	printf("Bitte geben sie die Hausnummber ein! \n");
	scanf("%s", studi.Adresse.);
	printf("Bitte geben sie die Adresse ein! \n");
	scanf("%s", studi.addrs.strasse)
	printf("Bitte geben sie die Adresse ein! \n");
}
