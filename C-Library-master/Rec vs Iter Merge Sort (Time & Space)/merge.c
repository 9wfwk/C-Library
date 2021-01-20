#include <stdio.h>
#include "ex1.h"

void merge(student ls1[],int sz1,student ls2[],int sz2, student ls[]){
	if(sz1==0 && sz2==0){
		return;
	}
	else{
		int i=0,j=0;
		int k=0;
		while(i<sz1 && j<sz2){
			if(ls1[i].cgpa < ls2[j].cgpa){
				ls[k]=ls1[i];
				k++;
				++i;
			}
			else if(ls1[i].cgpa > ls2[j].cgpa){
				ls[k]=ls2[j];
				++j;
				++k;
			}
			else{
				ls[k]=ls1[i];
				++k;
				++i;
				ls[k]=ls2[j];
				++k;
				++j;
			}
		}

		if(i==sz1 && j < sz2){
			while(j<sz2){
				ls[k]=ls2[j];
				++k;
				++j;
			}
		}
		else if(i < sz1 && j==sz2){
			while(i<sz1){
				ls[k]=ls1[i];
				++k;
				++i;
			}
		}
	}
}

