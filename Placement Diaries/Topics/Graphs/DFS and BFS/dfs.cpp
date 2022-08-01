#include <bits/stdc++.h>
using namespace std;


void dfs(map<int,vector<int>> g, int key, set<int> vis) {

    if (!g.count(key) && vis.count(key)) return;

    cout << key << " ";

    vis.insert(key);

    for (int i : g[key]) {
        dfs(g, i, vis);
    }
}


int main() {

    map<int, vector<int>> g;

    set<int> vis;

    dfs(g, 1, vis);

    return 0;
}