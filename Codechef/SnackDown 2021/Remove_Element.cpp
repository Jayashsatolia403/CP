#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i=0; i < n; i++)
#define ll long long 




int main() {
    int t;
    cin >> t;

    while (t--) {
        int n,k;
        cin >> n >> k;

        vector<int> v(n, 0);

        forn (i, n) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        
        if (v[n-1]+v[0] > k) {
            cout << "NO" << endl;
            continue;
        }

        // for (int i=n-1, i > 0; i--) {
        //     if (v[i] + v[0] > k) {
        //         if (!done) done = true;
        //         else {
        //             cout << "NO" << endl;
        //             break;
        //         }
        //     }
        //     else break;
        // }

        cout << "YES" << endl;
    }

    return 0;
}