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
	int size();
	void reverse();
	T value_at(int);
	void insert_at(int, T);
	void erase_at(int);
	T value_from_end(int);	
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

template <typename T>
int LinkedList<T>::size(){
	
	int count = 0;
	if(Node<T> *cur = this->get_head()){
		
		while(cur){
			count++;
			cur = cur->get_next();
		}
	}
	return count;
}

template <typename T>
void LinkedList<T>::reverse(){
	
	Node<T> *a;
	//Check if list is not empty
	if(a = this->get_head()){					
		if(a->has_next()){
			//List should have at least 2 elements so that we can reverse
			//(i.e. No need to reverse if only 1 element)
			Node<T> *b, *c;
			b = a->get_next();			
			a->set_next(NULL);
			while(b->has_next()){
				c = b->get_next();
				b->set_next(a);
				a = b;
				b = c;
			}
			b->set_next(a);
			this->set_head(b);
		} 
	}
}

template <typename T>
T LinkedList<T>::value_at(int index){	
	//Indexing starts at 0
	int count = 0;
	Node<T> *cur = this->get_head();
	
	while(cur && count < index){		
		cur = cur->get_next();
		count++;
	}
	
	if(count == index){
		return cur->get_data();
	} else{
		cout << "\nInvalid Index\n";
		return ERROR;
	}
}

template <typename T>
void LinkedList<T>::insert_at(int index, T data){
	//Indexing starts at 0
	int count = 0;	
	Node<T> *cur = this->get_head();
	Node<T> *prev = NULL;
	Node<T> *node = new Node<T>(data);
	
	while(cur && count < index){
		prev = cur;
		cur = cur->get_next();
		count++;
	}
	
	if(count == 0){
		node->set_next(cur);
		this->set_head(node);
	} else if(count == index){		
		node->set_next(cur);
		prev->set_next(node);
	} else{
		cout << "\nInvalid Index\n";
	}
}

int main(){
	
	LinkedList<int> L;
	L.print();
	L.push_back(5);
	L.push_front(10);
	L.push_front(3);
	L.push_back(6);	
	L.print();	
	cout << L.value_at(3) << endl;
	L.insert_at(3, 7);	
	//L.reverse();
	L.print();	
	cout << L.value_at(6) << endl;
	return 0;
}
