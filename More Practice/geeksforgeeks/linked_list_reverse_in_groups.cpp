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
	Node* reverse(Node*, int);
	void reverse_recursive(Node**, Node*, Node*);
public:
	LinkedList();
	~LinkedList();
	void push_front(int);
	void print();
	void reverse();
	void reverse(int);
	void reverse_recursive();
};

LinkedList::LinkedList(){ head = NULL; }

void LinkedList::push_front(int key){
	Node *node = new Node(key);
	node->next = head;
	head = node;
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

// To reverse complete list
void LinkedList::reverse(){
	Node *prev, *cur, *next;
	prev = NULL; cur = head;

	while(cur){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	head = prev;
}

// Recursive approach for reversing a linked list
void LinkedList::reverse_recursive(Node **head, Node *cur,  Node *prev){
	if(cur){
		if(!cur->next){
			// Last node to be marked as head
			*head = cur;
			cur->next = prev;
			return;
		}

		Node *next = cur->next;
		cur->next = prev;

		reverse_recursive(head, next, cur);
	}
}


// Wrapper for reverse_recursive(Node*)
void LinkedList::reverse_recursive(){
	reverse_recursive(&head, head, NULL);
}

// To reverse in groups of k nodes
Node* LinkedList::reverse(Node *node, int k){
	Node *prev = NULL, *cur = node, *next;
	int count = 0;

	while(cur && count < k){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		++count;
	}

	// Reverse the rest and connect to the start node
	// (Start node on being flipped is at the end)
	if(next) node->next = reverse(next, k);

	return prev;
}

// Wrapper for reverse(Node*, int)
void LinkedList::reverse(int k){
	head = reverse(head, k);
}

int main(){
	LinkedList list;
	list.push_front(8);
	list.push_front(5);
	list.push_front(7);
	list.push_front(1);
	list.push_front(9);
	list.push_front(6);
	list.print();
	list.reverse(2);
	list.print();
	return 0;
}
