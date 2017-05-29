#include <iostream>
#include <climits>
using namespace std;

class Heap{
	int capacity;
	int size;
	int *A;
public:
	Heap(int);
	int leftChild(int);
	int rightChild(int);
	void swap(int&, int&);
	void insert(int);
	int extractMin();
	void print();
	void maxHeapify(int);
	void buildMaxHeap();
};

Heap::Heap(int c){
	capacity = c;
	size = 0;
	A = new int[capacity];
}

void Heap::swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

int Heap::leftChild(int i){
	return 2*i + 1;
}

int Heap::rightChild(int i){
	return 2*i + 2;
}

void Heap::insert(int val){
	if(size<capacity){
		A[size++] = val;
		buildMaxHeap();
	} else{
		cout << "Overflow!\n";
	}
}

int Heap::extractMin(){
	int val = INT_MIN;
	if(size){
		val = A[size-1];
		size--;
		buildMaxHeap();		
	}	
	return val;	
}

void Heap::print(){
	if(size > 0){
		for(int i = 0; i < size; i++)
			cout << A[i] << " ";
		cout << "\n";
	} else{
		cout << "Underflow\n";
	}
}

void Heap::maxHeapify(int i){
	int l, r, max;
	l = leftChild(i);
	r = rightChild(i);
	if(l < size && A[l] > A[i])
		max = l;
	else
		max = i;
	if(r < size && A[r] > A[max])
		max = r;
	if(max != i){
		swap(A[i], A[max]);
		maxHeapify(max);
	}
}

void Heap::buildMaxHeap(){
	for(int i = size/2; i>=0; i--)
		maxHeapify(i);
}

int main(){
	
	Heap heap(10);
	heap.print();
	heap.insert(5);
	heap.insert(10);
	heap.insert(7);
	heap.print();
	cout << heap.extractMin() << "\n";
	heap.print();
	return 0;
}
