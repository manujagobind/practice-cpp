#include <iostream>
#include <algorithm>
using namespace std;

class DisjointSets{
	int *parent;
	int *size;
	int N;
	int root(int);
public:
	DisjointSets(int);	
	void unite(int, int);	
    void print();
    void getResult();
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
	}}
}

void DisjointSets::print(){
	for(int i=0; i<N; i++)
		cout << parent[i] << " ";
	cout << endl;
}

void DisjointSets::getResult(){
    int *temp = new int[N];
    for(int i=1; i<N;i++)
        temp[i] = size[root(i)];
    sort(temp+1, temp+N);
    int i=1;
    while(temp[i] <= 1)
        i++;    
    cout << temp[i] << " ";
    i = N-1;
    while(temp[i] <= 1)
        i--;
    cout << temp[i];
    delete temp;
}

int main(){

    int N, g, b;
    cin >> N;
    DisjointSets sets(2*N+1);        
    for(int i=0; i<N; i++){
        cin >> g >> b;
        sets.unite(g, b);
    }    
    sets.getResult();
	return 0;
}
