#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    bool canJump(vector<int>& v) {
        int n = v.size();

        if (n <= 1) return true;

        for (int i=1; i < n; i++) {
        	if (v[i-1] == 0) return false;
        	v[i] = max(v[i-1]-1, v[i]);
        }

        return v[n-2];
    }
};



int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i=0; i < n; i++) cin >> v[i];

	cout << Solution().canJump(v) << endl;

	return 0;
}