#include <bits/stdc++.h>
using namespace std;





class Solution {
public:
	bool is_palindrome(string s, int i, int j, int dp[1001][1001] ) {
		if (i < 0 || j >= s.length() || i >= j) return true;
		if (s[i] != s[j]) return false;

		if (dp[i][j]) return dp[i][j];

		dp[i][j] = is_palindrome(s, i+1, j-1, dp);

		return dp[i][j];
	}

    string longestPalindrome(string s) {
        int n = s.length();

        // vector<vector<int>> dp(n, vector<int>(n, 0));

        int dp[1001][1001];

        for (int i=0; i < 1001; i++) for (int j=0; j < 1001; j++) dp[i][j] = 0;


        int result = 0, start=0, end=0;

        for (int i=0; i < n; i++) {
        	for (int j=i+1; j < n; j++) {
        		if (is_palindrome(s, i, j, dp)) {
        			if (result < j-i+1) {
        				result = j-i+1;
        				start = i;
        				end = j+1;
        			}
        		}
        	}
        }

        if (end-start == 0) return s.substr(0,1);


        return s.substr(start, end-start);
    }
};




int main() {
	string s;
	cin >> s;

	cout << Solution().longestPalindrome(s) << endl;
}