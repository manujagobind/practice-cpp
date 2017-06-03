#include <iostream>
using namespace std;

class Heap{
    long *array;
    int size, capacity;
    int left(int);
    int right(int);
    int parent(int);
    void exchange(int, int);
    void bubbleUp(int);
    void bubbleDown(int);
    void buildMinHeap();
public:
    Heap(int);
    void insert(long);    
    void remove(long);
    long getMin();
    void print();
};

Heap::Heap(int c){
    capacity = c;
    size = 0;
    array = new long[capacity+1];
}

int Heap::left(int i){
    return 2*i;
}

int Heap::right(int i){
    return 2*i+1;
}

int Heap::parent(int i){
    return i/2;
}

void Heap::exchange(int i, int j){
    long temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void Heap::bubbleUp(int i){
    while(i > 1 && array[parent(i)] > array[i]){
        exchange(i, parent(i));
        i = parent(i);
    }
}

void Heap::bubbleDown(int i){
    int l, r, min;
    l = left(i);
    r = right(i);
    if(l <= size && array[l] < array[i])
        min = l;
    else
        min = i;
    if(r <= size && array[r] < array[min])
        min = r;
    if(min != i){
        exchange(min, i);
        bubbleDown(min);
    }
}

void Heap::insert(long val){
    array[++size] = val;
    bubbleUp(size);
}

void Heap::remove(long val){    
    for(int i=1; i<= size; i++)
        if(array[i]==val){
            int j = i;
            while(j < size){
                array[j] = array[j+1];
                j++;
            }            
        }  
    size--;    
    buildMinHeap();    
}

void Heap::buildMinHeap(){
    for(int i=size/2; i>=1; i--)
        bubbleDown(i);
}

long Heap::getMin(){
    return array[1];
}

void Heap::print(){
    for(int i=1; i<=size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main(){
    
    int Q;
    cin >> Q;
    Heap heap(Q);
    while(Q--){
        int c, x;
        cin >> c;
        switch(c){
            case 1:
                cin >> x;
                heap.insert(x);
            break;                
            case 2:
                cin >> x;
                heap.remove(x);            
            break;
            case 3:
                cout << heap.getMin() << endl;
        }
    }       
}
