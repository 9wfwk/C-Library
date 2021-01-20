#include <bits/stdc++.h>
#include <unistd.h>

enum color_t{BLACK, RED};

struct Node{
	Node *p;
	Node *l;
	Node *r;
	color_t color;
	int key;

	Node(int x) : key(x), p(NULL), l(NULL), r(NULL), color(RED){}
};

struct RBT{
	Node *root;
	RBT(): root(NULL){}
};

using namespace std;

vector<string> vec;

Node* GetParent(Node *n);
Node* GetGrandParent(Node *n);
Node* GetSibling(Node *n);
Node* GetUncle(Node *n);
void RotateLeft(Node *n);
void RotateRight(Node *n);
Node* Insert(Node* root, Node* n);
void InsertRecurse(Node *root,Node* n);
void InsertRepairTree(Node *n);
void InsertCase3(Node *n);
void InsertCase4(Node *n);
void InsertCase4Step2(Node *n);

void levelTrav(Node *n);
void Inorder(Node *n);

int main(){
	vec.push_back("B");
	vec.push_back("R");
	
	int num,el;
	RBT* rbt = new RBT();
	cout << "Enter no. of elements: " << endl;
	cin >> num;
	Node *rt=NULL;
	Node *n=NULL;

	rbt->root = rt;
	
	cout << "Enter elements:" << "\n";
	for(int i=0; i<num; ++i){
		cout << "i: " << i << "\n";
		cin >> el;
		n=new Node(el);
		rt = Insert(rt,n);
	}

	int op;
	sos:
		cout << "Enter more (1-Yes/0-No):" << "\n";
	cin >> op;
	if(op!=0){
		cout << "Enter element: " << "\n";
		cin >> el;
		n=new Node(el);
		rt = Insert(rt,n);

		goto sos;
	}
	
	sos1:
		cout << "(1)Level Trav:\n(2)Inorder Trav:" << "\n";
	cin >> op;
	switch(op){
		case 1:
		{
			levelTrav(rt);
			break;
		}
		case 2:
		{
			Inorder(rt);
			cout << "\n";
			break;
		}
		default:
		{
			break;
		}
	}
	
	cout << "Perform operation again(1-Yes/0-No):" << "\n";
	cin >> op;
	if(op!=0){
		goto sos1;
	}
	
}

Node* GetParent(Node* n){
	//sleep(1);
	cout << "MMMM" << endl;
	Node* par;
	if(n==NULL){
		par=NULL;
	}
	else	par=n->p;

	return par;
}

Node* GetGrandParent(Node *n){
	cout << "LLLL" << endl;
	return GetParent(GetParent(n));
}

Node* GetSibling(Node *n){
	cout << "KKKK" << endl;
	Node *p=GetParent(n);
	cout << "OOOO" << endl;
	if(n==NULL || p==NULL){
		cout << "QQQQ" << endl;
		return NULL;
	}

	else{
		cout << "NNNN" << endl;
		if(p->l!=NULL && n==p->l){
			return p->r;
		}
		else if(p->r!=NULL && n==p->r){
			return p->l;
		}
	}
	cout << "PPPP" << endl;
}


Node* GetUncle(Node *n){
	cout << "JJJJ" << endl;
	Node *p=GetParent(n);

	return GetSibling(p);
}

/*
void RotateLeft(Node* n) {
  Node* nnew = n->r;
  Node* par = GetParent(n);
  assert(nnew != NULL);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.
  n->r = nnew->l;
  nnew->l = n;
  n->p = nnew;
  // Handle other child/parent pointers.
  if (n->r != NULL) {
    n->r->p = n;
  }

  // Initially n could be the root.
  if (par != NULL) {
    if (n == par->l) {
      par->l = nnew;
    } else if (n == par->r) {
      par->r = nnew;
    }
  }
  nnew->p = par;
}

void RotateRight(Node* n) {
  Node* nnew = n->l;
  Node* par = GetParent(n);
  assert(nnew != NULL);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.

  n->l = nnew->r;
  nnew->r = n;
  n->p = nnew;

  // Handle other child/parent pointers.
  if (n->l != NULL) {
    n->l->p = n;
  }

  // Initially n could be the root.
  if (par!= NULL) {
    if (n == par->l) {
      par->l = nnew;
    } else if (n == par->r) {
      par->r = nnew;
    }
  }
  nnew->p = par;
}
*/

