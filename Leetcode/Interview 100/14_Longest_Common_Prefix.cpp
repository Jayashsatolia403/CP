#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        int n = INT_MAX;

        for (int i=0; i < v.size(); i++) { int len = v[i].size(); n = min(len, n); }

        string lcp = "";

    	bool done = false;

        for (int i=0; i < n; i++) {
        	if (done) break;

        	char common = v[0][i];

        	for (int j=0; j < v.size(); j++) {
        		string s = v[j];
        		if (s[i] != common) { done = true; break; }
        	}

        	if (!done) lcp += common;
        }

        return lcp;
    }
};



int main() {
	int n;
	cin >> n;
	vector<string> v(n, "");
	for (int i=0; i < n; i++) cin >> v[i];

	cout << Solution().longestCommonPrefix(v) << endl;

	return 0;
}