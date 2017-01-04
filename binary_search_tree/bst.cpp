#include <iostream>
#include <queue>
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

//Level-order traversal
template <typename T>
void levelorder(BSTNode<T> *root){
  if(root == NULL)
    return;
  else{
    queue< BSTNode<T>* > q;
    q.push(root);
    BSTNode<T> *current;
    while(!q.empty()){
      current = q.front();
      q.pop();

      cout << current->data << " ";

      if(current->left)
        q.push(current->left);
      if(current->right)
        q.push(current->right);
    }
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
  if(root == NULL)
    return NULL;

  if(root->left == NULL)
    return root;

  return minimum(root->left);
}

//Returns node with minimum value (iterative approach)
template <typename T>
BSTNode<T>* minimum_iterative(BSTNode<T> *root){
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

//Returns number of nodes in the tree
template <typename T>
int get_node_count(BSTNode<T> *root){
  if(root == NULL)
    return 0;
  else
    return get_node_count(root->left) + get_node_count(root->right) + 1;
}

//Returns height of the tree
template <typename T>
int get_height(BSTNode<T> *root){
  if(root == NULL)
    return -1;
  else
    return max(get_height(root->left), get_node_count(root->right)) + 1;
}

//Deletes the tree and deallocates the memory used in heap
template <typename T>
BSTNode<T>* delete_tree(BSTNode<T> *root){
  if(root == NULL)
    return NULL;
  else{
    root->left = delete_tree(root->left);
    root->right = delete_tree(root->right);
    delete root;
    return NULL;
  }
}

//Deletes a node in the tree
template <typename T>
BSTNode<T>* delete_value(BSTNode<T> *root, T value){
  if(value == root->data){
    if(root->left == NULL && root->right == NULL) //Leaf node
      root = NULL;
    else if(root->left == NULL) //Only right child
      root = root->right;
    else if(root->right == NULL)  //Only left child
      root = root->left;
    else{
      BSTNode<T> *min = minimum(root->right);
      root->data = min->data;
      root->right = delete_value(root->right, min->data);
    }
  }
  else if(value < root->data)
    root->left = delete_value(root->left, value);
  else
    root->right = delete_value(root->right, value);
  return root;
}

//Returns the node with next highest value after a given value
template <typename T>
BSTNode<T>* successor(BSTNode<T> *root, T value){
  if(root == NULL)
    return NULL;

  BSTNode<T>* node = root;
  while(node->data != value){
    if(value < node->data)
      node = node->left;
    else
      node = node->right;
  }

  if(node->right)
    return minimum(node->right);
  else{
    BSTNode<T> *ancestor = root;
    //TODO
  }

}

//Returns true if the tree is a binary search tree
template <typename T>
bool isBST(BSTNode<T> *root){
  //TODO
}


int main(){

  BSTNode<int> *root = NULL;
  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 8);
  root = insert(root, 2);
  root = insert(root, 1);
  root = insert(root, 20);
  root = insert(root, 10);

  inorder(root);
  cout << endl;
  levelorder(root);
  cout << endl;
  cout << successor(root, 7)->data;
  //root = delete_tree(root);
  //root = delete_value(root, 5);
  //cout << endl;
  //inorder(root);
  //levelorder(root);
  //cout << endl;
  //root = delete_value(root, 5);
  //cout << endl;
  //inorder(root);
  //cout << endl;
  //levelorder(root);
  //root = delete_value(root, 3);
  //cout << endl;
  //inorder(root);
  //cout << endl;
  //levelorder(root);
  cout << endl;
  //cout << "Min " << minimum(root->right)->data << endl;
  //cout << "Count " << get_node_count(root) << endl;
  //cout << "Height " << get_height(root) << endl;
  return 0;
}
