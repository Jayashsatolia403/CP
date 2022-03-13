#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();

        int result = 0;

        stack<pair<int,int>> s;

        for (int i=0; i < n; i++) {

        	while (!s.empty() && s.top().second >= v[i]) {
        		pair<int,int> p = s.top();

        		cout << p.first << " > " << p.second << endl;
        		s.pop();
        		result = max(result, v[i]*(i-p.first+1));
        	}

        	s.push({i, v[i]});
        }

        return result;
    }
};






int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i=0; i < n; i++) cin >> v[i];

	cout << Solution().largestRectangleArea(v) << endl;
	
	return 0;
}