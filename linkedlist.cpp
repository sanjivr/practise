#include "linkedlist.h"
#include <iostream>

using namespace std;

template<class T> linkedList<T>::linkedList(){
	head = NULL;
}

template<class T> void linkedList<T>::insert(T value) {
	struct node<T> *inode = new struct node<T>();
	inode->val = value;
	inode->next = NULL;
	if(head == NULL) {
		head = inode;
	} else {
		inode->next = head;
		head = inode;
	}
}

template<class T> void linkedList<T>::print() {
	if(head == NULL) {
		cout << "List Empty\n";
		return;
	}
	struct node<T> *cur = head;
	do {
		cout << cur->val <<"\t";
		cur = cur->next;
	}while(cur != NULL);
	cout << "\n";	
}

int main() {

	linkedList<int> ll;
	ll.insert(2);
	ll.insert(1);
	ll.insert(4);
	ll.print();
}
