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

void insertion_sort(int data[], int size){

  for(int i=1, key; i<size; i++){
    for(int j=i-1; j>=0; j--){
      if(data[j+1] < data[j])
        swap(&data[j+1], &data[j]);
    }
  }
}

void insertion_sort_alt(int data[], int size){

  for(int i=1, key, j; i<size; i++){

    key = data[i];
    j = i - 1;

    while(j >= 0 && data[j] > key){

      data[j+1] = data[j];
      --j;
    }
    data[j+1] = key;
  }
}

int main(){

  int data[] = {11, 55, 9, 44, 26, 22, 78, 0, 12, 5};
  int size = 10;
  display(data, size);
  insertion_sort_alt(data, size);
  display(data, size);
  return 0;
}
