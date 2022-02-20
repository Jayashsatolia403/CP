#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";

        string s = countAndSay(n-1);

        string result = "";

        int cnt = 1;
        char c = s[0];

        for (int i=1; i < s.length()+1; i++) {
        	if (s[i] != s[i-1]) {
        		result += cnt+'0';
        		cnt = 0;
        		result += c;
        		c = s[i];
        	}
        	cnt++;
        }

        if (result.empty()) { result = cnt + '0'; result += c; }

        return result;
    }
};



int main() {
	int n;
	cin >> n;

	cout << Solution().countAndSay(n) << endl;

	return 0;
}