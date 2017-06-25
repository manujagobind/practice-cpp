#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(long *a, long n){
    for(long i=0; i<n; ++i)
        cout << a[i] << " ";
}

void swap(long *x, long *y){
    long temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(long *a, long start, long end){
    for(long i=start, j=end; i<=j; ++i, --j)
        swap(a[i], a[j]);
}

void left_rotate(long *a, long d, long n){
    reverse(a, 0, d-1);
    reverse(a, d, n-1);
    reverse(a, 0, n-1);
}

int main() {
    long n, d; cin >> n >> d;
    long *a = new long[n];
    for(int i=0;i<n;++i)
        cin >> a[i];
    left_rotate(a, d, n);
    print(a, n);
    delete a;
    return 0;
}

