//Queue implementation using linked lists

#include <iostream>
using namespace std;

template <typename T>
class Node{

public:
  T data;
  Node<T> *next;

  Node(T);
  ~Node(){}
};

template <typename T>
Node<T>::Node(T data){
  this->data = data;
  this->next = NULL;
}

template <typename T>
class Queue{

  Node<T> *head, *tail;
public:
  Queue();
  ~Queue(){}
  bool empty();
  void enqueue(T value);
  T dequeue();
  void show();
};

template <typename T>
Queue<T>::Queue(){
  head = tail = NULL;
}

template <typename T>
bool Queue<T>::empty(){
  return head == NULL;
}

template <typename T>
void Queue<T>::enqueue(T value){
  Node<T> *node = new Node<T>(value);
  if(empty()){
    head = tail = node;
  }
  else{
    tail->next = node;
    tail = node;
  }
}

template <typename T>
T Queue<T>::dequeue(){

  if(!empty()){
    T value = head->data;
    head = head->next;
    return value;
  }
  else{
    cerr << "Underflow\n";
    throw;
  }
}

template <typename T>
void Queue<T>::show(){

  Node<T> *cursor = head;
  while(cursor){
    cout << cursor->data << " --> ";
    cursor = cursor->next;
  }
  cout << endl;
}

int main(){

  Queue<int> Q;
  Q.show();
  Q.enqueue(5);
  Q.enqueue(2);
  Q.enqueue(3);
  Q.show();
  cout << Q.dequeue() << endl;
  cout << Q.dequeue() << endl;
  cout << Q.dequeue() << endl;
  Q.show();
  return 0;
}
