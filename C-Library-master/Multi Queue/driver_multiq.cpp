#include "MultiQueue.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

MultiQ loadFile(FILE* fptr, int line);
MultiQ testDel(int num, MultiQ mq);

int main(int argc, char *argv[]){
	FILE *fptr;
	
	fptr=fopen(argv[1],"r");
	
	MultiQ mq1 = loadFile(fptr,stoi(string(argv[2])));
	printMQ(mq1);
	
	int num;
	printf("Enter no. of deletions:\n");
	scanf("%d",&num);
	
	mq1=testDel(num,mq1);
	printMQ(mq1);
}


MultiQ loadFile(FILE *fptr, int line){
	int id,pr;
	if(fptr==NULL){
		printf("Error opening file\n");
		exit(1);
	}
	else{
		MultiQ mq=createMQ(line);
		Task t;

		while(fscanf(fptr,"%d,%d\n",&id,&pr) != EOF){
			t.tid=id;
			t.p=pr;
			mq=addMQ(mq,t);
		}

		return mq;
	}
}

MultiQ testDel(int num, MultiQ mq){

	for(int i=0; i<num; ++i){
		mq=delNextMQ(mq);
	}
	
	return mq;
}
