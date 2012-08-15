#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "node.h"

template<class T> class linkedList {
	private:
		struct node<T> *head;
	public:
		linkedList();
		void insert(T value);
		void insert(T value, int position);
		T remove();
		T remove(int position);
		void print();
};
#endif
