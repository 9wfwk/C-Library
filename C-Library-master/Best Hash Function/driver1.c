#include "1.h"
#include <locale.h>

int main(int argc, char *argv[]){
	srand(time(0));

	setlocale(LC_ALL, "en_US.UTF-8");
	int tableSize, baseNumber;	
	book bk = parsingFunction(argv[1]);
	
	int ts[3];

	profile *p=profiler(&bk, ts);
	
	printf("\n\n");
	printf("-------------------------------------------------------------\n");
	printf("\n\nProfile of tableSize and basNumbers for file %s\n\n",argv[1]);
	printProfile(p);
}
