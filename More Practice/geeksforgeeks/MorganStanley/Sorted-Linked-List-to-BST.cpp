#include <bits/stdc++.h>
using namespace std;

class LinkedListNode{
public:
	int data;
	LinkedListNode *next;
	LinkedListNode(int data){
		this->data = data;
		next = NULL;
	}
};

class TreeNode{
public:
	int data;
	TreeNode *left, *right;
	TreeNode(int data){
		this->data = data;
		left = right = NULL;
	}	
};

class LinkedList{
	LinkedListNode *head;
public:
	LinkedList(){
		head = NULL;
	}
	~LinkedList(){
		while(head){
			LinkedListNode *temp = head;
			head = head->next;
			delete temp;
		}
		head = NULL;
	}
	void push_front(int data){
		LinkedListNode *node = new LinkedListNode(data);
		node->next = head;
		head = node;	
	}
	int length(){
		int count = 0;
		LinkedListNode *cur = head;
		while(cur){
			++count;
			cur = cur->next;
		}
		return count;
	}
	void print(){
		LinkedListNode *cur = head;
		while(cur){
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}
	LinkedListNode* get_head(){
		return this->head;
	}
};

class BST{
	TreeNode *root;
	void destroy(TreeNode *node){
		if(node){
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
	void inorder(TreeNode *node){
		if(node){
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}
	TreeNode* construct(LinkedListNode**, int);
public:
	BST(LinkedList &list){
		int len = list.length();
		LinkedListNode *head = list.get_head();
		root = construct(&head, len);
	}
	~BST(){
		destroy(root);
		root = NULL;
	}
	void inorder(){
		inorder(root);
		cout << endl;
	}
};

TreeNode* BST::construct(LinkedListNode **head, int len){

	if(len <= 0) return NULL;

	TreeNode *left = construct(head, len/2);
	TreeNode *t_root = new TreeNode((*head)->data);

	t_root->left = left;
	*head = (*head)->next;
	t_root->right = construct(head, len - len/2 - 1);

	return t_root;
}

int main(){

	int A[] = {10, 9, 8, 7, 6, 8, 4, 3, 2, 1};

	LinkedList list;
	for(int a : A) list.push_front(a);
	
	BST bst(list);
	bst.inorder();
	return 0;
}
