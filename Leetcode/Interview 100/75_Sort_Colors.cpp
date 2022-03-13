#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> m = {{0, 0}, {1, 0}, {2, 0}};

        for (int i : nums) m[i]++;

        for (int i=0; i < m[0]; i++) {
        	nums[i] = 0;
        }

        for (int i=0; i < m[1]; i++) nums[m[0]+i] = 1;
    	for (int i=0; i < m[2]; i++) nums[m[0]+m[1]+i] = 2;
    }
};





int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i=0; i < n; i++) cin >> v[i];

	Solution().sortColors(v);

	for (int i : v) cout << i << " ";
	
	return 0;
}