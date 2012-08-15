#include<iostream>
#include<string>
using namespace std;



void kmpprocess(const char* p, int size, const char *s, int textSize) {
	cout << size << "\n";
	int *b = new int[size+1];
	int i;
	b[0] = -1;
	for(i = 1; i < size+1; i++) {
		if(p[i-1] == p[b[i-1]])
			b[i] = b[i-1] + 1;
		else
			b[i] = 0;
	}

	for (i= 0; i < size+1; i++) {
		cout << "\t" << b[i];
	}
	cout << "\n";

	int m = 0; //Start of match in text
	i = 0; //Current pos in pattern

	while( m+i < textSize) {
		if(s[m+i] == p[i]) {
			if(i == size-1){
				cout << "Match found at  " << m << "\n";
				return;
			}
			i++;
		} else {
			m = m + i - b[i];
			if(b[i] > -1)
				i = b[i];
			else
				i = 0;
		}

	}

}



int main() {

//	char p[6] = {'a', 'b', 'a', 'b', 'a', 'a'};
//	char p[7] = {'a', 'b', 'c', 'd', 'a', 'b', 'd'};
//	string s("participate in parachute");	
//	kmpprocess(s.c_str(), s.size());
//	s = "abcdabd";
//	kmpprocess(s.c_str(), s.size());
	string pattern("abcabade");
	string text("abcdeabcedabcabadabcabade");
	kmpprocess(pattern.c_str(), pattern.size(), text.c_str(), text.size());

}


