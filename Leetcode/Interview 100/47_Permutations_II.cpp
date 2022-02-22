#include <bits/stdc++.h>
using namespace std;







class Solution {
public:
	vector<vector<int>> result;

	void dfs(map<int,int> count, vector<int>& cur, int n) {

		if (cur.size() == n) {
			vector<int>x(cur);
			result.push_back(x);
			return;
		}


		for (auto& it: count) {
			if (it.second > 0) {
				int f = it.first;

				count[f]--;
				cur.push_back(f);

				dfs(count, cur, n);

				count[f]++;
				cur.pop_back();
			}
		}
	}

    vector<vector<int>> permuteUnique(vector<int>& v) {
        vector<int> cur;
        map<int, int> count; 

        for (int i : v) count[i]++;

        dfs(count, cur, v.size());

        return result;
    }
};



int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i=0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	vector<vector<int>> result;

	result = Solution().permuteUnique(v);

	for (int i=0; i < result.size(); i++) {
		for (int j=0; j < n; j++) cout << result[i][j] << " ";
		cout << endl;
	}

	return 0;
}