#include <bits/stdc++.h>
using namespace std;



class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int a, int b) {
            key = a;
            val = b;
            prev = NULL;
            next = NULL;
        }
    };

    Node* left = new Node(-1,-1);
    Node* right = new Node(-1,-1);

    int csize;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        csize = capacity;
        left->next = right;
        right->prev = left;
    }

    void insertNode(Node* node) {
        right->prev->next = node;
        node->prev = right->prev;
        node->next = right;
        right->prev = node;

        m[node->key] = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        m.erase(node->key);
    }
    
    int get(int key) {
        if (!m.count(key)) return -1;

        Node* node = m[key];

        deleteNode(node);
        insertNode(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (m.size() == csize && !m.count(key)) {
            deleteNode(left->next);
        }

        if (m.count(key)) {
            deleteNode(m[key]);
        }

        insertNode(new Node(key, value));

        // cout << "start" << endl;
        // for (auto& it : m) {
        //     cout << it.first << " >> " << it.second->val << endl;
        // }
        // cout << "end" << endl;

    }
};





int main() {
    LRUCache l = LRUCache(2);

    l.put(2,6);

    cout << l.get(1) << endl;

    l.put(1,5);
    l.put(1,2);

    cout << l.get(1) << endl;
    cout << l.get(2) << endl;

    return 0;
}