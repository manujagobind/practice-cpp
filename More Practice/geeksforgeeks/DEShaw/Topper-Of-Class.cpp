#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> llPair;    // pair(marks, id)
bool comparator(const llPair &p1, const llPair &p2){
    if(p1.F == p2.F) return p1.S < p2.S;
    return p1.F > p2.F;
}

int main(){
    
    ll T;  cin >> T;
    while(T--){
        ll N, temp;  cin >> N;
        vector<llPair> V;
        for(ll i=0; i<N; ++i){
            cin >> temp;
            V.push_back(mp(temp, i));
        }
        sort(V.begin(), V.end(), comparator);
        ll K;   cin >> K;
        ll counter = 0, i=0;
        while(counter < K && i < N){
            cout << V[i++].S << " ";
            if(V[counter].F != V[i].F) ++counter;
        }
        cout << endl;
    }
    return 0;
}
