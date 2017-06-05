#include <iostream>
using namespace std;

void display(int data[], int size){

  for(int i=0;   i<size ; i++){
    cout << data[i] << " ";
  }
  cout << endl;
}

void merge(int data[], int left, int mid, int right){

  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *L = new int[n1];
  int *R = new int[n2];

  //Copying elements to left and right arrays
  for(i=0; i<n1; i++)
    L[i] = data[left + i];
  for(j=0; j<n2; j++)
    R[j] = data[mid + 1 + j];

  i = j = 0;
  k = left;

  //Sorting and merging
  while(i < n1 && j < n2){

    if(L[i] <= R[j])
      data[k++] = L[i++];
    else
      data[k++] = R[j++];
  }

  while(i < n1){
    data[k++] = L[i++];
  }
  while(j < n2){
    data[k++] = R[j++];
  }
}

void merge_sort(int data[], int left, int right){

  if(left < right){
    int mid = (left + right) / 2;
    merge_sort(data, left, mid);
    merge_sort(data, mid+1, right);
    merge(data, left, mid, right);
  }
}

int main(){

  int data[] = {11, 55, 9, 44, 26, 22, 78, 0, 12, 5};
  int size = 10;
  display(data, size);
  merge_sort(data, 0, size-1);
  display(data, size);
  return 0;
}
