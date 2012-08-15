#include<iostream>

using namespace std;

struct node {
	struct node *next;
	int key;
};

class ll {
	private:
		struct node *head;
		int size;
	public:
		ll();
		~ll();
		void insert(int key);
		void print() const;
		void reverse();
		int length() const;
		const struct node* getCommonTail(const ll& other) const;
};

ll::ll() {
	head = NULL;
	size = 0;
}

ll::~ll() {
	struct node *cur = head;
	struct node *t = NULL;
	while(cur != NULL) {
		t = cur;
		cur = cur->next;
		delete t;
	}
}

int ll::length() const {
	return size;
}

/*
	Given 2 linked lists determine the common tail of values
	Linked lists are read-only -> hence cannot reverse
	Linked lists do not share common nodes. i.e 2 linked lists are not in a Y shape
*/
const struct node* ll::getCommonTail(const ll& other) const {

	if(size == 0) 
		return NULL;
	int otherListSize = other.length();
	if(otherListSize == 0) 
		return NULL;
	
	if(otherListSize > size )
		return other.getCommonTail(*this);
	int skipCount = size - otherListSize;
	struct node *cur = head;
	while(skipCount > 0 && cur != NULL) {
		cur = cur->next;
		skipCount--;
	}
	struct node *otherCur = other.head;
	struct node *tail = NULL;
	while( cur != NULL & otherCur != NULL) {
		if(cur->key == otherCur->key) {
			if(tail == NULL) {
				tail = cur;
			}  else {
				//Tail is valid, Do nothing
			}

		} else {
			tail = NULL; //reset tail
		}

		cur = cur->next;
		otherCur = otherCur->next;
	}
	return tail;
	
}

void ll::insert(int key) {

	struct node *n = new node();
	n->key = key;
	n->next = NULL;

	if( head == NULL) { 
		head = n;
	} else {
		n->next = head;
		head = n;
	}	
	size++;	
}

void ll::print() const {
	struct node *cur = head;
	while(cur != NULL) {
		cout << "\t" << cur->key;
		cur = cur->next;
	}
	cout << "\n";
}

void test() {
	ll l1, l2;
	l1.insert(5);
	l2.insert(5);
	
	l1.insert(4);
	l2.insert(4);
	
	l1.insert(1);
	l2.insert(3);

	l1.insert(2);
	l2.insert(2);

	l1.insert(7);
	l2.insert(8);
	
	l2.insert(-1);
	l2.insert(12);
	l2.insert(13);

	l1.print();
	l2.print();

	const struct node *commonTail = l1.getCommonTail(l2); //works with l1.getCommonTail(l2) also
	const struct node *cur = commonTail;
	cout << "Common Tail \n";
	while(cur != NULL) {
		cout << "\t"<< cur->key;
		cur = cur->next;
	}
	cout << "\n";


}


int main() {
	test();
}
