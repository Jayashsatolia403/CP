#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int q;
    cin >> q;

    vector<int> hm(n);

    while (q--) {
        int x,y;
        cin >> x >> y;

        hm[x-1]++;
        if (y < n) {
            hm[y]--;
        }
    }

    int z = 0;
    for(int i = 0; i < n; i++){
        z += hm[i];
        hm[i] = z;
    }

    map<int,vector<int>> m;

    for (int i=0; i < n; i++) {
        m[hm[i]].push_back(i);
    }

    sort(v.begin(), v.end());

    vector<int> result(n);

    int idx = 0;

    for (auto &i : m) {
        for (int j : i.second) {
            result[j] = v[idx++];
        }
    }

    for (int i : result) cout << i << " ";

    return 0;
}