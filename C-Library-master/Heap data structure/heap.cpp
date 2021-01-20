#include "heap.h"

using namespace std;

void print1dArr(int *arr,int size);

int main(){
	heap h=newHeap();
	h.arr=(int*)realloc(h.arr,sizeof(int)*10);
	int full=0;
	h.arr[0]=0; //To maintain the parent child index property start the heap from index 1

	int op=1,i=1; //
	int ele;
	printf("Enter no. of elements:\n");
	scanf("%d",&ele);

	do{
		if(full==7){
			full=0;//Make full zero as extra memory has been allocated
			h.arr=(int *)realloc(h.arr,((sizeof(int))*i)+10*sizeof(int)); //Increases the size of array in each allocation by 10.
					//10*sizeof(int) is necessary, otherwise invalid next size RE is obtained.
		}

		printf("Enter %d th element:\n",i);
		scanf("%d",h.arr+i);
		++i;
		++full;
		++h.size;
		--ele; //decrease the left element to enter count

		if(ele<=0){
			printf("Enter element (1-yes/0-no):\n");
			scanf("%d",&op);
		}
	}while(op!=0 || ele>0);

	print1dArr(h.arr,h.size);

	do{
		cout << "(1)Build max heap:\n(2)Max-heapify :\n(3)Build min heap:\n(4)Min-heapify:\n(5)Heap-Sort the array:\n(6)Extract max:\n(7)Increase key:\n(8)Print heap:" << endl;
		cout << "(9)Insert into max heap:\n(10)Extract min:\n(11)Decrease key:\n(12)Insert into min heap:" << endl;
		cin >> op;
		switch(op){
			case 1:
			{
				buildMaxHeap(h);
				cout << "\n";
				printHeap(h);
				break;
			}
			case 2:
			{
				int ind;
				cout << "Enter index to be max heapified:" << endl;
				cout << "heap size: " << h.size << endl;
				cin >> ind;
				maxHeapify(h,ind);
				cout << "\n";
				printHeap(h);

				break;
			}
			case 3:
			{
				buildMinHeap(h);
				cout << "\n";
				printHeap(h);
				break;
			}
			case 4:
			{
				int ind;
				cout << "Enter index:" << endl;
				cin >> ind;
				minHeapify(h,ind);
				cout << "\n";
				printHeap(h);
				
				break;
			}
			case 5:
			{
				heapSort(h);
				print1dArr(h.arr , h.size);
				break;
			}
			case 6:
			{
				if(h.arr[1]<h.arr[2]){
					cout << "Heap is not Max heap\n";
				}

				int ans = extractMax(h);
				cout << "Extract Max: " << ans << endl;
				break;
			}
			case 7:
			{
				cout << "Enter old index: \n";
				int oldind;
				cin >> oldind;
				int newval;
				cout << "Enter new value: \n";
				cin >> newval;
				increaseKey(h,oldind,newval);
				
				printHeap(h);
				break;
			}
			case 8:
			{
				printHeap(h);
				break;
			}
			case 9:
			{
				int element;
				cout << "Enter element to be inserted\n";
				cin >> element;
				insertIntoMax(h,element);
				
				cout << endl;
				printHeap(h);
				break;
			}
			case 10:
			{
				int ans = extractMin(h);
				cout << "Min extract: " << ans << endl;
				break;
			}
			case 11:
			{
				int oldind;
				int newval;
				cout << "Enter old index:\n";
				cin >> oldind;
				cout << "Enter new value:\n";
				cin >> newval;
				
				decreaseKey(h,oldind,newval);
				cout << endl;
				printHeap(h);
				break;
				
			}
			case 12:
			{
				int element;
				cout << "Enter element to be inserted:\n";
				cin >> element;
				insertIntoMin(h,element);
				
				cout << endl;
				printHeap(h);
				break;
			}
			default:
			{
				cout << "Invalid option" << endl;
			}
		}

		cout << "Perform more op (1-yes/0-no):" << endl;
		cin >> op;

	}while(op!=0);

}

void print1dArr(int *arr,int size){
	printf("[ ");
	for(int i=1; i<=size; ++i){	//Don't print starting zero; print from index 1 till size
		printf(" %d ",*(arr+i));
	}
	printf(" ]\n");
}


void heapSort(heap h){
	int o=h.size;
	for(int i=h.size; i>0; --i){
		buildMaxHeap(h);
		h.size--;
		swapint(h.arr[1],h.arr[i]); //As root is maximum in max heap, swap it with last element of heap and buildMaxHeap on remaining
	}

	h.size=o;
}

void maxHeapify(heap h,int curr_ind){
	int left_ch = getLeftChildInd(h,curr_ind);
	int right_ch = getRightChildInd(h,curr_ind);

	int largest=curr_ind;

	if(right_ch<=h.size && h.arr[right_ch]>h.arr[largest]){ //<= because one needs to get the element at h.arr[size] also due to h.arr[0]=0
		largest=right_ch;
	}
	if(left_ch<=h.size && h.arr[left_ch]>h.arr[largest]){
		largest=left_ch;
	}

	if(largest != curr_ind){
		swapint(h.arr[largest],h.arr[curr_ind]);
		maxHeapify(h,largest);
	}
}


