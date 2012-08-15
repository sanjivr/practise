#include<iostream>

using namespace std;

//Assumption sorted array. but rotated


bool is_sorted(int *a, int start, int end) {
	if(a[start] <= a[end]) 
		return true;
	else
		return false;
}

void print(int *a, int start, int end) {
	for (int i =start; i <= end; i++) 
		cout << "\t" << a[i];
	cout << "\n";

}

bool binary_search(int x, int *a, int start, int end) {
	cout << "Binary Searching in " ;
	print(a, start, end);
	if(x < a[start])
		return false;
	if(x > a[end])
		return false;

	if(start == end ) {
		if(a[start] == x) 
			return true;
		else
			return false;
	} else {
		int mid = start + ((end - start )/2);
		if( x <= a[mid])
			return binary_search(x,a, start, mid);
		else if (a[mid+1] <= x ) 
			return binary_search(x, a, mid+1, end);
		else
			return false;
	}

	
}

bool search(int x, int *a, int start, int end) {
	cout << "Searching in " ;
	print(a, start, end);
	if(is_sorted(a, start, end)) {
		return binary_search(x, a, start, end);
	} else {
		int mid = start + ((end - start)/2);
		if(is_sorted(a, start, mid)) { //First array is sorted
			if(a[start] <= x && x <= a[mid]) {
				return binary_search(x, a, start, mid);
			}
			else {
				return search(x, a, mid+1, end);
			}
		} 
		else { //Second array is sorted
			if(a[mid+1] <= x && x <= a[end] ) {
				return binary_search(x, a, mid+1, end);

			} else {
				return search(x, a, start, mid);
			}
		}

	}

}

int find_split_index(int *a, int start, int end) {
	if(is_sorted(a, start, end)) {
		return start;
	}	

	int mid = (start + ((end - start)/2));
	if(is_sorted(a, start, mid)) 
		return find_split_index(a, mid+1, end);
	else
		return find_split_index(a, start, mid);

}

int main() {
	int a[10][10] = {
	{9,0,1,2,3,4,5,6,7,8},
	{8,9,0,1,2,3,4,5,6,7},
	{7,8,9,0,1,2,3,4,5,6},
	{6,7,8,9,0,1,2,3,4,5},
	{5,6,7,8,9,0,1,2,3,4},
	{4,5,6,7,8,9,0,1,2,3},
	{3,4,5,6,7,8,9,0,1,2},
	{2,3,4,5,6,7,8,9,0,1},
	{1,2,3,4,5,6,7,8,9,0},
	{0,1,2,3,4,5,6,7,8,9}
	};

	int size = 10;
	int i ,j;
	for(j =0; j<=size-1; j++) {
		for(i = 0; i <= size-1; i++)
			cout << "\t" << a[j][i];
		cout << "\n";
		int split_index = find_split_index(a[j],0,size-1);

		cout << "Split Index = "<< split_index << " Value = "<< a[j][split_index] << "\n";
	}
	/*
	cin >> j;
	cout << "Number to find: \n";
	int x;
	cin >> x;
	cout << "\n"<< search(x, a[j], 0, size-1);
*/
}
