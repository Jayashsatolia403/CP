#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
    	if (needle.empty() || haystack == needle) return 0;
    	else if (haystack.empty() || needle.length() > haystack.length()) return -1;

        int i = 0, idx = 0, n = haystack.length(), m = needle.length();

        while (i < n) {
        	if (needle[idx] == haystack[i]) {
        		int cnt = 1;
        		idx++;


        		while (m-idx < n-i && idx < m && needle[idx] == haystack[i+cnt]) {
        			cnt++;
        			idx++;
        		}

        		if (idx == m) return i;
        	}

        	i++;
        	idx = 0;
        }

        return -1;
    }
};




int main() {
	string a, b;
	cin >> a >> b;


	cout << Solution().strStr(a, b) << endl;
	return 0;
}




// hello
// ll