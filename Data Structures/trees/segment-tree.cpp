#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

/* Perform range operations in O(logN) with segment trees */

/* This implementation finds the minimum element in an subarray in O(logN) as opposed to the simple for loop approach which does it in O(N) */


int tree[5000];
int A[5000];

int build(int node, int start, int end){
	if(start == end){
		tree[node] = A[start];	
	}
	else{
		int mid = (start + end)>>1;
		build(node<<1, start, mid);
		build(node<<1|1, mid+1, end);
		
		tree[node] = min(tree[node<<1], tree[node<<1|1]);
	}
}

int query(int node, int start, int end, int l, int r){
	if(start>r||end<l)return INF;
	if(l<=start && end<=r)return tree[node];
	else{
		int mid = (start+end)>>1;
		int a = query(node<<1, start, mid, l, r);
		int b = query(node<<1|1, mid+1, end, l, r);
		return min(a,b);	
	}
}

int update(int node, int start, int end, int idx, int val){
	if(start == end && start == idx){
		tree[node] = val;
		A[idx] = val;
	}
	else{
		int mid = (start + end)>>1;
		if(idx<=mid) update(node<<1, start, mid, idx, val);
		else update(node<<1|1, mid+1, end, idx, val);
		tree[node] = min(tree[node<<1], tree[node<<1|1]);
	}
}

int main(){
	
	int n, q;
	cin >> n >> q; // read in number of elements and number of queries
	
	for(int i=0;i<n;i++) cin >> A[i]; // read in array
	
	build(1, 0, n-1); // build segment tree
	
	while(q--){
		// each query is of two types - type 1 (update an index) OR type 2 (query a subarray)
		
		int type;
		cin >> type; // whether query or update	on array
		
		if(type == 1){ // if update an index
			int idx, val;
			cin >> idx >> val;
			idx--; // remove 1-based indexing
			update(1, 0, n-1, idx, val);
		}
		
		else if(type == 2){	// if to query the minimum of a subarray
			int l, r;
			cin >> l >> r;
			l--, r--;
			cout << "Minimum element from index "<<l<<" to index "<<r<<" is "<< query(1, 0, n-1, l, r) <<"\n";
		}
	}
	
	/* Total complexity = O( n + qLogn )
}



