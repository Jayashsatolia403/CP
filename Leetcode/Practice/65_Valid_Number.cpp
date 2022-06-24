#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isNumber(string s) {

    	set<char> valid = {'+', '-', '.', 'e', 'E', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
        
        bool done_dot = false, done_e = false, done_num = false, done_num_after_e=false;

        int n = s.size();

        for (int i=0; i < n; i++) {

        	if (!valid.count(s[i])) return false;

        	if (s[i] == '+' || s[i] == '-') {
        		if (i != 0) {
        			if (s[i-1] != 'e' && s[i-1] != 'E') return false;
        		}
        	}

        	if (s[i] == '.') {
        		if (done_dot || done_e) return false;
        		else done_dot = true;
        	}

        	if (s[i] == 'e' || s[i] == 'E') {
        		if (done_e || !done_num) return false;
        		else {
        			done_e = true;
        		}
        	}

        	if (s[i] >= '0' && s[i] <= '9') { done_num = true; if (done_e) done_num_after_e = true; }
        }

        if (done_dot && !done_num) return false;
        if (done_e && !done_num_after_e) return false;
        if (s[0] == '+' || s[0] == '-') {
        	if (!done_num) return false;
        }

        return true;
    }
};



int main() {
	string s;
	cin >> s;

	cout << Solution().isNumber(s);

	return 0;
}