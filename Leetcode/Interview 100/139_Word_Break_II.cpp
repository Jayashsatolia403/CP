#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	set<string> words;
	vector<string> result;

	void dfs(string s, vector<string>& wordDict, string cur) {
		if (s.empty()) {
			result.push_back(cur.substr(1, cur.length()));
			return;
		}

		int n = s.length();

		for (int i=0; i < n; i++) {
			string x = s.substr(0, i+1);

			if (words.find(x) != words.end()) {
				string temp = cur;
				cur += " " + x; 
				dfs(s.substr(i+1, n-i-1), wordDict, cur);
				cur = temp;
			}
		}
	}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n = wordDict.size();

        for (int i=0; i < n; i++) {
        	words.insert(wordDict[i]);
        }

        dfs(s, wordDict, "");
        
    	return result;
    }
};




// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
        
//     }
// };



int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> wordDict(n, "");
	for (int i=0; i < n; i++) cin >> wordDict[i];

	vector<string> result = Solution().wordBreak(s, wordDict);

	for (string x: result) cout << x << endl;

	return 0;
}