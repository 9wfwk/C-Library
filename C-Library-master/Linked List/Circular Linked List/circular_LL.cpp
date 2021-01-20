#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
};

void functionality();
struct ListNode *appendCir(struct ListNode **front, struct ListNode **rear, int num);
struct ListNode *showAll(struct ListNode *front, struct ListNode *rear);
int delCir(struct ListNode **front, struct ListNode **rear);

int main(){
	functionality();
}

void functionality(){
	struct ListNode *front, *rear;
	front=NULL;
	rear=NULL;
	int ch;

	int op;
	printf("(1) Circular Linked List:\n");
	cin >> op;
	
	switch(op){
		case 1:
		{
			printf("Enter more elements (yes-1/no-0):\n");
			cin >> ch;
			while(ch!=0){
				int num;
				printf("Enter element:\n");
				cin >> num;
				appendCir(&front,&rear,num);
				printf("Enter more elements (yes-1/no-0):\n");
				cin >> ch;
			}
			
			break;
		}
		
		default:
		{
			break;
		}
	}
	
	int ch1;
	printf("Perform operation (yes-1/no-1):\n");
	cin >> ch1;
	while(ch1!=0){
		int op2;
		printf("(1) Show circular linked list:\n(2) Delete element at front from cicular LL:\n");
		cin >> op2;
		switch(op2)
		{
			case 1:
			{
				printf("\n");
				showAll(front,rear);
				break;
			}
			case 2:
			{
				int item;
				item=delCir(&front, &rear);
				printf("List after deletion of %d:\n",item);
				showAll(front,rear);
				break;
			}
			default:
			{
				break;
			}
		}
		
		printf("Perform operation (yes-1/no-1):\n");
		cin >> ch1;
	}
}

struct ListNode *appendCir(struct ListNode **front, struct ListNode **rear, int num){
	struct ListNode  *r;
	
	r=(struct ListNode *)malloc(sizeof(struct ListNode));
	r->val=num;

	if(*front==NULL){
		*front=r;
	}
	else{
		(*rear)->next=r;
	}
	*rear=r;
	(*rear)->next=*front;
	
	return *front;
}

struct ListNode *showAll(struct ListNode *front, struct ListNode *rear){
	struct ListNode *temp;
	temp=front;
	
	if(front==NULL){
		printf("[ ]\n");
		return NULL;
	}
	else if(front==rear){
		printf("[ %d ]\n",temp->val);
		return front;
	}
	else{
		int flag=1;
		
		printf("[ ");
		while(flag){
			printf(" %d,",temp->val);
			temp=temp->next;
			if(temp==rear){
				flag=0;
			}
		}
		
		printf(" %d ]\n",temp->val);
	}
	return front;
}


// Function to delete the front node from any linked list -->


int delCir(struct ListNode **front, struct ListNode **rear){
	int item;
	
	if((*front)==NULL){
		return NULL;
	}
	else if(*front==*rear){
		item=(*front)->val;
		free(*front);
		*front=NULL;
		*rear=NULL;
	}
	else{
		struct ListNode *temp;
		temp=*front;
		item=temp->val;
		(*front)=(*front)->next;
		(*rear)->next=*front;
		free(temp);
	}
	return item;
}
