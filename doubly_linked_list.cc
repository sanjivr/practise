#include <iostream>

#include "doubly_linked_list.h"

using namespace std;



void dll::print() {

	struct node *cur = head;
	while(cur != NULL) {
		cout << "\t" << cur->key;
		cur = cur->next;
	}
	cout << "\n";
	cur = tail;
	while(cur != NULL) {
		cout << "\t" << cur->key;
		cur = cur->prev;
	}
	cout << "\n";
	cout << "Size : "<< size << "\n";
}

const struct node* dll::insert(int val){
	struct node *n = new node(val, this);
	if(insert_impl(n))
		return n;
	delete n;
	return NULL;
		
}

bool dll::insert_impl(const struct node *n_c) {
	if(n_c == NULL)
		return false;
	if(n_c->owner != this)
		return false;

	struct node *n = const_cast<struct node *>(n_c);
	
	if(head == NULL && tail == NULL) {
		head = n;
		tail = n;
	}
	else {
		n->next = head;
		head->prev = n;
		head = n;
	}
	size++;
	return true;
}

void dll::remove(int val) {

	const struct node *n = find(val);
	if(remove_impl(n)) {
		delete n;
	}
}


bool dll::remove_impl(const struct node *n_c) {

	if(n_c == NULL)
		return false;
	if(n_c->owner != this)
		return false;

	struct node *n = const_cast<struct node *>(n_c);

	struct node *prev  = n->prev;
	struct node *next  = n->next;

	n->prev = NULL;
	n->next = NULL;

	if(prev) {
		prev->next = next;
	}
	if(next) {
		next->prev = prev;
	}

	if(n == head) 
		head = next;
	if(n == tail)
		tail = prev;

	size--;
	return true;

}

void dll::move_to_head(int val) {
	const struct node *n = find(val);
	move_to_head_impl(n);
}

bool dll::move_to_head_impl(const struct node *n) {

	if(n == NULL)
		return false;
	if(n->owner != this)
		return false;

	return (remove_impl(n) && insert_impl(n));

}

const struct node * dll::find(int val) {

	struct node *cur = head;
	while(cur != NULL) {
		if(cur->key == val) 
			return cur;
		else
			cur = cur->next;
	}

}

/*int main() {

	dll l;
	int ch;
	int val;
	while(1) {
		cout << "\n1.Insert\n2.remove\n3.move to head\n4.print\n5.exit\n";
		cin >> ch;
		switch(ch) {
			case 1:
				cout << "Value: ";
				cin >> val;
				l.insert(val);
				break;
			case 2:
				cout << "Value: ";
				cin >> val;
				l.remove(val);
				break;

			case 3:
				cout << "Value: ";
				cin >> val;
				l.move_to_head(val);
				break;
			case 4:
				l.print();
				break;
			case 5: return 0;

		}
	}
}
*/
