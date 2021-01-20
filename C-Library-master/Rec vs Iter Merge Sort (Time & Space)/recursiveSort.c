#include "ex2.h"

void recursiveMergeSort(student arr[], int sz, char *p1, int *space){
	if(sz==0 || sz==1){
		char b;
		char *p2=&b;
		
		*space = (int)(p1-p2); //p1-p2 because stack is alloted from top to bottom in assembly.
		return;
	}
	int mid=sz/2;
	student left[mid];
	student right[sz-mid];

	for(int i=0; i<mid; ++i){
		left[i]=arr[i];
	}

	for(int j=mid,k=0; j<sz; ++j){
		right[k]=arr[j];
		++k;
	}
	
	recursiveMergeSort(left,mid, p1,space);
	recursiveMergeSort(right,sz-mid, p1,space);
	merge(left,mid,right,sz-mid,arr);
}
