#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V, E;    
    list<int> *adj;
    int *vertices;
    void DFS(int, int[]);
public:
    Graph(int, int);
    ~Graph();
    void add_edge(int, int);    
    void even_tree(int);
};

Graph::Graph(int V, int E){
    this->V = V;
    this->E = E;
    adj = new list<int>[V];
    vertices = new int[V];
    for(int i=0; i<V; ++i)
        vertices[i] = 1;
}

Graph::~Graph(){
    delete[] vertices;
    delete[] adj;    
}

void Graph::add_edge(int u, int v){    
    adj[v-1].push_back(u-1);
}

void Graph::DFS(int v, int color[]){
    color[v] = 1;
    list<int>::iterator it;       
    
    if(!adj[v].empty()){
        for(it=adj[v].begin(); it!=adj[v].end(); ++it){
            if(!color[*it]){
                DFS(*it, color);                   
                vertices[v] += vertices[*it];
            }
        }            
    }      
}

void Graph::even_tree(int s){
    int *color = new int[V];
    for(int i=0; i<V; ++i)
        color[i] = 0;         
    DFS(s, color);        
    int count = 0;
    for(int i=0; i<V; ++i)
        if(vertices[i] % 2 == 0)
            ++count;    
    cout << count-1;
    delete[] color;
}

int main(){
    
    int V, E;   cin >> V >> E;
    Graph G(V, E);
    
    while(E--){
        int u, v;   cin >> u >> v;
        G.add_edge(u, v);
    }
        
    G.even_tree(0);
    
    return 0;
}
