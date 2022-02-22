#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	string get_char_freq(string s) {
		string result = "00000000000000000000000000";

		for (char c: s) {
			result[c-'a'] += '0'+1;
		}


		return result;
	}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> m;

        for (string s : strs) {
        	string x = get_char_freq(s);
        	m[x].push_back(s);
        }

        for (auto& it: m) {
        	string s = it.first;
        	result.push_back(m[s]);
        }

        return result;
    }
};





int main() {
	int n;
	cin >> n;
	vector<string> strs(n, "");
	for (int i=0; i < n; i++) cin >> strs[i];

	vector<vector<string>> result = Solution().groupAnagrams(strs);

	for (int i=0; i < result.size(); i++) {
		for (int j=0; j < result[i].size(); j++) cout << result[i][j] << " ";
		cout << endl;
	}

	return 0;
}