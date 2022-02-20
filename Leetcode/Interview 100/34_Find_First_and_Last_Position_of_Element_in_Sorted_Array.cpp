#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> searchRange(vector<int>& v, int t) {
        int start=INT_MAX, end = INT_MIN, n = v.size();

        int left = 0, right = n-1;

        while (left <= right) {
        	int mid = left + (right-left)/2;

        	if (v[mid] == t) start = min(mid, start);

        	if (v[mid] >= t) right = mid-1;
        	else left = mid+1;
        }

        left = 0, right = n-1;

        while (left <= right) {
        	int mid = left + (right-left)/2;

        	if (v[mid] == t) end = max(mid, end);

        	if (v[mid] > t) right = mid-1;
        	else left = mid+1;
        }

        return {start==INT_MAX?-1:start, end==INT_MIN?-1:end};
    }
};



int main() {
	int n, target;
	cin >> n;

	vector<int> v(n, 0);
	for (int i=0; i < n; i++) cin >> v[i];

	cin >> target;

	for (int i : Solution().searchRange(v, target)) cout << i << " ";

	return 0;
}