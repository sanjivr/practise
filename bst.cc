#include <iostream>
#include <stack>
#include <deque>
#include <queue>

using namespace std;
struct node {
	struct node *left;
	struct node *right;
	struct node *parent;
	int key;
};


class BST {
	private:
		struct node *root;
		void inorder(struct node *);
		void preorder(struct node *);
		void postorder(struct node *);
		struct node* find_min_at_rooted_subtree(struct node *);
		void min_height(struct node*, int cur_depth, int &min);
	public:
		BST();
		~BST(){}
		void insert(int value);
		struct node* search(int value);
		void remove(int value) ;
		struct node* find_successor(struct node *);
		void inorder();
		void inorder_it();
		void preorder() ;
		void preorder_it() ;
		void postorder() ;
		void postorder_it();
		void bfs();
		void bfs_level_order(); //This can be modified to print the borders of a tree
		void bfs_level_zigzag();
		void min_height();

};

BST::BST() {
	root = NULL;
}

void BST::insert(int value) {
	if(root == NULL) {
		root = new node();
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		root->key = value;
		return;
	}

	struct node *cur = root;
	struct node *entry = new node();
	entry->key = value;
	while(1) {
		if(value < cur->key) {
			if(cur->left != NULL) {
				cur = cur->left;
			}
			else {
				cur->left = entry;
				entry->parent = cur;
				return;
			}

		} else if (value > cur->key) {
			if(cur->right != NULL) {
				cur = cur->right;
			} else {
				cur->right = entry;
				entry->parent = cur;
				return;
			}
		} else {
			return;
		}
	}
}

struct node* BST::search(int value) {
	
	struct node *cur = root;
	while(cur != NULL) {
		if (cur->key == value) {
			cout << "\nFound \n";
			return cur;
		}
		else if (value < cur->key) 
			cur = cur->left;
		else
			cur = cur->right;
	
	}
	cout << "\nNot Found \n";
	return NULL;
}

void BST::inorder(struct node *n) {

	if(n == NULL)
		return;
	else {
		inorder(n->left);
		cout << "\t"<< n->key;
		inorder(n->right);
	}
}

void BST::inorder() {
	inorder(root);
	cout << "\n";
}

void BST::inorder_it() {
	
	if(!root)
		return;

	struct node *cur = root;
	stack<struct node*> st;
	
	do {
		if(cur) {
			st.push(cur);
			cur = cur->left;
		} else {
			struct node *n = st.top();
			cout << "\t" << n->key;
			st.pop();
			cur = n->right;
		
		}
		if(st.empty() && cur == NULL) 
			break;

	} while(1);
	cout << "\n";
}

void BST::preorder() {
	preorder(root);
	cout << "\n";
}

void BST::preorder(struct node *cur) {
	if(cur == NULL)
		return;
	cout << "\t"<<cur->key;
	preorder(cur->left);
	preorder(cur->right);
}

void BST::preorder_it() {
	
	if(!root)
		return;
	
	struct node *cur = root;
	stack<struct node *> st;
	do {
		if(cur != NULL) {
			cout << "\t" << cur->key;
			st.push(cur);
			cur = cur->left;
		} else {
			struct node *n = st.top();
			st.pop();
			cur = n->right;
		}
		if(st.empty() && cur == NULL)
			break;
	} while(1);
	cout << "\n";
}

void BST::postorder() {
	postorder(root);
	cout << "\n";
}

void BST::postorder(struct node *cur) {
	if(cur == NULL)
		return;
	postorder(cur->left);
	postorder(cur->right);
	cout << "\t" << cur->key;
	return;
}

void BST::postorder_it() {


	struct node *cur = root;
	stack<struct node *> st, q;
	while(cur != NULL) {
		st.push(cur);
		if(cur->left) {
			q.push(cur->left);
		}
		if(cur->right) {
			q.push(cur->right);
		}
		if(!q.empty()) {
			cur = q.top();
			q.pop();
		} else {
			cur = NULL;
		}
	} 
	
	while(!st.empty()) {
		struct node *n = st.top();
		st.pop();
		cout << "\t"<<n->key;
	}
	cout << "\n";
}

void BST::bfs() {
	cout << "\n";
	struct node *cur = root;
	queue<struct node*> q;
	q.push(cur);
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		if(cur->left) 
			q.push(cur->left);
		if(cur->right)
			q.push(cur->right);
		cout << "\t" << cur->key;
	}

}

struct node_bfs {
	struct node *node;
	int level;
	node_bfs(struct node *n, int l){ node = n; level =l; }
};

