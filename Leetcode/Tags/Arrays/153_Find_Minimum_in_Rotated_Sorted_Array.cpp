#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& v) {

    	int l=0, r=v.size()-1;

    	while (l < r) {
    		int m = l + (r-l)/2;

    		if (v[m] < v[m-1]) return v[m];
    		
    		if (v[m] > v[r]) {
    			l = m+1;
    		}
    		else {
    			r = m-1;
    		}
    	}

    	return v[l];
    }
};


int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; i++) cin >> v[i];

	cout << Solution().findMin(v);

	return 0;
}