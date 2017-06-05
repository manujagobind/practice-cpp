#include <iostream>
using namespace std;

void printMatrix(int a[][300], int m, int n){

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}		
}

void rotateLoop(int a[][300], int M, int N, int m, int n, int r){

	while(r--){
		int temp = a[m][n], i;
		for(i=n; i<N-n-1;i++)
			a[m][i] = a[m][i+1];
		for(i=m; i<M-m-1;i++)
			a[i][N-n-1] = a[i+1][N-n-1];
		for(i=N-n-1;i>n;i--)
			a[M-m-1][i] = a[M-m-1][i-1];
		for(i=M-m-1;i>m;i--)
			a[i][n] = a[i-1][n];
		a[m+1][n] = temp;
	}
}

int main() {
    int M, N, R;
    cin >> M >> N >> R;
    int a[300][300];
    for(int i=0; i<M; i++)
        for(int j=0; j<N;j++)
            cin >> a[i][j];
    int t = min(M, N);
    for(int k=0; k<t/2; k++){
        int m = M - 2*k;
        int n = N - 2*k;
        int r = R % (2*n + 2*(m-2));
        rotateLoop(a, M, N, k, k, r);
    }
    printMatrix(a, M, N);
    return 0;
}
