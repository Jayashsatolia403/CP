#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	double get_power(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        if (n%2 == 0) {
        	double res = myPow(x, n/2);
        	double f = res*res;

        	return f;
        }
        else {
        	double res = myPow(x, n/2);
        	double f = res*res*x;

        	return f;
        }

        return 0;
	}

    double myPow(double x, int n) {
    	if (n < 0) x = (double)1/x;

    	cout << 1/x << endl;

    	return get_power(x, abs(n));
    }
};





int main() {
	double x;
	int n;
	cin >> x >> n;

	cout << Solution().myPow(x, n) << endl;

	return 0;
}