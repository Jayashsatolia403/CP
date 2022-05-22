#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<vector<int>> dp;

	bool dfs(vector<int>& nums, int target, int phase, vector<int> progress, int fix_target, int key) {

		// for (int i : progress) cout << i << " ";
		// cout  << "     >>>>>     " << target << " > " << phase << " > " << key << endl;

		if (target == 0 && phase == 0) return true;

		if (target == 0) {
			return dfs(nums, fix_target, phase-1, progress, fix_target, 0);
		}

		if (target < 0 || phase < 0) return false;

		if (dp[target][phase] != -1) return dp[target][phase];

		bool cond1 = false, cond2 = false;

		if (key >= nums.size()) return false;

		if (!progress[key]) {
			progress[key] = true;
			cond1 = dfs(nums, target-nums[key], phase, progress, fix_target, key+1);
			progress[key] = false;
		}
		cond2 = dfs(nums, target, phase, progress, fix_target, key+1);

		dp[target][phase] = cond1 || cond2;

		return dp[target][phase];
	}

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;

        for (int i : nums) target += i;
        if (target % k != 0) return false;
    	target /= k;

    	int n = nums.size();
    	vector<int> progress(n, 0);

    	dp = vector<vector<int>>(target+1, vector<int>(k, -1));

    	return dfs(nums, target, k-1, progress, target, 0);
    }
};


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i=0; i < n; i++) cin >> nums[i];

	cout << Solution().canPartitionKSubsets(nums, k);

	return 0;
}