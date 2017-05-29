#include <iostream>
#include <list>
using namespace std;

class Graph{
	int n;
	list< int > *adj;
public:
	Graph(int);
	void addEdge(int, int);
	void BFS(int);
};

Graph::Graph(int n){
	this->n = n;
	adj = new list< int >[n];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::BFS(int s){
	bool *visited = new bool[n];
	for(int i = 0 ; i < n ; i++)
		visited[i] = false;

	list< int > queue;
	visited[s] = true;
	queue.push_back(s);

	list< int >::iterator i;

	while(!queue.empty()){
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for(i=adj[s].begin(); i!=adj[s].end(); i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main(){

	Graph G(4);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(3, 3);
	G.BFS(2);
	return 0;
}
