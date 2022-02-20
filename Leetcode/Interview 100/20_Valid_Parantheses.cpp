#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    bool isValid(string s) {
        stack<char> check;

        map<char,char> m = {{'(',')'}, {'{','}'}, {'[',']'}};

        for (char c : s) {
        	if (m.find(c) == m.end()) {
        		if (!check.empty() && m[check.top()] == c) {
        			check.pop();
        		}
        		else return false;
        	}
        	else check.push(c);
        }

        return check.empty();
    }
};




int main() {
	string s;
	cin >> s;

	cout << Solution().isValid(s) << endl;
	return 0;
}