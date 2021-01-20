#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXI 100 //Maximum size of the expression to be evaluated

struct conv{
	char tar[MAXI];
	char stack[50];
	char ansstack[200];
	char *s, *t;
	int top,flag,anstop;
};

struct express{
	char expr[MAXI];
	int stack[50];
	char *s;
	int *t;
	int top,flag;
};

struct node{
	char val;
	struct node *next;
};
	

int evaluatePost(struct express *p);
void initexpr(struct express *p);
int countDigit(int num);
void pushp(struct express *p, int num);
int popp(struct express *p);
int evaluatePre(struct express *p);
int revNum(int num);

//convert infix expression to postfix expression with alphanumeric terms 
void initconv(struct conv *p);
void convertInPo(struct conv *p);
void pushStack(struct conv *p, char c);
void pushAns(struct conv *p, char c);
int getWt(char c);
char popStack(struct conv *p);
char peekStack(struct conv *p);

//convert infix expression to pre fix expression with alphanumeric terms 
void convertInPre(struct conv *p);
void reverseTar(struct conv *p);
void changePar(struct conv *p);
void revAns(struct conv *p);
void reverseAns(struct conv *p);
void revDig(struct conv *p, int flag);
void pushinList(struct node **headp, char c);
char popfromList(struct node **headp);

char *strrev(char *str);

int main(){
	int op;
	string op1;
	struct express s;
	struct conv p;
	sos:
	{
		printf("Enter distict numbers (i.e. 12, 2, 123), operators (+,-,/,*,%,^) separated by 'whitespace' character.\n");
		printf("(1)Evaluate a postfix expression:\n(2)Evaluate a prefix expression:\n(3)Convert infix expression to postfix:\n");
		printf("(4)Convert Infix expression to Pre fix:\n");
		getline(cin,op1);
		op = stoi(op1);
		switch(op)
		{
			case 1:
			{
				initexpr(&s);
				s.flag=1;
				printf("Enter postfix expression:\n");
				cin.getline(s.expr,MAXI);
				int ans=evaluatePost(&s);
				printf("Answer : %d\n",ans);
				printf("\n");
				break;
			}
			case 2:
			{
				initexpr(&s);
				s.flag=-1;
				printf("Enter prefix expression:\n");
				cin.getline(s.expr,MAXI);
				int ans=evaluatePre(&s);
				printf("Answer : %d\n",ans);
				printf("\n");
				break;
			}
			case 3:
			{
				initconv(&p);
				p.flag=1;
				printf("Enter infix expression:\n");
				cin.getline(p.tar,MAXI);
				printf("\n");
				convertInPo(&p);
				printf("Infix expression : %s\nPostfix expression : %s\n",p.tar,p.ansstack);
				printf("\n");
				break;
			}
			case 4:
			{
				initconv(&p);
				p.flag=-1;
				printf("Enter infix expression:\n");
				cin.getline(p.tar,MAXI);
				printf("\n");
				convertInPre(&p);
				printf("Infix expression : %s\nPre fix expression : %s\n",p.tar,p.ansstack);
				printf("\n");
				break;
			}
			default:
			{
				goto sos;
			}
		}
	}
}


//Function to initialize struct express -->


void initexpr(struct express *p){
	p->top=-1;
	p->s=p->expr;
	p->t=p->stack;
	p->flag=0;
}


//Function to count the number of digits in a number -->


int countDigit(int num){
	int count=0,quo;

	while(num != 0){
		count++;
		num=num/10;
	}
	return count;
}

	
//Function to evaluate a postfix expression -->


