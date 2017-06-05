#include <iostream>
using namespace std;

class NQueensSolver{
	int N;
	int **board;
	bool safe(int, int);
	bool solve(int, int);
	void print();
public:
	NQueensSolver(int);
	~NQueensSolver();
	void solve();
};

NQueensSolver::NQueensSolver(int N){
	this->N = N;
	board = new int*[N];
	for(int i=0; i<N; ++i)
		board[i] = new int[N];
}

NQueensSolver::~NQueensSolver(){
	delete[] board;
}

void NQueensSolver::print(){
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

bool NQueensSolver::safe(int row, int col){
	int r=row, c=col;
	while(c >= 0){
		if(board[r][c]==1)
			return false;
		--c;
	}
	c=col;
	while(r>=0 && c>=0){
		if(board[r][c]==1)
			return false;
		--r;
		--c;
	}
	r=row; c=col;
	while(r<N && c>=0){
		if(board[r][c]==1)
			return false;
		++r;
		--c;
	}
	return true;
}

bool NQueensSolver::solve(int row, int col){
	if(col >= N)
		return true;
	for(int i=0; i<N; ++i){
		if(safe(i, col)){
			board[i][col] = 1;
			if(solve(i, col+1))
				return true;
			else
				board[i][col] = 0;
		}
	}	
	return false;		
}

void NQueensSolver::solve(){
	if(solve(0, 0))
		print();
	else
		cout << "Cannot be solved!\n";
}

int main(){

	NQueensSolver solver(8);
	solver.solve();
	return 0;
}
