#include "single_LL_header.h"

int main(){
	functionality();
}

void functionality(){
	int op;
	int op1;
	ListNode *p;
	p=NULL;
start:	
	printf("(1) Linked List (FIFO):\n(2) Linked List (LIFO):\n(3) Linked List in ascending order:\n");
	scanf("%d",&op);
	fflush(stdin);
	switch(op){
		case 1:
		{
			int num;
			int n;
			cout << "Enter no. of elements:" << endl;
			cin >> n;
			cout << "Enter elements: " << endl;
			while(n>0){
				cin >> num;
				append(&p,num);
				--n;
			}
				
			printf("Enter more(1-Yes, 0-No) ?\n");
			cin >>op1;
			
			while(op1!=0){
				printf("Enter element:\n");
				cin >> num;
				append(&p,num);
				
				printf("Enter more(1-Yes, 0-No) ?\n");
				cin >>op1;
			}
			
			break;
		}
		case 2:
		{
			int num;
			int n,op3;
			cout << "Enter no. of elements:" << endl;
			cin >> n;
			cout << "Enter elements: " << endl;
			while(n>0){
				cin >> num;
				addAtBeg(&p,num);
				--n;
			}
				
			printf("Enter more(1-Yes, 0-No) ?\n");
			cin >>op3;
			
			while(op3!=0){
				printf("Enter element:\n");
				cin >> num;
				addAtBeg(&p,num);
				
				printf("Enter more(1-Yes, 0-No) ?\n");
				cin >>op3;
			}
			
			break;
		}
		case 3:
		{
			int num;
			int n,op4;
			cout << "Enter no. of elements:" << endl;
			cin >> n;
			cout << "Enter elements: " << endl;
			while(n>0){
				cin >> num;
				addAsc(&p,num);
				--n;
			}
				
			printf("Enter more(1-Yes, 0-No) ?\n");
			cin >>op4;
			
			while(op4!=0){
				printf("Enter element:\n");
				cin >> num;
				addAsc(&p,num);
				
				printf("Enter more(1-Yes, 0-No) ?\n");
				cin >>op4;
			}
			break;
		}
		default:
		{
			goto start;
		}
	}
	
	int ch1;
	do
	{
		int op2;
		printf("(1) Show all elements:\n(2) Sort elements in ascending order:\n(3) Get no. of elements present in the list:\n");
		printf("(4) Add an element after target element:\n(5) Delete an element:\n(6) Enter an element before a target:\n");
		printf("(7) Get nth node (0-indexed):\n(8) Get nth node from the end (1-indexed):\n(9) Get middle element of the list:\n");
		printf("(10) Create a clone:\n(11) Merge two sorted linkedlists:\n(12) Palindrome linked list:\n(13) Remove nth from end:\n");
		cout << "(14) Remove duplicates from linked list after sort:\n(15) Delete alternate nodes:\n";
		cout << "(16) Add 2 numbers with digits in node:\n" << "(17) Reverse a list:\n" << "(18) Detect loop:" << endl;
		cout << "(19) Concatenate list:\n" << "(20) Swap nodes: " << endl;
		cin >> op2;
		fflush(stdin);
		
		switch(op2){
			case 1:
			{
				printf("Elements of the list:\n");
				showAll(&p);
				break;
			}
			case 2:
			{
				int k=countEleLL(&p);
				while(k>0){
					sortAsc(&p);
					k--;
				}
				printf("Sorted list:\n");
				showAll(&p);
				break;
			}
			case 3:
			{
				int count;
				count=countEleLL(&p);
				printf("\nTotal no. of elements : %d\n",count);
				break;
			}
			case 4:
			{
				int num;
				int n;
				
				printf("Enter target element:\n");
				scanf("%d",&n);
				printf("Enter element to be added:\n");
				scanf("%d",&num);
				fflush(stdin);
				printf("\n");
				addAfter(&p,n,num);
				printf("List after addition:\n");
				showAll(&p);
				
				break;
			}
			case 5:
			{
				int tar;
				
				printf("Enter element to be deleted:\n");
				scanf("%d",&tar);
				deleteListNode(&p,tar);
				printf("\nList after element deletion:\n");
				showAll(&p);
				break;
			}
			case 6:
			{
				int tar;
				int num;
				
				printf("Enter target element:\n");
				scanf("%d",&tar);
				printf("Enter element to be inserted:\n");
				scanf("%d",&num);
				addBefore(&p,tar,num);
				printf("List after adding element:\n");
				printf("\n");
				showAll(&p);
				
				break;
			}
			case 7:
			{
				int index;
				
				printf("Enter index:\n");
				scanf("%d",&index);
				int result=getNthNode(&p,index);
				showAll(&p);
				printf("Element at nth index : %d \n", result);
				break;
			}
			case 8:
			{
				int index;
				
				printf("Enter index from the end:\n");
				scanf("%d",&index);
				int res=getNthNode(&p,(countEleLL(&p)-1)-index);
				showAll(&p);
				printf("Element at index %d from end : %d\n",index,res);
				break;
			}
			case 9:
			{
				int res;
				res=getMiddleEle(&p);
				showAll(&p);
				printf("Middle element of list : %d\n",res);
				break;
			}
			case 10:
			{
				ListNode *p1;
				copyList(&p,&p1);
				printf("Original list:\n");
				showAll(&p);
				printf("Copied list:\n");
				showAll(&p1);
				break;
			}
			case 11:
			{
				cout << "Enter other list:" << endl;
				int num;
				int option;
				ListNode* other=NULL;
				do{
					printf("Enter element:\n");
					cin >> num;
					cin.clear();
					fflush(stdin);
					append(&other,num);
					
					printf("Enter more (1-Yes, 0-No) ?\n");
					cin >> option;
					cin.clear();
					fflush(stdin);
				}while(option != 0);	
				
				showAll(&p);
				showAll(&other);
				
				ListNode* mergedList = mergeTwoLists(p,other);
				showAll(&mergedList);
				mergedList = erase(&mergedList);
				
				break;
			}
			case 12:
			{
				bool ans = isPalindrome(p);
				cout << bool(ans) << endl;
				break;
			}
			case 13:
			{
				int B;
				cout << "Enter n:\n" << endl;
				cin >> B;
				p=removeNthFromEnd(p,B);

				showAll(&p);
				break;
			}
			case 14:
			{
				int k=countEleLL(&p);
				while(k>0){
					sortAsc(&p);
					k--;
				}
				p=deleteDuplicates(p);
				showAll(&p);
				break;
			}
			case 15:
			{
				p=deleteAlternateNode(p);
				showAll(&p);
				break;
			}
			case 16:
			{
				cout << "Enter other list:" << endl;
				int num;
				int option;
				ListNode* other=NULL;
				do{
					printf("Enter element:\n");
					cin >> num;
					cin.clear();
					fflush(stdin);
					append(&other,num);
					
					printf("Enter more (1-Yes, 0-No) ?\n");
					cin >> option;
					cin.clear();
					fflush(stdin);
				}while(option != 0);	
				
				showAll(&p);
				showAll(&other);
				
				ListNode *added_list = addTwoNumbers(p,other);
				showAll(&added_list);
				added_list = erase(&added_list);
				break;
			}	
			case 17:
			{
				p=reverseList(p);
				cout << "Reverse: " << endl;
				showAll(&p);
				break;
			}
			case 18:
			{
				cout << hasCycle(p) << endl;
				break;
			}
			case 19:
			{
				cout << "Enter other list:" << endl;
				int num;
				int option;
				ListNode* other=NULL;
				do{
					printf("Enter element:\n");
					cin >> num;
					cin.clear();
					fflush(stdin);
					append(&other,num);
					
					printf("Enter more (1-Yes, 0-No) ?\n");
					cin >> option;
					cin.clear();
					fflush(stdin);
				}while(option != 0);
				
				cout << "Press 1 to concatenate second after first/ 0 otherwise:" << endl;
				int _op;
				cin >> _op;
				if(_op==1){
					p = concat(p,other);
				}
				else{
					p = concat(other,p);
				}
				
				cout << "Resultant list: " << endl;
				showAll(&p);
				break;
			}
			case 20:
			{
				int key1;
				int key2;
				printf("Enter elements to be swapped\n");
				cin >> key1 >> key2;
				
				swapNode(&p,key1,key2);
				printf("List after swapping\n");
				showAll(&p);
				break;
			}							
			default:
			{
				break;
			}
		}
		
		fflush(stdin);
		printf("\nPerform more operation (1-yes/0-no):\n");
		cin >> ch1;
		fflush(stdin);
	}while(ch1 != 0);
	
	p = erase(&p);
}
