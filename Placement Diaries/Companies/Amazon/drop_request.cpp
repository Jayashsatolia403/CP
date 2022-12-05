#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> dropped;

    for (int i=0; i < n; i++) {
        if (i+3 < n && a[i] == a[i]) {
            dropped.insert(i+3);
        }
        if (i+20 < n && a[i+20]-a[i] < 10) {
            dropped.insert(i+20);
        }
        if (i+60 < n && a[i+60]-a[i] < 60) {
            dropped.insert(i+60);
        }
    }

    cout << dropped.size() << endl;

    return 0;
}