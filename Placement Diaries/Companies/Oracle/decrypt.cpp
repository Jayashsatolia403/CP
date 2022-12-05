#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i=0; i < n; i++) {
            cin >> v[i];
        }

        vector<int> f(26);
        map<char,int> m;

        for (string &s : v) {
            f[s[0]-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            m[f[i]] = i;
        }

        for (int i=0; i < n; i++) {
            for (int j=0; j < v[i].size(); j++) {
                if (v[i][j]-'0' <= 9) continue;
                if (f[v[i][j]-'a'] > 0) {
                    v[i][j] = '1';
                }
                else {
                    v[i][j] = '0';
                }
            }
        }

        int result = 0;

        for (string &s : v) {
            cout << s << " ";
        }
        cout << endl;

        for (string &s : v) {
            result += stoi(s);
        }

        cout << result << endl;

    }

    return 0;
}