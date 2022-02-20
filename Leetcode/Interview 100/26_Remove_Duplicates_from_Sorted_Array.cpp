#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, n = nums.size();

        for (int i=1; i < n; i++) {
        	if (nums[i] != nums[i-1]) {
        		nums[idx++] = nums[i];
        	}
        }

        return idx;
    }
};





int main() {
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i=0; i < n; i++) cin >> nums[i];

	int x = Solution().removeDuplicates(nums);

	for (int i=0; i < x; i++) cout << nums[i] << " ";

	return 0;
}