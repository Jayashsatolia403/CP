#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

#define ll long long

#define p(a,b) pair<int,int>(a,b)




string lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int track = 0;

    forn (i, n+1) {
        forn (j, m+1) {
            if (i==0 || j == 0) dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }


    int cnt = 1;
    string result = "";

    forn (i, n+1) {
        if (dp[i][m] == cnt) {
            result += s1[i-1];
            cnt++;
        }
    }


    return result;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, f;
        cin >> n;
        f = n;

        vector<string> strs;

        while (f--) {
            string s;
            cin >> s;

            strs.push_back(s);
        }

        if (n < 2) {
            cout << strs[0] << endl;
            continue;
        }

        string check = lcs(strs[0], strs[1]);


        for (int i=2; i<n; i++) {
            check = lcs(check, strs[i]);
        }

        cout << check.length() << endl;

        cout << check << endl;
    }

    return 0;
}