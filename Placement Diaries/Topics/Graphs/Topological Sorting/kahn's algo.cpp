#include <bits/stdc++.h>
using namespace std;

#define VI vector<int>
#define mp make_pair


vector<int> result;

// Implementing Topo Sorting using Kahn's Algorithm

void topo_sort(map<int,vector<int>> g) {
    vector<int> indegree(6, 0);

    for (auto& it : g) {
        for (int i : it.second) {
            indegree[i]++;
        }
    }


    queue<int> q;
    
    for (int i=0; i < 6; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {

        int top = q.front();
        q.pop();

        result.push_back(top);

        for (int x: g[top]) {
            indegree[x]--;

            if (indegree[x] == 0) {
                q.push(x);
            }
        }
    }
}



int main() {
    map<int, vector<int>> g;

    g.insert(mp(5,VI{0,2}));
    g.insert(mp(4,VI{1,0}));
    g.insert(mp(2,VI{3}));
    g.insert(mp(3,VI{1}));
    g.insert(mp(0,VI{}));

    
    topo_sort(g);

    for (int i : result) cout << i << " ";
    
    return 0;
}