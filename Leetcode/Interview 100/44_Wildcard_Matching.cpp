#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length(), idx = 0;

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for (int i=1; i <= m; i++) if (dp[0][i-1] && p[i-1]=='*') dp[0][i] = true;


        for (int i=0; i < n; i++) {
        	for (int j=0; j < m; j++) {
        		if (s[i] == p[j] || p[j] == '?') dp[i+1][j+1] = dp[i][j];
        		else if (p[j] == '*') dp[i+1][j+1] = dp[i][j+1] | dp[i+1][j] | dp[i][j];
        	}
        }

        return dp[n][m];

    }
};



int main() {
	string s, p;
	cin >> s >> p;

	cout << Solution().isMatch(s, p) << endl;

	return 0;
}