#include <bits/stdc++.h>
using namespace std;

void print(int *a, int size){
    for(int i=0; i<size; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void insertionSort(int *a, int size) {
    int val = a[size-1], j=size-1;
    while(j>0 && a[j-1] > val){
        a[j] = a[j-1];
        --j;
        print(a, size);
    }
    a[j] = val;
    print(a, size);
}

int main(void) {
    
    int _ar_size;
    cin >> _ar_size;
    int *_ar = new int[_ar_size];
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        cin >> _ar[_ar_i];
    }

    insertionSort(_ar, _ar_size);
    delete _ar;
    return 0;
}

