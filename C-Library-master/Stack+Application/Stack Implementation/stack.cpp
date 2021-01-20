#include "stack.h"

Stack newStack(int cap){
	Stack s;
	s.capacity = cap;
	s.list = newll();

	return s;
}

int push(Stack *s, int ele){
	if(s->list.count == s->capacity){
		return 0;
	}

	else{
		insertFirst(&(s->list), ele);
	}
}

ListNode* pop(Stack *s){
	ListNode *ans = deleteFirst(&(s->list));

	return ans;
}

void printStack(Stack *s){
	printList(&(s->list));
}
