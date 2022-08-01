#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

int dijkstra(map<int, vector<pair<int,int>>> g, int src, int dest) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,src});

    set<int> vis;

    vector<int> dist(100, INF);
    dist[src] = 0; 

    while (!pq.empty()) {
        pair<int,int> curr = pq.top();
        pq.pop();

        int u = curr.second;

        if (vis.count(curr.second)) continue;
        else vis.insert(curr.second);


        if (curr.second == dest) {
            return curr.first;
        }

        for (auto& it : g[curr.second]) {

            int v = it.first;
            int weight = it.second;

            if (dist[v] > dist[u] + it.second) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return -1;
}


int main() {
    map<int, vector<pair<int,int>>> g;

    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (graph[i][j] != 0) {
                g[i].push_back({j, graph[i][j]});
            }
        }
    }

    for (int i=0; i < 9; i++) {
        cout << dijkstra(g, 0, i) << endl;
    }

    return 0;
}