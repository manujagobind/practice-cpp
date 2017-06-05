#include <iostream>
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

int height(Node *root){
	if(root==NULL)
		return -1;
	return 1 + max(height(root->left), height(root->right));
}

void printLevel(Node* root, int level){
	if(root){
		if(level == 0)
			cout << root->data << " ";
		else if (level>0){
			printLevel(root->left, level-1);
			printLevel(root->right, level-1);
		}
	}
}

void levelOrder(Node *root){
	int h = height(root);
	for(int i=0;i<=h;i++)
		printLevel(root, i);		
}

int main(){

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	levelOrder(root);
	return 0;
}
