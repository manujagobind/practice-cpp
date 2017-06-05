#include <iostream>
#include <climits>
using namespace std;

class Queue{
	int front, rear, size;
	unsigned int capacity;
	int *array;
public:
	Queue(int);
	void enqueue(int);
	int dequeue();
	bool full();
	bool empty();
	int Front();
	int Rear();
};

Queue::Queue(int c){
	capacity = c;
	front = size = 0;
	rear = capacity - 1;
	array = new int[capacity];
}

bool Queue::full(){
	return size==capacity;
}

bool Queue::empty(){
	return size==0;
}

void Queue::enqueue(int val){
	if(!full()){
		rear = (rear+1) % capacity;
		array[rear] = val;
		size++;
	}
}

int Queue::dequeue(){
	if(empty()){
		return INT_MIN;
	} 
	int val = array[front];
	front = (front+1) % capacity;
	size--;
	return val;
}

int Queue::Front(){
	if(empty()){
		return INT_MIN;
	}
	return array[front];		
}

int Queue::Rear(){
	if(empty()){
		return INT_MIN;
	}
	return array[rear];
}

int main(){

	Queue queue(10);
	
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	
	cout << queue.dequeue() << "\n";
	cout << queue.Front() << "\n";
	cout << queue.Rear() << "\n";
	cout << queue.dequeue() << "\n";
	cout << queue.dequeue() << "\n";
	return 0;
}
