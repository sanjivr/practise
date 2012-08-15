#include <iostream>

#include "doubly_linked_list.h"

using namespace std;

const struct node* dll::insert(string msg, int cnt){
	struct node *n = new node(msg, cnt);
	if(insert_impl(n))
		return n;
	delete n;
	return NULL;
		
}

bool dll::insert_impl(const struct node *n_c) {
	if(n_c == NULL)
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


bool dll::remove_impl(const struct node *n_c) {

	if(n_c == NULL)
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
