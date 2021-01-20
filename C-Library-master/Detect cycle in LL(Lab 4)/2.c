#include "2.h"

long long myheap_size =0;

void *myalloc(int size){
	void *block = malloc(size+sizeof(int));
	int *block_size = (int*)block;

	*block_size = size;
	myheap_size += size;
	return (block+sizeof(int));
}

void myfree(void *p){
	p=p-sizeof(int);
	int *block_size = (int*)p;
	int ans = *(block_size);
	myheap_size -= ans;
	
	free(p);
}
