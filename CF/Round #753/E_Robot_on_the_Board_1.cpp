#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)


bool dfs(int i, int j, string seq) {
    int n = seq.size();


    forn (i, n) {
        if (seq[i] == 'L') {
            i--;
            
            if (i < 0) return false;
        } else if (seq[i] == 'R') {
            i++;

            if (i > n-1) return false;
        } else if (seq[i] == 'U') {
            j--;

            if (j < 0) return false;
        } else {
            j++;
            
            if (j > n-1) return false;
        }
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

        string seq;

        cin >> seq;

        bool res = dfs(2, 1, seq);

        if (res)
            cout << "Good" << endl;

        // forn (i, m) {
        //     bool flag = false;

        //     forn (j, n) {
        //         if (dfs(i, j, seq)) {
        //             cout << i << " " << j << endl;
        //             flag = true;
        //             break;
        //         }
        //     }

        //     if (flag) break;
        // }
    }

    return 0;
}