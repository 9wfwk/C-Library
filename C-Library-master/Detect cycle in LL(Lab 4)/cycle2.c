#include "linkedlist.h"


int testCyclic2(linkedlist *Ls){
	linkedlist Ls1 = newll();
	
	node *temp=Ls->first;
	node *temp2=Ls->first;
	
	for(int i=0; i<Ls->count; ++i){ //dep copy Ls into Ls1
		temp2=temp;
		insertFirst(&Ls1,temp->element);
		temp=temp->next;
	}
	node *temp1=Ls1.first;
	
	while(temp1->next!=NULL){ //goto last node of Ls1
		temp1=temp1->next; 
	}
	
	temp1->next=temp2->next; //Set Ls1.'lastnode'->next == Ls.'lastnode'->next i.e. induce cycle in Ls1
	
	
	if(Ls1.count==0){
		return 0;
	}

	node *prev=NULL;
	node *next=NULL;
	node *current=Ls1.first;

	while(current!=NULL){
		next=current->next;
		current->next=prev;
		
		prev=current;
		current = next;

		if(current==Ls1.first){
			//Ls->first = prev; //modification
			return 1;
		}
	}

	//Ls->first = prev; //Mod - 2; print the reverse list if linear
	return 0;
}
