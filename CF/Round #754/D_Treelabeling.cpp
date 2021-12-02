#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define p(a,b) pair<int,int>(a,b)

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        map<int,int> hashmap;
        map<int,int>::iterator itr;

        forn (i, n-1) {
            int u, v;
            cin >> u >> v;

            hashmap.insert(p(u, v));
        }

        forn (i, n) {
            
        }
    }

    return 0;
}