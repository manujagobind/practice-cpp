#include <iostream>
using namespace std;

class DisjointSets{
	int *parent;
	int *size;
	int N;
	int root(int);
public:
	DisjointSets(int);	
	void unite(int, int);	
    int getSize(int);
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
    if(i!=j){
	if(size[i] < size[j]){
		parent[i] = j;
		size[j] += size[i];
	} else{
		parent[j] = i;
		size[i] += size[j];
	}}
}

int DisjointSets::getSize(int i){
    return size[root(i)];
}

int main(){

    int N, Q;   cin >> N >> Q;
	DisjointSets sets(N);
	while(Q--){
        int x, y;
        char query; cin >> query;
        switch(query){
            case 'Q':                
                cin >> x;
                cout << sets.getSize(x) << endl;
            break;
            case 'M':
                cin >> x >> y;
                sets.unite(x, y);
        }
    }
	return 0;
}
