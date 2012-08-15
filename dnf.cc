#include<iostream>

using namespace std;

void swap(int *a, int *b) {

	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void dnf_partition(int *a, int p, int k, int size) {

	int p_index = 0; //stores current index where all values < p
	int k_index = size -1;//stores current index where all values >= k
	int i = 0;
	while( i <= k_index ) {
		if(a[i] < p ) {
			swap (&a[i], &a[p_index]);
			p_index++;
			i++;
		} else if (a[i] >= k ) {
			swap(&a[i], &a[k_index]);
			k_index--;
		} else {
			i++;
		}
	}

	for(int j = 0; j < size; j++)
		cout << "\t" << a[j];
	cout << "\n";
	cout << p_index << "\t" << k_index << "\n";

	i = k_index - p_index ;
	while ( p_index > 0 || k_index < size-1 ||  i >= 0) {
		if(p_index > 0) {
			cout << "\t" << 0;
			p_index--;
		}
		if(i >= 0 ) {
			cout << "\t" << 1;
			i--;
		}
		if(k_index < size-1) {
			cout << "\t" << 2;
			k_index++;
		}
	}
	cout << "\n";
}


int main(){

	int a[10] = {0,1,0,1,1,0,1,1,1,0};
	dnf_partition(a, 1, 2, 10);

}
