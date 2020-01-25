#include <stdio.h>




void add(int arrar[]);

int main(){

int a = 13;
int b = 19;
int res = 0;

int array[3];
array[0] = a;
array[1] = b;
array[2] = res;

add(array);

printf("%d\n", array[2]);
}

void add(int array[]){

array[2] = array[0] + array[1];

}



