#include <bits/stdc++.h>

class Node{
public:
	int data;
	Node* npx;
	Node(int);
};

Node::Node(int data){
	this->data = data;
	npx = NULL;
}

class XORLinkedList{
	Node *head, *tail;
	void destroy();
	Node* XOR(Node*, Node*);
	void push(Node**, Node**, int);
	void pop(Node**, Node**);
	void traverse(Node*);
public:
	XORLinkedList();
	~XORLinkedList();
	void push_front(int);
	void push_back(int);
	void pop_front();
	void pop_back();
	Node* front() const;
	Node* back() const;
	void traverse_forward();
	void traverse_backward();
};

XORLinkedList::XORLinkedList(){
	head = tail = NULL;
}

XORLinkedList::~XORLinkedList(){
	destroy();
}

void XORLinkedList::destroy(){
	Node *prev, *cur, *next;
	cur = head;	prev = NULL;

	while(cur){
	
		if(prev) delete prev;
		next = XOR(prev, cur->npx);
		prev = cur;
		cur = next;
	}

	if(prev) delete prev;
	head = NULL;
}

Node* XORLinkedList::XOR(Node *x, Node *y){
	return (Node*)( (uintptr_t) (x) ^ (uintptr_t) (y) );
}

void XORLinkedList::push(Node **start, Node **end, int data){
	Node *node = new Node(data);
	node->npx = XOR(NULL, *start);

	if(*start){
		Node* next = XOR(head->npx, NULL);
		(*start)->npx = XOR(node, next);
	}

	if(!node->npx) *end = node; // Adjust end too if node is inserted to an empty list
	*start = node;
}

void XORLinkedList::push_front(int data){
	push(&head, &tail, data);
}

void XORLinkedList::push_back(int data){
	push(&tail, &head, data);
}

void XORLinkedList::pop(Node **start, Node **end){
	if(*start){
		Node *next = XOR(NULL, (*start)->npx);
		if(next) next->npx = XOR(NULL, XOR(*start, next->npx));
		delete *start;		
		*start = next;
		if(!(*start)) *end = *start; // Adjust end too if the node deleted renders the list empty
	}
}

void XORLinkedList::pop_front(){
	pop(&head, &tail);
}

void XORLinkedList::pop_back(){
	pop(&tail, &head);
}

Node* XORLinkedList::front() const{
	return head;	
}

Node* XORLinkedList::back() const{
	return tail;
}

void XORLinkedList::traverse(Node *start){
	Node *prev, *cur, *next;
	cur = start; prev = NULL;

	while(cur){
		std::cout << cur->data << " ";	
		next = XOR(prev, cur->npx);
		prev = cur;
		cur = next;
	}
	
	std::cout << std::endl;
}

void XORLinkedList::traverse_forward(){
	traverse(head);
}

void XORLinkedList::traverse_backward(){
	traverse(tail);
}

int main(){

	XORLinkedList list;
	list.push_back(7);
	list.push_front(5);
	list.push_front(10);
	list.push_back(15);
	list.traverse_forward();
	list.traverse_backward();
	list.pop_front();
	list.pop_back();
	list.traverse_forward();
	list.traverse_backward();
	return 0;
}
