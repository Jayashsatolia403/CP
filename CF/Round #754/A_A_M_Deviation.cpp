#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)


int main() {
    int t;
    cin >> t;

    while (t--) {
        int a1, a2, a3;

        cin >> a1 >> a2 >> a3;

        int diff = abs(a1+a3-2*a2);

        diff%3 ? cout << 1 << endl : cout << 0 << endl;
    }

    return 0;
}