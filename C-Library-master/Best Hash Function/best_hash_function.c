#include "best_hash_function.h"

string newString(int len){
	string str;
	str.arr=(char*)malloc(sizeof(char)*len);

	str.len=0;

	return str;
}

book newBook(int size){
	book bk;
	bk.array = (string*)malloc(sizeof(string)*size);
	bk.size = size;

	for(int i=0; i<size;++i){
		bk.array[i]=newString(WORDSIZE);
	}

	return bk;
}


void printBook(book *bk){
	for(int i=0; i<bk->size; ++i){
		printf("%s\n",(bk->array[i]).arr);
	}
}

int hashFunction(string str, int baseNumber, int tableSize){
	int ch;
	int sum=0;
	for(int i=0;i<str.len; ++i){
		ch = (int)(str.arr[i]);
		sum = sum +ch;
	}

	int index = (((sum*(rand()%(15900000-10000+1)+10000))%baseNumber)%tableSize);
	
	return index;
}

int collisonCount(book bk, int baseNumber, int tableSize){
	int ary[tableSize];
	int count=0,ind;

	for(int i=0; i<tableSize; ++i){
		ary[i]=0;
	}

	//ary[i]=0 indicates no string has been hashed to the ith index
	
	for(int i=0; i<bk.size; ++i){
		ind = hashFunction(bk.array[i],baseNumber,tableSize);
		//printf("%s\t\t\t:Index= %d\n",bk.array[i].arr,ind);
		if(ary[ind]>0){
			++count;
		}

		ary[ind]=ary[ind]+1;
	}

	return count;
}


book parsingFunction(char *filename){

	FILE *fptr=fopen(filename,"r");
	FILE *fptr1=fopen("text.txt","w");

	int cont=0,baseNumber,tableSize;
	char *line=(char*)malloc(sizeof(char)*250);
	char *token;

	while(fscanf(fptr,"%[^\n]\n",line)!=EOF){
		token = strtok(line," ");
		while(token != NULL){
			fprintf(fptr1,"%s\n",token);
			++cont;
			token = strtok(NULL," ");
		}
	}

	book bk = newBook(cont);
	int i=0;

	fclose(fptr1); //Reset fptr1 at the start of text1.txt
	fptr1 = fopen("text.txt","r");

	while(fscanf(fptr1,"%[^\n]\n",bk.array[i].arr) != EOF){
		bk.array[i].len = strlen(bk.array[i].arr);
		++i;
		if(i==cont){ //To handle segmentation fault for bk.array[cont].arr
			break;
		}
	}

	printf("Total number of valid strings: %d\n",bk.size);
	
	//printBook(&bk);

	return bk;
}


profile* profiler(book *bk, int *ts){
	ts[0]=5000;
	ts[1]=50000;
	ts[2]=500000;
	struct timeval t1,t2;
	double et;
	
	//srand(time(0));

	profile *pro=(profile*)malloc(sizeof(profile)*18);
	
	gettimeofday(&t1,NULL);
	int k=0;
//	int ct=0;
	for(int i=0; i<3; ++i){ //for each ts		
		int upper, lower;
		for(int j=0; j<6; ++j){ //6 bn for each ts
//			ct=0;
			if(j<3){
				lower = ts[i];
				upper = 2*ts[i];
			}
			else{
				lower= 1000*ts[i];
				upper=2147483645;
			}

			int ran = (rand()%(upper-lower+1))+lower+j+i;

//			printf("%d\t%d\tRan value: %d\n",i,j,ran);
			while(isPrime(ran) != 1){
				ran = (rand()%(upper-lower+1))+lower+j+i;
//				printf("%d\t%d\tRan value in loop: %d\n",i,j,ran);
/*				if(ct==0){
					fprintf(fptr,"Ran value in loop: %d\n",ran);
				}
				++ct;
*/			}
			
			if(k<6){
				pro[k].ts=5000;
				pro[k].bn=ran;
			}
			else if(k<12){
				pro[k].ts=50000;
				pro[k].bn=ran;
			}
			else
			{
				pro[k].ts=500000;
				pro[k].bn=ran;
			}

//			printf("k= %d\n",k);
			++k;
		}

	}


	gettimeofday(&t2,NULL);
	et = (t2.tv_sec-t1.tv_sec)*1000.0;
	et += (t2.tv_usec-t1.tv_usec)/1000.0;
	
	//printProfile(pro);

	printf("\nTime: %lf\n",et);
	
	int mincoll = collisonCount(*bk,pro[0].bn, pro[0].ts);
	int best_index=0, currcoll;
	
	printf("TableSize: %d \tBaseNumber: %d\tCollison: %d\n",pro[0].ts,pro[0].bn,mincoll);
	
	for(int i=1; i<18; ++i){
		currcoll = collisonCount(*bk,pro[i].bn, pro[i].ts);
		printf("TableSize: %d \tBaseNumber: %d\tCollison: %d\n",pro[i].ts,pro[i].bn,currcoll);
		if(currcoll <mincoll){
			best_index=i;
			mincoll = currcoll;
		}
	}
/* As the number of collisons depended only on tableSize and not on baseNumbers as, bseNumber > sum(ascii)
 * Hence, I changed the hash Function a bit, multiplied sum(ASCII) by 1597
 */
	pro[best_index].best=1;
	printf("\nBest TableSize: %d\tBaseNumber: %d\tCollison: %d\tIndex: %d\n",pro[best_index].ts,pro[best_index].bn,mincoll,best_index);
				
	return pro;
}


int isPrime(int num){
	for(int i=2; i<=(int)(sqrt(num)); ++i){
		if(num%i==0){
			return 0;
		}
	}

	return 1;
}


void printProfile(profile *pro){
	for(int i=0; i<18; ++i){
		printf("TableSize: %d  \tBaseNumber: %d\tBest:%d\n",pro[i].ts,pro[i].bn,pro[i].best);
	}
}
