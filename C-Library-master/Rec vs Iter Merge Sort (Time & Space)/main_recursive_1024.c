#include "ex1.h"
#include "ex2.h"

#define FILE_NAME "1024.txt"
#define NO_OF_RECORDS 1024

int main(){
	FILE *fptr;
	if((fptr = fopen(FILE_NAME,"r"))==NULL){ 
		printf("Error opening A.txt\n");
		exit(1);
	}

	timeAndSpaceRecursiveSort(fptr,NO_OF_RECORDS);
}
