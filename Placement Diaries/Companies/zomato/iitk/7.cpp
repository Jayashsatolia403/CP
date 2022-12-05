#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];

    vector<vector<int>> prefix_sum(n, vector<int>(32, 0));

    for (int i=0; i < n; i++) {
        for (int j=0; j < 32; j++) {
            prefix_sum[i][j] += (i > 0 ? prefix_sum[i-1][j] : 0);

            int f = pow(2, j);
            f = v[i]&f;

            prefix_sum[i][j] += (f ? 1 : 0); 
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l-=2;
        r--;

        vector<int> right = prefix_sum[r];
        vector<int> bit_x = vector<int>(32, 0);

        for (int i=0; i < 32; i++) {
            int f = pow(2, i);
            f = x&f;

            bit_x[i] = (f ? 1 : 0);
        }
 
        if (l >= 0) {
            vector<int> left = prefix_sum[l];

            for (int i=0; i < 32; i++) {
                right[i] -= left[i];
            }
        }


        int ans = 0;
        for (int i=0; i < 32; i++) {
            if (bit_x[i] == 0) {
                ans += right[i]*pow(2, i);
            }
            else if (bit_x[i] == 1) {
                ans += (r-l-right[i])*pow(2, i);
            }
        }

        cout << ans << endl;
    }

    return 0;
}