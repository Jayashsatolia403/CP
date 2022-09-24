#include <bits/stdc++.h>
using namespace std;


int dfs(map<int,vector<int>> g, int key, int cnt, int n, int mxn, vector<int> &vis, vector<int> &val, int mn) {
    
    // cout << cnt << " > " << n << " > " << mxn << endl;
    if (vis[key]) return cnt;

    vis[key] = true;

    if (n == 0) return cnt;

    int result = 0;

    for (int i : g[key]) {
        if (val[i]==mn) n--;
        result = max(result, dfs(g, i, cnt+(n!=mxn), n, mxn, vis, val, mn));
        if (val[i] == mn) n++;
    }

    return result;
}

int main() {
    int n = 7;
    // vector<int> from = {0,0,1}, to = {1,2,3}, val = {5,5,7,5};
    vector<int> from = {0,1,2,2,4,4}, to = {1,2,3,4,5,6}, val = {9,9,11,9,9,15,15};

    map<int, vector<int>> g;

    int mn = INT_MAX;
    for (int i : val) mn = min(mn, i);

    int cnt = 0;

    for (int i : val) if (i == mn) cnt++;

    for (int i=0; i < from.size(); i++) {
        g[from[i]].push_back(to[i]);
        g[to[i]].push_back(from[i]);
    }

    vector<int> vis(n+1);

    if (cnt <= 1) {
        cout << 0 << endl;
        return 0;
    }

    if (val[0] == mn) cnt--;

    cout << dfs(g, 0, 0, cnt, cnt, vis, val, mn);

    return 0;
}