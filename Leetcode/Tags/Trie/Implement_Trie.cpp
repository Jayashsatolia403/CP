struct TrieNode {
public: 

	TrieNode* links[26];
	bool flag;

	void put(char ch, TrieNode* node) {
		links[ch-'a'] = node;
	}

	TrieNode* get(char ch) {
		return links[ch-'a'];
	}

	bool containsKey(char ch) {
		return links[ch-'a'] != NULL;
	}

	void endString() {
		flag = true;
	}
};


class Trie {
private: TrieNode* root;
public:

	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode* node = root;

		for (char c: word) {
			if (!node->containsKey(c)) node->put(c, new TrieNode());
			node = node->get(c);
		}

		node->endString();
	}

	bool search(string word) {
		TrieNode* node = root;

		for (char c : word) {
			if (node->containsKey(c)) {
				node = node->get(c);
			}
			else return false;
		}

		if (node->flag) return true;

		return false;
	}

	bool startsWith(string word) {
		TrieNode* node = root;

		for (char c : word) {
			if (node->containsKey(c)) {
				node = node->get(c);
			}
			else return false;
		}

		return true;
	}
};