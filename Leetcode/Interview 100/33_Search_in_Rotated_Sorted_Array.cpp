#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int n = nums.size();
        int left = 0, right = n-1, k=0;

        while (left <= right) {        	
        	int mid = left + (right-left)/2;

        	if (mid > 0 && nums[mid] < nums[mid-1]) {k = mid; break;}
        	else if (nums[left] <= nums[mid] && nums[right] < nums[mid]) left = mid+1;
        	else right = mid-1;
        }

        int a = k-1, b = k;

    	left = 0;
    	right = a;

    	while (left <= right) {
    		int mid = left + (right - left)/2;
    		if (nums[mid] == target) return mid;
    		else if (nums[mid] > target) right = mid-1;
    		else left = mid+1;
    	}

    	left = b;
    	right = n-1;

    	while (left <= right) {
    		int mid = left + (right - left)/2;
    		if (nums[mid] == target) return mid;
    		else if (nums[mid] > target) right = mid-1;
    		else left = mid+1;
    	}

        return -1;
    }
};



int main() {
	int n, target;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i=0; i < n; i++) cin >> nums[i];
	cin >> target;

	cout << Solution().search(nums, target);
	return 0;
}