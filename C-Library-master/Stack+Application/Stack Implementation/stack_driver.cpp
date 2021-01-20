#include <stdio.h>
#include "stack.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
	FILE *fptr;
	fptr = fopen(argv[1],"r");
	int cap;

	printf("Enter Stack capacity\n");
	cin >> cap;

	Stack s=newStack(cap);

	int ele;
	while(fscanf(fptr,"%d\n",&ele) != EOF){
		int flag = push(&s, ele);
		if(flag==0){
		       	printf("Error: Stack is full\n");
			goto term1;
		}

	}
term1:
	printf("Stack contents:\n");
	printStack(&s);

	for(int i=0; i<10; ++i){
		ListNode *ans = pop(&s);
		if(ans == NULL){
			printf("ERROR: Stack is empty\n");
			goto term;
		}

		printf("Popped %d\n",ans->element);
	}

term:
	printf("Stack contents:\n");
	printStack(&s);
}
		
