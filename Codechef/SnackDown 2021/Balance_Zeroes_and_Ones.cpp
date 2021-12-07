#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i=0; i < n; i++)
#define ll long long 


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int cnt1 = 0, cnt0=0, cnt = 0;

        forn (i, n) {
            if (s[i] == '1') cnt1++;
            else if (s[i] == '0') cnt0++;
            else cnt++;
        }

        int diff = abs(cnt1 - cnt0);
        int diff_q = abs(diff-cnt);

        int no_of_1s, no_of_0s;

        if (cnt1 > cnt0) {
            no_of_0s = abs(diff-diff_q);
        }
        else {
            no_of_1s = abs(diff-diff_q);
        }

        no_of_1s += (diff_q/2);
        no_of_0s += (diff_q/2) + diff_q%2;

        forn (i, n) {
            if (s[i] == '?') {
                if (no_of_0s > 0) {
                    cout << 0;
                    no_of_0s--;
                }
                else {
                    cout << 1;
                    no_of_1s--;
                }
            }
            else {
                cout << s[i];
            }
        }

        cout << endl;
    }

    return 0;
}