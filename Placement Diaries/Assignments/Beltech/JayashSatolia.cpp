#include <bits/stdc++.h>
using namespace std;



int m, n;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool dfs(vector<vector<char>>& board, string &word, int r, int c, int depth) {
    // if the depth reaches the length of word, the word exists in the board
    if (depth == word.length() - 1) return true;

    // Marking the cell as visited
    board[r][c] = '$';

    // iterating through the neighbors
    for (int i = 0; i < 4; i++) {

        int rnext = r + dr[i];
        int cnext = c + dc[i];

        // Performing dfs on the next position is it is valid
        if (rnext >= 0 && rnext < m && cnext >= 0 && cnext < n && board[rnext][cnext] == word[depth + 1]) {
            bool result = dfs(board, word, rnext, cnext, depth + 1);
            if (result) return true;
        }
    }


    // Backtracking the cell if no neightbor is valid
    board[r][c] = word[depth];
    
    return false;
}



bool checkIfExist(vector<vector<char>>& board, string &word) {
    int len = word.length();

    // if the number of cells cannot contain the string
    if (m * n < len) return false;

    // if the board does not contain all the occurances of chars in word
    unordered_map<char, int> mp;

    for (auto &v: board) for (char c: v) mp[c]++;
    
    for (char &c: word) {
        mp[c]--;
        if (mp[c] < 0) return false;
    }

    // find the longest prefix and suffix of the same character
    int left = word.find_first_not_of(word[0]);
    int right = len - word.find_last_not_of(word[len - 1]);
    
    // if the longest prefix > the longest suffix, reverse word so that we won't have too long prefix of the same character from the begining
    if (left > right) reverse(word.begin(), word.end());
    
    char first = word[0];
    
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            // only if the cell is the same as the first character we search deeply
            if (board[r][c] == first){
                bool ans = dfs(board, word, r, c, 0);
                if (ans) return true;
            }
        }
    }


    // Returning false if not such string exists
    return false;
}



int main() {
    // Taking rows and columns as input
    cin >> m >> n;

    // Taking the board as input
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // Taking the word as input
    string word;
    cin >> word;

    // Calling the function
    cout << checkIfExist(board, word) << endl;


    return 0;
}