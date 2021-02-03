#include "Huffman_coding.h"

// /* Print nodes at a given level */
// void printGivenLevel(treeNode* root, int level){ 
//     if (root == NULL) 
//         return; 
//     if (level == 1) 
//         cout << root->data->first << " " << root->data->second << endl; 
//     else if (level > 1) 
//     { 
//         printGivenLevel(root->left, level-1); 
//         printGivenLevel(root->right, level-1); 
//     } 
// } 
 
// int height(treeNode* node){ 
//     if (node == NULL) 
//         return 0; 
//     else
//     { 
//         /* compute the height of each subtree */
//         int lheight = height(node->left); 
//         int rheight = height(node->right); 
 
//         /* use the larger one */
//         if (lheight > rheight) 
//             return(lheight + 1); 
//         else return(rheight + 1); 
//     } 
// }

// void levelTrav(treeNode* root){ 
//     int h = height(root); 
//     int i; 
//     for (i = 1; i <= h; i++) 
//         printGivenLevel(root, i); 
// } 

void DFS(treeNode *root, string str, vector<pair<char,string>> &vec){
    if(root->left==NULL && root->right==NULL){
        vec.push_back(make_pair(root->data->first, str));
        return;
    }
    DFS(root->left, str+'0', vec);
    //str.pop_back();
    DFS(root->right, str+'1', vec);
    //str.pop_back();
}

vector<pair<char, string>> huffman(treeNode *root){
    string str;
    vector<pair<char, string>> vec;
    DFS(root, str, vec);

    return vec;
}

void levelTrav(treeNode *root){
	if(root==NULL)
		return;
	else{
		queue<treeNode *> Q;
		Q.push(root);
		while( !Q.empty()){
			treeNode *curr=Q.front();
			cout << " " << curr->data->first << " ::: " << curr->data->second << endl;
			if(curr->left != NULL)
				Q.push(curr->left);
			if(curr->right != NULL)
				Q.push(curr->right);
			
			Q.pop();
		}
	}
}

void postOrder(const treeNode *root){
    if(root==NULL){
        // cout << "-----------------------------------------------------" << endl;
        return;
    }

    cout << root->data->first << " " << root->data->second << endl;// << ":" << root->left << " " << root->right;
    //cout << root->data->first << " " << root->data->second;// << ":" << root->left << " " << root->right;
    postOrder(root->left);
    postOrder(root->right);
}

treeNode *newTreeNode(pair<char,int> &query){
    treeNode *newTN = new treeNode();
    newTN->left = NULL;
    newTN->right = NULL;

    pair<char,int> *p1 = new pair<char,int>[1];
    p1->first = query.first;
    p1->second = query.second;
    newTN->data = p1;

    return newTN;
}

bool compare_pair::operator()(treeNode *p1, treeNode *p2){
    return p1->data->second > p2->data->second;
}

void printPQ(priority_queue<treeNode*, vector<treeNode*>, compare_pair> pq){
    while(!pq.empty()){
        cout << (pq.top()->data)->first << " : " << (pq.top()->data)->second << "--" << (pq.top()->left) << " " << pq.top()->right << endl;
        pq.pop();
    }
    cout << endl;
}

void printArr(int *arr, int size){
    for(int i=0; i<size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printMap(pair<char,int> *mp, int size){
    for(int i=0; i<size; ++i){
        cout << char(mp[i].first) << " : " << mp[i].second << endl;
    }
}

bool compare(pair<char, int> &p1, pair<char, int> &p2){
    return p1.second < p2.second;
}

pair<char,int> *processMessage(string &str){
    int *arr = new int[26];
    for(int i=0; i<26; ++i){
        arr[i] = 0;
    }

    for(int i=0; i<str.size(); ++i){
        ++arr[str[i]-65];
    }
    //printArr(arr, 26);

    pair<char,int> *mp = new pair<char,int>[26]; // ???????
    //printArr(arr, 26);
    for(int i=0; i<26; ++i){
        //cout << "character: " << char(i+65) << " ," << "count: " << arr[i] << endl;
        mp[i].first = char(i+65);
        mp[i].second = arr[i];
    }

    //printMap(mp, 26);
    
    sort(mp, mp+26, compare);
    return mp;
}

void toUpperMy(string &str){
    for(int i=0; i<str.size(); ++i){
        str[i] = toupper(str[i]);
    }
}

void huffmanTreeFormation(priority_queue< treeNode*, vector<treeNode*>, compare_pair> &pq){
    while(pq.size()>1){
        treeNode *left_t = pq.top();
        pq.pop();
        treeNode *right_t = pq.top();
        pq.pop();

        pair<char, int> parent;
        parent.first = '-';
        parent.second = (left_t->data->second) + (right_t->data->second);

        treeNode *parent_t = newTreeNode(parent);
        parent_t->left = left_t;
        parent_t->right = right_t;
        pq.push(parent_t);
    }
}

int main(){
    string str;
    cout << "Enter message in caps: " << endl;
    cin >> str;
    toUpperMy(str);

    cout << str << " " << endl;

    pair<char,int> *mp = processMessage(str);
    //priority_queue< pair<char, int>, vector<pair<char, int>>, compare_greater> pq;
    //printMap(mp, 26);

    priority_queue< treeNode*, vector<treeNode*>, compare_pair> pq;
    for(int i=0; i<26; ++i){
        if(mp[i].second > 0){
            // cout << "AAAA: " << mp[i].second << endl;
            treeNode *newTN = newTreeNode(mp[i]);
            pq.push(newTN);
        }
    }

    //printPQ(pq);
    huffmanTreeFormation(pq);
    // cout << pq.top()->data->first << " " << pq.top()->data->second << endl;
    // cout << pq.top()->left->data->first << " " << pq.top()->right->data->second << endl;
    // postOrder(pq.top());

    cout << "-----------------------------------Huffman Tree Level Order Traversal-----------------------------------" << endl;
    levelTrav(pq.top());
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    vector<pair<char, string>> huffman_codes = huffman(pq.top());

    cout << "-----------------------------------Generated Huffman codes----------------------------------------------" << endl;
    for(int i=0; i<huffman_codes.size(); ++i){
        cout << huffman_codes[i].first << " ::: " << huffman_codes[i].second << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
}