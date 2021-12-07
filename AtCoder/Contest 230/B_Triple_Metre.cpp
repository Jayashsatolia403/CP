#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)


int main() {
    string s;
    cin >> s;

    int i = 0;
    int n = s.length();

    while (i < n) {
        if (i!=0 && i!=n-1 && s[i]=='x') {
            if (s[i+1] != 'x') {
                cout << "No" << endl;
                return 0;
            } else i+=2;
        } else i++;
    }

    cout << "Yes" << endl;

    return 0;
}