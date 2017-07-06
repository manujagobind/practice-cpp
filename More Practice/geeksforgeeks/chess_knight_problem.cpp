#include <bits/stdc++.h>
#define N 8
using namespace std;

int row[] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[] = {-1, 1, 1, -1, 2, -2, 2, -2};

bool valid(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}

class Node{
public:    
    int x, y, dist;
    bool const operator==(const Node& o) const{
        return x == o.x && y == o.y;
    }
    bool operator<(const Node& o) const{
        return x < o.x || (x == o.x && y < o.y);
    }
    Node(int x, int y, int dist=0){
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

int BFS(Node src, Node dest){
    map<Node, bool> visited;
    queue<Node> q;
    q.push(src);
    
    while(!q.empty()){
        Node node = q.front(); q.pop();
        
        int x = node.x;
        int y = node.y;
        int dist = node.dist;
        
        if(x == dest.x && y == dest.y)
            return dist;
        
        if(!visited.count(node)){
            visited[node] = true;
            for(int i=0; i<8; ++i){
                int x1 = x + row[i];
                int y1 = y + col[i];
                
                if(valid(x1, y1))
                    q.push(Node(x1, y1, dist+1));
            }
        }
    }
    return -1;
}

int main() {

    Node src(0, 0);
    Node dest(0, 7);
    cout << BFS(src, dest) << endl; 
    return 0;
}

