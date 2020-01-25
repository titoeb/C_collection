#include<stdio.h>
#include<stdlib.h>

struct node{
	double data;
	struct node *next;
};

struct node *push(struct node *begin, double data);
struct node *pop(struct node *begin);
void peek(struct node *begin);
void traverse(struct node *begin);
struct node *free_list(struct node *begin);

int main(){
	struct node *list = NULL;
	traverse(list);
	for(double i = 0.9; i >  0.000001; i = i*i){
		list = push(list, i);
	}
	traverse(list);
	list = pop(list);
	traverse(list);
	peek(list);
	list = free_list(list);
	traverse(list);
}

struct node *push(struct node *begin, double data){
	struct node *new = malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	
	if (begin == NULL){
		// This the first element.
		begin = new;			
	} else {
		// Append an element.
		new->next = begin;
		begin = new;
	}
	return begin;
}

void traverse(struct node *begin){
	struct node *current = begin;
	if (begin == NULL){
		printf("No Elements are on the stack!\n");
	} else {
		printf("The list is:");
		while(current != NULL){
			printf(" %lf,", current->data);
			current = current->next;		
		}
		printf("\n");
	}
}

struct node *pop(struct node *begin){
	if(begin == NULL){
		printf("The stack is empty cannot pop the first element!\n");
		return NULL;
	} else {
		printf("The first element was %lf\n", begin->data);
		if(begin->next == NULL){
			return NULL;
			free(begin);
		} else {
			struct node* current = begin->next;
			free(begin);
			return current;
		}
	}

}

void peek(struct node *begin){
	if(begin == NULL){
		printf("Cannot peek into stack since it is empty!\n");
	} else{
		printf("First value on the stack is %lf\n", begin->data);
	}
}

struct node *free_list(struct node *begin){
	struct node *current = begin;
	struct node *tmp = NULL;
	if (begin == NULL){
		return NULL;
	} else {
		while(current != NULL){
			tmp = current;
			current = current->next;		
			free(tmp);
		}
	}
	return NULL;
}
