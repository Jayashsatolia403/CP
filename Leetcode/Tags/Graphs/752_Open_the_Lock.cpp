#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    map<string, int> vis;

    int dfs(set<string> deadends, string target, string cur, int res) {
    	cout << cur << " > " << res << endl;
    	if (cur == target) return res;
    	if (vis.count(cur)) vis[cur];

    	int result = INT_MAX;

    	for (int i=0; i < 4; i++) {
    		if (cur[i] == 9) continue;
    		cur[i] += 1;
    		result = min(result, dfs(deadends, target, cur, res+1));
    		cur[i] -= 1;
    	}

    	// for (int i=0; i < 4; i++) {
    	// 	cur[i] -= 1;
    	// 	result = min(result, dfs(deadends, target, cur, res+1));
    	// 	cur[i] += 1;
    	// }

    	vis[cur] = result;

    	return result;
    }

    int openLock(vector<string>& deadends, string target) {
        set<string> s;

        for (string i : deadends) {
        	s.insert(i);
        }

        return dfs(s, target, "0000", 0);
    }
};



int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i=0; i < n; i++) cin >> v[i];
	string target;
	cin >> target;

	cout << Solution().openLock(v, target);

	return 0;
}


