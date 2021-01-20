#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList newll(){
	LinkedList head;
	head.count = 0;
	head.first = NULL;

	return head;
}

void insertFirst(LinkedList *head, int el){
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));

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


void printList(LinkedList *head){
	int i=1;
	ListNode *temp=head->first;
	
	printf("[ ");
	while(i<= head->count){
		printf(" %d ",temp->element);
		temp=temp->next;
		++i;
	}

	printf(" ]\n");
}

ListNode* deleteFirst(LinkedList *head){
	ListNode* temp=head->first;
	if(temp==NULL) goto term;

	head->first = head->first->next;
	--(head->count);
	
	term:
		return temp;
}


int search(LinkedList *head, int ele){
	ListNode *temp = head->first;
	while(temp != NULL){
		if(temp->element == ele){
			return 1;
		}
		temp=temp->next;
	}

	return 0;
}

ListNode *deleteNode(LinkedList *head, int ele){
	ListNode *temp=head->first;
	ListNode *temp1= temp;
	ListNode *res=NULL;
	
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
