#include "5.h"

linkedlist* makeCircularList(linkedlist *Ls){
	linkedlist *Ls1 = (linkedlist*)malloc(sizeof(linkedlist));
	Ls1->first = Ls->first;
	Ls1->count = Ls->count;

	if(Ls1->first==NULL) return Ls1;

	int flag = testCyclic1(Ls);
	if(flag==0){
		node *temp=Ls1->first;
		while(temp->next != NULL){
			temp=temp->next;
		}

		temp->next=Ls1->first;

		return Ls1;
	}
	else if(flag==1){
		int curr=0;
		int ct=0;
		node *temp=Ls1->first;

		while(curr<Ls1->count){
		       temp=temp->next;
		       ++curr;
		}

		node *temp1=Ls1->first;
		node *temp2=temp1;

		if(temp1==temp)	goto term;

		while(temp1->next!=temp){
			temp1=temp1->next;
			//free(temp2);
			temp2=temp1;
			++ct;
		}

		++ct;
		//free(temp1);
		Ls1->first = temp;
		Ls1->count = Ls->count - ct;

term:		return Ls1;
	}
}
