/*
  Given an array A and a number x,
  check for pair in A with sum as x
*/

#include <iostream>
#include <set>
#define MAX 100
using namespace std;

int exchange(int *a, int *b){

  int temp = *a;
  *a = *b;
  *b = temp;
}

void print(int *arr, int size){

  for(int i=0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int *arr, int start, int end){

  int pivot = start, key = arr[end];
  for(int i=start; i < end; i++){

    if(arr[i] < key){
      exchange(&arr[i], &arr[pivot]);
      pivot++;
    }
  }
  exchange(&arr[end], &arr[pivot]);
  return pivot;
}

void quickSort(int *arr, int start, int end){

  if(start < end){

    int pId = partition(arr, start, end);
    quickSort(arr, start, pId - 1);
    quickSort(arr, pId + 1, end);
  }
}

/*
  Sort the array, and then check sum from both ends
  Increment/Decrement as necessary
*/
bool hasPairWithSum(int *arr, int size, int sum){

  quickSort(arr, 0, size-1);
  for(int i=0, j=size-1; i<j ;){

    int temp = arr[i] + arr[j];
    if(temp == sum) return true;
    else if(temp < sum) i++;
    else j++;
  }
  return false;
}

/*
  Insert the complement of each element into a set
  (Complement of n = sum - n)
  For each element encountered, check if it's complement is in the set
*/
bool hasPairWithSum_approach2(int *arr, int size, int sum){

  bool set[MAX] = {0};
  for(int i=0, temp; i < size ; i++){

    temp = sum - arr[i];
    if(temp >= 0 && set[temp]){
      return true;
    }
    set[arr[i]] = 1;
  }
  return false;
}

int main(){

  int arr[] = {5, 6, 1, 8, 2, 7, 0, 4};
  int sum = 10;
  cout << hasPairWithSum_approach2(arr, 8, sum) << endl;
  return 0;
}
