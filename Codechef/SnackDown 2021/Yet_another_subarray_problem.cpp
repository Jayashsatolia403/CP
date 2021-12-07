#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i=0; i < n; i++)
#define ll long long 



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        forn (i, n) {
            cout << (i+1)*2 << " ";
        }

        cout << endl;
    }

    return 0;
}