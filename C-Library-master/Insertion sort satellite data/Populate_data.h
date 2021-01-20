#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

struct Record{
	long long int card_num;
	char bank_code[7];
	char expiry[8];
	char first_name[50];
	char last_name[50];
};

typedef struct Record record;

record newRec();
