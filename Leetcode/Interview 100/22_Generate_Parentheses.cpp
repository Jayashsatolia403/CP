#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	void backtrack(int n, int open, int close, vector<string>& result, string s) {
		if (s.length() >= n*2) { result.push_back(s); return;}

		if (open < n) backtrack(n, open+1, close, result, s+'(');
		if (close < open) backtrack(n, open, close+1, result, s+')');
	}


    vector<string> generateParenthesis(int n) {
        vector<string> result;

        backtrack(n, 0, 0, result, "");

        return result;
    }
};



int main() {
	int n;
	cin >> n;

	vector<string> v = Solution().generateParenthesis(n);

	for (string s: v) cout << s << endl;

	return 0;
}