#include <iostream>
#include <cstring>
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
	char x;
	if(top>=0){
		x = array[top--];
	} else{
		x = '$';		
	}
	return x;
}

int Stack::peek(){
	return array[top];
}

bool Stack::empty(){
	return (top == -1);
}

bool isOperand(char c){
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

void evaluatePostfix(char *exp){
	
	int len = strlen(exp);
	Stack stack(len);

	int i = 0;
	while(exp[i]){
		if(isOperand(exp[i]))
			stack.push(int(exp[i]-'0'));
		else{
			int a, b;
			b = stack.pop();
			a = stack.pop();
			switch(exp[i]){
				case '+': stack.push(a+b); break;
				case '-': stack.push(a-b); break;
				case '*': stack.push(a*b); break;
				case '/': stack.push(a/b); break;
			}
		}
	i++;
	}
	cout << "Result:\t" <<  stack.pop() << "\n";
}

int main(){
	char exp[] = "231*+9-";
	evaluatePostfix(exp);
	return 0;
}
