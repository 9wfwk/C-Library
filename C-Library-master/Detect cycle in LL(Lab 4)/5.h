#include "linkedlist.h"
#include "3.h"

#ifndef _5_H
#define _5_H

linkedlist* makeCircularList(linkedlist *Ls);
/* If Ls is linear, creates a circular list by setting the last node of Ls 
 * point to the first node of Ls.
 *
 * If Ls is cyclic, it deletes all nodes from the head before the cycle i.e.
 * after deletion, the result is a circular list and only nodes that were
 * within the cycle remain */
 
#endif
