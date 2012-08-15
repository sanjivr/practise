#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;

void remove_vowels(string &s){
	char *c = new char(s.length());
	memcpy(c, s.c_str(), s.length());
	char *cur_pos = c;
	char *check_pos = cur_pos;
	int skip_count =0 ;

	while(*check_pos != '\0'){
		while(*check_pos == '_')
			check_pos ++;
		*cur_pos = *check_pos;
		printf("%s\n", c);
		check_pos++;
		cur_pos++;
	}
	s = string(c);

}

int main(){
	string s;
	while(1){
		cout << "Enter string: ";
		cin >> s;
		remove_vowels(s);
		cout << s;
	}
}
