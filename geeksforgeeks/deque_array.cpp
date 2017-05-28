#include <iostream>
#include <climits>
using namespace std;

class Deque{

	int front, rear;
	int capacity, size;
	int *array;
public:
	Deque(int);
	bool empty();
	bool full();	
	void push_front(int);
	void push_back(int);
	int pop_front();
	int pop_back();
	void print();
};

Deque::Deque(int c){
	capacity = c;
	front = -1;	
	rear = 0;
	size = 0;
	array = new int[capacity];
}

bool Deque::empty(){
	return front==-1;
}

bool Deque::full(){
	return size==capacity;
}

void Deque::push_front(int val){
	if(empty()){
		front++;
		array[front] = val;
		size = 1;
	} else if(!full()){
		if(front == 0)
			front = capacity - 1;
		else
			front--;
		array[front] = val;
		size++;
	} else{
		cout << "Overflow!\n";
	}
}

void Deque::push_back(int val){	
	if(empty()){
		front = rear = 0;
		array[rear] = val;
		size = 1;
	} else if(!full()){
		rear = (rear + 1) % capacity;
		array[rear] = val;
		size++;	
	} else{
		cout << "Overflow!\n";
	}
}

int Deque::pop_front(){
	if(!empty()){
		int val = array[front];
		if(size==1){
			front = -1;
			rear = 0;			
		} else if(front == capacity-1){
			front = 0;
		} else {
			front++;
		}
		size--;
		return val;
	}
	return INT_MIN;
}

int Deque::pop_back(){
	if(!empty()){
		int val = array[rear];
		if(size == 1){
			front = -1;
			rear = 0;
		} else if(rear == 0){
			rear = capacity - 1;		
		} else{
			rear--;
		}
		size--;
		return val;
	}
	return INT_MIN;
}

void Deque::print(){
	if(!empty()){
		int i = front;
		while(i != rear){
			cout << array[i] << " ";
			i = (i+1) % capacity;
		}	
	}
	cout << "\n";
}

int main(){

	Deque deque(3);
	deque.print();
	deque.push_back(3);
	deque.push_back(5);
	deque.push_back(2);
	deque.print();/*
	cout <<	deque.pop_front() << "\n";
	cout << deque.pop_front() << "\n";
	cout << deque.pop_back() << "\n";
	cout << deque.pop_back() << "\n";
	cout << deque.pop_back() << "\n";*/
}
