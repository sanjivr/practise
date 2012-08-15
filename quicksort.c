#include<iostream>

using namespace std;

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *a, int start, int end) {

	int pivot = *(a+start);
	int i = start - 1;
	int j = end + 1;
	while(1) {
		do{
			j--;
		}
		while(*(a+j) > pivot && j >= start);
		do{
			i++;
		}
		while(*(a+i) < pivot && i <= end) ;

		if(j > i) {
			swap(a+j, a+i);
		}
		else {
			return j;				
		}
	}
}

void quicksort(int *a, int start, int end) {
	if(end <= start ){
		return;
	}
	int pivot_index = partition(a, start, end);
	quicksort(a, start, pivot_index);
	quicksort(a, pivot_index+1, end);
}

int main() {

	int a[10] = {2, 45, 3, 12, 7, 4, 9,10, 1, 15};
	quicksort(a, 0, 9);
	cout << "list\n";
	for(int i =0; i< 10; i++)
		cout <<"\t"<< a[i];
	cout << "\n";

}

/*
int main() {
	int n;
	while(1) {
		int *a = NULL;
		cout << "Enter size: ";
		cin >> n;
		if(n <= 0)
			return 0;
		a = new int[n];
		for(int i = 0; i<n;i++){
			cout << "\nEnter Element ["<<i<<"]: ";
			cin >> a[i];
		}
		
		quicksort(a, 0, n-1);
		cout << "Sorted Output \n";
		for(int i = 0; i < n; i++) {
			cout << a[i] << "\t";
		}
		delete a;
	}
} */