void BST::bfs_level_order() {
	if(!root) 
		return;
	cout << "\n";
	int cur_l = 0;
	int prev_l = 0;
	struct node_bfs *cur = new node_bfs(root,0);
	queue<struct node_bfs *> q;
	q.push(cur);
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		if(cur->node->left)
			q.push(new node_bfs(cur->node->left, cur->level+1));
		if(cur->node->right)
			q.push(new node_bfs(cur->node->right, cur->level+1));

		cur_l = cur->level;
		if(cur_l != prev_l) {
			cout << "\n";
			prev_l = cur_l;
		}
		cout << "\t" << cur->node->key;
		delete cur;
	}
}
void BST::bfs_level_zigzag() {
	if(!root)
		return;
	cout << "\n";
	int cur_l = 0;
	int prev_l = 0;
	struct node_bfs *cur = new node_bfs(root,0);
	queue<struct node_bfs *> q;
	stack<struct node *> st;
	q.push(cur);
	bool flip = false;
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		if(cur->node->left)
			q.push(new node_bfs(cur->node->left, cur->level+1));
		if(cur->node->right)
			q.push(new node_bfs(cur->node->right, cur->level+1));

		cur_l = cur->level;
		if(cur_l != prev_l) {
			cout << "\n";
			prev_l = cur_l;
			flip = !flip;
			while(!st.empty()) {
				struct node *n = st.top();
				st.pop();
				cout << "\t" << n->key;
			}
			cout << "\n";
		}
		if(flip)
			st.push(cur->node);
		else
			cout << "\t" << cur->node->key;
		delete cur;
	}

	while(!st.empty()) {
		struct node *n = st.top();
		st.pop();
		cout << "\t" << n->key;
	}
	cout << "\n";
}	

void BST::remove(int value) {

	struct node *n = NULL;
	n = this->search(value);
	if( n == NULL) 
		return;

	struct node *p = n->parent;
	//1. element to be deleted is a leaf.
	if(n->left == NULL && n->right == NULL) {
		if(p == NULL) { //element is root
			root = NULL;
		} else if (p->left == n) {
			p->left = NULL;
		} else if (p->right == n) {
			p->right = NULL;
		}

		delete n;
		return;
	}
	
	//2. element to be deleted has only 1 child
	if(n->left == NULL || n->right == NULL) {
		struct node *child_n = (n->left == NULL)?n->right:n->left; //get the single child of n
		child_n->parent = p;
		if(p == NULL) { //n was the root
			root = child_n;
		} else if (p->left == n) {
			p->left = child_n;
		} else if (p->right == n) {
			p->right = child_n;
		}
		delete n;
		return;
		
	}	
	
	if(n->left != NULL && n->right != NULL) {
		struct node *successor = this->find_successor(n);
		if(successor != NULL) {
			int tmp = successor->key;
			this->remove(successor->key); //remove the succssor
			n->key = tmp;
			return;
			
		} else {
			cout << "This condition cannot arise \n";
			return;
		}
	}

	//if(n) has two children;
}

struct node* BST::find_min_at_rooted_subtree(struct node *n) {
	if (!n) 
		return NULL;
	struct node *cur = n;
	while(cur->left != NULL) {
		cur = cur->left;
	}
	return cur;

}

struct node* BST::find_successor(struct node *n) {
	
	if(n == NULL)
		return NULL;
	
	if( n == root) 
		return find_min_at_rooted_subtree(n->right);

	else {
		struct node *p = n->parent;
		if(p->left == n)  { //node is a left child
			if(n->right) //node has right children
				return find_min_at_rooted_subtree(n->right);
			else // node has only left children
				return p;
		}
		else if(p->right == n) { //if node is a right child;
			if(n->right)  //if node has right children;
				return find_min_at_rooted_subtree(n->right);
			else { //node is  a leaf;
					
				while(p!= NULL && p->right == n) {
					n = p;
					p = p->parent;
				}
				if(p == NULL)
					return NULL;
				else
					return p;
			}
		}

	}
}

void BST::min_height(struct node *n, int cur_depth, int &min)
{
	if(n == NULL){
		int height = cur_depth-1;
		if(min > height)
			min = height;
		return;
	}

	min_height(n->left, cur_depth+1, min);
	min_height(n->right, cur_depth+1, min);

}

void BST::min_height() {
	int min = 200;
	min_height(root, 0, min);
	cout << "Min Height = " << min << "\n";
}
		

int main() {
	
	BST bst;
	int ch;
	int value;
	while(1) {
		cout << "\n1.Enter\n2.Search\n3.Print\n4.Exit\n5.bfs\n6.Remove\n7.Successor\n8.setup\n";
		cin >> ch;
		switch(ch) {
			case 1: cout << "\nInsert ..";
				cin >> value;
				bst.insert(value);
				break;
			case 2: 
				cout << "\nSearch..";
				cin>> value;
				bst.search(value);
				break;
			case 3: bst.inorder_it();
				//bst.preorder();
				//bst.preorder_it();
				bst.postorder();
				bst.postorder_it();
				break;
			case 4:
				return 0;
			case 5: bst.bfs_level_order();
				//bst.bfs_level_zigzag();
				break;
			case 6: cout << "\nRemove..";
				cin >> value;
				bst.remove(value);
				bst.inorder_it();
				break;

			case 7: cout << "Successor of...";
				cin >> value;
				{	
				struct node *n = bst.find_successor(bst.search(value));
				if(n) 
					cout << "Successor = " << n->key<<"\n";
				else
					cout << "No successor \n";
				}
				break;
			case 8: 
				bst.insert(10);
				bst.insert(5); bst.insert(15);
				bst.insert(3); bst.insert(7); bst.insert(12); bst.insert(20);
				bst.insert(2); bst.insert(4); bst.insert(18); bst.insert(30);
				bst.insert(1); bst.insert(40);
				bst.insert(35); bst.insert(44);
				break;
			case 9:
				bst.min_height();
				break;
		}
	}
}
