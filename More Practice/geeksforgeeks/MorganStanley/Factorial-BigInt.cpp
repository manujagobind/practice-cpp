#include <bits/stdc++.h>
using namespace std;

void multiply(int n, deque<int> &result){

	int carry = 0;
	deque<int>::iterator it;

	for(it=result.begin(); it!=result.end(); ++it){
		int prod = *it * n + carry;
		carry = prod / 10;
		prod %= 10;
		*it = prod;
	}

	while(carry){
		result.push_back(carry%10);
		carry /= 10;
	}
}

void factorial(int n){
	deque<int> result;
	result.push_front(1);	// MSB is at right end

	for(int i=2; i<=n; ++i)	
		multiply(i, result);

	while(!result.empty()){
		cout << result.back();
		result.pop_back();
	}
	cout << endl;
}

int main(){

	factorial(100);
	return 0;
}
