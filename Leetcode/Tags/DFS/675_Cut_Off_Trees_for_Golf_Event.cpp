#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	vector<vector<int>> dp, vis;

	int dfs(vector<vector<int>> &v, int i, int j, int prev, int move, int target) {
		int n = v.size(), m = v[0].size();

		if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == 0) return INT_MAX;

		if (v[i][j] > 1) target--;

		if (target == 0) {
			return move;
		}

		int result = INT_MAX;

		vector<pair<int,int>> pos = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

		for (pair<int,int> p : pos) {
			result = min(result, dfs(v, i+p.first, j+p.second, v[i][j], move+1, target));
		}


		return result;
	}

    int cutOffTree(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();

        int result = INT_MAX;
        int target = 0;

        for (int i=0; i < n; i++) {
        	for (int j=0; j < m; j++) if (v[i][j] > 1) target++;
        }

		result = min(result, dfs(v, 0, 0, -1, 0, target));

        return result == INT_MAX ? -1 : result;
    }
};



int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> v[i][j];

	cout << Solution().cutOffTree(v);

	return 0;
}