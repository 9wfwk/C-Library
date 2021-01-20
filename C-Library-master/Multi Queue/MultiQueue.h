#ifndef _MULTIQUEUE_H
#define _MULTIQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <bits/stdc++.h>
#include "Queue.h"
#include "MultiQueue.h"

using namespace std;

struct NodeM{
       Queue qarr;
       Priority p;
       NodeM* next;
};

struct MultiQ{
	NodeM* first;
	NodeM* last;
	int size;
};

//creates a list of num Queues, each of which is empty
MultiQ createMQ(int num);

//adds task t to the Queue corresponding to priority p in mp. Task includes TaskId tid and a priority p 
MultiQ addMQ(MultiQ mq,Task t);

//returns the front of the non-empty Queue in mq with the highest priority
Task nextMQ(MultiQ mq);

//deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
MultiQ delNextMQ(MultiQ mq);

//test whether all Queues in mq are empty
bool isEmptyMQ(MultiQ mq);

//returns the total number of items in the MultiQ
int sizeMQ(MultiQ mq);

//returns the number of items in mq with the priority p
int sizeMQbyPriority(MultiQ mq,Priority p);

//returns the queue with priority p
Queue getQueueFromMQ(MultiQ mq,Priority p);

MultiQ newMQ();

void printMQ(MultiQ mq);

#endif
