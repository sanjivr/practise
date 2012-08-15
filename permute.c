#include<iostream>
#include<string>


using namespace std;

void permute(char *s, int cur, int max) {
	if(cur == max)
	{
		printf("%s\n", s);
		return;
	}

	else {
		for(int i = cur; i <= max; i++) {
			char t = s[cur];
			s[cur] = s[i];
			s[i] = t;
			permute(s, cur+1, max);
			t = s[cur];
			s[cur] = s[i];
			s[i] = t;
		}
	}

}

int main() {
	/*string s;
	cout << "Enter:";
	cin >> s;
	cout << "\n";

	char *c = new char[s.size()+1];
	memcpy(c, s.c_str(), s.size());
	c[s.size()] = '\0';
	*/
	char c[4];
	c[0] = '1';
	c[1] = '2';
	c[2] = '3';
	c[3] = '4';
	permute(c, 0, 3);

}
