#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

/* Finds longest increasing subsequence in O(N logN) time, using binary search */

int main(){
	int n;
	cin >> n;
	
	vector<int> A(n);
	vector<int> lis(n+1, INF);
	
	for(int i=0;i<n;i++) cin >> A[i];
	
	/* for non-decreasing subsequence, change lower_bound to upper_bound */
	for(int i=0;i<n;i++) *lower_bound(lis.begin(), lis.end(), A[i]) = A[i];
	
	for(int i=0;i<=n;i++) 
		if(lis[i] == INF) { 
			cout << i ; 
			break;
		}
	
}
