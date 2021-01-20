#include <stdio.h>
#include "linkedlist.h"

int main(int argc,char *argv[]){
	FILE *fptr;
	
	fptr = fopen(argv[1],"r");

	int el;
	
	linkedlist head = newll();

	while(fscanf(fptr,"%d\n",&el) != EOF){
		insertFirst(&head,el);
		//printf("%d",el);
	}
	
	fclose(fptr);
	
	printf("Original list\n");
	printList(&head);
	
	deleteFirst(&head);
	printf("List after deleting first element\n");
	printList(&head);
	
	printf("%d\n",search(&head,45));
	printf("%d\n",search(&head,17));

	node *ans=delete(&head, 49);
	if(ans == NULL){
		printf("Element not found\n");
	}
	else	printf("%d node deleted\n",ans->element);
	printf("List after deletion\n");
	printList(&head);

	node *ans1=delete(&head,99);
	if(ans1==NULL)	printf("Element not found\n");
	else	printf("%d node deleted\n",ans1->element);
	printf("List after deleteion\n");
	printList(&head);

	node *ans2=delete(&head,2);
	if(ans2==NULL)	printf("Element not found\n");
	else	printf("%d node deleted\n",ans2->element);
	printf("List after deletion\n");
	printList(&head);
}
