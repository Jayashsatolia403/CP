#include <bits/stdc++.h>
using namespace std;


const int N = 100005;

bool visited[N];

vector<int> adj_list[N];



void bfs(int vertex) {
    queue<int> q;

    q.push(vertex);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        visited[cur] = true;

        for (int i: adj_list[cur]) {
            if (visited[cur]) continue;

            q.push(i);
        }
    }
}

