#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        
    }
};



int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];

    cout << Solution().findKthLargest(v, k);

    return 0;
}