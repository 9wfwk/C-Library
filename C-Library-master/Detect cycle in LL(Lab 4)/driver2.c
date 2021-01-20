#include "2.h"

int main(){
	int *p=(int*)myalloc(sizeof(int)*10);
	int *p1=p;
	--p1;

	srand(time(0));

	if(p){
		for(int i=0; i<10; ++i){
			*(p+i)=i;
		}

		for(int i=0; i<10; ++i){
			printf("%d\n",*p1);
			++p1;
		}

		printf("%d\n",*p1);

		myfree((void*)p);
	}

	for(int i=0; i<100; ++i){
		printf("-----------------------------------------------\n");
		int m;
		printf("Rand %d : %d\n",i+1,m= rand()%(25000-10000+1)+10000);

		int *arr = (int*)myalloc(m*sizeof(int));
		int *p1=arr;
		--p1;

		printf("Size of block: %d ---- Heap size allocated: %d\n",*p1,myheap_size);
		printf("Starting address: %u ---- Ending address: %u \n",&arr[0],&arr[m-1]);

		//myfree((void*)arr);
		/* Uncommenting above line allocated same block again*/

		printf("Size freed: %d ---- Current Heap Size: %d\n",*p1,myheap_size);
		printf("----------------------------------------------\n");
	}
}
