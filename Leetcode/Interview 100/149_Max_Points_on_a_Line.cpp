#include <bits/stdc++.h>
using namespace std;





class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result = 0;

        for (int i=0; i < points.size(); i++) {
            map<float,int> m;
            
        	for (int j=i+1; j < points.size(); j++) {
        		int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];

                float slope;
                
        		if (x1 == x2) slope = INT_MAX;
                else slope = (float)(y2-y1)/(float)(x2-x1);
                
                m[slope]++;
        	}
            
            for (auto& it : m) {
                result = max(result, it.second);
            }
            
            m.clear();
        }
        
        return max(result+1, 2);
    }
};




int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(2, 0));

	for (int i=0; i < n; i++) cin >> v[i][0] >> v[i][1];

	cout << Solution().maxPoints(v);
	
	return 0;
}