#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct mini_win_t
{
    char    *letters;
    unsigned code;
} MiniWin;

typedef struct ticket_t
{
    MiniWin *mini_wins;
    unsigned count;
} Ticket;

const char *bingo(const Ticket *ticket, unsigned win)
{
    int n_tickets = ticket->count;
    MiniWin *current;
    int mini = 0;
    int len = ticket->count;
    for(int i = 0; i < n_tickets; j++){
	// Go through all mini tickets;
	current = ticket->mini_wins;

		for(int j = 0; j < len; i++){
			if(current->letters[j] == current->code){
				++mini;
				break;			
			}
		}
	
	
    }

	if (mini >= win)
	    return "Winner!";
	else
	    return "Loser!";
}
