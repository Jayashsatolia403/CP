#include <bits/stdc++.h>
using namespace std;



class Node {
public:
	int key, val;
	Node next, prev;

	Node(int key, int val) {
		key = key;
		val = val;
		next = NULL;
		prev = NULL;
	}
}


class LRUCache {
public:
	map<int,Node*> cache;
	int capacity = capacity;
	Node* left, right;

    LRUCache(int capacity) {
        capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    void remove(Node* node) {
    	Node* prev = node->prev, next = node->next;

    	prev->next = next;
    	next->prev = prev;
    }

    void insert(Node* node) {
    	right->next = node;
    	node->prev = right;
    }
    
    int get(int key) {
        if (cache.count(key)) {
        	remove(cache[key]);
        	insert(cache[key]);
        	return cache[key]->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        
        if (cache.count(key)) {
        	remove(cache[key]);
        }

        Node* node = new Node(key, value); 
        cache[key] = node;
    	insert(cache[key]);

    	if (cache.size() > capacity) {
    		cache.erase(left->next->key);
    		remove(left->next);
    	}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



int main() {
	return 0;
}