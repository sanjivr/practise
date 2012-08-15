#include<iostream>

using namespace std;
class heap {

	int max_size;
	int size;
	int *a;

	public:
		heap(int max);
		void heapify(int index);
		void build_heap();
		void pre_insert(int);
		int min();
		void delete_min();
		void print();
		void insert(int);
		
};

heap::heap(int max) {
	max_size = max;
	size = 0;
	a = new int[max_size];
}

void heap::pre_insert(int value) {
	if(size < max_size) {
		*(a+ size) = value;
		size++;
	}
}

void heap::build_heap() {
	for (int i = (size)/2; i >= 0; i--) {
		cout << "Calling heapify on index " << i << "\n";
		heapify(i);
		print();
	}
}

void heap::heapify(int index) {

	int min = index;
	if( 2*index + 1 < size && a[2*index + 1] < a[index])
		min = 2*index + 1;
	if(2*index + 2 < size && a[2*index + 2] < a[min])
		min = 2*index + 2;
	
	if( min != index) {
	int tmp = a[index];
	a[index] = a[min];
	a[min] = tmp; 
	heapify(min);
	}

}

int heap::min() {
if(size > 0) 
	return *a;
}

void heap::delete_min() {
	if(size > 0 ) 
	{
		cout << "Deleting "<<*a << "\n";
		a[0] = a[size-1];
		size--;
		heapify(0);
		print();
	}

}

void heap::insert(int val) {
	if(size >= max_size)
		return;
	int index = size;
	int parent = (index - 1 )/2;
	a[size++] = val;
	while( parent >= 0 && a[index] < a[parent]) {
		int tmp = a[index];
		a[index] = a[parent];
		a[parent] = tmp;

		index = parent;
		parent = (index - 1)/2;
	}
	

}

void heap::print() {

	for(int i = 0; i < size; i++) 
		cout << *(a+i) << "\t";
	cout << "\n";

}

int main() {

	heap h(10);
	while(1) {
		cout << "1.Enter\n2.Heapify\n3.print\n4.min\n5.exit\n6.delete min\n7.post insert";
		int ch, val;
		cin >> ch;
		switch(ch) {
			case 1: 
				cin >> val;
				h.pre_insert(val);
				break;
			case 2: h.build_heap();
				break;
			case 3: h.print();
				break;
			case 4: val = h.min();
				cout << val << "\n";
				break;
			case 5: return 0;
			case 6: h.delete_min();
				break;
			case 7: cin >> val;
				h.insert(val);
				break;
		}

	}	
}
