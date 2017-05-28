#include <iostream>
#include <climits>
using namespace std;

class Node{
public:
	int key;
	Node *next;
	Node(int);
};

class Queue{
	Node *front, *rear;
public:
	Queue();
	void enqueue(int);
	int dequeue();	
};

Node::Node(int val){
	key = val;
	next = NULL;
}

Queue::Queue(){
	front = rear = NULL;
}

void Queue::enqueue(int val){
	Node *node = new Node(val);
	
	if(!rear){
		front = rear = node;
		return;
	}
	
	rear->next = node;
	rear = node;
}

int Queue::dequeue(){
	if(!front){
		return INT_MIN;
	}

	Node *temp = front;
	front = front->next;

	if(!front)
		rear = NULL;

	return temp->key;
}

int main(){
	
	Queue queue;
	queue.enqueue(10);
	queue.enqueue(20);
	cout << queue.dequeue() << "\n";
	cout << queue.dequeue() << "\n";
	cout << queue.dequeue() << "\n";
	return 0;	
}
