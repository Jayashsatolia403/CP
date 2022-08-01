#include <bits/stdc++.h>
using namespace std;




int longestPath(map<int,vector<pair<int,int>>> g, int n) {

    vector<int> indegree(n, 0);

    for (int i=0; i < n; i++) {
        for (auto& it : g[i]) {
            indegree[it.first]++;
        }
    }

    queue<int> q;

    for (int i=0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        result.push_back(top);

        for (auto& it : g[top]) {
            indegree[it.first]--;

            if (indegree[it.first] == 0) {
                q.push(it.first);
            }
        }
    }

    
}




int main()
{
    // n is number of cities
    int n = 6;
 
    vector< pair<int,int> > graph[n+1];
 
    // create undirected graph
    // first edge
    graph[1].push_back(make_pair(2, 3));
    graph[2].push_back(make_pair(1, 3));
 
    // second edge
    graph[2].push_back(make_pair(3, 4));
    graph[3].push_back(make_pair(2, 4));
 
    // third edge
    graph[2].push_back(make_pair(6, 2));
    graph[6].push_back(make_pair(2, 2));
 
    // fourth edge
    graph[4].push_back(make_pair(6, 6));
    graph[6].push_back(make_pair(4, 6));
 
    // fifth edge
    graph[5].push_back(make_pair(6, 5));
    graph[6].push_back(make_pair(5, 5));
 
    
    map<int, vector<pair<int,int>>> g;

    for (int i = 1; i <= n; i++)
    {
        for (auto it : graph[i])
        {
            g[i].push_back(it);
        }
    }
 
    return 0;
}