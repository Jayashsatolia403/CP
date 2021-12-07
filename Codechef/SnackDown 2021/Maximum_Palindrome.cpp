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

        if (n < 3) {
            cout << "ab" << endl;
            continue;
        }

        int d = n/2;
        int r = n%2;

        // 97 - 122
        int cnt = 26;
        string s = "";

        forn (i, d) {
            if (i > cnt-1) {
                i = i-cnt;
                cnt *= 2;
            }

            char f = 97 + i;

            s += f;
        }

        cout << s;
        char c = (s[s.length()-1]+1);

        if (r!=0) cout << c;

        reverse(s.begin(), s.end());

        cout << s << endl;
    }

    return 0;
}