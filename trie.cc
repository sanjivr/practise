#include<iostream>
#include<hash_map>
#include<list>

using namespace std;
using namespace __gnu_cxx;


struct trieNode{

	hash_map<char, struct trieNode*> hmap;
	int depth;
	list<string> values;

	trieNode(int val): depth(val){}
		
};

class trie {

	private:
		struct trieNode *root;

		void insert_impl(int pos, const string& obj, struct trieNode *node) ;
	public: 

		trie(): root(NULL){}
		void insert(const string& obj);
		void matches(const string& obj);

};

void trie::insert_impl(int pos, const string& obj, struct trieNode *node) {
		if(pos == obj.size())
			return;
		char c = obj.at(pos);
		if(node->hmap.find(c) == node->hmap.end()){
			struct trieNode *cur = new trieNode(pos+1);
			node->hmap.insert(pair<char, struct trieNode*>(c, cur));
		}

		if(pos >= 2) {
			node->hmap.find(c)->second->values.push_back(string(obj));
		}
		insert_impl(pos+1, obj, node->hmap.find(c)->second);
}

void trie::insert(const string &obj) {

	if(root == NULL) 
		root = new trieNode(0);

	insert_impl(0, obj, root);
}

void trie::matches(const string &obj) {

	const char *c = obj.c_str();
	int pos = 0;
	struct trieNode *cur = root;
	while(cur != NULL && pos < obj.size()) {
		
		if(cur->hmap.find(c[pos]) == cur->hmap.end()) {
			cur = NULL;
		} else {
			cur = cur->hmap.find(c[pos])->second;
			cout << "Found a trie node for " << c[pos] << " at level " << pos << "\n";
			pos++;
		}
	}	
	if(cur != NULL) 
	{

		list<string>::iterator it = cur->values.begin();
		while(it != cur->values.end())
		{
			cout << "\t" << *it;
			it++;
		}
	}
}


int main() {

	trie t;
	t.matches("sand");
}