void RotateLeft(Node *x){
	cout << "IIII" << endl;
	Node *p=GetParent(x);
	cout << "RRRR" << endl;
	
	Node *y=x->r;
	if(y==NULL || x==NULL){
		cout << "SSSS" << "\n";
		return;
	}
	
	x->r = y->l;
	if(x->r!=NULL){ //set y left child parent as x
		(x->r)->p=x;
	}
	y->l=x;
	y->p=x->p;
	x->p=y;

	if(p==NULL){;}
	else if(x==p->l)	p->l=y;
	else if(x==p->r)	p->r=y;
}

void RotateRight(Node *y){
	cout << "HHHH" << endl;
	Node *par=GetParent(y);
	Node *x=y->l;

	if(x==NULL || y==NULL)	return;

	//Make x right child y's left child
	y->l = x->r;
	if(y->l!=NULL){
		(y->l)->p=y;
	}
	x->r = y;
	x->p = y->p; //Make y's parent as x's parent
	y->p = x;

	//Handle parent node children
	if(par==NULL){;}
	else if(y==par->l)	par->l=x;
	else if(y==par->r)	par->r=x;
}


Node* Insert(Node *root, Node *n){
	cout << "GGGG" << endl;
	InsertRecurse(root,n);	

	InsertRepairTree(n);

	root = n;
	while(GetParent(root)!= NULL){
		root = GetParent(root);
	}
	return root;
}

void InsertRecurse(Node* root,Node* n){
	cout << "FFFF" << endl;
	if(root!=NULL){
		if(root->key > n->key){
			if(root->l == NULL){
				root->l=n;
			}
			else{
				InsertRecurse(root->l,n);
				return;
			}
		}
		else{
			if(root->r==NULL){
				root->r=n;
			}
			else{
				InsertRecurse(root->r,n);
				return;
			}
		}
	}

	n->p = root;
}

void InsertRepairTree(Node *n){
	cout << "AAAA" << endl;
	if(n==NULL)	return;
	else if(GetParent(n)==NULL){
		n->color=BLACK;
	}
	else if(GetParent(n)->color ==BLACK){
		return;
	}
	else if(GetUncle(n)!=NULL && GetUncle(n)->color == RED){
		InsertCase3(n);
	}
	else{
		InsertCase4(n);
	}
}

void InsertCase3(Node *n){
	cout << "BBBB" << endl;
	GetParent(n)->color = BLACK;
	GetParent(n)->color = BLACK;
	GetGrandParent(n)->color = RED;
	InsertRepairTree(GetGrandParent(n));
}

void InsertCase4(Node *n){
	cout << "CCCC" << endl;
	Node* p=GetParent(n);
	Node* g=GetGrandParent(n);

	if(n==p->r && p==g->l){
		RotateLeft(p);
		n = n->l; //Make current node as the bottom
	}
	if(n == p->l && p==g->r){
		RotateRight(p);
		n = n->r;
	}

	InsertCase4Step2(n);
}

void InsertCase4Step2(Node* n){
	cout << "DDDD" << endl;
	Node *p=GetParent(n);
	Node *g=GetGrandParent(n);

	if(p==g->l){
		RotateRight(g);
	}
	else if(p==g->r){
		RotateLeft(g);
	}

	color_t tc = p->color;
	p->color = g->color;
	g->color = tc;
}

void levelTrav(Node *root){
	cout << "EEEE" << endl;
	if(root==NULL)
		return;
	else{
		std::queue<Node *> Q;
		Q.push(root);
		while(!Q.empty()){
			Node *curr=Q.front();
			std::cout << " " << curr->key << ":" << vec[curr->color] << " ";
			if(curr->l != NULL)
				Q.push(curr->l);
			if(curr->r != NULL)
				Q.push(curr->r);
			
			Q.pop();
		}
	}
	cout << endl;
}

void Inorder(Node *root){
	if(root){
		Inorder(root->l);
		cout << " " << root->key << ":" << vec[root->color] << " ";
		Inorder(root->r);
	}
}
