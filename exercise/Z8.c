#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct bruch_t{
	int zaehler;
	int nenner;	
};

typedef struct bruch_t bruch_t;

void bruchEingabe(bruch_t *bruch);
void bruchAusgabe(bruch_t* bruch);
void bruchAddition(bruch_t* bruch, bruch_t add);
void bruchSubtraktion(bruch_t* bruch, bruch_t sub);
void bruchMultiplikation(bruch_t* bruch, bruch_t mult);
void bruchDivision(bruch_t* bruch, bruch_t div);
float bruchQuotient(bruch_t bruch);
void bruchErweitern(bruch_t* bruch, int faktor);
void bruchKuerzen(bruch_t* bruch);
int *prim_fac(int number);
int prod_a_min_b(int *a, int* b);
int len(int *nums);

void bruchEingabe(bruch_t *bruch){
	printf("Bitte geben sie den Zaehler ein!\n");
	scanf("%d", &bruch->zaehler);

	printf("Bitte geben sie den Nenner ein!\n");
	scanf("%d", &bruch->nenner);
}

void bruchAusgabe(bruch_t* bruch){
	printf("%d/%d\n", bruch->zaehler, bruch->nenner);
}

void bruchSubtraktion(bruch_t* bruch, bruch_t sub){
	bruch_t result;
	bruchKuerzen(bruch);
	bruchKuerzen(&sub);

	result.nenner = bruch->nenner * sub.nenner;
	result.zaehler = bruch->zaehler * sub.nenner - sub.zaehler * bruch->nenner; 

	bruch->nenner = result.nenner;
	bruch->zaehler = result.zaehler;
	printf("Startin to kuerz bruch\n");
	bruchKuerzen(bruch);
}

void bruchAddition(bruch_t* bruch, bruch_t add){
	bruch_t result;
	bruchKuerzen(bruch);
	bruchKuerzen(&add);


	result.nenner = bruch->nenner * add.nenner;
	result.zaehler = bruch->zaehler * add.nenner + add.zaehler * bruch->nenner;

	bruch->nenner = result.nenner;
	bruch->zaehler = result.zaehler;
	bruchKuerzen(bruch);

}

void bruchMultiplikation(bruch_t* bruch, bruch_t mult){
	bruch_t result;
	bruchKuerzen(bruch);
	bruchKuerzen(&mult);


	result.nenner = bruch->nenner * mult.nenner;
	result.zaehler = bruch->zaehler * mult.zaehler;

	bruch->nenner = result.nenner;
	bruch->zaehler = result.zaehler;
	bruchKuerzen(bruch);
}
void bruchDivision(bruch_t* bruch, bruch_t div){
	bruch_t result;
	bruchKuerzen(bruch);
	bruchKuerzen(&div);


	result.nenner = bruch->nenner * div.zaehler;
	result.zaehler = bruch->zaehler * div.nenner;

	bruch->nenner = result.nenner;
	bruch->zaehler = result.zaehler;
	bruchKuerzen(bruch);
}
float bruchQuotient(bruch_t bruch){
	return ((float) bruch.zaehler) / ((float) bruch.nenner);
}

void bruchErweitern(bruch_t* bruch, int faktor){
	bruch->nenner = faktor * bruch->nenner;
	bruch->zaehler = faktor * bruch->zaehler;
}
void bruchKuerzen(bruch_t* bruch){

	int zaehler = bruch->zaehler;
	int *primes_zaehler = prim_fac(zaehler);


	int nenner = bruch->nenner;
	int *primes_nenner = prim_fac(nenner);


	bruch->zaehler = prod_a_min_b(primes_zaehler, primes_nenner);

	bruch->nenner =	prod_a_min_b(primes_nenner, primes_zaehler);	
	free(primes_zaehler);
	free(primes_nenner);

}

int len(int *nums){
	int iter = 0;
	while(*nums != -2){
		++iter;
		++nums;
	}
	return iter;
}

int *prim_fac(int number){
	int *allnum;	
	int * allnum_start;
	int start;
	if (number < 0){
		start = -1;
		number = - number;
	} else {
		start = 1;
	}
	
        allnum = (int *) malloc(sizeof(int) * number);
	allnum_start = allnum;
	
	*allnum = start; 
	++allnum;
	
	while(number % 2 == 0){
		*allnum = 2;
		number /= 2;
		++allnum;
	}
	for(int i = 3; i <= sqrt(number); i += 2){
		while(number % i == 0){
			*allnum = i;
			++allnum;
			number /= i;	
		}
	}
		
	if (number > 2)	{
		*allnum = number;	
		++allnum;	
	} 
		
	*allnum = -2;
	
	return allnum_start;
}

int prod_a_min_b(int *a, int* b){
	int len_a = len(a);
	int len_b = len(b);
	int prod = 1;
	int rel = 0;
	int *b_considered = (int*) malloc(sizeof(int) * (len_b - 1));
	for (int i = 1; i < len_b; ++i){
		*(b_considered + i) = 0;
	}
	for(int i = 1; i < len_a; ++i){
		rel = 0;
		for(int j = 1; j < len_b; ++j){
			if(*(b_considered + j - 1) == 0){
				if (*(a + i) == *(b + j)){
					rel = 1;
					*(b_considered + j - 1) = 1;
					break;			
				}	
			}
		}
		if (rel == 0){
			prod *= *(a + i);
		}
	}
	free(b_considered);
	return prod * *a;
}

/////////////////////////////////////////////

/*
int main(){
	bruch_t bruch;
	bruchEingabe(&bruch);
	
	bruch_t sub;
	bruchEingabe(&sub);

	printf("Der Bruch war\n");
	bruchAusgabe(&bruch);

	printf("Abgezogen habe ich \n");
	bruchAusgabe(&sub);

	printf("Und das ergebnis ist \n");
	bruchSubtraktion(&bruch, sub);
	printf("Ausgabe");
	bruchAusgabe(&sub);	
	
	
	printf("Gekuerzt ist das\n");
	bruchKuerzen(&bruch);
	bruchAusgabe(&bruch);
	
}
*/

/*
int main(){
	
	int zaehler = 100;
	int *primes_zaehler = prim_fac(zaehler);
	printf("The prime factorization of %d is:\n", zaehler);
	int iter = 0;	
	while(*(primes_zaehler + iter) != -2){
		printf("%d ", *(primes_zaehler + iter));
		++iter;
	}
	printf("\n\n");
	
	int nenner = 2500;
	int *primes_nenner = prim_fac(nenner);
	iter = 0;	
	while(*(primes_nenner + iter) != -2){
		printf("%d ", *(primes_nenner + iter));
		++iter;
	}
	printf("\n\n");
	
	printf("The new zaehler is %d and the new nenner is %d/n",prod_a_min_b(primes_zaehler, primes_nenner), prod_a_min_b(primes_nenner, primes_zaehler) );	
} */


int main(){
	bruch_t bruch;
	bruch.zaehler = 5;
	bruch.nenner = 50;	
	
	
	bruch_t sub;
	sub.zaehler = 2;
	sub.nenner = 50;
	
	bruchAusgabe(&bruch);
	bruchSubtraktion(&bruch ,sub);
	bruchAusgabe(&bruch);
	
} 


