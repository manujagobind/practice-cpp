#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;  string s;
    cin >> n >> s;
    
    int level = 0, valleys = 0;
    bool belowSea = false;
    
    for(int i=0; i<n; ++i){
        char slope = s[i];
        
        if(slope=='U') ++level;
        else --level;
        
        
        if(!belowSea && level < 0){
            ++valleys;
            belowSea = true;
        }
        
        if(level >= 0) belowSea = false;
    }
    
    cout << valleys;
    return 0;
}

