#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;


class Solution {
public:
	vector<VI> result;
	VI tin, low, vis;

	void dfs(map<int, VI> g, int key, int prev, int cur) {

		tin[key] = cur;
		low[key] = cur;
		vis[key] = true;

		for (int i : g[key]) {
			if (i == prev) continue;

			if (vis[i]) {
				low[key] = min(low[key], tin[i]);
			}
			else {
				dfs(g, i, key, cur+1);
				low[key] = min(low[key], low[i]);
				if (low[i] > tin[key]) {
					result.push_back({key, i});
					cout << key << " > " << i << endl;
				}
			}
		}
	}

    vector<VI> criticalConnections(int n, vector<VI>& connections) {
        
        map<int, VI> g;

        for (VI v : connections) {
        	g[v[0]].push_back(v[1]);
        	g[v[1]].push_back(v[0]);
        }

        tin = VI(n, INT_MAX);
        low = VI(n, INT_MAX);
        vis = VI(n, 0);

        for (auto& it : g) {
        	if (tin[it.first] == INT_MAX) {
        		dfs(g, it.first, -1, 0);
        	}
        }

        return result;
    }
};




int main() {
	int n;
	cin >> n;
	vector<VI> v;

	for (int i=0; i < n; i++) {
		VI x(2);
		cin >> x[0] >> x[1];

		v.push_back(vector<int>(x));
	}

	vector<VI> result = Solution().criticalConnections(n, v); 

	return 0;
}