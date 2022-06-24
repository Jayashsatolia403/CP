#include <bits/stdc++.h>
using namespace std;

// 0 1 11 
// + + -

// (1+(4+5+2)-3)+(6+8)


class Solution {
public:
    int calculate(string s) {
        stack<int> vals, prevs;

        vector<string> v;

        string f = "";

        for (char c : s) {
        	if (c-'0' <= 9 && c-'0' >= 0) {
        		f += c;
        	}
        	else {
        		if (f.size()) v.push_back(f);

        		f = "";

        		if (c == ' ') continue;

        		string x = "";
        		x += c;
        		v.push_back(x);
        	}
        }

        if (f.size()) v.push_back(f);

        int cur = 0, prev = 1 ;

        for (string c : v) {

        	if (c.size() > 1 || (c[0] >= '0' && c[0] <= '9')) {
        		cur += stoi(c)*prev;
        	} 

        	if (c == "+" || c == "-") prev = (c == "+" ? 1 : -1);

        	if (c == "(") {
        		prevs.push(prev);
        		vals.push(cur);
        		cur = 0;
        		prev=1;
        	}

        	if (c == ")") {
        		cur = cur*prevs.top();
                prevs.pop();

                cur += vals.top();
                vals.pop();

        	}
        }

        return cur;
    }
};



int main() {
	string s;
	getline(cin, s);

	cout << Solution().calculate(s);

	return 0;
}