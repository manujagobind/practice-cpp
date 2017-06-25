#include <bits/stdc++.h>
using namespace std;

void exchange(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void print(int *a, int size){
	for(int i=0; i<size; ++i)
		cout << a[i] << " ";
	cout << endl;
}

void bubble_sort(int *a, int size){
	for(int i=0; i<size; ++i){
		for(int j=0; j<size-i-1; ++j){
			print(a, size);
			if(a[j] > a[j+1])
				exchange(&a[j], &a[j+1]);
		}
		cout << endl;
	}
}

void bubble_sort_recursive(int *a, int size){
	if(size <= 1) return;

	for(int i=0; i<size-1; ++i)
		if(a[i] > a[i+1])
			exchange(&a[i], &a[i+1]);
	
	print(a, size);
	bubble_sort_recursive(a, size-1);
}

void bubble_sort_optimized(int *a, int size){
	for(int i=0; i<size; ++i){
		bool swapped = false;
		for(int j=0; j<size-1; ++j){
			print(a, size);
			if(a[j] > a[j+1]){
				exchange(&a[j], &a[j+1]);
				swapped = true;
			}
		}
		cout << endl;
		if(!swapped) break;
	}
}


void selection_sort(int *a, int size){
	for(int i=0; i<size;++i){
		int min_id = i;
		for(int j=i+1; j<size; ++j)
			min_id = (a[j] < a[min_id])? j : min_id;
		exchange(&a[i], &a[min_id]);
		print(a, size);
	}
}

void insertion_sort(int *a, int size){
	for(int i=1; i<size; ++i){
		int val = a[i], j=i;		
		while(j>0 && a[j-1] > val){
			a[j] = a[j-1];
			--j;
		}
		a[j] = val;
	}
}

void insertion_sort_recursive(int *a, int size){
	if(size <= 1)
		return;
	
	insertion_sort_recursive(a, size-1);
	
	int val = a[size-1], j=size-1;
	while(j>0 && a[j-1] > val){
		a[j] = a[j-1];
		--j;
	}
	a[j] = val;
	print(a, size);
}

void shell_sort(int *a, int size){
	int h;
	for(h=1; h<size && (3*h+1)<size; h=3*h+1);

	for(; h>0; h/=3){

		for(int i=h; i<size; ++i){
			int val = a[i], j = i;
			while(j >= h && a[j-h] > val){
				a[j] = a[j-h];
				j -= h;
			}
			a[j] = val;
			cout << "h=" << h << ":\t"; print(a, size);
		}
	}
}

void merge(int *a, int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = new int[n1];
	int *R = new int[n2];

	for(int i=0; i<n1; ++i)
		L[i] = a[left+i];
	for(int i=0; i<n2; ++i)
		R[i] = a[mid+1+i];

	int i=0, j=0, k=left;
	while(i < n1 && j < n2){
		if(L[i] <= R[j])
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	}

	while(i<n1)
		a[k++] = L[i++];

	while(j<n2)
		a[k++] = R[j++];

	delete R;
	delete L;
}

void merge_sort(int *a, int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		merge_sort(a, left, mid);
		merge_sort(a, mid+1, right);
		merge(a, left, mid, right);
	}
}


/*TODO
void merge_sort_iterative(int *a, int size){
	for(int i=1;  i <= size; i*=2){
		for(int left = 0; left < size-1; left += 2*i){
			int mid = left + i - 1;
			int right = min(left + 2*i - 1, size - 1);
			cout << i << " " << left << " " << mid << " " << right << endl; 
			merge(a, left, mid, right);
		}
	}
}*/

int partition(int *a, int left, int right){

	int pivot = a[right];
	int p = left;

	for(int i=left; i<=right; ++i){
		if(a[i] < pivot){
			exchange(&a[i], &a[p]);
			++p;
		}
	}
	
	exchange(&a[p], &a[right]);
	return p;
}

void quick_sort(int *a, int left, int right){
	if(left < right){
		int p = partition(a, left, right);
		quick_sort(a, left, p-1);
		quick_sort(a, p+1, right);
	}
}

void quick_sort_iterative(int *a, int left, int right){
	stack<int> stack;

	stack.push(left);
	stack.push(right);

	while(!stack.empty()){
		right = stack.top(); stack.pop();
		left = stack.top(); stack.pop();

		int p = partition(a, left, right);
	
		if(p-1 > left){
			stack.push(left);
			stack.push(p-1);
		}

		if(p+1<right){
			stack.push(p+1);
			stack.push(right);
		}
	}
}

int main(){
//	int a[] = {5, 1, 3, 4, 2};
//	int a[] = {1, 2, 3, 4, 5};
	int a[] = {10, 9, 8, 7, 6, 5, 4,  3, 2, 1};
	int size = sizeof(a) / sizeof(a[0]);
//	bubble_sort(a, size);
//	bubble_sort_recursive(a, size);
//	bubble_sort_optimized(a, size);
//	selection_sort(a, size);
//	insertion_sort(a, size);
//	insertion_sort_recursive(a, size);i
//	shell_sort(a, size);
//	merge_sort(a, 0, size-1);
//	quick_sort(a, 0, size-1);
	quick_sort_iterative(a, 0, size-1);
	cout << "--" << endl;
	print(a, size);
	return 0;
}
