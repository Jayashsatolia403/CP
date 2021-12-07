#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i=0; i < n; i++)

#define ll long long 



int main() {
    int t;
    cin >> t;

    while (t--) {
        ll a, b, res = 0;
        cin >> a >> b;

        ll f = a+b;

        ll max_pos = f/4;


        forn (i, max_pos) {
            if (a == 0 || b == 0) {
                break;
            }
            else if (a < b) {
                a--;
                b -= 3;
            }
            else {
                b--;
                a -= 3;
            }

            res++;
        }

        cout << res << endl;
    }

    return 0;
}