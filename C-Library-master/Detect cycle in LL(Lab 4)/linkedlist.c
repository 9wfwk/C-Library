#include "linkedlist.h"

linkedlist newll(){
	linkedlist head;
	head.count = 0;
	head.first = NULL;

	return head;
}

void insertFirst(linkedlist *head, int el){
	node *temp = (node*)myalloc(sizeof(node));
	
	temp->element = el;
	if(head->first == NULL){
		head->first = temp;
		temp->next = NULL;
		 ++(head->count);
	}

	else{
		temp->next = head->first;
		head->first = temp;
		++(head->count);
	}
}


void printList(linkedlist *head){
	int i=1;
	node *temp=head->first;
	
	printf("[ ");
	while((i<=2*(head->count)) && temp != NULL){
		printf(" %d ",temp->element);
		
		fflush(stdout); //Sleep must be used after flushing out the buffer of printf, as the output of printf is bufferred
		usleep(1000*10);
		
		temp=temp->next;
		++i; //Comment this for printing list 2 times

		if(i==(head->count)+1)	printf("\t||\t");
	}

	printf(" ]\n");
}

node* deleteFirst(linkedlist *head){
	node* temp=head->first;
	if(temp==NULL) goto term;

	head->first = head->first->next;
	--(head->count);
	
	term:
		return temp;
}


int search(linkedlist *head, int ele){
	node *temp = head->first;
	while(temp != NULL){
		if(temp->element == ele){
			return 1;
		}
		temp=temp->next;
	}

	return 0;
}

node *delete(linkedlist *head, int ele){
	node *temp=head->first;
	node *temp1= temp;
	node *res=NULL;
	
	if(temp!=NULL && temp->element==ele){
		head->first = temp->next;
		--(head->count);
		res = temp;
	}

	else{

		while(temp != NULL){
			if(temp->element==ele){
				temp1->next = temp->next;
				res = temp;	
				--(head->count);
				goto sos1;
			}

			temp1=temp;
			temp=temp->next;
		}
	}

	sos1:
		return res;
}
