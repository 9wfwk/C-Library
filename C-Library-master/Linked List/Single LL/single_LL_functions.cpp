#include "single_LL_header.h"

ListNode* deleteAlternateNode(ListNode* A){
	if(A==NULL || A->next==NULL){
		return A;
	}
	else{
		ListNode* temp=A;
		ListNode* temp1=temp->next;

		while(temp!=NULL && temp1!=NULL){
			temp->next=temp1->next; //Segmentation fault
			temp=temp->next; //Segmentation fault
			if(temp!=NULL);
				temp1=temp->next;
		}

		return A;
	}
}


ListNode* deleteDuplicates(ListNode* A){
	if(A==NULL || A->next==NULL){
		return A;
	}

	ListNode* temp=A;
	ListNode* temp1=A->next;
	while(temp != NULL){
		while(temp1!=NULL && temp1->val==temp->val){ //temp!=NULL should be 1st because otherwise temp1 val will be accessed (segmetation fault
			temp1=temp1->next;
		}

		temp->next=temp1;
		temp=temp->next;
		temp1=temp;
	}

	return A;
}


ListNode* removeNthFromEnd(ListNode* A,int B){
	int len=countEleLL(&A);
	int fir=len-B+1; //get index of node to be removed from the start; consider head to be of index 1.
	ListNode* ans=A;
	if(fir<=1){ //If n >= length then remove the head node
		ans=ans->next;
		free(A);
		return ans;
	}
	else{
		ListNode* temp;
		int i=2;
		A=A->next; //else remove ith node after head node
		while(i!=fir){
			++i;
			temp=A;
			A=A->next;
		}

		temp->next=A->next;
		free(A);

		return ans;
	}

}

bool isPalindrome(ListNode* head){
	int len=countEleLL(&head);
	int i=0;

	if(head==NULL || head->next == NULL){
		return true;
	}
	else{
		int arr[len/2];

		if(len%2==0){
			while(i<len/2){
				arr[i]=head->val;
				head=head->next;
				++i;
			}

			i--;
			while(i>=0){
				if(head->val != arr[i])
					return false;
				head=head->next;
				--i;
			}
		}
		else{
			while(i<len/2){
				arr[i]=head->val;
				head=head->next;
				++i;
			}

			head=head->next;
			--i;

			while(i>=0){
				if(head->val != arr[i])
					return false;
				head=head->next;
				--i;
			}
		}

		return true;
	}
}


//Function to merge 2 linked lists

ListNode *mergeTwoLists(ListNode *A, ListNode *B){
	if(!A)
		return B;
	if(!B)
		return A;

	ListNode *res = new ListNode(0);//new ListNode(0); // Don't do ListNode* res = NULL; *resPtr or 
	ListNode *resPtr = res;          // filling the list gives segmentation fault.
	while(A && B)
	{
		if(A->val <= B->val)
		{
			cout << "AAAA" << endl;
			res->next = A;
			A = A->next;
		}
		else
		{
			cout << "BBBB" << endl;
		  	res->next = B;
		   	B = B->next;
		}
		res = res->next;
	}

	while(A)
	{
		cout << "CCCC" << endl;		
		res->next = A;
		res = res->next;
		A = A->next;
	}
	while(B)
	{
		cout << "DDDD" << endl;
		res->next = B;
		res = res->next;
		B = B->next;
	}
	return resPtr->next;
}

// Function to add any value to the linked list to the end of the list -->



void append(ListNode **s, int num){
	ListNode *temp;
	temp=*s;
	ListNode *r;

	if(*s == NULL){
		temp=(ListNode*)malloc(sizeof(ListNode));
		temp->val=num;
		temp->next=NULL;

		*s=temp;
	}

	else{
		while(temp->next != NULL){
			temp=temp->next;
		}

		r=(ListNode*)malloc(sizeof(ListNode));
		r->val=num;
		r->next=NULL;

		temp->next=r;
	}
}


// Function to show all elements of liked list in insertion order -->


void showAll(ListNode **s){
	if(*s==NULL){
		printf("\n");
		printf("No more elements\n");
		return;
	}

	int count = countEleLL(s);

	ListNode *temp;
	temp=*s;

	printf("[ ");
	while(temp->next != NULL)
	{
		printf(" %d ",temp->val);
		temp=temp->next;
	}
	printf(" %d ",temp->val);
	printf(" ]");
	printf("\n");
}



// Function to sort the list in ascending order -->



