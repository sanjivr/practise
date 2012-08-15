#include<math.h>
#include<iostream>

using namespace std;


int find_max_trail(int n){

	// = 2^x + y
	// find x

	if(n%2 == 0)
		return 0;

	int x = int(log(n)/log(2));
	int y = pow(2, x+1);
	if(n == y-1)
		return x+1;
	int z = pow(2, x);
	return find_max_trail(n-z);
	
}

int main() {

	int n;
	while(1) {
		cout << "Enter..\n";
		cin >> n;
		cout<<find_max_trail(n)<<"\n";
	}
}
