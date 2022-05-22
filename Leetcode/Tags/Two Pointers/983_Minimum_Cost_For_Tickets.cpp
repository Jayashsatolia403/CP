#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size(); 
        
        vector<int> dp(days[n-1]+1, INT_MAX-100);

        dp[0] = 0;

        for (int i=1; i <= n; i++) {
            for (int j=0; j < 30; j++) {
            	if (i+j >= n) break;

                if (j == 0) dp[i+j] = min(dp[i+j], costs[0]);
                else if (j < 7) dp[i+j] = min(dp[i+j], costs[1]);
                else dp[i+j] = min(dp[i+j], costs[2]);
            }
        }
        
        int result = 0;
        
        for (int i : days) {
            result += dp[i];
        }

        for (int i : dp) cout << i << " > ";
        cout << endl;
        
        return result;
    }
};



int main() {
	int n;
	cin >> n;
	vector<int> days(n, 0), costs(3, 0);
	for (int i=0; i <n; i++) cin >> days[i];
	for (int i=0; i < 3; i++) cin >> costs[i];

	cout << Solution().mincostTickets(days, costs);

	return 0;
}