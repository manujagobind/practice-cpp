#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int);
};

class Stack{
	Node *top;	
public:
	Stack();
	bool empty();
	void push(int);
	int pop();
	int peek();
	void print();
};

Node::Node(int data){
	this->data = data;
	this->next = NULL;
}

Stack::Stack(){
	this->top = NULL;
}

bool Stack::empty(){
	return top == NULL;
}

void Stack::push(int data){
	Node *node = new Node(data);
	node->next = top;
	top = node;
}

int Stack::pop(){
	if(top){
		Node *temp = top;
		int val = temp->data;
		top = top->next;
		delete temp;
		return val;
	} else{
		cout << "Stack Underflow!\n";
		return -1;
	}
}

int Stack::peek(){
	if(top){
		return top->data;
	} else{
		cout << "Stack Underflow\n";
		return -1;
	}
} 

void Stack::print(){

	if(top){
		Node *cursor = top;
		while(cursor){
			cout << cursor->data << "->";
			cursor = cursor->next;
		}
		cout << "\n";
	} else{
		cout << "Stack Underflow!\n";
	}
}

int main(){

	Stack stack;
	stack.print();
	stack.push(5);
	stack.push(10);		
	stack.print();	
	stack.pop();
	stack.print();
	stack.pop();
	stack.pop();
	return 0;
}
