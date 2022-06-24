#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();

        for (int i=0; i < n; i++) {
        	for (int j=0; j < m; j++) {
        		int temp = v[i][j];
        		if (i > 0) v[i][j] += v[i-1][j];
        		if (j > 0 && i > 0) {if (v[i][j-1] + temp < v[i][j] && v[i][j-1] + temp > 0) {v[i][j] = v[i][j-1] + temp; }} 
        		else if (j > 0) v[i][j] += v[i][j-1];
        	}
        }

        for (vector<int> x : v) {
        	for (int i : x) cout << i << " ";
        	cout << endl;
        }

        return v[n-1][m-1]+1;
    }
};


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> v[i][j];

	cout << Solution().calculateMinimumHP(v);

	return 0;
}