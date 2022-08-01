#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;
        return (findTheWinner(n-1, k)+k-1)%n+1;
    }
};


int main() {
    Solution s;
    cout << s.findTheWinner(3, 2) << endl;
    return 0;
}