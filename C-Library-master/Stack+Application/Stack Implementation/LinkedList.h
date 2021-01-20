#include <stdio.h>

struct ListNode{
	int element;
	ListNode *next;
};

struct LinkedList{
	int count;
	ListNode *first;
};

void insertFirst(LinkedList *head, int ele);

ListNode* deleteFirst(LinkedList *head);

void printList(LinkedList *head);

int search(LinkedList *head, int ele);
/* searches for a given element in the linked list. Returs 1 if found, 0 otherwise*/

ListNode* deleteList(LinkedList *head, int ele);
/*deletes the first element in the LinkedList that contains the element=ele and returns it. If ListNode not found, returns an error message saying element not found*/

LinkedList newll();
