#include <sys/time.h>
#include "3.h"
#include "5.h"

linkedlist createList(long long int N){
	srand(time(0));
	FILE *fptr;

	fptr = fopen("out3a.txt","a");

	long long int ran;
	linkedlist Ls = newll();
	
	for(long long int i=0; i<N; ++i){
		ran= rand()%(UPPER-LOWER+1)+LOWER;
		insertFirst(&Ls,ran);
	}

	fprintf(fptr,"Total Heap space allocated for N=%lld :  %lld\n",N,myheap_size);

	return Ls;
}


linkedlist createCycle(linkedlist Ls){
	srand(time(0));
	int m = rand()%(2)+1;
	printf("%d\n",m);

	if(m==1){
		srand(time(0));
		long long int ran = 3; //rand()%(UPPER-LOWER+1)+LOWER;
		node* last=Ls.first;
		node* tar=NULL;

		printf("ran value: %lld\n",ran);
		
		if(last==NULL){ //empty list
			goto term;
		}
/*
		else if(last->next==NULL && last->element==ran){ //list with 1 element pointing to itself
			tar = last;
		}

		else if(last->next==NULL && last->element!=ran){ //list with 1 list->element != ran
			goto term;
		}
*/
		else{ //multi element list
			while(last->next != NULL){
				if(last->element==ran){ //if target element is found break the loop
					tar = last;
					break;
				}

				last=last->next;
			}

			while(last->next!=NULL){ //move last to the last element
				last=last->next;
			}
		}
		
		if(tar==NULL && last->element == ran){ //last element of the list == ran
			tar = last;
		}
		
		last->next=tar;
		printf("\nLinkedList after creating cycle\n");
		printList(&Ls);
	}
term:	
	if(m==0){
		printf("\nNo cycle created\n");
	}
	return Ls;
}


int main(int argc, char *argv[]){
	FILE *fptr2;
	fptr2 = fopen("timespace.txt","a");
	char *pEnd;
	long long int N;

	struct timeval t1,t2,t3,t4;
	double et1,et2;

	N=strtoll(argv[1],NULL, 10); //strtoll(char *str, char *end, int base)

	linkedlist Ls = createList(N); //3(a)

	printList(&Ls);

	int *temp;
	int tem;

	Ls = createCycle(Ls); //3(b)

	gettimeofday(&t1,NULL);
	int test_cyc = testCyclic1(&Ls);
	gettimeofday(&t2,NULL);

	printf("\n");
	if(test_cyc == 1){
		printf("Linked List is cyclic testcyclic1\n");
	}
	else{
		printf("Linked list is linear testcyclic1\n");
	}		

	gettimeofday(&t3,NULL);
	int test_cyc1 = testCyclic2(&Ls);
	gettimeofday(&t4,NULL);

	if(test_cyc1==1){
		printf("Linked list is cyclic testcyclic2\n");
	}
	else{
		printf("Linked list is linear testcyclic2\n");
	}

	printf("\n");
	printf("Current heap space used: %lld\n",myheap_size);
	et1 = (t2.tv_sec-t1.tv_sec)*1000.00;
	et1 += (t2.tv_usec-t1.tv_usec)/1000.00;

	et2 = (t4.tv_sec-t3.tv_sec)*1000.0;
	et2 += (t4.tv_usec-t3.tv_usec)/1000.0;
	
	printf("\n");
	printf("Time hare and tort algo: %lf\n",et1);
	printf("Time link reversal algorithm: %lf\n",et2);

	//linkedlist *Ls1=makeCircularList(&Ls);

	//printf("\nList after making it circular\n");
	//printList(Ls1);
	
	node *nd=detectCycle(Ls.first);
	printf("%d\n",nd->element);
}
