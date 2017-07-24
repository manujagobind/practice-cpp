#include <bits/stdc++.h>
using namespace std;

double search(double low, double high, double A[], int N){

	double epi = 0.0000000000001;
	double force = 0.0, mid;
	mid = (low + high) / 2.0;

	for(int i=0; i<N; ++i) force += 1.0 / (mid - A[i]);

	if(abs(force) < epi)	return mid;
	else if(force >0)	return search(mid, high, A, N);
	else	return search(low, mid, A, N);
}

int main(){

	int T;	cin >> T;
	while(T--){
		int N;	cin >> N;
		double *A = new double[N];

		for(int i=0; i<N; ++i)	cin >> A[i];

        cout << setprecision(2) << fixed;
		for(int i=0; i<N-1; ++i) cout << search(A[i], A[i+1], A, N) << " ";
        cout << endl;
		delete[] A;
	}
	return 0;
}
