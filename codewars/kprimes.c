#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// In the preloaded section are some functions that can help.
// They can be used as a small library.
// There is no file to include, only the templates below.
/*
struct node {
    int data;
    struct node *next;
};
struct list {
    size_t sz;
    struct node *head;
};

struct list* createList();

// push data at the head of the list
void insertFirst(struct list* l, int data);

struct list* reverse(struct list* l);

void listFree(struct list* l);
*/
// functions to write
/*
struct list* kPrimes(int k, int start, int nd)
{

}
int puzzle(int s)
{

}
 */

int num_prime_factors(int num){
	/*int *out = malloc(sizeof(int) * len);

	for(int i = 0; i < len; i++){
		out[i] = -1;
	} */
	int found = 0;
	while (num % 2 == 0){
		/*if(found >= len - 1){
			len_old = len;
			len *= 2;
			out = realloc(out, sizeof(int) * len);
			for(int i = len_old - 1; i < len; i++){
				out[i] = -1;
			}
		} */
		//out[found] = 2;
		found++;
		num /= 2;
	}
	int cur_check = 3;
	while(num > 1){
		/*if(found >= len - 1){
			len_old = len;
			len *= 2;
			out = realloc(out, sizeof(int) * len);
			for(int i = len_old - 1; i < len; i++){
				out[i] = -1;
			}
		}*/
		if (num % cur_check == 0){
			//out[found] = cur_check;
			found++;
			num /= cur_check;
		} else{
			cur_check += 2;
		}
	}
	return found;
}

int *findKprimes(int k, int start, int end){
	int number = 0;
	for(int i = start; i <= end; i++){
		if(num_prime_factors(i) == k){
			number++;
			printf("Found k-prime %d\n", i);
		}
	}

	int *out = malloc(sizeof(int) * number);
	number = 0;
	for(int i = start; i <= end; i++){
		if(num_prime_factors(i) == k){
			out[number] = i;
			number++;
		}
	}

	return out;
}


int main(int argc, char *argv[]){
	int num = atoi(argv[1]);
	int *out = findKprimes(5, 500, 600);
	for(int i = 0; i < 7; i++){
		printf("%d ", out[i]);	
	}
	printf("\n");



}
