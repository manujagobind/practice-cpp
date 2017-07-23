#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int T;  cin >> T;
    while(T--){
        int N;  cin >> N;
        int *A = new int [N];
        
        for(int i=0; i<N; ++i)
            cin >> A[i];
            
        int global_max, local_max;
        global_max = local_max = A[0];
        
        for(int i=1; i<N; ++i){
            
            local_max = max(A[i], local_max + A[i]);
            global_max = max(local_max, global_max);
            
        }
        
        cout << global_max << endl;
        
        delete[] A;
    }
    return 0;
}
