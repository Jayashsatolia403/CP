#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (long i = 0; i < n; i++)

#define ll long long




int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll u, v;
        cin >> u >> v;

        ll x,y;

        x = -(u*u);
        y = (v*v);

        cout << x << " " << y << endl;
    }

    return 0;
}