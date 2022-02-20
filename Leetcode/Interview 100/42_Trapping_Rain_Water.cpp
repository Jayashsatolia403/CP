#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size(), prev = 0, result = 0;

        vector<int> left(n, 0), right(n, 0);

        for (int i=0; i < n; i++) {
        	left[i] = max(prev, v[i]);
        	prev = left[i];
        }

        prev = 0;

        for (int i=n-1; i >= 0; i--) {
        	right[i] = max(prev, v[i]);
        	prev = right[i];
        }

        // for (int i=0; i < n; i++) cout << left[i] << " > " << right[i] << endl;

        for (int i=0; i < n; i++) {
        	int x = min(left[i], right[i]) - v[i];

        	if (x > 0) result += x;
        }


        return result;
    }
};



int main() {
	int n;
	cin >> n;
	vector<int> heights(n, 0);

	for (int i=0; i < n; i++) cin >> heights[i];

	cout << Solution().trap(heights) << endl;

	return 0;
}