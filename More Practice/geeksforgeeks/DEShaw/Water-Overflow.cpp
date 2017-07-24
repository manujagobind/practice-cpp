#include <bits/stdc++.h>
using namespace std;

int main(){

	int T;	cin >> T;
	while(T--){
		int K, row, glass;
		cin >> K >> row >> glass;
		--row;	--glass;

		double M[K][K];
		memset(M, 0.0, sizeof(M));
		M[0][0] = K;

		for(int i=0; i<K-1; ++i)
			for(int j=0; j<=i; ++j){
				if(M[i][j] > 1){
					double diff = M[i][j] - 1.0;
					M[i][j] = 1;
					M[i+1][j] += (double)diff / 2.0;
					M[i+1][j+1] += (double)diff/2.0;
				}
			}
	
		cout << M[row][glass] << endl;
	}
	return 0;
}
