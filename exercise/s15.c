#include<stdio.h>


unsigned long ggt(unsigned long a, unsigned long b);

int main(){

}


unsigned long ggt(unsigned long a, unsigned long b){
	if (b > 0){
		return ggt(b, a % b);
	} else {
		return a;
	}
}
