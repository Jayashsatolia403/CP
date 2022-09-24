#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>

void dfs(vector<vector<int>> &g, int node, int parent, vi &vis, vi &tin, vi &low, int &timer) {
    vis[node] = true;

    tin[node] = low[node] = timer++;

    for (int i : g[node]) {
        if (i == parent) continue;

        if (!vis[i]) {
            dfs(g, i, node, vis, tin, low, timer);
            low[node] = min(low[node], low[i]);
            if (low[i] > tin[node]) {
                cout << node << " > " << i << endl;
            }
        }
        else {
            low[node] = min(low[node], tin[i]);
        }
    }
}


int solve(vector<vector<int>>& graph) {
    int n = graph.size()+1;

    vector<vector<int>> g(252);

    for (vector<int> v : graph) {
        g[v[0]].push_back(v[1]);
        g[v[1]].push_back(v[0]);
    }

    int count = 0;

    vi vis(n), tin(n), low(n);

    int timer = 0;

    dfs(g, graph[0][0], -1, vis, tin, low, timer);

    return 0;
}



int main() {

}