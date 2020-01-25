#include <stdio.h>

int main(int arc, char *argv[]){
	
	int Zahl = 12;
	int Zwei = 24;
	
	Zwei = Zahl;	

	printf("Wert von Zahl: %d\n", Zahl);
	printf("Der Wert von Variable Zwei: %d\n", Zwei);
	printf("Die Adresse von Zahl: %p\n", &Zahl);	

	int *Zahl_ptr = &Zahl;
	printf("Der Wert (Speicherstelle) des Zeigers ist: %p\n", Zahl_ptr);
	printf("Der Wert, der an der Speicherstelle gespeichert ist auf die der Zeiger zeigt ist %d\n", *Zahl_ptr);
	printf("Die Adresse, an der der Zeiger gespeichert ist ist %p\n", &Zahl_ptr);
	
	return 0;
}
