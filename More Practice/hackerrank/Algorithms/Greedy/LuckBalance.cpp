#include <bits/stdc++.h>
using namespace std;

class Contest{
public:
    int luck, imp;
    static bool comparator(const Contest& c1, const Contest &c2){
        return c1.luck < c2.luck;
    }
};

int main(){
    
    int N, K, count_imp=0, ans=0;   cin >> N >> K;
    Contest *contest = new Contest[N];
    for(int i=0; i<N; ++i){
        cin >> contest[i].luck >> contest[i].imp;
        if(contest[i].imp) ++count_imp;
    }
    
    sort(contest, contest+N, Contest::comparator);
    
    for(int i=0, k=0; i<N; ++i){
        if(contest[i].imp && k < count_imp-K){
            ans -= contest[i].luck;
            ++k;
        } else
            ans += contest[i].luck;
    }
    
    cout << ans;
    
    delete[] contest;    
    return 0;
}
