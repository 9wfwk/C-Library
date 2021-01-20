#include "ex2.h"

void insertionSortRecursive(record* recp, int n){
	if(n<=1){
		//printf("\nBBBBBBBBBBBBBBBB\n");
		return;
	}
	
	//printf("\nCCCCCCCCCCCCCCCCCCCC\n");
	insertionSortRecursive(recp,n-1);
	record keyrec = *(recp+n-1);

	insertInOrder(recp,keyrec,n);
}

void insertInOrder(record* recp,record keyrec, int n){
	int j=n-2;
	//printf("\nDDDDDDDDDDDDDDDDDDDDD\n");
	while(j>=0 && recp[j].card_num > keyrec.card_num){
		//printf("\nEEEEEEEEEEEEEEEEEE\n");
		recp[j+1] = recp[j];
		j--;
	}

	recp[j+1] = keyrec;
}