int evaluatePost(struct express *p){
	while(*(p->s) != '\0'){
		if(isdigit(*(p->s)) != 0){
			int num, count=0,digit;
			
			if(p->flag==1){ // true is evaluation is for postfix expression 
				sscanf(p->s,"%d",&num);
				printf("num : %d\n", num);
			}
			
/*			else if(p->flag==-1){ // true if evaluation is for prefix expression
				sscanf(p->s,"%d",&num);
				num=revNum(num);
			}
			if(*(p->s)=='0' && num != 0){ // if the number has 0's at the end then due to the reversal operation, the value of the number 
										  // falls. This counts the number of zeroes preeceding the num in reverse format.
				count++;
				printf("A\n");
			}
*/			digit=countDigit(num)+count; // to traverse the pointer s through the zeroes preceeding too, count has been added.
			while(digit != 0){
				(p->s)++;
				digit--;
//				printf("B\n");
			}			
			sos1:
			{
				num=num*pow(10,(double)count);
				pushp(p,num);
				continue;
			}
		}
		else if(*(p->s) == ' '){
			(p->s)++;
			continue;
		}
		else if(*(p->s)=='+' || *(p->s)== '-' || *(p->s)== '*' || *(p->s)== '/' || *(p->s)=='%' || *(p->s) == '^'){
			int op1,op2;
			if(p->flag==1){
				op2=popp(p);
				op1=popp(p);
			}
			
			// The first if is for postfix expression evaluation 
			// Second if is for prefix expression evaluation 
			else if(p->flag==-1){
				op1=popp(p);
				op2=popp(p);
			}
			char c=*(p->s);
			switch(c)
			{
				case '+':
				{
					pushp(p,op1+op2);
					break;
				}
				case '-':
				{
					pushp(p,op1-op2);
					break;
				}
				case '*':
				{
					pushp(p,op1*op2);
					break;
				}
				case '/':
				{
					pushp(p,op1/op2);
					break;
				}
				case '%':
				{
					int quo=op1/op2;
					pushp(p,(op1-(op2*quo)));
					break;
				}
				case '^':
				{
					pushp(p,(int)(pow(op1,op2)));
					break;
				}
				default:
				{
					break;
				}
			}
			(p->s)++;
			continue;
		}
		(p->s)++;
	}
	return popp(p);
}


void pushp(struct express *p, int num){
	if(p->top==49){
		printf("Stack is full\n");
	}
	else{
		(p->top)++;
		*(p->stack+p->top)=num;
	}
}

int popp(struct express *p){
	if(p->top==-1){
		//printf("Invalid postfix expression.\n");
		return -273;
	}
	else{
		int ele=*(p->stack + p->top);
		*(p->stack + p->top)=0;
		(p->top)--;
		return ele;
	}
}


//Function to evaluate a prefix expression -->


int evaluatePre(struct express *p){
	char *c=strrev(p->expr);
	strcpy(p->expr,c);
	int ans=evaluatePost(p);
	return ans;
}


//Function to reverse a number -->


int revNum(int num){
	int rem=0, rev=0;
	while(num != 0){
		rem=num%10;
		num=num/10;
		rev=rem*pow(10,(double)countDigit(num))+rev;
	}
	
	return rev;
}

//-----------------------------------------------------------------------------------

//Function to initialise struct conv variable -->



void initconv(struct conv *p){
	strcpy(p->tar,"");
	strcpy(p->stack,"");
	strcpy(p->ansstack,"");
	p->top=-1;
	p->t=p->tar;
	p->s=p->stack;
	p->flag=0;
	p->anstop=-1;
}


//Function to convert infix expression to postfix expression -->


void convertInPo(struct conv *p){
	while(*(p->t) != '\0'){
		char ch=*(p->t);
		
		if(ch == '('){
			pushStack(p,'(');
			(p->t)++;
		}
		
		else if(isalpha(ch) != 0){
			pushAns(p,ch);
			pushAns(p,' ');
			(p->t)++;
		}
		
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='%'){
			int flag=1;
			while(flag){
				char c=peekStack(p);
				int n=getWt(c);
				int m=getWt(ch);
				if(n>=m){
					c=popStack(p);
					if(c=='?'){
						printf("Invalid expression.\n");
						return;
					}
					pushAns(p,c);
					pushAns(p,' ');
				}
				if(n<m){
					flag=0;
				}
			}			
			pushStack(p,ch);
			(p->t)++;
		}
		
		else if(*(p->t)==')'){
			while(peekStack(p) != '('){
				char c=popStack(p);
				pushAns(p,c);
				pushAns(p,' ');
			}
			popStack(p);
			(p->t)++;
		}
		
		else if(isdigit(ch) != 0){
			while(isdigit(ch) != 0){
				pushAns(p,ch);
				(p->t)++;
				ch=*(p->t);
			}
			pushAns(p,' ');
		}
		else 
			(p->t)++;
	}
	
	while(p->top != -1){
		pushAns(p,*(p->stack+p->top));
		(p->top)--;
	}
	
	pushAns(p,'\0');
}

