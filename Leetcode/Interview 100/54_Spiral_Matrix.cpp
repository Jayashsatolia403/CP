#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int left=0, right=matrix[0].size()-1, top = 0, bottom = matrix.size()-1;


        while (result.size() < matrix.size()*matrix[0].size()) {
        	
        	for (int i=left; i <= right && top <= bottom; i++) {
        		result.push_back(matrix[top][i]);
        	}
        	top++;

        	for (int i=top; i <= bottom && left <=right; i++) {
        		result.push_back(matrix[i][right]);
        	}
        	right--;

        	for (int i=right; i >= left && top <= bottom; i--) {
        		result.push_back(matrix[bottom][i]);
        	}
        	bottom--;

        	for (int i=bottom; i >= top && left <= right; i--) {
        		result.push_back(matrix[i][left]);
        	}
        	left++;

        }

        return result;
    }
};




int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m, 0));

	for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> matrix[i][j];

	vector<int> result = Solution().spiralOrder(matrix);

	for (int i : result) cout << i << " ";

	return 0;
}