#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int T;  cin >> T;
    while(T--){
        int N;  cin >> N;
        int *A = new int[N];
        int *B = new int[N];
        int *C = new int[2*N];
        
        for(int i=0; i<N; ++i)  cin >> A[i];
        for(int i=0; i<N; ++i)  cin >> B[i];
        
        int i, j, k;
        i = j = k = 0;
        while(i<N && j<N){
            if(A[i] < B[j])
                C[k++] = A[i++];
            else
                C[k++] = B[j++];
        }
        while(i<N)
            C[k++] = A[i++];
        while(j<N)
            C[k++] = B[j++];
            
        cout << C[N-1]+C[N] << endl;
        
        delete[] B;
        delete[] A;
    }
    return 0;
}
