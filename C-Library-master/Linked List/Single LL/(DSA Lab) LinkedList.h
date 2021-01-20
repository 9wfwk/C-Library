#include <stdio.h>

struct Node{
	int element;
	struct Node *next;
};

typedef struct Node node;

struct LinkedList{
	int count;
	struct Node *first;
};

typedef struct LinkedList linkedlist;

void insertFirst(linkedlist *head, int ele);

node* deleteFirst(linkedlist *head);

void printList(linkedlist *head);

int search(linkedlist *head, int ele);
/* searches for a given element in the linked list. Returs 1 if found, 0 otherwise*/

node* delete(linkedlist *head, int ele);
/*deletes the first element in the linkedlist that contains the element=ele and returns it. If node not found, returns an error message saying element not found*/

linkedlist newll();
