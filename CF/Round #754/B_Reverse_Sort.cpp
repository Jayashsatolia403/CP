#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, count=0;
        string s;
        bool done = false;

        vector<int> res_forward;
        vector<int> res_backward;

        cin >> n;
        cin >> s;

        int i=0, j=n-1;

        while (i < j) {
            if (s[i] == '1' && s[j] == '0') {
                count += 2;
                ++i;
                --j;
                res_forward.push_back(i);
                res_backward.push_back(j+2);
                done = true;
            } 
            else if (s[i] == '1') --j;
            else ++i;
        }

        if (!done) {
            cout << 0 << endl;
            continue;
        }

        cout << 1 << endl;

        cout << count << " ";
        
        forn (i, res_forward.size()) {
            cout << res_forward[i] << " ";
        }

        reverse(res_backward.begin(), res_backward.end());

        forn (i, res_backward.size()) {
            cout << res_backward[i] << " ";
        }

        cout << endl;
    }

    return 0;
}