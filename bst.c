#include<stdio.h>
#include<stdlib.h>

struct node {
	int key;
	struct node *parent;
	struct node *left;
	struct node *right;
	
	node() {
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

struct bst {
	struct node *root;
	bst() {
		root =  NULL;
	}
};


bool is_leaf(struct node *n) {
return (n && (n->left == NULL) && (n->right==NULL));
}

bool is_left_child(struct node *n) {
return n &&  n->parent && n->parent->left && (n==n->parent->left);
}

bool is_right_child(struct node *n) {
return n && n->parent && n->parent->right && (n==n->parent->right);
}

void insert(int k, struct node *n) {
	if( k < n->key) {
		if(n->left) {
			insert(k, n->left);
		} else {
			struct node *a = new node();
			a->key = k;
			n->left = a;
			a->parent = n;
		}
	} else if ( k > n->key) {
		if(n->right) {
			insert(k, n->right);
		} else {
			struct node *a = new node();
			a->key = k;
			n->right = a;
			a->parent = n;
		}
	}

}

void bst_insert(int k, struct bst *b) {
	if(b == NULL) 
		return;
	if(b->root == NULL) {
		struct node *n = new node();
		n->key = k;
		b->root = n;
	} else {
		insert(k, b->root);
	}
}

void inorder(struct node *n) {
	if(n == NULL) 
		return;
	inorder(n->left);
	printf("%d\t", n->key);
	inorder(n->right);
}

void bst_inorder(struct bst *b) {
	if(b == NULL) 
		return;
	if(b->root == NULL)
		return;
	else {
		inorder(b->root);
	}
}

struct node* find(int k , struct node *n) {
	if(n == NULL)
		return NULL;
	if (n->key == k)
		return n;
	if(k < n->key)
		return find(k, n->left);
	if(k > n->key)
		return find(k, n->right);
}

struct node* bst_find(int k, struct bst *b) {
	if(b == NULL)
		return NULL;
	if(b->root == NULL)
		return NULL;
	return find(k, b->root);
}

void del(int k, struct bst *b) {
	struct node *n = bst_find(k, b);
	if(n) {
		
	} else {
		return;
	}
}


int main() {

	struct bst b;
	while(1) {
		printf("1.insert\n2.inorder\n3.exit\n4.find\n");
		int ch;
		scanf("%d", &ch);
		switch(ch) {
			case 1: printf("Enter key: ");
				int k;
				scanf("%d", &k);
				bst_insert(k, &b);
				printf("\n");
				break;
			case 2:
				bst_inorder(&b);
				printf("\n");
				break;
			case 3:
				exit(0);
				break;
			case 4:
				scanf("%d", &k);
				struct node *n = bst_find(k, &b);
				if(n)
					printf("%d found\n", k);
				else
					printf("%d not found\n", k);

		}

	}

}
