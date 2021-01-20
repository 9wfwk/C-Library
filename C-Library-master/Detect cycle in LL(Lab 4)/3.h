#include "linkedlist.h"
#include <time.h>

#ifndef _3_H
#define _3_H

#define UPPER 11
#define LOWER 2

linkedlist createList(long long int N);
/* generates N random numbers 
 * stores the N random numbers in a linked list
 * uses myalloc and outputs the total heap space allocated in a text file
 * returns the linked list */

linkedlist createCycle(linkedlist Ls);
/* tosses a coin programmatically to decide if Ls should be cyclic or linear
 * If cyclic, generates random no. r,points the last node to 1st node having r
 * If linear returns Ls as it is */
 
int testCyclic1(linkedlist *head);
 
int testCyclic2(linkedlist *head);

/* testcyclic 1 performs better if the list is linear
 * testcyclic 2 performs faster if the list is circular
 */
 
#endif
