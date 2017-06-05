#include <iostream>
#define MAX 10
using namespace std;

class RatInAMaze{
	int N;
	int **solution;
	bool safe(int[][MAX], int, int);
	bool solve(int[][MAX], int, int);
	void print();
public:
	RatInAMaze(int);
	~RatInAMaze();
	void solve(int[][MAX]);
};

RatInAMaze::RatInAMaze(int N){
	this->N = N;
	solution = new int*[N];
	for(int i=0; i<N; ++i)
		solution[i] = new int[N];
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			solution[i][j] = 0;
}

RatInAMaze::~RatInAMaze(){
	delete[] solution;
}

void RatInAMaze::print(){
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			cout << solution[i][j] << " ";
		cout << endl;
	}
}

bool RatInAMaze::safe(int maze[][MAX], int x, int y){
	return (x>=0 && x<N && y>=0 && y<N && maze[x][y]);
}

bool RatInAMaze::solve(int maze[][MAX], int x, int y){
	if(x==N-1 && y==N-1){
		solution[x][y] = 1;
		return true;
	}

	if(safe(maze, x, y)){
		solution[x][y] = 1;
		
		if(solve(maze, x+1, y))
			return true;
		if(solve(maze, x, y+1))
			return true;

		solution[x][y] = 0;
	}
	return false;
}

void RatInAMaze::solve(int maze[][MAX]){
	if(solve(maze, 0, 0))
		print();
	else
		cout << "No solution!\n";
}

int main(){

	int maze[][MAX] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
	RatInAMaze solver(4);
	solver.solve(maze);
	return 0;
}
