#include<iostream>
#include<string>
#include<string.h>


using namespace std;

void swap(char *a, char *b){
	
	char t = *a;
	*a = *b;
	*b = t;
}

void remove_duplicates(string s){

	char *a = new char[s.size()+1];
	strncpy(a, s.c_str(), s.size());

	int cur_end = s.size()-1;
	for(int i = 0; i <= cur_end; i++) {
		for(int j = i+1; j<= cur_end;j++) {
			if(a[i] == a[j]) {
				while(a[i] == a[cur_end] && j != cur_end) {
					cur_end--;
				}
				swap(&a[j], &a[cur_end]);
				cur_end--;
			}
		}
	}
	a[cur_end+1] = '\0';
	cout << string(a) << "\n";
}

int main() {

	string s;
	while(1) {
		cin >> s;
		remove_duplicates(s);
	}
}
