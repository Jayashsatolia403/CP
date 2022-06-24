#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;



class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();

        vector<VI> dp(n+1, VI(m+1, -1));

        for (int i=1; i <= n; i++) {
        	for (int j = 1; j <= m; j++) {
        		if (a[i-1] == b[j-1]) {
        			dp[i][j] = 1 + dp[i-1][j-1];
        		}
        		else {
        			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        		}
        	}
        }

        return dp[n][m]+1;

    }
};



int main() {
	string a, b;
	cin >> a >> b;

	cout << Solution().longestCommonSubsequence(a, b);

	return 0;
}