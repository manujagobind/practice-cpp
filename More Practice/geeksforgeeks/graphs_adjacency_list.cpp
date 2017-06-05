#include <iostream>
using namespace std;

class Node{
public:
	int dest;
	Node *next;
	Node(int);
};

Node::Node(int dest){
	this->dest = dest;
	next = NULL;
}

class AdjList{
public:
	Node *head;
	AdjList();
};

AdjList::AdjList(){
	head = NULL;
}

class Graph{
	int n;
	AdjList *list;
public:
	Graph(int);	
	void print();
	void addEdge(int, int);
};

Graph::Graph(int n){
	this->n = n;
	this->list = new AdjList[this->n];
}

void Graph::print(){
	for(int i=0;i<n;i++){
		Node *cursor = list[i].head;
		cout << i << " --> ";
		while(cursor){
			cout << cursor->dest << " ";
			cursor = cursor->next;
		}	
		cout << "\n";
	}
}

void Graph::addEdge(int src, int dest){
	Node *node1 = new Node(src);
	Node *node2 = new Node(dest);

	node1->next = list[dest].head;
	list[dest].head = node1;

	node2->next = list[src].head;
	list[src].head = node2;
}

int main(){

	Graph G(5);
	G.addEdge(0, 1);
	G.addEdge(0, 4);
	G.addEdge(1, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 4);
	G.addEdge(2, 3);
	G.addEdge(3, 4);
	G.print();
	return 0;
}
