#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#ifndef EX1_H
#define EX1_H

struct Student{
	char name[10];
	float cgpa;
};

typedef struct Student student;

int minimum(int a, int b);

void merge(student ls1[],int sz1, student ls2[], int sz2, student ls[]);		

void printArr(student arr[], int sz);

void recursiveMergeSort(student arr[], int sz, char *p1, int *space); //p1 is pointer declared in calling function for recursiveMergeSort, space is the topofstack-p1 to calculate stack space used.

void iterativeMergeSort(student arr[], int sz, char *p1, int *space);//p1 is pointer declared in calling function for recursiveMergeSort, space is the topofstack-p1 to calculate stack space used.

#endif
