#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>

using namespace std;

void remove_spaces(const string& s) {

	char *a = new char[s.size()+1];
	int num_spaces_found = 0;

	strncpy(a, s.c_str(), s.size() + 1);

	for(int i = 0; i < s.size() + 1 ; i++)
	{
		if(a[i] == ' '){
			num_spaces_found++;
		}
		else {
			if(i-num_spaces_found >= 0) {
				a[i-num_spaces_found] = a[i];
			}
		}
	}
	cout << "Space Removed "<< string(a) << "\n";
}

int main() {

	string s;
	while(1) {
		cout << "Enter String ... ";
		getline(cin, s);
		remove_spaces(s);
	}
}
