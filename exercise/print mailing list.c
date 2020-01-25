#include <stdio.h>

struct mailing_list{
    char first_name[100];
    char last_name[100];
    char adress[100];
    char city[100];
};
int iter;

int main(void){
	struct mailing_list friends[] ={
	    {"Tim", "Toebrock","Gutenbergstraße 6", "Goettingen"},
	    {"Eva", "Schmitz","Sternenburgstraße 28", "Bonn"},
	    {"Monica", "Toebrock","Siegburger Weg 58", "Hennef"}
	};
	
	  int size =  sizeof(friends) / sizeof(friends[0]);

    printf("The mailing list does contain: \n");
  
    for(iter = 0; iter < size; ++iter){
        printf("%s %s living at %s in %s \n", friends[iter].first_name,
        friends[iter].last_name,  friends[iter].adress,
        friends[iter].city);
    }
      
	return 0;
}


