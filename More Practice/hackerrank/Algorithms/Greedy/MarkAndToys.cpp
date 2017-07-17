#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int N, K, count;   cin >> N >> K;
    int *A = new int [N];
    
    for(int i=0; i<N; ++i)
        cin >> A[i];
    
    sort(A, A+N);
    
    count = 0;
    while(K-A[count] >= 0){
        K -= A[count];
        ++count;        
    }
    
    cout << count;
    
    delete[] A;
    return 0;
}
