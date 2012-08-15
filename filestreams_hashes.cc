#include<iostream>
#include<fstream>

#include<string>
#include<ext/hash_set>
#include<ext/hash_map>
#include<ext/hash_fun.h>

using namespace std;
using namespace __gnu_cxx;

namespace __gnu_cxx {
	template<> struct hash<std::string> {
		hash<const char*> h;
		size_t operator() (const std::string&s) const {
			{
				return h(s.c_str());
			}
		}
	};
}

int main(){

	ifstream FH("./test.diff");
	hash_set<string> hset;
	hash_map<string, string> hmap;
	string s;
	while(FH.good()) {
		FH >> s;
		hset.insert(s);
		hmap.insert(pair<string, string>(s,s));
	//	cout << s << "\n";
	}
	FH.close();

	hash_set<string>::iterator it = hset.begin();
	while(it != hset.end()) {
	//	cout << *it << "\n";
		it++;
	}

	hash_map<string, string>::iterator it2 = hmap.begin();
	while(it2 != hmap.end()) {
		cout << it2->second << "\n";
		it2++;
	}
}
