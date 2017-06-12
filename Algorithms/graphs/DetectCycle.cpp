#include <iostream>
#include <list>
using namespace std;

class Graph{
	int n;
	list<int> *adj;
	bool hasCycle(int, bool*, bool*);
public:
	Graph(int);
	~Graph();
	void addEdge(int, int);
	bool hasCycle();
};

Graph::Graph(int n){
	this->n = n;
	adj = new list<int>[n];
}

Graph::~Graph(){
	delete[] adj;
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

bool Graph::hasCycle(int v, bool *visited, bool *recStack){
	if(!visited[v]){
		visited[v] = true;
		recStack[v] = true;

		list<int>::iterator it;
		for(it=adj[v].begin(); it!=adj[v].end(); ++it){
			if(!visited[*it] && hasCycle(*it, visited, recStack))
				return true;
			else if(recStack[*it])
				return true;
		}
	}
	recStack[v] = false;
	return false;
}

bool Graph::hasCycle(){
	bool *visited, *recStack;
	visited = new bool[n];
	recStack = new bool[n];

	for(int i=0; i<n; ++i)
		visited[i] = recStack[i] = false;

	for(int i=0; i<n; ++i)
		if(hasCycle(i, visited, recStack))
			return true;

	delete[] recStack;
	delete[] visited;
}

int main(){
	Graph G(4);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(3, 3);

	cout << (G.hasCycle()? "Has cycle.\n" : "No cycle\n");	
	return 0;
