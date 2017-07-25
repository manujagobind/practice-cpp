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

Node* construct(int preorder[], int size){

	stack<Node*> S;
	Node *root = new Node(preorder[0]);
	S.push(root);

	int i; Node *temp;
	for(i=1; i<size; ++i){
		temp = NULL;
		while(!S.empty() and preorder[i] > S.top()->data){
			temp = S.top();
			S.pop();
		}
		if(temp){
			temp->right = new Node(preorder[i]);
			S.push(temp->right);
		} else{
			S.top()->left = new Node(preorder[i]);
			S.push(S.top()->left);
		}
	}
	return root;
}

void inorder(Node *node){
	if(node){
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}
}

int main(){

	int preorder[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof(preorder) / sizeof(preorder[0]);
	Node *root = construct(preorder, size);
	inorder(root);
	cout << endl;
	return 0;
}
