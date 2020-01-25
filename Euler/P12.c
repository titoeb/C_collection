#include<stdio.h>
#include<stdlib.h>
#include<math.h>



struct list{
	int *data;
	int len;
	int pos;
};


void list_append(struct list *this, int value){
	if(this->pos >= this->len - 1){
		this->data = realloc(this->data, sizeof(int) * this->len * 2);
		this->len *= 2;
	}
	this->data[this->pos + 1] = value;
	this->pos++;
	return;
}

void list_free(struct list *this){
	free(this->data);
	free(this);
	return;
}

struct list *list_init(int len){
	struct list *out = malloc(sizeof(struct list*) );
	out->data = malloc(sizeof(int) * len);
	out->len = len;
	out->pos = 0;
	return out; 
}

struct list *triangle(int until){
	struct list *out = list_init(10);
	int cur_num = 0;
	for(int i = 1; i < until; i++){
		cur_num += i;
		list_append(out, cur_num);
	}
}

struct list *find_divisors(int num){
	struct list *out = list_init(10);
	for(int pot_div = 1; pot_div <= num; pot_div++){
		if(num % pot_div == 0){
			list_append(out, pot_div);		
		}
	}
	return out;
}

int num_divisors(int num){
	int out = 0;
	for(int pot_div = 1; pot_div <= num; pot_div++){
		if(num % pot_div == 0){
			out++;		
		}
	}
	return out;
}

int first_triangle(int num_div){
	int cur_num = 0;
	int i = 1;
	while(1){
		cur_num += i;
		if(num_divisors(cur_num) >= num_div){
			return cur_num;
		}
		i++;
	}
}

int main(){
	printf("The first triangle number with 5 divisors is %d\n", first_triangle(5));
	printf("The first triangle number with 50 divisors is %d\n", first_triangle(50));
	printf("The first triangle number with 100 divisors is %d\n", first_triangle(100));
	printf("The first triangle number with 500 divisors is %d\n", first_triangle(500));
	return 0;
}
