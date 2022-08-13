#include <bits/stdc++.h>
using namespace std;


int parent[100000];
int rank_arr[100000];


int find_parent(int x) {
    if (parent[x] == x) return x;

    return parent[x] = find_parent(parent[x]);
} 


void unite(int u, int v) {

    u = find_parent(u);
    v = find_parent(v);
    
    int ru = rank_arr[u];
    int rv = rank_arr[v];

    if (ru < rv) {
        parent[u] = v;
    }
    else if (ru > rv) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank_arr[u]++;
    }

}


int main() {
    int n;
    cin >> n;

    for (int i=0; i < n; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
    }

    int m;
    cin >> m;
    
    for (int i=0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        unite(a, b);
    }

    for (int i=1; i < n; i++) {
        cout << find_parent(i) << " ";
    }
    cout << endl;
    
    for (int i=1; i < n; i++) cout << rank_arr[i] << " ";

    return 0;
}