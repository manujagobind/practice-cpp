#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    deque<int> dq;
    int sum = 0, count = 0;
    for(int i=0; i<m; ++i){
        sum += s[i];
        dq.push_back(s[i]);        
    }

    if(sum == d) ++count;
    
    for(int i=m; i<n; ++i){
        sum -= dq.front(); dq.pop_front();
        sum += s[i]; dq.push_back(s[i]);
        if(sum == d) ++count;
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}

