#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();

        vector<vector<int>> result;

        sort(v.begin(),v.end());

        for (int i=0; i < n-2; i++) {
        	if (i > 0 && v[i] == v[i-1]) continue;

        	int target = 0 - v[i];

        	set<int> m;

        	for (int j = i+1; j < n; j++) {
    			if (j > i+1 && v[j] == v[j-1]) continue;
        		
        		if (m.find(v[j]) != m.end()) {
        			vector<int> temp = {v[i], v[j], target-v[j]};
        			result.push_back(temp);
        		}
        		else m.insert(target - v[j]);
        	}
        }

        return result;
    }
};




int main() {
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i=0; i < n; i++) cin >> nums[i];

	vector<vector<int>> result = Solution().threeSum(nums);

	for (vector<int> v : result) cout << v[0] << " " << v[1] << " " << v[2] << endl;

	return 0;
}