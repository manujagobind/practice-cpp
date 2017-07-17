#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, temp, count;  cin >> N;
    vector<int> W;
    for(int i=0; i<N; ++i){
        cin >> temp;
        W.push_back(temp);
    }        
    
    sort(W.begin(), W.end());
    count = 0;
    vector<int>::iterator it;    
    
    for(it=W.begin(); it!=W.end(); it=upper_bound(W.begin(), W.end(), *it + 4))
        ++count;
    
    cout << count;
    return 0;
}

