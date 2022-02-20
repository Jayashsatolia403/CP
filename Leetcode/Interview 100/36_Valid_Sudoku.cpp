#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	bool is_valid(vector<vector<char>> board, int i, int j, int cur) {
		if (i < 0 || j < 0 || i >= 9 || j >= 9 || board[i][j]!='.') return false;


		for (int x=0; x < 9; x++) {
			if (board[i][x] == cur+'0' || board[x][j] == cur+'0') return false;
		}

		
		if (i < 3) i=0;
		else if (i < 6) i=3;
		else i=6;

		if (j < 3) j=0;
		else if (j < 6) j=3;
		else j=6;

		for (int i=0; i < i+3; i++) {
			for (int j=0; j < j+3; j++) {
				if (board[i][j] == cur + '0') return false;
			}
		}

		return true;
	}

	bool dfs(vector<vector<char>>& board, int i, int j, int cur) {
		if (i == 9 && j == 9) return true;

		if (!is_valid(board, i, j, cur)) { cout << i << " > " << j <<  endl; return false; }

		board[i][j] = cur+'0';

		for (int x=0; x < 9; x++) {
			dfs(board, i+1, j, x);
			dfs(board, i, j+1, x);
		}

		return true;
	}

    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i=0; i < 9; i++) {
        	for (int j=0; j < 9; j++) {
        		if (board[i][j] == '.') dfs(board, i, j, 0); 
        	}
        }

        bool result = true;

        for (int i=0; i < 9; i++) {
        	for (int j=0; j < 9; j++) {
        		if (is_valid(board, i, j, ))
        	}
        }

        return result;
    }
};



int main() {
	vector<vector<char>> board(9, vector<char>(9, '.'));

	for (int i=0; i < 9; i++) {
		for (int j=0; j < 9; j++) {
			cin >> board[i][j];
		}
	}

	cout << Solution().isValidSudoku(board) << endl;

	return 0;
}

