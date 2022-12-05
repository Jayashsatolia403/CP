#include <bits/stdc++.h>
using namespace std;




int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int result[n] = {};
    result[0] = v[0];

    for (int i=1; i < n; i++) {
        result[i] = v[i];
        for (int j=0; j < i; j++) {
            result[i] = min(result[i], v[j]+(i-j)*x);
        }
    }
    int op = 0;
    for (int i=0; i < n; i++) {
        op += result[i];
    }
    cout << op << endl;

    return 0;
}