#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max=1, cur_min=1, result = INT_MIN;

        for (int x : nums) {
        	if (x == 0) {
        		cur_max = 1;
        		cur_min = 1;
        		result = max(result, 0);
        		continue;
        	}

        	int temp = cur_max;

        	cur_max = max(max(x*cur_max, x*cur_min), x);
        	cur_min = min(min(x*temp, x*cur_min), x);

        	result = max(cur_max, result);
        }

        return result;
    }
};




int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i=0; i < n; i++) cin >> v[i];

	cout << Solution().maxProduct(v);
	
	return 0;
}