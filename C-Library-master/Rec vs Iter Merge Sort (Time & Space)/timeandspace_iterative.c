#include "ex1.h"

void printArr(student arr[],int sz){
	for(int i=0; i<sz; ++i){
		printf("Name: %s\tCgpa: %f\n",arr[i].name, arr[i].cgpa);
	}
}

void timeAndSpaceIterativeSort(FILE *fptr, int NO_OF_RECORDS){
	student* ls1=(student*)malloc(10*sizeof(student));
	
	int sz1=0, sz2=0;
	int full=0;
	struct timeval t1,t2;
	double elapsedtime;
	
	int i=0;
	
	while(fscanf(fptr,"%[^,],%f\n",ls1[i].name,&ls1[i].cgpa) != EOF){ //read everythin till a comma is obtained.
		++sz1;
		++i;
		++full;
		if(full==8){
			ls1=(student*)realloc(ls1,(i+10)*sizeof(student));
			full=0;
		}
	}
	
	int space;
	
	char *p1;
	char a;
	p1 = &a;
	
	gettimeofday(&t1,NULL);	
	iterativeMergeSort(ls1,sz1,p1,&space);
	gettimeofday(&t2,NULL);
	
	//printArr(ls1,sz1);
	elapsedtime = (t2.tv_sec-t1.tv_sec)*1000.00;
	elapsedtime += (t2.tv_usec - t1.tv_usec)/1000.00;
	
	FILE *fptr1 = fopen("time_space.txt","a");
	if(NO_OF_RECORDS==1024){
		printf("----------------------------------------Iterative Sort Results----------------------------------------------------------\n");
	}
	printf("Iterative %d ; Space: %d\t; Time: %lf\n",NO_OF_RECORDS, space, elapsedtime);
	fprintf(fptr1,"Iterative %d ; Space: %d\t; Time: %lf\n",NO_OF_RECORDS, space, elapsedtime);
	
	if(NO_OF_RECORDS==10240){
		printf("----------------------------------------------------------------------------------------------------------------\n");
	}
}
