#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int data){
		this->data = data;
		left = right = NULL;
	}
};

class BST{
	Node *root;
	Node* insert(Node*, int);
	void destroy(Node*);
	int get_count(Node*, int, int);
public:
	BST();
	~BST();
	void insert(int);
	int get_count(int, int);
};

BST::BST(){
	root = NULL;
}

BST::~BST(){
	destroy(root);
	root = NULL;
}

void BST::destroy(Node *node){
	if(node){
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

Node* BST::insert(Node *node, int data){
	if(!node) node = new Node(data);
	else if(data < node->data) node->left = insert(node->left, data);
	else node->right = insert(node->right, data);
	return node;
}

void BST::insert(int data){
	root = insert(root, data);
}

int BST::get_count(Node *node, int L, int R){
	if(!node) 
		return 0;
	else if(node->data >= L and node->data <= R) // If node->data is in range, add 1 to total count and check for more nodes in both subtrees
		return 1 + get_count(node->left, L, R) + get_count(node->right, L, R);
	else if(node->data < L) // If node->data is below the range, check in right subtree
		return get_count(node->right, L, R);
	else // If node->data is above the range, check in left subtree
		return get_count(node->left, L, R);
}

int BST::get_count(int L, int R){
	return get_count(root, L, R);
}

int main(){

	BST bst;
	
	int A[] = {3, 22, 13, 10, 33};
	int L = 2, R = 11;
	int N = sizeof(A) / sizeof(A[0]);

	for(int a : A)	bst.insert(a);

	cout << bst.get_count(L, R) << endl;

	return 0;
}
