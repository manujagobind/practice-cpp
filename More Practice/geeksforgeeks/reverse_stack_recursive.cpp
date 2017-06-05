#include <iostream>
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
	void reverse();
	void insertAtBottom(int);
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

void Stack::reverse(){	
	if(!empty()){
		int temp = pop();
		reverse();
		insertAtBottom(temp);
	}
}


void Stack::insertAtBottom(int val){
	if(empty()){
		push(val);
	} else{
		int temp = pop();
		insertAtBottom(val);
		push(temp);
	}
}

int main(){

	Stack stack(10);

	stack.print();
	stack.push(5);
	stack.push(10);
	stack.push(2);	
	stack.push(3);
	stack.print();
	stack.reverse();
	stack.print();
	return 0;
}
