#include "ex2.h"

void iterativeMergeSort(student arr[], int n, char *p1, int *space){
	int mid,right;
	int iterspace = 2*sizeof(int);
	for(int curr_size=1;curr_size<n;curr_size*=2){
		for(int start=0;start<n;start+=2*curr_size){
			mid = minimum(start+curr_size-1,n-1);
			right = minimum(start+2*curr_size-1,n-1);

			student newarr[right-start+1];
			iterspace += 2*sizeof(int)+(right-start+1)*sizeof(student);

			merge(arr+start,mid-start+1,arr+mid+1,right-mid,newarr);
			for(int i=0;i<right-start+1;i++){
				arr[start+i]=newarr[i];
			}
		}
	}
	
	char b;
	char *p2=&b;
	
	*space = (int)(p1-p2); //p1-p2 because stack is alloted from top to bottom in assembly.

}


int minimum(int a, int b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}
