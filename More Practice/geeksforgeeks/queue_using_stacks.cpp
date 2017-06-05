#include <iostream>
#include <climits>
using namespace std;

class Stack{
	int top;
	int capacity;
	int *array;
public:
	Stack(int);
	void push(int);
	int pop();	
	int peek();
	bool empty();
	void print();
};

Stack::Stack(int c){
	capacity = c;
	top = -1;
	array = new int[capacity];
}

void Stack::push(int val){
	if(top<capacity){
		array[++top] = val;
	} else{
		cout << "Stack Overflow!\n";
	}
}

int Stack::pop(){
	int x;
	if(top>=0){
		x = array[top--];
	} else{
		x = -1;		
	}
	return x;
}

int Stack::peek(){
	return array[top];
}

bool Stack::empty(){
	return (top == -1);
}

void Stack::print(){
	if(top>=0){
		int i = top;
		while(i>=0){
			cout << array[i--] << " ";
		}
		cout << "\n";
	} else {
		cout << "Stack Underflow!\n";
	}
}

class Queue{
	Stack s1, s2;
public:
	Queue(int capacity) : s1(capacity), s2(capacity) {}
	void enqueue(int);
	int dequeue();
	int front();
};

void Queue::enqueue(int val){
	while(!s1.empty())
		s2.push(s1.pop());
	s1.push(val);
	while(!s2.empty())
		s1.push(s2.pop());
}

int Queue::dequeue(){
	if(!s1.empty())
		return s1.pop();
	return INT_MIN;
}

int Queue::front(){
	return s1.peek();
}

int main(){

	Queue queue(10);

	return 0;
}
