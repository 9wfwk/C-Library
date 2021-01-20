#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct ListNode{
	ListNode *prev;
	float coeff;
	int exp;
	ListNode *next;
};

ListNode *append(ListNode **head, float coeff, int exp);
void showPol(ListNode *head);
ListNode *addPol(ListNode *fp, ListNode *sp, ListNode **res);
ListNode *padd(ListNode **head, float cf, int ep);
void multPol(ListNode *fp, ListNode *sp, ListNode **res);

int main(){
	ListNode *fp=NULL;
	ListNode *sp=NULL;
	
	int ch;
	sos:
	{
		int op;
		printf("(1)Polynomial operations:\n");
		cin >> op;
		switch(op)
		{
			case 1:
			{
				int ch1;
				printf("Enter term (1st) (yes-1/no-0):\n");
				cin >> ch1;
				while(ch1!=0)
				{
					printf("Enter coefficients and exponents of 1st polynomial:\n");
					int exp;
					float coeff;
					cin >> coeff >> exp;
					
					fp=append(&fp,(float)coeff,exp);
					
					printf("Enter term (1st) (yes-1/no-0):\n");
					cin >> ch1;
				}
				
				printf("Enter term (2nd) (yes-1/no-0):\n");
				cin >> ch1;
				while(ch1!=0)
				{
					printf("Enter coefficients and exponents of 2nd polynomial:\n");
					int exp;
					float coeff;
					
					cin >> coeff >> exp;
					sp=append(&sp,(float)coeff,exp);
					printf("Enter term (2nd) (yes-1/no-0):\n");
					cin >> ch1;
				}
				
				break;
			}
			default:
			{
				goto sos;
			}
		}
	}
		
	sos1:
	{
		printf("Perform operation (yes-1/no-1):\n");
		cin >> ch;
		
		while(ch!=0)
		{
			int op1;
			printf("(1)Show polynomials:\n(2)Add polynomials:\n(3)Add another term:\n(4)Multiply Pol-1 and Pol-2:\n");
			cin >> op1;
			
			switch(op1)
			{
				case 1:
				{
					printf("\nPol 1:\n");
					showPol(fp);
					printf("Pol 2:\n");
					showPol(sp);
					printf("\n");
					break;
				}
				case 2:
				{
					ListNode *res=NULL;
					res=addPol(fp,sp,&res);
					showPol(fp);
					printf(" + \n");
					showPol(sp);
					printf(" =\n");
					showPol(res);
					break;
				}
				case 3:
				{
					float cf;
					int ep,op;
					printf("Enter coefficient and exponent of new term:\n");
					cin >> cf >> ep;
					printf("Enter in Pol-1 or Pol-2:\n");
					cin >> op;
					
					if(op==1){
						fp=padd(&fp,cf,ep);
					}
					else if(op==2){
						sp=padd(&sp,cf,ep);
					}
					
					printf("Polynomial %d after term addition:\n",op);
					if(op==1){
						showPol(fp);
					}
					else if(op==2){
						showPol(sp);
					}
					break;
				}
				case 4:
				{
					ListNode *res=NULL;
					multPol(fp,sp,&res);
					printf("\nPolynomial after multiplication:\n");
					showPol(res);
					break;
				}
				default:
				{
					goto sos1;
				}
			}
			
			goto sos1;
		}
	}
}


//Function to store a polynomial in linked list -->


ListNode *append(ListNode **head, float coeff, int exp){
	ListNode *temp=*head;
	ListNode *r=(ListNode *)malloc(sizeof(ListNode));
	
	r->coeff=(float)coeff;
	r->exp=exp;
	
	if(temp==NULL){
		r->prev=NULL;
		r->next=NULL;
		temp=r;
		*head=temp;
		return *head;
	}
	else if(temp->next == NULL){
		goto sos2;
	}
	else{
		int flag=1;
		while(temp->next != NULL){
			temp=temp->next;
		}
	}
	sos2:
	{
		temp->next=r;
		r->prev=temp;
		r->next=NULL;
		return *head;
	}
}


// Function to show the polynomials on the screen -->


void showPol(ListNode *head){
	ListNode *temp=head;
	if(temp==NULL){
		printf("[ 0 ]\n");
		return;
	}
	else{
		int ct=temp->exp, flag=1;
		printf("[");
		while(flag){
			if(ct==temp->exp){
				printf(" (%f)z^(%d) ",temp->coeff,temp->exp);
				ct--;
			}
			else{
				float d=0;
				printf(" (%f)z^(%d) ",(float)d,ct);
				ct--;
				continue;
			}
			if(temp->next==NULL){
				flag=0;
			}
			temp=temp->next;
		}
		printf("]\n");
	}
}


