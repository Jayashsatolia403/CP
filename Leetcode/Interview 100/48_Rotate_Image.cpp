#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();


        for (int i=0; i < n; i++) {
        	for (int j=i+1; j < n; j++) {
    			int temp = matrix[i][j];
    			matrix[i][j] = matrix[j][i];
    			matrix[j][i] = temp;
        	}
        }

        for (int i=0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};






int main() {
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for (int i=0; i < n; i++) for (int j=0; j < n; j++) cin >> matrix[i][j];

	Solution().rotate(matrix);

	for (int i=0; i < n; i++) {
		for (int j=0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}