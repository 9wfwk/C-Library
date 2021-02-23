#ifndef _HUFFMAN_CODING
#define _HUFFMAN_CODING
#include <bits/stdc++.h>

using namespace std;

struct treeNode{
    struct treeNode *left;
    pair<char,int> *data;
    struct treeNode *right;
};

typedef struct treeNode treeNode;

/* Encoder */
void encoding_process();
string encoder(map<char, string> huffman_codes, string message);

/* Huffman code generation */
void DFS(treeNode *root, string str, vector<pair<char,string>> &vec);
map<char, string> huffman(treeNode *root);

/* Huffman Tree traversal */
void postOrder(const treeNode *root);
void levelTrav(const treeNode *root);

/* Huffman Tree formation */
class compare_pair{
    public:
       bool operator()(treeNode *p1, treeNode *p2);
};

treeNode *newTreeNode(pair<char,int> &query);

void huffmanTreeFormation(priority_queue<treeNode, vector<treeNode>, compare_pair> &pq);
treeNode *newTreeNode(pair<char, int> &query);

/* String processing to frequency table functions */
void printArr(int *arr);
pair<char,int> *processMessage(string &str);
void toUpperMy(string &str);
bool compare(pair<char, int> &p1, pair<char,int> &p2);
void printMap(vector<pair<char,int>> &mp);
void printPQ(priority_queue<treeNode, vector<treeNode>, compare_pair> pq);

#endif