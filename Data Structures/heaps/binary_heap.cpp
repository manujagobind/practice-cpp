#include <iostream>
#include <cassert>

// Class Entry
template <typename T, typename U>
class Entry{
	T key;
	U payload;
public:
	Entry(T, U);
	T getKey() const;
	U getPayload() const;
	void setKey(T);
	void setPayload(U);
	void print() const;
};

// Constructor for class  Entry
template <typename T, typename U>
Entry<T, U>::Entry(T key, U payload){
	this->key = key;
	this->payload = payload;
}

// Getter function
template <typename T, typename U>
T Entry<T, U>::getKey() const {
	return key;
}

// Getter function
template <typename T, typename U>
U Entry<T, U>::getPayload() const {
	return payload;
}

// Setter function
template <typename T, typename U>
void Entry<T, U>::setKey(T key){
	this->key = key;
}

// Setter function
template <typename T, typename U>
void Entry<T, U>::setPayload(U payload){
	this->payload = payload;
}

// Prints key and payload
template <typename T, typename U>
void Entry<T, U>::print() const {
	std::cout << "(" << key  << ", " << payload << ") ";
}

// Class MinHeap
template <typename T, typename U>
class MinHeap{
	Entry<T, U> **array;
	int capacity, size;
	int left(int) const;
	int right(int) const;
	int parent(int) const;
	void bubbleUp(int);
	void bubbleDown(int);
	void exchange(int, int);
public:
	MinHeap(int);
	void insert(Entry<T, U>*);
	Entry<T, U>* extractMin();
	void decreaseKey(int, T);
	void print();
	void buildHeap();
	void heapSort();
	int getSize() const;
	int getCapacity() const;
};

// Constructor for class MinHeap
template <typename T, typename U>
MinHeap<T, U>::MinHeap(int capacity){
	this->capacity = capacity;
	size = 0;
	// Each element of the array is a pointer to an Entry object
	array = new Entry<T, U>*[capacity+1]; // Indexing of heap begins at 1
}

// Returns index of left child
template <typename T, typename U>
int MinHeap<T, U>::left(int i) const {
	return 2*i;
}

// Return index of right child
template <typename T, typename U>
int MinHeap<T, U>::right(int i) const {
	return 2*i + 1;
}

// Returns index of parent node
template <typename T, typename U>
int MinHeap<T, U>::parent(int i) const {
	return i/2;
}

// Swaps content of array[] at corrosponding indices
template <typename T, typename U>
void MinHeap<T, U>::exchange(int i, int j){
	Entry<T, U> *temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

// BubbleUp
template <typename T, typename U>
void MinHeap<T, U>::bubbleUp(int i){
	while(i > 1 && array[parent(i)]->getKey() > array[i]->getKey()){
		exchange(i, parent(i));
		i = parent(i);
	}
}

// BubbleDown
template <typename T, typename U>
void MinHeap<T, U>::bubbleDown(int i){
	int l, r, mini;
	l = left(i);
	r = right(i);
	if(l <= size && array[l]->getKey() < array[i]->getKey())
		mini = l;
	else
		mini = i;
	if(r <= size && array[r]->getKey() < array[mini]->getKey())
		mini = r;
	if(mini != i){
		exchange(mini, i);
		bubbleDown(mini);
	}
}

// Inserts an Entry to the heap
template <typename T, typename U>
void MinHeap<T, U>::insert(Entry<T, U> *entry){
	assert(size < capacity);
	array[++size] = entry;
	bubbleUp(size); // To maintain heap-order
}

// Returns Entry with minimun key
template <typename T, typename U>
Entry<T, U>* MinHeap<T, U>::extractMin(){
	assert(size > 0);
	Entry<T, U> *entry = array[1];
	exchange(1, size);	
	size--;
	bubbleDown(1); // To maintain heap-order
	return entry;
}

// Set's a new (lower) key for an Entry at a certain index
template <typename T, typename U>
void MinHeap<T, U>::decreaseKey(int index, T new_key){
	assert(index >= 1 && index <= size);
	assert(new_key < array[index]->getKey());
	array[index]->setKey(new_key);
	bubbleUp(index); // To maintain heap-order
}


// Print's the contents of the heap (in levelorder)
template <typename T, typename U>
void MinHeap<T, U>::print(){
	for(int i=1; i<=size; i++){
		std::cout << i;
		array[i]->print();
	}
 	std::cout << std::endl;
}

// Getter function: returns number of nodes in the heap
template <typename T, typename U>
int MinHeap<T, U>::getSize() const {
	return size;
}

// Getter function
template <typename T, typename U>
int MinHeap<T, U>::getCapacity() const {
	return capacity;
}

// Enforces heap-order on all nodes
template <typename T, typename U>
void MinHeap<T, U>::buildHeap(){
	for(int i=size/2; i >= 1; i--)
		bubbleDown(i);
}

// Sorts in descending order
template <typename T, typename U>
void MinHeap<T, U>::heapSort(){
	buildHeap();
	int cur_size = size; // Store actual size
	for(int i=size; i >= 2 ; i--){
		exchange(1, i);
		size--;		
		bubbleDown(1);		
	}
	size = cur_size; // Reassign actual size
}

// Test drive
int main(){

	MinHeap< int, int > heap(10);
	std::cout << "Capacity: " << heap.getCapacity() << std::endl;
	std::cout << "Size: " << heap.getSize() << std::endl;

	Entry<int, int> *entry;

	for(int i=1, n=5; i<=n; i++){
		entry = new Entry<int, int>(n-i+1, (n-i+1)*10);
		heap.insert(entry);
	}	

	heap.print();
	heap.heapSort();
	heap.print();
	heap.buildHeap(); // Necessary after sort to restore array as heap
	heap.print();
	
	entry = heap.extractMin();
	std::cout << "Min: " << entry->getKey() << std::endl;
	heap.decreaseKey(4, 0);
	heap.print();
	std::cout << "Size: " << heap.getSize() << std::endl;
	entry = heap.extractMin();
	heap.print();
	std::cout << "Min: " << entry->getKey() << std::endl;

	return 0;
}
