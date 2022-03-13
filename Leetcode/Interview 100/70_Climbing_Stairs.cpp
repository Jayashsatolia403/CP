#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int climbStairs(int n) {
    	int f=1, s=1;

    	if (n <= 1) return n;

    	for (int i=2; i <= n; i++) {
    		int temp = s;
    		s = f + s;
    		f = temp;
    	}

    	return s;
    }
};




int main() {
	int n;
	cin >> n;

	cout << Solution().climbStairs(n) << endl;

	return 0;
}