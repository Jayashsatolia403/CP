#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> parents(n+1, 0), rank(n+1, 0);
        
        for (int i=1; i < n+1; i++) parents[i] = i;
        
        for (int i=0; i < n; i++) {
            int a = parents[edges[i][0]], b = parents[edges[i][1]];
            
            while (parents[a] != parents[parents[a]]) {
                a = parents[a];
            }
            
            while (parents[b] != b) {
                b = parents[b];
            }


            
            
            if (a == b) return edges[i];
            
            if (rank[a] >= rank[b]) {
                parents[b] = a;
                rank[a]++;
            }
            else {
                parents[a] = b;
                rank[b]++;
            }

            for (int i : parents) cout << i << " ";
            cout << endl;
        }
        
        return vector<int>();
    }
};



int main() {
	vector<vector<int>> edges = {{1,5},{3,4},{3,5},{4,5},{2,4}};

	vector<int> result = Solution().findRedundantConnection(edges);

	for (int i : result) cout << i << " > ";

	return 0; 
}