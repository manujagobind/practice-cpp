#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int key;
	Node *next;
	Node(int key){this->key = key; next = NULL;}
};

class LinkedList{
	Node *head;
	void destroy();
	void reverse_print(Node*);
public:
	LinkedList operator+(LinkedList&);
	LinkedList();
	~LinkedList();
	void push_front(int);
	void push_back(int);
	void print();
	void reverse_print();
};

LinkedList::LinkedList(){ head = NULL; }

void LinkedList::push_front(int key){
	Node *node = new Node(key);
	node->next = head;
	head = node;
}

void LinkedList::push_back(int key){
	Node *node = new Node(key);
	if(!head) head = node;
	else{
		Node *cur = head, *prev = NULL;
		while(cur){
			prev = cur;
			cur = cur->next;
		}
		prev->next = node;
	}
}

LinkedList::~LinkedList(){
	destroy();
	head = NULL;
}

void LinkedList::destroy(){
	while(head){
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::print(){
	Node *cur = head;
	while(cur){
		cout << cur->key << " ";
		cur = cur->next;
	}
	cout << endl;
}

void LinkedList::reverse_print(Node* node){
	if(!node) return;

	reverse_print(node->next);
	cout << node->key << " ";
}

void LinkedList::reverse_print(){
	reverse_print(head);
	cout << endl;
}

LinkedList LinkedList::operator+(LinkedList &list){
	// Least Significant Bit is at the head node
	LinkedList result;
	Node *first = this->head;
	Node *second = list.head;
	int sum=0, carry=0;

	while(first || second){
		sum = carry + (first? first->key : 0) + (second? second->key : 0);
		carry = (sum >= 10)? 1 : 0;
	
		sum = sum % 10;
		result.push_back(sum);

		if(first) first = first->next;
		if(second) second = second->next;
	}

	if(carry > 0)
		result.push_back(carry);

	return result;
}

int main(){
	LinkedList list1, list2;
	// Insert 365
	list1.push_front(3);
	list1.push_front(6);
	list1.push_front(5);
	// Insert 248
	list2.push_front(2);
	list2.push_front(4);
	list2.push_front(8);
	cout << "List1:\t"; list1.reverse_print();
	cout << "List2:\t"; list2.reverse_print();
	LinkedList result = list1 + list2;
	cout << "Sum:\t"; result.reverse_print(); 
	return 0;
}
