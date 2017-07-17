#include <bits/stdc++.h>
using namespace std;

int main(){
    
    long n, i;
    cin >> n;
    long *A = new long[n];
    for(i=0; i<n; ++i)
        cin >> A[i];
    sort(A, A+n);
        
    i = n-3;
    while(i >=0 && A[i]+A[i+1] <= A[i+2])
        --i;
    
    if(i >= 0)        
        cout << A[i] << " " << A[i+1] << " " << A[i+2];
    else cout << -1;   
    
    delete[] A;
    return 0;        
}
