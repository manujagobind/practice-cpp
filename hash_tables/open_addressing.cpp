#include <iostream>
#define TABLE_SIZE 10
#define ERROR -1
using namespace std;

template <typename T>
class Element{
	int key;
	T value;
public:
	Element(int, T);
	int getKey();
	T getValue();
};

template <typename T>
class HashMap{
	Element<T> **table;
public:	
	HashMap();
	~HashMap();
	int hash(int);
	void insert(int, T);
	void print();		
	T value(int);
};

template <typename T>
Element<T>::Element(int key, T value){
	this->key = key;
	this->value = value;
}

template <typename T>
int Element<T>::getKey(){
	return this->key;
}

template <typename T>
T Element<T>::getValue(){
	return this->value;
}

template <typename T>
HashMap<T>::HashMap(){
	this->table = new Element<T>*[TABLE_SIZE];
	for(int i=0; i<TABLE_SIZE; i++){
		table[i] = NULL;
	}
}

template <typename T>
HashMap<T>::~HashMap(){
	for(int i=0; i<TABLE_SIZE; i++){
		delete table[i];
	}
	delete[] table;
}

template <typename T>
int HashMap<T>::hash(int key){
	return (key % TABLE_SIZE);
}

template <typename T>
void HashMap<T>::insert(int key, T value){
		
	int hashVal = hash(key);
	while(this->table[hashVal]){
		hashVal = hash(hashVal + 1);
	}
	this->table[hashVal] = new Element<T>(key, value);
}

template <typename T>
void HashMap<T>::print(){
	for(int i=0; i<TABLE_SIZE; i++){
		cout << i << " -> ";
		if(this->table[i]){
			cout << "( " << this->table[i]->getKey() << ", " << this->table[i]->getValue() << " )";
		}
		cout << endl;
	}
}

template <typename T>
T HashMap<T>::value(int key){
	int hashVal = hash(key);
	while(this->table[hashVal] && this->table[hashVal]->getKey() != key){		
		hashVal = hash(hashVal + 1);
	}
	if(this->table[hashVal]){
		return this->table[hashVal]->getValue();
	}	
	return ERROR;
}

int main(){
	
	HashMap<int> map;
	map.insert(1, 6);
	map.insert(3, 5);
	map.print();
	cout << map.value(3) << map.value(1);
	return 0;
}
