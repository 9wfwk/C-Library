#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

struct Stack{
	int capacity;
	LinkedList list;
};

Stack newStack(int cap); //create a Stack with capacity cap

int push(Stack *s, int ele);
/* returns 1 if element successfuly pushed
 * return 0 if, -> Stack is full */

ListNode* pop(Stack *s);

void printStack(Stack *s);
