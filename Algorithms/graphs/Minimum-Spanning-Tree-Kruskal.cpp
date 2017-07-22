#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)
#define F first
#define S second

using namespace std;

typedef pair< int, pair<int, int> > Edge;

class Graph{
	int E, V;
	vector<Edge> edges;
public:
	Graph(int, int);
	void add_edge(int, int, int);
	void min_spanning_tree();
};

class DisjointSets{

	int *parent;
	int *size;
	int N;
	int root(int);
public:
	DisjointSets(int);
	~DisjointSets();
	bool find(int, int);
	void unite(int, int);
};

DisjointSets::DisjointSets(int N){
	this->N = N;
	parent = new int[N];
	size = new int[N];
	for(int i=0; i<N; ++i){
		parent[i] = i;
		size[i] = 1;
	}
}

DisjointSets::~DisjointSets(){
	delete[] size;
	delete[] parent;
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
	if (i != j){
		if(size[i] < size[j]){
			parent[i] = j;
			size[j] += size[i];
		} else{
			parent[j] = i;
			size[i] += size[j];
		}
	}
}

Graph::Graph(int V, int E){
	this->V = V;
	this->E = E;
}

void Graph::add_edge(int u, int v, int w){
	edges.push_back(mp(w, mp(u, v)));
}

// Kruskal's Algorithm
void Graph::min_spanning_tree(){

	int mst_wt = 0;

	DisjointSets sets(V);	// Each vertex represents an independent set
	sort(edges.begin(), edges.end());	// Sort edges in increasing order of weight

	cout << "Edges in MST:\n\n";

	for(Edge edge : edges){		// For each edge
		if(!sets.find(edge.S.F, edge.S.S)){	// If its end vertices belong to different sets
			cout << "\t" << edge.S.F << " - (" << edge.F <<  ") -> " << edge.S.S << endl;
			sets.unite(edge.S.F, edge.S.S);	// Merge the two sets
			mst_wt += edge.F;
		}
	}

	cout << "\nTotal Weight of MST = " << mst_wt << endl;
}

int main(){

	Graph G(9, 14);
	G.add_edge(0, 1, 4);
	G.add_edge(0, 7, 8);
	G.add_edge(1, 2, 8);
	G.add_edge(1, 7, 11);
	G.add_edge(2, 3, 7);
	G.add_edge(2, 8, 2);
	G.add_edge(2, 5, 4);
	G.add_edge(3, 4, 9);
	G.add_edge(3, 5, 14);
	G.add_edge(4, 5, 10);
	G.add_edge(5, 6, 2);
	G.add_edge(6, 7, 1);
	G.add_edge(7, 8, 7);
	G.min_spanning_tree();
	return 0;
}
