#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<sys/time.h>

using namespace std;

struct TreeNode{
	TreeNode *left;
	int val;
	TreeNode *right;
};

struct min_max{
	int min;
	int max;
	int flag;
};

static TreeNode *pre;
static std::vector<int> myVec;

#define maxi(a,b) (a>b ? a+1:b+1)

TreeNode* invertTree(TreeNode* A);
int diameterOfBinaryTree(TreeNode *root);
void insert(TreeNode **rootp, int ele);
void inorder(TreeNode *root);
void preorder(TreeNode *root);
void postorder(TreeNode *root);
bool searchbst(TreeNode *root,int tar);
bool deletebnode(TreeNode **rootp, int tar);
void insertTree(TreeNode **rootp, TreeNode *tree);
void minMaxBST(TreeNode *root, min_max *p);
void initminmax(min_max *p);
int heightBst(TreeNode *root);
void levelTrav(TreeNode *root);
TreeNode *deleteNode(TreeNode *root, int key);
TreeNode *findMax(TreeNode *root);
TreeNode *findMin(TreeNode *root);
int InOrderSucc(TreeNode *root, int key);
void BstToArr(TreeNode *root);
TreeNode *returnSuccessor(TreeNode *root, int key);
TreeNode *Find(TreeNode *root, int key);
TreeNode *returnPredecessor(TreeNode *root, int key);

