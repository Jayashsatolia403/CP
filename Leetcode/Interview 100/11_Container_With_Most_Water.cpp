#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), result = 0;

        int left = 0, right = n-1;

        while (left < right) {
        	result = max(min(height[left], height[right])*(right-left), result);

        	height[left] > height[right] ? right-- : left++;
        }

        return result;
    }
};




int main() {
	int n;
	cin >> n;
	vector<int> height(n, 0);
	for (int i=0; i < n; i++) cin >> height[i];

	cout << Solution().maxArea(height) << endl;

	return 0;
}