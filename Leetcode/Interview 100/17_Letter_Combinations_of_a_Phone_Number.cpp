#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	map<char, string> m = {
        	{'2', "abc"},
        	{'3', "def"},
        	{'4', "ghi"},
        	{'5', "jkl"},
        	{'6', "mno"},
        	{'7', "pqrs"},
        	{'8', "tuv"},
        	{'9', "wxyz"}
        };


	void backtrack(string digits, int i, vector<string>& result, string cur) {
		if (i == digits.length()) {
			result.push_back(cur);
			return;
		}
		if (i > digits.length()) return;

		for (char c : m[digits[i]]) {
			cur += c;
			backtrack(digits, i+1, result, cur);
			cur.pop_back();
		}
	}

    vector<string> letterCombinations(string digits) {

    	if (digits.empty()) return vector<string>();

        vector<string> result;

        int n = digits.length();

        backtrack(digits, 0, result, "");

        return result;
    }
};



int main() {
	string digits;
	cin >> digits;

	vector<string> v = Solution().letterCombinations(digits);

	for (string s : v) cout << s << endl;

	return 0;
}