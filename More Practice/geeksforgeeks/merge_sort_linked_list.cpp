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
	void split(Node*, Node**, Node**);
	Node* merge(Node*, Node*);
	void  merge_sort(Node**);
public:
	LinkedList(){ head = NULL; }
	~LinkedList(){ destroy(head); head = NULL; }
	void insert(int);
	void print();
	void merge_sort();
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

void LinkedList::split(Node *src, Node **L, Node **R){
	Node *fast, *slow;

	if(!src || !src->next){
		*L = src;
		*R = NULL;
	} else {
		slow = src;
		fast = src->next;

		while(fast){
			fast = fast->next;
			if(fast){
				slow = slow->next;
				fast = fast->next;
			}
		}

		*L = src;
		*R = slow->next;
		slow->next = NULL;
	}
}

Node* LinkedList::merge(Node *L, Node *R){
	if(!L) return R;
	if(!R) return L;

	Node *result = NULL;
	if(L->key <= R->key){
		result = L;
		result->next = merge(L->next, R);
	} else{
		result = R;
		result->next = merge(L, R->next);
	}
}

void LinkedList::merge_sort(Node **start){
	if(!(*start) || !((*start)->next)) return;

	Node *L, *R; L = R = NULL;
	split(*start, &L, &R);

	merge_sort(&L);
	merge_sort(&R);
	*start = merge(L, R);
}

void LinkedList::merge_sort(){
	merge_sort(&head);
}

int main(){
	LinkedList list;
	list.insert(5);
	list.insert(7);
	list.insert(3);
	list.insert(8);
	list.insert(1);
	list.insert(2);
	list.insert(4);
	list.insert(0);
	list.insert(9);
	list.print();
	list.merge_sort();
	list.print();
	return 0;
}
