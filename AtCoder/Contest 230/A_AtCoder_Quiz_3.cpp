#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i=0; i < n; i++)



int main() {
    int n;
    cin >> n;

    int x = n;

    int digit = 0;

    while (x > 0) {
        x = x/10;
        digit++;
    }

    cout << "AGC";
    forn (i, 3-digit) cout << 0;
    cout << (n>=42?n+1:n);

    return 0;
}