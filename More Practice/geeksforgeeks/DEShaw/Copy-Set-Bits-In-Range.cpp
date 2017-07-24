#include <bits/stdc++.h>
using namespace std;

int main(){

	int T;	cin >> T;
	while(T--){

		unsigned int x, y, l, r, mask, len;
		cin >> x >> y >> l >> r;
	
		len = (1 << (r-l+1)) - 1;
		cout << len << endl;	
		mask = (len<<(l-1)) & y;
		cout << mask << endl;
		x = x | mask;
		cout << x << endl;
	}
	return 0;
}
