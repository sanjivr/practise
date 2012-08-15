/*
	Replace spaces with %20c
*/

#include<iostream>
#include<string>
#include<deque>
#include<string.h>
#include<stdlib.h>

using namespace std;

class cdq{

	private:
		int size;
		deque<char> d;

	public:
		cdq(int val): size(val){}
		char push(char x);
		char pop();
		bool empty();
		void increaseSize(int val);
		void decreaseSize(int val);
};

void cdq::increaseSize(int val){
	size += val;
}

void cdq::decreaseSize(int val) {
	size -= val;
}

char cdq::push(char x) {
	char p = '-';
	if(d.size() == size) {
		p = d.front();
		d.pop_front();
		d.push_back(x);
	} else {
		d.push_back(x);
	}
	return p;
}

bool cdq::empty() {
	return d.empty();
}

char cdq::pop() {
	char p;
	p = d.front();
	d.pop_front();
	return p;
}


void replace_space(const string& s) {

	char *c = new char[s.size()+1];
	strncpy(c, s.c_str(), s.size()+1);
	cdq dq(0);
	int i;
	int size = s.size()+1;
	for(i = 0; i < s.size()+1; i++) {
		if(c[i] == ' '){
			dq.increaseSize(4);
			dq.push('%');
			dq.push('2');
			dq.push('0');
			dq.push('c');
//			cout << string(c) << "\n";
			size = size+3;
			c = (char *)realloc(c, size);
		
		}
		if(!dq.empty()){
			if(c[i] == ' ')
			{	
				c[i] = dq.pop();
				dq.decreaseSize(1);
			} else {	
			c[i] = dq.push(c[i]);
			}
//			cout << string(c) << "\n";
		}
	}
	while(!dq.empty()) {
		c[i] = dq.pop();
//		cout << string(c) << "\n";
		i++;
	}
	cout << string(c) << "\n";

}


int main() {
	string s;
	while(1) {
		getline(cin, s);
		replace_space(s);
	}

}
