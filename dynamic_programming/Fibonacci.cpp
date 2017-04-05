#include <iostream>
#define MAX 20
#define NIL -1
using namespace std;

int lookup[MAX];

void initialize_lookup(){
	for(int i=0; i < MAX; i++)
		lookup[i] = NIL;
}

int fibonacci(int n){
	
	if(lookup[n] == NIL){
		
		if(n <= 1)
			lookup[n] = n;
		else
			lookup[n] = fibonacci(n-1) + fibonacci(n-2);
	}
	
	return lookup[n];
}

int main(){
	
	initialize_lookup();
	cout << fibonacci(10) << endl;
	return 0;
}
