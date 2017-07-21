#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topological_sort(int, bool[], stack<int>&);
public:
	Graph(int);
	~Graph();
	void add_edge(int, int);
	void topological_sort(); // Using stack and a bool visited array
	void kahns_topological_sort();	// Kahn's Algorithm: using indegrees of vertices and a queue
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph(){
	delete[] adj;
}

void Graph::add_edge(int u, int v){
	adj[u].push_back(v);
}

void Graph::topological_sort(int v, bool visited[], stack<int> &S){
	visited[v] = true;	// Mark vertex as visited
	
	list<int>::iterator it;
	for(it=adj[v].begin(); it!=adj[v].end(); ++it)	
		if(!visited[*it])
			topological_sort(*it, visited, S);	// Completely explore the vertex

	S.push(v);	// Add vertex to the stack
}

void Graph::topological_sort(){
	bool *visited = new bool[V];
	stack<int> S;

	for(int i=0; i<V; ++i)	// Mark all vertices as unvisited
		visited[i] = false;

	for(int i=0; i<V; ++i)
		if(!visited[i])	
			topological_sort(i, visited, S);

	while(!S.empty()){	// Pop and display items from the stack 
		cout << S.top() << " ";
		S.pop();
	}

	cout << endl;
	delete[] visited;
}

void Graph::kahns_topological_sort(){
	
	vector<int> in_degree(V, 0);	// Initialize indegree of all vertices to 0

	for(int i=0; i<V; ++i){
		list<int>::iterator it;
		for(it = adj[i].begin(); it!=adj[i].end(); ++it)
			in_degree[*it]++;	// Increment indegree of a vertex if it has an incoming edge
	}

	queue<int> Q;

	// Add all vertices with indegree 0 to the queue
	for(int i=0; i<V; ++i)
		if(in_degree[i] == 0)
			Q.push(i);

	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		cout << u << " ";

		list<int>::iterator it;	
		for(it=adj[u].begin(); it!=adj[u].end(); ++it){
			--in_degree[*it];	// Decrement indegrees of all vertices adjacent to u
			if(in_degree[*it] == 0)	// If indegree of any vertex becomes zero, add it to the queue
				Q.push(*it);
		}			
	}

	cout << endl;
}

int main(){

	Graph G(6);
	G.add_edge(5, 2);
	G.add_edge(5, 0);
	G.add_edge(4, 0);
	G.add_edge(4, 1);
	G.add_edge(2, 3);
	G.add_edge(3, 1);
	G.topological_sort();
	G.kahns_topological_sort();
	return 0;
}
