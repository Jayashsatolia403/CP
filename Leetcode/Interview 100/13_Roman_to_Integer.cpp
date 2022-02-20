#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
    	int n = s.length(), result=0;

    	map<char, int> values;

    	vector<pair<int, int>> v =  {{'I', 1},
					 {'V', 5},
					 {'X', 10},
					 {'L', 50},
					 {'C', 100},
					 {'D', 500},
					 {'M', 1000}};

		for (pair<int, int> p : v) values[p.first] = p.second;

    	for (int i=0; i < n-1; i++) {
    		int x = values[s[i]];
    		int next = values[s[i+1]];

    		if (x < next) result -= x;
    		else result += x;
    	}

    	result += values[s[n-1]];

    	return result;
    }
};


int main() {
	string s;
	cin >> s;

	cout << Solution().romanToInt(s) << endl;
}