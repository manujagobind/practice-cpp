#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

typedef pair<int, int> iPair;

class Graph{
	int n;
	list< pair<int, int> > *adj;
public:
	Graph(int);
	~Graph();
	void add_edge(int, int, int);	
	void shortest_path(int);
};

Graph::Graph(int n){
	this->n = n;
	adj = new list< pair<int, int> >[n];
}


Graph::~Graph(){
	delete[] adj;
}

void Graph::add_edge(int u, int v, int w){
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Dijkstra's Single Source Shortest Path Algorithm
void Graph::shortest_path(int s){
	
	vector<int> dist(n, INF);
	priority_queue< iPair, vector<iPair>, greater<iPair> > pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		list<iPair>::iterator it;
		for(it=adj[u].begin(); it!= adj[u].end(); ++it){
			int v = (*it).first;
			int weight = (*it).second;

			if(dist[v] > dist[u]+weight){
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	for(int i=0; i<n; ++i)
		cout << i << " " << dist[i] << endl;
}

int main(){

	Graph graph(9);
	graph.add_edge(0, 1, 4);
	graph.add_edge(0, 7, 8);
	graph.add_edge(1, 2, 8);
	graph.add_edge(1, 7, 11);
	graph.add_edge(2, 3, 7);
	graph.add_edge(2, 8, 2);
	graph.add_edge(2, 5, 4);
	graph.add_edge(3, 4, 9);
	graph.add_edge(3, 5, 14);
	graph.add_edge(4, 5, 10);
	graph.add_edge(5, 6, 2);
	graph.add_edge(6, 7, 1);
	graph.add_edge(6, 8, 6);
	graph.add_edge(7, 8, 7);
	graph.shortest_path(0);
	return 0;
}
