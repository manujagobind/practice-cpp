#include <iostream>
#include <cstring>
using namespace std;

class Stack{
	int top;
	int capacity;
	char *array;
public:
	Stack(int);
	void push(char);
	char pop();
	void print();
	char peek();
	bool isEmpty();
};

Stack::Stack(int c){
	capacity = c;
	top = -1;
	array = new char[capacity];
}

void Stack::push(char c){
	if(top<capacity){
		array[++top] = c;
	} else{
		cout << "Stack Overflow!\n";
	}
}

char Stack::pop(){
	char x;
	if(top>=0){
		x = array[top--];
	} else{
		x = '$';		
	}
	return x;
}

void Stack::print(){
	if(top>=0){
		int i = top;
		while(i>=0){
			cout << array[i--] << "-->";
		}
		cout << "\n";
	} else{
		cout << "Stack Underflow!\n";
	}	
}

char Stack::peek(){
	return array[top];
}

bool Stack::isEmpty(){
	return (top == -1);
}

bool isOperand(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char c){
	switch(c){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

void infixToPostfix(char* exp){

	int len = strlen(exp);	
	Stack stack(len);
	
	int k = -1;
	for(int i = 0; exp[i]; i++){
		
		if(isOperand(exp[i])){
			exp[++k] = exp[i];
		} else if (exp[i] == '('){
			stack.push(exp[i]);
		} else if (exp[i] == ')'){
			while(!stack.isEmpty() && stack.peek() != '(')
				exp[++k] = stack.pop();
			stack.pop();
		} else{
			while(!stack.isEmpty() && precedence(exp[i]) <= precedence(stack.peek()))
				exp[++k] = stack.pop();
			stack.push(exp[i]);
		}
	}

	while(!stack.isEmpty())
		exp[++k] = stack.pop();
	exp[++k] = '\0';
	cout << exp << "\n";
}

int main(){
	
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}

