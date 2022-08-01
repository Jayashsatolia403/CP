#include <bits/stdc++.h>
using namespace std;



int main() {
    map<int, vector<int>> g;

    g.insert({1, {2, 3}});
    g.insert({2, {1, 3}});

    queue<int> q;

    set<int> vis;
    
    q.push(1);

    while (!q.empty()) {
        int key = q.front();
        q.pop();

        if (vis.count(key)) continue;
        vis.insert(key);

        cout << key << " ";

        for (int i : g[key]) {
            q.push(i);
        }
    }

    return 0;
}