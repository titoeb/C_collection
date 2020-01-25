#include<stdio.h>
#include<stdlib.h>


struct Node{
	int value;
	struct Node *next;
};


struct Node *insert_node(struct Node *insert, int val){
	// Create the new element
	struct Node *new = malloc(sizeof(struct Node));
	new->value = val;
	new->next = NULL;	

	if(insert == NULL){
		// List was empty so far
		return new;	
	} else{
		if (insert->value > val){
			new->next = insert;
			return new;

		} else {
			//list does have at least one entry and we have to find the right position
			struct Node *current = insert;
			while(current->next != NULL && current->next->value < val){
				current = current->next;
			}
			if((current->next == NULL) || (current->next->value != val)){
				new->next = current->next;
				current->next = new;
			}
			return insert;
			}

	}
}

void prnt_list(struct Node *list){
	if(list == NULL){
		printf("The list is empty!\n");
		return;
	}
	while(list != NULL){
		printf("%d ", list->value);
		list = list->next;
	}
	printf("\n");
	return;
}

void free_list(struct Node *list){
	if(list == NULL){
		return;
	}
	struct Node *tmp = NULL;
	while(list != NULL){
		tmp = list;
		list = list->next;
		free(tmp);
	}
	printf("\n");
	return;
}
int give_val_pos(struct Node *list, int pos){
	if(list == NULL){
		printf("The list is empty!\n");
		return -1;
	}
	int cur_pos = 0;
	while(list != NULL && cur_pos < pos){
		if(list->next != NULL)
			list = list->next;
		else {
			cur_pos = pos + 2;
			break;
		}
		++cur_pos;
	}
	if(pos == cur_pos)
		return list->value;
	else{
		printf("Does not exist!\n");
		return -1;
	}
}

struct Node *u(int len){
	if (len <= 0){
		return NULL;
	}
	struct Node *begin = malloc(sizeof(struct Node));
	begin = insert_node(begin, 1);
	int value;
	for(int i = 1; i < len; i++){
		// Find current value
		value = give_val_pos(begin, i);
		begin = insert_node(begin, 2 * value + 1);
		begin =  insert_node(begin, 3 * value + 1);
		//printf("At iteration %d value was %d the first inserted value was %d and the second one was %d\n", i, value , 2 * value + 1, 3*value +1 );
	}
	return begin;
}
int dblLinear(int n) {
	struct Node *list = u(n);
	//prnt_list(list);
	int value = give_val_pos(list, n + 1);
	free(list);
	return value;
}

int main(int argc, char *argv[]){
	printf("dbl_linear(10) = %d\n", dblLinear(atoi(argv[1])));
	/*struct Node *lst = NULL;
	lst = insert_node(lst, 9);
	lst = insert_node(lst, 3);
	prnt_list(lst);
	lst = insert_node(lst, 9);
	prnt_list(lst);*/
	
}
