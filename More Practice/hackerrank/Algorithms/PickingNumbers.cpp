#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, temp, count=0;  cin >> n;
    int a[100] = {0};
    
    for(int i=0; i<n; ++i){
        cin >> temp;
        a[temp]++;
    }      
    
    for(int i=1; i<100; ++i)
        if(a[i]+a[i-1] > count)
            count = a[i] + a[i-1];
    
    cout << count;    
    return 0;
}
