#include<iostream>
using namespace std;

/*
	@param a - pointer to head of the array
	@param size - size of array
	@return - length of longest zigzag sequence in the array
	
*/
int longest_zigzag_sequence_length(int *a, int size) {
	int op = -1; //1 for < , 2 for >, -1 for not set. Not very optimal. indicator for next operation
	int count = 0;
	int prev_max_count = 0;
	int  i = 0;
	
	if(size < 2) {
		return size-1;
	}


	do {
		//cout << "Comparing "<< a[i] << " and "<< a[i+1]<<"\n";
		if(a[i] < a[i+1]) {
			if(op == -1) {
				count++;
				op = 2; //set the next expected op
			}
			else if(op == 1) {
				count++;
				op = 2; //set the next expected op
			} else {
				if(count > prev_max_count) {
					prev_max_count = count;
				}
				count = 1; //next expected op is same as current op
			}	
		} else { //Assumption - no adjacent equal numbers
			if(op == -1) {
				count++;
				op = 1; //set the next expected op
			}
			else if (op == 2) {
				count++;
				op = 1; //set the next expected op
			} else {
				if(count > prev_max_count) {
					prev_max_count = count;
				}
				count = 1; //next expected op is same as current op
			}
		}
		i = i+1;
		//cout << "Count = "<< count << " Next operation = " << op << "\n";
	} while(i < size - 1);
	return (count > prev_max_count ? count:prev_max_count);
}


void test() {
	int ret;
	int a[8] = {10, 12, 13, 8, 10, 7, 5,6};
	ret = longest_zigzag_sequence_length(a, 8);
	if(ret == 4) {
		cout << " pass\n";
	} else 
		cout << "fail\n";
	int b[1] = {1};
	ret = longest_zigzag_sequence_length(b, 1);
	if(ret == 0) {
		cout << " pass\n";
	} else 
		cout << "fail\n";
	int c[2] = {1,0};
	ret = longest_zigzag_sequence_length(c, 2);
	if(ret == 1) {
		cout << " pass\n";
	} else 
		cout << "fail\n";
	int d[3] = {12, 10, 13};
	ret = longest_zigzag_sequence_length(d, 3);
	if(ret == 2) {
		cout << " pass\n";
	} else 
		cout << "fail\n";
	int e[3] = {1,2,3};
	ret = longest_zigzag_sequence_length(e, 3);
	if(ret == 1) {
		cout << " pass\n";
	} else 
		cout << "fail\n";
	int f[3] = {30,24, 12};
	ret = longest_zigzag_sequence_length(f, 3);
	if(ret == 1) {
		cout << " pass\n";
	} else 
		cout << "fail\n";
	int g[12] =  {100, 20, 90, 70, 95, 75, 60, 65, 55, 50, 80, 85};
	ret = longest_zigzag_sequence_length(g, 12);
	if(ret == 5) {
		cout << " pass\n";
	} else 
		cout << "fail\n";
	

}

int main() {

	test();
/*
	int size , ele, i;
	cout << "Enter size ";
	cin >> size;
	cout << "\n";
	int *a = new int[size];
	for (i = 0; i < size; i++) {
		cout << "Enter entry ";
		cin >> ele;
		a[i] = ele;
	}
	cout << "\n";

	for(i = 0; i < size; i++) {
		cout << "\t"<< a[i];
	}
	cout << "\n";

	cout << "Longest zigzag "<< longest_zigzag_sequence_length(a, size) << "(count of consecutive pairs. Add 1 to get number of consecutive elements)\n";
	delete a;
*/

}
