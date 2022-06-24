#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	bool are_not_common(vector<int>& a, vector<int>& b) {

		for (int i=0; i < 26; i++) {
			if (a[i] > 0 && b[i] > 0) return false;
		}

		return true;

	}
    int maxProduct(vector<string>& v) {
    	int n = v.size();
        vector<vector<int>> check(n, vector<int>(26, 0));

        int count = 0;
        for (string s : v) {
        	for (char c : s) {
        		check[count][c-'a'] = 1;
        	}
        	count++;
        }

        int result = 0;

        for (int i=0; i < n; i++) {
        	for (int j=i+1; j < n; j++) {
        		if (are_not_common(check[i], check[j])) {
        			int a = v[i].size(), b = v[j].size();
        			result = max(result, a*b);
        		}
        	}
        }

        return result;
    }
};



int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i=0; i < n; i++) cin >> v[i];

	cout << Solution().maxProduct(v);

	return 0;
}