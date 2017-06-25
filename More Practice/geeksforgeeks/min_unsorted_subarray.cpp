#include <bits/stdc++.h>
using namespace std;

void minUnsortedSubarray(int arr[], int size){
	int start=0, end=size-1, i, min, max;

	for(start=0; start<size-1; ++start)
		if(arr[start] > arr[start+1])
			break;

	if(start == size-1){
		cout << "Array is already sorted.\n";
		return;
	}

	for(end=size-1; end>0; --end)
		if(arr[end] < arr[end-1])
			break;

	max = min =  arr[start];
	for(i=start; i<=end; ++i){
		max = (arr[i] > max)? arr[i] : max;
		min = (arr[i] < min)? arr[i] : min;
	}

	for(i=0; i < start; ++i)
		start = (arr[i] > min)? i : start;

	for(i=end+1; i<size; ++i)
		end = (arr[i] < max)? i : end;

	cout << "Required subarray indices: start = " << start << ", end = " << end << endl;
}

int main(){

	int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
	int size = sizeof(arr) / sizeof(arr[0]);
	minUnsortedSubarray(arr, size);
	return 0;
}
