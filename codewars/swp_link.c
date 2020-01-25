#include<stdio.h>  // For sample visualisation code, you may remove that ^^
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node, *LinkedList;

int swap_node(Node *listPointer1, unsigned int index1, Node *listPointer2, unsigned int index2)
{	Node *l1_prev;
	Node *l1_elem;
	Node *l1_next;
	Node *l2_prev;
	Node *l2_elem;
	Node *l2_next;
	
	// Find element in list 1 if not found return 0
	l1_prev = NULL;
	l1_elem = listPointer1;
	l1_next = listPointer1->next;

	for(int i = 0; i < index1; i++){
		l1_prev = l1_elem;
		l1_elem = l1_next;
		if(l1_next != NULL){
			l1_next = l1_next->next;
		}
	}
	if(l1_elem == NULL){
		return 0;
	}
	
	// Find element in list 2 if not found return 0
	l2_prev = NULL;
	l2_elem = listPointer2;
	l2_next = listPointer2->next;

	for(int i = 0; i < index2; i++){
		l2_prev = l2_elem;
		l2_elem = l2_next;
		if(l2_next != NULL){
			l2_next = l2_next->next;
		}
	}
	if(l2_elem == NULL){
		return 0;
	}

	// If both found swap elements and return 1
	if(l1_prev == NULL){
		// THIS DOES NOT WORK!
		l1_elem->next = l2_next;
	} else {
		l1_prev->next = l2_elem;
		l1_elem->next = l2_next;
	}

	if(l2_prev == NULL){
		// THIS DOES NOT WORK!!!
		l2_elem->next = l1_next;

	} else {
		l1_prev->next = l2_elem;
		l1_elem->next = l2_next;
	}

	
    
    return (1);

}

Node *push(Node *begin, double value){
	Node *new = malloc(sizeof(Node));
	new->value = value;
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

void traverse(Node *begin){
	Node *current = begin;
	if (begin == NULL){
		printf("No Elements are on the stack!\n");
	} else {
		printf("The list is:");
		while(current != NULL){
			printf(" %d,", current->value);
			current = current->next;		
		}
		printf("\n");
	}
}

int main(){
	Node *list1 = NULL;
	for(int i = 4; i > 0; i--){
		list1 = push(list1, i);
	}
	traverse(list1);

	Node *list2 = NULL;
	for(int i = 8; i > 4; i--){
		list2 = push(list2, i);
	}
	traverse(list2);

	swap_node(list1, 2, list2, 0);
	traverse(list1);
	traverse(list2);
	
	return 0;

}
