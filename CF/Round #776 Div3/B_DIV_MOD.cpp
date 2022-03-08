#include <bits/stdc++.h> 
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll l, r, a;
        cin >> l >> r >> a;

        ll x = (r/a)*a-1;
        ll result;

        if (x >= l) result = max(((r/a)+(r%a)), (x/a)+(x%a));
        else result = (r/a)+(r%a);

        cout << result << endl;
    }
    return 0;
}