#include <iostream>
#include <set>
using namespace std;

int main(){
    
    int n1, n2, n3, i;
    cin >> n1 >> n2 >> n3;
    int *a = new int [n1];
    int *b = new int [n2];
    int *c = new int [n3];
    for(i=0;i<n1;i++)
        cin >> a[i];
    for(i=0;i<n2;i++)
        cin >> b[i];
    for(i=0;i<n3;i++)
        cin >> c[i];
    for(i=n1-2;i>=0;i--)
        a[i] += a[i+1];
    for(i=n2-2;i>=0;i--)
        b[i] += b[i+1];
    for(i=n3-2;i>=0;i--)
        c[i] += c[i+1];
    set< int > s1, s2;  
    for(i=0;i<n1;i++)
        s1.insert(a[i]);
    for(i=n2-1;i>=0;i--)
        if(s1.find(b[i]) != s1.end())
            s2.insert(b[i]);
    int id = -1;
    for(i=n3-1;i>=0;i--)
        if(s2.find(c[i]) != s2.end()){
            id = i;                        
        }      
    if(id != -1)
        cout << c[id];
    else
        cout << 0;
    return 0;
}
