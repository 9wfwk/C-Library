#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct dnode{
	struct dnode *prev;
	int val;
	struct dnode *next;
};

struct dnode *append(struct dnode **headp, int num);
void showAll(struct dnode *head);
int count(struct dnode *head);
int deleteNode(struct dnode **head, int tar);
struct dnode *addAtBeg(struct dnode *head, int num);
void addAfter(struct dnode *head, int tar, int num);

int main(){
	struct dnode *head=NULL;
	struct dnode *head1=NULL;
	int ch;
	
	sos:
	{
		int op;
		printf("(1)Double linked list:\n");
		cin >> op;
		
		switch(op){
			case 1:
			{	
				int ch1;
				printf("Enter element for List-1 (y/n):\n");
				cin >> ch;
				fflush(stdin);
				cin.clear();
				while(ch!=0)
				{
					int num;
					printf("Enter next element:\n");
					cin >> num;
					
					append(&head,num);
					printf("\nEnter more elements (yes-1/no-1):\n");
					cin >> ch;
				}
				
				printf("Enter element for List-2 (yes-1/no-1):\n");
				cin >> ch;
				while(ch!=0)
				{
					int num;
					printf("Enter next element:\n");
					cin >> num;
					
					append(&head1,num);
					printf("\nEnter more elements (y/n):\n");
					cin >> ch;
				}
				break;
				
			}
			default:
			{
				goto sos;
			}
		}
	}
	
	printf("Perform operation (yes-1/no-0):\n");
	cin >> ch;
	sos1:
	{
		while(ch!=0){
			int op1,op2;
			printf("(1)Show linked list:\n(2)Delete element:\n(3)Add element at beginning of list:\n(4)Add node after a node:\n");
			cin >> op1;
			
			switch(op1){
				case 1:
				{
					printf("List-1 or List-2:\n");
					cin >> op2;
					if(op2==1)
						showAll(head);
					else if(op2==2)
						showAll(head1);
					break;
				}
				case 2:
				{
					int tar;
					printf("List-1 or List-2:\n");
					cin >> op2;
					
					printf("Enter element to be deleted:\n");
					cin >> tar;
					if(op2==1){
						deleteNode(&head,tar);
						printf("List-1 after deletion:\n");
						showAll(head);
					}
					else if(op2==2){
						deleteNode(&head1,tar);
						printf("List-2 after deletion:\n");
						showAll(head1);
					}
					break;
				}
				case 3:
				{
					char ch;
					do{
						int num;
						printf("Enter element to be added :\n");
						cin >> num;
						
						printf("List-1 or List-2:\n");
						cin >> op2;
						
						if(op2==1){
							head=addAtBeg(head,num);
							printf("List-1 after addition:\n");
							showAll(head);
						}
						else if(op2==1){
							head1=addAtBeg(head1,num);
							printf("List-2 after addition:\n");
							showAll(head1);
						}
						printf("Enter more elements at beginning (y/n):\n");
						cin >> ch;
					}while(ch!=0);
					break;
				}
				case 4:
				{
					char ch;
					do{
						int tar,num;
						printf("Enter target node:\n");
						scanf("%d",&tar);
						fflush(stdin);
						printf("Enter new node value:\n");
						scanf("%d",&num);
						fflush(stdin);
						printf("List-1 or List-2:\n");
						scanf("%d",&op2);
						fflush(stdin);
						if(op2==1){
							addAfter(head,tar,num);
							printf("List-1 after addition:\n");
							showAll(head);
						}
						else if(op2==2){
							addAfter(head1,tar,num);
							printf("List-2 after addition:\n");
							showAll(head1);
						}
						printf("Enter more nodes (y/n):\n");
						scanf("%c",&ch);
						fflush(stdin);
					}while(ch!=0);
					break;
				}
				default:
				{
					goto sos1;
				}
			}
			
			printf("\nPerform operation again (y/n):\n");
			cin >> ch;
		}
	}
}


// Function to append a node to double linked list -->


struct dnode *append(struct dnode **headp, int num){
	struct dnode *temp, *r;
	temp=*headp;
	r=(struct dnode *)malloc(sizeof(struct dnode));
	r->val=num;
	
	if(temp==NULL){
		r->prev=NULL;
		r->next=NULL;
		*headp=r;
		return *headp;
	}
	
	else if(temp->next==NULL){
		goto sos3;
	}
	else{
		int flag=1;
		while(flag){
			temp=temp->next;
			if(temp->next==NULL){
				flag=0;
			}
		}
	}
	sos3:
	{
		r->prev=temp;
		r->next=NULL;
		temp->next=r;
	}
}


// Function to show the double linked list -->


void showAll(struct dnode *head){
	struct dnode *temp=head;
	if(temp==NULL){
		printf("[ ]\n");
	}
	else if(temp->next==NULL){
		printf("[ %d ]\n",temp->val);
	}
	else{
		int flag=1;
		printf("[");
		while(flag){
			printf(" %d,",temp->val);
			temp=temp->next;
			if(temp->next==NULL)
				flag=0;
		}
		printf(" %d ]\n",temp->val);
	}
}


// Function to delete a node from linked list -->


int deleteNode(struct dnode **headp, int tar){
	struct dnode *temp=*headp;
	if(temp==NULL){
		return NULL;
	}
	else if(temp->next == NULL){
		if(temp->val==tar){
			*headp=NULL;
			return tar;
		}
		else{
			return NULL;
		}
	}
	else{
		if(temp->val==tar){
			*headp=temp->next;
			free(temp);
			return tar;
		}
		else{
			int flag=1;
			while(flag==1){
				temp=temp->next;
				if(temp->val==tar){ // checks if node is to be deleted
					flag=0;
				}
				if(temp->next==NULL){// checks if the node reached is last node or not
					flag=-1;
				}
			}
			if(flag==0){ 
				(temp->prev)->next=temp->next;
				(temp->next)->prev=temp->prev;
				free(temp);
				return tar;
			}
			if(flag==-1){
				if(temp->val==tar){ // again checks if the last node value matches with the target or not
					(temp->prev)->next=temp->next;
					free(temp);
				}
				else{
					return NULL;
				}
				return NULL;
			}
		}
	}
}


// Function to add a node in the beginning of the linked list -->


struct dnode *addAtBeg(struct dnode *head, int num){
	struct dnode *temp=head;
	struct dnode *r=(struct dnode *)malloc(sizeof(struct dnode));
	
	r->val=num;
	r->prev=NULL;
	if(temp==NULL){
		r->next=NULL;
		temp=r;
		head=temp;
		return head;
	}
	else{
		r->next=temp;
		temp->prev=r;
		head=r;
		return head;
	}
}


// Function to add a node after any node -->


void addAfter(struct dnode *head, int tar, int num){
	struct dnode *temp=head;
	struct dnode *r=(struct dnode *)malloc(sizeof(struct dnode));
	r->val=num;
	
	if(temp==NULL){
		printf("List is empty.\n");
		return;
	}
	else{
		if(temp->val==tar){
			goto sos2;
		}
		else{
			int flag=1;
			while(flag==1){
				temp=temp->next;
				if(temp->next==NULL){
					if(temp->val==tar){ // condition checks if the last node is the target node 
						goto sos2;
					}
					else{
						flag=-1; // condition tells that target not found in the list
						return;
					}
				}
				if(temp->val==tar) // target found before the last node was reached
					flag=0;
			}
			if(flag==0)
				(temp->next)->prev=r;
		}
		sos2:
		{
			r->next=temp->next;
			r->prev=temp;
			temp->next=r;
		}
	}
}
