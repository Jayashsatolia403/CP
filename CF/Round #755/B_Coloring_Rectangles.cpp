#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n,m;
        cin >> n >> m;

        int multiple = n*m;

        if (multiple == 2) {
            cout << 1 << endl;
            continue;
        }

        if (multiple%3 == 0) {
            cout << multiple/3 << endl;
        }
        else if (multiple%2 == 2) {
            cout << multiple/3+1 << endl;
        }
        else {
            cout << (multiple-3)/3+2 << endl;
        }
    }

    return 0;
}