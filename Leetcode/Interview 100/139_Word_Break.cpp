#include <bits/stdc++.h>
using namespace std;



class DPSolution {
public:
	bool wordBreak(string s, vector<string>& v) {
		int n = s.length();
		vector<bool> dp(n+1, false);
		dp[0] = true;

		set<string> words;

		for (string s : v) words.insert(s);

		for (int i=1; i <= n; i++) {
			for (int j=0; j < i; j++) {
				if (dp[j] && words.count(s.substr(j, i-j))) {
					dp[i] = true;
				}
			}
		}

		return dp[n];
	}
};



class Solution {
public:
	set<string> words;

	bool dfs(string s, vector<string>& wordDict) {
		if (s.empty()) return true;

		int n = s.length();

		for (int i=0; i < n; i++) {
			string x = s.substr(0, i+1);

			if (words.find(x) != words.end()) {
				bool result = dfs(s.substr(i+1, n-i-1), wordDict);

				if (result) return true;
			}
		}

		return false;
	}

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = wordDict.size();

        for (int i=0; i < n; i++) {
        	words.insert(wordDict[i]);
        }

        return dfs(s, wordDict);
    }
};




int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> wordDict(n, "");
	for (int i=0; i < n; i++) cin >> wordDict[i];

	cout << DPSolution().wordBreak(s, wordDict);

	return 0;
}