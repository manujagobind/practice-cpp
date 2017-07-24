#include <bits/stdc++.h>
using namespace std;

int main(){

	int T;	cin >> T;
	while(T--){
		int N;	cin >> N;
		int *A = new int[N];
		int *left = new int[N];
		int *right = new int[N];

		for(int i=0; i<N; ++i) left[i] = right[i] = 1;
		for(int i=0; i<N; ++i)	cin >> A[i];
	
		for(int i=1; i<N; ++i) left[i] = A[i-1] * left[i-1];
		for(int i=N-2; i>=0; --i) right[i] = A[i+1] * right[i+1];

		for(int i=0; i<N; ++i) cout << left[i] * right[i] << " ";

		cout << endl;
		delete[] left;
		delete[] right;
		delete[] A;
	}
	return 0;
}
