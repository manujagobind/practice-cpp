#include<bits/stdc++.h>
using namespace std;

// Fast implementation of disjoint sets

int par[1000];

int find(int i){
	return par[i] = (par[i]==i)? i : find(par[i]);	
}

int unite(int i, int j){
	if(find(i) < find(j))
		swap(i, j);
	par[i] = find(par[j]);
}

int main(){
	int n = 10;
	
	for(int i=0;i<=n;i++) par[i] = i;
	
	unite(1, 2);
	unite(2, 5);
	unite(3, 4);
	
	if(find(1) == find(5))
		cout << "1 and 5 are connected.\n";
	
	if(find(3) != find(1))
		cout << "3 and 1 are disconnected.\n";
	
}