void sortAsc(ListNode **s){
	if(*s==NULL){
		printf("No elements in the list:\n");
	}
	else{
		ListNode *temp1;
		temp1=*s;
		ListNode *temp2;
		int flag=1;
		while(flag){
			temp2=temp1->next;

			if(temp1->val > temp2->val){
				int tmp;
				tmp=temp2->val;
				temp2->val=temp1->val;
				temp1->val=tmp;
			}

			if(temp2->next == NULL){
				flag=0;
			}
			temp1=temp1->next;
		}
	}
}



// Function to count the number of elements in the linkedlist -->



int countEleLL(ListNode **s){
	int count=1;

	if(*s == NULL){
		return 0;
	}

	else{
		ListNode *temp;
		temp=*s;
		while(temp->next != NULL){
			count++;
			temp=temp->next;
		}
	}

	return count;
}



// Function to add an element at the beginning -->



void addAtBeg(ListNode **s, int num){
	ListNode *temp;

	if(*s == NULL){
		temp=(ListNode*)malloc(sizeof(ListNode));
		temp->val=num;
		temp->next=NULL;
		*s=temp;
	}

	else{
		ListNode *r;

		r=(ListNode *)malloc(sizeof(ListNode));
		r->val=num;
		r->next=*s;
		*s=r;
	}
}



// Function to add a element after a given element -->



void addAfter(ListNode **s, int n, int num){
	ListNode *temp;

	if(*s == NULL){
		printf("Linked List is empty\n");
	}

	else{
		int flag=1;
		ListNode *r;
		temp=*s;
		while(flag)
		{
			if(temp->val == n)
			{
				r=(ListNode *)malloc(sizeof(ListNode));
				r->val=num;
				r->next=temp->next;
				temp->next=r;
				flag=0;
			}
		temp=temp->next;
		}
	}
}



//Function to deleteListNode a target element -->



void deleteListNode(ListNode **s, int tar){
	if(*s==NULL){
		printf("Linked List is empty\n");
	}
	else{
		ListNode *temp,*prev;
		temp=*s;
		prev=*s;
		int flag=1;

		if((*s)->val==tar)
		{
			(*s)=(*s)->next;
			flag=0;
		}

		while(flag){
			if(temp->val==tar)
			{
				flag=0;
				prev->next=temp->next;
				free(temp);
			}

			prev=temp;
			temp=temp->next;
		}
	}
}



// Function to add a number before a target element -->



void addBefore(ListNode **s, int tar, int num){
	int flag=1;

	if(*s==NULL){
		printf("Linked list is empty\n");
	}
	if((*s)->val==tar)
	{
		ListNode *r;
		r=(ListNode *)malloc(sizeof(ListNode));
		r->val=num;
		r->next=*s;
		*s = r;
		flag=0;
	}

	else
	{
		ListNode *prev, *temp;

		temp=*s;
		prev=*s;

		while(flag)
		{
			if(temp->val==tar)
			{
				flag=0;
				ListNode *q;
				q=(ListNode *)malloc(sizeof(ListNode));
				q->val=num;
				q->next=temp;
				prev->next=q;
			}

			prev=temp;
			temp=temp->next;
		}
	}
}

// Function to insert elements in a linked list in ascending order -->

void addAsc(ListNode **s, int num){
	ListNode *temp, *r;
	int flag=1;
	temp=*s;

	if(*s==NULL || (*s)->val>num)
	{
		r=(ListNode *)malloc(sizeof(ListNode));
		r->val=num;
		r->next=temp;
		*s=r;
		flag=0;
	}
	else
	{
		while(flag)
		{
			if(temp->val <= num && (temp->next == NULL || temp->next->val > num))
			{
				r=(ListNode *)malloc(sizeof(ListNode));
				r->val=num;
				r->next=temp->next;
				temp->next=r;
				flag=0;
			}

			temp=temp->next;
		}
	}
}

// Function to get element present at Nth index position -->


int getNthNode(ListNode **s, int index)
{
	int count=0;
	ListNode *temp;
	temp=*s;
	if(index>(countEleLL(s)-1) || index < 0)
	{
		return NULL;
	}
	while(count != index)
	{
		count++;
		temp=temp->next;
	}

	return (temp->val);
}


// Function to return the middle element of a linked list -->



int getMiddleEle(ListNode **s)
{
	if(*s==NULL)
	{
		return NULL;
	}
	else
	{
		int n=countEleLL(s);
		return getNthNode(s,n/2);
	}
}


// Function to create a copy of a list-->


