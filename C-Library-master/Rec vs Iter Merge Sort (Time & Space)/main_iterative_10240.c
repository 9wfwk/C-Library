#include "ex1.h"
#include "ex2.h"

#define FILE_NAME "10240.txt"
#define NO_OF_RECORDS 10240

int main(){
	FILE *fptr;
	if((fptr = fopen(FILE_NAME,"r"))==NULL){ 
		printf("Error opening A.txt\n");
		exit(1);
	}
		
	timeAndSpaceIterativeSort(fptr,NO_OF_RECORDS);
}
