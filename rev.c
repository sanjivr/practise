#include<stdlib.h>
#include<stdio.h>

struct node {
	struct node* prev; //Unused in linked list
	struct node* next; 
	int key;
};

struct link_list {
	struct node *head;
	link_list() {
		head =  new struct node();
		head->next = NULL;
	}
};


void insert(int k, struct link_list *ll) {
	struct node *cur = new struct node();
	cur->key = k;
	cur->next = NULL;
	struct node *n = ll->head;
	while(n->next != NULL) {
		n = n->next;
	}		
	n->next = cur;
}

void del(int k, struct link_list *ll){
	struct node *n = ll->head;
	while(n && n->next != NULL) {
		if(n->next->key == k) {
			struct node *t = n->next;
			n->next = t->next;
			delete t;
		}
		n = n->next;
	}
}

void print(struct link_list *ll) {
	struct node *n = ll->head;
	while ( n->next != NULL ) {
		printf("%d\t", n->next->key);
		n = n->next;
	}	
	printf("\n");

}

void rev(struct link_list *ll) {

	struct node *a, *b, *c;
	a = ll->head->next;
	if(a == NULL) {
		return;
	}
	b = a->next; 
	a->next = NULL; //Required.
	if(b == NULL) {
		return;
	}
	c = b->next;

	while ( c != NULL) {
		b->next = a;
		a = b;
		b = c;
		c = c->next;
	}
	b->next = a;
	ll->head->next = b;

}

int main() {
	struct link_list *ll = new struct link_list();
	int i;
	for( i = 0; i <= 5; i++) {
		int t;
		scanf("%d", &t);
		insert(t, ll);
	}

	print(ll);
	rev(ll);
	print(ll);
	/*for (i = 0; i <= 8;i++) {
		
		int t;
		scanf("%d", &t);
		del(t,ll);
		print(ll);
	} */
}
