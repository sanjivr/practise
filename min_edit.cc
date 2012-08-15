#include<iostream>
#include<string>

using namespace std;

void gen_edits(string &s, int count){
	if(count == 0)
		return;

	char c;
	int size = s.size();
	//Generate all replaces
	for(int i = 0; i< size;i++){
		char orig = s.at(i);
		for(c ='a'; c <= 'z'; c++){
			s.replace(i, 1, 1, c);
			gen_edits(s, count-1);
		cout << s << "\n";
		}
		s.replace(i, 1, 1, orig);
		//cout << s << "\n";

	}
	//Generate all deletes
	for(int i=0; i < size;i++) {
		char orig = s.at(i);
		s.erase(i, 1);
		gen_edits(s, count-1);
		cout << s << "\n";
		s.insert(i,1,orig);
	}
	//Generate all inserts
	for(int i =0; i < size; i++){
		for(c = 'a'; c <='z'; c++) {
			s.insert(i, 1, c);
			gen_edits(s, count-1);
			cout << s << "\n";
			s.erase(i, 1);
		}

	}
}

int main() {
	
	string s("12345");
	gen_edits(s, 2);
}
