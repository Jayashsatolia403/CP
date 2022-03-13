#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
	vector<vector<int>> result;

	void dfs(vector<int> nums, int idx, vector<int> cur) {
		if (idx >= nums.size()) {
			result.push_back(cur);
			return;
		}


		result.push_back(cur);

		for (int i=idx; i < nums.size(); i++) {
			cur.push_back(nums[i]);
			dfs(nums, i+1, cur);
			cur.pop_back();
		}
	}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, 0, cur);
        return result;
    }
};



int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i=0; i < n; i++) cin >> v[i];

	vector<vector<int>> result = Solution().subsets(v);
	
	cout << result.size() << endl;


	for (int i=0; i < result.size(); i++) {
		for (int j=0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}

		cout << endl;
	}
	
	return 0;
}