#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int divide(int a, int b) {
    	int cnt = 0;

    	bool is_pos = (a<0&&b<0 || a>0&&b>0) ? true : false;

    	long long x = a, y=b;

    	x = x<0?x*-1:x;
    	y = y<0?y*-1:y;

        while (x>=0 && x-y>=0 && y!=0) {
        	x -= y;
        	cnt++;
        }

        return is_pos?cnt:-1*cnt;
    }
};



int main() {
	int a, b;
	cin >> a >> b;

	cout << Solution().divide(a, b) << endl;
	return 0;
}