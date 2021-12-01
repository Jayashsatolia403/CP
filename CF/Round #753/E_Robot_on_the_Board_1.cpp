#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

int good_i, good_j;

bool check(int i, int j, string seq, int left, int right) {

    int n = seq.size();


    forn (k, n) {
        if (seq[k] == 'L') {
            --j;
            
            if (j < 0) return false;
        } else if (seq[k] == 'R') {
            ++j;

            if (j > right) return false;
        } else if (seq[k] == 'U') {
            --i;

            if (i < 0) return false;
        } else {
            ++i;
            
            if (i > left) return false;
        }

        good_j = j;
        good_i = i;
    }


    return true;
}


int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n;
        cin >> m;

        good_j = m-1;
        good_i = n-1;

        string seq;

        cin >> seq;

        bool flag = false;

        forn (i, n) {
            forn (j, m) {

                if (check(i, j, seq, n-1, m-1)) {
                    cout << i+1 << " " << j+1 << endl;
                    flag = true;
                }
            }
        }

        if (!flag) {
            cout << good_j+1 << " " << good_i+1 << endl;
        }
    }

    return 0;
}