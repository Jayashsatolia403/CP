#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        forn (i,n) {
            cin >> a[i];
        }

        forn (i,n) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool done = false;

        forn (i,n) {
            if (b[i] - a[i] < 0 || b[i] - a[i] > 1) {
                cout << "NO" << endl;
                done = true;
                break;
            }
        }

        if (done) continue;

        cout << "YES" << endl;
    }

    return 0;
}