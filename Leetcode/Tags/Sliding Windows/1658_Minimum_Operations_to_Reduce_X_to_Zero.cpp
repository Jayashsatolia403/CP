#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();

        int total = 0, target = 0;
        for (int i : nums) total += i;
        target = total - x;

    	if (target < 0) return -1;
    	if (target == 0) return n;

    	int cur = 0, left = 0, result = INT_MAX;

    	for (int i=0; i < n; i++) {
    		cur += nums[i];

    		while (cur > target) {
    			cur -= nums[left++];
    		}

    		if (cur == target) result = min(result, n - (i-left+1));
    	}

    	return result == INT_MAX ? -1 : result;
    }
};



int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n, 0);

	for (int i=0; i < n; i++) cin >> v[i];

	cout << Solution().minOperations(v, k);

	return 0;
}


