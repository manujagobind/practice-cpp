#include <bits/stdc++.h>
#define MAX 10
using namespace std;

void spiral_traversal(int A[][MAX], int x, int y, int size){
	
	int i;
	for(i=y; i<size-y; ++i)
		cout << A[x][i] << " ";
	for(i=x+1; i<size-x; ++i)
		cout << A[i][size-y-1] << " ";
	for(i=size-2-y; i>=y; --i)
		cout << A[size-x-1][i] << " ";
	for(i=size-2-x; i>x; --i)
		cout << A[i][y] << " ";
}

int main(){

	int size=6;
	int A[MAX][MAX];
	int count = 1;

	for(int i=0; i<size; ++i)
		for(int j=0; j<size; ++j)
			A[i][j] = count++;

	for(int i=0; i<size/2; ++i)
		spiral_traversal(A, i, i, size);
	cout << endl;

	return 0;
}
