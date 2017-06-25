#include <bits/stdc++.h>
#include <exception>
using namespace std;

class Node{
public:
	int key;
	Node *next, *prev;
	Node(int key){
		this->key = key;
		next = prev = NULL;
	}
};

class DoubleLinkedList{
	Node *head, *tail;
	void destroy(Node*);
	Node* last_node(Node*);
	Node* partition(Node*, Node*);
	void quick_sort(Node*, Node*);
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void push_front(int);
	void push_back(int);
	void print_forward();
	void print_backward();
	void quick_sort();
};

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

DoubleLinkedList::DoubleLinkedList(){
	head = tail = NULL;
}

DoubleLinkedList::~DoubleLinkedList(){
	destroy(head);
	head = tail = NULL;
}

void DoubleLinkedList::destroy(Node *node){
	while(node){
		Node *temp = node;
		node = node->next;
		delete temp;
	}
}

void DoubleLinkedList::push_front(int key){
	Node *node = new Node(key);
	node->next = head;
	if(head) head->prev = node;
	head = node;
	if(!tail) tail = node;
}

void DoubleLinkedList::push_back(int key){
	Node *node = new Node(key);
	node->prev =  tail;
	if(tail) tail->next = node;
	tail = node;
	if(!head) head = node;
}

void DoubleLinkedList::print_forward(){
	Node *cur = head;
	while(cur){
		cout << cur->key << " ";
		cur = cur->next;
	}
	cout << endl;
}

void DoubleLinkedList::print_backward(){
	Node *cur = tail;
	while(cur){
		cout << cur->key << " ";
		cur = cur->prev;
	}
	cout << endl;
}

Node* DoubleLinkedList::last_node(Node *node){
	while(node && node->next){
		node = node->next;
	}
	return node;
}

Node* DoubleLinkedList::partition(Node *start, Node *end){
	Node *pivot = end;
	Node *p = start;
	
	for(Node *i = start; i != end; i = i->next){
		if(i->key < pivot->key){
			swap(&p->key, &i->key);
			p = p->next;
		}
	}

	swap(&p->key, &end->key);
	return p;
}

void DoubleLinkedList::quick_sort(Node *start, Node *end){
	if(!start || !end || start == end || start == end->next) return;
	
	Node *pivot = partition(start, end);
	quick_sort(start, pivot->prev);
	quick_sort(pivot->next, end);
}

void DoubleLinkedList::quick_sort(){
	quick_sort(head, tail);
}

int main(){

	DoubleLinkedList list;
	list.push_back(5);
	list.push_back(7);
	list.push_front(1);
	list.push_back(3);
	list.push_front(2);
	list.push_front(8);
	list.push_front(10);
	list.push_back(4);
	list.push_back(9);
	list.print_forward();
	list.quick_sort();
	list.print_forward();
	return 0;
}
