#include "ex2.h"
#include <sys/time.h>

#define NO_OF_RECORDS 100000
void readRecords();
void printrec(record* rec);

record* recp;

int main(){
	readRecords();
}

void readRecords(){
	FILE *fptr2;
	fptr2=fopen("space.txt","a");
	int a;
	recp=(record*)malloc(50*sizeof(record));
	for(int i=0; i<50; ++i){
		*(recp+i)=newRec();
	}

	int full =0;

	FILE *fptr;
	FILE *fptr1;

	if((fptr = fopen("100000","r"))==NULL){ //Whenever changing the filename, change preprocessor directive for define NO_OF_RECORDS too.
		printf("Error opening file\n");
		exit(1);
	}

	else{
		int i=0;
		while(fscanf(fptr,"\"%lld,%[^,],%[^,],%[^,],%[^\"]\"\n",&((recp+i)->card_num), recp[i].bank_code, recp[i].expiry, recp[i].first_name, recp[i].last_name) !=EOF){
			printf("i = %d \t full= %d\n",i,full);
			//printrec(recp+i);
			++i;
			++full;
			
			if(full == 48){
				recp = (record*)realloc(recp, (i+51)*sizeof(record));
				full=0;
			}
		}
		
		struct timeval t1,t2;
		double elapsedTime;


		printf("\nRecords in sorted order\n");
		
		gettimeofday(&t1,NULL);
		insertionSortRecursive(recp,NO_OF_RECORDS);
		gettimeofday(&t2,NULL);

		//for(int i=0; i<NO_OF_RECORDS; ++i){
			//printf("\nAAAAAAAAAAAAAAAAAAAAAAAAA\n");
			//printrec(recp+i);
	//	}

		elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.00;
		elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.00;
		
		fptr1 = fopen("Insertion_sort_time_out","a");
		fprintf(fptr1,"Time(in ms): %lf \tNo. of records: %d \n",elapsedTime,NO_OF_RECORDS);
		
		fclose(fptr);
		fclose(fptr1);
		
		fprintf(fptr2,"Space: %llu \t No. of records: %u\n",((int*)(recp+sizeof(record))-&a),NO_OF_RECORDS);
	}
	
}

record newRec(){
	record rec;

	rec.card_num = 0;
	rec.bank_code[0] = '\0';
	rec.expiry[0] = '\0';
	rec.first_name[0] = '\0';
	rec.last_name[0] = '\0';

	return rec;
}

void printrec(record* rec){
	printf("\n");
	printf("Card num : %lld\n",rec->card_num);
	printf("Bank code: %s\n",rec->bank_code);
	printf("Expiry date: %s\n",rec->expiry);
	printf("Name: %s %s\n",rec->first_name,rec->last_name);
}
