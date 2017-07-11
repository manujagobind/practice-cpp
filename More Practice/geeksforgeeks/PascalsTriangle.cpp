#include <bits/stdc++.h>
using namespace std;

class PascalsTriangle{
	long binomialCoeff(int, int);
public:
	void print(int);
};

long  PascalsTriangle::binomialCoeff(int n, int k){
	int result = 1;
	if (k > n-k) k = n-k;
	for(int i=0; i<k; ++i){
		result *= (n - i);
		result /= (i + 1);
	}
	return result;
}

void PascalsTriangle::print(int n){
	for(int i=0; i<n; ++i){
		for(int j=0; j<=i; ++j)
			cout << binomialCoeff(i, j) << " ";
		cout << endl;
	}
}

int main(){

	PascalsTriangle Pascal;
	Pascal.print(10);
	return 0;
}
