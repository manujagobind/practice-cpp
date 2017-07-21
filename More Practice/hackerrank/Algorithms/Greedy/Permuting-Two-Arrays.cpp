#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

int main(){

    ull Q;  cin >> Q;
    while(Q--){
        ull N, K, count=0;  cin >> N >> K;
        ull *A = new ull[N];
        ull *B = new ull[N];
        
        for(ull i=0; i<N; ++i) cin >> A[i];
        for(ull i=0; i<N; ++i) cin >> B[i];
        
        sort(A, A+N);
        sort(B, B+N, greater<ull>());
        
        for(ull i=0; i<N; ++i){
            if(A[i] + B[i] >= K){
                ++count;
            }              
        }
        
        if(count == N)
            cout << "YES\n";
        else    
            cout << "NO\n"; 
        
        delete[] B;
        delete[] A;
    }
    return 0;
}
