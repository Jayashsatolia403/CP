#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        int r = 1;

        for (int i=n-1; i >= 0; i--) {
        	if (digits[i] + r > 9) { digits[i] = (digits[i]+r)%10; }
        	else {
        		digits[i]++;
        		r = 0;
        		break;
        	}  
        }

        if (r > 0) {
        	vector<int> result(digits.size()+1, 0);
        	result[0] = 1; 

        	for (int i=0; i < digits.size(); i++) result[i+1] = digits[i];

        	return result;
        }

        return digits;
    }
};





int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i=0; i < n; i++) cin >> v[i];

	vector<int> result = Solution().plusOne(v);

	for (int i: result) cout << i << " ";

	return 0;
}