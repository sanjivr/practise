#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H

#include <iostream>

struct node {

	struct node *prev;
	struct node *next;
	void *owner;
	int key;

	node(int val, void *creator): prev(NULL), next(NULL), key(val), owner(creator) {}
};

class dll {

	private:
		struct node *head;
		struct node *tail;
		int size;

		bool insert_impl(const struct node* n);
		const struct node* find(int val);

	public:
		dll(): head(NULL), tail(NULL), size(0) {}
		const struct node* insert(int val);
		void remove(int val);
		void move_to_head(int val);

		bool remove_impl(const struct node *);
		bool move_to_head_impl(const struct node *);
		void print();
		int get_size() { return size;}
		const struct node* get_tail () {return tail;}
};

#endif
