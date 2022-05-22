#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	vector<int> dp;

	bool dfs(vector<int> &nums, int target, int key) {
		int n = nums.size();

		if (target == 0) return true;
		if (target < 0) return false;

		if (dp[target] != -1) return dp[target];

		if (key >= n) return false;

		dp[target] = dfs(nums, target-nums[key], key+1) || dfs(nums, target, key+1);

		return dp[target];
	}

    bool canPartition(vector<int>& nums) {
        
        int target = 0;
        for (int i : nums) target+=i;
        if (target % 4 != 0) return false;
        target /= 4;

    	dp = vector<int>(target+1, -1);

    	return dfs(nums, target, 0);
    }
};





int main() {
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i=0; i < n; i++) cin >> nums[i];

	cout << Solution().canPartition(nums);

	return 0;
}