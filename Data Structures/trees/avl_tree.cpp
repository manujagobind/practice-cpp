#include <iostream>
#include <climits>
using namespace std;

class TreeNode{
public:
	int data;
	int height;
	TreeNode *left, *right;
	TreeNode(int);
};

TreeNode::TreeNode(int data){
	this->data = data;
	height = 0;
	left = right = NULL;
}

class AVLTree{
	TreeNode *root;
	TreeNode* insert(TreeNode*, int);
	TreeNode* remove(TreeNode*, int);
	TreeNode* rightRotate(TreeNode*);
	TreeNode* leftRotate(TreeNode*);
	void inorder(TreeNode*) const;	
	TreeNode* minimum(TreeNode*);
public:
	AVLTree();
	void insert(int);
	void inorder() const;
	int height(TreeNode*) const;
	int get_height() const;
	int getBalance(TreeNode*) const;
	TreeNode* minimum();
	TreeNode* maximum();
	void remove(int);
};

AVLTree::AVLTree(){
	root = NULL;
}

TreeNode* AVLTree::rightRotate(TreeNode* node){

	TreeNode *pivot, *T;
	pivot = node->left;
	T = pivot->right;

	pivot->right = node;
	node->left = T;

	node->height = max(height(node->left), height(node->right)) + 1;
	pivot->height = max(height(pivot->left), height(pivot->right)) + 1;

	return pivot;
}

TreeNode* AVLTree::leftRotate(TreeNode *node){

	TreeNode *pivot, *T;
	pivot = node->right;
	T = pivot->left;

	pivot->left = node;
	node->right = T;

	node->height = max(height(node->left), height(node->right)) + 1;
	pivot->height = max(height(pivot->left), height(pivot->right)) + 1;
	return pivot;
}

TreeNode* AVLTree::insert(TreeNode *node, int data){	
	if(node == NULL) {
		node = new TreeNode(data);
	} else if (data < node->data) {
		node->left = insert(node->left, data);
	} else if (data > node->data){
		node->right = insert(node->right, data);
	} else {
		// Not adding if already present
		return node;
	}

	if(!node)
		return NULL;

	node->height = 1 + max(height(node->left), height(node->right));	
	int balance = getBalance(node);

	if(balance > 1 && data < node->left->data)
		return rightRotate(node);
	if(balance < -1 && data > node->right->data)
		return leftRotate(node);
	if(balance > 1 && data > node->left->data){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance < -1 && data < node->right->data){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}		

	return node;
}

void AVLTree::insert(int data){
	root = insert(root, data);
}

void AVLTree::inorder(TreeNode *node) const {
	if(node){
		inorder(node->left);		
		cout << node->data << " ";
		inorder(node->right);
	}
}

void AVLTree::remove(int data){
	root = remove(root, data);
}

TreeNode* AVLTree::remove(TreeNode *node, int data){

	if(!node)
		return NULL;

	if(node->data == data){		
		if(!node->left && !node->right){		
			TreeNode *temp = node;
			delete temp;
			return  NULL;
		} else if (!node->left) {			
			node = node->right;
		} else if (!node->right) {
			node = node->left;	
		} else {
			TreeNode *min = minimum(node->right);
			node->data = min->data;
			node->right = remove(root->right, min->data);
		}		
	}	 else if (data < node->data){
		node->left = remove(node->left, data);
	} else {
		node->right = remove(node->right, data);
	}

	if(!node)
		return node;	

	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);

	if(balance > 1 && getBalance(node->left) >= 0)
		return rightRotate(node);
	if(balance > 1 && getBalance(node->left) < 0){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance < -1 && getBalance(node->right) <= 0)
		return leftRotate(node);
	if(balance < -1 && getBalance(node->right) > 0){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

void AVLTree::inorder() const {
	inorder(root);
	cout << endl;
}

int AVLTree::height(TreeNode *node) const {
	if(node){
		return node->height;
	}
	return -1;
}

int AVLTree::get_height() const {
	return height(root);
}

int AVLTree::getBalance(TreeNode* node) const {
	if(node){
		return height(node->left) - height(node->right);
	}
	return 0;
}

TreeNode* AVLTree::minimum() {	
	TreeNode *cursor = root;
	while(cursor->left)
		cursor = cursor->left;
	return cursor;
}

TreeNode* AVLTree::minimum(TreeNode *node){
	while(node->left)
		node = node->left;
	return node;
}

TreeNode* AVLTree::maximum() {
	TreeNode *cursor = root;
	while(cursor->right)
		cursor = cursor->right;
	return cursor;
}

int main(){

	AVLTree tree;
	tree.insert(5);
	tree.insert(9);
	tree.insert(2);
	tree.insert(8);
	tree.insert(1);
	tree.insert(7);
	tree.insert(6);
	tree.insert(3);
	tree.insert(4);
	cout << "Height:\t" << tree.get_height() << endl;
	tree.remove(5);
	cout << "Height:\t" << tree.get_height() << endl;
	tree.remove(1);
	cout << "Height:\t" << tree.get_height() << endl;
	tree.remove(9);
	cout << "Height:\t" << tree.get_height() << endl;
	tree.inorder();	
	cout << tree.minimum()->data << " " << tree.maximum()->data << endl;
	return 0;
}
