#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<ext/hash_set>
#include<ext/hash_map>
#include<ext/hash_fun.h>
#include "doubly_linked_list.h"


using namespace std;

using namespace __gnu_cxx;

namespace __gnu_cxx {
        template<> struct hash<std::string> {
                hash<const char*> h;
                size_t operator() (const std::string&s) const {
                        {   
                                return h(s.c_str());
                        }   
                }   
        };  
}
class topic{

	private:
		string topic_id;
		hash_map<string, struct node*>  subscriber_map;	//for each subscriber, pointer to next position in message_queue to get message from
		dll messages;
		bool subscriber_exists(const string& subscriber_id);	
		
	protected:
		void put(const string& message);	
		string get_message(const string& subscriber_id);
		void subscribe(const string& subscriber_id);
		void unsubscribe(const string& subscriber_id);

	public:
		topic(const string& id): topic_id(id){}
		friend class broker;
		~topic();
};

topic::~topic() {
/*********************
	TODO
********************/
}

bool topic::subscriber_exists(const string& subscriber_id) {
	if(subscriber_map.find(subscriber_id) != subscriber_map.end())
		return true;
	else
		return false;
}

void topic::put(const string& message) {
	int num_subscribers = subscriber_map.size();
	messages.insert(message, num_subscribers);
}

string topic::get_message(const string& subscriber_id) {
	if(subscriber_exists(subscriber_id)) {
		hash_map<string, struct node*>::iterator sub_iterator = subscriber_map.find(subscriber_id);
		struct node *n = sub_iterator->second;	
		string message;
		if(n != NULL){
			n->count--;
			struct node *t = n->next;
			message = n->message;
			if(n->count <= 0)
			{
				messages.remove_impl(n);
			}
			subscriber_map.insert(pair<string, struct node*>(subscriber_id, t));
		} else {
			n = const_cast<struct node*>(messages.get_head());
			if(n != NULL) {
				n->count--;
				struct node*t = n->next;
				message = n->message;
				if(n->count <= 0) {
					messages.remove_impl(n);
				}
				subscriber_map.insert(pair<string, struct node*>(subscriber_id, t));
			} else {
				cout << "No eligible messages\n";
			}
		}
		return message;
		
	} else {
		return string("NOT SUBSCRIBED TO THIS TOPIC");
	}

}

void topic::subscribe(const string& subscriber_id) {
	if(!subscriber_exists(subscriber_id)){
		subscriber_map.insert(pair<string, struct node*>(subscriber_id, const_cast<struct node*>(messages.get_tail())));
		cout << "\nAdded " << subscriber_id << "to topic " << topic_id << "\n";
	}
	else {
		cout << "\nAlready subscribed" << subscriber_id << "to topic " << topic_id << "\n";
		return;
	}
}

void topic::unsubscribe(const string& subscriber_id) {
	if(subscriber_exists(subscriber_id)) {
		subscriber_map.erase(subscriber_id);
		//Decrease the delivery count for all messages by 1
	} else {
		return;
	}
}



class broker{

	private:
		hash_map<string, topic*> topics;
		topic* find_topic(const string& topic_id);
	public:
		broker() {}
		void add_topic(const string &topic_id);
		void put_message(const string& message, const string& topic_id);
		string get_message(const string& subscriber_id, const string& topic_id);	
		void subscribe(const string& subscriber_id, const string& topic_id);
		void unsubscribe(const string& subscriber_id, const string& topic_id);
		~broker();
		

};

broker::~broker() {
	hash_map<string, topic*>::iterator topics_iterator;
	topics_iterator = topics.begin();

	topic *t = NULL;	

	while(topics_iterator != topics.end()) {
		t = NULL;
		t = topics_iterator->second;
		delete t;	
	}
	
	topics.clear();

}

topic* broker::find_topic(const string& topic_id) {
	topic *t = NULL;
	hash_map<string, topic*>::iterator topics_iterator = topics.find(topic_id) ;
	
	if(topics_iterator == topics.end()) {
		cout << "Error. Topic doesn't exist\n";
		return NULL;
	}

	t = topics_iterator->second;
	return t;


}

void broker::add_topic(const string &topic_id){
	topic *t = find_topic(topic_id);
	if(t != NULL) {
		cout << "Topic already exists\n";
		return;
	}
	t = new topic(topic_id);
	topics.insert(pair<string, topic *>(topic_id, t));
}

void broker::put_message(const string& message, const string& topic_id) {
	topic *t = find_topic(topic_id);
	if(t == NULL) {
		cout << "Internal Error. Topic has no associated topic object\n";
		return;
	}
	
	t->put(message);

}

string broker::get_message(const string& subscriber_id, const string& topic_id) {
	topic *t = find_topic(topic_id);
	if(t == NULL) {
		cout << "Internal Error. Topic has no associated topic object\n";
		return string("NO SUCH TOPIC");
	}

	return t->get_message(subscriber_id);
	
}

void broker::subscribe(const string& subscriber_id, const string& topic_id) {
	topic *t = find_topic(topic_id);
	if(t == NULL) {
		cout << "Internal Error. Topic has no associated topic object\n";
		return;
	}
	t->subscribe(subscriber_id);
}

void broker::unsubscribe(const string& subscriber_id, const string& topic_id) {
	topic *t = find_topic(topic_id);
	if(t == NULL) {
		cout << "Internal Error. Topic has no associated topic object\n";
		return;
	}
	t->unsubscribe(subscriber_id);

}

class subscriber {

	private:
		string subscriber_id;
		hash_set<string> topic_set;

	public:


};


class producer {

		
//	static produce_message(const string& message, const string& topic);

};


int main() {

	broker b;
	int ch;
	while(1) {
		cout<< "\n1.Add topic\n2.Subscribe\n3.Unsubscribe\n4.Push Message\n5.Get Message\n";
		cin>> ch;
		string topic;
		string subscriber;
		string message;
		switch(ch) {
			case 1: cout << "\nTopic Name..";
				cin>> topic;
				b.add_topic(topic);
				break;
			case 2:
				cout << "\nTopic Name..";
				cin >> topic;
				cout << "\nSub id..";
				cin >> subscriber;
				b.subscribe(subscriber, topic);
				break;
			case 3:
				cout << "\nTopic Name..";
				cin >> topic;
				cout << "\nSub id...";
				cin >> subscriber;
				b.unsubscribe(subscriber, topic);
				break;
			case 4:
				
				cout << "\nTopic Name..";
				cin >> topic;
				cout << "\nMessage...";
				cin >> message;
				b.put_message(message, topic);
				break;

			case 5:
				cout << "\nTopic Name..";
				cin >> topic;
				cout << "\nSubscriber..";
				cin >> subscriber;
				cout << "\n Message.."<< b.get_message(subscriber, topic);
				break;
				
				
		}
	}
}
