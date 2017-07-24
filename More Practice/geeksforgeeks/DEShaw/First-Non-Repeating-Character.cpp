#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;  cin >> T;
    while(T--){
        int N; string S;
        cin >> N >> S;
        int count, i, j;
        map<char, int> M;
	i=0;
	while(S[i]){
		if(M.find(S[i]) != M.end())
			M[S[i]] = M[S[i]] + 1;
		else
			M.insert(make_pair(S[i], 1));
		++i;
	}
	i=0;
	char c = '\0';
	while(S[i]){
		if(M[S[i]] == 1){
			c = S[i];
			break;
		}
		++i;
	}

	if(c != '\0')	cout << S[i] << endl;
	else	cout << "-1\n";
    }
    return 0;
}
