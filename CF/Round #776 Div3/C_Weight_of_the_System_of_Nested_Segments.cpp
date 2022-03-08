#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> coordinates(m, 0), weights(m, 0);

        for (int i=0; i < m; i++) cin >> coordinates[i] >> weights[i];

        map<int, int> relation;

        for (int i=0; i < m; i++) relation[weights[i]] = coordinates[i];

        sort(weights.begin(), weights.end());

        vector<pair<int, int>> result;
        int count = 0;

        int i=0, j = 2*n-1;

        while (i < j) {
            int x = weights[i++];
            int y = weights[j--];

            result.push_back({relation[x], relation[y]});

            count += x + y;
        }

        cout << count << endl;
        
        for (pair<int, int> p : result) cout << p.first << " " << p.second << endl;

        cout << endl;
    }

    return 0;
}