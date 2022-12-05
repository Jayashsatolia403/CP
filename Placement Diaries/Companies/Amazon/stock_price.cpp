#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += i;
        cur = a[i];
    }

    int idx = 0;

    for (int i=0; i<n-1; i++) {
        int l = a[i];
        int r = a[n-1]-a[i+1];
        int diff = abs(l-r);

        if (diff < cur) {
            cur = diff;
            idx = i;
        }
    }

    cout << idx << endl;

    return 0;
}