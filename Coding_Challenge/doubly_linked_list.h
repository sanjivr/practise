#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>

using namespace std;

struct node {

	struct node *prev;
	struct node *next;
	string message;
	int count;

	node(string msg, int cnt): prev(NULL), next(NULL), message(msg), count(cnt) {}
	string get_message(){ 
		return message;
	}
};

class dll {

	private:
		struct node *head;
		struct node *tail;
		int size;

		bool insert_impl(const struct node* n);

	public:
		dll(): head(NULL), tail(NULL), size(0) {}
		const struct node* insert(string msg, int cnt);
		bool remove_impl(const struct node *);
		int get_size() { return size;}
		const struct node* get_tail () {return tail;}
		const struct node* get_head() { return head;}
};

#endif
