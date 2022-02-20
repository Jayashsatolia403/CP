#include <bits/stdc++.h>
using namespace std;



class SolutionIterative {
public:
	int longestCommonSubsequence(string s1, string s2) {
		int n = s1.length(), m = s2.length();

		int dp[n+1][m+1], result=0;

		for (int i=0; i <= n; i++) for (int j=0; j <= m; j++) dp[i][j] = 0;

		for (int i=1; i <= n; i++) {
			for (int j=1; j <= m; j++) {
				if (s1[i-1] == s2[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}

		return dp[n][m];
	}
};



class SolutionRecursive {
public:
	map<pair<int, int>, int> dp;
	string text1, text2;

	int lcs(int l1, int l2) {
		if (l1==0 || l2==0) return 0;

		pair<int,int> len(l1,l2);

		if (dp.count(len)) return dp[len];

		if (text1[l1-1] == text2[l2-1]) {
			dp[len] = 1 + lcs(l1-1, l2-1);
			return dp[len];
		}

		dp[len] = max(lcs(l1, l2-1), lcs(l1-1, l2));

		return dp[len];
	}

    int longestCommonSubsequence(string s1, string s2) {
    	text1 = s1;
    	text2 = s2;

    	return lcs(s1.length(), s2.length());
    }
};


int main() {
	string s1, s2;
	cin >> s1 >> s2;

	// cout << SolutionRecursive().longestCommonSubsequence(s1, s2) << endl;
	cout << SolutionIterative().longestCommonSubsequence(s1, s2) << endl;

	return 0;
}