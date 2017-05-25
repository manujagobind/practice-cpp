#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int N, O, r, c, i, x, y, o;
    cin >> N >> O;
    cin >> r >> c;
    int top = N - r;
    int bottom = r - 1;
    int left = c- 1;
    int right = N - c;
    int total = top + bottom + left + right + min(top, left) + min(top, right) + min(right, bottom) + min(bottom, left);    
    
    int *X = new int[8];
    int *Y = new int[8];

    /*

	0 --> left 
	1 --> right	
	2 --> bottom
	3 --> top
	4 --> bottom-left
	5 --> top-left
	6 --> top-right
	7 --> bottom-right

    */

    X[0] = r; Y[0] = 0;
    X[1] = r; Y[1] = N+1;
    X[2] = 0; Y[2] = c;
    X[3] = N+1; Y[3] = c;
    X[4] = 0; Y[4] = 0;
    X[5] = r + min(top, left) + 1; Y[5] = 0;
    X[6] = r + min(top, right) + 1; Y[6] = c + min(top, right) + 1;
    X[7] = 0; Y[7] = c + min(bottom, right) + 1;


    if(O > 0){

	    for(o=0;o<O;o++){
	        cin >> x >> y;	        
	        if(x==r && y<c && y>Y[0]){
	        	X[0] = x; Y[0] = y;
	        } else if (x==r && y>c && y<Y[1]){
	        	X[1] = x; Y[1] = y;
	        } else if (y==c && x<r && x>X[2]){
	        	X[2] = x; Y[2] = y;
	        } else if (y==c && x>r && x<X[3]){
	        	X[3] = x; Y[3] = y;
	        } else if(abs(r-x) == abs(c-y)){
	        	if(x<r && y<c && x>X[4] && y>Y[4]){
	        		X[4] = x; Y[4] = y;
		        } else if (x>r && y<c && x<X[5] && y>Y[5]){
		        	X[5] = x; Y[5] = y;
		        } else if (x>r && y>c && x<X[6] && y<Y[6]){
		        	X[6] = x; Y[6] = y;
		        } else if (x<r  && y>c && x>X[7] && y<Y[7]){
		        	X[7] = x; Y[7] = y;
		        }
	        }
	    }

		i=8;
	   	while(i--){
	   		
	   		x=X[i];
	   		y=Y[i];

	   		if(x==r && y < c)
	   			total -= y - 1 + 1;
	   		else if(x==r && y > c)
	   			total -= N - y + 1;
	   		else if(y==c && x < r)
	   			total -= x - 1 + 1;
	   		else if(y==c && x > r)
	   			total -= N - x + 1;
	   		else if(abs(r-x) == abs(c-y)){
	   			if(x < r && y < c)
	   				total -= min(x-1, y-1) + 1;
	   			else if(x > r && y < c)
	   				total -= min(N-x, y-1) + 1;
	   			else if(x > r && y > r)
	   				total -= min(N-x, N-y) + 1;
	   			else if(x < r && y > r)
	   				total -= min(x-1, N-y) + 1;
	   		}   			

	   	}
    }

   	cout << total << endl;
    return 0;
}