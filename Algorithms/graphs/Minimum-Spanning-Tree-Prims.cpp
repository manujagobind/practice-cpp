#include <bits/stdc++.h>

#define INF INT_MAX
#define mp(a, b) make_pair(a, b)
#define F first
#define S second

using namespace std;

typedef pair<int, int> iPair;

class Graph{
	int V;
	list<iPair> *adj;
public:
	Graph(int V);
	~Graph();
	void add_edge(int, int, int);
	void prims_min_spanning_tree();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<iPair>[V];
}

Graph::~Graph(){
	delete[] adj;
}

void Graph::add_edge(int u, int v, int w){
	adj[u].push_back(mp(v, w));
	adj[v].push_back(mp(u, w));
}

void Graph::prims_min_spanning_tree(){

	priority_queue< iPair, vector<iPair>, greater<iPair> > pq;
	vector<int> key(V, INF);	// Priority queue of STL doesn't support DecreaseKey(), hence we have a separate key vector
	vector<int> parent(V, -1);
	vector<bool> inMST(V, false);	// To keep track of vertices already added in the MST

	int src = 0;
	pq.push(mp(0, src));	// Insert source vertex into the priority queue
	key[src] = 0;	// Key of source is set to 0

	while(!pq.empty()){
		int u = pq.top().S; pq.pop();	// Extract min
		inMST[u] = true;	// Add to MST
		for(list<iPair>::iterator it=adj[u].begin(); it != adj[u].end(); ++it){
			int v = (*it).F;
			int wt = (*it).S;
			
			// If adjacent vertices of u are not in MST and have 
			// greater key than the weight(u, v), then we update their key values
			if(!inMST[v] && key[v] > wt){
				key[v] = wt;
				pq.push(mp(key[v], v));
				parent[v] = u;
			}
		}
	}


	for(int i=1; i<V; ++i)
		cout << parent[i] << " - (" << key[i] << ") -> " << i << endl;
}

int main(){

	Graph G(9);
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
	G.add_edge(6, 8, 6);
	G.add_edge(7, 8, 7);
	G.prims_min_spanning_tree();
	return 0;
}

