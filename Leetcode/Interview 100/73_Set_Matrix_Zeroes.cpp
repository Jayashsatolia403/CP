#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();


        for (int i=0; i < n; i++) {
        	for (int j=0; j < m; j++) {
        		if (matrix[i][j] == 0) {
        			for (int x = 0; x < n; x++) matrix[x][j] =  matrix[x][j] == 0 ? 0 : INT_MIN;
    				for (int x = 0; x < m; x++) matrix[i][x] = matrix[i][x] == 0 ? 0 : INT_MIN;
        		}
        	}
        }

        for (int i=0; i < n; i++) {
        	for (int j=0; j < m; j++) {
        		if (matrix[i][j] == INT_MIN) matrix[i][j] = 0;
        	}
        }
    }
};


int main() {
	int n, m; 
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));

	for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> v[i][j];

	Solution().setZeroes(v);

	for (int i=0; i < n; i++) {
		for (int j=0; j < m; j++) cout << v[i][j] << " ";
		cout << endl;
	}

	return 0;
}