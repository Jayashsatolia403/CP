#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
	vector<int> dp;
	int result = 0;

	int dfs(vector<string>& strs, int m, int n, int key, int op) {
		// cout << key << " " << op << " > " << m << " " << n << endl;
		int x = strs.size();

		if (m < 0 || n < 0) return op-1;

		if (key >= x) {
			return op;
		}

		if (dp[key]) return dp[key];

		int a=0, b=0;

		for (char c : strs[key]) {
			if (c == '0') a++;
			else b++;
		}

		int l = dfs(strs, m-a, n-b, key+1, op+1);
		int o = dfs(strs, m, n, key+1, op);

		if (key == 2) cout << l << " > " << o << endl;
		
		dp[key] = max(l, o);

		return dp[key];
	}

    int findMaxForm(vector<string>& strs, int m, int n) {
        int x = strs.size();

        dp = vector<int>(x, 0);

        return dfs(strs, m, n, 0, 0);
    }
};



int main() {
	int x, m, n;
	cin >> x >> m >> n;
	vector<string> strs(x, "");
	for (int i=0; i < x; i++) cin >> strs[i];

	cout << Solution().findMaxForm(strs, m, n);

	return 0;
}