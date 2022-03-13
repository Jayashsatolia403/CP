#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());

        int n = v.size();

        vector<vector<int>> result;

        result.push_back(v[0]);

        for (int i=1; i < n; i++) {
        	int rn = result.size();

        	if (result[rn-1][1] >= v[i][0]) {
        		if (result[rn-1][1] < v[i][1]) {
        			result[rn-1][1] = v[i][1];
        		}
        	}
        	else {
        		result.push_back(v[i]);
        	}
        }

        return result;
    }
};


// [[1,3],[2,6],[8,10],[15,18]]



int main() {
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(2, 0));

	for (int i=0; i < n; i++) {
		cin >> v[i][0] >> v[i][1];
	}

	vector<vector<int>> result = Solution().merge(v);

	for (vector<int> i : result) cout << i[0] << " " << i[1] << endl;

	return 0;
}





