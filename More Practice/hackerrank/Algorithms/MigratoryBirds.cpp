#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    map<int, int> m;
    map<int, int>:: iterator it;
    
    for(int a : ar){
        if(m.find(a) == m.end()) m.insert(make_pair(a, 1));
        else m[a] = m[a] + 1;
    }
    
    int freq = 0, id=0;
    for(auto& item : m){        
        if(item.second > freq){
            id = item.first;
            freq = item.second;
        }
    }
    
    for(auto& item : m)     
        if(item.second == freq && item.first < id)
            id = item.first;            
    
    return id;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}

