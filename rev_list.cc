#include<iostream>

using namespace std;

struct node {
	struct node *next;
	int key;
};

class ll {
	private:
		struct node *head;
		struct node *reverse_block(struct node *, int n);
	public:
		ll();
		void insert(int key);
		void print();
		void reverse();
		void reverse(int n);
};

ll::ll():head(NULL){}

void ll::insert(int key) {

	struct node *n = new node();
	n->key = key;
	n->next = NULL;

	if( head == NULL) { 
		head = n;
		return;
	} else {
		n->next = head;
		head = n;
	}	
}

void ll::print() {
	struct node *cur = head;
	while(cur != NULL) {
		cout << "\t" << cur->key;
		cur = cur->next;
	}
	cout << "\n";
}

void ll::reverse() {
	struct node *cur = head;
	struct node *prev = NULL;

	do {
		struct node *tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}while(cur != NULL);

	head = prev;
}

void ll::reverse(int n) {
	
	head = reverse_block(head, n);
}


struct node* ll::reverse_block(struct node *oldHead, int n) {
	if(oldHead== NULL)
		return NULL;

	struct node *prev = NULL;
	int count = n;

	struct node *cur = oldHead;
	struct node *t;
	struct node *newHead = NULL;

	while(cur != NULL && count > 0) {
		t = cur->next;
		cur->next = prev;
		prev = cur;
		cur = t;
		count--;
	}

	newHead = prev;
	oldHead->next = reverse_block(cur, n);
	return newHead;
}

int main() {
	int ch;
	int n;
	ll l;
	while(1) {
		cout << "\n1.enter\n2.print\n3.reverse\n4.exit\n5.reverse block\n";
		cin >> ch;	
		switch(ch) {
			case 1: cout << "\n Enter:";
				cin >> n;
				l.insert(n);
				break;
			case 2:
				l.print();
				break;
			case 3: l.reverse();
				break;
			case 4: return 0;
			case 5: cout << "\n block size\n";
				cin >> n;
				l.reverse(n);
		}
	}
}
