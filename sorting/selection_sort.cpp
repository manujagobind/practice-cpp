#include <iostream>
using namespace std;

void swap(int *x, int *y){

  int temp = *x;
  *x = *y;
  *y = temp;
}

void selection_sort(int data[], int size){

  for(int i=0, min; i<size-1; i++){
    min = i;
    for(int j=i+1;j<size;j++){
      min = (data[j] < data[min])? j : min;
    }
    if(i != min)
      swap(&data[i], &data[min]);
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
  selection_sort(data, size);
  display(data, size);
  return 0;
}
