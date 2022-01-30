#include <bits/stdc++.h>
using namespace std;


const int N = 100005;

bool visited[N];

vector<int> adj_list[N];



void dfs(int vertex) {
    visited[vertex] = true;

    for (int i: adj_list[vertex]) {
        if (visited[i]) continue;

        dfs(i);
    }
}