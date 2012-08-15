#include<iostream>
#include<string>

using namespace std;

void print_words(const string& s) {
	
	const char *a = s.c_str();
	int size = s.size();
	int start = -1;
	int end = -1;
	for(int i = 0; i< size; i++) {
		if(i-1 >= 0) {
			if(a[i-1] == ' ' && a[i] != ' ') 
				start = i;
			else if(a[i-1] != ' ' && a[i] == ' ')
				end = i;
			
			if(end != -1){
				if(start < 0) 
					start = 0;
				cout<< string(a, start, end-start+1) << "\n";
				start = -1;
				end = -1;
			}
		}
	}
	if(start < 0)
		start = 0;
	if(end < 0)
		end = size-1;
	cout << string(a, start, end-start+1) << "\n";
}

int main() {

	string s;
	while(1){	
	getline(cin, s);
	print_words(s);
	}
}


