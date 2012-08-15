#ifndef _NODE_H
#define _NODE_H

template<class T> struct node {
	T val;
	struct node<T> *next;
	struct node<T> *prev;
	node() {}
	node(T value) : val(value) {}
};

#endif