int main(){
	char ch;
	TreeNode *root=NULL;
	int n,ele;

	cout << "Enter no. of elements: " << endl;
	cin >> n;
	while(n>0){
		cout << "Enter element: " << endl;
		cin >> ele;
		insert(&root,ele);
		--n;
	}

	sos:
	{
		std::cout << "Enter elements in tree (y/n):" << std::endl;
		
		std::cin >> ch;
		std::cin.clear();
		fflush(stdin);
		
		if(ch != 'n'){
			std::cout << "Enter element:" << std::endl;
			int ele;
			
		// Below is the code to clear input buffer for std::cin 	
			std::cin >> ele;
			std::cin.clear();
			fflush(stdin);
			
			insert(&root, ele);
			goto sos;
		}
	}
	
	int op;
	sos1:
	{
		std::cout << "Perform operation (y/n):" << std::endl;
		std::cin >> ch;
		std::cin.clear();
		fflush(stdin);
		if(ch != 'n'){
			printf("(1)In order traversal:\n(2)Pre-order traversal:\n(3)Post-order traversal:\n(4)Insert more element:\n");
			printf("(5)Search element in BST:\n(6)Delete a node in BST:\n(7)Height of BST:\n(8)Find min. and max. element:\n");
			std::cout << "(9)Level-order traversal:\n" << "(10)Find inorder successor:\n" << "(11)Find inorder predecessor:" << std::endl;
			cout<<"(12)Find diameter:"<<"\n(13)Invert tree:"<<endl;
			std::cin >> op;
			std::cin.clear();
			fflush(stdin);
			
			switch(op){
				case 1:
				{
					std::cout << "Root element : " << root->val << std::endl;
					std::cout << "[ ";
					inorder(root);
					std::cout << " ]" << std::endl;
					break;
				}
				case 2:
				{
					printf("Root element: %d\n",root->val);
					printf("\n[ ");
					preorder(root);
					printf(" ]\n");
					break;
				}
				case 3:
				{
					printf("Root element: %d\n",root->val);
					printf("\n[ ");
					postorder(root);
					printf(" ]\n");
					break;
				}
				case 4:
				{
					printf("Enter element:\n");
					int ele;
					scanf("%d",&ele);
					fflush(stdin);
					insert(&root,ele);
					break;
				}
				case 5:
				{
					int tar;
					printf("Enter target element:\n");
					scanf("%d",&tar);
					fflush(stdin);
					bool ans=searchbst(root,tar);
					if(ans)
						printf("Target element present.\n\n");
					else
						printf("Target not found.\n\n");
					break;
				}
				case 6:
				{
					int tar;
					printf("Enter element to be deleted:\n");
					scanf("%d",&tar);
					fflush(stdin);
					if((bool)deleteNode(root,tar))
						printf("Deleted node: %d\n\n",tar);
					else
						printf("Node not found.\n\n");
					break;
				}
				case 7:
				{	
					struct timeval t1,t2;
					double elapsedTime;
					gettimeofday(&t1,NULL);
					int ht=heightBst(root);
					gettimeofday(&t2,NULL);
					printf("Height of BST : %d\n",ht);
					break;
				}
				case 8:
				{
					min_max  m;
					initminmax(&m);
					minMaxBST(root,&m);
					printf("Minimum element: %d\nMaximum element: %d\n",m.min,m.max);
					break;
				}
				case 9:
				{
					std::cout << "[ ";
					levelTrav(root);
					std::cout << " ]" << std::endl;
					break;
				}
				case 10:
				{
					int tar;
					std::cout << "Enter target element:" << std::endl;
					std::cin >> tar;
					std::cin.clear();
					fflush(stdin);
					TreeNode *suc=returnSuccessor(root, tar);
					if(suc==NULL){
						std::cout << "The target has no inorder successor element." << std::endl;
					}
					else{
						std::cout << "Inorder successor of " << tar << " is: " << suc->val << std::endl;
					}
					break;
				}
				case 11:
				{
					int tar;
					std::cout << "Enter target element:" << std::endl;
					std::cin >> tar;
					std::cin.clear();
					fflush(stdin);
					TreeNode *pred=returnPredecessor(root, tar);
					if(pred==NULL)
						std::cout << "No inorder predecessor." << std::endl;
					else
						std::cout << "Inorder predecessor of " << tar << " is: " << pred->val << std::endl;
					break;
				}
				case 12:
				{
					cout << "Diameter of BST: " << diameterOfBinaryTree(root) << endl;
					break;
				}
				case 13:
				{
					root=invertTree(root);
					levelTrav(root);
					printf("\n");
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
	
	return 0;
}

//Invert BST-->


TreeNode* invertTree(TreeNode* A){
	if((A->left == NULL && A->right==NULL)||A==NULL){
		return A;
	}
	else{
		printf("A-left : %p\nA right %p\n",A->left,A->right);
		TreeNode* temp=A->left;
		A->left=A->right;
		A->right=temp;
		printf("A-left : %p\nA right %p\n",A->left,A->right);
		levelTrav(A);
		printf("\n");
		if(A->left != NULL)
			invertTree(A->left);
		if(A->right != NULL)
			invertTree(A->right);

		return A;
	}
}
//Find BST diameter-->


int diameterOfBinaryTree(TreeNode *root){
	if(root==NULL){
		return 1;
	}
	int diar = heightBst(root->left) + heightBst(root->right);
	int dia1 = diameterOfBinaryTree(root->left);
	int dia2 = diameterOfBinaryTree(root->right);

	return (diar>dia1?((diar>dia2)?diar:dia2):(dia1>dia2)?dia1:dia2);
}

//Function to insert a node in tree -->


void insert(TreeNode **rootp, int ele){
	TreeNode *temp=*rootp;
	
	if(temp==NULL){
		TreeNode *r=new(std::nothrow) TreeNode;
		r->val=ele;
		r->left=NULL;
		r->right=NULL;
		*rootp=r;
	}
	else if(ele > temp->val)
		insert(&(temp->right),ele);
	else if(ele <= temp->val)
		insert(&(temp->left),ele);
}


//Function to perform inorder traversal -->


void inorder(TreeNode *root){
	if(root != NULL){
		inorder(root->left);
		printf(" %d ",root->val);
		inorder(root->right);
	}
	else
		return;
}


//Function to perform preorder traversal of tree -->


void preorder(TreeNode *root){
	if(root != NULL){
		printf(" %d ",root->val);
		preorder(root->left);
		preorder(root->right);
	}
	else
		return;
}


//Function to perform postorder traversal of tree -->


void postorder(TreeNode *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf(" %d ",root->val);
	}
	else
		return;
}


//Function to search any element in BST -->


bool searchbst(TreeNode *root, int tar){
	TreeNode *temp=root;
	if(temp==NULL){
		return false;
	}
	else if(temp->val==tar)
		return true;
	else{
		if(tar > temp->val){
			searchbst(temp->right, tar);
		}
		else if(tar <= temp->val){
			searchbst(temp->left, tar);
		}
	}
}


//Function to delete a node from BST -->


bool deletebnode(TreeNode **rootp, int tar){
	TreeNode *temp=*rootp;
	
	if(temp==NULL)
		return false;
	else if(temp->val==tar){
		TreeNode *peel=temp->left;
		TreeNode *peer=temp->right;
		
		delete temp;
		temp=NULL;
		*rootp=NULL;
		insertTree(&pre,peel);
		insertTree(&pre,peer);
		
		return true;
	}
	else if(tar < temp->val){
		pre=temp;
		deletebnode(&(temp->left),tar);
	}
	else if(tar > temp->val){
		pre=temp;
		deletebnode(&(temp->right),tar);
	}
}


//Function to insert an entire tree in another tree -->


void insertTree(TreeNode **rootp, TreeNode *tree){
	if(tree != NULL){
		insertTree(rootp, tree->left);
		insert(rootp, tree->val);
		insertTree(rootp, tree->right);
	}
	else 
		return;
}


//Function to initialise min_max struct variable -->


void initminmax(min_max *p){
	p->min=1;
	p->max=0;
	p->flag=1;
}


//Function to find minimum and maximum element in a BST -->


void minMaxBST(TreeNode *root, min_max *p){
	if(root==NULL)
		return;
	else{
		if(root->left != NULL && p->flag)
			minMaxBST(root->left,p);
		else if(p->flag){
			p->min=root->val;
			p->flag=0;
		}
		
		if(root->right != NULL)
			minMaxBST(root->right,p);
		else
			p->max=root->val;
		
		return;
	}
}


//Function to find height of a binary tree -->


int heightBst(TreeNode *root){
	if(root==NULL)
		return 0;
	return (maxi(heightBst(root->left),heightBst(root->right)));
}


//Function to perform level order traversal of a tree -->


void levelTrav(TreeNode *root){
	if(root==NULL)
		return;
	else{
		std::queue<TreeNode *> Q;
		Q.push(root);
		while( !Q.empty()){
			TreeNode *curr=Q.front();
			std::cout << " " << curr->val << " ";
			if(curr->left != NULL)
				Q.push(curr->left);
			if(curr->right != NULL)
				Q.push(curr->right);
			
			Q.pop();
		}
	}
}


//Delete node in a BST optimally -->

/* The function returns the new root of the sub-tree whose head node is the node which is to be deleted.
 * The node to be deleted is considered a tree and the function returns the new head of the sub-tree after
 * node deletion.
*/

TreeNode *deleteNode(TreeNode *root, int key){
	if(root==NULL)
		return root;
	else if(key < root->val)
		root->left=deleteNode(root->left,key);
	else if(key > root->val)
		root->right=deleteNode(root->right, key);
	else{
		if(root->left==NULL && root->right==NULL){
			delete root;
			root=NULL;
		}
		else if(root->left==NULL){
			TreeNode *temp=root;
			root=root->right;
			delete temp;
			temp=NULL;
		}
		else if(root->right==NULL){
			TreeNode *temp=root;
			root=root->left;
			delete temp;
			temp=NULL;
		}
		else{
			TreeNode *temp=findMax(root->left);
			root->val=temp->val;
			root->left=deleteNode(root->left,root->val);
		}
	}
	return root;
}


//Function to find maximum in a tree -->


TreeNode *findMax(TreeNode *root){
	if(root==NULL)
		return NULL;
	else{
		while(root->right != NULL)
			root=root->right;
	}
	
	return root;
}


//Function to find minimum element in a tree -->


TreeNode *findMin(TreeNode *root){
	if(root==NULL)
		return NULL;
	else{
		while(root->left != NULL)
			root=root->left;
	}
	
	return root;
}


//Function to find inorder successor of any element in a BST -->


int InOrderSucc(TreeNode *root, int key){
	BstToArr(root);
	std::vector<int>::iterator it;
	std::vector<int>::iterator it1=std::find(myVec.begin(), myVec.end(), key);
	
	if( it1 != myVec.end() && it != myVec.end()-1 ){
		return *(it1+1);
	}
	else
		return -1;
}


//Function to add elements of BST to a vector -->


void BstToArr(TreeNode *root){
	if(root != NULL){
		BstToArr(root->left);
		myVec.push_back(root->val);
		BstToArr(root->right);
	}
}


//Function to get inorder successor- O(height of tree) -->


TreeNode *returnSuccessor(TreeNode *root, int key){
	TreeNode *curr=Find(root, key);
	
	if(curr==NULL)
		return NULL;
	if(curr->right != NULL){
		return findMin(curr->right);
	}
	else{
		TreeNode *successor=NULL;
		TreeNode *ancestor=root;
		
		while(ancestor != curr){
			if(key <= ancestor->val){
				successor=ancestor;
				ancestor=ancestor->left;
			}
			
			else{
				ancestor=ancestor->right;
			}
		}
		
		return successor;
	}
}


//Function to return TreeNode corresponding to a given key -->


TreeNode *Find(TreeNode *root, int key){
	if(root==NULL)
		return NULL;
	else if(root->val > key){
		TreeNode *ans=Find(root->left,key);
		return ans;
	}
	else if(root->val < key){
		TreeNode *ans=Find(root->right, key);
		return ans;
	}
	
	else
		return root;
}


//Function to return inorder predecessor of TreeNode -->


TreeNode *returnPredecessor(TreeNode *root, int key){
	TreeNode *curr=Find(root, key);
	
	if(curr==NULL)
		return NULL;
	else{
		if(curr->left != NULL)
			return findMax(curr->left);
		else{
			TreeNode *pred=NULL;
			TreeNode *anc=root;
			
			while(anc != curr){
				if(key > anc->val){
					pred=anc;
					anc=anc->right;
				}
				else
					anc=anc->left;
			}
			
			return pred;
		}
	}
}
