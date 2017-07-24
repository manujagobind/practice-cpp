#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    
    int T;  cin >> T;
    while(T--){
        int N;  cin >> N;
        
        ll ans = 0, temp;
        for(ll i=0; i<N; ++i){
            cin >> temp;
            ans ^= temp;
        }
        cout << ans << endl;       
    }
    return 0;
}