//Function to add two polynomials -->


ListNode *addPol(ListNode *fp, ListNode *sp, ListNode **ans){
	ListNode *f=fp, *s=sp, *temp=*ans;
	ListNode *r=(ListNode *)malloc(sizeof(ListNode));
	if(f==NULL && s==NULL){
		*ans=NULL;
	}
	
	else if(f==NULL && !(s==NULL)){
		*ans=s;
	}
	
	else if(s==NULL && !(f==NULL)){
		*ans=f;
	}
	
	else{
		int flag1=1, flag2=1;
		while(flag1==1 && flag2==1){
			if(f->exp==s->exp){
				append(ans, (s->coeff)+(f->coeff), s->exp);
				s=s->next;
				f=f->next;
			}
			else if(s->exp > f->exp){ //adds the lower exponent term and proceeds the pointer to higher exponent term 1 step forward
				append(ans, s->coeff, s->exp);
				s=s->next;
			}
			else if(f->exp > s->exp){
				append(ans, f->coeff, f->exp);
				f=f->next;
			}
			
			if(f==NULL)
				flag1=0;
			if(s==NULL)
				flag2=0;
		}
		
		if(flag1==1){ // if second polynomial had lesser no. of terms than first polynomial, then appends remaining terms of the 1st.
			while(f!=NULL){
				append(ans,f->coeff,f->exp);
				f=f->next;
			}
		}
		else if(flag2==1){
			while(s!=NULL){
				append(ans,s->coeff,s->exp);
				s=s->next;
			}
		}
	}
	return *ans;
}


//Function to add any term in the descending order of exponents of the terms -->


ListNode *padd(ListNode **head, float cf, int ep){
	ListNode *temp=*head;
	ListNode *r=(ListNode *)malloc(sizeof(ListNode));
	
	r->coeff=cf;
	r->exp=ep;
	
	if(temp==NULL){
		r->next=NULL;
		r->prev=NULL;
		*head=r;
		return *head;
	}
	else if(temp->next==NULL && ep>temp->exp){
		r->next=temp;
		temp->prev=r;
		*head=r;
		return *head;
	}
	else if(temp->next==NULL && ep<temp->exp){
		temp->next=r;
		r->prev=temp;
		r->next=NULL;
		return *head;
	}
	else if(temp->next==NULL && temp->exp==ep){
		temp->coeff=(temp->coeff)+cf;
		free(r);
		return *head;
	}
	else{
		temp=temp->next;
		while(temp!=NULL){
			sos3:
			{	
				if(temp->exp==ep){ // if the term has exponent equal to the term to be added
					temp->coeff=(temp->coeff)+cf;
					free(r);
					return *head;
				}
				else if(temp->next == NULL && temp->exp>ep){ // adds the terms if its exponent is lesser than the last term of the polynomial.
					temp->next=r;
					r->prev=temp;
					r->next=NULL;
					return *head;
				}
				else if(ep<temp->exp && ep>((temp->next)->exp)) // adds the new term in the middle of two existing nodes.
				{ 
					r->next=temp->next;
					r->prev=temp;
					(temp->next)->prev=r;
					temp->next=r;
					return *head;
				}
				
//Commented out the lines below as temp->next traverses the pointer away from the head node where the below conditions did not
// play any role.
/*				else if(ep>(temp->exp)){
					r->next=temp;
					temp->prev=r;
					*head=r;
					return *head;
				}
*/			}
			temp=temp->next;
		}
	}
}


//Function to multiply two polynomials -->


void multPol(ListNode *fp, ListNode *sp, ListNode **res){
	ListNode *f=fp, *s=sp;
	float cf;
	int ep;
	
	if(f==NULL && s==NULL){
		return;
	}
	else if(f==NULL && !(s==NULL)){
		*res=s;
	}
	else{
		if(s==NULL && !(f==NULL)){
			*res=f;
		}
		else{
			while(f != NULL){
				while(s != NULL){
					cf=(f->coeff)*(s->coeff);
					ep=(f->exp)+(s->exp);
					padd(res, (float)cf, ep);
					s=s->next;
				}
				s=sp;
				f=f->next;
			}
		}
	}
}
