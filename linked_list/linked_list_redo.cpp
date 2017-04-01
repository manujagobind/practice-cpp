#include <iostream>
#define ERROR -1
using namespace std;

template <typename T>
class Node{
	
	T data;
	Node<T> *next;
public:
	Node(T);
	T get_data();
	void set_data(T);
	Node<T>* get_next();
	void set_next(Node<T>*);
	bool has_next();
};

template <typename T>
class LinkedList{
	
	Node<T> *head;
public:
	LinkedList();
	Node<T>* get_head();
	void set_head(Node<T>*);
	void set_head();
	void print();
	void push_front(T data);
	T pop_front();
	void push_back(T data);
	T pop_back();
};

template <typename T>
Node<T>::Node(T data){
	this->data = data;
	this->next = NULL;	
}

template <typename T>
T Node<T>::get_data(){
	return this->data;
}

template <typename T>
void Node<T>::set_data(T data){
	this->data = data;
}

template <typename T>
Node<T>* Node<T>::get_next(){
	return this->next;
}

template <typename T>
void Node<T>::set_next(Node<T> *next){
	this->next = next;
}

template <typename T>
bool Node<T>::has_next(){
	return (this->next != NULL);
}

template <typename T>
LinkedList<T>::LinkedList(){
	this->head = NULL;
}

template <typename T>
Node<T>* LinkedList<T>::get_head(){
	return this->head;
}

template <typename T>
void LinkedList<T>::set_head(Node<T> *node){
	this->head = node;
}

template <typename T>
void LinkedList<T>::print(){
	
	Node<T> *cur = this->get_head();
	while(cur){
		cout << cur->get_data() << " --> ";
		cur = cur->get_next();
	}
	cout << endl;
}

template <typename T>
void LinkedList<T>::push_front(T data){
	
	Node<T> *node = new Node<T>(data);
	if(Node<T> *temp = this->get_head()){
		node->set_next(temp);		
	}
	
	this->set_head(node);
}

template <typename T>
T LinkedList<T>::pop_front(){
	if(Node<T> *cur = this->get_head()){		
		
		T data = cur->get_data();
		
		if(cur->has_next()){
			this->set_head(cur->get_next());
		} else{
			this->set_head(NULL);
		}
		
		return data;
	}
	return ERROR;
}

template <typename T>
void LinkedList<T>::push_back(T data){
	
	Node<T> *node = new Node<T>(data);
	
	if(Node<T>* cur = this->get_head()){
		while(cur->has_next()){
			cur = cur->get_next();
		}
		cur->set_next(node);
	} else{		
		this->set_head(node);
	}	
}

int main(){
	
	LinkedList<int> L;
	L.print();
	L.push_back(5);
	L.push_front(10);
	L.push_front(3);
	L.push_back(5);	
	L.print();
	return 0;
}
