#include <bits/stdc++.h>

#define INF INT_MAX
#define mp(a, b) make_pair(a, b)
#define F first
#define S second

using namespace std;

typedef pair<int, int> iPair;
typedef pair< int, pair<int, int> > Edge;

class Graph{
	int V, E;
	vector<Edge> edges;
public:
	Graph(int, int);
	void add_edge(int, int, int);
	void shortest_path(int);
};

Graph::Graph(int V, int E){
	this->V = V;
	this->E = E;
}

void Graph::add_edge(int u, int v, int w){
	edges.push_back(mp(w, mp(u, v)));
}

// Bellman Ford's Single Source Shortest Path Algorithm
void Graph::shortest_path(int s){
	
	int *distance = new int[V];
	int *parent = new int[V];

	for(int i=0; i<V; ++i){
		distance[i] = INF;
		parent[i] = -1;
	}
	
	distance[s] = 0;

	for(int i=1; i<V; ++i){
		for(Edge edge : edges){
			if(distance[edge.S.S] > distance[edge.S.F] + edge.F){
				distance[edge.S.S] = distance[edge.S.F] + edge.F;
				parent[edge.S.S] = edge.S.F;
			}
		}
	}

	cout << "Vertex\tDist\tParent\n";
	for(int i=0; i<V; ++i){
		cout << " " << i << " \t" << distance[i] << "\t" << parent[i] << endl;
	}

	delete[] parent;
	delete[] distance;
}

int main(){

	Graph G(5, 7);
	G.add_edge(0, 1, 4);
	G.add_edge(0, 2, 5);	
	G.add_edge(0, 3, 8);
	G.add_edge(1, 2, -3);
	G.add_edge(2, 4, 4);
	G.add_edge(3, 4, 2);
	G.add_edge(4, 3, 1);
	G.shortest_path(0);
	return 0;
}
