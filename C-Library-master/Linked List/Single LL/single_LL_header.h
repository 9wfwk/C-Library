#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

#ifndef LL_H
#define LL_H

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

ListNode* deleteAlternateNode(ListNode* A);

ListNode* deleteDuplicates(ListNode* A);

ListNode* removeNthFromEnd(ListNode* A, int B);

bool isPalindrome(ListNode* head);

ListNode* mergeTwoLists(ListNode* A,ListNode* B);

void functionality();

void append(ListNode **s, int num);

void showAll(ListNode **s);

void sortAsc(ListNode **s);

int countEleLL(ListNode **s);

//Stack (LIFO) order insertion
void addAtBeg(ListNode **s,int num);

void addAfter(ListNode **s, int n, int num);

void deleteListNode(ListNode **s, int tar);

void addBefore(ListNode **s, int tar, int num);

//Enters a new element in list in its sorted position
void addAsc(ListNode **s, int num);

int getNthNode(ListNode **s, int index);

int getMiddleEle(ListNode **s);

void copyList(ListNode **s1, ListNode **s2);

ListNode *reverseList(ListNode *head);

bool hasCycle(ListNode *head);

ListNode *erase(ListNode **head);

ListNode *concat(ListNode *head, ListNode *other);

//swaps the node and its satellite data containing key1 and key2
void swapNode(ListNode **head, int key1, int key2);

int checkExistence(ListNode **head, int key);

#endif
