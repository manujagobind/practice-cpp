#include <iostream>
using namespace std;
#define MAX 1000

class Stack{
	int top;
public:
	int a[MAX];
	Stack() { top = -1;}
	bool push(int x);
	int pop();
	bool isEmpty();
};

bool Stack::push(int x){
	if(top >= MAX){
		cout << "Stack Overflow!\n";
		return false;
	} else{
		a[++top] = x;
		return true;
	}
}

int Stack::pop(){
	if(top < 0){
		cout << "Stack Underflow!";
		return -1;
	} else{
		int x = a[top--];
		return x;
	}		
}

bool Stack::isEmpty(){
	return (top < 0);
}

int main(){
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	cout << s.pop() << " popped from stackk\n";
	return 0;
}
