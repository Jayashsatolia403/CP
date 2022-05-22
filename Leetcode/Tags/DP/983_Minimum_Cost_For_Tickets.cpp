#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	vector<int> dp;
    
	int dfs(int i, vector<int>&days, vector<int>&costs) {
		if (i >= days.size()) return 0;
        
        if (dp[i]) return dp[i];
        
        
		int j1 = i, j2 = i, j3 = i;

		while (days[j1] < days[i]+1) j1++;
		while (days[j2] < days[i]+7) j2++;
		while (days[j3] < days[i]+30) j3++;

		int a = costs[0] + dfs(j1, days, costs);
		int b = costs[1] + dfs(j2, days, costs);
		int c = costs[2] + dfs(j3, days, costs);
        
        dp[i] = min(a, min(b, c));

		return dp[i];
	}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
    	dp = vector<int>(365, 0);

        return dfs(0, days, costs);
    }
};




int main() {
	int n;
	cin >> n;
	vector<int> days(n, 0), costs(3, 0);
	for (int i=0; i < n; i++) cin >> days[i];
	cin >> costs[0] >> costs[1] >> costs[2];

	cout << Solution().mincostTickets(days, costs);

	return 0;
}