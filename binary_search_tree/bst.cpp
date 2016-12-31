#include <iostream>
using namespace std;

template <typename T>
struct BSTNode{

  T data;
  BSTNode<T> *left, *right;
};

template <typename T>
BSTNode<T>* getNewNode(T value){

  BSTNode<T> *node = new BSTNode<T>;
  node->data = value;
  node->left = node->right = NULL;
}

//Inorder traversal
template <typename T>
void inorder(BSTNode<T>* root){
  if(root != NULL){
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

//Insert an element to the tree
template <typename T>
BSTNode<T>* insert(BSTNode<T> *root, T value){
  if(root == NULL){
    BSTNode<T> *node = getNewNode(value);
    root = node;
  }
  else if(value < root->data){
    root->left = insert(root->left, value);
  }
  else{
    root->right = insert(root->right, value);
  }
  return root;
}

//Search for an element in the tree
template <typename T>
bool search(BSTNode<T> *root, T value){
  if(root == NULL)
    return false;
  else if(value == root->data)
    return true;
  else if(value < root->data)
    return search(root->left, value);
  else
    return search(root->right, value);
}

//Search for an element in the tree (iterative approach)
template <typename T>
bool search_iterative(BSTNode<T> *root, T value){
  while(root != NULL && root->data != value){
    if(value < root->data)
      root = root->left;
    else
      root = root->right;
  }
  if(root)
    return true;
  else
    return false;
}

//Returns node with minimum value
template <typename T>
BSTNode<T>* minimum(BSTNode<T> *root){
  while(root->left)
    root = root->left;
  return root;
}

//Returns node with maximum value
template <typename T>
BSTNode<T>* maximum(BSTNode<T> *root){
  while(root->right)
    root = root->right;
  return root;
}


int main(){

  BSTNode<int> *root = NULL;
  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 8);
  root = insert(root, 7);
  inorder(root);
  cout << maximum(root)->data;
  return 0;
}
