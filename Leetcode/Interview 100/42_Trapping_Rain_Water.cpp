#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size(), result = 0, progress=0, backup=0;

        int start=0;

        for (int end=1; end < n; end++) {
        	if (v[end] > v[end-1] && v[end-1] != 0) if (end-1 != start || v[end-1] != 0) backup += v[end]-v[end-1];

        	if (v[start] == 0) start++;
        	else if (v[start] <= v[end]) { result += progress; start = end; backup = 0; progress = 0; }
        	else progress += v[start]-v[end];
        }

        return result + backup;
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