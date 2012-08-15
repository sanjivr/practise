#include<iostream>
#include<string>

using namespace std;

/*
@any stage of permutation you can
a) open bracket -> only if opens so far < count
b) close bracket -> only if count < open
*/

void permute(string s, int count, int open, int closed) {
	if(count == closed) {
		cout << s << "\n";
		return;
	}

	string s1(s);
	string s2(s);
	if(closed < open) {
		s1.append("}");
		permute(s1, count, open, closed+1);
	}
	if(open < count) {
		s2.append("{");
		permute(s2, count, open+1, closed);
	}

}

int main() {

	permute(string(), 10, 0, 0);
}
