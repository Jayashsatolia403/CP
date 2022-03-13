#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
	bool dfs(vector<vector<char>> v, string s, int idx, int i, int j) {
		int n = s.length();


		if (idx < 0 || idx >= n || i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || s[idx] != v[i][j]) return false;

		if (idx == n-1) return true;

		int temp = v[i][j];
		v[i][j] = '*';

		bool a = dfs(v, s, idx+1, i+1, j);
		bool b = dfs(v, s, idx+1, i, j+1);
		bool c = dfs(v, s, idx+1, i-1, j);
		bool d = dfs(v, s, idx+1, i, j-1);

		v[i][j] = temp;

		return a || b || c || d;
	}

    bool exist(vector<vector<char>>& v, string s) {
        
        int n = v.size(), m = v[0].size();

        for (int i=0; i < n; i++) {
        	for (int j=0; j < m; j++) {
        		if (dfs(v, s, 0, i, j)) return true;
        	}
        }

        return false;
    }
};



int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m, '0'));
	for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> v[i][j];

	string s;
	cin >> s;

	cout << Solution().exist(v, s) << endl;
	
	return 0;
}