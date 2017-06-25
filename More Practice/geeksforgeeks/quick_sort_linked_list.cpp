#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int key;
	Node *next;
	Node(int key){
		this->key = key;
		next = NULL;
	}
};

class LinkedList{
	Node *head;
	void destroy(Node*);
	Node* tail(Node*);
	Node* partition(Node*, Node*, Node**, Node**);
	Node* quick_sort(Node*, Node*);
public:
	LinkedList(){ head = NULL; }
	~LinkedList(){ destroy(head); head = NULL; }
	void insert(int);
	void print();
	void quick_sort();
};

void LinkedList::destroy(Node *node){
	while(node){
		Node *temp = node;
		node = node->next;
		delete temp;
	}
}

void LinkedList::insert(int key){
	Node *node = new Node(key);
	node->next = head;
	head = node;
}

void LinkedList::print(){
	Node *cur = head;
	while(cur){
		cout << cur->key << " ";
		cur = cur->next;
	}
	cout << endl;
}

Node* LinkedList::tail(Node *node){
	Node *cur = node;
	while(cur && cur->next) cur = cur->next;
	return cur;
}

Node* LinkedList::partition(Node *start, Node *end, Node **new_start, Node **new_end){
	Node *pivot = end;
	Node *cur = start, *prev = NULL, *tail=pivot;

	while(cur != pivot){
		if(cur->key < pivot->key){
			
			if(!(*new_start)) *new_start = cur;
			
			prev = cur;
			cur = cur->next;			
		} else {
				
			if(prev) prev->next = cur->next;
			Node *temp = cur->next;
			
			// Shift node to end of the list	
			cur->next = NULL;
			tail->next = cur;
			tail = cur;

			cur = temp;
		}
	}

	if(!(*new_start)) *new_start = pivot;
	*new_end = tail;
	return pivot;
}

Node* LinkedList::quick_sort(Node *start, Node *end){
	
	if(!start || start == end) return start;

	Node *new_start = NULL, *new_end = NULL;
	Node *pivot = partition(start, end, &new_start, &new_end);

	if(new_start != pivot){
		Node *temp = new_start;
		
		while(temp->next != pivot) temp = temp->next;
		temp->next = NULL;

		new_start = quick_sort(new_start, temp);
		temp = tail(new_start);
		temp->next = pivot;
	}

	pivot->next = quick_sort(pivot->next, new_end);

	return new_start;
}

void LinkedList::quick_sort(){
	head = quick_sort(head, tail(head));
}

int main(){
	LinkedList list;
	list.insert(5);
	list.insert(7);
	list.insert(9);
	list.insert(11);
	list.print();
	list.quick_sort();
	list.print();
	return 0;
}
