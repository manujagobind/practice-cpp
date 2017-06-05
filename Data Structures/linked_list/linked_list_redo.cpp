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
	int size();	//Number of nodes in the list
	void reverse();
	T value_at(int);
	void insert_at(int, T);
	void erase_at(int);
	T value_from_end(int);	
	void swap(T, T); //Swap two nodes without swapping data
	void rotate(int); //Rotate list counter-clockwise by k positions
	void del();	//Delete the list	
	T mid(); //Return data at middle node
	bool search(T);	//Search for an element
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

template <typename T>
void LinkedList<T>::erase_at(int index){
	
	int count = 0;
	Node<T> *cur = this->get_head(), *prev = NULL;
	
	while(cur && count < index){
		prev = cur;
		cur = cur->get_next();
		count++;
	}
	
	if(count == 0){
		this->set_head(cur->get_next());
		delete cur;
	}
	else if(count == index){
		prev->set_next(cur->get_next());
		delete cur;
	} else{
		cout << "\nInvalid Index\n";
	}
}

template <typename T>
T LinkedList<T>::value_from_end(int index){
	
	/*	Indexing starts from 0
		If index = 0, return last element
		If index = 1, return second last element
		And so on. . */
		
	int num = this->size() - index;
	
	if(num > 0){
		int count = 1;
		Node<T> *cur = this->get_head();
		while(cur && count < num){
			cur = cur->get_next();
			count++;
		}
		
		return cur->get_data();
	} else{
		cout << "\nInvalid Index\n";
		return ERROR;
	}		
}

template <typename T>
void LinkedList<T>::swap(T x, T y){
	//Assuming both values are present in the list
	
	if(x == y){
		return;
	}
	
	Node<T> *x_prev, *x_cur, *y_prev, *y_cur;
	Node<T> *cur = this->get_head(), *prev = NULL;
	x_cur = this->get_head();
	x_prev = NULL;
	
	while(x_cur && x_cur->get_data() != x){
		x_prev = x_cur;
		x_cur = x_cur->get_next();
	}
	
	y_cur = this->get_head();
	y_prev = NULL;
	while(y_cur && y_cur->get_data() != y){
		y_prev = y_cur;
		y_cur = y_cur->get_next();
	}
	
	if(x_prev){
		x_prev->set_next(y_cur);
	} else{
		this->set_head(y_cur);
	}
	
	if(y_prev){
		y_prev->set_next(x_cur);
	} else{
		this->set_head(x_cur);
	}
	
	Node<T> *temp = y_cur->get_next();
	y_cur->set_next(x_cur->get_next());		
	x_cur->set_next(temp);
}

template <typename T>
void LinkedList<T>::rotate(int k){
	//Assuming k > 0 and k < size of the list
	
	if(k <= 0){
		return;
	}
	
	int count = 1;
	Node<T> *start, *cur, *new_head;
	start = cur = this->get_head();
	
	while(count < k && cur){		
		cur = cur->get_next();
		count++;
	}
	
	if(cur->has_next()){
		new_head = cur->get_next();
		this->set_head(new_head);
		cur->set_next(NULL);	
		
		while(new_head->has_next()){			
			new_head = new_head->get_next();
		}
				
		if(start){			
			new_head->set_next(start);
		}		
	}
}

template <typename T>
void LinkedList<T>::del(){
	
	Node<T> *cur = this->get_head(), *next;
	while(cur){
		next = cur->get_next();
		delete cur;
		cur = next;
	}
	this->set_head(NULL);
}

template <typename T>
T LinkedList<T>::mid(){
	
	Node<T> *ptr1, *ptr2;
	ptr1 = ptr2 = this->get_head();
	
	while(ptr1 && ptr1->has_next()){
		ptr1 = ptr1->get_next()->get_next();
		ptr2 = ptr2->get_next();
	}
	
	return ptr2->get_data();
}

template <typename T>
bool LinkedList<T>::search(T element){
	
	Node<T> *cur = this->get_head();
	while(cur){
		if(cur->get_data() == element){
			return true;
		}
		cur = cur->get_next();
	}
	return false;
}

int main(){
	
	LinkedList<int> L;
	L.print();
	L.push_back(5);
	L.push_front(4);
	L.push_front(10);
	L.push_front(3);
	L.push_back(6);	
	L.print();	
	cout << L.value_at(3) << endl;	
	//L.erase_at(3);	
	//L.swap(4, 5);
	//L.reverse();
	//cout << L.value_from_end(2) << endl; 
	//L.rotate(3);
	cout << L.search(5) << endl;
	L.print();	
	//cout << L.value_at(2) << endl;
	return 0;
}
