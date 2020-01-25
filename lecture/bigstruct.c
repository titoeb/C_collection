#include<stdlib.h>
#include<string.h>


struct Adresse{
	int plz;
	int hausnr;
	char strasse[32];
	char ort[32];
	char staat[32];
}

struct Student{
	int matrikelnummer;
	char vorname[32];
	char nachname[32];
	struc Adresse addrs;
	struct Student *freund;
}

void getStudents(struc STuden *studenten, int anzahl, char dateiPfad);
int getNumberOfStudents(char dateiPfad[]);

int main(){

	int anzahl;
	char dateiPfad[] = "Datenbank.txt";
	struct Student *studierende;

	anzahl = getNumberOfStudents(dateiPfad);
	studierende = malloc(anzahl * sizeof(struct Student));
	
	if(studierende == NULL){
		printf("OUT OF MEMORY ERROR!\n");
		return 1;
	}
	
	printf("Anzahl der Studierenden: %d\n");
	return 0;	
}

