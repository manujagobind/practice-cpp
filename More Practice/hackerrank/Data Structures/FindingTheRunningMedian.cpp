#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;    cin >> n;
    double x, median = 0.0;
    priority_queue<int> left;   // Max Heap
    priority_queue< int, vector<int>, greater<int> > right; // Min Heap
    
    while(n--){
        cin >> x;
        
        if(left.size() > right.size()){
            if(x < median){
                right.push(left.top()); left.pop();
                left.push(x);                
            } else
                right.push(x);                                            
            median = (double) (left.top() + right.top()) / 2.0 ;
        } else if(left.size() == right.size()){
            if(x < median){
                left.push(x);
                median = (double) left.top();
            } else{
                right.push(x);
                median = (double) right.top();                
            }
        } else{
            if(x < median){
                left.push(x);                
            } else{
                left.push(right.top()); right.pop();
                right.push(x);
            }
            median = (double) (left.top() + right.top()) / 2.0 ;
        }
        
        cout << (double) median << endl;
    }
        
    return 0;
}
