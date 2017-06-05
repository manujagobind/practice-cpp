#include <iostream>
using namespace std;

class DisjointSets{
	int *parent;
	int *size;
	int N;
	int root(int);
public:
	DisjointSets(int);
	bool find(int, int);
	void unite(int, int);
	void print();
};

DisjointSets::DisjointSets(int N){
	this->N = N;
	parent = new int[N];
	size = new int[N];
	for(int i=0; i<N; i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int DisjointSets::root(int i){
	while(i != parent[i]){
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
	return i;
}

bool DisjointSets::find(int p, int q){
	return root(p) == root(q);
}

void DisjointSets::unite(int p, int q){
	int i = root(p);
	int j = root(q);
	if(i != j){
		if(size[i] < size[j]){
			parent[i] = j;
			size[j] += size[i];
		} else{
			parent[j] = i;
			size[i] += size[j];
		}
	}
}

void DisjointSets::print(){
	for(int i=0; i<N; i++)
		cout << parent[i] << " ";
	cout << endl;
}

int main(){

	DisjointSets sets(10);
	sets.unite(2, 9);
	sets.unite(4, 9);
	sets.unite(3, 4);
	sets.unite(5, 6);
	sets.print();
	cout << sets.find(2, 4) << endl;
	return 0;
}
