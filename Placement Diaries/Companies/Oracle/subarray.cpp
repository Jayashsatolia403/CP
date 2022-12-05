#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, mn, mx;
    cin >> n >> mn >> mx;
    vector<int> v(n);
    for (int i=0; i < n; i++) {
        cin >> v[i];
    }


    bool mn_done = false, mx_done = false;

    for (int i=0; i < n; i++) {
        if (v[i] == mn && mx_done || v[i] == mx && mn_done) {
            if (v[i] == mx) v[i] = -1;
            else v[i] = -2;
            mn_done = false;
            mx_done = false;
        }
        else if (v[i] == mn) {
            mn_done = true;
            v[i] = -3;
        }
        else if (v[i] == mx) {
            mx_done = true;
            v[i] = -4;
        }
    

    int result = 0, left = 0;


    for (int i=0; i < n; i++) {
        if (v[i] == -1 || v[i] == -2) {

            int target = v[i] == -1 ? -3 : -4;

            for (int j=left; j < i; j++) {
                if (v[j] == target) {
                    left = j+1;
                    break;
                }
            }

            result += (left)*(n-i);
        }
    }

    cout << result << endl;

    return 0;
}


// [1, -3, -1, -4]