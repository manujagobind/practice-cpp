//Circular queue implementation using fixed size arrays

//Head = index of first element
//Tail = index where next item is to be inserted

#include <iostream>
#define CAPACITY 5
using namespace std;

template <typename T>
class Queue{

  int head, tail, size;
  T array[CAPACITY];
public:
  Queue();
  ~Queue(){}
  bool empty();
  bool full();
  void enqueue(T);
  T dequeue();
  void show();
};

template <typename T>
Queue<T>::Queue(){
  //Initializing empty queue
  head = tail = 0;
  size = 0;
}

template <typename T>
bool Queue<T>::empty(){
  return head == tail;
}

template <typename T>
bool Queue<T>::full(){
  if(head == 0)
    return tail == CAPACITY - 1;
  return tail == head - 1;
}

template <typename T>
void Queue<T>::enqueue(T value){
  if(!full()){

    array[tail] = value;
    tail = (tail + 1) % CAPACITY;
  }
  else{
    cerr << "Overflow\n";
  }
}

template <typename T>
T Queue<T>::dequeue(){
  if(!empty()){
    T value = array[head];
    head = (head + 1) % CAPACITY;
    return value;
  }
  else{
    cerr << "Underflow\n";
  }
}

template <typename T>
void Queue<T>::show(){
  if(!empty()){
    int i = head;
    while(i != tail)
      cout << array[i++] << " ";
    cout << endl;
  }
  else{
    cerr << "Underflow\n";
  }
}

int main(){

  Queue<int> Q;

  cout << Q.empty() << Q.full() << endl;
  Q.enqueue(3);
  Q.enqueue(5);
  Q.enqueue(1);
  Q.enqueue(2);
  cout << Q.empty() << Q.full() << endl;
  Q.enqueue(7);
  cout << Q.empty() << Q.full() << endl;
  Q.show();
  cout << Q.dequeue() << endl;
  cout << Q.dequeue() << endl;
  cout << Q.dequeue() << endl;
  cout << Q.dequeue() << endl;
  Q.show();
  cout << Q.empty() << Q.full() << endl;
  return 0;
}
