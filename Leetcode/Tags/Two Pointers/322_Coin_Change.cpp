#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount+1, INT_MAX-100);
        dp[0] = 0;

        for (int i=0; i < amount+1; i++) {
        	for (int coin : coins) {
        		if (coin <= i) dp[i] = min(dp[i], dp[i-coin]+1);
        	}
        }

        return dp[amount] == INT_MAX-100 ? -1 : dp[amount];
    }
};



int main() {
	int n, amount;
	cin >> n >> amount;
	vector<int> coins(n, 0);
	for (int i=0; i < n; i++) cin >> coins[i];

	cout << Solution().coinChange(coins, amount); 
	
	return 0;
}