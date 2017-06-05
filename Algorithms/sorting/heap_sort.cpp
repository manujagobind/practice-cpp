#include <iostream>
using namespace std;

void swap(int *x, int *y){

  int temp = *x;
  *x = *y;
  *y = temp;
}

void display(int data[], int size){

  for(int i=0;   i<size ; i++){
    cout << data[i] << " ";
  }
  cout << endl;
}

int left(int i){
  return 2 * i + 1;
}

int right(int i){
  return 2 * i + 2;
}

void max_heapify(int data[], int size, int i){

  int max = i;

  if(left(i) < size && data[left(i)] > data[max])
    max = left(i);
  if (right(i) < size && data[right(i)] > data[max])
    max = right(i);

  if(max != i){

    swap(&data[i], &data[max]);
    max_heapify(data, size, max);
  }
}

void build_max_heap(int data[], int size){

  for(int i = size/2 - 1 ; i >= 0 ; i--)
    max_heapify(data, size, i);
}

void heap_sort(int data[], int size){

  build_max_heap(data, size);
  for(int i=size-1; i>=0 ; i--){
    swap(&data[0], &data[i]);
    max_heapify(data, i, 0);
  }
}

int main(){

  int data[] = {11, 55, 9, 44, 26, 22, 78, 0, 12, 5};
  int size = 10;
  display(data, size);
  heap_sort(data, size);
  display(data, size);
  return 0;
}
