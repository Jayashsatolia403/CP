#include <bits/stdc++.h>
using namespace std;


// Not Done Properly

class Solution {
public:
    int myAtoi(string s) {
        int result=0;
        bool is_neg = false;
        bool done = false, started = false;

        for (char c : s) {
        	if (c == '-' && !done) { if (!started) is_neg = true; done = true; if (started) break; else continue; }
        	if (c == ' ' || (!done && c == '+')) { done = true; if (started) break; else continue; }
        	if (!isdigit(c)) break;

        	started = true;

        	result += c-'0';
        	if (!is_neg && result > INT_MAX/10) return INT_MAX;
        	else if (is_neg && -result < INT_MIN/10) return INT_MIN;
        	result *= 10;
        }

        result /= 10;

        result = is_neg ? -1*result : result;

        return result;
    }
};



int main() {
	string s;
	getline(cin, s);

	cout << Solution().myAtoi(s) << endl;

	return 0;
}