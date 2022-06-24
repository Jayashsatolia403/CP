#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

	int expandAroundCenter(string s, int l, int r) {
		
		while (l >= 0 && r < s.size() && s[l] == s[r]) {
			l--;
			r++;
		}

		return r-1-l;
	}

	string longestPalindrome(string s) {

		int n = s.size(), start=0, end=0;

		if (n == 0) return "";

		for (int i=0; i < n; i++) {
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i+1);

			int len = max(len1, len2);

			if (len > end-start) {
				start = i - (len-1)/2;
				end = i + (len)/2;
			}
		}

		return s.substr(start, end-start+1);
	}
};




// O(n^2) Time & O(n^2) Space
// class Solution {
// public:
// 	vector<vector<int>> dp;

// 	bool is_palindrome(string s, int i, int j) {
// 		int n = s.size();

// 		if (i >= j) return 1;

// 		if (s[i] != s[j]) return 0;

// 		if (dp[i][j] != -1) return dp[i][j];

// 		dp[i][j] = is_palindrome(s, i+1, j-1);

// 		return dp[i][j]; 
// 	}

//     string longestPalindrome(string s) {
        
//         int n = s.size(), result = 0, good_i=0, good_j=0;

//         dp = vector<vector<int>>(n, vector<int>(n, -1));

//         for (int i=0; i < n; i++) {
//         	for (int j=i+1; j < n; j++) {
//         		if (is_palindrome(s, i, j)) {
//         			if (j+1-i > result) {
//         				result = j+1-i;
//         				good_i=i;
//         				good_j=j;
//         			}
//         		}
//         	}
//         }

//         return s.substr(good_i, good_j+1-good_i);
//     }
// };



int main() {
	string s;
	cin >> s;

	cout << Solution().longestPalindrome(s);

	return 0;
}