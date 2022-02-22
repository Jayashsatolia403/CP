#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = -pow(10, 5), cur = -pow(10, 5), n = nums.size();

        for (int i=0; i < n; i++) {
        	cur = max(cur+nums[i], nums[i]);
        	result = max(result, cur);
        }

        return result;
    }
};




int main() {
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i=0; i < n; i++) cin >> nums[i];


	cout << Solution().maxSubArray(nums) << endl;

	return 0;
}