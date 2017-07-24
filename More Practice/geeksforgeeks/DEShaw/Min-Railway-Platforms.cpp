#include <bits/stdc++.h>
using namespace std;

int find_min_platforms(int A[], int D[], int N){
	sort(A, A+N);
	sort(D, D+N);
	
	int count = 1, i=1, j=0, max_count = 1;
	while(i < N && j < N){
		if(A[i] < D[j]){
			++i;
			++count;
		} else{
			++j;
			--count;
		}
		max_count = max(count, max_count);
	}

	return max_count;
}

int main(){

    int T;  cin >> T;
    while(T--){
        int N;  cin >> N;
        int *A = new int[N];
        int *D = new int[N];
        
        for(int i=0; i<N; ++i)  cin >> A[i];
        for(int i=0; i<N; ++i)  cin >> D[i];
     
        cout << find_min_platforms(A, D, N) << endl;
        
        delete[] D;
        delete[] A;
    }
	return 0;
}
