#include "Queue.h"

Queue newQ(){
	Queue q;
	q.head = NULL;
	q.tail = NULL;
	q.length = 0;

	return q;
}

bool isEmptyQ(Queue q){
	if(q.length<=0){
		return true;
	}
	else
		return false;
}

Queue delQ(Queue q){
	if(isEmptyQ(q))
		return q;
	else if(q.length==1){
		free(q.head);
		q.head=NULL;
		q.tail=NULL;
		q.length=0;
		return q;
	}

	else{
		Task* temp=q.head;
		q.head=temp->next;
		free(temp);
		q.length--;
		return q;
	}
}

Queue addQ(Queue q, TaskId id, Priority pi){
	Task* temp = (Task*)malloc(sizeof(Task));
	temp->tid=id;
	temp->p=pi;

	if(isEmptyQ(q)){
		temp->next=NULL;
		q.head=temp;
		q.tail=temp;
		q.length=1;
	}

	else{
		temp->next=NULL;
		q.tail->next=temp;
		q.tail=temp;
		q.length++;
	}

	return q;
}

void printQ(Queue q){
	Task* temp=q.head;

	while(temp != NULL){
		printf("Tid:%d  Priority:%d\n",temp->tid,temp->p);
		temp=temp->next;
	}
	
	printf("\n");
}

Task frontQ(Queue q){
	Task n=*(q.head);
	return n;
}
