#include <iostream>
using namespace std;

//Class definition for Node
template <typename T>
class Node{
  T data;
  Node<T> *next;
public:
  Node(T value);
  ~Node();
  T get_data();
  void set_data(T);
  Node<T>* get_next();
  void set_next(Node<T>*);
  bool has_next();
};

template <typename T>
Node<T>::Node(T data){
  this->data = data;
  this->next = NULL;
}

template <typename T>
Node<T>::~Node(){}

template <typename T>
T Node<T>::get_data(){
  return this->data;
}

template <typename T>
void Node<T>::set_data(T data){
  this->data = data;
}

template <typename T>
Node<T>* Node<T>::get_next(){
  return this->next;
}

template <typename T>
void Node<T>::set_next(Node<T> *next){
  this->next = next;
}

template <typename T>
bool Node<T>::has_next(){
  if(this->next)
    return true;
  return false;
}

template <typename T>
class LinkedList{
  Node<T> *head;
public:
  LinkedList();
  ~LinkedList();
  Node<T>* get_head();
  void set_head(Node<T>*);
  bool empty();
  T front();
  T back();
  void push_front(T);
  T pop_front();
  void push_back(T);
  T pop_back();
  int size();
  void show();
  T value_at(int);
  void insert_at(int, T);
  void erase_at(int);
  void remove(T);
  T value_from_end(int);
  void reverse();
};


template <typename T>
LinkedList<T>::LinkedList(){
  this->head = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList(){}

template <typename T>
Node<T>* LinkedList<T>::get_head(){
  return this->head;
}

template <typename T>
void LinkedList<T>::set_head(Node<T> *node){
  this->head = node;
}

//Checks whether list is empty
template <typename T>
bool LinkedList<T>::empty(){
  if(this->head)
    return false;
  return true;
}

//Returns the value of the first node
template <typename T>
T LinkedList<T>::front(){
  if(!this->empty())
    return this->head->get_data();
}

//Returns the value of the last node
template <typename T>
T LinkedList<T>::back(){
  if(!this->empty()){
    Node<T> *cursor = this->head;
    while(cursor->has_next())
      cursor = cursor->get_next();
    return cursor->get_data();
  }
}

//Inserts a node at the begining of the list
template <typename T>
void LinkedList<T>::push_front(T data){
  Node<T> *node = new Node<T>(data);
  node->set_next(this->head);
  this->set_head(node);
}

//Pops the first node and returns its value
template <typename T>
T LinkedList<T>::pop_front(){
  if(!this->empty()){
    T val = this->head->get_data();
    this->head = this->head->get_next();
    return val;
  }
  else{
    cout << "Cannot pop from empty list";
    throw;
  }
}

//Inserts a node at the end of the list
template <typename T>
void LinkedList<T>::push_back(T data){
  Node<T> *node = new Node<T>(data);
  if(this->empty()){
    this->set_head(node);
  }
  else{
    Node<T> *cursor = this->head;
    while(cursor->has_next())
      cursor = cursor->get_next();
    cursor->set_next(node);
  }
}

//Pops the last node and returns its value
template <typename T>
T LinkedList<T>::pop_back(){
  if(!this->empty()){
    Node<T> *current = this->head;
    Node<T> *previous = NULL;
    while(current->has_next()){
      previous = current;
      current = current->get_next();
    }
    if(previous){
      previous->set_next(NULL);
      return current->get_data();
    }
    else{
      this->set_head(NULL);
      return current->get_data();
    }
  }
  else{
    cout << "Cannot pop from empty list";
    throw;
  }
}

//Returns the number of elements in the list
template <typename T>
int LinkedList<T>::size(){
  int count = 0;
  Node<T> *cursor = this->get_head();
  while(cursor){
    cursor = cursor->get_next();
    count += 1;
  }
  return count;
}

//Prints the list
template <typename T>
void LinkedList<T>::show(){
  Node<T> *cursor = this->get_head();
  while(cursor){
    cout << cursor->get_data() << " --> ";
    cursor = cursor->get_next();
  }
  cout << endl;
}

//Returns the value of node at given index
template <typename T>
T LinkedList<T>::value_at(int index){
  if(index >= 0){
    int count = 0;
    Node<T> *cursor = this->get_head();
    while(cursor){
      if(index == count){
        return cursor->get_data();
      }
      cursor = cursor->get_next();
      ++count;
    }
    cout << "Index out of bounds";
    throw;
  }
  else{
    cout << "Invalid index";
    throw;
  }
}

//Inserts a node at given index
template <typename T>
void LinkedList<T>::insert_at(int index, T data){
  Node<T> *node = new Node<T>(data);
  if(index >= 0){
    int count = 0;
    Node<T> *current = this->get_head();
    Node<T> *previous = NULL;
    while(current){
      if(index == count){
        if(previous){
          previous->set_next(node);
        }
        else{
          this->set_head(node);
        }
        node->set_next(current);
        return;
      }
      previous = current;
      current = current->get_next();
      ++count;
    }
    if(index == count){
      previous->set_next(node);
      return;
    }
    cout << "Index out of bounds";
    throw;
  }
  else{
    cout << "Invalid index";
    throw;
  }
}

//Removes node at given index
template <typename T>
void LinkedList<T>::erase_at(int index){
  if(index >= 0){
    Node<T> *current = this->get_head();
    Node<T> *previous = NULL;
    int count = 0;
    while(current){
      if(index == count){
        if(previous){
          previous->set_next(current->get_next());
        }
        else{
          this->set_head(current->get_next());
        }
        delete current;
        return;
      }
      previous = current;
      current = current->get_next();
      ++count;
    }
    cout << "Index out of bounds";
    throw;
  }
  else{
    cout << "Invalid index";
    throw;
  }
}

//Removes first occurance of a node
template <typename T>
void LinkedList<T>::remove(T data){
  Node<T> *current = this->get_head();
  Node<T> *previous = NULL;
  while(current){
    if(current->get_data() == data){
      if(previous){
        previous->set_next(current->get_next());
      }
      else{
        this->set_head(current->get_next());
      }
      delete current;
      return;
    }
    previous = current;
    current = current->get_next();
  }
}

//Returns node at nth position from end
template <typename T>
T LinkedList<T>::value_from_end(int n){
  int size = this->size();
  if(n > 0 && n <= size){
    int index = size - n;
    return this->value_at(index);
  }
  else if(n <= 0){
    cout << "Invalid position";
    throw;
  }
  else{
    cout << "Too few values";
    throw;
  }
}

template <typename T>
void LinkedList<T>::reverse(){
  Node<T> *a = this->get_head(), *b, *c;

  if(a->has_next()){
    b = a->get_next();
  } else{
    //List has only 1 element
    return;
  }

  if(b->has_next()){
    a->set_next(NULL);
    while(b->has_next()){
      c = b->get_next();
      b->set_next(a);
      a = b;
      b = c;
    }
    b->set_next(a);
    this->set_head(b);
  }
  else{
    //List has only two elements
    a->set_next(NULL);
    b->set_next(a);
    this->set_head(b);
  }
}

int main(){

  LinkedList<int> list;
  //Node<int> *node = new Node<int>(5);
  //Node<int> *node2 = new Node<int>(6);
  list.push_back(7);
  list.push_front(2);
  list.push_back(5);
  list.push_back(6);
  list.show();
  list.reverse();
  list.show();
  //list.erase_at(0);
  //cout << list.value_from_end(1) << endl;
  //cout << list.value_at(2) << endl;
  return 0;
}
