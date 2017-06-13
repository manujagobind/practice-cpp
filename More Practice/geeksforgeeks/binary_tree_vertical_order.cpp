#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int);
};

Node::Node(int data){
	this->data = data;
	left = right = NULL;
}

class BinaryTree{
	Node* root;
	void findMinMax(Node*, int*, int*, int);
	void printVerticalLine(Node*, int, int);
	void destroy(Node*);
public:
	BinaryTree(Node*);
	~BinaryTree();
	void verticalOrder();
};

BinaryTree::BinaryTree(Node* root){
	this->root = root;
}

BinaryTree::~BinaryTree(){
	destroy(root);
	root = NULL;
}

void BinaryTree::findMinMax(Node *node, int *min, int *max, int hd){
	if(!node)
		return;

	if(hd < *min)
		*min = hd;
	else if(hd > *max)
		*max = hd;

	findMinMax(node->left, min, max, hd-1);
	findMinMax(node->right, min, max, hd+1);
}

void BinaryTree::printVerticalLine(Node *node, int line_no, int hd){
	if(!node)
		return;
	
	if(hd == line_no)
		cout << node->data << " ";

	printVerticalLine(node->left, line_no, hd-1);
	printVerticalLine(node->right, line_no, hd+1);
}

void BinaryTree::verticalOrder(){
	int min = INT_MAX;
	int max = INT_MIN;
	findMinMax(root, &min, &max, 0);

	for(int line_no = min; line_no <= max; ++line_no){
		printVerticalLine(root, line_no, 0);
		cout << endl;
	}
}

void BinaryTree::destroy(Node *node){
	if(node){
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

int main(){
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->left->right = new Node(8);
	root->right->right->right = new Node(9);

	BinaryTree tree(root);
	tree.verticalOrder();
	return 0;
}
