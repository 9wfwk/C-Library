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

void DFS(treeNode *root, string str, map<char,string> &mp){
    if(root->left==NULL && root->right==NULL){
        mp.insert(make_pair(root->data->first, str));
        return;
    }
    DFS(root->left, str+'0', mp);
    //str.pop_back();
    DFS(root->right, str+'1', mp);
    //str.pop_back();
}

map<char, string> huffman(treeNode *root){
    string str;
    map<char, string> mp;
    DFS(root, str, mp);

    return mp;
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
    
    // sort(mp, mp+26, compare); No need to sort here.
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

string encoder(map<char, string> huffman_codes, string message){
    string encoded = string();
    for(int i=0; i<message.size(); ++i){
        encoded += huffman_codes[message[i]];
        // encoded = encoded +","+ huffman_codes[message[i]];
    }
    // encoded.erase(0,1);
    return encoded;
}

// string decoder(string str, priority_queue<treeNode *, vector<treeNode*>, compare_pair> &pq){
//     string msg = string();
//     treeNode *root = pq.top();

//     cout << "CCCCCCCCC" << endl;

//     int i=0;
//     while(i<str.size()){
//         if(str[i]=='0'){
//             root = root->left;
//         }
//         else{
//             root = root->right;
//         }
//         ++i;

//         if(root->left==NULL && root->right==NULL){
//             cout << "Reached: " << root->data->first << endl;
//             msg += root->data->first;
//             root = pq.top();
//         }
//     }

//     cout << "message: " << msg << endl;

//     return msg;
// }

// string decoding_process(string &str, string &msg){
//     cout << "DDDDDD" << endl;
//     pair<char,int> *mp = processMessage(msg);
//     cout << "EEEEEE" << endl;

//     priority_queue< treeNode*, vector<treeNode*>, compare_pair> pq;
//     for(int i=0; i<26; ++i){
//         cout << "FFFFFF" << endl;
//         if(mp[i].second > 0){
//             cout << "GGGGGG" << endl;
//             treeNode *newTN = newTreeNode(mp[i]);
//             pq.push(newTN);
//         }
//     }


//     huffmanTreeFormation(pq);
//     //map<char, string> huffman_codes = huffman(pq.top());

//     string message = decoder(str, pq);
//     return message;
// }

int main(){
    string str;
    cout << "Enter message: " << endl;
    cin >> str;
    toUpperMy(str);

    cout << "Your message: " << str << endl;

    pair<char,int> *mp = processMessage(str);
    //priority_queue< pair<char, int>, vector<pair<char, int>>, compare_greater> pq;
    //printMap(mp, 26);

    priority_queue< treeNode*, vector<treeNode*>, compare_pair> pq;
    int tot_freq = 0;
    for(int i=0; i<26; ++i){
        if(mp[i].second > 0){
            // cout << "AAAA: " << mp[i].second << endl;
            tot_freq += mp[i].second;
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
    cout << endl;
    levelTrav(pq.top());
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    map<char, string> huffman_codes = huffman(pq.top());

    cout << "-----------------------------------Generated Huffman codes----------------------------------------------" << endl;
    cout << endl;
    map<char, string>::iterator it;
    for(it = huffman_codes.begin(); it!=huffman_codes.end(); ++it){
        cout << it->first << " ::: " << it->second << endl;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    
    cout << "-----------------------------------Encoded Huffman String-----------------------------------------------" << endl;
    cout << endl;
    string encoded = encoder(huffman_codes, str);
    cout << encoded << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    double avg_bit_len = 0.00;
    int sum_bit_len = 0;
    for(it = huffman_codes.begin(); it!=huffman_codes.end(); ++it){
        cout << "frequency of " << it->first << " : " << mp[int(it->first)-65].second << endl;
        sum_bit_len += (it->second).size() * mp[int(it->first)-65].second;
    }

    cout << "-----------------------------------Statistics-----------------------------------------------------------" << endl;
    cout << endl;
    cout << "Sum of bit lengths of huffman codes: " << sum_bit_len << endl;
    cout << "Total frequency of all characters: " << tot_freq << endl;
    avg_bit_len = double(sum_bit_len)/tot_freq;

    cout << "Average bit length of Huffman codes: " << avg_bit_len << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
}