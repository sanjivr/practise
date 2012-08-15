#include "doubly_linked_list.h"
//#include <hash_map>
#include<ext/hash_map>

#include <iostream>

using namespace std;

class lru {

	private:
		dll lst;
		__gnu_cxx::hash_map<int, struct node *> hmap;
		int max_size;

	public:
		lru(int size): max_size(size){}
		bool fetch(int key);
		
};


bool lru::fetch(int key) {

	__gnu_cxx::hash_map<int, struct node *>::iterator it = hmap.begin();
	it = hmap.find(key);

	if( it != hmap.end()) { //Key is found 
		struct node *n = (it->second);
		lst.move_to_head_impl(n);

	} else { //key is not found

		if(lst.get_size() >= max_size) {
			//Remove the oldest i,e at the tail
			struct node *n = const_cast<struct node *>(lst.get_tail());
			if(lst.remove_impl(n))
			{
				hmap.erase(n->key);
				delete n;
			} else {
				//could not remove from list
			}
		}

		struct node *n = const_cast<struct node *>(lst.insert(key));
		if(n) {
			hmap.insert(pair<int, struct node*>(key, n));
		}

	}

	lst.print();

}

int main() {

	lru cache(5);
	int ch;
	int val;
	while(1) {
			cout << "Value ... \n";
			cin >> val;
			cache.fetch(val);
		}
}


