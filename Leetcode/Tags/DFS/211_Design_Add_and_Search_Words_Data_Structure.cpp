#include <bits/stdc++.h>
using namespace std;




class WordDictionary {
public:
    set<string> s;

    WordDictionary() {
        
    }
    
    void addWord(string word) {
        s.insert(word);
    }
    
    bool search(string word) {
        
        int n = word.size();

        if (s.count(word)) return true;

        for (int i=0; i < n; i++) {
        	if (word[i] == '.') {
        		for (int j=0; j < 26; j++) {
        			word[i] = 'a'+j;
        			if (search(word)) return true;
        		}
        	}
        }

        return false;
    }
};




int main() {
	WordDictionary* x = new WordDictionary();

	x->addWord("jayash");
	cout << x->search("j.y.s.") << endl;
	cout << x->search("jayash") << endl;
	cout << x->search(".....h") << endl;

	return 0;
}