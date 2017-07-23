#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	int **adj;
	bool safe(int, int[], int);
	bool paint(int, int[], int);
public:
	Graph(int);
	~Graph();
	void add_edge(int, int);
	void print_adj();
	void paint(int);
};

Graph::Graph(int V){
	this->V = V;
	adj = new int*[V];
	for(int i=0; i<V; ++i)	adj[i] = new int[V];
	for(int i=0; i<V; ++i)
		for(int j=0; j<V; ++j)	adj[i][j] = 0;
}

Graph::~Graph(){
	for(int i=0; i<V; ++i)	delete[] adj[i];
	delete[] adj;
}

void Graph::add_edge(int u, int v){
	adj[u][v] = 1;
	adj[v][u] = 1;		
}

void Graph::print_adj(){
	for(int i=0; i<V; ++i){
		for(int j=0; j<V; ++j) cout << adj[i][j] << " ";
		cout << endl;
	}
}

bool Graph::safe(int v, int color[], int c){
	/*  We cannot assign color c to a vertex if any of its 
	adjacent vertices have the same color c. */
	for(int i=0; i<V; ++i)
		if(adj[v][i] && color[i] == c)
			return false;
	return true;
}

bool Graph::paint(int m, int color[], int v){
	if(v == V)  return true;

	for(int c=1; c<=m; ++c){
		if(safe(v, color, c)){	// Check if color c can be assigned to vertex v
			color[v] = c;	// If safe, assign color c to vertex v
			if(paint(m, color, v+1)) // Check for next vertex
				return true;
			color[v] = 0; // Backtrack if no color could be assigned to the next vertex
		}
	}

	return false;
}

void Graph::paint(int m){
	int *color = new int[V];

	for(int i=0; i<V; ++i)	color[i] = 0;

	if(!paint(m, color, 0)) cout << "Nodes could not be coloured!\n";
	else{
		for(int i=0; i<V; ++i)	cout << color[i] << " ";
		cout << endl;
	}

	delete[] color;
}

int main(){

	Graph G(4);
	G.add_edge(0, 1);
	G.add_edge(0, 2);
	G.add_edge(0, 3);
	G.add_edge(1, 2);
	G.add_edge(2, 3);
	G.paint(3);	
	return 0;
}
