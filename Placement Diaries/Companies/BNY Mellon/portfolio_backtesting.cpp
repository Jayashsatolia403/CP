#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, int arr[]) {
    int p = 0, ng = 0;
    multiset<int> q;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            p += arr[i];
        }
        else {
            int x = abs(arr[i]);
            if (q.size() < k) {
                if (p - (ng + x) >= 0) {
                    ng += x;
                    q.insert(x);
                }
            } else if (q.size() == k) {
                ng += x;
                q.insert(x);
                auto it = --q.end();
                ng -= *it;
                q.erase(it);
            }
        }
    }
    
    // for(auto it: q) cout << it << " ";
    
    
    if (q.size() < k) {
        cout << -1 << endl;
        return;
    }
    int final = p - ng;
    cout << final << endl;
}

int main()
{
    int n, k; cin >> n; cin >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    solve(n, k, arr);
    return 0;
}