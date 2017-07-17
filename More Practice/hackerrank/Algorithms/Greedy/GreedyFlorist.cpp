#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, k, min_cost=0, p=1;   cin >> n >> k;
    int *cost = new int[n];
    
    for(int i=0; i<n; ++i)
        cin >> cost[i];

    sort(cost, cost+n, greater<int>());
    
    for(int i=0; i<n; ++i){
        if(i>0 && i%k == 0)
            ++p;
        min_cost += p * cost[i];
    }        
    
    cout << min_cost;
    delete[] cost;
    return 0;
}
