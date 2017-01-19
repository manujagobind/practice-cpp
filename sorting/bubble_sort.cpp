#include <iostream>
using namespace std;

void swap(int *x, int *y){

  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubble_sort(int data[], int size){

  for(int i=0; i<size-1; i++){
    for(int j=0;j<size-i-1;j++){
      if(data[j] > data[j+1])
        swap(&data[j], &data[j+1]);
    }
  }
}

void bubble_sort_optimized(int data[], int size){

  bool swapped;
  for(int i=0 ; i < size-1 ; i++){
    swapped = false;
    for(int j=0 ; j < size-i-1; j++){
      if(data[j] > data[j+1]){
        swap(&data[j], &data[j+1]);
        swapped = true;
      }
    }
    if(!swapped)
      break;
  }
}

void display(int data[], int size){

  for(int i=0;   i<size ; i++){
    cout << data[i] << " ";
  }
  cout << endl;
}

int main(){

  int data[] = {11, 55, 9, 44, 26, 22, 78, 0, 12, 5};
  int size = 10;
  display(data, size);
  bubble_sort_optimized(data, size);
  display(data, size);
  return 0;
}
