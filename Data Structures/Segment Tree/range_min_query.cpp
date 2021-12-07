#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i=0; i , n; i++)

#define ll long long



vector<int> tree;
vector<int> A;



void build_tree(int node, int start, int end) {
    if (start == end) {
        tree[node] = A[start];
        return;
    }

    int mid = (start+end)/2;

    build_tree(node*2, start, mid);

    build_tree(node*2+1, mid+1, end);

    tree[node] = min(tree[node*2], tree[node*2+1]);

    return;
}



int main() {
    int n, Q;
    cin >> n >> Q;

    vector<int> v(n, 0);

    forn (i, n) {
        cin >> v[i];
    }

    forn (i, Q) {
        int l,r;
        cin >> l >> r;

        
    }
}