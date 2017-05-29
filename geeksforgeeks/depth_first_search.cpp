#include <iostream>
#include <list>
using namespace std;

class Graph{
	int n;
	list< int > *adj;
	void DFSHelper(int, bool[]);
public:
	Graph(int);
	void addEdge(int, int);
	void DFS(int);
};

Graph::Graph(int n){
	this->n = n;
	adj = new list< int >[n];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::DFSHelper(int v, bool visited[]){
	visited[v] = true;
	cout << v << " ";

	list< int >::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++)
		if(!visited[*i])
			DFSHelper(*i, visited);
}

void Graph::DFS(int s){
	bool *visited = new bool[n];
	for(int i=0; i<n; i++)
		visited[i] = false;
	DFSHelper(s, visited);
}

int main(){

	Graph G(4);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(3, 3);
	G.DFS(2);
	return 0;
}
