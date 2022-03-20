class LRUCache {
public:
    LRUCache(int capacity) {
        map<int, int> m;
        int c = capacity;
        queue<int> q;
    }
    
    int get(int key) {
    	if (q.size() == capacity) {
    		q.pop();
    		q.push(key);
    	}

        return m[key];
    }
    
    void put(int key, int value) {
        if (q.size() == capacity) {
        	int x = queue.back();
        	m.erase(x);
        	m[key] = value;
        	q.pop();
        	q.push(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
