#include<stdio.h>
#include<stdlib.h>


struct bruch{
	int zaehler;
	int nenner;
};

int ggt(int a, int b){
	if (b == 0)
		return a;
	else
		return ggt(b, a % b);
}

typedef struct bruch bruch_t;

void bruchKuerzen(bruch_t* bruch){
	int Teiler = ggt(bruch->zaehler, bruch->nenner);
	if(Teiler != 1){
		bruch->zaehler = bruch->zaehler / Teiler;
		bruch->nenner = bruch->nenner / Teiler;
	}
	return;		
}

void bruchEingabe(bruch_t* bruch){
	int zaehler, nenner;
	printf("Bitte geben Sie den Zaehler ein!\n");
	scanf("%d", &zaehler);
	printf("Bitte geben Sie den Nenner ein!\n");
	scanf("%d", &nenner);

	bruch->zaehler = zaehler;
	bruch->nenner = nenner;
	return;
}

void bruchAddition(bruch_t* bruch, bruch_t add){
	int n1, n2, z1 ,z2, n3, z3;
	n1 = bruch->nenner;
	n2 = add.nenner;
	z1 = bruch->zaehler;
	z2 = add.zaehler;

	n3 = n1 * n2;
	z3 = n2 * z1 + n1 * z2;
	
	bruch->nenner = n3;
	bruch->zaehler = z3;
	bruchKuerzen(bruch);
	return;
}

void bruchSubtraktion(bruch_t* bruch, bruch_t sub){
	sub.zaehler = - sub.zaehler;
	bruchAddition(bruch, sub);
	return;

}

void bruchMultiplikation(bruch_t* bruch, bruch_t mult){
	bruch->zaehler = bruch->zaehler * mult.zaehler;
	bruch->nenner = bruch->nenner * mult.nenner;
	bruchKuerzen(bruch);
	return;
}

void bruchDivision(bruch_t* bruch, bruch_t mult){
	bruch->zaehler = bruch->zaehler * mult.nenner;
	bruch->nenner = bruch->nenner * mult.zaehler;
	bruchKuerzen(bruch);
	return;
}

float bruchQuotient(bruch_t bruch){
	return (float) bruch.zaehler / (float) bruch.nenner;
}

void bruchErweitern(bruch_t* bruch, int faktor){
	bruch->nenner = bruch->nenner * faktor;
	bruch->zaehler = bruch->zaehler * faktor;
	return;
}

void bruchAusgabe(bruch_t* bruch){
	printf("%d/%d\n", bruch->zaehler, bruch->nenner);
	return;
}

int main(){
	bruch_t bruch1;
	bruch_t bruch2;
	bruchEingabe(&bruch1);
	bruchAusgabe(&bruch1);

	bruchEingabe(&bruch2);
	bruchAusgabe(&bruch2);
	bruchSubtraktion(&bruch1, bruch2);
	bruchAusgabe(&bruch1);
	return 1;
}
