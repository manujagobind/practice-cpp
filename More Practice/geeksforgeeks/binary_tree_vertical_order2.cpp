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
	void getVerticalOrder(Node*, int, map< int, vector<int> >&);
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

void BinaryTree::getVerticalOrder(Node *node, int hd, map< int, vector<int> > &m){
	if(!node)
		return;

	queue< pair<Node*, int> > q;
	q.push(make_pair(root, hd));
	
	while(!q.empty()){
		pair<Node*, int> temp = q.front();
		q.pop();
		Node *node = temp.first;
		hd = temp.second;
		
		m[hd].push_back(node->data);
		
		if(node->left)
			q.push(make_pair(node->left, hd-1));
		if(node->right)
			q.push(make_pair(node->right, hd+1));
	}
}

void BinaryTree::verticalOrder(){
	map< int, vector<int> > m;
	map< int, vector<int> >::iterator it;
	
	getVerticalOrder(root, 0, m);
	for(it = m.begin(); it != m.end(); ++it){
		int i=0, sz=it->second.size();
		for(i=0; i<sz; ++i)
			cout << it->second[i] << " ";
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
