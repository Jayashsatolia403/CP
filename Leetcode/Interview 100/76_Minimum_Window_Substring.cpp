#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	bool check(map<char,int> chars, map<char, int> compare) {
		for (auto& it : chars) if (it.second > compare[it.first]) return false; 
		return true;
	}

    string minWindow(string s, string t) {
        map<char,int> chars;
        map<char, int> compare;

        for (char c : t) chars[c]++;

        int left = 0, n = s.length(), m = t.length();

    	int result = INT_MAX;

    	int g_left=0, g_right=n-1;

    	for (int i=0; i < n; i++) {
    		compare[s[i]]++;

    		while (check(chars, compare)) {
    			// cout << left << " > " << i << endl;

    			if (compare[s[left]] < chars[s[left]]) break;
    			else compare[s[left]]--;

    			if (i-left+1 < result) {
    				result = i-left+1;
    				g_left = left;
    				g_right = i;
    			}

    			left++;
    		}
    	}

    	cout << result << endl;

    	return s.substr(g_left, g_right-g_left+1);
    }
};



int main() {
	string s, t;
	cin >> s >> t;

	cout << Solution().minWindow(s, t) << endl;
	
	return 0;
}


