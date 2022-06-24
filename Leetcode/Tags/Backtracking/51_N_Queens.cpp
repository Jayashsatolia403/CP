#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<string>> result;
    
    bool is_valid(vector<string>& v) {

        if (v.size() < 1) return true;
        
        int n = v.size(), m = v[0].size();
        
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                if (v[i][j] == 'Q') {

                    for (int x=0; x < n; x++) {
                        if (x != i && v[x][j] != '.') return false;
                    }

                    for (int x=0; x < m; x++) {
                        if (x != j && v[i][x] != '.') return false;

                        if (x != 0) {
                            if (i-x >= 0 && j-x >= 0) {
                                if (v[i-x][j-x] != '.') return false;
                            }

                            if (i+x < n && j+x < m) {
                                if (v[i+x][j+x] != '.') return false;
                            }

                            if (i-x >= 0 && j+x < m) {
                                if (v[i-x][j+x] != '.') return false;
                            }

                            if (i+x < n && j-x >= 0) {
                                if (v[i+x][j-x] != '.') return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
    
    void dfs(int n, int idx, vector<string> cur) {
        if (!is_valid(cur)) {
            return;
        }

        if (idx == n) {
            result.push_back(vector<string>(cur));
            return;
        }

        string x = "";
        for (int i=0; i < n; i++) x += '.';

        for (int i=0; i < n; i++) {
            x[i] = 'Q';
            cur.push_back(x);
            dfs(n, idx+1, cur);
            x[i] = '.';
            cur.pop_back();
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        dfs(n, 0, vector<string>());

        return result;
    }
};




int main() {
    int n;
    cin >> n;

    vector<vector<string>> result = Solution().solveNQueens(n);

    for (vector<string> v : result) {
        for (string s : v) cout << s << endl;
        cout << endl << endl;
    }

    return 0;
}