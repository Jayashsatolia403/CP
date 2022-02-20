#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	void dfs(vector<int> nums, vector<vector<int>>& result, int idx, vector<int> cur, vector<bool>& visited) {
		int n = nums.size();

		if (idx == n) {
			result.push_back(cur);
			return;
		}

		if (idx > n) return;

		for (int i=0; i < n; i++) {
			if (visited[i]) continue;

			visited[i] = true;
			cur.push_back(nums[i]);

			dfs(nums, result, idx+1, cur, visited);

			visited[i] = false;
			cur.pop_back();
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> visited(nums.size(), false); 

        dfs(nums, result, 0, cur, visited);

        return result;
    }
};




int main() {
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i=0; i < n; i++) cin >> nums[i];


	vector<vector<int>> result = Solution().permute(nums);

	for (vector<int> v : result) {
		for (int i : v) cout << i << " ";
		cout << endl;
	}

	return 0;
}