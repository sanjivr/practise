#include<iostream>

using namespace std;

void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}


int partition(int *a, int start, int end) {

	int pivot = a[start]; //Select element at start of block as pivot
	swap(&a[start], &a[end]); //Move element at start of block to the end.
	int final_pivot_index  = start; //Keep track of final sorted position to insert pivot
	for(int i = start; i <= end-1 ; i++) { //Iterate over all elements in the block till "end - 1" since "end" contains the pivot
		if(a[i] <= pivot) {			//Move all elements < pivot into the block start -> final_pivot_index-1
			swap(&a[i], &a[final_pivot_index]);
			final_pivot_index++;
		}
	}
	swap(&a[end], &a[final_pivot_index]); //move the pivot into its final sorted position
	return final_pivot_index;
}

/*
	Similar to quicksort. Partition returns an pivot index "j"  which guarantees 
	for all i < j , a[i] <= a[j];
	for all i > j , a[j] < a[i]
	i.e partition returns pivot index such that element in pivot index is in it's final sorted position
	if required k < pivot, search in first partition
	if required k > pivot, search in second partition
	if required k = pivot, return a[pivot]
*/
int kth(int *a, int start, int end, int k) {
	if(start >= end)
		return a[start];

	int pivot_index = partition(a, start, end);
	if(pivot_index == k) 
		return a[k];
	else if (k < pivot_index) 
		return kth(a, start, pivot_index-1,k);
	else 
		return kth(a, pivot_index+1, end, k);

}


int main() {

	int a[10] = {2, 45, 3, 12, 7, 7,9,10, 1, 15};
	int k;
	cout << "list\n";
	for(int i =0; i< 10; i++)
		cout <<"\t"<< a[i];
	cout << "\n";
	cin >> k;
	int ak = kth(a, 0, 9, k);
	cout << ak << "\n";

}
