#include <bits/stdc++.h>
using namespace std;

int main(){

	int T;	cin >> T;
	while(T--){
		int N;	cin >> N;
		int *A = new int[N];

		for(int i=0; i<N;++i)	cin >> A[i];

		int *L = new int[N];
		int *R = new int[N];
		
		for(int i=0; i<N-1; ++i){
			int j = i-1;
			int max = A[j];
			while(j>=0){
				max = (max < A[j])? A[j] : max;
				--j;
			}
			L[i] = max;

			j=i+1;
			max = A[j];
			while(j<N){
				max = (max < A[j])? A[j] : max;
				++j;
			}
			R[i] = max;
		}

		int total = 0;
		for(int i=1; i<N-1; ++i){
			if(A[i] < min(L[i], R[i]))
				total += min(L[i], R[i]) - A[i];
		}
		cout << total << endl;

		delete[] L;
		delete[] R;
		delete[] A;
	}
	return 0;
}
