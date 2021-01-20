#ifndef _QUEUE_H
#define _QUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <bits/stdc++.h>

using namespace std;

typedef int TaskId;
typedef int Priority;

struct Task{
	TaskId tid;
	Priority p;
	Task* next;
};

struct Queue{
	Task* head;
	Task* tail;
	int length;
};

Queue newQ();

bool isEmptyQ(Queue q);

Queue delQ(Queue q);

Task frontQ(Queue q);

Queue addQ(Queue q, TaskId id, Priority pi);

Queue lengthQ(Queue q);

void printQ(Queue q);


#endif