void pushStack(struct conv *p, char c){
	if(p->top==49){
		printf("Stack is full.\n");
	}
	else{
		(p->top)++;
		*(p->stack+p->top)=c;
	}
}

void pushAns(struct conv *p, char c){
	if(p->anstop==199){
		printf("ansstack is full.\n");
	}
	else{
		(p->anstop)++;
		*(p->ansstack+p->anstop)=c;
	}
}


//Function to peek character present in conv.stack -->


char peekStack(struct conv *p){
	if(p->top==-1){
		return '\0';
	}
	else{
		return *(p->stack+p->top);
	}
}


//Function to assign weight of operators according to their precedence -->


int getWt(char c){
	int wt;
	switch(c){
		case '+':
		{
			wt=1;
			break;
		}
		case '-':
		{
			wt=1;
			break;
		}
		case '*':
		{
			wt=2;
			break;
		}
		case '/':
		{
			wt=2;
			break;
		}
		case '%':
		{
			wt=2;
			break;
		}
		case '^':
		{
			wt=3;
			break;
		}
		default:
		{
			wt=0;
			break;
		}
	}
	return wt;
}


//Function to pop element from conv.stack -->


char popStack(struct conv *p){
	if(p->top==-1){
		return '?';
	}
	else{
		char c=*(p->stack+p->top);
		*(p->stack+p->top)='\0';
		(p->top)--;
		return c;
	}
}

//---------------------------------------------------------------------------

//Function to convert infix expression to pre fix expression -->


void convertInPre(struct conv *p){
	reverseTar(p);
	changePar(p);
	revDig(p,1);
	convertInPo(p);
	revAns(p);
	revDig(p,-1);
}


//Function to reverse conv.tar -->

void reverseTar(struct conv *p){
	char *g;
	g=strrev(p->tar);
	strcpy(p->tar,g);
}


//Function to replace '(' with ')' and vice versa -->


void changePar(struct conv *p){
	while(*(p->t) != '\0'){
		if(*(p->t)=='(')
			*(p->t)=')';
		else if(*(p->t)==')')
			*(p->t)='(';
	}
	p->t=p->tar;
}


// Function to reverse content of array conv.ansstack -->


void revAns(struct conv *p){
	char *t=strrev(p->ansstack);
	strcpy(p->ansstack, t);
}


//Functio to reverse digit characters in a array involved in forming a number -->


void revDig(struct conv *p, int flag){
	if(flag==1){
		char *c=p->tar;
		char *d=p->tar;
		while((*c) != '\0'){
			if(isdigit(*c)==0){
				c++;
				d++;
			}
			
			else{
				struct node *head=NULL;
				while(isdigit(*c) != 0){
					pushinList(&head, *c);
					c++;
				}
				
				while(d != c){
					*d=popfromList(&head);
					d++;
				}
			}
		}
	}
	
	else{
		char *c=p->ansstack;
		char *d=p->ansstack;
		
		while((*c) != '\0'){
			if(isdigit(*c)==0){
				c++;
				d++;
			}
			
			else{
				struct node *head=NULL;
				while(isdigit(*c) != 0){
					pushinList(&head, *c);
					c++;
				}
				
				while(d != c){
					*d=popfromList(&head);
					d++;
				}
			}
		}
	}
}

void pushinList(struct node **headp, char c){
	struct node *temp=*headp;
	struct node *r=(struct node *)malloc(sizeof(struct node));
	r->val=c;
	
	if(temp == NULL){
		r->next=NULL;
		*headp=r;
	}
	
	else{
		r->next=temp;
		*headp=r;
	}
}

char popfromList(struct node **headp){
	struct node *temp=*headp;
	
	if(temp==NULL){
		printf("Error\n");
		return '\0';
	}
	else{
		*headp=(*headp)->next;
		char c=temp->val;
		free(temp);
		temp=NULL;
		return c;
	}
}

//Reverse a string

char *strrev(char *str){
      char *p1, *p2;

      if (!str || !*str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
