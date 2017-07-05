#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, amount, expenditure=-1, max=INT_MIN;
    cin >> amount >> n >> m;
    
    int *keyboard = new int[n];
    int *usb = new int[m];
    
    for(int i=0; i<n; ++i)
        cin >> keyboard[i];
    for(int i=0; i<m; ++i)
        cin >> usb[i];
    
    sort(keyboard, keyboard+n, greater<int>());
    sort(usb, usb+m);
        
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(keyboard[i] + usb[j] <= amount){
                expenditure = keyboard[i] + usb[j];
                max = (expenditure > max)? expenditure : max;
            }
        }
    }
    
    
    cout << ((expenditure != -1)? max : -1);
    
    delete usb;
    delete keyboard;   
    return 0;
}

