#ifndef heap_h
#define heap_h
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stdint.h>

struct Heap{
	int *arr;
	int size;
};

typedef struct Heap heap;

void maxHeapify(heap h, int index);
void buildMaxHeap(heap h);
void minHeapify(heap h, int index);
void buildMinHeap(heap h);
void heapSort(heap h);
heap newHeap();
void swapint(int &t1, int &t2);
void printHeap(heap h);
int getLeftChildInd(heap h,int index);
int getRightChildInd(heap h, int index);
int getParentIndex(heap h, int index);
int getLogBase2Ind(int num);

int extractMax(heap &h); //As we are modifying the size of the heap in this, take a reference variable so that it gets reflected in the original heap.
void insertIntoMax(heap &h, int element);
void increaseKey(heap h, int oldind, int newval);

int extractMin(heap &h);
void insertIntoMin(heap &h, int element);
void decreaseKey(heap h, int oldind, int newval);

#endif
