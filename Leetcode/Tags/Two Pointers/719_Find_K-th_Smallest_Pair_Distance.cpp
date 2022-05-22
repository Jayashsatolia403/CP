#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
    	int n = nums.size();

        sort(nums.begin(), nums.end());

        int low=0, high=nums[n-1]-nums[0]; 


        while (low < high) {
        	int mid = (high + low)/2;

        	int left = 0, count = 0;

        	for (int right=1; right < n; right++) {
        		while (nums[right] - nums[left] > mid) left++;
        		count += right - left;
        	}

        	if (count >= k) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};




int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i=0; i < n; i++) cin >> nums[i];

	cout << Solution().smallestDistancePair(nums, k);

	return 0;
}