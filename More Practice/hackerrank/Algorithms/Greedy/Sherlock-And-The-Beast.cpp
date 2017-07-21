#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    
    int T;
    cin >> T;
    while(T--){
        ll N, temp;   cin >> N;
        temp = N;
        while(N%3 != 0)
            N -= 5;
        if(N < 0)
            cout << -1 << endl;
        else{
            for(ll i=1; i<=N; ++i)
                cout << 5;
            for(ll i=1; i<=temp-N; ++i)
                cout << 3;            
            cout << endl;
        }
    }
}
