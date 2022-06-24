#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int l) {
        priority_queue<int, vector<int>, greater<int> > pq;

        vector<int> diffs;

        int n = v.size();

        for (int i=1; i < n; i++) {
        	diffs.push_back((v[i] <= v[i-1] ? 0 : v[i]-v[i-1]));
        }

        int count = 0;

        for (int i : diffs) {
        	pq.push(i);

        	if (l > 0) l--;
        	else {
        		b -= pq.top();
	        	pq.pop();
	        	if (b < 0) break;
	        }

        	count++;
        }

        return count;
    }
};



int main() {
	int n, bricks, ladders;
	cin >> n >> bricks >> ladders;
	vector<int> heights(n);
	for (int i=0; i < n; i++) cin >> heights[i];

	cout << Solution().furthestBuilding(heights, bricks, ladders);

	return 0;
}