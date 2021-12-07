#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i=0; i < n; i++)

#define ll long long 


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n;
        k = n;

        int digit = 0;
        bool good = false;

        while (k>0) {
            
            if (k%2 == 0) good = true;

            k = k/10;

            digit++;
        }


        if (n%2 == 0) {
            cout << 0 << endl;
        }
        else {
            if (!good) {
                cout << -1 << endl;
                continue;
            }

            int x = pow(10, digit-1);
            int y = n/x;
            if (y%2 == 0) {
                cout << 1 << endl;
            }
            else cout << 2 << endl;
        }
    }

    return 0;
}