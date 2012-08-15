#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<algorithm>


using namespace std;


void print_stack(stack<char> &st) {
	stack<char> tmp;
	while(!st.empty()) {
		char c = st.top();
		st.pop();
		tmp.push(c);
	}

	while(!tmp.empty()) {
		char c= tmp.top();
		tmp.pop();
		st.push(c);
		cout<<c;
	}
	cout<<"\n";

}

/*

	eg:
		prefix = abc 	(c being top of stack)
		suffix = defg 	(d being front of queue)
		
		If size of prefix is "n" and size of suffix is "m", then there are "m" ways of populating the position "n+1"th  position.
		For each way of filling position "n+1" there are m-1 remaining characters which need to be permuted.
		eg:

		permute (abc, defg)
				abc+d + permute(efg)
				abc+e + permute(fgd)
				abc+f + permute(gde)
				abc+g + permute(def)
			
		This cycling of elements to be considered for "n+1"th position can be achieved by maintaining suffix as a queue
			
			iterating over the length of the queue
				pop from front of queue
			    	push to top of stack (i.e new prefix)
			    	generate all permutations for the remaining items in  suffix queue.
			    	pop from top of stack
			    	push to back of queue
		Once the iteration is complete, the queue will be in same ordering of elements as before the iteration

		to permute a whole string 
		permute(empty_stack, queue_with_all_chars_in_string)
*/

void permute (stack<char> &prefix, queue<char> &suffix, int &perm_count) {

	if(suffix.size() == 0) {
	//if it is required to print all combinations of lenght "n", then insted of suffix.size() == 0, check prefix.size() == n
		print_stack(prefix);
		perm_count++;
		return;
	}
	for(int i = 0; i < suffix.size(); i++) {
		char c = suffix.front();
		suffix.pop();
		prefix.push(c);
		permute(prefix, suffix, perm_count);
		c = prefix.top();
		prefix.pop();
		suffix.push(c);
	}
}

int main() {
	stack<char> prefix;
	queue<char> suffix;
	string input;
	int perm_count = 0;
	while(1) {
		cout << "Enter the string: ";
		cin >> 	input;
		cout << "\n";
		
		for(string::iterator it = input.begin(); it != input.end(); it++) {
			if(*it != '\0')
				suffix.push(*it);
		}
		
		permute(prefix, suffix, perm_count);

		cout << "Number of permutations = "<<perm_count << "\n";
		
		while(!prefix.empty())
			prefix.pop();
		while(!suffix.empty())
			suffix.pop();	
		perm_count = 0;
	}

}
