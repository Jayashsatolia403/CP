#include <bits/stdc++.h>
using namespace std;


vector<int> result;

#define VI vector<int>
#define mp make_pair


set<int> vis;


// Time Complexity : O(V+E)
void topo_sort(map<int,vector<int>> g, int key) {

    if (vis.count(key)) return;
    vis.insert(key);


    if (!g.count(key)) {
        result.push_back(key);
        return;
    }

    for (int i : g[key]) {
        topo_sort(g, i);
    }

    result.push_back(key);
}





int main() {
    map<int,vector<int>> g;

    vector<pair<int,int>> undirected_edges;

    for (auto& it : g) {
        int i = it.first;
        if (!vis.count(i)) {
            topo_sort(g, i);
        }
    }

    reverse(result.begin(), result.end());

    vector<int> transfer(result.size());
    int count = result.size();

    for (int i : result) {
        transfer[i] = count--;
    }

    for (pair<int,int> it : undirected_edges) {
        int a = transfer[it.first];
        int b = transfer[it.second];
        
        if (a < b) {
            g[a].push_back(b);
        }
        else {
            g[b].push_back(a);
        }
    }

    return 0;
}