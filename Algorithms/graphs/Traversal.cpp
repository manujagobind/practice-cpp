#include <iostream>
#include <list>
using namespace std;

class Graph{
	int n;
	list<int> *adj;
	void DFS(int, bool[]);
public:
	Graph(int);
	~Graph();
	void addEdge(int, int);
	void BFS(int);		// Breadth first seearch
	void DFS(int);		// Depth first search
	void IDFS(int); 	// Iterative depth first search
	bool DLS(int, int, int);	// Depth Limited Search
	bool IDDFS(int, int, int);	// Iterative deepening depth first search
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

void Graph::BFS(int s){
	bool *visited = new bool[n];
	for(int i=0; i<n; ++i)
		visited[i] = false;

	list<int> q;
	list<int>::iterator it;
	visited[s] = true;
	q.push_back(s);

	while(!q.empty()){
		s = q.front();
		std::cout << s << " ";
		q.pop_front();
		
		for(it = adj[s].begin(); it != adj[s].end(); ++it)
			if(!visited[*it]){
				visited[*it] = true;
				q.push_back(*it);
			}
	}

	std::cout << std::endl;
	delete[] visited;
}

void Graph::DFS(int v, bool visited[]){
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); ++it)
		if(!visited[*it])
			DFS(*it, visited);
}

void Graph::DFS(int s){
	bool *visited = new bool[n];
	for(int i=0; i<n; ++i)
		visited[i] = false;	
	DFS(s, visited);
	std::cout << std::endl;
	delete[] visited;
}

void Graph::IDFS(int s){
	bool *visited = new bool[n];
	for(int i=0; i<n; ++i)
		visited[i] = false;

	list<int> stack;
	list<int>::iterator it;
	stack.push_back(s);
	
	while(!stack.empty()){
		s = stack.back();
		stack.pop_back();

		if(!visited[s]){
			cout << s << " ";
			visited[s] = true;
		}
	
		for(it = adj[s].begin(); it != adj[s].end(); ++it)
			if(!visited[*it])
				stack.push_back(*it);
	}

	std::cout << std::endl;
	delete[] visited;
}

bool Graph::DLS(int src, int dest, int limit){
	if(src == dest)
		return true;

	if(limit <= 0)
		return false;
	
	list<int>::iterator it;
	for(it=adj[src].begin(); it!=adj[src].end(); ++it)
		if(DLS(*it, dest, limit-1))
			return true;

	return false;
}

bool Graph::IDDFS(int src, int dest, int max_depth){
	for(int i=0; i<= max_depth; ++i)
		if(DLS(src, dest, i))
			return true;
	return false;
}

int main(){
	Graph G(7);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 4);
	G.addEdge(2, 5);
	G.addEdge(2, 6);

	G.BFS(0);
	G.DFS(0);
	G.IDFS(0);

	cout << G.IDDFS(0, 6, 3) << endl;
	return 0;
}
