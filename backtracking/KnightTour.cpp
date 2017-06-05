#include <iostream>
using namespace std;

class KnightTour{
	int *xMoves, *yMoves;
	int **matrix, N;
	bool safe(int, int) const;
	bool solve(int, int, int);
	void print();
public:
	KnightTour(int);
	~KnightTour();
	void solve();
};

KnightTour::KnightTour(int N){
	this->N = N;
	xMoves = new int[8];
	yMoves = new int[8];
	matrix = new int*[N];
	for(int i=0; i<N; ++i)
		matrix[i] = new int[N];
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			matrix[i][j] = -1;
	//x[] = {2, 2, -2, -2, 1, 1, -1, -1} and y[] = {1, -1, 1, -1, 2, -2, 2, -2}
	xMoves[0] = xMoves[1] = 2;
	xMoves[2] = xMoves[3] = -2;
	xMoves[4] = xMoves[5] = 1;
	xMoves[6] = xMoves[7] = -1;
	yMoves[0] = yMoves[2] = 1;
	yMoves[1] = yMoves[3] = -1;
	yMoves[4] = yMoves[6] = 2;
	yMoves[5] = yMoves[7] = -2;	
}

KnightTour::~KnightTour(){
	delete xMoves;
	delete yMoves;
	delete[] matrix;
}

bool KnightTour::safe(int x, int y) const {
	return (x >= 0 && x < N && y >= 0 && y < N && matrix[x][y] == -1);
}

void KnightTour::print(){
	std::cout << "Solution:\n";
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}

bool KnightTour::solve(int x, int y, int move){
	std::cout << "Move " << move << std::endl;
	if(move == N*N)
		return true;
	int nextX, nextY;
	for(int i=0; i<8; i++){
		nextX = x + xMoves[i];
		nextY = y + yMoves[i];
		if(safe(nextX, nextY)){
			matrix[nextX][nextY] = move;
			if(solve(nextX, nextY, move+1))
				return true;
			else
				matrix[nextX][nextY] = -1;
		}	
	}
	return false;
}

void KnightTour::solve(){
	matrix[0][0] = 0;
	if(solve(0, 0, 1))
		print();
	else
		std::cout << "Solution does not extst!\n";
}

int main(){

	KnightTour solver(8);
	solver.solve();
	return 0;
}