void swapint(int &t1, int &t2){
	int temp=t1;
	t1=t2;
	t2=temp;
}


heap newHeap(){
	heap h;
	h.arr=(int*)malloc(sizeof(int)*1);
	h.arr[0]=0;
	h.size=0;

	return h;
}


void printHeap(heap h){
	int lb2 = getLogBase2Ind(h.size);
	int i=1;
	int j=1;
	for(int k=1; k<=lb2; ++k){ //Perfom floor(log m) iteration to print these floor(log n) levels.
		int l=1; //print 2*i nodes of each level in next while loop.
		while(l<=i){
			cout << h.arr[j] << "\t";
			++l;
			++j;
		}
		cout << endl;
		i=i*2; //Exponentiate the no. of nodes in the next level of heap
	}

	//Below while loop prints the elements of the last level.
	while(j<=h.size){ // As we have added a 0 at the start, we need to go 1 extra index.
		cout << h.arr[j] << "\t";
		++j;
	}

	cout << "\n";
}

int getLeftChildInd(heap h, int index){
	if(2*index<=h.size){ //<= to consider element at index size
		return 2*index;
	}
	else{
		return INT8_MAX; //Don't return -1 as h.arr[-1]=0 and hence cretes problem in minHeapify
	}
}

int getRightChildInd(heap h, int index){
	if((2*index+1)<=h.size){ ////<= to consider element at index size
		int right_ch = 2*index+1;
		return right_ch;
	}
	else{
		return INT8_MAX; //Don't return -1 as h.arr[-1]=0 and hence creates problem in min heapify
	}
}

int getParentIndex(heap h, int index){
	return index/2;
}

int getLogBase2Ind(int num){
	int ct=0;
	while(num >= 2){
		++ct;
		num=num/2;
	}

	return ct;
}


void buildMaxHeap(heap h){
	for(int i=h.size/2; i>0; --i){
		maxHeapify(h,i);
	}
}

void buildMinHeap(heap h){
	for(int j=h.size/2; j>0; --j){
		minHeapify(h,j);
	}
}

void minHeapify(heap h, int curr_ind){
	int left_ch = getLeftChildInd(h,curr_ind);
	int right_ch = getRightChildInd(h,curr_ind);

	int smallest = curr_ind;
	if(left_ch <= h.size && h.arr[left_ch]<h.arr[smallest]){
		smallest = left_ch;
	}
	if(right_ch <= h.size && h.arr[right_ch]<h.arr[smallest]){
		smallest = right_ch;
	}

	if(smallest != curr_ind){
		swapint(h.arr[curr_ind],h.arr[smallest]);
		minHeapify(h,smallest);
	}
}


int extractMax(heap &h){
	int ans;
	if(h.arr[1] < h.arr[2]){
		cout << "Heap is not max heap" << endl;
	}
	else{
		ans = h.arr[1];
		swapint(h.arr[1],h.arr[h.size]);
		h.size--;

		maxHeapify(h,1);
	}

	return ans;
}


void increaseKey(heap h, int oldind, int newval){
	if(h.arr[oldind]>newval){
		cout << "New key is less than old key\n";
	}
	else{
		h.arr[oldind]=newval;
		while(oldind > 1 && h.arr[getParentIndex(h,oldind)] < h.arr[oldind]){
			swap(h.arr[oldind/2],h.arr[oldind]);
			oldind = oldind/2;
		}
	}
}


void insertIntoMax(heap &h, int element){
	h.arr = (int*)realloc(h.arr,sizeof(int)*(h.size+2));
	h.size++;
	h.arr[h.size]=INT8_MIN;
	increaseKey(h,h.size,element);
}


int extractMin(heap &h){
	int min;
	if(h.arr[1] > h.arr[2]){
		cout << "Heap is not min heap" << endl;
	}
	else{
		min=h.arr[1];
		swapint(h.arr[1], h.arr[h.size]);

		h.size--;

		minHeapify(h,1);
	}

	return min;
}


void decreaseKey(heap h, int oldind, int newval){
	if(h.arr[oldind] < newval){
		cout << "old value is less than new value" << endl;
	}

	else{
		h.arr[oldind]=newval;
		while(oldind>1 && h.arr[getParentIndex(h,oldind)] > h.arr[oldind]){
			swapint(h.arr[getParentIndex(h,oldind)], h.arr[oldind]);
			oldind = oldind/2;
		}
	}
}


void insertIntoMin(heap &h, int element){
	h.arr = (int*)realloc(h.arr,sizeof(int)*(h.size+2));
	h.arr[++h.size]=INT8_MAX;
	decreaseKey(h,h.size,element);
}
