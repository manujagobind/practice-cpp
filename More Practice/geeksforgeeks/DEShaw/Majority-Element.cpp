#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;  cin >> T;
    while(T--){
        int N;  cin >> N;
        int *A = new int [N];
        
        for(int i=0; i<N; ++i)  cin >> A[i];
 
	/* Moore's Voting Algorithm:
	   maj_id stores the index of a potential candidate.*/
        int count = 1, maj_id = 0;
        for(int i=1; i<N; ++i){
            if(A[maj_id] == A[i]) ++count;
            else --count;
            if(count == 0){
                maj_id = i;
                count = 1;
            }
        }
	/*Check if the selected candidate is also the majority element.*/
        count = 0;
        for(int i=0; i<N; ++i)
            if(A[i] == A[maj_id])
                ++count;
                
        if(count > N/2)
            cout << A[maj_id] << endl;
        else
            cout << "NO Majority Element\n";
        
        delete[] A;
    }
    return 0;
}
