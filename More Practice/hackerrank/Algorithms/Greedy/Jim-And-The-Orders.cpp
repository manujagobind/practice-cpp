#include <bits/stdc++.h>
using namespace std;

class Order{
public:    
    int id, t, d;
    static bool comparator(Order &o1, Order &o2){
        int time1 = o1.t + o1.d;
        int time2 = o2.t + o2.d;
        
        if(time1 == time2)
            return o1.id < o2.id;
        return (time1 < time2);
    }
};

int main(){
    
    int n;  cin >> n;
    Order *orders = new Order[n];
    
    for(int i=0; i<n; ++i){
        orders[i].id = i+1;
        cin >> orders[i].t >> orders[i].d;
    }
    
    sort(orders, orders+n, Order::comparator);
    
    for(int i=0; i<n; ++i)
        cout << orders[i].id << " ";
    
    delete[] orders;
    return 0;
}
