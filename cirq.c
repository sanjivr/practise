#include<stdio.h>
#include<stdlib.h>

struct cirq {
	//One slot will always be empty to differentiate between full and empty cases
	int strg[8];
	int head; //points to first element
	int tail; //points to next slot to insert
	
	cirq();
	void encirq(int k);
	int decirq();
	void print();

	bool full();
	bool empty();

};

cirq::cirq() {
	head = tail = 0;
}

bool cirq::full() {
	if((tail + 1)%8 == head) 
		return true;
	else
		return false;
}

bool cirq::empty() {
	if(head == tail)
		return true;
	else
		return false;

}

void cirq::encirq(int k) {
	if(full()) {
		printf("Queue Full\n");
	} else {
		strg[tail] = k;
		tail = (tail + 1)%8;
	}
}


int cirq::decirq() {
	if(empty()){
		printf(" Queue Emtpy \n");
		return -1;
	} else {
		int ele = strg[head];
		head = (head + 1)%8;
		return ele;
	}
}

void cirq::print() {

	for(int i = head; i != tail; i = (i+1)%8) {
		printf("%d\t", strg[i]);
	}
	printf("\n");

}

int main() {
	struct cirq q;
	while(1) {
		printf("1. insert\n");
		printf("2. delete\n");
		printf("3. print\n");
		printf("4. exit\n");
		int ch;
		scanf("%d", &ch);
		int key;
		switch(ch) {
			case 1:
				printf("insert...\n");
				scanf("%d", &key);
				q.encirq(key);
				break;
				
			case 2:
				key = q.decirq();
				printf("decirqd %d\n", key);
				break;
	
			case 3:	
				q.print();
				break;
			case 4: exit(0);
		}
	}
}