void copyList(ListNode **s1, ListNode **s2)
{
	ListNode *temp1,*temp2,*temp3,*temp4;
	temp1=*s1;

	if(*s1==NULL)
	{
		printf("No elements to copy\n");
		return;
	}

	else
	{
		// creation of head node
		temp3=(ListNode*)malloc(sizeof(ListNode));
		temp3->val=temp1->val;
		temp3->next=NULL;
		*s2=temp3;
		temp1=temp1->next;

		while(temp1->next != NULL)
		{
			temp4=(ListNode *)malloc(sizeof(ListNode));
			temp4->val=temp1->val;
			temp4->next=NULL;
			temp3->next=temp4;
			temp3=temp4;
			temp1=temp1->next;
		}

		temp4=(ListNode *)malloc(sizeof(ListNode));
		temp4->val=temp1->val;
		temp4->next=NULL;
		temp3->next=temp4;
	}
}


//Add 2 numbers


ListNode *addTwoNumbers(ListNode *l1,ListNode *l2){
	ListNode *temp1=l1;
	ListNode *temp2=l2;
	ListNode *res=NULL;
	int ct=0, sum, dig;
	while(temp1!=NULL && temp2!=NULL){
		sum=(temp1->val)+(temp2->val)+ct;
		dig=(sum)%10;
		ct=ct/10;
		append(&res,dig);
		temp1=temp1->next;
		temp2=temp2->next;
	}
	
	while(temp1!=NULL){
		sum = (temp1->val)+ct;
		dig = (sum%10);
		ct=ct/10;
		append(&res,dig);
		temp1=temp1->next;
	}

	while(temp2!=NULL){ 
		sum = (temp2->val)+ct;
		dig = (sum%10);
		ct=ct/10;
		append(&res,dig);
		temp2=temp2->next;
	}

	if(ct==1){
		append(&res,1);
	}

	return res;
}

//Reverse a linked list


ListNode *reverseList(ListNode *head){
	struct ListNode *temp;
	temp=head;
	if(temp == NULL){
		return NULL;
	}
	else{
		struct ListNode *rev;
		rev=NULL;
		while(temp->next != NULL){
			addAtBeg(&rev,temp->val);
			temp=temp->next;
		}
		
		addAtBeg(&rev,temp->val);
		free(head);
		copyList(&rev,&head);
		return head;
	}
}

//Function to detect loop-->


bool hasCycle(ListNode *head){
	ListNode *fast=head, *slow=head;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = (fast->next)->next;
		if(slow==fast){
			return true;
		}
	}
	
	return false;
}

// Function to erase any linked list completely out of memory -->


ListNode *erase(ListNode **head){
	struct ListNode *temp=*head;
	if(temp==NULL){
		return *head;
	}
	else if(temp->next==NULL){
		free(temp);
		*head=NULL;
	}
	else{
		int flag=1;
		while(flag){
			temp=(*head)->next;
			free(*head);
			*head=temp;
			
			if(temp==NULL){
				flag=0;
			}
		}
	}
	
	return *head;
}

// Function to concatenate two lists -->

ListNode *concat(ListNode *head1, ListNode *head2){
	ListNode *temp=head1;
	int flag=1;
	if(temp==NULL){
		return NULL;
	}
	else if(temp->next == NULL)
		flag=0;
	else{
		while(flag){
			temp=temp->next;
			if(temp->next==NULL)
				flag=0;
		}
	}
	
	temp->next=head2;
	return head1;
}


// Function to swap two nodes by address changing -->


void swapNode(ListNode **s, int key1, int key2)
{
	if(*s==NULL || countEleLL(s)==1)
	{
		printf("Insufficient elements to swap.\n");
		return;
	}
	int flag1=checkExistence(s,key1);
	int flag2=checkExistence(s,key2);
	
	if(flag1<1 || flag1<1)
	{
		printf("Target element not found in list.\n");
		return;
	}
	
	ListNode *temp1,*prev1;
	ListNode *temp2,*prev2;
	
	temp1=*s;
	temp2=*s;
	prev1=*s;
	prev2=*s;
	prev1=temp1;
	
	while(temp1->val != key1)
	{
		prev1=temp1;
		temp1=temp1->next;
	}
	
	while(temp2->val != key2)
	{
		prev2=temp2;
		temp2=temp2->next;
	}
	
	ListNode *r;
	
	r=temp2->next;
	temp2->next=temp1->next;
	
	prev1->next=temp2;
	temp1->next=r;
	prev2->next=temp1;
}


// Function to check whether a given value exists in the linked list or not -->


int checkExistence(ListNode **s, int value){
	ListNode *temp;
	int count =0;
	temp=*s;
	while(temp->next != NULL)
	{
		if(temp->val == value)
		{
			count++;
		}
		temp=temp->next;
	}
	if(temp->val==value)
	{
		count++;
	}
	
	return count;
}
