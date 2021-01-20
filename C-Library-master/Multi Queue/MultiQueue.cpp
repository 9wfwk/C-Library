#include "Queue.h"
#include "MultiQueue.h"

MultiQ createMQ(int num){
	MultiQ mq=newMQ();
	
	NodeM* n=(NodeM*)malloc(sizeof(NodeM));
	n->p=num;
	n->next=NULL;
	n->qarr=newQ();
	
	mq.first=n;
	mq.size=num;
	
	NodeM* newN;
	
	for(int i=num-1; i>0; --i){
		newN=(NodeM*)malloc(sizeof(NodeM));
		newN->p=i;
		newN->qarr= newQ();
		newN->next=NULL;
		n->next=newN;
		n=newN;
	}
	
	mq.last=newN;
	
	return mq;
		
}

MultiQ newMQ(){
	MultiQ mq;
	mq.first=NULL;
	mq.last=NULL;
	mq.size=0;
	
	return mq;
}

void printMQ(MultiQ mq){
	NodeM* temp=mq.first;
	for(int i=0; i<mq.size; ++i){
		cout << "Queue: " << i+1 << endl;
		cout << "----------------------------------------------" << endl;		
		printQ(temp->qarr);

		temp=temp->next;
	}
}

MultiQ addMQ(MultiQ mq, Task t){
	NodeM* temp=mq.first;
	for(int i=0; i<mq.size; ++i){

		if(temp->p==t.p){
			temp->qarr=addQ(temp->qarr,t.tid,t.p);
			break;
		}
		temp=temp->next;
	}

	return mq;
}

Task nextMQ(MultiQ mq){
	NodeM* temp=mq.first;
	Task t;

	for(int i=0; i<mq.size; ++i){
		if(isEmptyQ(temp->qarr)==false){
			t=frontQ(temp->qarr);
			break;
		}
		temp=temp->next;
	}
	
	return t;
}

MultiQ delNextMQ(MultiQ mq){
	NodeM* temp=mq.first;
	for(int i=0; i<mq.size; ++i){
		if(isEmptyQ(temp->qarr)==false){
			temp->qarr=delQ(temp->qarr);
			break;
		}
		temp=temp->next;
	}
	
	mq.size=sizeMQ(mq);
	return mq;
}

bool isEmptyMQ(MultiQ mq){
	NodeM* temp=(NodeM*)malloc(sizeof(NodeM));
	temp=mq.first;

	for(int i=0; i<mq.size; ++i){
		if(!isEmptyQ(temp->qarr))
			return false;
		temp=temp->next;
	}

	return true;
}

int sizeMQ(MultiQ mq){
	return mq.size;
}

int sizeMQbyPriority(MultiQ mq, Priority pi){
	NodeM* temp=mq.first;

	for(int i=0; i<mq.size; ++i){
		if(temp->p==pi){
			return temp->qarr.length;
		}

		temp=temp->next;
	}

	return 0;
}

Queue getQueueFromMQ(MultiQ mq, Priority pi){
	NodeM* temp=mq.first;

	for(int i=0; i<mq.size; ++i){
		if(temp->p==pi)
			return temp->qarr;
		temp=temp->next;
	}
	
	return newQ();
}
