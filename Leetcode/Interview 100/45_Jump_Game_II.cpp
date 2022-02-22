#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, 0);

        int i = 1, j=0;

        while (i < n) {
			while (j < i) {
				if (v[j] >= i-j) { dp[i] = dp[j]+1; break; }
				j++;
			}

			i++;
        }

        return dp[n-1];
    }
};



int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i=0; i < n; i++) cin >> v[i];

	cout << Solution().jump(v) << endl;

	return 0;
}