#include "linkedlist.h"

/* Hare and Tortoise Algorithm -
 * hare jumps 2 nodes
 * tort jumps 1 node
*/

/* Return 1 if the list is cyclic
 * Return 0 if the list is linear
*/

int testCyclic1(linkedlist *Ls){
	node* hare=Ls->first;
	node* tort=Ls->first;
	int flag=0; //flag==0; hare and tort are starting
		    //flag==1; hare and tort have started

	if(hare==NULL){ //If list is empty
		return 0;
	}

	else if(hare==hare->next){//list has single element pointing to itself
		return 1;
	}

	else{
		while(hare != NULL && hare->next != NULL){
			if(hare==tort && flag!=0){
				return 1;
			}

			hare =hare->next->next;
			tort =tort->next;
			flag=1;
		}
	}

	return 0;
}
