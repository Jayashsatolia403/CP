#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i=0; i < n; i++)
#define ll long long 




int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll p, m, v;
        cin >> p >> m >> v;

        ll res = (m-p+1)*v;

        cout << res << endl;
    }

    return 0;
}