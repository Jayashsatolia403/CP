#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = total/2;

        if (nums1.size() < nums2.size()) {
        	vector<int> temp = nums1;
        	nums1 = nums2;
        	nums2 = temp;
        }

        int left=0, right = nums1.size()-1, i=0, j=0;

        while (true) {
        	i = (left+right)/2; // A
        	j = half-i-2; // B

        	int a_left = (i >= 0 ? nums1[i] : INT_MIN);
        	int a_right = (i+1 < nums1.size() ? nums1[i+1] : INT_MAX);
        	int b_left = (j >= 0 ? nums2[j] : INT_MIN);
        	int b_right = (j+1 < nums2.size() ? nums2[j+1] : INT_MAX);

        	if (a_left <= b_right && b_left <= a_right) {
        		if (total % 2) return min(a_right, b_right);
        		double result = 0;
        		result = ((double)max(a_left, b_left) + (double)min(a_right, b_right))/2;
        		return result;
        	}
        	else if (a_left > b_right) right = i-1;
        	else left = i+1;
        }

        return -1;
    }
};



int main() {
	int n, m;
	cin >> n >> m;

	vector<int> nums1(n,0), nums2(m,0);

	for (int i=0; i < n; i++) cin >> nums1[i];
	for (int i=0; i < m; i++) cin >> nums2[i];


	cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}