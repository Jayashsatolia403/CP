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
    map<int, vector<int>> g;

    g.insert(mp(5,VI{0,2}));
    g.insert(mp(4,VI{1,0}));
    g.insert(mp(2,VI{3}));
    g.insert(mp(3,VI{1}));
    g.insert(mp(0,VI{}));

    
    for (auto& it : g) {
        if (!vis.count(it.first)) {
            topo_sort(g, it.first);
        }
    }

    reverse(result.begin(), result.end());

    for (int i : result) cout << i << " ";
    
    return 0;
}